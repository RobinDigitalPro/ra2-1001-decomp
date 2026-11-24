#include "recovered/recovery_b1663.hpp"
#include <cstring>
#include <stdexcept>
namespace ra2::recovered::b1663 { namespace {
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

#include "recovered/recovery_b1663_methods.inc"
inline void invoke(Memory&m,State&s,Frame&f,unsigned target,unsigned continuation,const Operations&op){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
if(target==0x76d957u){if(!op.heap_context||!op.allocate)throw std::domain_error("genuine ordinary allocator callback required");const unsigned actual=op.allocate(op.heap_context,m,m.r32(child.entry_sp+4),s.fp);s.ax=actual;finish(m,s,child,0);f.sp=child.sp;return;}
if(target==0x76d67bu){if(!op.heap_context||!op.release)throw std::domain_error("genuine ordinary release callback required");const unsigned actual=op.release(op.heap_context,m,m.r32(child.entry_sp+4),s.fp);s.ax=actual;finish(m,s,child,0);f.sp=child.sp;return;}
switch(target){
case 0x57eeb0u:f_0017eeb0(m,s,child,op);break;
case 0x47b190u:f_0007b190(m,s,child,op);break;
case 0x57ece0u:f_0017ece0(m,s,child,op);break;
case 0x58a920u:f_0018a920(m,s,child,op);break;
case 0x58be90u:f_0018be90(m,s,child,op);break;
case 0x62fde0u:f_0022fde0(m,s,child,op);break;
case 0x42d3e0u:f_0002d3e0(m,s,child,op);break;
case 0x76aa50u:f_0036aa50(m,s,child,op);break;
case 0x576620u:f_00176620(m,s,child,op);break;
case 0x557340u:f_00157340(m,s,child,op);break;
case 0x557280u:f_00157280(m,s,child,op);break;
case 0x42add0u:f_0002add0(m,s,child,op);break;
case 0x545500u:f_00145500(m,s,child,op);break;
case 0x42d4a0u:f_0002d4a0(m,s,child,op);break;
case 0x42d050u:f_0002d050(m,s,child,op);break;
default:throw std::domain_error("B1663 unresolved authentic target; fail closed");}f.sp=child.sp;
}
struct ExpectedByte{unsigned address;unsigned char value;};
constexpr ExpectedByte ro_bytes[]={
{0x785708u,0x00u},
{0x785709u,0x00u},
{0x78570au,0x00u},
{0x78570bu,0x00u},
{0x78570cu,0x00u},
{0x78570du,0x00u},
{0x78570eu,0xf0u},
{0x78570fu,0x3fu},
{0x786630u,0x18u},
{0x786631u,0x2du},
{0x786632u,0x44u},
{0x786633u,0x54u},
{0x786634u,0xfbu},
{0x786635u,0x21u},
{0x786636u,0xf9u},
{0x786637u,0x3fu},
{0x7867f8u,0x00u},
{0x7867f9u,0x00u},
{0x7867fau,0x80u},
{0x7867fbu,0x3fu},
{0x7879b8u,0x18u},
{0x7879b9u,0x2du},
{0x7879bau,0x44u},
{0x7879bbu,0x54u},
{0x7879bcu,0xfbu},
{0x7879bdu,0x21u},
{0x7879beu,0x19u},
{0x7879bfu,0x40u},
{0x787a80u,0x18u},
{0x787a81u,0x2du},
{0x787a82u,0x44u},
{0x787a83u,0x54u},
{0x787a84u,0xfbu},
{0x787a85u,0x21u},
{0x787a86u,0xe9u},
{0x787a87u,0x3fu},
{0x788158u,0x18u},
{0x788159u,0x2du},
{0x78815au,0x44u},
{0x78815bu,0x54u},
{0x78815cu,0xfbu},
{0x78815du,0x21u},
{0x78815eu,0x09u},
{0x78815fu,0x40u},
{0x788d80u,0x00u},
{0x788d81u,0x00u},
{0x788d82u,0x00u},
{0x788d83u,0x3fu},
{0x790ca8u,0x00u},
{0x790ca9u,0x00u},
{0x790caau,0x00u},
{0x790cabu,0x00u},
{0x790cacu,0x00u},
{0x790cadu,0x00u},
{0x790caeu,0x00u},
{0x790cafu,0x40u},
{0x790cb0u,0x00u},
{0x790cb1u,0x00u},
{0x790cb2u,0x00u},
{0x790cb3u,0x00u},
{0x790cb4u,0x00u},
{0x790cb5u,0x00u},
{0x790cb6u,0xf8u},
{0x790cb7u,0x3fu},
{0x790db0u,0x00u},
{0x790db1u,0x00u},
{0x790db2u,0x10u},
{0x790db3u,0x00u},
{0x790db4u,0x00u},
{0x790db5u,0x00u},
{0x790db6u,0xf0u},
{0x790db7u,0x3du},
{0x7875a0u,0xe0u},
{0x7875a1u,0xd3u},
{0x7875a2u,0x42u},
{0x7875a3u,0x00u},
{0x7875a4u,0x10u},
{0x7875a5u,0xceu},
{0x7875a6u,0x42u},
{0x7875a7u,0x00u},
{0x7875a8u,0x50u},
{0x7875a9u,0xd0u},
{0x7875aau,0x42u},
{0x7875abu,0x00u},
};
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
}
Result run(Memory&world,std::uint32_t entry,unsigned char*storage,unsigned size,const NativeState&in,const fp::Image&incoming,const Operations&op){
 need(storage&&size==0x8000u+68u&&entry>=0x8000u&&!(entry&7u)&&std::uint64_t(entry)+68u<=0x100000000ull&&std::uint64_t(reinterpret_cast<std::uintptr_t>(storage))+0x8000u==entry,"B1663 actual owned aligned32KB+68 frame");
 need(op.heap_context&&op.allocate&&op.release,"B1663 actual ordinary heap callbacks required");
 // Boundary I/O uses the owned physical storage. Root Memory accesses retain its observer.
 std::array<std::uint32_t,16>before{};std::memcpy(before.data(),storage+0x8004,64);std::uint32_t ret;std::memcpy(&ret,storage+0x8000,4);
 constexpr unsigned B=0x18000000u,self=B+0x400,table=B+0x10000,grid=B+0x20000,objects=B+0x30000,rect=B+0x50000,origin=rect+32;
 need(in.cx==self&&before[0]==1&&before[1]==0x3f000000&&before[2]==rect&&before[3]==origin&&before[4]==1,"B1663 finite positive ownership inputs");
 need(std::uint64_t(entry)+68u<=B||std::uint64_t(entry)-0x8000u>=std::uint64_t(B)+0x140000u,"B1663 public/private disjoint");
 constexpr unsigned short controls[]{0x037f,0x077f,0x0b7f,0x0f7f,0x027f,0x067f,0x0a7f,0x0e7f,0x007f,0x047f,0x087f,0x0c7f};bool cw=false;for(auto c:controls)cw|=incoming.word(0)==c;
 need(cw&&incoming.word(8)==0xffff&&(incoming.word(4)&~0x3800u)==0&&!(in.flags&0x400u),"B1663 finite CW/TOP/empty tags/DF input");
 for(unsigned k=28;k<108;++k)need(incoming.bytes[k]==static_cast<unsigned char>(k*7+11),"B1663 qualified opaque incoming80 pattern");
 Memory m=world;leaf::Memory local(storage,entry-0x8000u,size);m.add(local);
 need(m.r32(self+0x180)==1&&m.r32(self+0x184)==1&&m.r32(0x81a910)==3&&m.r32(0x81a914)==3&&m.r32(0x81a958)==table&&m.r32(0x836b4c)==7&&m.r32(0xa58634)==3&&m.r32(0xa58638)==9&&m.r32(0xa5863c)==grid&&m.r32(0xa58640)==3,"B1663 borrowed coherent Map projection");
 need(m.r32(rect)==0&&m.r32(rect+4)==0&&m.r32(rect+8)==7&&m.r32(rect+12)==7&&m.r32(origin)==0x00030003,"B1663 finite rectangle/origin");
 constexpr unsigned coords[]{0x00030001,0x00020002,0x00010003,0x00030002,0x00020003,0x00040002,0x00030003,0x00020004,0x00040003,0x00030004,0x00050003,0x00040004,0x00030005,0x00050004,0x00040005};
 for(unsigned y=0;y<7;++y)for(unsigned x=0;x<7;++x){unsigned expected=0;for(auto p:coords)if((p&65535u)==x&&(p>>16)==y)expected=p;unsigned at=grid+80*(y*7+x);need(m.r32(at)==expected&&m.r32(at+0x38)==((x==3&&y==3)?1u:0u)&&m.r32(at+0x3c)==0&&m.r8(at+0x4b)==0,"B1663 exact49 metadata records");}
 for(unsigned k=0;k<15;++k){unsigned p=coords[k],cell=objects+0x80*k;need(m.r32(table+4*((p>>16)*512+(p&65535)))==cell&&m.r32(cell+0x24)==p&&m.r32(cell+0x38)==((k==4||k==8)?0u:1u),"B1663 exact live cell/predicate fields");}
 need(m.r32(table+4*(6*512+4))==0,"B1663 iterator first-null point");constexpr unsigned delta[]{0xffff0000,0xffff0001,1,0x10001,0x10000,0x1ffff,0xffff,0xffffffff};for(unsigned k=0;k<8;++k)need(m.r32(0x839da0+4*k)==delta[k],"B1663 authentic neighbor initializer projection");
 need(m.r8(0xa581d8)==0&&m.r32(0xa581dc)==1&&m.r32(0xa581e0)==104&&m.r8(0xa57968)==1&&m.r32(0xa57970)==0&&m.r32(0xa57974)==0x3fe00000,"B1663 genuine finite RNG/populated cache input");
 for(unsigned k=0;k<250;++k){unsigned n=68+k;need(m.r32(0xa581e4+4*k)==((n*0x9e3779b9u)^(n<<16)^0xa5a53c3cu),"B1663 accepted leaf RNG n1 input");}
 need(m.r32(0x7875a0)==0x42d3e0&&m.r32(0x7875a8)==0x42d050&&m.r32(0x7c3a04)==0xe7f,"B1663 authentic virtual bindings and FTOL cachedCW");
 for(const auto&b:ro_bytes)need(m.r8(b.address)==b.value,"B1663 exact authenticated math/virtual readonly input");
 State s{};s.ax=in.ax;s.cx=in.cx;s.dx=in.dx;s.bx=in.bx;s.bp=in.bp;s.si=in.si;s.di=in.di;s.arithmetic_flags=in.flags;s.fp.image=incoming;Frame f{entry,entry,ret};f_0017eeb0(m,s,f,op);
 need(f.sp==entry+24&&s.bx==in.bx&&s.bp==in.bp&&s.si==in.si&&s.di==in.di&&!(s.arithmetic_flags&0x400u),"B1663 exact RET20/nonvol/DF");
 need((s.ax&255u)==1&&s.fp.image.word(0)==0xe7f&&s.fp.image.word(4)==((incoming.word(4)&0x3800u)|0x20u)&&s.fp.image.word(8)==0xffff,"B1663 literal positive result/FP control status tags");
 Result result{s.ax,s,{}};std::memcpy(result.words.data(),storage+0x8004,64);need(result.words==before,"B1663 all16 exact caller poststate");return result;
}
}
