#pragma once
#include "recovered/recovery_b979.hpp"
namespace ra2::recovered::b1249 {
using Memory=b979::Memory;using Inputs=b979::Inputs;using Heap=b979::Heap;using FileApi=b979::FileApi;
// An actual call-boundary address, independently captured by the x86 bridge.
// It supplies no private stack contents and never contains original EAX.
struct CallFrame{unsigned entry_esp=0;};
struct Observation{unsigned filename=0,reader=0,index=0,positive_assignments=0,name_callbacks=0,final_filename_free_bool=0;};
unsigned run(unsigned,Memory&,const Inputs&,const CallFrame&,Heap&,FileApi&,Observation&);
}
