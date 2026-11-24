#include "recovered/recovery_b1611.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1611 {
namespace {
void need(bool yes){if(!yes)throw std::domain_error("B1611 finite one-pixel software surface route");}
bool separate(U a,U an,U b,U bn){return std::uint64_t(a)+an<=b||std::uint64_t(b)+bn<=a;}
U color(U x){return floating_b61::s32(x)>255?255u:x;}
// This is the selected semantic x87 arithmetic, not an FP image oracle.
// w: 0 integer width=1, 4 integer clip origin=0, 8 scale, 12 float zero,
// 16 double one, 24 double half, 32/36 ratios, 40 inverse area,
// 48..135 eleven actual FISTP qwords, 136/140 unscaled origins,
// 144 x upper boundary, 148 final y boundary, 152/156/160 actual RGB bytes. All operands are produced.
void resample(std::array<U,44>& w){
 asm volatile(
  // 6283EB..62841C: source/destination ratios and reciprocal pixel area.
  "fildl 0(%[w])\n\tfidivl 0(%[w])\n\tfstps 32(%[w])\n\t"
  "fildl 0(%[w])\n\tfidivl 0(%[w])\n\tfsts 36(%[w])\n\t"
  "fmuls 32(%[w])\n\tfdivrl 16(%[w])\n\tfstps 40(%[w])\n\t"
  // 628430..6284B7: clipped x/y endpoints; 76AA50 fast CW-match
  // body performs real FISTP qword under the already required CW0E7F.
  "fildl 4(%[w])\n\tfmuls 8(%[w])\n\tfistpll 48(%[w])\n\t"
  "fildl 0(%[w])\n\tfmuls 8(%[w])\n\tfistpll 56(%[w])\n\t"
  "fildl 4(%[w])\n\tfmuls 8(%[w])\n\tfistpll 64(%[w])\n\t"
  "fildl 0(%[w])\n\tfmuls 8(%[w])\n\tfistpll 72(%[w])\n\t"
  // 6284D3..628550: inverse origins and the live next-row boundary.
  "fildl 48(%[w])\n\tfdivs 8(%[w])\n\tfstps 136(%[w])\n\t"
  "fildl 64(%[w])\n\tfdivs 8(%[w])\n\tfstps 140(%[w])\n\t"
  "flds 140(%[w])\n\tfistpll 80(%[w])\n\t"
  "flds 140(%[w])\n\tfadds 36(%[w])\n\tfld %%st(0)\n\tfistpll 88(%[w])\n\t"
  // 62857C..6285CB: three black RGB accumulators, column endpoints.
  "flds 12(%[w])\n\tflds 12(%[w])\n\tflds 12(%[w])\n\t"
  "flds 136(%[w])\n\tfistpll 96(%[w])\n\t"
  "flds 136(%[w])\n\tfadds 32(%[w])\n\tfsts 144(%[w])\n\tfistpll 104(%[w])\n\t"
  // 62861A/628682: the selected one-row and one-column weights.
  "flds 36(%[w])\n\tflds 32(%[w])\n\tfmul %%st(1), %%st\n\tfmuls 40(%[w])\n\t"
  // 6286D8..628704: real zero byte->integer loads, weighted sums;
  // the three integer operands below are read from the actual RGB allocation.
  "fildl 152(%[w])\n\tfmul %%st(1), %%st\n\tfaddp %%st, %%st(5)\n\t"
  "fildl 156(%[w])\n\tfmul %%st(1), %%st\n\tfaddp %%st, %%st(4)\n\t"
  "fildl 160(%[w])\n\tfmul %%st(1), %%st\n\tfaddp %%st, %%st(3)\n\t"
  "fstp %%st(0)\n\tfstp %%st(0)\n\t"
  // 628759..628791: three actual +0.5 and truncating qword stores.
  // These operations naturally produce PE; no status/register patching.
  "faddl 24(%[w])\n\tfistpll 112(%[w])\n\t"
  "faddl 24(%[w])\n\tfistpll 120(%[w])\n\t"
  "faddl 24(%[w])\n\tfistpll 128(%[w])\n\t"
  // 628815 releases the still-live y boundary into the actual local result.
  "fstps 148(%[w])\n\t"
  : : [w]"r"(w.data())
  : "memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");
}
}
U run(U root,Memory& m,const Inputs& i,Heap& heap){
 need(root==0x2281f0u);const U self=i.cx,out=i.arg[0],input=i.arg[1],clip=i.arg[2];
 need(i.arg[3]==0u&&separate(out,16,input,16)&&separate(out,16,clip,16));
 need(separate(self,0x1488,out,16)&&separate(self,0x1488,input,16)&&separate(self,0x1488,clip,16));
 for(U k=0;k<4;++k){const U expected=k<2?0u:1u;need(m.r32(input+4*k)==expected&&m.r32(clip+4*k)==expected);}
 (void)m.r8(out+15u);
 const U surface=m.r32(self+0x121cu),scale=m.r32(self+0x1484u);need(surface&&scale==0x3f800000u);
 // Whole finite context input, without imposing a pattern on heap padding.
 for(U off=0;off<0x1488u;++off){U expected=0;for(U f:{0x121cu,0x1484u})if(off>=f&&off<f+4){expected=((f==0x121cu?surface:scale)>>(8*(off-f)))&255u;break;}need(m.r8(self+off)==expected);}
 need(heap.r32(surface)==0x785ef8u&&heap.r32(surface+4)==1u&&heap.r32(surface+8)==1u);
 need(heap.r32(surface+12)==0u&&heap.r32(surface+16)==2u&&heap.r32(surface+24)==2u&&heap.r8(surface+28)==1u);
 const U pixels=heap.r32(surface+20);need(pixels&&separate(surface,32,pixels,16));
 for(U k=0;k<32;++k)(void)heap.r8(surface+k);
 for(U k=0;k<16;++k)(void)heap.r8(pixels+k);
 need(heap.r8(pixels)==255u&&heap.r8(pixels+1)==255u);
 for(U off:{0xe8u,0xecu,0xf0u,0xf4u,0xf8u,0xfcu})need(m.r32(0x83b200u+off)==0u);
 // Bind the substituted software projections and actual immutable operands.
 constexpr U slots[][2]={{0x5cu,0x411370u},{0x60u,0x4112f0u},{0x70u,0x4113b0u},{0x74u,0x4113c0u},{0x7cu,0x4112c0u},{0x80u,0x4112d0u}};
 for(const auto& slot:slots)need(m.r32(0x785ef8u+slot[0])==slot[1]);
 need(m.r32(0x7c3a04u)==0x0e7fu);
 need(m.r32(0x785708u)==0u&&m.r32(0x78570cu)==0x3ff00000u);
 need(m.r32(0x785728u)==0u&&m.r32(0x78572cu)==0x3fe00000u);
 need(m.r32(0x785738u)==0u&&m.r32(0x7867f8u)==0x3f800000u);
 need(i.fp.image.word(0)==0x0e7fu&&i.fp.image.word(4)==0u&&i.fp.image.word(8)==0xffffu);
 namespace fp=ra2::platform::x87;const auto host=fp::capture_host();fp::restore_host(i.fp.image);
 try{
  const U width=m.r32(input+8),height=m.r32(input+12),rgb_size=3u*width*height;
  const U rgb=heap.allocate(rgb_size);need(rgb);
  // Actual two zeroing passes: the RGB constructor loop and REP STOS.
  for(U k=0;k<rgb_size;++k)heap.w8(rgb+k,0);
  m.w32(self+0x1238,rgb);
  for(U k=0;k<rgb_size;++k)heap.w8(rgb+k,0);
  m.w32(self+0x123c,width);m.w32(self+0x1240,height);
  const U target_width=heap.r32(surface+4),target_height=heap.r32(surface+8);
  i.arg[1]=target_width;
  // Actual411370/4113B0/4113C0: balanced software lock, bpp/stride.
  heap.w32(surface+12,heap.r32(surface+12)+1u);
  const U pixel_address=heap.r32(surface+20)+0u*heap.r32(surface+16)+0u*(target_width*heap.r32(surface+16));
  alignas(16) std::array<U,44> w{};
  w[0]=width;w[1]=m.r32(clip);w[2]=scale;w[3]=0u;
  w[4]=0u;w[5]=0x3ff00000u;w[6]=0u;w[7]=0x3fe00000u;
  w[38]=heap.r8(rgb);w[39]=heap.r8(rgb+1u);w[40]=heap.r8(rgb+2u);
  resample(w);
  i.arg[2]=w[36];i.arg[3]=w[24];
  // Computed conversion results, not the separate immutable FP oracle.
  const U x0=w[12],x1=(w[14]+1u<target_width?w[14]+1u:target_width);
  const U y0=w[16],y1=(w[18]+1u<target_height?w[18]+1u:target_height);
  const U first=color(w[28]),second=color(w[30]),third=color(w[32]);
  const U packed=((third>>m.r32(0x83b2ecu))<<m.r32(0x83b2e8u))|
                 ((second>>m.r32(0x83b2fcu))<<m.r32(0x83b2f8u))|
                 ((first>>m.r32(0x83b2f4u))<<m.r32(0x83b2f0u));
  heap.w8(pixel_address,packed);heap.w8(pixel_address+1u,packed>>8);
  i.arg[2]=w[34]; // 628803/62880E restores the unscaled x origin.
  // Actual4112F0 decrements the lock count; its AL result is discarded.
  heap.w32(surface+12,heap.r32(surface+12)-1u);
  const U mask_size=(target_width*target_height)/8u+1u;
  const U mask=heap.allocate(mask_size);need(mask);m.w32(self+0x1270,mask);
  for(U k=0;k<mask_size;++k)heap.w8(mask+k,0);
  // Root T=S-7C uses public words1..3 as scratch; preserve exact poststate.
  i.arg[1]=target_width;i.arg[2]=w[34];i.arg[3]=w[24];
  m.w32(out,x0);m.w32(out+4,y0);m.w32(out+8,x1-x0);m.w32(out+12,y1-y0);
  i.fp.image=fp::capture_host();fp::restore_host(host);
 }catch(...){fp::restore_host(host);throw;}
 return out;
}
}
