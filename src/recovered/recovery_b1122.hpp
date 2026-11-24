#pragma once
// Private uncompiled semantic draft. No acceptance/ABI claim.
#include "recovered/numeric_b71.hpp"
#include "recovered/recovery_b1025.hpp"
namespace ra2::recovered::b1122 {
using Memory=global_b26::Memory;using Heap=b979::Heap;
using Inputs=global_b26::Inputs;using Api=b1025::Api;
struct Observation{std::array<unsigned char,100>file{};unsigned filename{},payload{},length{},final_free{};DWORD bytes_read{};};
unsigned run(unsigned root,Memory&,const Inputs&,Heap&,Api&,ra2::platform::x87::State&,Observation&);
unsigned rebuild(Memory&,unsigned owner,Heap&,ra2::platform::x87::State&);
}
