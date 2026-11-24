#include "recovered/recovery_b450.hpp"
#include "recovered/numeric_b88.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::projection450 {
namespace {
using namespace floating_b61;
std::uint32_t round_cell(std::uint32_t signed_tile) {
    const auto q=signed_tile<<8u;
    const auto sum=q+0x80u;
    const auto bias=(s32(sum)<0)?255u:0u;
    return sar(sum+bias,8u)<<8u;
}
}
std::uint32_t fun_00474eb0(Memory& m,const Inputs& i) {
    const auto receiver=i.cx, out=i.arg[0];
    if(!receiver||!out)throw std::domain_error("projection450 requires receiver and output");
    if(m.r32(receiver+0x38u)!=0xffffu)throw std::domain_error("projection450 contract selects the original no-frame sentinel branch");
    const auto scratch_base=receiver+0xf0000u;
    if(scratch_base<receiver||scratch_base-receiver<0x1c0u)throw std::domain_error("projection450 scratch aliases receiver");
    if(scratch_base>=out&&scratch_base-out<24u)throw std::domain_error("projection450 scratch aliases result");
    const auto manager=m.r32(0x821cacu);
    if(!manager)throw std::domain_error("projection450 requires initialized projection context");

    // 0x474eb0 constructs a private three-dword local from tile coordinates.
    // Keep this scratch outside the observable fixture objects; preserve the
    // surrounding declared guest arena exactly after the inlined accepted leaf.
    const auto saved0=m.r32(scratch_base),saved1=m.r32(scratch_base+4),saved2=m.r32(scratch_base+8),
               saved3=m.r32(scratch_base+12),saved4=m.r32(scratch_base+16),saved5=m.r32(scratch_base+20);
    const auto x=round_cell(sx16(m.r16(receiver+0x24u)));
    const auto y=round_cell(sx16(m.r16(receiver+0x26u)));
    m.w32(scratch_base,x);m.w32(scratch_base+4,y);m.w32(scratch_base+8,0);
    auto leaf_i=i;leaf_i.cx=manager;leaf_i.arg[0]=scratch_base;leaf_i.arg[1]=scratch_base+12;
    (void)numeric_b88::fun_00698010(m,leaf_i);
    const auto projected_x=m.r32(scratch_base+12),projected_y=m.r32(scratch_base+16);
    const auto decoration=sx8(m.r8(receiver+0x11bu));
    m.w32(out,projected_x-30u);
    m.w32(out+4u,projected_y+m.r32(0x821974u)-15u*decoration);
    m.w32(out+8u,60u);m.w32(out+12u,30u);
    i.fp=leaf_i.fp;
    m.w32(scratch_base,saved0);m.w32(scratch_base+4,saved1);m.w32(scratch_base+8,saved2);
    m.w32(scratch_base+12,saved3);m.w32(scratch_base+16,saved4);m.w32(scratch_base+20,saved5);
    return out;
}
}
