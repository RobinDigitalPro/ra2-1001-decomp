#include "heap_b336_win32.hpp"
#include "small_heap_b336_adapter.hpp"

#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <limits>
#include <stdexcept>

namespace ra2::platform::small_crt_heap336 {
namespace {
using namespace ra2::platform::small_crt_heap;
using U = std::uint32_t;

void need(bool ok, const char* why) {
    if (!ok) throw std::domain_error(why);
}
U addr(const void* p) {
    const auto q = reinterpret_cast<std::uintptr_t>(p);
    need(q != 0 && q <= std::numeric_limits<U>::max(), "non-x86/null Win32 address");
    return static_cast<U>(q);
}
bool range(U a, U n, U b, U size) {
    return a >= b && std::uint64_t(a) + n <= std::uint64_t(b) + size;
}
std::vector<std::uint8_t> copy_bytes(U p, U n) {
    const auto* b = reinterpret_cast<const std::uint8_t*>(std::uintptr_t(p));
    return {b, b + n};
}
U get32(const std::vector<std::uint8_t>& v, U off) {
    return U(v.at(off)) | (U(v.at(off + 1)) << 8) |
           (U(v.at(off + 2)) << 16) | (U(v.at(off + 3)) << 24);
}
void put32(std::vector<std::uint8_t>& v, U off, U x) {
    for (U n = 0; n != 4; ++n) v.at(off + n) = std::uint8_t(x >> (8 * n));
}
template<class Fn> Fn kernel32(const char* name) {
    const auto module = GetModuleHandleW(L"kernel32.dll");
    need(module != nullptr, "Kernel32 is not loaded");
    const auto p = GetProcAddress(module, name);
    need(p != nullptr && sizeof(Fn) == sizeof(p), "required Kernel32 function unavailable");
    Fn result{};
    std::memcpy(&result, &p, sizeof(result));
    return result;
}
template<class Fn> U fn_address(Fn f) {
    static_assert(sizeof(Fn) == sizeof(std::uintptr_t), "B336 adapter requires x86 Windows");
    return static_cast<U>(reinterpret_cast<std::uintptr_t>(f));
}
template<class Fn> void bind_slot(volatile U* slot, Fn expected, Fn replacement,
                                  const char* name) {
    need(slot != nullptr, name);
    if (*slot == fn_address(expected)) *slot = fn_address(replacement);
    else need(*slot == fn_address(replacement), name);
}
[[noreturn]] void callback_fail_fast() noexcept {
    RaiseFailFastException(nullptr, nullptr, 0);
    std::abort();
}
} // namespace

Heap* Heap::active_original_ = nullptr;

Heap::Heap(Memory& m, U table, HANDLE heap, CRITICAL_SECTION* lock,
           U first_request, U seed)
    : memory_(m), table_(table), heap_(heap), lock_(lock),
      first_request_(first_request), seed_(seed) {
    static_assert(sizeof(void*) == 4, "B336 adapter requires 32-bit Windows");
    need(table_ && heap_ && lock_, "B336 adapter requires initialized heap/table/lock");
    need(first_request_ == 14u || first_request_ == 15u,
         "B336 exact first compressed request is 14 or 15 bytes");
    need(memory_.r32(0xb10e18u) == table_ && memory_.r32(0xb10e1cu) == addr(heap_) &&
         memory_.r32(0xb10e14u) == 0u && memory_.r32(0xb10e0cu) == table_ &&
         memory_.r32(0x817554u) == 1016u,
         "B336 requires a fresh initialized one-entry CRT region table");
    need(memory_.r32(0x81729cu) == addr(lock_), "B336 lock 9 identity differs");
    need(HeapValidate(heap_, 0, reinterpret_cast<void*>(std::uintptr_t(table_))) != FALSE &&
         HeapSize(heap_, 0, reinterpret_cast<void*>(std::uintptr_t(table_))) >= 320u,
         "B336 CRT table is not a real 320-byte heap allocation");
    requests_ = {first_request_, 8u};
}

Heap::~Heap() {
    if (active_original_ == this) active_original_ = nullptr;
    if (ordinary_ && !ordinary_freed_)
        HeapFree(heap_, 0, reinterpret_cast<void*>(std::uintptr_t(ordinary_)));
    if (arena_) VirtualFree(reinterpret_cast<void*>(std::uintptr_t(arena_)), 0, MEM_RELEASE);
    if (metadata_) HeapFree(heap_, 0, reinterpret_cast<void*>(std::uintptr_t(metadata_)));
}

bool Heap::owned(U a, U n) const {
    return range(a, n, table_, 320u) ||
           (metadata_ && range(a, n, metadata_, 0x41c4u)) ||
           (committed_ && arena_ && range(a, n, arena_, 0x8000u)) ||
           (ordinary_ && !ordinary_freed_ && range(a, n, ordinary_, ordinary_bytes_)) ||
           range(a, n, 0x7d100000u, 8u);
}

U Heap::identity(U p, U width) const {
    if (!p) return 0;
    if (range(p, width, table_, 320u)) return 0xd1000000u + p - table_;
    if (metadata_ && range(p, width, metadata_, 0x41c4u)) return 0xd2000000u + p - metadata_;
    if (arena_ && range(p, width, arena_, 0x100000u)) return 0xd3000000u + p - arena_;
    if (ordinary_ && range(p, width, ordinary_, ordinary_bytes_)) return 0xd4000000u + p - ordinary_;
    if (p == addr(lock_)) return 0xd5000000u;
    throw std::domain_error("B336 observed pointer escaped exact allocation identities");
}

void Heap::record(Event e) { events_.push_back(e); }

std::uint8_t Heap::r8(U a) const {
    if (range(a, 1, 0x7d100000u, 8u))
        return reinterpret_cast<const std::uint8_t*>(scratch_.data())[a - 0x7d100000u];
    if (owned(a, 1)) return *reinterpret_cast<const std::uint8_t*>(std::uintptr_t(a));
    return std::uint8_t(memory_.r8(a));
}
U Heap::r32(U a) const {
    return U(r8(a)) | (U(r8(a + 1u)) << 8) | (U(r8(a + 2u)) << 16) |
           (U(r8(a + 3u)) << 24);
}
void Heap::w8(U a, std::uint8_t v) {
    if (range(a, 1, 0x7d100000u, 8u)) {
        reinterpret_cast<std::uint8_t*>(scratch_.data())[a - 0x7d100000u] = v;
        return;
    }
    if (owned(a, 1)) *reinterpret_cast<std::uint8_t*>(std::uintptr_t(a)) = v;
    else memory_.w8(a, v);
}
void Heap::w32(U a, U v) {
    for (U n = 0; n != 4; ++n) w8(a + n, std::uint8_t(v >> (8 * n)));
}

U Heap::heap_alloc(U h, U flags, U bytes) {
    need(h == addr(heap_), "B336 HeapAlloc used a different CRT heap");
    if (flags == 0u && bytes == 0x4000u) {
        need(!ordinary_ && !small_allocations_ && !metadata_ && !arena_,
             "B336 output buffer must be the first per-root allocation");
    } else {
        need(flags == 8u && bytes == 0x41c4u && !metadata_ &&
             ordinary_ && !small_allocations_,
             "B336 only permits zeroed CRT metadata after the ordinary output buffer");
    }
    auto* p = static_cast<std::uint8_t*>(HeapAlloc(heap_, flags, bytes));
    need(p != nullptr && HeapValidate(heap_, 0, p) != FALSE && HeapSize(heap_, 0, p) >= bytes,
         "B336 real HeapAlloc/HeapValidate/HeapSize success path required");
    const U base = addr(p);
    if (bytes == 0x4000u) {
        ordinary_ = base;
        ordinary_bytes_ = 0x4000u;
        for (U k = 0; k != ordinary_bytes_; ++k)
            p[k] = std::uint8_t(seed_ * 73u + k * 131u + (k >> 3u) + 0x5du);
        record({1u, flags, bytes, 0u, identity(base)});
    } else {
        metadata_ = base;
        record({1u, flags, bytes, 0u, identity(base)});
    }
    return base;
}

U Heap::virtual_alloc(U requested, U bytes, U type, U protection) {
    need(protection == PAGE_READWRITE, "B336 requires PAGE_READWRITE for CRT arena");
    void* p{};
    if (type == MEM_RESERVE) {
        need(!requested && !arena_ && bytes == 0x100000u,
             "B336 exact 1 MiB arena reservation required");
        p = VirtualAlloc(nullptr, bytes, type, protection);
        need(p != nullptr, "B336 excludes arena reservation failure");
        arena_ = addr(p);
        record({3u, type, bytes, 0u, identity(arena_)});
        return arena_;
    }
    need(type == MEM_COMMIT && requested == arena_ && bytes == 0x8000u && !committed_,
         "B336 exact first 32 KiB arena commit required");
    p = VirtualAlloc(reinterpret_cast<void*>(std::uintptr_t(requested)), bytes, type, protection);
    need(addr(p) == arena_, "B336 excludes relocated/failed first-chunk commit");
    committed_ = true;
    record({4u, type, bytes, identity(requested), identity(addr(p))});
    return addr(p);
}

void Heap::enter() {
    need(addr(lock_) == memory_.r32(0x81729cu), "B336 lock enter identity mismatch");
    const U ordinal = lock_enters_++;
    need(ordinal < 5u, "B336 exact five-lock-enter route exceeded");
    record({5u, 0u, 0u, identity(addr(lock_)), ordinal});
    EnterCriticalSection(lock_);
    try {
    // On both the recovered route and original x86 route, lock-entry ordinal
    // 1/3 is the existing real OS boundary immediately before either
    // second CRT free body. Capture the exact arena slot while the lock is
    // held; the native path needs no function patch or synthetic callback.
    if (ordinal == 1u || ordinal == 3u) {
        const U free_ordinal = ordinal == 1u ? 0u : 1u;
        const U pointer = arena_ + (free_ordinal == 0u ? 0xfe0u : 0xff0u);
        const U span = free_ordinal == 0u ? 0x20u : 0x10u;
        if (!temporary_[free_ordinal]) {
            temporary_[free_ordinal] = pointer;
            temporary_span_[free_ordinal] = span;
        }
        need(temporary_[free_ordinal] == pointer && temporary_span_[free_ordinal] == span,
             "B336 free-boundary arena identity differs");
        need(r32(pointer - 4u) == (free_ordinal == 0u ? 0x21u : 0x11u) &&
             r32(pointer + span - 8u) == (free_ordinal == 0u ? 0x21u : 0x11u) &&
             r32(pointer + span - 4u) == 0xffffffffu,
             "B336 temporary boundary tags/sentinel differ at real lock boundary");
        capture_temporary_prefree(free_ordinal, pointer);
        if (free_ordinal == 0u) { small_allocations_ = 1u; small_releases_ = 1u; }
        else { small_allocations_ = 2u; small_releases_ = 2u; }
    }
    } catch (...) { LeaveCriticalSection(lock_); throw; }
}
void Heap::leave() {
    record({6u, 0u, 0u, identity(addr(lock_)), lock_enters_ - 1u});
    LeaveCriticalSection(lock_);
}

U Heap::allocate(U bytes) {
    if (bytes == 0x4000u) {
        need(!ordinary_ && requests_.size() == 2u && small_allocations_ == 0,
             "B336 output allocation must precede CRT initialization");
        return heap_alloc(addr(heap_), 0u, bytes);
    }
    need(small_allocations_ < 2u && bytes == requests_[small_allocations_] &&
         memory_.r32(0x817554u) == 1016u,
         "B336 CRT temporary request order/threshold mismatch");
    w32(0x7d100004u, bytes);
    enter();
    U result{};
    try {
        if (small_allocations_ == 0u)
            result = fun_007736d3_allocate_first_small_block(*this, *this, bytes, 0x7d100000u);
        else
            result = b336::allocate_eight_from_tracked_empty_chunk(*this, bytes, 0x7d100000u);
    } catch (...) { leave(); throw; }
    leave();
    const U span = (bytes + 0x17u) & 0xfffffff0u;
    const U expected = arena_ + (small_allocations_ == 0u ? 0x1000u - span : 0x0ff0u);
    need(result == expected, "B336 CRT allocation returned an unexpected high-edge identity");
    temporary_[small_allocations_] = result;
    temporary_span_[small_allocations_] = span;
    ++small_allocations_;
    return result;
}

void Heap::capture_temporary_prefree(U ordinal, U pointer) {
    need(ordinal < 2u && pointer == temporary_[ordinal] && temporary_span_[ordinal] != 0,
         "B336 temporary prefree capture identity mismatch");
    temporary_prefree_[ordinal] = copy_bytes(pointer - 4u, temporary_span_[ordinal]);
}
void Heap::capture_ordinary_prefree() {
    need(ordinary_ && !ordinary_freed_, "B336 ordinary output is not live at free");
    if (ordinary_prefree_.empty()) ordinary_prefree_ = copy_bytes(ordinary_, ordinary_bytes_);
}

U Heap::free_ordinary(U pointer) {
    need(pointer == ordinary_ && !ordinary_freed_ && small_releases_ == 2u &&
         memory_.r32(0x817554u) == 1016u && r32(metadata_ + 0x144u) == 0u,
         "B336 ordinary release requires its exact owner and no live small blocks");
    capture_ordinary_prefree();
    auto* raw = reinterpret_cast<void*>(std::uintptr_t(pointer));
    need(HeapValidate(heap_, 0, raw) != FALSE && HeapSize(heap_, 0, raw) >= ordinary_bytes_,
         "B336 ordinary output failed the real prefree heap checks");
    const BOOL result = HeapFree(heap_, 0, raw);
    ordinary_free_bool_ = static_cast<U>(result);
    record({2u, 0u, ordinary_bytes_, identity(pointer), ordinary_free_bool_});
    if (result != FALSE) ordinary_freed_ = true;
    return ordinary_free_bool_;
}

U Heap::release(U pointer) {
    if (!pointer) return 0u; // Original 0x36df28 null input does not call HeapFree.
    if (small_releases_ < 2u) {
        const U ordinal = small_releases_;
        need(ordinal < small_allocations_ && pointer == temporary_[ordinal],
             "B336 exact temporary free order and owner required");
        enter();
        try {
            if (ordinal == 0u)
                b336::release_first_class1_temporary(*this, pointer, first_request_);
            else
                b336::release_second_class0_temporary(*this, pointer);
        } catch (...) { leave(); throw; }
        leave();
        return 0u; // 0x3733a8 return register is not asserted by this route.
    }
    enter();
    need(memory_.r32(0x817554u) == 1016u && r32(metadata_ + 0x144u) == 0u,
         "B336 ordinary free must observe an empty CRT small-block registry");
    leave();
    return free_ordinary(pointer);
}

Snapshot Heap::snapshot(U no_live_result) const {
    need(no_live_result == 0u, "B336 heap snapshot requires zero surviving allocation result");
    need(ordinary_ && ordinary_freed_ && ordinary_free_bool_ != 0u &&
         small_allocations_ == 2u && small_releases_ == 2u && lock_enters_ == 5u && committed_ && metadata_,
         "B336 snapshot requires both temporaries and the ordinary output to be released");
    const U record = memory_.r32(0xb10e18u);
    need(record == table_ && memory_.r32(0xb10e14u) == 1u &&
         memory_.r32(0xb10e0cu) == record && memory_.r32(0xb10e10u) == record &&
         memory_.r32(0xb10e08u) == 0u,
         "B336 final region and empty-chunk identity differs");
    need(r32(metadata_) == 0u && r32(metadata_ + 0x144u) == 0u &&
         r32(table_ + 4u) == 1u && r32(table_ + 8u) == 0x7fffffffu,
         "B336 final no-live-block/chunk-availability state differs");
    need(temporary_prefree_[0].size() == 0x20u && temporary_prefree_[1].size() == 0x10u,
         "B336 both exact rounded temporary prefree spans are required");

    Snapshot s{copy_bytes(table_, 320u), copy_bytes(metadata_, 0x41c4u),
               copy_bytes(arena_, 0x8000u), {}, ordinary_prefree_,
               temporary_prefree_, ordinary_free_bool_};
    for (const auto& e : events_)
        s.events.push_back({e.kind, e.flags, e.bytes, e.identity, e.result});
    const std::array<std::array<U, 5>, 15> expected{{
        {{1u, 0u, 0x4000u, 0u, 0xd4000000u}},
        {{5u, 0u, 0u, 0xd5000000u, 0u}},
        {{1u, 8u, 0x41c4u, 0u, 0xd2000000u}},
        {{3u, MEM_RESERVE, 0x100000u, 0u, 0xd3000000u}},
        {{4u, MEM_COMMIT, 0x8000u, 0xd3000000u, 0xd3000000u}},
        {{6u, 0u, 0u, 0xd5000000u, 0u}},
        {{5u, 0u, 0u, 0xd5000000u, 1u}}, {{6u, 0u, 0u, 0xd5000000u, 1u}},
        {{5u, 0u, 0u, 0xd5000000u, 2u}}, {{6u, 0u, 0u, 0xd5000000u, 2u}},
        {{5u, 0u, 0u, 0xd5000000u, 3u}}, {{6u, 0u, 0u, 0xd5000000u, 3u}},
        {{5u, 0u, 0u, 0xd5000000u, 4u}}, {{6u, 0u, 0u, 0xd5000000u, 4u}},
        {{2u, 0u, 0x4000u, 0xd4000000u, ordinary_free_bool_}}
    }};
    need(s.events.size() == expected.size(), "B336 null free or extra OS API event appeared");
    for (U n = 0; n != expected.size(); ++n)
        need(s.events[n] == expected[n], "B336 actual Win32/lock event order differs");
    const auto normalize = [&](std::vector<std::uint8_t>& v, U off) {
        put32(v, off, identity(get32(v, off)));
    };
    normalize(s.table, 12u); normalize(s.table, 16u);
    for (U n = 0; n != 63u; ++n) {
        normalize(s.metadata, 0x148u + n * 8u);
        normalize(s.metadata, 0x14cu + n * 8u);
    }
    normalize(s.metadata, 0x340u); normalize(s.metadata, 0x344u);
    for (U n = 0; n != 8u; ++n) {
        normalize(s.arena, n * 0x1000u + 0x10u);
        normalize(s.arena, n * 0x1000u + 0x14u);
    }
    need(s.ordinary_prefree.size() == 0x4000u, "B336 full ordinary prefree payload missing");
    return s;
}

void Heap::activate() {
    need(!active_original_ || active_original_ == this, "another B336 IAT forwarder is active");
    active_original_ = this;
}
void Heap::deactivate() {
    need(active_original_ == this, "wrong B336 active IAT adapter");
    active_original_ = nullptr;
}
void Heap::bind_original() {
    need(active_original_ != nullptr, "activate B336 adapter before binding original IAT");
    active_original_->bind_original_slots();
}
void Heap::bind_original_slots() {
    auto* alloc_slot = reinterpret_cast<volatile U*>(0x785270u);
    auto* free_slot = reinterpret_cast<volatile U*>(0x785268u);
    auto* virtual_slot = reinterpret_cast<volatile U*>(0x785290u);
    auto* enter_slot = reinterpret_cast<volatile U*>(0x7851dcu);
    auto* leave_slot = reinterpret_cast<volatile U*>(0x7851e0u);
    bind_slot(alloc_slot, kernel32<LPVOID (WINAPI*)(HANDLE,DWORD,SIZE_T)>("HeapAlloc"), &Heap::iat_heap_alloc, "B336 HeapAlloc IAT identity mismatch");
    bind_slot(free_slot, kernel32<BOOL (WINAPI*)(HANDLE,DWORD,LPVOID)>("HeapFree"), &Heap::iat_heap_free, "B336 HeapFree IAT identity mismatch");
    bind_slot(virtual_slot, kernel32<LPVOID (WINAPI*)(LPVOID,SIZE_T,DWORD,DWORD)>("VirtualAlloc"), &Heap::iat_virtual_alloc, "B336 VirtualAlloc IAT identity mismatch");
    bind_slot(enter_slot, kernel32<void (WINAPI*)(LPCRITICAL_SECTION)>("EnterCriticalSection"), &Heap::iat_enter, "B336 EnterCriticalSection IAT identity mismatch");
    bind_slot(leave_slot, kernel32<void (WINAPI*)(LPCRITICAL_SECTION)>("LeaveCriticalSection"), &Heap::iat_leave, "B336 LeaveCriticalSection IAT identity mismatch");
}

void* WINAPI Heap::iat_heap_alloc(HANDLE h, DWORD f, SIZE_T n) {
    if (!active_original_) callback_fail_fast();
    try { return reinterpret_cast<void*>(std::uintptr_t(active_original_->heap_alloc(addr(h), f, static_cast<U>(n)))); }
    catch (...) { callback_fail_fast(); }
}
BOOL WINAPI Heap::iat_heap_free(HANDLE h, DWORD f, LPVOID p) {
    if (!active_original_ || h != active_original_->heap_ || f != 0u || !p) callback_fail_fast();
    auto* self = active_original_;
    const U pointer = addr(p);
    try {
        need(pointer == self->ordinary_ && !self->ordinary_freed_, "B336 original HeapFree is not the output owner");
        need(self->memory_.r32(0x817554u) == 1016u && self->r32(self->metadata_ + 0x144u) == 0u,
             "B336 original HeapFree requires threshold1016 and zero live class-0 blocks");
        self->capture_ordinary_prefree();
        need(HeapValidate(h, 0, p) != FALSE && HeapSize(h, 0, p) >= self->ordinary_bytes_, "B336 native output prefree validation failed");
        const BOOL result = HeapFree(h, f, p);
        self->ordinary_free_bool_ = static_cast<U>(result);
        self->record({2u, f, self->ordinary_bytes_, self->identity(pointer), self->ordinary_free_bool_});
        if (result != FALSE) self->ordinary_freed_ = true;
        return result;
    } catch (...) { callback_fail_fast(); }
}
void* WINAPI Heap::iat_virtual_alloc(LPVOID p, SIZE_T n, DWORD t, DWORD f) {
    if (!active_original_) callback_fail_fast();
    try { return reinterpret_cast<void*>(std::uintptr_t(active_original_->virtual_alloc(p ? addr(p) : 0u, static_cast<U>(n), t, f))); }
    catch (...) { callback_fail_fast(); }
}
void WINAPI Heap::iat_enter(LPCRITICAL_SECTION p) {
    if (!active_original_ || p != active_original_->lock_) callback_fail_fast();
    try { active_original_->enter(); } catch (...) { callback_fail_fast(); }
}
void WINAPI Heap::iat_leave(LPCRITICAL_SECTION p) {
    if (!active_original_ || p != active_original_->lock_) callback_fail_fast();
    try { active_original_->leave(); } catch (...) { callback_fail_fast(); }
}

} // namespace ra2::platform::small_crt_heap336
