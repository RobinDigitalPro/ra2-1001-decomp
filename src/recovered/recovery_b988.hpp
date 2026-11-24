#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/audio988.hpp"
#include <cstdint>
namespace ra2::recovered::recovery_b988 {
using global_b26::Memory;using global_b26::Inputs;using ra2::platform::audio988::Boundary;using ra2::platform::audio988::Format;
struct FormatObservation{Format bytes{};std::uintptr_t pointer=0;};
std::uint32_t run(Memory&,const Inputs&,Boundary&,std::uint32_t,FormatObservation&);
std::uint32_t fun_0040a6e0(Memory&,const Inputs&,Boundary&,FormatObservation&);
std::uint32_t fun_0040a770(Memory&,const Inputs&,Boundary&,FormatObservation&);
}
