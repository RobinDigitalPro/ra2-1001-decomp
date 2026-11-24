#include "recovery_b379.hpp"
#include "platform/x87_b61.hpp"
#include "platform/x87_extended_b40.hpp"
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b379 {
namespace {
void need(bool ok, const char* why) {
    if (!ok) throw std::domain_error(why);
}

// Bounded model of the pinned 0x4ba080 table path. The caller x87 instruction
// order is transcribed below; the arithmetic/table synthesis duplicates the
// accepted B348 finite route and still requires root-specific native review.
std::uint32_t pinned_positive_sqrt(Memory& m, Inputs const& i, std::uint64_t sum) {
    auto& fp = i.fp;
    fp.load64(sum); // original CALL 0x4ba080 consumes the qword local
    fp.compare32(m.r32(0x00785738u));
    need((fp.status() & 0x4000u) == 0, "zero squared distance excluded");
    fp.compare32(m.r32(0x00785738u));
    need((fp.status() & 0x4100u) == 0, "negative/zero squared distance excluded");
    const auto bits = fp.pop32(); // bounded model of FSTP float
    std::uint32_t ecx = bits & 0x007fffffu;
    std::uint32_t eax = (bits >> 23) - 0x7fu;
    if ((eax & 1u) != 0u) ecx |= 0x00800000u;
    const auto ax = static_cast<std::uint16_t>(eax);
    const auto half = static_cast<std::int16_t>(ax) >> 1;
    eax = static_cast<std::uint32_t>(static_cast<std::int32_t>(half)) + 0x7fu;
    ecx >>= 10;
    const auto table = m.r32(0x0080013cu + ecx * 4u);
    eax <<= 23;
    const auto result = table + eax;
    need((sum == 0x4039000000000000ull && result == 0x40a00000u) ||
         (sum == 0x40f9000000000000ull && result == 0x43a00000u),
         "only pinned exact norm rows 25->5 and 102400->320 are modeled");
    fp.load32(result);
    return result;
}

std::uint32_t exact_distance(Memory& m, Inputs const& i,
                             std::int32_t dx, std::int32_t dy, std::int32_t dz) {
    auto& fp = i.fp;
    // FILD dword at 0x5cd2e6, 0x5cd2ea, 0x5cd2ee (dy,dz,dx).
    fp.load_integer32(static_cast<std::uint32_t>(dy));
    fp.load_integer32(static_cast<std::uint32_t>(dz));
    fp.load_integer32(static_cast<std::uint32_t>(dx));
    // Original 0x5cd2f5..0x5cd303 register-level x87 operations.
    fp.load_st0();
    ra2::platform::x87_extended::multiply_st1(fp);
    fp.load_st2();
    ra2::platform::x87_extended::multiply_st3(fp);
    fp.add_pop();
    ra2::platform::x87_b61::reg<0xd9c3>(fp);
    ra2::platform::x87_extended::multiply_st4(fp);
    fp.add_pop();
    const auto sum = fp.pop64(); // FSTP qword [ESP] at 0x5cd305
    ra2::platform::x87_b61::reg<0xddd8>(fp);
    ra2::platform::x87_b61::reg<0xddd8>(fp);
    ra2::platform::x87_b61::reg<0xddd8>(fp);
    need(sum == 0x4039000000000000ull || sum == 0x40f9000000000000ull,
         "only the 3-4-0 and 192-256-0 squared norms are modeled");
    (void)pinned_positive_sqrt(m, i, sum); // CALL 0x4ba080
    need(fp.control() == m.r32(0x007c3a04u),
         "exclude the 0x76aa50 control-word replacement route");
    return static_cast<std::uint32_t>(fp.pop_integer64()); // CALL 0x76aa50, low EAX
}

void copy_coordinates(Memory& m, std::uint32_t object, std::int32_t (&xyz)[3]) {
    // Concrete bytes at slot target 0x5cd4d0 copy object+0x88..+0x90 to
    // caller's 12-byte temporary; signed interpretation follows later FILDs.
    xyz[0] = static_cast<std::int32_t>(m.r32(object + 0x88u));
    xyz[1] = static_cast<std::int32_t>(m.r32(object + 0x8cu));
    xyz[2] = static_cast<std::int32_t>(m.r32(object + 0x90u));
}
}

std::uint32_t fun_005cd290(Memory& m, const Inputs& i) {
    const auto receiver = i.cx;
    const auto other = i.arg[0]; // [ESP+0x30] after prologue; RET 4
    if (other == 0u) return 0u; // TEST/JNZ, XOR EAX,EAX at 0x5cd29b..a2
    need(receiver != 0u, "positive route requires a nonnull ECX receiver");
    const auto vptr = m.r32(receiver);
    need(vptr == 0x0078612cu && m.r32(other) == vptr,
         "both objects must use constructor-proven vptr 0x78612c");
    need(m.r32(vptr + 0x48u) == 0x005cd4d0u,
         "slot +0x48 must be the pinned coordinate-copy target");
    need(m.r32(vptr + 0x2cu) == 0x0041b580u,
         "slot +0x2c must be the pinned type-2 target");

    std::int32_t a[3]{}, b[3]{};
    copy_coordinates(m, other, a);    // first virtual getter, 0x5cd2b3
    copy_coordinates(m, receiver, b); // second virtual getter, 0x5cd2c1
    const auto dx = static_cast<std::int64_t>(b[0]) - a[0];
    const auto dy = static_cast<std::int64_t>(b[1]) - a[1];
    const auto dz = static_cast<std::int64_t>(b[2]) - a[2];
    need((dx == 3 && dy == 4 && dz == 0) ||
         (dx == 192 && dy == 256 && dz == 0),
         "fixture is restricted to the two positive receiver-minus-other deltas");
    const auto distance = exact_distance(m, i, static_cast<std::int32_t>(dx),
                                         static_cast<std::int32_t>(dy),
                                         static_cast<std::int32_t>(dz));
    // Actual pinned slot target bytes at 0x41b580: B8 02 00 00 00 C3
    // (MOV EAX,2; RET). This concrete target excludes 6, so 0x5cd331 branches
    // directly to 0x5cd35a and never reads other+0x418 or extent helpers.
    constexpr std::uint32_t observed_type = 2u;
    if (observed_type == 6u) {
        throw std::logic_error("type-6 adjustment has no modeled evidence");
    }
    need(observed_type == 2u, "this contract only models observed type 2");
    return distance; // MOV EAX,EBX at 0x5cd35b; caller cleanup is RET 4
}
}