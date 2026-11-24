#include "recovered/recovery_b1702.hpp"
#include <array>
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b1702::helpers {
namespace {
using U=std::uint32_t;
constexpr U self=0x18001000u, owner=0x18003000u, target=0x18005000u;
constexpr U component_vtable=0x78e1ecu, primary_vtable=0x798c88u;
struct Range { U base,size; };
void need(bool ok,const char* why){if(!ok)throw std::domain_error(why);}
std::uint64_t end(const Range&r){return std::uint64_t(r.base)+r.size;}
void covered(const Memory&m,const Range&r){
 need(r.size!=0&&end(r)<=0x100000000ULL,"FD5F0 finite mapped range wraps");
 // Read-only coverage check: discard values; never seed or normalize memory.
 for(U i=0;i<r.size;++i)(void)m.r8(r.base+i);
}
}

void require_selected_basis(const Memory&m,const State&s,const Frame&f){
 need(s.cx==self,"FD5F0 sample0 Self address");
 need(f.sp==f.entry_sp,"FD5F0 Root entry SP");
 need(f.entry_sp>=0x68u && std::uint64_t(f.entry_sp)+0x44u<=0x100000000ULL,
      "FD5F0 complete byte-derived stack window [R-68h,R+44h)");
 const Range stack{f.entry_sp-0x68u,0xacu};
 const std::array<Range,8> ranges{{
   {self,0x30u},{owner,0x4d4u},{target,4u},
   {component_vtable,0x14u},{primary_vtable+0x2cu,4u},
   {primary_vtable+0x48u,4u},{primary_vtable+0x1a0u,4u},stack
 }};
 for(std::size_t a=0;a<ranges.size();++a){
  need(end(ranges[a])<=0x100000000ULL,"FD5F0 selected range wraps");
  for(std::size_t b=a+1;b<ranges.size();++b)
   need(end(ranges[a])<=ranges[b].base||end(ranges[b])<=ranges[a].base,
        "FD5F0 public/stack or selected slot ranges alias");
  covered(m,ranges[a]);
 }
 // The supplied actual caller owns R and its complete 16-word argument area.
 // Only the actual return word is read by the selected guest route.
 need(m.r32(f.entry_sp)==f.outer_return,"FD5F0 actual outer return word");
 // Exact sample0 fields consumed by reached instructions; opaque/unread
 // secondary XYZ, direction[1] preimage, other caller words and registers stay
 // unconstrained. Shared page bytes/hash/protection are pinned separately.
 need(m.r32(self+4u)==component_vtable && m.r32(self+0xcu)==owner,
      "FD5F0 reached Self interface/owner links");
 need(m.r32(self+0x18u)==1024u && m.r32(self+0x1cu)==2048u &&
      m.r32(self+0x20u)==0u,"FD5F0 reached primary XYZ");
 need(m.r32(owner)==primary_vtable && m.r32(owner+0x494u)==target &&
      m.r32(owner+0x4d0u)==0u,"FD5F0 reached Owner table/target/base index");
 need(m.r32(owner+0x88u)==1280u && m.r32(owner+0x8cu)==2048u &&
      m.r32(owner+0x90u)==0u,"FD5F0 reached Owner XYZ");
 need(m.r32(target)==primary_vtable,"FD5F0 reached Target primary table");
 need(m.r32(component_vtable+0x10u)==0x4fbd80u &&
      m.r32(primary_vtable+0x2cu)==0x6fee90u &&
      m.r32(primary_vtable+0x48u)==0x5cd4d0u &&
      m.r32(primary_vtable+0x1a0u)==0x41b320u,
      "FD5F0 exact reached normal virtual slots");
 need(m.r32(0x00a28cc0u)==0u,"FD5F0 reached first X sentinel only");
 need(m.r32(0x007c3a04u)==0x00000e7fu && s.fp.image.word(0u)==0x037fu,
      "FD5F0 actual FTOL cache and entry x87 control word");
 // Stack coverage is [R-68h,R+44h); byte-derived writes cover only
 // [R-68h,R-20h). Existing private initial bytes remain untouched inputs.
 // Do not inspect guest flags, caller16, entry AX/DX, FP payload, LastError,
 // TEB/FS or host x87 state here; no state is modified by this guard.
}
} // namespace ra2::recovered::recovery_b1702::helpers
