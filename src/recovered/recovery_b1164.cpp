#include "recovery_b1164.hpp"
#include <cstdint>
#include <stdexcept>
namespace ra2::recovered::b1164 {
static void need(bool x){if(!x)throw std::domain_error("1164 positive owned original108/268-byte value hash removal");}
static unsigned length(Heap&h,unsigned p){need(p);unsigned n=0u;while(n<80u&&h.r8(p+n))++n;need(n>=24u&&n<=43u);return n;}
static unsigned hash(Heap&h,unsigned p){const unsigned n=length(h,p);unsigned value=n;for(unsigned k=0;k<n;++k){value+=unsigned(int(std::int8_t(h.r8(p+k))))+k;value=(value<<8u)^(value>>24u);}return value;}
static bool equal(Heap&h,unsigned a,unsigned b){const auto n=length(h,a);if(n!=length(h,b))return false;for(unsigned k=0;k<n;++k)if(h.r8(a+k)!=h.r8(b+k))return false;return true;}
static void unsigned_load(State&f,unsigned n){const std::uint64_t value=n;ra2::platform::x87::Image host;asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\tfildq %[n]\n\tfnsave %[guest]\n\tfrstor %[host]":[host]"=m"(host.bytes),[guest]"+m"(f.image.bytes):[n]"m"(value):"memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");}
static unsigned owner(unsigned root){need(root==0x353220u||root==0x353ea0u);return root==0x353220u?0xb0ebe0u:0xb0e968u;}
unsigned run(unsigned root,Memory&m,const Inputs&i,Heap&h,State&f){const auto o=owner(root),bytes=root==0x353220u?108u:268u,nextoff=bytes+4u;need(i.cx==o&&m.r32(o+8u)==128u&&m.r32(o+12u)==7u&&m.r32(o+16u)==0u&&m.r8(o+20u)==0u&&m.r32(o+24u)==0x5bd730u&&m.r32(o+32u)==0x9999999au&&m.r32(o+36u)==0x3fc99999u&&m.r32(o+40u)==0x9999999au&&m.r32(o+44u)==0x3fe99999u&&m.r32(o+48u)==128u&&f.image.word(4u)==0u&&f.image.word(8u)==0xffffu);const auto count=m.r32(o+4u),table=m.r32(o),key=m.r32(i.arg[0]);need(count>=2u&&count<=6u&&table&&key);
 unsigned_load(f,count-1u);f.divide_integer32(128u);const auto fraction=f.pop32();const auto bucket=hash(h,key)&127u;unsigned previous=0u,node=h.r32(table+4u*bucket),visited=0u;while(node&&!equal(h,h.r32(node),key)){need(++visited<=6u);previous=node;node=h.r32(node+nextoff);}need(node);for(unsigned k=0;k<bytes;k+=4u)m.w32(i.arg[1]+k,h.r32(node+4u+k));const auto next=h.r32(node+nextoff);
 if(previous){i.arg[0]&=0xffffff00u;h.w32(previous+nextoff,next);m.w32(o+4u,count-1u);}need(h.release(h.r32(node))!=0u);h.w32(node,0u);need(h.release(node)!=0u);if(!previous)h.w32(table+4u*bucket,next);f.load32(fraction);f.compare_pop64(0x3fc999999999999aull);if(!previous)m.w32(o+4u,count-1u);need(f.status()&0x100u);if(previous)i.arg[0]=(i.arg[0]&0xffffff00u)|1u;return 1u;
}
unsigned cleanup(unsigned root,Memory&m,Heap&h){const auto o=owner(root),nextoff=(root==0x353220u?108u:268u)+4u;need(m.r32(o+8u)==128u&&m.r32(o+48u)==128u);const auto table=m.r32(o);for(unsigned bucket=0;bucket<128u;++bucket){auto p=h.r32(table+4u*bucket);unsigned visited=0u;while(p){need(++visited<=6u);const auto next=h.r32(p+nextoff);need(h.release(h.r32(p))!=0u);h.w32(p,0u);need(h.release(p)!=0u);p=next;}h.w32(table+4u*bucket,0u);}m.w32(o+4u,0u);return h.release(table);}
}
