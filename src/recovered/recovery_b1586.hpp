#pragma once
#include "recovered/recovery_b1043.hpp"
#include <array>
namespace ra2::recovered::b1586 {using b1043::Memory;using b1043::Inputs;using b1043::Heap;using b1043::Observation;using Caller=std::array<unsigned,28>;static_assert(sizeof(Caller)==112,"exact standalone caller bytes");unsigned run(Memory&,const Inputs&,Caller&,Heap&,Observation&);}
