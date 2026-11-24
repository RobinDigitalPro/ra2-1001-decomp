#pragma once

#include "recovered/global_b26_memory.hpp"
#include <cstdint>

namespace ra2::recovered::recovery_b360 {
using Memory = global_b26::Memory;
using Inputs = global_b26::Inputs;

struct Operations {
    std::uint32_t (*socket)(void* context, std::int32_t family,
                            std::int32_t type, std::int32_t protocol){};
    std::int32_t (*bind)(void* context, std::uint32_t socket,
                         const std::uint8_t* address, std::int32_t length){};
    std::int32_t (*getsockopt)(void* context, std::uint32_t socket,
                               std::int32_t level, std::int32_t option,
                               std::uint8_t* value, std::int32_t* length){};
    std::int32_t (*close)(void* context, std::uint32_t socket){};
    void* context{};
};

// Finite success routes for the exact recovered roots at RVAs 0x356250 and
// 0x3563c0. Native validation executes the original roots and supplies the
// actual platform operations through its separately reviewed bridge.
std::uint32_t fun_00756250(Memory&, const Inputs&, const Operations&);
std::uint32_t fun_007563c0(Memory&, const Inputs&, const Operations&);
}
