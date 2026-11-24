#pragma once
#include "recovered/floating_b61_memory.hpp"
#include "platform/ordinary_heap.hpp"
#include "recovered/ini_integer.hpp"
#include "recovered/ini_components.hpp"
#include <array>
#include <cstdint>
#include <vector>
namespace ra2::recovered::b1502 {
using U=std::uint32_t;using Memory=floating_b61::Memory;using Inputs=floating_b61::Inputs;using Heap=platform::ordinary_heap::Heap;
struct Runtime {U actual_entry_s{};U locale_initial_flag{};const CrtClassification*classification{};};
struct Owner {U address{},requested{},rounded{};bool released{};U actual_free_result{};std::vector<std::uint8_t>raw;};
struct Observation {std::vector<Owner>owners;std::vector<U>free_order;U final_owner{},empty_select_vq{},id{};std::array<U,4>rectangle{};U final_section_cache{},final_key_cache{};};
// Exact finite DEEA0 producer: borrowed coherent one-section/two-key sorted
// ID/ActiveRect graph, decimal ID, complete nondegenerate4CSV, missing Origin
// and five optional names. Actual callerword1=S+8 is written through Memory.
U fun_004deea0(Memory&,const Inputs&,Heap&,const Runtime&,Observation&);
}
