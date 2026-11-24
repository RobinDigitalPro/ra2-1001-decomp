#include "boundary_b64.hpp"
#include <stdexcept>

namespace ra2::recovered::boundary_b64 {
namespace {
inline std::uint32_t invoke(const Operations& ops,Memory& m,std::uint32_t target,
                            std::vector<std::uint32_t> args) {
    if(!ops.invoke) throw std::invalid_argument("Block64 call boundary is required");
    return ops.invoke(m,target,args,ops.context);
}
}

// Original RVA 0x122ca0. Its formatting callee remains an explicit boundary:
// argument extraction/push order and the caller's post-call EAX assignment are
// reconstructed here, while formatting side effects belong to Operations.
std::uint32_t fun_00522ca0(Memory& m,const Inputs& i,const Operations& ops) {
    const auto p=i.cx;
    const auto d0=m.r32(p);
    const auto d1=m.r32(p+4u);
    const auto w2=m.r16(p+8u);
    const std::uint32_t byte0=d0&0xffu;
    const std::uint32_t byte1=(d0>>8)&0xffu;
    const std::uint32_t byte2=(d0>>16)&0xffu;
    const std::uint32_t byte3=(d0>>24)&0xffu;
    const std::uint32_t byte4=d1&0xffu;
    const std::uint32_t byte5=(d1>>8)&0xffu;
    const std::uint32_t byte6=(d1>>16)&0xffu;
    const std::uint32_t byte7=(d1>>24)&0xffu;
    const std::uint32_t byte8=w2&0xffu;
    const std::uint32_t byte9=(w2>>8)&0xffu;
    invoke(ops,m,0x0076da34u,{0x00a39f24u,0x007c8d30u,
        byte0,byte1,byte2,byte3,byte4,byte5,byte6,byte7,byte8,byte9});
    // The original discards the callee result and installs this pointer in EAX.
    return 0x00a39f24u;
}

// Original RVA 0x29e1b0. The callback at 0x76e2ca is the original one-argument
// registration boundary. After that call, the caller reloads all values it
// consumes, so callback register returns are intentionally not fabricated.
std::uint32_t fun_0069e1b0(Memory& m,const Inputs& i,const Operations& ops) {
    const auto object=i.cx;
    const auto flag=m.r8(0x00aa60d0u);
    if((flag&1u)==0u) {
        // Writes mirror the initializer branch in instruction order. The pairs
        // are the original eight-entry signed direction table at 0xaa6078.
        m.w32(0x00aa6078u,0u);          m.w32(0x00aa607cu,0xffffffffu);
        m.w32(0x00aa6080u,1u);          m.w32(0x00aa6084u,0xffffffffu);
        m.w32(0x00aa6088u,1u);
        m.w32(0x00aa6090u,1u);
        m.w32(0x00aa608cu,0u);
        m.w32(0x00aa6098u,0u);
        m.w32(0x00aa6094u,1u);
        m.w32(0x00aa609cu,1u);
        m.w32(0x00aa60a0u,0xffffffffu); m.w32(0x00aa60a4u,1u);
        m.w32(0x00aa60a8u,0xffffffffu);m.w32(0x00aa60acu,0u);
        const auto new_flag=std::uint32_t((flag|1u)&0xffu);
        m.w8(0x00aa60d0u,new_flag);
        m.w32(0x00aa60b0u,0xffffffffu); m.w32(0x00aa60b4u,0xffffffffu);
        (void)invoke(ops,m,0x0076e2cau,{0x0069e2b0u});
    }

    const auto index=i.arg[0];
    const auto stride=i.arg[1];
    const auto old_left=m.r32(object+0xd64u);
    const auto old_right=m.r32(object+0xd68u);
    const auto table=0x00aa6078u+index*8u;
    const auto left_delta=m.r32(table)*stride;
    const auto right_delta=m.r32(table+4u)*stride;
    const auto candidate_left=left_delta+old_left;
    const auto candidate_right=right_delta+old_right;
    if(candidate_left==old_left && candidate_right==old_right)
        return candidate_left;

    // The original writes delta-adjusted fields and leaves EAX holding the
    // resulting right endpoint (it is the base value used for the final store).
    const auto new_left=m.r32(object+0xd74u)+(candidate_left-old_left);
    const auto right_field=m.r32(object+0xd78u);
    const auto new_right=right_field+(candidate_right-old_right);
    m.w32(object+0xd74u,new_left);
    m.w32(object+0xd78u,new_right);
    return new_right;
}
}
