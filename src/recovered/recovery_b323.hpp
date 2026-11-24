#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/x87_state.hpp"
#include <array>
#include <cstdint>

namespace ra2::recovery_b323 {
using Memory = recovered::global_b26::Memory;
using Inputs = recovered::global_b26::Inputs;
struct EntryState {
    Inputs input{};
    std::uint32_t eax=0,ecx=0,edx=0,ebx=0,ebp=0,esi=0,edi=0;
    std::array<std::uint32_t,16> caller_words{};
};

// Finite positive 0x708970 route: index 0 names one explicit opaque type
// record, the original manager list contains one available 0x280 pool node,
// and 76aa50 receives the exact caller float 1.0f.
std::uint32_t fun_00405170(Memory&, const Inputs&);
std::uint32_t fun_00708970(Memory&, EntryState&, platform::x87::State&);
}
