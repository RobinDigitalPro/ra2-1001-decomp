#include "recovery_b1690.hpp"
#include "recovered/recovery_b557.hpp"
#include "recovered/leaf_memory.hpp"
#include <array>
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::b1690 {
namespace {
namespace fp=platform::x87;
constexpr unsigned map=0x81a820u,scratch_base=0x7d100000u;
constexpr unsigned output=0x83ab78u,format_address=0x7c0f9cu;
void need(bool v){if(!v)throw std::domain_error("9E340 positive coordinate-format contract");}
std::uint64_t r64(Memory& m,unsigned p){return m.r32(p)|(std::uint64_t(m.r32(p+4u))<<32u);}
bool separate(unsigned a,unsigned n,unsigned b,unsigned bytes){
    return std::uint64_t(a)+n<=b||std::uint64_t(b)+bytes<=a;
}
void object_span(unsigned p,unsigned bytes){
    need(p!=0u&&std::uint64_t(p)+bytes<=0x100000000ull);
    // Both Source-private symbolic frames are disjoint from borrowed objects.
    need(separate(p,bytes,0x7d000000u,0x8000u));
    need(separate(p,bytes,scratch_base,128u));
}
void bytes(Memory& m,unsigned p,unsigned count){for(unsigned k=0;k<count;++k)(void)m.r8(p+k);}
unsigned quotient256(unsigned value){return unsigned(global_b26::s32(value)/256);}
}

void preflight(Memory& m,const Inputs& i){
    const auto action=global_b26::s32(i.arg[0]);need(action>=500&&action<=900);
    object_span(i.cx,4u);need(m.r32(i.cx)==0x78991cu);
    need(m.r32(0x78991cu+0x68u)==0x49ea40u&&m.r32(0x78991cu+0x84u)==0x49e340u);
    const unsigned mouse=m.r32(0x821fa8u);object_span(mouse,152u);bytes(m,mouse,152u);
    need(m.r32(mouse)==0x79aa04u&&m.r32(0x79aa04u+0x34u)==0x75f010u);
    need(m.r32(mouse+0x1cu)==0u&&m.r32(mouse+0x20u)==0u);
    need(m.r32(0x821970u)==0u&&m.r32(0x821974u)==0u);
    need(m.r32(0x821cacu)==map&&m.r32(map)==0x79091cu);
    need(m.r32(map+0xb0u)==0u);
    const unsigned view_y=m.r32(map+0xb4u);
    need(view_y%30u==0u&&view_y/30u>=23u&&view_y/30u<=26u);
    need(m.r32(map+0xdb0u)==0u&&m.r32(map+0xf0u)==25u&&m.r32(map+0xf4u)==80u);
    need(m.r32(map+0x13cu)==0x40000u);
    constexpr std::array<unsigned,12> matrix{0x40888889u,0x41088889u,0u,0u,
        0xc0888889u,0x41088889u,0u,0u,0u,0u,0x3f800000u,0u};
    for(unsigned k=0;k<12u;++k)need(m.r32(map+0xde4u+4u*k)==matrix[k]);
    need(m.r32(0x7c3a04u)==0x0e7fu);
    need(r64(m,0xaa5f90u)==0x3fe0000000000000ull&&r64(m,0x785728u)==0x3fe0000000000000ull);
    need(m.r32(0xaa6070u)==640u&&m.r32(0xaa6074u)==2000u&&m.r32(0xaa606cu)==0u);
    need(m.r32(0x838f80u)==60u&&m.r8(0x838f70u)==7u);
    need(r64(m,0x838ef0u)==0x404e000000000000ull&&r64(m,0x838f10u)==0x3fce000000000000ull);
    need(m.r32(0xa57848u)==60u&&m.r32(0xb0de50u)==0u);
    const unsigned flags=m.r32(0xa255c0u);object_span(flags,4u);need(m.r32(flags)==0u);
    need(m.r8(0xa292fcu)!=0u);
    constexpr std::array<unsigned,8> text{'(', '%','d',',','%','d',')',0};
    for(unsigned k=0;k<text.size();++k)need(m.r16(format_address+2u*k)==text[k]);
    bytes(m,output,40u);
    // Complete old B557 borrowed cell neighborhood, now reached through fixed
    // Map81A820. Every actual cell pointer and used field is checked; no single
    // winning-cell/output callback is substituted for the original lookup.
    const unsigned table=m.r32(map+0x138u);object_span(table,0x140a4u);
    unsigned occupant=0u;
    std::array<unsigned,625> cells{};unsigned count=0u;
    for(unsigned y=16u;y<=40u;++y)for(unsigned x=16u;x<=40u;++x){
        const unsigned cell=m.r32(table+4u*(y*512u+x));object_span(cell,0x180u);
        need(separate(cell,0x180u,table+0x8040u,0xc064u));
        for(unsigned k=0;k<count;++k)need(separate(cell,0x180u,cells[k],0x180u));
        cells[count++]=cell;
        need(m.r32(cell+0x24u)==(x|(y<<16u))&&m.r8(cell+0x11bu)==12u);
        need(m.r32(cell+0x140u)==0u&&m.r8(cell+0x12cu)==0u&&m.r8(cell+0x11cu)==0u);
        const unsigned object=m.r32(cell+0xe4u);if(!occupant)occupant=object;need(object==occupant);
    }
    object_span(occupant,0x5beu);const unsigned type=m.r32(occupant+0x418u);object_span(type,0x1386u);
    need(separate(occupant,0x5beu,type,0x1386u));
    need(m.r32(occupant)==0x787bbcu&&m.r32(type)==0x7881f8u);
    need(m.r32(0x787bbcu+0x80u)==0x6b6910u&&m.r32(0x787bbcu+0x84u)==0x4538b0u&&m.r32(0x787bbcu+0x2cu)==0x453890u);
    need(m.r8(occupant+0x372u)==0u&&m.r32(occupant+0x1b8u)==0u&&m.r8(occupant+0x5bdu)==0u);
    need(m.r8(type+0xaa6u)==0u&&m.r8(type+0x1385u)==0u);
    for(unsigned a:{0xa9eb70u,0xa9eb90u,0xa9eb94u,0xa9eb98u})(void)m.r32(a);
}

unsigned run(Memory& m,const Inputs& i,WideStdio& stdio,Observation& o){
    o=Observation{};
    o.entry_fp=fp::capture_host();
    need(o.entry_fp.word(0)==0x037fu&&o.entry_fp.word(8)==0xffffu&&
         (o.entry_fp.word(4)&~0x3800u)==0u);
    const auto action=global_b26::s32(i.arg[0]);need(action>=500&&action<=900);
    // Source-owned local bytes only. They are not read from, added to, or seeded
    // into an Original stack. The Memory copy's temporary spans do not escape.
    std::array<std::uint8_t,128> local_bytes{};
    leaf::Memory local(local_bytes.data(),scratch_base,unsigned(local_bytes.size()));
    Memory work=m;work.add(local);
    o.action_before=i.arg[0];o.root_receiver=i.cx;o.root_vptr=work.r32(i.cx);
    need(o.root_vptr==0x78991cu);
    o.predicate_target=work.r32(o.root_vptr+0x68u);need(o.predicate_target==0x49ea40u);
    // Actual49EA40 XOR AL,AL;RET0. Its upper EAX is irrelevant to this branch.
    o.predicate_al=0u;++o.predicate_calls;o.stage=1u;
    o.mouse_receiver=work.r32(0x821fa8u);o.mouse_vptr=work.r32(o.mouse_receiver);
    need(o.mouse_vptr==0x79aa04u);
    o.getter_target=work.r32(o.mouse_vptr+0x34u);need(o.getter_target==0x75f010u);
    o.getter_output=scratch_base+32u;
    // Actual18B75F010: output pointer returned in full EAX, two DWORD copies.
    const unsigned getter_x=work.r32(o.mouse_receiver+0x1cu);
    const unsigned getter_y=work.r32(o.mouse_receiver+0x20u);
    work.w32(o.getter_output,getter_x);work.w32(o.getter_output+4u,getter_y);
    o.getter_values={getter_x,getter_y};++o.getter_calls;o.stage=2u;
    const unsigned x=work.r32(o.getter_output)-work.r32(0x821970u);
    const unsigned y=work.r32(o.getter_output+4u)-work.r32(0x821974u);
    work.w32(scratch_base,x);work.w32(scratch_base+4u,y);o.screen={x,y};
    recovery_b557::Inputs child{};
    child.cx=map;child.fp.image=o.entry_fp;
    child.arg[0]=scratch_base;child.arg[1]=scratch_base+8u;
    child.arg[2]=scratch_base+12u;child.arg[3]=scratch_base+24u;
    child.arg[4]=scratch_base+28u;child.arg[5]=scratch_base+29u;
    for(unsigned k=0;k<6u;++k)o.child_arguments[k]=child.arg[k];
    ++o.child_calls;o.stage=3u;
    o.child_result=recovery_b557::fun_00660600(work,child);
    o.child_fp=child.fp.image;o.child_words_after=child.arg;
    o.packed_cell=work.r32(scratch_base+8u);
    for(unsigned k=0;k<3u;++k)o.world[k]=work.r32(scratch_base+12u+4u*k);
    o.object=work.r32(scratch_base+24u);o.flag_a=work.r8(scratch_base+28u);o.flag_b=work.r8(scratch_base+29u);
    // Actual sixth output aliases the low byte of Root caller action word0.
    i.arg[0]=(i.arg[0]&0xffffff00u)|o.flag_b;o.action_after=i.arg[0];o.stage=4u;
    // Publish the computed production helper image. Never restore a literal
    // expected CW/SW/register value from the independent hardware ledger.
    fp::restore_host(child.fp.image);
    need(work.r8(0xa292fcu)!=0u);
    o.format_x_bits=quotient256(o.world[0]);o.format_y_bits=quotient256(o.world[1]);
    ++o.formats;o.stage=5u;
    o.format_result=stdio.format(output,format_address,o.format_x_bits,o.format_y_bits);
    o.stage=6u;
    return output; // Actual49E404 overrides the library return with83AB78.
}
}
