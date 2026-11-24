#include "recovery_b297.hpp"
#include "recovery_b297_composed.hpp"
#include <stdexcept>

namespace ra2::recovered::recovery_b297 {
namespace {


// The original 0x191300 caller body invokes 0x1ca970 and then initializes
// its outer fields. Keep this exact composition visible so the helper is the
// accepted implementation, not a test callback result.
void compose_00191300(Memory& m,std::uint32_t c) {
    Inputs nested{}; nested.cx=c;
    fun_005ca970(m,nested);
    m.w32(c+0x98,ones); m.w32(c+0x9c,ones); m.w32(c+0xa0,ones);
    m.w8(c+0xa4,0); m.w32(c+0xa8,0); m.w32(c+0xac,0);
    m.w32(c+0xb0,m.r32(0x00a2896cu)); m.w32(c+0xb8,0);
    m.w32(c+0x00,0x007911e8u); m.w32(c+0x04,0x007911ccu);
    m.w32(c+0x08,0x007911c4u); m.w32(c+0x0c,0x007911bcu);
}
}

std::uint32_t fun_0062ddd0(Memory& m,Inputs& in,
                           ra2::platform::small_crt_heap::Heap& heap) {
    const auto c=in.cx;
    compose_00191300(m,c);
    m.w32(c+0xcc,0); m.w32(c+0xd0,1); m.w8(c+0xd4,1);
    m.w8(c+0xd5,0); m.w32(c+0xc8,0x007857fcu);
    // This draft passes the exact root request to the live heap adapter.
    const auto child=heap.allocate(4u);
    m.w32(c+0xcc,child); m.w8(c+0xd5,1);
    m.w32(c+0x00,0x007938a8u); m.w32(c+0x04,0x0079388cu);
    m.w32(c+0x08,0x00793884u); m.w32(c+0x0c,0x0079387cu);
    heap.w32(child,0); m.w32(c+0xbc,0); m.w32(c+0xc0,0);
    m.w32(c+0xc4,0);
    return c;
}
}
