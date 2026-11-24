#include "recovery_b1322.hpp"
#include "recovered/map_b106.hpp"
#include "recovered/recovery_b107.hpp"
#include "platform/x87_extended_b40.hpp"
#include "platform/x87_integer_subtract_b42.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1322 {
namespace {
using U=std::uint32_t;using FP=ra2::platform::x87::State;
void need(bool condition,const char*why){if(!condition)throw std::domain_error(why);}
void slot(Memory&m,U surface,U offset,U target){
 need(m.r32(surface)==0x785ef8u&&m.r32(0x785ef8u+offset)==target,"1322 authentic software vtable slot");
}
U width(Memory&m,U p){slot(m,p,0x7cu,0x4112c0u);return m.r32(p+4u);}
U height(Memory&m,U p){slot(m,p,0x80u,0x4112d0u);return m.r32(p+8u);}
U surface(Memory&m,U receiver){const U p=m.r32(receiver+0x1218u);
 need(p&&m.r32(p)==0x785ef8u&&m.r32(p+4u)==4u&&m.r32(p+8u)==4u,"1322 borrowed 4x4 software surface");
 need(m.r32(p+0xcu)==0u&&m.r32(p+0x10u)==2u&&m.r32(p+0x14u)&&m.r32(p+0x18u)==32u&&m.r8(p+0x1cu)==1u,"1322 constructor-layout prestate, no ownership claim");return p;
}
U bucket(Memory&m,U receiver,U index){
 const U owner=m.r32(receiver+0x1254u),rows=m.r32(owner);
 need(owner&&rows&&index<256u&&m.r32(owner+8u)==256u,"1322 accepted bucket layout");
 const U p=rows+24u*index;need(m.r32(p)==0x7937c4u&&m.r32(p+4u)==0u&&m.r32(p+8u)==0u&&m.r32(p+0x10u)==0u,"1322 authentic empty bucket");return p;
}
// Real 75FB60 -> 411370 -> 4113B0/4113C0 -> 4112C0 and 4112F0.
// This caller-specific composition preserves lock-count writes and the real
// two-byte store. No controlled callback, allocation or heap teardown exists.
void black_pixel(Memory&m,U p,U x,U y){
 slot(m,p,0x24u,0x75fb60u);slot(m,p,0x5cu,0x411370u);
 m.w32(p+0xcu,m.r32(p+0xcu)+1u);
 slot(m,p,0x70u,0x4113b0u);const U bpp=m.r32(p+0x10u);
 slot(m,p,0x74u,0x4113c0u);const U pitch=width(m,p)*m.r32(p+0x10u);
 const U address=m.r32(p+0x14u)+bpp*x+pitch*y;
 need(address&&bpp==2u,"1322 actual word pixel");slot(m,p,0x70u,0x4113b0u);
 m.w16(address,0u);slot(m,p,0x60u,0x4112f0u);m.w32(p+0xcu,m.r32(p+0xcu)-1u);
}
// Elementary x87 FADD ST0,ST2. All numeric guest state, including stale
// registers, stays explicit; this executes no original game bytes.
void add_st2(FP&f){f.require_masked();ra2::platform::x87::Image host;
 asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\t.byte 0xd8,0xc2\n\tfnsave %[guest]\n\tfrstor %[host]"
 :[host]"=m"(host.bytes),[guest]"+m"(f.image.bytes)::"memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");
}
U convert(Memory&m,FP&f){const auto cw=std::uint16_t(m.r32(0x7c3a04u));
 if(f.control()!=cw)f.load_control(cw);return U(f.pop_integer64());
}
U count_false(Memory&m,Inputs&q){
 // Explicit new caller-specific extension of B109 165070: even quotient0,
 // occupied cell and count0. Its private callerword is still overwritten.
 const U point=q.arg[0];need(std::int32_t(m.r32(0xa57848u))>0&&m.r32(point+8u)==0u,"1322 q0 shroud count route");
 const U x=m.r32(point)/256u,y=m.r32(point+4u)/256u;
 need(x==3u&&y==2u,"1322 mapped flat cell");q.arg[0]=x|(y<<16u);
 const U cell=m.r32(m.r32(0x81a958u)+4u*(512u*y+x));
 need(cell&&m.r32(cell+0x13cu)==0u,"1322 count0 genuine occupied cell");return cell&0xffffff00u;
}
U dirty(Memory&m,U r,U x,U y){
 const U d=r+0x1208u;std::int32_t px=std::int32_t(x+m.r32(r+0x1498u)),py=std::int32_t(y+m.r32(r+0x149cu));
 std::int32_t left=px,top=py,w=1,h=1;
 if(std::int32_t(m.r32(d+8u))>0&&std::int32_t(m.r32(d+12u))>0){
  left=std::int32_t(m.r32(d));top=std::int32_t(m.r32(d+4u));w=std::int32_t(m.r32(d+8u));h=std::int32_t(m.r32(d+12u));
  if(left>px){w+=left-px;left=px;}if(top>py){h+=top-py;top=py;}
  // Original grows a missing right/bottom edge by two, not one.
  if(left+w<px+1)w=px-left+2;if(top+h<py+1)h=py-top+2;
 }
 m.w32(d,U(left));m.w32(d+4u,U(top));m.w32(d+8u,U(w));m.w32(d+12u,U(h));return U(w);
}
}
U fun_00629680(Memory&memory,const Inputs&i){
 const U r=i.cx,p=surface(memory,r),point=i.arg[0];
 need(memory.r32(0xa1e0e4u)&&memory.r32(0xb0de50u)==1u,"1322 nonnull house and positive shroud mode");
 slot(memory,p,0x78u,0x411290u); // actual method produces private {0,0,4,4}
 const U x=memory.r32(point),y=memory.r32(point+4u);need(x<4u&&y<4u,"1322 inbounds pixel");
 i.arg[0]=x; // Original S+4 is reused, while EDI preserves point.
 need(memory.r32(r+0x1484u)==0x41800000u&&memory.r32(r+0x148cu)==0xffffffffu&&memory.r32(r+0x1494u)==5u,"1322 exact finite projection fixture");
 FP fp=i.fp;
 fp.load_integer32(x);platform::x87_extended::divide32(fp,memory.r32(r+0x1484u));platform::x87_integer_subtract::subtract_integer32(fp,memory.r32(r+0x148cu));
 fp.load_integer32(y);platform::x87_extended::divide32(fp,memory.r32(r+0x1484u));platform::x87_extended::add_integer32(fp,memory.r32(r+0x1494u));
 fp.load_st0();add_st2(fp);fp.multiply32(memory.r32(0x788d80u));fp.add64(std::uint64_t(memory.r32(0x785728u))|(std::uint64_t(memory.r32(0x78572cu))<<32u));
 const int cx=std::int16_t(convert(memory,fp));fp.subtract_st0_st1();fp.multiply32(memory.r32(0x788d80u));fp.add64(std::uint64_t(memory.r32(0x785728u))|(std::uint64_t(memory.r32(0x78572cu))<<32u));
 const int cy=std::int16_t(convert(memory,fp));fp.pop_st0();need(cx==3&&cy==2,"1322 actual projection cell");
 std::array<std::uint8_t,32> bytes{};constexpr U scratch=0x7a200000u;
 leaf::Memory local(bytes.data(),scratch,U(bytes.size()));Memory m=memory;m.add(local);
 local.w32(scratch,U(cx*256+128));local.w32(scratch+4u,U(cy*256+128));local.w32(scratch+8u,0u);
 const U cell=m.r32(m.r32(0x81a958u)+4u*(512u*U(cy)+U(cx)));
 need(m.r32(0x81a95cu)>1027u&&cell&&m.r8(cell+0x11bu)==0u&&m.r8(cell+0x11cu)==0u&&(m.r8(0x838f70u)&7u)==7u,"1322 warm flat height helper");
 // Actual 557070 copies exactly two DWORDs to its private heightquery scratch.
 local.w32(scratch+16u,local.r32(scratch));local.w32(scratch+20u,local.r32(scratch+4u));
 Inputs h{};h.cx=cell;h.arg[0]=scratch+16u;h.fp=fp;const U z=map_b106::fun_004702c0(m,h);fp=h.fp;need(z==0u,"1322 actual flat height zero");local.w32(scratch+8u,z);
 Inputs q{};q.cx=0x81a820u;q.arg[0]=scratch;
 need((recovery_b107::fun_00564f30(m,q)&255u)==1u,"1322 actual hidden flag true");
 i.arg[0]=(i.arg[0]&0xffffff00u)|1u;
 q.arg[0]=scratch;need((count_false(m,q)&255u)==0u,"1322 genuine zero visibility count");
 (void)bucket(m,r,(x-5u*y)&255u);black_pixel(m,p,x,y);i.fp=fp;return dirty(m,r,x,y);
}
U fun_00629b20(Memory&m,const Inputs&i){
 const U p=surface(m,i.cx),h=height(m,p),w=width(m,p),bytes=(w*h)/8u+1u,bitmap=m.r32(i.cx+0x1270u);
 need(bitmap&&bytes==3u,"1322 positive three-byte bitmap clear");for(U k=0;k<bytes;++k)m.w8(bitmap+k,0u);
 U eax=0u;for(U k=0;k<256u;++k){const U row=bucket(m,i.cx,k);eax=m.r32(row+4u);}return eax;
}
U fun_0062b6b0(Memory&memory,const Inputs&i){
 need(memory.r32(0xb0de50u)==1u,"1322 positive per-pixel full refresh");const U p=surface(memory,i.cx),w=width(memory,p),h=height(memory,p);
 std::array<std::uint8_t,8> bytes{};constexpr U scratch=0x7a300000u;leaf::Memory local(bytes.data(),scratch,8u);Memory m=memory;m.add(local);
 for(U y=0;y<h;++y)for(U x=0;x<w;++x){local.w32(scratch,x);local.w32(scratch+4u,y);Inputs child=i;child.arg[0]=scratch;(void)fun_00629680(m,child);i.fp=child.fp;}
 return h; // Original reload at62B751, RET0; child callerwords stay private.
}
}
