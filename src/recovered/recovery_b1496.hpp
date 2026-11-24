#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/x87_state.hpp"
namespace ra2::recovered::b1496 {
using Memory=global_b26::Memory;
struct Inputs:global_b26::Inputs {mutable platform::x87::State fp;};
struct ExceptionAPI {virtual void raise(std::uint32_t,std::uint32_t,std::uint32_t,const std::uint32_t*)=0;virtual ~ExceptionAPI()=default;};
std::uint32_t fun_007787f2(Memory&,const Inputs&,ExceptionAPI&);
}
