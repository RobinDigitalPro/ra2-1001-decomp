#include "recovery_b394.hpp"
#include <algorithm>
#include <stdexcept>
namespace ra2::recovered::recovery_b394 {
std::uint32_t fun_0076bec1(Memory&m,const Inputs&i){
 const auto src=i.arg[0],dst=i.arg[1],count=i.arg[4],state=i.arg[5];
 if((i.arg[2]&65535u)!=16||(i.arg[3]&65535u)!=1||(src&3u)||!count||count>64||(count&15u))throw std::domain_error("B394 requires aligned mono16 whole16-byte blocks,16..64 output bytes");
 auto predicted=floating_b61::s32(m.r32(state));auto encoded=m.r16(state+4);
 if(predicted < -32768||predicted>32767||(encoded&31u)||encoded>88u*32u)throw std::domain_error("B394 initial predictor/index outside normal stream state");
 for(std::uint32_t n=0;n<count/2;++n){
  const auto byte=m.r8(src+n/2);encoded|=m.r8((n&1u?0x816e10u:0x816d10u)+byte);
  predicted+=floating_b61::s32(m.r32(0x814bb0u+2u*encoded));
  encoded=m.r16(0x8161f0u+encoded);
  predicted=std::max(-32768,std::min(32767,predicted));m.w16(dst+2u*n,static_cast<std::uint32_t>(predicted));
 }
 m.w32(state,static_cast<std::uint32_t>(predicted));m.w16(state+4,encoded);return count;
}
}
