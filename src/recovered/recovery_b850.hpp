#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"
#include <cstdint>

namespace ra2::recovered::recovery_b850 {
struct Eb750Case {
    std::uint32_t object{}; // fixture storage for selected serializer fields
    std::uint32_t ini_root{};
    std::uint32_t country_text{};
    std::uint32_t color_table{};
    std::uint32_t color_object{};
    std::uint32_t color_text{};
    std::uint32_t section_scratch{};
    std::uint32_t key_scratch{};
    std::uint32_t value_scratch{};
};

// Private bounded translation proposal for original RVA 0xeb750. Its direct
// callees remain real in the original differential; this model expands their
// byte-reviewed finite effects into ordered calls to draft_writer850.
std::uint32_t serialize_eb750(
    ra2::recovered::global_b26::Memory&,
    const Eb750Case&,
    ra2::platform::ordinary_heap::Heap&);
}

namespace ra2::recovered::recovery_b850 {std::uint32_t fun_004eb750(global_b26::Memory&,const global_b26::Inputs&,const Eb750Case&,platform::ordinary_heap::Heap&);}
