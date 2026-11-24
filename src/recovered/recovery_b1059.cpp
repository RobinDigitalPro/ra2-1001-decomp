#include "recovered/recovery_b1059.hpp"
#include "recovered/name_hash.hpp"
#include <stdexcept>
namespace ra2::recovered::b1059 {
static void need(bool x){if(!x)throw std::domain_error("1059 outside reviewed populated cached digest contract");}
static unsigned digest(Memory&m,unsigned p){need(p&&m.r8(p+0x38u)!=0u);std::uint8_t bytes[20];for(unsigned j=0;j<20u;++j)bytes[j]=m.r8(p+0x39u+j);NameHashState state{};return fun_00493da0(state,bytes,20);}
std::uint32_t fun_00649690(Memory&m,const Inputs&){
 unsigned total=digest(m,m.r32(0x821a10u));need((m.r8(0xa59638u)&1u)!=0u&&m.r8(0xa9e8f8u)!=0u);
 const auto count=m.r32(0xa59630u),array=m.r32(0xa59624u);need(count>=2u&&count<=7u);
 for(unsigned key=1;key<=count;++key){unsigned record=0;for(unsigned j=0;j<count;++j){const auto p=m.r32(array+4u*j);if(m.r32(p+0x28u)==key){record=p;break;}}if(record)total+=digest(m,m.r32(record+0x38u));}
 return total+m.r32(0xa9e8f4u);
}
}
