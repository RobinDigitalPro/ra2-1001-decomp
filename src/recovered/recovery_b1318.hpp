#pragma once
#include "recovered/recovery_b1299.hpp"
namespace ra2::recovered::b1318 {
using Memory=ra2::recovered::b1299::Memory;using Inputs=ra2::recovered::b1299::Inputs;using Heap=ra2::recovered::b1299::Heap;
unsigned run(unsigned root,Memory&,const Inputs&,Heap&);
}
