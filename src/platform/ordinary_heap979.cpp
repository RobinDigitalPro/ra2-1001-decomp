#include "platform/ordinary_heap979.hpp"

#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <limits>
#include <sstream>
#include <string>

namespace ra2::recovered::b979 {
namespace {
using HeapAllocFn = LPVOID (WINAPI*)(HANDLE, DWORD, SIZE_T);
using HeapFreeFn = BOOL (WINAPI*)(HANDLE, DWORD, LPVOID);
using HeapDestroyFn = BOOL (WINAPI*)(HANDLE);
using HeapValidateFn = BOOL (WINAPI*)(HANDLE, DWORD, LPCVOID);
using HeapSizeFn = SIZE_T (WINAPI*)(HANDLE, DWORD, LPCVOID);
using EnterCriticalSectionFn = void (WINAPI*)(LPCRITICAL_SECTION);
using LeaveCriticalSectionFn = void (WINAPI*)(LPCRITICAL_SECTION);

HeapAllocFn real_heap_alloc{};
HeapFreeFn real_heap_free{};
HeapDestroyFn real_heap_destroy{};
HeapValidateFn real_heap_validate{};
HeapSizeFn real_heap_size{};
EnterCriticalSectionFn real_enter_critical_section{};
LeaveCriticalSectionFn real_leave_critical_section{};

template<class Fn>
Fn kernel32_function(const char* name) {
    HMODULE kernel = GetModuleHandleW(L"kernel32.dll");
    if (!kernel) throw std::runtime_error("Kernel32 is not loaded");
    FARPROC p = GetProcAddress(kernel, name);
    if (!p) throw std::runtime_error(std::string("Kernel32 API unavailable: ") + name);
    static_assert(sizeof(Fn) == sizeof(p), "heap adapter is x86-only");
    Fn f{};
    std::memcpy(&f, &p, sizeof(f));
    return f;
}

template<class Fn>
std::uint32_t function_address(Fn p) {
    static_assert(sizeof(Fn) == sizeof(std::uintptr_t), "heap adapter is x86-only");
    return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(p));
}

template<class Fn>
void bind_slot(volatile std::uint32_t* slot, Fn expected, Fn replacement,
               const char* name) {
    if (!slot || *slot != function_address(expected))
        throw std::runtime_error(std::string("verified original IAT slot mismatch: ") + name);
    *slot = function_address(replacement);
}

[[noreturn]] void callback_fail_fast() noexcept {
    RaiseFailFastException(nullptr, nullptr, 0);
    std::abort();
}

std::uint32_t as_u32(const void* p) {
    const auto v = reinterpret_cast<std::uintptr_t>(p);
    if (v == 0 || v > std::numeric_limits<std::uint32_t>::max())
        throw std::runtime_error("Win32 heap returned a null or non-x86 pointer");
    return static_cast<std::uint32_t>(v);
}

std::uint32_t round16(std::uint32_t bytes) {
    const std::uint64_t rounded = (std::uint64_t(bytes) + 15u) & ~std::uint64_t(15u);
    if (rounded > 0xffffffe0ull)
        throw std::domain_error("rounded heap request exceeds the original allocator size guard");
    return static_cast<std::uint32_t>(rounded);
}
} // namespace

HeapAdapter* HeapAdapter::active_original_ = nullptr;

void HeapAdapter::set_passive_observer(passive979Ledger* ledger) {
    require_ready();
    if (!blocks_.empty())
        throw std::logic_error("passive observer binding requires no live owners");
    if (ledger && (!ledger->calls ||
        (reinterpret_cast<std::uintptr_t>(ledger->calls)&15u) != 0u ||
        ledger->capacity == 0u || ledger->capacity > 1024u ||
        ledger->used != 0u || ledger->overflow != 0u || ledger->invalid != 0u))
        throw std::invalid_argument("passive observer requires aligned fresh fixed storage");
    observer_ = ledger;
}

passive979Call* HeapAdapter::begin_passive(passive979Sdk api,
    std::uint32_t target, std::uint32_t count, std::uint32_t a,
    std::uint32_t b, std::uint32_t c) noexcept {
    if (!observer_) return nullptr;
    if (observer_->used >= observer_->capacity) {
        observer_->overflow = 1u;
        return nullptr; // Actual SDK operation still proceeds; proof must fail.
    }
    auto* p = &observer_->calls[observer_->used];
    p->sequence = ++observer_->used;
    p->api = api; p->target = target; p->argument_count = count;
    p->arguments[0] = a; p->arguments[1] = b; p->arguments[2] = c;
    p->result = 0u; p->completed_mask = 0u;
    passive979_sample(&p->point[0]);
    p->completed_mask = 1u;
    return p;
}

