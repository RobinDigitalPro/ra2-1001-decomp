#pragma once
#include "recovered/recovery_b1279.hpp"
namespace ra2::recovered::b1299 {
using Memory=ra2::recovered::b1279::Memory;
using Inputs=ra2::recovered::b1279::Inputs;
using Heap=ra2::recovered::b1279::Heap;
unsigned run(unsigned root,Memory&,const Inputs&,Heap&);
}
