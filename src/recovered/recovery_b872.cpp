#include "recovered/recovery_b872.hpp"
#include <string>
#include <stdexcept>
namespace ra2::recovered::recovery_b872 {using U=std::uint32_t;
namespace {void need(bool b,const char*s){if(!b)throw std::domain_error(s);}std::string text(global_b26::Memory&m,U p){need(p,"872 nonnulltext");std::string s;for(U k=0;k<64;++k){auto c=m.r8(p+k);if(!c)return s;s.push_back(char(c));}throw std::domain_error("872 boundedtypename");}void put(global_b26::Memory&m,U p,const std::string&s){for(U k=0;k<s.size();++k)m.w8(p+k,U(static_cast<unsigned char>(s[k])));m.w8(p+U(s.size()),0);}}
std::uint32_t fun_0067d060(global_b26::Memory&m,const global_b26::Inputs&i,const Eb750Case&c,platform::ordinary_heap::Heap&h){need(i.cx==c.ini_root,"872 INIreceiver");const auto section=m.r32(0x796400);need(text(m,section)=="Smudge"&&!probe_section(m,h,i.cx,section),"872 absentSmudge");const auto table=m.r32(0x81a958);need(table&&m.r32(0xa57658)==0xffffffff,"872 fulltableandtypelessfallback");U written=0,last_type=0;
 for(U y=0;y<512;++y)for(U x=0;x<512;++x){auto cell=m.r32(table+4*(x+512*y));if(!cell){m.w32(0xa57634,x+(y<<16));cell=0xa57610;}last_type=m.r32(cell+0x48);if(last_type==0xffffffff||m.r8(cell+0x11f))continue;need(last_type==0&&written==0,"872 onepositivetypezero");const auto type=m.r32(m.r32(0xa2880c));auto name=text(m,type+0x24);need(!name.empty(),"872 positivetypeName");auto value=name+","+std::to_string(x)+","+std::to_string(y)+",0";put(m,c.key_scratch,"0");put(m,c.value_scratch,value);write_absent(m,h,i.cx,section,c.key_scratch,c.value_scratch);++written;}
 need(written==1&&last_type==0xffffffff,"872 positiveoneoutputandlastnullcell");return last_type;}
}
