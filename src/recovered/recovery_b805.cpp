#include "recovery_b805.hpp"

#include "recovered/recovery_b121.hpp"
#include "recovered/leaf_memory.hpp"

#include <array>
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b805 {
namespace {
constexpr std::uint32_t kDelimiter = 0x007d06dcu;
constexpr std::uint32_t kLocalStack = 0x7ff00000u;
constexpr std::uint32_t kBuffer = kLocalStack + 0x0cu;
constexpr std::uint32_t kWideHolder = kLocalStack + 0x08u;
constexpr std::uint32_t kConvertedHolder = kLocalStack + 0x30u;
constexpr std::array<std::uint32_t, 6> kKeys{
    0x007d11c8u, 0x007d11ccu, 0x007d11d0u,
    0x007d11d4u, 0x007d11d8u, 0x007d11dcu};
constexpr std::array<std::uint32_t, 6> kValues{
    0x00a5a89cu, 0x00a5a8a0u, 0x00a5a8b0u,
    0x00a5a8a4u, 0x00a5a8a8u, 0x00a5a8acu};

void need(bool ok, const char* why) {
    if (!ok) throw std::domain_error(why);
}

std::uint32_t memory_wide_length(const Memory& m, std::uint32_t p,
                                 std::uint32_t limit) {
    need(p != 0u, "B805 requires a nonnull UTF-16 pointer");
    for (std::uint32_t n = 0; n < limit; ++n)
        if (m.r16(p + 2u*n) == 0u) return n;
    throw std::domain_error("B805 bounded UTF-16 terminator not found");
}

std::uint32_t heap_wide_length(const Heap& h, std::uint32_t p,
                               std::uint32_t limit) {
    need(p != 0u, "B805 requires a nonnull heap UTF-16 pointer");
    for (std::uint32_t n = 0; n < limit; ++n)
        if (h.r8(p + 2u*n) == 0u && h.r8(p + 2u*n + 1u) == 0u) return n;
    throw std::domain_error("B805 bounded heap UTF-16 terminator not found");
}

void wide_copy(Memory& m, std::uint32_t dst, std::uint32_t src,
               std::uint32_t limit) {
    for (std::uint32_t n = 0; n < limit; ++n) {
        const auto ch = m.r16(src + 2u*n);
        m.w16(dst + 2u*n, ch);
        if (ch == 0u) return;
    }
    throw std::domain_error("B805 input copy exceeded its 0x158-byte root buffer");
}

bool equal_original_byte_strings(const Heap& h, const Memory& m,
                                 std::uint32_t left, std::uint32_t right) {
    // Exact two-byte-at-a-time comparison performed by 0x359340.
    for (std::uint32_t n = 0; n < 256u; n += 2u) {
        const auto a0 = h.r8(left + n), b0 = m.r8(right + n);
        if (a0 != b0) return false;
        if (a0 == 0u) return true;
        const auto a1 = h.r8(left + n + 1u), b1 = m.r8(right + n + 1u);
        if (a1 != b1) return false;
        if (a1 == 0u) return true;
    }
    throw std::domain_error("B805 byte-string compare exceeded bound");
}

std::uint32_t match_closed_short_token(Memory& m, std::uint32_t wide_holder,
                                       Heap& h) {
    const auto wide = m.r32(wide_holder);
    const auto units = heap_wide_length(h, wide, 172u);
    need(units == 8u, "B805 selected route requires one 8-unit ASCII token");
    for (std::uint32_t n = 0; n < units; ++n)
        need(h.r8(wide + 2u*n) < 0x80u && h.r8(wide + 2u*n + 1u) == 0u,
             "B805 selected route requires ASCII UTF-16 code units");

    // Exact success path of 0x35cbc0, extended only by allowing the short
    // 8-byte input. The three calls to 0x76d957 request length+1 bytes.
    const auto converted = h.allocate(units + 1u); // 0x76d957
    need(converted != 0u, "B805 conversion allocation failed");
    for (std::uint32_t n = 0; n < units; ++n)
        h.w8(converted + n, h.r8(wide + 2u*n)); // 0x6eed90 low-byte conversion
    h.w8(converted + units, 0u);

    const auto bytes = units + 1u;
    const auto joined = h.allocate(bytes); // scan including NUL, then 0x76d957
    need(joined != 0u && joined != converted, "B805 joined allocation failed");
    h.w8(joined, 0u); // 0x75cc28
    for (std::uint32_t n = 0; n < bytes; ++n)
        h.w8(joined + n, h.r8(converted + n));
    need(h.release(converted) != 0u, "B805 converted-string free failed");

    m.w32(kConvertedHolder, 0u); // 0x75cc59
    const auto published = h.allocate(bytes);
    need(published != 0u && published != joined, "B805 publish allocation failed");
    m.w32(kConvertedHolder, published); // 0x75cc7e
    for (std::uint32_t n = 0; n < bytes; ++n)
        h.w8(published + n, h.r8(joined + n));
    need(h.release(joined) != 0u, "B805 joined-string free failed");

    std::uint32_t result = 0u;
    for (std::uint32_t n = 0; n < kKeys.size(); ++n) {
        const auto key = m.r32(kKeys[n]);
        if (equal_original_byte_strings(h, m, published, key)) {
            result = m.r32(kValues[n]);
            break;
        }
    }
    need(result != 0u && m.r32(kKeys[1]) != 0u &&
         equal_original_byte_strings(h, m, published, m.r32(kKeys[1])),
         "B805 route must hit the original @Closed@ table row");
    need(h.release(published) != 0u, "B805 matched published-string free failed");
    m.w32(kConvertedHolder, 0u); // 0x359320
    return result;
}
}

std::uint32_t run(Memory& original, const Inputs& i, Heap& h) {
    need(i.cx != 0u && original.r16(i.cx) != 0u,
         "B805 route requires a nonempty UTF-16 input at ECX");
    need(original.r32(0x00a255c8u) != 4u,
         "B805 route uses mode other than four (root selects eight entries)");
    need(original.r32(0x00817554u) == 0u,
         "B805 route requires initialized ordinary-heap threshold zero");

    Memory m = original;
    std::array<std::uint8_t, 0x180> local_bytes{};
    ra2::recovered::leaf::Memory stack_span(local_bytes.data(), kLocalStack,
                                             static_cast<std::uint32_t>(local_bytes.size()));
    m.add(stack_span);

    const auto input_units = memory_wide_length(m, i.cx, 172u);
    need(input_units == 8u, "B805 route requires exactly one @Closed@ token");
    wide_copy(m, kBuffer, i.cx, 172u); // original 0x76efc9
    constexpr std::uint32_t output = 0x00a27dc4u;
    const auto default_value = m.r32(0x00a5a89cu);
    for (std::uint32_t n = 0; n < 8u; ++n) m.w32(output + 4u*n, default_value);

    recovery_b121::Inputs next{};
    next.arg[0] = kBuffer;
    next.arg[1] = kDelimiter;
    const auto token = recovery_b121::fun_00770411(m, next);
    need(token == kBuffer, "B805 first real TLS tokenizer call did not return token start");

    const auto clone_bytes = (input_units + 1u) * 2u;
    const auto wide_clone = h.allocate(clone_bytes); // exact 0x75b300 request: 18
    need(wide_clone != 0u, "B805 0x75b300 allocation failed");
    for (std::uint32_t n = 0; n <= input_units; ++n) {
        const auto ch = m.r16(token + 2u*n);
        h.w8(wide_clone + 2u*n, ch);
        h.w8(wide_clone + 2u*n + 1u, ch >> 8u);
    }
    m.w32(kWideHolder, wide_clone);

    const auto selected = match_closed_short_token(m, kWideHolder, h);
    need(selected == m.r32(0x00a5a8a0u), "B805 @Closed@ row selected wrong output global");
    need(h.release(m.r32(kWideHolder)) != 0u, "B805 0x75b390 wide-clone free failed");
    m.w32(kWideHolder, 0u);
    m.w32(output, selected);

    next.arg[0] = 0u; // exact second root tokenizer call follows TLS cursor
    const auto end = recovery_b121::fun_00770411(m, next);
    need(end == 0u, "B805 bounded fixture unexpectedly contains another token");
    return 0u; // root's final EAX is the second tokenizer's zero; RET 0
}
}
