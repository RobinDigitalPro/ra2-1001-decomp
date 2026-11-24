#include "recovered/recovery_b1424.hpp"
#include "recovered/text_b104.hpp"
#include "platform/x87_state.hpp"
#include <stdexcept>
namespace ra2::recovered::b1424 {
namespace {
using U=std::uint32_t;
namespace fp=ra2::platform::x87;
void need(bool value,const char*message){if(!value)throw std::domain_error(message);}
U word(const Heap&heap,U address){return heap.r8(address)|(heap.r8(address+1)<<8);}
// Actual75B300 reads the real cache value, allocates length*2+2, first writes
// NUL, then copies the entire UTF16 string including its terminator.
U make_temporary(Memory&memory,Heap&heap,U source){
 need(source,"1424 positive original cache result");U length=0;
 while(memory.r16(source+length*2)){need(length<15,"1424 bounded nonempty UTF16");++length;}
 need(length>0,"1424 positive default label");
 U temporary=0;temporary=heap.allocate((length+1)*2);need(temporary,"1424 real temporary allocation");
 heap.w8(temporary,0);heap.w8(temporary+1,0);
 for(U k=0;k<=length;++k){const U w=memory.r16(source+2*k);heap.w8(temporary+2*k,w);heap.w8(temporary+2*k+1,w>>8);}
 return temporary;
}
// Actual75B350 reads a produced one-DWORD string holder. The holder is a local
// C++ value representing5A73A0's own reserved four bytes, never an outer word.
U copy_holder(Heap&heap,U destination,const U&holder){
 heap.w32(destination,0);need(holder,"1424 produced temporary holder");U length=0;
 while(word(heap,holder+length*2)){need(length<15,"1424 bounded real temporary");++length;}
 const U copy=heap.allocate(length*2+2);need(copy,"1424 real independent string copy");heap.w32(destination,copy);
 for(U k=0;k<=length;++k){const U w=word(heap,holder+2*k);heap.w8(copy+2*k,w);heap.w8(copy+2*k+1,w>>8);}
 return destination;
}
U construct_record(Memory&memory,Heap&heap,U object){
 global_b26::Inputs lookup{};lookup.cx=0x7cffa8;lookup.dx=0;lookup.arg[0]=0x7cffb8;lookup.arg[1]=5;
 const U translated=text_b104::fun_006eeb60(memory,lookup);
 U temporary=make_temporary(memory,heap,translated);
 // Actual5B63B0 constructs the copied string, writes base vptr and tag-1.
 (void)copy_holder(heap,object+4,temporary);heap.w32(object,0x7922e4);heap.w32(object+8,0xffffffff);
 // Actual75B390 frees this actual temporary and zeros the produced holder.
 need(heap.release(temporary)==1,"1424 real temporary free");temporary=0;
 heap.w32(object,0x791b30);return object;
}
// Actual79223C+8=5B5BF0, positive zero-old-vector/capacity10/backingNULL route.
// The original C byte is cleared before allocation and restored afterwards.
U grow_empty(Memory&memory,Heap&heap,U vector,U capacity){
 need(memory.r32(vector)==0x79223c&&memory.r32(0x792244)==0x5b5bf0,"1424 actual resize virtual target");
 need(capacity==10&&memory.r32(vector+4)==0&&memory.r32(vector+8)==0&&memory.r32(vector+16)==0&&memory.r8(vector+13)==0,"1424 natural cleared vector");
 memory.w8(vector+12,0);const U data=heap.allocate(capacity*4);memory.w8(vector+12,1);need(data,"1424 actual vector allocation");
 memory.w32(vector+4,data);memory.w32(vector+8,capacity);memory.w8(vector+13,1);
 if(std::int32_t(memory.r32(vector+8))<std::int32_t(memory.r32(vector+16)))memory.w32(vector+16,memory.r32(vector+8));
 return (memory.r32(vector+8)&0xffffff00u)|1;
}
}
std::uint32_t configure_crt(Memory&m,const Inputs&i){if(i.arg[0]>1016)return 0;m.w32(0x817554,i.arg[0]);return 1;}
std::uint32_t fun_005b41c0(Memory&m,const Inputs&i,Heap&heap){
 const auto host=fp::capture_host();fp::restore_host(i.fp.image);
 try{
  const U object=heap.allocate(12);need(object,"1424 actual mandatory record allocation");const U record=construct_record(m,heap,object);
  const U vector=i.arg[0];need(vector==i.cx+8&&m.r32(i.cx)==0x791a7c,"1424 producer-compatible receiver/vector");
  const U count=m.r32(vector+16),capacity=m.r32(vector+8);need(count==0&&capacity==0&&m.r32(vector+20)==10,"1424 natural useful empty-vector input");
  need((grow_empty(m,heap,vector,capacity+m.r32(vector+20))&255)==1,"1424 real virtual resize AL1");
  const U at=m.r32(vector+16),data=m.r32(vector+4);m.w32(vector+16,at+1);heap.w32(data+at*4,record);
  const U result=m.r32(0xa25888);need(result==0,"1424 original zero optional-record count");
  i.fp.image=fp::capture_host();fp::restore_host(host);return result;
 }catch(...){fp::restore_host(host);throw;}
}
}
