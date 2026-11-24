#pragma once
#include "recovered/recovery_b161.hpp"
#include "recovered/recovery_b642.hpp"
namespace ra2::recovered::recovery_b1696 {
using U=std::uint32_t;
using Memory=floating_b61::Memory;using Inputs=floating_b61::Inputs;
inline constexpr U private_points=0x7e220000u;
struct Projection {
 U P{},map{},C{},A{},B{},N7{},initial_kind{};
 std::array<U,8> neighbors{};
 std::array<U,16> caller{};
};
struct Trace {
 U logical_ebp{},private_coord1{},private_coord2{},value1{},value2{};
 U first_eax{},second_eax{},first_calls{},second_calls{};
};
// Read-only finite-domain proof, including absence of public/private overlaps.
Projection preflight(Memory&,const Inputs&);
// Only selected flag180/type9..14 case4. Trace contains model addresses, not
// physical stack/ABI evidence. Both coordinate values are produced inside run.
U run(Memory&,const Inputs&,const Projection&,Trace* trace=nullptr);
}
