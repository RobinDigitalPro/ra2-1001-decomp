#include "recovery_b1287.hpp"
#include "leaf_b56_c.hpp"
#include "leaf_containers.hpp"
#include "numeric_b80.hpp"
#include <array>
#include <initializer_list>
#include <stdexcept>
namespace ra2::recovered::recovery_b1287 {
namespace {
void need(bool ok,const char*why){if(!ok)throw std::domain_error(why);}
void put4(leaf::Memory&stack,std::uint32_t to,Memory&m,std::uint32_t from){
 for(unsigned k=0;k<4u;++k)stack.w32(to+4u*k,m.r32(from+4u*k));
}
bool eq4(const leaf::Memory&stack,std::uint32_t at,
         std::uint32_t x,std::uint32_t y,std::uint32_t w,std::uint32_t h){
 return stack.r32(at)==x&&stack.r32(at+4u)==y&&
        stack.r32(at+8u)==w&&stack.r32(at+12u)==h;
}
std::uint32_t one(Memory&m,const Inputs&i){
 need(m.r32(0x83a8e8u)==1u,"1287 one published candidate");
 const auto object=m.r32(m.r32(0x83a8dcu));
 const auto vt=m.r32(object);
 need(vt==0x787bbcu&&m.r32(vt+0x2cu)==0x453890u&&
      m.r32(vt+0xa8u)==0x4538c0u&&m.r32(vt+0x124u)==0x450ac0u&&
      m.r32(vt+0xfcu)==0x43a080u,"1287 genuine kind6 virtual closure");
 need(m.r8(object+0x5b7u)==0u&&m.r8(0xa28953u)==1u,
      "1287 callback mode and kind6 gate");
 need(m.r8(object+0x75u)!=0u,"1287 observable dirty-state consumption");
 const auto p=i.arg[1],q=i.arg[2];
 std::array<std::uint8_t,0x100> private_bytes{};
 constexpr std::uint32_t base=0xf1000000u;
 leaf::Memory stack(private_bytes.data(),base,private_bytes.size());
 put4(stack,base,m,p);put4(stack,base+0x10u,m,q);
 leaf::Inputs clip{};clip.cx=base+0x20u;clip.dx=base;clip.arg[0]=base+0x10u;
 (void)leaf::fun_0041fdf0(stack,clip);
 need(eq4(stack,base+0x20u,120u,238u,60u,30u),
      "1287 genuine positive caller-rectangle clip");
 // +A8 produces the exact coordinates compared by the +124 fast cache.
 const auto x=m.r32(object+0x88u)-0x80u;
 const auto y=m.r32(object+0x8cu)-0x80u;
 const auto z=m.r32(object+0x90u);
 const auto view=m.r32(0x821cacu);
 need(view!=0u&&x==m.r32(object+0x51cu)&&
      y==m.r32(object+0x520u)&&z==m.r32(object+0x524u)&&
      m.r32(view+0xb0u)==m.r32(object+0x528u)&&
      m.r32(view+0xb4u)==m.r32(object+0x52cu),
      "1287 exact +124 cached-rectangle producer");
 need(m.r32(object+0x50cu)==130u&&m.r32(object+0x510u)==240u&&
      m.r32(object+0x514u)==20u&&m.r32(object+0x518u)==20u&&
      m.r32(0x821970u)==11u&&m.r32(0x821974u)==13u&&
      m.r32(0x821978u)==20u&&m.r32(0x82197cu)==20u,
      "1287 bounded positive root and disjoint callback viewport");
 // Original root compares [120,238,60,30] with the translated cached
 // [141,253,20,20]; its four strict tests pass. It then calls real +FC.
 // +FC, under A28953=1, clips its private rectangle against the viewport,
 // clears +75 and exits on the empty clip before 698010 or renderer dispatch.
 for(unsigned k=0;k<4u;++k)stack.w32(base+0x40u+4u*k,m.r32(0x821970u+4u*k));
 clip.cx=base+0x50u;clip.dx=base+0x10u;clip.arg[0]=base+0x40u;
 (void)leaf::fun_0041fdf0(stack,clip);
 need(eq4(stack,base+0x50u,0u,0u,0u,0u),
      "1287 real callback empty viewport clip");
 m.w8(object+0x75u,0u);
 //69F5DE/69F6B8 use caller arg1 as the original registry loop counter.
 i.arg[1]=1u;return 1u; // One object, RET0xC; other caller words unchanged.
}
}
std::uint32_t fun_0069f5a0(Memory&m,const Inputs&i){return one(m,i);}
std::uint32_t fun_00699740(Memory&m,const Inputs&i){
 const auto self=i.cx;
 need(m.r32(self+0xe0u)==1u&&m.r32(0xaa60c8u)==0u,
      "1287 one real coordinate record and empty prior dirty list");
 need((i.arg[2]&0xffu)==0u&&m.r32(i.arg[0]+8u)==0u&&
      m.r32(i.arg[1]+8u)==0u,
      "1287 no final rectangle after positive counted-loop call");
 const auto record=m.r32(self+0xe4u),packed=m.r32(record+0x24u);
 need(packed==0x0005000au&&m.r32(self+0xb0u)==0u&&
      m.r32(self+0xb4u)==0u,
      "1287 finite real coordinate and zero wrapper viewport origin");
 std::array<std::uint8_t,0x100> private_bytes{};
 constexpr std::uint32_t base=0xf0000000u;
 leaf::Memory stack(private_bytes.data(),base,private_bytes.size());
 leaf::Inputs construct{};construct.cx=base;
 // Exact positive signed16 rounding path at 699770..9AE.
 construct.arg[0]=0xa00u;construct.arg[1]=0x500u;construct.arg[2]=0u;
 (void)leaf::fun_0041b630(stack,construct);
 Memory child=m;child.add(stack);
 Inputs projected{};projected.arg[0]=base+0x10u;projected.arg[1]=base;
 projected.fp.image=i.fp.image;
 (void)numeric_b80::fun_00697de0(child,projected);
 i.fp.image=projected.fp.image;
 need(stack.r32(base+0x10u)==150u&&stack.r32(base+0x14u)==225u,
      "1287 accepted projection of authentic 10,5,0 coordinate");
 // 6997DD..839 forms two private copies and calls 29F5A0 with flag one.
 const auto rx=stack.r32(base+0x10u)-m.r32(self+0xb0u)-30u;
 const auto ry=stack.r32(base+0x14u)-m.r32(self+0xb4u)+m.r32(0x821974u);
 for(const auto at:{base+0x30u,base+0x40u}){
  stack.w32(at,rx);stack.w32(at+4u,ry);
  stack.w32(at+8u,60u);stack.w32(at+12u,30u);
 }
 Inputs nested{};nested.cx=self;nested.arg[0]=1u;
 nested.arg[1]=base+0x30u;nested.arg[2]=base+0x40u;
 (void)one(child,nested);
 // With no prior dirty rectangles and both final extents zero, 69995F
 // reloads the second final pointer into EAX before returning.
 return i.arg[1];
}
}
