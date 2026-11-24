#include "recovery_b1357.hpp"
#include <stdexcept>
namespace ra2::recovered::b1357 {
namespace {using U=std::uint32_t;
U stopped_entry(Memory&m,const Inputs&i){
 if(m.r32(i.arg[0])==0)throw std::domain_error("B1357 pre-requested stop required");
 // Both original entries publish entry, clear completion, test stop, publish completion.
 m.w32(i.arg[0]+0x18,1);m.w32(i.arg[0]+8,0);m.w32(i.arg[0]+8,1);return 0;
}}
U fun_0075d240(Memory&m,const Inputs&i){return stopped_entry(m,i);}
U fun_004094d0(Memory&m,const Inputs&i){return stopped_entry(m,i);}
U fun_00481290(Memory&m,const Inputs&i){
 if(m.r16(i.arg[0])==m.r16(i.cx+0x24))throw std::domain_error("B1357 unequal leading WORDs required");
 m.w32(i.cx+0x18,m.r32(i.cx+0x18)+1u);return 0;
}
}
