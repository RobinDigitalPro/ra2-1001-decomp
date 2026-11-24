#include "recovered/allocation_families.hpp"

namespace ra2::recovered {
namespace {
std::uint32_t family_49(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops,
                         std::uint32_t initial_tag, unsigned shift) {
    const std::uint32_t count = in.arg[0];
    m.w32(in.cx + 4u, 0u);
    m.w32(in.cx + 8u, count);
    m.w8(in.cx + 0xcu, 1u);
    m.w8(in.cx + 0xdu, 0u);
    m.w32(in.cx, initial_tag);
    if (count == 0u) return in.cx;
    const std::uint32_t supplied = in.arg[1];
    if (supplied != 0u) {
        m.w32(in.cx + 4u, supplied);
        return in.cx;
    }
    const std::uint32_t bytes = count << shift;
    const std::uint32_t allocated = fun_0076d957(bytes, ops);
    m.w32(in.cx + 4u, allocated);
    m.w8(in.cx + 0xdu, 1u);
    return in.cx;
}
std::uint32_t family_18(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops,
                         std::uint32_t initial_tag, std::uint32_t final_tag) {
    const std::uint32_t count = in.arg[0];
    m.w32(in.cx + 4u, 0u);
    m.w32(in.cx + 8u, count);
    m.w8(in.cx + 0xcu, 1u);
    m.w8(in.cx + 0xdu, 0u);
    m.w32(in.cx, initial_tag);
    if (count != 0u) {
        const std::uint32_t supplied = in.arg[1];
        if (supplied != 0u) {
            m.w32(in.cx + 4u, supplied);
        } else {
            const std::uint32_t bytes = count << 2u;
            const std::uint32_t allocated = fun_0076d957(bytes, ops);
            m.w32(in.cx + 4u, allocated);
            m.w8(in.cx + 0xdu, 1u);
        }
    }
    m.w32(in.cx, final_tag);
    m.w32(in.cx + 0x14u, 10u);
    m.w32(in.cx + 0x10u, 0u);
    return in.cx;
}
} // namespace

std::uint32_t fun_0040bc10(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_49(m, in, ops, 0x007857fcu, 2u);
}

std::uint32_t fun_0042b510(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_49(m, in, ops, 0x007874fcu, 2u);
}

std::uint32_t fun_00454750(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_49(m, in, ops, 0x007880acu, 2u);
}

std::uint32_t fun_0046cc20(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_49(m, in, ops, 0x007889d4u, 2u);
}

std::uint32_t fun_0046cdf0(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_18(m, in, ops, 0x007889d4u, 0x00788a94u);
}

std::uint32_t fun_0046d7d0(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_49(m, in, ops, 0x00788a14u, 2u);
}

std::uint32_t fun_0047cce0(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_49(m, in, ops, 0x0078819cu, 2u);
}

std::uint32_t fun_0047fc70(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_49(m, in, ops, 0x00788d5cu, 2u);
}

std::uint32_t fun_004911c0(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_49(m, in, ops, 0x0078957cu, 2u);
}

std::uint32_t fun_004965b0(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_49(m, in, ops, 0x00789744u, 2u);
}

std::uint32_t fun_004a9f20(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_49(m, in, ops, 0x0078bb10u, 2u);
}

std::uint32_t fun_004a9f70(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_49(m, in, ops, 0x0078bb30u, 2u);
}

std::uint32_t fun_004ba030(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_49(m, in, ops, 0x0078bf64u, 2u);
}

std::uint32_t fun_004bf840(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_49(m, in, ops, 0x0078591cu, 2u);
}

std::uint32_t fun_004ce770(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_49(m, in, ops, 0x0078c79cu, 2u);
}

std::uint32_t fun_004de970(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_49(m, in, ops, 0x0078db64u, 2u);
}

std::uint32_t fun_004f7e00(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_49(m, in, ops, 0x0078d784u, 2u);
}

std::uint32_t fun_004f7e50(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_49(m, in, ops, 0x0078da44u, 2u);
}

std::uint32_t fun_004f7ea0(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_49(m, in, ops, 0x0078df08u, 2u);
}

std::uint32_t fun_004f7ef0(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_49(m, in, ops, 0x00789660u, 2u);
}

std::uint32_t fun_004f7f40(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_49(m, in, ops, 0x0078db04u, 2u);
}

std::uint32_t fun_004f7f90(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_49(m, in, ops, 0x0078d384u, 2u);
}

std::uint32_t fun_004f9f90(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_18(m, in, ops, 0x0078e118u, 0x0078e178u);
}

std::uint32_t fun_004fa360(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_18(m, in, ops, 0x0078e138u, 0x0078e198u);
}

std::uint32_t fun_004fa730(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_18(m, in, ops, 0x0078e158u, 0x0078e1b8u);
}

std::uint32_t fun_004faac0(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_49(m, in, ops, 0x0078e118u, 2u);
}

std::uint32_t fun_004fab10(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_49(m, in, ops, 0x0078e138u, 2u);
}

std::uint32_t fun_004fab60(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_49(m, in, ops, 0x0078e158u, 2u);
}

std::uint32_t fun_0050a8d0(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_18(m, in, ops, 0x0078eb5cu, 0x0078eb7cu);
}

std::uint32_t fun_0050acb0(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_49(m, in, ops, 0x0078eb5cu, 2u);
}

std::uint32_t fun_0051dc50(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_49(m, in, ops, 0x0078ec04u, 2u);
}

std::uint32_t fun_0052cff0(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_49(m, in, ops, 0x0079024cu, 2u);
}

std::uint32_t fun_00530140(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_49(m, in, ops, 0x007903b4u, 2u);
}

std::uint32_t fun_0053c5b0(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_49(m, in, ops, 0x0078d4c4u, 2u);
}

std::uint32_t fun_0058af70(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_18(m, in, ops, 0x0078df08u, 0x0078df28u);
}

std::uint32_t fun_0058bd60(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_49(m, in, ops, 0x00790d90u, 2u);
}

std::uint32_t fun_0058be40(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_49(m, in, ops, 0x00790998u, 2u);
}

std::uint32_t fun_0058c010(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_49(m, in, ops, 0x00790e4cu, 2u);
}

std::uint32_t fun_0058c0d0(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_49(m, in, ops, 0x00790f74u, 3u);
}

std::uint32_t fun_005a3980(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_49(m, in, ops, 0x00791898u, 2u);
}

std::uint32_t fun_005b5e50(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_18(m, in, ops, 0x00792168u, 0x00792148u);
}

std::uint32_t fun_005b60d0(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_49(m, in, ops, 0x0078d804u, 2u);
}

std::uint32_t fun_005b6120(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_49(m, in, ops, 0x0078d884u, 2u);
}

std::uint32_t fun_005b6170(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_49(m, in, ops, 0x00792168u, 2u);
}

std::uint32_t fun_005c5e00(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_18(m, in, ops, 0x00792348u, 0x00792368u);
}

std::uint32_t fun_005c6180(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_49(m, in, ops, 0x00792348u, 2u);
}

std::uint32_t fun_00604c80(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_49(m, in, ops, 0x0078d2c4u, 2u);
}

std::uint32_t fun_00612860(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_18(m, in, ops, 0x0079329cu, 0x0079327cu);
}

std::uint32_t fun_00612b70(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_18(m, in, ops, 0x007932bcu, 0x0079325cu);
}

std::uint32_t fun_0064a3e0(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_18(m, in, ops, 0x00793fc0u, 0x0079402cu);
}

std::uint32_t fun_0064a7d0(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_18(m, in, ops, 0x00793fe0u, 0x0079404cu);
}

std::uint32_t fun_0064aae0(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_18(m, in, ops, 0x00794000u, 0x0079406cu);
}

std::uint32_t fun_0064ba00(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_49(m, in, ops, 0x00793fc0u, 2u);
}

std::uint32_t fun_0064ba50(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_49(m, in, ops, 0x00793fe0u, 2u);
}

std::uint32_t fun_0064baa0(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_49(m, in, ops, 0x00794000u, 2u);
}

std::uint32_t fun_0065a490(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_18(m, in, ops, 0x00788a14u, 0x0078bb9cu);
}

std::uint32_t fun_0066a420(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_49(m, in, ops, 0x007944ccu, 2u);
}

std::uint32_t fun_0066a520(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_49(m, in, ops, 0x0078d444u, 2u);
}

std::uint32_t fun_006807e0(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_49(m, in, ops, 0x007967f4u, 2u);
}

std::uint32_t fun_00691a00(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_49(m, in, ops, 0x0079705cu, 2u);
}

std::uint32_t fun_006d4ea0(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_18(m, in, ops, 0x007880acu, 0x007880ccu);
}

std::uint32_t fun_006ed720(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_18(m, in, ops, 0x007857fcu, 0x0078579cu);
}

std::uint32_t fun_006ed780(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_18(m, in, ops, 0x007915ecu, 0x007915ccu);
}

std::uint32_t fun_006ed830(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_49(m, in, ops, 0x007915ecu, 2u);
}

std::uint32_t fun_00719290(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_18(m, in, ops, 0x00790998u, 0x00790ee4u);
}

std::uint32_t fun_00725030(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_49(m, in, ops, 0x0079204cu, 2u);
}

std::uint32_t fun_00725080(leaf::Memory& m, const leaf::Inputs& in, const AllocationWrapperOperations& ops) {
    return family_49(m, in, ops, 0x00791f1cu, 2u);
}

} // namespace ra2::recovered
