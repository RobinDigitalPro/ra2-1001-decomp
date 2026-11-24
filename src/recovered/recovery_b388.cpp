#include "recovery_b388.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::recovery_b388 {
namespace {
using U=std::uint32_t;
struct Parsed {U value,end,flags;};
// Original 7704cf/7774e0 decimal nonoverflow route. ASCII classification is
// read from the original C-locale table; no platform classification callback.
template<class Read> Parsed decimal(Memory&m,Read read,U start,U flags){
 U at=start,v=0;auto c=read(at);
 auto classify=[&](U ch,U mask){if(ch>=256)throw std::domain_error("B388 ASCII only");return m.r16(m.r32(0x817564u)+ch*2u)&mask;};
 while(classify(c,8)){at+=2;c=read(at);}
 if(c=='-'){flags|=2;at+=2;c=read(at);}else if(c=='+'){at+=2;c=read(at);}
 bool any=false;
 while(classify(c,4)){
  const U digit=c-'0';if(digit>=10)break;
  if(v>214748364u||(v==214748364u&&digit>7))throw std::domain_error("B388 excludes overflow");
  v=v*10+digit;any=true;flags|=8;at+=2;c=read(at);
 }
 if(!any||classify(c,0x103))throw std::domain_error("B388 requires decimal digits and nonalphanumeric terminator");
 return {(flags&2)?0u-v:v,at,flags};
}
}
std::uint32_t fun_007704cf(Memory&m,const Inputs&i){
 if(i.arg[2]!=10||(i.arg[3]&~1u))throw std::domain_error("B388 decimal, flags0/1 only");
 auto p=decimal(m,[&](U at){return m.r16(at);},i.arg[0],i.arg[3]);
 i.arg[2]=0xffffffffu/10u;i.arg[3]=p.flags;
 if(i.arg[1])m.w32(i.arg[1],p.end);
 return p.value;
}
std::uint32_t fun_00691400(Memory&m,const Inputs&i){
 // 76ef62 copies at most12 UTF16 units into private stack storage. The
 // consumer overwrites unit11 with NUL, then splits at three colons.
 std::array<U,12> text{};bool nul=false;
 for(U k=0;k<12;++k){if(!nul){text[k]=m.r16(i.cx+2*k);nul=!text[k];}}
 text[11]=0;std::array<U,4> part{};U begin=0;
 for(U k=0;k<4;++k){
  U end=begin;if(k<3){while(end<11&&text[end]!=':'&&text[end])++end;if(end==11||text[end]!=':')throw std::domain_error("B388 requires HH:MM:SS:FF");text[end]=0;}
  auto p=decimal(m,[&](U at){if(at/2>=12)throw std::domain_error("B388 time span");return text[at/2];},begin*2,1);
  part[k]=p.value;begin=end+1;
 }
 const U fractional=U((std::uint64_t(part[3]*60u)*0x51eb851full)>>37);
 return ((part[0]*60u+part[1])*60u+part[2])*60u+fractional;
}
}
