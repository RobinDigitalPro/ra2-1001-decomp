#pragma once
#include "recovered/recovery_b979.hpp"
#include <array>
#include <string>
namespace ra2::recovered::b1038 {
using Memory=b979::Memory;using Inputs=b979::Inputs;using Heap=b979::Heap;
struct Fixture {unsigned root,base,holder,receiver,parser,input,section,section_name,key_table,section_table;std::array<unsigned,3>nodes{},values{},keys{};};
struct Observation {unsigned object=0,codes=0,code=0;};
Fixture prepare(Memory&,Heap&,Inputs&,unsigned root,unsigned base,const std::string&token);
unsigned run(Memory&,const Inputs&,Heap&,const Fixture&,Observation&);
void cleanup_result(Memory&,Heap&,const Fixture&,const Observation&);
void cleanup_fixture(Memory&,Heap&,const Fixture&);
unsigned fun_004dfaa0(Memory&,const Inputs&,Heap&,const Fixture&,Observation&);
unsigned fun_004df9a0(Memory&,const Inputs&,Heap&,const Fixture&,Observation&);
unsigned fun_004df8e0(Memory&,const Inputs&,Heap&,const Fixture&,Observation&);
unsigned fun_004df610(Memory&,const Inputs&,Heap&,const Fixture&,Observation&);
}