void HeapAdapter::finish_passive(passive979Call* p,
                                std::uint32_t result) noexcept {
    if (!p) return;
    passive979_sample(&p->point[3]);
    p->result = result;
    p->completed_mask |= 8u;
}

void HeapAdapter::observed_lock(Event::Kind kind, CRITICAL_SECTION* cs) {
    const bool enter = kind == Event::Kind::enter_lock;
    const auto target = enter ? function_address(real_enter_critical_section)
                              : function_address(real_leave_critical_section);
    auto* p = begin_passive(enter ? passive979Sdk::enter_lock
                                  : passive979Sdk::leave_lock,
                            target, 1u, function_address(cs));
    push_lock_event(kind, cs); // Included before SDK in the observed span.
    std::uint32_t raw_void_result{};
    if (p) {
        raw_void_result = passive979_call1(target, function_address(cs),
                                           &p->point[1], &p->point[2]);
        p->completed_mask |= 6u;
    } else if (enter) real_enter_critical_section(cs);
    else real_leave_critical_section(cs);
    // A void SDK has no promised EAX. Preserve and expose the actual residue.
    finish_passive(p, raw_void_result);
}


HeapAdapter::HeapAdapter(HANDLE heap,
                         volatile const std::uint32_t* small_block_count,
                         CRITICAL_SECTION* lock9, bool owns_heap,
                         FreshBytesMode fresh_bytes_mode, std::uint32_t passive_byte_limit,
                         std::uint32_t passive_record_limit)
    : heap_(heap), small_block_count_(small_block_count), lock9_(lock9),
      owns_heap_(owns_heap), fresh_bytes_mode_(fresh_bytes_mode),
      passive_byte_limit_(passive_byte_limit), passive_record_limit_(passive_record_limit) {
    static_assert(sizeof(void*) == 4, "heap adapter requires a Windows x86 process");
    if (!heap_ || !small_block_count_ || !lock9_)
        throw std::invalid_argument("heap adapter requires a real heap, registry count, and initialized lock 9");
    if (fresh_bytes_mode_ != FreshBytesMode::patterned &&
        fresh_bytes_mode_ != FreshBytesMode::capture && fresh_bytes_mode_ != FreshBytesMode::replay)
        throw std::invalid_argument("invalid fresh-byte mode");
    if (passive_byte_limit_ != 256u && passive_byte_limit_ != 4096u && passive_byte_limit_ != 16816u)
        throw std::invalid_argument("passive byte limit must be 256,4096or16816");
    if (passive_record_limit_ != 64u && passive_record_limit_ != 512u &&
        passive_record_limit_ != 1024u)
        throw std::invalid_argument("passive record limit must be64or512or1024");
    if (fresh_bytes_mode_ != FreshBytesMode::patterned && passive_record_limit_ > 64u)
        extra_fresh_inputs_.resize(passive_record_limit_ - 64u);
    if (fresh_bytes_mode_ != FreshBytesMode::patterned && passive_byte_limit_ > 256u)
        extended_fresh_bytes_.resize(passive_record_limit_ * (passive_byte_limit_ - 256u));
    if (!real_heap_alloc) real_heap_alloc = kernel32_function<HeapAllocFn>("HeapAlloc");
    if (!real_heap_free) real_heap_free = kernel32_function<HeapFreeFn>("HeapFree");
    if (!real_heap_destroy) real_heap_destroy = kernel32_function<HeapDestroyFn>("HeapDestroy");
    if (!real_heap_validate) real_heap_validate = kernel32_function<HeapValidateFn>("HeapValidate");
    if (!real_heap_size) real_heap_size = kernel32_function<HeapSizeFn>("HeapSize");
    if (!real_enter_critical_section)
        real_enter_critical_section = kernel32_function<EnterCriticalSectionFn>("EnterCriticalSection");
    if (!real_leave_critical_section)
        real_leave_critical_section = kernel32_function<LeaveCriticalSectionFn>("LeaveCriticalSection");
}

HeapAdapter::~HeapAdapter() {
    if (active_original_ == this) active_original_ = nullptr;
    if (owns_heap_ && heap_ && !destroyed_) {
        real_heap_destroy(heap_);
        destroyed_ = true;
    }
}

