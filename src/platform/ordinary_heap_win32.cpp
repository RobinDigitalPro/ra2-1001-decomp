#include "ordinary_heap_win32.hpp"

#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <limits>
#include <sstream>
#include <string>

namespace ra2::platform::ordinary_heap {
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

HeapAdapter::HeapAdapter(HANDLE heap,
                         volatile const std::uint32_t* small_block_count,
                         CRITICAL_SECTION* lock9, bool owns_heap)
    : heap_(heap), small_block_count_(small_block_count), lock9_(lock9),
      owns_heap_(owns_heap) {
    static_assert(sizeof(void*) == 4, "heap adapter requires a Windows x86 process");
    if (!heap_ || !small_block_count_ || !lock9_)
        throw std::invalid_argument("heap adapter requires a real heap, registry count, and initialized lock 9");
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
    if (bytes <= 1016u || bytes > 0xffffffe0u)
        throw std::domain_error("real heap adapter accepts only original ordinary-route sizes (1017..0xffffffe0)");
    require_zero_small_block_count();
    const auto rounded = round16(bytes);
    void* p = real_heap_alloc(heap_, 0, rounded);
    if (!p) throw std::runtime_error("real HeapAlloc failed; bounded fixture is success-only");
    return record_allocation(p, rounded);
}

std::uint32_t HeapAdapter::release(std::uint32_t pointer) {
    require_ready();
    if (!pointer) throw std::domain_error("ordinary-route release requires a tracked nonnull allocation");
    auto it = blocks_.find(pointer);
    if (it == blocks_.end()) throw std::domain_error("release requires this heap context's exact live allocation base");

    // Mirrors original 0x36df28 ordering: lock 9, check the empty small-block
    // registry, unlock, and only then call the actual OS HeapFree.
    push_lock_event(Event::Kind::enter_lock, lock9_);
    real_enter_critical_section(lock9_);
    try {
        require_zero_small_block_count();
    } catch (...) {
        push_lock_event(Event::Kind::leave_lock, lock9_);
        real_leave_critical_section(lock9_);
        throw;
    }
    push_lock_event(Event::Kind::leave_lock, lock9_);
    real_leave_critical_section(lock9_);

    auto* raw = reinterpret_cast<void*>(std::uintptr_t(pointer));
    if (real_heap_validate(heap_, 0, raw) == FALSE)
        throw std::domain_error("HeapValidate rejected the live pointer before HeapFree");
    const BOOL ok = real_heap_free(heap_, 0, raw);
    const auto ordinal = it->second.ordinal;
    events_.push_back({Event::Kind::release, ordinal, it->second.bytes, pointer,
                       static_cast<std::uint32_t>(ok)});
    if (ok != FALSE) blocks_.erase(it);
    return static_cast<std::uint32_t>(ok);
}

std::uint32_t HeapAdapter::record_allocation(void* pointer, std::uint32_t rounded_size) {
    const auto base = as_u32(pointer);
    if (!rounded_size || blocks_.find(base) != blocks_.end())
        throw std::runtime_error("HeapAlloc returned an invalid or duplicate live allocation");
    if (real_heap_validate(heap_, 0, pointer) == FALSE)
        throw std::runtime_error("HeapValidate rejected actual HeapAlloc pointer");
    const SIZE_T actual_size = real_heap_size(heap_, 0, pointer);
    if (actual_size == static_cast<SIZE_T>(-1) || actual_size < rounded_size)
        throw std::runtime_error("HeapSize does not cover the rounded HeapAlloc request");

    const auto ordinal = next_ordinal_++;
    blocks_.emplace(base, Block{rounded_size, ordinal});
    seed_payload(base, rounded_size, ordinal);
    events_.push_back({Event::Kind::allocate, ordinal, rounded_size, base, base});
    return base;
}

BOOL HeapAdapter::record_release(void* pointer) {
    const auto base = as_u32(pointer);
    auto it = blocks_.find(base);
    if (it == blocks_.end()) callback_fail_fast();
    if (real_heap_validate(heap_, 0, pointer) == FALSE) callback_fail_fast();
    const BOOL ok = real_heap_free(heap_, 0, pointer);
    const auto ordinal = it->second.ordinal;
    events_.push_back({Event::Kind::release, ordinal, it->second.bytes, base,
                       static_cast<std::uint32_t>(ok)});
    if (ok != FALSE) blocks_.erase(it);
    return ok; // actual Kernel32 BOOL, preserved to original caller
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
    events_.clear();
    next_ordinal_ = 0;
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
    if (!self || heap != self->heap_ || flags != 0 || bytes <= 1016u || bytes > 0xffffffe0u)
        callback_fail_fast();
    if (self->small_block_count_ && *self->small_block_count_ != 0)
        callback_fail_fast();
    void* p = real_heap_alloc(heap, flags, bytes);
    if (!p) callback_fail_fast(); // don't enter original new-handler retry on this probe
    try {
        const auto base = self->record_allocation(p, static_cast<std::uint32_t>(bytes));
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
    self->push_lock_event(Event::Kind::enter_lock, cs);
    real_enter_critical_section(cs);
}

void WINAPI HeapAdapter::iat_leave_critical_section(LPCRITICAL_SECTION cs) {
    auto* self = active_original_;
    if (!self || cs != self->lock9_) callback_fail_fast();
    self->push_lock_event(Event::Kind::leave_lock, cs);
    real_leave_critical_section(cs);
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

namespace ra2::platform::ordinary_heap {
std::vector<HeapAdapter::LiveBlock> HeapAdapter::live() const {std::vector<LiveBlock> v;for(const auto& x:blocks_)v.push_back({x.first,x.second.bytes,x.second.ordinal});std::sort(v.begin(),v.end(),[](const auto&a,const auto&b){return a.ordinal<b.ordinal;});return v;}
}
