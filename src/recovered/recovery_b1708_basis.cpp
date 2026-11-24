#include "recovery_b1708.hpp"
#include <array>
#include <stdexcept>

namespace ra2::recovered::recovery_b1708 {
namespace {
struct Range { U base; U size; };
void basis(bool ok) {
    if (!ok) throw std::domain_error("2C7F40 outside frozen positive public basis");
}
bool separate(Range a, Range b) {
    return std::uint64_t(a.base)+a.size <= b.base ||
           std::uint64_t(b.base)+b.size <= a.base;
}
}
void require_selected_basis(const Memory& m, const State& s, const Frame& f) {
    // Readonly logical-input checks. Physical ownership/writability, complete
    // stack coverage and normal producer/lifetime receipts remain external.
    basis(f.sp==f.entry_sp && f.entry_sp>=0x200u && f.entry_sp<=0xffffffbbu);
    basis(m.r32(f.entry_sp)==f.outer_return);
    const Range protected_stack{f.entry_sp-0x200u,0x244u};
    // Actual Root/tiny-leaf minimum only; deeper common components check their
    // own memory accesses. No undefined private byte is tested for a value.
    for(U a=f.entry_sp-0x70u;a!=f.entry_sp+0x44u;++a)(void)m.r8(a);
    std::array<Range,64> ranges{}; U used=0u;
    const auto add=[&](U p,U n) {
        basis(p!=0u && n!=0u && std::uint64_t(p)+n<=0x100000000ull);
        const Range r{p,n}; basis(separate(r,protected_stack));
        for(U i=0u;i<used;++i)basis(separate(r,ranges[i]));
        basis(used<ranges.size());ranges[used++]=r;
        // Long pointer-table ownership is established by the external world
        // fixture; endpoints plus every selected entry are read here.
        if(n<=0x1000u)for(U k=0u;k<n;++k)(void)m.r8(p+k);
        else {(void)m.r8(p);(void)m.r8(p+n-1u);}
    };
    const U d=m.r32(f.entry_sp+4u), v=m.r32(f.entry_sp+8u), c=m.r32(f.entry_sp+0xcu);
    add(d,12u);add(v,8u);add(c,16u);
    basis(m.r16(d)==0u && m.r16(d+2u)==0u && m.r16(d+4u)==1u && m.r16(d+6u)==1u);
    basis(m.r32(v)==0u && m.r32(v+4u)==0u);
    basis(m.r32(c)==0u && m.r32(c+4u)==0u && m.r32(c+8u)==1u && m.r32(c+0xcu)==1u);
    basis(m.r32(f.entry_sp+0x10u)==0u && m.r32(f.entry_sp+0x14u)==0u);
    const U encoded=m.r32(d+8u); add(encoded,3u);
    basis(encoded<=0xfffffffcu && m.r8(encoded)==3u && m.r8(encoded+1u)==0u && m.r8(encoded+2u)==1u);
    const U self=s.cx;add(self,0x5ccu);
    basis(m.r32(self)==0x798c88u && m.r8(self+0x5bbu)==1u && m.r32(self+0x564u)==0u);
    basis(m.r32(self+0x88u)==0x1e80u && m.r32(self+0x8cu)==0x1e80u && m.r32(self+0x90u)==0u);
    basis(m.r8(self+0x79u)==0u && m.r8(self+0x370u)==0u);
    const U type=m.r32(self+0x5acu);add(type,0xba8u);
    basis(m.r8(type+0xba6u)==0u && m.r32(type+0xb60u)==1u && m.r32(type+0xb64u)==3u &&
          m.r32(type+0xb5cu)==4u && m.r32(type+0xb68u)==11u);
    const U table=m.r32(0x81a958u);add(table,0x100000u);
    constexpr std::array<U,9> xs{{30,30,31,31,30,29,30,28,32}};
    constexpr std::array<U,9> ys{{30,31,30,31,29,30,28,30,32}};
    std::array<U,9> cell{};
    for(U i=0u;i<cell.size();++i) {
        cell[i]=m.r32(table+4u*(512u*ys[i]+xs[i]));add(cell[i],0x200u);
        basis(m.r32(cell[i]+0x24u)==(xs[i]|(ys[i]<<16u)));
    }
    basis(m.r8(cell[0]+0x11cu)==1u && m.r32(cell[0]+0x140u)==0x100u && m.r32(cell[1]+0x44u)==0u);
    basis(m.r32(cell[1]+0x38u)==1006u && m.r32(cell[2]+0x38u)==1006u && m.r32(cell[3]+0x38u)==1006u);
    basis(m.r8(cell[0]+0x11bu)==0u && m.r8(cell[3]+0x11bu)==5u && m.r8(cell[8]+0x11bu)==0u);
    basis(m.r16(cell[0]+0x116u)==0u && m.r32(cell[0]+0xecu)==10u &&
          m.r16(cell[7]+0x116u)==0u && m.r32(cell[7]+0xecu)==10u);
    const U array=m.r32(0xa1e11cu);add(array,4u);const U q=m.r32(array);add(q,0x286u);basis(m.r8(q+0x285u)==1u);
    const U main=m.r32(0x821c9cu);add(main,32u);
    basis(m.r32(main)==0x785ef8u && m.r32(main+4u)==1u && m.r32(main+8u)==1u &&
          m.r32(main+0xcu)==0u && m.r32(main+0x10u)==1u);
    const U pixel=m.r32(main+0x14u);add(pixel,1u);basis(pixel!=0xffffffffu && m.r8(pixel)==0xe7u);
    const U context=m.r32(0xab8088u);add(context,0x188u);
    basis(m.r32(context+4u)==1u && m.r32(context+8u)!=0u);
    const U renderer=m.r32(context+0xd0u);add(renderer,8u);basis(m.r32(renderer)==0x7894d0u);
    const U palette=m.r32(renderer+4u);add(palette,256u);
    basis(m.r32(context+0x174u)==palette);
    // The independently proven black-RGB producer supplies this public table.
    // The model still reads its actual selected palette byte; it seeds nothing.
    for(U i=0u;i<256u;++i)basis(m.r8(palette+i)==0u);
    add(0x798000u,0x1000u);add(0x7894d0u,8u);
    basis(m.r32(0x798cb4u)==0x6fee90u && m.r32(0x798f48u)==0x4c9530u &&
          m.r32(0x798f4cu)==0x4c9610u && m.r32(0x7894d4u)==0x4862d0u);
    constexpr std::array<U,8> direction{{0xffff0000u,0xffff0001u,1u,0x10001u,0x10000u,0x1ffffu,0xffffu,0xffffffffu}};
    for(U i=0u;i<8u;++i)basis(m.r32(0x839da0u+4u*i)==direction[i]);
    basis(m.r32(0xa3a8b0u)==1000u && m.r32(0x84e508u)==1u && m.r32(0xaa7c50u)==0u);
    basis(m.r32(0xaa5f90u)==0u && m.r32(0xaa5f94u)==0u && m.r32(0x785728u)==0u &&
          m.r32(0x78572cu)==0x3fe00000u && m.r32(0x7c3a04u)==0xe7fu && m.r32(0x7e09bcu)==3u);
    basis(m.r32(0x7bebacu)==0x3000u && m.r32(0x821facu)==0u && m.r32(0x8198f4u)==0u);
    basis(m.r32(0xab7f10u)==0u && m.r32(0xab7f14u)==0u && m.r32(0xab7f18u)==1u && m.r32(0xab7f1cu)==1u);
    // Mutable Root globals cannot alias the borrowed inputs or local frames.
    constexpr std::array<Range,17> globals{{
        {0x821c9cu,4u},{0xab8088u,4u},{0x81a958u,4u},{0xa1e11cu,4u},
        {0x839da0u,32u},{0xa3a8b0u,4u},{0x84e508u,4u},{0xaa7c50u,4u},
        {0xaa5f90u,8u},{0x785728u,8u},{0x7c3a04u,4u},{0x7e09bcu,4u},
        {0x7bebacu,4u},{0x821facu,4u},{0x8198f4u,4u},{0xab7f10u,16u},
        {0x785ef8u,0x80u}
    }};
    for(auto g:globals)add(g.base,g.size);
    const auto& fp=s.fp.image.bytes;
    basis(fp[0]==0x7fu && fp[1]==3u && fp[4]==0u && fp[5]==0u && fp[8]==0xffu && fp[9]==0xffu);
    for(U i=28u;i<108u;++i)basis(fp[i]==0u);
    // Raw FP address/reserved metadata is carried unchanged here, not repaired.
    // Complete globals/immutable vtables, normal context/surface production and
    // deeper private-frame aliases are joined by the independent packet gate.
}
} // namespace ra2::recovered::recovery_b1708
