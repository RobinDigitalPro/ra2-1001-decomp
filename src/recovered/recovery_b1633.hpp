#pragma once
#define NOMINMAX
#include <windows.h>
#include <array>
#include "recovered/floating_b61_memory.hpp"
#include "recovered/recovery_b979.hpp"
namespace ra2::recovered::b1633 {
using U=std::uint32_t;using Memory=global_b26::Memory;using Inputs=floating_b61::Inputs;using Heap=b979::Heap;
// Private finite draft. Fixture must supply the actual owned resource188
// HWNDs and genuine User32 forwarding observers; no substituted return values.
struct Api {
 U root_pre_call_S{}; // Authenticated pre-CALL bridge witness; never mapped/written.
 HWND parent{};std::array<HWND,16> controls{}; // 6D2..6E1 in order
 decltype(&::GetDlgItem) get_dlg_item=&::GetDlgItem;
 decltype(&::InvalidateRect) invalidate_rect=&::InvalidateRect;
};
U fun_005c3880(Memory&,const Inputs&,Heap&,Api&);
}
