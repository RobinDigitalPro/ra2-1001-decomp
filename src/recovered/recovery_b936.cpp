#include "recovered/recovery_b936.hpp"
#include "recovered/recovery_b274.hpp"
#include <array>
#include <stdexcept>

namespace ra2::recovered::recovery_b936 {
namespace {
void require(bool ok, const char* text) { if (!ok) throw std::domain_error(text); }
std::uint32_t load16(const std::uint8_t* p, unsigned off) {
    return std::uint32_t(p[off]) | (std::uint32_t(p[off+1]) << 8);
}
std::uint32_t load32(const std::uint8_t* p, unsigned off) {
    return load16(p,off) | (load16(p,off+2) << 16);
}
}

std::uint32_t fun_0076f1bf(Memory& m, const Inputs& in, const Ops& op) {
    require(op.get_local_time && op.get_system_time && op.get_time_zone_information,
            "36f1bf requires real GetLocalTime/GetSystemTime/GetTimeZoneInformation forwarders");
    std::array<std::uint8_t,16> local{};
    std::array<std::uint8_t,16> utc{};
    op.get_local_time(op.context, local.data());
    op.get_system_time(op.context, utc.data());

    const bool cache_hit = load16(utc.data(),10)==m.r16(0xb1044au) &&
        load16(utc.data(),8)==m.r16(0xb10448u) &&
        load16(utc.data(),6)==m.r16(0xb10446u) &&
        load16(utc.data(),2)==m.r16(0xb10442u) &&
        load16(utc.data(),0)==m.r16(0xb10440u);
    std::uint32_t dst = m.r32(0xb10438u);
    if (!cache_hit) {
        std::array<std::uint8_t,172> zone{};
        const auto status=op.get_time_zone_information(op.context,zone.data());
        require(status!=0xffffffffu, "36f1bf finite route excludes GetTimeZoneInformation failure");
        require(status<=2u, "36f1bf finite route accepts TIME_ZONE_ID_UNKNOWN/STANDARD/DAYLIGHT only");
        dst=0;
        if (status==2u && load16(zone.data(),154)!=0u && load32(zone.data(),168)!=0u) dst=1;
        m.w32(0xb10438u,dst);
        for (unsigned k=0;k<4;++k) m.w32(0xb10440u+4u*k,load32(utc.data(),4u*k));
    }
    require(dst<=1u, "36f1bf cached DST flag must match the accepted B274 finite contract");

    global_b26::Inputs h{};
    h.arg[0]=load16(local.data(),0);  // year
    h.arg[1]=load16(local.data(),2);  // month
    h.arg[2]=load16(local.data(),6);  // day
    h.arg[3]=load16(local.data(),8);  // hour
    h.arg[4]=load16(local.data(),10); // minute
    h.arg[5]=load16(local.data(),12); // second
    h.arg[6]=dst;
    const auto result=ra2::recovered::recovery_b274::fun_00776572(m,h);
    if (in.arg[0]) m.w32(in.arg[0],result);
    return result;
}
}
