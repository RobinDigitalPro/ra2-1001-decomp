#pragma once
#define NOMINMAX
#include <windows.h>
#include <objidl.h>
#include <ole2.h>
#include <propidl.h>
#include "recovered/global_b26_memory.hpp"
namespace ra2::recovered::b1128{
using Memory=global_b26::Memory;using Inputs=global_b26::Inputs;
struct Api{decltype(&::MultiByteToWideChar)mbtowide{};decltype(&::WideCharToMultiByte)widetomb{};decltype(&::StgOpenStorage)open{};};
struct Observation{HRESULT missing_open{};ULONG released_sets{},released_storage{};unsigned streams{},units{},converted{};};
inline constexpr GUID iid_sets{0x13au,0u,0u,{0xc0u,0u,0u,0u,0u,0u,0u,0x46u}};
inline constexpr GUID summary{0xf29f85e0u,0x4ff9u,0x1068u,{0xabu,0x91u,8u,0u,0x2bu,0x27u,0xb3u,0xd9u}};
unsigned run(unsigned root,Memory&,const Inputs&,Api&,Observation&);
}
