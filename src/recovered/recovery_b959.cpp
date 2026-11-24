#include "recovered/recovery_b959.hpp"
#include "platform/ole_stream951.hpp"
namespace ra2::recovered::recovery_b959 {
using U=std::uint32_t;
static void read_bytes(U s,void*p,U n){auto&owner=ra2::platform::ole_stream951::Stream::current();ra2::platform::ole_stream951::need(s==owner.address(),"959 actualprovider");ra2::platform::ole_stream951::need(reinterpret_cast<IStream*>(std::uintptr_t(s))->Read(p,n,nullptr)==S_OK,"959 complete successful read");}
static U word(U s){U v;read_bytes(s,&v,4);return v;}
static void range(Memory&m,U s,U a,U n){std::vector<std::uint8_t>b(n);read_bytes(s,b.data(),n);for(U k=0;k<n;++k)m.w8(a+k,b[k]);}
static void fixup(Memory&m,U slot){auto v=m.r32(slot);if(v){auto n=m.r32(0xaa5384),cap=m.r32(0xaa537c),p=m.r32(0xaa5378);if(n>=cap)throw std::domain_error("959 registry growth excluded");m.w32(0xaa5384,n+1);m.w32(p+8*n,v);m.w32(p+8*n+4,slot);m.w32(slot,0);}}
static U vector(Memory&m,U s,U v){auto n=word(s),p=m.r32(v+4),count=m.r32(v+0x10),capacity=m.r32(v+8);if(n>8||count!=0||n>capacity)throw std::domain_error("959 empty preallocated vector bound");for(U j=0;j<n;++j){auto x=word(s);m.w32(v+0x10,j+1);m.w32(p+4*j,x);}for(U j=0;j<n;++j)fixup(m,p+4*j);return n;}
U fun_004366e0(Memory&m,const Inputs&i){auto s=i.arg[0];i.arg[0]=vector(m,s,i.cx);i.arg[0]=vector(m,s,i.cx+0x18);return 0;}
U fun_0051eb20(Memory&m,const Inputs&i){for(auto q:{std::pair<U,U>{0xa39574,1},{0x7c8bd0,4},{0x7c8bd4,4},{0xa39578,4},{0xa39584,1},{0x7c8bd8,4},{0x7c8bdc,4},{0xa3957c,4},{0xa394b8,4},{0xa39580,4}})range(m,i.cx,q.first,q.second);fixup(m,0xa39580);for(U v:{0xa39548u,0xa394c0u,0xa39508u})vector(m,i.cx,v);return 0;}
}