void HeapAdapter::require_ready() const {
    if (!heap_ || destroyed_) throw std::logic_error("heap adapter is not live");
}

void HeapAdapter::require_zero_small_block_count() const {
    if (!small_block_count_ || *small_block_count_ != 0)
        throw std::domain_error("bounded ordinary-heap fixture requires zero CRT small-block records");
}

std::uint32_t HeapAdapter::allocate(std::uint32_t bytes) {
    require_ready();
    if (bytes == 0u || bytes > 0xffffffe0u)
        throw std::domain_error("B795 fixture requires positive requests routed to real ordinary HeapAlloc by threshold 0");
    require_zero_small_block_count();
    const auto rounded = round16(bytes);
    validate_fresh_request(rounded, 0u); // Reject replay mismatch before allocating.
    auto* observation = begin_passive(passive979Sdk::heap_alloc,
        function_address(real_heap_alloc), 3u, function_address(heap_), 0u, rounded);
    void* p{};
    if (observation) {
        p = reinterpret_cast<void*>(std::uintptr_t(passive979_call3(
            function_address(real_heap_alloc), function_address(heap_), 0u,
            rounded, &observation->point[1], &observation->point[2])));
        observation->completed_mask |= 6u;
    } else p = real_heap_alloc(heap_, 0, rounded);
    if (!p) throw std::runtime_error("real HeapAlloc failed; bounded fixture is success-only");
    const auto result = record_allocation(p, rounded);
    finish_passive(observation, result);
    return result;
}

std::uint32_t HeapAdapter::release(std::uint32_t pointer) {
    require_ready();
    if (!pointer) throw std::domain_error("ordinary-route release requires a tracked nonnull allocation");
    auto it = blocks_.find(pointer);
    if (it == blocks_.end()) throw std::domain_error("release requires this heap context's exact live allocation base");

    // Mirrors original 0x36df28 ordering: lock 9, check the empty small-block
    // registry, unlock, and only then call the actual OS HeapFree.
    observed_lock(Event::Kind::enter_lock, lock9_);
    try {
        require_zero_small_block_count();
    } catch (...) {
        observed_lock(Event::Kind::leave_lock, lock9_);
        throw;
    }
    observed_lock(Event::Kind::leave_lock, lock9_);

    auto* observation = begin_passive(passive979Sdk::heap_free,
        function_address(real_heap_free), 3u, function_address(heap_), 0u, pointer);
    auto* raw = reinterpret_cast<void*>(std::uintptr_t(pointer));
    if (real_heap_validate(heap_, 0, raw) == FALSE)
        throw std::domain_error("HeapValidate rejected the live pointer before HeapFree");
    snapshot(pointer);
    BOOL ok{};
    if (observation) {
        ok = static_cast<BOOL>(passive979_call3(function_address(real_heap_free),
            function_address(heap_), 0u, pointer,
            &observation->point[1], &observation->point[2]));
        observation->completed_mask |= 6u;
    } else ok = real_heap_free(heap_, 0, raw);
    const auto ordinal = it->second.ordinal;
    events_.push_back({Event::Kind::release, ordinal, it->second.bytes, pointer,
                       static_cast<std::uint32_t>(ok)});
    if (ok != FALSE) blocks_.erase(it);
    finish_passive(observation, static_cast<std::uint32_t>(ok));
    return static_cast<std::uint32_t>(ok);
}

std::uint32_t HeapAdapter::record_allocation(void* pointer, std::uint32_t rounded_size, std::uint32_t flags) {
    const auto base = as_u32(pointer);
    if (!rounded_size || blocks_.find(base) != blocks_.end())
        throw std::runtime_error("HeapAlloc returned an invalid or duplicate live allocation");
    if (real_heap_validate(heap_, 0, pointer) == FALSE)
        throw std::runtime_error("HeapValidate rejected actual HeapAlloc pointer");
    const SIZE_T actual_size = real_heap_size(heap_, 0, pointer);
    if (actual_size == static_cast<SIZE_T>(-1) || actual_size < rounded_size)
        throw std::runtime_error("HeapSize does not cover the rounded HeapAlloc request");

    validate_fresh_request(rounded_size, flags);
    const auto ordinal = next_ordinal_++;
    blocks_.emplace(base, Block{rounded_size, ordinal});
    apply_fresh_bytes(base, rounded_size, flags, ordinal);
    allocation_flags.push_back(flags); addresses.push_back(base);
    events_.push_back({Event::Kind::allocate, ordinal, rounded_size, base, base});
    return base;
}

