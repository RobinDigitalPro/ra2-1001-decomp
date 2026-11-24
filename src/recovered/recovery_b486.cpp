#include "recovery_b486.hpp"
#include "rng_b70.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b486 {
using U=std::uint32_t;
U fun_00405ad0(Memory&m,const Inputs&i){
 const auto sample=m.r32(i.cx+0xc0),spec=m.r32(sample+0x24);
 const auto low=m.r32(spec+0x58),high=m.r32(spec+0x5c);
 if(low<33||high<low||high>120||(m.r8(sample+0x18)&0x20)||(m.r8(spec+0x10)&0x88))throw std::domain_error("486 positive bounded delayed-sample scheduling");
 // Exact4790 route returns0 for a delayed lower bound and bit20clear.
 // Exact2790 then clears the pending pointer before the useful RNG update.
 m.w32(i.cx+0x168,0);
 floating_b61::Inputs c{};c.cx=0x821558;c.arg[0]=low;c.arg[1]=high;
 const auto delay=rng_b70::fun_0062fe40(m,c);m.w32(sample+0x13c,delay);m.w32(sample+0x148,0);return 0;
}
U fun_004e5a90(Memory&m,const Inputs&i){
 if(global_b26::s32(i.arg[1])>=0||m.r32(0xa1e0e4)==i.cx)throw std::domain_error("486 negative object index and nonlocal owner");
 U offset=0;switch(i.arg[0]){case 1:case 40:offset=(i.arg[2]&255)?0x52e4:0x52e0;break;case 2:case 3:offset=0x52d8;break;case 6:case 7:offset=0x52e8;break;case 15:case 16:offset=0x52dc;break;default:throw std::domain_error("486 selected nonempty timer category");}
 const auto timer=m.r32(i.cx+offset);if(!timer||m.r8(timer+0x6c))throw std::domain_error("486 inactive timer activation");
 m.w8(timer+0x6d,1);m.w8(timer+0x6c,1);m.w32(timer+0x28,m.r32(0xa2896c));m.w32(timer+0x2c,i.stack_minus8);m.w32(timer+0x30,0);m.w32(timer+0x34,0);return 0;
}
}
