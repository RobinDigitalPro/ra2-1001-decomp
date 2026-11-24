#pragma once
#include "recovered/recovery_b108_machine.hpp"
namespace ra2::recovered::recovery_b712 {
using recovery_b108::Memory; using recovery_b108::State; using recovery_b108::Frame; using recovery_b108::Operations;
void fun_00534f10(Memory&,State&,Frame&,const Operations&);
struct Result {std::uint32_t eax;std::array<std::uint32_t,16> args;};
Result run(Memory&,const floating_b61::Inputs&);
std::uint32_t call_root(Memory&,const floating_b61::Inputs&);
}
