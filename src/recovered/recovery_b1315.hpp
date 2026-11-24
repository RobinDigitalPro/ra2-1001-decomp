#pragma once
#include "recovered/recovery_b1296.hpp"
namespace ra2::recovered::b1315 {
using Memory=b1296::Memory;
using Inputs=b1296::Inputs;
using Heap=b1296::Heap;
unsigned run(unsigned root,Memory&,const Inputs&,Heap&);
}
