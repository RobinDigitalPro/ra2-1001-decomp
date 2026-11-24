#pragma once
#include "recovered/floating_b61_memory.hpp"
namespace ra2::recovered::b1645 {
using Memory=global_b26::Memory;
using Inputs=floating_b61::Inputs;
// The fixture binds its genuine owned physical surface and retains actual FP.
// Source assurance supplies explicitly synthetic I/O through this interface.
struct Api {
 virtual ~Api()=default;
 virtual unsigned surface()const=0;
 virtual unsigned is_lost(unsigned surface,platform::x87::State&)=0;
};
unsigned run(Memory&,const Inputs&,Api&);
}
