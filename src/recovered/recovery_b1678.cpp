#include "recovered/recovery_b1678.hpp"
#include "platform/surface1678_fp.hpp"

namespace ra2::recovered::b1678 {
namespace model=ra2::recovered::b1678;
namespace fp=ra2::platform::x87;
using U=unsigned;
inline void need(bool x,const char* text){if(!x)throw std::domain_error(text);}
inline U allocate(model::Memory& m,model::State& s,const model::Operations& op,U bytes){
 need(op.allocate&&op.context,"owned genuine allocator context");
 const U p=op.allocate(op.context,m,bytes,s.fp);need(p!=0,"finite successful allocation");return p;
}
void run(model::Memory& m,model::State& s,model::Frame& frame,const model::Operations& op){
 need(m.r8(0xa39bf4u)==0&&!(s.arithmetic_flags&0x400u),"fresh initialization and DF0");
 for(U p:{0xa39a30u,0xa39a34u,0xa39a58u,0xa39a5cu})need(m.r32(p)==0,"exact default-zero animation parameters");
 need(m.r32(0x7c3a04u)==0x0e7fu,"authentic cached FTOL control");
 constexpr U virtuals[][2]={{0x10,0x75fd00},{0x18,0x760760},{0x5c,0x411370},{0x60,0x4112f0},{0x70,0x4113b0},{0x74,0x4113c0},{0x78,0x411290},{0x7c,0x4112c0}};
 for(const auto& v:virtuals)need(m.r32(0x785ef8u+v[0])==v[1],"authentic normal surface addresspoint");
 need(s.fp.image.word(8)==0xffffu&&(s.fp.image.word(4)&~0x3800u)==0,"empty initial FP with finite status");
 constexpr unsigned short controls[]{0x037f,0x077f,0x0b7f,0x0f7f,0x027f,0x067f,0x0a7f,0x0e7f,0x007f,0x047f,0x087f,0x0c7f};
 bool control=false;for(auto value:controls)control|=s.fp.image.word(0)==value;need(control,"qualified12 control words");
 need(surface120fd0_fp::initial_bounds(s.fp)==0xc04c800000000000ull,"actual initial zero-minus57 bounds");
 U final_center=0;
 for(U n=0;n<80;++n){
  // 521024..521060 and actual438140: retain the allocation/construction order.
  const U surface=allocate(m,s,op,32);
  m.w32(surface+4,256);m.w32(surface+8,128);m.w32(surface+12,0);
  m.w32(surface,0x785f8cu);m.w32(surface+16,1);
  m.w32(surface+20,0);m.w32(surface+24,32768);m.w8(surface+28,0);
  const U pixels=allocate(m,s,op,32768);
  m.w32(surface+20,pixels);m.w8(surface+28,1);m.w32(surface,0x785ef8u);
  m.w32(0xa39a78u+n*4,surface);
  // The authentic normal785EF8 full rectangle is256x128, one byte/pixel.
  // Root's fill/unlock followed by its own lock leaves exactly count1.
  for(U p=0;p<32768;p+=4)m.w32(pixels+p,0xffffffffu);
  m.w32(surface+12,1);
  // Independent table-domain proof: all8191 noncenter distances are positive,
  // outside [-57,0], with no external call between those calculations and
  // the last center. The last center/bounds overwrite both touched FP slots
  // and establish all observable numeric state before the next allocation.
  const U sine_index=surface120fd0_fp::begin_center(s.fp,n);
  const auto intensity=surface120fd0_fp::finish_center_and_bounds(s.fp,m.r32(0x7ea104u+sine_index*4));
  need(intensity==0,"actual finite center intensity");
  final_center=pixels+0x4080u;m.w8(final_center,0);
 }
 m.w8(0xa39bf4u,1);
 s.ax=0xa39bb8u;s.cx=0;s.dx=final_center;
 (void)model::integer::sub(s.ax,0xa39bb8u,32,s.arithmetic_flags);
 model::finish(m,s,frame,0);
}
}
