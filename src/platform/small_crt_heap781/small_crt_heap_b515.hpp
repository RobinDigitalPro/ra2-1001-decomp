#pragma once
// Private B515 fork of the B406 first-region observer. It preserves the
// existing allocator operation model and adds only a live request20 snapshot;
// the B406 request20 terminal-free contract remains unchanged.
#define NOMINMAX
#include <windows.h>
#include "recovered/global_b26_memory.hpp"
#include "small_crt_heap_algorithm.hpp"
#include <array>
#include <vector>

namespace ra2::recovery_b515 {
using Memory=ra2::recovered::global_b26::Memory;
using X86Memory=ra2::platform::small_crt_heap781::X86Memory;
using RealWin32Api=ra2::platform::small_crt_heap781::RealWin32Api;
struct State {
    std::vector<unsigned char> table, metadata, arena;
    std::vector<std::array<unsigned,5>> events;
    unsigned return_offset=0;
    std::vector<unsigned char> ordinary;
};
// One fresh initialized CRT table and one successful small allocation.
// CRT bookkeeping is translated; all backing allocations and locks are real.
class Heap final : public X86Memory, public RealWin32Api {
public:
    Heap(Memory&, unsigned table, HANDLE heap, CRITICAL_SECTION* lock, unsigned request=24, unsigned seed=0);
    Heap(Memory&, unsigned table, HANDLE heap, CRITICAL_SECTION* lock,
         std::vector<unsigned> requests, std::vector<unsigned> arena_pointer_offsets, unsigned seed=0);
    ~Heap();
    unsigned allocate(unsigned bytes);
    unsigned allocate_building252(); // Exact ordinary5E0 before the one small4 child.
    unsigned building252_pointer() const;
    unsigned backing306_pointer() const; // Exact small16 then ordinary1804 route.
    void release(unsigned user); // exact class-1 temporary sequence only
    std::uint8_t r8(unsigned) const override;
    unsigned r32(unsigned) const override;
    void w8(unsigned,std::uint8_t) override;
    void w32(unsigned,unsigned) override;
    unsigned heap_alloc(unsigned,unsigned,unsigned) override;
    unsigned virtual_alloc(unsigned,unsigned,unsigned,unsigned) override;
    State snapshot(unsigned result) const;
    unsigned normalize_user_pointer(unsigned) const;
    unsigned first_user_pointer() const;
    unsigned user_pointer(unsigned ordinal) const;
    void activate();
    void deactivate();
    static void bind_original();
private:
    Memory& memory_;
    unsigned table_, metadata_=0, arena_=0;
    HANDLE heap_;
    CRITICAL_SECTION* lock_;
    bool committed_=false;
    unsigned request_;
    unsigned seed_, ordinary_=0, ordinary_bytes_=0;
    std::vector<unsigned> requests_,arena_pointer_offsets_;
    unsigned next_allocation_=0;
    unsigned tuple223_releases_=0;
    bool tuple223_sequence() const;
    void validate_tuple223_result(unsigned) const;
    unsigned string169_releases_=0;
    bool string169_sequence() const;
    void validate_string169_result(unsigned) const;
    bool empty173_released_=false;
    bool terminal_class2_=false; // Exact standalone {32}/{40}, span30 then last-live release.
    bool terminal_single9_=false; // Only the explicitly requested {9} temporary sequence.
    void validate_empty173_result() const;
    unsigned scratch_[2]{};
    std::vector<std::array<unsigned,5>> events_;
    bool owned(unsigned,unsigned) const;
    void enter();
    void leave();
    static Heap* active_;
    static void* WINAPI allocate_iat(HANDLE,DWORD,SIZE_T);
    static void* WINAPI virtual_iat(void*,SIZE_T,DWORD,DWORD);
    static void WINAPI enter_iat(CRITICAL_SECTION*);
    static void WINAPI leave_iat(CRITICAL_SECTION*);
};
void compare(const State&,const State&);
}
