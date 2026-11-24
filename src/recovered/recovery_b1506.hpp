#pragma once
#include "recovered/floating_b61_memory.hpp"
#include "recovered/recovery_b979.hpp"
#include <array>
#include <cstdint>
namespace ra2::recovered::b1506 {
using U=std::uint32_t;using Memory=floating_b61::Memory;using Inputs=floating_b61::Inputs;using Heap=b979::Heap;
namespace fp=platform::x87;
// Typed semantic trace, not native API telemetry. Close has no return contract:
// its result=0 is a model void placeholder, never an observed native EAX.
struct FileEvent {U slot{},argument0{},argument1{},result{},position{};};
struct Observation {
 std::array<U,3> owners{};std::array<FileEvent,7> file_events{};U event_count{},constructor_calls{};
 fp::Image actual_provider_prefix_fp{};U prefix_fs_head{},prefix_fs_selector{};
};
// Standalone exact30DD20 positive MemFile route; original ctor/CCFile callers
// are not recovered by this contract. Inputs.fp is an explicit model distinct
// from actual typed-provider hardware FP, which the fixture captures separately.
U fun_0070dd20(Memory&,const Inputs&,Heap&,Observation&);
}
