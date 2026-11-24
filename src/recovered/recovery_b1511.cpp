#include "recovered/recovery_b1511.hpp"
#include <array>
#include <cstdint>
#include <stdexcept>
namespace ra2::recovered::b1511 {
namespace {
using U=std::uint32_t;
constexpr U kMap=0x0081a820u;
std::array<U,3> coordinates(Memory& m,U receiver) {
    // Actual slot48=005CD4D0. Its disjoint local output is fully produced.
    return {m.r32(receiver+0x88u),m.r32(receiver+0x8cu),m.r32(receiver+0x90u)};
}
U packed_cell(const std::array<U,3>& xyz) {
    const auto x=static_cast<std::int32_t>(xyz[0])/256;
    const auto y=static_cast<std::int32_t>(xyz[1])/256;
    return (U(x)&0xffffu)|((U(y)&0xffffu)<<16u);
}
U map_hit(Memory& m,U packed) {
    // Exact selected hit branch of00545500; no fallback invented.
    const auto x=static_cast<std::int16_t>(packed);
    const auto y=static_cast<std::int16_t>(packed>>16u);
    const auto index=static_cast<std::int32_t>(y)*512+static_cast<std::int32_t>(x);
    if(index<0 || index>=2048)
        throw std::domain_error("B1511 requires the reviewed mapped2048entry hit");
    const auto cell=m.r32(m.r32(kMap+0x138u)+4u*U(index));
    if(!cell)throw std::domain_error("B1511 excludes map fallback");
    return cell;
}
void shared_update_clear_bit(Memory& m,U receiver) {
    // Actual slot3B8=006B8000: coordinate getter, actual map lookup,
    // then authentic0047BEC0 input bit test and the006B81A0 epilogue.
    const auto cell=map_hit(m,packed_cell(coordinates(m,receiver)));
    const auto owner=m.r32(receiver+0x1b4u);
    const auto bit=m.r32(owner+0x30u)&31u;
    if(m.r32(cell+0x78u)&(U(1)<<bit))
        throw std::domain_error("B1511 excludes later3B8 dispatch and loop");
}
bool map_membership(Memory& m,U packed) {
    // Exact00557450 enabled, table-hit, cell11B=11C=0 projection.
    const auto cell=map_hit(m,packed);
    if(m.r8(cell+0x11bu)!=0u || m.r8(cell+0x11cu)!=0u)
        throw std::domain_error("B1511 requires reviewed flat cell fields");
    const auto x=std::int32_t(std::int16_t(packed));
    const auto y=std::int32_t(std::int16_t(packed>>16u));
    const auto f0=std::int32_t(m.r32(kMap+0xf0u));
    const auto f8=std::int32_t(m.r32(kMap+0xf8u));
    const auto fc=std::int32_t(m.r32(kMap+0xfcu));
    const auto f100=std::int32_t(m.r32(kMap+0x100u));
    const auto f104=std::int32_t(m.r32(kMap+0x104u));
    if(x+y<=f0+2*fc)return false;
    if(x+y>f0+2*(fc+f104)+2)return false;
    if(x-y>=2*(f8+f100)-f0)return false;
    if(y-x>=f0-2*f8)return false;
    return true;
}
}
std::uint32_t fun_006b81b0(Memory& m,const Inputs& i) {
    if(i.arg[0]!=2u)return i.arg[0];
    const auto receiver=i.cx;
    if(m.r32(receiver)!=0x00797a28u || m.r32(receiver+0x208u)!=0u)
        throw std::domain_error("B1511 requires authenticated receiver and208zero");
    const auto packed=packed_cell(coordinates(m,receiver));
    // Original006B8216 writes[ESP+18] afterSUB10/PUSHESI: outerarg0.
    // Later helpers receive the address of this produced coordinate word.
    i.arg[0]=packed;
    shared_update_clear_bit(m,receiver);
    if(m.r32(receiver+0x34u)!=0u)
        throw std::domain_error("B1511 excludes nonzero34 event route");
    if(m.r8(receiver+0x32du)==0u && map_membership(m,i.arg[0]))
        m.w8(receiver+0x32du,1u);
    if(m.r8(receiver+0x373u)==0u)
        throw std::domain_error("B1511 excludes373zero dispatch route");
    const auto cell=map_hit(m,i.arg[0]);
    // Actual0047B730 entry guard; no allocation/constructor credit.
    if(m.r32(cell+0x44u)==0x7eu)
        throw std::domain_error("B1511 excludes7B730 positive allocation path");
    return cell;
}
}
