#pragma once

#include "recovered/global_b26_memory.hpp"
#include <cstdint>

namespace ra2::recovered::recovery_b937 {
using Memory = global_b26::Memory;
using Inputs = global_b26::Inputs;

// These callbacks are a platform boundary. Native callbacks must forward to
// the actual kernel32 imports and replay only the captured original results.
struct Ops {
    void* context{};
    std::uint32_t get_locale_info_iat_value{};
    bool (*get_version_platform_id)(void*, std::uint32_t&){};
    std::uint32_t (*enum_callback_count)(void*){};
    bool (*enum_callback_text)(void*, std::uint32_t, char*, std::uint32_t){};
    int (*get_locale_info_a)(void*, std::uint32_t, std::uint32_t, char*, int){};
    bool (*is_valid_code_page)(void*, std::uint32_t){};
    bool (*is_valid_locale)(void*, std::uint32_t, std::uint32_t){};
};

// Finite positive route: the prepared country and language names are obtained
// from the first LCID_INSTALLED locale on the actual host. The three entry functions stay
// separate so a native harness can prove each indexed root independently.
std::uint32_t fun_0077ad6a(Memory&, const Inputs&, const Ops&);
std::uint32_t fun_0077af3f(Memory&, const Ops&);
std::uint32_t fun_0077afc6(Memory&, const Inputs&, const Ops&);
}
