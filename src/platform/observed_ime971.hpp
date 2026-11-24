#pragma once
#define NOMINMAX
#include <windows.h>
#include <cstdint>
#include <vector>
namespace ra2::platform::ime971 {
struct Event{HWND hwnd;UINT message;WPARAM w;LPARAM l;LRESULT result;bool operator==(const Event&o)const{return hwnd==o.hwnd&&message==o.message&&w==o.w&&l==o.l&&result==o.result;}bool operator!=(const Event&o)const{return !(*this==o);}};
inline std::vector<Event>&trace(){static std::vector<Event>v;return v;}
inline LRESULT WINAPI forward(HWND h,UINT msg,WPARAM w,LPARAM l){const auto r=::DefWindowProcA(h,msg,w,l);trace().push_back({h,msg,w,l,r});return r;}
inline std::uint32_t address(){return std::uint32_t(reinterpret_cast<std::uintptr_t>(&forward));}
}
