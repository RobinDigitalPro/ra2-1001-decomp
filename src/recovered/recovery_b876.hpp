#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"
#include <cstdint>
namespace ra2::recovered::recovery_b876 {
struct Eb750Case {std::uint32_t object{},ini_root{},country_text{},color_table{},color_object{},color_text{},section_scratch{},key_scratch{},value_scratch{};};
std::uint32_t write_absent(global_b26::Memory&,platform::ordinary_heap::Heap&,std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t);
std::uint32_t probe_section(global_b26::Memory&,platform::ordinary_heap::Heap&,std::uint32_t,std::uint32_t);
}

namespace ra2::recovered::recovery_b876 {std::uint32_t fun_0065a300(global_b26::Memory&,const global_b26::Inputs&,const Eb750Case&,platform::ordinary_heap::Heap&);}
