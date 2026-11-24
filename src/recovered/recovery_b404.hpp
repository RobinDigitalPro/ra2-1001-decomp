#pragma once
#include "recovered/floating_b61_memory.hpp"
#include "recovered/allocation_wrappers.hpp"
#include <cstdint>

namespace ra2::recovered::constructors404 {
using floating_b61::Memory;
using floating_b61::Inputs;
struct HeapMemoryOperations {
    std::uint32_t (*read32)(std::uint32_t address, void* context);
    std::uint32_t (*read8)(std::uint32_t address, void* context);
    void (*write32)(std::uint32_t address, std::uint32_t value, void* context);
    void (*write8)(std::uint32_t address, std::uint32_t value, void* context);
    void* context;
};
struct Operations {
    AllocationWrapperOperations heap;
    HeapMemoryOperations heap_memory;
    std::uint32_t tick_result;
    std::uint32_t stack_base;
};
// Bounded successful constructor route: 0x10 small-CRT allocation followed by
// the existing protocol's 0x1804 ordinary allocation, plus the original
// WinMM timeGetTime import through the accepted B30 wrapper.
std::uint32_t fun_00626470(Memory&, const Inputs&, const Operations&);
}
