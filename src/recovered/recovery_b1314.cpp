#include "recovery_b1314.hpp"
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
#include <array>
#include <stdexcept>

namespace ra2::recovered::global_b26 {
std::uint32_t fun_00545500(Memory&,const Inputs&);
}
namespace ra2::recovered::b1314 {
namespace {
using U=std::uint32_t;
using FP=ra2::platform::x87::State;
constexpr U scratch=0x7c000000u;
struct Variant {U old_category,child_category;bool north_south;};
Variant variant(U root){switch(root){
 case 0x15ace0u:return {0x5cu,0x4fu,true};
 case 0x15b200u:return {0x60u,0x58u,false};
 case 0x15be10u:return {0xdfu,0xd2u,true};
 case 0x15c330u:return {0xe3u,0xdbu,false};
 default:throw std::domain_error("1314 exact four roots");}}
void need(bool ok,const char*why){if(!ok)throw std::domain_error(why);}
U packed(int x,int y){return U(std::uint16_t(x))|(U(std::uint16_t(y))<<16u);}
U cell_at(Memory&m,U point){global_b26::Inputs q{};q.cx=0x81a820u;q.arg[0]=point;return global_b26::fun_00545500(m,q);}
U cell_at(Memory&m,int x,int y,U point){m.w32(point,packed(x,y));return cell_at(m,point);}
void rect(Memory&m,U cell,U out,bool ab,FP&fp){
 Inputs q{};q.cx=cell;q.arg[0]=out;q.fp=fp;
 if(ab)(void)recovery_b612::fun_00474ab0(m,q);else (void)recovery_b220::fun_00474d00(m,q);
 fp=q.fp;
}
void join(leaf::Memory&local,U out,U a,U b){
 leaf::Inputs q{};q.cx=out;q.dx=a;q.arg[0]=b;
 need(leaf::fun_0045ec50(local,q)==out,"1314 rectangle union");
}
U classify(Memory&m,U root,U coordinate){global_b26::Inputs q{};q.cx=coordinate;
 switch(root){
 case 0x15ace0u:return lookup_b67::fun_0055a860(m,q);
 case 0x15b200u:return lookup_b67::fun_0055a980(m,q);
 case 0x15be10u:return lookup_b67::fun_0055b960(m,q);
 case 0x15c330u:return lookup_b67::fun_0055ba90(m,q);
 }throw std::domain_error("1314 classifier");
}

// Caller-specific existing-category route of CAB0/CFE0/D4C0/DA00.
// Unlike the B1311 positive-mutation wrappers, this path still performs the
// two initial geometry calls and real classifier, then takes the equality exit.
void already_current(Memory&m,leaf::Memory&local,U root,FP&fp){
 const auto v=variant(root);const int x=v.north_south?4:5,y=v.north_south?5:6;
 const U point=scratch+0x600u,center=cell_at(m,x,y,point);
 need(center!=0xa57610u&&m.r32(center+0x44u)==v.child_category,"1314 actual already-current neighbor");
 const U before=cell_at(m,x-(v.north_south?0:1),y-(v.north_south?1:0),scratch+0x610u);
 const U after=cell_at(m,x+(v.north_south?0:1),y+(v.north_south?1:0),scratch+0x614u);
 need(before!=0xa57610u&&after!=0xa57610u,"1314 child original populated axial lookup");
 // Original order is 474D00 then 474AB0, before the integer union/classifier.
 rect(m,center,scratch+0x300u,false,fp);rect(m,center,scratch+0x310u,true,fp);
 join(local,scratch+0x320u,scratch+0x310u,scratch+0x300u);
 const U result=classify(m,root,point);
 need(result==1u&&m.r32(center+0x44u)==v.child_category,"1314 positive classifier1 equals current category");
 // CAB0 CD55 / CFE0 D24F / D4C0 D76F / DA00 DC79 exit here.
 // No category store, dirty append, cache redraw or 7C810 occurs in this child.
}

void redraw(Memory&m,U cell,int x,int y){
 need(cell!=0xa57610u&&m.r32(cell+0x38u)==0xffffu,"1314 genuine no-art cell");
 const U record=m.r32(m.r32(0xa1e11cu)+4u*m.r32(cell+0x44u));
 need(record&&m.r8(record+0x27cu)==0u&&m.r32(0x821b88u)&&m.r8(m.r32(0x821b88u)+0x584u)==0u,"1314 472140 no-art producer");
 m.w32(cell+0xecu,m.r32(record+0x268u));m.w8(cell+0x11cu,0u);
 Inputs q{};q.cx=cell;q.arg[0]=0xffffffffu;(void)recovery_b728::fun_00478b40(m,q);
 need(m.r32(cell+0x4cu)==7u&&m.r32(cell+0x24u)==packed(x,y),"1314 positive cache marker");
 need(m.r32(0x81a910u)==7u&&m.r32(0x81a914u)==11u,"1314 accepted cache stride");
 const U index=U(19*y+x),cache_a=m.r32(0x81a884u),cache_b=m.r32(0x81a88cu);
 need(cache_a&&cache_b,"1314 borrowed cache spans");
 m.w8(cache_a+4u*index,m.r8(cell+0x4cu));m.w8(cache_a+4u*index+1u,m.r8(cell+0x11bu));
 m.w8(cache_b+10u*index+8u,m.r8(cell+0x11bu));
}
void traverse(Memory&m,leaf::Memory&local,U cell,FP&fp){
 need(m.r32(cell+0xe4u)==0u,"1314 bounded 7C810 empty object list");
 const int x=std::int16_t(m.r16(cell+0x24u)),y=std::int16_t(m.r16(cell+0x26u));
 constexpr U p=scratch+0x500u;
 leaf::Inputs c{};c.cx=p+8u;c.arg[0]=U(x*256+128);c.arg[1]=U(y*256+128);c.arg[2]=0u;
 need(leaf::fun_0041b630(local,c)==p+8u,"1314 original local point producer");
 local.w32(p,128u);local.w32(p+4u,128u);
 Inputs h{};h.cx=cell;h.ax=p;h.arg[0]=p;h.fp=fp;(void)map_b106::fun_004702c0(m,h);fp=h.fp;
 for(int dy=-2;dy<=2;++dy)for(int dx=-2;dx<=2;++dx){
  const U neighbor=cell_at(m,x+dx,y+dy,scratch+0x540u);
  need(neighbor!=0xa57610u&&m.r32(neighbor+0xe4u)==0u,"1314 all25 original neighborhood probes");
 }
 // Original last loop increment leaves EAX3. The outer root overwrites it.
}

U run(U root,Memory&memory,const Inputs&i){
 const auto v=variant(root);need(memory.r32(i.arg[0])==packed(5,5),"1314 borrowed outer center");
 std::array<std::uint8_t,8192> raw{};leaf::Memory local(raw.data(),scratch,U(raw.size()));Memory m=memory;m.add(local);
 const U center=cell_at(m,i.arg[0]);const int bx=v.north_south?5:4,by=v.north_south?4:5,ax=v.north_south?5:6,ay=v.north_south?6:5;
 const U before=cell_at(m,bx,by,scratch+0x700u),after=cell_at(m,ax,ay,scratch+0x704u);
 need(center!=0xa57610u&&before!=0xa57610u&&after!=0xa57610u&&center!=before&&center!=after&&before!=after,"1314 distinct real category cells");
 need(m.r32(center+0x44u)==v.old_category&&m.r32(before+0x44u)==v.old_category&&m.r32(after+0x44u)==v.old_category,"1314 special category branch");
 FP fp=i.fp;
 rect(m,center,scratch+0x100u,false,fp);rect(m,center,scratch+0x110u,true,fp);
 join(local,scratch+0x120u,scratch+0x110u,scratch+0x100u);
 // Exact special branch stores before, after, then center; its local flag stays0.
 m.w32(before+0x44u,v.old_category+1u);m.w32(after+0x44u,v.old_category+1u);m.w32(center+0x44u,v.old_category+1u);
 already_current(m,local,root,fp);
 // These caller geometry calls are D00 then AB0, not B1311's mutation order.
 rect(m,center,scratch+0x130u,false,fp);rect(m,center,scratch+0x140u,true,fp);
 join(local,scratch+0x150u,scratch+0x140u,scratch+0x130u);
 join(local,scratch+0x160u,scratch+0x120u,scratch+0x150u);
 local.w32(scratch+0x180u,local.r32(scratch+0x160u));local.w32(scratch+0x184u,local.r32(scratch+0x164u));
 local.w32(scratch+0x190u,m.r32(0x821970u));local.w32(scratch+0x194u,m.r32(0x821974u));
 leaf::Inputs shift{};shift.cx=scratch+0x180u;shift.arg[0]=scratch+0x1a0u;shift.arg[1]=scratch+0x190u;
 (void)leaf::fun_0047cc40(local,shift);
 leaf::Inputs build{};build.cx=scratch+0x1b0u;build.arg[0]=scratch+0x1a0u;build.arg[1]=local.r32(scratch+0x168u);build.arg[2]=local.r32(scratch+0x16cu);
 (void)leaf::fun_00453ab0(local,build);
 global_b26::Inputs append{};for(U k=0;k<4u;++k)append.arg[k]=local.r32(scratch+0x1b0u+4u*k);append.arg[4]=0u;
 // Root entryE: second45EC50 saves EDI=center atE-CC. 47CC40 reaches onlyE-C8;
 // 453AB0 has no pushes. 698660 entersE-C8 and copies high24 from entry-4=E-CC.
 append.stack_minus8=center;
 need(recovery_b349::fun_00698660(m,append)==0u,"1314 sole actual first dirty insertion");
 redraw(m,center,5,5);redraw(m,before,bx,by);redraw(m,after,ax,ay);
 traverse(m,local,center,fp);traverse(m,local,before,fp);traverse(m,local,after,fp);
 i.fp=fp;
 // Original MOV EAX,[frame+50] reads its produced zero optional-rectangle width,
 // then MOV AL,BL writes the unchanged zero flag. Full EAX0, not 7C810's EAX3.
 return 0u;
}
}
U fun_0055ace0(Memory&m,const Inputs&i){return run(0x15ace0u,m,i);}
U fun_0055b200(Memory&m,const Inputs&i){return run(0x15b200u,m,i);}
U fun_0055be10(Memory&m,const Inputs&i){return run(0x15be10u,m,i);}
U fun_0055c330(Memory&m,const Inputs&i){return run(0x15c330u,m,i);}
}
