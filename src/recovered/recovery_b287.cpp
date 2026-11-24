#include "recovery_b287.hpp"
#include <cstdint>
#include <limits>
#include <stdexcept>
namespace ra2::recovered::recovery_b287 {
namespace {
void require(bool ok,const char* why){if(!ok)throw std::domain_error(why);}
std::uint32_t add(std::uint32_t a,std::uint32_t b){require(a<=std::numeric_limits<std::uint32_t>::max()-b,"B287 excludes address wrap");return a+b;}
std::uint32_t guest_bytes(Memory&m,std::uint32_t p,std::uint32_t limit){require(p!=0,"B287 requires nonnull byte input");for(std::uint32_t n=0;n<limit;++n)if(m.r8(add(p,n))==0)return n;throw std::domain_error("B287 byte input lacks bounded NUL");}
std::uint32_t owned_bytes(Heap&h,std::uint32_t p,std::uint32_t limit){require(p!=0,"B287 requires nonnull owned byte input");for(std::uint32_t n=0;n<limit;++n)if(h.r8(add(p,n))==0)return n;throw std::domain_error("B287 owned byte string lacks bounded NUL");}
std::uint16_t wide_unit(Heap&h,std::uint32_t p){return static_cast<std::uint16_t>(h.r8(p)|(std::uint16_t(h.r8(add(p,1u)))<<8));}
void put_wide(Heap&h,std::uint32_t p,std::uint16_t v){h.w8(p,static_cast<std::uint8_t>(v));h.w8(add(p,1u),static_cast<std::uint8_t>(v>>8));}
std::uint32_t wide_length(Heap&h,std::uint32_t p,std::uint32_t limit){require(p!=0,"B287 requires nonnull UTF-16 temp");for(std::uint32_t n=0;n<limit;++n)if(wide_unit(h,add(p,n*2u))==0)return n;throw std::domain_error("B287 UTF-16 temp lacks bounded NUL");}
void copy_wide_nul(Heap&h,std::uint32_t dst,std::uint32_t src,std::uint32_t units){for(std::uint32_t n=0;n<units;++n){const auto v=wide_unit(h,add(src,n*2u));put_wide(h,add(dst,n*2u),v);if(v==0)return;}throw std::domain_error("B287 wide copy exceeded bound");}
void copy_bytes_exact(Heap&h,std::uint32_t dst,std::uint32_t src,std::uint32_t count){for(std::uint32_t n=0;n<count;++n)h.w8(add(dst,n),h.r8(add(src,n)));}
void copy_bytes_nul(Heap&h,std::uint32_t dst,std::uint32_t src,std::uint32_t extent){for(std::uint32_t n=0;n<extent;++n){const auto c=h.r8(add(src,n));h.w8(add(dst,n),c);if(c==0)return;}throw std::domain_error("B287 byte copy exceeded NUL bound");}
}

std::uint32_t rva_0035cb00(Memory&m,const Inputs&i,Heap&h){
    const auto output=i.cx, holder=i.dx;
    require(output&&holder&&output!=holder&&(i.arithmetic_flags&0x400u)==0,"B287 wide conversion needs distinct cells and DF clear");
    require(m.r32(output)==0,"B287 finite route requires empty output cell");
    const auto source=m.r32(holder);require(source!=0&&source!=output&&source!=holder,"B287 selects a distinct nonnull source region");
    const auto length=guest_bytes(m,source,4097u);
    require(length>=1017u&&length<=1032u,"B287 source length must be 1017..1032 bytes");
    for(std::uint32_t n=0;n<length;++n)require(m.r8(add(source,n))!=0,"B287 converter domain excludes embedded NUL");
    const auto bytes=add(length*2u,2u);require(bytes>1016u,"B287 buffers must be ordinary-heap sized");
    auto converted=h.allocate(bytes);require(converted!=0,"B287 requires successful first allocation");
    // Exact accepted 0x2eed60 conversion effect; the real native helper runs in the differential.
    for(std::uint32_t n=0;n<length;++n)put_wide(h,add(converted,n*2u),m.r8(add(source,n)));
    put_wide(h,add(converted,length*2u),0);
    auto duplicate=h.allocate(bytes);require(duplicate&&duplicate!=converted,"B287 requires distinct second allocation");
    put_wide(h,duplicate,0);
    copy_wide_nul(h,duplicate,converted,length+1u);
    require(h.release(converted)!=0,"B287 first temporary free must succeed");
    m.w32(output,0);
    auto result=h.allocate(bytes);require(result&&result!=duplicate,"B287 requires distinct published result allocation");
    m.w32(output,result);
    copy_wide_nul(h,result,duplicate,length+1u);
    require(h.release(duplicate)!=0,"B287 second temporary free must succeed");
    return output;
}

std::uint32_t rva_0035aa60(Memory&m,const Inputs&i,Heap&h){
    const auto object=i.cx;require(object&&(i.arithmetic_flags&0x400u)==0,"B287 byte truncation needs object and DF clear");
    const auto old=m.r32(object);require(old!=0,"B287 selects nonnull current string");
    const auto length=owned_bytes(h,old,4097u);require(length>=1017u&&length<=1032u,"B287 current string length must be 1017..1032 bytes");
    const auto needle=static_cast<std::uint8_t>(i.arg[0]);require(needle!=0,"B287 search byte must be nonzero");
    std::uint32_t position=0;while(position<length&&h.r8(add(old,position))!=needle)++position;
    require(position<length,"B287 finite route requires a match before NUL");
    require(position+1u>1016u,"B287 temporary/final buffers must be ordinary-heap sized");
    const auto bytes=add(position,1u);
    auto temporary=h.allocate(bytes);require(temporary&&temporary!=old,"B287 requires distinct temporary allocation");
    h.w8(temporary,0);
    // Exact accepted 0x36dd10 bounded-copy effect on this no-embedded-NUL prefix.
    copy_bytes_exact(h,temporary,old,position);
    h.w8(add(temporary,position),0);
    require(h.release(old)!=0,"B287 old owned string free must succeed");
    m.w32(object,0);
    const auto temp_length=owned_bytes(h,temporary,bytes);
    require(temp_length==position,"B287 temporary must be exactly the prefix before the matched byte");
    auto result=h.allocate(bytes);require(result&&result!=temporary,"B287 requires distinct final allocation");
    m.w32(object,result);
    copy_bytes_nul(h,result,temporary,bytes);
    const auto free_result=h.release(temporary);
    require(free_result!=0,"B287 final temporary free must succeed");
    return (free_result&0xffffff00u)|1u; // root's final MOV AL,1
}
}

