#pragma once
#include "recovered/recovery_b979.hpp"
namespace ra2::recovered::b1029 {
using Memory=ra2::recovered::b979::Memory;using Inputs=ra2::recovered::b979::Inputs;using Heap=ra2::recovered::b979::Heap;
struct Case{unsigned root,n,seed;};
unsigned run(Memory&,const Inputs&,Heap&,unsigned);
unsigned fun_004cf7e0(Memory&,const Inputs&,Heap&);unsigned fun_0073be50(Memory&,const Inputs&,Heap&);unsigned fun_005749c0(Memory&,const Inputs&,Heap&);unsigned fun_00678120(Memory&,const Inputs&,Heap&);unsigned fun_00679440(Memory&,const Inputs&,Heap&);
}
