#include "recovered/recovery_b1622.hpp"
#include "recovered/name_hash.hpp"
#include <array>
#include <stdexcept>
#include <string>
namespace ra2::recovered::b1622 { namespace {
void need_at(bool value,int line){if(!value)throw std::domain_error("1622 finite existing-House guard line "+std::to_string(line));}
#define need(x) need_at((x),__LINE__)
U houses_query(Memory&m){
 constexpr std::array<std::uint8_t,7>literal{{'H','o','u','s','e','s',0}};
 for(U k=0;k<literal.size();++k)need(m.r8(0x7c58c4+k)==literal[k]);
 const U actual=::ra2::recovered::ini_name_hash(literal.data(),6,nullptr);
 need(actual==0x52981a3d);return actual;
}
U section_count_miss(Memory&m,Heap&heap,U ini){
 // Actual50BF50 uses the existing global section index, not a fabricated empty
 // receiver. Warm House remains cached after the genuine signed search miss.
 need(m.r32(ini)==0x78db34&&m.r32(ini+36)==1&&m.r32(ini+40)==10&&m.r8(ini+44)==1);
 const U first=m.r32(ini+32);need(first&&m.r32(ini+48)==first);
 constexpr std::array<std::uint8_t,5>house{{'H','o','u','s','e'}};
 const U cached_key=heap.r32(first),house_key=::ra2::recovered::ini_name_hash(house.data(),5,nullptr);
 need(house_key==0x2f515b63&&cached_key==house_key);
 const U query=houses_query(m);need(query!=cached_key);
 U cursor=first;int remaining=int(m.r32(ini+36));bool found=false;
 while(remaining>0){const int half=remaining/2;const U middle=cursor+8*U(half);const auto value=std::int32_t(heap.r32(middle)),wanted=std::int32_t(query);
  if(value>wanted)remaining=half;
  else if(value==wanted){found=true;break;}
  else{cursor=middle+8;remaining-=half+1;}
 }
 need(!found);
 // 510739 XOR EAX,EAX; 50BFBB JZ50C007 excludes cached-row publication.
 // BF50's temporary arg0 hash write is consumed by its RET4; no outer word.
 return 0;
}
}
U run(U root,Memory&m,const Inputs&i,Heap&heap,U base){
 need(root==0xeaf40&&base>=0x10000000&&std::uint64_t(base)+0x200000<=0x100000000ull);
 const U ini=i.cx;need(ini==base+0x3000);
 const U created_count=section_count_miss(m,heap,ini);need(created_count==0); // 4EAF5B JLE4EB019, no creation/name-copy loop.
 const U count=m.r32(0xa1a5d8),roster=m.r32(0xa1a5cc);need(count==1&&roster==base+0xb0000);
 const U house=m.r32(roster);need(house==base+0x10000&&m.r32(house+0x30)==0);
 need(m.r32(0xa255c8)==1); // Explicit public numeric TEST/JNE input only; no mode/class/producer claim.
 // The unchanged callee verifies the complete seven-block parser graph, all
 // normal used-field House/Type/color providers, and fresh PercentBuilt child.
 // Only the produced outgoing INI word is modeled. Unused child arg1..15 are
 // portable carriers, not original private-frame observations or fixture seeds.
 Inputs child{};child.ax=i.ax;child.cx=house;child.dx=i.dx;child.arg[0]=ini;
 child.stack_minus8=i.stack_minus8;child.arithmetic_flags=i.arithmetic_flags;child.fp=i.fp;
 const U child_result=b1621::run(0xeb0d0,m,child,heap,base);need(child_result==0);
 i.fp=child.fp; // Carry actual computed numeric state; never force a poststate.
 need(m.r32(0xa255c8)==1); // 4EB03B JNE4EB073 skips4E24D0.
 const U reloaded_count=m.r32(0xa1a5d8);need(reloaded_count==1);
 const U next_index=1;need(next_index>=reloaded_count&&reloaded_count!=0); // 4EB07F JNE excludes fallback constructors.
 return reloaded_count; // Actual MOV EAX,[A1A5D8]; outer RET0/all16 unchanged.
}
}
