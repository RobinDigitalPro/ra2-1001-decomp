#pragma once
#include "recovered/recovery_b566_machine.hpp"
namespace ra2::recovered::b1678 {
using Memory=ra2::recovered::floating_b61::Memory;
using State=ra2::recovered::recovery_b566::State;
using Frame=ra2::recovered::recovery_b566::Frame;
using ra2::recovered::recovery_b566::finish;
namespace integer=ra2::recovered::direct_b33::integer;
struct Operations {
 void* context=nullptr;
 unsigned(*allocate)(void*,Memory&,unsigned,ra2::platform::x87::State&)=nullptr;
};
// Finite fresh default-zero80-surface initialization; exact scope in B1678.
void run(Memory&,State&,Frame&,const Operations&);
}
