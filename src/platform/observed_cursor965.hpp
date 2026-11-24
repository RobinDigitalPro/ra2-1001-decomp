#pragma once
#define NOMINMAX
#include <windows.h>
#include <cstdint>
#include <vector>
namespace ra2::platform::cursor965 {
struct Event{BOOL input;int result;bool operator==(const Event&o)const{return input==o.input&&result==o.result;}bool operator!=(const Event&o)const{return !(*this==o);}};
inline std::vector<Event>&trace(){static std::vector<Event>v;return v;}
inline int WINAPI show(BOOL visible){auto r=::ShowCursor(visible);trace().push_back({visible,r});return r;}
inline std::uint32_t address(){return std::uint32_t(reinterpret_cast<std::uintptr_t>(&show));}
}
