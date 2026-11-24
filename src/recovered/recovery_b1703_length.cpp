#include "recovered/recovery_b1703.hpp"

#include <stdexcept>

namespace ra2::recovered::recovery_b1703::calls {
namespace ix = direct_b33::integer;

void length_76ef45(Memory& m, State& s, Frame& caller, U continuation, U actual_target) {
    if (actual_target != 0x0076ef45u)
        throw std::domain_error("1b6760 length target outside selected domain");

    // CALL pushes the actual continuation below the caller's one UTF-16 pointer
    // argument. The original helper returns with plain RET; the caller cleans
    // its argument after observing EAX.
    caller.push(m, continuation);
    Frame f{caller.sp, caller.sp, continuation};

    // 0076ef45 8b4c2404: MOV ECX,[ESP+4]
    s.cx = m.r32(f.sp + 4u);

    // 0076ef49 66833900: CMP word ptr [ECX],0
    (void)ix::sub(m.r16(s.cx), 0u, 16u, s.arithmetic_flags);

    // 0076ef4d 8d4102: LEA EAX,[ECX+2]; LEA does not change flags.
    s.ax = s.cx + 2u;

    // 0076ef50 740a: JZ empty
    if (!ix::condition("JZ", s.arithmetic_flags)) {
        for (;;) {
            // 0076ef52 668b10: MOV DX,word ptr [EAX]; writing DX preserves EDX[31:16].
            s.dx = (s.dx & 0xffff0000u) | (m.r16(s.ax) & 0xffffu);

            // 0076ef55/56: two separate INC EAX instructions, each updating flags.
            s.ax = ix::increment(s.ax, 32u, s.arithmetic_flags);
            s.ax = ix::increment(s.ax, 32u, s.arithmetic_flags);

            // 0076ef57 6685d2: TEST DX,DX; JNZ loops to the next UTF-16 word.
            (void)ix::logical(s.dx & 0xffffu, 16u, s.arithmetic_flags);
            if (!ix::condition("JNZ", s.arithmetic_flags))
                break;
        }
    }

    // Common exit (including the empty-string branch): SUB EAX,ECX;
    // SAR EAX,1; DEC EAX. This returns the number of 16-bit code units
    // preceding the terminating word. The memory input must be a valid
    // NUL-terminated UTF-16 span; the original routine has no explicit bound.
    s.ax = ix::sub(s.ax, s.cx, 32u, s.arithmetic_flags);
    s.ax = ix::shift(s.ax, 1u, 32u, s.arithmetic_flags, ix::Shift::arithmetic_right);
    s.ax = ix::decrement(s.ax, 32u, s.arithmetic_flags);

    // 0076ef61 C3: RET (no stack cleanup).
    recovery_b566::finish(m, s, f, 0u);
    caller.sp = f.sp;
}

} // namespace ra2::recovered::recovery_b1703::calls
