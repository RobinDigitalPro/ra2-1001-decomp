#pragma once

#include "recovered/floating_b61_memory.hpp"
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b851 {
using Memory = ra2::recovered::global_b26::Memory;
using Inputs = ra2::recovered::floating_b61::Inputs;
using U = std::uint32_t;

constexpr U root_rva = 0x0012fa20u;
constexpr U aircraft_vptr = 0x0078612cu;
constexpr U cell_vptr = 0x00788b04u;
constexpr U aircraft_set_target = 0x006bf0c0u; // actual AircraftClass slot +0x370
constexpr U aircraft_set_state = 0x0041b160u; // actual AircraftClass slot +0x1d0
constexpr U set_state_helper = 0x00591ab0u;

// Finite composition of the actual original callback paths reached by this
// contract. These routines are not substitutes for arbitrary virtual calls:
// the original vptr/slot bytes and each branch precondition are pinned in the
// accompanying dependency_spec.json.
inline U reached_set_target_cell(Memory& memory, U aircraft, U target) {
    if (memory.r32(aircraft) != aircraft_vptr)
        throw std::domain_error("B851 requires the original AircraftClass primary vptr");

    const U prior_target = memory.r32(aircraft + 0x228u);
    memory.w8(aircraft + 0x404u, 0u);
    if (target == prior_target || target == 0u || target == aircraft)
        throw std::domain_error("B851 positive route requires a distinct non-null cell target");

    const U flags = memory.r8(target + 0x14u);
    if ((flags & 0x02u) != 0u)
        throw std::domain_error("B851 excludes original SetTarget flag-bit-1 path");

    memory.w32(aircraft + 0x228u, target);

    // The actual 0x6bf0c0 body tests these fields after storing +0x228.
    // Zero avoids its unrelated 0x67fb90 and +0x354/+0xf0 callback routes.
    if (memory.r32(aircraft + 0x238u) != 0u || memory.r32(aircraft + 0x25cu) != 0u)
        throw std::domain_error("B851 excludes aircraft target side-effect subobject routes");
    return memory.r32(aircraft + 0x25cu);
}

inline U reached_set_state(Memory& memory, U aircraft, U arg1, U arg2) {
    if (memory.r32(aircraft) != aircraft_vptr || arg1 != 1u || arg2 != 0u)
        throw std::domain_error("B851 requires original AircraftClass slot +0x1d0 with arguments (1,0)");

    // Original target 0x41b160 calls 0x591ab0 on this path. The real helper
    // returns immediately for [aircraft+0x98] == 0x13, before any field write
    // or follow-on virtual call.
    if (memory.r32(aircraft + 0x98u) != 0x13u)
        throw std::domain_error("B851 excludes 0x591ab0 follow-on state routes");
    return 1u;
}

inline U fun_0052fa20(Memory& memory, const Inputs& inputs) {
    const U root = inputs.cx;
    const U start = memory.r32(root);
    const U interval = memory.r32(root + 8u);
    if (start != 0xffffffffu || interval != 0u)
        throw std::domain_error("B851 contract requires the finite timer-ready sentinel route");

    const U current_frame = memory.r32(0x00a2896cu);
    memory.w32(root, current_frame);
    memory.w32(root + 4u, inputs.stack_minus8);
    memory.w32(root + 8u, 0x1eu);

    const U count = memory.r32(root + 0x1cu);
    const U array = memory.r32(root + 0x10u);
    if (count != 1u || array == 0u)
        throw std::domain_error("B851 contract requires one initialized list node");

    const U node = memory.r32(array);
    if (node == 0u)
        throw std::domain_error("B851 list node pointer must be non-null");
    const U aircraft = memory.r32(node);
    const U target_cell = memory.r32(node + 4u);
    if (aircraft == 0u || target_cell == 0u || aircraft == target_cell)
        throw std::domain_error("B851 requires distinct non-null aircraft and cell pointers");
    if (memory.r32(target_cell) != cell_vptr)
        throw std::domain_error("B851 target must carry the original CellClass primary vptr");

    memory.w32(aircraft + 0x254u, 1u);
    (void)reached_set_target_cell(memory, aircraft, target_cell);
    (void)reached_set_state(memory, aircraft, 1u, 0u);

    // Original 0x52fa20 reloads the list count into EAX before the loop test
    // and returns with that value on the one-entry route.
    return count;
}
} // namespace kamikaze851
