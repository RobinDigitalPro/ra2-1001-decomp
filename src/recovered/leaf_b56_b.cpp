#include "leaf_b56_b.hpp"
#include <array>
#include <cstdint>
namespace ra2::recovered::leaf {
namespace {
inline std::uint32_t neg(std::uint32_t a){return 0u-a;}
inline std::uint32_t mul(std::uint32_t a,std::uint32_t b){return a*b;}
inline std::uint32_t trunc_half(std::uint32_t x){return sar(x+((x>>31)&1u),1);}
inline std::uint32_t round8(std::uint32_t x){return sar(x+((x>>31)?0xffu:0u),8);}
}
std::uint32_t fun_005e08d0(Memory&,const Inputs& i){
 constexpr std::array<std::uint32_t,29> v{{0x94,0xd8,0xf5,0xe2,0xd5,0x101,0x129,0xd7,0xbb,0x100,0xd6,0x125,0x122,0x112,0xe7,0x116,0x11d,0x11c,0xfe,0x10f,0x117,0x114,0xe6,0xf3,0xf4,0x2bc,0x10e,0xbc6,0xbc7}};
 for(auto x:v)if(i.cx==x)return 1;return 0;
}
std::uint32_t fun_00575b70(Memory& m,const Inputs& i){
 constexpr std::array<std::uint32_t,15> off{{0x40,0x3c,0x48,0x44,0x4c,0x50,0x54,0x58,0x5c,0x60,0x64,0x68,0x6c,0x70,0x74}};
 constexpr std::array<std::uint32_t,15> lo{{0,0,0,0,0,2,1,0,0,0,0,0,0,0,0}};
 constexpr std::array<std::uint32_t,15> hi{{3,4,3,100,100,8,100,100,100,100,3,3,100,100,0xffff}};
 std::uint32_t eax=0;for(unsigned n=0;n<off.size();++n){auto a=i.cx+off[n],x=m.r32(a);eax=x;if(s32(x)<s32(lo[n]))m.w32(a,lo[n]);else if(s32(x)>s32(hi[n]))m.w32(a,hi[n]);}return eax;
}
std::uint32_t fun_00403920(Memory& m,const Inputs& i){
 const auto c=i.cx,low=i.arg[0],high=i.arg[1];
 const std::uint64_t newv=(std::uint64_t(high)<<32)|low, old=(std::uint64_t(m.r32(c+0x2c))<<32)|m.r32(c+0x28);
 const auto delta=static_cast<std::uint64_t>(newv-old);m.w32(c+0x10,static_cast<std::uint32_t>(delta));m.w32(c+0x14,static_cast<std::uint32_t>(delta>>32));m.w32(c+0x48,m.r32(c+0x48)+1);
 auto upper=(std::uint64_t(m.r32(c+0x24))<<32)|m.r32(c+0x20);auto start=(std::uint64_t(m.r32(c+0x1c))<<32)|m.r32(c+0x18);
 if(start>upper){m.w32(c+0x18,0);m.w32(c+0x1c,0);}
 start=(std::uint64_t(m.r32(c+0x1c))<<32)|m.r32(c+0x18);
 if(delta>start){m.w32(c+0x18,static_cast<std::uint32_t>(delta));m.w32(c+0x1c,static_cast<std::uint32_t>(delta>>32));}
 auto mark=(std::uint64_t(m.r32(c+0xc))<<32)|m.r32(c+8);if(delta>mark)m.w32(c+0x4c,m.r32(c+0x4c)+1);
 auto end=(std::uint64_t(m.r32(c+0x34))<<32)|m.r32(c+0x30);if(delta>end){m.w32(c+0x30,static_cast<std::uint32_t>(delta));m.w32(c+0x34,static_cast<std::uint32_t>(delta>>32));}
 m.w32(c+0x28,low);m.w32(c+0x2c,high);return static_cast<std::uint32_t>(delta>>32);
}
std::uint32_t fun_00606810(Memory& m,const Inputs& i){const auto c=i.cx;auto x=m.r32(c+0x10)+m.r32(c+0x14)*i.arg[0];m.w32(c+0x10,x);if(s32(x)>0x2000){x=0x2000;m.w32(c+0x10,x);}auto f=x&0xfff;if(m.r8(c+0x11)&0x10)f=0x1000-f;const auto g=0x1000-f;
 auto a=m.r32(c+0x24)*g+m.r32(c+0x18)*f;m.w32(c+4,sar(a,12));a=m.r32(c+0x1c)*f+m.r32(c+0x28)*g;m.w32(c+8,sar(a,12));a=m.r32(c+0x2c)*g+m.r32(c+0x20)*f;m.w32(c+0xc,sar(a,12));return f;}
std::uint32_t fun_00634310(Memory& m,const Inputs& i){const auto d=i.cx,s=i.arg[1],w=i.arg[0]&255u;std::uint32_t eax=0;for(unsigned k=0;k<3;++k){auto dst=m.r8(d+k);auto src=m.r8(s+k);auto prod=(src-dst)*w;auto q=sar(prod+((prod>>31)?255u:0u),8);eax=(q&0xffffff00u)|((dst+q)&255u);m.w8(d+k,eax);}return eax;}
std::uint32_t fun_00697eb0(Memory& m,const Inputs& i){const auto in=i.arg[1],out=i.arg[0];const auto x=m.r32(in),y=m.r32(in+4);
 auto a=mul(x,15u);a=mul(a,4);a=trunc_half(a);auto b=mul(x,15u);b=mul(b,2);b=trunc_half(b);auto c=neg(mul(y,15u));c=mul(c,4);c=trunc_half(c);a+=c;
 auto d=mul(y,15u);d=mul(d,2);d=trunc_half(d);b+=d;m.w32(out,round8(a));m.w32(out+4,round8(b));return out;}
std::uint32_t fun_0069bf60(Memory& m,const Inputs& i){const auto x=i.arg[0],y=i.arg[1],p=i.arg[2],q=i.arg[3];
 auto a=trunc_half(mul(x,15u*4u));m.w32(p,a);auto b=trunc_half(mul(x,15u*2u));m.w32(q,b);
 auto cx=trunc_half(mul(neg(mul(y,15u)),4u));m.w32(p,m.r32(p)+cx);auto dy=trunc_half(mul(y,15u*2u));m.w32(q,m.r32(q)+dy);m.w32(p,round8(m.r32(p)));m.w32(q,round8(m.r32(q)));m.w32(p,m.r32(p)+0x3c00u);return m.r32(p);}
inline std::uint32_t mulhi_u(std::uint32_t a,std::uint32_t b){return static_cast<std::uint32_t>((std::uint64_t(a)*b)>>32);}
inline std::uint32_t imulhi(std::uint32_t a,std::uint32_t b){return static_cast<std::uint32_t>((std::int64_t(s32(a))*s32(b))>>32);}
std::uint32_t fun_004fe550(Memory& m,const Inputs& i){
 const auto src=i.cx,out=i.arg[0];const std::uint32_t r=m.r8(src),g=m.r8(src+1),b=m.r8(src+2),magic=0x80808081u;
 const std::uint32_t ecx=r*6u;const std::uint32_t rem=ecx%255u;
 std::uint32_t edx=mulhi_u(magic,rem*g)>>7;
 std::uint32_t edi=(255u-edx)*b;edx=mulhi_u(magic,edi);
 edi=(255u-g)*b;edx>>=7;const std::uint32_t t20=edx;
 edx=imulhi(magic,edi)+edi;edx=sar(edx,7);if(edx>>31)++edx;const std::uint32_t t24=edx,t28=edx;
 edx=mulhi_u(magic,(255u-rem)*g)>>7;edi=(255u-edx)*b;const std::uint32_t t2c=mulhi_u(magic,edi)>>7;
 std::uint32_t idx=imulhi(magic,ecx);idx=sar(idx+ecx,7);if(idx>>31)++idx;
 auto remap=[](std::uint32_t n){return n+(n>4?0xfffffffcu:2u);};
 std::array<std::uint32_t,7> slots{{0,b,b,t20,t24,t28,t2c}};
 const auto idx1=remap(idx),first=slots[idx1],idx2=remap(idx1),third=slots[idx2],idx3=remap(idx2),second=slots[idx3];
 m.w8(out,first);m.w8(out+1,second);m.w8(out+2,third);return out;
}
}


