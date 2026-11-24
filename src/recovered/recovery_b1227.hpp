#pragma once
#include "recovered/recovery_b1198.hpp"
namespace ra2::recovered::b1227 {
using b1198::Memory;using b1198::Inputs;using b1198::Api;
struct Observation{unsigned clips=0,pixels=0,api_calls=0;};
unsigned run(Memory&,const Inputs&,Api&,Observation&);
}
