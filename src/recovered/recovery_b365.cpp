#include "recovery_b365.hpp"

#include "recovered/leaf_memory.hpp"
#include "recovered/recovery_b359.hpp"
#include "recovered/recovery_b363.hpp"

#include <array>
#include <stdexcept>

namespace ra2::recovered::recovery_b365 {
namespace {
using U = std::uint32_t;
constexpr U private_frame = 0x7d200000u;

void require(bool ok, const char* message) {
    if (!ok) throw std::domain_error(message);
}
}

U fun_00497840(Memory& m, const Inputs& i) {
    const U output = i.arg[0];
    const U format = i.arg[1];
    require(output && format, "B365 needs the output pair and literal format");
    require(std::uint64_t(output) + 8u <= 0x100000000ull &&
            std::uint64_t(format) + 4u <= 0x100000000ull,
            "B365 output and format spans must not wrap");
    require(m.r16(format) == 'A' && m.r16(format + 2u) == 0u,
            "B365 covers exactly UTF-16 L'A'");
    require(m.r8(0x79c6d4u + 0x41u) == 0x20u &&
            m.r8(0x79c6f4u) == 0x06u,
            "B365 requires original classification bytes for ordinary A");

    // The original formatter starts a 0x42 stream at its output pointer with
    // capacity 0x7fffffff. For the pinned A table route, 0x776b88 decrements
    // capacity by two and stores the word directly; 0x76f398 writes the two
    // terminating zero bytes. The buffer is a private local in the original.
    std::array<std::uint8_t, 8> result_bytes{};
    std::array<std::uint8_t, 1032> local_bytes{};
    ra2::recovered::leaf::Memory result_span(result_bytes.data(), private_frame, 8u);
    ra2::recovered::leaf::Memory local_span(local_bytes.data(), private_frame + 8u, 1024u);
    Memory child_memory = m;
    child_memory.add(result_span); child_memory.add(local_span);
    const U text = private_frame + 8u;
    const U result = private_frame;
    child_memory.w16(text, 'A'); child_memory.w16(text + 2u, 0u);
    Inputs child{};
    child.cx = result;
    child.dx = text;
    child.arithmetic_flags = i.arithmetic_flags;
    child.arg[0] = i.arg[2];
    child.arg[1] = i.arg[3];
    child.arg[2] = i.arg[4];
    child.arg[3] = i.arg[5];
    child.arg[4] = i.arg[6];
    child.arg[5] = i.arg[7];
    child.arg[6] = 1u;
    for (U n = 7u; n < child.arg.size(); ++n)
        child.arg[n] = 0x97840000u + n;

    const U child_eax = ra2::recovered::recovery_b359::fun_00497610(child_memory, child);
    require(child_eax == result, "B365 B359 child returned another local pair");
    const U x = child_memory.r32(result);
    const U y = child_memory.r32(result + 4u);
    m.w32(output, x);
    m.w32(output + 4u, y);
    return output;
}

U fun_00497920(Memory& m, const Inputs& i) {
    const U output = i.arg[0];
    const U format = i.arg[1];
    require(output && format, "B365 color wrapper needs output and literal format");
    require(std::uint64_t(output) + 8u <= 0x100000000ull &&
            std::uint64_t(format) + 4u <= 0x100000000ull,
            "B365 color output and format spans must not wrap");
    require(m.r16(format) == 'A' && m.r16(format + 2u) == 0u,
            "B365 color wrapper covers exactly UTF-16 L'A'");
    require(m.r8(0x79c6d4u + 0x41u) == 0x20u &&
            m.r8(0x79c6f4u) == 0x06u,
            "B365 color wrapper requires original A classification bytes");

    const U color_source = i.arg[5] + 0x308u;
    require(color_source >= i.arg[5] && std::uint64_t(color_source) + 3u <= 0x100000000ull,
            "B365 color descriptor address must not wrap");
    std::array<std::uint8_t, 8> result_bytes{};
    std::array<std::uint8_t, 1032> local_bytes{};
    ra2::recovered::leaf::Memory result_span(result_bytes.data(), private_frame, 8u);
    ra2::recovered::leaf::Memory local_span(local_bytes.data(), private_frame + 8u, 1032u);
    Memory child_memory = m;
    child_memory.add(result_span); child_memory.add(local_span);
    const U text = private_frame + 0x10u;
    const U private_output = private_frame;
    child_memory.w16(text, 'A'); child_memory.w16(text + 2u, 0u);

    // 0x97920 invokes 0x4fe550 on outer arg5+0x308, packs RGB565, then
    // calls 0x97610. Reuse the reviewed B363 conversion/glyph composition;
    // its Inputs copy keeps the helper's arg3 stack-word mutation private.
    Inputs color{};
    color.cx = private_output;
    color.dx = text;
    color.arithmetic_flags = i.arithmetic_flags;
    color.arg[0] = i.arg[2];
    color.arg[1] = i.arg[3];
    color.arg[2] = i.arg[4];
    color.arg[3] = i.arg[5];
    color.arg[4] = i.arg[6];
    color.arg[5] = i.arg[7];
    color.arg[6] = 1u;
    const U child_eax = ra2::recovered::recovery_b363::fun_00497770(child_memory, color);
    require(child_eax == private_output, "B365 color composition returned another private pair");
    const U x = child_memory.r32(private_output), y = child_memory.r32(private_output + 4u);
    m.w32(output, x); m.w32(output + 4u, y);
    return output;
}
}
