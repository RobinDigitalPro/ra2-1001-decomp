#pragma once
#include "recovered/recovery_b979.hpp"
namespace ra2::recovered::b1258 {
using Memory=b979::Memory;using Inputs=b979::Inputs;using Heap=b979::Heap;using FileApi=b979::FileApi;
struct Observation{unsigned owner=0,index_name=0,file=0,bag_name=0,index=0,bag_handle=0,index_handle=0,header_version=0,count=0;};
unsigned run(unsigned,Memory&,const Inputs&,Heap&,FileApi&,Observation&);
unsigned cleanup(Heap&,FileApi&,const Observation&);
}
