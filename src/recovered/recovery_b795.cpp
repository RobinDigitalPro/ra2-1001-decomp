#include "recovery_b795.hpp"

#include "recovered/recovery_b392.hpp"
#include "recovered/recovery_b388.hpp"
#include "recovered/leaf_memory.hpp"

#include <array>
#include <stdexcept>

namespace ra2::recovered::recovery_b795 {
namespace {
constexpr std::uint32_t delimiter_va = 0x007d06dcu;
constexpr std::uint32_t local_stack_base = 0x7ff00000u;
constexpr std::uint32_t local_holder = local_stack_base + 4u;

void need(bool v, const char* why) {
    if (!v) throw std::domain_error(why);
}

std::uint32_t wide_length(const Heap& h, std::uint32_t p) {
    need(p != 0u, "B795 requires a nonnull heap UTF-16 pointer");
    std::uint32_t n = 0u;
    while (h.r8(p + 2u*n) != 0u || h.r8(p + 2u*n + 1u) != 0u) ++n;
    return n;
}

std::uint32_t parse_one_decimal_digit(Memory& m, const Heap& h, std::uint32_t p) {
    // Compose the accepted positive decimal parser. On the original path,
    // 0x35C9B0 -> 0x3704B8 -> 0x3704CF classifies ASCII through 0x3774E0
    // and the pinned C-locale table at 0x817564.
    need(wide_length(h, p) == 1u, "B795 numeric token is outside the one-digit route");
    const auto c = h.r8(p);
    need(h.r8(p + 1u) == 0u && c >= '0' && c <= '9',
         "B795 numeric token must be one ASCII decimal digit");
    // The accepted parser reads its token through Memory. Expose only this
    // already-owned four-byte UTF-16 token span for the duration of the call.
    std::array<std::uint8_t, 4> token_bytes{};
    for (std::uint32_t k = 0; k != token_bytes.size(); ++k)
        token_bytes[k] = static_cast<std::uint8_t>(h.r8(p + k));
    ra2::recovered::leaf::Memory token_span(token_bytes.data(), p, 4u);
    Memory parser_memory = m;
    parser_memory.add(token_span);
    ra2::recovered::recovery_b388::Inputs parsed{};
    parsed.arg[0] = p;
    parsed.arg[1] = 0u;
    parsed.arg[2] = 10u;
    parsed.arg[3] = 0u;
    const auto value = ra2::recovered::recovery_b388::fun_007704cf(parser_memory, parsed);
    need((parsed.arg[3] & 8u) != 0u,
         "B795 decimal helper did not accept the C-locale digit");
    need(value == c - '0', "B795 decimal helper produced an unexpected digit");
    return value;
}

std::uint32_t extract(Memory& m, const Inputs& root, Heap& h,
                      std::uint32_t start, std::uint32_t& result_slot) {
    Inputs call{};
    call.cx = root.arg[0];                 // original EDI is the source pointer-cell
    call.arg[0] = start;
    call.arg[1] = delimiter_va;
    call.arg[2] = local_holder;
    const auto end = recovery_b392::fun_0075c690(m, call, h);
    result_slot = m.r32(local_holder);
    need(end != 0xffffffffu && result_slot != 0u,
         "B795 positive route requires a delimiter-terminated nonempty token");
    need(wide_length(h, result_slot) != 0u,
         "B795 0x35BDE0 positive branch requires a nonempty token");
    return end;
}

void assign_fourth_from_empty_receiver(Memory& m, const Inputs& root, Heap& h,
                                       std::uint32_t source) {
    const auto destination_slot = root.cx + 0x0cu;
    const auto old = m.r32(destination_slot);
    const auto units = wide_length(h, source);
    need(old != 0u && wide_length(h, old) == 0u,
         "B795 0x35B510 specialization requires root-created empty receiver string");
    need(units == 2u && h.r8(source) == 'O' && h.r8(source + 2u) == 'n',
         "B795 fourth token must be UTF-16 On");

    // Exact bounded 0x75B510 old-empty/new-nonempty branch. The broader
    // B258 accepted model has a different old/source contract and is not used.
    (void)h.release(old);                 // 0x36D67B
    m.w32(destination_slot, 0u);
    const auto fresh = h.allocate((units + 1u) * 2u); // 0x36D957, request 6
    need(fresh != 0u, "B795 success-only receiver assignment allocation failed");
    m.w32(destination_slot, fresh);
    h.w8(fresh, 0u); h.w8(fresh + 1u, 0u);
    for (std::uint32_t k = 0; k <= units; ++k) {
        h.w8(fresh + 2u*k, h.r8(source + 2u*k));
        h.w8(fresh + 2u*k + 1u, h.r8(source + 2u*k + 1u));
    }
}
}

std::uint32_t run(Memory& original, const Inputs& i, Heap& h) {
    need(i.cx != 0u && i.arg[0] != 0u,
         "B795 requires receiver and source pointer-cell");
    need(original.r32(0x00817554u) == 0u,
         "B795 uses the explicit initialized threshold-zero ordinary-heap route");
    need(original.r32(i.arg[0]) != 0u,
         "B795 source pointer-cell must refer to a live ordinary-heap input");

    // Give nested helper calls a private guest stack span. This copy makes the
    // span lifetime local to the invocation, while the arena writes remain
    // visible through shared backing Memory objects.
    Memory m = original;
    std::array<std::uint8_t, 32> local_bytes{};
    ra2::recovered::leaf::Memory stack_span(local_bytes.data(), local_stack_base,
                                             static_cast<std::uint32_t>(local_bytes.size()));
    m.add(stack_span);

    const auto receiver = i.cx;
    const auto empty = h.allocate(2u);       // 0x35B300 called with EDI=0
    need(empty != 0u, "B795 success-only initial empty-string allocation failed");
    h.w8(empty, 0u); h.w8(empty + 1u, 0u);
    m.w32(receiver + 0x0cu, empty);
    m.w32(receiver + 0u, 0u);
    m.w32(receiver + 4u, 0u);
    m.w32(receiver + 8u, 0u);
    m.w32(local_holder, 0u);                // 0x35B2F0 initializes local holder

    std::uint32_t index = 0u;
    for (unsigned field = 0; field != 3u; ++field) {
        std::uint32_t token = 0u;
        index = extract(m, i, h, index, token);
        const auto value = parse_one_decimal_digit(m, h, token); // 0x35C9B0 -> 3704B8 -> 3704CF
        m.w32(receiver + 4u*field, value);
    }

    std::uint32_t fourth = 0u;
    (void)extract(m, i, h, index, fourth);
    assign_fourth_from_empty_receiver(m, i, h, fourth); // 0x35B510 bounded subroute

    const auto holder_value = m.r32(local_holder);
    if (holder_value) (void)h.release(holder_value); // 0x35B390
    m.w32(local_holder, 0u);
    return receiver; // original full EAX=ESI; RET 4
}
}
