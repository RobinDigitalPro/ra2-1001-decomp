#include "recovery_b295.hpp"
namespace ra2::recovered::recovery_b295 {
// Pinned two-element route: 76d6dc -> 76d7da -> original signed-DWORD
// comparator510750 and swap76d828. Larger partitions are outside this contract.
std::uint32_t fun_0076d686(Memory&m,const Inputs&i){
 const auto base=i.arg[0];
 if(i.arg[1]!=2||i.arg[2]!=4||i.arg[3]!=0x510750||!base||base>0xfffffff7u||i.entry_esp<0x100||(i.arithmetic_flags&0x400))
  throw std::domain_error("295 requires two dwords, exact comparator and valid entry stack");
 const auto a=m.r32(base),b=m.r32(base+4);
 if(a==b)throw std::domain_error("295 excludes equal elements");
 if(global_b26::s32(a)>global_b26::s32(b)){m.w32(base,b);m.w32(base+4,a);}
 // Root EBP=S-4; local pointers EBP-80h and EBP-F8h each decrement4.
 i.arg[0]=i.entry_esp-0x88;i.arg[1]=i.entry_esp-0x100;
 return base+4;
}
}
