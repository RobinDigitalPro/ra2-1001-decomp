#pragma once
#include "recovered/recovery_b1048.hpp"
namespace ra2::recovered::b1053 {
using b1048::Memory;using b1048::Inputs;using b1048::State;
struct Observation{unsigned base_calls=0,membership_comparisons=0,boolean_stores=0;};
std::uint32_t fun_006fe9d0(Memory&,const Inputs&,State&,Observation&);
}
