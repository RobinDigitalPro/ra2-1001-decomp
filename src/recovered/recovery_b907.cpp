#include "recovered/recovery_b907.hpp"
#include "recovered/name_hash.hpp"
#include <cstdint>
#include <stdexcept>
#include <string>

namespace ra2::recovered::recovery_b907 {
namespace {
using U = std::uint32_t;
void need(bool value, const char* why) {
    if (!value) throw std::domain_error(why);
}
std::string text(const Memory& m, U address, U max = 32) {
    need(address != 0, "B907 requires a nonnull text address");
    std::string out;
    for (U n = 0; n < max; ++n) {
        const auto c = static_cast<std::uint8_t>(m.r8(address + n));
        if (!c) return out;
        out.push_back(static_cast<char>(c));
    }
    throw std::domain_error("B907 text exceeds bounded name");
}

// The accepted 0x5928a0 positive cache path uses a signed binary search over
// 12-byte hash/offset/length rows and returns the real backing+entry offset.
U cached_resource(Memory& m, const std::string& path) {
    need(!path.empty() && path.size() <= 31, "B907 bounded path");
    need(m.r8(0x00b10530u) == 0, "B907 requires pinned C-mode uppercase path");
    std::string key = path;
    for (auto& c : key) {
        const auto u = static_cast<std::uint8_t>(c);
        if (u >= 'a' && u <= 'z') c = static_cast<char>(u - ('a' - 'A'));
    }
    NameHashState state{};
    const auto hash = fun_00493da0(state,
        reinterpret_cast<const std::uint8_t*>(key.data()),
        static_cast<std::int32_t>(key.size()));

    auto manager = m.r32(0x00a588e0u);
    for (unsigned chain = 0; chain < 2 && manager; ++chain) {
        const auto next = m.r32(manager + 4u);
        if (!m.r32(manager + 8u)) break;
        auto count = m.r32(manager + 0x14u);
        auto table = m.r32(manager + 0x20u);
        need(count <= 12u, "B907 bounded original cache row count");
        while (count) {
            const auto mid = count / 2u;
            const auto row = table + mid * 12u;
            const auto current = m.r32(row);
            if (global_b26::s32(current) > global_b26::s32(hash)) {
                count = mid;
            } else if (current == hash) {
                const auto backing = m.r32(manager + 0x24u);
                need(backing != 0, "B907 positive cache requires loaded backing");
                return backing + m.r32(row + 4u);
            } else {
                table = row + 12u;
                count -= mid + 1u;
            }
        }
        manager = next;
    }
    throw std::domain_error("B907 finite route requires a cached positive hit");
}
}

std::uint32_t fun_005cfcc0(Memory& m, const Inputs& i) {
    const auto self = i.cx;
    need(self != 0, "B907 nonnull owner");

    // 0x5cfcca tests +0x1e1. Zero branches to 0x5cfd62, which explicitly
    // clears +0x1e2 and then joins the 76eb30 path constructor. The selected
    // constructor arguments are null prefix/directory, inline name, and the
    // original .SHP suffix at 0x7b9ca4.
    if (m.r8(self + 0x1e1u) != 0)
        throw std::domain_error("B907 bounded route requires +0x1e1 == 0");
    need(m.r8(self + 0xa8u) == 0 && m.r8(self + 0x1fcu) == 0 && m.r8(self + 0x207u) == 0,
         "B907 no optional path or extension rewrite");
    const auto name = text(m, self + 0x1c8u, 16);
    need(!name.empty() && name.size() <= 12, "B907 inline resource basename");

    const auto extension = text(m, 0x007b9ca4u, 8);
    need(extension == ".SHP", "B907 original path suffix literal");
    const auto resource = cached_resource(m, name + extension);

    // Original 0x5cfe3f clears the old output pointer and byte flag. Since
    // +0xa8 is zero, the destructor path is skipped. Then the real positive
    // 0x5924c0/0x5928a0 cache result is stored at +0xa4.
    m.w32(self + 0xa4u, 0);
    m.w8(self + 0xa8u, 0);
    m.w32(self + 0xa4u, resource);
    m.w8(self + 0x1e2u, 0);

    const auto width = static_cast<std::int32_t>(static_cast<std::int16_t>(m.r16(resource + 2u)));
    const auto height = static_cast<std::int32_t>(static_cast<std::int16_t>(m.r16(resource + 4u)));
    const auto extent = width > height ? width : height;
    const auto result = extent > 8 ? static_cast<U>(extent) : 8u;
    m.w32(self + 0x1bcu, result);
    return result;
}
}
