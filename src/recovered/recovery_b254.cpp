#include "recovery_b254.hpp"
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
// Original RVA 0xfa910; initial vptr 0x78e158, slot 0x78e164->0x4fa6a0, final vptr 0x78e0b8.
std::uint32_t rva_000fa910(Memory&m,const Inputs&i,Heap&h){return copy4(m,i,h,0x78e158,0x78e164,0x4fa6a0,0x78e0b8,true);}
// Original RVA 0xfa9a0; initial vptr 0x78e118, slot 0x78e124->0x4f9f00, final vptr 0x78e178.
std::uint32_t rva_000fa9a0(Memory&m,const Inputs&i,Heap&h){return copy4(m,i,h,0x78e118,0x78e124,0x4f9f00,0x78e178,true);}
// Original RVA 0x10ac20; initial vptr 0x78eb5c, slot 0x78eb68->0x50a840, final vptr 0x78eb3c.
std::uint32_t rva_0010ac20(Memory&m,const Inputs&i,Heap&h){return copy4(m,i,h,0x78eb5c,0x78eb68,0x50a840,0x78eb3c,true);}
// Original RVA 0x24b610; initial vptr 0x793fc0, slot 0x793fcc->0x64a350, final vptr 0x793fa0.
std::uint32_t rva_0024b610(Memory&m,const Inputs&i,Heap&h){return copy4(m,i,h,0x793fc0,0x793fcc,0x64a350,0x793fa0,true);}
// Original RVA 0x24b6a0; initial vptr 0x793fe0, slot 0x793fec->0x64a740, final vptr 0x793f80.
std::uint32_t rva_0024b6a0(Memory&m,const Inputs&i,Heap&h){return copy4(m,i,h,0x793fe0,0x793fec,0x64a740,0x793f80,true);}
// Original RVA 0x24b7c0; initial vptr 0x78e118, slot 0x78e124->0x4f9f00, final vptr 0x78e0f8.
std::uint32_t rva_0024b7c0(Memory&m,const Inputs&i,Heap&h){return copy4(m,i,h,0x78e118,0x78e124,0x4f9f00,0x78e0f8,true);}
// Original RVA 0x24b850; initial vptr 0x78df08, slot 0x78df14->0x4f6600, final vptr 0x78df28.
std::uint32_t rva_0024b850(Memory&m,const Inputs&i,Heap&h){return copy4(m,i,h,0x78df08,0x78df14,0x4f6600,0x78df28,true);}
// Original RVA 0x24b970; initial vptr 0x78e158, slot 0x78e164->0x4fa6a0, final vptr 0x78e1b8.
std::uint32_t rva_0024b970(Memory&m,const Inputs&i,Heap&h){return copy4(m,i,h,0x78e158,0x78e164,0x4fa6a0,0x78e1b8,true);}
// Original RVA 0x2d4f50; initial vptr 0x7880ac, slot 0x7880b8->0x453c40, final vptr 0x797fec.
std::uint32_t rva_002d4f50(Memory&m,const Inputs&i,Heap&h){return copy4(m,i,h,0x7880ac,0x7880b8,0x453c40,0x797fec,true);}
// Original RVA 0x18a980; initial vptr 0x78eb5c, slot 0x78eb68->0x50a840, final vptr 0x78eb5c.
std::uint32_t rva_0018a980(Memory&m,const Inputs&i,Heap&h){return copy4(m,i,h,0x78eb5c,0x78eb68,0x50a840,0x78eb5c,false);}
// Original RVA 0x18aaa0; initial vptr 0x78eb5c, slot 0x78eb68->0x50a840, final vptr 0x78eb5c.
std::uint32_t rva_0018aaa0(Memory&m,const Inputs&i,Heap&h){return copy4(m,i,h,0x78eb5c,0x78eb68,0x50a840,0x78eb5c,false);}
// Original RVA 0x6ca20; initial vptr 0x7889d4, slot 0x7889e0->0x46cd60, final vptr 0x788a94.
std::uint32_t rva_0006ca20(Memory&m,const Inputs&i,Heap&h){return copy4(m,i,h,0x7889d4,0x7889e0,0x46cd60,0x788a94,true);}
// Original RVA 0x6c7f0; initial vptr 0x7889d4, slot 0x7889e0->0x46cd60, final vptr 0x7889f4.
std::uint32_t rva_0006c7f0(Memory&m,const Inputs&i,Heap&h){return copy4(m,i,h,0x7889d4,0x7889e0,0x46cd60,0x7889f4,true);}
// Original RVA 0x18bcd0; initial vptr 0x78df08, slot 0x78df14->0x4f6600, final vptr 0x790e2c.
std::uint32_t rva_0018bcd0(Memory&m,const Inputs&i,Heap&h){return copy4(m,i,h,0x78df08,0x78df14,0x4f6600,0x790e2c,true);}
} // namespace ra2::recovered::recovery42_vectors
