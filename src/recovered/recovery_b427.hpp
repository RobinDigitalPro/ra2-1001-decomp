#pragma once

#include "recovered/global_b27_memory.hpp"
#include <array>
#include <cstdint>

namespace ra2::recovered::recovery_b427 {
using Memory = global_b27::Memory;
using State = global_b27::State;

// Direct imports only; the native implementation must forward to the matching
// KERNEL32 entry point. The host side is deliberately separate from this model.
struct Ops {
    void* context{};
    std::uint32_t (*locale_info_w)(void*, std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t){};
    std::uint32_t (*locale_info_a)(void*, std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t){};
    std::uint32_t (*string_type_a)(void*, std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t){};
    std::uint32_t (*string_type_w)(void*, std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t){};
    std::uint32_t (*map_a)(void*, std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t){};
    std::uint32_t (*map_w)(void*, std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t){};
    struct VersionA {
        std::uint32_t size{}, major{}, minor{}, build{}, platform{};
        std::array<std::uint8_t, 128> csd{};
    };
    bool (*version_a)(void*, VersionA&){};
};

void fun_0078101b(Memory&, State&, const Ops&); // GetLocaleInfoW, cached W mode
void fun_0078112e(Memory&, State&, const Ops&); // GetLocaleInfoA, cached A mode
void fun_0077d5af(Memory&, State&, const Ops&); // GetStringTypeA, explicit LCID
void fun_0077e549(Memory&, State&, const Ops&); // GetStringTypeW
void fun_00774c82(Memory&, State&, const Ops&); // LCMapStringA, cached A mode
void fun_0077e70e(Memory&, State&, const Ops&); // LCMapStringW, cached W mode
void fun_0072ba70(Memory&, State&, const Ops&); // GetVersionExA constructor
}
