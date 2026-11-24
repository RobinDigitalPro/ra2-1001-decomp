#include "recovered/recovery_b1642.hpp"
#include <array>
#include <stdexcept>

namespace ra2::recovered::b1642 {
namespace {
void need(bool ok) {
    if (!ok) throw std::domain_error("1BE350 private fixed one-player recipe");
}
void fixed_inputs(global_b26::Memory& m, const floating_b61::Inputs& i) {
    need((i.cx & 255u)==1u && (i.dx & 255u)==1u);
    need(m.r32(0xa5a874u)==0u && m.r32(0xa27db8u)==1u);
    need(m.r32(0xa25672u)==0x41u); // UTF16 A, NUL
    need(m.r8(0xa25c20u)=='X' && m.r8(0xa25c21u)==0u);
    need(m.r8(0xa25e22u)=='Y' && m.r8(0xa25e23u)==0u);
    need(m.r8(0xa256d0u)=='Z' && m.r8(0xa256d1u)==0u);
    need(m.r32(0xa256e4u)==0u && m.r16(0xa2793eu)==0u);
    need(m.r16(0xa5a808u)==0u && m.r8(0xa5a410u)==0u && m.r8(0xa5a420u)==0u);
    need(m.r32(0xb10530u)==0u && m.r32(0x817554u)==0u);
    need(m.r32(0xb10e14u)==0u && m.r32(0x81776cu)==1u);
    for (auto a : {0xa2897cu,0xa28758u,0xa255f8u,0xa255ecu,0xa25600u,
                   0xa255e0u,0xa25e4cu,0xa25e44u}) need(m.r32(a)==0u);
    for (auto a : {0xa255f2u,0xa255f3u,0xa255f4u,0xa25670u,0xa255f1u,0xa25e48u})
        need(m.r8(a)==0u);
    for (unsigned k=0;k<24u;++k) need(m.r32(0xa2560cu+4u*k)==0u);
    const auto player=m.r32(m.r32(0xa27dacu));
    need(player!=0u && m.r32(player)==0x42u); // UTF16 B, NUL
    for (auto off : {0x49u,0x4du,0x51u,0x55u}) need(m.r32(player+off)==0u);
    need(m.r32(0xab7edcu)==0u);
}
}

std::uint32_t run(global_b26::Memory& m, const floating_b61::Inputs& i,
                  b979::Heap& heap, const recovery_b936::Ops& clock) {
    fixed_inputs(m,i);
    // Each child owns its argument copy. B274 overwrites its own argument0;
    // that write must not be transferred to the outer sixteen caller words.
    auto time_call=[&]() {
        floating_b61::Inputs child=i;
        child.arg[0]=0u;
        const auto value=recovery_b936::fun_0076f1bf(m,child,clock);
        i.fp=child.fp;
        return value;
    };
    const auto first=time_call();
    if (first==m.r32(0xa5a8b4u)) m.w8(0xa5a8b8u,1u);
    m.w8(0xa5a8b8u,0u);
    (void)time_call();
    // CL1 guarantees material BL1. The three bounded C-locale comparisons
    // see empty snapshots and A/X/Y; their private argument writes and
    // discarded integer returns have no further observable effect here.
    m.w16(0xa5a85eu,0u);
    m.w8(0xa5a41du,0u);
    m.w8(0xa5a440u,0u);
    const auto timestamp=time_call();
    m.w32(0xa5a8b4u,timestamp);
    // Keep the source addresses explicit; these are numeric snapshots,
    // not inferred original class members.
    m.w32(0x7d11a4u,m.r32(0xa255f8u));
    m.w32(0x7d11a8u,m.r32(0xa255ecu));
    m.w32(0x7d11acu,m.r32(0xa25600u));
    const std::array<unsigned,5> live_bytes{0xa255f2u,0xa255f3u,0xa255f4u,0xa25670u,0xa255f1u};
    for (unsigned k=0;k<live_bytes.size();++k) m.w8(0xa5a8b9u+k,m.r8(live_bytes[k]));
    for (unsigned k=0;k<4u;++k) m.w8(0xa5a808u+k,m.r8(0xa25672u+k));
    for (unsigned k=0;k<2u;++k) m.w8(0xa5a420u+k,m.r8(0xa25e22u+k));
    m.w32(0x7d11b4u,m.r32(0xa25e44u));
    for (unsigned k=0;k<2u;++k) m.w8(0xa5a410u+k,m.r8(0xa25c20u+k));
    m.w8(0x7d11b0u,m.r8(0xa25e48u));

    // A local numeric span represents the original private 520-byte output.
    // It is disjoint by Memory::add's overlap guard and is never published.
    std::array<std::uint8_t,520> buffer{};
    constexpr unsigned local_address=0x3f000000u;
    leaf::Memory local(buffer.data(),local_address,unsigned(buffer.size()));
    auto child_memory=m;
    child_memory.add(local);
    global_b26::Inputs serializer=i;
    serializer.cx=local_address;
    (void)b1109::run(0x1b7b10u,child_memory,serializer,heap,i.fp);
    need(buffer[93]==0u);

    // Real count1 child constructs a fully initialized packet but enters no
    // peer loop. The empty hash route produces0 without a character loop.
    std::array<std::uint8_t,455> packet{};
    packet[0]=0x17u;
    packet[4]=std::uint8_t(m.r8(0xa256d0u));
    for (unsigned k=0;k<94u;++k) packet[47u+k]=buffer[k];
    // Both fixed tail DWORDs are0 under this recipe. No packet pointer or
    // private byte escapes; no sender/provider call is substituted.
    return m.r32(0xa27db8u);
}
}
