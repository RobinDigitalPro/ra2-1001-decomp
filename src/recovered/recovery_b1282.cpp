#include "recovery_b1282.hpp"
#include "recovery_b1281.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b1282 {
std::uint32_t fun_0041c990(Memory&m,const Inputs&i){
 auto need=[](bool q,const char*s){if(!q)throw std::domain_error(s);};
 const auto self=i.cx,house=i.arg[0],other=i.arg[1],desc=m.r32(self+0xdcu);
 need(house!=0u&&other!=0u&&(i.arg[2]&255u)==0u,"1282 nonnull Houses and zero gate");
 need(desc!=0u&&m.r8(desc+0xeeu)!=0u&&m.r32(self+0xe0u)==0u,"1282 one enabled descriptor");
 need(m.r32(self+0x98u)==7u&&m.r32(self+0x9cu)==0u&&m.r8(self+0xa4u)!=0u,"1282 selector8 receiver flags");
 need(m.r32(self+0xa0u)==2u&&m.r32(self+0xacu)==0u,"1282 bounded ownership gates");
 need(global_b26::s32(m.r32(self+0xb0u))<=global_b26::s32(m.r32(house+0x11cu)),"1282 minimum House field gate");
 need(m.r32(0xa255c8u)==0u&&m.r32(m.r32(0xa255c0u)+0x60cu)==3u&&m.r8(m.r32(0x821b88u)+0x1437u)==0u,"1282 simple original scenario gates");
 const auto predicate=recovery_b1281::fun_0041cef0(m,i);
 if((predicate&255u)==0u)return predicate&0xffffff00u;
 // Real1E130 returns true without comparison when descriptor E8 is clear.
 need(m.r8(desc+0xe8u)==0u,"1282 disabled coordinate restriction");
 // Real4F2B30 validates its nonnull list, then returns true for count zero.
 const auto list=m.r32(desc+0xdcu);
 need(list!=0u&&m.r32(list+0x9cu)==0u,"1282 valid empty prerequisite list");
 const auto threshold=m.r32(desc+0xb8u);
 need(threshold<=3u&&m.r32(0x84e4b8u)==4u,"1282 finite nonnegative count limit and Team registry");
 const auto array=m.r32(0x84e4acu);unsigned count=0;
 // Exact readonly4F2AF0 owner+descriptor scan, with original reverse order.
 for(unsigned k=4u;k!=0u;--k){const auto team=m.r32(array+4u*(k-1u));
  if(team!=0u&&m.r32(team+0x2cu)==house&&m.r32(team+0x24u)==desc)++count;
 }
 if(count>=threshold)return count&0xffffff00u;
 return 1u; // Original reloads EAX=E0(null), then MOV AL,1.
}
}
