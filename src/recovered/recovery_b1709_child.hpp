#pragma once
#include "recovery_b1709.hpp"
namespace ra2::recovered::recovery_b1709 {
// Private new-domain projection. Existing accepted B1708 remains unchanged.
void execute_score(Memory&,State&,Frame&);
void execute_surface(Memory&,State&,Frame&);
void execute_renderer(Memory&,State&,Frame&);
void require_child_warm_basis(const Memory&,const State&,const Frame&);
// root_6c7f40 is declared by the real parent interface; no dummy child.
}
