#include "recovered/recovery_b1234.hpp"
#include <stdexcept>
#include <string>
namespace ra2::recovered::b1234 {
unsigned run(Memory&m,Inputs&,Heap&heap,Provider&api,unsigned root){
 if(root!=0x37de2au||m.r32(0xb107ccu)||m.r32(0xb107e0u)||m.r32(0xb10540u)||m.r32(0xb10ac8u)||m.r32(0xb10ce4u)||!m.r32(0xb10e2cu))throw std::domain_error("1234 cold genuine timezone contract");
 api.enter12();m.w32(0x818618u,0xffffffffu);m.w32(0x818608u,0xffffffffu);m.w32(0xb10718u,0u);
 unsigned table=m.r32(0xb10474u),record=m.r32(table);if(!record||m.r32(table+4u)||m.r8(record)!='T'||m.r8(record+1u)!='Z'||m.r8(record+2u)!='=')throw std::domain_error("1234 produced one-record environment projection");
 const char lhs[2]={'T','Z'},rhs[2]={'T','Z'};if(!api.probe())throw std::domain_error("1234 actual cold W probe failed");m.w32(0xb107e0u,1u);if(api.compare_names(lhs,rhs)!=2u)throw std::domain_error("1234 real wide provider unequal");
 const unsigned source=record+3u;std::string value;for(unsigned k=0;k<16u&&m.r8(source+k);++k)value+=char(m.r8(source+k));if(value.size()<14u||value.size()>15u||m.r8(source+unsigned(value.size())))throw std::domain_error("1234 finite timezone value");
 const auto cache=heap.allocate(unsigned(value.size())+1u);if(!cache)throw std::runtime_error("1234 actual cache allocation");m.w32(0xb107ccu,cache);for(unsigned k=0;k<=value.size();++k)heap.w8(cache+k,k==value.size()?0u:unsigned(static_cast<unsigned char>(value[k])));api.leave12();
 unsigned p=0;for(unsigned k=0;k<3u;++k)m.w8(m.r32(0x8185fcu)+k,unsigned(static_cast<unsigned char>(value[p++])));m.w8(m.r32(0x8185fcu)+3u,0u);const bool negative=value[p]=='-';if(negative)++p;
 const auto digits=[&](){if(p+2u>value.size()||value[p]<'0'||value[p]>'9'||value[p+1u]<'0'||value[p+1u]>'9')throw std::domain_error("1234 two decimal digits");const unsigned n=unsigned(value[p]-'0')*10u+unsigned(value[p+1u]-'0');p+=2u;return n;};
 const unsigned hours=digits();if(value[p++]!=':')throw std::domain_error("1234 hour delimiter");const unsigned minutes=digits();if(value[p++]!=':')throw std::domain_error("1234 minute delimiter");const unsigned seconds=digits();if(value.size()-p!=3u)throw std::domain_error("1234 exact positive suffix");
 const unsigned total=hours*3600u+minutes*60u+seconds;m.w32(0x818570u,negative?0u-total:total);m.w32(0x818574u,unsigned(int(static_cast<signed char>(value[p]))));const unsigned out=m.r32(0x818600u);for(unsigned k=0;k<3u;++k)m.w8(out+k,unsigned(static_cast<unsigned char>(value[p+k])));m.w8(out+3u,0u);return out;
}
}
