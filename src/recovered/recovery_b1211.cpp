#include "recovery_b1211.hpp"
#include "platform/x87_state.hpp"
#include <stdexcept>
namespace ra2::recovered::b1211{
static void need(bool b){if(!b)throw std::domain_error("1211 genuine first-cell warm Clear cache publication");}
unsigned run(unsigned r,Memory&m,const Inputs&i,Heap&h){
 need(r==0x72140u&&i.arg[0]==0xffffffffu);const unsigned cell=i.cx;
 need(cell!=0xa57610u&&m.r32(cell)==0x788b04u&&m.r32(cell+0x24u)==0x00140001u&&m.r32(cell+0x44u)==0xffffffffu&&m.r32(cell+0x38u)==0xffffu);
 // Actual54CF40 signed/clamped cache index, reached twice by472140.
 const auto index=[&](){const int x=static_cast<short>(m.r16(cell+0x24u)),y=static_cast<short>(m.r16(cell+0x26u));int n=int((m.r32(0x81a914u)+m.r32(0x81a910u)+1u)*unsigned(y)+unsigned(x));if(n<0)return 0u;return n<int(m.r32(0x81a888u))?unsigned(n):m.r32(0x81a888u)-1u;};
 const auto a=m.r32(0x81a884u)+4u*index(),z=m.r32(0x81a88cu)+10u*index();
 // Overlay-1/tileFFFF selects4729D6 without consuming the height argument.
 m.w32(cell+0xecu,0u);m.w8(cell+0x11cu,0u);need(m.r8(m.r32(0x821b88u)+0x584u)==0u);
 // Actual478B40->557450 positive membership. The table is the genuine
 // 40000h-capacity Map vector's finite borrowed read-set, not a whole Map.
 const unsigned packed=m.r32(cell+0x24u);const int x=static_cast<short>(packed),y=static_cast<short>(packed>>16u);const auto table=m.r32(0x81a958u);need(m.r32(table+4u*unsigned(x+512*y))==cell&&m.r8(cell+0x11bu)==0u);
 const int w=int(m.r32(0x81a910u)),bx=int(m.r32(0x81a918u)),by=int(m.r32(0x81a91cu)),bw=int(m.r32(0x81a920u)),bh=int(m.r32(0x81a924u));need(x+y>w+2*by&&x+y<=w+2*(by+bh)+2&&x-y<2*(bx+bw)-w&&y-x<w-2*bx);
 need(m.r32(0x8391d8u)==0x3f800000u&&m.r32(0x787518u)==0x47ae147bu&&m.r32(0x78751cu)==0x3f847ae1u);
 namespace fp=ra2::platform::x87;fp::State s;s.image=fp::capture_host();s.load32(m.r32(0x8391d8u));s.compare_pop64(0x3f847ae147ae147bull);need((s.status()&0x4100u)==0u);fp::restore_host(s.image);
 need(m.r32(cell+0xe4u)==0u);m.w32(cell+0x4cu,0u);
 h.w8(a+1u,m.r8(cell+0x11bu));h.w8(a,m.r8(cell+0x4cu));h.w8(z+8u,m.r8(cell+0x11bu));return z;
}
}
