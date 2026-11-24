#include "recovery_b191.hpp"

#include <stdexcept>

namespace ra2::recovered::recovery_b191 {
using namespace global_b26;
namespace {
constexpr std::uint32_t g_items = 0x008192b0u;
constexpr std::uint32_t g_item_gate = 0x008192f8u;
constexpr std::uint32_t g_pool_cell = 0x00819300u;
constexpr std::uint32_t g_count = 0x008192e4u;
constexpr std::uint32_t g_capacity = 0x008192e8u;
constexpr std::uint32_t g_append_head = 0x008191e0u;
constexpr std::uint32_t g_pool_enabled = 0x007b7b68u;
constexpr std::uint32_t g_generation = 0x007b7b6cu;
constexpr std::uint32_t g_callback = 0x00819898u;
constexpr std::uint32_t g_locale_mode = 0x00b10530u;

// RVA 0x70f0 on the scalar control block's bounded 16.16 fields.
std::uint32_t control_update(Memory& m, std::uint32_t p) {
    const auto end = m.r32(p + 8u);
    const auto cur = m.r32(p + 4u);
    if (end == cur || (m.r8(p) & 1u) == 0) return 0;
    m.w32(p + 4u, end);
    m.w32(p, m.r32(p) | 2u);
    return 1;
}

// RVA 0x7030, constrained to 0x4092d0's observed null-function-pointer path.
void control_init(Memory& m, std::uint32_t p, std::uint32_t fixed_scale) {
    if (m.r32(g_callback) != 0)
        throw std::domain_error("Block191 excludes a nonnull 0x4092d0 function pointer");
    m.w32(p, 0);
    // 0x4092d0 returns EDX:EAX = 0:0 when [0x819898] is zero.
    m.w32(p + 0x18u, 0);
    m.w32(p + 0x10u, 0x3e8u);
    m.w32(p, 1u);
    m.w32(p + 8u, fixed_scale << 16);
    m.w32(p + 0x1cu, 0);
    m.w32(p + 0x0cu, 0x0010624du);
    m.w32(p + 0x14u, 0);
    (void)control_update(m, p);
}

// RVA 0x70d0 for the only reached arguments: divisor 1000 and value 0.
void control_set_rate(Memory& m, std::uint32_t p, std::uint32_t rate) {
    constexpr std::uint32_t divisor = 1000u;
    const std::uint32_t quotient = (rate << 16) / divisor;
    m.w32(p + 0x10u, divisor);
    m.w32(p + 0x0cu, quotient);
    m.w32(p + 0x14u, 0);
}

void control_set_position(Memory& m, std::uint32_t p, std::uint32_t position_hi) {
    m.w32(p, m.r32(p) | 1u);
    m.w32(p + 8u, position_hi << 16);
}

// Exact reached 0x401000 initializer: three 0x7030 initializations, three
// 0x70d0 rate updates, then the 0x7080 tail route.
void audio_controls_init(Memory& m, std::uint32_t p) {
    control_init(m, p, 0x4000u);
    control_init(m, p + 0x28u, 0x64u);
    control_init(m, p + 0x50u, 0x2000u);
    control_set_rate(m, p + 0x28u, 0xau);
    control_set_rate(m, p, 0x4000u);
    control_set_rate(m, p + 0x50u, 0x4000u);
    // 0x401000 tail-jumps 0x407080; it does not call 0x4070f0 here.
    control_set_position(m, p, 0x4000u);
}

std::uint32_t pool_pop(Memory& m, std::uint32_t cell) {
    const auto node = m.r32(cell);
    if (!node) return 0;
    m.w32(cell, m.r32(node));
    return node + 8u;
}

std::uint32_t append_tail(Memory& m, std::uint32_t sentinel, std::uint32_t node) {
    const auto tail = m.r32(sentinel + 4u);
    m.w32(node, sentinel);
    m.w32(node + 4u, tail);
    m.w32(sentinel + 4u, node);
    m.w32(tail, node);
    return tail;
}

bool same_fast_ascii(Memory& m, std::uint32_t a, std::uint32_t b) {
    if (m.r32(g_locale_mode) != 0)
        throw std::domain_error("Block191 constrains 0x36d860 to its byte-compare fast branch");
    for (std::uint32_t n = 0; n != 128u; ++n) {
        const auto ca = m.r8(a + n), cb = m.r8(b + n);
        if (ca != cb) return false;
        if (ca == 0) return true;
    }
    throw std::domain_error("Block191 keys must terminate within 128 bytes");
}
}

// RVA 0x5170, bounded to the nonempty recycle-list route. The argument is
// the matched item node from 0x6680, not an invented helper result.
std::uint32_t fun_00405170(Memory& m, const Inputs& i) {
    const auto item = i.cx;
    if (m.r32(g_pool_enabled) == 0 || m.r32(g_item_gate + 4u) == 0 ||
        m.r32(item + 0x0cu) == 0)
        throw std::domain_error("Block191 requires 0x5170 positive entry guards");

    const auto cell = m.r32(g_pool_cell);
    if (cell == 0) throw std::domain_error("Block191 requires the original pool-head cell");
    auto object = pool_pop(m, cell);
    if (object == 0) throw std::domain_error("Block191 excludes 0x5170 allocation fallback");

    auto count = m.r32(g_count) + 1u;
    const auto capacity = m.r32(g_capacity);
    m.w32(g_count, count);
    if (s32(count) > s32(capacity)) m.w32(g_capacity, count);

    for (std::uint32_t n = 0; n != 0xa0u; ++n) m.w32(object + n * 4u, 0);
    m.w32(object + 0x24u, item);
    m.w32(object, object);
    m.w32(object + 4u, object);
    m.w32(object + 8u, 0);
    m.w32(object + 0x1cu, 0);
    m.w32(object + 0x154u, 0);
    m.w32(object + 0x268u, 0);
    m.w32(object + 0x1e0u, 0);
    m.w32(object + 0xa8u, 0);
    audio_controls_init(m, object + 0xb8u);
    m.w32(object + 0x158u, 0);
    (void)append_tail(m, g_append_head, object);

    const auto generation = m.r32(g_generation);
    m.w32(object + 0x138u, generation);
    m.w32(g_generation, generation + 1u);
    return object;
}

// RVA 0x6680. Positive fixture domain: first list item has an inline key
// identical to ECX's key, the recycled pool node is available, and the
// scalar rate fields take the original bounded positive arithmetic route.
std::uint32_t fun_00406680(Memory& m, const Inputs& i) {
    if (m.r32(g_item_gate) == 0)
        throw std::domain_error("Block191 excludes the disabled-list early return");
    const auto item = m.r32(g_items);
    if (item == 0 || item == m.r32(item + 8u))
        throw std::domain_error("Block191 requires one present item");
    if (!same_fast_ascii(m, i.cx, item + 0x6cu))
        throw std::domain_error("Block191 requires a matching first item key");

    Inputs recycle{};
    recycle.cx = item;
    const auto object = fun_00405170(m, recycle);

    const auto ticks = i.dx;
    if (s32(ticks) <= 0 || ticks > 0x100u)
        throw std::domain_error("Block191 bounds the integer audio-time input to 1..256");
    const std::uint32_t converted = ticks * 0x40u; // 64-bit 0x36da00 then /0x100 at 0x36de10
    const auto rate_factor = m.r32(item + 0x1cu) >> 16;
    if (rate_factor < 0x100u || rate_factor > 0x200u)
        throw std::domain_error("Block191 bounds the item's 16.16 rate factor to 256..512");
    const auto position = (rate_factor * converted) >> 14;
    const auto control = object + 0xb8u;
    control_set_position(m, control, position);
    return control_update(m, control); // the single reached 0x70f0 call returns EAX=1
}
} // namespace ra2::recovered::recovery_b191
