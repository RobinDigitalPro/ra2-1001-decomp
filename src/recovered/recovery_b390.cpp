#include "recovered/recovery_b390.hpp"
#include "recovered/hash_wrappers.hpp"
#include "recovered/name_hash.hpp"
#include <array>
#include <iterator>
#include <stdexcept>
#include <vector>

namespace ra2::recovered::recovery_b390 {
namespace {
enum Kind:std::uint32_t{normalized=1,raw_byte=2,dword=3,qword=4,span16=5};
void load(Memory&m,std::uint32_t p,NameHashState&s){s.accumulator=m.r32(p);s.pending=m.r32(p+4u);if(s.pending>3u)throw std::domain_error("B390 requires the documented NameHashState pending range 0..3");for(unsigned k=0;k<4;++k)s.scratch[k]=static_cast<std::uint8_t>(m.r8(p+8u+k));s.completion_byte=static_cast<std::uint8_t>(m.r8(p+12u));}
void store(Memory&m,std::uint32_t p,const NameHashState&s){m.w32(p,s.accumulator);m.w32(p+4u,s.pending);for(unsigned k=0;k<4;++k)m.w8(p+8u+k,s.scratch[k]);m.w8(p+12u,s.completion_byte);}
std::uint32_t bytes(NameHashState&s,const std::uint8_t*p,std::uint32_t n){return fun_00493da0(s,p,static_cast<std::int32_t>(n));}
// 493bd0/493c60 do not pad or return a preview CRC for pending bytes.
// Their nested argument overwrite on commit is outside this caller frame.
std::uint32_t add_byte(NameHashState&s,std::uint32_t b,bool norm){
 if(s.pending==0)s.scratch.fill(0);
 s.scratch[s.pending++]=static_cast<std::uint8_t>(norm?((b&255u)!=0u):b);
 if(s.pending!=4)return s.pending;
 s.completion_byte=4;s.accumulator=fun_00493f70(s.scratch.data(),4,s.accumulator);s.pending=0;return s.accumulator;
}
std::uint32_t add_dword(NameHashState&s,std::uint32_t v){return fun_00493d10(s,v);}
std::uint32_t add_qword(NameHashState&s,std::uint32_t lo,std::uint32_t hi){return fun_00493d50(s,std::uint64_t(lo)|(std::uint64_t(hi)<<32u));}
std::uint32_t add_span(Memory&m,NameHashState&s,std::uint32_t p,std::uint32_t n){std::vector<std::uint8_t>b(n);for(std::uint32_t k=0;k<n;++k)b[k]=static_cast<std::uint8_t>(m.r8(p+k));return bytes(s,b.data(),n);}
std::uint32_t add_zstr(Memory&m,NameHashState&s,std::uint32_t p){std::array<std::uint8_t,256>b{};std::uint32_t n=0;for(;n<b.size();++n){b[n]=static_cast<std::uint8_t>(m.r8(p+n));if(!b[n])break;}if(n==b.size())throw std::domain_error("B390 positive fixture requires NUL within 256 readable bytes");return bytes(s,b.data(),n);}
std::uint32_t init_101b0(Memory&m,std::uint32_t object,std::uint32_t state,NameHashState&s,Trace*t){
 auto ret=add_dword(s,m.r32(object+0x10u));if(t)t->push_back({0x10u,dword,4u,m.r32(object+0x10u),ret});store(m,state,s);
 const auto raw=m.r8(object+0x20u);ret=add_byte(s,raw,true);if(t)t->push_back({0x20u,normalized,1u,raw,ret});store(m,state,s);return ret;
}
std::uint32_t init_10960(Memory&m,std::uint32_t object,std::uint32_t state,NameHashState&s,Trace*t){
 auto ret=init_101b0(m,object,state,s,t);
 for(const auto off:{0x24u,0x64u,0x3du}){ret=add_zstr(m,s,object+off);if(t)t->push_back({off,span16,0xffffffffu,0u,ret});store(m,state,s);}return ret;
}
struct Op{std::uint16_t off;Kind kind;std::uint16_t width;};
constexpr Op k315790[]={
 {0x144,normalized,1},{0x146,normalized,1},{0x147,normalized,1},{0x148,normalized,1},{0x149,normalized,1},{0x14a,normalized,1},{0x14b,normalized,1},{0x14c,normalized,1},{0x14d,normalized,1},{0x14e,normalized,1},{0x14f,normalized,1},{0x150,normalized,1},{0x151,normalized,1},
 {0x98,qword,8},{0x100,dword,4},{0xf8,qword,8},{0x166,normalized,1},{0x168,dword,4},{0x16c,dword,4},{0x170,dword,4},{0x174,dword,4},
 {0xa0,qword,88},{0x114,dword,4},{0x120,dword,4}};
constexpr Op k2d4540[]={
 {0x2c0,qword,8},{0x2c8,dword,4},{0x2d0,qword,8},{0x2d8,qword,8},{0x2e0,dword,4},{0x2f4,dword,4},{0x520,dword,4},{0x3bc,dword,4},{0x310,dword,4},{0x31c,span16,16},
 {0x330,qword,8},{0x338,qword,8},{0x340,qword,8},{0x348,qword,8},{0x350,qword,8},{0x358,qword,8},{0x360,normalized,1},{0x368,dword,4},
 {0xa9d,normalized,1},{0xa9e,normalized,1},{0xa9c,normalized,1},{0x370,qword,8},{0x380,qword,8},{0x378,qword,8},{0x558,dword,4},{0x388,dword,4},{0x38c,dword,4},
 {0x398,qword,8},{0x3a0,dword,4},{0x3a4,dword,4},{0x3e0,dword,4},{0x3fc,dword,4},{0x418,dword,4},{0x434,dword,4},{0x450,dword,4},{0x46c,dword,4},{0x488,dword,4},{0x4a4,dword,4},{0x69c,dword,4},{0x6b8,dword,4},
 {0x500,dword,4},{0x504,dword,4},{0x508,dword,4},{0x50c,dword,4},{0x52c,dword,4},{0x530,dword,4},{0x550,dword,4},{0x554,dword,4},{0x55c,dword,4},{0x570,dword,4},{0x58c,dword,4},{0x598,dword,4},{0x59c,dword,4},{0x5a0,dword,4},{0x5a4,dword,4},{0x5ac,dword,4},{0x5b4,dword,4},{0x5e8,dword,4},{0x5ec,dword,4},{0x634,dword,4},{0x638,dword,4},{0x63c,dword,4},{0x640,dword,4},{0x654,dword,4},{0x670,dword,4},{0x6f8,dword,4},{0x6fc,dword,4},
 {0xaa0,normalized,1},{0xaa1,normalized,1},{0xaa2,normalized,1},{0xaa3,normalized,1},{0xaa4,normalized,1},{0xaa5,normalized,1},{0xaa6,normalized,1},{0xaa7,normalized,1},{0xaa8,normalized,1},{0xaa9,normalized,1},{0xaaa,normalized,1},{0xaab,normalized,1},
 {0xad8,normalized,1},{0xad9,normalized,1},{0xadb,normalized,1},{0xadc,normalized,1},{0xadd,normalized,1},{0xade,raw_byte,1},{0xadf,raw_byte,1},{0xae0,normalized,1},{0xae1,normalized,1},{0xae2,normalized,1},
 {0xaec,normalized,1},{0xaed,normalized,1},{0xaee,normalized,1},{0xaef,normalized,1},{0xaf0,normalized,1},{0xaf1,normalized,1},{0xb5a,normalized,1},{0xb5b,normalized,1},{0x5cd,normalized,1},{0x5ce,normalized,1},{0x5cf,normalized,1}};
std::uint32_t run(Memory&m,const Inputs&i,const Op*ops,std::size_t count,Trace*t){const auto object=i.cx,state_addr=i.arg[0];NameHashState s{};load(m,state_addr,s);auto ret=init_10960(m,object,state_addr,s,t);
 for(const auto&o:std::vector<Op>(ops,ops+count)){
  if(o.kind==qword&&o.width==88u){for(unsigned k=0;k<11u;++k){const auto off=o.off+8u*k,lo=m.r32(object+off),hi=m.r32(object+off+4u);ret=add_qword(s,lo,hi);if(t)t->push_back({off,qword,8u,std::uint64_t(lo)|(std::uint64_t(hi)<<32u),ret});store(m,state_addr,s);}continue;}
  std::uint64_t raw=0;std::uint32_t n=o.width;
  if(o.kind==qword){const auto lo=m.r32(object+o.off),hi=m.r32(object+o.off+4u);raw=std::uint64_t(lo)|(std::uint64_t(hi)<<32u);ret=add_qword(s,lo,hi);}
  else if(o.kind==dword){raw=m.r32(object+o.off);ret=add_dword(s,static_cast<std::uint32_t>(raw));}
  else if(o.kind==normalized||o.kind==raw_byte){raw=m.r8(object+o.off);ret=add_byte(s,static_cast<std::uint32_t>(raw),o.kind==normalized);}
  else if(o.kind==span16){ret=add_span(m,s,object+o.off,o.width);for(unsigned k=0;k<o.width&&k<8;++k)raw|=std::uint64_t(m.r8(object+o.off+k))<<(k*8u);}
  if(t)t->push_back({o.off,static_cast<std::uint32_t>(o.kind),n,raw,ret});store(m,state_addr,s);
 }
 return ret;
}
}
std::uint32_t run_00315790(Memory&m,const Inputs&i,Trace*t){return run(m,i,k315790,std::size(k315790),t);}
std::uint32_t run_002d4540(Memory&m,const Inputs&i,Trace*t){return run(m,i,k2d4540,std::size(k2d4540),t);}
std::uint32_t rva_00315790(Memory&m,const Inputs&i){return run_00315790(m,i,nullptr);}
std::uint32_t rva_002d4540(Memory&m,const Inputs&i){return run_002d4540(m,i,nullptr);}
}

