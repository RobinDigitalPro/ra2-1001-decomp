#include "recovered/recovery_b206.hpp"
#include "platform/locale206_win32.hpp"
#include "platform/small_crt_heap_win32.hpp"

#define NOMINMAX
#include <windows.h>
#include <cstdint>
#include <cstring>
#include <stdexcept>

namespace ra2::recovered::recovery_b206 {
using Memory = ra2::recovered::global_b26::Memory;
using Inputs = ra2::recovered::global_b26::Inputs;
using Heap = ra2::platform::small_crt_heap::Heap;

namespace {
// Exact positive W-path used by original RVA 0x38112e for the restricted
// locale inputs. Windows APIs are called directly; no fixture supplies their
// return values. A local wide buffer stands in for that helper's x86 alloca.
std::uint32_t locale_to_ansi(Memory& m, std::uint32_t lcid, std::uint32_t lctype,
                             std::uint32_t code_page, char* output,
                             std::uint32_t output_bytes) {
    const auto cache = m.r32(0x00b10828u);
    if (cache == 0u) {
        if (ra2::platform::locale206::locale_info(0u, LOCALE_ILANGUAGE, nullptr, 0) == 0)
            return 0u; // The finite contract requires the original W probe to succeed.
        m.w32(0x00b10828u, 1u);
    } else if (cache != 1u) {
        return 0u; // The finite contract excludes cached A/failure paths.
    }

    const auto cp = code_page == 0u
        ? m.r32(0x00b10540u)
        : code_page;
    const int count = ra2::platform::locale206::locale_info(lcid, lctype, nullptr, 0);
    if (count <= 0 || count > 128) return 0u;
    wchar_t wide[128]{};
    if (ra2::platform::locale206::locale_info(lcid, lctype, wide, count) == 0) return 0u;
    // These are the original 0x220 flags and -1 source count. The selected
    // LOCALE_ILANGUAGE strings are invariant ASCII for this code page route.
    return static_cast<std::uint32_t>(ra2::platform::locale206::to_bytes(
        cp, 0x220u, wide, -1, output, static_cast<int>(output_bytes),
        nullptr, nullptr));
}
} // namespace

// Bounded original RVA 0x3802d0: mode 1, positive 128-byte stack buffer,
// then one five-byte game-heap allocation and copy from the local buffer.
std::uint32_t fun_007802d0(Memory& m, const Inputs& i, Heap& heap) {
    if (i.arg[0] != 1u || i.arg[1] != 0x0409u ||
        i.arg[2] != LOCALE_ILANGUAGE || i.arg[3] == 0u)
        throw std::domain_error("recovery_b206 finite locale-info route only");

    char stack_output[128]{};
    i.arg[0] = 0u; // Original 0x7802f8 temporarily overwrites caller arg0.
    const auto written = locale_to_ansi(m, i.arg[1], i.arg[2], 0u,
                                          stack_output, 128u);
    if (written != 5u)
        throw std::domain_error("Windows LOCALE_ILANGUAGE did not produce a four-digit ID and NUL");

    // This successful first pass follows 0x780359 directly. The two-pass
    // ERROR_INSUFFICIENT_BUFFER branch is not reached for the 5-byte value.
    const auto published = heap.allocate(written);
    m.w32(i.arg[3], published); // Original publishes before its byte copy.
    std::memcpy(reinterpret_cast<void*>(static_cast<std::uintptr_t>(published)),
                stack_output,
                written);
    // Original wrote caller arg0=0 at VA 0x7802f8 and leaves it zero on this
    // success path; the restore at 0x78033e belongs only to the retry path.
    return 0u; // original 0x780401 XOR EAX,EAX; RET (cleanup 0)
}
} // namespace ra2::recovered::recovery_b206
