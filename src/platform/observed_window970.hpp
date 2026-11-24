#pragma once
#define NOMINMAX
#include <windows.h>
#include <array>
#include <cstdint>
#include <vector>
namespace ra2::platform::window_api_b970 {
enum class Api : std::uint32_t { get_parent=1, get_window_rect=2, move_window=3 };
struct Event { Api api{}; std::uint32_t hwnd{}, parent{}; std::array<std::int32_t,4> rect{}; std::int32_t x{},y{},cx{},cy{},repaint{},result{}; bool buffer{}; bool operator==(const Event&o)const{return api==o.api&&hwnd==o.hwnd&&parent==o.parent&&rect==o.rect&&x==o.x&&y==o.y&&cx==o.cx&&cy==o.cy&&repaint==o.repaint&&result==o.result&&buffer==o.buffer;}bool operator!=(const Event&o)const{return !(*this==o);} };
using Trace=std::vector<Event>;
inline Trace& events(){static Trace e;return e;} inline void reset(){events().clear();} inline const Trace& trace(){return events();}
inline std::uint32_t narrow(HWND h){return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(h));}
inline HWND WINAPI get_parent(HWND h){HWND p=::GetParent(h);Event e{};e.api=Api::get_parent;e.hwnd=narrow(h);e.parent=narrow(p);e.result=p!=nullptr;events().push_back(e);return p;}
inline BOOL WINAPI get_window_rect(HWND h,LPRECT r){const BOOL ok=::GetWindowRect(h,r);Event e{};e.api=Api::get_window_rect;e.hwnd=narrow(h);e.buffer=r!=nullptr;e.result=ok;if(r)e.rect={r->left,r->top,r->right,r->bottom};events().push_back(e);return ok;}
inline BOOL WINAPI move_window(HWND h,int x,int y,int cx,int cy,BOOL repaint){const BOOL ok=::MoveWindow(h,x,y,cx,cy,repaint);Event e{};e.api=Api::move_window;e.hwnd=narrow(h);e.x=x;e.y=y;e.cx=cx;e.cy=cy;e.repaint=repaint;e.result=ok;events().push_back(e);return ok;}
inline std::uint32_t get_parent_address(){return narrow(reinterpret_cast<HWND>(&get_parent));}
inline std::uint32_t get_window_rect_address(){return narrow(reinterpret_cast<HWND>(&get_window_rect));}
inline std::uint32_t move_window_address(){return narrow(reinterpret_cast<HWND>(&move_window));}
inline bool valid_trace(const Trace&t){return t.size()==4&&t[0].api==Api::get_parent&&t[0].result&&t[0].parent&&t[1].api==Api::get_window_rect&&t[1].result&&t[1].buffer&&t[1].hwnd==t[0].parent&&t[2].api==Api::get_window_rect&&t[2].result&&t[2].buffer&&t[2].hwnd==t[0].hwnd&&t[3].api==Api::move_window&&t[3].result&&t[3].hwnd==t[0].hwnd&&t[3].repaint==FALSE;}
}
