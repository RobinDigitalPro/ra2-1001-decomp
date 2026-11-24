#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/ole_property1010.hpp"
#include <array>
namespace ra2::recovered::b1010 {
using global_b26::Memory;using global_b26::Inputs;
struct Observation{std::array<std::uint8_t,16>variant{};std::uint32_t open_pointer=0,live_vtable=0;std::uint32_t spec_kind=0,spec_id=0;HRESULT open_result=E_FAIL,read_result=E_FAIL;};
std::uint32_t fun_006516b0(Memory&,Inputs&,Observation&);
std::uint32_t fun_00651850(Memory&,Inputs&,Observation&);
std::uint32_t fun_00652010(Memory&,Inputs&,Observation&);
}
