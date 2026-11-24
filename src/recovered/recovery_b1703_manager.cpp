#include "recovered/recovery_b1703.hpp"
#include <stdexcept>
#include <type_traits>

// Canonical B843 has no public declaration header. Link the existing TU;
// this declaration does not copy its removal/destructor/real-heap logic.
namespace ra2::recovered::recovery_b843 {
std::uint32_t fun_005243c0(global_b26::Memory&,
                         const global_b26::Inputs&,
                         platform::ordinary_heap::Heap&);
}

namespace ra2::recovered::recovery_b1703::calls {
static_assert(std::is_same_v<Memory, global_b26::Memory>,
              "B843 must use the same actual guest Memory spans");

void manager_5243c0(Memory& m, State& s, Frame& caller,
                     U continuation, U actual_target, Heap& heap) {
    if (actual_target != 0x5243c0u)
        throw std::domain_error("1B6760 manager requires actual 5243C0");

    // The Root already pushed its actual index argument. Model the real CALL.
    caller.push(m, continuation);
    Frame f{caller.sp, caller.sp, continuation};

    // 5243C0..C2: actual incoming values, not a predicted House pointer.
    // At the selected Root call T1=R-13C, the first write is R-140.
    // That word survives RET4 and is read naturally by the later E73D0 call.
    f.push(m, s.bx);
    f.push(m, s.si);
    f.push(m, s.di);

    // These are exactly the two inputs read by the canonical implementation.
    // Other Inputs storage is unused host metadata, never written to guest
    // caller/private memory and never substituted for any guest byte.
    global_b26::Inputs consumed{};
    consumed.cx = s.cx;
    consumed.arg[0] = m.r32(f.entry_sp + 4u);
    // Run the genuine provider under the live guest image, preserving the
    // actual host image separately. Capture actual post-call state, including
    // any real SDK changes; never reinstall an input/expected guest image.
    ra2::platform::x87::Image host;
    asm volatile("fnsave %[host]\n\tfrstor %[guest]"
        : [host] "=m" (host.bytes)
        : [guest] "m" (s.fp.image.bytes)
        : "memory", "st", "st(1)", "st(2)", "st(3)", "st(4)",
          "st(5)", "st(6)", "st(7)");
    try {
        s.ax = recovery_b843::fun_005243c0(m, consumed, heap);
    } catch (...) {
        // Failure evidence remains actual; restore host even on the excluded
        // exceptional path. No allocation, logging or new diagnostics here.
        asm volatile("fnsave %[guest]\n\tfrstor %[host]"
            : [guest] "=m" (s.fp.image.bytes)
            : [host] "m" (host.bytes)
            : "memory", "st", "st(1)", "st(2)", "st(3)", "st(4)",
              "st(5)", "st(6)", "st(7)");
        throw;
    }
    asm volatile("fnsave %[guest]\n\tfrstor %[host]"
        : [guest] "=m" (s.fp.image.bytes)
        : [host] "m" (host.bytes)
        : "memory", "st", "st(1)", "st(2)", "st(3)", "st(4)",
          "st(5)", "st(6)", "st(7)");

    // B843 does not expose its internal CX/DX/arithmetic flags or transitive
    // destructor/API private stack. Those volatile results are dead in this
    // selected Root before later E73D0/final instructions produce the observed
    // outputs. Leaving their State fields untouched is NOT a preservation or
    // full-child-machine-state claim. No private value is invented for them.
    // The guest FP image above is the actual provider poststate. TEB/LastError
    // are not restored or normalized. Whole-Root/provider observations still
    // require independent physical evidence; child volatile fields stay dead.
    s.di = f.pop(m);
    s.si = f.pop(m);
    s.bx = f.pop(m);
    recovery_b566::finish(m, s, f, 4u); // Actual RET4: return word + one argument.
    caller.sp = f.sp;
}
} // namespace ra2::recovered::recovery_b1703::calls
