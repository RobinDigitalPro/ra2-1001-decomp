#pragma once

// Private adapter for the bounded recovery190 real-heap comparison fixture.
// Windows x86 only: returned values are raw pointers from the actual Win32 heap.
#define NOMINMAX
#include <windows.h>
#include "platform/ordinary_heap.hpp"

#include <cstdint>
#include <map>
#include <stdexcept>
#include <vector>

namespace ra2::platform::ordinary_heap {

struct Event {
    enum class Kind : std::uint8_t { allocate, release, enter_lock, leave_lock };
    Kind kind{};
    std::uint32_t ordinal{}; // allocation identity, assigned in allocation order
    std::uint32_t size{};    // rounded HeapAlloc request; zero for lock events
    std::uint32_t address{}; // raw allocation or CRITICAL_SECTION address
    std::uint32_t result{};  // pointer for allocate, actual BOOL for release
};

struct AllocationIdentity {
    std::uint32_t ordinal{};
    std::uint32_t offset{};
};

class HeapAdapter final : public ra2::platform::ordinary_heap::Heap {
public:
    // Attach to a real heap. `small_block_count` and `lock9` must point into
    // the mapped, initialized original globals used by the bounded fixture.
    // The original side attaches to the handle stored by original 0x773271;
    // the C++ side attaches to a real HeapCreate(0,4096,0) handle.
    HeapAdapter(HANDLE heap, volatile const std::uint32_t* small_block_count,
                CRITICAL_SECTION* lock9, bool owns_heap);
    ~HeapAdapter() override;

    HeapAdapter(const HeapAdapter&) = delete;
    HeapAdapter& operator=(const HeapAdapter&) = delete;

    std::uint32_t allocate(std::uint32_t bytes) override;
    std::uint32_t release(std::uint32_t pointer) override;
    std::uint32_t r8(std::uint32_t address) const override;
    std::uint32_t r32(std::uint32_t address) const override;
    void w8(std::uint32_t address, std::uint32_t value) override;
    void w32(std::uint32_t address, std::uint32_t value) override;

    // Install only after the original CRT heap and lock initializers have run.
    // Each slot must already contain the verified real Kernel32 address. The
    // wrappers forward to that same API and instrument real calls.
    void install_original_iat_forwarders(volatile std::uint32_t* heap_alloc_slot,
                                         volatile std::uint32_t* heap_free_slot,
                                         volatile std::uint32_t* enter_cs_slot,
                                         volatile std::uint32_t* leave_cs_slot);
    static void activate_original_forwarders(HeapAdapter& context);
    static void deactivate_original_forwarders(HeapAdapter& context);

    // Compare pointer-bearing effects only through (allocation ordinal, byte
    // offset). Addresses outside this context's live allocations are rejected.
    AllocationIdentity identify(std::uint32_t address, std::uint32_t width = 1) const;

    struct LiveBlock { std::uint32_t address,bytes,ordinal; };
    std::vector<LiveBlock> live() const;
    const std::vector<Event>& events() const noexcept { return events_; }
    std::size_t live_blocks() const noexcept { return blocks_.size(); }
    void reset_observation();
    // Fixture setup only: reserve storage before an observed guest call.
    void reserve_observation_events(std::size_t capacity) { events_.reserve(capacity); }
    HANDLE native_handle() const noexcept { return heap_; }
    bool owns_heap() const noexcept { return owns_heap_; }

    // Explicit destruction is useful to make the fixture's lifetime visible.
    // It calls the real HeapDestroy and never destroys a handle it does not own.
    void destroy();

private:
    struct Block {
        std::uint32_t bytes{};
        std::uint32_t ordinal{};
    };

    HANDLE heap_{};
    volatile const std::uint32_t* small_block_count_{};
    CRITICAL_SECTION* lock9_{};
    bool owns_heap_{};
    bool destroyed_{};
    std::uint32_t next_ordinal_{};
    std::map<std::uint32_t, Block> blocks_;
    std::vector<Event> events_;

    std::uint32_t record_allocation(void* pointer, std::uint32_t rounded_size);
    BOOL record_release(void* pointer);
    void check_live_range(std::uint32_t address, std::uint32_t width) const;
    void seed_payload(std::uint32_t base, std::uint32_t bytes,
                      std::uint32_t ordinal);
    void require_ready() const;
    void require_zero_small_block_count() const;
    void push_lock_event(Event::Kind kind, CRITICAL_SECTION* cs);

    static HeapAdapter* active_original_;
    static void* WINAPI iat_heap_alloc(HANDLE heap, DWORD flags, SIZE_T bytes);
    static BOOL WINAPI iat_heap_free(HANDLE heap, DWORD flags, LPVOID pointer);
    static void WINAPI iat_enter_critical_section(LPCRITICAL_SECTION cs);
    static void WINAPI iat_leave_critical_section(LPCRITICAL_SECTION cs);
};

// Make and return a genuine private portable-side heap. Critical-section 9 is
// the real initialized lock shared by the serial comparison schedule.
HANDLE create_portable_heap();

} // namespace ra2::platform::ordinary_heap
