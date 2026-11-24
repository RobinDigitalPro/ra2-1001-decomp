#include "recovered/recovery_b879.hpp"
#include <string>
namespace ra2::recovered::recovery_b879 {using U=std::uint32_t;
U fun_006e4740(global_b26::Memory&m,const global_b26::Inputs&i,const Eb750Case&c,platform::ordinary_heap::Heap&h){
 if(i.cx!=c.ini_root||m.r32(0x84e508)!=1||m.r32(m.r32(0x84e4fc))!=c.object)throw std::domain_error("879 positive single tube");U section=m.r32(0x7e1ea0);if(section!=0x7e1ea4||probe_section(m,h,i.cx,section))throw std::domain_error("879 absent Tubes");U o=c.object;
 auto s16=[&](U a){return global_b26::s32(global_b26::sx16(m.r16(a)));};auto x=s16(o+0x24),y=s16(o+0x26);auto index=x+512*y;if(index<0||index>=0x40000)throw std::domain_error("879 valid mapindex");U cell=m.r32(m.r32(0x81a958)+4*U(index));if(!cell||m.r16(cell+0x116)!=0||m.r32(cell+0xec)!=10)throw std::domain_error("879 real cell tube predicate");m.w16(cell+0x116,0);
 std::string value=std::to_string(x)+","+std::to_string(y)+","+std::to_string(global_b26::s32(m.r32(o+0x2c)))+","+std::to_string(s16(o+0x28))+","+std::to_string(s16(o+0x2a));for(U k=0;k<100;++k)value+=","+std::to_string(global_b26::s32(m.r32(o+0x30+4*k)));if(value.size()>=256)throw std::domain_error("879 boundedcompleteCSV");m.w8(c.key_scratch,'0');m.w8(c.key_scratch+1,0);for(U k=0;k<value.size();++k)m.w8(c.value_scratch+k,std::uint8_t(value[k]));m.w8(c.value_scratch+U(value.size()),0);if(write_absent(m,h,i.cx,section,c.key_scratch,c.value_scratch)!=1)throw std::domain_error("879 successfulwrite");return m.r32(0x84e508);
}}
