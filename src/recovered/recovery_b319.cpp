#include "recovery_b319.hpp"

#include <stdexcept>

namespace ra2::recovery_b319 {
namespace {
void need(bool ok, const char* why) {
    if (!ok) throw std::domain_error(why);
}
constexpr std::uint32_t g_clock = 0x00a2896cu;
constexpr std::uint32_t g_seed = 0x00a9de68u;
constexpr std::uint32_t g_vec = 0x00aa1188u;

void empty_vector(Memory& m, std::uint32_t p, std::uint32_t initial,
                  std::uint32_t final, bool counted_tail) {
    m.w32(p + 4u, 0); m.w32(p + 8u, 0);
    m.w8(p + 0x0cu, 1); m.w8(p + 0x0du, 0);
    m.w32(p, initial);
    m.w32(p, final);
    if (counted_tail) { m.w32(p + 0x10u, 0); m.w32(p + 0x14u, 10); }
}

void base_544df0(Memory& m, std::uint32_t p) {
    // Exact zero-count composition at 0x544df0: calls 0x4dff60,
    // 0x569980, 0x569a30 x3 and 0x42d4a0. Their actual zero routes are
    // expressed here from the reached original writes; no virtual call runs.
    m.w32(p + 4u, 0); m.w32(p + 8u, 0); m.w32(p + 0x0cu, 2);
    m.w32(p, 0x0078dc3cu);
    empty_vector(m, p + 0x4cu, 0x007909f8u, 0x007909d8u, false);
    m.w32(p + 0x4cu + 0x10u, 0); m.w32(p + 0x4cu + 0x14u, 10);
    for (std::uint32_t i = 0; i != 3; ++i) {
        const auto row = p + 0x88u + i * 0x18u;
        empty_vector(m, row, 0x00790a18u, 0x007909b8u, false);
        m.w32(row + 0x10u, 0); m.w32(row + 0x14u, 10);
    }
    empty_vector(m, p + 0xd0u, 0x007875e0u, 0x007875e0u, false);
    m.w32(p + 0xd0u, 0x007875a0u);
    m.w32(p + 0xd0u + 0x14u, 10); m.w32(p + 0xd0u + 0x10u, 0);
    m.w32(p + 0x138u, 0); m.w32(p + 0x13cu, 0);
    m.w8(p + 0x140u, 1); m.w8(p + 0x141u, 0);
    m.w32(p + 0x134u, 0x00790998u);
    // Original loop clears exactly the first four bytes of each 16-byte cell.
    for (std::uint32_t i = 0; i != 0x100u; ++i) {
        m.w8(p + 0x160u + i * 0x10u, 0);
        m.w8(p + 0x161u + i * 0x10u, 0);
        m.w8(p + 0x162u + i * 0x10u, 0);
        m.w8(p + 0x163u + i * 0x10u, 0);
    }
    m.w32(p + 0x115cu, 0); m.w32(p + 0x1160u, 0);
    m.w8(p + 0x1164u, 1); m.w8(p + 0x1165u, 0);
    m.w32(p + 0x1158u, 0x007875a0u);
    m.w32(p + 0x116cu, 10); m.w32(p + 0x1168u, 0);
    m.w32(p, 0x0079091cu); m.w32(p + 0x144u, 13);
}

void init_498830(Memory& m, std::uint32_t p) {
    base_544df0(m, p);
    const auto seed = m.r32(0x0083a940u);
    m.w32(p + 0x1170u, seed);
    m.w32(p + 0x1174u, 0); m.w32(p + 0x1178u, 0);
    m.w8(p + 0x117cu, 0); m.w8(p + 0x117du, 0);
    m.w32(p + 0x117eu, seed);
    m.w32(p + 0x1182u, 0); m.w32(p + 0x1188u, 0);
    m.w32(p + 0x118cu, 0); m.w32(p + 0x1190u, 0);
    m.w32(p + 0x1194u, 0xffffffffu); m.w8(p + 0x1198u, 0);
    m.w32(p + 0x119cu, 0); m.w32(p + 0x11a0u, 0); m.w32(p + 0x11a4u, 0);
    m.w32(p + 0x11a8u, 0xffffffffu);
    for (std::uint32_t off = 0x11acu; off <= 0x11b0u; ++off) m.w8(p + off, 0);
    m.w32(p + 0x11b4u, 0xffffffffu);
    for (std::uint32_t off = 0x11b8u; off <= 0x11c4u; off += 4u) m.w32(p + off, 0);
    for (std::uint32_t off = 0x11c8u; off <= 0x11cdu; ++off) m.w8(p + off, 0);
    for (std::uint32_t off = 0x11d0u; off <= 0x11dcu; off += 4u) m.w32(p + off, 0);
    m.w32(p, 0x0078991cu);
    m.w32(0x0083ac68u, 0); m.w32(0x0083a944u, 0); m.w32(0x0083a960u, 0);
}

void init_62c6b0_zero(Memory& m, std::uint32_t p) {
    // Original 0x62c6b0 count=0 branch (0x62c6bb..0x62c740).
    m.w32(p + 4u, 0); m.w32(p + 8u, 0);
    m.w8(p + 0x0cu, 1); m.w8(p + 0x0du, 0);
    m.w32(p, 0x007937e4u);
    m.w32(p, 0x007937c4u);
    m.w32(p + 0x14u, 10); m.w32(p + 0x10u, 0);
}

void init_626470(Memory& m, MixedHeap& heap, TickClock& clock,
                 std::uint32_t p) {
    init_498830(m, p);
    const auto zero = std::uint32_t{0};
    m.w32(p + 0x11e4u, zero); m.w32(p + 0x11e8u, zero);
    m.w32(p + 0x11ecu, zero); m.w32(p + 0x11f0u, zero);
    m.w32(p + 0x11f4u, zero); m.w32(p + 0x11f8u, zero);
    m.w32(p + 0x11fcu, zero); m.w32(p + 0x1200u, zero);
    for (unsigned i=0;i<4;++i) m.w32(p+0x1208u+4u*i,m.r32(g_seed+4u*i));
    m.w32(p + 0x1218u, zero); m.w32(p + 0x121cu, zero);
    empty_vector(m,p+0x1220u,0x007875e0u,0x007875e0u,false);
    m.w32(p+0x1220u,0x007875a0u); m.w32(p+0x1234u,10); m.w32(p+0x1230u,0);
    m.w32(p+0x1238u,zero); m.w32(p+0x123cu,zero); m.w32(p+0x1240u,zero);
    m.w32(p+0x1244u,zero); m.w32(p+0x1248u,zero); m.w32(p+0x124cu,zero);
    m.w32(p+0x1250u,zero); m.w32(p+0x1254u,zero);
    empty_vector(m,p+0x1258u,0x00791f9cu,0x00791f9cu,false);
    m.w32(p+0x1258u,0x00791f7cu);
    m.w32(p+0x1258u+0x14u,10);m.w32(p+0x1258u+0x10u,0);
    m.w32(p+0x1270u,zero);
    for (unsigned i=0;i<0x16u;++i) {
        const auto row=p+0x1274u+i*0x18u;
        empty_vector(m,row,0x00791f9cu,0x00791f9cu,false);
        m.w32(row,0x00791f7cu); m.w32(row+0x14u,10); m.w32(row+0x10u,0);
    }
    m.w32(p+0x1484u,zero); m.w32(p+0x1488u,1u);
    m.w32(p+0x148cu,zero); m.w32(p+0x1490u,zero); m.w32(p+0x1494u,zero);
    for (unsigned i=0;i<4;++i) m.w32(p+0x1498u+4u*i,m.r32(g_seed+4u*i));
    m.w32(p+0x14a8u,zero); m.w32(p+0x14acu,zero); m.w32(p+0x14b0u,zero);
    m.w8(p+0x14b8u,0); m.w8(p+0x14b9u,0); m.w32(p+0x14d0u,0xffffffffu);
    m.w8(p+0x14d4u,0); m.w8(p+0x14d5u,0); m.w8(p+0x14d6u,0);
    for (unsigned i=0;i<4;++i) m.w32(p+0x14d8u+4u*i,m.r32(g_seed+4u*i));
    m.w32(p+0x14f8u,zero);
    m.w32(p+0x14fcu,clock.time_get_time()>>4u);
    m.w32(p+0x1504u,zero);

    m.w32(p,0x007936dcu);
    const auto child=heap.allocate(0x10u);
    need(child!=0,"319 finite route requires the successful 0x10 small allocation");
    m.w32(child+4u,0x006292e0u); m.w32(child+8u,0x100u); m.w32(child+0xcu,10u);
    const auto ordinary=heap.allocate(0x1804u);
    need(ordinary!=0,"319 finite route requires the successful 0x1804 ordinary allocation");
    m.w32(ordinary,0x100u);
    const auto rows=ordinary+4u;
    for(std::uint32_t i=0;i!=0x100u;++i) init_62c6b0_zero(m,rows+i*0x18u);
    m.w32(child,rows);
    for(std::uint32_t i=0;i!=0x100u;++i) m.w32(rows+i*0x18u+0x14u,10u);
    m.w32(p+0x1254u,child);

    // 0x405bf0 reached with ECX=p+0x14bc.
    m.w32(p+0x126cu,0x1f4u);
    m.w32(p+0x14c8u,0x008192ecu); m.w32(p+0x14bcu,0);
    m.w32(p+0x14c0u,0); m.w32(p+0x14c4u,0);
    m.w32(p+0x126cu,0x1f4u);
}

void init_214030(Memory& m, MixedHeap& heap, TickClock& clock,
                 std::uint32_t p) {
    init_626470(m,heap,clock,p);
    m.w8(p+0x1508u,0);
    m.w32(p+0x150cu,clock.time_get_time()>>4u);
    m.w32(p+0x1514u,0); m.w32(p+0x1518u,0);
    m.w32(p+0x151cu,clock.time_get_time()>>4u);
    m.w32(p+0x1524u,0); m.w32(p+0x1538u,0xffffffffu); m.w32(p+0x153cu,0xffffffffu);
    m.w32(p+0x1528u,0); m.w32(p+0x152cu,0); m.w32(p+0x1530u,0);
    m.w8(p+0x1534u,0); m.w32(p,0x007932ecu);
}

void callback_677bb0(Memory& m,std::uint32_t row) {
    m.w32(row+0x14u,0); m.w32(row+0x18u,m.r32(g_clock));
    m.w32(row+0x20u,0); m.w32(row+0x24u,0); m.w32(row+0x28u,1);
}

void init_273e00(Memory& m,std::uint32_t p) {
    m.w32(p,0);m.w32(p+4u,m.r32(g_clock));m.w32(p+0xcu,0);m.w32(p+0x10u,0);
    m.w32(p+0x14u,1);m.w32(p+0x1cu,0);m.w32(p+0x20u,0);
    for(unsigned k=0;k<4;++k)m.w32(p+0x24u+k*4u,m.r32(g_vec+k*4u));
    m.w32(p+0x34u,0);m.w8(p+0x38u,1);m.w8(p+0x39u,0);m.w8(p+0x3au,0);m.w8(p+0x3bu,0);
    m.w32(p+0x3cu,0xffffffffu);
    for(unsigned off=0x40;off<=0x50;off+=4)m.w32(p+off,0);
    for(unsigned k=0;k<75;++k){const auto row=p+0x68u+k*0x30u;
        m.w32(row,0);m.w32(row+4u,m.r32(g_clock));m.w32(row+0xcu,0);m.w32(row+0x10u,0);m.w32(row+0x14u,1);
    }
    for(unsigned k=0;k<75;++k){const auto row=p+0x54u+k*0x30u;
        m.w32(row,0);m.w32(row+4u,0);m.w32(row+8u,0);m.w32(row+0xcu,0);
    }
}
}

std::uint32_t fun_00671080(Memory& m,MixedHeap& heap,TickClock& clock,
                           EntryState& entry) {
    const auto receiver=entry.ecx;
    need(receiver!=0,"319 requires a nonzero receiver");
    need(std::uint64_t(receiver)+0x4ee7u<=0x100000000ull,
         "319 receiver span must not wrap");
    init_214030(m,heap,clock,receiver);
    for(unsigned k=0;k<4;++k){
        const auto p=receiver+0x1540u+k*0xe64u;
        m.w32(p,0);m.w32(p+4u,m.r32(g_clock));m.w32(p+0x0cu,0);
        m.w32(p+0x10u,0);m.w32(p+0x14u,1);
        for(unsigned j=0;j<75;++j)callback_677bb0(m,p+0x54u+j*0x30u);
    }
    m.w32(receiver+0x4ed8u,0);m.w32(receiver+0x4edcu,0);
    for(unsigned off=0x4ee0;off<=0x4ee1;++off)m.w8(receiver+off,0);
    m.w8(receiver+0x4ee2u,1);
    for(unsigned off=0x4ee4;off<=0x4ee6;++off)m.w8(receiver+off,0);
    m.w32(receiver,0x007962b0u);
    for(unsigned k=0;k<4;++k)init_273e00(m,receiver+0x1540u+k*0xe64u);
    entry.eax=receiver;
    return receiver;
}

} // namespace ra2::recovery_b319
