#include "recovery_b383.hpp"

#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b383 {
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
    throw std::domain_error("B383 requires a NUL-terminated original type name within 256 bytes");
}

std::uint32_t zero_offset_top(Memory& m, std::uint32_t object,const Graph& g) {
    const auto vptr = m.r32(object);
    require(vptr == g.vptr, "B383 object must use the wrapper-specific original vptr");
    const auto col = m.r32(vptr - 4u);
    require(col == g.col, "B383 object must use the wrapper-specific original COL");
    require(m.r32(col + 4u) == 0u && m.r32(col + 8u) == 0u,
            "B383 supports only the pinned zero COL offsets");
    return object;
}

std::uint32_t first_pass_target(Memory& m, std::uint32_t source_type,
                                std::uint32_t target_type,
                                std::uint32_t source_delta,const Graph& g) {
    require(source_type == kSource, "B383 source descriptor must be AbstractClass");
    require(target_type == g.target,
            "B383 target descriptor is outside this wrapper original target");
    require(m.r32(g.col + 16u) == g.chd, "B383 expected wrapper-specific original CHD");
    require(m.r32(g.chd + 4u) == g.attributes && m.r32(g.chd + 8u) == g.count &&
            m.r32(g.chd + 12u) == g.bca,
            "B383 requires the wrapper-specific original CHD/BCA profile");

    // This is only the original 0x36f800 first pass: find a target candidate,
    // then its source in the candidate's contained-base range. The second
    // target-only/public pass is deliberately excluded from B383.
    for (std::uint32_t n = 0; n < g.count; ++n) {
        const auto outer = m.r32(g.bca + 4u * n);
        if (!same_type_name(m, m.r32(outer), target_type)) continue;
        const auto contained = m.r32(outer + 4u);
        require(contained != 0u && n + contained < g.count,
                "B383 target BCD subtree exceeds the pinned BCA");
        for (std::uint32_t k = 0; k < contained; ++k) {
            const auto child = m.r32(g.bca + 4u * (n + 1u + k));
            if (!same_type_name(m, m.r32(child), source_type)) continue;
            const auto mdisp = m.r32(child + 8u);
            const auto pdisp = s32(m.r32(child + 12u));
            const auto vdisp = m.r32(child + 16u);
            require(mdisp == 0u && pdisp == -1 && vdisp == 0u,
                    "B383 source BCD must have pinned PMD {0,-1,0}");
            if (mdisp == source_delta) return outer;
        }
    }
    throw std::domain_error("B383 positive fixture did not reach first-pass source-in-target match");
}

std::uint32_t cast_root(Memory& m, const Inputs& i,const Graph& g) {
    // Raw x86 stack parameters at [EBP+8..18]: object, vfDelta, source,
    // target, isReference. Entry ECX/EDX are not inputs on this route.
    const auto object = i.arg[0];
    const auto vf_delta = i.arg[1];
    const auto source_type = i.arg[2];
    const auto target_type = i.arg[3];
    const auto is_reference = i.arg[4];
    require(object != 0u, "B383 positive cast excludes null objects");
    require(vf_delta == 0u && is_reference == 0u,
            "B383 supports only vfDelta=0 and pointer-cast mode");
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
            "B383 target PMD must be pinned {0,-1,0}");
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
    throw std::domain_error("B383 positive wrapper fixture requires a sorted-key hit");
}

std::uint32_t wrapper(Memory& m, const Inputs& i,const Graph& g) {
    const auto receiver = i.cx;
    require(m.r8(receiver + 4u) == 0x34u, "B383 wrapper requires tag 0x34");
    const auto key = m.r32(receiver);
    const auto count = m.r32(kCount);
    require(count >= 1u && count <= 7u,
            "B383 wrapper requires an initialized 1..7 row registry");
    const auto table = m.r32(kRegistry);
    auto row = m.r32(kCache);
    if (row && m.r32(row) != key) row = 0;
    if (!row) {
        require(m.r8(kInitialized) != 0u,
                "B383 excludes original registry initialization route");
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

std::uint32_t fun_006aabf0(Memory& m,const Inputs& i) {constexpr Graph g{0x785e88,0x79e250,0x79e240,0x79e218,9,5,0x7b91f0};return wrapper(m,i,g);}
std::uint32_t fun_006aacc0(Memory& m,const Inputs& i) {constexpr Graph g{0x7975a8,0x7ae7b8,0x7ae7a8,0x7ae780,9,1,0x7c55a0};return wrapper(m,i,g);}
std::uint32_t fun_006ab1d0(Memory& m,const Inputs& i) {constexpr Graph g{0x798888,0x7af580,0x7af570,0x7af548,9,1,0x7e0560};return wrapper(m,i,g);}
std::uint32_t fun_006ab850(Memory& m,const Inputs& i) {constexpr Graph g{0x7977f8,0x7aea70,0x7aea60,0x7aea38,9,1,0x7e05e0};return wrapper(m,i,g);}
std::uint32_t fun_006aad90(Memory& m,const Inputs& i) {constexpr Graph g{0x79768c,0x7ae908,0x7ae8f8,0x7ae8c8,10,1,0x7e0528};return wrapper(m,i,g);}
std::uint32_t fun_006ab440(Memory& m,const Inputs& i) {constexpr Graph g{0x798934,0x7af638,0x7af628,0x7af5f8,10,1,0x7e0580};return wrapper(m,i,g);}
std::uint32_t fun_006ab510(Memory& m,const Inputs& i) {constexpr Graph g{0x797898,0x7aeb28,0x7aeb18,0x7aeae8,10,1,0x7e05a0};return wrapper(m,i,g);}
std::uint32_t fun_006ab6b0(Memory& m,const Inputs& i) {constexpr Graph g{0x788374,0x79f6a8,0x79f698,0x79f668,10,1,0x7bc1a8};return wrapper(m,i,g);}
std::uint32_t fun_006ab370(Memory& m,const Inputs& i) {constexpr Graph g{0x797f28,0x7aed60,0x7aed50,0x7aed20,11,1,0x7b9978};return wrapper(m,i,g);}
std::uint32_t fun_006ab5e0(Memory& m,const Inputs& i) {constexpr Graph g{0x798274,0x7aeff8,0x7aefe8,0x7aefb8,11,1,0x7e05c0};return wrapper(m,i,g);}
} // namespace ra2::recovered::recovery_b383
