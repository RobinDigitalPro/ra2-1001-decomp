#include "recovery_b184.hpp"

#include <cstdint>
#include <stdexcept>
#include <vector>

namespace ra2::recovered::recovery_b184 {
namespace {
struct Rect { std::uint32_t x, y, w, h; };

std::int32_t signed32(std::uint32_t x) {
    return x < 0x80000000u ? static_cast<std::int32_t>(x)
                           : static_cast<std::int32_t>(static_cast<std::int64_t>(x) - 0x100000000ll);
}
Rect read_rect(const Memory& m, std::uint32_t p) {
    return {m.r32(p), m.r32(p+4u), m.r32(p+8u), m.r32(p+12u)};
}
void write_rect(Memory& m, std::uint32_t p, const Rect& r) {
    m.w32(p,r.x); m.w32(p+4u,r.y); m.w32(p+8u,r.w); m.w32(p+12u,r.h);
}
bool overlap_axis(std::uint32_t a, std::uint32_t alen,
                  std::uint32_t b, std::uint32_t blen) {
    // Original uses signed comparisons and considers endpoint contact an
    // overlap: only a strict gap selects the non-overlap branch.
    if (signed32(a) < signed32(b))
        return signed32(a + alen) >= signed32(b);
    return signed32(b + blen) >= signed32(a);
}
Rect unite(const Rect& a, const Rect& b) {
    const auto x = signed32(a.x) < signed32(b.x) ? a.x : b.x;
    const auto y = signed32(a.y) < signed32(b.y) ? a.y : b.y;
    const auto ar = a.x + a.w, br = b.x + b.w;
    const auto ab = a.y + a.h, bb = b.y + b.h;
    const auto right = signed32(ar) > signed32(br) ? ar : br;
    const auto bottom = signed32(ab) > signed32(bb) ? ab : bb;
    return {x,y,right-x,bottom-y};
}

// This is a direct bounded translation of the self-recursive body.  recursive
// arguments occupy the parent's transient stack and are not entry caller words;
// only the outer invocation mirrors writes to Inputs::arg[0].
std::uint32_t insert(Memory& m, std::uint32_t receiver, Rect candidate,
                    const Inputs* outer, unsigned depth) {
    if (depth > 16u) throw std::domain_error("Block184 recursion bound exceeded");
    const auto count_word = m.r32(receiver+4u);
    const auto count = signed32(count_word);
    const auto records = m.r32(receiver+0x0cu);
    const auto capacity = signed32(m.r32(receiver+0x10u));
    if (signed32(candidate.w) <= 0 || signed32(candidate.h) <= 0)
        return receiver;

    std::uint32_t hit = 0xffffffffu;
    for (std::int32_t j=0; j<count; ++j) {
        const auto slot = records + static_cast<std::uint32_t>(j)*16u;
        const auto current = read_rect(m,slot);
        const bool x = overlap_axis(candidate.x,candidate.w,current.x,current.w);
        if (outer) outer->arg[0] = (outer->arg[0]&0xffffff00u) | (x ? 1u : 0u);
        const bool y = overlap_axis(candidate.y,candidate.h,current.y,current.h);
        if (x && y) { hit=static_cast<std::uint32_t>(j); break; }
    }
    if (hit != 0xffffffffu) {
        // 0x5afde4 stores candidate.y+candidate.h to the outer caller's arg0
        // before the union is formed. The recursive call uses a local stack arg.
        if (outer) outer->arg[0] = candidate.y + candidate.h;
        const auto old_count = m.r32(receiver+4u);
        const auto merged = unite(candidate,read_rect(m,records+hit*16u));
        const auto new_count = old_count-1u;
        m.w32(receiver+4u,new_count);
        for (std::uint32_t j=hit; j<new_count; ++j) {
            const auto dst=records+j*16u, src=dst+16u;
            write_rect(m,dst,read_rect(m,src));
        }
        return insert(m,receiver,merged,nullptr,depth+1u);
    }

    if (count < capacity) {
        write_rect(m,records+count_word*16u,candidate);
        m.w32(receiver+4u,count_word+1u);
        return receiver;
    }

    // Full-capacity branch: original chooses the first minimum *unsigned*
    // low-DWORD union area (JNC skips equal/larger), overwrites that record,
    // returns the selected union height, and leaves arg0 equal to its area.
    if (outer) outer->arg[0]=0xffffffffu;
    if (count <= 0) throw std::domain_error("Block184 full-capacity route requires positive count");
    std::uint32_t best_index=0, best_area=0xffffffffu;
    Rect best{};
    for (std::uint32_t j=0; j<count_word; ++j) {
        const auto merged=unite(candidate,read_rect(m,records+j*16u));
        const auto area=merged.w*merged.h;
        if (area < best_area) {
            best_index=j; best_area=area; best=merged;
            if (outer) outer->arg[0]=best_area;
        }
    }
    write_rect(m,records+best_index*16u,best);
    return best.h;
}
} // namespace

std::uint32_t fun_005afcf0(Memory& m, const Inputs& i) {
    const auto candidate_ptr=i.arg[0]; // saved in ESI before arg0 is reused as scratch
    const auto candidate=read_rect(m,candidate_ptr);
    return insert(m,i.cx,candidate,&i,0u);
}
} // namespace ra2::recovered::recovery_b184
