#pragma once
#include "recovered/global_b26_memory.hpp"
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <cstdint>
#include <string_view>

namespace ra2::recovered::recovery_b251 {
using Memory = ra2::recovered::global_b26::Memory;
struct Heap {
    virtual ~Heap() = default;
    virtual std::uint32_t allocate(std::uint32_t request) = 0;
    virtual void release(std::uint32_t pointer) = 0;
    virtual std::uint8_t r8(std::uint32_t address) const = 0;
    virtual void w8(std::uint32_t address, std::uint8_t value) = 0;
    virtual void w32(std::uint32_t address, std::uint32_t value) = 0;
};
struct FileApi {
    using CreateFileProc=HANDLE (WINAPI*)(LPCSTR,DWORD,DWORD,LPSECURITY_ATTRIBUTES,DWORD,DWORD,HANDLE);
    using ReadFileProc=BOOL (WINAPI*)(HANDLE,LPVOID,DWORD,LPDWORD,LPOVERLAPPED);
    using CloseHandleProc=BOOL (WINAPI*)(HANDLE);
    CreateFileProc create_file=&::CreateFileA;
    ReadFileProc read_file=&::ReadFile;
    CloseHandleProc close_handle=&::CloseHandle;
};
struct Document {
    std::uint32_t filename_clone=0, line_buffer=0;
    std::uint32_t manager=0, selector_z=0;
    std::uint32_t section=0, section_name=0, node=0, value=0, key=0;
    std::uint32_t key_table=0, section_table=0;
};
// Positive one-section/one-key parser route for exactly [Intro]/ItemMax=-1.
Document parse_intro_itemmax(Memory&, Heap&, FileApi&, std::uint32_t manager_guest,
                             std::uint32_t filename_pointer_slot,
                             std::uint32_t selector_pointer_slot);
// DDA10 minimal route: consumes the still-live graph and returns a 0x70 object.
std::uint32_t build_intro_object(Memory&, Heap&, const Document&);
// Original 0x50ad20 cleanup after DDA10 returns. Does not free returned object.
void destroy_document(Memory&, Heap&, const Document&);
// RVA0xDD8F0, plain RET. Finite successful Intro/ItemMax=-1 route.
// manager_guest denotes the caller-local original frame at entry ESP-0x9C.
using Inputs = ra2::recovered::global_b26::Inputs;
std::uint32_t fun_004dd8f0(Memory&, const Inputs&, Heap&, FileApi&,
                         std::uint32_t manager_guest);
} // namespace ra2::recovered::recovery_b251
