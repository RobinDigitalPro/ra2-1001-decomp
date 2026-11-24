#include "recovery_b1311.hpp"
#include "recovered/recovery_b220.hpp"
#include "recovered/recovery_b612.hpp"
#include "recovered/recovery_b728.hpp"
#include "recovered/recovery_b349.hpp"
#include "recovered/lookup_b67.hpp"
#include "recovered/map_b106.hpp"
#include "recovered/leaf_b56_c.hpp"
#include "recovered/leaf_b15_a.hpp"
#include "recovered/leaf_math.hpp"
#include "recovered/leaf_containers.hpp"
#include "recovered/leaf_memory.hpp"
#include <array>
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::global_b26 {
std::uint32_t fun_00545500(Memory&,const Inputs&);
}
namespace ra2::recovered::b1311 {
namespace {
using U=std::uint32_t;
using FP=ra2::platform::x87::State;
constexpr U kStack=0x7c000000u;
void need(bool ok,const char* text){if(!ok)throw std::domain_error(text);}
U packed(int x,int y){return U(std::uint16_t(x))|(U(std::uint16_t(y))<<16u);}
int sx16(U word){return int(static_cast<std::int16_t>(word));}
bool horizontal(U root){return root==0x15cab0u||root==0x15d4c0u;}
U category(U root){switch(root){case 0x15cab0u:return 0x4eu;
 case 0x15cfe0u:return 0x57u;case 0x15d4c0u:return 0xd1u;
 case 0x15da00u:return 0xdau;default:throw std::domain_error("1311 root");}}
U classified(Memory&m,U root,U coordinate){
 global_b26::Inputs q{};q.cx=coordinate;
 switch(root){case 0x15cab0u:return lookup_b67::fun_0055a860(m,q);
 case 0x15cfe0u:return lookup_b67::fun_0055a980(m,q);
 case 0x15d4c0u:return lookup_b67::fun_0055b960(m,q);
 case 0x15da00u:return lookup_b67::fun_0055ba90(m,q);}
 throw std::domain_error("1311 classifier");
}
U find_cell(Memory&m,U coordinate){
 global_b26::Inputs q{};q.cx=0x81a820u;q.arg[0]=coordinate;
 return global_b26::fun_00545500(m,q);
}
U find_cell(Memory&m,int x,int y,U location){
 m.w32(location,packed(x,y));return find_cell(m,location);
}
void rect(Memory&m,U cell,U output,bool vertical,FP&fp){
 Inputs q{};q.cx=cell;q.arg[0]=output;q.fp=fp;
 if(vertical)(void)recovery_b612::fun_00474ab0(m,q);
 else (void)recovery_b220::fun_00474d00(m,q);
 fp=q.fp;
}
void combine(leaf::Memory&stack,U out,U first,U second){
 leaf::Inputs q{};q.cx=out;q.dx=first;q.arg[0]=second;
 need(leaf::fun_0045ec50(stack,q)==out,"1311 accepted rectangle union");
}
void redraw(Memory&m,U cell,int x,int y){
 need(cell!=0xa57610u&&m.r32(cell+0x38u)==0xffffu,
      "1311 real no-art cell");
 const U table=m.r32(0xa1e11cu),type=m.r32(cell+0x44u);
 const U record=m.r32(table+4u*type);
 need(record!=0u&&m.r8(record+0x27cu)==0u&&
      m.r32(0x821b88u)!=0u&&m.r8(m.r32(0x821b88u)+0x584u)==0u,
      "1311 accepted 472140 no-art producer");
 m.w32(cell+0xecu,m.r32(record+0x268u));
 m.w8(cell+0x11cu,0u);
 Inputs q{};q.cx=cell;q.arg[0]=0xffffffffu;
 (void)recovery_b728::fun_00478b40(m,q);
 need(m.r32(cell+0x4cu)==7u&&m.r32(cell+0x24u)==packed(x,y),
      "1311 positive cache marker and cell coordinate");
 const U index=U(19*y+x);
 need(m.r32(0x81a820u+0xf0u)==7u&&m.r32(0x81a820u+0xf4u)==11u&&
      m.r32(0x81a884u)!=0u&&m.r32(0x81a88cu)!=0u,
      "1311 accepted 54CF40 cache stride");
 m.w8(m.r32(0x81a884u)+4u*index,m.r8(cell+0x4cu));
 m.w8(m.r32(0x81a884u)+4u*index+1u,m.r8(cell+0x11bu));
 m.w8(m.r32(0x81a88cu)+10u*index+8u,m.r8(cell+0x11bu));
}

// Original 0x7C810, reached only with +E4 empty. It still projects one
// real local {128,128,worldX} through accepted 0x702C0 and scans 25 cells.
U traverse(Memory&m,leaf::Memory&stack,U cell,FP&fp){
 need(m.r32(cell+0xe4u)==0u,"1311 bounded 7C810 empty object list");
 const int x=sx16(m.r16(cell+0x24u)),y=sx16(m.r16(cell+0x26u));
 constexpr U point=kStack+0x500u;
 leaf::Inputs construct{};construct.cx=point+8u;
 construct.arg[0]=U(x*256+128);construct.arg[1]=U(y*256+128);
 construct.arg[2]=0u;
 need(leaf::fun_0041b630(stack,construct)==point+8u,
      "1311 actual 1B630 point producer");
 stack.w32(point,128u);stack.w32(point+4u,128u);
 Inputs projected{};projected.cx=cell;projected.ax=point;
 projected.arg[0]=point;projected.fp=fp;
 (void)map_b106::fun_004702c0(m,projected);fp=projected.fp;
 for(int dy=-2;dy<=2;++dy)for(int dx=-2;dx<=2;++dx){
  const U neighbor=find_cell(m,x+dx,y+dy,kStack+0x540u);
  need(neighbor!=0xa57610u&&m.r32(neighbor+0xe4u)==0u,
       "1311 in-domain empty neighbor traversal");
 }
 return 3u; // The final outer counter increment leaves EAX=3.
}
}

U run(U root,Memory&m,const Inputs&i){
 const U old=category(root),next=old+1u;
 need(m.r32(i.arg[0])==packed(5,5),"1311 borrowed center coordinate");
 const bool across=horizontal(root);
 std::array<std::uint8_t,8192> raw{};
 leaf::Memory stack(raw.data(),kStack,U(raw.size()));
 Memory local=m;local.add(stack);
 const U center=find_cell(local,i.arg[0]);
 const int bx=across?5:4,by=across?4:5;
 const int ax=across?5:6,ay=across?6:5;
 const U before=find_cell(local,bx,by,kStack+0x700u);
 const U after=find_cell(local,ax,ay,kStack+0x704u);
 need(center!=0xa57610u&&before!=0xa57610u&&after!=0xa57610u&&
      center!=before&&center!=after&&before!=after&&
      m.r32(center+0x44u)==old&&m.r32(before+0x44u)==old&&
      m.r32(after+0x44u)==old,"1311 three distinct real category cells");
 FP fp=i.fp;
 rect(local,center,kStack+0x100u,false,fp);
 rect(local,center,kStack+0x110u,true,fp);
 combine(stack,kStack+0x120u,kStack+0x110u,kStack+0x100u);
 need(sx16(m.r16(i.arg[0]))==5&&sx16(m.r16(i.arg[0]+2u))==5,
      "1311 finite map domain");
 need(classified(local,root,i.arg[0])==1u,
      "1311 positive accepted neighbor classification");
 local.w32(center+0x44u,next);local.w32(before+0x44u,next);
 local.w32(after+0x44u,next);
 rect(local,center,kStack+0x130u,true,fp);
 rect(local,center,kStack+0x140u,false,fp);
 combine(stack,kStack+0x150u,kStack+0x130u,kStack+0x140u);
 combine(stack,kStack+0x160u,kStack+0x120u,kStack+0x150u);
 // 0x435420, 0x47CC40 and 0x453AB0 are all reached original helpers.
 // Execute them on the actual union, viewport and local rectangle values.
 leaf::Inputs copy{};copy.cx=kStack+0x160u;copy.arg[0]=kStack+0x180u;
 (void)leaf::fun_00435420(stack,copy);
 stack.w32(kStack+0x190u,m.r32(0x821970u));
 stack.w32(kStack+0x194u,m.r32(0x821974u));
 leaf::Inputs shift{};shift.cx=kStack+0x180u;
 shift.arg[0]=kStack+0x1a0u;shift.arg[1]=kStack+0x190u;
 (void)leaf::fun_0047cc40(stack,shift);
 leaf::Inputs build{};build.cx=kStack+0x1b0u;
 build.arg[0]=kStack+0x1a0u;
 build.arg[1]=stack.r32(kStack+0x160u+8u);
 build.arg[2]=stack.r32(kStack+0x160u+12u);
 (void)leaf::fun_00453ab0(stack,build);
 global_b26::Inputs append{};
 for(U k=0;k<4u;++k)append.arg[k]=stack.r32(kStack+0x1b0u+4u*k);
 append.arg[4]=0u;
 // Earlier 0x45EC50 PUSH EDI at root ESP E-F4 supplies B349's
 // entry-ESP-4 private word. Positive horizontal paths restore the center
 // pointer to EDI; positive vertical paths have explicitly ORed EDI,-1.
 append.stack_minus8=across?center:0xffffffffu;
 need(recovery_b349::fun_00698660(local,append)==0u,
      "1311 genuine first dirty rectangle append");
 redraw(local,center,5,5);redraw(local,before,bx,by);redraw(local,after,ax,ay);
 (void)traverse(local,stack,center,fp);
 (void)traverse(local,stack,before,fp);
 const U eax=traverse(local,stack,after,fp);
 i.fp=fp;
 return eax; // Last empty-list 7C810 returns outer counter 3.
}
U fun_0055cab0(Memory&m,const Inputs&i){return run(0x15cab0u,m,i);}
U fun_0055cfe0(Memory&m,const Inputs&i){return run(0x15cfe0u,m,i);}
U fun_0055d4c0(Memory&m,const Inputs&i){return run(0x15d4c0u,m,i);}
U fun_0055da00(Memory&m,const Inputs&i){return run(0x15da00u,m,i);}
}
