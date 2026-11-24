#include "recovery_b372.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b372 {
std::uint32_t fun_006d4450(Memory& m,const Inputs& i){
 const auto object=i.arg[0],out=i.arg[1];
 if(!out||m.r32(object)!=0x786678u||m.r32(0x7866a8u)!=0x41c320u)
  throw std::domain_error("372 requires original786678 size dispatch and writable output");
 // Actual41C320 returns BA8; 410180 adds4 and clears the high output word.
 m.w32(out,0xbacu);m.w32(out+4u,0u);
 constexpr unsigned offsets[]{0x3e0,0x3fc,0x418,0x434,0x450,0x46c,0x488,0x4a4,0x654,0x670,0x2f4,0x520,0x3bc,0x310,0x69c,0x6b8};
 for(auto off:offsets)m.w32(out,m.r32(out)+4u*m.r32(object+off)+4u);
 return 0;
}
}
