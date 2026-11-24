#define NOMINMAX
#include <windows.h>
#include <objidl.h>
#include <stdexcept>
#include "recovered/recovery_b963.hpp"
#include "platform/ole_stream951.hpp"
namespace ra2::recovered::recovery_b963 {
namespace {
void need(bool ok,const char*s){if(!ok)throw std::runtime_error(s);}
void read(IStream*s,void*p,ULONG bytes){need(s->Read(p,bytes,nullptr)==S_OK,"B963 complete successful genuine Read");}
void register_slot(Memory&m,Heap&h,std::uint32_t slot){
 const auto value=h.r32(slot);if(!value)return;
 const auto count=m.r32(0xaa5384u),capacity=m.r32(0xaa537cu),data=m.r32(0xaa5378u);
 need(count<capacity,"B963 preallocated registry");
 m.w32(0xaa5384u,count+1u);m.w32(data+8u*count,value);m.w32(data+8u*count+4u,slot);h.w32(slot,0u);
}
}
std::uint32_t fun_0052fd00(Memory&m,const Inputs&i,Heap&h){
 need(i.arg[0]==ra2::platform::ole_stream951::Stream::current().address(),"B963 genuine stream address");
 auto*s=reinterpret_cast<IStream*>(std::uintptr_t(i.arg[0]));std::uint32_t count=0;read(s,&count,4u);
 need(count>=1u&&count<=4u&&m.r32(i.cx+0x1cu)==0u&&m.r32(i.cx+0x14u)==8u,"B963 finite empty vector");
 for(unsigned j=0;j<count;++j){
  const auto allocation=h.allocate(8u);need(allocation!=0u,"B963 successful ordinary allocation");
  // The real stream writes directly to a genuine allocation, as the original does.
  read(s,reinterpret_cast<void*>(std::uintptr_t(allocation)),8u);
  register_slot(m,h,allocation);register_slot(m,h,allocation+4u);
  const auto old=m.r32(i.cx+0x1cu);need(old<m.r32(i.cx+0x14u),"B963 no vector growth");
  m.w32(i.cx+0x1cu,old+1u);m.w32(m.r32(i.cx+0x10u)+old*4u,allocation);
 }
 i.arg[0]=count;return 0u;
}
}
