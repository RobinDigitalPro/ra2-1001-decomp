#include "recovered/recovery_b1328.hpp"
#include "recovered/floating_b39_memory.hpp"
#include "recovered/floating_b61_b.hpp"
#include "recovered/global_b28_memory.hpp"
#include "recovered/numeric_b71_matrix.hpp"
#include "recovered/leaf_memory.hpp"
#include <array>
#include <stdexcept>

namespace ra2::recovered::b1328 {
namespace {
using U=std::uint32_t;
using State=floating_b39::State;
constexpr U scratch_base=0x7d800000u,root_frame=scratch_base+0x8000u;
void need(bool value,const char*why){if(!value)throw std::domain_error(why);}
void absolute(ra2::platform::x87::State& state){
 // Exact FABS on the explicit guest image. The older platform adapter has no
 // FABS method; this local elementary operation never invokes original code.
 state.require_masked();ra2::platform::x87::Image host;
 asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\tfabs\n\tfnsave %[guest]\n\tfrstor %[host]"
  :[host]"=m"(host.bytes),[guest]"+m"(state.image.bytes):
  :"memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");
}
void integer_helper(Memory&m,global_b28::State&s,U rva){
 for(const auto&e:global_b28::entries_a())if(e.rva==rva){e.function(m,s);return;}
 for(const auto&e:global_b28::entries_b())if(e.rva==rva){e.function(m,s);return;}
 throw std::runtime_error("B1328 missing accepted B28 helper");
}
void copy(Memory&m,U dst,U src){for(U k=0;k<12u;++k)m.w32(dst+4u*k,m.r32(src+4u*k));}
bool disjoint(U a,U as,U b,U bs){return std::uint64_t(a)+as<=b||std::uint64_t(b)+bs<=a;}
U run(Memory&outer,const Inputs&i){
 const U object=i.arg[0],output=i.arg[1],key=i.arg[2];
 need(object&&output&&key,"B1328 nonnull borrowed inputs");
 const U descriptor=outer.r32(object+8u);
 need(descriptor&&outer.r32(object+0x2cu)==0u&&outer.r32(object+0x18u)==1u,
      "B1328 finite ratio-one selected-row route");
 need((outer.r32(descriptor+0x280u)&0x7fffffffu)==0u&&
      (outer.r32(descriptor+0x284u)&0x7fffffffu)==0u,
      "B1328 exact zero descriptor angles");
 need(outer.r32(descriptor+0x2e0u)==0x4000u&&outer.r16(descriptor+0x2f4u)==0u,
      "B1328 stable actual B8850 direction record");
 need(outer.r32(key)!=0xffffffffu,"B1328 positive packed-key update");
 need(disjoint(object,0x30u,descriptor,0x2f6u)&&disjoint(output,48u,object,0x30u)&&
      disjoint(output,48u,descriptor,0x2f6u)&&disjoint(key,4u,object,0x30u)&&
      disjoint(key,4u,descriptor,0x2f6u)&&disjoint(key,4u,output,48u),
      "B1328 disjoint borrowed object, descriptor, output and key");
 need(i.fp.image.word(8)==0xffffu&&(i.fp.image.word(4)&0x3800u)==0u,
      "B1328 empty incoming x87 stack with TOP zero");
 i.fp.require_masked();
 std::array<std::uint8_t,0x10000>bytes{};
 leaf::Memory local(bytes.data(),scratch_base,U(bytes.size()));Memory m=outer;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.arg=i.arg;
 s.arithmetic_flags=i.arithmetic_flags;s.fp=i.fp;
 // T = align_down(entryESP-4,8)-0x230. Preserve the actual root-local
 // destinations; the disjoint private mapping supplies their addresses only.
 m.w32(root_frame+0x18u,0u);
 s.fp.load64(floating_b39::read64(m,0x785708u));
 s.fp.compare_pop64(floating_b39::read64(m,0x785708u));
 need((s.fp.status()&0x4000u)!=0u,"B1328 original ratio comparison");
 for(U offset:{0x280u,0x284u}){
  s.fp.load32(m.r32(descriptor+offset));absolute(s.fp);
  s.fp.compare_pop64(floating_b39::read64(m,0x788170u));
  need((s.fp.status()&0x100u)!=0u,"B1328 original small-angle fast leg");
 }
 m.w32(key,m.r32(key)<<6u);
 m.w32(key,m.r32(key)+m.r32(object+0x18u));
 // 4A00DD/66BCFD pushes key, T+110, object. B71's arg0 scratch is
 // private to that nested frame and must not overwrite this root's arg0.
 Inputs nested=i;nested.fp=s.fp;nested.ax=root_frame+0x110u;
 nested.cx=m.r32(key)-1u;nested.dx=m.r32(key);nested.arg[0]=object;
 nested.arg[1]=root_frame+0x110u;nested.arg[2]=key;
 s.ax=numeric_b71::fun_0053b210(m,nested);s.fp=nested.fp;
 need(s.ax==root_frame+0x110u,"B1328 actual B71 output local");
 global_b28::State copied{};copied.cx=root_frame+0xe0u;copied.arg[0]=s.ax;
 integer_helper(m,copied,0x18cc10u);
 need(copied.ax==root_frame+0xe0u,"B1328 actual 58CC10 output local");
 // Complete accepted 58CE60 identity stores, also used by B71. This helper
 // performs no x87 operation and its RET consumes no arguments.
 for(U k=0;k<12u;++k)m.w32(root_frame+0x20u+4u*k,
                         (k==0u||k==5u||k==10u)?0x3f800000u:0u);
 m.w32(root_frame+0xcu,m.r32(object+0x2cu));
 // Actual accepted 70D920 performs twelve forward DWORD copies from the
 // initialized runtime affine row. Its memory adapter is exactly B26.
 global_b28::State row{};row.cx=root_frame+0x140u;row.dx=m.r32(object+0x18u);
 integer_helper(m,row,0x30d920u);
 need(row.ax==root_frame+0x140u,"B1328 actual selected-row copy");
 copy(m,root_frame+0x20u,row.ax);
 copy(m,root_frame+0xb0u,root_frame+0x20u);
 // 4A01DB pushes T+E0. With ESP=T-4, EDX=T+B0 and ECX=T+170.
 // B61 preserves the original x87 order, including the eight-live-register
 // maximum; its caller-arg0 overwrite belongs only to this nested frame.
 nested=i;nested.fp=s.fp;nested.cx=root_frame+0x170u;
 nested.dx=root_frame+0xb0u;nested.arg[0]=root_frame+0xe0u;
 const U composed=floating_b61::fun_0058df80(m,nested);s.fp=nested.fp;
 need(composed==root_frame+0x170u,"B1328 actual affine composition output");
 copy(m,root_frame+0x50u,composed);copy(m,output,root_frame+0x50u);
 i.fp=s.fp;return output;
}
}
U fun_0049fd70(Memory&m,const Inputs&i){return run(m,i);}
U fun_0066b990(Memory&m,const Inputs&i){return run(m,i);}
}
