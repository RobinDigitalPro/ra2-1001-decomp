#include "recovered/recovery_b1590.hpp"
#include "recovered/numeric_b88.hpp"
#include "recovered/leaf_b56_c.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1590 {namespace {
void need(bool value){if(!value)throw std::domain_error("B1590 finite genuine software double ellipse domain");}
std::uint64_t read64(const Memory&m,U at){return std::uint64_t(m.r32(at))|(std::uint64_t(m.r32(at+4))<<32);}
U format(const Memory&m,U s){need(m.r32(s)==0x785ef8);return m.r32(s+0x10);}
U stride(const Memory&m,U s){return m.r32(s+4)*format(m,s);}
U lock(Memory&m,U s,U x,U y){const U old=m.r32(s+0xc);need(old!=0xffffffffu);m.w32(s+0xc,old+1);return m.r32(s+0x14)+x*format(m,s)+y*stride(m,s);}
U unlock(Memory&m,U s){const U old=m.r32(s+0xc);need(old);const U count=old-1;m.w32(s+0xc,count);return (count&0xffffff00u)|1u;}
// Caller-specific composition of the authentic 75FB60 finite format2 path.
U set_pixel(Memory&m,U s,std::int32_t x,std::int32_t y,U color){need(x>=0&&x<256&&y>=0&&y<128);const U pixel=lock(m,s,U(x),U(y));m.w16(pixel,color);return unlock(m,s);}
// Both integer recurrences follow the parent-reviewed 760000 selected CFG.
// The initial vertical endpoints precede the outer lock; middle horizontal
// endpoints use genuine nested lock/unlock. Region stores use the outer lock.
U ellipse(Memory&m,U s,std::int32_t cx,std::int32_t cy,std::int32_t rx,std::int32_t ry,U color){
 const std::int32_t A=rx*rx,B=ry*ry;
 (void)set_pixel(m,s,cx,cy+ry,color);(void)set_pixel(m,s,cx,cy-ry,color);
 const U pixels=lock(m,s,0,0),row_stride=stride(m,s);
 auto store=[&](std::int32_t x,std::int32_t y){need(x>=0&&x<256&&y>=0&&y<128);m.w16(pixels+U(y)*row_stride+2*U(x),color);};
 auto four=[&](std::int32_t x,std::int32_t y){store(cx+x,cy+y);store(cx-x,cy-y);store(cx+x,cy-y);store(cx-x,cy+y);};
 std::int32_t x=0,y=ry,dx=0,dy=2*A*ry,d=A/4-A*ry;
 for(;;){d+=dx+B;if(d>=0){dy-=2*A;d-=dy;--y;}dx+=2*B;++x;if(dx>=dy)break;four(x,y);}
 (void)set_pixel(m,s,cx+rx,cy,color);(void)set_pixel(m,s,cx-rx,cy,color);
 x=rx;y=0;dx=2*B*x;dy=0;d=B/4-B*x;
 for(;;){d+=dy+A;if(d>=0){dx-=2*B;d-=dx;--x;}dy+=2*A;++y;if(dy>dx)break;four(x,y);}
 return unlock(m,s);
}
struct Span{U at,size;};
void disjoint(Memory&m,const std::array<Span,10>&v){for(U k=0;k<v.size();++k){need(v[k].at&&v[k].size&&std::uint64_t(v[k].at)+v[k].size<=0x100000000ull);if(k+1<v.size()){(void)m.r8(v[k].at);(void)m.r8(v[k].at+v[k].size-1);}for(U j=0;j<k;++j)need(std::uint64_t(v[k].at)+v[k].size<=v[j].at||std::uint64_t(v[j].at)+v[j].size<=v[k].at);}}
}
U fun_004518d0(Memory&m,const Inputs&i){
 need(i.cx==4&&(i.dx&255u)==0&&i.arg[0]==0&&i.arg[1]==0&&i.arg[2]==0&&(i.arg[4]&255u)==0&&(i.arg[5]&255u)==1);
 const U tactical=m.r32(0x821cac),surface=m.r32(0x821c9c);need(tactical&&surface&&m.r32(surface)==0x785ef8&&m.r32(surface+4)==256&&m.r32(surface+8)==128&&format(m,surface)==2&&m.r32(surface+0xc)==0);const U pixels=m.r32(surface+0x14);need(pixels&&(pixels&1u)==0);
 constexpr U local=0x7d890000,xyz=local,point=local+16,viewport=local+32,bbox=local+48,out=local+64;
 disjoint(m,{{{0x785000,4096},{0x7c3000,4096},{0x821000,4096},{0x83b000,4096},{0xaa5000,4096},{0xaa6000,4096},{tactical,0xb8},{surface,32},{pixels,65536},{local,80}}});
 need(m.r32(0x785ef8+0x20)==0x760000&&m.r32(0x785ef8+0x24)==0x75fb60&&m.r32(0x785ef8+0x5c)==0x411370&&m.r32(0x785ef8+0x60)==0x4112f0&&m.r32(0x785ef8+0x70)==0x4113b0&&m.r32(0x785ef8+0x74)==0x4113c0&&m.r32(0x785ef8+0x7c)==0x4112c0);
 need(m.r32(tactical+0xb0)==U(-128)&&m.r32(tactical+0xb4)==U(-64)&&read64(m,0xaa5f90)==0x3fc0000000000000ull&&read64(m,0x785728)==0x3fe0000000000000ull&&m.r32(0xaa6070)==640&&m.r32(0xaa6074)==480&&m.r32(0x7c3a04)==0x0e7f);
 need(i.fp.image.word(8)==0xffff&&(i.fp.image.word(4)&~0x3800u)==0);i.fp.require_masked();
 need(m.r32(0x821970)==0&&m.r32(0x821974)==0&&m.r32(0x821978)==256&&m.r32(0x82197c)==128);
 need(m.r32(0x83b2e8)==0&&m.r32(0x83b2ec)==3&&m.r32(0x83b2f0)==11&&m.r32(0x83b2f4)==3&&m.r32(0x83b2f8)==5&&m.r32(0x83b2fc)==2);
 const U rgb=i.arg[3],blue=(rgb&255u)>>m.r32(0x83b2ec),red=((rgb>>16)&255u)>>m.r32(0x83b2f4),green=((rgb>>8)&255u)>>m.r32(0x83b2fc);
 const U color=(blue<<m.r32(0x83b2e8))|(red<<m.r32(0x83b2f0))|(green<<m.r32(0x83b2f8));
 // These bytes are produced by copies of public arguments/viewport and helper
 // outputs, never by an assumed native private-frame seed. Nothing escapes.
 std::array<std::uint8_t,80>bytes{};leaf::Memory local_memory(bytes.data(),local,U(bytes.size()));Memory composed=m;composed.add(local_memory);
 for(U k=0;k<3;++k)local_memory.w32(xyz+4*k,i.arg[k]);
 Inputs child=i;child.cx=tactical;child.arg[0]=xyz;child.arg[1]=point;const U projected=numeric_b88::fun_00698010(composed,child);i.fp=child.fp;need((projected&255u)!=0);
 const U px=local_memory.r32(point),py=local_memory.r32(point+4),rx=i.cx,ry=rx/2;need(px==128&&py==64);
 for(U k=0;k<4;++k)local_memory.w32(viewport+4*k,m.r32(0x821970+4*k));
 local_memory.w32(bbox,px-rx);local_memory.w32(bbox+4,py-ry);local_memory.w32(bbox+8,2*rx);local_memory.w32(bbox+12,2*ry);
 leaf::Inputs clip;clip.cx=out;clip.dx=bbox;clip.arg[0]=viewport;clip.arg[1]=0;clip.arg[2]=0;need(leaf::fun_0041fdf0(local_memory,clip)==out);need(local_memory.r32(out)==124&&local_memory.r32(out+4)==62&&local_memory.r32(out+8)==8&&local_memory.r32(out+12)==4);
 (void)ellipse(m,surface,global_b26::s32(px),global_b26::s32(py),global_b26::s32(rx),global_b26::s32(ry),color);
 const U result=ellipse(m,surface,global_b26::s32(px),global_b26::s32(py),global_b26::s32(rx-1),global_b26::s32(ry-1),color);need(m.r32(surface+0xc)==0);
 return result&0xffffff00u; // Root MOV AL,0 preserves all higher return bits.
}
}
