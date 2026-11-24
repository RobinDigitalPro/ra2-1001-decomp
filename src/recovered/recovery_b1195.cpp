#include "recovery_b1195.hpp"
#include <stdexcept>
namespace ra2::recovered::b1195{
namespace{
constexpr unsigned owner=0x819908u;
void need(bool x){if(!x)throw std::domain_error("1195 authentic cold owned workspace constructor");}
unsigned table(Heap&h,unsigned capacity){const unsigned header=h.allocate(20u);need(header);h.w32(header+12u,0u);h.w32(header+16u,0xffffffffu);h.w32(header,0u);h.w32(header+4u,capacity);const unsigned data=h.allocate((capacity+1u)*4u);need(data);h.w32(header+8u,data);for(unsigned k=0;k<=capacity;++k)h.w32(data+4u*k,0u);return header;}
}
unsigned run(unsigned root,Memory&m,const Inputs&i,Heap&h,State&){
 need(root==0x27fb0u&&i.cx==owner);for(unsigned k=0;k<0xc80u;++k)need(m.r8(owner+k)==0u);
 m.w8(owner,0u);m.w8(owner+1u,0u);m.w8(owner+2u,0u);m.w8(owner+3u,1u);m.w32(owner+4u,0x3f800000u);m.w8(owner+8u,1u);
 for(unsigned p:{0x18u,0x1cu,0x20u,0x24u,0x3cu})m.w32(owner+p,0u);for(unsigned p:{0x28u,0x2cu,0x6cu})m.w32(owner+p,0xffffffffu);m.w8(owner+0x38u,1u);m.w16(owner+0x70u,0u);m.w16(owner+0x72u,0u);
 for(unsigned j=0;j<3u;++j){const unsigned v=owner+0x74u+24u*j;m.w32(v+4u,0u);m.w32(v+8u,0u);m.w8(v+12u,1u);m.w8(v+13u,0u);m.w32(v,0x7874fcu);m.w32(v,0x7874dcu);m.w32(v+20u,10u);m.w32(v+16u,0u);}
 m.w32(owner+0x14u,table(h,0x10000u));m.w32(owner+0x68u,table(h,0x2710u));
 const unsigned nodes=h.allocate(0x100004u);need(nodes);for(unsigned k=0;k<0x10000u;++k){h.w32(nodes+16u*k+4u,0u);h.w32(nodes+16u*k+8u,0u);h.w32(nodes+16u*k+12u,0u);}h.w32(nodes+0x100000u,0u);m.w32(owner+0x10u,nodes);
 const unsigned records=h.allocate(0x180004u);need(records);h.w32(records+0x180000u,0u);m.w32(owner+12u,records);h.w32(records+0x180000u,0u);h.w32(nodes+0x100000u,0u);
 for(unsigned p:{0x14u,0x68u}){const unsigned header=m.r32(owner+p);h.w32(h.r32(header+8u),0u);h.w32(header,0u);}
 for(unsigned j=0;j<3u;++j){for(unsigned p:{0x40u,0x4cu,0x58u,0xc74u})m.w32(owner+p+4u*j,0u);const unsigned v=owner+0x74u+24u*j;m.w32(v+16u,0u);m.w8(v+13u,0u);m.w32(v+8u,0u);for(unsigned k=0;k<1000u;++k)m.w8(owner+0xbcu+1000u*j+k,0u);}
 const unsigned scratch=h.allocate(0x27100u);need(scratch);m.w32(owner+0x64u,scratch);return owner;
}
unsigned cleanup(Memory&m,Heap&h){
 for(unsigned p:{0x14u,0x68u}){const unsigned header=m.r32(owner+p);need(header);need(h.release(h.r32(header+8u))!=0u);need(h.release(header)!=0u);m.w32(owner+p,0u);}
 for(unsigned p:{0x10u,0xcu}){need(h.release(m.r32(owner+p))!=0u);m.w32(owner+p,0u);}
 for(unsigned p:{0x18u,0x1cu,0x24u,0x20u,0x40u,0x4cu,0x58u,0x44u,0x50u,0x5cu,0x48u,0x54u,0x60u})need(m.r32(owner+p)==0u);
 need(h.release(m.r32(owner+0x64u))!=0u);
 for(unsigned j=3u;j-->0u;){const unsigned v=owner+0x74u+24u*j;need(m.r32(v+4u)==0u&&m.r8(v+13u)==0u);m.w32(v,0x7874fcu);m.w8(v+13u,0u);m.w32(v+8u,0u);}
 return 0u;
}
}
