#pragma once

#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"
#include <cstdint>
#include <string>

namespace ra2::recovery_b367 {

// Win32 boundary for the bounded file-read path. The native side binds these
// operations to forwarding wrappers; every wrapper calls the real Kernel32
// function. The destination is a real pointer returned by the attached heap.
class FileApi {
public:
    virtual ~FileApi() = default;
    virtual std::uint32_t create_existing_read(const std::string& path,
        std::uint32_t access, std::uint32_t share,
        std::uint32_t disposition, std::uint32_t attributes) = 0;
    virtual std::uint32_t get_file_size(std::uint32_t handle) = 0;
    virtual std::uint32_t set_file_pointer(std::uint32_t handle,
        std::uint32_t low, std::uint32_t high, std::uint32_t method) = 0;
    virtual bool read_file(std::uint32_t handle, std::uint32_t destination,
        std::uint32_t requested, std::uint32_t& transferred) = 0;
    virtual std::uint32_t close_handle(std::uint32_t handle) = 0;
    virtual std::uint32_t get_last_error() = 0;
};

// Selected route: A5AB48 starts null; A5AB4C/50/54 are valid caller-supplied
// cache values, so only PIPBRD.SHP is opened, sized, allocated, and read.
// The helper throws outside this finite success route instead of substituting
// a synthetic API result. Return value is the original full EAX at RET.
std::uint32_t fun_005ce490(recovered::global_b26::Memory& memory,
                           const recovered::global_b26::Inputs& inputs,
                           platform::ordinary_heap::Heap& heap,
                           FileApi& files);

} // namespace ra2::recovery_b367
