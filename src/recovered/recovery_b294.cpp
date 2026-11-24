#include "recovery_b294.hpp"
#include <cstdint>
#include <limits>
#include <stdexcept>
namespace ra2::recovered::recovery_b294 {
namespace {
void require(bool ok,const char*why){if(!ok)throw std::domain_error(why);}
std::uint32_t add(std::uint32_t a,std::uint32_t b){require(a<=std::numeric_limits<std::uint32_t>::max()-b,"B294 excludes address wrap");return a+b;}
std::uint16_t wide(Memory&m,std::uint32_t p){return static_cast<std::uint16_t>(m.r8(p)|(std::uint16_t(m.r8(add(p,1u)))<<8));}
std::uint16_t wide(Heap&h,std::uint32_t p){return static_cast<std::uint16_t>(h.r8(p)|(std::uint16_t(h.r8(add(p,1u)))<<8));}
void put(Heap&h,std::uint32_t p,std::uint16_t c){h.w8(p,c);h.w8(add(p,1u),c>>8);}
std::uint32_t length(Memory&m,std::uint32_t p,std::uint32_t limit){require(p,"B294 null guest wide pointer excluded");for(std::uint32_t n=0;n<limit;++n)if(!wide(m,add(p,n*2u)))return n;throw std::domain_error("B294 guest wide source lacks bounded NUL");}
std::uint32_t length(Heap&h,std::uint32_t p,std::uint32_t limit){require(p,"B294 null heap wide pointer excluded");for(std::uint32_t n=0;n<limit;++n)if(!wide(h,add(p,n*2u)))return n;throw std::domain_error("B294 heap wide source lacks bounded NUL");}
void copy_nul(Memory&m,Heap&h,std::uint32_t dst,std::uint32_t src,std::uint32_t units){for(std::uint32_t n=0;n<units;++n){const auto c=wide(m,add(src,n*2u));put(h,add(dst,n*2u),c);if(!c)return;}throw std::domain_error("B294 guest-to-heap copy exceeded bound");}
void copy_nul(Heap&h,std::uint32_t dst,std::uint32_t src,std::uint32_t units){for(std::uint32_t n=0;n<units;++n){const auto c=wide(h,add(src,n*2u));put(h,add(dst,n*2u),c);if(!c)return;}throw std::domain_error("B294 heap copy exceeded bound");}
std::uint16_t ascii_lower_mode0(std::uint16_t c){return c>='A'&&c<='Z'?static_cast<std::uint16_t>(c+0x20u):c;}
}

// Original 0x75be00 null-receiver branch. The nonnull/overlapping memmove
// branch and its 0x76ebd0 jump tables are deliberately outside this contract.
std::uint32_t rva_0035be00(Memory&m,const Inputs&i,Heap&h){
 const auto cell=i.cx,source=i.arg[0];require(cell&&source&&(i.arithmetic_flags&0x400u)==0,"B294 requires receiver cell, nonnull source and DF clear");
 require(m.r32(cell)==0,"B294 selects original null-receiver branch");
 m.w32(cell,0);const auto n=length(m,source,2049u);require(n>=1017u&&n<=1032u,"B294 source must be a long terminated UTF-16 string");
 const auto bytes=2u*(n+1u);const auto result=h.allocate(bytes);require(result,"B294 source result allocation must succeed");m.w32(cell,result);put(h,result,0);copy_nul(m,h,result,source,n+1u);
 return (result&0xffffff00u)|1u; // Original MOV AL,1; RET 8.
}

// Original 0x75c370 route with nonnull owned input and CRT mode flag zero.
std::uint32_t rva_0035c370(Memory&m,const Inputs&i,Heap&h){
 const auto object=i.cx,output_cell=i.arg[0];require(object&&output_cell&&object!=output_cell&&(i.arithmetic_flags&0x400u)==0,"B294 requires distinct object/output cells and DF clear");
 const auto old=m.r32(object);require(old,"B294 selects nonnull owned wide input");
 const auto n=length(h,old,2049u);require(n>=1017u&&n<=1032u,"B294 old UTF-16 string must be long and terminated");
 require(m.r32(0x00b10530u)==0,"B294 closes 0x76fb34 on its direct mode-zero branch");
 const auto bytes=2u*(n+1u);auto temp=h.allocate(bytes);require(temp&&temp!=old,"B294 temporary allocation must succeed and be distinct");copy_nul(h,temp,old,n+1u);
 for(std::uint32_t k=0;k<n;++k){const auto c=wide(h,add(temp,k*2u));put(h,add(temp,k*2u),ascii_lower_mode0(c));}
 m.w32(output_cell,0);auto result=h.allocate(bytes);require(result&&result!=temp&&result!=old,"B294 result allocation must succeed and be distinct");m.w32(output_cell,result);copy_nul(h,result,temp,n+1u);
 require(h.release(temp)!=0,"B294 temporary free must succeed");
 return output_cell; // Original EAX=entry arg0 address; RET 4. Old owner remains live.
}
}
