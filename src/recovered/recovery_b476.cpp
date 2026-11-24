#include "recovered/recovery_b476.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b476 { namespace {
constexpr std::uint32_t kHash=0x006814e0u;
std::uint32_t hash_6814e0(const Memory&m,std::uint32_t node){
 const auto key=m.r32(node); if(!key)return 0; std::uint32_t len=0;
 while(m.r8(key+len)!=0u){if(++len>8u)throw std::domain_error("B476 key exceeds accepted 8-byte route");}
 std::uint32_t v=len; for(std::uint32_t i=0;i<len;++i){auto c=m.r8(key+i);auto s=(c&0x80u)?c|0xffffff00u:c;v+=s+i;v=(v<<8u)^(v>>24u);} return v;
}
std::uint32_t rehash(Memory&m,const Inputs&in,Heap&h,std::uint32_t link,bool grow){
 const auto t=in.cx, count=m.r32(t+8), shift=m.r32(t+0xc);
 if(m.r32(t+0x18)!=kHash)throw std::domain_error("B476 requires authentic 0x6814e0 callback input");
 const auto old=m.r32(t); if(!old)throw std::domain_error("B476 requires a live old bucket array");
 if(m.r8(t+0x14)==1)throw std::domain_error("B476 success path excludes status byte one");
 if(grow){if(count!=256||shift!=8)throw std::domain_error("B476 grow bounded to 256 buckets / shift 8");}
 else if(count!=512||shift!=9||count<=m.r32(t+0x30))throw std::domain_error("B476 shrink bounded to 512 buckets above high-water");
 const auto next_count=grow?count*2u:count/2u, next_shift=grow?shift+1u:shift-1u;
 m.w32(t+8,next_count);m.w32(t+0xc,next_shift);const auto nb=h.allocate(next_count*4u);if(!nb)throw std::domain_error("B476 excludes allocation failure");m.w32(t,nb);
 for(std::uint32_t i=0;i<next_count;++i)h.w32(nb+4u*i,0);
 for(std::uint32_t i=0;i<count;++i){auto node=h.r32(old+4u*i);while(node){const auto n=m.r32(node+link);const auto bucket=hash_6814e0(m,node)&(next_count-1u);const auto head=h.r32(nb+4u*bucket);h.w32(nb+4u*bucket,node);m.w32(node+link,head);node=n;}}
 return h.release(old);
}
}
std::uint32_t fun_00753570(Memory&m,const Inputs&i,Heap&h){return rehash(m,i,h,0x70,true);}
std::uint32_t fun_007539a0(Memory&m,const Inputs&i,Heap&h){return rehash(m,i,h,8,true);}
std::uint32_t fun_00753d70(Memory&m,const Inputs&i,Heap&h){return rehash(m,i,h,8,true);}
std::uint32_t fun_00754200(Memory&m,const Inputs&i,Heap&h){return rehash(m,i,h,0x110,true);}
std::uint32_t fun_007534c0(Memory&m,const Inputs&i,Heap&h){return rehash(m,i,h,0x70,false);}
std::uint32_t fun_007538f0(Memory&m,const Inputs&i,Heap&h){return rehash(m,i,h,8,false);}
std::uint32_t fun_00753cc0(Memory&m,const Inputs&i,Heap&h){return rehash(m,i,h,8,false);}
std::uint32_t fun_00754150(Memory&m,const Inputs&i,Heap&h){return rehash(m,i,h,0x110,false);}
}
