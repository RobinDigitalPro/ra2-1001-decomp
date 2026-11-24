#pragma once
#include "recovered/floating_b61_memory.hpp"
namespace ra2::recovered::b1463 {
using Memory=global_b26::Memory;using Inputs=floating_b61::Inputs;
// Virtualentry only names the produced private128-byte buffer for Memory; no incoming private bytes are seeded/read.
std::uint32_t fun_00743f10(Memory&,const Inputs&,std::uint32_t virtual_entry);
std::uint32_t produce_record(Memory&,const Inputs&);
}
