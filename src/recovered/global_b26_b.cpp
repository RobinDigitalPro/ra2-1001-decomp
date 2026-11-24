#include "recovered/global_b26_memory.hpp"
#include <array>
#include <cstdint>

namespace ra2::recovered::global_b26 {
namespace {
constexpr std::uint32_t u32(std::uint64_t x) { return static_cast<std::uint32_t>(x); }
std::uint32_t mul_signed32(std::uint32_t a, std::uint32_t b) { return u32(static_cast<std::uint64_t>(std::int64_t(s32(a)) * std::int64_t(s32(b)))); }
std::uint32_t signed_half(std::uint32_t d) { return sar(d + (s32(d) < 0 ? 1u : 0u), 1); }
std::uint32_t abs_idiom(std::uint32_t d) { const auto mask = 0u - (d >> 31); return (d ^ mask) - mask; }
std::uint32_t put_al(std::uint32_t eax, std::uint32_t al) { return (eax & 0xffffff00u) | (al & 0xffu); }
}

std::uint32_t fun_004f2af0(Memory&m,const Inputs&i){
 auto raw=m.r32(0x0084e4b8u),last=raw-1u; if(s32(last)<0)return 0;
 auto p=m.r32(0x0084e4acu)+last*4u; std::uint32_t eax=0;
 // INT_MIN wraps on DEC to INT_MAX; it is excluded from bounded fixtures.
 for(auto k=last;;--k,p-=4u){auto q=m.r32(p);if(q&&m.r32(q+0x2cu)==i.cx&&m.r32(q+0x24u)==i.arg[0])++eax;if(k==0)break;}
 return eax;
}
std::uint32_t fun_004f47b0(Memory&m,const Inputs&i){
 if(m.r32(0x00a255c8u))return i.cx==m.r32(0x00a1e0e4u)?1u:0u;
 return (m.r8(i.cx+0x134u)||m.r8(i.cx+0x135u))?1u:0u;
}
std::uint32_t fun_004f47f0(Memory&m,const Inputs&i){
 const auto mode=m.r32(0x00a255c8u);auto eax=put_al(mode,m.r8(i.cx+0x134u));
 if(mode!=0)return eax;
 if(eax&0xffu)return put_al(eax,1);
 const auto b=m.r8(i.cx+0x135u);return put_al(eax,b?1u:0u);
}
std::uint32_t fun_004f4d00(Memory&m,const Inputs&i){
 auto obj=i.cx;auto scratch=i.stack_minus8;m.w8(obj+0x5668u,1);m.w32(obj+0x1ecu,m.r32(0x00a2896cu));m.w32(obj+0x1f0u,scratch);m.w32(obj+0x1f4u,i.arg[0]);return scratch;
}
std::uint32_t fun_004f4d40(Memory&m,const Inputs&i){
 auto obj=i.cx;auto scratch=i.stack_minus8;m.w8(obj+0x5669u,1);m.w32(obj+0x1f8u,m.r32(0x00a2896cu));m.w32(obj+0x1fcu,scratch);m.w32(obj+0x200u,i.arg[0]);return scratch;
}
std::uint32_t fun_0051f0f0(Memory&m,const Inputs&i){auto al=m.r8(0x00a39574u);if(al)m.w8(0x00a39584u,1);return put_al(i.ax,al);}
std::uint32_t fun_0051f170(Memory&m,const Inputs&){if(m.r8(0x00a39574u))return 1;return s32(m.r32(0x00a39578u))>0?1u:0u;}
std::uint32_t fun_0051f1a0(Memory&m,const Inputs&){return m.r32(0x00a3957cu)==1u?1u:0u;}
std::uint32_t fun_0051f1b0(Memory&m,const Inputs&){return m.r32(0x00a3957cu)==2u?1u:0u;}
std::uint32_t fun_00522060(Memory&m,const Inputs&i){
 auto eax=m.r32(0x00a39ef0u);if(!eax||!i.cx)return eax;
 const auto count=m.r32(0x00a39e1cu);eax=m.r32(0x00a39ef4u);if(s32(count)<=1)return eax;
 auto slot=eax,first_hole=0u;std::uint32_t index=1;
 for(;;){auto value=m.r32(slot);if(!value){if(!first_hole)first_hole=slot;}else if(value==i.cx)return slot;
  ++index;slot+=4u;if(s32(index)>=s32(count))break;}
 if(first_hole){m.w32(first_hole,i.cx);eax=m.r32(0x00a39ef8u)+1u;m.w32(0x00a39ef8u,eax);}
 else eax=slot;
 return eax;
}
std::uint32_t fun_005220c0(Memory&m,const Inputs&i){
 auto eax=m.r32(0x00a39ef0u);if(!eax||!i.cx)return eax;
 const auto count=m.r32(0x00a39e1cu);eax=m.r32(0x00a39ef4u);if(s32(count)<=1)return eax;
 auto slot=eax;std::uint32_t index=1;
 for(;;){if(m.r32(slot)==i.cx){m.w32(slot,0);eax=m.r32(0x00a39ef8u)-1u;m.w32(0x00a39ef8u,eax);return eax;}
  ++index;slot+=4u;if(s32(index)>=s32(count))break;}
 return slot;
}
std::uint32_t fun_005228e0(Memory&m,const Inputs&i){
	auto eax=m.r32(0x00a39eecu);if(!eax)return eax;
 const auto value=(i.dx&0xffu)?0u:0xffff8000u;const auto index=i.cx&0xffu;m.w16(0x00a39c10u+index*2u,value);return eax;
}
std::uint32_t fun_00522ff0(Memory&m,const Inputs&i){
 m.w16(0x00a3a010u,i.cx);m.w32(0x00a39ff0u,i.dx);m.w32(0x00a3a004u,i.arg[0]);m.w32(0x00a3a020u,i.arg[1]);m.w32(0x00a39fd8u,i.arg[2]);m.w32(0x00a39fb0u,i.arg[3]);m.w32(0x00a3a014u,i.arg[4]);m.w32(0x00a3a044u,1);return i.arg[3];
}
std::uint32_t fun_005239d0(Memory&m,const Inputs&i){const auto eax=m.r32(0x00a3a044u);if(eax)m.w32(i.cx+0xc0u,0);return eax;}
std::uint32_t fun_005277b0(Memory&m,const Inputs&i){
 if(i.cx==0xffffu)return i.cx;auto sum=i.cx;auto n=m.r32(0x00a3ab10u);if(s32(n)<=0)return sum;auto base=m.r32(0x00a3ab04u);
 for(std::uint32_t k=0;k<n;++k){auto p=m.r32(base+k*4u);if(s32(m.r32(p))>s32(i.cx))break;sum+=m.r32(p+4u);}return sum;
}
std::uint32_t fun_005298b0(Memory&m,const Inputs&){
 auto eax=m.r32(0x00a28920u);if(s32(eax)<=0)return eax;const auto base=m.r32(0x00a28914u);std::uint32_t k=0;
 for(;;){auto p=m.r32(base+k*4u);while(p){m.w32(p+0x2d8u,0);p=m.r32(p+0x28cu);}eax=m.r32(0x00a28920u);++k;if(s32(k)>=s32(eax))return eax;}
}
std::uint32_t fun_00533dc0(Memory&m,const Inputs&){if(m.r32(0x00a255c8u)==0)return 0xffffffffu;return m.r32(0x0083a710u)==m.r32(0x00798bfcu)?0x146u:0x196u;}
std::uint32_t fun_00534d60(Memory&m,const Inputs&i){
 auto x=m.r32(0x0083a710u),y=m.r32(0x0083a714u);const auto same=x==m.r32(0x00798bfcu);
 std::uint32_t o0=same?0x10u:0x14u,o1=same?0x7eu:0x9eu,o2=same?0x13eu:0x18eu,o3=same?0x68u:0x82u;
 const auto xb=m.r32(0x00798c00u),yb=m.r32(0x00798c0cu);if(s32(x)>=s32(xb)){auto d=x-xb;o0+=signed_half(d);o1+=signed_half(y-yb);}
 m.w32(i.cx,o0);m.w32(i.cx+4u,o1);m.w32(i.cx+8u,o2);m.w32(i.cx+12u,o3);return i.cx;
}
std::uint32_t fun_00534de0(Memory&m,const Inputs&i){
 auto x=m.r32(0x0083a710u),y=m.r32(0x0083a714u);const bool same=x==m.r32(0x00798bfcu);
 std::uint32_t o0=same?0x10u:0x14u,o1=same?0xebu:0x12cu;const auto xb=m.r32(0x00798c00u),yb=m.r32(0x00798c0cu);if(s32(x)>=s32(xb)){o0+=signed_half(x-xb);o1+=signed_half(y-yb);}
 m.w32(i.cx,o0);m.w32(i.cx+4u,o1);m.w32(i.cx+8u,0xc8u);m.w32(i.cx+12u,0x14u);return i.cx;
}
std::uint32_t fun_005350b0(Memory&m,const Inputs&i){
 const auto a=(((i.dx&0xffffu)>>(m.r16(0x0083b2e8u)&31u))&0xffu) << (m.r32(0x0083b2ecu)&31u);
 const auto b=(((i.dx&0xffffu)>>(m.r16(0x0083b2f8u)&31u))&0xffu) << (m.r32(0x0083b2fcu)&31u);
 const auto c=(((i.dx&0xffffu)>>(m.r16(0x0083b2f0u)&31u))&0xffu) << (m.r32(0x0083b2f4u)&31u);
 const auto word=(a&0xffu)|((b&0xffu)<<8);m.w16(i.cx,word);m.w8(i.cx+2u,c);return i.cx;
}
std::uint32_t fun_005376f0(Memory&m,const Inputs&i){auto eax=i.arg[0];if(m.r32(0x00a2876cu)==0)eax<<=1;m.w32(i.cx+8u,eax);return eax;}
std::uint32_t fun_0053ba20(Memory&m,const Inputs&){
 const auto flag=m.r8(0x00a56758u);if(flag){const auto base=m.r32(0x007ca76cu),end=base+m.r32(0x007ca770u),cursor=m.r32(0x00a5674cu);if(cursor<end)return end;m.w8(0x00a56758u,0);return base;}
 const auto base=m.r32(0x007ca76cu),cursor=m.r32(0x00a5674cu);if(cursor>=base)return base;const auto len=m.r32(0x007ca770u);m.w8(0x00a56758u,1);return base+len;
}
std::uint32_t fun_00545490(Memory&m,const Inputs&i){
 const auto ptr=i.arg[0];auto vx=m.r32(ptr),vy=m.r32(ptr+4u);const auto x=sar(vx+((vx&0x80000000u)?255u:0u),8);const auto y=sar(vy+((vy&0x80000000u)?255u:0u),8);const auto index=(y<<9)+x;
 if(s32(index)>=0 && s32(index)<s32(m.r32(i.cx+0x13cu))){const auto table=m.r32(i.cx+0x138u);const auto found=m.r32(table+index*4u);if(found)return found;}
 // The fallback overwrites the caller's arg[0] word (SI low, AX high), then
 // rereads that same slot into the global. Inputs exposes the stack word.
 i.arg[0]=((y&0xffffu)<<16)|(x&0xffffu);m.w32(0x00a57634u,i.arg[0]);return 0x00a57610u;
}
std::uint32_t fun_00545500(Memory&m,const Inputs&i){
 const auto ptr=i.arg[0];const auto x=sx16(m.r16(ptr)),y=sx16(m.r16(ptr+2u));const auto index=(y<<9)+x;
 if(s32(index)>=0 && index<0x40000u){const auto table=m.r32(i.cx+0x138u);const auto p=m.r32(table+index*4u);if(p)return p;}
 m.w32(0x00a57634u,m.r32(ptr));return 0x00a57610u;
}
std::uint32_t fun_0054b830(Memory&m,const Inputs&i){
 const auto c=i.arg[0],out=i.arg[1];const auto x=sx16(m.r16(c)),y=sx16(m.r16(c+2u));const auto index=(y<<9)+x;std::uint32_t p=0;
 if(s32(index)>=0&&index<0x40000u){auto table=m.r32(0x0081a958u);p=m.r32(table+index*4u);}
 if(!p){m.w32(0x00a57634u,m.r32(c));p=0x00a57610u;}
 const auto packed=m.r32(p+0x24u);i.arg[0]=packed;auto row=sx16(i.arg[0]>>16),col=sx16(static_cast<std::uint16_t>(i.arg[0]));row=sar(row+(s32(row)<0?3u:0u),2);col=sar(col+(s32(col)<0?3u:0u),2);
 return m.r32(out+0x58dcu+4u*(130u*row+col));
}
std::uint32_t fun_0055f720(Memory&m,const Inputs&i){
 const auto x=sx16(m.r16(i.cx)),y=sx16(m.r16(i.cx+2u));const auto index=(y<<9)+x;std::uint32_t p=0;
 if(s32(index)>=0&&index<0x40000u){const auto table=m.r32(0x0081a958u);p=m.r32(table+index*4u);}
 if(!p){m.w32(0x00a57634u,m.r32(i.cx));p=0x00a57610u;}
 const auto v=m.r32(p+0x44u);return s32(v)>=0x4a&&s32(v)<=0x65?1u:0u;
}
std::uint32_t fun_0055f770(Memory&m,const Inputs&i){
 const auto x=sx16(m.r16(i.cx)),y=sx16(m.r16(i.cx+2u));const auto index=(y<<9)+x;std::uint32_t p=0;
 if(s32(index)>=0&&index<0x40000u){const auto table=m.r32(0x0081a958u);p=m.r32(table+index*4u);}
 if(!p){m.w32(0x00a57634u,m.r32(i.cx));p=0x00a57610u;}
 const auto v=m.r32(p+0x44u);return s32(v)>=205&&s32(v)<=232?1u:0u;
}
std::uint32_t fun_0056a990(Memory&m,const Inputs&i){const auto x=sx16(m.r16(i.cx)),y=sx16(m.r16(i.cx+2u));const auto factor=m.r32(0x00836b4cu);return m.r32(0x00a5863cu)+mul_signed32(y,factor)*80u+x*80u;}
std::uint32_t fun_0056a9b0(Memory&m,const Inputs&i){return m.r32(0x00a5863cu)+i.cx*80u;}
std::uint32_t fun_0056b760(Memory&m,const Inputs&i){
 const auto base=m.r32(0x00a5863cu);if(!base)return i.ax;const auto y=sx16(m.r16(i.cx+2u)),x=sx16(m.r16(i.cx));const auto index=mul_signed32(y,m.r32(0x00836b4cu))+x;const auto offset=index*80u;m.w32(base+offset+0x38u,i.dx);return offset;
}
std::uint32_t fun_0056b790(Memory&m,const Inputs&i){
 const auto base=m.r32(0x00a5863cu);if(!base)return 0xffffffffu;const auto y=sx16(m.r16(i.cx+2u)),x=sx16(m.r16(i.cx));const auto index=mul_signed32(y,m.r32(0x00836b4cu))+x;return m.r32(base+index*80u+0x38u);
}
std::uint32_t fun_00572ad0(Memory&m,const Inputs&i){const auto count=m.r32(0x00a57950u);if(s32(count)<=0)return 0;const auto base=m.r32(0x00a57944u);for(std::uint32_t n=0;n<count;++n){auto p=m.r32(base+n*4u);if(p&&m.r32(p+8u)==i.cx)return p;}return 0;}
std::uint32_t fun_0057e670(Memory&m,const Inputs&i){
 const auto base=m.r32(0x00a5863cu);if(!base)return i.ax;const auto coord=i.arg[0],y=sx16(m.r16(coord+2u)),x=sx16(m.r16(coord));const auto index=mul_signed32(y,m.r32(0x00836b4cu))+x,offset=index*80u;m.w32(base+offset+0x38u,i.arg[1]);return offset;
}
std::uint32_t fun_0057e6a0(Memory&m,const Inputs&i){
 const auto base=m.r32(0x00a5863cu);if(!base)return 0xffffffffu;const auto coord=i.arg[0],y=sx16(m.r16(coord+2u)),x=sx16(m.r16(coord));const auto index=mul_signed32(y,m.r32(0x00836b4cu))+x;return m.r32(base+index*80u+0x38u);
}
std::uint32_t fun_0058a810(Memory&m,const Inputs&i){
 const auto x=sx16(m.r16(i.cx)),y=sx16(m.r16(i.cx+2u));auto eax=y;const auto sum=x+y,lower=m.r32(0x00a58634u);
 if(s32(sum)<=s32(lower)||s32(x-y)>=s32(lower)||s32(y-x)>=s32(lower)||s32(sum)>s32(m.r32(0x00a58638u)))return eax&0xffffff00u;
 return put_al(eax,1);
}
std::uint32_t fun_00591510(Memory&m,const Inputs&i){
 auto eax=m.r32(i.cx+0x98u);const auto arg=i.arg[0];if(eax==0x1cu&&arg==5u)return arg;
 m.w32(i.cx+0x98u,arg);m.w32(i.cx+0xa0u,0xffffffffu);m.w8(i.cx+0xa4u,0);m.w32(i.cx+0xa8u,0);
 m.w32(i.cx+0xacu,m.r32(0x00a2896cu));m.w32(i.cx+0xb0u,m.r32(0x00a2896cu));m.w32(i.cx+0xb4u,i.stack_minus8);m.w32(i.cx+0xb8u,0);return i.stack_minus8;
}
std::uint32_t fun_00591a50(Memory&m,const Inputs&i){
 auto eax=m.r32(i.cx+0xa0u);if(eax==0xffffffffu)return put_al(eax,0);
 m.w32(i.cx+0x98u,eax);m.w32(i.cx+0xa0u,0xffffffffu);m.w32(i.cx+0xa8u,0);m.w32(i.cx+0xb0u,m.r32(0x00a2896cu));m.w32(i.cx+0xb4u,i.stack_minus8);m.w32(i.cx+0xb8u,0);auto result=m.r32(0x00a2896cu);m.w32(i.cx+0xacu,result);m.w8(i.cx+0xa4u,0);return put_al(result,1);
}
std::uint32_t fun_0059eca0(Memory&m,const Inputs&){return (m.r32(0x00a58cc4u)||m.r32(0x00a58cc8u))?1u:0u;}
std::uint32_t fun_005b3e40(Memory&m,const Inputs&){
 std::uint32_t eax=0;auto count=m.r32(0x00a27db8u);if(s32(count)>0){const auto base=m.r32(0x00a27dacu);for(;;){const auto p=m.r32(base+eax*4u);m.w32(p+0x59u,eax);count=m.r32(0x00a27db8u);++eax;if(s32(eax)>=s32(count))break;}}return put_al(eax,1);
}
std::uint32_t fun_005c28c0(Memory&m,const Inputs&i){for(auto a:{0x00a5a230u,0x00a5a254u,0x00a5a5c4u,0x00a5a278u})m.w8(a,0);return put_al(i.ax,0);}
std::uint32_t fun_005c2b00(Memory&m,const Inputs&i){const auto base=m.r32(0x00a27dacu);m.w32(0x00a27dc0u,i.cx);const auto v=m.r32(base);m.w32(0x00a27dc4u+i.cx*4u,v);return base;}
std::uint32_t fun_005c2cf0(Memory&m,const Inputs&i){const auto needle=m.r32(0x00a5a89cu);for(std::uint32_t n=0;n<8;++n){auto a=0x00a27dc4u+n*4u;if(m.r32(a)==needle){m.w32(a,i.cx);return n;}}return 0xffffffffu;}
std::uint32_t fun_005c2da0(Memory&m,const Inputs&i){if(!i.cx)return 0;for(auto a:{0x00a5a89cu,0x00a5a8a0u,0x00a5a8b0u,0x00a5a8a4u,0x00a5a8a8u,0x00a5a8acu})if(i.cx==m.r32(a))return 0;return 1;}
std::uint32_t fun_005c2de0(Memory&m,const Inputs&i){if(!i.cx)return 0;return (i.cx==m.r32(0x00a5a8a4u)||i.cx==m.r32(0x00a5a8a8u)||i.cx==m.r32(0x00a5a8acu))?1u:0u;}
std::uint32_t fun_005c2e70(Memory&m,const Inputs&){const auto a=m.r32(0x00a5a8a4u),b=m.r32(0x00a5a8a8u),c=m.r32(0x00a5a8acu);std::uint32_t eax=0;for(std::uint32_t n=0;n<8;++n){auto v=m.r32(0x00a27dc4u+n*4u);if(v&&(v==a||v==b||v==c))++eax;}return eax;}
std::uint32_t fun_005c2eb0(Memory&m,const Inputs&){
 auto eax=m.r32(0x00a25888u),ecx=m.r32(0x00a25e4cu);if(s32(eax)>=s32(ecx))eax=ecx;else ecx=eax;
 auto n=m.r32(0x00a27db8u);eax=n;if(s32(n)>=s32(ecx))return put_al(eax,1);
 eax=0;if(s32(ecx)<=0)return put_al(eax,1);const auto needle=m.r32(0x00a5a89cu);std::uint32_t p=0x00a27dc4u;
 for(;;){if(m.r32(p)==needle)return put_al(eax,0);++eax;p+=4u;if(s32(eax)>=s32(ecx))break;}return put_al(eax,1);
}
std::uint32_t fun_005c2ef0(Memory&m,const Inputs&){auto eax=m.r32(0x00a25888u),ecx=m.r32(0x00a25e4cu);if(s32(eax)<s32(ecx))ecx=eax;eax=ecx;return put_al(eax,s32(m.r32(0x00a27db8u))>s32(eax)?1u:0u);}
std::uint32_t fun_005c3c50(Memory&m,const Inputs&i){
 auto p=m.r32(0x00a27dc4u+i.cx*4u);std::uint32_t eax=0;if(!p)return 1;
 if(p==m.r32(0x00a5a8a4u)||p==m.r32(0x00a5a8a8u)||p==m.r32(0x00a5a8acu))return 1;
 return m.r32(p+0x65u)==1u?1u:0u;
}
std::uint32_t fun_005d46d0(Memory&m,const Inputs&i){
 const auto arr=m.r32(0x00a1e11cu),p=m.r32(arr+i.dx*4u);std::uint32_t status=0;
 if(m.r8(p+0x279u)!=0||m.r8(p+0x278u)!=0||m.r32(p+0x264u)==0x7eu||m.r8(p+0x27au)!=0)status=0xfffffff4u;
 if(m.r32(p+0x268u)==9u)--status;if(i.dx==0x7eu)--status;
 m.w32(i.cx,0);m.w32(i.cx+4u,status);return i.cx;
}
std::uint32_t fun_0060b9f0(Memory&m,const Inputs&){for(auto a:{0x00a5e2fcu,0x00a5e2fdu,0x00a5e2c8u})m.w8(a,0);for(auto a:{0x00a5e2e4u,0x00a5e250u,0x00a5e208u,0x00a5e280u,0x00a5e284u})m.w32(a,0);return 0;}
std::uint32_t fun_0060c730(Memory&m,const Inputs&i){const auto flag=m.r8(0x00a5e2fcu);return put_al(i.ax,(flag&&i.cx==4u)?0u:1u);}
std::uint32_t fun_0060f440(Memory&m,const Inputs&i){
 m.w32(0x00a5e280u,0xffffffffu);m.w8(0x00a5e2c8u,1);m.w32(0x00a5e284u,0xffffffffu);const auto flag=m.r8(0x00a5e2fcu);if(!flag)return 0xffffff00u;const auto count=m.r32(0x00a288b0u);if(s32(count)>0)return count;m.w32(0x00a5e280u,i.arg[0]);m.w32(0x00a5e284u,i.arg[1]);return i.arg[0];
}
std::uint32_t fun_0060f480(Memory&m,const Inputs&i){
 const auto flag=m.r8(0x00a5e2fcu);m.w8(0x00a5e2c8u,0);if(!flag||s32(m.r32(0x00a288b0u))>0||m.r32(0x00a5e208u)==0)return put_al(i.ax,flag);
 auto d0=abs_idiom(i.arg[0]-m.r32(0x00a5e280u));if(s32(d0)>3)return d0;
 auto d1=abs_idiom(i.arg[1]-m.r32(0x00a5e284u));if(s32(d1)>3)return d1;
 m.w32(0x00a5e208u,0);return d1;
}
std::uint32_t fun_00612440(Memory&m,const Inputs&i){
 auto a=(static_cast<std::uint32_t>(m.r8(i.cx+2u))>>(m.r8(0x0083b2f4u)&31u))<<(m.r32(0x0083b2f0u)&31u);
 auto b=(static_cast<std::uint32_t>(m.r8(i.cx+1u))>>(m.r8(0x0083b2fcu)&31u))<<(m.r32(0x0083b2f8u)&31u);
 auto c=(static_cast<std::uint32_t>(m.r8(i.cx))>>(m.r8(0x0083b2ecu)&31u))<<(m.r32(0x0083b2e8u)&31u);return a|b|c;
}
std::uint32_t fun_00620a50(Memory&m,const Inputs&i){
 auto ecx=i.cx,edi=ecx+i.dx;if(s32(ecx)>s32(edi))return i.ax;const auto arg1=i.arg[1]&0xffu,arg0=i.arg[0],src=i.arg[2];auto base=m.r32(0x00a1e264u);std::uint32_t last_eax=i.ax;
 for(;;){auto k=(base+ecx)&0xffu;const auto rec=0x00a1e264u+111u*k;
  last_eax=37u*k;
  if(m.r8(rec+0x13u)==arg1&&m.r32(rec+0x0fu)==arg0){const auto copied=m.r32(src);m.w32(rec+0x1bu,copied);const auto tail=m.r8(src+4u);m.w8(rec+0x1fu,tail);return put_al(src,tail);}
  ++ecx;if(s32(ecx)>s32(edi))break;
 }
 return last_eax;
}

const std::array<Entry,55>& entries_b(){static const std::array<Entry,55> e{{
 {0x000f2af0u,fun_004f2af0},{0x000f47b0u,fun_004f47b0},{0x000f47f0u,fun_004f47f0},{0x000f4d00u,fun_004f4d00},{0x000f4d40u,fun_004f4d40},
 {0x0011f0f0u,fun_0051f0f0},{0x0011f170u,fun_0051f170},{0x0011f1a0u,fun_0051f1a0},{0x0011f1b0u,fun_0051f1b0},{0x00122060u,fun_00522060},
 {0x001220c0u,fun_005220c0},{0x001228e0u,fun_005228e0},{0x00122ff0u,fun_00522ff0},{0x001239d0u,fun_005239d0},{0x001277b0u,fun_005277b0},
 {0x001298b0u,fun_005298b0},{0x00133dc0u,fun_00533dc0},{0x00134d60u,fun_00534d60},{0x00134de0u,fun_00534de0},{0x001350b0u,fun_005350b0},
 {0x001376f0u,fun_005376f0},{0x0013ba20u,fun_0053ba20},{0x00145490u,fun_00545490},{0x00145500u,fun_00545500},{0x0014b830u,fun_0054b830},
 {0x0015f720u,fun_0055f720},{0x0015f770u,fun_0055f770},{0x0016a990u,fun_0056a990},{0x0016a9b0u,fun_0056a9b0},{0x0016b760u,fun_0056b760},
 {0x0016b790u,fun_0056b790},{0x00172ad0u,fun_00572ad0},{0x0017e670u,fun_0057e670},{0x0017e6a0u,fun_0057e6a0},{0x0018a810u,fun_0058a810},
 {0x00191510u,fun_00591510},{0x00191a50u,fun_00591a50},{0x0019eca0u,fun_0059eca0},{0x001b3e40u,fun_005b3e40},{0x001c28c0u,fun_005c28c0},
 {0x001c2b00u,fun_005c2b00},{0x001c2cf0u,fun_005c2cf0},{0x001c2da0u,fun_005c2da0},{0x001c2de0u,fun_005c2de0},{0x001c2e70u,fun_005c2e70},
 {0x001c2eb0u,fun_005c2eb0},{0x001c2ef0u,fun_005c2ef0},{0x001c3c50u,fun_005c3c50},{0x001d46d0u,fun_005d46d0},{0x0020b9f0u,fun_0060b9f0},
 {0x0020c730u,fun_0060c730},{0x0020f440u,fun_0060f440},{0x0020f480u,fun_0060f480},{0x00212440u,fun_00612440},{0x00220a50u,fun_00620a50}}};return e;}
} // namespace ra2::recovered::global_b26
