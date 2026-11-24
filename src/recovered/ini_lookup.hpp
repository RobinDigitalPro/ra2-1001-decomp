#pragma once

#include <cstddef>
#include <cstdint>

namespace ra2::recovered {

// Portable state views, NOT declarations of original classes or x86 layouts.
// Original index: table+0, signed count+4, sorted byte+12, cached node+16;
// nodes contain a signed 32-bit identifier and a pointer (eight bytes on x86).
struct IniIndexEntry {
    std::int32_t key;
    void* value;
};
struct IniIndex {
    IniIndexEntry* entries;
    std::int32_t count;
    std::uint8_t sorted;
    IniIndexEntry* cached;
    std::uint32_t spare = 0; // Legacy label: original +8 is capacity in mutation routines.
};
struct IniKeyNode {
    IniKeyNode* next;
    IniKeyNode* previous;
    const std::uint8_t* name;
};
struct IniSection {
    IniIndex keys; // Original key index begins at section+0x2c.
    IniKeyNode* first = nullptr; // Original linked-list head pointer at +0x18.
};
struct IniValue { const std::uint8_t* text; }; // Original text pointer at value+0x10.
enum class IniIndexKind { sections, entries };

// name_hash.hpp supplies ini_name_hash for RVA 0x93da0 with fresh zero state.
// Sort RVA 0x36d686 with the appropriate original comparator, and uppercase
// RVA 0x36e313 remain explicit dependencies; this API does not recover them.
struct IniOperations {
    std::uint32_t (*hash_name)(const std::uint8_t*, std::size_t, void*);
    void (*sort_nodes)(IniIndexEntry*, std::int32_t, IniIndexKind, void*);
    std::int32_t (*uppercase)(std::int32_t, void*);
    void* context;
    IniSection* missing_section; // Original global at VA 0xb10aac.
    IniValue* missing_value;     // Original global at VA 0xb10ab0.
};

// count must be nonnegative; nonempty tables and non-null cached nodes must be
// readable. A nonzero sorted byte asserts signed ascending order. sort_nodes
// must permute whole nodes in place as the supplied original sorting dependency
// would, including duplicate ordering. It must not mutate unrelated state.
// Query pointers may alias table keys: the original reads them AFTER sorting.
// Search clears cache only when sorting, does not cache the returned node, and
// leaves a nonzero sorted byte unchanged. Empty indexes touch no table/query.
IniIndexEntry* fun_005106d0(IniIndex&, const std::int32_t* query, const IniOperations&);
IniIndexEntry* fun_005105a0(IniIndex&, const std::int32_t* query, const IniOperations&);

// Membership uses a matching cached node before considering sorted state.
// Only AL is an observed result; high EAX bits are intentionally unspecified.
std::uint8_t fun_00510220(IniIndex&, const std::int32_t* query, const IniOperations&);

// Original RVA 0x10e860: section_index adapts receiver+0x20. Node values must
// resolve to the corresponding IniSection/IniValue views. Names are readable
// NUL-terminated bytes; callbacks must exist whenever reached. A null name
// returns the EXACT default byte without touching section_index or callbacks.
// The final value's first byte is sign-extended before uppercase. Neither a
// class identity nor an ABI-compatible interface is claimed. Pointer wraparound,
// malformed memory, concurrent state mutation and negative counts are excluded.
std::uint8_t fun_0050e860(IniIndex* section_index,
                        const std::uint8_t* section, const std::uint8_t* key,
                        std::uint8_t default_value, const IniOperations&);

} // namespace ra2::recovered
