#include "recovered/recovery_b1702.hpp"
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b1702::calls {
namespace {
void require_ftol(bool condition, const char* message) {
    if (!condition) throw std::domain_error(message);
}
}

// Exact selected body at VA 0x0076AA50 / RVA 0x0036AA50.
// Input: one live x87 ST(0), actual private caller frame, no explicit args.
// Output: EDX:EAX = the actual signed FISTP qword; ST(0) is popped.
void ftol_76aa50(Memory& m, State& s, Frame& caller,
                 U continuation, U actual_target) {
    require_ftol(actual_target == 0x0076aa50u,
                 "FD5F0 FTOL actual target mismatch");

    // CALL pushes its real continuation at the caller's current ESP.
    const U pre_call_sp = caller.sp;
    caller.push(m, continuation);
    const U callee_entry_sp = caller.sp;
    const U local_sp = callee_entry_sp - 0x0cu;

    // 76AA50: FNSTCW word [ESP]; MOV EDX,[ESP]; AND EDX,FFFFh;
    // CMP EDX,dword [7C3A04h].  Preserve the untouched high half of
    // this scratch DWORD because the original AND discards it.
    m.w16(local_sp, s.fp.control());
    const U observed_cw = m.r32(local_sp) & 0xffffu;
    const U cw_global_for_compare = m.r32(0x007c3a04u);

    // On mismatch the body reads the global DWORD again, stores that entire
    // DWORD to [ESP], then FLDCW loads its low WORD.  No status or CW is
    // forced when the exact comparison says they already match.
    if (observed_cw != cw_global_for_compare) {
        const U cw_global_for_load = m.r32(0x007c3a04u);
        m.w32(local_sp, cw_global_for_load);
        s.fp.load_control(static_cast<std::uint16_t>(m.r16(local_sp)));
    }

    // FISTP qword [ESP+4] writes the real rounded/truncated result and pops
    // exactly one x87 value.  The existing x87 backend preserves host state
    // and updates the guest image without normalizing its bytes.
    const std::uint64_t result = s.fp.pop_integer64();
    m.w32(local_sp + 4u, static_cast<U>(result));
    m.w32(local_sp + 8u, static_cast<U>(result >> 32u));

    // MOV EDX,[EAX+4]; MOV EAX,[EAX]; ADD ESP,0Ch; RET.
    s.dx = m.r32(local_sp + 8u);
    s.ax = m.r32(local_sp + 4u);
    const U returned_esp = recovery_b566::integer::add(
        local_sp, 0x0cu, 32u, s.arithmetic_flags);
    require_ftol(returned_esp == callee_entry_sp,
                 "FD5F0 FTOL local stack arithmetic mismatch");
    caller.sp = returned_esp;
    require_ftol(caller.pop(m) == continuation,
                 "FD5F0 FTOL RET continuation mismatch");
    require_ftol(caller.sp == pre_call_sp,
                 "FD5F0 FTOL caller ESP was not restored");
}
} // namespace ra2::recovered::recovery_b1702::calls
