#pragma once
#include "recovery_b1701.hpp"
namespace ra2::recovered::recovery_b1701::helpers {
// Caller already pushed genuine arguments. Each entry owns CALL/childFrame,
// real callee RET cleanup and caller.sp publication. No replacement results.
void pick(Memory&,State&,Frame&,U continuation);
void map_cell(Memory&,State&,Frame&,U continuation);
}
