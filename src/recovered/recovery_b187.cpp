// Private implementation sketch for RVA 0x2e190. Not part of the build.
// All Windows file operations are forwarded through the proposed observer in
// block187_cases.hpp; that observer must call the real Kernel32 CreateFileA.
#include "recovery_b187.hpp"
#include "recovered/leaf_memory.hpp"
#include "recovered/text_b96.hpp"
#include "platform/observed_create_file187.hpp"
#include <array>
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b187 {
using global_b26::Inputs;
using global_b26::Memory;

namespace {
struct TempFile {
    std::uint32_t vptr{};       // +00
    std::uint32_t zero4{};      // +04
    std::uint32_t zero8{};      // +08
    std::uint32_t status0c{};   // +0c (constructor writes INVALID_HANDLE_VALUE)
    std::uint32_t handle10{};   // +10 (getter and CreateFileA use this field)
    std::uint32_t filename{};   // +14
    std::uint16_t zero18{};     // +18
    std::uint16_t zero1a{};     // +1a
    std::uint8_t initialized{}; // +1c
    std::array<std::uint8_t, 3> padding{};
};
static_assert(sizeof(TempFile) == 0x20);

void construct(TempFile& t, std::uint32_t guest_filename) {
    // Exact reached stores from VA 0x6300e0 (RVA 0x2300e0), including the
    // constructor-installed vptr. The three padding bytes are not written.
    t.status0c = 0xffffffffu;
    t.handle10 = 0xffffffffu;
    t.zero4 = 0;
    t.zero8 = 0;
    t.filename = guest_filename;
    t.zero18 = 0;
    t.zero1a = 0;
    t.initialized = 0;
    t.vptr = 0x00793c84u;
}

std::uint32_t read_c_string(Memory& m, std::uint32_t p,
                            std::array<char, 65>& out) {
    std::uint32_t n = 0;
    for (; n < out.size(); ++n) {
        out[n] = static_cast<char>(m.r8(p + n));
        if (out[n] == '\0') return n;
    }
    throw std::domain_error("187 resource literal not bounded");
}

bool reached_open_path(TempFile& t, Memory& m) {
    // This models the reached 0x495010 -> vtable[+0x14] -> 0x630240 prefix.
    // Constructor/vtable evidence is recorded in closure.json. The reached
    // virtual +0x18 target is 0x630a70, whose exact test is handle != -1.
    if (!t.filename || t.handle10 != 0xffffffffu) return false;
    std::array<char, 65> name{};
    (void)read_c_string(m, t.filename, name);
    const auto result = ra2::platform::file187::Observer::create_file_a(
        name.data(), 0x80000000u, 1u, nullptr, 3u, 0x80u, nullptr);
    t.handle10 = static_cast<std::uint32_t>(
        reinterpret_cast<std::uintptr_t>(result));
    // The selected fresh-empty-CWD domain is exactly INVALID_HANDLE_VALUE.
    // Do not define the other 0x630240 success/close branch here.
    if (t.handle10 != 0xffffffffu)
        throw std::domain_error("187 outside fresh-empty-CWD file-miss contract");
    return false; // original 0x630240 returns AL=0; 0x495010 returns full EAX=0
}

void reached_destroy_path(TempFile& t) {
    // Exact 0x630060 false branch: install base vptr, call the authentic
    // +0x18 getter 0x630a70 (false for handle -1), skip close/release, see
    // initialized byte +0x1c==0, and install final vptr 0x793c3c.
    t.vptr = 0x00793c84u;
    if (t.handle10 != 0xffffffffu || t.initialized != 0)
        throw std::domain_error("187 outside no-handle/no-init destructor branch");
    t.vptr = 0x00793c3cu;
}

std::uint32_t resource_hit(Memory& m, std::uint32_t name) {
    // The original 0x5924c0 wrapper passes a local stack out-pointer to
    // accepted 0x5928a0. Attach a short-lived stack-address span to a copy of
    // Memory so helper reads/writes to the output cell are exact but do not
    // mutate the receiver or persist a dangling span in the caller Memory.
    std::array<std::uint8_t, 4> local_out{};
    constexpr std::uint32_t stack_out = 0xf0000000u;
    leaf::Memory stack_span(local_out.data(), stack_out, local_out.size());
    Memory helper_memory = m;
    helper_memory.add(stack_span);
    Inputs lookup{};
    lookup.cx = name;
    lookup.dx = stack_out;
    const auto found = text_b96::fun_005928a0(helper_memory, lookup);
    const auto payload = stack_span.r32(stack_out);
    if ((found & 0xffu) != 1u || !payload)
        throw std::domain_error("187 requires both real archive lookups to hit");
    return payload;
}

std::int32_t sign16(Memory& m, std::uint32_t a) {
    return static_cast<std::int16_t>(m.r16(a));
}

void copy_dimensions(Memory& m, std::uint32_t receiver,
                     std::uint32_t output, std::uint32_t x, bool second) {
    m.w32(output, x);
    const auto a = sign16(m, x + 2u);
    const auto b = sign16(m, x + 4u);
    const auto c = sign16(m, x + 6u);
    if (!second) {
        m.w32(receiver + 0x64u, static_cast<std::uint32_t>(a));
        m.w32(receiver + 0x68u, static_cast<std::uint32_t>(b));
        m.w32(receiver + 0x6cu, static_cast<std::uint32_t>(c));
    } else {
        m.w32(receiver + 0x70u, static_cast<std::uint32_t>(a));
        m.w32(receiver + 0x74u, static_cast<std::uint32_t>(b));
        m.w32(receiver + 0x78u, static_cast<std::uint32_t>(c));
        m.w32(receiver + 0x7cu, static_cast<std::uint32_t>(c) << 2);
    }
}
} // namespace

std::uint32_t fun_0042e190(Memory& m, const Inputs& i) {
    const auto receiver = i.cx;
    TempFile first{}, second{};
    construct(first, 0x007ba39cu); // PBEACON.SHP

    // First 0x495010 result is zero on actual CreateFileA failure. The root
    // then calls 0x5924c0; resource_hit inlines only that wrapper's local
    // out-pointer arrangement and calls the accepted 0x5928a0 implementation.
    m.w32(0x00836cd4u, reached_open_path(first, m));
    const auto p0 = resource_hit(m, first.filename);
    copy_dimensions(m, receiver, 0x00836cd4u, p0, false);

    construct(second, 0x007ba370u); // original construction follows first resource publication
    m.w32(0x00836cd8u, reached_open_path(second, m));
    const auto p1 = resource_hit(m, second.filename);
    copy_dimensions(m, receiver, 0x00836cd8u, p1, true);

    reached_destroy_path(second);
    reached_destroy_path(first);
    return 0; // final 0x630a70 zero survives both destructors and the root epilogue
}
} // namespace ra2::recovered::recovery_b187
