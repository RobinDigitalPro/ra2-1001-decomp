#include "recovered/recovery_b1411.hpp"
#include "recovered/recovery_b652.hpp"
#include "platform/observed_mutex149.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1411 {
namespace {using U=std::uint32_t;
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
U warm_surfaces(Memory&m,U p){
 const U shape=m.r32(p+4u);need(shape&&m.r16(shape+2u)==1u&&m.r16(shape+4u)==1u,"1411 one-pixel shape dimensions");
 need(m.r32(0x785f74u)==0x4112c0u&&m.r32(0x785f78u)==0x4112d0u,"1411 actual width/height slots");
 for(U off:{0x44u,0x58u,0x6cu}){
  const U surface=m.r32(p+off);need(surface&&m.r32(surface)==0x785ef8u,"1411 genuine warm software surface");
  // Original75D890 six real getter calls,4112C0/4112D0, return these fields.
  need(std::int32_t(m.r32(surface+4u))>=1&&std::int32_t(m.r32(surface+8u))>=1,"1411 warm size checks fit");
 }
 need(m.r32(p+0x24u)!=0u,"1411 positive source surface");return 1u;
}
}
U fun_0075db90(Memory&memory,const Inputs&i){
 const U p=i.cx;need(warm_surfaces(memory,p)==1u,"1411 warm readiness");
 const U shape=memory.r32(p+4u),source=memory.r32(p+0x24u),dest=memory.r32(p+0x44u);
 need(memory.r32(source)==0x785ef8u&&memory.r32(dest)==0x785ef8u&&memory.r32(0x785f00u)==0x760840u,"1411 actual blit provider");
 need(memory.r32(p+8u)==0u&&memory.r16(shape+6u)==1u,"1411 real first frame");
 const auto handle=reinterpret_cast<HANDLE>(std::uintptr_t(memory.r32(0xb103f8u)));
 need(ra2::platform::mutex149::Mutex::wait(handle,10000u)==WAIT_OBJECT_0,"1411 real mutex acquired");
 const U frame=shape+8u;
 const U x=global_b26::sx16(memory.r16(frame)),y=global_b26::sx16(memory.r16(frame+2u));
 const U w=global_b26::sx16(memory.r16(frame+4u)),h=global_b26::sx16(memory.r16(frame+6u));
 const U left=memory.r32(p+0x14u)-memory.r32(p+0x3cu)+x;
 const U top=memory.r32(p+0x18u)-memory.r32(p+0x40u)+y;
 need(ra2::platform::mutex149::Mutex::release(handle)!=0,"1411 real mutex released");
 need(left==0u&&top==0u&&w==1u&&h==1u&&memory.r32(p+0x2cu)==0u&&memory.r32(p+0x30u)==0u,"1411 bounded positive capture geometry");
 for(U surface:{source,dest})need(memory.r32(surface+4u)==1u&&memory.r32(surface+8u)==1u&&memory.r32(surface+12u)==0u&&memory.r32(surface+16u)==2u&&memory.r32(surface+24u)==2u,"1411 RGB565 constructor layout");
 memory.w32(p+0x48u,left);memory.w32(p+0x4cu,top);memory.w32(p+0x50u,w);memory.w32(p+0x54u,h);
 // Two actual produced private rectangles; no caller/pre-entry padding escapes.
 constexpr U scratch=0x7a411000u;std::array<std::uint8_t,32> bytes{};
 leaf::Memory local(bytes.data(),scratch,U(bytes.size()));Memory m=memory;m.add(local);
 for(U k=0;k<4u;++k){local.w32(scratch+4u*k,k<2u?0u:1u);local.w32(scratch+16u+4u*k,k<2u?0u:1u);}
 Inputs child=i;child.cx=dest;child.arg[0]=scratch;child.arg[1]=source;child.arg[2]=scratch+16u;child.arg[3]=0u;child.arg[4]=1u;
 const U result=recovery_b652::fun_00760840(m,child);
 // B652 overwrites its own nested caller word1 with79AA9C; root outerwords unchanged.
 i.fp=child.fp;return result;
}
}
