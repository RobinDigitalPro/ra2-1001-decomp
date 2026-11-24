#pragma once

#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"

#include <cstdint>

namespace ra2::recovered::recovery_b333 {
using Memory = ra2::recovered::global_b26::Memory;
using Inputs = ra2::recovered::global_b26::Inputs;
using Heap = ra2::platform::ordinary_heap::Heap;

// A native bridge must bind these to the actual descriptor's initialized
// CRITICAL_SECTION and Kernel32 ReadFile. The interface does not supply read
// results: read_file must forward the call to the real API.
struct FileOps {
    virtual ~FileOps() = default;
    virtual void enter(std::uint32_t critical_section) = 0;
    virtual void leave(std::uint32_t critical_section) = 0;
    virtual bool read_file(std::uint32_t handle, std::uint32_t buffer,
                           std::uint32_t request, std::uint32_t& bytes_read) = 0;
};

// Finite raw-binary ReadFile success route. Descriptor setup must come from
// original 0x779188; FileOps forwards real lock and ReadFile operations.
std::uint32_t fun_00780de3(Memory& memory, const Inputs& inputs, Heap& heap,
                           FileOps& file_ops);

} // namespace ra2::recovered::recovery_b333
