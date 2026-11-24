#pragma once
#include "recovered/global_b26_memory.hpp"
#include <array>
namespace ra2::recovered::b1194{
using Memory=global_b26::Memory;using Inputs=global_b26::Inputs;
using Caps=std::array<unsigned char,316>;using Mode=std::array<unsigned char,108>;
struct Api{virtual~Api()=default;virtual unsigned create(unsigned guid,unsigned output,unsigned outer)=0;virtual unsigned caps(unsigned object,Caps&hardware,unsigned software)=0;virtual unsigned mode(unsigned object,Mode&display)=0;virtual unsigned release(unsigned object)=0;};
struct Observation{unsigned calls=0,object=0,create_hr=~0u,caps_hr=~0u,mode_hr=~0u,release_result=~0u;Caps hardware{};Mode display{};};
unsigned run(Memory&,const Inputs&,Api&,Observation&);
}
