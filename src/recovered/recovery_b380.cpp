#include "recovery_b380.hpp"

#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b380 {
namespace {
using ra2::recovered::global_b26::s32;
constexpr std::uint32_t kVptr = 0x0078612cu;
constexpr std::uint32_t kCol = 0x0079e500u;
constexpr std::uint32_t kChd = 0x0079e4f0u;
constexpr std::uint32_t kBca = 0x0079e4a0u;
constexpr std::uint32_t kSource = 0x007b91d0u;
constexpr std::uint32_t kObject = 0x007b94d8u;
constexpr std::uint32_t kFoot = 0x007b9558u;
constexpr std::uint32_t kAircraft = 0x007b9570u;
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
    throw std::domain_error("B380 requires a NUL-terminated original type name within 256 bytes");
}

std::uint32_t zero_offset_top(Memory& m, std::uint32_t object) {
    const auto vptr = m.r32(object);
    require(vptr == kVptr, "B380 object must use pinned vptr 0x78612c");
    const auto col = m.r32(vptr - 4u);
    require(col == kCol, "B380 object must use pinned COL 0x79e500");
    require(m.r32(col + 4u) == 0u && m.r32(col + 8u) == 0u,
            "B380 supports only the pinned zero COL offsets");
    return object;
}

std::uint32_t first_pass_target(Memory& m, std::uint32_t source_type,
                                std::uint32_t target_type,
                                std::uint32_t source_delta) {
    require(source_type == kSource, "B380 source descriptor must be AbstractClass");
    require(target_type == kObject || target_type == kFoot || target_type == kAircraft,
            "B380 target descriptor is outside the three selected wrapper routes");
    require(m.r32(kCol + 16u) == kChd, "B380 expected pinned CHD 0x79e4f0");
    require(m.r32(kChd + 4u) == 5u && m.r32(kChd + 8u) == 18u &&
            m.r32(kChd + 12u) == kBca,
            "B380 requires the pinned 18-entry CHD/BCA profile");

    // This is only the original 0x36f800 first pass: find a target candidate,
    // then its source in the candidate's contained-base range. The second
    // target-only/public pass is deliberately excluded from B380.
    for (std::uint32_t n = 0; n < 18u; ++n) {
        const auto outer = m.r32(kBca + 4u * n);
        if (!same_type_name(m, m.r32(outer), target_type)) continue;
        const auto contained = m.r32(outer + 4u);
        require(contained != 0u && n + contained < 18u,
                "B380 target BCD subtree exceeds the pinned BCA");
        for (std::uint32_t k = 0; k < contained; ++k) {
            const auto child = m.r32(kBca + 4u * (n + 1u + k));
            if (!same_type_name(m, m.r32(child), source_type)) continue;
            const auto mdisp = m.r32(child + 8u);
            const auto pdisp = s32(m.r32(child + 12u));
            const auto vdisp = m.r32(child + 16u);
            require(mdisp == 0u && pdisp == -1 && vdisp == 0u,
                    "B380 source BCD must have pinned PMD {0,-1,0}");
            if (mdisp == source_delta) return outer;
        }
    }
    throw std::domain_error("B380 positive fixture did not reach first-pass source-in-target match");
}

std::uint32_t cast_root(Memory& m, const Inputs& i) {
    // Raw x86 stack parameters at [EBP+8..18]: object, vfDelta, source,
    // target, isReference. Entry ECX/EDX are not inputs on this route.
    const auto object = i.arg[0];
    const auto vf_delta = i.arg[1];
    const auto source_type = i.arg[2];
    const auto target_type = i.arg[3];
    const auto is_reference = i.arg[4];
    require(object != 0u, "B380 positive cast excludes null objects");
    require(vf_delta == 0u && is_reference == 0u,
            "B380 supports only vfDelta=0 and pointer-cast mode");
    const auto complete = zero_offset_top(m, object);

    // 0x76f67d stores object-vfDelta over the root's first stack argument.
    // The selected contract fixes vfDelta=0, so the observed value remains
    // the caller-supplied object pointer.
    i.arg[0] = object - vf_delta;
    const auto source_delta = i.arg[0] - complete;
    const auto selected = first_pass_target(m, source_type, target_type, source_delta);
    const auto mdisp = m.r32(selected + 8u);
    const auto pdisp = s32(m.r32(selected + 12u));
    const auto vdisp = m.r32(selected + 16u);
    require(mdisp == 0u && pdisp == -1 && vdisp == 0u,
            "B380 target PMD must be pinned {0,-1,0}");
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
    throw std::domain_error("B380 positive wrapper fixture requires a sorted-key hit");
}

std::uint32_t wrapper(Memory& m, const Inputs& i, std::uint32_t target_type) {
    const auto receiver = i.cx;
    require(m.r8(receiver + 4u) == 0x34u, "B380 wrapper requires tag 0x34");
    const auto key = m.r32(receiver);
    const auto count = m.r32(kCount);
    require(count >= 1u && count <= 7u,
            "B380 wrapper requires an initialized 1..7 row registry");
    const auto table = m.r32(kRegistry);
    auto row = m.r32(kCache);
    if (row && m.r32(row) != key) row = 0;
    if (!row) {
        require(m.r8(kInitialized) != 0u,
                "B380 excludes original registry initialization route");
        row = inline_wrapper_search(m, table, count, key);
        m.w32(kCache, row);
    }

    const auto object = m.r32(row + 4u);
    Inputs nested = i;
    nested.arg[0] = object;
    nested.arg[1] = 0u;
    nested.arg[2] = kSource;
    nested.arg[3] = target_type;
    nested.arg[4] = 0u;
    return cast_root(m, nested);
}
} // namespace

std::uint32_t fun_0076f624(Memory& m, const Inputs& i) { return cast_root(m, i); }
std::uint32_t fun_006ab030(Memory& m, const Inputs& i) { return wrapper(m, i, kObject); }
std::uint32_t fun_006ab100(Memory& m, const Inputs& i) { return wrapper(m, i, kFoot); }
std::uint32_t fun_006abb90(Memory& m, const Inputs& i) { return wrapper(m, i, kAircraft); }
} // namespace ra2::recovered::recovery_b380
