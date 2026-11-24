#include "recovered/recovery_b1579.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b1579 {
namespace {using U=std::uint32_t;void need(bool ok){if(!ok)throw std::domain_error("B1579 finite genuine78E540 state3 transition");}
U positive_query(Memory&m,U self,U argument){need(argument==2&&m.r32(self)==0x78e540u);const U type=m.r32(self+0x5a8);need(type!=0);const U configured=m.r32(type+0x504);need(configured==900);U result=configured+configured;if(global_b26::s32(result)<1792)result=1792;else if(global_b26::s32(result)>4096)result=4096;return result;}
}
std::uint32_t run(Memory&m,const Inputs&i){const U self=i.cx;need(m.r32(self)==0x78e540u&&m.r32(self+0xa8)==3&&m.r8(self+0x37f)==0);const U queried=positive_query(m,self,2u); // Root literal2, not any rootcallerword.
const U sign=global_b26::sar(queried,31);const U rounded=global_b26::sar(queried+(sign&255u),8);const U delay=rounded+6u;need(delay==13u); // Finite-input intermediate check; arithmetic was computed.
m.w8(self+0x37f,1);switch(m.r32(self+0xa8)){case 3: // Authentic16B table index3 selects original4C3604.
need(m.r32(self+0x494)!=0);m.w32(self+0xa8,0);return 1u;default:throw std::domain_error("B1579 unselected state");}
}
}
