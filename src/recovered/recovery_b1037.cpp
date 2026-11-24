#include "recovered/recovery_b1037.hpp"
#include <stdexcept>
#include <initializer_list>
namespace ra2::recovered::b1037 {
namespace{void need(bool b,const char*s){if(!b)throw std::domain_error(s);}}
unsigned run(Memory&m,const Inputs&i,Heap&h,unsigned root){const bool self=root==0x138c00u;need(self||root==0x1381a0u,"1037 exact useful roots");const unsigned p=i.cx;
 const auto r=[&](unsigned a){return self?h.r32(a):m.r32(a);};const auto rb=[&](unsigned a){return self?h.r8(a):m.r8(a);};const auto w=[&](unsigned a,unsigned x){if(self)h.w32(a,x);else m.w32(a,x);};const auto byte=[&](unsigned a,unsigned x){if(self)h.w8(a,x);else m.w8(a,x);};
 const auto release=[&](unsigned a){need(a!=0u,"1037 positive genuine owned content");need(h.release(a)!=0u,"1037 actual successful HeapFree");};
 const auto base=[&](unsigned q){w(q,0x78c82cu);need(m.r32(0x84e320u)==0u&&m.r32(0x84e324u)==0u&&m.r32(0x84e328u)==0u,"1037 no external active/focus object");w(q,0x78c8b4u);need(r(q+4u)==0u&&r(q+8u)==0u,"1037 original isolated list node getters return exact receiver");w(q+8u,0u);w(q+4u,0u);return q;};
 w(p,0x790624u);need(rb(p+0x54u)==0u,"1037 finite inactive stop/play state");const unsigned auxiliary=p+0x118u;w(auxiliary,0x790734u);need(r(auxiliary+0x3cu)==0u&&r(auxiliary+0x40u)==0u,"1037 no unproved auxiliary polymorphic provider");base(auxiliary);
 for(unsigned off:{0xb8u,0x58u}){const unsigned q=p+off;w(q,0x78b6a0u);need(rb(q+0x5cu)==1u,"1037 positive owned image descriptor");release(r(q+0x58u));w(q+0x58u,0u);byte(q+0x5cu,0u);w(q+0x14u,0u);w(q+0x18u,0u);base(q);}
 w(p+0x34u,0x790714u);need(rb(p+0x41u)==1u,"1037 positive primary vector ownership");release(r(p+0x38u));w(p+0x38u,0u);byte(p+0x41u,0u);w(p+0x3cu,0u);const unsigned eax=base(p);if(self){need((i.arg[0]&1u)!=0u,"1037 actual deleting flag");release(p);return p;}return eax;
}
}
