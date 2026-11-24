#include "recovery_b1307.hpp"
#include "recovered/numeric_b71.hpp"
#include "recovered/numeric_b88.hpp"
#include <array>
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b1307 {
namespace {
constexpr std::uint32_t kVtable = 0x78c004u;
constexpr std::uint32_t kLocalOutput = 0x30000008u;
constexpr std::uint32_t kLocalAngle = 0x30000004u;
void need(bool p, const char* what) { if (!p) throw std::domain_error(what); }
}
std::uint32_t fun_004bd980(Memory& m, const Inputs& i) {
    const auto self=i.cx, owner=m.r32(self+0x0cu);
    need(m.r8(self+0x53u)!=0u,"B1307 active route");
    need(owner!=0u && floating_b61::s32(m.r32(owner+0x6cu))>0,"B1307 owner gate");
    need(m.r32(self+4u)==kVtable && m.r32(kVtable+0x60u)==0x4bf180u,
         "B1307 installed virtual thunk");
    need(m.r8(self+0x10u)==0u,"B1307 callback AL zero");
    const auto old=m.r32(self+0x54u), desc=owner+0x2e0u;
    need(old==256u || old==0xffffff00u,"B1307 nonzero signed offset");
    const auto count=static_cast<std::int16_t>(m.r16(desc+0x14u));
    const auto delta=static_cast<std::int16_t>(m.r16(desc)-m.r16(desc+4u));
    need(count>0 && delta!=0 && (delta<0?-std::int32_t(delta):std::int32_t(delta))>=count,
         "B1307 positive interpolation");
    need(m.r32(desc+8u)==0xffffffffu && m.r32(desc+0x10u)>0u,
         "B1307 live phase");
    std::array<std::uint8_t,4> output{};
    std::array<std::uint8_t,2> angle{};
    leaf::Memory out_span(output.data(),kLocalOutput,4u);
    leaf::Memory angle_span(angle.data(),kLocalAngle,2u);
    Memory view=m;view.add(out_span);view.add(angle_span);
    Inputs sampled=i;sampled.cx=desc;sampled.arg[0]=kLocalOutput;
    need(numeric_b71::fun_004b8850(view,sampled)==kLocalOutput,
         "B1307 accepted interpolation output");
    view.w16(kLocalAngle,std::uint16_t(view.r32(kLocalOutput)+(old<<8u)));
    Inputs updated=i;updated.cx=desc;updated.arg[0]=kLocalAngle;
    updated.stack_minus8=0x13579bdfu;
    need(numeric_b88::fun_004b8780(view,updated)==0u,
         "B1307 accepted angle setter equal branch");
    m.w32(self+0x54u,floating_b61::s32(old)<0?old+1u:old-1u);
    return 1u;
}
}
