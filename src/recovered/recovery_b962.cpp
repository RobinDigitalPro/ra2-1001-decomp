#include "recovered/recovery_b962.hpp"
#include "recovered/recovery_b959.hpp"
#include "platform/ole_stream951.hpp"
namespace ra2::recovered::recovery_b962 {
using U=std::uint32_t;
namespace {
void read_exact(U s,void* p,U n) {
 auto& owner=ra2::platform::ole_stream951::Stream::current();
 ra2::platform::ole_stream951::need(s==owner.address(),"B962 actual IStream identity");
 ra2::platform::ole_stream951::need(reinterpret_cast<IStream*>(std::uintptr_t(s))->Read(p,n,nullptr)==S_OK,"B962 complete successful Read");
}
U word(U s) { U v=0; read_exact(s,&v,4); return v; }
void range(Memory& m,U s,U a,U n) {std::vector<std::uint8_t>b(n);read_exact(s,b.data(),n);for(U k=0;k<n;++k)m.w8(a+k,b[k]);}
// A direct bounded rendition of 0x295170. Its storage and capacity are real
// guest globals; no callback or substitute vtable is involved.
void fixup(Memory& m,U slot) {
 const U v=m.r32(slot); if(!v)return;
 const U n=m.r32(0xaa5384),cap=m.r32(0xaa537c),p=m.r32(0xaa5378);
 if(n>=cap)throw std::domain_error("B962 registry growth excluded");
 m.w32(p+8*n,v);m.w32(p+8*n+4,slot);m.w32(0xaa5384,n+1);m.w32(slot,0);
}
void append_vector(Memory& m,U s,U obj,bool register_slots) {
 const U n=word(s),p=m.r32(obj+4),count=m.r32(obj+0x10),cap=m.r32(obj+8);
 if(n>4||count!=0||n>cap)throw std::domain_error("B962 vector bound");
 for(U j=0;j<n;++j){const U x=word(s);m.w32(p+4*j,x);m.w32(obj+0x10,j+1);}
 if(register_slots)for(U j=0;j<n;++j)fixup(m,p+4*j);
}
}
U fun_0064ecd0(Memory& m,const Inputs& i) {
 const U s=i.cx;
 range(m,s,0xa28960,4);fixup(m,0xa28960);
 range(m,s,0xa1e0e4,4);fixup(m,0xa1e0e4);
 range(m,s,0xa2896c,4);
 append_vector(m,s,0xa288a0,true);
 range(m,s,0x8391d0,0x1b0);
 Inputs nested=i;ra2::recovered::recovery_b959::fun_0051eb20(m,nested);
 append_vector(m,s,0x84e490,true);
 append_vector(m,s,0x84e568,true);
 range(m,s,0x7bea10,0x4c);range(m,s,0x7bea5c,0x4c);
 range(m,s,0x8393b0,0x98);range(m,s,0x839448,0x13);
 range(m,s,0xa28000,0x3c0);range(m,s,0xaa0c7c,4);
 return 0;
}
}
