#include "recovery_b227.hpp"
#include "platform/observed_ticks152.hpp"
#include <algorithm>
#include <array>
#include <stdexcept>

namespace ra2::recovered::recovery_b227 {
namespace {
constexpr std::uint32_t list_count = 0x00a288b0u;
constexpr std::uint32_t list_data = 0x00a288a4u;
constexpr std::uint32_t ring_count = 0x00a1a668u;
constexpr std::uint32_t ring_tail = 0x00a1a670u;
constexpr std::uint32_t ring_records = 0x00a1a674u;
constexpr std::uint32_t ring_ticks = 0x00a1ddf4u;
constexpr std::uint32_t record_size = 111u;
constexpr std::uint32_t sound_owner_table = 0x00821b88u;

void need(bool ok, const char* message) {
    if (!ok) throw std::domain_error(message);
}

std::int32_t signed32(std::uint32_t x) { return static_cast<std::int32_t>(x); }

// Original call at 0x6c1af4 enters RVA 0xb5c00 with four words:
// [arg0] = [A1E0E4]+0x30, [arg1] = action index 6,
// [arg2] = the dword 11 produced by 0x2aaaf0, [arg3] = its byte 0x34.
// B5C00 reads the actual index-6 table word and calls the actual one-byte
// RET at RVA 0x68f0. That leaf has no register or memory effects.
void build_record(Memory& m, const Inputs& i, std::uint32_t object,
                  std::array<std::uint8_t, 111>& out) {
    // Frame 209 fills every DWORD in the 0x400-byte region below entry ESP
    // with stack_minus8. The copied record begins at entry ESP-136, an
    // aligned location within that region.
    for (unsigned k = 0; k < record_size; ++k)
        out[k] = static_cast<std::uint8_t>(i.stack_minus8 >> (8u * (k & 3u)));

    const auto primary = m.r32(object);
    need(primary == 0x00787bbcu, "227 requires constructor-proven primary vptr");
    need(m.r32(primary + 0x2cu) == 0x00453890u,
         "227 requires the pinned +2c getter used by the real 2aaaf0 helper");
    need(m.r32(primary + 0x9cu) == 0x0044a620u,
         "227 requires the pinned positive +9c action predicate");

    const auto secondary = m.r32(object + 4u);
    need(secondary == 0x00787ba0u && m.r32(secondary + 0x10u) == 0x0040ffc0u,
         "227 requires the constructor-proven secondary +10 getter");
    // 2AAAF0 takes its real fallback branch (the +2c getter returns 6),
    // obtains dword 11 through the authentic secondary +10 getter, and writes
    // dword 11 / byte 0x34 into temporary stack slots. The caller passes those
    // slots as B5C00's third and fourth arguments; they are not record bytes.
    const auto helper_value = m.r32(object + 0x10u);
    need(helper_value == 11u, "227 bounded 2aaaf0 selector requires value 11");

    const auto global_object = m.r32(0x00a1e0e4u);
    const auto value = m.r32(global_object + 0x30u);
    need(signed32(value) >= 0,
         "227 positive B5C00 route requires nonnegative [A1E0E4]+0x30");

    // B5C00 uses its actual second argument (action index 6), so the original
    // table read is at 0x7c16fc + 4*6 == 0x7c1714.
    (void)m.r32(0x007c1714u);
    out[0] = 6u; // B5C00 stores BL from the action-index argument.
    out[2] = static_cast<std::uint8_t>(value); // B5C00 MOV [ESI+2],AL.
    const auto timer = m.r32(0x00a2896cu);
    for (unsigned k = 0; k < 4; ++k)
        out[3u + k] = static_cast<std::uint8_t>(timer >> (8u * k));
    for (unsigned k = 0; k < 4; ++k)
        out[7u + k] = static_cast<std::uint8_t>(helper_value >> (8u * k));
    out[11] = 0x34u; // B5C00 CL is the low byte of its fourth argument.
    // record[1] and [12..110] are untouched x86 stack residue.
}
}

std::uint32_t fun_006eabb0(Memory& m, const Inputs& i) {
    const auto count = m.r32(list_count);
    need(signed32(count) == 1, "227 bounded single-entry action list required");
    const auto array = m.r32(list_data);
    const auto object = m.r32(array);
    need(object != 0 && (m.r8(object + 0x14u) & 1u) != 0,
         "227 requires one nonnull, action-enabled list item");

    // Exact reached prefix of RVA 0x4a620: this <=0 field check and a nested
    // selector of 0x10 return true, so the root skips +0x98 and reaches +0x31c.
    need(signed32(m.r32(object + 0x3fcu)) <= 0,
         "227 +9c gate requires nonpositive receiver field");
    const auto owner = m.r32(object + 0x418u);
    const auto owner_kind = m.r32(owner + 0xc44u);
    need(owner_kind == 0x10u, "227 +9c gate requires original accepted selector 0x10");
    need(m.r32(m.r32(object) + 0x31cu) == 0x006c1ac0u,
         "227 requires pinned +31c action RVA 0x2c1ac0");

    const auto old_count = m.r32(ring_count);
    const auto tail = m.r32(ring_tail);
    need(old_count < 0x80u && tail < 0x80u,
         "227 positive ring enqueue requires count/tail in [0,127]");
    need(m.r8(0x00a5e2fcu) == 0,
         "227 requires the genuine 60c420 gate to select enqueue branch");

    std::array<std::uint8_t, record_size> record{};
    build_record(m, i, object, record);
    const auto destination = ring_records + record_size * tail;
    for (unsigned k = 0; k < record_size; ++k) m.w8(destination + k, record[k]);

    // RVA 0x785524 is the actual imported timeGetTime slot.  The adapter only
    // observes the real OS call; it never supplies a result to either side.
    const auto tick = ra2::platform::ticks152::Tick::get();
    m.w32(ring_ticks + 4u * tail, tick);
    m.w32(ring_tail, (tail + 1u) & 0x7fu);
    m.w32(ring_count, old_count + 1u);

    // The actual final call to 0x708970 is bounded to its signed-negative-ID
    // path. It writes only its transient [ESP+0xc] local, skips every sound
    // lookup/create/play method, and returns EAX=0.  The global state change
    // above remains the observable successful action.
    const auto owner_table = m.r32(sound_owner_table);
    const auto sound_id = m.r32(owner_table + 0x640u);
    need(signed32(sound_id) < 0, "227 final original sound helper requires negative ID");
    return 0u;
}
}
