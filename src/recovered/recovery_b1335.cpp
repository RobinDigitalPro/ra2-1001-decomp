#include "recovery_b1335.hpp"
#include <algorithm>
#include <array>
#include <stdexcept>
namespace ra2::recovered::global_b26 {std::uint32_t fun_006eee20(Memory&,const Inputs&);}
namespace ra2::recovered::b1335 {
namespace {
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
// Original31550 calls31370 with width output in its private argument word
// and a null height output. The original4314F5/4314F7 skips that null write.
// This reached uppercase-only adapter extends B86's two-output fixture locally;
// no canonical B86 contract or controlled operation callback is substituted.
unsigned width_31550(Memory&m,unsigned receiver,const std::array<unsigned,16>&text){
 const auto descriptor=m.r32(receiver+4u),fallback=m.r32(receiver+8u);
 need(descriptor!=0u,"1335 original font descriptor");
 const auto table=m.r32(descriptor+0x18u),stride=m.r32(descriptor+0x14u),glyphs=m.r32(descriptor+0x1cu);
 unsigned current=0u,maximum=0u;
 for(const auto ch:text){
  if(!ch)break;
  need(ch=='W',"1335 original repeated W literal");
  const auto index=m.r16(table+2u*ch);
  auto glyph=index?glyphs+(index-1u)*stride:0u;
  if(!glyph)glyph=fallback;
  if(glyph){current+=m.r8(glyph)+m.r32(receiver+0x2cu);if(s32(current)>s32(maximum))maximum=current;}
 }
 return maximum;
}
}
std::uint32_t fun_00616e20(Memory&m,const Inputs&i){
 const auto resource=m.r32(i.cx+0x54u);
 need(m.r16(resource+6u)>0u,"1335 warm positive resource frame");
 need((i.arg[3]&255u)==0u,"1335 optional surface branch excluded");
 const auto frame_width=sx16(m.r16(resource+12u)),frame_height=sx16(m.r16(resource+14u));
 need(s32(frame_width)>0&&s32(frame_height)>0,"1335 positive signed frame dimensions");
 const auto font=m.r32(0x836d30u);need(font!=0u,"1335 actual97830 font getter");
 need(m.r8(0x7c6294u)=='W'&&m.r8(0x7c6295u)==0u,"1335 unchanged original W literal");
 std::array<unsigned,16> text{};
 i.arg[3]=15u;
 for(unsigned n=0;n<15u;++n){
  global_b26::Inputs convert{};convert.cx=0x7c6294u;
  const auto out=global_b26::fun_006eee20(m,convert);
  text[n]=m.r16(out);--i.arg[3];
 }
 const auto width=width_31550(m,font,text);
 m.w32(i.arg[0],width+frame_width+26u);
 auto height=std::max(frame_height+6u,m.r32(font+0x1cu));
 m.w32(i.arg[1],height);
 m.w32(i.arg[0],m.r32(i.arg[0])+10u);
 height+=4u;m.w32(i.arg[1],height);
 if(s32(i.arg[2])>1)m.w32(i.arg[1],height*i.arg[2]);
 return i.arg[1];
}
}
