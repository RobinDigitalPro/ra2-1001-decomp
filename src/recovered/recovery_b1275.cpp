#include "recovery_b1275.hpp"
#include "platform/observed_keyboard1275.hpp"
#include <stdexcept>
namespace ra2::recovered::b1275 {
unsigned run(unsigned root,Memory&m,const Inputs&i,Observation&o){const unsigned key=i.cx&255u;if(root!=0x1f4410u||(i.cx&0x0f00u)!=0u||!((key>=0x30u&&key<=0x39u)||(key>=0x41u&&key<=0x5au)))throw std::domain_error("1275 positive single-key/no-modifier route");
 if(m.r32(0xb10e20u)!=0u||m.r32(0xb10530u)!=0u||m.r32(0xb10e24u)!=0u||m.r32(0x81776cu)!=1u||m.r32(0x817560u)!=0x81756au)throw std::domain_error("1275 original C-locale readset");
 for(unsigned j=0;j<256u;++j)if(m.r16(0x81756au+2u*j)&0x8000u)throw std::domain_error("1275 actual C-locale no-lead-byte table");
 if(m.r16(0x7d4ea0u)!='%'||m.r16(0x7d4ea2u)!='h'||m.r16(0x7d4ea4u)!='s'||m.r16(0x7d4ea6u)!=0u)throw std::domain_error("1275 literal wide percent-hs format");
 m.w16(i.dx,0u);char bytes[32];o.provider_buffer=provider1275::address(bytes);const unsigned scan=provider1275::Observer::map(key,0u);const unsigned n=unsigned(provider1275::Observer::name(LONG((scan<<16u)|0x02000001u),bytes,32));
 // Original inline strcat copies exactly n+1 produced bytes, including NUL;
 // private provider tails are not used. Selected %hs counts no lead bytes.
 for(unsigned j=0;j<n;++j){provider1275::Observer::enter();const unsigned wide=static_cast<unsigned char>(bytes[j]);provider1275::Observer::leave();m.w16(i.dx+2u*j,wide);++o.atomic_pairs;}
 m.w16(i.dx+2u*n,0u);o.label_bytes=n;if(m.r32(0xb10e24u)!=0u)throw std::domain_error("1275 actual original counter restored");return n;
}
}
