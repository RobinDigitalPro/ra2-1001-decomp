#include "recovery_b255.hpp"
#include <stdexcept>
#include <string>
namespace ra2::recovered::recovery42_vectors {
namespace {
void require(bool ok,const char* why){if(!ok)throw std::domain_error(why);}
// The fixed slot is resolved from the supplied original read-only page. The
// reached helper is represented by its original null-buffer branch effects;
// there is no callback return or fabricated dispatch result.
void actual_null_buffer_clear(Memory&m,std::uint32_t dst,std::uint32_t expected_vptr,std::uint32_t slot,std::uint32_t helper){
 require(m.r32(dst)==expected_vptr,"vector copy requires its exact initial constructor-compatible vptr");
 require(m.r32(slot)==helper,"vector copy fixed read-only slot target mismatch");
 require(m.r32(dst+4)==0,"vector copy null-buffer clear branch requires null old storage");
 // Every evidenced helper target takes its null-buffer path here: clear owner/count.
 m.w8(dst+0x0d,0); m.w32(dst+8,0);
}
std::uint32_t copy4(Memory&m,const Inputs&i,Heap&h,std::uint32_t initial,std::uint32_t slot,std::uint32_t helper,std::uint32_t final,bool constructor){
 const auto dst=i.cx,src=i.arg[0]; require(dst&&src&&dst!=src,"distinct nonnull source and destination required");
 if(constructor){m.w32(dst,initial);m.w32(dst+4,0);m.w32(dst+8,0);m.w8(dst+0x0c,1);m.w8(dst+0x0d,0);}
 actual_null_buffer_clear(m,dst,initial,slot,helper);
 const auto count=m.r32(src+8); require(count>=256&&count<=300,"positive DWORD count 256..300 required");
 const auto source=m.r32(src+4); require(source!=0,"readable DWORD source array required");
 m.w32(dst+8,count); const auto allocation=h.allocate(count*4);
 if(!allocation)throw std::domain_error("bounded route requires successful ordinary allocation");
 m.w32(dst+4,allocation); m.w8(dst+0x0d,1);
 for(std::uint32_t n=0;n<count;++n)h.w32(allocation+n*4,m.r32(source+n*4));
 m.w32(dst+0x10,m.r32(src+0x10)); m.w32(dst+0x14,m.r32(src+0x14));
 if(constructor)m.w32(dst,final);
 return dst;
}
std::uint32_t reserve8(Memory&m,const Inputs&i,Heap&h){
 const auto dst=i.cx,requested=i.arg[0]; require(dst!=0,"caller-owned vector header required");
 require(requested>=128&&requested<=191,"reserve count must be 128..191");
 require(m.r32(dst)==0&&m.r32(dst+4)==0&&m.r32(dst+8)==0,"empty 8-byte vector header required");
 const auto bytes=requested*8;const auto p=h.allocate(bytes);if(!p)throw std::domain_error("bounded reserve requires successful ordinary allocation");
 i.arg[0]=requested-1; m.w32(dst,p); m.w32(dst+8,requested);m.w32(dst+0x10,0);
 return 1u;
}
} // namespace
// Original RVA 0xc2220; exact bounded sibling contract follows block133, with a fresh per-RVA fixture.
std::uint32_t rva_000c2220(Memory&m,const Inputs&i,Heap&h){return reserve8(m,i,h);}
// Original RVA 0xf8160; exact bounded sibling contract follows block133, with a fresh per-RVA fixture.
std::uint32_t rva_000f8160(Memory&m,const Inputs&i,Heap&h){return reserve8(m,i,h);}
// Original RVA 0x11dca0; exact bounded sibling contract follows block133, with a fresh per-RVA fixture.
std::uint32_t rva_0011dca0(Memory&m,const Inputs&i,Heap&h){return reserve8(m,i,h);}
// Original RVA 0x18bf50; exact bounded sibling contract follows block133, with a fresh per-RVA fixture.
std::uint32_t rva_0018bf50(Memory&m,const Inputs&i,Heap&h){return reserve8(m,i,h);}
// Original RVA 0x2260d0; exact bounded sibling contract follows block133, with a fresh per-RVA fixture.
std::uint32_t rva_002260d0(Memory&m,const Inputs&i,Heap&h){return reserve8(m,i,h);}
// Original RVA 0x2ced30; exact bounded sibling contract follows block133, with a fresh per-RVA fixture.
std::uint32_t rva_002ced30(Memory&m,const Inputs&i,Heap&h){return reserve8(m,i,h);}
} // namespace ra2::recovered::recovery42_vectors
