#include "recovery_b223.hpp"

#include <cstdint>
#include <stdexcept>
#include <string>

namespace ra2::recovered::recovery_b223 {
namespace {
[[noreturn]] void unsupported(const char* why) { throw std::domain_error(why); }
void require(bool ok, const char* why) { if (!ok) unsupported(why); }

std::string read_memory_z(const Memory& m, std::uint32_t p) {
    require(p != 0, "1AE0A0 requires the original non-null source holder/pointer");
    std::string s;
    for (unsigned n = 0; n < 32; ++n) {
        const auto c = static_cast<char>(m.r8(p + n));
        if (c == '\0') return s;
        s.push_back(c);
    }
    unsupported("1AE0A0 source exceeds the finite string bound");
}

std::string read_heap_z(const Heap& h, std::uint32_t p) {
    require(p != 0, "1AE0A0 local string pointer is null on the selected positive route");
    std::string s;
    for (unsigned n = 0; n < 32; ++n) {
        const auto c = static_cast<char>(h.r8(p + n));
        if (c == '\0') return s;
        s.push_back(c);
    }
    unsupported("1AE0A0 heap string exceeds the finite bound");
}

std::uint32_t alloc(Heap& h, std::uint32_t request) {
    const auto p = h.allocate(request);
    require(p != 0, "1AE0A0 selected route requires successful real CRT allocation");
    return p;
}
void write_z(Heap& h, std::uint32_t p, const std::string& s) {
    for (std::uint32_t k = 0; k < s.size(); ++k)
        h.w8(p + k, static_cast<std::uint8_t>(s[k]));
    h.w8(p + static_cast<std::uint32_t>(s.size()), 0);
}

// Bounded execution of original 0x36fa70's byte-in-delimiter-string search.
// The delimiter bytes are read from the pinned guest VA on every query.
bool delimiter_contains(const Memory& m, std::uint32_t set, std::uint8_t byte) {
    require(set != 0, "1AE0A0 delimiter string is null");
    for (unsigned k = 0; k < 16; ++k) {
        const auto d = static_cast<std::uint8_t>(m.r8(set + k));
        if (!d) return false;
        if (d == byte) return true;
    }
    unsupported("1AE0A0 delimiter set lacks a terminator in its bounded span");
}

// Instruction-order translation of the productive 0x35ab40 route. It first
// skips delimiter bytes, scans to the next delimiter, copies the complete
// remaining suffix, extracts the token through scratch, then replaces the
// local token string. Every allocation/free crosses the real Heap boundary.
std::uint32_t next_token(Memory& m, Heap& h, const std::string& source,
                         std::uint32_t start, std::uint32_t delimiters,
                         std::uint32_t& token_pointer) {
    std::uint32_t p = start;
    while (p < source.size() && delimiter_contains(
               m, delimiters, static_cast<std::uint8_t>(source[p]))) ++p;
    require(p < source.size(), "1AE0A0 selected route requires a nonempty token");
    const auto token_start = p;
    while (p < source.size() && !delimiter_contains(
               m, delimiters, static_cast<std::uint8_t>(source[p]))) ++p;
    require(p < source.size(), "1AE0A0 selected tokens must end at a delimiter");
    const auto token_end = p; // Original helper returns the delimiter index.
    const auto token_length = token_end - token_start;
    require(token_length == 1u,
            "1AE0A0 full-tuple recipe has four one-byte tokens");

    // 0x75abf3..0x75abff: free old output token before allocating the suffix.
    if (token_pointer) h.release(token_pointer);
    token_pointer = 0;

    const auto suffix = source.substr(token_start);
    const auto suffix_ptr = alloc(h, static_cast<std::uint32_t>(suffix.size() + 1u));
    h.w8(suffix_ptr,0);
    write_z(h, suffix_ptr, suffix); // 0x75ac02..0x75ac4d

    // 0x75ac55..0x75ac86: scratch request is token_length+1; the original
    // copies only the token bytes and places NUL at that exact boundary.
    const auto scratch = alloc(h, token_length + 1u);
    h.w8(scratch,0);
    for (std::uint32_t k = 0; k < token_length; ++k)
        h.w8(scratch + k, static_cast<std::uint8_t>(suffix[k]));
    h.w8(scratch + token_length, 0);

    // 0x75ac95..0x75aca1 frees the full suffix, then 0x75aca4..0x75acef
    // publishes a distinct final token allocation copied from scratch.
    h.release(suffix_ptr);
    const auto final_token = alloc(h, token_length + 1u);
    const auto scratch_text = read_heap_z(h, scratch);
    h.w8(final_token,0);
    write_z(h, final_token, scratch_text);
    h.release(scratch);
    token_pointer = final_token;
    return token_end;
}

std::uint32_t length_from_slot(const Heap& h, std::uint32_t p) {
    return static_cast<std::uint32_t>(read_heap_z(h, p).size());
}

// The route uses the original single-byte C-locale classification table.
// This is the 0x36e6b2 loop specialized only by bounded input values, with
// real table reads matching 0x36e521(mask 8) and 0x36e4cc(mask 4).
std::uint32_t parse_decimal(Memory& m, const Heap& h, std::uint32_t p) {
    require(m.r32(0x0081776cu) == 1u,
            "1AE0A0 decimal route requires the original single-byte CRT mode");
    const auto table = m.r32(0x00817560u);
    require(table != 0 && table == 0x0081756au,
            "1AE0A0 decimal route requires the pinned initial CRT table");
    auto classify = [&](std::uint8_t c, std::uint16_t mask) {
        return (m.r8(table + 2u * c) & mask) != 0;
    };
    auto c = static_cast<std::uint8_t>(h.r8(p));
    while (classify(c, 0x0008u)) c = static_cast<std::uint8_t>(h.r8(++p));
    const auto sign = c;
    if (c == '+' || c == '-') c = static_cast<std::uint8_t>(h.r8(++p));
    std::uint32_t value = 0;
    unsigned digits = 0;
    while (classify(c, 0x0004u)) {
        value = value * 10u + static_cast<std::uint32_t>(c) - 0x30u;
        ++digits;
        c = static_cast<std::uint8_t>(h.r8(++p));
    }
    require(digits == 1u,
            "1AE0A0 finite numeric tokens are one actual CRT-classified digit");
    return sign == '-' ? 0u - value : value;
}

void assign_name(Memory& m, Heap& h, std::uint32_t receiver,
                 std::uint32_t token_pointer) {
    // 0x759570's selected compare-mismatch path. Receiver initially owns an
    // empty string; supported names are one uppercase letter, so the original
    // two strings mismatch at byte zero and take the replacement path.
    const auto old = m.r32(receiver);
    const auto source = token_pointer;
    require(old && source && h.r8(old) == 0,
            "1AE0A0 name copy requires the constructor-created empty string");
    const auto name = read_heap_z(h, source);
    require(name.size() == 1u && name[0] >= 'A' && name[0] <= 'Z',
            "1AE0A0 name is one bounded uppercase ASCII byte");
    if (old) h.release(old);              // 0x7595c4..0x7595d9
    m.w32(receiver, 0);                   // 0x7595dc
    const auto copy = alloc(h, static_cast<std::uint32_t>(name.size() + 1u));
    m.w32(receiver, copy);                // 0x759602
    h.w8(copy, 0);                        // 0x759607
    write_z(h, copy, name);               // 0x75960c..0x75962a
}
} // namespace

std::uint32_t fun_005ae0a0(Memory& m, const Inputs& i, Heap& h) {
    const auto receiver = i.cx;
    const auto holder = i.arg[0]; // Original root reads caller [S+4].
    require(receiver && holder, "1AE0A0 requires receiver and source-holder spans");
    const auto source = read_memory_z(m, m.r32(holder));
    require(source.size() == 8u && source[1] == ',' && source[3] == ',' &&
            source[5] == ',' && source[7] == ',',
            "1AE0A0 requires exactly four one-byte tokens with a trailing delimiter");
    require(source[0] >= 'A' && source[0] <= 'Z' &&
            source[2] >= '0' && source[2] <= '9' &&
            source[4] >= '0' && source[4] <= '9' &&
            source[6] >= '0' && source[6] <= '9',
            "1AE0A0 finite format is LETTER,DIGIT,DIGIT,DIGIT, with trailing delimiter");
    const auto delimiters = 0x007b9950u;
    require(m.r8(delimiters) == ',' && m.r8(delimiters + 1u) == 0,
            "1AE0A0 requires the exact pinned comma/NUL delimiter set");

    // 0x759260(receiver, 0): the original empty-string constructor.
    m.w32(receiver, 0);
    const auto empty = alloc(h, 1u);
    m.w32(receiver, empty);
    h.w8(empty, 0);

    // Root 0x5ae0b2..0x5ae0b8 initializes the three numeric fields; 0x759250
    // clears the local token pointer. The local pointer itself has no lifetime
    // beyond this call and is not a persistent guest-memory publication.
    m.w32(receiver + 4u, 0);
    m.w32(receiver + 8u, 0);
    m.w32(receiver + 0xcu, 0);
    std::uint32_t token_pointer = 0;

    auto next = next_token(m, h, source, 0u, delimiters, token_pointer);
    require(length_from_slot(h, token_pointer) == 1u,
            "1AE0A0 first token length must take the real positive branch");
    assign_name(m, h, receiver, token_pointer);

    const std::uint32_t fields[]{4u, 8u, 0xcu};
    for (unsigned k = 0; k < 3; ++k) {
        next = next_token(m, h, source, next, delimiters, token_pointer);
        require(length_from_slot(h, token_pointer) == 1u,
                "1AE0A0 numeric token length must take the real positive branch");
        const auto value = parse_decimal(m, h, token_pointer);
        m.w32(receiver + fields[k], value);
    }

    // 0x759320's real final-token destructor: release and clear its pointer.
    h.release(token_pointer);
    token_pointer = 0;
    return receiver; // Original EAX=ESI, RET 4.
}
} // namespace ra2::recovered::recovery_b223
