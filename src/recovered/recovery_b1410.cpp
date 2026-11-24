#include "recovery_b1410.hpp"
#include "recovered/map_b106.hpp"
#include "recovered/recovery_b107.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::global_b26 {
std::uint32_t fun_004f47b0(Memory&,const Inputs&);
std::uint32_t fun_00545490(Memory&,const Inputs&);
}
namespace ra2::recovered::b1410 {
namespace {
using U=std::uint32_t;
void need(bool v,const char*s){if(!v)throw std::domain_error(s);}
U action(Memory&m,Inputs&nested){
 const U self=nested.cx,owner=m.r32(self+0x1b4u);
 need(self&&nested.arg[0]==self&&m.r32(self)==0x78c2a0u&&m.r32(0x78c45cu)==0x6cc360u,
      "1410 actual installed receiver and status getter");
 need(m.r8(self+0x204u)==0u&&m.r32(self+0x38u)==0u&&m.r32(0xa288b0u)==1u&&
      m.r32(m.r32(0xa288a4u))==self&&m.r8(self+0x77u)==1u&&(nested.arg[1]&255u)==1u&&owner,
      "1410 same single-selected target finite action route");
 // Real6CC360 literal getter returns AL0. Original6C1CCD/6C1D07
 // clear two lowbytes in these nested copies, not the wrapper caller frame.
 nested.arg[0]&=0xffffff00u;nested.arg[1]&=0xffffff00u;
 global_b26::Inputs predicate{};predicate.cx=owner;
 need(global_b26::fun_004f47b0(m,predicate)==1u,"1410 genuine current-owner predicate");
 return 4u;
}
}
U fun_004cc340(Memory&memory,const Inputs&i){
 const U mode=memory.r32(0xa255c8u);
 need(mode>=1u&&mode<=4u,"1410 nonzero current mode");
 Inputs classifier=i;const U result=action(memory,classifier);
 need(memory.r32(i.arg[0])==0x78c2a0u&&memory.r32(0x78c2e8u)==0x5cd4d0u,
      "1410 actual installed world coordinate getter");
 // Exact produced local outputs: three getter words, three copied point
 // words, two heightquery words. The last is distinct from B106's own stack.
 constexpr U scratch=0x7a410000u;
 std::array<std::uint8_t,32> bytes{};leaf::Memory local(bytes.data(),scratch,U(bytes.size()));
 Memory m=memory;m.add(local);
 for(U k=0;k<3u;++k)local.w32(scratch+12u+4u*k,m.r32(i.arg[0]+0x88u+4u*k));
 for(U k=0;k<3u;++k)local.w32(scratch+4u*k,local.r32(scratch+12u+4u*k));
 const U x=local.r32(scratch),y=local.r32(scratch+4u);
 need(x>=1280u&&x<1536u&&y>=1280u&&y<1536u,"1410 genuine cell5,5 world coordinates");
 const U grid=m.r32(0x81a958u),index=2565u;
 need(grid&&m.r32(0x81a95cu)==0x40000u,"1410 complete declared Map vector capacity");
 const U cell=m.r32(grid+4u*index);
 need(cell&&m.r8(cell+0x11bu)==0u&&m.r8(cell+0x11cu)==0u&&
      (m.r32(cell+0x140u)&0x100u)==0u&&(m.r8(cell+0x12cu)&8u)==0u,
      "1410 flat occupied cell and even-height predicate");
 need((m.r8(0x838f70u)&7u)==7u&&m.r32(0x838f80u)==60u&&m.r32(0xa57848u)==60u&&
      m.r32(0x785728u)==0u&&m.r32(0x78572cu)==0x3fe00000u&&m.r32(0x7c3a04u)==0x0e7fu,
      "1410 original warm height and truncation constants");
 local.w32(scratch+24u,x);local.w32(scratch+28u,y); // actual557070 two-DWORD copy
 Inputs height{};height.cx=cell;height.arg[0]=scratch+24u;height.fp=i.fp;
 const U z=map_b106::fun_004702c0(m,height);
 need(z==0u,"1410 actual flat height result");local.w32(scratch+8u,z);
 global_b26::Inputs lookup{};lookup.cx=0x81a820u;lookup.arg[0]=scratch;
 need(global_b26::fun_00545490(m,lookup)==cell,"1410 actual Map world lookup");
 Inputs visible{};visible.cx=0x81a820u;visible.arg[0]=scratch;visible.fp=height.fp;
 need((recovery_b107::fun_00564f30(m,visible)&255u)==1u,"1410 actual even-quotient positive cell predicate");
 i.fp=visible.fp;
 // Original4CC3D2 loads nonzero mode, reaching4CC3F5 without final+80 provider.
 return result;
}
}
