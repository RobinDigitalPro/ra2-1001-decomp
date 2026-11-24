#pragma once
#define NOMINMAX
#include <windows.h>
#include "recovered/recovery_b979.hpp"
#include "platform/small_crt_heap1279_algorithm.hpp"
#include <array>
#include <cstdint>
#include <map>
#include <vector>

namespace ra2::platform::mixed_heap1279 {
using Memory = ra2::recovered::b979::Memory;
using U = std::uint32_t;
struct Event {
    enum Kind : U { user_alloc=1, user_free=2, enter9=3, leave9=4,
                    metadata_alloc=5, reserve=6, commit=7,
                    decommit=8, release_region=9, metadata_free=10,
                    table_free=11, heap_destroy=12 };
    Kind kind;
    U ordinal, argument, result;
    bool operator==(const Event& b) const {
        return kind==b.kind&&ordinal==b.ordinal&&argument==b.argument&&result==b.result;
    }
};
struct Owner { U address, span, ordinal; bool small; };

// B1279-only mixed CRT adapter. Portable and original instances use separate
// real Win32 heaps. No ordinary_heap979 contract is weakened.
class Heap final : public ra2::recovered::b979::Heap,
                   public ra2::platform::small_crt_heap1279::RealWin32Api {
public:
    Heap(Memory&, HANDLE, U table, CRITICAL_SECTION*, bool portable);
    ~Heap() override;
    Heap(const Heap&) = delete;
    Heap& operator=(const Heap&) = delete;
    U allocate(U) override;
    U release(U) override;
    U allocate_reader() override;
    void free_reader(U) override;
    U r8(U) const override;
    U r32(U) const override;
    void w8(U,U) override;
    void w32(U,U) override;
    U heap_alloc(U,U,U) override;
    U virtual_alloc(U,U,U,U) override;
    std::vector<Owner> live() const;
    std::vector<std::uint8_t> table_bytes() const;
    std::vector<std::uint8_t> metadata_bytes() const;
    std::vector<std::uint8_t> arena_bytes() const;
    std::vector<std::uint8_t> bytes(U,U) const;
    void reset_observation();
    void install_original_iat();
    void deactivate_original_iat();
    void teardown_portable();
    void begin_original_teardown();
    void end_original_teardown();
    U table() const { return table_; }
    U handle_address() const { return static_cast<U>(reinterpret_cast<std::uintptr_t>(handle_)); }
    U metadata() const { return metadata_; }
    U arena() const { return arena_; }
    const std::vector<Event>& events() const { return events_; }
    const std::vector<U>& addresses() const { return addresses_; }
    const std::vector<std::pair<U,std::vector<std::uint8_t>>>& prefree() const { return prefree_; }
private:
    class View final : public ra2::platform::small_crt_heap1279::X86Memory {
    public:
        explicit View(Heap& h):heap(h){}
        std::uint8_t r8(U a) const override { return static_cast<std::uint8_t>(heap.r8(a)); }
        U r32(U a) const override { return heap.r32(a); }
        void w8(U a,std::uint8_t v) override { heap.w8(a,v); }
        void w32(U a,U v) override { heap.w32(a,v); }
    private: Heap& heap;
    } view_{*this};
    struct Block { U span, ordinal; bool small; };
    Memory& memory_;
    HANDLE handle_;
    U table_, metadata_=0, arena_=0;
    CRITICAL_SECTION* lock_;
    bool portable_, committed_=false, active_=false, teardown_mode_=false,
         torn_down_=false;
    U small_allocs_=0, small_frees_=0, pending_live_=0;
    U pending_free_ordinal_=0;
    std::vector<std::uint8_t> pending_free_bytes_;
    std::array<U,2> scratch_{};
    std::map<U,Block> blocks_;
    std::vector<U> addresses_;
    std::vector<Event> events_;
    std::vector<std::pair<U,std::vector<std::uint8_t>>> prefree_;
    U record_user(U,U,bool);
    U ordinary_alloc(U);
    U ordinary_free(U);
    void enter();
    void leave();
    bool owns(U,U) const;
    void require_live(U,U) const;
    static Heap* active_original_;
    static void* WINAPI iat_heap_alloc(HANDLE,DWORD,SIZE_T);
    static BOOL WINAPI iat_heap_free(HANDLE,DWORD,LPVOID);
    static void* WINAPI iat_virtual_alloc(LPVOID,SIZE_T,DWORD,DWORD);
    static BOOL WINAPI iat_virtual_free(LPVOID,SIZE_T,DWORD);
    static BOOL WINAPI iat_heap_destroy(HANDLE);
    static void WINAPI iat_enter(LPCRITICAL_SECTION);
    static void WINAPI iat_leave(LPCRITICAL_SECTION);
};
}
