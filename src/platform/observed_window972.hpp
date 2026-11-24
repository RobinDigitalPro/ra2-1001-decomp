#pragma once
#define NOMINMAX
#include <windows.h>
#include <array>
#include <cstdint>
#include <vector>
namespace ra2::platform::window_api_b972 {
enum class Api:std::uint32_t { get_window_long=1, child_window_from_point=2, client_to_screen=3, get_window_rect=4 };
struct Event {Api api{};std::uint32_t hwnd{},result{};std::int32_t index{};POINT point_before{},point_after{};RECT rect{};bool buffer{};bool operator==(const Event&o)const{return api==o.api&&hwnd==o.hwnd&&result==o.result&&index==o.index&&point_before.x==o.point_before.x&&point_before.y==o.point_before.y&&point_after.x==o.point_after.x&&point_after.y==o.point_after.y&&rect.left==o.rect.left&&rect.top==o.rect.top&&rect.right==o.rect.right&&rect.bottom==o.rect.bottom&&buffer==o.buffer;}bool operator!=(const Event&o)const{return !(*this==o);}};
using Trace=std::vector<Event>;inline Trace&events(){static Trace e;return e;}inline void reset(){events().clear();}inline const Trace&trace(){return events();}
inline std::uint32_t narrow(HWND h){return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(h));}
inline LONG WINAPI get_window_long(HWND h,int index){const LONG v=::GetWindowLongA(h,index);Event e{};e.api=Api::get_window_long;e.hwnd=narrow(h);e.index=index;e.result=static_cast<std::uint32_t>(v);events().push_back(e);return v;}
inline HWND WINAPI child_window_from_point(HWND h,POINT p){const HWND v=::ChildWindowFromPoint(h,p);Event e{};e.api=Api::child_window_from_point;e.hwnd=narrow(h);e.point_before=p;e.result=narrow(v);events().push_back(e);return v;}
inline BOOL WINAPI client_to_screen(HWND h,LPPOINT p){Event e{};e.api=Api::client_to_screen;e.hwnd=narrow(h);e.buffer=p!=nullptr;if(p)e.point_before=*p;const BOOL ok=::ClientToScreen(h,p);e.result=static_cast<std::uint32_t>(ok);if(p)e.point_after=*p;events().push_back(e);return ok;}
inline BOOL WINAPI get_window_rect(HWND h,LPRECT p){Event e{};e.api=Api::get_window_rect;e.hwnd=narrow(h);e.buffer=p!=nullptr;const BOOL ok=::GetWindowRect(h,p);e.result=static_cast<std::uint32_t>(ok);if(p)e.rect=*p;events().push_back(e);return ok;}
inline std::uint32_t get_window_long_address(){return narrow(reinterpret_cast<HWND>(&get_window_long));}
inline std::uint32_t child_window_from_point_address(){return narrow(reinterpret_cast<HWND>(&child_window_from_point));}
inline std::uint32_t client_to_screen_address(){return narrow(reinterpret_cast<HWND>(&client_to_screen));}
inline std::uint32_t get_window_rect_address(){return narrow(reinterpret_cast<HWND>(&get_window_rect));}
inline bool valid_trace(const Trace&t){if(t.size()!=6)return false;const auto convert=(t[1].result==t[3].result)?t[1].result:t[2].result;return t[0].api==Api::get_window_long&&t[0].index==-8&&t[0].result!=0&&t[1].api==Api::child_window_from_point&&t[1].hwnd==t[0].result&&t[1].result!=0&&t[2].api==Api::get_window_long&&t[2].index==-8&&t[2].hwnd==t[1].result&&t[3].api==Api::get_window_long&&t[3].index==-8&&t[3].hwnd==t[0].hwnd&&t[3].result==t[0].result&&t[4].api==Api::client_to_screen&&t[4].result&&t[4].buffer&&t[4].hwnd==convert&&t[5].api==Api::get_window_rect&&t[5].result&&t[5].buffer&&t[5].hwnd==t[1].result;}
}
