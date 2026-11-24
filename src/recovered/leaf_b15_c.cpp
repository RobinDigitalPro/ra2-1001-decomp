#include "leaf_b15_c.hpp"

namespace ra2::recovered::leaf {
std::uint32_t fun_005a9410(Memory&m,const Inputs&i){auto p=m.r32(i.cx+0x1c);m.w32(i.cx+0x30,i.arg[0]);auto v=sx16(m.r16(p+6));if(i.arg[0]>=v){v-=1;m.w32(i.cx+0x30,v);}return v;}
std::uint32_t fun_005c6310(Memory&m,const Inputs&i){std::uint32_t a=0;if(s32(i.dx)<=0)return 0;for(std::uint32_t n=0;n<i.dx;++n){auto b=m.r8(i.cx+n);a=(a<<1)+b+(a>>31);}return a;}
std::uint32_t fun_005c8f30(Memory&m,const Inputs&i){auto p=m.r32(i.cx+0x38);return p?m.r32(m.r32(p+4)+0x28):0;}
std::uint32_t fun_005cc8c0(Memory&,const Inputs&i){return i.arg[0]?1u:0u;}
std::uint32_t fun_005cd850(Memory&m,const Inputs&i){auto s=i.arg[0],d=i.cx+0x88;auto a=m.r32(s);m.w32(d,a);auto b=m.r32(s+4);m.w32(d+4,b);auto c=m.r32(s+8);m.w32(d+8,c);return c;}
std::uint32_t fun_005fa670(Memory&m,const Inputs&i){auto d=i.arg[0],old=m.r32(i.cx+4);m.w32(d+0xc,old);m.w32(i.cx+4,d);return d;}
std::uint32_t fun_00607ad0(Memory&m,const Inputs&i){auto a=i.arg[0];m.w32(i.cx+0x38,a);if(a)m.w8(i.cx+0xc,1);m.w32(i.cx+0x13c,0);m.w32(i.cx+0x140,0);return a;}
std::uint32_t fun_00608c30(Memory&m,const Inputs&i){auto count=s32(m.r32(i.cx+0x10));if(count<=0)return 0xffffffffu;auto arr=m.r32(i.cx+4),key=i.arg[0];for(std::int32_t n=0;n<count;++n)if(m.r32(m.r32(arr+std::uint32_t(n)*4))==key)return static_cast<std::uint32_t>(n);return 0xffffffffu;}
std::uint32_t fun_00608c70(Memory&m,const Inputs&i){return m.r32(m.r32(m.r32(i.cx+4)+i.arg[0]*4));}
std::uint32_t fun_00609110(Memory&m,const Inputs&i){auto c=s32(m.r32(i.cx+0x10));if(c<=0)return 0;auto a=m.r32(i.cx+4);for(std::int32_t n=0;n<c;++n){auto p=m.r32(a+std::uint32_t(n)*4);if(m.r8(p+0xc))return m.r32(p);}return 0;}
std::uint32_t fun_00609b80(Memory&m,const Inputs&i){m.w8(i.arg[0]+0xc,0);auto v=m.r32(i.cx+0xa8)-1;m.w32(i.cx+0xa8,v);if(!v)m.w32(i.cx+0xb0,0xffffffffu);return v;}
std::uint32_t fun_0060a730(Memory&m,const Inputs&i){auto flag=i.arg[0]&0xffu;m.w32(i.cx+0xb4,0xffffffffu);if(!flag)return flag;auto count=s32(m.r32(i.cx+0x30));if(count<=0){m.w32(i.cx+0xac,0xffffffffu);return 0;}for(std::int32_t n=0;n<count;++n){auto arr=m.r32(i.cx+0x24);auto p=m.r32(arr+std::uint32_t(n)*4);m.w32(p+0x74,0xffffffffu);}m.w32(i.cx+0xac,0xffffffffu);return std::uint32_t(count);}
std::uint32_t fun_0060aef0(Memory&m,const Inputs&i){if(s32(m.r32(i.cx+0x14))<=0)return 0;auto v=m.r32(i.cx+0x8c);return (v==0xffffffffu||s32(v)>0)?1u:0u;}
std::uint32_t fun_00619cf0(Memory&m,const Inputs&i){m.w32(i.cx,i.arg[0]);m.w32(i.cx+4,i.arg[1]);m.w32(i.cx+8,i.arg[2]);m.w32(i.cx+12,i.arg[3]);return i.cx;}
std::uint32_t fun_00619d10(Memory&m,const Inputs&i){m.w32(i.cx,i.arg[0]);m.w32(i.cx+4,i.arg[1]);m.w32(i.cx+8,i.arg[2]);m.w32(i.cx+12,i.arg[3]);return i.arg[2];}
std::uint32_t fun_00621b70(Memory&m,const Inputs&i){auto v=m.r32(i.cx);auto r=(v>>31)+v*2+i.dx;m.w32(i.cx,r);return r;}
std::uint32_t fun_00626070(Memory&m,const Inputs&i){auto v=m.r32(i.cx);if(!v)return 0;auto q=(m.r32(i.cx+4)+1)&0x7f;m.w32(i.cx+4,q);--v;m.w32(i.cx,v);return v;}
std::uint32_t fun_00629f50(Memory&m,const Inputs&i){auto n=m.r32(i.arg[0]+0xc78);return i.cx+n*24+0x1274;}
std::uint32_t fun_0062cd00(Memory&m,const Inputs&i){auto s=i.arg[0],d=i.cx+0x28;auto a=m.r32(s);m.w32(d,a);auto b=m.r32(s+4);m.w32(d+4,b);auto c=m.r32(s+8);m.w32(d+8,c);return c;}
std::uint32_t fun_0062e3d0(Memory&m,const Inputs&i){auto k=i.arg[0];if(!k)return 0;auto c=s32(m.r32(i.cx+0xd0));if(c<=0)return 0;auto a=m.r32(i.cx+0xcc);for(std::int32_t n=0;n<c;++n)if(m.r32(a+std::uint32_t(n)*4)==k)return 1;return 0;}
std::uint32_t fun_0062e410(Memory&m,const Inputs&i){auto k=i.arg[0];if(!k)return 0xffffffffu;auto c=s32(m.r32(i.cx+0xd0));if(c<=0)return 0xffffffffu;auto a=m.r32(i.cx+0xcc);for(std::int32_t n=0;n<c;++n)if(m.r32(a+std::uint32_t(n)*4)==k)return std::uint32_t(n);return 0xffffffffu;}
std::uint32_t fun_0062e440(Memory&m,const Inputs&i){auto c=s32(m.r32(i.cx+0xd0));if(c>0){auto a=m.r32(i.cx+0xcc);for(std::int32_t n=0;n<c;++n)if(!m.r32(a+std::uint32_t(n)*4))return (std::uint32_t(n)&0xffffff00u)|1u;return std::uint32_t(c)&0xffffff00u;}return 0;}
std::uint32_t fun_0062e470(Memory&m,const Inputs&i){auto c=s32(m.r32(i.cx+0xd0));if(c<=0)return 0;auto a=m.r32(i.cx+0xcc),k=i.arg[0];for(std::int32_t n=0;n<c;++n){auto v=m.r32(a+std::uint32_t(n)*4);if(!v||v==k)return (std::uint32_t(n)&0xffffff00u)|1u;}return std::uint32_t(c)&0xffffff00u;}
std::uint32_t fun_0062e4b0(Memory&m,const Inputs&i){auto c=s32(m.r32(i.cx+0xd0));if(c>0){auto a=m.r32(i.cx+0xcc);for(std::int32_t n=0;n<c;++n)if(m.r32(a+std::uint32_t(n)*4))return (std::uint32_t(n)&0xffffff00u)|1u;return std::uint32_t(c)&0xffffff00u;}return 0;}
std::uint32_t fun_0062eb20(Memory&m,const Inputs&i){auto p=i.arg[0];auto v=m.r32(p);m.w32(i.cx+0x40,v);return p;}
std::uint32_t fun_0062fef0(Memory&m,const Inputs&i){m.w32(i.cx,i.arg[0]);m.w32(i.cx+4,i.arg[1]);return i.cx;}
std::uint32_t fun_00630a70(Memory&m,const Inputs&i){return m.r32(i.cx+0x10)!=0xffffffffu?1u:0u;}
std::uint32_t fun_006504e0(Memory&m,const Inputs&i){auto a=m.r32(i.arg[0]);m.w32(i.cx+0x3d8,a);auto b=m.r32(i.arg[0]+4);m.w32(i.cx+0x3dc,b);return b;}
std::uint32_t fun_00658360(Memory&m,const Inputs&i){auto n=s32(i.arg[0]);if(n<0||n>=50)return 0;auto off=std::uint32_t(n)*41+0x1238;auto b=m.r8(i.cx+off);m.w8(i.arg[1],b);return 1;}
std::uint32_t fun_00658600(Memory&m,const Inputs&i){auto n=s32(i.arg[0]);if(n<0||n>=50)return 0;auto off=std::uint32_t(n)*41+0x1a3a;auto b=m.r8(i.cx+off);m.w8(i.arg[1],b);return 1;}
std::uint32_t fun_0065a120(Memory&m,const Inputs&i){auto v=m.r32(i.cx+0x214)+1;m.w32(i.cx+0x214,v);return v;}
std::uint32_t fun_0065f8c0(Memory&m,const Inputs&i){m.w32(i.cx+0x2c,i.arg[0]);return 1;}
std::uint32_t fun_00664e90(Memory&m,const Inputs&i){return m.r32(i.cx+0x55)==0xfffffffeu?0xfffffffeu:m.r32(i.cx+0x51);}
std::uint32_t fun_00664ef0(Memory&m,const Inputs&i){auto v=i.arg[0];if(v==0xfffffffeu){m.w32(i.cx+0x51,0xffffffffu);m.w32(i.cx+0x55,v);}else{m.w32(i.cx+0x51,v);m.w32(i.cx+0x55,0xffffffffu);}return v;}
std::uint32_t fun_00668a80(Memory&m,const Inputs&i){m.w32(i.cx+0x24,0);for(unsigned n=0;n<8;++n){auto p=i.cx+0x6c+n*4;m.w32(p-0x20,0xffffffffu);m.w32(p,0xffffffffu);}return i.cx+0x8c;}
std::uint32_t fun_00668c60(Memory&m,const Inputs&i){return m.r32(i.cx+0x128)==0xfffffffeu?0xfffffffeu:m.r32(i.cx+0x124);}
std::uint32_t fun_00668c80(Memory&m,const Inputs&i){return m.r32(i.cx+0x120)==0xfffffffeu?0xfffffffeu:m.r32(i.cx+0x11c);}
std::uint32_t fun_0066ac50(Memory&m,const Inputs&i){if(m.r32(i.cx+0x38))return 0;auto a=i.arg[0],b=i.arg[1];m.w32(i.cx+0x38,a);m.w32(i.cx+0x3c,a+b);m.w8(i.cx+0x34,i.arg[2]);return 1;}
std::uint32_t fun_0066ac80(Memory&m,const Inputs&i){if(!m.r32(i.cx+0x38))return 0;m.w8(i.cx+0x34,0);m.w32(i.cx+0x3c,0);m.w32(i.cx+0x38,0);return 1;}
std::uint32_t fun_0066aca0(Memory&m,const Inputs&i){auto active=m.r8(i.cx+0x1e);auto ptr=m.r32(i.cx+0x38);if(active&&ptr){m.w8(i.cx+0x34,0);m.w32(i.cx+0x3c,0);m.w32(i.cx+0x38,0);return 1;}if(active)return 0;auto c=m.r32(i.cx+0x3c);if(!c)return 0;--c;m.w32(i.cx+0x3c,c);if(c)return 0;auto f=m.r8(i.cx+0x34)==0;m.w8(i.cx+0x34,f);m.w32(i.cx+0x3c,m.r32(i.cx+0x38));return 1;}
std::uint32_t fun_00677070(Memory&,const Inputs&i){switch(i.cx){case 0x10:return 2;case 0x28:case 3:return 3;case 7:return i.dx==5?1u:0u;default:return 0xffffffffu;}}
std::uint32_t fun_0067fb90(Memory&m,const Inputs&i){auto v=i.arg[0];if(v!=m.r32(i.cx+0x68))m.w32(i.cx+0x6c,v);return v;}
std::uint32_t fun_0067fd80(Memory&m,const Inputs&i){auto c=s32(m.r32(i.cx+0x48));if(c<=0)return 0;auto a=m.r32(i.cx+0x3c);std::uint32_t found=0;for(std::int32_t n=0;n<c;++n){auto p=m.r32(a+std::uint32_t(n)*4);if(m.r32(p+4)==1)++found;}return found;}
std::uint32_t fun_006907a0(Memory&m,const Inputs&i){auto v=((i.arg[0]&0xff)<<16)|((i.arg[1]&0xff)<<8)|(i.arg[2]&0xff);m.w32(i.cx+8,v);return v;}
std::uint32_t fun_00692ec0(Memory&m,const Inputs&i){auto a=m.r8(i.cx+0x58);if(a)return 0;auto p=m.r32(i.cx+0x24);if(m.r8(p+0xdd)){auto v=m.r32(i.cx+0x60);return v?1u:0u;}return m.r8(i.cx+0x57);}
std::uint32_t fun_00693ff0(Memory&m,const Inputs&i){auto p=m.r32(i.cx+0x24);if(m.r8(p+0xdd))return 1;return m.r8(i.cx+0x57)==0?1u:0u;}
std::uint32_t fun_00697700(Memory&m,const Inputs&i){auto ret=i.cx;for(unsigned n=0;n<6;++n)m.w32(i.cx+n*4,0);m.w8(i.cx+0x18,0);return ret;}
std::uint32_t fun_0069fbe0(Memory&m,const Inputs&i){auto old=m.r32(i.cx+0xd90);if(old)return old;old=m.r32(i.cx+0xd94);if(old)return old;auto p=i.arg[0];auto a=m.r32(p);m.w32(i.cx+0xd90,a);auto b=m.r32(p+4);m.w32(i.cx+0xd94,b);auto c=m.r32(p);m.w32(i.cx+0xd98,c);auto d=m.r32(p+4);m.w32(i.cx+0xd9c,d);return d;}
std::uint32_t fun_0069fc20(Memory&m,const Inputs&i){if(!m.r32(i.cx+0xd90)&&!m.r32(i.cx+0xd94))return 0;auto p=i.arg[0];auto a=m.r32(p);m.w32(i.cx+0xd98,a);auto b=m.r32(p+4);m.w32(i.cx+0xd9c,b);return b;}
std::uint32_t fun_0069fdb0(Memory&m,const Inputs&i){m.w32(i.cx+0xd90,0);m.w32(i.cx+0xd98,0);m.w32(i.cx+0xd94,0);m.w32(i.cx+0xd9c,0);return 0;}
}
