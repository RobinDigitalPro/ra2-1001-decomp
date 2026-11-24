#include "recovery_b1191.hpp"
#include <stdexcept>
namespace ra2::recovered::b1191{
unsigned run(Memory&m,const Inputs&,Api&api,Observation&seen){const unsigned receiver=m.r32(0x83a6fcu);if(!receiver)throw std::domain_error("1191 positive actual DirectDraw receiver");alignas(4) Descriptor caps{};caps[0]=0x3cu;caps[1]=1u;seen.hresult=api.get_caps(receiver,caps,0u);++seen.provider_calls;seen.descriptor=caps;if(seen.hresult!=0u)throw std::domain_error("1191 bounded actual GetCaps S_OK");const unsigned flags=unsigned(caps[4])|(unsigned(caps[5])<<8u)|(unsigned(caps[6])<<16u)|(unsigned(caps[7])<<24u);unsigned result=0u;if(flags&0x40u)result=1u;if(flags&0x80u)result|=2u;if(flags&0x10000u)result|=4u;if(flags&0x8000000u)result|=8u;if(flags&0x4000000u)result|=16u;if(flags&0x2000000u)result|=32u;if(flags&0x200u)result|=64u;return result;}
}
