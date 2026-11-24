#include "recovery_b357.hpp"
#include <stdexcept>

namespace ra2::recovered::recovery_b357 {
namespace {
void need(bool ok, const char* message) {
    if (!ok) throw std::domain_error(message);
}
}

std::uint32_t fun_004983a0(Memory& m, const Inputs& in, Heap& heap,
                           const Context& context) {
    // 0x4983a7 loads EDI from entry [ESP+4] (arg0). Restrict to the branch
    // whose accepted 0x4981c0 predicate returns EAX=0, equal to EDI.
    need(in.arg[0] == 0u, "357 exact EDI=0 selection case required");
    need(m.r32(0x00b11ee0u) != 0u,
         "357 selection-reset route needs a visibly nonzero current value");
    need(m.r32(0x007c0d84u) == 0u,
         "357 zero selector must skip the later indirect call");
    need(m.r32(0x00838be0u) == 0u,
         "357 cleanup list must be empty; populated node ownership is excluded");
    need(m.r8(0x007bd77cu) == ';' && m.r8(0x007bd77du) == 0u,
         "357 pinned delimiter literal must remain semicolon-NUL");
    need(m.r8(0x00838becu) == 0u,
         "357 cached string must be the exact empty string");
    need(context.ptd != 0u,
         "357 actual initialized CRT thread-data block is required");

    // Exact selected positive route: accepted 0x4981c0's EAX=0 lets the root
    // publish zero into B11EE0 before calling 0x46fce0 and 0x46fa20.
    m.w32(0x00b11ee0u, 0u);

    // 0x46fce0: ECX is the current cached selection B838BE4. The target stores
    // it back and copies the prior value to B838BE8 (the saved selection).
    const auto cached = m.r32(0x00838be4u);
    m.w32(0x00838be4u, cached);
    m.w32(0x00838be8u, cached);

    // 0x46fa20 with a null list writes null back, then tail-jumps to
    // 0x46fa70(0x838bec). On the empty string, 0x779146/0x775160 duplicates
    // one NUL byte via the real request-1 CRT path; 0x76e802 finds no token;
    // 0x76df28 frees the duplicate. Delimiter literal at 0x7bd77c is ';'.
    const auto duplicate = heap.allocate(1u);
    need(duplicate != 0u, "357 successful one-byte CRT allocation required");
    heap.write8(duplicate, 0u); // 0x779010 copies the source NUL byte
    m.w8(0x00838becu, ';'); // 0x46fac8 appends the pinned delimiter first.
    m.w8(0x00838bedu, 0u);
    // 0x46faf0 appends the duplicate empty string at index 1. It does not
    // overwrite the delimiter at index 0 or the higher bytes.
    // 0x76e896 stores the final scan cursor through the actual PTD returned
    // by the native GetPTD/TlsGetValue path. It remains a stale owner pointer
    // after the following free; the native proof checks its raw allocation
    // identity before freeing and compares the post-free value by ordinal.
    m.w32(context.ptd + 0x18u, duplicate);
    heap.release(duplicate);

    // 0x4984af sees B7C0D84 == EDI and skips vtable+8. Helper 0x46fa70's
    // XOR/SETZ sequence at 0x46fc75..0x46fc7d establishes full EAX=1.
    return 1u;
}
}
