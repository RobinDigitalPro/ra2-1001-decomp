#pragma once
#include "recovered/recovery_b1025.hpp"
#include "recovered/recovery_b1063.hpp"
namespace ra2::recovered::b1100{using b1063::Memory;using b1063::Inputs;using b1063::Heap;using b1063::State;using Api=b1025::Api;using Clock=DWORD(WINAPI*)();
struct FileObservation{std::array<unsigned char,100>file{};unsigned name{};};
struct PalObservation:FileObservation{unsigned payload{},object{},final_free{};DWORD bytes_read{};};
struct Observation{FileObservation shp,outer_pal;PalObservation inner;unsigned holder{},animation{};};
unsigned run(Memory&,const Inputs&,Heap&,Api&,Clock,State&,Observation&);}
