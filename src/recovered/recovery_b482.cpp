#include "recovery_b482.hpp"
#include "platform/observed_file482.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b482 {
using File=platform::file482::File;using U=std::uint32_t;
namespace {
void need(bool b){if(!b)throw std::domain_error("482 successful owned-file route");}
void live(Memory&m,U self){need(m.r32(self)==0x78773c&&m.r32(0x787754)==0x42f600&&m.r32(self+0x10)==File::handle()&&m.r32(self+0xc)==0xffffffffu);}
}
U fun_00630330(Memory&m,const Inputs&i){live(m,i.cx);const auto result=File::read(m,i.arg[0],i.arg[1]);m.w8(0xa9e184,0);return result;}
U fun_00630420(Memory&m,const Inputs&i){live(m,i.cx);return File::write(m,i.arg[0],i.arg[1]);}
U fun_00630550(Memory&m,const Inputs&i){live(m,i.cx);need(i.arg[1]<=2);return File::seek(i.arg[0],i.arg[1]);}
U fun_0042f4a0(Memory&m,const Inputs&i){
 live(m,i.cx);const auto self=i.cx;need(m.r8(self+0x25)&&m.r8(self+0x24)&&m.r8(self+0x22));
 const auto first=m.r32(self+0x3c),size=m.r32(self+0x40)-first,bias=m.r32(self+0x4c);
 File::seek(m.r32(self+0x38)+bias+first,0);
 // Original passes buffer start, not buffer+first, at42F4DD..42F4E4.
 File::write(m,m.r32(self+0x2c),size);
 const auto position=File::seek(m.r32(self+0x48)+bias,0);m.w8(self+0x24,0);return (position&0xffffff00u)|1u;
}
U fun_0042f640(Memory&m,const Inputs&i){
 const auto self=i.cx;need(m.r8(self+0x25)&&!m.r8(self+0x24)&&!m.r8(self+0x22)&&i.arg[0]==1&&m.r32(self+0x44)<=m.r32(self+0x30));
 // Actual42F4A0 returns at its clean-buffer guard; the positive root
 // then reopens the complete in-memory image for reading and resets cursors.
 m.w8(self+0x21,0);m.w32(self+0x28,1);m.w8(self+0x22,0);
 m.w32(self+0x34,0);m.w32(self+0x38,0);m.w32(self+0x3c,0xffffffffu);m.w32(self+0x40,0xffffffffu);m.w32(self+0x48,0);m.w8(self+0x21,1);return 1;
}
}
