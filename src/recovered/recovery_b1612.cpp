#include "recovered/recovery_b1612.hpp"
#include "recovered/recovery_b1288.hpp"
#include <algorithm>
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1612 {
namespace {
void need(bool b){if(!b)throw std::domain_error("B1612 genuine one-cell two-pixel software rendering");}
U clipped_color(U x){return floating_b61::s32(x)>255?255u:x;}
// The complete selected ratio/endpoints/row arithmetic. w is integer storage
// for real x87 operands/results, never a saved-register poststate oracle.
// Integer dimensions: sourceW[0], sourceH[43], targetW[42], targetH[44].
// Eleven qword FISTP slots occupy bytes48..135; float origins136/140.
// Both pixels stay in one semantic arithmetic group. The row boundary is
// live only inside this asm; generic Heap calls never receive a live ST value.
void resample_row(std::array<U,53>&w){
 asm volatile(
  "fildl 0(%[w])\n\tfidivl 168(%[w])\n\tfstps 32(%[w])\n\t"
  "fildl 172(%[w])\n\tfidivl 176(%[w])\n\tfsts 36(%[w])\n\t"
  "fmuls 32(%[w])\n\tfdivrl 16(%[w])\n\tfstps 40(%[w])\n\t"
  // Actual clipped endpoints0,2,0,1, scaled by actual1.0.
  "fildl 4(%[w])\n\tfmuls 8(%[w])\n\tfistpll 48(%[w])\n\t"
  "fildl 180(%[w])\n\tfmuls 8(%[w])\n\tfistpll 56(%[w])\n\t"
  "fildl 4(%[w])\n\tfmuls 8(%[w])\n\tfistpll 64(%[w])\n\t"
  "fildl 184(%[w])\n\tfmuls 8(%[w])\n\tfistpll 72(%[w])\n\t"
  "fildl 48(%[w])\n\tfdivs 8(%[w])\n\tfstps 136(%[w])\n\t"
  "fildl 64(%[w])\n\tfdivs 8(%[w])\n\tfstps 140(%[w])\n\t"
  "flds 140(%[w])\n\tfistpll 80(%[w])\n\t"
  "flds 140(%[w])\n\tfadds 36(%[w])\n\tfld %%st(0)\n\tfistpll 88(%[w])\n\t"

  "flds 12(%[w])\n\tflds 12(%[w])\n\tflds 12(%[w])\n\t"
  "flds 136(%[w])\n\tfistpll 96(%[w])\n\t"
  "flds 136(%[w])\n\tfadds 32(%[w])\n\tfsts 144(%[w])\n\tfistpll 104(%[w])\n\t"
  "flds 36(%[w])\n\tflds 32(%[w])\n\tfmul %%st(1), %%st\n\tfmuls 40(%[w])\n\t"
  "fildl 152(%[w])\n\tfmul %%st(1), %%st\n\tfaddp %%st, %%st(5)\n\t"
  "fildl 156(%[w])\n\tfmul %%st(1), %%st\n\tfaddp %%st, %%st(4)\n\t"
  "fildl 160(%[w])\n\tfmul %%st(1), %%st\n\tfaddp %%st, %%st(3)\n\t"
  "fstp %%st(0)\n\tfstp %%st(0)\n\t"
  "faddl 24(%[w])\n\tfistpll 112(%[w])\n\t"
  "faddl 24(%[w])\n\tfistpll 120(%[w])\n\t"
  "faddl 24(%[w])\n\tfistpll 128(%[w])\n\t"
  // Retain the first computed color, then advance the actual float origin.
  "movl 112(%[w]), %%eax\n\tmovl %%eax, 200(%[w])\n\t"
  "movl 120(%[w]), %%eax\n\tmovl %%eax, 204(%[w])\n\t"
  "movl 128(%[w]), %%eax\n\tmovl %%eax, 208(%[w])\n\t"
  "movl 144(%[w]), %%eax\n\tmovl %%eax, 136(%[w])\n\t"

  "flds 12(%[w])\n\tflds 12(%[w])\n\tflds 12(%[w])\n\t"
  "flds 136(%[w])\n\tfistpll 96(%[w])\n\t"
  "flds 136(%[w])\n\tfadds 32(%[w])\n\tfsts 144(%[w])\n\tfistpll 104(%[w])\n\t"
  "flds 36(%[w])\n\tflds 32(%[w])\n\tfmul %%st(1), %%st\n\tfmuls 40(%[w])\n\t"
  "fildl 188(%[w])\n\tfmul %%st(1), %%st\n\tfaddp %%st, %%st(5)\n\t"
  "fildl 192(%[w])\n\tfmul %%st(1), %%st\n\tfaddp %%st, %%st(4)\n\t"
  "fildl 196(%[w])\n\tfmul %%st(1), %%st\n\tfaddp %%st, %%st(3)\n\t"
  "fstp %%st(0)\n\tfstp %%st(0)\n\t"
  "faddl 24(%[w])\n\tfistpll 112(%[w])\n\t"
  "faddl 24(%[w])\n\tfistpll 120(%[w])\n\t"
  "faddl 24(%[w])\n\tfistpll 128(%[w])\n\t"
  "fstps 148(%[w])\n\t"
  : : [w]"r"(w.data())
  : "eax","memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");
}
void immutable(Memory&m){
 constexpr U slots[][2]={{0x5cu,0x411370u},{0x60u,0x4112f0u},{0x70u,0x4113b0u},{0x74u,0x4113c0u},{0x7cu,0x4112c0u},{0x80u,0x4112d0u}};
 for(const auto&s:slots)need(m.r32(0x785ef8u+s[0])==s[1]);
 need(m.r32(0x7875acu)==0x42cc10u);
 need(m.r32(0x7c3a04u)==0xe7fu&&m.r32(0x785bb8u)==0x3f800000u);
 need(m.r32(0x7860a8u)==0x437f0000u&&m.r32(0x785738u)==0u);
 need(m.r32(0x785708u)==0u&&m.r32(0x78570cu)==0x3ff00000u);
 need(m.r32(0x785728u)==0u&&m.r32(0x78572cu)==0x3fe00000u&&m.r32(0x7867f8u)==0x3f800000u);
 for(U off:{0xe8u,0xecu,0xf0u,0xf4u,0xf8u,0xfcu})need(m.r32(0x83b200u+off)==0u);
}
}
U run(U root,Memory&m,const Inputs&i,Heap&heap){
 need(root==0x228c80u);const U self=i.cx,vector=self+0x1220u;
 need(m.r32(self+0xf0u)==7u&&m.r32(self+0xf8u)==2u&&m.r32(self+0xfcu)==2u);
 need(m.r32(self+0x100u)==3u&&m.r32(self+0x104u)==3u);
 need(m.r32(self+0x148cu)==2u&&m.r32(self+0x1494u)==12u&&m.r32(self+0x1484u)==0x3f800000u);
 need(m.r32(vector)==0x7875a0u&&m.r32(vector+8)==10u&&m.r8(vector+12)==1u&&m.r8(vector+13)==1u);
 need(m.r32(vector+16)==1u&&m.r32(vector+20)==10u);
 const U queue=m.r32(vector+4);need(queue);for(U k=0;k<48;++k)(void)heap.r8(queue+k);
 const U packed=heap.r32(queue);need(packed==0x00070005u);
 const U map_table=m.r32(0x81a958u);need(map_table);const U cell=m.r32(map_table+4u*(5u+512u*7u));
 need(cell&&m.r32(cell+0x24u)==packed&&m.r8(cell+0x11bu)==0u&&m.r8(cell+0x11cu)==0u);
 const U surface=m.r32(self+0x121cu),rgb=m.r32(self+0x1238u);
 need(surface&&rgb&&surface!=queue&&surface!=rgb&&rgb!=queue&&m.r32(self+0x123cu)==2u&&m.r32(self+0x1240u)==1u&&m.r32(self+0x1270u)==0u);
 for(U k=0;k<32;++k)(void)heap.r8(surface+k);for(U k=0;k<16;++k)(void)heap.r8(rgb+k);
 need(heap.r32(surface)==0x785ef8u&&heap.r32(surface+4)==2u&&heap.r32(surface+8)==1u&&heap.r32(surface+12)==0u);
 need(heap.r32(surface+16)==2u&&heap.r32(surface+24)==4u&&heap.r8(surface+28)==1u);
 const U pixels=heap.r32(surface+20);need(pixels&&pixels!=surface&&pixels!=rgb&&pixels!=queue);
 for(U k=0;k<16;++k)(void)heap.r8(pixels+k);for(U k=0;k<4;++k)need(heap.r8(pixels+k)==255u);
 for(U k=0;k<6;++k)need(heap.r8(rgb+k)!=0u);
 // B1288 additionally validates the authentic ordinary Cell/Type/cache graph.
 const U tile=m.r32(cell+0x38u),types=m.r32(0xa28914u);need(tile<4u&&types);
 const U type=m.r32(types+4u*tile);need(type);const U cache=m.r32(type+0xa4u);need(cache);
 const U subtile=m.r8(cell+0x11au);need(subtile<8u);const U color=m.r32(cache+16u+4u*subtile);need(color);
 for(U k=0;k<3;++k)need(m.r8(color+0x2bu+k)==0u);
 immutable(m);need(i.fp.image.word(0)==0xe7fu&&i.fp.image.word(4)==0u&&i.fp.image.word(8)==0xffffu);
 // 557450 and41FDF0 are finite integer projections of their exact bodies.
 const int x=int(std::int16_t(packed)),y=int(std::int16_t(packed>>16));
 const int sum=x+y,delta=x-y;
 need(sum>int(m.r32(self+0xf0u)+2u*m.r32(self+0xfcu)));
 need(sum<=int(m.r32(self+0xf0u)+2u*(m.r32(self+0xfcu)+m.r32(self+0x104u))+2u));
 need(delta<int(2u*(m.r32(self+0xf8u)+m.r32(self+0x100u))-m.r32(self+0xf0u)));
 need(y-x<int(m.r32(self+0xf0u)-2u*m.r32(self+0xf8u)));
 const int left=int(m.r32(self+0x148cu))-y+x,top=y-int(m.r32(self+0x1494u))+x;
 const int clipped_x=std::max(0,left),clipped_y=std::max(0,top);
 const int clipped_w=std::min(2,left+2)-clipped_x,clipped_h=std::min(1,top+1)-clipped_y;
 need(clipped_x==0&&clipped_y==0&&clipped_w==2&&clipped_h==1);
 namespace fp=ra2::platform::x87;const auto host=fp::capture_host();
 try{
  // These six bytes have actual root zero stores before70EC0. Copy Memory
  // so the private guest span never leaks into the caller's span registry.
  std::array<std::uint8_t,6> local{};constexpr U private_base=0xd0000000u;
  leaf::Memory local_span(local.data(),private_base,U(local.size()));Memory nested=m;nested.add(local_span);
  Inputs color_in=i;color_in.cx=cell;color_in.arg[0]=private_base;color_in.arg[1]=private_base+3u;
  (void)recovery_b1288::fun_00470ec0(nested,color_in);
  // Exact normal width-two path copies both actual produced RGB triples.
  for(U k=0;k<6;++k)heap.w8(rgb+k,nested.r8(private_base+k));
  // Child6281F0 receives copied private arguments; outeri.arg never changes.
  fp::restore_host(color_in.fp.image);
  heap.w32(surface+12,heap.r32(surface+12)+1u);
  alignas(16) std::array<U,53>w{};
  w[0]=m.r32(self+0x123cu);w[1]=U(clipped_x);w[2]=m.r32(self+0x1484u);w[3]=m.r32(0x785738u);
  w[4]=m.r32(0x785708u);w[5]=m.r32(0x78570cu);w[6]=m.r32(0x785728u);w[7]=m.r32(0x78572cu);
  w[42]=heap.r32(surface+4);w[43]=m.r32(self+0x1240u);w[44]=heap.r32(surface+8);w[45]=U(clipped_x+clipped_w);w[46]=U(clipped_y+clipped_h);
  for(U k=0;k<3;++k){w[38+k]=heap.r8(rgb+k);w[47+k]=heap.r8(rgb+3u+k);}
  resample_row(w);
  for(U column=0;column<2;++column){
   const U first=clipped_color(w[column?28:50]),second=clipped_color(w[column?30:51]),third=clipped_color(w[column?32:52]);
   const U value=((third>>m.r32(0x83b2ecu))<<m.r32(0x83b2e8u))|((second>>m.r32(0x83b2fcu))<<m.r32(0x83b2f8u))|((first>>m.r32(0x83b2f4u))<<m.r32(0x83b2f0u));
   const U at=heap.r32(surface+20)+column*heap.r32(surface+16);heap.w8(at,value);heap.w8(at+1,value>>8);
  }
  heap.w32(surface+12,heap.r32(surface+12)-1u);
  const U mask_size=(heap.r32(surface+4)*heap.r32(surface+8))/8u+1u;
  const U mask=heap.allocate(mask_size);need(mask);m.w32(self+0x1270u,mask);for(U k=0;k<mask_size;++k)heap.w8(mask+k,0u);
  const U rx=w[12],ry=w[16],right=std::min(w[14]+1u,heap.r32(surface+4)),bottom=std::min(w[18]+1u,heap.r32(surface+8));
  // Actual42CC10 resets count before observing/freeing the owned buffer.
  m.w32(vector+16u,0u);need(heap.release(queue)==1u);m.w32(vector+4u,0u);m.w8(vector+13u,0u);m.w32(vector+8u,0u);
  // Only after the queue tail: first-rectangle union/publication.
  m.w32(self+0x1244u,rx);m.w32(self+0x1248u,ry);m.w32(self+0x124cu,right-rx);m.w32(self+0x1250u,bottom-ry);
  i.fp.image=fp::capture_host();fp::restore_host(host);return rx;
 }catch(...){fp::restore_host(host);throw;}
}
}
