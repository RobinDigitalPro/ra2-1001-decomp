#include "recovered/recovery_b918.hpp"
#include "recovered/name_hash.hpp"
#include <cstdint>
#include <stdexcept>
#include <string>

namespace ra2::recovered::recovery_b918 {
namespace {
using U = std::uint32_t;
void need(bool value, const char* why) {
    if (!value) throw std::domain_error(why);
}
std::string text(const Memory& m, U address, U max = 32) {
    need(address != 0, "B918 requires a nonnull text address");
    std::string out;
    for (U n = 0; n < max; ++n) {
        const auto c = static_cast<std::uint8_t>(m.r8(address + n));
        if (!c) return out;
        out.push_back(static_cast<char>(c));
    }
    throw std::domain_error("B918 text exceeds bounded name");
}

// The accepted 0x5928a0 positive cache path uses a signed binary search over
// 12-byte hash/offset/length rows and returns the real backing+entry offset.
U cached_resource(Memory& m, const std::string& path) {
    need(!path.empty() && path.size() <= 31, "B918 bounded path");
    need(m.r8(0x00b10530u) == 0, "B918 requires pinned C-mode uppercase path");
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
        need(count <= 12u, "B918 bounded original cache row count");
        while (count) {
            const auto mid = count / 2u;
            const auto row = table + mid * 12u;
            const auto current = m.r32(row);
            if (global_b26::s32(current) > global_b26::s32(hash)) {
                count = mid;
            } else if (current == hash) {
                const auto backing = m.r32(manager + 0x24u);
                need(backing != 0, "B918 positive cache requires loaded backing");
                return backing + m.r32(row + 4u);
            } else {
                table = row + 12u;
                count -= mid + 1u;
            }
        }
        manager = next;
    }
    throw std::domain_error("B918 finite route requires a cached positive hit");
}
}


std::uint32_t fun_00425490(Memory&m,const Inputs&i){const U self=i.cx;need(i.arg[0]==0xffffffffu&&!m.r8(self+0x31a)&&!m.r8(self+0x1fc)&&!m.r8(self+0xa8),"918 borrowed-cache path without variant rewrite");const auto name=text(m,self+0x1c8,16);need(!name.empty(),"918 positivebasename");const auto extension=text(m,0x7b9ca4,8);need(extension==".SHP","918 originalsuffix");const U resource=cached_resource(m,name+extension);m.w32(self+0xa4,resource);const auto count=static_cast<std::int16_t>(m.r16(resource+6));need(count>=1&&count<=8,"918 finite positiveframecount");if(!m.r32(self+0x288))m.w32(self+0x288,m.r8(self+0x32d)?count/2:count);if(!m.r32(self+0x284))m.w32(self+0x284,m.r32(self+0x288));std::int32_t largest=0;U best=0;for(U k=0;k<U(count);++k){const auto w=static_cast<std::int16_t>(m.r16(resource+0xc+0x18*k)),h=static_cast<std::int16_t>(m.r16(resource+0xeu +0x18*k));const auto area=std::int32_t(w)*std::int32_t(h);if(area>largest){largest=area;best=k;}}m.w32(self+0x268,best);return resource+0xc+0x18*U(count);}
}
