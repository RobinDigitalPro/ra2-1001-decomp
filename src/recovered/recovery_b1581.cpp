#include "recovered/recovery_b1581.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b1581 {
namespace {using U=std::uint32_t;void need(bool ok){if(!ok)throw std::domain_error("B1581 finite ownerbookkeeping publiccontrols");}
// Actual44D930numericmode0, originalA283C4nonzero earlyguard; ignored return carrier.
void selected_mode_guard(Memory&m,U mode){need(mode==0&&m.r32(0xa283c4)==1);}
}
std::uint32_t run(Memory&m,const Inputs&i){const U self=i.cx;need(m.r32(self)==0x787bbcu&&m.r8(self+0x76)==0&&m.r8(self+0x5b4)==1);const U type=m.r32(self+0x418),owner=m.r32(self+0x1b4);need(type!=0&&owner!=0);need(m.r8(type+0x1366)==1&&m.r8(type+0x1365)==1&&m.r8(type+0x1358)==1&&m.r32(type+0x1400)==3);need(m.r32(owner+0x52cc)==3&&m.r32(owner+0x218)==10);need(m.r32(0xa283c4)==1&&m.r8(0xa285a8)==0);for(U k=0;k<8;++k)need(m.r32(self+0x49c+4*k)==0);for(U k=0;k<3;++k)need(m.r32(self+0x4c0+4*k)==0);
// OriginalXYZreads feed local-only integer preparation on this finite branch.
(void)m.r32(self+0x88);(void)m.r32(self+0x8c);(void)m.r32(self+0x90);
if(m.r8(type+0x1366)!=0){const U after=m.r32(owner+0x52cc)-1u;m.w32(owner+0x52cc,after);if(global_b26::s32(after)<0)m.w32(owner+0x52cc,0);}
if(m.r8(type+0x1365)!=0){const U after=m.r32(owner+0x218)-m.r32(type+0x1400);m.w32(owner+0x218,after);if(global_b26::s32(after)<0)m.w32(owner+0x218,0);}
selected_mode_guard(m,0u);need(m.r8(0xa285a8)==0);const U bl=1;need(m.r8(type+0x1358)==1);const U eax=m.r32(0xa283c4);return (eax&0xffffff00u)|bl; // Actual globalreload thenMOVAL,BL; full result is1, not masked comparison.
}
}
