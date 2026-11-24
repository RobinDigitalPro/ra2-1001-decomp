#pragma once

#include "platform/small_heap_file_recipe249.hpp"
#include "platform/small_crt_heap_win32.hpp"

#include <cstdint>

namespace ra2::platform::file_heap249 {

// Every function pointer must forward to the real Win32 API. A private probe
// may wrap it only to record arguments/results and then call the saved target.
struct FileApi {
    using CreateFileAProc = HANDLE (WINAPI*)(LPCSTR, DWORD, DWORD,
        LPSECURITY_ATTRIBUTES, DWORD, DWORD, HANDLE);
    using ReadFileProc = BOOL (WINAPI*)(HANDLE, LPVOID, DWORD, LPDWORD, LPOVERLAPPED);
    using CloseHandleProc = BOOL (WINAPI*)(HANDLE);
    CreateFileAProc create_file_a = &::CreateFileA;
    ReadFileProc read_file = &::ReadFile;
    CloseHandleProc close_handle = &::CloseHandle;
};

// Private bridge for the exact 32DA70 nine-request recipe. The first 0x0c
// request uses the existing real-API CRT bootstrap; later operations are the
// separately translated 3736d3/3733a8 one-chunk class-63 paths.
class FileHeap final : public Memory {
public:
    using Bootstrap = ra2::platform::small_crt_heap::Heap;
    FileHeap(ra2::recovered::global_b26::Memory& globals, Bootstrap& bootstrap,
             HANDLE crt_heap);
    ~FileHeap() override;

    std::uint32_t allocate(std::uint32_t request);
    void release(std::uint32_t user);
    std::uint32_t heap_alloc(std::uint32_t heap, std::uint32_t flags,
                             std::uint32_t bytes);

    std::uint8_t r8(std::uint32_t address) const override;
    std::uint32_t r32(std::uint32_t address) const override;
    void w8(std::uint32_t address, std::uint8_t value) override;
    void w32(std::uint32_t address, std::uint32_t value) override;

    std::uint32_t line_buffer() const { return line_buffer_; }
    void free_line_buffer();

private:
    ra2::recovered::global_b26::Memory& globals_;
    Bootstrap& bootstrap_;
    HANDLE crt_heap_;
    std::uint32_t line_buffer_=0;
    std::uint32_t line_buffer_size_=0;
    std::uint32_t allocations_=0;
    std::uint32_t releases_=0;
    std::uint32_t allocation_ptrs_[9]{};
    void lock() const;
    void unlock() const;
};

} // namespace ra2::platform::file_heap249
