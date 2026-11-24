#include "recovery_b846.hpp"

#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b846 {
namespace {
using U = std::uint32_t;
constexpr U kIndexPtr = 0x0081a6c0u;
constexpr U kIndexCount = 0x0081a6c4u;
constexpr U kAlreadySorted = 0x0081a6ccu;
constexpr U kCachedEntry = 0x0081a6d0u;
constexpr U kVtableTrueFlag = 0x0078edd4u;
constexpr U kVtableFalse = 0x0078f3c4u;
constexpr U kFalseBody = 0x0051a3e0u;
constexpr U kTrueFlagBody = 0x0051ae40u;

void require(bool ok, const char* why) {
    if (!ok) throw std::domain_error(why);
}

U lookup_key(U key) {
    // `AND CH,0xf7` clears bit 11, then `AND BH,0xe8` clears bits 8-10
    // and bit 12 from the comparison key. The callback receives the value
    // after only the first mask, so modifier bits 8-10 remain observable.
    return key & ~0x00001f00u;
}
U callback_key(U key) { return key & ~0x00000800u; }
bool signed_less(U a, U b) { return global_b26::s32(a) < global_b26::s32(b); }

U dispatch_original_slot(Memory& m, U object, U key) {
    const U vtable = m.r32(object);
    const U target = m.r32(vtable + 0x14u);
    if (vtable == kVtableFalse && target == kFalseBody) return 0u;
    if (vtable == kVtableTrueFlag && target == kTrueFlagBody)
        return (callback_key(key) & 0x00000700u) != 0u ? 1u : 0u;
    throw std::domain_error("846 vptr/slot target is outside the two byte-backed original routes");
}
}

std::uint32_t fun_00480de0(Memory& m, const Inputs& in) {
    const U key = in.cx;
    const U compare = lookup_key(key);
    const U count = m.r32(kIndexCount);
    require(count >= 1u && count <= 8u,
            "846 finite contract requires a 1..8-entry hotkey index");
    const U rows = m.r32(kIndexPtr);
    require(rows != 0u, "846 hotkey index base is null");
    require(m.r8(kAlreadySorted) != 0u,
            "846 finite contract supplies an already sorted index and bypasses qsort");

    U entry = m.r32(kCachedEntry);
    if (entry == 0u || m.r32(entry) != compare) {
        U lo = 0u, hi = count;
        while (lo < hi) {
            const U mid = lo + ((hi - lo) >> 1u);
            const U candidate = rows + mid * 8u;
            if (signed_less(m.r32(candidate), compare)) lo = mid + 1u;
            else hi = mid;
        }
        require(lo < count, "846 case must hit the sorted hotkey index");
        entry = rows + lo * 8u;
        require(m.r32(entry) == compare,
                "846 case must hit an exact normalized hotkey key");
        m.w32(kCachedEntry, entry);
    }

    const U object = m.r32(entry + 4u);
    require(object != 0u, "846 selected command pointer is null");
    const U prevent = dispatch_original_slot(m, object, key);
    return prevent ? 0u : 1u; // Exact normalization of original `NEG AL; SBB EAX,EAX; INC EAX`.
}
}
