#pragma once
#include "recovered/global_b26_memory.hpp"
#include "recovered/leaf_memory.hpp"
#include <cstdint>
namespace ra2::recovered::recovery_b299 {
using Memory=ra2::recovered::global_b26::Memory;
using Inputs=ra2::recovered::global_b26::Inputs;
struct ClockOperations { std::uint32_t(*time_get_time)(void*); void* context; };
// time_get_time must invoke the verified live winmm!timeGetTime import.
// The adapter is an observation boundary, never a supplied timestamp.
std::uint32_t fun_00652810(Memory&,ra2::recovered::leaf::Memory&,
                           const Inputs&,const ClockOperations&);
}
