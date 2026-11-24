#include "recovery_b1373.hpp"
#include <cstdint>
#include <limits>
#include <stdexcept>
namespace ra2::recovered::b1373 {
namespace {
using U = std::uint32_t;
void need(bool ok, const char* why) { if (!ok) throw std::domain_error(why); }

// The accepted/indexed 0x730e40 helper is reached on this default mode. Its
// finite contract reads A255C8 and returns AL=0 here; the caller only tests AL.
bool original_730e40_al_zero(Memory& m) {
    need(m.r32(0xa255c8u) == 0, "1373 actual 730e40 default-mode input");
    return false;
}
}

U fun_0051f740(Memory& m, const Inputs&) {
    // 0x51f852 state-2 route only. The state-1 refresh/store route is excluded.
    need(m.r32(0xa3957cu) == 2, "1373 phase-2 timer state");
    const U interval = m.r32(0x7c8bdcu);
    const U start = m.r32(0x7c8bd8u);
    const U now = m.r32(0xa2896cu);
    need(interval > 0 && start <= 0x7fffffffu && interval <= 0x7fffffffu - start && now <= 0x7fffffffu,
         "1373 finite positive timer interval and start");
    need(now > start + interval,
         "1373 expired signed timer interval");

    // The exact phase-2 path at 0x51f872 clears A3957C. It does not reach the
    // state-1-only store at 0x51f778, so 7C8BD8 remains unchanged.
    m.w32(0xa3957cu, 0);
    need(m.r32(0xa39518u) == 0 && m.r32(0xa39558u) == 0 && m.r32(0xa394d0u) == 0,
         "1373 skip all populated timer queues");
    need(m.r8(0xa39584u) == 0 && m.r8(0xa39574u) == 0,
         "1373 skip follow-up UI/timer branches");
    const U countdown = m.r32(0xa39578u);
    need(countdown >= 2 && countdown <= 200, "1373 nonterminal positive countdown");
    const U remaining = countdown - 1;
    m.w32(0xa39578u, remaining);
    // Actual CDQ/IDIV 225: with remaining in [1,199], quotient is zero and
    // remainder is nonzero, so the root exits with full EAX=0 and no message.
    need(remaining % 225u != 0, "1373 no terminal countdown message");
    return remaining / 225u;
}

U fun_005c4940(Memory& m, const Inputs& i) {
    // Explicit root ABI values: [entry ESP+4] is arg0, EDX is the other sentinel.
    need(i.arg[0] == 0xffffffffu && i.dx == 0xffffffffu,
         "1373 original -1/-1 default arguments");
    need(m.r32(0xa255ccu) == 0 && m.r32(0xa255c8u) == 0,
         "1373 null provider and default mode");
    const U old = m.r32(0x7d11c4u);
    need(old <= 7, "1373 bounded previous slot count");
    need(!original_730e40_al_zero(m), "1373 actual default helper AL branch");
    // Original default path writes 8 at 0x5c4a14 and again at 0x5c4c49.
    // The intervening route has no other global effects; final byte/word state is 8.
    m.w32(0x7d11c4u, 8);
    i.arg[0] = 8; // Original MOV [current ESP+0x1C],ESI (entry ESP+4) overwrites outer arg0.
    return 8;
}
}
