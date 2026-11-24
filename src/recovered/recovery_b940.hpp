#pragma once

#include "recovered/global_b27_memory.hpp"
#include "recovered/recovery_b427.hpp"
#include <cstdint>

namespace ra2::recovered::recovery_b940 {
using Memory = ra2::recovered::global_b27::Memory;
using State = ra2::recovered::global_b27::State;

// GetCPInfo is the only additional platform boundary. The accepted B427
// helpers retain their own real GetStringTypeA/LCMapStringA Ops boundary.
struct Ops {
    void* context{};
    std::uint32_t (*get_cp_info)(void*, std::uint32_t codepage,
                                 std::uint32_t guest_cpinfo){};
    ra2::recovered::recovery_b427::Ops locale{};
};

// frame_bp is the value of EBP after the original PUSH EBP / MOV EBP,ESP
// prologue. The caller-saved EBP value is already in Memory at frame_bp.
std::uint32_t fun_00777295(Memory&, State&, const Ops&,
                           std::uint32_t frame_bp);
}
