#pragma once
#include "recovered/recovery_b979.hpp"
namespace ra2::recovered::b1279 {
using Memory=b979::Memory;
using Inputs=b979::Inputs;
using Heap=b979::Heap;
unsigned run(unsigned root,Memory&,const Inputs&,Heap&);
}
