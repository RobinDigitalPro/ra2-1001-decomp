#pragma once
#include "recovered/global_b26_memory.hpp"
#include <array>
namespace ra2::recovered::b1191{
using Memory=global_b26::Memory;using Inputs=global_b26::Inputs;using Descriptor=std::array<unsigned char,316>;
struct Api{virtual~Api()=default;virtual unsigned get_caps(unsigned receiver,Descriptor&hardware,unsigned software)=0;};
struct Observation{unsigned provider_calls=0;Descriptor descriptor{};unsigned hresult=0;};
unsigned run(Memory&,const Inputs&,Api&,Observation&);
}
