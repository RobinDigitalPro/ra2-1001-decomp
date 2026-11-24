#include "recovered/recovery_b1055.hpp"
#include <stdexcept>
#include <initializer_list>
namespace ra2::recovered::b1055{
static void need(bool v){if(!v)throw std::domain_error("1055 outside bounded positive cleanup");}
unsigned fun_00665630(Memory&m,const Inputs&i,Heap&h){const auto p=i.cx;unsigned result=0u;
 for(unsigned off:{0x28b8u,0x28d0u}){auto n=m.r32(p+off+16u);need(n>=1u&&n<=4u);const auto a=m.r32(p+off+4u);while(n){result=h.release(h.r32(a));--n;m.w32(p+off+16u,n);for(unsigned k=1u;k<=n;++k)h.w32(a+4u*(k-1u),h.r32(a+4u*k));}}
 const auto clear=[&](unsigned off,unsigned tag){m.w32(p+off,tag);const auto a=m.r32(p+off+4u);need(a&&m.r8(p+off+13u)==1u);result=h.release(a);m.w32(p+off+4u,0u);m.w8(p+off+13u,0u);m.w32(p+off+8u,0u);};
 clear(0x28d0u,0x790714u);clear(0x28b8u,0x78957cu);clear(0x28a0u,0x7944acu);for(unsigned off:{0x27e0u,0x27c8u,0x27b0u})clear(off,0x791858u);
 const auto f=p+0x22fcu;need(m.r8(f+0x5cu)==1u&&m.r32(f+0x54u)!=0u&&m.r32(f+0x2cu)==0u&&m.r32(f+0x10u)==0xffffffffu&&m.r32(f+0x14u)==0u&&m.r8(f+0x1cu)==0u);
 m.w32(f,0x7856a0u);m.w32(f+0x60u,0u);result=h.release(m.r32(f+0x54u));m.w32(f+0x54u,0u);m.w32(f+0x58u,0u);m.w8(f+0x5cu,0u);
 m.w32(f,0x785658u);m.w32(f,0x78773cu);m.w32(f+0x30u,0u);for(unsigned off:{0x21u,0x23u,0x24u,0x25u})m.w8(f+off,0u);
 // Actual630060 installs793C84, invokes genuine793C9C IsOpen630A70,
 // sees constructor handleFFFFFFFF and performs no OS handle operation.
 m.w32(f,0x793c84u);m.w32(f,0x793c3cu);
 const auto q=p+0x9d8u;need(m.r32(q)==0u&&m.r8(q+0x19u)==0u&&m.r32(q+0x24u)==0u);m.w32(q+0x2c4u,0x278u);
 for(unsigned k=0;k<7u;++k)m.w32(q+0x1480u+4u*k,0x00010001u);
 for(unsigned off:{0u,4u,8u,12u,16u,0x1cu,0x20u,0x24u,0x2b0u,0x2b4u})m.w32(q+off,0u);
 m.w32(q+0x14u,0x13u);for(unsigned off:{0x18u,0x19u,0x1au})m.w8(q+off,0u);for(unsigned off:{0x28u,0x16cu,0x2b8u})m.w16(q+off,0u);m.w32(q+0x2bcu,0xfffffffeu);m.w32(q+0x2c0u,0xffffffffu);
 clear(0x8a0u,0x79448cu);clear(0x640u,0x79446cu);return result;
}
unsigned run(Memory&m,const Inputs&i,Heap&h,State&,unsigned root){need(root==0x265630u);return fun_00665630(m,i,h);}
}
