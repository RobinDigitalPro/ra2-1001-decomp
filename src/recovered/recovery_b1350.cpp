#include "recovered/recovery_b1350.hpp"
#include "recovered/recovery_b1332.hpp"
#include "recovered/floating_b61_a.hpp"
#include "recovered/floating_b61_b.hpp"
#include "recovered/floating_callers_b40_memory.hpp"
#include "recovered/map_b79.hpp"
#include "recovered/numeric_b88.hpp"
#include "recovered/numeric_b80.hpp"
#include "recovered/leaf_b21_a.hpp"
#include "recovered/recovery_b511.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1350 {
namespace {
using U = std::uint32_t;
constexpr U base = 0x7dc00000u, T = base + 0x8000u;
void need(bool yes, const char* why) { if (!yes) throw std::domain_error(why); }
void copy(Memory& m, U out, U in, U words) { for (U k=0;k<words;++k) m.w32(out+4u*k,m.r32(in+4u*k)); }
void closed_fp(Memory& m, const Inputs& i, U rva, U cx, U dx, std::array<U,2> args, U sp, U cleanup) {
    floating_b39::State s{}; s.cx=cx; s.dx=dx; s.fp=i.fp;
    constexpr U ret=0x13579bdfu;
    m.w32(sp,ret); m.w32(sp+4u,args[0]); m.w32(sp+8u,args[1]);
    floating_b39::Frame f{}; f.entry_sp=f.return_sp=f.sp=sp; f.outer_return=ret;
    floating_b39::Function fn=nullptr;
    if (rva==0x18dad0u) for (const auto&e:floating_b39::entries_a()) if(e.rva==rva) fn=e.function;
    if (rva==0x3105e0u) for (const auto&e:floating_callers_b40::entries_a()) if(e.rva==rva) fn=e.function;
    need(fn!=nullptr,"B1350 closed original numeric helper"); fn(m,s,f,{});
    need(f.sp==sp+4u+cleanup,"B1350 exact nested numeric cleanup"); i.fp=s.fp;
}
void prepare_70bc10(Memory& m, const Inputs& i, U receiver, U matrix) {
    // Stable private frame for 70BC10: inverse matrix, copied matrix,
    // vector output, then the original 16-entry direction preparation.
    Inputs q{}; q.cx=T+0x500u; q.dx=matrix; q.fp=i.fp;
    floating_b61::fun_0058e220(m,q); i.fp=q.fp;
    copy(m,T+0x530u,T+0x500u,12u);
    closed_fp(m,i,0x18dad0u,T+0x530u,0u,{T+0x560u,0x821df0u},T+0x400u,8u);
    // Actual 70E420: receiver+10 is a 12-byte offset table, +14 the resource.
    const U resource=m.r32(receiver+0x14u)+164u*m.r32(m.r32(receiver+0x10u));
    const U table=m.r8(resource+0xa3u);
    need(table==1u&&m.r32(0x7e37fcu+4u*table)==16u,"B1350 original direction table1 has16 entries");
    closed_fp(m,i,0x3105e0u,T+0x560u,table,{0u,0u},T+0x400u,0u);
}
void slot(Memory& m,U surface,U off,U target) {
    need(m.r32(surface)==0x785ef8u&&m.r32(0x785ef8u+off)==target,"B1350 authentic software-surface slot");
}
U format(Memory& m,U surface) { slot(m,surface,0x70u,0x4113b0u); return m.r32(surface+0x10u); }
U pitch(Memory& m,U surface) { slot(m,surface,0x74u,0x4113c0u);slot(m,surface,0x7cu,0x4112c0u);return m.r32(surface+4u)*m.r32(surface+0x10u); }
U lock(Memory& m,U surface,U x,U y) {
    slot(m,surface,0x5cu,0x411370u);m.w32(surface+12u,m.r32(surface+12u)+1u);
    const U data=m.r32(surface+20u),horizontal=format(m,surface)*x;
    return data+horizontal+pitch(m,surface)*y;
}
U unlock(Memory& m,U surface) {
    slot(m,surface,0x60u,0x4112f0u);const U count=m.r32(surface+12u)-1u;m.w32(surface+12u,count);return(count&0xffffff00u)|1u;
}
void rectangle(Memory& m,U surface,U out) {
    slot(m,surface,0x78u,0x411290u);m.w32(out,0u);m.w32(out+4u,0u);
    m.w32(out+8u,m.r32(surface+4u));m.w32(out+12u,m.r32(surface+8u));
}
void palette_pixel(Memory& m,U mode,U dst,U src) {
    need(m.r32(mode)==0x78942cu&&m.r32(0x789430u)==0x485fa0u,"B1350 actual838E0 format2 palette mode");
    // 485FA0's older contiguous memory interface observes only these disjoint
    // records. Relocate their addresses without altering any operand value.
    std::array<std::uint8_t,0x300> storage{}; leaf::Memory view(storage.data(),0x1000u,U(storage.size()));
    view.w32(0x1004u,0x1100u);view.w8(0x1020u,m.r8(src));view.w16(0x1022u,m.r16(dst));
    const U table=m.r32(mode+4u);for(U k=0;k<256u;++k)view.w16(0x1100u+2u*k,m.r16(table+2u*k));
    leaf::Inputs q{};q.cx=0x1000u;q.arg[0]=0x1022u;q.arg[1]=0x1020u;q.arg[2]=1u;
    (void)leaf::fun_00485fa0(view,q);m.w16(dst,view.r16(0x1022u));
}
U draw_49f0c0(Memory& m,const Inputs& i,U destination,U context,U source,U source_rect,U point,U clip,U mode,U brightness) {
    need(source==0xac8838u&&m.r32(source+4u)==256u&&m.r32(source+8u)==256u&&m.r32(source+16u)==1u&&
         m.r32(source+20u)==0xacae88u&&m.r32(source+12u)==0u,"B1350 producer-consistent inline8-bit raster");
    need(m.r32(destination+4u)==1u&&m.r32(destination+8u)==1u&&m.r32(destination+16u)==2u&&
         m.r32(destination+12u)==0u,"B1350 borrowed positive one-pixel RGB565 destination");
    need(m.r32(clip)==0u&&m.r32(clip+4u)==0u&&m.r32(clip+8u)==1u&&m.r32(clip+12u)==1u,"B1350 valid one-pixel clip");
    need(m.r32(0x821facu)==0u&&m.r32(0x8198f4u)==0u,"B1350 optional depth/aux rings absent for plain palette mode");
    m.w32(context+0x17cu,0u);
    const U dst_rect=T+0x700u,src_rect=T+0x710u,src_full=T+0x720u;
    m.w32(dst_rect,m.r32(point));m.w32(dst_rect+4u,m.r32(point+4u));
    m.w32(dst_rect+8u,m.r32(source_rect+8u));m.w32(dst_rect+12u,m.r32(source_rect+12u));
    copy(m,src_rect,source_rect,4u);rectangle(m,source,src_full);
    // 434A00 ->760CF0: initialized private overlap/pointers; distinct
    // surfaces skip overlap reversal. Actual760AD0 clips equal-size records.
    Inputs q{};q.cx=dst_rect;q.dx=clip;q.arg[0]=src_rect;q.arg[1]=src_full;q.fp=i.fp;
    need(numeric_b80::fun_00760ad0(m,q)==1u,"B1350 actual positive rectangle clip");i.fp=q.fp;
    need(m.r32(dst_rect)==0u&&m.r32(dst_rect+4u)==0u&&m.r32(dst_rect+8u)==1u&&m.r32(dst_rect+12u)==1u&&
         m.r32(src_rect)==127u&&m.r32(src_rect+4u)==128u&&m.r32(src_rect+8u)==1u&&m.r32(src_rect+12u)==1u,
         "B1350 actual clipping selects the produced raster pixel");
    const U dst=lock(m,destination,m.r32(clip)+m.r32(dst_rect),m.r32(clip+4u)+m.r32(dst_rect+4u));
    const U src=lock(m,source,m.r32(src_full)+m.r32(src_rect),m.r32(src_full+4u)+m.r32(src_rect+4u));
    const U rowbytes=format(m,destination)*m.r32(dst_rect+8u),destination_pitch=pitch(m,destination);
    need(rowbytes==destination_pitch&&destination_pitch!=pitch(m,source),"B1350 original noncontiguous row arm");
    const U source_pitch=pitch(m,source),out_pitch=pitch(m,destination);(void)source_pitch;(void)out_pitch;(void)brightness;
    // 434E54..434E71 passes one pixel with initialized zero optional ring
    // cursors. The actual palette callback ignores those defined arguments.
    palette_pixel(m,mode,dst,src);
    (void)unlock(m,destination);return unlock(m,source);
}
}
U fun_00463630(Memory& outer,const Inputs& i) {
    need(i.fp.image.word(8)==0xffffu&&(i.fp.image.word(4)&0x3800u)==0u,"B1350 affine helpers require eight free x87 registers");
    const U pair=i.arg[0],receiver=outer.r32(pair),animation=outer.r32(pair+4u),matrix=i.arg[1],point=i.arg[2],clip=i.arg[3];
    need(outer.r32(receiver+4u)==1u&&animation!=0u&&outer.r32(animation+4u)==1u&&outer.r32(animation+8u)!=0u,"B1350 one authentic queued request with valid animation matrix");
    const U type=outer.r32(i.cx+0x98u);need(outer.r8(type+0x2c7u)==0u&&i.arg[5]==0u,"B1350 plain positive palette mode");
    std::array<std::uint8_t,0x10000> storage{};leaf::Memory local(storage.data(),base,U(storage.size()));Memory m=outer;m.add(local);
    prepare_70bc10(m,i,receiver,matrix);
    Inputs q{};q.fp=i.fp;(void)map_b79::fun_0070bd90(m,q);i.fp=q.fp;
    const U animation_index=(i.arg[4]%m.r32(animation+8u))*m.r32(animation+4u);
    copy(m,T+0x34u,m.r32(animation+12u)+48u*animation_index,12u);
    q={};q.cx=T+0x98u;q.dx=matrix;q.arg[0]=T+0x34u;q.fp=i.fp;
    copy(m,T+0x64u,floating_b61::fun_0058df80(m,q),12u);i.fp=q.fp;
    q={};q.cx=T+0xc4u;q.dx=0x821db0u;q.arg[0]=T+0x64u;q.fp=i.fp;
    const U transformed=floating_b61::fun_0058df80(m,q);i.fp=q.fp;
    q={};q.cx=receiver;q.dx=0u;q.arg[0]=0u;q.arg[1]=transformed;q.fp=i.fp;
    need(numeric_b88::fun_0070c080(m,q)==1u,"B1350 real eight-corner queue producer");i.fp=q.fp;
    q={};q.cx=T+0x34u;q.fp=i.fp;(void)b1332::fun_0070c4a0(m,q);i.fp=q.fp;copy(m,T+0x1cu,T+0x34u,6u);
    m.w32(T+0x10u,m.r32(point)+m.r32(T+0x1cu));m.w32(T+0x14u,m.r32(point+4u)+m.r32(T+0x20u));
    const U selected=m.r32(m.r32(0xa9ea04u)+4u*m.r32(type+0x2a4u)),context=m.r32(selected+0x30cu);
    Inputs selection{};selection.cx=context;selection.arg[0]=i.arg[5]&~0x10u;
    const U mode=recovery_b239::selectors511::select_85880(m,selection);
    // Actual70BC00 is MOV EAX,AC8838; RET, not a pointer load.
    return draw_49f0c0(m,i,m.r32(0x821c9cu),context,0xac8838u,T+0x24u,T+0x10u,clip,mode,i.arg[6]);
}
}
