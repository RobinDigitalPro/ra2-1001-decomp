#pragma once
#include "platform/small_crt_heap_win32.hpp"
#include "recovered/global_b26_memory.hpp"
#include "recovered/recovery_b305.hpp"
#include <cstdint>

namespace ra2::recovered::recovery_b442 {
using Memory=ra2::recovered::global_b26::Memory;
using Inputs=ra2::recovered::global_b26::Inputs;
using GuestHeap=ra2::recovered::recovery_b305::GuestHeap;
std::uint32_t fun_0050cbb0(Memory&,Inputs&,GuestHeap&);
}
