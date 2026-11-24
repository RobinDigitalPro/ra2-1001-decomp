#pragma once
#include "recovered/recovery_b979.hpp"
#include <string>
namespace ra2::recovered::b1146{
using Memory=b979::Memory;using Inputs=b979::Inputs;using Heap=b979::Heap;using FileApi=b979::FileApi;
struct FileState{unsigned vptr=0x785658u,mode=1u,bias=0u,extent=0xffffffffu,handle=0xffffffffu,name=0u;unsigned char owned=1u,buffered=0u;};
struct Observation{FileState file;unsigned record=0u,server=0u,positive_reads=0u,default_reads=0u;};
// Static finite reconstruction of RVA32D230, not yet compiled or executed.
// InputB0DE90 is one realowned prepared section-name holder; callerECX is fresh8B.
unsigned run(Memory&,const Inputs&,Heap&,FileApi&,Observation&);
// Configuration-owner fixture cleanup from72EC80(flags0)/630AB0/630CC0/72EC50.
unsigned cleanup(Memory&,unsigned wrapper,Heap&);
}
