#include "recovered/recovery_b1453.hpp"
#include "recovered/floating_composed_b43_memory.hpp"
#include "recovered/numeric_b97.hpp"
#include "recovered/recovery_b930.hpp"
#include "recovered/numeric_b88_detail.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1453 {
namespace {
using U=std::uint32_t;using Q=std::uint64_t;
constexpr U base=0x7da00000u,T=base+0x8000u,carrier=base+0x6000u;
struct Sequence {
 std::array<std::uint8_t,0x10000> bytes{};
 leaf::Memory local{bytes.data(),base,U(bytes.size())};
 Memory m;floating_b39::State s{};
 Sequence(Memory&outer,const Inputs&i):m(outer){m.add(local);s.fp=i.fp;s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.arg=i.arg;s.arithmetic_flags=i.arithmetic_flags;}
 void copy(U dst,U src,U words){for(U k=0;k<words;++k)m.w32(dst+4*k,m.r32(src+4*k));}
 void vector(U dst,U x,U y,U z){m.w32(dst,x);m.w32(dst+4,y);m.w32(dst+8,z);}
 void identity(U dst){for(U k=0;k<12;++k)m.w32(dst+4*k,(k==0||k==5||k==10)?0x3f800000u:0u);s.ax=0;s.dx=0x3f800000u;s.cx=dst;}
 void identity_quaternion(U dst){vector(dst,0,0,0);m.w32(dst+12,0x3f800000u);s.ax=0;s.dx=0x3f800000u;s.cx=dst;}
 void call(U rva,U cx,U dx,std::initializer_list<U> args){
  s.cx=cx;s.dx=dx;U k=0;for(U a:args)s.arg[k++]=a;
  // Valid carrier for the accepted helper's 16-word ABI bookkeeping. Only
  // actual explicit helper arguments are semantic inputs; the rest are not
  // proposed original stack producers and cannot reach the outer arguments.
  m.w32(carrier,0x70cc20u);for(U j=0;j<16;++j)m.w32(carrier+4+4*j,s.arg[j]);
  floating_b39::Function fn=nullptr;
  for(auto&e:floating_b39::entries_a())if(e.rva==rva)fn=e.function;
  for(auto&e:floating_b39::entries_b())if(e.rva==rva)fn=e.function;
  for(auto&e:floating_callers_b40::entries_a())if(e.rva==rva)fn=e.function;
  for(auto&e:floating_composed_b43::entries_a())if(e.rva==rva)fn=e.function;
  if(!fn)throw std::logic_error("B1453 unclosed typed helper");
  floating_b39::Frame f{};f.entry_sp=f.return_sp=f.sp=carrier;f.outer_return=0x70cc20u;
  fn(m,s,f,{});
 }
 void numeric(U va,U cx,U dx,std::initializer_list<U>args){
  Inputs child{};child.fp=s.fp;child.ax=s.ax;child.cx=cx;child.dx=dx;child.arg=s.arg;U k=0;for(U a:args)child.arg[k++]=a;
  if(va==0x58cd50u)s.ax=numeric_b97::fun_0058cd50(m,child);
  else if(va==0x61a540u)s.ax=numeric_b97::fun_0061a540(m,child);
  else if(va==0x58d680u)s.ax=numeric_b97::fun_0058d680(m,child);
  else throw std::logic_error("B1453 numeric dispatch");s.fp=child.fp;
 }
 void transform(U output,U matrix,U vec){call(0x18e180u,output,matrix,{vec});}
 void matrix(U dst,U a,U b){call(0x18ccf0u,dst,s.dx,{a,b});}
 void quaternion(U dst,U axis,U angle){
  numeric(0x61a540u,T+0x20,axis,{angle});
  call(0x219de0u,dst,s.dx,{T+0x10,T+0x20});
 }
 U cast64(U address){s.fp.load64(floating_b39::read64(m,address));return s.fp.pop32();}
 Q helper64(U rva,Q value){call(rva,s.cx,s.dx,{U(value),U(value>>32)});return s.fp.pop64();}
};
}
std::uint32_t fun_0070cc20(Memory&outer,const Inputs&i){
 i.fp.require_masked();Sequence q(outer,i);auto&m=q.m;auto&fp=q.s.fp;
 // The staggered original prologue produces T+DC and T+48 before either read.
 const U ebp=q.cast64(0xadee18u);m.w32(T+0xdcu,ebp);
 const U ebx=q.cast64(0xadf220u);m.w32(T+0x48u,ebx);
 constexpr U diagonal_angles[]{0x3f490e56u,0x4016cac1u,0x407b51ecu,0x40afec8bu};
 constexpr U diagonal_locals[]{T+0xa0u,T+0x7cu,T+0xc4u,T+0xacu};
 for(U k=0;k<4;++k){
  const U axis=k?T+0x30u:T+0x3cu,vec=k?T+0x3cu:T+0x30u;
  q.vector(axis,0,0,0x3f800000u);q.vector(vec,0x3f800000u,0,0);
  q.numeric(0x58cd50u,T+0x4cu,q.s.dx,{axis,diagonal_angles[k]});
  q.transform(T+0x10u,T+0x4cu,vec);q.copy(diagonal_locals[k],T+0x10u,3);
 }
 q.vector(T+0xd0u,0x3f800000u,0,0);q.vector(T+0xb8u,0,0x3f800000u,0);
 q.vector(T+0x88u,0xbf800000u,0,0);q.vector(T+0x94u,0,0xbf800000u,0);
 constexpr U diagonals[]{0x407b51ecu,0x4016cac1u,0x3f490e56u,0x40afec8bu};
 constexpr U diagonal_axes[]{T+0xc4u,T+0x7cu,T+0xa0u,T+0xacu};
 constexpr U cardinals[]{0x40490e56u,0x3fc90e56u,0u,0x4096cac1u};
 constexpr U cardinal_axes[]{T+0x88u,T+0xb8u,T+0xd0u,T+0x94u};
 q.identity(0xadee20u);
 // Original interleaves four matrix calls with the four quaternion calls in
 // each group. Keep those phases and their physical x87 history unchanged.
 for(U group=0;group<4;++group){
  U ma=0xadee50u+group*0xc0u,qa=0xadf268u+group*0x40u;
  U angle=(group==1||group==2)?ebp:ebx;
  for(U k=0;k<4;++k)q.matrix(ma+48*k,group?cardinals[k]:diagonals[k],angle);
  for(U k=0;k<4;++k)q.quaternion(qa+16*k,group?cardinal_axes[k]:diagonal_axes[k],angle);
 }
 for(U k=0;k<4;++k)q.identity(0xadf150u+48*k);
 for(U k=0;k<4;++k)q.identity_quaternion(0xadf368u+16*k);
 for(U n=0;n<256;++n){
  m.w32(T+0x48u,n);q.identity(T+0xe0u);
  fp.load_integer32(n);fp.multiply32(m.r32(0x7998c4u));const U angle=fp.pop32();
  q.call(0x18d7a0u,T+0xe0u,q.s.dx,{angle});q.vector(T+0x3cu,0x3f800000u,0,0);
  q.transform(T+0x10u,T+0xe0u,T+0x3cu);q.copy(0xade1e8u+12*n,T+0x10u,3);
  fp.load32(m.r32(0x785738u));fp.load32(m.r32(0xade1ecu+12*n));fp.subtract_st0_st1();m.w32(T+0x30u,fp.pop32());
  fp.subtract32(m.r32(0xade1e8u+12*n));m.w32(T+0x34u,fp.pop32());m.w32(T+0x38u,0);
  q.copy(0xadf3b0u+12*n,T+0x30u,3);
  q.numeric(0x58cd50u,T+0x4cu,q.s.dx,{0xadf3b0u+12*n,m.r32(0x821decu)});
  q.transform(T+0x20u,T+0x4cu,0xade1e8u+12*n);q.copy(0xade1e8u+12*n,T+0x20u,3);
 }
 q.identity(0xae0088u);
 constexpr U shifted[]{0x4096cac1u,0x40490e56u,0x3fc90e56u,0u};
 for(U group=0;group<4;++group){U angle=(group==1||group==2)?ebp:ebx;
  for(U k=0;k<4;++k)q.matrix(0xae00b8u+group*0xc0u+48*k,group?diagonals[k]:shifted[k],angle);
 }
 q.identity_quaternion(0xade098u);
 constexpr U shifted_axes[]{T+0x94u,T+0x88u,T+0xb8u,T+0xd0u};
 for(U group=0;group<4;++group){U angle=(group==1||group==2)?ebp:ebx;
  for(U k=0;k<4;++k)q.quaternion(0xade0a8u+group*0x40u+16*k,group?diagonal_axes[k]:shifted_axes[k],angle);
 }
 for(U k=0;k<4;++k)q.identity(0xae03b8u+48*k);
 for(U k=0;k<4;++k)q.identity_quaternion(0xade1a8u+16*k);
 q.identity(0xadf228u);fp.load64(floating_b39::read64(m,0xadee10u));fp.change_sign();const U neg60=fp.pop32();
 q.call(0x18d560u,0xadf228u,q.s.dx,{neg60});
 fp.load64(floating_b39::read64(m,0xadf3a8u));fp.change_sign();const U neg45=fp.pop32();q.call(0x18d7a0u,0xadf228u,q.s.dx,{neg45});
 for(U k=0;k<4;++k)q.identity(0xadffb8u+48*k);
 for(auto pair:std::array<std::array<U,2>,10>{{{0xadffccu,0xbf800000u},{0xadffe8u,0u},{0xadffecu,0x3f800000u},{0xadfff8u,0x3f800000u},{0xadfffcu,0u},{0xae0018u,0xbf800000u},{0xae0048u,0u},{0xae004cu,0xbf800000u},{0xae0058u,0xbf800000u},{0xae005cu,0u}}})m.w32(pair[0],pair[1]);
 i.fp=fp;return 0;
}
ra2::platform::x87::Image prepare_original_inputs(Memory&outer){
 Inputs in{};in.fp.image=ra2::platform::x87::Image::empty(0x027fu);
 Sequence q(outer,in);auto&m=q.m;auto&fp=q.s.fp;
 if(m.r32(0xb1042cu)!=0)throw std::domain_error("B1453 genuine CRT ordinary numeric mode");
 // 70C8A0 -> 76DAF0 wrapper -> unchanged real power core B930/B928.
 fp.load64(floating_b39::read64(m,0x785700u));fp.load64(floating_b39::read64(m,0x7856f8u));fp.exchange_st1();
 const Q base64=fp.pop64(),exponent=fp.store64();
 Inputs power{};power.fp=fp;power.ax=U(exponent>>32);power.arg[0]=U(base64);power.arg[1]=U(base64>>32);power.arg[2]=U(exponent);power.arg[3]=U(exponent>>32);
 recovery_b930::fun_0076DB12(m,power);fp=power.fp;numeric_b88::detail::reg<0xd8c0>(fp);
 floating_b39::write64(m,0xadee08u,q.helper64(0xba080u,fp.pop64()));
 for(auto pair:std::array<std::array<U,2>,3>{{{0x785710u,0xadf3a8u},{0x785718u,0xadee10u},{0x785720u,0xadede8u}}}){
  fp.load64(floating_b39::read64(m,0x7998b8u));fp.multiply64(floating_b39::read64(m,pair[0]));floating_b39::write64(m,pair[1],fp.pop64());
 }
 fp.load64(floating_b39::read64(m,0xadede8u));fp.subtract64(floating_b39::read64(m,0xadee10u));
 Q arg=fp.pop64();q.call(0xba190u,q.s.cx,q.s.dx,{U(arg),U(arg>>32)});
 fp.multiply64(floating_b39::read64(m,0xadee08u));fp.multiply64(floating_b39::read64(m,0x785728u));q.call(0x36aa50u,q.s.cx,q.s.dx,{});m.w32(0xae0478u,q.s.ax);
 fp.load_integer32(m.r32(0xae0478u));fp.multiply64(floating_b39::read64(m,0x785730u));floating_b39::write64(m,0xadee18u,q.helper64(0xba220u,fp.pop64()));
 fp.load_integer32(2*m.r32(0xae0478u));fp.divide64(floating_b39::read64(m,0xadee08u));floating_b39::write64(m,0xadf220u,q.helper64(0xba220u,fp.pop64()));
 q.identity(T+0x18u);m.w32(0x821decu,m.r32(0x785cf0u));q.numeric(0x58d680u,T+0x18u,q.s.dx,{m.r32(0x821decu)});
 q.vector(T,0xbf3504e6u,0xbf3504e6u,0);q.transform(T+0xcu,T+0x18u,T);
 q.copy(0x821df0u,T+0xcu,3);fp.load32(m.r32(0x821df0u));fp.multiply32(m.r32(0x7998c0u));m.w32(0x821da4u,0);m.w32(0x821da8u,0);m.w32(0x821da0u,fp.pop32());return fp.image;
}
}
