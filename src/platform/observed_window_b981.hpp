#pragma once
#define NOMINMAX
#include <windows.h>
#include <array>
#include <cstdint>
#include <vector>
namespace ra2::platform::window_api_b981 {
enum class Api:std::uint32_t{parent=1,rect=2,move=3};
struct Event{Api api{};std::uint32_t hwnd{},result{},aux{};std::array<std::int32_t,4> rect{};std::int32_t x{},y{},cx{},cy{},repaint{};bool operator==(const Event&o)const{return api==o.api&&hwnd==o.hwnd&&result==o.result&&aux==o.aux&&rect==o.rect&&x==o.x&&y==o.y&&cx==o.cx&&cy==o.cy&&repaint==o.repaint;}};
inline std::vector<Event>&events(){static std::vector<Event>v;return v;}inline void reset(){events().clear();}inline const auto&trace(){return events();}inline std::uint32_t narrow(HWND h){return std::uint32_t(reinterpret_cast<std::uintptr_t>(h));}
inline HWND WINAPI get_parent(HWND h){HWND p=::GetParent(h);events().push_back({Api::parent,narrow(h),std::uint32_t(p!=nullptr),narrow(p)});return p;}
inline BOOL WINAPI get_window_rect(HWND h,LPRECT r){BOOL b=::GetWindowRect(h,r);Event e{};e.api=Api::rect;e.hwnd=narrow(h);e.result=b;e.aux=r!=nullptr;if(r)e.rect={r->left,r->top,r->right,r->bottom};events().push_back(e);return b;}
inline BOOL WINAPI move_window(HWND h,int x,int y,int cx,int cy,BOOL repaint){BOOL b=::MoveWindow(h,x,y,cx,cy,repaint);Event e{};e.api=Api::move;e.hwnd=narrow(h);e.result=b;e.x=x;e.y=y;e.cx=cx;e.cy=cy;e.repaint=repaint;events().push_back(e);return b;}
template<class F>inline std::uint32_t addr(F f){return narrow(reinterpret_cast<HWND>(f));}inline std::uint32_t parent_address(){return addr(&get_parent);}inline std::uint32_t rect_address(){return addr(&get_window_rect);}inline std::uint32_t move_address(){return addr(&move_window);}
inline bool valid(const std::vector<Event>&t){return t.size()==4&&t[0].api==Api::parent&&t[0].result&&t[0].hwnd&&t[0].aux&&t[1].api==Api::rect&&t[1].result&&t[1].aux&&t[1].hwnd==t[0].aux&&t[2].api==Api::rect&&t[2].result&&t[2].aux&&t[2].hwnd==t[0].hwnd&&t[3].api==Api::move&&t[3].result&&t[3].hwnd==t[0].hwnd&&t[3].repaint==FALSE;}
}
