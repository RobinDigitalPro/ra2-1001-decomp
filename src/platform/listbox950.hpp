#pragma once
#define NOMINMAX
#include <windows.h>
#include "recovered/global_b26_memory.hpp"
#include <commctrl.h>
#include <cstdint>
namespace ra2::platform::b950 {
struct Event { unsigned api,msg,w,l,result; };
using Observer=void(*)(const Event&);
inline void set_observer(Observer);
inline void bind_imports(ra2::recovered::global_b26::Memory&);
inline HWND WINAPI get_dlg_item(HWND,int);
inline LRESULT WINAPI send_message(HWND,UINT,WPARAM,LPARAM);
}


#include <cstdint>
namespace ra2::platform::b950 {
inline Observer observer=nullptr;
inline void set_observer(Observer o){observer=o;}
inline HWND WINAPI get_dlg_item(HWND parent,int id){HWND result=::GetDlgItem(parent,id);if(observer)observer(Event{0,0x10000u,unsigned(id),unsigned(reinterpret_cast<std::uintptr_t>(parent)),unsigned(reinterpret_cast<std::uintptr_t>(result))});return result;}
inline LRESULT WINAPI send_message(HWND hwnd,UINT msg,WPARAM wp,LPARAM lp){LRESULT result=::SendMessageA(hwnd,msg,wp,lp);if(observer)observer(Event{unsigned(reinterpret_cast<std::uintptr_t>(hwnd)),unsigned(msg),unsigned(wp),unsigned(lp),unsigned(result)});return result;}
inline void bind_imports(ra2::recovered::global_b26::Memory&m){m.w32(0x0078549c,unsigned(reinterpret_cast<std::uintptr_t>(&get_dlg_item)));m.w32(0x007854a0,unsigned(reinterpret_cast<std::uintptr_t>(&send_message)));}
}
