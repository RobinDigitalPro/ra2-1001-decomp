#include "recovery_b361.hpp"

#include "recovered/map_b106.hpp"
#include "recovered/direct_b33_memory.hpp"
#include "recovered/floating_callers_b40_memory.hpp"
#include <array>
#include <cstdint>
#include <stdexcept>
#include <utility>

namespace ra2::recovered::global_b26 {
std::uint32_t fun_00545500(Memory&, const Inputs&);
}

namespace ra2::recovered::recovery_b361 {
namespace {
using U = std::uint32_t;
using I = std::int32_t;
constexpr U kMap = 0x702c0u;
constexpr U kHeight = 0x75960u;
constexpr U kConvert = 0x297fb0u;
constexpr U kOuterReturn = 0x13579bdfu;
constexpr U kPrivateStackBase = 0x7e000000u;
constexpr U kHeightStack = kPrivateStackBase + 0x1000u;
constexpr U kConvertStack = kPrivateStackBase + 0x8100u;
constexpr U kOutput = kPrivateStackBase + 0x0200u;

const ra2::recovered::direct_b33::Entry& height_entry() {
    for (const auto& e : ra2::recovered::direct_b33::entries_a())
        if (e.rva == kHeight) return e;
    throw std::runtime_error("missing accepted 0x75960 translation");
}
struct MapContext { Memory* memory{}; ra2::platform::x87::State* fp{}; };
void invoke_map(Memory& m, ra2::recovered::direct_b33::State& s,
                const ra2::recovered::direct_b33::Call& call, void* raw) {
    auto& ctx = *static_cast<MapContext*>(raw);
    if (call.target != kMap || call.argument_words != 1u || call.cleanup != 4u)
        throw std::runtime_error("0x75960 reached an unreviewed call boundary");
    ra2::recovered::map_b106::Inputs in{};
    in.cx = s.cx; in.arg[0] = m.r32(call.sp + 4u); in.fp = *ctx.fp;
    s.ax = ra2::recovered::map_b106::fun_004702c0(*ctx.memory, in);
    *ctx.fp = in.fp;
}
struct HeightOutput { U x{}, y{}, height{}; };
HeightOutput call_height(Memory& m, U entity, U ebp, ra2::platform::x87::State& fp) {
    std::array<std::uint8_t, 0x5000> stack_bytes{};
    Memory cm = m;
    ra2::recovered::leaf::Memory stack(stack_bytes.data(), kPrivateStackBase,
                                       std::uint32_t(stack_bytes.size()));
    cm.add(stack);
    auto s = ra2::recovered::direct_b33::State{};
    s.cx = entity; s.bp = ebp; s.bx = 0x2468ace0u;
    s.si = 0x10203040u; s.di = 0x50607080u;
    auto& e = height_entry();
    auto f = ra2::recovered::direct_b33::Frame{
        kHeightStack, kHeightStack, kOuterReturn, kOuterReturn, 4u, 1u, kMap};
    cm.w32(kHeightStack, kOuterReturn); cm.w32(kHeightStack+4u, kOutput);
    cm.w32(kHeightStack+8u, ebp);
    MapContext context{&cm, &fp};
    const ra2::recovered::direct_b33::Operations ops{invoke_map, &context};
    e.function(cm, s, f, ops);
    if (f.sp != kHeightStack+8u || s.ax != kOutput)
        throw std::runtime_error("0x75960 stack/result contract differs");
    return {cm.r32(kOutput), cm.r32(kOutput+4u), cm.r32(kOutput+8u)};
}
U call_converter(Memory& m, U ecx, ra2::platform::x87::State& fp) {
    std::array<std::uint8_t, 0x1000> stack_bytes{};
    Memory cm = m;
    ra2::recovered::leaf::Memory stack(stack_bytes.data(), kPrivateStackBase+0x8000u,
                                       std::uint32_t(stack_bytes.size()));
    cm.add(stack);
    const auto& entries = ra2::recovered::floating_callers_b40::entries_a();
    const ra2::recovered::floating_callers_b40::Entry* selected = nullptr;
    for (const auto& e : entries) if (e.rva == kConvert) selected = &e;
    if (!selected) throw std::runtime_error("missing accepted 0x297fb0 translation");
    auto s = ra2::recovered::floating_callers_b40::State{}; s.cx = ecx; s.fp = fp;
    auto f = ra2::recovered::floating_callers_b40::Frame{};
    f.entry_sp = kConvertStack; f.sp = kConvertStack; f.return_sp = kConvertStack;
    f.outer_return = kOuterReturn; cm.w32(kConvertStack, kOuterReturn);
    selected->function(cm, s, f, {});
    if (f.sp != kConvertStack+4u) throw std::runtime_error("0x297fb0 stack contract differs");
    fp = s.fp; return s.ax;
}

I arithmetic_shift(U value, unsigned bits) {
    return static_cast<I>(ra2::recovered::global_b26::sar(value, bits));
}
U sign_word(U value) { return I(value) < 0 ? 0xffffffffu : 0u; }
std::pair<I, I> project(HeightOutput h, U converted) {
    U eax = h.x * 3u; eax = eax + eax * 4u; eax <<= 2u;
    U edx = sign_word(eax); eax -= edx;
    U edi = U(arithmetic_shift(eax, 1u));
    eax = h.x * 3u; eax = eax + eax * 4u; eax <<= 1u;
    edx = sign_word(eax); eax -= edx;
    U ecx = eax;
    eax = h.y << 4u; eax -= h.y; eax = 0u - eax; eax <<= 2u;
    edx = sign_word(eax); eax -= edx; eax = U(arithmetic_shift(eax, 1u));
    edi += eax;
    eax = h.y * 3u; ecx = U(arithmetic_shift(ecx, 1u));
    eax = eax + eax * 4u; eax <<= 1u;
    edx = sign_word(eax); eax -= edx; eax = U(arithmetic_shift(eax, 1u));
    ecx += eax;
    eax = edi; edx = sign_word(eax) & 0xffu; eax += edx;
    const I screen_x = arithmetic_shift(eax, 8u);
    eax = ecx; edx = sign_word(eax) & 0xffu; eax += edx;
    const I screen_y = arithmetic_shift(eax, 8u) - I(converted);
    return {screen_x, screen_y};
}

U packed(U x, U y) { return (x & 0xffffu) | ((y & 0xffffu) << 16); }
I signed16(U v) {
    v &= 0xffffu;
    return v < 0x8000u ? I(v) : I(v) - 0x10000;
}

bool diamond_contains(Memory& m, U object, U xy) {
    const I x = signed16(xy), y = signed16(xy >> 16);
    const I d = I(m.r32(object + 0xf0u));
    const I twice_height = I(m.r32(object + 0xf4u) * 2u);
    const I sum = x + y;
    return sum > d && x - y < d && y - x < d &&
           sum <= I(U(d) + U(twice_height));
}

U cell_at(Memory& m, U manager, U xy, const Inputs& in,
          ra2::recovered::leaf::Memory& scratch_span) {
    Memory local = m;
    local.add(scratch_span);
    local.w16(0x7d010000u, xy);
    local.w16(0x7d010002u, xy >> 16);
    ra2::recovered::global_b26::Inputs lookup{};
    lookup.cx = manager;
    lookup.arg[0] = 0x7d010000u;
    lookup.arithmetic_flags = in.arithmetic_flags;
    return ra2::recovered::global_b26::fun_00545500(local, lookup);
}

// This is the `bit 0x08`-clear/bit 0x10-clear path of 0x2a0410. The original
// accepted 0x75960 and 0x297fb0 bodies execute through their reviewed call
// contracts; 0x4702c0 is reached by the height helper. With map-cell XY
// in the reviewed small positive range, the original integer projection is
// exactly (30*(x-y), 15*(x+y+1)); the 0x297fb0 conversion receives zero and,
// under the pinned empty x87/0x0e7f precondition, leaves physical R7=0.5 and the precision status bit after truncation.
U queue_cell(Memory& m, U queue, U entity, const Inputs& in) {
    const U epoch = m.r32(0xa2896cu);
    const U flags = m.r8(entity + 0x12cu);
    if (m.r32(0x81a82cu) != 0u || m.r32(entity + 0x5cu) == epoch ||
        (flags & 0x10u) != 0u || (!(flags & 8u) && !m.r8(entity + 0x138u)) ||
        static_cast<std::int8_t>(m.r8(entity + 0x11bu)) < -4 ||
        static_cast<std::int8_t>(m.r8(entity + 0x11bu)) > 4 ||
        m.r8(entity + 0x11cu) != 0u)
        throw std::domain_error("0x2a0410 outside the reviewed 9cca0 insertion route");

    const I x = signed16(m.r16(entity + 0x24u));
    const I y = signed16(m.r16(entity + 0x26u));
    if (x < 19 || x > 21 || y < 19 || y > 21)
        throw std::domain_error("0x2a0410 XY outside the bounded 3x3 route");

    m.w32(entity + 0x5cu, epoch);
    const auto height = call_height(m, entity, 0xdecafbadu, in.fp);
    const U converted = call_converter(m, 0u, in.fp);
    if (converted != 0u)
        throw std::domain_error("0x297fb0 conversion did not produce the reviewed zero");

    const auto [screen_x, screen_y] = project(height, converted);
    const I relative_x = screen_x - I(m.r32(queue + 0xb0u));
    const I relative_y = screen_y - I(m.r32(queue + 0xb4u));
    const I min_x = I(m.r32(0x821970u)) - 0x1e;
    const I max_x = I(m.r32(0x821978u)) + I(m.r32(0x821970u)) + 0x1e;
    const I max_y = I(m.r32(0x821974u)) + I(m.r32(0x82197cu)) + 0xf;
    if (relative_x < min_x || relative_x > max_x || relative_y < -0x1e ||
        relative_y > max_y)
        throw std::domain_error("0x2a0410 projection is outside the supplied viewport");

    const U count = m.r32(queue + 0xe0u);
    if (count >= 0x31fu) throw std::domain_error("0x2a0410 queue is full");
    m.w32(queue + 0xe4u + count * 4u, entity);
    m.w32(queue + 0xe0u, count + 1u);
    m.w8(entity + 0x138u, 0u);
    m.w8(queue + 0xd7du, 1u);
    return count + 1u;
}
}

U fun_0009cca0(Memory& m, const Inputs& in) {
    const U manager = in.cx;
    const U coords = in.arg[0];
    const U queue = m.r32(0x821cacu);
    if (manager != 0x81a820u || m.r32(manager + 0x138u) != m.r32(0x81a958u) ||
        !queue || m.r32(manager + 0xf0u) != 30u || m.r32(manager + 0xf4u) != 20u ||
        m.r32(0x821970u) != 0xffffff9cu || m.r32(0x821978u) != 1000u ||
        m.r32(0x821974u) != 1000u || m.r32(0x82197cu) != 1000u ||
        m.r32(queue + 0xb0u) != 0u || m.r32(queue + 0xb4u) != 0u ||
        in.fp.image.word(0) != 0x0e7fu || in.fp.image.word(8) != 0xffffu)
        throw std::domain_error("0x9cca0 outside the pinned manager/queue/x87 route");

    const U center = packed(m.r16(coords), m.r16(coords + 2u));
    if (signed16(center) != 20 || signed16(center >> 16) != 20 ||
        !diamond_contains(m, manager, center))
        throw std::domain_error("0x9cca0 center outside the reviewed diamond");

    std::array<std::uint8_t, 0x1000> stack{};
    ra2::recovered::leaf::Memory scratch_span(stack.data(), 0x7d010000u,
                                                std::uint32_t(stack.size()));
    const U center_cell = cell_at(m, manager, center, in, scratch_span);
    if ((m.r8(center_cell + 0x12cu) & 8u) == 0u)
        throw std::domain_error("0x9cca0 center cell lacks required bit 0x08");
    m.w32(center_cell + 0x12cu, m.r32(center_cell + 0x12cu) & 0xffffffe7u);
    (void)queue_cell(m, queue, center_cell, in);

    for (U k = 0; k < 8u; ++k) {
        const U d = 0x839da0u + 4u * k;
        const U xy = packed(m.r16(d) + m.r16(coords), m.r16(d + 2u) + m.r16(coords + 2u));
        in.arg[0] = xy; // The original writes the packed candidate into caller arg0.
        const U entity = cell_at(m, manager, xy, in, scratch_span);
        if (scratch_span.r16(0x7d010000u) == m.r16(coords) &&
            scratch_span.r16(0x7d010002u) == m.r16(coords + 2u))
            continue;
        m.w32(entity + 0x12cu, m.r32(entity + 0x12cu) & 0xffffffefu);
        (void)queue_cell(m, queue, entity, in);
    }
    return m.r32(queue + 0xe0u);
}
}
