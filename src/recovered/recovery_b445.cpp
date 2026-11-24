#include "recovery_b445.hpp"
#include "crt_b83.hpp"
#include "name_hash.hpp"
#include <vector>
#include <stdexcept>
namespace ra2::recovered::recovery_b445 {
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
template<unsigned N>unsigned load(Memory&m,unsigned names,unsigned flags,const unsigned(&dest)[N]){
 unsigned result=0;for(unsigned j=0;j<N;++j){result=lookup(m,m.r32(names+4*j),flags+j);m.w32(dest[j],result);}return result;
}
}
unsigned fun_006e8d40(Memory&m,const Inputs&){
 constexpr unsigned dest[]{0xaa8b70,0xaa8af4,0xaa8b6c,0xaa8bbc,0xaa8b0c,0xaa8b8c,0xaa8b4c,0xaa8b2c,0xaa8b88,0xaa8b3c};
 return load(m,0x7e2014,0xaa8cbc,dest);
}
unsigned fun_006e9af0(Memory&m,const Inputs&){
 constexpr unsigned dest[]{0xaa8b00,0xaa8b7c,0xaa8b74,0xaa8b38,0xaa8b9c,0xaa8af8,0xaa8b40,0xaa8b48,0xaa8b90,0xaa8b08,0xaa8b54,0xaa8b34,0xaa8b30,0xaa8b58,0xaa8b64,0xaa8b68};
 return load(m,0x7e203c,0xaa8cc6,dest);
}
}
