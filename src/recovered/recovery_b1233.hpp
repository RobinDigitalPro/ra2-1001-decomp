#pragma once
#include "recovered/recovery_b979.hpp"
#include <string>
namespace ra2::recovered::b1233 {
using Memory=b979::Memory;using Inputs=b979::Inputs;using Heap=platform::ordinary_heap::Heap;
struct Query {unsigned result,offset,length;};
struct Provider {virtual ~Provider()=default;virtual unsigned module_path(unsigned,char*,unsigned)=0;virtual unsigned version_size(const char*,unsigned&)=0;virtual unsigned version_info(const char*,unsigned,unsigned,unsigned)=0;virtual Query query(unsigned,const char*)=0;};
unsigned run(Memory&,Inputs&,Heap&,Provider&,unsigned root);
}
