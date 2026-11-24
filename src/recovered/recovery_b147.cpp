

// Private Block147 translation sketch. It is intentionally not part of the
// shared recovery build; parent owns integration and original differential.
#include "recovered/recovery_b147.hpp"
#include "recovered/numeric_b88_detail.hpp"
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b147 {
using floating_b61::Inputs;
using floating_b61::Memory;
namespace x87 = ra2::platform::x87;
namespace detail = ra2::recovered::numeric_b88::detail;

// Finite positive domain: T>0, 1<=P<T, selected C=T, vptr=0x790734,
// and prior [this+0x34] differs from the clamped requested value. The actual
// target at vptr+0x48 is checked and its observed byte store is reproduced.
std::uint32_t fun_0067a140(Memory& m, const Inputs& i) {
    const auto object = i.cx;
    const auto total = m.r32(object + 0x30u);
    const auto page = m.r32(object + 0x48u);
    const auto limit = total - page;
    auto requested = i.arg[0];
    if (floating_b61::s32(requested) >= floating_b61::s32(limit))
        requested = limit;
    if (floating_b61::s32(requested) < 0) requested = 0;
    else if (requested > total) requested = total;

    if (requested == m.r32(object + 0x34u)) return 0;
    m.w32(object + 0x34u, requested);

    const auto vptr = m.r32(object);
    if (vptr != 0x790734u || m.r32(vptr + 0x48u) != 0x004cf180u)
        throw std::invalid_argument("Block147 requires authentic 0x790734/+0x48 table route");
    m.w8(object + 0x1cu, 1u); // original 0x4cf180: MOV byte [ECX+1c],1; RET

    const auto selected = m.r8(object + 0x2eu) ? m.r32(object + 0x14u)
                                               : m.r32(object + 0x18u);
    // Original stack argument overwrite at VA 0x67a175: [entry ESP+4]=EBX.
    i.arg[0] = selected;

    auto& fp = i.fp;
    fp.load_integer32(total);              // FILD [this+30]
    fp.load_integer32(selected);            // FILD [entry ESP+10] after store
    fp.load_integer32(page);                // FILD [this+48]
    detail::reg<0xd8f2>(fp);               // FDIV ST0,ST2
    detail::reg<0xd8c9>(fp);               // FMUL ST0,ST1
    const auto minimum = detail::integer(m, fp); // original 0x76aa50
    const auto inset = minimum < 4u ? 4u : minimum;
    fp.load_integer32(requested);           // FILD [this+34]
    m.w32(object + 0x4cu, inset);
    detail::reg<0xd8f2>(fp);               // FDIV ST0,ST2
    detail::reg<0xd8c9>(fp);               // FMUL ST0,ST1
    auto position = detail::integer(m, fp);
    const auto upper = selected - inset;
    fp.pop_st0();                           // FSTP ST0
    fp.pop_st0();                           // FSTP ST0
    if (floating_b61::s32(position) >= floating_b61::s32(upper)) position = upper;
    m.w32(object + 0x50u, position);
    return 1u;                              // original MOV EAX,1; RET 4
}
}
