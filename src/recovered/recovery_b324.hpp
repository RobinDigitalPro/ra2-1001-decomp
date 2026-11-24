#pragma once

#include "recovered/global_b26_memory.hpp"
#include "recovered/ini_multi.hpp"
#include "recovered/ini_text.hpp"

#include <cstdint>

namespace ra2::recovered::recovery_b324 {
using Memory = global_b26::Memory;
using Inputs = global_b26::Inputs;

// Projection of one already sorted raw x86 INI index. The portable INI
// routines operate on node views; this adapter writes only the original
// +0x10 cache node identity back to the guest index.
struct IndexProjection {
    std::uint32_t guest_index{};
    std::uint32_t guest_nodes{};
    IniIndex* logical{};
    IniIndexEntry* entries{};
    std::uint32_t count{};
    void flush(Memory&) const;
};

// Finite positive 0x69c30 route: one sorted section, one sorted key named by
// the original caller's key pointer, and a successful bounded three-decimal
// scan. Inputs follow the observed thiscall/stack contract: ECX is the INI
// receiver; arg[0..3] are out3, section, key, input3. `ini_graph` is the
// logical projection of raw receiver+0x20. Output and input are three bytes.
std::uint32_t rva_00069c30(Memory&, const Inputs&, IniIndex& ini_graph,
    const IndexProjection& section_index, const IndexProjection& key_index,
    const IniOperations&, const CrtClassification&);

// Raw receiver adapter for one already-sorted section and one key. It rebuilds
// the portable view from receiver+0x20 / section+0x2c and reads the actual
// single-byte CRT classification table through the guest Memory interface.
std::uint32_t fun_00469c30(Memory&, const Inputs&, const IniOperations&);
}
