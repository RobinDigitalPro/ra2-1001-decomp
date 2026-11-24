#include "recovered/recovery_b1488.hpp"
#include "recovered/recovery_b925.hpp"
#include "recovered/crt_b83.hpp"
#include <stdexcept>
namespace ra2::recovered::b1488 {
using U=std::uint32_t;
static void need(bool x,const char*s){if(!x)throw std::domain_error(s);}
U fun_00514700(Memory&m,const Inputs&i){
 need(i.cx==2&&m.r32(0xb10530)==0,"1488 exactargc2 ASCII route");
 const U argv=i.dx,option=m.r32(argv+4);need(m.r32(argv)!=0&&option!=0,"1488 actual nonnull argv");
 constexpr char selected[]="-noaudio";for(U k=0;k<8;++k){const U c=m.r8(option+k),lower=c>='A'&&c<='Z'?c+32:c;need(lower==U(selected[k]),"1488 eight-character positive option");}need(m.r8(option+8)==0,"1488 produced NUL at8");
 global_b26::Inputs child{};child.cx=0xa28570;recovery_b925::fun_00680a20(m,child);
 m.w8(0xa28953,0);
 U index=1;
 for(;index<i.cx;++index){
  const U current=m.r32(argv+4*index);child={};child.arg[0]=current;const U upper=crt_b83::fun_00781b14(m,child);need(upper==current,"1488 actual uppercase pointer");
  constexpr U literals[]{0x7c6f50,0x7c6f48,0x7c6f40,0x7c6f34};
  for(U k=0;k<4;++k){child={};child.arg[0]=literals[k];child.arg[1]=upper;const U equal=crt_b83::fun_0076d860(m,child);need((equal==0)==(k==3),"1488 actual ordered comparisons");}
  m.w32(0x7de560,0);
 }
 // Loop reloads index1, increments to2, then MOV AL,1 preserves high24=0.
 return (index&0xffffff00u)|1u;
}
}
