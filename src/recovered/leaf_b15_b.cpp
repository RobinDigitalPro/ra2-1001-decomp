#include "leaf_b15_b.hpp"
#include <initializer_list>
namespace ra2::recovered::leaf {
static std::uint32_t b15_ring_next(std::uint32_t tail){auto v=(tail+1u)&0x800000ffu;if(s32(v)<0){--v;v|=0xffffff00u;++v;}return v;}
std::uint32_t fun_0049e990(Memory&m,const Inputs&i){auto v=i.arg[0];m.w32(i.cx+0x119c,v);auto r=(v&0xffffff00u)|(v!=0);m.w8(i.cx+0x1198,r);return r;}
std::uint32_t fun_0049eac0(Memory&m,const Inputs&i){m.w32(i.cx+4,i.arg[0]);m.w32(i.cx+8,i.arg[1]);m.w32(i.cx,0x786020);return i.cx;}
std::uint32_t fun_0049f150(Memory&m,const Inputs&i){m.w32(i.cx+4,i.arg[0]);m.w32(i.cx+8,i.arg[1]);m.w32(i.cx+0xc,0);m.w32(i.cx,0x785f8c);return i.cx;}
std::uint32_t fun_004a9800(Memory&m,const Inputs&i){m.w8(i.cx,0);m.w8(i.cx+1,0);m.w8(i.cx+2,0);return i.cx;}
std::uint32_t fun_004b1500(Memory&m,const Inputs&i){for(auto o:{0u,4u,8u,0x0cu,0x10u,0x14u,0x18u,0x1cu,0x20u,0x24u})m.w32(i.cx+o,0);m.w32(i.cx+0x28,0x10000);m.w8(i.cx+0x2c,0);return i.cx;}
std::uint32_t fun_004b22d0(Memory&m,const Inputs&i){auto p=m.r32(i.cx+0x20);if(p){m.w32(p+0x5c4,0);m.w32(i.cx+0x20,0);}return p;}
std::uint32_t fun_004b8b00(Memory&m,const Inputs&i){auto v=s32(i.arg[0]);auto r=v<127?i.arg[0]:127u;m.w16(i.cx+0x14,(r&0xffu)<<8);return r;}
std::uint32_t fun_004bbb70(Memory&m,const Inputs&i){auto v=m.r32(i.cx);if(!v)return 0;m.w8(i.cx+4,0);--v;m.w32(i.cx,v);if(v&1)m.w8(i.cx+4,1);return (v&0xffffff00u)|1u;}
std::uint32_t fun_004c1ca0(Memory&m,const Inputs&i){if(s32(m.r32(i.cx+0x6c))<=0)return 0;return m.r32(m.r32(i.cx+0x60));}
std::uint32_t fun_004c1cb0(Memory&m,const Inputs&i){auto rnd=[](std::uint32_t v){auto s=s32(v);return static_cast<std::uint16_t>(sar(v+(((s<0)?0xffffffffu:0u)&0xffu),8));};auto x=rnd(m.r32(i.cx+0x34)),y=rnd(m.r32(i.cx+0x38));auto p=i.arg[0];m.w32(p,std::uint32_t(x)|(std::uint32_t(y)<<16));return p;}
std::uint32_t fun_004c86f0(Memory&m,const Inputs&i){m.w32(i.arg[0],m.r32(i.arg[1]));return i.arg[0];}
std::uint32_t fun_004cd5b0(Memory&m,const Inputs&i){m.w32(i.cx+0x490,0);m.w32(i.cx+0x494,0);return 0;}
std::uint32_t fun_004ce7c0(Memory&m,const Inputs&i){auto count=m.r32(i.cx+0x10),idx=i.arg[0];if(s32(idx)>=s32(count))return 0;--count;m.w32(i.cx+0x10,count);if(s32(idx)<s32(count)){auto n=idx;do{auto p=m.r32(i.cx+4);++n;auto v=m.r32(p+n*4);m.w32(p+(n-1)*4,v);count=m.r32(i.cx+0x10);}while(s32(n)<s32(count));}return (idx&0xffffff00u)|1u;}
std::uint32_t fun_004cee20(Memory&m,const Inputs&i){if(i.arg[0]||m.r8(i.cx+0x1c)){m.w8(i.cx+0x1c,0);return 1;}return i.arg[0]&0xffffff00u;}
std::uint32_t fun_004df7b0(Memory&m,const Inputs&i){m.w32(i.cx+4,i.arg[0]);m.w8(i.cx+8,0);m.w8(i.cx+9,1);m.w32(i.cx+0xc,0);m.w32(i.cx,0x78dbd0);return i.cx;}
std::uint32_t fun_004dfd20(Memory&m,const Inputs&i){auto p=m.r32(i.cx+4),v=m.r32(i.cx+8);return v<m.r32(p+0x10)?1u:0u;}
std::uint32_t fun_004dff60(Memory&m,const Inputs&i){m.w32(i.cx+4,0);m.w32(i.cx+8,0);m.w32(i.cx+0xc,2);m.w32(i.cx,0x78dc3c);return i.cx;}
std::uint32_t fun_004e4ba0(Memory&m,const Inputs&i){auto v=i.arg[0];if(v==m.r32(i.cx+0x30))return (i.cx&0xffffff00u)|1u;if(v==0xffffffffu)return i.cx&0xffffff00u;return m.r32(i.cx+0x5674)&(1u<<(v&31))?1u:0u;}
std::uint32_t fun_004e4be0(Memory&m,const Inputs&i){auto v=i.arg[0];if(!v)return i.cx&0xffffff00u;if(v==i.cx)return (i.cx&0xffffff00u)|1u;if(m.r32(v+0x30)==m.r32(i.cx+0x30))return (i.cx&0xffffff00u)|1u;if(m.r32(v+0x30)==0xffffffffu)return i.cx&0xffffff00u;return (i.cx&0xffffff00u)|((m.r32(i.cx+0x5674)&(1u<<(m.r32(v+0x30)&31)))!=0);}
std::uint32_t fun_004ee170(Memory&m,const Inputs&i){auto count=m.r32(i.cx+0x551c);if(s32(count)<=0)return count;std::uint32_t n=0;do{auto p=m.r32(i.cx+0x5510);auto e=p+n*8;if(m.r32(e)==i.arg[0])m.w8(e+4,1);count=m.r32(i.cx+0x551c);++n;}while(s32(n)<s32(count));return count;}
std::uint32_t fun_004f60c0(Memory&m,const Inputs&i){m.w8(i.cx,i.arg[0]);m.w8(i.cx+1,i.arg[1]);m.w8(i.cx+2,i.arg[2]);return i.arg[2]&255;}
std::uint32_t fun_004f6e40(Memory&m,const Inputs&i){auto count=m.r32(i.cx+0x10),p=m.r32(i.cx+4),q=i.arg[0];for(std::uint32_t n=0;s32(n)<s32(count);++n){auto e=p+n*8;if(m.r32(e)==m.r32(q)&&m.r8(e+4)==m.r8(q+4))return n;}return 0xffffffffu;}
std::uint32_t fun_004f8120(Memory&m,const Inputs&i){auto count=m.r32(i.cx+0x10),idx=i.arg[0];if(s32(idx)>=s32(count))return 0;--count;m.w32(i.cx+0x10,count);if(s32(idx)<s32(count)){auto n=idx;do{auto p=m.r32(i.cx+4);++n;auto v=m.r32(p+n*4);m.w32(p+(n-1)*4,v);count=m.r32(i.cx+0x10);}while(s32(n)<s32(count));}return (idx&0xffffff00u)|1u;}
std::uint32_t fun_004f9b30(Memory&m,const Inputs&i){m.w32(i.cx+4,0);m.w32(i.cx+8,0);m.w8(i.cx+0xc,1);m.w8(i.cx+0xd,0);m.w32(i.cx+0x14,10);m.w32(i.cx+0x10,0);m.w32(i.cx,0x78e0b8);return i.cx;}
std::uint32_t fun_004fe6a0(Memory&m,const Inputs&i){return (m.r8(i.cx)==m.r8(i.arg[0])&&m.r8(i.cx+1)==m.r8(i.arg[0]+1)&&m.r8(i.cx+2)==m.r8(i.arg[0]+2))?0u:1u;}
std::uint32_t fun_00508bb0(Memory&m,const Inputs&i){auto v=m.r32(i.cx+0x5ac);switch(v){case 0xb:case 0xc:case 0xd:case 0xe:case 0xf:case 0x22:case 0x23:case 0x24:case 0x14:case 0x15:return 1;default:return 0;}}
std::uint32_t fun_00521a40(Memory&m,const Inputs&i){auto count=m.r32(i.cx+0x10),idx=i.arg[0];if(s32(idx)>=s32(count))return 0;--count;m.w32(i.cx+0x10,count);if(s32(idx)<s32(count)){auto n=idx;do{auto p=m.r32(i.cx+4);++n;auto v=m.r32(p+n*4);m.w32(p+(n-1)*4,v);count=m.r32(i.cx+0x10);}while(s32(n)<s32(count));}return (idx&0xffffff00u)|1u;}
std::uint32_t fun_005229e0(Memory&m,const Inputs&i){auto a=m.r32(i.arg[0]);m.w32(i.cx,a);auto b=m.r32(i.arg[1]);m.w32(i.cx+4,b);auto c=m.r16(i.arg[1]+4);m.w16(i.cx+8,c);return (i.arg[1]&0xffff0000u)|c;}
std::uint32_t fun_00522aa0(Memory&m,const Inputs&i){for(unsigned n=0;n<10;++n)if(m.r8(i.cx+n)!=255)return 0;return 1;}
std::uint32_t fun_00524210(Memory&m,const Inputs&i){auto p=m.r32(i.cx+0x48);if(!p)return 0;m.w32(p+0x28,i.arg[0]);p=m.r32(i.cx+0x48);m.w32(p+0x2c,i.arg[1]);p=m.r32(i.cx+0x48);m.w32(p+0x30,i.arg[2]);return p;}
std::uint32_t fun_00524240(Memory&m,const Inputs&i){auto a=m.r32(i.cx+0x4c);if(a){m.w32(a+0x28,i.arg[0]);a=m.r32(i.cx+0x4c);m.w32(a+0x2c,i.arg[1]);a=m.r32(i.cx+0x4c);m.w32(a+0x30,i.arg[2]);}auto b=m.r32(i.cx+0x50);if(b){m.w32(b+0x28,i.arg[0]);b=m.r32(i.cx+0x50);m.w32(b+0x2c,i.arg[1]);auto c=m.r32(i.cx+0x50);m.w32(c+0x30,i.arg[2]);return b;}return 0;}
std::uint32_t fun_00524460(Memory&m,const Inputs&i){auto idx=i.arg[0];if(s32(idx)<0||s32(idx)>=s32(m.r32(i.cx+0x44)))return 0xffffffffu;return m.r32(m.r32(i.cx+0x28+idx*4)+0x60);}
std::uint32_t fun_00524480(Memory&m,const Inputs&i){auto n=m.r32(i.cx+0x44);for(std::uint32_t k=0;s32(k)<s32(n);++k){auto p=m.r32(i.cx+0x28+k*4);if(m.r32(p+0x60)==i.arg[0])return p+0x64;}return 0;}
std::uint32_t fun_005244c0(Memory&m,const Inputs&i){auto n=m.r32(i.cx+0x44);for(std::uint32_t k=0;s32(k)<s32(n);++k){auto p=m.r32(i.cx+0x28+k*4);if(m.r32(p+0x60)==i.arg[0])return p+0x4c;}return 0;}
std::uint32_t fun_00524500(Memory&m,const Inputs&i){auto n=m.r32(i.cx+0x44);for(std::uint32_t k=0;s32(k)<s32(n);++k)if(m.r32(m.r32(i.cx+0x28+k*4)+0x60)==i.arg[0])return k;return 0xffffffffu;}
std::uint32_t fun_00524ce0(Memory&m,const Inputs&i){if(!m.r8(i.cx+4)||!m.r8(i.cx+5))return 0;return m.r32(m.r32(m.r32(i.cx+0x48)+4)+0x28);}
std::uint32_t fun_00524d20(Memory&m,const Inputs&i){if(!m.r8(i.cx+4)||!m.r8(i.cx+5))return 0;auto p=m.r32(i.cx+0x4c);if(!p)return 0;return m.r32(m.r32(p+4)+0x28);}
std::uint32_t fun_00524e40(Memory&m,const Inputs&i){auto v=i.arg[0]&0xffff;m.w16(i.cx+0x22,((v&255)<<8)|(v>>8));return v;}
std::uint32_t fun_00525a60(Memory&m,const Inputs&i){auto p=m.r32(i.cx+0x4c);if(p){auto d=p+0x4c;m.w32(d,m.r32(i.arg[0]));m.w32(d+4,m.r32(i.arg[0]+4));m.w16(d+8,m.r16(i.arg[0]+8));return d;}return 0;}
std::uint32_t fun_00525a90(Memory&m,const Inputs&i){auto p=m.r32(i.cx+0x48);if(p)m.w8(p+0xc4,0);return p;}
std::uint32_t fun_00525aa0(Memory&m,const Inputs&i){auto p=m.r32(i.cx+0x48);if(p)m.w8(p+0xc4,1);return p;}
std::uint32_t fun_0052c8c0(Memory&m,const Inputs&i){for(unsigned n=0;n<4;++n)m.w32(i.cx+4*n,i.arg[n]);return i.cx;}
std::uint32_t fun_0052d0f0(Memory&m,const Inputs&i){auto bit=i.dx;auto shift=bit&0x80000007u;if(s32(shift)<0){--shift;shift|=0xfffffff8u;++shift;}auto adj=bit+(s32(bit)<0?7u:0u);auto byteoff=sar(adj,3);auto mask=static_cast<std::uint8_t>(1u<<(shift&31u));return (m.r8(i.cx+byteoff)&mask)?1u:0u;}
std::uint32_t fun_00530b80(Memory&m,const Inputs&i){auto h=m.r32(i.cx+0x314),t=m.r32(i.cx+0x318);if(h==t)return h&0xffff0000u;return (h&0xffff0000u)|m.r16(i.cx+0x114+h*2);}
std::uint32_t fun_00530ba0(Memory&m,const Inputs&i){auto t=m.r32(i.cx+0x318),h=m.r32(i.cx+0x314);auto next=b15_ring_next(t);if(next==h)return 0;m.w16(i.cx+0x114+t*2,i.arg[0]);m.w32(i.cx+0x318,next);return (next&0xffffff00u)|1u;}
std::uint32_t fun_00530be0(Memory&m,const Inputs&i){auto t=m.r32(i.cx+0x318);auto next=b15_ring_next(t);return next==m.r32(i.cx+0x314)?1u:0u;}
std::uint32_t fun_00537220(Memory&m,const Inputs&i){auto p=m.r32(i.cx+8);if(!p)return i.cx;while(p!=i.cx){auto next=m.r32(p+8);if(!next)return p;p=next;}return i.cx;}
std::uint32_t fun_00537250(Memory&m,const Inputs&i){auto p=m.r32(i.cx+4);if(!p)return i.cx;while(p!=i.cx){auto next=m.r32(p+4);if(!next)return p;p=next;}return i.cx;}
std::uint32_t fun_005376d0(Memory&m,const Inputs&i){auto p=m.r32(i.cx+4);if(p){m.w32(p+0x94,0);m.w32(i.cx+4,0);}return p;}
std::uint32_t fun_00538660(Memory&m,const Inputs&i){auto n=m.r32(i.cx+0x44);if(!n)return 0;auto ix=s32(i.arg[0])<s32(n-1)?i.arg[0]:n-1;return m.r32(m.r32(i.cx+0x38)+ix*4);}
}
