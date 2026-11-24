#pragma once
#include "recovered/recovery_b108_machine.hpp"
namespace ra2::recovered::recovery_b711 {
using recovery_b108::Memory; using recovery_b108::State; using recovery_b108::Frame; using recovery_b108::Operations;
struct Result { std::uint32_t eax; std::array<std::uint32_t,16> args; };
void fun_005f5d00(Memory&,State&,Frame&,const Operations&);
Result run(Memory&,const floating_b61::Inputs&);
std::uint32_t call_root(Memory&,const floating_b61::Inputs&);
}
