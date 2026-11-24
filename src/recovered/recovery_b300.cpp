#include "recovery_b300.hpp"
#include <cstdint>
#include <limits>
#include <stdexcept>
namespace ra2::recovered::recovery_b300 {
namespace {
void require(bool ok,const char* why){if(!ok)throw std::domain_error(why);}
std::uint32_t add(std::uint32_t a,std::uint32_t b){require(a<=std::numeric_limits<std::uint32_t>::max()-b,"B300 excludes address wrap");return a+b;}
std::int32_t signed_word(std::uint32_t v){return static_cast<std::int32_t>(v);}
std::uint32_t byte_destroy(Heap& h,std::uint32_t cell){const auto p=h.r32(cell);const auto result=p?h.release(p):0u;h.w32(cell,0);return result;}
std::uint32_t wide_destroy(Heap& h,std::uint32_t cell){const auto p=h.r32(cell);const auto result=p?h.release(p):0u;h.w32(cell,0);return result;}
std::uint32_t receiver_cell_destroy(Memory& m,Heap& h,std::uint32_t cell){const auto p=m.r32(cell);const auto result=p?h.release(p):0u;m.w32(cell,0);return result;}
std::uint32_t positive_count(Memory& m,std::uint32_t object,std::uint32_t offset){const auto n=signed_word(m.r32(add(object,offset)));require(n==1||n==2,"B300 bounds original signed collection counts to one or two");return static_cast<std::uint32_t>(n);}
}
// Finite positive ownership route for original 0x5add90. Collection arrays
// and every reachable owner are real ordinary-heap blocks >=1017 bytes.
std::uint32_t rva_001add90(Memory& m,const Inputs& i,Heap& h){
 const auto object=i.cx;require(object&&(i.arithmetic_flags&0x400u)==0,"B300 requires receiver and DF clear");
 const auto wide_count=positive_count(m,object,0x4cu),byte_count=positive_count(m,object,0x64u);
 const auto wide_array=m.r32(add(object,0x40u)),byte_array=m.r32(add(object,0x58u));
 require(wide_array&&byte_array,"B300 requires both nonnull collection arrays");
 require(m.r8(add(object,0x49u))!=0&&m.r8(add(object,0x61u))!=0,"B300 selects owned-array free branches");
 // First collection: each element's +0xC wide-string owner, then element.
 for(std::uint32_t k=0;k<wide_count;++k){const auto element=h.r32(add(wide_array,k*4u));require(element,"B300 requires nonnull wide element objects");wide_destroy(h,add(element,0x0cu));h.release(element);}
 // Second collection: each element is a pointer cell owning a byte string.
 for(std::uint32_t k=0;k<byte_count;++k){const auto element=h.r32(add(byte_array,k*4u));require(element,"B300 requires nonnull byte element cells");byte_destroy(h,element);h.release(element);}
 // Array flags are set, so both pointer arrays are released and their cells cleared.
 const auto bytes=m.r32(add(object,0x58u));m.w32(add(object,0x54u),0x00791fdcu);if(bytes&&m.r8(add(object,0x61u))!=0){h.release(bytes);m.w32(add(object,0x58u),0);}
 m.w8(add(object,0x61u),0);m.w32(add(object,0x5cu),0);
 const auto wides=m.r32(add(object,0x40u));m.w32(add(object,0x3cu),0x00791fbcu);if(wides&&m.r8(add(object,0x49u))!=0){h.release(wides);m.w32(add(object,0x40u),0);}
 m.w8(add(object,0x49u),0);m.w32(add(object,0x44u),0);
 // The +0x28 owner is conditionally freed; original code clears its pointer cell either way.
 const auto optional=m.r32(add(object,0x28u));m.w32(add(object,0x24u),0x00791f9cu);if(optional&&m.r8(add(object,0x31u))!=0)h.release(optional);m.w32(add(object,0x28u),0);
 m.w8(add(object,0x31u),0);m.w32(add(object,0x2cu),0);
 // Eight embedded string cells, in original call order. The last call's full
 // HeapFree result survives the RET with no cleanup bytes.
 receiver_cell_destroy(m,h,add(object,0x20u));receiver_cell_destroy(m,h,add(object,0x1cu));receiver_cell_destroy(m,h,add(object,0x18u));
 receiver_cell_destroy(m,h,add(object,0x10u));receiver_cell_destroy(m,h,add(object,0x0cu));receiver_cell_destroy(m,h,add(object,0x08u));receiver_cell_destroy(m,h,add(object,0x04u));
 return receiver_cell_destroy(m,h,object);
}
}

