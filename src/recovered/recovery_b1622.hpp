#pragma once
#include "recovered/recovery_b1621.hpp"
namespace ra2::recovered::b1622 {
using U=b1621::U;using Memory=b1621::Memory;using Inputs=b1621::Inputs;using Heap=b1621::Heap;
U run(U root,Memory&,const Inputs&,Heap&,U arena_base);
}