BOOL HeapAdapter::record_release(void* pointer) {
    const auto base = as_u32(pointer);
    auto it = blocks_.find(base);
    if (it == blocks_.end()) callback_fail_fast();
    auto* observation = begin_passive(passive979Sdk::heap_free,
        function_address(real_heap_free), 3u, function_address(heap_), 0u, base);
    if (real_heap_validate(heap_, 0, pointer) == FALSE) callback_fail_fast();
    snapshot(base);
    BOOL ok{};
    if (observation) {
        ok = static_cast<BOOL>(passive979_call3(function_address(real_heap_free),
            function_address(heap_), 0u, base,
            &observation->point[1], &observation->point[2]));
        observation->completed_mask |= 6u;
    } else ok = real_heap_free(heap_, 0, pointer);
    const auto ordinal = it->second.ordinal;
    events_.push_back({Event::Kind::release, ordinal, it->second.bytes, base,
                       static_cast<std::uint32_t>(ok)});
    if (ok != FALSE) blocks_.erase(it);
    finish_passive(observation, static_cast<std::uint32_t>(ok));
    return ok; // actual Kernel32 BOOL, preserved to original caller
}

void HeapAdapter::validate_fresh_request(std::uint32_t rounded_size, std::uint32_t flags) const {
    if (fresh_bytes_mode_ == FreshBytesMode::patterned) return;
    if (flags != 0u || rounded_size == 0u || rounded_size > passive_byte_limit_ || (rounded_size & 15u) != 0u)
        throw std::domain_error("passive/replay requires flags0, rounded16-byte multiples within the configured limit");
    if (next_ordinal_ >= passive_record_limit_)
        throw std::out_of_range("fixed fresh-input ledger exhausted");
    if (fresh_bytes_mode_ == FreshBytesMode::capture) {
        if (fresh_input_count_ != next_ordinal_ || fresh_input_count_ >= passive_record_limit_)
            throw std::logic_error("capture ordinal/count mismatch");
    } else {
        if (!replay_available_ || replay_consumed_ >= fresh_input_count_)
            throw std::logic_error("replay input unavailable or exhausted");
        const auto& input = fresh_record(replay_consumed_);
        if (input.ordinal != next_ordinal_ || input.rounded_size != rounded_size || input.flags != flags)
            throw std::domain_error("replay ordinal/rounded size/flags mismatch");
    }
}

void HeapAdapter::apply_fresh_bytes(std::uint32_t base, std::uint32_t rounded_size,
                                    std::uint32_t flags, std::uint32_t ordinal) {
    if (fresh_bytes_mode_ == FreshBytesMode::patterned) {
        if (!flags) seed_payload(base, rounded_size, ordinal); // Existing default unchanged.
        return;
    }
    if (fresh_bytes_mode_ == FreshBytesMode::capture) {
        auto& input = fresh_record(fresh_input_count_);
        input.ordinal = ordinal; input.rounded_size = rounded_size; input.flags = flags;
        const auto* payload = reinterpret_cast<const std::uint8_t*>(std::uintptr_t(base));
        for (std::uint32_t k = 0; k < rounded_size; ++k) {
            if (k < 256u) input.bytes[k] = payload[k];
            else extended_fresh_bytes_[ordinal * (passive_byte_limit_ - 256u) + k - 256u] = payload[k];
        }
        ++fresh_input_count_; // Capture never stores into Original allocation payload.
    } else {
        const auto& input = fresh_record(replay_consumed_);
        auto* payload = reinterpret_cast<std::uint8_t*>(std::uintptr_t(base));
        for (std::uint32_t k = 0; k < rounded_size; ++k) {
            payload[k] = k < 256u ? input.bytes[k]
                : extended_fresh_bytes_[ordinal * (passive_byte_limit_ - 256u) + k - 256u];
        }
        ++replay_consumed_; // Only model-side allocations can use this mode.
    }
}

HeapAdapter::FreshInput& HeapAdapter::fresh_record(std::size_t k) {
    if (k >= passive_record_limit_) throw std::out_of_range("fresh record capacity");
    return k < 64u ? fresh_inputs_[k] : extra_fresh_inputs_.at(k - 64u);
}
const HeapAdapter::FreshInput& HeapAdapter::fresh_record(std::size_t k) const {
    if (k >= passive_record_limit_) throw std::out_of_range("fresh record capacity");
    return k < 64u ? fresh_inputs_[k] : extra_fresh_inputs_.at(k - 64u);
}

