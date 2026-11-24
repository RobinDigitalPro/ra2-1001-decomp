#pragma once
#include "recovered/ini_bulk.hpp"
#include <array>

namespace ra2::recovered {
// Portable views of observed links, not original polymorphic C++ classes.
// Raw x86 node offsets: tag0, next4, previous8. Tags are original address words;
// they are never dereferenced as host virtual-function tables.
struct IniLink {
    std::uint32_t original_tag;
    IniLink* next;
    IniLink* previous;
};
struct IniLinkedList { std::uint32_t original_tag; IniLink head; IniLink tail; };
struct IniLinkedValue { IniLink link; std::array<std::uint32_t,7> words; };

struct IniMutationOperations {
    IniOperations lookup;
    // Original request is eight bytes per node, even on a 64-bit host. Return
    // storage for original_bytes/8 portable IniIndexEntry objects, or null.
    IniIndexEntry* (*allocate_entries)(std::uint32_t original_bytes, void*);
    // Called with old table (including null), or a list receiver when bit0 is
    // set. No payload destruction is implied. Callbacks must not modify index,
    // argument or link state, and must not throw. Original CRT heap is unrecovered.
    void (*release_storage)(void*, void*);
    void* context;
};
// Coherent tables: 0<=count<=capacity (the legacy field named spare). Successful
// growth requires readable count entries, disjoint new storage, no arithmetic
// wrap and enough storage. Input key/value pointers must survive allocation and
// release; aliasing a retired table during growth is excluded. No-growth append
// reads key, stores key, then reads/stores value, before incrementing count.
// Query may alias a table key; removal reads it after sorting and preserves the
// original midpoint duplicate selection. Only AL success/failure is modeled.
std::uint8_t fun_00510150(IniIndex&, const std::int32_t* key, void* const* value,
    const IniMutationOperations&);
std::uint8_t fun_00510360(IniIndex&, const std::int32_t* key, const IniOperations&);
// Negative amount returns false without touching index (null allowed there).
// Zero still allocates/copies/releases on success. Failure preserves index.
std::uint8_t fun_00510620(IniIndex*, std::int32_t amount, const IniMutationOperations&);

IniLink* fun_0040e160(IniLink&);
// Insert node after position, first detaching it if both links are non-null.
// All reached links must be writable; node cannot be null. Tag untouched.
IniLink* fun_0040e180(IniLink& position, IniLink& node);
// Copies the seven by-value original words into offsets12..36 in order
// [arg1,arg2,arg3,arg4,arg6,arg7,arg5]; pointer-like words stay encoded uint32.
IniLinkedValue* fun_0050ffb0(IniLinkedValue&, std::uint32_t,std::uint32_t,std::uint32_t,
    std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t);
// Initialization overwrites previous links without unlinking external nodes.
IniLinkedList* fun_00510000(IniLinkedList&);
// Requires a finite coherent sentinel list. Unlinks nodes without freeing their
// payloads/storage, resets observed tags, preserves the empty sentinel chain,
// then optionally releases only receiver for flags bit0. Return is receiver identity;
// caller must not dereference it after a real release. Other flag bits ignored.
IniLinkedList* fun_00510070(IniLinkedList&, std::uint32_t flags,const IniMutationOperations&);
}
