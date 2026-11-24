#include "recovered/recovery_b1075.hpp"
#include "recovered/recovery_b1063.hpp"
#include "recovered/recovery_b1070.hpp"
#include "recovered/global_b60_c.hpp"
#include <stdexcept>
namespace ra2::recovered::b1075 {
namespace {
void need(bool b){if(!b)throw std::domain_error("1075 outside positive two-byte owned constructors with coherent warm cache");}
}
unsigned fun_00483430(Memory&m,const Inputs&i,Heap&h){
 const auto p=i.cx,surface=i.arg[2],n=i.arg[3];need(n==27u||n==53u);need((i.arg[4]&255u)!=0u||n==53u);need(i.arg[0]==0xa55948u&&i.arg[1]==0x820150u&&m.r32(surface)==0x78bbe4u&&m.r32(0x78bc54u)==0x4aa970u&&m.r32(surface+0x10u)==2u);
 m.w32(p+4u,m.r32(surface+0x10u));for(unsigned off=8u;off<=0x168u;off+=4u)m.w32(p+off,0u);m.w32(p+0x16cu,n);for(unsigned off=0x170u;off<=0x17cu;off+=4u)m.w32(p+off,0u);m.w32(p,0x788f70u);
 const auto output=h.allocate(n*512u);need(output!=0u);m.w32(p+0x170u,output);m.w32(p+0x174u,output+(n-1u)/2u*512u);
 if((i.arg[4]&255u)==0u){leaf::Memory span(reinterpret_cast<unsigned char*>(std::uintptr_t(output)),output,n*512u);Memory view=m;view.add(span);Inputs q{};q.cx=output;q.dx=n;q.arg[0]=i.arg[0];global_b26::fun_004ab710(view,q);}
 m.w32(p+0x180u,m.r16(0x83b300u));m.w32(p+0x184u,m.r16(0x83b302u));
 if((i.arg[4]&255u)==0u){Inputs q{};q.cx=p;b1063::fun_004838e0(m,q,h);}
 const auto count=m.r32(0x839490u),capacity=m.r32(0x839488u),data=m.r32(0x839484u);need(count>=1u&&count<=3u&&capacity==10u&&data!=0u);m.w32(0x839490u,count+1u);h.w32(data+count*4u,p);return p;
}
unsigned fun_00536a40(Memory&m,const Inputs&i,Heap&h,State&fp){
 need((i.arg[6]&255u)!=0u&&i.arg[7]==0u&&m.r32(0x81a6e8u)>=1u&&m.r32(0x81a6e8u)<=3u);need(m.r8(0xa39574u)==0u&&m.r32(0xa3957cu)==0u);const auto p=i.cx;Inputs base{};base.cx=p;base.arg[0]=i.arg[0];base.arg[1]=i.arg[1];base.arg[2]=i.arg[2];base.arg[3]=i.arg[8];base.arg[4]=1u;fun_00483430(m,base,h);
 m.w32(p+0x188u,i.arg[0]);m.w32(p+0x18cu,i.arg[1]);m.w32(p+0x190u,0x7ca3a0u);m.w32(p+0x194u,0u);for(unsigned k=0;k<3u;++k){need(i.arg[3u+k]>=64u&&i.arg[3u+k]<=960u&&i.arg[3u+k]%64u==0u);m.w32(p+0x198u+4u*k,i.arg[3u+k]);m.w32(p+0x1a4u+4u*k,i.arg[3u+k]);}m.w8(p+0x1b0u,0u);m.w32(p,0x7905bcu);
 need(m.r32(0x7c13c0u)==0xffffffffu);if(m.r32(0x7ca4a0u)==0xffffffffu)m.w32(0x7ca4a0u,m.r32(0x7c13c0u));
 const auto output=m.r32(p+0x170u);leaf::Memory span(reinterpret_cast<unsigned char*>(std::uintptr_t(output)),output,i.arg[8]*512u);Memory view=m;view.add(span);b1070::Inputs color{};color.cx=p;color.arg[0]=i.arg[3];color.arg[1]=i.arg[4];color.arg[2]=i.arg[5];color.arg[3]=0u;color.fp.image=fp.image;b1070::fun_00536c80(view,color);fp.image=color.fp.image;return p;
}
unsigned run(Memory&m,const Inputs&i,Heap&h,State&fp,unsigned root){if(root==0x83430u)return fun_00483430(m,i,h);if(root==0x136a40u)return fun_00536a40(m,i,h,fp);throw std::domain_error("1075 exact two roots");}
}
