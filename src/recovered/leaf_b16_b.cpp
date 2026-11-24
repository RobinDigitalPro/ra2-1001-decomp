#include "leaf_b16_b.hpp"
namespace ra2::recovered::leaf {
std::uint32_t fun_0075a030(Memory&m,const Inputs&i){auto p=m.r32(i.cx);return p?p:0x8248a4u;}
std::uint32_t fun_00406620(Memory&m,const Inputs&i){m.w32(i.cx+0x60,i.dx);m.w32(i.cx+0x64,i.arg[0]);return i.arg[0];}
std::uint32_t fun_00431310(Memory&m,const Inputs&i){auto old=m.r8(i.cx+0x41);m.w8(i.cx+0x41,i.arg[0]);return old;}
std::uint32_t fun_005ca430(Memory&m,const Inputs&i){auto p=m.r32(i.cx+0xc);m.w8(p,0);m.w32(i.cx+0x14,0);return p;}
std::uint32_t fun_00724f50(Memory&m,const Inputs&i){auto p=m.r32(i.cx+4);auto v=m.r32(i.cx+8);return v<m.r32(p+0x10)?1u:0u;}
std::uint32_t fun_004312f0(Memory&m,const Inputs&i){auto old=m.r16(i.cx+0x24);m.w16(i.cx+0x24,i.arg[0]);return old;}
std::uint32_t fun_0062e3c0(Memory&m,const Inputs&i){auto p=m.r32(i.cx+0xcc);return m.r32(p+i.arg[0]*4u);}
std::uint32_t fun_00686bd0(Memory&m,const Inputs&i){m.w32(i.cx+4,0);m.w32(i.cx,0x796888);return i.cx;}
std::uint32_t fun_006874d0(Memory&m,const Inputs&i){m.w32(i.cx+4,0);m.w32(i.cx,0x796918);return i.cx;}
std::uint32_t fun_00687dd0(Memory&m,const Inputs&i){m.w32(i.cx+4,0);m.w32(i.cx,0x7969a8);return i.cx;}
std::uint32_t fun_006886d0(Memory&m,const Inputs&i){m.w32(i.cx+4,0);m.w32(i.cx,0x796a38);return i.cx;}
std::uint32_t fun_00688fd0(Memory&m,const Inputs&i){m.w32(i.cx+4,0);m.w32(i.cx,0x796ac8);return i.cx;}
std::uint32_t fun_006898d0(Memory&m,const Inputs&i){m.w32(i.cx+4,0);m.w32(i.cx,0x796b58);return i.cx;}
std::uint32_t fun_0068a1d0(Memory&m,const Inputs&i){m.w32(i.cx+4,0);m.w32(i.cx,0x796be8);return i.cx;}
std::uint32_t fun_0068aad0(Memory&m,const Inputs&i){m.w32(i.cx+4,0);m.w32(i.cx,0x796c78);return i.cx;}
std::uint32_t fun_0068b0d0(Memory&m,const Inputs&i){m.w32(i.cx+4,0);m.w32(i.cx,0x796cd8);return i.cx;}
std::uint32_t fun_0068b6d0(Memory&m,const Inputs&i){m.w32(i.cx+4,0);m.w32(i.cx,0x796d38);return i.cx;}
std::uint32_t fun_0068b9d0(Memory&m,const Inputs&i){m.w32(i.cx+4,0);m.w32(i.cx,0x796d68);return i.cx;}
std::uint32_t fun_0068bfd0(Memory&m,const Inputs&i){m.w32(i.cx+4,0);m.w32(i.cx,0x796dc8);return i.cx;}
std::uint32_t fun_004cf240(Memory&m,const Inputs&i){m.w32(i.cx+0xc,i.arg[0]);m.w32(i.cx+0x10,i.arg[1]);return i.arg[0];}
std::uint32_t fun_005f8d70(Memory&m,const Inputs&i){m.w32(i.cx+4,0);m.w8(i.cx+8,0);m.w32(i.cx,0x792b00);return i.cx;}
std::uint32_t fun_0062cd50(Memory&m,const Inputs&i){m.w32(i.cx+0x40,i.arg[0]);m.w32(i.cx+0x44,i.arg[1]);return i.arg[0];}
std::uint32_t fun_0051a410(Memory&m,const Inputs&i){m.w32(i.cx+4,i.arg[0]);m.w32(i.cx,0x78ec6c);return i.cx;}
std::uint32_t fun_0051a860(Memory&m,const Inputs&i){m.w32(i.cx+4,i.arg[0]);m.w32(i.cx,0x78f43c);return i.cx;}
std::uint32_t fun_0051aa40(Memory&m,const Inputs&i){m.w32(i.cx+4,i.arg[0]);m.w32(i.cx,0x78f48c);return i.cx;}
std::uint32_t fun_0065a130(Memory&m,const Inputs&i){auto p=m.r32(i.cx+i.arg[1]*4u+0x632);m.w32(i.arg[0],p);return i.arg[0];}
std::uint32_t fun_006a7960(Memory&m,const Inputs&i){auto p=i.arg[0];if(p)m.w32(p+0x5550,m.r32(i.cx+0x74));return (p&0xffffff00u)|1u;}
std::uint32_t fun_006a79a0(Memory&m,const Inputs&i){auto p=i.arg[0];if(p)m.w32(p+0x5558,m.r32(i.cx+0x74));return (p&0xffffff00u)|1u;}
std::uint32_t fun_006d4b50(Memory&m,const Inputs&i){return i.cx+0x8f4u+i.arg[0]*28u;}
std::uint32_t fun_00650560(Memory&m,const Inputs&i){auto a=m.r32(i.arg[0]);m.w32(i.cx+0x3e8,a);auto b=m.r32(i.arg[0]+4);m.w32(i.cx+0x3ec,b);return b;}
std::uint32_t fun_0076f78c(Memory&m,const Inputs&i){auto p=i.arg[0];auto v=m.r32(p);auto h=m.r32(v-4);auto out=p-m.r32(h+4);auto d=m.r32(h+8);if(d)out+=m.r32(p-d);return out;}
std::uint32_t fun_00617fa0(Memory&m,const Inputs&i){auto n=sx16(m.r16(i.cx+6));auto index=i.arg[0];if(index>=n)return 0;return i.cx+index*24u+8u;}
std::uint32_t fun_0077ba20(Memory&m,const Inputs&i){auto src=i.arg[1],delta=i.arg[0]-i.arg[1];for(unsigned k=0;k<3;++k){auto v=m.r32(src);m.w32(delta+src,v);src+=4;}return src;}
std::uint32_t fun_0040ff90(Memory&m,const Inputs&i){m.w32(i.cx,0x785dd8);m.w32(i.cx+4,0x785dbc);m.w32(i.cx+8,0x785db4);m.w32(i.cx+0xc,0x785dac);return 0;}
std::uint32_t fun_00590ed0(Memory&m,const Inputs&i){auto v=(i.arg[1]&0xffff0000u)|((m.r16(i.cx)-m.r16(i.arg[1]))&0xffffu);m.w32(i.arg[0],v);return i.arg[0];}
std::uint32_t fun_0067fd30(Memory&m,const Inputs&i){auto n=m.r32(i.cx+0x48);if(s32(n)<=0)return 0;auto p=m.r32(i.cx+0x3c);std::uint32_t count=0;for(std::uint32_t k=0;k<n;++k){auto item=m.r32(p+k*4u);if(m.r32(item+4)!=7)++count;}return count;}
std::uint32_t fun_00545540(Memory&m,const Inputs&i){auto cell=i.arg[0];auto y=s32(sx16(m.r16(cell+2)));auto x=s32(sx16(m.r16(cell)));auto index=(static_cast<std::uint32_t>(y)<<9)+static_cast<std::uint32_t>(x);auto map=m.r32(i.cx+0x138);auto val=m.r32(map+index*4u);return (sx16(m.r16(cell))&0xffffff00u)|(val!=0);}
std::uint32_t fun_0077b5f0(Memory&m,const Inputs&i){auto p=i.arg[0];std::uint32_t n=0;for(;;){auto c=m.r8(p);if(c>=0x41&&c<=0x5a){++n;++p;continue;}if(c>=0x61&&c<=0x7a){++n;++p;continue;}return n;}}
std::uint32_t fun_0058aa70(Memory&m,const Inputs&i){m.w32(i.cx+4,0);m.w32(i.cx+8,0);m.w8(i.cx+0xc,1);m.w8(i.cx+0xd,0);m.w32(i.cx+0x14,10);m.w32(i.cx+0x10,0);m.w32(i.cx,0x790e2c);return i.cx;}
std::uint32_t fun_00649bf0(Memory&m,const Inputs&i){m.w32(i.cx+4,0);m.w32(i.cx+8,0);m.w8(i.cx+0xc,1);m.w8(i.cx+0xd,0);m.w32(i.cx+0x14,10);m.w32(i.cx+0x10,0);m.w32(i.cx,0x78eb3c);return i.cx;}
std::uint32_t fun_00649cf0(Memory&m,const Inputs&i){m.w32(i.cx+4,0);m.w32(i.cx+8,0);m.w8(i.cx+0xc,1);m.w8(i.cx+0xd,0);m.w32(i.cx+0x14,10);m.w32(i.cx+0x10,0);m.w32(i.cx,0x793f80);return i.cx;}
std::uint32_t fun_00649f30(Memory&m,const Inputs&i){m.w32(i.cx+4,0);m.w32(i.cx+8,0);m.w8(i.cx+0xc,1);m.w8(i.cx+0xd,0);m.w32(i.cx+0x14,10);m.w32(i.cx+0x10,0);m.w32(i.cx,0x78e0f8);return i.cx;}
std::uint32_t fun_006d4d30(Memory&m,const Inputs&i){m.w32(i.cx+4,0);m.w32(i.cx+8,0);m.w8(i.cx+0xc,1);m.w8(i.cx+0xd,0);m.w32(i.cx+0x14,10);m.w32(i.cx+0x10,0);m.w32(i.cx,0x797fec);return i.cx;}
std::uint32_t fun_0067fd50(Memory&m,const Inputs&i){auto n=m.r32(i.cx+0x48);if(s32(n)<=0)return 0;auto p=m.r32(i.cx+0x3c);std::uint32_t count=0;for(std::uint32_t k=0;k<n;++k){auto item=m.r32(p+k*4u);auto v=m.r32(item+4);if(v==0||v==6)++count;}return count;}
std::uint32_t fun_00480620(Memory&m,const Inputs&i){for(unsigned k=0;k<5;++k)m.w32(i.cx+0x44+k*4u,i.arg[k]);return i.arg[4];}
std::uint32_t fun_0076f406(Memory&m,const Inputs&i){auto p=i.arg[0];for(;;){auto c=m.r16(p);if(c==0||c==(i.arg[1]&0xffffu))return c==(i.arg[1]&0xffffu)?p:0u;p+=2;}}
std::uint32_t fun_0058ce60(Memory&m,const Inputs&i){for(unsigned k=0;k<12;++k)m.w32(i.cx+k*4u,(k==0||k==5||k==10)?0x3f800000u:0u);return 0;}
std::uint32_t fun_00690760(Memory&m,const Inputs&i){m.w32(i.cx,0);m.w32(i.cx+4,0x4b0);m.w32(i.cx+8,0xffffff);m.w32(i.cx+0xc,0xf);m.w32(i.cx+0x10,2);m.w32(i.cx+0x14,0);return i.cx;}
std::uint32_t fun_005929c0(Memory&m,const Inputs&i){auto node=i.cx;if(!node)return 0;auto prev=m.r32(node+4);if(!prev)return 0;auto next=m.r32(node+8);if(!next)return 0;m.w32(next+4,prev);prev=m.r32(node+4);next=m.r32(node+8);m.w32(prev+8,next);m.w32(node+8,0);m.w32(node+4,0);return prev;}
std::uint32_t fun_00778d91(Memory&m,const Inputs&i){auto v=i.arg[0]&0xffu;if(v&0x20)return 5;if(v&8)return 1;if(v&4)return 2;if(v&1)return 3;return (v&2u)<<1;}
}
