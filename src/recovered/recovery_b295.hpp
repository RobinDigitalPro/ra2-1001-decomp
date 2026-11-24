#pragma once
#include "global_b26_memory.hpp"
namespace ra2::recovered::recovery_b295 {
using Memory=global_b26::Memory;
struct Inputs:global_b26::Inputs {std::uint32_t entry_esp=0;};
std::uint32_t fun_0076d686(Memory&,const Inputs&);
}
