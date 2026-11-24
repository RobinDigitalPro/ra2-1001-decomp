#pragma once
#include "recovered/recovery_b1264.hpp"
namespace ra2::recovered::b1682 {
using Memory=b1264::Memory;using Inputs=b1264::Inputs;using State=b1264::State;
struct Observation{std::uint64_t percentage{};unsigned prefix_status{},helper_result{};};
// Private positive finite route; no compilation/execution/acceptance GO.
unsigned run(Memory&,const Inputs&,State&,Observation&);
unsigned run(Memory&,const Inputs&,State&);
}
