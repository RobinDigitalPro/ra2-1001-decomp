#pragma once
#define NOMINMAX
#include <windows.h>
#include "recovered/floating_b61_memory.hpp"
namespace ra2::recovered::b1641 {
using U=std::uint32_t;using Memory=global_b26::Memory;using Inputs=floating_b61::Inputs;
struct Api{HWND parent{};decltype(&::GetDlgItem)get_dlg_item=&::GetDlgItem;decltype(&::SendMessageA)send_message_a=&::SendMessageA;};
U fun_00575210(Memory&,const Inputs&,Api&);
}
