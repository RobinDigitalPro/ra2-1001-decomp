#include "recovery_b341.hpp"

#include <cstdint>
#include <cstring>
#include <stdexcept>

namespace ra2::recovered::recovery_b341 {
namespace {
using U = std::uint32_t;
void require(bool ok, const char* why) {
    if (!ok) throw std::domain_error(why);
}
U checked_add(U a, U b) {
    const auto result = std::uint64_t(a) + b;
    require(result <= 0xffffffffull, "B341 address arithmetic does not wrap");
    return static_cast<U>(result);
}

// Bounded translation of the two reached 0x4090e0 paths. The receiver's
// mode bit bypasses the node-table bound path. With total=128, consumed=0,
// progress=0, and a count below 64, these passes never cross a segment or
// refill boundary. The exact resulting fields follow the original stores.
U cursor_pass(Memory& m, U receiver, U amount) {
    const U total = m.r32(receiver + 0x34);
    const U consumed = m.r32(receiver + 0x38);
    const U progress = m.r32(receiver + 0x2c);
    require(total == 128 && consumed == 0 && progress <= 64,
            "B341 selected receiver extent/progress state");
    U left = total - consumed - progress;
    require(left != 0, "B341 receiver has cached capacity");
    const U bounded = amount < left ? amount : left;
    require((m.r8(receiver + 0x10) & 1u) != 0,
            "B341 selected mode skips node-bound lookup");
    require(bounded < left, "B341 excludes exact segment exhaustion");
    m.w32(receiver + 8, left);

    U copied = 0;
    if (bounded != 0) {
        m.w32(receiver + 4, checked_add(m.r32(receiver + 4), bounded));
        left -= bounded;
        m.w32(receiver + 8, left);
        copied = bounded;
    }

    // The original loop stores the accumulated count in +2c and advances
    // the ring cursor at +30. Its only division is skipped in this domain.
    const U new_progress = checked_add(progress, copied);
    const U new_cursor = checked_add(m.r32(receiver + 0x30), copied);
    const U cycle = m.r32(m.r32(receiver) + 0x14);
    require(cycle == 1000 && new_cursor < cycle,
            "B341 ring cursor stays below controller cycle");
    m.w32(receiver + 0x2c, new_progress);
    m.w32(receiver + 0x30, new_cursor);
    require(copied == amount, "B341 cursor pass consumed the requested bytes");
    return copied;
}

U cached_fread(Memory& m, U destination, U count, U file, Locks& locks) {
    require(file < 0x00816fd0u || file > 0x00817230u,
            "B341 FILE takes the original imported critical-section path");
    require(m.r16(file + 0x0c) == 8,
            "B341 FILE cache flag is the observed bit 0x8");
    require(m.r32(file + 0x18) == 128,
            "B341 FILE buffer length is 128 bytes");
    const U available = m.r32(file + 4);
    const U source = m.r32(file);
    require(count != 0 && count < available && available == 128 && source != 0,
            "B341 fread is a positive, complete cache hit");
    const U lock_address = checked_add(file, 0x20);
    locks.enter(lock_address);
    // This is the reached 0x76e02b branch: FILE flag 0x8 passes TEST 0x10c and count is
    // smaller than FILE._cnt, so it calls the original 0x7745e0 memmove path,
    // updates _ptr and _cnt, and does not reach the OS read branch.
    for (U n = 0; n < count; ++n)
        m.w8(destination + n, m.r8(source + n));
    m.w32(file, checked_add(source, count));
    m.w32(file + 4, available - count);
    locks.leave(lock_address);
    return count; // size=1, so the original fread return is element count.
}
} // namespace

std::uint32_t fun_00408f50(Memory& m, const Inputs& i, Locks& locks) {
    const U receiver = i.cx, file = i.dx;
    U remaining = i.arg[0];
    const U out_pointer = i.arg[1];
    require(receiver && file && out_pointer && remaining >= 1 && remaining <= 64,
            "B341 finite count and nonnull pointers");
    require(m.r32(receiver) != 0 && m.r32(m.r32(receiver) + 0x14) == 1000,
            "B341 receiver controller contract");
    require(m.r32(receiver + 0x14) == 0 && m.r32(receiver + 0x18) == 1 &&
            m.r32(receiver + 0x2c) == 0 && m.r32(receiver + 0x30) == 5 &&
            m.r32(receiver + 0x34) == 128 && m.r32(receiver + 0x38) == 0,
            "B341 receiver starts on the finite cache route");
    require(m.r32(receiver + 0x0c) != 0,
            "B341 receiver carries a valid nonnull node pointer");

    m.w32(out_pointer, 0);
    (void)cursor_pass(m, receiver, 0); // Original 0x4090e0, EDX=0.
    U request = m.r32(receiver + 8);
    if (request > remaining) request = remaining;
    require(request == remaining, "B341 caller count fits receiver cached capacity");

    const U read = cached_fread(m, m.r32(receiver + 4), request, file, locks);
    require(read == request, "B341 cached fread returns the full requested count");
    (void)cursor_pass(m, receiver, read); // Original 0x4090e0, EDX=fread result.
    remaining -= read;
    require(remaining == 0, "B341 selected route completes in one fread call");
    m.w32(out_pointer, i.arg[0] - remaining);
    return 1; // Original success branch 0x409001; RET 8.
}
} // namespace ra2::recovered::recovery_b341
