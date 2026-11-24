#include "recovery_b292.hpp"
#include <cstdint>
#include <limits>
#include <stdexcept>
namespace ra2::recovered::recovery_b292 {
namespace {
void require(bool ok,const char* why){if(!ok)throw std::domain_error(why);}
std::uint32_t add(std::uint32_t a,std::uint32_t b){require(a<=std::numeric_limits<std::uint32_t>::max()-b,"B292 excludes address wrap");return a+b;}
std::uint8_t byte(Heap&h,std::uint32_t p){return static_cast<std::uint8_t>(h.r8(p));}
std::uint16_t wide(Heap&h,std::uint32_t p){return static_cast<std::uint16_t>(h.r8(p)|(std::uint16_t(h.r8(add(p,1u)))<<8));}
std::uint16_t wide(Memory&m,std::uint32_t p){return static_cast<std::uint16_t>(m.r8(p)|(std::uint16_t(m.r8(add(p,1u)))<<8));}
void put_wide(Heap&h,std::uint32_t p,std::uint16_t v){h.w8(p,static_cast<std::uint8_t>(v));h.w8(add(p,1u),static_cast<std::uint8_t>(v>>8));}
std::uint32_t len8(Heap&h,std::uint32_t p,std::uint32_t limit){require(p,"B292 byte pointer null");for(std::uint32_t n=0;n<limit;++n)if(!h.r8(add(p,n)))return n;throw std::domain_error("B292 byte string unbounded");}
std::uint32_t len16(Heap&h,std::uint32_t p,std::uint32_t limit){require(p,"B292 wide heap pointer null");for(std::uint32_t n=0;n<limit;++n)if(!wide(h,add(p,n*2u)))return n;throw std::domain_error("B292 wide heap string unbounded");}
std::uint32_t len16(Memory&m,std::uint32_t p,std::uint32_t limit){require(p,"B292 wide memory pointer null");for(std::uint32_t n=0;n<limit;++n)if(!wide(m,add(p,n*2u)))return n;throw std::domain_error("B292 wide memory string unbounded");}
void copy8(Heap&h,std::uint32_t dst,std::uint32_t src,std::uint32_t count){for(std::uint32_t k=0;k<count;++k)h.w8(add(dst,k),h.r8(add(src,k)));}
void copy8_nul(Heap&h,std::uint32_t dst,std::uint32_t src,std::uint32_t bound){for(std::uint32_t k=0;k<bound;++k){const auto c=byte(h,add(src,k));h.w8(add(dst,k),c);if(!c)return;}throw std::domain_error("B292 byte copy exceeded bound");}
void copy16_mem_to_heap(Heap&h,std::uint32_t dst,Memory&m,std::uint32_t src,std::uint32_t units){for(std::uint32_t k=0;k<units;++k){const auto c=wide(m,add(src,k*2u));put_wide(h,add(dst,k*2u),c);if(!c)return;}throw std::domain_error("B292 guest wide copy exceeded bound");}
void copy16_heap(Heap&h,std::uint32_t dst,std::uint32_t src,std::uint32_t units){for(std::uint32_t k=0;k<units;++k){const auto c=wide(h,add(src,k*2u));put_wide(h,add(dst,k*2u),c);if(!c)return;}throw std::domain_error("B292 heap wide copy exceeded bound");}
void concat_append_helper_35b5a0(Memory&m,Heap&h,std::uint32_t&cell,std::uint32_t source,std::uint32_t old_len,std::uint32_t source_len){
 const auto old=cell;const auto request=4u*(old_len+1u+source_len);auto replacement=h.allocate(request);require(replacement&&replacement!=old,"B292 nested 35b5a0 allocation must succeed and be distinct");
 cell=replacement;copy16_heap(h,replacement,old,old_len+1u);
 for(std::uint32_t k=0;k<source_len;++k)put_wide(h,add(replacement,(old_len+k)*2u),wide(m,add(source,k*2u)));
 put_wide(h,add(replacement,(old_len+source_len)*2u),0);
 require(h.release(old)!=0,"B292 nested 35b5a0 old wide owner free must succeed");
}
}

// Remove one byte from a long owned string. The native route is the start=100,
// span=1 branch, so the signed/clipping branches are excluded; arg0 still becomes the result pointer.
std::uint32_t rva_00359c50(Memory&m,const Inputs&i,Heap&h){
 const auto object=i.cx,start=i.arg[0],span=i.arg[1];require(object&&(i.arithmetic_flags&0x400u)==0,"B292 requires object and DF clear");
 const auto old=m.r32(object);require(old,"B292 selects nonnull owned string");
 const auto n=len8(h,old,4097u);require(n>=1017u&&n<=1032u,"B292 source length must be 1017..1032 bytes");
 require(start==100u&&span==1u&&start+span<n,"B292 bounded delete route requires start=100/span=1");
 for(std::uint32_t k=0;k<n;++k)require(h.r8(add(old,k))!=0,"B292 input excludes embedded NUL");
 const auto request=n-span+1u;require(request>1016u,"B292 output must be ordinary-heap-sized");
 auto result=h.allocate(request);require(result&&result!=old,"B292 requires distinct result owner");
 i.arg[0]=result; // 0x759c9b writes EDX through entry stack slot S+4 (arg0).
 // The original mutates both endpoint bytes before copying; for span 1 these are the same byte.
 h.w8(add(old,start),0);h.w8(add(old,start+span-1u),0);
 copy8_nul(h,result,old,start+1u);
 const auto tail_start=start+span,tail_count=n-tail_start;
 copy8(h,add(result,start),add(old,tail_start),tail_count);h.w8(add(result,start+tail_count),0);
 const auto fr=h.release(old);require(fr!=0,"B292 old string free must succeed");m.w32(object,result);
 return (fr&0xffffff00u)|1u; // root's MOV AL,1 and RET 8.
}

// Long-wide concatenation route through the actual nested 0x35b5a0 root.
std::uint32_t rva_0035ccc0(Memory&m,const Inputs&i,Heap&h){
 const auto output=i.cx, source=i.dx, holder=i.arg[0];require(output&&source&&holder&&(i.arithmetic_flags&0x400u)==0,"B292 requires output, source and target holder; DF clear");
 const auto n=len16(m,source,2049u),target=m.r32(holder);require(n>=1017u&&n<=1032u&&target,"B292 finite concat uses long nonnull source and target");
 const auto t=len16(m,target,2049u);require(t>=1017u&&t<=1032u,"B292 finite concat target length must be 1017..1032 units");
 const auto source_bytes=2u*(n+1u);auto first=h.allocate(source_bytes);require(first,"B292 first wide temporary allocation must succeed");
 copy16_mem_to_heap(h,first,m,source,n+1u);
 auto old=h.allocate(source_bytes);require(old&&old!=first,"B292 second wide temporary allocation must succeed");copy16_heap(h,old,first,n+1u);
 std::uint32_t nested=old;concat_append_helper_35b5a0(m,h,nested,target,n,t);
 const auto joined=n+t;const auto final_bytes=2u*(joined+1u);m.w32(output,0);auto result=h.allocate(final_bytes);require(result&&result!=nested&&result!=first,"B292 final result allocation must succeed and be distinct");
 m.w32(output,result);copy16_heap(h,result,nested,joined+1u);
 require(h.release(nested)!=0,"B292 appended temporary free must succeed");require(h.release(first)!=0,"B292 first temporary free must succeed");
 return output; // original root returns EBX=entry ECX; RET 4; caller words unchanged.
}
}
