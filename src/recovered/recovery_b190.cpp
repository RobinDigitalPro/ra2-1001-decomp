#include "recovery_b190.hpp"

#include <stdexcept>

namespace ra2::recovered::recovery_b190 {
namespace {
// Exact 0x4e0840 leaf: MOV DL,[ECX]; XOR EAX,EAX; TEST DL,DL; SETZ AL; RET.
// This route reaches it only for NUL record starts.
std::uint32_t fun_004e0840(Memory& m, std::uint32_t record) {
    return m.r8(record) == 0u ? 1u : 0u;
}
}

std::uint32_t fun_005fb220(Memory& m, const Inputs& i) {
    const auto cursor = i.cx;
    const auto top = m.r32(0x00a5df68u);
    if (!top) throw std::domain_error("Block190 requires the bounded iterator manager");
    const auto rows_desc = m.r32(top + 0x0cu);
    if (!rows_desc) throw std::domain_error("Block190 requires a row descriptor");
    const auto rows = m.r32(rows_desc);
    const auto row_count = m.r32(rows_desc + 8u);
    if (!rows || row_count == 0u || row_count > 8u)
        throw std::domain_error("Block190 row count must be in 1..8");

    if (m.r8(cursor + 8u) != 0u) return 0u; // original already-exhausted exit

    auto row_index = m.r32(cursor);
    auto position = m.r32(cursor + 4u);
    for (;;) {
        if (row_index >= row_count) {
            m.w8(cursor + 8u, 1u);
            return 0u;
        }

        const auto row = rows + row_index * 0x18u;
        const auto row_length = m.r32(row + 0x10u);
        if (row_length > 3u)
            throw std::domain_error("Block190 bounded NUL scan limits each row to three records");
        if (position >= row_length) {
            m.w32(cursor + 4u, 0u);
            ++row_index;
            m.w32(cursor, row_index);
            position = 0u;
            continue;
        }

        // Original LEA EBP,[record_base + (position*65)*4].
        const auto record = m.r32(row + 4u) + position * 0x104u;
        ++position;
        m.w32(cursor + 4u, position);
        const auto empty = fun_004e0840(m, record) != 0u;
        if (!empty)
            throw std::domain_error("Block190 bounded route excludes computed nonempty-record dispatch");

        if (position < row_length) continue;
        m.w32(cursor + 4u, 0u);
        ++row_index;
        m.w32(cursor, row_index);
        position = 0u;
    }
}
} // namespace ra2::recovered::recovery_b190
