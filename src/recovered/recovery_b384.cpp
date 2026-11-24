#include "recovery_b384.hpp"

#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b384 {
namespace {
using ra2::recovered::global_b26::s32;
struct Graph{std::uint32_t vptr,col,chd,bca,count,attributes,target;};
constexpr std::uint32_t kSource = 0x007b91d0u;
constexpr std::uint32_t kRegistry = 0x00aa7a60u;
constexpr std::uint32_t kCount = 0x00aa7a64u;
constexpr std::uint32_t kInitialized = 0x00aa7a6cu;
constexpr std::uint32_t kCache = 0x00aa7a70u;

void require(bool condition, const char* message) {
    if (!condition) throw std::domain_error(message);
}

// Matches the original helper's unsigned-byte, NUL-terminated decorated-name
// comparison, but only for these mapped, valid original RTTI strings.
bool same_type_name(Memory& m, std::uint32_t left, std::uint32_t right) {
    if (left == right) return true;
    for (std::uint32_t n = 0; n < 256u; ++n) {
        const auto a = m.r8(left + 8u + n);
        const auto b = m.r8(right + 8u + n);
        if (a != b) return false;
        if (a == 0) return true;
    }
    throw std::domain_error("B384 requires a NUL-terminated original type name within 256 bytes");
}

std::uint32_t zero_offset_top(Memory& m, std::uint32_t object,const Graph& g) {
    const auto vptr = m.r32(object);
    require(vptr == g.vptr, "B384 object must use the wrapper-specific original vptr");
    const auto col = m.r32(vptr - 4u);
    require(col == g.col, "B384 object must use the wrapper-specific original COL");
    require(m.r32(col + 4u) == 0u && m.r32(col + 8u) == 0u,
            "B384 supports only the pinned zero COL offsets");
    return object;
}

std::uint32_t first_pass_target(Memory& m, std::uint32_t source_type,
                                std::uint32_t target_type,
                                std::uint32_t source_delta,const Graph& g) {
    require(source_type == kSource, "B384 source descriptor must be AbstractClass");
    require(target_type == g.target,
            "B384 target descriptor is outside this wrapper original target");
    require(m.r32(g.col + 16u) == g.chd, "B384 expected wrapper-specific original CHD");
    require(m.r32(g.chd + 4u) == g.attributes && m.r32(g.chd + 8u) == g.count &&
            m.r32(g.chd + 12u) == g.bca,
            "B384 requires the wrapper-specific original CHD/BCA profile");

    // This is only the original 0x36f800 first pass: find a target candidate,
    // then its source in the candidate's contained-base range. The second
    // target-only/public pass is deliberately excluded from B384.
    for (std::uint32_t n = 0; n < g.count; ++n) {
        const auto outer = m.r32(g.bca + 4u * n);
        if (!same_type_name(m, m.r32(outer), target_type)) continue;
        const auto contained = m.r32(outer + 4u);
        require(contained != 0u && n + contained < g.count,
                "B384 target BCD subtree exceeds the pinned BCA");
        for (std::uint32_t k = 0; k < contained; ++k) {
            const auto child = m.r32(g.bca + 4u * (n + 1u + k));
            if (!same_type_name(m, m.r32(child), source_type)) continue;
            const auto mdisp = m.r32(child + 8u);
            const auto pdisp = s32(m.r32(child + 12u));
            const auto vdisp = m.r32(child + 16u);
            require(mdisp == 0u && pdisp == -1 && vdisp == 0u,
                    "B384 source BCD must have pinned PMD {0,-1,0}");
            if (mdisp == source_delta) return outer;
        }
    }
    throw std::domain_error("B384 positive fixture did not reach first-pass source-in-target match");
}

std::uint32_t cast_root(Memory& m, const Inputs& i,const Graph& g) {
    // Raw x86 stack parameters at [EBP+8..18]: object, vfDelta, source,
    // target, isReference. Entry ECX/EDX are not inputs on this route.
    const auto object = i.arg[0];
    const auto vf_delta = i.arg[1];
    const auto source_type = i.arg[2];
    const auto target_type = i.arg[3];
    const auto is_reference = i.arg[4];
    require(object != 0u, "B384 positive cast excludes null objects");
    require(vf_delta == 0u && is_reference == 0u,
            "B384 supports only vfDelta=0 and pointer-cast mode");
    const auto complete = zero_offset_top(m, object,g);

    // 0x76f67d stores object-vfDelta over the root's first stack argument.
    // The selected contract fixes vfDelta=0, so the observed value remains
    // the caller-supplied object pointer.
    i.arg[0] = object - vf_delta;
    const auto source_delta = i.arg[0] - complete;
    const auto selected = first_pass_target(m, source_type, target_type, source_delta,g);
    const auto mdisp = m.r32(selected + 8u);
    const auto pdisp = s32(m.r32(selected + 12u));
    const auto vdisp = m.r32(selected + 16u);
    require(mdisp == 0u && pdisp == -1 && vdisp == 0u,
            "B384 target PMD must be pinned {0,-1,0}");
    return complete + mdisp;
}

std::uint32_t inline_wrapper_search(Memory& m, std::uint32_t table,
                                    std::uint32_t count, std::uint32_t key) {
    std::uint32_t lower = table;
    auto remaining = static_cast<std::int32_t>(count);
    const auto signed_key = s32(key);
    while (remaining > 0) {
        const auto mid = static_cast<std::uint32_t>(remaining / 2);
        const auto row = lower + mid * 8u;
        const auto row_key = s32(m.r32(row));
        if (row_key == signed_key) return row;
        if (row_key > signed_key) {
            remaining = static_cast<std::int32_t>(mid);
        } else {
            lower = row + 8u;
            remaining -= static_cast<std::int32_t>(mid) + 1;
        }
    }
    throw std::domain_error("B384 positive wrapper fixture requires a sorted-key hit");
}

std::uint32_t wrapper(Memory& m, const Inputs& i,const Graph& g) {
    const auto receiver = i.cx;
    require(m.r8(receiver + 4u) == 0x34u, "B384 wrapper requires tag 0x34");
    const auto key = m.r32(receiver);
    const auto count = m.r32(kCount);
    require(count >= 1u && count <= 7u,
            "B384 wrapper requires an initialized 1..7 row registry");
    const auto table = m.r32(kRegistry);
    auto row = m.r32(kCache);
    if (row && m.r32(row) != key) row = 0;
    if (!row) {
        require(m.r8(kInitialized) != 0u,
                "B384 excludes original registry initialization route");
        row = inline_wrapper_search(m, table, count, key);
        m.w32(kCache, row);
    }

    const auto object = m.r32(row + 4u);
    Inputs nested = i;
    nested.arg[0] = object;
    nested.arg[1] = 0u;
    nested.arg[2] = kSource;
    nested.arg[3] = g.target;
    nested.arg[4] = 0u;
    return cast_root(m, nested,g);
}
} // namespace

std::uint32_t fun_006ab780(Memory& m,const Inputs& i) {constexpr Graph g{0x787084,0x79e958,0x79e948,0x79e918,11,1,0x7b9c28};return wrapper(m,i,g);}
std::uint32_t fun_006ab2a0(Memory& m,const Inputs& i) {constexpr Graph g{0x78dde0,0x7a5710,0x7a5700,0x7a56c0,15,5,0x7c51d8};return wrapper(m,i,g);}
std::uint32_t fun_006abac0(Memory& m,const Inputs& i) {constexpr Graph g{0x787bbc,0x79f1f0,0x79f1e0,0x79f1a0,15,1,0x7ba638};return wrapper(m,i,g);}
std::uint32_t fun_006ab920(Memory& m,const Inputs& i) {constexpr Graph g{0x78e540,0x7a5fa0,0x7a5f90,0x7a5f48,16,1,0x7c5f48};return wrapper(m,i,g);}
std::uint32_t fun_006ab9f0(Memory& m,const Inputs& i) {constexpr Graph g{0x798c88,0x7af880,0x7af870,0x7af828,16,1,0x7e05f8};return wrapper(m,i,g);}
} // namespace ra2::recovered::recovery_b384
