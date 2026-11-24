#include "recovery_b124.hpp"
#include "platform/current_crt_thread.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b124 {
// RVA37f427: initialized TLS output and nonnegative signed32 epoch route.
std::uint32_t fun_0077f427(Memory&m,const Inputs&i){
 const auto seconds=m.r32(i.arg[0]);const auto state=ra2::platform::current_crt_thread(m.r32(0x817778));
 if(seconds>0x7fffffffu)throw std::domain_error("negative epoch outside contracted route");
 const auto output=m.r32(state+0x40);if(!output)throw std::domain_error("lazy calendar allocation outside contracted route");
 auto rem=seconds%126230400u,year=70+4*(seconds/126230400u);bool leap=false;
 if(rem>=31536000u){rem-=31536000u;++year;if(rem>=31536000u){rem-=31536000u;++year;if(rem>=31622400u){rem-=31622400u;++year;}else leap=true;}}
 m.w32(output+0x14,year);const auto day=rem/86400u;m.w32(output+0x1c,day);rem%=86400u;
 const auto table=leap?0x818624u:0x818658u;unsigned month=0;while(month<12&&m.r32(table+4*(month+1))<day)++month;
 if(month>=12)throw std::domain_error("invalid original month table");m.w32(output+0x10,month);m.w32(output+0xc,day-m.r32(table+4*month));
 m.w32(output+0x18,(seconds/86400u+4)%7);m.w32(output+8,rem/3600u);rem%=3600u;m.w32(output+4,rem/60u);m.w32(output,rem%60u);m.w32(output+0x20,0);return output;
}
}