const HeapAdapter::FreshInput& HeapAdapter::fresh_input(std::size_t k) const {
    if (k >= fresh_input_count_) throw std::out_of_range("fresh-input index out of range");
    return fresh_record(k);
}

std::uint8_t HeapAdapter::fresh_input_byte(std::size_t k, std::uint32_t offset) const {
    const auto& input = fresh_input(k);
    if (offset >= input.rounded_size) throw std::out_of_range("fresh-input byte offset");
    if (offset < 256u) return input.bytes[offset];
    return extended_fresh_bytes_.at(k * (passive_byte_limit_ - 256u) + offset - 256u);
}

void HeapAdapter::copy_fresh_inputs_from(const HeapAdapter& capture) {
    require_ready();
    if (fresh_bytes_mode_ != FreshBytesMode::replay || &capture == this ||
        !blocks_.empty() || next_ordinal_ != 0u || fresh_input_count_ != 0u ||
        replay_available_ || !events_.empty() || !snapshots.empty() ||
        !allocation_flags.empty() || !addresses.empty())
        throw std::logic_error("replay import requires an empty replay context");
    // Completed serial capture boundary: deactivated, all recorded lifetimes closed.
    if (capture.fresh_bytes_mode_ != FreshBytesMode::capture ||
        active_original_ == &capture || !capture.blocks_.empty() ||
        capture.fresh_input_count_ == 0u ||
        capture.fresh_input_count_ != capture.next_ordinal_ ||
        capture.fresh_input_count_ > passive_record_limit_)
        throw std::logic_error("replay import requires completed inactive capture");
    for (std::size_t k = 0; k < capture.fresh_input_count_; ++k) {
        const auto& input = capture.fresh_record(k);
        if (input.ordinal != k || input.flags != 0u || input.rounded_size == 0u ||
            input.rounded_size > passive_byte_limit_ ||
            input.rounded_size > capture.passive_byte_limit_ || (input.rounded_size & 15u) != 0u)
            throw std::domain_error("captured fresh-input metadata is invalid");
    }
    // All metadata checked before any import. Destination tail storage was
    // already allocated by its constructor; no allocation or candidate call.
    for (std::size_t k = 0; k < capture.fresh_input_count_; ++k) {
        const auto& input = capture.fresh_record(k);
        for (std::uint32_t j = 256u; j < input.rounded_size; ++j)
            extended_fresh_bytes_[k * (passive_byte_limit_ - 256u) + j - 256u] =
                capture.fresh_input_byte(k, j);
    }
    for (std::size_t k = 0; k < capture.fresh_input_count_; ++k)
        fresh_record(k) = capture.fresh_record(k); // Immutable PREINPUT only.
    fresh_input_count_ = capture.fresh_input_count_;
    replay_consumed_ = 0u; replay_available_ = true;
}

void HeapAdapter::assert_replay_consumed() const {
    if (fresh_bytes_mode_ != FreshBytesMode::replay || !replay_available_ ||
        replay_consumed_ != fresh_input_count_ || next_ordinal_ != fresh_input_count_)
        throw std::logic_error("replay fresh-input ledger was not exactly consumed");
}

void HeapAdapter::seed_payload(std::uint32_t base, std::uint32_t bytes,
                               std::uint32_t ordinal) {
    auto* p = reinterpret_cast<std::uint8_t*>(std::uintptr_t(base));
    for (std::uint32_t offset = 0; offset < bytes; ++offset) {
        // Explicit fixture input for the otherwise unspecified fresh bytes.
        // Original and C++ heaps use the same byte function of ordinal+offset.
        p[offset] = static_cast<std::uint8_t>((ordinal*73u + offset*131u +
                                               (offset >> 3) + 0x5du) & 0xffu);
    }
}

void HeapAdapter::check_live_range(std::uint32_t address, std::uint32_t width) const {
    require_ready();
    if (!width) throw std::domain_error("zero-width heap access is not part of the fixture contract");
    auto it = blocks_.upper_bound(address);
    if (it == blocks_.begin()) throw std::out_of_range("heap access is outside a tracked live allocation");
    --it;
    const std::uint64_t base = it->first;
    const std::uint64_t end = base + it->second.bytes;
    const std::uint64_t access_end = std::uint64_t(address) + width;
    if (address < base || access_end > end || access_end > 0x100000000ull)
        throw std::out_of_range("heap access crosses a tracked live allocation bound");
}

