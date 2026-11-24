#include "recovered/recovery_b153.hpp"
#include "platform/observed_locale153.hpp"

#include <array>
#include <stdexcept>

namespace ra2::recovered::recovery_b153 {
namespace {
constexpr std::uint32_t kKey = 0x007bc504u;
constexpr std::uint32_t kFormat = 0x007bc530u;
constexpr std::uint32_t kTable = 0x00ab7ec0u;
constexpr std::uint32_t kCount = 0x00ab7eb8u;
constexpr std::uint32_t kValues = 0x00ab7ec4u;
constexpr std::uint32_t kCompareMode = 0x00b10530u;
constexpr std::uint32_t kRowSize = 0x28u;

void require(bool okay, const char* message) {
    if (!okay) throw std::domain_error(message);
}
std::uint8_t fold_ascii(std::uint8_t c) {
    return c >= 'A' && c <= 'Z' ? static_cast<std::uint8_t>(c + ('a' - 'A')) : c;
}
int compare_ascii_bounded(Memory& m, std::uint32_t a, std::uint32_t b) {
    // The original comparator continues through NUL; the finite source
    // contract bounds both supplied table keys to at most 31 bytes.
    for (unsigned n = 0; n < 32; ++n) {
        const auto x = static_cast<std::uint8_t>(m.r8(a + n));
        const auto y = static_cast<std::uint8_t>(m.r8(b + n));
        if (x == y) {
            if (!x) return 0;
            continue;
        }
        const auto lx = fold_ascii(x), ly = fold_ascii(y);
        if (lx != ly) return lx < ly ? -1 : 1;
        if (!lx) return 0;
    }
    throw std::domain_error("153 table key exceeds its bounded NUL-terminated domain");
}

std::uint32_t lookup_format(Memory& m) {
    require(m.r32(kCompareMode) == 0, "153 requires Block145's original mode-zero comparator state");
    const auto count = m.r32(kCount);
    const auto table = m.r32(kTable);
    const auto values = m.r32(kValues);
    require(count == 2u && table != 0 && values != 0,
            "153 requires the supplied two-row text-table geometry");
    // The bounded sorted table has the exact original key in row zero and a
    // lexically later row one. Checking both rows preserves the binary-search
    // precondition without inventing a lookup callback or table result.
    require(compare_ascii_bounded(m, table, kKey) == 0,
            "153 table row zero must match the original key");
    require(compare_ascii_bounded(m, table + kRowSize, kKey) > 0,
            "153 table row one must sort after the original key");
    const auto index = m.r32(table + 0x24u);
    require(index == 0u && m.r32(table + kRowSize + 0x24u) == 1u,
            "153 two-row table indices must be 0 then 1");
    const auto format = m.r32(values + 4u * index);
    require(format == kFormat, "153 positive route uses the original UTF-16 L%d literal");
    require(m.r16(format) == '%' && m.r16(format + 2u) == 'd' && m.r16(format + 4u) == 0,
            "153 original format literal must remain UTF-16 L%d");
    return format;
}

std::uint32_t write_decimal(Memory& m, std::uint32_t destination, std::uint32_t value) {
    // Original 375d7e is a wide-output formatter. 37dc05 widens each emitted
    // digit through the original C-locale classifier before 376b88 stores AX.
    require(value <= 99u, "153 hour field must be in [0,99]");
    std::array<std::uint16_t, 2> digits{};
    std::uint32_t length = 0;
    if (value >= 10u) digits[length++] = static_cast<std::uint16_t>('0' + value / 10u);
    digits[length++] = static_cast<std::uint16_t>('0' + value % 10u);
    for (std::uint32_t n = 0; n < length; ++n) {
        // Actual37dc05 surrounds C-locale byte-to-WORD conversion with the
        // real atomic exports; 376b88 writes the resulting WORD afterward.
        ra2::platform::locale153::Counter::enter();
        const auto wide=std::uint16_t(std::uint8_t(digits[n]));
        ra2::platform::locale153::Counter::leave();
        m.w16(destination + 2u * n, wide);
    }
    // 36f0a4 writes the low and high bytes of the wide NUL at the formatter
    // cursor. The next byte pair is outside its output and stays untouched.
    m.w16(destination + 2u * length, 0);
    return length;
}
}

std::uint32_t fun_00465850(Memory& m, const Inputs& i) {
    require(i.cx != 0, "153 positive route requires nonnull destination");
    require(i.dx <= 0x7fffffffu, "153 positive route requires nonnegative signed-int input");
    require(m.r32(0x00b10e20u) == 0u,
            "153 requires the original C-locale conversion branch");
    require(m.r32(0x0081776cu) == 1u,
            "153 requires the original one-byte conversion count");
    const auto atomic_counter = m.r32(0x00b10e24u);

    // Exact mathematical result of the original 0x91a2b3c5 signed magic
    // division sequence on the bounded nonnegative input.
    std::uint32_t ticks = i.dx;
    if (ticks / 3600u > 99u) ticks = 0x57e3fu; // original clamp: 359999
    const auto hours = ticks / 3600u;
    const auto remainder = ticks - hours * 3600u;
    const auto minutes = remainder / 60u;
    const auto seconds = remainder - minutes * 60u;
    (void)minutes;
    (void)seconds; // they remain actual formatter varargs; L"%d" consumes only hours

    (void)lookup_format(m); // validates the real key-hit state and original format pointer
    const auto emitted = write_decimal(m, i.cx, hours);
    // In mode zero, 37dc05 calls the genuine InterlockedIncrement and
    // InterlockedDecrement IATs around every widened digit; their net effect
    // on B10E24 is zero. The nonzero-mode lock-table path is excluded.
    require(m.r32(0x00b10e24u) == atomic_counter,
            "153 serialized Interlocked pairs restore the CRT conversion counter");
    return emitted;
}
}
