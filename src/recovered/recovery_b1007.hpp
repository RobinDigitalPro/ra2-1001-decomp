#pragma once
#include "recovered/recovery_b1000.hpp"
#include "platform/crt_open1007.hpp"
namespace ra2::recovered::b1007 {
using global_b26::Memory;using global_b26::Inputs;using Api=ra2::platform::crt_open1007::Api;
struct Observation{SECURITY_ATTRIBUTES security{};HANDLE handle=INVALID_HANDLE_VALUE;};
static_assert(sizeof(SECURITY_ATTRIBUTES)==12u,"1007 x86 security attributes ABI");
std::uint32_t fun_00779188(Memory&,Inputs&,Api&,Observation&);
std::uint32_t fun_007767f6(Memory&,Inputs&,Api&,Observation&);
}
