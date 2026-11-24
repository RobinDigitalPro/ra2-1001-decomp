#include "recovered/recovery_b1432.hpp"
#include "recovered/text_b104.hpp"
#include "platform/x87_state.hpp"
#include <stdexcept>
namespace ra2::recovered::b1432 {
namespace {
using U=std::uint32_t;namespace fp=ra2::platform::x87;
void need(bool ok,const char*message){if(!ok)throw std::domain_error(message);}
U default_tooltip(Memory&m,const Inputs&i,Heap&heap,U key,U line){
 need(i.arg[0]==0xffffffffu,"1432 normal no-hover-row contract");
 const auto host=fp::capture_host();fp::restore_host(i.fp.image);
 try{
  // Actual roots clear EDX and supply original file/line to the unchanged
  // cache lookup. All nested argument words are produced private values.
  global_b26::Inputs lookup{};lookup.cx=key;lookup.dx=0;lookup.arg[0]=0x7e6cbc;lookup.arg[1]=line;
  const U text=text_b104::fun_006eeb60(m,lookup);need(text,"1432 real nonempty cache hit");
  // Exact75B300 constructor: clear fresh holder, measure UTF16, allocate,
  // publish owner, write initial NUL, then copy including the terminator.
  m.w32(i.cx,0);U length=0;
  while(m.r16(text+2*length)){need(length<15,"1432 bounded localized text");++length;}
  need(length==5,"1432 explicit five-character tooltip fixture");
  const U owner=heap.allocate(2*length+2);need(owner,"1432 genuine string allocation");m.w32(i.cx,owner);heap.w8(owner,0);heap.w8(owner+1,0);
  for(U k=0;k<=length;++k){const U unit=m.r16(text+2*k);heap.w8(owner+2*k,unit);heap.w8(owner+2*k+1,unit>>8);}
  i.fp.image=fp::capture_host();fp::restore_host(host);return i.cx;
 }catch(...){fp::restore_host(host);throw;}
}
}
std::uint32_t configure_crt(Memory&m,const Inputs&i){if(i.arg[0]>1016)return 0;m.w32(0x817554,i.arg[0]);return 1;}
std::uint32_t fun_00733d40(Memory&m,const Inputs&i,Heap&heap){return default_tooltip(m,i,heap,0x7d49a4,0x966);}
std::uint32_t fun_00733fa0(Memory&m,const Inputs&i,Heap&heap){return default_tooltip(m,i,heap,0x7d49b8,0x991);}
}
