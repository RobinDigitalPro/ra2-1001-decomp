#pragma once
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include "platform/x87_state.hpp"
namespace ra2::platform::modal1436 {
// The actual OS call runs with the supplied guest numeric state. Capture its
// complete numeric result and restore the host state at the platform boundary.
inline BOOL end_dialog(std::uint32_t target,std::uint32_t dialog,ra2::platform::x87::State& state){
 using Function=BOOL(WINAPI*)(HWND,INT_PTR);
 const auto host=ra2::platform::x87::capture_host();
 ra2::platform::x87::restore_host(state.image);
 const BOOL result=reinterpret_cast<Function>(std::uintptr_t(target))(reinterpret_cast<HWND>(std::uintptr_t(dialog)),0x481);
 state.image=ra2::platform::x87::capture_host();
 ra2::platform::x87::restore_host(host);
 return result;
}
}
