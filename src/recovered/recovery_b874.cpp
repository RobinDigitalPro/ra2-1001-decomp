#include "recovered/recovery_b874.hpp"
#include <array>
namespace ra2::recovered::recovery_b874 {
namespace {void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
U text(Memory&m,U lc,U type,U field,platform::ordinary_heap::Heap&h,const LocaleOps&ops){std::array<char,128>v{};int n=ops.ansi(ops.context,lc,type,v.data(),128);need(n>0&&n<=16&&v[n-1]==0,"874 successful bounded ANSI query");U p=h.allocate(n);need(p,"874 successful ordinary allocation");m.w32(field,p);for(int k=0;k<n;++k)h.w8(p+k,std::uint8_t(v[k]));return p;}
void number(Memory&m,U lc,U type,U field,const LocaleOps&ops){std::array<std::uint16_t,4>v{};for(U k=0;k<4;++k)v[k]=std::uint16_t(m.r16(0xb10818+2*k));int n=ops.wide(ops.context,lc,type,v.data(),4);need(n>0&&n<=4&&v[n-1]==0,"874 successful bounded Wide query");for(U k=0;k<4;++k)m.w16(0xb10818+2*k,v[k]);m.w8(field,0);for(U k=0;k<4;++k){U b=m.r8(0xb10818+2*k);if(!(m.r8(m.r32(0x817560)+2*b)&4))break;m.w8(field,m.r8(field)*10+b-0x30);}}
void grouping(platform::ordinary_heap::Heap&h,U p){for(U k=0;k<16;){U b=h.r8(p+k);if(!b)return;if(b>='0'&&b<='9'){h.w8(p+k,b-'0');++k;}else if(b==';'){U j=k;do{need(j+1<16,"874 grouping bounded");h.w8(p+j,h.r8(p+j+1));++j;}while(h.r8(p+j));}else ++k;}throw std::domain_error("874 grouping terminator");}
}
U fun_0077a939(Memory&m,const Inputs&i,platform::ordinary_heap::Heap&h,const LocaleOps&ops){need(i.arg[0]&&m.r32(0xb10828)==2&&m.r32(0xb10824)==1&&m.r32(0x81776c)==1,"874 positive original cache/ctype path");U lc=m.r16(0xb106e0),dest=i.arg[0];const U types[]={0x15,0x14,0x16,0x17,0x18,0x50,0x51};for(U k=0;k<7;++k){U p=text(m,lc,types[k],dest+12+4*k,h,ops);if(k==4)grouping(h,p);}const U nums[]={0x1a,0x19,0x54,0x55,0x56,0x57,0x52,0x53};for(U k=0;k<8;++k)number(m,lc,nums[k],dest+40+k,ops);return 0;}
}
