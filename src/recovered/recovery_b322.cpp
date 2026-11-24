#include "recovery_b322.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b322 {
constexpr unsigned kRecordTablePointer=0xb10e3c,kRecordCount=0xb11e40;
std::uint32_t fun_0076fd9e(Memory& m, const Inputs& inputs, Locks& locks) {
    // The finite route takes the nonempty registry path and mode-1 counter.
    // 0x7715b6(2) is the outer lock. Its already-populated slot selects the
    // direct EnterCriticalSection branch and avoids the allocation branch.
    if (inputs.arg[0] != 1u || m.r32(kRecordCount) != 1u)
        throw std::domain_error("Block322 slice requires mode 1 and one registry record");
    locks.enter( 2u);

    const auto record_table = m.r32(kRecordTablePointer);
    if (record_table == 0u)
        throw std::domain_error("Block322 slice requires a nonnull registry table");
    const auto record = m.r32(record_table);
    if (record == 0u || (m.r8(record + 0x0cu) & 0x83u) == 0u)
        throw std::domain_error("Block322 slice requires a nonnull selected record");

    // 0x76ff68(0, record) calls 0x7715b6(28). The initialized slot is used
    // directly; its matched 0x76ffba counterpart leaves the same real lock.
    locks.enter( 28u);
    const auto flags = m.r32(record + 0x0cu);
    if ((flags & 0x83u) == 0u || (flags & 3u) != 2u ||
        (flags & 0x108u) == 0u || (m.r8(record + 0x0du) & 0x40u) != 0u)
        throw std::domain_error("Block322 slice requires the observed mode-1 record flags");

    const auto start = m.r32(record + 8u);
    if (m.r32(record) != start)
        throw std::domain_error("Block322 slice requires an empty record range");

    // 0x76fd39 sees diff==0, skips 0x774915, clears [record+4], writes
    // [record]=[record+8], and returns zero. Then 0x76fd0b returns zero
    // because byte [record+0xd] lacks bit 0x40; mode 1 increments EBX.
    m.w32(record + 4u, 0u);
    m.w32(record, start);
    locks.leave( 28u);
    locks.leave( 2u);
    return 1u;
}
}
