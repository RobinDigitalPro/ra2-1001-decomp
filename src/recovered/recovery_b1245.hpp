#pragma once
#include "recovered/recovery_b979.hpp"
namespace ra2::recovered::b1245 {
using Memory=b979::Memory;using Inputs=b979::Inputs;using Heap=b979::Heap;using FileApi=b979::FileApi;
struct FindApi{virtual ~FindApi()=default;virtual HANDLE first(const char*,WIN32_FIND_DATAA*)=0;virtual BOOL next(HANDLE,WIN32_FIND_DATAA*)=0;virtual BOOL close(HANDLE)=0;};
struct Observation{unsigned filename=0,ini=0,reader=0,allocations=0,sections=0,keys=0,battle_callbacks=0,final_free_bool=0,find_close_bool=0;};
unsigned run(unsigned,Memory&,const Inputs&,Heap&,FileApi&,FindApi&,Observation&);
}
