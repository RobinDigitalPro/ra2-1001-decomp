#pragma once
#include "recovered/global_b26_memory.hpp"
#include <array>
namespace ra2::recovered::b1198{
using Memory=global_b26::Memory;using Inputs=global_b26::Inputs;using Descriptor=std::array<unsigned char,108>;
struct Api{virtual~Api()=default;virtual unsigned is_lost(unsigned surface)=0;virtual unsigned lock(unsigned surface,Descriptor&)=0;virtual unsigned unlock(unsigned surface,unsigned pixels)=0;};
struct Observation{unsigned calls=0,lost_hresult=~0u,operation_hresult=~0u;Descriptor descriptor{};};
unsigned run(Memory&,const Inputs&,Api&,unsigned root,Observation&);
}
