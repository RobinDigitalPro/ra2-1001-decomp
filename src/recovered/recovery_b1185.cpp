#include "recovered/recovery_b1185.hpp"
#include "recovered/name_hash.hpp"
#include <stdexcept>
#include <string>
namespace ra2::recovered::b1185 {namespace {
void need(bool x){if(!x)throw std::domain_error("1185 actual positive one-key SOUNDS Theme ownership route");}
std::string text(Heap&h,unsigned p){std::string s;for(unsigned j=0;j<32u;++j){const auto c=h.r8(p+j);if(!c)return s;s+=char(c);}throw std::domain_error("1185 bounded owned text");}
unsigned hash(const std::string&s){return ini_name_hash(reinterpret_cast<const unsigned char*>(s.data()),s.size(),nullptr);}
unsigned clone(Heap&h,const std::string&s){const unsigned p=h.allocate(unsigned(s.size()+1u));need(p!=0u);for(unsigned j=0;j<=s.size();++j)h.w8(p+j,j==s.size()?0u:unsigned(static_cast<unsigned char>(s[j])));return p;}
}
unsigned run(Memory&m,Inputs&i,Heap&h,unsigned root,unsigned base,Observation&z){need(root==0x3228d0u&&i.arg[0]==base+0x4000u&&i.arg[1]==base+0x5000u);const unsigned ini=i.arg[0],section_holder=i.arg[1];need(text(h,m.r32(section_holder))=="SOUNDS"&&m.r32(ini)==0x78db34u&&m.r32(ini+36u)==1u&&m.r8(ini+44u)==0u&&m.r32(ini+48u)==0u);const unsigned global=m.r32(ini+32u);need(h.r32(global)==hash("SOUNDS"));m.w8(ini+44u,1u);m.w32(ini+48u,global);++z.sorts;
 const unsigned section=h.r32(global+4u),index=h.r32(section+44u);need(h.r32(section)==0x78eba4u&&h.r32(section+48u)==1u&&h.r8(section+56u)==0u&&h.r32(section+60u)==0u&&h.r32(index)==hash("Theme"));const unsigned node=h.r32(index+4u);need(h.r32(node)==0x78eb9cu&&text(h,h.r32(node+12u))=="Theme");
 //50C320 constructs the key holder in caller argument1 at entry S+8.
 const unsigned key=clone(h,"Theme");++z.allocations;++z.key_copies;i.arg[1]=key;
 const unsigned fallback=clone(h,"");++z.allocations;h.w8(section+56u,1u);h.w32(section+60u,index);++z.sorts;const auto value=text(h,h.r32(node+16u));need(value.size()==10u);for(unsigned char c:value)need(c>32u&&c<127u);const unsigned temporary=clone(h,value);++z.allocations;++z.value_reads;need(h.release(fallback)!=0u);++z.frees;
 const unsigned old=m.r32(i.cx+0x490u);need(old!=0u&&text(h,old).empty());need(h.release(old)!=0u);++z.frees;const unsigned retained=clone(h,value);++z.allocations;m.w32(i.cx+0x490u,retained);++z.theme_assignments;need(h.release(key)!=0u);++z.frees;i.arg[1]=0u;const unsigned result=h.release(temporary);need(result!=0u);++z.frees;return result;}
}
