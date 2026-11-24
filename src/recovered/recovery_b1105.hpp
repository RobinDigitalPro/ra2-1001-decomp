#pragma once
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include "recovered/global_b26_memory.hpp"
#include <array>
namespace ra2::recovered::b1105{using Memory=global_b26::Memory;using Inputs=global_b26::Inputs;
struct Api{decltype(&::EnterCriticalSection)enter{};decltype(&::LeaveCriticalSection)leave{};decltype(&::GetCPInfo)cp{};decltype(&::GetStringTypeA)type{};decltype(&::LCMapStringA)map{};};
struct Observation{alignas(16)std::array<unsigned char,1536>scratch{};unsigned helper_bp()const{return unsigned(reinterpret_cast<std::uintptr_t>(scratch.data()))+0x550u;}unsigned root_cp()const{return helper_bp()+0x14u;}};
unsigned run(Memory&,const Inputs&,const Api&,Observation&);}
