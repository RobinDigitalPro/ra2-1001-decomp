#pragma once
#include "recovered/recovery_b1062.hpp"
namespace ra2::recovered::b1204 {
using Memory=b1062::Memory;using Inputs=b1062::Inputs;using Heap=b1062::Heap;using Api=b1062::Api;
struct Observation{b1062::Observation probe,parser;};
unsigned run(Memory&,const Inputs&,Heap&,Api&,Observation&);
}
