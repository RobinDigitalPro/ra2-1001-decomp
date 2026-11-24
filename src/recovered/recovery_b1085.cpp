#include "recovered/recovery_b1085.hpp"
#include <stdexcept>
namespace ra2::recovered::b1085 {
unsigned run(Memory&m,const Inputs&,Heap&h,State&,unsigned rva){
 auto need=[](bool v){if(!v)throw std::domain_error("1085 six positive owned buffers and authentic constructed-empty receiver");};
 need(rva==0x1c27c0u&&m.r32(0x817554u)==0u);
 // Original full owner constructor 664F70, called with A255C8 at4D3F30,
 // installs 791838 at +27E0, giving this exact A27DA8 receiver.
 need(m.r32(0xa27da8u)==0x791838u&&m.r32(0x791844u)==0x5a3010u);
 need(m.r32(0xa27dacu)==0u&&m.r32(0xa27db0u)==0u&&m.r32(0xa27db8u)==0u&&m.r8(0xa27db4u)==1u&&m.r8(0xa27db5u)==0u&&m.r32(0xa27dbcu)==10u);
 for(unsigned n=0;n<6u;++n)need(m.r32(0xa5a89cu+4u*n)!=0u);
 for(unsigned n=0;n<6u;++n){const auto slot=0xa5a89cu+4u*n;h.release(m.r32(slot));m.w32(slot,0u);}
 // Tail1A4070 sees count0 and invokes actual791838+0C ->1A3010.
 // Its EAX is the null array pointer; count/capacity/ownership are reset.
 m.w32(0xa27db8u,0u);m.w8(0xa27db5u,0u);m.w32(0xa27db0u,0u);
 return 0u;
}
}
