#include "recovered/recovery_b1477.hpp"
#include "platform/ole_stream951.hpp"
#include <stdexcept>
namespace ra2::recovered::b1477 {
namespace {
using U=std::uint32_t;namespace fp=ra2::platform::x87;
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
void initialize(Memory&m,U p){m.w32(p+12u,0x8192ecu);m.w32(p,0);m.w32(p+4u,0);m.w32(p+8u,0);}
void register_id(Memory&m,U id,U self){
 const U n=m.r32(0xaa539cu),cap=m.r32(0xaa5394u),data=m.r32(0xaa5390u);need(n<cap,"1477 genuine IDregistry spare capacity");
 m.w32(0xaa539cu,n+1u);m.w32(data+8u*n,id);m.w32(data+8u*n+4u,self);
}
template<class Values>void register_slot(Memory&m,Values&values,U slot){
 const U value=values.r32(slot);if(!value)return;
 const U n=m.r32(0xaa5384u),cap=m.r32(0xaa537cu),data=m.r32(0xaa5378u);need(n<cap,"1477 genuine tokenregistry spare capacity");
 m.w32(0xaa5384u,n+1u);m.w32(data+8u*n,value);m.w32(data+8u*n+4u,slot);values.w32(slot,0);
}
void read_word(IStream*s,U&v){need(s->Read(&v,4u,nullptr)==S_OK,"1477 genuine complete IStream Read DWORD");}
void load_vector(Memory&m,Heap&h,U self,U stream){
 need(stream==ra2::platform::ole_stream951::Stream::current().address(),"1477 genuine current stream");
 auto*s=reinterpret_cast<IStream*>(std::uintptr_t(stream));
 //410120 has its own copied stream argument; ID scratch cannot reach the root caller.
 U saved_id;read_word(s,saved_id);register_id(m,saved_id,self);
 const U saved1c=m.r32(self+0x1cu);
 need(m.r32(m.r32(self)+0x30u)==0x4b85d0u,"1477 actual sizeof0 virtual target");
 need(s->Read(reinterpret_cast<void*>(std::uintptr_t(self)),0u,nullptr)==S_OK,"1477 actual zero-byte Read still called");m.w32(self+0x1cu,saved1c);
 //5CCDF0: the four constructor-produced slots remain real zero-valued queries.
 for(U off:{0x30u,0x34u,0x38u,0x18u})register_slot(m,m,self+off);
 initialize(m,self+0x3cu);initialize(m,self+0x50u);m.w32(self+0x94u,0u);
 //62E200 unconditionally resets the vector. The prior live owner is NOT freed.
 m.w32(self+0xccu,0u);m.w32(self+0xd0u,0u);m.w8(self+0xd4u,1u);m.w8(self+0xd5u,0u);m.w32(self+0xc8u,0x7857fcu);
 U count;read_word(s,count);need(count>=1u&&count<=8u,"1477 positive bounded pointer count");
 need(m.r32(0x7857fcu+8u)==0x40b8b0u,"1477 actual resize virtual target");
 //40B8B0(count,NULL), with its freshly-produced old pointer0: allocate, no copy/free.
 m.w8(self+0xd4u,0u);const U allocation=h.allocate(4u*count);m.w8(self+0xd4u,1u);need(allocation,"1477 actual successful vector owner");
 m.w32(self+0xccu,allocation);m.w32(self+0xd0u,count);m.w8(self+0xd5u,1u);
 U token;for(U k=0;k<count;++k){read_word(s,token);h.w32(allocation+4u*k,token);}
 for(U k=0;k<count;++k)register_slot(m,h,allocation+4u*k);
}
}
std::uint32_t configure_crt(Memory&m,const Inputs&i){if(i.arg[0]>1016u)return 0u;m.w32(0x817554u,i.arg[0]);return 1u;}
std::uint32_t fun_006cbdc0(Memory&m,const Inputs&i,Heap&h){
 const U self=i.arg[0],stream=i.arg[1];need(self&&stream&&m.r32(self)==0x797a28u,"1477 actual primary constructor receiver");
 need(m.r32(0x797a3cu)==0x6cbdc0u&&m.r32(self+0x108u)==0u,"1477 real loader slot and constructor108zero");
 need(m.r32(0x817554u)==0u&&m.r32(0xb10e14u)==0u,"1477 actual ordinary CRT configuration");
 const auto host=fp::capture_host();fp::restore_host(i.fp.image);
 try{
  load_vector(m,h,self,stream);m.w32(self+0x408u,0u);register_slot(m,m,self+0x1b4u);
  for(U k=0;k<8u;++k)register_slot(m,m,self+0x25cu+4u*k);
  for(U off:{0x1b0u,0x3f8u,0x228u,0x22cu,0x230u,0x384u,0x238u,0x234u,0x23cu,0x40cu,0x410u,0x208u,0x20cu,0xfcu,0x27cu})register_slot(m,m,self+off);
  //Self108==0 skips the entire AA8700 branch and its outer arg1 rewrite.
  register_slot(m,m,self+0x108u);initialize(m,self+0x3d8u);m.w32(self+0x3ecu,1u);m.w32(self+0x3f0u,0u);
  i.fp.image=fp::capture_host();fp::restore_host(host);return 0u;
 }catch(...){fp::restore_host(host);throw;}
}
}
