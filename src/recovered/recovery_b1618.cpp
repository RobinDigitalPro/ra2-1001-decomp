#include "recovered/recovery_b1618.hpp"
#include <algorithm>
#include <array>
#include <stdexcept>
namespace ra2::recovered::recovery_b220 {std::uint32_t fun_00474d00(global_b26::Memory&,const floating_b61::Inputs&);}
namespace ra2::recovered::recovery_b612 {std::uint32_t fun_00474ab0(global_b26::Memory&,const floating_b61::Inputs&);}
namespace ra2::recovered::b1618 {namespace {void need(bool v){if(!v)throw std::domain_error("1618 finite contained wall wear");}using Rect=std::array<int,4>;
Rect read(Memory&m,U p){return {int(m.r32(p)),int(m.r32(p+4)),int(m.r32(p+8)),int(m.r32(p+12))};}
Rect union_rect(Rect a,Rect b){if(b[2]<=0||b[3]<=0)return a;if(a[2]<=0||a[3]<=0)return b;int x=std::min(a[0],b[0]),y=std::min(a[1],b[1]);int w=b[2]+std::max(0,b[0]-a[0]),h=b[3]+std::max(0,b[1]-a[1]);if(b[0]+b[2]<a[0]+a[2])w=a[0]-x+a[2]+1;if(b[1]+b[3]<a[1]+a[3])h=a[1]-y+a[3]+1;return{x,y,w,h};}
Rect intersection(Rect a,Rect b){int x=std::max(a[0],b[0]),y=std::max(a[1],b[1]);return{x,y,std::max(0,std::min(a[0]+a[2],b[0]+b[2])-x),std::max(0,std::min(a[1]+a[3],b[1]+b[3])-y)};}}
U run(U root,Memory&m,const Inputs&i,Heap&heap){(void)heap;need(root==0x75be0&&i.arg[0]==200);U cell=i.cx;need(m.r32(cell+0x44)==0&&m.r16(cell+0x24)==0&&m.r16(cell+0x26)==0&&m.r8(cell+0x11b)==0&&m.r8(cell+0x11e)==0&&(m.r8(cell+0x140)&0x80)==0);
 U table=m.r32(0xa1e11c),type=m.r32(table);need(table&&type&&m.r32(type)==0x7929c8&&m.r32(0x792a64)==0x5d57d0&&m.r32(type+0x264)==0&&m.r32(type+0x268)!=9&&m.r32(type+0x270)==3&&m.r32(type+0x274)==100&&m.r8(type+0x278)==1&&m.r8(type+0x279)==0&&m.r8(type+0x27a)==0&&m.r8(type+0x284)==0&&m.r8(type+0x27f)==0);
 U shp=m.r32(type+0xa4),scene=m.r32(0x821cac),back=m.r32(0xaa60bc);need(shp&&scene&&back&&m.r8(type+0xa8)==1);need(m.r16(shp+2)==16&&m.r16(shp+4)==14&&m.r16(shp+6)==4);for(U n:{0u,2u}){U p=shp+8+24*n;need(m.r16(p)==0&&m.r16(p+2)==0&&m.r16(p+4)==12&&m.r16(p+6)==10);}
 need(m.r32(scene+0xb0)==0&&m.r32(scene+0xb4)==0&&m.r32(0x821974)==0&&m.r32(0xaa6070)==640&&m.r32(0xaa6074)==480&&m.r32(0xaa5f90)==0&&m.r32(0xaa5f94)==0&&m.r32(0x785728)==0&&m.r32(0x78572c)==0x3fe00000&&m.r32(0x7c3a04)==0xe7f);need(m.r32(0xaa60c8)==1&&m.r32(0xaa60c0)==1&&m.r8(back+16)==0);need(i.fp.image.word(8)==0xffff&&(i.fp.image.word(4)&~0x3800)==0);
 const U address[]{cell,type,shp,scene,table,back},size[]{0x144,0x288,104,0xb8,4,20};for(U a=0;a<6;++a){const std::uint64_t end=std::uint64_t(address[a])+size[a];need(address[a]&&end<=0x100000000ull);need(end<=0x7d000000ull||std::uint64_t(address[a])>=0x7d008000ull);need(end<=0x7d020000ull||std::uint64_t(address[a])>=0x7d021000ull);for(U b=a+1;b<6;++b)need(std::uint64_t(address[a])+size[a]<=address[b]||std::uint64_t(address[b])+size[b]<=address[a]);}
 // Source-only computational locals are disjoint from both accepted children synthetic stacks.
 std::array<std::uint8_t,4096> local{};leaf::Memory span(local.data(),0x7d020000,4096);Memory work=m;work.add(span);Inputs child=i;child.arg[0]=0x7d020000;child.cx=cell;need(recovery_b220::fun_00474d00(work,child)==child.arg[0]);i.fp=child.fp;Rect first=read(work,0x7d020000);
 child=i;child.arg[0]=0x7d020020;need(recovery_b612::fun_00474ab0(work,child)==child.arg[0]);i.fp=child.fp;Rect second=read(work,0x7d020020),incoming=union_rect(first,second);incoming[1]-=int(m.r32(0x821974));need(incoming[2]>0&&incoming[3]>0);
 // Actual698660 contained flag0 branch; do not call B349 empty-append Source.
 Rect existing=read(m,back),clipped=intersection(existing,incoming);need(clipped==incoming);const U incoming_flag=0;need(!incoming_flag);
 U wear=(m.r8(cell+0x11e)+0x10)&255;m.w8(cell+0x11e,wear);U stages=m.r32(type+0x270),level=wear>>4;need(level!=stages-1);need(i.arg[0]!=0xffffffff&&level<stages&&level!=stages-1);return 0;
}}
