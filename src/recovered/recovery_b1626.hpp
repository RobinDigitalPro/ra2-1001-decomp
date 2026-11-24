#pragma once

#include "recovered/recovery_b979.hpp"
#include "recovered/floating_b61_memory.hpp"

#include <cstdint>
#include <windows.h>

namespace ra2::recovered::b1626 {
using U = std::uint32_t;
using Memory = b979::Memory;
using Heap = b979::Heap;
using Inputs = floating_b61::Inputs;

// Local adapter for the exact Win32 APIs reached by this selected route.
// Defaults forward directly to the real APIs; a validation wrapper may record
// and forward those calls without changing the shared FileApi architecture.
struct Api {
    using GetDlgItemProc = HWND (WINAPI*)(HWND, int);
    using EnableWindowProc = BOOL (WINAPI*)(HWND, BOOL);
    using CreateFileAProc = HANDLE (WINAPI*)(LPCSTR, DWORD, DWORD,
        LPSECURITY_ATTRIBUTES, DWORD, DWORD, HANDLE);
    using GetFileSizeProc = DWORD (WINAPI*)(HANDLE, LPDWORD);
    using CloseHandleProc = BOOL (WINAPI*)(HANDLE);

    GetDlgItemProc get_dlg_item = &::GetDlgItem;
    EnableWindowProc enable_window = &::EnableWindow;
    CreateFileAProc create_file_a = &::CreateFileA;
    GetFileSizeProc get_file_size = &::GetFileSize;
    CloseHandleProc close_handle = &::CloseHandle;
};

U run(U root, Memory&, const Inputs&, Heap&, Api&);
} // namespace ra2::recovered::b1626
