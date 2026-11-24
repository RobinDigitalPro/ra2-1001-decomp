#include "recovery_b1283.hpp"
#include "recovery_b349.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b1283 {
namespace {
void need(bool ok,const char*message){if(!ok)throw std::domain_error(message);}
std::int32_t signed_word(unsigned x){return global_b26::s32(x);}
}
std::uint32_t fun_0069f6d0(Memory&m,const Inputs&i){
 need(m.r32(0x83a8e8u)==1u,"1283 one published candidate");
 const auto object=m.r32(m.r32(0x83a8dcu));
 const auto vt=m.r32(object);
 need(vt==0x787bbcu&&m.r32(vt+0x2cu)==0x453890u&&
      m.r32(vt+0xa8u)==0x4538c0u&&m.r32(vt+0x124u)==0x450ac0u,
      "1283 exact kind6 and rectangle virtual targets");
 need(m.r8(object+0x75u)!=0u,"1283 positive dirty candidate");
 // 0x4538C0 writes x-0x80, y-0x80, z to the 0x450AC0 local.
 const auto x=m.r32(object+0x88u)-0x80u;
 const auto y=m.r32(object+0x8cu)-0x80u;
 const auto z=m.r32(object+0x90u);
 const auto view=m.r32(0x821cacu);
 need(view!=0u&&x==m.r32(object+0x51cu)&&
      y==m.r32(object+0x520u)&&z==m.r32(object+0x524u)&&
      m.r32(view+0xb0u)==m.r32(object+0x528u)&&
      m.r32(view+0xb4u)==m.r32(object+0x52cu),
      "1283 exact +124 fast cached rectangle branch");
 // 0x450AC0 returns its already published four-word rectangle.
 const auto rx=m.r32(object+0x50cu)+m.r32(0x821970u);
 const auto ry=m.r32(object+0x510u)+m.r32(0x821974u);
 const auto width=m.r32(object+0x514u),height=m.r32(object+0x518u);
 need(width>0u&&width<=1024u&&height>0u&&height<=1024u,
      "1283 positive bounded rectangle extent");
 need(signed_word(i.arg[0])<signed_word(rx+width)&&
      signed_word(i.arg[1])<signed_word(ry+height)&&
      signed_word(i.arg[0]+i.arg[2])>signed_word(rx)&&
      signed_word(i.arg[1]+i.arg[3])>signed_word(ry),
      "1283 positive strict rectangle intersection");
 global_b26::Inputs append{};
 append.arg[0]=m.r32(object+0x50cu);append.arg[1]=m.r32(object+0x510u);append.arg[2]=width;
 append.arg[3]=height;append.arg[4]=0u;
 // Physical stack proof: +124 writes z at its ESP+0x30 (VA 0x450AF6).
 // That address becomes the accepted append's entry ESP-4. It is produced
 // by original code, never supplied from the root fixture's stack_minus8.
 append.stack_minus8=z;
 (void)recovery_b349::fun_00698660(m,append);
 m.w8(object+0x75u,0u);
 return 1u; // One candidate scanned; original RET 0x10.
}
}
