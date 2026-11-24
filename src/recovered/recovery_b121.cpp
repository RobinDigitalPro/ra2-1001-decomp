#include "recovery_b121.hpp"
#include "platform/current_crt_thread.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b121 {
namespace {
std::uint32_t thread(Memory&m){return ra2::platform::current_crt_thread(m.r32(0x817778));}
std::uint32_t random15(Memory&m){const auto t=thread(m),s=m.r32(t+0x14)*0x343fdu+0x269ec3u;m.w32(t+0x14,s);return(s>>16)&0x7fff;}
bool delimiter(Memory&m,std::uint32_t chars,std::uint32_t c){for(unsigned k=0;k<3;++k){const auto d=m.r16(chars+2*k);if(!d)return false;if(d==c)return true;}throw std::domain_error("unbounded delimiters");}
}
// RVA370411 cdecl wide token extraction; original overwrites caller arg0.
std::uint32_t fun_00770411(Memory&m,const Inputs&i){
 const auto t=thread(m);auto p=i.arg[0]?i.arg[0]:m.r32(t+0x1c);unsigned steps=0;
 while(m.r16(p)&&delimiter(m,i.arg[1],m.r16(p))){p+=2;if(++steps>32)throw std::domain_error("unbounded token prefix");}
 const auto start=p;i.arg[0]=start;
 while(m.r16(p)&&!delimiter(m,i.arg[1],m.r16(p))){p+=2;if(++steps>32)throw std::domain_error("unbounded token");}
 if(m.r16(p)){m.w16(p,0);p+=2;}m.w32(t+0x1c,p);return start!=p?start:0;
}
// RVA206700 RET4: row0 initialization and four updates of the real TLS seed.
std::uint32_t fun_00606700(Memory&m,const Inputs&i){
 if(i.arg[0])throw std::domain_error("only original row0 contracted");constexpr unsigned row=0x7d5958;
 const auto r0=random15(m);m.w32(i.cx+0x30,(r0&63)-31);m.w32(i.cx+0x34,((r0>>5)&31)-15);
 for(unsigned k=0;k<3;++k)m.w32(i.cx+0x18+4*k,m.r32(row+4*k));
 if(m.r32(row+0x18)!=5)throw std::domain_error("original table shift differs");const auto r1=random15(m);
 for(unsigned k=0;k<3;++k)m.w32(i.cx+0x18+4*k,m.r32(i.cx+0x18+4*k)-((r1>>(5*k))&31));
 for(unsigned k=0;k<3;++k){const auto v=m.r32(row+12+4*k);m.w32(i.cx+0x24+4*k,v);m.w32(i.cx+4+4*k,v);}m.w32(i.cx+0x10,0);
 const auto r2=random15(m),low=m.r32(row+0x24),high=m.r32(row+0x20);if(low!=3||high!=12)throw std::domain_error("original range differs");m.w32(i.cx+0x14,low+r2%(high-low+1));
 const auto result=random15(m)&m.r32(row+0x1c);m.w32(i.cx+0x38,result);return result;
}
}
