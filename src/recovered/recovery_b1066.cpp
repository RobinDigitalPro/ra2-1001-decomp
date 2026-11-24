#include "recovered/recovery_b1066.hpp"
#include "recovered/preallocated_b66.hpp"
#include <stdexcept>
namespace ra2::recovered::b1066{
static void need(bool v){if(!v)throw std::domain_error("1066 outside positive caller-proven directional map queue");}
// Actual545500 bounded positive lookup, composed without a fabricated stack
// point pointer. Current cell coordinates and map indices agree by contract.
static unsigned neighbor(Memory&m,unsigned cell,unsigned direction){
 need(direction<8u);const auto packed=m.r32(cell+0x24u);
 const auto dx=static_cast<std::int16_t>(m.r16(0x839da0u+4u*direction));
 const auto dy=static_cast<std::int16_t>(m.r16(0x839da2u+4u*direction));
 const auto x=static_cast<std::int16_t>(packed)+dx,y=static_cast<std::int16_t>(packed>>16u)+dy;
 need(x>=0&&x<32&&y>=0&&y<32);const auto p=m.r32(m.r32(0x81a958u)+4u*unsigned(y*512+x));need(p!=0u);return p;
}
static unsigned enqueue(Memory&m,unsigned cell){Inputs q{};q.cx=0x81a820u;q.arg[0]=cell+0x24u;return global_b26::fun_00628bf0(m,q);}
static unsigned set_direction(Memory&m,const Inputs&i){const auto origin=i.cx,dir=i.arg[0];need((dir==0u||dir==2u)&&i.arg[1]==1u&&m.r32(0x81ba48u)==16u&&m.r32(0x81ba50u)<=3u);
 // S-38+40 = S+8, the caller's actual arg1 DWORD. Flag1 produces zero.
 i.arg[1]=0u;const auto z=dir==0u?0x800u:0u;const auto code=dir==0u?0u:9u;
 m.w8(origin+0x11eu,code);m.w32(origin+0x140u,(m.r32(origin+0x140u)&~0x11f80u)|0x11380u|z);enqueue(m,origin);
 const auto first=neighbor(m,origin,dir);m.w32(first+0x2cu,origin);m.w32(first+0x140u,(m.r32(first+0x140u)&~0x11f00u)|0x11300u|z);m.w8(first+0x11eu,code);enqueue(m,first);
 const auto second=neighbor(m,first,dir);m.w32(second+0x2cu,origin);m.w32(second+0x140u,(m.r32(second+0x140u)&~0x11f00u)|0x11100u|z);m.w8(second+0x11eu,code);enqueue(m,second);
 const auto third=neighbor(m,second,dir);m.w32(third+0x140u,m.r32(third+0x140u)|0x1000u);
 const auto opposite=neighbor(m,origin,(dir+4u)&7u);m.w32(opposite+0x2cu,origin);m.w32(opposite+0x140u,(m.r32(opposite+0x140u)&~0x11f00u)|0x10300u|z);m.w8(opposite+0x11eu,code);
 return enqueue(m,opposite);
}
std::uint32_t fun_00472ed0(Memory&m,const Inputs&i){return set_direction(m,i);}
std::uint32_t fun_00473300(Memory&m,const Inputs&i){return set_direction(m,i);}
}
