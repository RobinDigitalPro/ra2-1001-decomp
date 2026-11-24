#define NOMINMAX
#include "recovered/recovery_b926.hpp"
#include "platform/observed_find926.hpp"
#include "recovered/crt_b83.hpp"
#include <windows.h>
#include <array>
#include <stdexcept>
#include <string>
#include <utility>
#include <limits>
#include <map>


namespace {
void require(bool b, const char* why) { if (!b) throw std::domain_error(why); }
std::string bounded_ext(ra2::recovered::recovery_b926::Memory& m, std::uint32_t p) {
    require(p != 0, "B926 null extension outside positive route");
    std::string s;
    for (unsigned k = 0; k < 3; ++k) {
        const auto c = static_cast<unsigned char>(m.r8(p + k));
        require((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'), "B926 exactly three ASCII letters required");
        s.push_back(static_cast<char>(c));
    }
    require(m.r8(p + 3) == 0, "B926 extension must terminate after exactly three bytes");
    return s;
}
std::uint32_t compare_skip_name(ra2::recovered::recovery_b926::Memory& m, const char* name) {
    std::array<std::uint8_t, 4096> ctype{}, constants{};
    for (std::uint32_t k = 0; k < 4096; ++k) {
        ctype[k] = static_cast<std::uint8_t>(m.r8(0xb10000u + k));
        constants[k] = static_cast<std::uint8_t>(m.r8(0x7c1000u + k));
    }
    std::array<std::uint8_t, 260> candidate{};
    for (std::size_t k = 0; k < candidate.size(); ++k) {
        candidate[k] = static_cast<std::uint8_t>(name[k]);
        if (!name[k]) break;
        if (k + 1 == candidate.size()) throw std::domain_error("B926 unterminated API filename");
    }
    ra2::recovered::leaf::Memory ctype_span(ctype.data(), 0xb10000u, 4096);
    ra2::recovered::leaf::Memory constant_span(constants.data(), 0x7c1000u, 4096);
    ra2::recovered::leaf::Memory candidate_span(candidate.data(), 0x30000000u, static_cast<std::uint32_t>(candidate.size()));
    ra2::recovered::recovery_b926::Memory compare_memory; compare_memory.add(ctype_span); compare_memory.add(constant_span); compare_memory.add(candidate_span);
    ra2::recovered::recovery_b926::Inputs cmp{}; cmp.arg[0] = 0x30000000u; cmp.arg[1] = 0x7c1b38u;
    return ra2::recovered::crt_b83::fun_0076d860(compare_memory, cmp);
}
}

namespace ra2::recovered::recovery_b926 {
std::uint32_t fun_0053a7a0(Memory& m, const Inputs& i) {
    const std::uint32_t extptr = m.r32(i.cx + 8u);
    const std::string extension = bounded_ext(m, extptr);
    // Exact root-local route for original `*.%3s` with a three-byte operand.
    const std::string query = "*." + extension;
    WIN32_FIND_DATAA data{};
    HANDLE h = ra2::platform::find926::Observer::first_active(query.c_str(), &data);
    require(h != INVALID_HANDLE_VALUE, "B926 positive fixture requires FindFirstFileA success");
    bool found = false;
    for (;;) {
        if ((data.dwFileAttributes & 0x116u) == 0 && compare_skip_name(m, data.cFileName) != 0) {
            found = true; break;
        }
        if (!ra2::platform::find926::Observer::next_active(h, &data)) break;
    }
    const BOOL closed = ra2::platform::find926::Observer::close_active(h);
    require(closed != FALSE, "B926 positive fixture requires successful FindClose");
    // Original calls FindClose (BOOL 1) then replaces AL with BL.
    return (static_cast<std::uint32_t>(closed) & 0xffffff00u) | (found ? 1u : 0u);
}
}
