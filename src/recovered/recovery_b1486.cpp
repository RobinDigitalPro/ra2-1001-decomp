#include "recovered/recovery_b1486.hpp"
#include "recovered/ini_bulk.hpp"
#include "recovered/ini_text.hpp"
#include "recovered/name_hash.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1486 {namespace {using U=std::uint32_t;void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
std::array<std::uint8_t,32> text(Memory&m,U p){std::array<std::uint8_t,32>b{};for(U k=0;k<32;++k){b[k]=std::uint8_t(m.r8(p+k));if(!b[k])return b;}throw std::domain_error("1486 bounded parsed text");}
void no_sort(IniIndexEntry*,std::int32_t,IniIndexKind,void*){throw std::domain_error("1486 already sorted single-entry index");}
std::int32_t no_upper(std::int32_t,void*){throw std::domain_error("1486 no bool/uppercase route");}
}
U configure_crt(Memory&m,const Inputs&i){need(!i.arg[0],"1486 actualsetter0");m.w32(0x817554,0);return 1;}
U fun_006dcb50(Memory&m,const Inputs&i,Heap&h){const U self=i.cx,p=i.arg[0];need(m.r32(0x817554)==0&&!m.r32(0x819778)&&!m.r32(0x7de560),"1486 genuine configured-noaudio/ordinaryCRT");need(m.r32(self+0x14)==0x7986bc&&!m.r32(self+0x18)&&!m.r32(self+0x1c)&&!m.r32(self+0x24)&&m.r32(self+0x28)==10&&!m.r32(self+0x2c),"1486 actual cold manager");
 const U rt=m.r32(p+0x20),s=m.r32(rt+4),kt=m.r32(s+0x2c),node=m.r32(kt+4);need(m.r32(p+0x24)==1&&m.r8(p+0x2c)==1&&!m.r32(p+0x30)&&m.r32(s+0x30)==1&&m.r8(s+0x38)==1&&!m.r32(s+0x3c)&&m.r32(s+0x18)==node&&m.r32(node+4)==s+0x20&&m.r32(node+8)==s+0x14,"1486 genuine one-entry parsed indices/sentinellinks");
 auto sn=text(m,m.r32(s+0xc)),kn=text(m,m.r32(node+0xc)),value=text(m,m.r32(node+0x10));need(sn==std::array<std::uint8_t,32>{'T','h','e','m','e','s'}&&kn==std::array<std::uint8_t,32>{'0'}&&value==std::array<std::uint8_t,32>{'T','h','e','m','e','0'},"1486 literal Themes/0/Theme0 finite domain");
 IniValue iv{value.data()};IniIndexEntry key{static_cast<std::int32_t>(m.r32(kt)),&iv};IniKeyNode end{},link{&end,&end,kn.data()};IniSection section{};section.keys={&key,1,1,nullptr,10};section.first=&link;IniIndexEntry re{static_cast<std::int32_t>(m.r32(rt)),&section};IniIndex index{&re,1,1,nullptr,10};IniOperations ops{ini_name_hash,no_sort,no_upper,nullptr,nullptr,nullptr};
 need(fun_0050bf50(&index,sn.data(),ops)==1,"1486 real nonempty Themes count");const auto*keyname=fun_0050c250(&index,sn.data(),0,ops);need(keyname,"1486 genuine firstkey");std::array<std::uint8_t,32>buffer{};need(fun_0050ddf0(&index,sn.data(),keyname,reinterpret_cast<const std::uint8_t*>(""),buffer.data(),32,ops)==6,"1486 real positiveINI buffer");
 const U owner=h.allocate(656);need(owner,"1486 genuine record allocation");h.w32(owner+0x280,0);h.w32(owner+0x284,0);h.w8(owner+0x200,0);h.w8(owner+0x201,0);h.w8(owner+0x288,1);h.w8(owner+0x289,0);h.w8(owner+0x28a,0);h.w32(owner+0x28c,0xffffffff);h.w8(owner,0);h.w8(owner+0x100,0);for(U k=0;k<7;++k)h.w8(owner+k,buffer[k]);
 // Original installed7986BC+8 ->6DD8C0 cold growth10, no oldowner.
 m.w8(self+0x20,0);const U table=h.allocate(40);need(table,"1486 genuine vector allocation");m.w8(self+0x20,1);m.w32(self+0x18,table);m.w32(self+0x1c,10);m.w8(self+0x21,1);m.w32(self+0x24,1);h.w32(table,owner);
 // Exact absent named-section branch of6DCA40; B321 present-section guard is not reused.
 need(fun_0050be00(&index,buffer.data(),ops)==nullptr,"1486 named Theme0 legitimately absent");need(index.cached==&re&&section.keys.cached==&key,"1486 original cache publications");m.w32(p+0x30,rt);m.w32(s+0x3c,kt);return m.r32(0x819778);
}}
