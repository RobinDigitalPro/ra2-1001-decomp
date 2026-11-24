#include "recovered/recovery_b1666.hpp"
#include <cstring>
#include <stdexcept>
#include <string>
namespace ra2::recovered::b1666 {namespace {
namespace leaf=ra2::recovered::leaf;
using namespace ra2::recovered::floating_b61;
namespace floating_b61=ra2::recovered::floating_b61;
using State=ra2::recovered::recovery_b566::State;
using Frame=ra2::recovered::recovery_b566::Frame;
using ra2::recovered::recovery_b566::finish;
using ra2::recovered::recovery_b566::string_instruction;
using ra2::recovered::recovery_b566::Kind;
using ra2::recovered::recovery_b566::Repeat;
using ra2::recovered::recovery_b566::reverse_divide32;
using ra2::recovered::recovery_b566::reverse_divide64;
namespace integer=ra2::recovered::direct_b33::integer;
namespace numeric_b88=ra2::recovered::numeric_b88;
namespace fp=ra2::platform::x87;

inline void need(bool ok,const char*why){if(!ok)throw std::domain_error(why);}
#include "recovered/recovery_b1666_methods.inc"
inline void invoke(Memory&m,State&s,Frame&f,unsigned target,unsigned continuation,const Operations&op){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 if(target==0x76f398u){
  // Independently byte-proved cold va_list path for exactly L"%ld" and1..9.
  // The ignored l qualifier keeps int32: one DWORD advance, one decimal digit,
  // one genuine mbtowc counter pair before the WORD append, then two NUL bytes.
  const unsigned output=m.r32(child.entry_sp+4),format=m.r32(child.entry_sp+8),list=m.r32(child.entry_sp+12),value=m.r32(list);
  need(format==0x7c0a34u&&m.r16(format)==37&&m.r16(format+2)==108&&m.r16(format+4)==100&&m.r16(format+6)==0&&value>=1&&value<=9,"B1666 exact authenticated %ld/one positive DWORD");
  need(m.r8(0x79c740)==7&&m.r8(0x79c72d)==0x60&&m.r32(0x7764c3)==0x775ed2&&m.r8(0x79c73a)==0x78,"B1666 new modifier DFA bytes retained");
  need(m.r32(0xb10530)==0&&m.r32(0xb10e20)==0&&m.r32(0xb10e24)==0&&m.r32(0x81776c)==1,"B1666 cold ordinary numeric locale projection");
  need(op.atomic_context&&op.interlocked&&op.increment_iat==0x7851bcu&&op.decrement_iat==0x7851c0u,"B1666 exact genuine atomic IAT identities");
  const auto inc=m.r32(op.increment_iat),dec=m.r32(op.decrement_iat);need(inc&&dec&&inc!=dec,"B1666 actual resolved atomic targets");
  need(op.interlocked(op.atomic_context,m,inc,0xb10e24,true,s.fp)==1&&m.r32(0xb10e24)==1,"B1666 actual full increment/owned counter poststate");
  need(op.interlocked(op.atomic_context,m,dec,0xb10e24,false,s.fp)==0&&m.r32(0xb10e24)==0,"B1666 actual full decrement/owned counter poststate");
  m.w16(output,static_cast<unsigned short>(48+value));m.w16(output+2,0);s.ax=1;
  finish(m,s,child,0);f.sp=child.sp;return;
 }
 if(target&&target==op.set_rect_target){need(op.window_context&&op.set_rect&&m.r32(0x7854a8)==target,"genuine USER32 SetRect binding");s.ax=op.set_rect(op.window_context,m,target,child.entry_sp,s.fp);finish(m,s,child,20);f.sp=child.sp;return;}
 // Atomic providers remain typed placeholders until parent pins the genuine IATs and formatter contract.
 if((op.increment_iat&&target==m.r32(op.increment_iat))||(op.decrement_iat&&target==m.r32(op.decrement_iat)))throw std::domain_error("B1666 atomic dispatch proof pending; no provider result substitution");
 switch(target){
case 0x411290u:f_00011290(m,s,child,op);break;
case 0x4112c0u:f_000112c0(m,s,child,op);break;
case 0x4112d0u:f_000112d0(m,s,child,op);break;
case 0x4112f0u:f_000112f0(m,s,child,op);break;
case 0x411370u:f_00011370(m,s,child,op);break;
case 0x4113b0u:f_000113b0(m,s,child,op);break;
case 0x4113c0u:f_000113c0(m,s,child,op);break;
case 0x41fdf0u:f_0001fdf0(m,s,child,op);break;
case 0x42bcd0u:f_0002bcd0(m,s,child,op);break;
case 0x4312f0u:f_000312f0(m,s,child,op);break;
case 0x431310u:f_00031310(m,s,child,op);break;
case 0x431320u:f_00031320(m,s,child,op);break;
case 0x431370u:f_00031370(m,s,child,op);break;
case 0x431550u:f_00031550(m,s,child,op);break;
case 0x4315d0u:f_000315d0(m,s,child,op);break;
case 0x431790u:f_00031790(m,s,child,op);break;
case 0x4317a0u:f_000317a0(m,s,child,op);break;
case 0x431b80u:f_00031b80(m,s,child,op);break;
case 0x431ec0u:f_00031ec0(m,s,child,op);break;
case 0x431f70u:f_00031f70(m,s,child,op);break;
case 0x432010u:f_00032010(m,s,child,op);break;
case 0x432210u:f_00032210(m,s,child,op);break;
case 0x434f80u:f_00034f80(m,s,child,op);break;
case 0x435400u:f_00035400(m,s,child,op);break;
case 0x435420u:f_00035420(m,s,child,op);break;
case 0x438140u:f_00038140(m,s,child,op);break;
case 0x438290u:f_00038290(m,s,child,op);break;
case 0x453ab0u:f_00053ab0(m,s,child,op);break;
case 0x485b40u:f_00085b40(m,s,child,op);break;
case 0x4895f0u:f_000895f0(m,s,child,op);break;
case 0x494310u:f_00094310(m,s,child,op);break;
case 0x497610u:f_00097610(m,s,child,op);break;
case 0x497840u:f_00097840(m,s,child,op);break;
case 0x497920u:f_00097920(m,s,child,op);break;
case 0x49ebd0u:f_0009ebd0(m,s,child,op);break;
case 0x49f150u:f_0009f150(m,s,child,op);break;
case 0x4fe550u:f_000fe550(m,s,child,op);break;
case 0x5f5e90u:f_001f5e90(m,s,child,op);break;
case 0x634310u:f_00234310(m,s,child,op);break;
case 0x696d50u:f_00296d50(m,s,child,op);break;
case 0x75fcd0u:f_0035fcd0(m,s,child,op);break;
case 0x75fd00u:f_0035fd00(m,s,child,op);break;
case 0x760ad0u:f_00360ad0(m,s,child,op);break;
default:throw std::domain_error("B1666 unprovided authentic target="+std::to_string(target));}f.sp=child.sp;
}
}
Result run(Memory&world,unsigned entry,unsigned char*storage,unsigned size,const NativeState&in,const fp::Image&incoming,const Operations&op){
 need(storage&&size==0x8000u+68u&&entry>=0x8000u&&!(entry&7u)&&std::uint64_t(entry)+68u<=0x100000000ull&&std::uint64_t(reinterpret_cast<std::uintptr_t>(storage))+0x8000u==entry,"B1666 actual owned32KB+68 aligned frame");
 need(!(in.flags&0x400u),"B1666 DF0");const unsigned low=entry-0x8000u;need(std::uint64_t(entry)+68u<=0x18000000u||low>=0x18100000u,"arena/private disjoint");need(std::uint64_t(entry)+68u<=0x400000u||low>=0xb28000u,"image/private disjoint");
 std::array<unsigned,16>before{};unsigned ret;std::memcpy(before.data(),storage+0x8004,64);std::memcpy(&ret,storage+0x8000,4);
 Memory m=world;leaf::Memory local(storage,low,size);m.add(local);
 need(before[0]==1&&m.r32(in.cx+4)>=1&&m.r32(in.cx+4)<=9&&m.r8(in.cx+10)==0,"B1666 force/positive single decimal digit/optional pool excluded");
 const unsigned surface=m.r32(0x821c88),font=m.r32(0x836d30),context=m.r32(0x81a70c),desc=m.r32(font+4),map=m.r32(desc+24),glyph=m.r32(desc+28),codec=m.r32(context+0xd0);
 need(m.r32(surface)==0x785ef8&&m.r32(surface+4)==32&&m.r32(surface+8)==24&&m.r32(surface+12)==0&&m.r32(surface+16)==2&&m.r32(surface+24)==1536,"B1666 normal borrowed32x24RGB565 C0");
 need(m.r32(context)==0x788f70&&m.r32(context+4)==2&&m.r32(context+8)!=0&&m.r32(codec)==0x789140&&m.r32(codec+4)==m.r32(context+0x174)&&m.r32(0x789144)==0x4895f0,"B1666 authentic bpp2 D0 descriptor; no bpp1 substitution");
 need(m.r32(0x821fac)==0&&m.r32(0x8198f4)==0,"B1666 no cyclic/auxiliary providers");
 need(m.r32(font+24)==1&&m.r32(font+28)==2&&m.r32(desc+8)==2&&m.r32(desc+20)==3&&m.r8(glyph)==2&&m.r8(glyph+1)==0xc0&&m.r8(glyph+2)==0x80,"B1666 borrowed2x2 glyph withspacing1");for(unsigned c=49;c<=57;++c)need(m.r16(map+2*c)==1,"B1666 postparsed digit map ordinal1");
 State s{};s.ax=in.ax;s.cx=in.cx;s.dx=in.dx;s.bx=in.bx;s.bp=in.bp;s.si=in.si;s.di=in.di;s.arithmetic_flags=in.flags;s.fp.image=incoming;Frame f{entry,entry,ret};f_00094310(m,s,f,op);
 need(f.sp==entry+8u&&s.ax==entry-0x18u,"B1666 RET4/full actual output-pair pointer");need(s.bx==in.bx&&s.bp==in.bp&&s.si==in.si&&s.di==in.di&&!(s.arithmetic_flags&0x400u),"B1666 preserved nonvolatile/DF");Result result{s.ax,s,{}};std::memcpy(result.words.data(),storage+0x8004,64);need(result.words==before,"B1666 exact all16 caller poststate");return result;
}
}
