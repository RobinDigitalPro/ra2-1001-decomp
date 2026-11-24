#include "recovered/recovery_b1420.hpp"
#include "recovered/recovery_b511.hpp"
#include "recovered/numeric_b80.hpp"
#include "recovered/leaf_b21_a.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1420 {
namespace {
using U=std::uint32_t;constexpr U base=0x7dc00000u,T=base+0x1000u;
void need(bool b,const char* why){if(!b)throw std::domain_error(why);}
void slot(Memory& m,U surface,U offset,U target){need(m.r32(surface)==0x785ef8u&&m.r32(0x785ef8u+offset)==target,"B1420 actual software-surface provider");}
U format(Memory& m,U s){slot(m,s,0x70u,0x4113b0u);return m.r32(s+16u);}
U pitch(Memory& m,U s){slot(m,s,0x74u,0x4113c0u);slot(m,s,0x7cu,0x4112c0u);return m.r32(s+4u)*m.r32(s+16u);}
U lock(Memory& m,U s,U x,U y){slot(m,s,0x5cu,0x411370u);m.w32(s+12u,m.r32(s+12u)+1u);return m.r32(s+20u)+format(m,s)*x+pitch(m,s)*y;}
U unlock(Memory& m,U s){slot(m,s,0x60u,0x4112f0u);const U value=m.r32(s+12u)-1u;m.w32(s+12u,value);return(value&0xffffff00u)|1u;}
void bounds(Memory& m,U s,U out){slot(m,s,0x78u,0x411290u);m.w32(out,0u);m.w32(out+4u,0u);m.w32(out+8u,m.r32(s+4u));m.w32(out+12u,m.r32(s+8u));}
void palette_pixel(Memory& m,U mode,U dst,U src){
    need(m.r32(mode)==0x78942cu&&m.r32(0x789430u)==0x485fa0u,"B1420 actual format2 palette provider");
    // Same finite contiguous-memory adapter as accepted B1350. Actual operand
    // values and all256 palette words are retained; no pointer escapes.
    std::array<std::uint8_t,0x300> storage{};leaf::Memory view(storage.data(),0x1000u,U(storage.size()));
    view.w32(0x1004u,0x1100u);view.w8(0x1020u,m.r8(src));view.w16(0x1022u,m.r16(dst));
    const U table=m.r32(mode+4u);for(U k=0;k<256u;++k)view.w16(0x1100u+2u*k,m.r16(table+2u*k));
    leaf::Inputs q{};q.cx=0x1000u;q.arg[0]=0x1022u;q.arg[1]=0x1020u;q.arg[2]=1u;
    (void)leaf::fun_00485fa0(view,q);m.w16(dst,view.r16(0x1022u));
}
U draw(Memory& m,const Inputs& i,U destination,U context,U source,U source_rect,U point,U clip){
    need(m.r32(destination+4u)==1u&&m.r32(destination+8u)==1u&&m.r32(destination+16u)==2u&&m.r32(destination+12u)==0u,"B1420 valid borrowed one-pixel RGB565 destination");
    need(m.r32(source+4u)==1u&&m.r32(source+8u)==1u&&m.r32(source+16u)==1u&&m.r32(source+12u)==0u,"B1420 actual temporary one-byte source");
    need(m.r32(clip)==0u&&m.r32(clip+4u)==0u&&m.r32(clip+8u)==1u&&m.r32(clip+12u)==1u,"B1420 exact nonempty clip");
    need(m.r32(0x821facu)==0u&&m.r32(0x8198f4u)==0u,"B1420 optional depth and auxiliary rings absent");
    // Original49F0C0 arg4=0 writes17C before the null arg5 selector. The warm
    // accepted511 selector has its own disjoint private frame and returnsC.
    m.w32(context+0x17cu,0u);Inputs selection{};selection.cx=context;selection.arg[0]=0u;selection.fp=i.fp;
    need(m.r32(context+8u)!=0u,"B1420 authentic warm palette context");
    const U mode=recovery_b239::selectors511::select_85880(m,selection);i.fp=selection.fp;
    need(mode==m.r32(context+12u),"B1420 actual zero-flags palette selection");
    const U destination_rect=T+0x100u,src_rect=T+0x110u,src_full=T+0x120u;
    m.w32(destination_rect,m.r32(point));m.w32(destination_rect+4u,m.r32(point+4u));
    m.w32(destination_rect+8u,m.r32(source_rect+8u));m.w32(destination_rect+12u,m.r32(source_rect+12u));
    for(U k=0;k<4u;++k)m.w32(src_rect+4u*k,m.r32(source_rect+4u*k));bounds(m,source,src_full);
    // Actual434A00/760CF0 initialize all overlap/optional-cursor locals.
    // Distinct surfaces and equal-size rectangles reach the accepted clip.
    Inputs q{};q.cx=destination_rect;q.dx=clip;q.arg[0]=src_rect;q.arg[1]=src_full;q.fp=i.fp;
    need(numeric_b80::fun_00760ad0(m,q)==1u,"B1420 useful real positive clip");i.fp=q.fp;
    for(U r:{destination_rect,src_rect})need(m.r32(r)==0u&&m.r32(r+4u)==0u&&m.r32(r+8u)==1u&&m.r32(r+12u)==1u,"B1420 actual clip selects one valid pixel");
    const U dst=lock(m,destination,m.r32(clip)+m.r32(destination_rect),m.r32(clip+4u)+m.r32(destination_rect+4u));
    const U src=lock(m,source,m.r32(src_full)+m.r32(src_rect),m.r32(src_full+4u)+m.r32(src_rect+4u));
    const U rowbytes=format(m,destination)*m.r32(destination_rect+8u),out_pitch=pitch(m,destination),in_pitch=pitch(m,source);
    need(rowbytes==out_pitch&&out_pitch!=in_pitch,"B1420 original noncontiguous palette row branch");
    // Original434E54..434E71 passes count1 plus produced zero optional
    // cursors; the real485FA0 provider ignores those extra four arguments.
    palette_pixel(m,mode,dst,src);(void)unlock(m,destination);return unlock(m,source);
}
}
U fun_0075e080(Memory& outer,const Inputs& i){
    const U self=i.cx,shape=outer.r32(self+4u),destination=i.arg[0],context=outer.r32(0x81a708u);
    need(shape&&destination&&context,"B1420 positive initialized cursor entry");
    need(destination==outer.r32(self+0x24u),"B1420 supplied primary destination branch");
    const U frame=outer.r32(self+8u),count=global_b26::sx16(outer.r16(shape+6u));
    need(frame<count&&count==1u,"B1420 valid nonempty selected shape frame");
    const U record=shape+8u+24u*frame,offset=outer.r32(record+0x14u);need(offset!=0u,"B1420 genuine nonnull borrowed pixel data");
    const U width=outer.r32(self+0x50u),height=outer.r32(self+0x54u);need(width==1u&&height==1u,"B1420 finite actual shape rectangle");
    std::array<std::uint8_t,0x2000> storage{};leaf::Memory local(storage.data(),base,U(storage.size()));Memory m=outer;m.add(local);
    // EntryS; T=S-58h. 438140 constructs T+4C from supplied data/size:
    // ownershipflag0. Root publishes785F8C first, then785EF8 after return.
    const U surface=T+0x38u; m.w32(surface,0x785f8cu);m.w32(surface+4u,width);m.w32(surface+8u,height);m.w32(surface+12u,0u);m.w32(surface+16u,1u);
    m.w32(surface+20u,shape+offset);m.w32(surface+24u,width*height);m.w8(surface+28u,0u);m.w32(surface,0x785ef8u);
    m.w32(T+0x10u,outer.r32(self+0x48u)+i.arg[1]);m.w32(T+0x14u,outer.r32(self+0x4cu)+i.arg[2]);
    m.w32(T+0x18u,0u);m.w32(T+0x1cu,0u);m.w32(T+0x20u,width);m.w32(T+0x24u,height);
    const U result=draw(m,i,destination,context,surface,T+0x18u,T+0x10u,self+0x2cu);
    // Actual438290 reads AL=ownershipflag0 (no free), clears its private
    // data/size/flag, and preserves EAX high24. Drawing's final unlock0|1
    // therefore becomes fullEAX0. No outer argument or source data changes.
    const U owner=m.r8(surface+28u);need(owner==0u,"B1420 borrowed wrapper teardown");
    m.w32(surface+20u,0u);m.w32(surface+24u,0u);m.w8(surface+28u,0u);return(result&0xffffff00u)|owner;
}
}
