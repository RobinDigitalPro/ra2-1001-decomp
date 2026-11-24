#pragma once

#define NOMINMAX
#include <windows.h>

#include "recovered/recovery_b336.hpp"
#include "platform/small_crt_heap_algorithm.hpp"
#include <array>
#include <cstdint>
#include <vector>

namespace ra2::platform::small_crt_heap336 {

struct State {
    std::vector<std::uint8_t> table, metadata, arena;
    std::vector<std::array<std::uint32_t, 5>> events;
    std::vector<std::uint8_t> ordinary_prefree;
    std::array<std::vector<std::uint8_t>, 2> temp_prefree;
    std::uint32_t ordinary_free_bool{};
};
using Snapshot = State;

// Private B336 adapter. Small-block bookkeeping follows the accepted generic
// first-allocation route plus the disjoint B336 transitions in
// ../small_heap_b336_adapter.cpp. All OS allocation/free and lock operations
// reach the real Win32 APIs. This class is not part of the shared adapter.
class Heap final : public ra2::recovered::recovery_b336::Heap,
                   public ra2::platform::small_crt_heap::X86Memory,
                   public ra2::platform::small_crt_heap::RealWin32Api {
public:
    using Memory = ra2::recovered::global_b26::Memory;

    Heap(Memory&, std::uint32_t table, HANDLE, CRITICAL_SECTION*,
         std::uint32_t first_request, std::uint32_t seed = 0);
    ~Heap() override;
    Heap(const Heap&) = delete;
    Heap& operator=(const Heap&) = delete;

    std::uint32_t allocate(std::uint32_t bytes) override;
    std::uint32_t release(std::uint32_t pointer) override;
    void w8(std::uint32_t address, std::uint8_t value) override;
    std::uint8_t r8(std::uint32_t address) const override;
    std::uint32_t r32(std::uint32_t address) const override;
    void w32(std::uint32_t address, std::uint32_t value) override;

    std::uint32_t heap_alloc(std::uint32_t heap, std::uint32_t flags,
                             std::uint32_t bytes) override;
    std::uint32_t virtual_alloc(std::uint32_t address, std::uint32_t bytes,
                                std::uint32_t type,
                                std::uint32_t protection) override;

    void activate();
    void deactivate();
    static void bind_original();
    void activate_original_forwarders() { activate(); bind_original(); }
    void deactivate_original_forwarders() { deactivate(); }
    Snapshot snapshot(std::uint32_t no_live_result = 0u) const;
    std::uint32_t heap_free_bool() const noexcept { return ordinary_free_bool_; }

private:
    struct Event {
        std::uint32_t kind{}, flags{}, bytes{}, identity{}, result{};
    };

    Memory& memory_;
    std::uint32_t table_{};
    HANDLE heap_{};
    CRITICAL_SECTION* lock_{};
    std::uint32_t first_request_{}, seed_{};
    std::uint32_t metadata_{}, arena_{}, ordinary_{}, ordinary_bytes_{};
    bool committed_{}, ordinary_freed_{};
    std::uint32_t ordinary_free_bool_{};
    std::uint32_t lock_enters_{};
    std::array<std::uint32_t, 2> temporary_{};
    std::array<std::uint32_t, 2> temporary_span_{};
    std::array<std::vector<std::uint8_t>, 2> temporary_prefree_{};
    std::vector<std::uint8_t> ordinary_prefree_;
    std::array<std::uint32_t, 2> scratch_{};
    std::uint32_t small_allocations_{}, small_releases_{};
    std::vector<unsigned> requests_;
    std::vector<Event> events_;

    static Heap* active_original_;
    bool owned(std::uint32_t, std::uint32_t) const;
    std::uint32_t identity(std::uint32_t, std::uint32_t = 1) const;
    void record(Event);
    void enter();
    void leave();
    std::uint32_t free_ordinary(std::uint32_t);
    void capture_ordinary_prefree();
    void capture_temporary_prefree(std::uint32_t ordinal,
                                   std::uint32_t pointer);
    void bind_original_slots();

    static void* WINAPI iat_heap_alloc(HANDLE, DWORD, SIZE_T);
    static BOOL WINAPI iat_heap_free(HANDLE, DWORD, LPVOID);
    static void* WINAPI iat_virtual_alloc(LPVOID, SIZE_T, DWORD, DWORD);
    static void WINAPI iat_enter(LPCRITICAL_SECTION);
    static void WINAPI iat_leave(LPCRITICAL_SECTION);
};

} // namespace ra2::platform::small_crt_heap336
