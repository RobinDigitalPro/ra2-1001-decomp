#include "recovered/recovery_b853.hpp"
#include "platform/x87_b61.hpp"
#include "platform/x87_extended_b40.hpp"
#include <cstdint>
#include <stdexcept>
namespace ra2::recovered::recovery_b853 {namespace {using U=std::uint32_t;
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
    // Root 43434E,43435B,43435F: dy,dz,dx.
    fp.load_integer32(static_cast<std::uint32_t>(dy));
    fp.load_integer32(static_cast<std::uint32_t>(dz));
    fp.load_integer32(static_cast<std::uint32_t>(dx));
    // Original root 434363..434371, identical arithmetic order.
    fp.load_st0();
    ra2::platform::x87_extended::multiply_st1(fp);
    fp.load_st2();
    ra2::platform::x87_extended::multiply_st3(fp);
    fp.add_pop();
    ra2::platform::x87_b61::reg<0xd9c3>(fp);
    ra2::platform::x87_extended::multiply_st4(fp);
    fp.add_pop();
    const auto sum = fp.pop64(); // FSTP qword [ESP] at 0x434373
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


}
std::uint32_t fun_00434230(Memory&m,const Inputs&i){using U=std::uint32_t;const U s=i.cx;need(i.arg[0]==3&&m.r32(s)==0x7877e0&&m.r32(0x787980)==0x41b320,"853 mode3 authenticreceiver");
 const int cx=std::int32_t(m.r32(s+0x88))/256,cy=std::int32_t(m.r32(s+0x8c))/256;need(cx==4&&cy==4,"853 boundedtranslatedcell");const U context=m.r32(m.r32(s+0xcc)+0x1b4),table=m.r32(0x81a958);need(context&&table,"853 initializedmapandcontext");m.w32(s+0x98,0);m.w32(s+0xc4,3);m.w32(s+0x9c,0);U best=0;std::int32_t distance=9999999;unsigned count=0;
 for(int x=cx-1;x<=cx+1;++x)for(int y=cy-1;y<=cy+1;++y){U cell=m.r32(table+4*(y*512+x));need(cell!=0,"853 allninecellsvalid");for(U o=m.r32(cell+0xe4);o;o=m.r32(o+0x30)){need(++count<=2&&m.r32(o)==0x798c88&&m.r32(0x798cb4)==0x6fee90&&m.r32(0x798cc4)==0x6bca10&&m.r32(0x798cd0)==0x5cd4d0,"853 originalunitvslotsandboundedlists");U member=m.r32(o+0x1b4);need(member!=0,"853 member");U index=m.r32(member+0x30);bool reject=member==context||index==m.r32(context+0x30);if(!reject&&index!=0xffffffffu)reject=(m.r32(context+0x5674)&(1u<<(index&31)))!=0;if(reject)continue;
 std::int32_t dx=std::int32_t(m.r32(o+0x88)-m.r32(s+0x88)),dy=std::int32_t(m.r32(o+0x8c)-m.r32(s+0x8c)),dz=std::int32_t(m.r32(o+0x90)-m.r32(s+0x90));need((dx==-192&&dy==-256&&dz==0)||(dx==3&&dy==4&&dz==0),"853 exactnormroute");auto d=std::int32_t(exact_distance(m,i,dx,dy,dz));if(d<distance){distance=d;best=o;}}}
 need(count==2&&best,"853 positiveclosestcandidate");m.w32(s+0xc8,best);return best;
}
}
