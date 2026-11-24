#pragma once
#include "recovered/recovery_b1025.hpp"
#include "recovered/recovery_b1063.hpp"
namespace ra2::recovered::b1090 {using b1063::Memory;using b1063::Inputs;using b1063::Heap;using b1063::State;using Api=b1025::Api;
struct Observation{std::array<unsigned char,100>file{};unsigned name{},payload{},object{},final_free{};DWORD bytes_read{};};
unsigned run(Memory&,const Inputs&,Heap&,Api&,State&,Observation&);
}
