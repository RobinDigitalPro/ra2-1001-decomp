#include "recovery_b1325.hpp"
#include <stdexcept>

namespace ra2::recovered::b1325 {
namespace {
using U=std::uint32_t;
constexpr U kLock=0x411370u,kUnlock=0x4112f0u;
constexpr U kBpp=0x4113b0u,kPitch=0x4113c0u,kWidth=0x4112c0u;
constexpr U kVtable=0x785ef8u,kListCount=0x8249a0u,kList=0x824994u;
void need(bool ok,const char*what){if(!ok)throw std::domain_error(what);}

// Finite translation of the reached original 0x411230 -> BSurface +0x5c/+0x60
// route. 0x411370 increments lock depth, obtains bpp and row pitch through the
// constructor-observed vtable getters, and returns the exact pixel address;
// 0x4112f0 then decrements the same depth. This only supports the pinned
// in-bounds one-pixel call used below.
U lock_pixel_411230(Memory&m,U ring,U x,U y){
 const U base=m.r32(ring+0x10u),surface=m.r32(ring+0x14u),end=m.r32(ring+0x1cu),size=m.r32(ring+0x20u);
 need(surface&&m.r32(surface)==kVtable,"B1325 requires constructor-observed 0x785ef8 BSurface");
 need(m.r32(kVtable+0x5cu)==kLock&&m.r32(kVtable+0x60u)==kUnlock,"B1325 original lock/unlock targets");
 need(m.r32(kVtable+0x70u)==kBpp&&m.r32(kVtable+0x74u)==kPitch&&
      m.r32(kVtable+0x7cu)==kWidth,"B1325 original pixel-size getter chain");
 const U bpp=m.r32(surface+0x10u),width=m.r32(surface+4u),pixels=m.r32(surface+0x14u);
 need(bpp==2u&&width==1u&&m.r32(surface+8u)==1u&&pixels&&
      m.r32(surface+0x18u)==width*bpp,"B1325 bounded software surface dimensions");
 const U prior=m.r32(surface+0x0cu);m.w32(surface+0x0cu,prior+1u);
 // Original +0x70 returns bpp; +0x74 calls +0x7c (width) then multiplies bpp.
 const U pitch=m.r32(surface+4u)*m.r32(surface+0x10u);
 U locked_pixel=m.r32(surface+0x14u)+x*bpp+y*pitch;
 // Exact 0x4112f0 tail: EAX=[ECX+0xc]; DEC EAX; store; AL=1.
 m.w32(surface+0x0cu,m.r32(surface+0x0cu)-1u);
 need(m.r32(surface+0x0cu)==prior,"B1325 balanced original surface lock depth");
 U address=base+locked_pixel;
 if(address>=end)address-=size;
 need(address==pixels&&size>=2u,"B1325 one in-bounds pixel after original ring wrap check");
 return address;
}
struct Rect {U x,y,w,h;};
Rect intersect_one_pixel(Memory&m,U caller,U object){
 const U left=m.r32(object),top=m.r32(object+4u),w=m.r32(object+8u),h=m.r32(object+12u);
 const U x1=m.r32(caller),y1=m.r32(caller+4u),w1=m.r32(caller+8u),h1=m.r32(caller+12u);
 // 0x1FDF0's positive intersection is identity for these pinned equal rects.
 need(left==x1&&top==y1&&w==w1&&h==h1&&left==0u&&top==0u&&w==1u&&h==1u,
      "B1325 finite positive clip intersection inputs");
 return {left,top,w,h};
}
}

U fun_0041f5e0(Memory&m,const Inputs&i){
 // Frozen positive contract: one listed object, one caller clip, one warmed
 // one-pixel frame; no resource virtual call, heap, or palette initialization.
 need(m.r32(kListCount)==1u,"B1325 exactly one original list entry");
 const U list=m.r32(kList);need(list,"B1325 object list pointer");
 const U record=m.r32(list);need(record,"B1325 list record pointer");
 const U resource=m.r32(record+0x38u);need(resource,"B1325 warmed resource pointer");
 const U borrowed_object=m.r32(record+0x24u);need(borrowed_object,"B1325 borrowed object pointer");
 need(m.r16(resource+6u)==1u,"B1325 one warmed frame");
 const U frame=resource+8u;
 need(m.r16(frame)==0u&&m.r16(frame+2u)==0u&&m.r16(frame+4u)==1u&&m.r16(frame+6u)==1u,
      "B1325 pinned 1x1 source frame");
 const U payload_offset=m.r32(frame+0x14u),source=resource+payload_offset;
 need(payload_offset==0x100u&&m.r8(source)==0u,"B1325 pinned zero source byte");
 const U projection=m.r32(0x821cacu);
 need(projection&&m.r32(projection+0xb0u)==0u&&m.r32(projection+0xb4u)==0u&&
      m.r32(0x821970u)==0u&&m.r32(0x821974u)==0u,"B1325 zero-origin projection fixture");
 const Rect clip=intersect_one_pixel(m,i.cx,record+0x28u);
 (void)clip;
 const U ring=m.r32(0x8198f4u);
 need(ring&&m.r32(ring+0x28u)==2u,"B1325 one-row 16-bit output ring");
 const U destination=lock_pixel_411230(m,ring,0u,0u);
 const U old_word=m.r16(destination),source_byte=m.r8(source);
 need(old_word==7u,"B1325 pinned nonzero destination word");
 const U lookup=0x8249b8u+(source_byte<<8u)+old_word;
 const U mapped=m.r8(lookup);
 m.w16(destination,mapped);
 return 1u;
}
}
