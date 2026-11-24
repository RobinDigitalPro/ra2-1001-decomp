#include "recovered/recovery_b864.hpp"
#include <string>
#include <stdexcept>
namespace ra2::recovered::recovery_b864 {using U=std::uint32_t;
std::uint32_t fun_006d9640(global_b26::Memory&m,const global_b26::Inputs&i,const Eb750Case&c,platform::ordinary_heap::Heap&h){if(i.cx!=c.ini_root)throw std::domain_error("864 INI receiver");const auto section=m.r32(0x798238);if(section!=0x7b8cc8||probe_section(m,h,i.cx,section))throw std::domain_error("864 original Terrain absent");const auto count=m.r32(0xa285a0),array=m.r32(0xa28594);if(count<1||count>4)throw std::domain_error("864 finite registry");U written=0;
 for(U k=0;k<count;++k){auto obj=m.r32(array+4*k);if(!obj||m.r8(obj+0x76)||!m.r8(obj+0x7d))continue;if(written++||m.r32(obj)!=0x798274||m.r32(0x798414)!=0x41b320)throw std::domain_error("864 one original coordinate vtable receiver");const auto x=global_b26::s32(global_b26::sx16(U(global_b26::s32(m.r32(obj+0x88))/256))),y=global_b26::s32(global_b26::sx16(U(global_b26::s32(m.r32(obj+0x8c))/256)));auto key=std::to_string(x+1000*y);for(U j=0;j<key.size();++j)m.w8(c.key_scratch+j,U(key[j]));m.w8(c.key_scratch+U(key.size()),0);if(write_absent(m,h,i.cx,section,c.key_scratch,m.r32(obj+0xb0)+0x24)!=1)throw std::domain_error("864 positivewriter");}
 if(written!=1)throw std::domain_error("864 positive selectedmember");return m.r32(0xa285a0);}
}
