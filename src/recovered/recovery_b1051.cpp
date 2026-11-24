#include "recovered/recovery_b1051.hpp"
#include "recovered/recovery_b1035.hpp"
#include <stdexcept>
#include <initializer_list>
namespace ra2::recovered::b1051 {
static void need(bool ok){if(!ok)throw std::domain_error("1051 outside reviewed positive contract");}
static unsigned remove(Memory&m,unsigned reg,unsigned value){const auto data=m.r32(reg+4u),n=m.r32(reg+16u);unsigned k=0;while(k<n&&m.r32(data+4u*k)!=value)++k;need(k<n);m.w32(reg+16u,n-1u);for(unsigned j=k+1u;j<n;++j)m.w32(data+4u*(j-1u),m.r32(data+4u*j));return n-1u;}
static void clear(Memory&m,Heap&h,unsigned v,unsigned tag){m.w32(v,tag);const auto p=m.r32(v+4u);if(p&&m.r8(v+13u)){h.release(p);m.w32(v+4u,0u);}m.w8(v+13u,0u);m.w32(v+8u,0u);}
unsigned fun_006cfec0(Memory&m,const Inputs&i,Heap&h){const auto p=i.cx;constexpr unsigned vt[]{0x797f28u,0x797f0cu,0x797f04u,0x797efcu};for(unsigned k=0;k<4u;++k)m.w32(p+4u*k,vt[k]);
 for(unsigned off:{0x60cu,0x62cu})if(m.r8(p+off+4u)&&m.r32(p+off)){h.release(m.r32(p+off));m.w32(p+off,0u);m.w8(p+off+4u,0u);}
 remove(m,0xaa87b8u,p);remove(m,0xa286f8u,p);
 for(unsigned off:{0x6a8u,0x68cu})clear(m,h,p+off,0x7880acu);
 for(unsigned off:{0x660u,0x644u})clear(m,h,p+off,0x78eb5cu);
 for(unsigned off:{0x57cu,0x560u})clear(m,h,p+off,0x7889d4u);
 clear(m,h,p+0x510u,0x78eb5cu);
 for(unsigned off:{0x494u,0x478u,0x45cu,0x440u,0x424u,0x408u,0x3ecu,0x3d0u})clear(m,h,p+off,0x7889d4u);
 clear(m,h,p+0x3acu,0x78df08u);clear(m,h,p+0x300u,0x7889d4u);clear(m,h,p+0x2e4u,0x793fc0u);
 // The accepted positive base cleanup has genuine populated registries and
 // five owned buffers; its actual final EAX is base registry remaining count.
 return ra2::recovered::b1035::run(m,i,h,0x1ce1f0u);
}
unsigned fun_006b7720(Memory&m,const Inputs&i,Heap&h){const auto p=i.cx;need(m.r32(0x8192f8u)==0u&&m.r32(p+0x408u)==0u&&m.r32(p+0x238u)==0u&&m.r32(p+0x208u)==0u&&m.r32(p+0x108u)==0u&&m.r32(p+0x94u)==0u);constexpr unsigned own[]{0x797a28u,0x797a0cu,0x797a04u,0x7979fcu};for(unsigned k=0;k<4u;++k)m.w32(p+4u*k,own[k]);
 const auto child=m.r32(p+0x230u);need(child&&h.r32(child)==0x7887b8u);remove(m,0x8388e8u,child);constexpr unsigned base[]{0x785dd8u,0x785dbcu,0x785db4u,0x785dacu};for(unsigned k=0;k<4u;++k)h.w32(child+4u*k,base[k]);h.release(child);m.w32(p+0x230u,0u);
 m.w32(p+0x3e0u,0u);m.w32(p+0x3e4u,0u);m.w32(p+0x1b4u,0u);m.w8(p+0x372u,0u);
 for(unsigned r:{0xa28860u,0xaa8810u,0xaa8700u})remove(m,r,p);
 clear(m,h,p+0x3c0u,0x78c79cu);clear(m,h,p+0x3a8u,0x78c79cu);clear(m,h,p+0x390u,0x7889d4u);clear(m,h,p+0xc8u,0x7857fcu);
 for(unsigned r:{0xaa87e0u,0xa27fb8u,0xaa8868u,0xaa87b8u,0xaa8760u})remove(m,r,p);
 m.w32(p+0x30u,0u);m.w8(p+0x7du,0u);for(unsigned off:{0x3cu,0x50u}){m.w32(p+off+8u,0u);m.w32(p+off+12u,0u);}for(unsigned k=0;k<4u;++k)m.w32(p+4u*k,base[k]);return p+0x50u;
}
static unsigned weight(Memory&m,unsigned entity,unsigned owner){need(m.r32(entity)==0x787bbcu);const auto type=m.r32(entity+0x418u);need(type&&m.r32(type+0xc78u)==0u&&m.r32(0x7bac08u)==1u&&m.r32(0x7bac60u)==1u);
 // Actual443E10 +48 getter uses footprint0 dimensions1x1: offsets both0.
 const auto x=global_b26::s32(m.r32(entity+0x88u))/256,y=global_b26::s32(m.r32(entity+0x8cu))/256;need(x>=0&&x<512&&y>=0&&y<512);const auto cell=m.r32(m.r32(0x81a958u)+4u*(unsigned(y)*512u+unsigned(x)));need(cell!=0u);const auto packed=m.r32(cell+0x24u);const auto cx=global_b26::s32(global_b26::sx16(packed)),cy=global_b26::s32(global_b26::sx16(packed>>16u));const auto index=cx/4+130*(cy/4);need(index>=0);return m.r32(owner+0x58dcu+4u*unsigned(index));
}
unsigned fun_006b25c0(Memory&m,const Inputs&i){need(i.arg[1]<=1u);unsigned preferred=0u,best=0u;int ps=-1,bs=-1;const auto n=m.r32(0xa28748u),table=m.r32(0xa2873cu),origin_owner=m.r32(i.arg[0]+0x1b4u);
 for(unsigned k=0;k<n;++k){const auto e=m.r32(table+4u*k),owner=m.r32(e+0x1b4u);if(m.r32(e+0x418u)!=i.cx)continue;const bool own=owner==i.dx;if(!own){need(owner&&origin_owner);const auto a=m.r32(owner+0x30u),b=m.r32(origin_owner+0x30u);const bool allied=owner==origin_owner||a==b||(a!=0xffffffffu&&(m.r32(origin_owner+0x5674u)&(1u<<(a&31u)))!=0u);if(allied){const auto config=m.r32(owner+0x34u);if(m.r8(config+0x1a6u)==0u)continue;}}
  const auto w=weight(m,e,origin_owner);need(w<=1000000u);const int score=int(i.arg[1]?w:0x7fffffffu-w);if(own&&score>ps){preferred=e;ps=score;}if(score>bs){best=e;bs=score;}}
 need(best!=0u);return (preferred&&ps>bs)||(i.arg[2]&255u)!=0u?preferred:best;
}
unsigned fun_006b2890(Memory&m,const Inputs&i){need(i.arg[1]<=1u);const auto owner=m.r32(i.arg[0]+0x1b4u),n=m.r32(owner+0x78u),table=m.r32(owner+0x6cu);unsigned best=0u;int score=-1;for(unsigned k=0;k<n;++k){const auto e=m.r32(table+4u*k);if(m.r32(e+0x418u)!=i.cx)continue;const auto w=weight(m,e,owner);need(w<=1000000u);const int s=int(i.arg[1]?w:0x7fffffffu-w);if(s>score){score=s;best=e;}}need(best!=0u);return best;}
unsigned run(Memory&m,const Inputs&i,Heap&h,State&,unsigned r){switch(r){case 0x2b25c0u:return fun_006b25c0(m,i);case 0x2b2890u:return fun_006b2890(m,i);case 0x2b7720u:return fun_006b7720(m,i,h);case 0x2cfec0u:return fun_006cfec0(m,i,h);default:throw std::domain_error("1051 root");}}
}
