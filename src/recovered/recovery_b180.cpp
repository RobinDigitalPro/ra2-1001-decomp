// Block180: only the documented positive pool/list route.
#include "recovery_b180.hpp"

#include <stdexcept>

namespace ra2::recovered::global_b26 {
std::uint32_t fun_00406140(Memory&, const Inputs&);
}

namespace ra2::recovered::recovery_b180 {
using namespace ra2::recovered::global_b26;

namespace {
constexpr std::uint32_t kPoolHead = 0x00ab82c4u;
constexpr std::uint32_t kList = 0x00ab8250u;
constexpr std::uint32_t kIndexedCount = 0x00ab82a8u;
constexpr std::uint32_t kObjectCount = 0x00ab82c8u;
constexpr std::uint32_t kObjectCapacity = 0x00ab82ccu;
constexpr std::uint32_t kGate = 0x008192f8u;
constexpr std::uint32_t kEmbeddedTag = 0x008192ecu;

// Exact reached 0x6100 branch for this route (record tag matches, EDX=0,
// EDI=0): store zero to [record], store EDI at +8, then return before any
// target dereference. The accepted leaf adapter uses a different Memory ABI,
// so this closed instruction branch is expressed against the root's Memory.
void clear_embedded_target(Memory& m, std::uint32_t record) {
    if (m.r32(record + 0x0cu) != kEmbeddedTag) return;
    m.w32(record, 0);
    m.w32(record + 8u, 0);
}
}

// RVA 0x308e50 (VA 0x708e50), bounded route:
//   ECX=index 0, EDX=readable source triplet, arg[0]=entry S+4 word;
//   indexed count and global gate are original zero BSS; pool/list prestate is
//   explicit synthetic valid state. The actual 0x308a20 integer skip branch
//   returns ESI=0, after which 0x6100 updates the embedded record as observed.
// This is not a claim that the game startup path populates these globals.
std::uint32_t fun_00708e50(Memory& m, const Inputs& i) {
    if (i.cx != 0 || m.r32(kIndexedCount) != 0 || m.r32(kGate) != 0)
        throw std::domain_error("outside Block180 bounded state route");

    // VA 0x407450 / RVA 0x7450: AB82C4 points to a separate head cell;
    // pop its node value, then update the cell (not the global pointer).
    const auto pool_head_cell = m.r32(kPoolHead);
    if (pool_head_cell == 0) throw std::domain_error("Block180 requires supplied pool-head cell");
    const auto node = m.r32(pool_head_cell);
    if (node == 0) throw std::domain_error("Block180 requires supplied nonempty pool");
    m.w32(pool_head_cell, m.r32(node));
    const auto object = node + 8u;
    const auto embedded = object + 0x0cu;

    // VA 0x405bf0 / RVA 0x5bf0: exact four-DWORD embedded initializer.
    m.w32(embedded, 0);
    m.w32(embedded + 4u, 0);
    m.w32(embedded + 8u, 0);
    m.w32(embedded + 0x0cu, kEmbeddedTag);

    // VA 0x407200 / RVA 0x7200: circular-list node initialization.
    m.w32(object, object);
    m.w32(object + 4u, object);
    m.w32(object + 8u, 0);

    // Four saved registers and the PUSH EBX at 0x708e98 make ESP=S-20.
    // Therefore [ESP+0x18] at 0x708ea9 reads S+4, Inputs.arg[0].
    // This selected raw stack contract agrees with the observed RET 4.
    m.w32(object + 0x30u, 0);
    m.w32(object + 0x20u, m.r32(i.dx));
    m.w32(object + 0x24u, m.r32(i.dx + 4u));
    m.w32(object + 0x28u, m.r32(i.dx + 8u));
    m.w32(object + 0x2cu, i.arg[0]);

    // VA 0x708a20 / RVA 0x308a20. Index 0 with [AB82A8]=0 takes JGE at
    // 0x708a34, preserving initial EDI=0 and skipping table, float, allocation,
    // and virtual-dispatch blocks. Pinned [8192F8]=0 makes reached 0x6140
    // return zero. Then exact reached 0x6100 is executed with target/value 0.
    const auto index = i.cx;
    if (s32(index) < 0) throw std::domain_error("negative index excluded");
    if (s32(index) < s32(m.r32(kIndexedCount)))
        throw std::domain_error("indexed-table route excluded");
    Inputs validate{};
    validate.cx = embedded;
    const std::uint32_t target = fun_00406140(m, validate);
    if (target != 0) throw std::domain_error("zero global gate must return EAX=0");
    clear_embedded_target(m, embedded);

    // VA 0x407350 / RVA 0x7350: append object to actual doubly-linked list.
    const auto next = m.r32(kList + 4u);
    m.w32(object, kList);
    m.w32(object + 4u, next);
    m.w32(kList + 4u, object);
    m.w32(m.r32(object + 4u), object);

    // Root counter update, including original signed JLE capacity condition.
    auto count = m.r32(kObjectCount) + 1u;
    const auto capacity = m.r32(kObjectCapacity);
    m.w32(kObjectCount, count);
    if (s32(count) > s32(capacity)) m.w32(kObjectCapacity, count);

    // Root returns the full EAX from 0x308a20, which is the zero ESI result.
    return 0;
}
} // namespace ra2::recovered::recovery_b180
