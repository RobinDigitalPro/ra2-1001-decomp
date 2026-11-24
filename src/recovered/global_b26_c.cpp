#include "recovered/global_b26_memory.hpp"
#include <cstdint>

namespace ra2::recovered::global_b26 {
namespace {
constexpr std::uint32_t A=0x00a2896cu;
std::uint32_t rate(std::uint32_t x){const auto h=imul_high(x,0x51eb851fu);return sar(h,4)+(h>>31);}
}
std::uint32_t fun_006216b0(Memory&m,const Inputs&i){auto n=m.r32(0x84e5a0);if(!n)return i.ax;auto idx=m.r32(0x84e5a4);while(n){auto off=111u*idx+0x84e5adu;if((m.r8(off)&1u)||s32(m.r32(0xa2896c))>s32(m.r32(off+2))){idx=(idx+1u)&0x3fffu;--n;m.w32(0x84e5a4,idx);m.w32(0x84e5a0,n);}else break;}return idx;}
std::uint32_t fun_0062eb50(Memory&m,const Inputs&i){auto v=i.arg[0];auto p=m.r32(0x821b88);auto z=v*m.r32(p+0x1448);m.w32(i.cx+0x4c,v);m.w32(i.cx+0x6c,z);m.w32(i.cx+0x70,z);return z;}
std::uint32_t fun_00633590(Memory&m,const Inputs&){auto x=m.r32(0xa9e318);return (x&0xffffff00u)|(x==0);}
std::uint32_t fun_0065a1d0(Memory&m,const Inputs&i){auto v=m.r32(0xa9e990);for(unsigned k=0;k<101;++k)m.w32(i.cx+0x632+4*k,v);return i.cx+0x7c6;}
std::uint32_t fun_0065a1f0(Memory&m,const Inputs&i){auto ix=i.arg[0],eax=ix;if(s32(ix)<0||ix>=101)return (eax&0xffffff00u);auto q=i.cx+0x632+4*ix;auto dx=m.r16(q);if(dx!=m.r16(0xa9e990))return (eax&0xffffff00u)|1u;auto ax=m.r16(q+2);if(ax!=m.r16(0xa9e992))return (eax&0xffff0000u)|(ax&0xff00u)|1u;return (eax&0xffff0000u)|(ax&0xff00u);}
std::uint32_t fun_00673f10(Memory&m,const Inputs&i){auto p=i.cx;auto v=i.stack_minus8;m.w8(p+0x39,0);m.w8(p+0x3a,0);m.w8(p+0x3b,0);m.w32(p+0x3c,0xffffffffu);m.w32(p+0x40,0);m.w32(p+0x48,0);m.w32(p+0x50,0);auto x=p+0x78;for(unsigned k=0;k<75;++k){m.w32(x-0x24,0);m.w32(x-0x20,0);m.w32(x-0x1c,0);m.w32(x-0x18,0);m.w32(x-0x14,0);auto global=m.r32(0xa2896c);auto b=x-0xc;m.w32(x,0);x+=0x30;m.w32(b,global);m.w32(b+4,v);m.w32(b+8,0);m.w32(x-0x40,0);m.w32(x-0x28,0);}return x;}
std::uint32_t fun_00676fe0(Memory&m,const Inputs&){auto p=m.r32(0xa255c8);if(p)m.w32(0xa28988,8);return p;}
std::uint32_t fun_006777d0(Memory&m,const Inputs&){auto p=m.r32(0xa255c0);auto x=m.r32(0x82196c)-m.r32(0xaa486c)-((m.r8(p+0x2239)?8u:0u)+0x12u)+m.r32(0x821964)-7u;return rate(x);}
std::uint32_t fun_00677820(Memory&m,const Inputs&){auto p=m.r32(0xa255c0);auto x=m.r32(0x82196c)-m.r32(0xaa486c)-((m.r8(p+0x2239)?8u:0u)+0x12u)+m.r32(0x821964)-7u;return rate(x)*2u;}
std::uint32_t fun_00694380(Memory&m,const Inputs&i){auto eax=i.ax;if(m.r32(i.cx)==0xffffffffu){eax=m.r32(A);m.w32(i.cx,eax);}return eax;}
std::uint32_t fun_00694e30(Memory&m,const Inputs&i){auto n=m.r32(0xa27f98),t=m.r32(0xa27f8c);if(s32(n)<=0)return 0;for(std::uint32_t k=0;k<n;++k){auto p=m.r32(t+4*k);if(m.r32(p+0xbc)==i.cx)return p;}return 0;}
std::uint32_t fun_00695bd0(Memory&m,const Inputs&i){auto n=0u;for(auto tab=0x7e0088u;tab<0x7e00b4u;tab+=4){auto p=m.r32(tab),a=i.cx,b=p;for(;;){auto x=m.r8(a),y=m.r8(b);if(x!=y)break;if(x==0)return n;x=m.r8(a+1);y=m.r8(b+1);if(x!=y)break;if(x==0)return n;a+=2;b+=2;}++n;}return m.r32(0x7e0084);}
std::uint32_t fun_00695cc0(Memory&m,const Inputs&i){auto p=m.r32(0xaa8c9c);m.w32(0xaa5db4,i.cx);auto stride=m.r32(p+8);auto base=m.r32(0xaa8ca0);auto x=m.r32(base)-stride*i.cx;auto q=m.r32(0xaa8c94);auto bound=m.r32(q)+m.r32(q+8);m.w32(0xaa5e84,x);if(s32(x)<=s32(bound))m.w32(0xaa5e84,bound);return x;}
std::uint32_t fun_006a7e30(Memory&m,const Inputs&i){auto ix=m.r32(i.cx+0x74);auto table=m.r32(0xa286fc);auto object=m.r32(table+4*ix);auto field=m.r32(i.cx+0x48);m.w32(object+0x55c,field);auto p=i.arg[0];if(p)m.w8(p+0x144,1);return (p&0xffffff00u)|1u;}
std::uint32_t fun_006a8910(Memory&m,const Inputs&i){auto ix=m.r32(i.cx),n=m.r32(i.cx+8);if(ix==0xffffffffu)return i.ax;auto d=m.r32(0xa2896c)-ix;if(s32(d)<s32(n)){n-=d;m.w32(i.cx,0xffffffffu);m.w32(i.cx+8,n);return n;}m.w32(i.cx+8,0);m.w32(i.cx,0xffffffffu);return 0;}
std::uint32_t fun_006a98d0(Memory&m,const Inputs&i){auto n=m.r32(0xaa7960),t=m.r32(0xaa7954);auto eax=i.ax;if(s32(n)<=0)return (eax&0xffffff00u)|1u;for(std::uint32_t k=0;k<n;++k){eax=m.r32(t+4*k);if(eax!=i.cx){eax=m.r32(eax+0x24);if(eax==m.r32(i.cx+0x24))return eax&0xffffff00u;}}return (eax&0xffffff00u)|1u;}
std::uint32_t fun_006ac790(Memory&m,const Inputs&i){auto n=m.r32(i.cx+0x9c),p=i.cx+0xa8;std::uint32_t best=0;if(s32(n)<=0)return 0;auto global=m.r32(0xa255c8);while(n){auto q=m.r32(p);auto x=m.r32(q+0x55c);if(s32(x)>s32(best))best=x;else if(x==0xffffffffu&&global)best=11;p+=8;--n;}return best;}
std::uint32_t fun_006b33d0(Memory&m,const Inputs&i){if(!i.cx||!m.r8(i.cx+0x7d))return i.ax&0xffffff00u;auto eax=m.r32(i.cx+0x6c);if(!eax)return eax;eax=m.r32(0xa283c4);if(eax)return (eax&0xffffff00u)|1u;return m.r8(i.cx+0x76)==0?1u:0u;}
std::uint32_t fun_006b57a0(Memory&m,const Inputs&i){auto n=m.r32(0x84e4b8),t=m.r32(0x84e4ac);if(s32(n)<=0)return 0;for(std::uint32_t k=0;k<n;++k){auto p=m.r32(t+4*k);if(m.r32(p+0x24)==i.cx)return p;}return 0;}
std::uint32_t fun_006c9e00(Memory&m,const Inputs&i){auto ix=m.r32(i.cx+0x130),n=m.r32(i.cx+0x138);if(ix!=0xffffffffu){auto d=m.r32(0xa2896c)-ix;n=s32(d)<s32(n)?n-d:0u;}return (n&0xffffff00u)|(n==0);}
std::uint32_t fun_006ccf00(Memory&m,const Inputs&i){auto x=m.r32(0xa2896c);m.w32(0xaa7c80,x);auto v=i.stack_minus8;m.w32(0xaa7c84,v);m.w32(0xaa7c88,0x19);return v;}
std::uint32_t fun_006ccf30(Memory&m,const Inputs&i){m.w8(0x7e09a0,i.cx);return i.ax;}
std::uint32_t fun_006cdc20(Memory&m,const Inputs&i){m.w32(i.cx+0x16c,0);m.w32(i.cx+0x154,m.r32(0xa2896c));m.w32(i.cx+0x158,i.stack_minus8);m.w32(i.cx+0x15c,i.arg[0]);return i.stack_minus8;}
std::uint32_t fun_006cec80(Memory&m,const Inputs&i){auto ix=m.r32(i.cx+0x148),n=m.r32(i.cx+0x150);if(ix!=0xffffffffu){auto d=m.r32(0xa2896c)-ix;n=s32(d)<s32(n)?n-d:0u;}return (n&0xffffff00u)|(n==0);}
std::uint32_t fun_006e7010(Memory&m,const Inputs&i){auto cap=(m.r8(0xa28770)==0&&m.r8(0xa28953)==0)?0xa8u:0u;m.w32(i.cx,cap);m.w32(i.cx+4,0);m.w32(i.cx+8,m.r32(0x821988)-0xa8u);m.w32(i.cx+12,m.r32(0x82198c)-0x20u);return i.cx;}
std::uint32_t fun_006e74e0(Memory&m,const Inputs&i){return m.r32(i.cx==0x280?0x7e1f94:0x7e1f98);}
std::uint32_t fun_006e7500(Memory&m,const Inputs&i){return m.r32(i.cx==0x280?0x7e1f9c:0x7e1fa0);}
std::uint32_t fun_006e9590(Memory&m,const Inputs&i){std::uint32_t w,b;if(!i.cx){w=m.r16(0xaa8af0);b=m.r8(0xaa8af2);m.w16(0xaa8b20,w);m.w8(0xaa8b22,b);return (i.ax&0xffff0000u)|w;}w=m.r16(0xaa8b98);b=m.r8(0xaa8b9a);m.w16(0xaa8b20,w);m.w8(0xaa8b22,b);return (i.ax&0xffffff00u)|b;}
std::uint32_t fun_006eb5d0(Memory&m,const Inputs&i){m.w8(0xaa8db8,0);return i.ax;}
std::uint32_t fun_006eb5e0(Memory&m,const Inputs&i){m.w32(0xaa8db4,i.cx);m.w8(0xaa8db8,0);return i.ax;}
std::uint32_t fun_006ec7b0(Memory&m,const Inputs&i){auto obj=m.r32(0xaa8dc0);if(!obj)return 0;auto eax=m.r32(obj+0x10)-1u;if(s32(eax)<0)return eax;auto p=m.r32(obj+4)+4*eax;for(;;){if(m.r32(p)==i.cx)break;--eax;p-=4;if(s32(eax)<0)return eax;}auto count=m.r32(obj+0x10);if(s32(eax)>=s32(count))return eax;--count;m.w32(obj+0x10,count);if(s32(eax)>=s32(count))return eax;auto base=m.r32(obj+4);++eax;for(;;){m.w32(base+4*eax-4,m.r32(base+4*eax));auto current=m.r32(obj+0x10);if(s32(eax)>=s32(current))return eax;++eax;}}
std::uint32_t fun_006eedc0(Memory&m,const Inputs&i){if(!i.cx)return 0;auto slot=m.r32(0xab7edc),out=0xaa8decu+(slot<<10),p=out,src=i.cx;std::uint32_t n=0x400;while(m.r16(src)!=0&&n){m.w8(p,m.r8(src));++p;src+=2;--n;}m.w8(p,0);m.w8(out+0x3ff,0);m.w32(0xab7edc,(m.r32(0xab7edc)+1)&7u);return out;}
std::uint32_t fun_006eee20(Memory&m,const Inputs&i){if(!i.cx)return 0;auto slot=m.r32(0xab7ee0),out=0xaace7cu+(slot<<11),p=out;std::uint32_t n=0x400;auto src=i.cx;while(m.r8(src)!=0&&n){m.w16(p,m.r8(src));p+=2;++src;--n;}m.w16(p,0);m.w16(out+0x7fe,0);m.w32(0xab7ee0,(m.r32(0xab7ee0)+1)&7u);return out;}
std::uint32_t fun_007003b0(Memory&m,const Inputs&i){auto eax=i.dx;if(s32(eax)<=0)return eax;auto src=i.cx,tab=m.r32(0xab8094);while(eax){auto x=m.r16(src);src+=2;--eax;m.w16(src-2,m.r16(tab+2*x));}return 0;}
std::uint32_t fun_00704d20(Memory&m,const Inputs&i){auto n=m.r32(0xab81d8),t=m.r32(0xab81cc);auto a=m.r16(i.cx),b=m.r16(i.cx+2);auto idx=n-1u;if(s32(idx)<0)return 0;for(;;){auto p=m.r32(t+4*idx);if(m.r16(p+0xe0)==a&&m.r16(p+0xe2)==b)return p;--idx;if(s32(idx)<0)return 0;}}
std::uint32_t fun_00707cf0(Memory&m,const Inputs&i){auto v=i.arg[0];for(unsigned k=0;k<3;++k){auto a=0x7e2f78u-8*k;if(v>=m.r32(a))return m.r32(a+4);}return m.r32(0x7e2f7c);}
std::uint32_t fun_007095f0(Memory&m,const Inputs&i){auto n=m.r32(0xab82a8),t=m.r32(0xab829c);if(s32(n)<=0)return 0xffffffffu;for(std::uint32_t k=0;k<n;++k)if(m.r32(t+4*k)==i.cx)return k;return 0xffffffffu;}
std::uint32_t fun_0070a460(Memory&m,const Inputs&i){auto n=m.r32(0xab83c0);if(s32(i.cx)<0||s32(i.cx)>=s32(n))return 0x7b907c;return m.r32(m.r32(0xab83b4)+4*i.cx);}
std::uint32_t fun_0070aab0(Memory&m,const Inputs&i){m.w32(0x7e3438,i.cx);if(s32(i.cx)>=255)m.w32(0x7e3438,255);return i.ax;}
std::uint32_t fun_0070b250(Memory&m,const Inputs&i){auto n=m.r32(0xab83c0);if(s32(i.cx)<0||s32(i.cx)>=s32(n))return (i.ax&0xffffff00u)|1u;auto p=m.r32(m.r32(0xab83b4)+4*i.cx);return (m.r32(p+0x48)==2)?1u:0u;}
std::uint32_t fun_0070b500(Memory&m,const Inputs&){auto x=m.r32(0xab82f8)+1u;m.w32(0xab82f8,x);return x;}
std::uint32_t fun_0070b510(Memory&m,const Inputs&){auto x=m.r32(0xab82f8);if(!x)return x;--x;m.w32(0xab82f8,x);if(s32(x)<0)m.w32(0xab82f8,0);return x;}
std::uint32_t fun_007126e0(Memory&m,const Inputs&){for(unsigned k=0;k<18;++k){auto byte=k>>3,bit=k&7;m.w8(0xae0aa0+byte,m.r8(0xae0aa0+byte)&~(1u<<bit));}auto out=m.r8(0xae0aa0)|0x40u;m.w8(0xae0aa0,out);return out;}
std::uint32_t fun_0072a500(Memory&m,const Inputs&i){auto n=m.r32(0xb0d858);auto eax=n-1u;if(s32(eax)<0)return 0;do{if(m.r32(0xb0d634+8*eax)==i.cx)return m.r32(0xb0d630+8*eax);--eax;}while(s32(eax)>=0);return 0;}
std::uint32_t fun_0072a570(Memory&m,const Inputs&i){auto n=m.r32(0xb0d858);auto eax=n-1u;if(s32(eax)<0)return 0;do{if(m.r32(0xb0d630+8*eax)==i.cx&&eax>0)return m.r32(0xb0d628+8*eax);--eax;}while(s32(eax)>=0);return 0;}
std::uint32_t fun_00730970(Memory&m,const Inputs&){auto x=m.r32(0xa255d4);return x==1||x==2;}
std::uint32_t fun_00730e70(Memory&m,const Inputs&i){if(m.r32(0xa255c8)!=4)return i.ax&0xffffff00u;auto x=m.r32(0xb0eec0)>>8;return (x&0xffffff00u)|(x&1u);}
std::uint32_t fun_0076da9e(Memory&m,const Inputs&){m.w32(0x8174a4,0x772742);m.w32(0x8174a0,0x772a98);m.w32(0x8174a8,0x7727a8);m.w32(0x8174ac,0x7726e8);m.w32(0x8174b0,0x772790);m.w32(0x8174b4,0x772a98);return 0x772a98;}
std::uint32_t fun_0077337d(Memory&m,const Inputs&i){auto p=m.r32(0xb10e18),n=m.r32(0xb10e14),end=p+n*20u,v=i.arg[0];while(p<end){if(v-m.r32(p+0xc)<0x100000u)return p;p+=0x14;}return 0;}
std::uint32_t fun_007785b2(Memory&m,const Inputs&i){auto key=i.arg[0],base=i.arg[1],p=base,n=m.r32(0x817bcc);const auto end=base+n*12u;if(m.r32(p+4)!=key){for(;;){p+=12;if(p>=end)break;if(m.r32(p+4)==key)break;}}if(p>=end||m.r32(p+4)!=key)return 0;return p;}
std::uint32_t fun_00779a6c(Memory&m,const Inputs&i){auto key=i.arg[0],base=i.arg[1],p=base,n=m.r32(0x817bcc);const auto end=base+n*12u;if(m.r32(p)!=key){for(;;){p+=12;if(p>=end)break;if(m.r32(p)==key)break;}}if(p>=end||m.r32(p)!=key)return 0;return p;}
std::uint32_t fun_0077b794(Memory&m,const Inputs&i){auto x=i.arg[0];if(x>=m.r32(0xb10e00))return 0;const auto bit=x&0x1fu;const auto word=sar(x,5);auto q=m.r32(0xb10d00+4*word);return m.r8(q+4+36*bit)&0x40u;}

const std::array<Entry,52>& entries_c(){static const std::array<Entry,52> e{{
{0x2216b0,fun_006216b0},{0x22eb50,fun_0062eb50},{0x233590,fun_00633590},{0x25a1d0,fun_0065a1d0},{0x25a1f0,fun_0065a1f0},{0x273f10,fun_00673f10},{0x276fe0,fun_00676fe0},{0x2777d0,fun_006777d0},{0x277820,fun_00677820},{0x294380,fun_00694380},{0x294e30,fun_00694e30},{0x295bd0,fun_00695bd0},{0x295cc0,fun_00695cc0},{0x2a7e30,fun_006a7e30},{0x2a8910,fun_006a8910},{0x2a98d0,fun_006a98d0},{0x2ac790,fun_006ac790},{0x2b33d0,fun_006b33d0},{0x2b57a0,fun_006b57a0},{0x2c9e00,fun_006c9e00},{0x2ccf00,fun_006ccf00},{0x2ccf30,fun_006ccf30},{0x2cdc20,fun_006cdc20},{0x2cec80,fun_006cec80},{0x2e7010,fun_006e7010},{0x2e74e0,fun_006e74e0},{0x2e7500,fun_006e7500},{0x2e9590,fun_006e9590},{0x2eb5d0,fun_006eb5d0},{0x2eb5e0,fun_006eb5e0},{0x2ec7b0,fun_006ec7b0},{0x2eedc0,fun_006eedc0},{0x2eee20,fun_006eee20},{0x3003b0,fun_007003b0},{0x304d20,fun_00704d20},{0x307cf0,fun_00707cf0},{0x3095f0,fun_007095f0},{0x30a460,fun_0070a460},{0x30aab0,fun_0070aab0},{0x30b250,fun_0070b250},{0x30b500,fun_0070b500},{0x30b510,fun_0070b510},{0x3126e0,fun_007126e0},{0x32a500,fun_0072a500},{0x32a570,fun_0072a570},{0x330970,fun_00730970},{0x330e70,fun_00730e70},{0x36da9e,fun_0076da9e},{0x37337d,fun_0077337d},{0x3785b2,fun_007785b2},{0x379a6c,fun_00779a6c},{0x37b794,fun_0077b794}}};return e;}
}
