#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/small_crt_heap_win32.hpp"
namespace ra2::recovered::recovery_b291 {
using Memory=global_b26::Memory; using Inputs=global_b26::Inputs; using Heap=platform::small_crt_heap::Heap;
std::uint32_t fun_00522f30(Memory&,Inputs&,Heap&);
}