std::uint32_t HeapAdapter::r8(std::uint32_t address) const {
    check_live_range(address, 1);
    return *reinterpret_cast<const std::uint8_t*>(std::uintptr_t(address));
}

std::uint32_t HeapAdapter::r32(std::uint32_t address) const {
    check_live_range(address, 4);
    const auto* p = reinterpret_cast<const std::uint8_t*>(std::uintptr_t(address));
    return std::uint32_t(p[0]) | (std::uint32_t(p[1]) << 8) |
           (std::uint32_t(p[2]) << 16) | (std::uint32_t(p[3]) << 24);
}

void HeapAdapter::w8(std::uint32_t address, std::uint32_t value) {
    check_live_range(address, 1);
    *reinterpret_cast<std::uint8_t*>(std::uintptr_t(address)) = static_cast<std::uint8_t>(value);
}

void HeapAdapter::w32(std::uint32_t address, std::uint32_t value) {
    check_live_range(address, 4);
    auto* p = reinterpret_cast<std::uint8_t*>(std::uintptr_t(address));
    for (unsigned n = 0; n < 4; ++n) p[n] = static_cast<std::uint8_t>(value >> (8u*n));
}

AllocationIdentity HeapAdapter::identify(std::uint32_t address, std::uint32_t width) const {
    check_live_range(address, width);
    auto it = blocks_.upper_bound(address);
    --it;
    return {it->second.ordinal, address-it->first};
}

void HeapAdapter::reset_observation() {
    require_ready();
    if (!blocks_.empty())
        throw std::logic_error("cannot reset allocation ordinals while tracked blocks are live");
    events_.clear(); snapshots.clear(); allocation_flags.clear(); addresses.clear();
    next_ordinal_ = 0;
    fresh_input_count_ = 0u; replay_consumed_ = 0u; replay_available_ = false;
}

void HeapAdapter::push_lock_event(Event::Kind kind, CRITICAL_SECTION* cs) {
    events_.push_back({kind, 0, 0,
                       static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(cs)), 0});
}

void HeapAdapter::install_original_iat_forwarders(
    volatile std::uint32_t* heap_alloc_slot,
    volatile std::uint32_t* heap_free_slot,
    volatile std::uint32_t* enter_cs_slot,
    volatile std::uint32_t* leave_cs_slot) {
    require_ready();
    if (fresh_bytes_mode_ == FreshBytesMode::replay)
        throw std::logic_error("replay mode cannot install Original IAT forwarders");
    if (active_original_ && active_original_ != this)
        throw std::logic_error("another original heap context already owns the IAT forwarders");
    bind_slot(heap_alloc_slot, real_heap_alloc, &HeapAdapter::iat_heap_alloc, "HeapAlloc");
    bind_slot(heap_free_slot, real_heap_free, &HeapAdapter::iat_heap_free, "HeapFree");
    bind_slot(enter_cs_slot, real_enter_critical_section,
              &HeapAdapter::iat_enter_critical_section, "EnterCriticalSection");
    bind_slot(leave_cs_slot, real_leave_critical_section,
              &HeapAdapter::iat_leave_critical_section, "LeaveCriticalSection");
    active_original_ = this;
}

void HeapAdapter::activate_original_forwarders(HeapAdapter& context) {
    context.require_ready();
    if (context.fresh_bytes_mode_ == FreshBytesMode::replay)
        throw std::logic_error("replay mode cannot activate Original IAT forwarders");
    if (active_original_ && active_original_ != &context)
        throw std::logic_error("original heap IAT forwarders already active for another context");
    active_original_ = &context;
}

void HeapAdapter::deactivate_original_forwarders(HeapAdapter& context) {
    if (active_original_ != &context)
        throw std::logic_error("attempted to deactivate a different original heap context");
    active_original_ = nullptr;
}

