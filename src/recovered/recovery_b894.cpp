#include "recovered/recovery_b894.hpp"
namespace ra2::recovered::recovery_b894 {using U=std::uint32_t;
U fun_0050c410(global_b26::Memory&m,const global_b26::Inputs&i,const Eb750Case&c,platform::ordinary_heap::Heap&h){
 const U n=i.arg[2],src=i.arg[1],section=i.arg[0];if(i.cx!=c.ini_root||!src||!section||n<1||n>48||probe_section(m,h,i.cx,section))throw std::domain_error("894 freshsection positive borrowedbinary contract");
 if(m.r32(0x787620)!=0x7ba308||m.r32(0x78761c)!=0x7ba34c)throw std::domain_error("894 authentic alphabet pointers");
 U pos=0;for(U k=0;k<n;k+=3){const U rem=n-k,x=(m.r8(src+k)<<16)|(rem>1?m.r8(src+k+1)<<8:0)|(rem>2?m.r8(src+k+2):0);m.w8(c.value_scratch+pos++,m.r8(0x7ba308+((x>>18)&63)));m.w8(c.value_scratch+pos++,m.r8(0x7ba308+((x>>12)&63)));m.w8(c.value_scratch+pos++,rem>1?m.r8(0x7ba308+((x>>6)&63)):m.r8(0x7ba34c));m.w8(c.value_scratch+pos++,rem>2?m.r8(0x7ba308+(x&63)):m.r8(0x7ba34c));}
 m.w8(c.value_scratch+pos,0);m.w8(c.key_scratch,'1');m.w8(c.key_scratch+1,0);if(write_absent(m,h,i.cx,section,c.key_scratch,c.value_scratch)!=1)throw std::domain_error("894 successfulINIwrite");return 1;
}}
