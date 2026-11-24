#pragma once
#include "recovered/recovery_b794_machine.hpp"
namespace ra2::recovered::b1679 {
using Memory=floating_b61::Memory;
using State=recovery_b794::State;
using Frame=recovery_b794::Frame;
struct Operations{void*context;void(*api)(void*,unsigned,Memory&,State&,Frame&);};
// Finite owned-window/cached-sprite route at217BE0. The four platform APIs
// require real owned providers; unselected dialog/collection paths are excluded.
void run(Memory&,State&,Frame&,const Operations&);
}
