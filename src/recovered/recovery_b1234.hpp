#pragma once
#include "recovered/recovery_b979.hpp"
namespace ra2::recovered::b1234 {
using Memory=b979::Memory;using Inputs=b979::Inputs;using Heap=platform::ordinary_heap::Heap;
struct Provider {virtual ~Provider()=default;virtual void enter12()=0;virtual void leave12()=0;virtual unsigned probe()=0;virtual unsigned compare_names(const char*,const char*)=0;};
unsigned run(Memory&,Inputs&,Heap&,Provider&,unsigned root);
}