void* WINAPI HeapAdapter::iat_heap_alloc(HANDLE heap, DWORD flags, SIZE_T bytes) {
    auto* self = active_original_;
    if (!self || heap != self->heap_ || (flags != 0 && !(flags == HEAP_ZERO_MEMORY && bytes == 4096u)) || bytes == 0u || bytes > 0xffffffe0u)
        callback_fail_fast();
    if (self->small_block_count_ && *self->small_block_count_ != 0)
        callback_fail_fast();
    try {
        self->validate_fresh_request(static_cast<std::uint32_t>(bytes), flags);
    } catch (...) { callback_fail_fast(); } // Before API; no leaked mismatch allocation.
    auto* observation = self->begin_passive(passive979Sdk::heap_alloc,
        function_address(real_heap_alloc), 3u, function_address(heap), flags,
        static_cast<std::uint32_t>(bytes));
    void* p{};
    if (observation) {
        p = reinterpret_cast<void*>(std::uintptr_t(passive979_call3(
            function_address(real_heap_alloc), function_address(heap), flags,
            static_cast<std::uint32_t>(bytes),
            &observation->point[1], &observation->point[2])));
        observation->completed_mask |= 6u;
    } else p = real_heap_alloc(heap, flags, bytes);
    if (!p) callback_fail_fast(); // don't enter original new-handler retry on this probe
    try {
        const auto base = self->record_allocation(p, static_cast<std::uint32_t>(bytes),flags);
        self->finish_passive(observation, base);
        return reinterpret_cast<void*>(std::uintptr_t(base));
    } catch (...) { callback_fail_fast(); }
}

BOOL WINAPI HeapAdapter::iat_heap_free(HANDLE heap, DWORD flags, LPVOID pointer) {
    auto* self = active_original_;
    if (!self || heap != self->heap_ || flags != 0 || !pointer)
        callback_fail_fast();
    return self->record_release(pointer);
}

void WINAPI HeapAdapter::iat_enter_critical_section(LPCRITICAL_SECTION cs) {
    auto* self = active_original_;
    if (!self || cs != self->lock9_) callback_fail_fast();
    self->observed_lock(Event::Kind::enter_lock, cs);
}

void WINAPI HeapAdapter::iat_leave_critical_section(LPCRITICAL_SECTION cs) {
    auto* self = active_original_;
    if (!self || cs != self->lock9_) callback_fail_fast();
    self->observed_lock(Event::Kind::leave_lock, cs);
}

void HeapAdapter::destroy() {
    require_ready();
    if (!owns_heap_) throw std::logic_error("cannot destroy the original CRT heap through a borrowed adapter");
    if (!blocks_.empty()) throw std::logic_error("cannot destroy heap while tracked allocations remain live");
    if (real_heap_destroy(heap_) == FALSE)
        throw std::runtime_error("real HeapDestroy failed");
    heap_ = nullptr;
    destroyed_ = true;
}

HANDLE create_portable_heap() {
    auto* heap = HeapCreate(0, 4096u, 0u);
    if (!heap) throw std::runtime_error("real HeapCreate(0,4096,0) failed");
    return heap;
}

} // namespace ra2::platform::ordinary_heap

namespace ra2::recovered::b979 {
std::vector<HeapAdapter::LiveBlock> HeapAdapter::live() const {std::vector<LiveBlock> v;for(const auto& x:blocks_)v.push_back({x.first,x.second.bytes,x.second.ordinal});std::sort(v.begin(),v.end(),[](const auto&a,const auto&b){return a.ordinal<b.ordinal;});return v;}
}

namespace ra2::recovered::b979 {
void HeapAdapter::snapshot(std::uint32_t p){auto it=blocks_.find(p);if(it==blocks_.end())throw std::runtime_error("979 snapshot outside live block");const auto*q=reinterpret_cast<const std::uint8_t*>(std::uintptr_t(p));snapshots.push_back({it->second.ordinal,{q,q+it->second.bytes}});}
std::uint32_t HeapAdapter::allocate_reader(){return allocate(4096u);}
void HeapAdapter::free_reader(std::uint32_t p){if(release(p)==0u)throw std::runtime_error("979 reader free failed");}
}

// Standalone original draft. Root may integrate this body into existing
// ordinary_heap979.cpp, so no additional canonical translation unit is needed.
// No compilation/runtime/Source/Original execution has qualified this draft.

