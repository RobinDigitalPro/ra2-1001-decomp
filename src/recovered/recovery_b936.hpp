#pragma once
#include "recovered/floating_b61_memory.hpp"
#include <cstdint>

namespace ra2::recovered::recovery_b936 {
using floating_b61::Inputs;
using floating_b61::Memory;

// Platform boundary shaped to the three imported Win32 calls reached by the
// original body. Buffers use the original 16-byte SYSTEMTIME and 172-byte
// TIME_ZONE_INFORMATION layouts; callbacks must forward actual API results.
struct Ops {
    void* context = nullptr;
    void (*get_local_time)(void*, std::uint8_t* system_time16) = nullptr;
    void (*get_system_time)(void*, std::uint8_t* system_time16) = nullptr;
    std::uint32_t (*get_time_zone_information)(void*, std::uint8_t* zone_info172) = nullptr;
};

std::uint32_t fun_0076f1bf(Memory&, const Inputs&, const Ops&);
}
