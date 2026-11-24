#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/x87_state.hpp"
namespace ra2::recovered::b1499 {
using U=std::uint32_t;using Memory=global_b26::Memory;
struct Inputs:global_b26::Inputs{mutable platform::x87::State fp;};
struct alignas(8) Variant {std::array<unsigned char,16>bytes;};
struct Params{Variant*args;U*named;U count,named_count;};
struct Exception{std::array<unsigned char,32>bytes;};
struct DispatchAPI{virtual U length(const std::uint16_t*)=0;virtual void initialize(Variant&)=0;virtual U invoke(U,U,U,Params&,Variant&,Exception&,U&)=0;virtual~DispatchAPI()=default;};
U fun_0078131b(Memory&,const Inputs&,DispatchAPI&);
}