namespace ra2::recovered::b979 {

// Basic GNU assembly only: no C++ body, implicit helper, callback or API.
// At entry E: [E]=return address; [E+4]=out. After PUSHFL/PUSHAL, T=E-36:
// +0 EDI,+4 ESI,+8 EBP,+12 saved ESP(E-4),+16 EBX,+20 EDX,+24 ECX,
// +28 EAX,+32 PUSHFL image,+36 return,+40 out. We derive entry ESP as T+36,
// rather than incorrectly exposing PUSHAL's saved ESP(E-4) as entry ESP.
extern "C" __attribute__((cdecl,naked,noinline))
void passive979_sample(passive979Raw*) noexcept {
    __asm__ volatile(
        "pushfl\n\t"
        "pushal\n\t"
        "movl 40(%esp),%edx\n\t"
        "movl 28(%esp),%eax\n\tmovl %eax,0(%edx)\n\t"
        "movl 24(%esp),%eax\n\tmovl %eax,4(%edx)\n\t"
        "movl 20(%esp),%eax\n\tmovl %eax,8(%edx)\n\t"
        "movl 16(%esp),%eax\n\tmovl %eax,12(%edx)\n\t"
        "movl 4(%esp),%eax\n\tmovl %eax,16(%edx)\n\t"
        "movl 0(%esp),%eax\n\tmovl %eax,20(%edx)\n\t"
        "movl 8(%esp),%eax\n\tmovl %eax,24(%edx)\n\t"
        "leal 36(%esp),%eax\n\tmovl %eax,28(%edx)\n\t"
        "movl 32(%esp),%eax\n\tmovl %eax,32(%edx)\n\t"
        "movw %fs,%ax\n\tmovzwl %ax,%eax\n\tmovl %eax,36(%edx)\n\t"
        "movl %fs:0x00,%eax\n\tmovl %eax,40(%edx)\n\t"
        "movl %fs:0x04,%eax\n\tmovl %eax,44(%edx)\n\t"
        "movl %fs:0x08,%eax\n\tmovl %eax,48(%edx)\n\t"
        "movl %fs:0x18,%eax\n\tmovl %eax,52(%edx)\n\t"
        "movl %fs:0x34,%eax\n\tmovl %eax,56(%edx)\n\t"
        // reserved_alignment and raw FP reserved bytes remain untouched;
        // initialize the entire fixed record outside the observed boundary.
        "fxsave 64(%edx)\n\t"
        "fnsave 576(%edx)\n\t"
        "frstor 576(%edx)\n\t"
        "popal\n\t"
        "popfl\n\t"
        "ret\n\t"
    );
}

// Entry S layout: return,target,arg0,arg1,arg2,before,after at +0..+24.
// Push args right-to-left; constant offset16 reaches arg2,arg1,arg0 in turn.
// SDK-before sampler entry is S-20; actual SDK pre-CALL ESP is S-12.
// SDK-return sampler entry is S-8; actual SDK returned ESP is S.
// Thus actual SDK pre-CALL/returned ESP = corresponding raw.esp+8.
// The SDK entry ESP is before.esp+4; after.esp-before.esp must be12.
extern "C" __attribute__((cdecl,naked,noinline))
std::uint32_t passive979_call3(
    std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t,
    passive979Raw*, passive979Raw*) noexcept {
    __asm__ volatile(
        "pushl 16(%esp)\n\t"
        "pushl 16(%esp)\n\t"
        "pushl 16(%esp)\n\t"
        "pushl 32(%esp)\n\t"
        "call passive979_sample\n\t"
        "leal 4(%esp),%esp\n\t"
        "call *16(%esp)\n\t"
        // FIRST instructions after actual SDK return: push after; call sampler.
        "pushl 24(%esp)\n\t"
        "call passive979_sample\n\t"
        "leal 4(%esp),%esp\n\t"
        "ret\n\t"
    );
}

// Entry S layout: return,target,arg0,before,after at +0..+16.
// SDK-before sampler entry is S-12; SDK-return sampler entry is S-8.
// Actual SDK pre-CALL/returned ESP = corresponding raw.esp+8.
// The SDK entry ESP is before.esp+4; after.esp-before.esp must be4.
// No synthetic EAX is assigned for Enter/LeaveCriticalSection (void APIs).
extern "C" __attribute__((cdecl,naked,noinline))
std::uint32_t passive979_call1(
    std::uint32_t, std::uint32_t, passive979Raw*, passive979Raw*) noexcept {
    __asm__ volatile(
        "pushl 8(%esp)\n\t"
        "pushl 16(%esp)\n\t"
        "call passive979_sample\n\t"
        "leal 4(%esp),%esp\n\t"
        "call *8(%esp)\n\t"
        // FIRST instructions after actual SDK return: push after; call sampler.
        "pushl 16(%esp)\n\t"
        "call passive979_sample\n\t"
        "leal 4(%esp),%esp\n\t"
        "ret\n\t"
    );
}

} // namespace ra2::recovered::b979
