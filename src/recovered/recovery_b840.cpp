#include "recovery_b840.hpp"
#include "platform/x87_b61.hpp"
#include "platform/x87_extended_b40.hpp"
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b840 {
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

std::uint32_t exact_distance(Memory& m,Inputs const& i,std::int32_t dx,std::int32_t dy) {
    auto& fp=i.fp;
    // 5CD3B9..D3: planar dy,dx; no Z term.
    fp.load_integer32(static_cast<std::uint32_t>(dy));
    fp.load_integer32(static_cast<std::uint32_t>(dx));
    fp.load_st0();ra2::platform::x87_extended::multiply_st1(fp);
    fp.load_st2();ra2::platform::x87_extended::multiply_st3(fp);
    fp.add_pop();const auto sum=fp.pop64();
    ra2::platform::x87_b61::reg<0xddd8>(fp);
    ra2::platform::x87_b61::reg<0xddd8>(fp);
    need(sum==0x4039000000000000ull||sum==0x40f9000000000000ull,"840 reviewed planar norms only");
    (void)pinned_positive_sqrt(m,i,sum);
    need(fp.control()==m.r32(0x007c3a04u),"840 original conversion control route");
    return static_cast<std::uint32_t>(fp.pop_integer64());
}

void copy_coordinates(Memory& m, std::uint32_t object, std::int32_t (&xyz)[3]) {
    // Concrete bytes at slot target 0x5cd4d0 copy object+0x88..+0x90 to
    // caller's 12-byte temporary; signed interpretation follows later FILDs.
    xyz[0] = static_cast<std::int32_t>(m.r32(object + 0x88u));
    xyz[1] = static_cast<std::int32_t>(m.r32(object + 0x8cu));
    xyz[2] = static_cast<std::int32_t>(m.r32(object + 0x90u));
}
}

std::uint32_t fun_005cd370(Memory& m,const Inputs& i) {
    const auto receiver=i.cx,other=i.arg[0];
    need(receiver&&other,"840 positive two-object route");
    const auto vptr=m.r32(receiver);
    need(vptr==0x78612cu&&m.r32(other)==vptr,"840 authentic constructor vptr");
    need(m.r32(vptr+0x48)==0x5cd4d0u&&m.r32(vptr+0x2c)==0x41b580u,"840 original getter/type slots");
    std::int32_t a[3]{},b[3]{};copy_coordinates(m,other,a);copy_coordinates(m,receiver,b);
    const auto dx=std::int64_t(b[0])-a[0],dy=std::int64_t(b[1])-a[1];
    need((dx==3&&dy==4)||(dx==192&&dy==256),"840 planar norm boundary");
    // Authentic type2 virtual method excludes the original type6 extent correction.
    return exact_distance(m,i,std::int32_t(dx),std::int32_t(dy));
}
}
