#include "recovery_b290.hpp"
#include <cstdint>
#include <limits>
#include <stdexcept>
namespace ra2::recovered::recovery_b290 {
namespace {
void require(bool ok,const char* why){if(!ok)throw std::domain_error(why);}
std::uint32_t add(std::uint32_t a,std::uint32_t b){require(a<=std::numeric_limits<std::uint32_t>::max()-b,"B290 excludes address wrap");return a+b;}
std::uint32_t guest_bytes(Memory&m,std::uint32_t p,std::uint32_t limit){require(p,"B290 expects nonnull guest byte string");for(std::uint32_t n=0;n<limit;++n)if(m.r8(add(p,n))==0)return n;throw std::domain_error("B290 guest byte string lacks bounded NUL");}
std::uint32_t owned_bytes(Heap&h,std::uint32_t p,std::uint32_t limit){require(p,"B290 expects nonnull owned byte string");for(std::uint32_t n=0;n<limit;++n)if(h.r8(add(p,n))==0)return n;throw std::domain_error("B290 owned byte string lacks bounded NUL");}
std::uint16_t wide(Heap&h,std::uint32_t p){return static_cast<std::uint16_t>(h.r8(p)|(std::uint16_t(h.r8(add(p,1u)))<<8));}
void put_wide(Heap&h,std::uint32_t p,std::uint16_t v){h.w8(p,static_cast<std::uint8_t>(v));h.w8(add(p,1u),static_cast<std::uint8_t>(v>>8));}
std::uint32_t owned_wide_length(Heap&h,std::uint32_t p,std::uint32_t limit){require(p,"B290 expects nonnull owned wide string");for(std::uint32_t n=0;n<limit;++n)if(wide(h,add(p,n*2u))==0)return n;throw std::domain_error("B290 wide string lacks bounded NUL");}
void copy_bytes(Heap&h,std::uint32_t dst,std::uint32_t src,std::uint32_t n){for(std::uint32_t k=0;k<n;++k)h.w8(add(dst,k),h.r8(add(src,k)));}
void copy_bytes_nul(Heap&h,std::uint32_t dst,std::uint32_t src,std::uint32_t extent){for(std::uint32_t k=0;k<extent;++k){auto c=h.r8(add(src,k));h.w8(add(dst,k),c);if(!c)return;}throw std::domain_error("B290 byte copy exceeded bound");}
void copy_wide_nul(Heap&h,std::uint32_t dst,std::uint32_t src,std::uint32_t extent){for(std::uint32_t k=0;k<extent;++k){auto c=wide(h,add(src,k*2u));put_wide(h,add(dst,k*2u),c);if(!c)return;}throw std::domain_error("B290 wide copy exceeded bound");}
}

// Finite mode-0 route. Original 0x76e313 reads [0xb10530]; the fixture fixes it at zero.
std::uint32_t rva_0035a8d0(Memory&m,const Inputs&i,Heap&h){
 const auto object=i.cx, out=i.arg[0];
 require(object&&out&&object!=out&&(i.arithmetic_flags&0x400u)==0,"B290 requires distinct cells and DF clear");
 const auto old=m.r32(object);require(old,"B290 selects nonnull owned input");
 const auto n=owned_bytes(h,old,4097u);require(n>=1017u&&n<=1032u,"B290 input length must be 1017..1032 bytes");
 for(std::uint32_t k=0;k<n;++k){const auto c=h.r8(add(old,k));require(c>=0x20u&&c<=0x7eu,"B290 finite lowercase route uses printable ASCII");}
 require(m.r32(0x00b10530u)==0,"B290 requires original CRT mode flag zero");
 auto temp=h.allocate(n+1u);require(temp&&temp!=old,"B290 requires distinct temporary allocation");
 copy_bytes_nul(h,temp,old,n+1u);
 // Original loops over the temporary and calls 0x76e313 only for [a-z]. In mode 0
 // that actual leaf subtracts 0x20; all other bytes take no call.
 for(std::uint32_t k=0;k<n;++k){auto c=h.r8(add(temp,k));if(c>=0x61u&&c<=0x7au)h.w8(add(temp,k),static_cast<std::uint8_t>(c-0x20u));}
 m.w32(out,0);
 auto result=h.allocate(n+1u);require(result&&result!=temp&&result!=old,"B290 requires distinct result allocation");
 m.w32(out,result);copy_bytes_nul(h,result,temp,n+1u);
 require(h.release(temp)!=0,"B290 temp free must succeed");
 return out; // original root returns EBP=entry arg0; RET 4. Old owner remains live.
}

// Finite single-member set route. arg[0] points to a caller-owned holder for "A".
std::uint32_t rva_00359e60(Memory&m,const Inputs&i,Heap&h){
 const auto object=i.cx, set_holder=i.arg[0];
 require(object&&set_holder&&(i.arithmetic_flags&0x400u)==0,"B290 requires object, set holder and DF clear");
 const auto old=m.r32(object);require(old,"B290 selects nonnull owned input");
 const auto n=owned_bytes(h,old,4097u);require(n>=1017u&&n<=1032u,"B290 input length must be 1017..1032 bytes");
 const auto set=m.r32(set_holder);require(set,"B290 requires nonnull target-set string");
 require(guest_bytes(m,set,16u)==1u&&m.r8(set)=='A'&&h.r8(add(old,n-1u))=='A'&&h.r8(add(old,n-2u))!='A',"B290 route requires set A and exactly a one-byte matching suffix");
 // The actual 0x76fa70 calls search the set for source[n-1], find A, then fail
 // on source[n-2]. The resulting prefix length is n-1.
 const auto prefix=n-1u, bytes=prefix+1u;require(bytes>1016u,"B290 buffers must remain in ordinary-heap size class");
 auto temp=h.allocate(bytes);require(temp&&temp!=old,"B290 requires distinct prefix temp");
 copy_bytes(h,temp,old,prefix);h.w8(add(temp,prefix),0);
 require(h.release(old)!=0,"B290 old owner free must succeed");m.w32(object,0);
 auto result=h.allocate(bytes);require(result&&result!=temp,"B290 requires distinct result");m.w32(object,result);
 copy_bytes_nul(h,result,temp,bytes);
 return h.release(temp); // original root returns final HeapFree EAX unchanged; RET 4.
}

// UTF-16 companion to 0x35aa60: find unique final marker and remove it.
std::uint32_t rva_0035c5b0(Memory&m,const Inputs&i,Heap&h){
 const auto object=i.cx;require(object&&(i.arithmetic_flags&0x400u)==0,"B290 requires object and DF clear");
 const auto old=m.r32(object);require(old,"B290 selects nonnull owned wide input");
 const auto n=owned_wide_length(h,old,2049u);require(n>=1017u&&n<=1032u,"B290 wide length must be 1017..1032 units");
 const auto marker=static_cast<std::uint16_t>(i.arg[0]);require(marker!=0,"B290 marker must be nonzero");
 for(std::uint32_t k=0;k+1u<n;++k)require(wide(h,add(old,k*2u))!=marker,"B290 requires unique marker at last unit");
 require(wide(h,add(old,(n-1u)*2u))==marker,"B290 requires final marker");
 const auto bytes=n*2u;require(bytes>1016u,"B290 buffers must remain ordinary-heap sized");
 auto temp=h.allocate(bytes);require(temp&&temp!=old,"B290 requires distinct wide temp");
 for(std::uint32_t k=0;k+1u<n;++k)put_wide(h,add(temp,k*2u),wide(h,add(old,k*2u)));
 put_wide(h,add(temp,(n-1u)*2u),0);
 require(h.release(old)!=0,"B290 old wide owner free must succeed");m.w32(object,0);
 auto result=h.allocate(bytes);require(result&&result!=temp,"B290 requires distinct wide result");m.w32(object,result);
 copy_wide_nul(h,result,temp,n);
 const auto fr=h.release(temp);require(fr!=0,"B290 final temp free must succeed");
 return (fr&0xffffff00u)|1u; // final MOV AL,1; RET 4.
}
}
