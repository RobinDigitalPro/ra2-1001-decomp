#include "recovered/recovery_b1605.hpp"
#include "recovered/global_b58_c.hpp"
#include "recovered/recovery_b262.hpp"
#include <array>
#include <stdexcept>

namespace ra2::recovered::b1605 {
namespace {
using Heap=ra2::platform::ordinary_heap::Heap;
namespace fp=ra2::platform::x87;
void need(bool v){if(!v)throw std::domain_error("B1605 finite blocked-terrain cache refresh");}
constexpr U map=0x81a820u,context=0x819908u,packed=0x00070007u;
void empty_header(Memory&m,U p,U table){
 need(m.r32(p)==table&&m.r32(p+4)==0&&m.r32(p+8)==0&&m.r8(p+13)==0&&m.r32(p+16)==0);
 // Exact nonowned/null path of accepted567BA0/567860. These three stores
 // preserve the pointer, vptr, growth and both uninterpreted padding bytes.
 m.w32(p+16,0);m.w8(p+13,0);m.w32(p+8,0);
}
void validate(Memory&m,const Inputs&i){
 need(i.cx==map&&m.r32(map)==0x79091cu&&m.r32(i.arg[0])==packed);
 need(m.r32(map+0xf0)==7&&m.r32(map+0xf4)==11&&m.r32(map+0xf8)==3&&m.r32(map+0xfc)==2&&m.r32(map+0x100)==1&&m.r32(map+0x104)==1&&m.r32(map+0x68)==361&&m.r32(map+0x5c)==0);
 need(m.r32(0x790a44)==0x567ba0&&m.r32(0x790ac4)==0x567860&&m.r32(0x78755c)==0x42b2f0&&m.r32(0x817554)==0);
 need(m.r8(0xa57610+0x11b)==0&&m.r8(0xa57610+0x11c)==0&&m.r32(0x81a95c)==4096);
 const U table=m.r32(0x81a958),base=m.r32(map+0x64),cache=m.r32(map+0x6c);
 for(U j=0;j<4096;++j)need(m.r32(table+4*j)==0);
 for(U j=0;j<361;++j){const bool old=j==120||j==140;need(m.r8(base+4*j)==7&&m.r8(base+4*j+1)==0&&m.r16(base+4*j+2)==0&&m.r8(cache+10*j+8)==0);
  for(U level=0;level<3;++level){const U v=m.r16(cache+10*j+2*level);need(v==U(old)||(level==0&&j==140&&v==0));}
  need(m.r16(cache+10*j+6)==U(old));}
 for(U level=0;level<3;++level){const U header=m.r32(map+0x7c+4*level),buckets=m.r32(header),v=map+0x88+24*level,nodes=m.r32(v+4);
  need(m.r32(header+4)==0x54c6d0&&m.r32(header+8)==256&&m.r32(header+12)==20&&m.r32(buckets-4)==256);
  for(U k=0;k<256;++k){const U b=buckets+24*k;need(m.r32(b)==0x790a38&&m.r32(b+4)==0&&m.r32(b+8)==0&&m.r8(b+12)==1&&m.r8(b+13)==0&&m.r32(b+16)==0&&m.r32(b+20)==20);}
  need(m.r32(map+0x70+4*level)==2&&m.r32(v)==0x7909b8&&m.r32(v+8)==10&&m.r8(v+12)==1&&m.r8(v+13)==1&&m.r32(v+16)==2&&m.r32(v+20)==10&&m.r32(nodes-4)==10);
  for(U k=0;k<10;++k){const U q=nodes+36*k;need(m.r32(q)==0x790ab8&&m.r32(q+4)==0&&m.r32(q+8)==0&&m.r8(q+12)==1&&m.r8(q+13)==0&&m.r32(q+16)==0);}
  need(m.r16(nodes+24)==0&&m.r32(nodes+28)==7&&m.r32(nodes+36+20)==16&&m.r16(nodes+36+24)==(level==2?0:1)&&m.r32(nodes+36+28)==0&&m.r32(nodes+36+32)==262);
 }
 for(U off:{0x40u,0x4cu,0x58u,0x44u,0x50u,0x5cu,0x48u,0x54u,0x60u})need(m.r32(context+off)==0);
 need(i.fp.image.word(8)==0xffff&&(i.fp.image.word(4)&~0x3800u)==0);
 constexpr std::uint16_t cw[]{0x037f,0x077f,0x0b7f,0x0f7f,0x027f,0x067f,0x0a7f,0x0e7f,0x007f,0x047f,0x087f,0x0c7f};bool valid=false;for(auto c:cw)valid=valid||i.fp.image.word(0)==c;need(valid);
}
U refresh(Memory&original,const Inputs&i,Heap&heap){
 validate(original,i);
 std::array<std::uint8_t,4> point_bytes{};
 leaf::Memory point(point_bytes.data(),0x7d030000u,4);Memory m=original;m.add(point);
 const U base=m.r32(map+0x64),cache=m.r32(map+0x6c);
 const auto membership=[&](U x,U y){point.w32(point.base(),x|(y<<16));global_b26::Inputs q{};q.cx=map;q.arg[0]=point.base();q.arg[1]=1;return global_b26::fun_00557450(m,q)&255u;};
 const auto host=fp::capture_host();fp::restore_host(i.fp.image);
 try{
  need(membership(7,7)==1);
  for(int level=2;level>=0;--level){
   const U side=1u<<(U(level)+1),start=7u&~(side-1u),header=m.r32(map+0x7c+4*U(level)),buckets=m.r32(header),nodes=m.r32(map+0x88+24*U(level)+4);
   for(U k=0;k<256;++k)empty_header(m,buckets+24*k,0x790a38);
   U temporary=0;
   for(U y=start;y<start+side;++y)for(U x=start;x<start+side;++x){const U index=y*19+x,p=cache+10*index,old=m.r16(p+2*U(level));
    if(old){need(old==1);if(!temporary){temporary=heap.allocate(20);need(temporary);heap.w8(temporary,1);heap.w8(temporary+1,0);}}
    m.w16(p+2*U(level),0);m.w16(p+6,m.r16(base+4*index+2));
   }
   need(temporary);empty_header(m,nodes+36,0x790ab8);
   // The true class7 branch avoids fill/new-node creation on both valid cells.
   for(U y=start;y<start+side;++y)for(U x=start;x<start+side;++x)if(membership(x,y))need(m.r8(base+4*(19*y+x))==7);
   m.w32(map+0x70+4*U(level),2);
   // Map5C=0 and empty T12 buckets avoid161950 and private edge-word copies.
   need(heap.release(temporary)==1);
  }
  for(U y=0;y<8;++y)for(U x=0;x<8;++x)if(membership(x,y)){
   const U p=cache+10*(19*y+x);
   for(U level=0;level<2;++level){const U id=m.r16(p+2*level),nodes=m.r32(map+0x88+24*level+4);need(id==0);m.w16(nodes+36*id+24,m.r16(p+2*(level+1)));}
  }
  recovery42_cleanup::State out{};out.cx=context;
  recovery42_cleanup::fun_00429a90(m,out,heap);
  i.fp.image=fp::capture_host();fp::restore_host(host);return out.ax;
 }catch(...){i.fp.image=fp::capture_host();fp::restore_host(host);throw;}
}
}
U run(U root,Memory&m,const Inputs&i,ra2::platform::ordinary_heap::Heap&heap){
 need(root==0x163130||root==0x165690);
 if(root==0x163130)return refresh(m,i,heap);
 const U vector=i.arg[0],coordinates=m.r32(vector+4);need(i.cx==map&&m.r32(vector+16)==1&&m.r32(coordinates)==packed);
 // True first-pass membership and actual nonresident-cell/sentinel route.
 global_b26::Inputs valid{};valid.cx=map;valid.arg[0]=coordinates;valid.arg[1]=1;
 need((global_b26::fun_00557450(m,valid)&255)==1);
 const U cache=m.r32(map+0x6c);m.w16(cache+140*10,0);
 need(m.r32(m.r32(0x81a958)+3591*4)==0);m.w32(0xa57634,packed);
 // Original72140's real A57610 guard has no persistent effect.
 // Parent's P+14 is entryS+4: its first caller DWORD is real scratch.
 i.arg[0]=packed;
 std::array<std::uint8_t,4> bytes{{7,0,7,0}};leaf::Memory point(bytes.data(),0x7d020000u,4);Memory local=m;local.add(point);
 Inputs nested=i;nested.arg[0]=point.base();const U result=refresh(local,nested,heap);i.fp=nested.fp;return result;
}
}
