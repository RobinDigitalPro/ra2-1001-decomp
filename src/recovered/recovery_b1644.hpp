#pragma once
#include "recovered/floating_b61_memory.hpp"
namespace ra2::recovered::b1644 {
using Memory=global_b26::Memory;
using Inputs=floating_b61::Inputs;
// External provider contract. Providers retain actual FP in the supplied state;
// scoped Source assurance supplies explicitly synthetic I/O through this interface.
struct Api {
 virtual ~Api()=default;
 virtual unsigned clock_target()const=0;
 virtual unsigned surface()const=0;
 virtual unsigned clock(platform::x87::State&)=0;
 virtual unsigned is_lost(unsigned surface,platform::x87::State&)=0;
};
unsigned run(Memory&,const Inputs&,Api&);
}
