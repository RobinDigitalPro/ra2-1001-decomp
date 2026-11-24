#pragma once
#include "recovered/recovery_b1100.hpp"
#include "recovered/floating_b61_memory.hpp"
#include "recovered/ini_integer.hpp"
#include "recovered/ini_components.hpp"
#include <array>
#include <cstdint>
#include <vector>
namespace ra2::recovered::b1508 {
using U=std::uint32_t;using Memory=global_b26::Memory;using Inputs=floating_b61::Inputs;
using Heap=b1100::Heap;using Api=b1100::Api;using Clock=b1100::Clock;
struct Runtime {U actual_entry_s{};U locale_initial_flag{};const CrtClassification*classification{};};
// Wrapper ownership only: the unchanged B1100 constructor has its own34 owners.
struct Owner {U address{},requested{},rounded{};bool released{};U actual_free_result{};std::vector<std::uint8_t>raw;};
struct Observation {std::vector<Owner>owners;std::vector<U>free_order;U id{},loop{},rate{},final_owner{};std::array<U,2>point{};std::array<U,4>rectangle{};U final_section_cache{},final_key_cache{};b1100::Observation constructor;};
// Positive original DE9E0: coherent borrowed4-key ID/Image/Palette/ActiveRect;
// missingOrigin/Loop/Rate; actualB1100 cachedSHP12B/physicalWHOLE.PAL9B domain.
// Callerword1 at actualS+8 endszero; fullEAX is the actual new40B owner.
U fun_004de9e0(Memory&,const Inputs&,Heap&,Api&,Clock,const Runtime&,Observation&);
}
