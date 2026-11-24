#include "recovery_b188.hpp"
#include "crt_b83.hpp"
#include "name_hash.hpp"
#include <vector>
#include <stdexcept>
namespace ra2::recovered::recovery_b188 {
namespace {
std::uint32_t cached_lookup(Memory&m,unsigned name){
 if(!name||m.r32(0xb10530)!=0)throw std::domain_error("188 nonnull C-mode name required");
 unsigned length=0;while(length<32&&m.r8(name+length))++length;
 if(length==32)throw std::domain_error("188 bounded original resource name");
 Inputs upper{};upper.arg[0]=name;const auto text=crt_b83::fun_00781b14(m,upper);
 std::vector<std::uint8_t>bytes(length);for(unsigned n=0;n<length;++n)bytes[n]=m.r8(text+n);
 NameHashState hash{};const auto key=fun_00493da0(hash,bytes.data(),static_cast<std::int32_t>(length));
 auto manager=m.r32(0xa588e0);
 for(unsigned chain=0;chain<2&&manager;++chain){
  const auto next=m.r32(manager+4);if(!next)break;
  if(!m.r32(manager+8))break;
  auto count=m.r32(manager+0x14),table=m.r32(manager+0x20);
  if(count>12)throw std::domain_error("188 cache bound");
  while(count){const auto mid=count/2,entry=table+mid*12,h=m.r32(entry);
   if(global_b26::s32(h)>global_b26::s32(key)){count=mid;continue;}
   if(h==key){const auto backing=m.r32(manager+0x24);if(!backing)throw std::domain_error("188 loaded-cache route required");return backing+m.r32(entry+4);}
   table=entry+12;count-=mid+1;
  }
  manager=next;
 }
 throw std::domain_error("188 all three resources must be present");
}
unsigned load_resource(Memory&m,unsigned name,unsigned owned_flag){
 m.w8(owned_flag,0); // actual 95050 prefix; cache hit excludes all file/heap fallback
 return cached_lookup(m,name);
}
}
std::uint32_t fun_006e7830(Memory&m,const Inputs&i){
 const unsigned selector=(i.cx?6u:0u)+(m.r32(0x83a710)==640?0u:1u);
 const auto a=load_resource(m,m.r32(0x7e1fb4+4*selector),0xaa8ca4);m.w32(0xaa8bb0,a);
 const auto b=load_resource(m,m.r32(0x7e1fb4+4*(selector+2)),0xaa8ca5);m.w32(0xaa8b94,b);
 const auto c=load_resource(m,m.r32(0x7e1fb4+4*(selector+4)),0xaa8ca6);m.w32(0xaa8bac,c);return c;
}
}
