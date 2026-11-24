#include "recovery_b718.hpp"
#include "crt_b83.hpp"
#include "name_hash.hpp"
#include <vector>
#include <stdexcept>
namespace ra2::recovered::recovery_b718 {
namespace {
// Same positive loaded-cache path proved in B188, with 26 original names.
unsigned lookup(Memory&m,unsigned name,unsigned flag){
 m.w8(flag,0);
 if(!name||m.r32(0xb10530))throw std::domain_error("445 nonempty C-locale name required");
 unsigned length=0;while(length<32&&m.r8(name+length))++length;
 if(length==32)throw std::domain_error("445 resource name bound");
 Inputs upper{};upper.arg[0]=name;auto text=crt_b83::fun_00781b14(m,upper);
 std::vector<std::uint8_t> bytes(length);for(unsigned k=0;k<length;++k)bytes[k]=m.r8(text+k);
 NameHashState state{};auto key=fun_00493da0(state,bytes.data(),length);
 auto manager=m.r32(0xa588e0);
 for(unsigned chain=0;chain<2&&manager;++chain){
  auto next=m.r32(manager+4);if(!next||!m.r32(manager+8))break;
  auto count=m.r32(manager+0x14),table=m.r32(manager+0x20);
  if(count>26)throw std::domain_error("445 cache record bound");
  while(count){
   auto middle=count/2,entry=table+middle*12,hash=m.r32(entry);
   if(global_b26::s32(hash)>global_b26::s32(key)){count=middle;continue;}
   if(hash==key){
    auto backing=m.r32(manager+0x24);
    if(!backing)throw std::domain_error("445 loaded backing required");
    return backing+m.r32(entry+4);
   }
   table=entry+12;count-=middle+1;
  }
  manager=next;
 }
 throw std::domain_error("445 all requested resources must be present");
}
}
unsigned fun_00495050(Memory&m,const Inputs&i){return lookup(m,i.cx,i.dx);}
}
