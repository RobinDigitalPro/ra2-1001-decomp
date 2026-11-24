#pragma once
#include "recovered/recovery_b566_machine.hpp"
namespace ra2::recovered::b1659 {
using Memory=global_b26::Memory;using State=recovery_b566::State;namespace fp=platform::x87;
// Context binds one genuinely owned HWND and frozen actual User32 identities.
// Callbacks perform actual SDK calls, returning actualEAX/observedguestFP.
struct Operations{
 void*window_context=nullptr;
 unsigned client_to_screen_target=0,def_window_proc_target=0;
 unsigned(*client_to_screen)(void*,Memory&,unsigned actual_target,unsigned child_entry,fp::State&)=nullptr;
 unsigned(*def_window_proc)(void*,Memory&,unsigned actual_target,unsigned child_entry,fp::State&)=nullptr;
};
struct NativeState{unsigned ax,cx,dx,bx,bp,si,di,flags;};
struct Result{unsigned eax;State state;std::array<unsigned,16>words;};
Result run(Memory&,unsigned entry,unsigned char*storage,unsigned size,const NativeState&,const fp::Image&,const Operations&);
}
