#pragma once
#include "recovered/recovery_b1025.hpp"
#include "platform/x87_state.hpp"
namespace ra2::recovered::b1098{using b979::Memory;using b979::Inputs;using b979::Heap;using Api=b1025::Api;using Clock=DWORD(WINAPI*)();using ra2::platform::x87::State;
struct Observation{std::array<unsigned char,100>file{};unsigned name{},owner{},filename_free{};};
unsigned run(Memory&,const Inputs&,Heap&,Api&,Clock,State&,Observation&,unsigned root);}
