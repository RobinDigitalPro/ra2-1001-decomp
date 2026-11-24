#pragma once
#include "recovered/floating_b61_memory.hpp"
#include <array>
namespace ra2::recovered::b1643 {
using Memory=global_b26::Memory;
using Inputs=floating_b61::Inputs;
// External provider contract. The native fixture binds authentic owned USER32
// and DirectDraw providers; Source assurance supplies explicitly synthetic I/O.
// window writes only its declared rectangle/point output and retains actual FP.
struct Api {
 virtual ~Api()=default;
 virtual const std::array<unsigned,4>& targets()const=0;
 virtual unsigned window(unsigned kind,Memory&,unsigned receiver,unsigned argument,platform::x87::State&)=0;
 virtual unsigned is_lost(unsigned surface,platform::x87::State&)=0;
 virtual unsigned surface()const=0;
};
unsigned run(Memory&,const Inputs&,Api&);
}
