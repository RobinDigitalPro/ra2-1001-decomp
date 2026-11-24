#include "recovered/lookup_b100.hpp"
#include "recovered/crt_b83.hpp"
namespace ra2::recovered::lookup_b100 {
namespace {
using global_b26::s32;
std::uint32_t compare(Memory& m, std::uint32_t a, std::uint32_t b) {
    Inputs q{}; q.arg[0] = a; q.arg[1] = b;
    return crt_b83::fun_0076d860(m, q);
}
std::uint32_t find(Memory& m, std::uint32_t key, std::uint32_t count_at,
                   std::uint32_t table_at, unsigned sentinels, bool pointer_result) {
    if (sentinels >= 1 && compare(m, key, 0x007b8e5cu) == 0) return 0;
    if (sentinels >= 2 && compare(m, key, 0x007b907cu) == 0) return 0;
    const auto count = m.r32(count_at);
    if (s32(count) <= 0) return 0;
    const auto table = m.r32(table_at);
    for (std::uint32_t index = 0; index < count; ++index) {
        const auto record = m.r32(table + index * 4u);
        if (compare(m, key, record + 0x24u) == 0)
            return pointer_result ? record : index;
    }
    return 0;
}
}
std::uint32_t fun_0040f2f0(Memory& m, const Inputs& i) { return find(m, i.cx, 0x00821e50u, 0x00821e44u, 2, false); }
std::uint32_t fun_0041c250(Memory& m, const Inputs& i) { return find(m, i.cx, 0x00a255b8u, 0x00a255acu, 2, true); }
std::uint32_t fun_0041def0(Memory& m, const Inputs& i) { return find(m, i.cx, 0x00a255a0u, 0x00a25594u, 2, true); }
std::uint32_t fun_00464cd0(Memory& m, const Inputs& i) { return find(m, i.cx, 0x00a1e030u, 0x00a1e024u, 2, true); }
std::uint32_t fun_005d55f0(Memory& m, const Inputs& i) { return find(m, i.cx, 0x00a1e128u, 0x00a1e11cu, 2, true); }
std::uint32_t fun_006194f0(Memory& m, const Inputs& i) { return find(m, i.cx, 0x00a1e140u, 0x00a1e134u, 1, false); }
std::uint32_t fun_0067db00(Memory& m, const Inputs& i) { return find(m, i.cx, 0x00a28818u, 0x00a2880cu, 2, true); }
std::uint32_t fun_006ac600(Memory& m, const Inputs& i) { return find(m, i.cx, 0x00a284f0u, 0x00a284e4u, 2, true); }
std::uint32_t fun_006e3f80(Memory& m, const Inputs& i) { return find(m, i.cx, 0x0084e548u, 0x0084e53cu, 2, true); }
std::uint32_t fun_00715af0(Memory& m, const Inputs& i) { return find(m, i.cx, 0x00821e50u, 0x00821e44u, 2, true); }
} // namespace ra2::recovered::lookup_b100
