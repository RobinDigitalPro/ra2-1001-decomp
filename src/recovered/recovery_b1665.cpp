#include "recovered/recovery_b1665.hpp"
#include <cstring>
#include <stdexcept>
namespace ra2::recovered::b1665 {namespace {
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

inline void finish_stack_probe(Memory&m,State&,Frame&f,unsigned cleanup,unsigned pc){if(pc!=0x76f1beu||cleanup||f.entry_sp<0x1030u||f.sp!=f.entry_sp-0x1030u)throw std::runtime_error("exact authenticated stack-probe return relocation");if(f.pop(m)!=f.outer_return)throw std::runtime_error("actual produced stack-probe continuation");}
#include "recovered/recovery_b1665_methods.inc"
inline void invoke(Memory&m,State&s,Frame&f,unsigned target,unsigned continuation,const Operations&op){f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
if(target==op.set_rect_target&&op.set_rect){if(!op.window_context||target!=m.r32(0x7854a8))throw std::domain_error("actual SetRect target/context");s.ax=op.set_rect(op.window_context,m,target,child.entry_sp,s.fp);finish(m,s,child,20);f.sp=child.sp;return;}
switch(target){
case 0x5f84d0u:f_001f84d0(m,s,child,op);break;
case 0x411290u:f_00011290(m,s,child,op);break;
case 0x4112c0u:f_000112c0(m,s,child,op);break;
case 0x4112d0u:f_000112d0(m,s,child,op);break;
case 0x4112f0u:f_000112f0(m,s,child,op);break;
case 0x411370u:f_00011370(m,s,child,op);break;
case 0x4113b0u:f_000113b0(m,s,child,op);break;
case 0x4113c0u:f_000113c0(m,s,child,op);break;
case 0x41fdf0u:f_0001fdf0(m,s,child,op);break;
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
case 0x435420u:f_00035420(m,s,child,op);break;
case 0x453ab0u:f_00053ab0(m,s,child,op);break;
case 0x5f5e90u:f_001f5e90(m,s,child,op);break;
case 0x634310u:f_00234310(m,s,child,op);break;
case 0x75fcd0u:f_0035fcd0(m,s,child,op);break;
case 0x75fd00u:f_0035fd00(m,s,child,op);break;
case 0x76ef45u:f_0036ef45(m,s,child,op);break;
case 0x76ef62u:f_0036ef62(m,s,child,op);break;
case 0x76f190u:f_0036f190(m,s,child,op);break;
default:throw std::domain_error("B1665 unresolved authentic target; fail closed");}f.sp=child.sp;}
void need(bool v,const char*s){if(!v)throw std::domain_error(s);}
}
Result run(Memory&world,unsigned entry,unsigned char*storage,unsigned size,const NativeState&in,const fp::Image&incoming,const Operations&op){
 need(storage&&size==0x8000u+68u&&entry>=0x8000u&&!(entry&7u)&&std::uint64_t(entry)+68u<=0x100000000ull&&std::uint64_t(reinterpret_cast<std::uintptr_t>(storage))+0x8000u==entry,"B1665 actual aligned owned32KB+68 frame");
 need(!(in.flags&0x400u),"B1665 qualified DF0");const unsigned low=entry-0x8000u;need(std::uint64_t(entry)+68u<=0x18000000u||low>=0x18100000u,"B1665 arena/private disjoint");need(std::uint64_t(entry)+68u<=0x400000u||low>=0xb28000u,"B1665 image/private disjoint");
 constexpr unsigned short controls[]{0x037f,0x077f,0x0b7f,0x0f7f,0x027f,0x067f,0x0a7f,0x0e7f,0x007f,0x047f,0x087f,0x0c7f};bool cw=false;for(auto c:controls)cw|=incoming.word(0)==c;
 need(cw&&incoming.word(8)==0xffff&&(incoming.word(4)&~0x3800u)==0,"B1665 finite12CW/eightTOP/empty tags");for(unsigned k=28;k<108;++k)need(incoming.bytes[k]==static_cast<unsigned char>(k*7+11),"B1665 qualified opaque80 input");
 std::array<unsigned,16>before{};unsigned ret;std::memcpy(before.data(),storage+0x8004,64);std::memcpy(&ret,storage+0x8000,4);
 Memory m=world;leaf::Memory local(storage,low,size);m.add(local);
 constexpr unsigned B=0x18000000u,font=B+0x2000,desc=B+0x3000,table=B+0x4000,glyph=B+0x5000,surface=B+0x6000,pixels=B+0x7000,text=B+0x8000,rect=B+0x9000,scroll=B+0xa000;
 need(in.cx==surface&&in.dx==rect&&before[0]==text&&before[1]==0&&before[2]==font&&before[3]==0xffffff&&before[4]==scroll&&before[5]==0&&before[6]==0&&before[7]==1&&before[8]==0,"B1665 finite nine actual caller arguments");
 need(m.r32(0x836d18)==surface&&m.r32(0x836d30)==font&&m.r8(0xa28968)==1,"B1665 borrowed normal surface/font graph");
 need(m.r32(surface)==0x785ef8&&m.r32(surface+4)==32&&m.r32(surface+8)==24&&m.r32(surface+12)==0&&m.r32(surface+16)==2&&m.r32(surface+20)==pixels&&m.r32(surface+24)==1536&&m.r8(surface+28)==0,"B1665 exact borrowed32x24 BSurface header");
 need(m.r32(font+4)==desc&&m.r32(font+8)==0&&m.r32(font+0x18)==1&&m.r32(font+0x1c)==2&&m.r32(font+0x20)==0&&m.r16(font+0x24)==0&&m.r32(font+0x2c)==0,"B1665 parsed one-font projection");
 need(m.r32(desc+4)==2&&m.r32(desc+8)==2&&m.r32(desc+0x10)==1&&m.r32(desc+0x14)==3&&m.r32(desc+0x18)==table&&m.r32(desc+0x1c)==glyph&&m.r16(table+65*2)==1&&m.r8(glyph)==2&&m.r8(glyph+1)==0xc0&&m.r8(glyph+2)==0x80,"B1665 parsed2x2 A glyph");
 need(m.r16(text)==65&&m.r16(text+2)==0&&m.r32(rect)==1&&m.r32(rect+4)==1&&m.r32(rect+8)==8&&m.r32(rect+12)==2&&m.r32(scroll)==0,"B1665 finite text/rectangle/scroll");
 constexpr unsigned shifts[]{11,3,0,3,5,2};for(unsigned k=0;k<6;++k)need(m.r32(0x83b2e8+4*k)==shifts[k],"B1665 standard565 shifts");
 constexpr unsigned slots[][2]={{0x14,0x75fcd0},{0x5c,0x411370},{0x60,0x4112f0},{0x70,0x4113b0},{0x74,0x4113c0},{0x78,0x411290},{0x7c,0x4112c0},{0x80,0x4112d0}};for(const auto&v:slots)need(m.r32(0x785ef8+v[0])==v[1],"B1665 authentic exact BSurface addresspoint/target");
 need(op.probe_context&&op.access_probe&&op.window_context&&op.set_rect&&op.set_rect_target&&m.r32(0x7854a8)==op.set_rect_target,"B1665 genuine qualified access-probe and USER32 SetRect providers");
 State s{};s.ax=in.ax;s.cx=in.cx;s.dx=in.dx;s.bx=in.bx;s.bp=in.bp;s.si=in.si;s.di=in.di;s.arithmetic_flags=in.flags;s.fp.image=incoming;Frame f{entry,entry,ret};f_001f84d0(m,s,f,op);
 need(f.sp==entry+40u&&s.ax==0u,"B1665 exact RET36/fullEAX0");need(s.bx==in.bx&&s.bp==in.bp&&s.si==in.si&&s.di==in.di&&!(s.arithmetic_flags&0x400u),"B1665 nonvolatiles/DF");
 Result result{s.ax,s,{}};std::memcpy(result.words.data(),storage+0x8004,64);need(result.words==before,"B1665 all16 exact caller poststate");return result;
}
}
