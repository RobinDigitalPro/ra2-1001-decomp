#pragma once
#define NOMINMAX
#include <windows.h>
#include <array>
#include <cstdint>
#include <vector>
namespace ra2::platform::window_api_b953 {
enum class Api:std::uint32_t {get_client_rect=1,client_to_screen=2,set_window_pos=3};
struct Event {Api api{};std::uint32_t hwnd{},insert_after{},flags{};std::array<std::int32_t,4> before{},after{};std::int32_t x{},y{},cx{},cy{},result{};bool buffer_nonnull{};friend bool operator==(const Event&,const Event&)=default;};
using Trace=std::vector<Event>;inline Trace& events(){static Trace e;return e;}inline void reset(){events().clear();}inline const Trace& trace(){return events();}
inline std::uint32_t narrow(HWND h){return std::uint32_t(reinterpret_cast<std::uintptr_t>(h));}
inline BOOL WINAPI get_client_rect(HWND h,LPRECT r){const BOOL ok=::GetClientRect(h,r);Event e{};e.api=Api::get_client_rect;e.hwnd=narrow(h);e.result=ok;e.buffer_nonnull=r!=nullptr;if(r)e.after={r->left,r->top,r->right,r->bottom};events().push_back(e);return ok;}
inline BOOL WINAPI client_to_screen(HWND h,LPPOINT p){Event e{};e.api=Api::client_to_screen;e.hwnd=narrow(h);e.buffer_nonnull=p!=nullptr;if(p)e.before={p->x,p->y,0,0};const BOOL ok=::ClientToScreen(h,p);e.result=ok;if(p)e.after={p->x,p->y,0,0};events().push_back(e);return ok;}
inline BOOL WINAPI set_window_pos(HWND h,HWND after,int x,int y,int cx,int cy,UINT flags){const BOOL ok=::SetWindowPos(h,after,x,y,cx,cy,flags);Event e{};e.api=Api::set_window_pos;e.hwnd=narrow(h);e.insert_after=narrow(after);e.x=x;e.y=y;e.cx=cx;e.cy=cy;e.flags=flags;e.result=ok;events().push_back(e);return ok;}
inline std::uint32_t get_client_rect_address(){return narrow(reinterpret_cast<HWND>(&get_client_rect));}inline std::uint32_t client_to_screen_address(){return narrow(reinterpret_cast<HWND>(&client_to_screen));}inline std::uint32_t set_window_pos_address(){return narrow(reinterpret_cast<HWND>(&set_window_pos));}
inline bool valid_trace(const Trace&t){if(t.size()!=7)return false;const auto&g0=t[0];const auto&a0=t[1];const auto&b0=t[2];const auto&g1=t[3];const auto&a1=t[4];const auto&b1=t[5];const auto&s=t[6];return g0.api==Api::get_client_rect&&a0.api==Api::client_to_screen&&b0.api==Api::client_to_screen&&g1.api==Api::get_client_rect&&a1.api==Api::client_to_screen&&b1.api==Api::client_to_screen&&s.api==Api::set_window_pos&&g0.result&&a0.result&&b0.result&&g1.result&&a1.result&&b1.result&&s.result&&g0.buffer_nonnull&&g1.buffer_nonnull&&a0.buffer_nonnull&&a1.buffer_nonnull&&b0.buffer_nonnull&&b1.buffer_nonnull&&g0.hwnd==a0.hwnd&&g0.hwnd==b0.hwnd&&g1.hwnd==a1.hwnd&&g1.hwnd==b1.hwnd&&g0.hwnd!=g1.hwnd&&a0.before[0]==g0.after[0]&&a0.before[1]==g0.after[1]&&a1.before[0]==g1.after[0]&&a1.before[1]==g1.after[1]&&b1.before[0]==g1.after[2]&&b1.before[1]==g1.after[3]&&s.hwnd==g1.hwnd&&s.insert_after==0&&s.flags==5&&s.cx==-1&&s.cy==-1;}
}
