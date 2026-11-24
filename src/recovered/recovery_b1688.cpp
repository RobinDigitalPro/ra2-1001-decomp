#include "recovery_b1688.hpp"
#include <stdexcept>

namespace ra2::recovered::b1688 {
namespace {
constexpr U kFilename = 0x007be900u;
constexpr U kMode = 0x007be90cu;
constexpr U kFramesFormat = 0x007be8f4u;
constexpr U kAverageFormat = 0x007be8e0u;
constexpr U kAheadFormat = 0x007be8ccu;
constexpr U kLatencyFormat = 0x007be8b4u;
constexpr U kSpeedFormat = 0x007be89cu;
constexpr U kFlagBase = 0x00a258b4u;
constexpr U kFlagStride = 0x68u;
constexpr U kFlagCount = 8u;

void emit(Stdio& api, Observation& out, U file, U format, U value, U slot) {
    out.stage = 3;
    out.formats[slot] = format;
    out.values[slot] = value;
    ++out.prints;
    const U returned = api.print(file, format, value);
    out.print_returns[slot] = returned;
    out.last_print_return = returned;
}
}

U run(Memory& memory, const Inputs& inputs, Stdio& api, Observation& out) {
    (void)inputs;
    out = {};
    out.nonzero_flag_index = 0xffffffffu;
    out.stage = 1;
    const U enabled = memory.r32(0x00a255c8u);
    if (enabled != 4u) {
        throw std::domain_error("82D80 outside selected A255C8==4 route");
    }

    out.stage = 2;
    ++out.opens;
    const U file = api.open(kFilename, kMode);
    out.file = file;
    out.open_return = file;
    if (file == 0u) {
        out.stage = 7;
        return file;
    }

    emit(api, out, file, kFramesFormat, memory.r32(0x00a2896cu), 0u);

    const U divisor = memory.r32(0x00a56754u);
    U average = 0u;
    if (divisor != 0u) {
        const U numerator = memory.r32(0x00a56750u);
        average = numerator / divisor; // Original XOR EDX,EDX; DIV ECX.
    }
    emit(api, out, file, kAverageFormat, average, 1u);
    emit(api, out, file, kAheadFormat, memory.r32(0x00a258a8u), 2u);
    emit(api, out, file, kLatencyFormat, memory.r32(0x00a27ed0u), 3u);
    emit(api, out, file, kSpeedFormat, memory.r32(0x00a28758u), 4u);

    out.stage = 4;
    out.container = memory.r32(0x00821f90u);
    if (out.container != 0u) {
        throw std::domain_error("82D80 nonnull container virtual route is outside selected domain");
    }

    out.stage = 5;
    for (U n = 0; n < kFlagCount; ++n) {
        const U flag = memory.r8(kFlagBase + n * kFlagStride);
        ++out.flags_checked;
        if (flag != 0u) {
            out.nonzero_flag_index = n;
            out.nonzero_flag = flag;
            throw std::domain_error("82D80 nonzero child flag route is outside selected domain");
        }
    }

    out.stage = 6;
    ++out.closes;
    out.close_return = api.close(file);
    out.stage = 7;
    return out.close_return;
}

U run(Memory& memory, const Inputs& inputs, Stdio& api) {
    Observation out;
    return run(memory, inputs, api, out);
}
} // namespace ra2::recovered::b1688
