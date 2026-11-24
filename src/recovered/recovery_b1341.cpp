#include "recovery_b1341.hpp"
#include "recovered/recovery_b112.hpp"
#include "recovered/numeric_b88_detail.hpp"
#include "recovered/leaf_memory.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1341 {
namespace {
using U=std::uint32_t;
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
U actor_type(Memory&m,U actor){
 const U v=m.r32(actor);need(v==0x78612cu&&m.r32(v+0x80u)==0x6b6910u&&m.r32(v+0x84u)==0x41b600u,"1341 actual chained type provider");
 const U type=m.r32(actor+0x5acu);need(type!=0u,"1341 borrowed valid type");return type;
}
bool classify(Memory&m,const Inputs&i,U p,bool upper){
 // 707F60 compares with1 then2; 707FE0 compares with2. Preserve all x87 effects.
 i.fp.load64(floating_b61::read64(m,p));i.fp.compare_pop64(floating_b61::read64(m,upper?0x7856f8u:0x785708u));
 if(upper)return (i.fp.status()&0x100u)==0u;
 if((i.fp.status()&0x100u)!=0u)return false;
 i.fp.load64(floating_b61::read64(m,p));i.fp.compare_pop64(floating_b61::read64(m,0x7856f8u));
 return (i.fp.status()&0x100u)!=0u;
}
void publish(Memory&m,const Inputs&i,U actor){
 const U owner=m.r32(actor+0x1b4u),record=m.r32(owner+0x34u),rules=m.r32(0x821b88u);
 need(m.r8(actor+0x32du)!=0u&&record&&m.r8(record+0x1a6u)==0u,"1341 actual provider gate");
 const auto denominator=global_b26::s32(m.r32(rules+0x1324u)),z=global_b26::s32(m.r32(actor+0x90u));
 need(denominator>0&&z==0,"1341 finite zero-height/positive-rules route");
 const U scaled=U(z/denominator)*10u;m.w8(actor+0x378u,scaled);
 const U type=actor_type(m,actor);need(m.r32(type+0x530u)==0u,"1341 supported real base sight zero");
 i.fp.load_integer32(m.r32(type+0x530u));i.fp.load_integer32(U(std::int32_t(std::int8_t(m.r8(actor+0x378u)))));
 i.fp.multiply64(floating_b61::read64(m,0x787518u));i.fp.add64(floating_b61::read64(m,0x785708u));
 numeric_b88::detail::reg<0xdec9>(i.fp);const U radius=numeric_b88::detail::integer(m,i.fp);
 const U factor=actor+0x118u;
 need(!classify(m,i,factor,false)&&classify(m,i,factor,true),"1341 actual factor class above2");
 need(actor_type(m,actor)==type,"1341 second actual type call");
 need(!classify(m,i,factor,false)&&classify(m,i,factor,true),"1341 repeated actual factor calls");
 need(m.r8(type+0x271u)==0u&&m.r8(type+0x283u)==0u,"1341 actual optional multiplier disabled");
 need(m.r8(actor+0x1e4u)==0u&&radius==0u,"1341 positive publish branch and inner radius-zero guard");
 m.w8(actor+0x1e4u,1u);m.w32(actor+0x1e8u,m.r32(actor+0x88u));m.w32(actor+0x1f4u,radius);
 m.w32(actor+0x1ecu,m.r32(actor+0x8cu));m.w32(actor+0x1f0u,m.r32(actor+0x90u));
}
}
std::uint32_t fun_0049dba0(Memory&m,const Inputs&i){
 need(m.r32(0xa28870u)==1u,"1341 one actual registry member");const U actor=m.r32(m.r32(0xa28864u));
 need(actor&&m.r8(actor+0x76u)==0u,"1341 active actor");const U v=m.r32(actor);
 need(v==0x78612cu&&m.r32(v+0x2cu)==0x41b580u,"1341 actual kind2 provider");
 const U owner=m.r32(actor+0x1b4u);need(owner&&m.r32(0xa255c8u)==0u&&m.r8(owner+0x134u)!=0u,"1341 actual visible-owner predicate");
 need(m.r8(actor+0x373u)!=0u&&m.r32(v+0x418u)==0x6cb1a0u,"1341 actual publish callback");
 publish(m,i,actor); // Original call supplies four literal zero child arguments.
 std::array<std::uint8_t,12> bytes{};constexpr U point=0x7d100000u;
 leaf::Memory local(bytes.data(),point,U(bytes.size()));Memory view=m;view.add(local);
 for(U k=0;k<3u;++k)view.w32(point+4u*k,m.r32(actor+0x88u+4u*k));
 Inputs child{};child.cx=0x81a820u;child.arg[0]=point;child.arg[1]=0u;child.arg[2]=m.r32(actor+0x1f4u)+3u;child.arg[3]=0u;child.fp=i.fp;
 need(child.arg[2]==3u&&m.r32(0x7908e8u+12u)==37u,"1341 actual radius3/count37");
 for(U k=0;k<37u;++k)need(m.r32(0xa56e68u+4u*k)==0u,"1341 unchanged original zero offset table");
 need(recovery_b112::fun_005479e0(view,child)==0u,"1341 actual finite B112 visibility return");i.fp=child.fp;
 const U type=actor_type(m,actor);need(m.r8(type+0xaddu)==0u,"1341 no additional type callback");return type;
}
}
