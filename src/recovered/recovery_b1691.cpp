#include "recovery_b1691.hpp"
#include <array>
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b1691 {
namespace {
constexpr std::uint32_t delimiter = 0x7b9950u;
constexpr std::uint32_t vector_vptr = 0x788a94u;
constexpr std::uint32_t text_limit = 512u;
void need(bool condition) {
    if (!condition) throw std::domain_error("1A09D0 finite fresh-vector and qualified CRT contract");
}
bool disjoint(std::uint32_t a, std::uint32_t an,
              std::uint32_t b, std::uint32_t bn) {
    return std::uint64_t(a) + an <= b || std::uint64_t(b) + bn <= a;
}
void span(std::uint32_t a, std::uint32_t n) {
    need(std::uint64_t(a) + n <= 0x100000000ull);
}
std::uint32_t text_bytes(Memory& m, std::uint32_t text) {
    span(text, text_limit);
    for (std::uint32_t n = 0; n < text_limit; ++n)
        if (m.r8(text + n) == 0u) return n + 1u;
    need(false); return 0u;
}
void check_text(Memory& m, std::uint32_t text, std::uint32_t bytes) {
    std::uint32_t n = 0u, tokens = 0u;
    while (n + 1u < bytes) {
        if (m.r8(text + n) == ',') { ++n; continue; }
        const auto begin = n;
        bool negative = false;
        auto c = m.r8(text + n);
        if (c == '+' || c == '-') { negative = c == '-'; ++n; }
        const auto digits = n;
        std::uint64_t value = 0u;
        while (n + 1u < bytes && (c = m.r8(text + n)) != ',') {
            need(c >= '0' && c <= '9' && n - digits < 10u);
            value = value * 10u + c - '0';
            need(value <= (negative ? 2147483648ull : 2147483647ull));
            ++n;
        }
        need(n > digits && tokens < 17u);
        if (tokens == 0u) need(n - begin == 1u && m.r8(text + begin) == '1');
        ++tokens;
    }
    need(tokens >= 1u);
}

// Reached null-pointer path of46C880: read pointer, zero count, ownership,
// capacity in original order. The active byte and all padding are untouched.
std::uint32_t clear_empty(Memory& m, std::uint32_t self) {
    const auto pointer = m.r32(self + 4u);
    m.w32(self + 0x10u, 0u);
    need(pointer == 0u);
    m.w8(self + 0xdu, 0u);
    m.w32(self + 8u, 0u);
    return pointer;
}
// Reached zero-size branch of46CE50 invokes the actual reached clear
// semantics again. It does not invoke slot+10 or the allocator.
std::uint32_t resize_zero(Memory& m, std::uint32_t self, std::uint32_t capacity) {
    need(capacity == 0u);
    clear_empty(m, self);
    const auto result_capacity = m.r32(self + 8u);
    const auto count = m.r32(self + 0x10u);
    if (global_b26::s32(result_capacity) < global_b26::s32(count))
        m.w32(self + 0x10u, result_capacity);
    return (result_capacity & 0xffffff00u) | 1u;
}
struct Allocations {
    std::array<std::uint32_t, 16> pointers{};
    std::uint32_t count = 0u;
    void add(std::uint32_t p, std::uint32_t self, std::uint32_t text,
             std::uint32_t bytes) {
        need(p != 0u && count < pointers.size()); span(p, 40u);
        need(disjoint(p, 40u, self, 0x248u) && disjoint(p, 40u, text, bytes));
        need(disjoint(p, 40u, delimiter, 2u));
        need(disjoint(p, 40u, vector_vptr, 28u));
        need(disjoint(p, 40u, 0x791764u, 0x68u));
        for (std::uint32_t j = 0u; j < count; ++j)
            need(disjoint(p, 40u, pointers[j], 40u));
        pointers[count++] = p;
    }
};
// Successful46CE50(10,0): active byte0 precedes real malloc40; active byte1
// follows it. Old pointer0 skips copy/free. Preserve every allocation byte
// until the caller's single DWORD append, including any rounded heap tail.
std::uint32_t grow_empty(Memory& m, Heap& heap, std::uint32_t vector,
                         std::uint32_t self, std::uint32_t text,
                         std::uint32_t bytes, Allocations& allocations) {
    m.w8(vector + 0xcu, 0u);
    const auto pointer = heap.allocate(40u);
    m.w8(vector + 0xcu, 1u);
    allocations.add(pointer, self, text, bytes);
    need(m.r32(vector + 4u) == 0u);
    m.w32(vector + 4u, pointer);
    m.w32(vector + 8u, 10u);
    m.w8(vector + 0xdu, 1u);
    const auto capacity = m.r32(vector + 8u);
    const auto count = m.r32(vector + 0x10u);
    if (global_b26::s32(capacity) < global_b26::s32(count))
        m.w32(vector + 0x10u, capacity);
    return (capacity & 0xffffff00u) | 1u;
}
void append_one(Memory& m, Heap& heap, StandardCrt& crt,
                std::uint32_t vector, std::uint32_t self,
                std::uint32_t text, std::uint32_t bytes,
                Allocations& allocations) {
    const auto token = crt.tokenize(0u, delimiter);
    const auto value = token ? crt.integer(token) : 0xffffffffu;
    const auto capacity = m.r32(vector + 8u);
    const auto count = m.r32(vector + 0x10u);
    need(capacity == 0u && count == 0u);
    // Both selected Root branches allow the zero-capacity growth route,
    // inspect positive growth10 and dispatch the authentic resize+8 method.
    const auto owner = m.r8(vector + 0xdu);
    need(owner != 0u || capacity == 0u);
    need(m.r32(vector + 0x14u) == 10u);
    const auto result = grow_empty(m, heap, vector, self, text, bytes, allocations);
    need((result & 0xffu) != 0u);
    const auto old_count = m.r32(vector + 0x10u);
    const auto pointer = m.r32(vector + 4u);
    m.w32(vector + 0x10u, old_count + 1u);
    heap.w32(pointer + 4u * old_count, value);
}
} // namespace

void preflight(Memory& m, const Inputs& inputs) {
    const auto self = inputs.cx, text = inputs.arg[1];
    need(inputs.arg[0] == 1u && self != 0u && text != 0u);
    span(self, 0x248u);
    const auto bytes = text_bytes(m, text);
    need(disjoint(self, 0x248u, text, bytes));
    need(disjoint(self, 0x248u, delimiter, 2u));
    need(disjoint(self, 0x248u, vector_vptr, 28u));
    need(disjoint(self, 0x248u, 0x791764u, 0x68u));
    need(disjoint(text, bytes, delimiter, 2u));
    need(disjoint(text, bytes, vector_vptr, 28u));
    need(disjoint(text, bytes, 0x791764u, 0x68u));
    need(m.r32(self) == 0x791764u && m.r32(0x7917c8u) == 0x5a09d0u);
    need(m.r32(0x788a9cu) == 0x46ce50u && m.r32(0x788aa0u) == 0x46c880u);
    need(m.r8(delimiter) == ',' && m.r8(delimiter + 1u) == 0u);
    for (std::uint32_t bank = 0u; bank < 2u; ++bank)
        for (std::uint32_t j = 0u; j < 8u; ++j) {
            const auto vector = self + 0xc8u + bank * 0xc0u + j * 0x18u;
            // Bounds-check all24 header bytes without normalizing padding.
            for (std::uint32_t k = 0u; k < 0x18u; ++k) (void)m.r8(vector + k);
            need(m.r32(vector) == vector_vptr && m.r32(vector + 4u) == 0u);
            need(m.r32(vector + 8u) == 0u && m.r8(vector + 0xcu) == 1u);
            need(m.r8(vector + 0xdu) == 0u && m.r32(vector + 0x10u) == 0u);
            need(m.r32(vector + 0x14u) == 10u);
        }
    check_text(m, text, bytes);
}

std::uint32_t run(Memory& m, const Inputs& inputs, Heap& heap, StandardCrt& crt) {
    // The caller must run preflight before entering the observed guest state.
    // Successful execution uses only fixed stack bookkeeping, Memory, the
    // qualified CRT and actual Heap; no observation containers are allocated.
    const auto self = inputs.cx, text = inputs.arg[1];
    const auto bytes = text_bytes(m, text);
    const auto token = crt.tokenize(text, delimiter);
    const auto rows = crt.integer(token);
    inputs.arg[0] = rows; //5A0A00 writes the real root caller word.
    need(rows == 1u);
    for (std::uint32_t j = 0u; j < 8u; ++j) {
        const auto first = self + 0xc8u + j * 0x18u;
        const auto first_capacity = m.r32(first + 8u);
        clear_empty(m, first); resize_zero(m, first, first_capacity);
        const auto second = first + 0xc0u;
        const auto second_capacity = m.r32(second + 8u);
        clear_empty(m, second); resize_zero(m, second, second_capacity);
    }
    Allocations allocations;
    for (std::uint32_t j = 0u; j < 8u; ++j) {
        const auto first = self + 0xc8u + j * 0x18u;
        append_one(m, heap, crt, first, self, text, bytes, allocations);
        append_one(m, heap, crt, first + 0xc0u, self, text, bytes, allocations);
    }
    const auto remaining = inputs.arg[0] - 1u;
    inputs.arg[0] = remaining; //5A0BEF/5A0BF0 finalDEC and caller-word store.
    return remaining; //Full EAX0; original cleanup RET8.
}
} // namespace ra2::recovered::recovery_b1691
