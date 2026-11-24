#pragma once
#define NOMINMAX
#include <windows.h>
#include <cstdint>
#include <vector>
namespace ra2::platform::control978 {
struct Event{std::uint32_t hwnd;int result;bool operator==(const Event&o)const{return hwnd==o.hwnd&&result==o.result;}};
inline std::vector<Event>&trace(){static std::vector<Event>v;return v;}
inline void reset(){trace().clear();}
inline std::uint32_t ptr(const void*p){return std::uint32_t(reinterpret_cast<std::uintptr_t>(p));}
inline int WINAPI id(HWND h){const int result=::GetDlgCtrlID(h);trace().push_back({ptr(h),result});return result;}
inline std::uint32_t address(){static_assert(sizeof(void*)==4);return ptr(reinterpret_cast<void*>(&id));}
}
