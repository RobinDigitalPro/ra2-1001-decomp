#include "recovered/recovery_b1594.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1594 {namespace {void need(bool v){if(!v)throw std::domain_error("B1594 finite genuineAir initialization");}}
U fun_004bc670(Memory&m,const Inputs&i){const U self=i.cx;need(self);const U air=m.r32(self+12);need(air&&m.r32(air)==0x78612c);const U type=m.r32(air+0x5ac);need(type&&m.r32(type)==0x786678);struct Span{U at,size;};const std::array<Span,4> spans{{{self,0x60},{air,0x5b0},{type,0xba4},{0x786000,4096}}};for(U j=0;j<spans.size();++j){const auto&a=spans[j];need(a.at&&std::uint64_t(a.at)+a.size<=0x100000000ull);(void)m.r8(a.at);(void)m.r8(a.at+a.size-1);for(U k=0;k<j;++k)need(std::uint64_t(a.at)+a.size<=spans[k].at||std::uint64_t(spans[k].at)+spans[k].size<=a.at);}
need(m.r32(0x78612c+0x2c)==0x41b580&&m.r32(0x78612c+0x80)==0x6b6910&&m.r32(0x78612c+0x84)==0x41b600&&m.r32(0x786678+0xbc)==0x6d4b70&&m.r8(type+0xba2)==0);const U height=m.r32(type+0x558);need(height>0&&height<=0x10000);m.w8(self+0x5c,1);m.w8(self+0x51,0);m.w8(self+0x50,0);m.w32(self+0x38,height);return height&0xffffff00u;}
}
