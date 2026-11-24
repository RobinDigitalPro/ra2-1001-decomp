#include "recovered/numeric_b80.hpp"
#include <cstdint>
namespace ra2::recovered::numeric_b80 {
namespace extra_detail {
std::uint32_t trig(Memory&,ra2::platform::x87::State&,std::uint64_t,bool);
std::uint32_t integer(Memory&,ra2::platform::x87::State&);
}
namespace {
// Accepted b8850 integer algorithm, returning its stack-local sample directly.
std::uint32_t heading(Memory&m,std::uint32_t p){
 auto value=m.r32(p);const auto count=static_cast<std::int16_t>(m.r16(p+20));
 if(count<=0)return value;
 const auto start=m.r32(p+8),duration=m.r32(p+16),elapsed=m.r32(0xa2896c)-start;
 auto remaining=duration;
 if(start!=0xffffffffu){if(std::int32_t(elapsed)>=std::int32_t(duration))return value;remaining-=elapsed;}
 if(!remaining)return value;
 const auto delta=static_cast<std::int16_t>(m.r16(p)-m.r16(p+4));
 const auto magnitude=delta<0?std::uint32_t(-std::int32_t(delta)):std::uint32_t(delta);
 const auto quotient=static_cast<std::int16_t>(magnitude/std::uint32_t(count));
 if(quotient>0)value=(value&0xffff0000u)|std::uint16_t(value-std::uint32_t(std::int32_t(delta)/quotient)*remaining);
 return value;
}
}
std::uint32_t fun_00634fd0(Memory&m,const Inputs&i){
 using namespace floating_b61;using namespace extra_detail;auto&f=i.fp;
 const auto object=m.r32(i.cx+12),out=i.arg[0];
 f.load_integer32(i.arg[1]);const auto distance=f.pop64();
 f.load32(m.r32(i.cx+0x50));const auto phase=f.pop64();
 const auto x=m.r32(object+0x88),y=m.r32(object+0x8c),z=m.r32(object+0x90);
 trig(m,f,phase,true);f.multiply64(distance);const auto planar=integer(m,f);
 const auto sample=heading(m,object+0x2e0);
 f.load_integer32(global_b26::sx16(sample)-0x3fffu);f.multiply64(read64(m,0x786620));const auto angle=f.pop64();
 f.load_integer32(planar);const auto plane=f.pop64();
 f.load_integer32(y);const auto yd=f.pop64();
 trig(m,f,angle,false);f.multiply64(plane);f.reverse_subtract64(yd);const auto ny=integer(m,f);
 trig(m,f,angle,true);f.multiply64(plane);ra2::platform::x87_extended::add_integer32(f,x);const auto nx=integer(m,f);
 f.load32(m.r32(i.cx+0x50));const auto phase2=f.pop64();
 trig(m,f,phase2,false);f.multiply64(distance);ra2::platform::x87_extended::add_integer32(f,z);const auto nz=integer(m,f);
 m.w32(out,nx);m.w32(out+4,ny);m.w32(out+8,nz);return out;
}
}
