#pragma once
#include "recovered/recovery_b1303.hpp"
namespace ra2::recovered::b1442 {
using Memory=b1303::Memory;using Inputs=b1303::Inputs;using Heap=b1303::Heap;
std::uint32_t run(std::uint32_t,Memory&,const Inputs&,Heap&);
}
