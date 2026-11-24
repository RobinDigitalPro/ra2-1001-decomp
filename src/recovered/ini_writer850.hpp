#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"
#include <cstdint>

namespace ra2::recovered::recovery_b850 {
// Private generalized semantic helper for the selected successful 0x10da40
// subset: one pre-existing root section with spare root-index capacity, then
// one fresh second section and distinct absent keys in either section. It is
// not a project API and is not yet covered by an accepted contract.
std::uint32_t write_absent(
    ra2::recovered::global_b26::Memory&,
    ra2::platform::ordinary_heap::Heap&,
    std::uint32_t root, std::uint32_t section_text,
    std::uint32_t key_text, std::uint32_t value_text);
}
