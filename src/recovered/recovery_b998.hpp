#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"
#include "platform/writer998.hpp"
#include <array>
#include <string>
namespace ra2::recovered::b998 {
using global_b26::Memory;using global_b26::Inputs;using ra2::platform::ordinary_heap::Heap;using FileApi=ra2::platform::writer998::Api;
struct Observation{std::array<std::string,8>chunks;};
std::uint32_t fun_00469510(Memory&,const Inputs&,Heap&,FileApi&,Observation&);
}
