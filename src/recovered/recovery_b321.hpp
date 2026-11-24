#pragma once

#include "recovered/global_b26_memory.hpp"
#include "recovered/ini_integer.hpp"
#include "recovered/ini_lookup.hpp"
#include "recovered/ini_text.hpp"

#include <cstdint>

namespace ra2::recovered::recovery_b321 {
using Memory = global_b26::Memory;
using Inputs = global_b26::Inputs;

// Projection for one already-sorted original raw index. The entries pointer
// names the logical node view backed by raw_table; cache writeback preserves
// original 32-bit node identities and never claims host pointers are ABI data.
struct IndexProjection {
    std::uint32_t guest_index{};
    std::uint32_t guest_table{};
    IniIndex* logical{};
    IniIndexEntry* entries{};
    std::uint32_t count{};
    void flush_cache(Memory&) const;
};

// Bounded orchestration for the concrete Map fixture. `section_graph` is the
// accepted logical projection of raw INI receiver+0x20 and its one Map section;
// `root_index` describes the section index and `key_index` its five-key index.
// The inputs retain the raw guest receiver needed by original Block111 Side.
std::uint32_t fun_006dca40(Memory&, const Inputs&);
std::uint32_t rva_002dca40(Memory&, const Inputs&, IniIndex& section_graph,
    const IndexProjection& root_index, const IndexProjection& key_index,
    const IniOperations&, const IntegerReadOperations&);

// Raw receiver adapter for the concrete one-section/five-key fixture. It
// rebuilds stack-local portable views from the raw guest index nodes and their
// value text pointers, calls the orchestration above, and projects cache node
// identities back to the original raw index fields.
std::uint32_t fun_006dca40(Memory&, const Inputs&, const IniOperations&,
    const IntegerReadOperations&);
}
