#pragma once

#include "recovered/global_b26_memory.hpp"
#include "platform/x87_state.hpp"
#include <array>
#include <cstdint>

namespace ra2::recovery_b345_20e950 {
struct EntryState {
    std::uint32_t eax=0,ecx=0,edx=0,ebx=0,ebp=0,esi=0,edi=0;
    std::array<std::uint32_t,16> caller_words{};
};

// Finite default branch: ECX addresses a byte other than 09/06/07; the
// original UI global points to a control object whose +620 DWORD is registry
// index zero satisfying the accepted 0x708970 positive contract.
std::uint32_t fun_0060e950(recovered::global_b26::Memory&, EntryState&,
                           platform::x87::State&);
}
