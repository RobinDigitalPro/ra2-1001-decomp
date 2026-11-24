#include "recovery_b356.hpp"

#include "recovered/direct_b33_memory.hpp"
#include "recovered/floating_callers_b40_memory.hpp"
#include "recovered/map_b106.hpp"

#include <stdexcept>

namespace ra2::recovered::recovery_b356 {
namespace {
using U = std::uint32_t;
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

struct MapContext {
    Memory* memory{};
    ra2::platform::x87::State* fp{};
};

void invoke_map(Memory& m, ra2::recovered::direct_b33::State& s,
                const ra2::recovered::direct_b33::Call& call, void* raw) {
    auto& ctx = *static_cast<MapContext*>(raw);
    if (call.target != kMap || call.argument_words != 1u || call.cleanup != 4u)
        throw std::runtime_error("0x75960 reached an unreviewed call boundary");
    ra2::recovered::map_b106::Inputs in{};
    in.cx = s.cx;
    in.arg[0] = m.r32(call.sp + 4u);
    in.fp = *ctx.fp;
    s.ax = ra2::recovered::map_b106::fun_004702c0(*ctx.memory, in);
    *ctx.fp = in.fp;
}

U call_height(Memory& m, U entity, U ebp, ra2::platform::x87::State& fp) {
    std::array<std::uint8_t, 0x5000> stack_bytes{};
    Memory call_memory = m;
    ra2::recovered::leaf::Memory private_stack(stack_bytes.data(), kPrivateStackBase,
                                               std::uint32_t(stack_bytes.size()));
    call_memory.add(private_stack);
    auto state = ra2::recovered::direct_b33::State{};
    state.cx = entity;
    state.bp = ebp;
    state.bx = 0x2468ace0u;
    state.si = 0x10203040u;
    state.di = 0x50607080u;
    auto& e = height_entry();
    auto frame = ra2::recovered::direct_b33::Frame{
        kHeightStack, kHeightStack, kOuterReturn, kOuterReturn, 4u, 1u, kMap};
    call_memory.w32(kHeightStack, kOuterReturn);
    call_memory.w32(kHeightStack + 4u, kOutput);
    call_memory.w32(kHeightStack + 8u, ebp);
    MapContext context{&call_memory, &fp};
    const ra2::recovered::direct_b33::Operations operations{invoke_map, &context};
    e.function(call_memory, state, frame, operations);
    if (frame.sp != kHeightStack + 8u || state.ax != kOutput)
        throw std::runtime_error("0x75960 stack/result contract differs");
    return call_memory.r32(kOutput + 8u);
}

U call_converter(Memory& m, U ecx, ra2::platform::x87::State& fp) {
    std::array<std::uint8_t, 0x1000> stack_bytes{};
    Memory call_memory = m;
    ra2::recovered::leaf::Memory private_stack(stack_bytes.data(), kPrivateStackBase + 0x8000u,
                                               std::uint32_t(stack_bytes.size()));
    call_memory.add(private_stack);
    const auto& entries = ra2::recovered::floating_callers_b40::entries_a();
    const ra2::recovered::floating_callers_b40::Entry* selected = nullptr;
    for (const auto& e : entries) if (e.rva == kConvert) selected = &e;
    if (!selected) throw std::runtime_error("missing accepted 0x297fb0 translation");
    auto state = ra2::recovered::floating_callers_b40::State{};
    state.cx = ecx;
    state.fp = fp;
    auto frame = ra2::recovered::floating_callers_b40::Frame{};
    frame.entry_sp = kConvertStack;
    frame.sp = kConvertStack;
    frame.return_sp = kConvertStack;
    frame.outer_return = kOuterReturn;
    call_memory.w32(kConvertStack, kOuterReturn);
    selected->function(call_memory, state, frame, {});
    if (frame.sp != kConvertStack + 4u) throw std::runtime_error("0x297fb0 stack contract differs");
    fp = state.fp;
    return state.ax;
}
}

U fun_002a0410(Memory& m, const Inputs& i) {
    const U receiver = i.cx;
    const U entity = i.arg[0];
    if (m.r32(0x81a82cu) != 0u || m.r32(entity + 0x5cu) == m.r32(0xa2896cu) ||
        (m.r8(entity + 0x12cu) & 0x10u) != 0u || m.r8(entity + 0x138u) == 0u ||
        static_cast<std::int8_t>(m.r8(entity + 0x11bu)) < -4 ||
        static_cast<std::int8_t>(m.r8(entity + 0x11bu)) > 4 ||
        m.r8(entity + 0x11cu) != 0u || m.r16(entity + 0x24u) != 0u ||
        m.r16(entity + 0x26u) != 0u)
        throw std::domain_error("0x2a0410 case is outside the reviewed zero-XY route");
    if (m.r32(receiver + 0xb0u) != 0u || m.r32(receiver + 0xb4u) != 0u) throw std::domain_error("reviewed receiver origin is zero");
    const U count = m.r32(receiver + 0xe0u);
    if (count >= 0x31fu) throw std::domain_error("0x2a0410 queue is full");
    if (m.r32(0x821970u) != 0u || m.r32(0x821978u) != 0u ||
        m.r32(0x82197cu) != 0u || m.r32(0x821974u) < 15u)
        throw std::domain_error("0x2a0410 viewport does not admit the reviewed point");

    m.w32(entity + 0x5cu, m.r32(0xa2896cu));
    // Execute both actual accepted helper translations reached by this path.
    if (m.r8(0x838f70u) != 7u || m.r32(0x838f80u) != 60u ||
        m.r32(0x838ef0u) != 0u || m.r32(0x838ef4u) != 0x404e0000u ||
        m.r32(0x838f10u) != 0u || m.r32(0x838f14u) != 0x3fce0000u)
        throw std::domain_error("0x702c0 cache must already be initialized on this route");
    (void)call_height(m, entity, 0xdecafbad, i.fp);
    if (call_converter(m, 0u, i.fp) != 0u)
        throw std::domain_error("0x297fb0 conversion did not produce the reviewed zero");

    // The root's default flags branch maps zero XY to (0,15), then queues it.
    m.w32(receiver + 0xe4u + 4u * count, entity);
    m.w32(receiver + 0xe0u, count + 1u);
    m.w8(entity + 0x138u, 0u);
    m.w8(receiver + 0xd7du, 1u);
    return count + 1u;
}
}
