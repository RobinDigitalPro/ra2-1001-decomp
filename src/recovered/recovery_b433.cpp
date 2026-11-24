#include "recovery_b433.hpp"
#include <stdexcept>
namespace ra2::recovered::keyboard433 {
namespace {void require(bool ok,const char* msg){if(!ok)throw std::domain_error(msg);}}
std::uint32_t fun_00530980(Memory& m,State& s,std::uint32_t scratch,const Ops&o){
 const auto vk=s.arg[0];
 // Positive bounded contract: digit VK, none of the early-return/control
 // flags, a zero keyboard-state array, and the caller-seeded output dword.
 require(vk>=0x30&&vk<=0x39&&(vk&0x800u)==0&&(vk&0x700u)==0,
         "keyboard433 requires unmodified ASCII digit VK route");
 require(o.map_virtual_key_a&&o.to_ascii,"keyboard433 requires real USER32 forwarders");
 // The exact instruction 5309e2 stores the modifier-test temporary before
 // the first API call; in this fixture [ESP+0x20] is caller word zero.
 s.arg[0]=0;
 const auto scan=o.map_virtual_key_a(o.context,vk&0xffffu,0);
 require(scan!=0,"keyboard433 positive VK must map to a nonzero scan code");
 const auto result=o.to_ascii(o.context,vk&0xffffu,scan,s.cx+0x14u,scratch,0);
 require(result==1,"keyboard433 positive digit route requires one translated character");
 const auto out=m.r32(scratch);
 s.ax=(result==1?0xffffffffu:0u)&out;
 return s.ax;
}
}
