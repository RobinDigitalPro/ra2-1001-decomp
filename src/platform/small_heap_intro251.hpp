#pragma once
#include "recovered/recovery_b251.hpp"
#include "platform/small_heap_file_recipe249.hpp"
#include "platform/small_crt_heap_win32.hpp"
#include <array>
#include <algorithm>
#include <memory>
#include <stdexcept>
#include <vector>
#include <cstdio>

namespace ra2::platform::intro251 {
using U=std::uint32_t;
using GuestMemory=ra2::recovered::global_b26::Memory;
using SmallMemory=ra2::platform::file_heap249::Memory;
inline void need(bool b,const char*s){if(!b)throw std::runtime_error(s);}
inline U span_class(U span){need(span>=16&&!(span&15),"251 invalid span");return std::min((span>>4)-1,63u);}
// Pinned773858..7739D4, sole initialized chunk. Bitmap selection follows
// the lowest fitting advertised class, then the first node in that class.
inline U allocate_current(SmallMemory&m,U request){
 const U record=m.r32(0xb10e0c),metadata=m.r32(record+16),arena=m.r32(record+12),heads=metadata+0x144;
 need(record==m.r32(0xb10e18)&&m.r32(0xb10e14)==1&&m.r32(metadata)==0,"251 sole current chunk required");
 const U rounded=(request+0x17)&~15u;need(request>0&&request<=0x140,"251 bounded small request");
 U cls=span_class(rounded);
 for(;cls<64;++cls){const U bit=0x80000000u>>(cls&31),map=m.r32(metadata+(cls<32?0x44:0xc4));if(map&bit)break;}
 need(cls<64,"251 no fitting advertised class");
 const U head=heads+cls*8,node=m.r32(head+4),oldspan=m.r32(node);
 need(node!=head&&node>=arena+12&&node<arena+0x1000&&!(oldspan&1)&&oldspan>=rounded,"251 selected first-page free node");
 const U residual=oldspan-rounded;const bool same=residual&&span_class(residual)==cls;
 if(!same){
  const U next=m.r32(node+4),previous=m.r32(node+8);
  //77387D..7738E1 clears availability only when removing the sole node.
  if(next==previous){const U countaddr=metadata+4+cls;const auto count=m.r8(countaddr);need(count,"251 class count underflow");
   const U bit=0x80000000u>>(cls&31),map=metadata+(cls<32?0x44:0xc4);
   m.w32(map,m.r32(map)&~bit);m.w8(countaddr,std::uint8_t(count-1));
   if(count==1)m.w32(record+(cls<32?0:4),m.r32(record+(cls<32?0:4))&~bit);
  }
  m.w32(previous+4,next);m.w32(next+8,previous);
  if(residual){
   const U rc=span_class(residual),rh=heads+rc*8,first=m.r32(rh+4);
   m.w32(node+4,first);m.w32(node+8,rh);m.w32(rh+4,node);m.w32(first+8,node);
   if(first==rh){const U ca=metadata+4+rc;const auto count=m.r8(ca);m.w8(ca,std::uint8_t(count+1));
    const U bit=0x80000000u>>(rc&31);if(!count)m.w32(record+(rc<32?0:4),m.r32(record+(rc<32?0:4))|bit);
    const U map=metadata+(rc<32?0x44:0xc4);m.w32(map,m.r32(map)|bit);
   }
  }
 }
 if(residual){m.w32(node,residual);m.w32(node+residual-4,residual);}
 const U allocated=node+residual;m.w32(allocated,rounded+1);m.w32(allocated+rounded-4,rounded+1);
 const U live=m.r32(heads);m.w32(heads,live+1);
 if(!live&&record==m.r32(0xb10e10)&&!m.r32(0xb10e08))m.w32(0xb10e10,0);
 m.w32(metadata,0);return allocated+4;
}

class Heap final:public ra2::recovered::recovery_b251::Heap,public SmallMemory{
 GuestMemory&m_;ra2::platform::small_crt_heap::Heap&bootstrap_;HANDLE handle_;U ordinary_=0,ordinal_=0;
 std::vector<std::unique_ptr<ra2::recovered::leaf::Memory>> spans_;
 static U ptr(void*p){return U(reinterpret_cast<std::uintptr_t>(p));}
 void map(U p,U size){spans_.emplace_back(new ra2::recovered::leaf::Memory(reinterpret_cast<std::uint8_t*>(p),p,size));m_.add(*spans_.back());}
 void lock(){EnterCriticalSection(reinterpret_cast<CRITICAL_SECTION*>(m_.r32(0x81729c)));}
 void unlock(){LeaveCriticalSection(reinterpret_cast<CRITICAL_SECTION*>(m_.r32(0x81729c)));}
public:
 struct Event{bool allocation;U request_or_pointer,result;};std::vector<Event>events;
 std::array<U,24>pointers{};
 Heap(GuestMemory&m,ra2::platform::small_crt_heap::Heap&b,HANDLE h):m_(m),bootstrap_(b),handle_(h){}
 ~Heap(){if(ordinary_)HeapFree(handle_,0,reinterpret_cast<void*>(ordinary_));}
 U allocate(U request)override{
  constexpr U requests[]{12,0x1000,0x44,6,0x28,3,8,0x50,0x50,0x70,0x140,10,6,1,11,1,1,5,5,5,1,6,1,8};
  need(ordinal_<24&&requests[ordinal_]==request,"251 allocation order/size mismatch");U p;
  if(ordinal_==0){p=bootstrap_.allocate(12);const U record=bootstrap_.r32(0xb10e18),arena=bootstrap_.r32(record+12),meta=bootstrap_.r32(record+16);map(arena,0x8000);map(meta,0x41c4);}
  else if(request==0x1000){need(!ordinary_,"251 duplicate ordinary allocation");ordinary_=ptr(HeapAlloc(handle_,HEAP_ZERO_MEMORY,0x1000));need(ordinary_,"251 real buffer allocation failed");map(ordinary_,0x1000);p=ordinary_;}
  else{lock();try{p=allocate_current(*this,request);}catch(...){unlock();throw;}unlock();}
  pointers[ordinal_++]=p;events.push_back({true,request,p});return p;
 }
 void release(U p)override{
  events.push_back({false,p,0});if(!p)return;
  if(p==ordinary_){need(HeapFree(handle_,0,reinterpret_cast<void*>(p))!=FALSE,"251 real buffer release failed");ordinary_=0;return;}
  lock();try{ra2::platform::file_heap249::release_file_small_block(*this,m_.r32(0xb10e18),p);}catch(...){unlock();throw;}unlock();
 }
 std::uint8_t r8(U a)const override{return bootstrap_.r8(a);}
 U r32(U a)const override{U v=0;for(unsigned j=0;j<4;++j)v|=U(r8(a+j))<<(j*8);return v;}
 void w8(U a,std::uint8_t v)override{bootstrap_.w8(a,v);}
 void w32(U a,U v)override{for(unsigned j=0;j<4;++j)w8(a+j,std::uint8_t(v>>(j*8)));}
};
}
