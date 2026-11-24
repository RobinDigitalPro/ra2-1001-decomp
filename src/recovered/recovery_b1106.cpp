#include "recovered/recovery_b1106.hpp"
#include <stdexcept>
namespace ra2::recovered::b1106{
static void need(bool b){if(!b)throw std::domain_error("1106 requires positive real wide environment to ANSI owned-copy route");}
unsigned run(Memory&m,const Inputs&,Heap&h,State&,const Api&a){need(m.r32(0xb106a8u)==0u&&m.r32(0x817554u)==0u);auto wide=a.get();need(wide!=nullptr);m.w32(0xb106a8u,1u);unsigned n=0u;while(wide[n]){while(wide[n]){need(n<1022u);++n;}++n;}++n;need(n>=2u&&n<=1024u);const auto size=a.convert(0u,0u,wide,int(n),nullptr,0,nullptr,nullptr);need(size>0&&size<=1024);const auto out=h.allocate(unsigned(size));need(out);const auto converted=a.convert(0u,0u,wide,int(n),reinterpret_cast<char*>(std::uintptr_t(out)),size,nullptr,nullptr);need(converted==size);need(a.release(wide)!=FALSE);return out;}
}
