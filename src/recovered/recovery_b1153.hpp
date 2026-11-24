#pragma once
#include "recovered/recovery_b979.hpp"
namespace ra2::recovered::b1153{
using Memory=b979::Memory;using Inputs=b979::Inputs;using Heap=b979::Heap;
// RVA 268020, explicit nonnull text arguments only. Full self EAX, RET16.
unsigned run(Memory&,const Inputs&,Heap&);
// Exact matching integer-vector clear 669150, RET0, raw HeapFree EAX.
unsigned clear(Memory&,unsigned receiver,Heap&);
}
