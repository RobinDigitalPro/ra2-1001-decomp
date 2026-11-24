#include "recovered/recovery_b1219.hpp"
#include <stdexcept>
namespace ra2::recovered::b1219{namespace{void need(bool b,const char*s){if(!b)throw std::domain_error(s);}void read(Memory&m,unsigned file,unsigned out,unsigned bytes){need(m.r32(file)==0x793bf4u&&m.r8(file+0x18u)==1u&&(m.r8(file+0x14u)&1u),"1219 genuine open borrowed MemFile");const auto pos=m.r32(file+0x10u),len=m.r32(file+0xcu),data=m.r32(file+4u);need(data&&pos<=len&&bytes<=len-pos&&out,"1219 positive complete bounded read");for(unsigned j=0;j<bytes;++j)m.w8(out+j,m.r8(data+pos+j));m.w32(file+0x10u,pos+bytes);}}
unsigned run(unsigned r,Memory&m,const Inputs&i,State&){need(r==0x116140u&&m.r32(i.cx+0x10u)==0u&&m.r32(i.cx+0xcu)==452u,"1219 reader exact positive complete record");const unsigned scenario=m.r32(0xa255c0u);need(scenario!=0u,"1219 authentic borrowed Scenario output span");read(m,i.cx,0x7c3978u,4u);read(m,i.cx,0xa2897cu,4u);read(m,i.cx,scenario+0x834u,4u);read(m,i.cx,scenario+0x83cu,260u);read(m,i.cx,0xa28878u,4u);read(m,i.cx,0xa28570u,4u);read(m,i.cx,0xa28758u,172u);
 // 5161B7/BC reload Scenario+83C before literal4068F0 RET; only AL is replaced.
 return((scenario+0x83cu)&0xffffff00u)|1u;}
}
