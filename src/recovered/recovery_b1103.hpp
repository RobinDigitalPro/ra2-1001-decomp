#pragma once
#include "recovered/recovery_b1090.hpp"
namespace ra2::recovered::b1103{using b1090::Memory;using b1090::Inputs;using b1090::Heap;using b1090::Api;using b1090::State;
struct Observation{b1090::Observation palette;unsigned zoom{},target{},final_free{};};unsigned run(Memory&,const Inputs&,Heap&,Api&,State&,Observation&);}
