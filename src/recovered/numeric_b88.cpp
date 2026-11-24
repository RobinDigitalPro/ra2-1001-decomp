#include "numeric_b88.hpp"
#include "numeric_b88_detail.hpp"
namespace ra2::recovered::numeric_b88 {
std::uint32_t fun_004b8780(Memory&m,const Inputs&i){
 const auto r=i.cx,cur=m.r16(r),prev=m.r16(r+4),count=m.r16(r+0x14);
 const auto diff=s32(sx16(cur-prev));const auto step=(diff<0?-diff:diff)/count;
 const auto predicted=std::uint16_t(cur-(diff/step)*s32(m.r32(r+0x10)));
 if(predicted==m.r16(i.arg[0])){m.w32(r+8,m.r32(0xa2896c));m.w32(r+12,i.stack_minus8);m.w32(r+16,0);return 0;}
 throw std::runtime_error("Block88 angle contract requires matching prediction");
}
std::uint32_t fun_004e24d0(Memory&m,const Inputs&i){
 using namespace detail;const auto r=i.cx,s=i.arg[0],g=m.r32(0x821b88),t=g+80*s,old=m.r32(r+0xc8);auto&f=i.fp;
 m.w32(r+0xc8,s);write64(m,r+0xd0,read64(m,t+0x1198));
 f.load64(read64(m,t+0x11a0));f.multiply64(read64(m,g+0x1080));write64(m,r+0xd8,f.pop64());
 f.load64(read64(m,t+0x11a8));f.multiply64(read64(m,g+0x1080));write64(m,r+0xe0,f.pop64());
 for(unsigned o=0;o<24;o+=8)write64(m,r+0xe8+o,read64(m,t+0x11b0+o));
 write64(m,r+0x108,read64(m,t+0x11d0));write64(m,r+0x110,read64(m,t+0x11d8));
 f.load64(read64(m,t+0x11c8));f.multiply64(read64(m,g+0x1080));write64(m,r+0x100,f.pop64());
 m.w32(r+0x5684,m.r32(0xa2896c));m.w32(r+0x5688,i.stack_minus8);
 m.w32(r+0x568c,m.r32(m.r32(g+0xe34)+4*s)+175u*m.r32(r+0x30));return old;
}
std::uint32_t fun_00698010(Memory&m,const Inputs&i){
 using namespace detail;const auto p=i.arg[0],out=i.arg[1],r=i.cx,x=m.r32(p),y=m.r32(p+4),z=m.r32(p+8);
 i.arg[0]=s32(z)>=728?1:0;
 const auto xx=div256(half_toward_zero(x*60u)+half_toward_zero(0u-y*60u));
 const auto yy=div256(half_toward_zero(x*30u)+half_toward_zero(y*30u));
 auto&f=i.fp;f.load_integer32(z);f.multiply64(read64(m,0xaa5f90));ext::add_integer32(f,i.arg[0]);f.add64(read64(m,0x785728));
 const auto oy=yy-integer(m,f)-m.r32(r+0xb4),ox=xx-m.r32(r+0xb0);m.w32(out,ox);m.w32(out+4,oy);
 const bool inside=s32(ox)>=-360&&s32(ox)<=s32(m.r32(0xaa6070)+360)&&s32(oy)>=-180&&s32(oy)<=s32(m.r32(0xaa6074)+180);
 return with_al(oy,inside);
}
std::uint32_t fun_00692c00(Memory&m,const Inputs&i){
 using namespace detail;const auto r=i.cx;if(!m.r8(r+0x55))return 0;const auto p=m.r32(r+0x24);const bool enabled=m.r8(p+0xdd)!=0;
 if(!enabled&&m.r8(r+0x57))return 54;
 auto rem=m.r32(r+0x34);const auto start=m.r32(r+0x2c);if(start!=0xffffffffu){const auto elapsed=m.r32(0xa2896c)-start;rem=s32(elapsed)>=s32(rem)?0:rem-elapsed;}
 auto&f=i.fp;std::uint32_t result;
 if(enabled&&m.r32(r+0x60)==2){f.load_integer32(m.r32(p+0xb0));f.multiply64(read64(m,m.r32(0x821b88)+0x680));f.load_integer32(rem);reg<0xd8e9>(f);reg<0xd8f1>(f);f.reverse_subtract64(read64(m,0x785708));f.multiply64(read64(m,0x797118));result=integer(m,f);f.pop_st0();}
 else{f.load_integer32(m.r32(p+0xb0)-rem);f.divide_integer32(m.r32(p+0xb0));f.multiply64(read64(m,0x797118));result=integer(m,f);}
 return s32(result)<53?result:53;
}
std::uint32_t fun_007730dc(Memory&m,const Inputs&i){
 const auto x=std::uint64_t(i.arg[0])|(std::uint64_t(i.arg[1])<<32);auto&f=i.fp;
 f.load64(x);f.compare_pop64(read64(m,0x786610));const bool neg=(f.status()&0x100)!=0;
 f.load64(x);if(neg)f.change_sign();const auto a=f.pop64();
 f.load64(a);f.compare_pop64(read64(m,0x785708));f.load64(a);f.compare_pop64(read64(m,0x785708));f.load_zero();write64(m,i.arg[4],f.pop64());return 0;
}
std::uint32_t fun_0077d195(Memory&m,const Inputs&i){
 const auto bits=std::uint64_t(i.arg[0])|(std::uint64_t(i.arg[1])<<32),exp=bits&0x7ff0000000000000ull;
 const bool neg=(bits>>63)!=0;auto&f=i.fp;
 if(exp==0x7ff0000000000000ull){f.load64(bits);f.pop64();return neg?4:0x200;}
 if(!exp&&(bits&0xfffffffffffffull))return neg?0x10:0x80;
 f.load64(bits);f.compare_pop64(read64(m,0x786610));return (f.status()&0x4000)?(neg?0x20:0x40):(neg?8:0x100);
}
std::uint32_t fun_0077e0d2(Memory&m,const Inputs&i){
 const auto p=i.arg[0];const auto lo=s32(m.r32(0x81860c)),hi=s32(m.r32(0x81861c)),day=s32(m.r32(p+0x1c));
 if(lo<hi){if(day<lo||day>hi)return 0;if(day>lo&&day<hi)return 1;}
 else{if(day<hi||day>lo)return 1;if(day>hi&&day<lo)return 0;}
 const auto ms=((m.r32(p+8)*60+m.r32(p+4))*60+m.r32(p))*1000;
 return day==lo?s32(ms)>=s32(m.r32(0x818610)):s32(ms)<s32(m.r32(0x818620));
}
}
