#pragma once

// Private adapter for the bounded recovery190 real-heap comparison fixture.
// Windows x86 only: returned values are raw pointers from the actual Win32 heap.
#define NOMINMAX
#include <windows.h>
#include "recovered/recovery_b979.hpp"
#include "platform/ordinary_heap979_observer.hpp"

#include <array>
#include <cstdint>
#include <map>
#include <stdexcept>
#include <vector>

namespace ra2::recovered::b979 {

enum class FreshBytesMode { patterned, capture, replay };

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

class HeapAdapter final : public ra2::recovered::b979::Heap {
public:
    // Attach to a real heap. `small_block_count` and `lock9` must point into
    // the mapped, initialized original globals used by the bounded fixture.
    // The original side attaches to the handle stored by original 0x773271;
    // the C++ side attaches to a real HeapCreate(0,4096,0) handle.
    HeapAdapter(HANDLE heap, volatile const std::uint32_t* small_block_count,
                CRITICAL_SECTION* lock9, bool owns_heap,
                FreshBytesMode fresh_bytes_mode = FreshBytesMode::patterned,
                std::uint32_t passive_byte_limit = 256u,
                std::uint32_t passive_record_limit = 64u);
    ~HeapAdapter() override;

    // Private method prototype: only provider PREINPUT, never postwrite output.
    struct FreshInput {
        std::uint32_t ordinal{};
        std::uint32_t rounded_size{};
        std::uint32_t flags{}; // IAT supplies actual flags/rounded size, not nominal size.
        std::array<std::uint8_t,256> bytes{};
    };
    const FreshInput& fresh_input(std::size_t k) const;
    std::size_t fresh_input_count() const noexcept { return fresh_input_count_; }
    // Read every captured byte, including the opt-in large-record tail.
    std::uint8_t fresh_input_byte(std::size_t k, std::uint32_t offset) const;
    void copy_fresh_inputs_from(const HeapAdapter& capture);
    void assert_replay_consumed() const;


    HeapAdapter(const HeapAdapter&) = delete;
    HeapAdapter& operator=(const HeapAdapter&) = delete;

    std::uint32_t allocate(std::uint32_t bytes) override;
    std::uint32_t allocate_reader() override;
    void free_reader(std::uint32_t) override;
    struct Snapshot {std::uint32_t ordinal;std::vector<std::uint8_t> bytes;};
    std::vector<Snapshot> snapshots;
    std::vector<std::uint32_t> allocation_flags;
    std::vector<std::uint32_t> addresses;
    void snapshot(std::uint32_t);
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
    HANDLE native_handle() const noexcept { return heap_; }
    bool owns_heap() const noexcept { return owns_heap_; }

    // Opt-in passive observations use caller-owned fixed storage. Bind only
    // outside a guest boundary with no live owners; nullptr disables. Default
    // heap behavior and actual SDK results are retained, never normalized.
    void set_passive_observer(passive979Ledger* ledger);

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
    FreshBytesMode fresh_bytes_mode_{FreshBytesMode::patterned};
    std::uint32_t passive_byte_limit_{256u};
    // Optional tail storage: allocated once during fixture construction, never
    // during capture/replay. Inline FreshInput::bytes remains exactly 256 bytes.
    std::vector<std::uint8_t> extended_fresh_bytes_;
    std::array<FreshInput,64> fresh_inputs_{};
    std::uint32_t passive_record_limit_{64u};
    std::vector<FreshInput> extra_fresh_inputs_;
    FreshInput& fresh_record(std::size_t k);
    const FreshInput& fresh_record(std::size_t k) const;
    std::size_t fresh_input_count_{};
    std::size_t replay_consumed_{};
    bool replay_available_{};
    void validate_fresh_request(std::uint32_t rounded_size, std::uint32_t flags) const;
    void apply_fresh_bytes(std::uint32_t base, std::uint32_t rounded_size,
                           std::uint32_t flags, std::uint32_t ordinal);

    passive979Ledger* observer_{};
    passive979Call* begin_passive(passive979Sdk, std::uint32_t target,
        std::uint32_t count, std::uint32_t a, std::uint32_t b=0u,
        std::uint32_t c=0u) noexcept;
    void finish_passive(passive979Call*, std::uint32_t result) noexcept;
    void observed_lock(Event::Kind, CRITICAL_SECTION*);

    std::map<std::uint32_t, Block> blocks_;
    std::vector<Event> events_;

    std::uint32_t record_allocation(void* pointer, std::uint32_t rounded_size, std::uint32_t flags=0);
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
