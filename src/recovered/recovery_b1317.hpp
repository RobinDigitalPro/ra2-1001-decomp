#pragma once
#include "recovered/recovery_b1315.hpp"
namespace ra2::recovered::b1317 {
using Memory=b1315::Memory;
using Inputs=b1315::Inputs;
using Heap=b1315::Heap;
unsigned run(unsigned root,Memory&,const Inputs&,Heap&);
}
