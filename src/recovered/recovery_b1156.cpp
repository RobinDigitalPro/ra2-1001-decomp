#include "recovery_b1156.hpp"
#include <stdexcept>
#include <cstdint>
namespace ra2::recovered::b1156{
unsigned run(unsigned root,Memory&m,const Inputs&i){
 const unsigned self=i.cx,data=m.r32(self+4u),capacity=m.r32(self+8u),source=i.arg[0],requested=i.arg[1];const bool was_closed=m.r8(self+24u)==0u;unsigned position=m.r32(self+16u),extent=m.r32(self+12u),mode=m.r32(self+20u);
 if(root!=0x22fb10u||m.r32(self)!=0x793bf4u||!data||!source||capacity<32u||capacity>1024u||!requested||requested>1400u||m.r8(self+25u)!=0u||position>=capacity)throw std::domain_error("1156 exact positive borrowed MemFile domain");
 if(std::uint64_t(source)<std::uint64_t(data)+capacity&&std::uint64_t(data)<std::uint64_t(source)+requested)throw std::domain_error("1156 disjoint borrowed source and destination");
 if(was_closed){if(mode!=1u||position!=0u||extent!=capacity)throw std::domain_error("1156 actual closed constructor joint state");position=0u;extent=0u;mode=2u;m.w32(self+16u,0u);m.w32(self+20u,mode);m.w8(self+24u,1u);m.w32(self+12u,0u);}
 else if(!((mode==2u&&extent==position)||(mode==3u&&extent==capacity)))throw std::domain_error("1156 actual open2/open3 plus seek joint state");
 const auto available=capacity-position;const auto count=requested<available?requested:available;for(unsigned n=0;n<count;++n)m.w8(data+position+n,m.r8(source+n));const auto next=position+count;m.w32(self+16u,next);if(next>extent)m.w32(self+12u,next);if(was_closed)m.w8(self+24u,0u);return count;
}
}
