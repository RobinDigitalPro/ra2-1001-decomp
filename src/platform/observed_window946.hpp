#pragma once
#define NOMINMAX
#include <windows.h>
#include <array>
#include <cstdint>
#include <vector>
namespace ra2::platform::window_api_b946 {
enum class Api : std::uint32_t { get_client_rect = 1, client_to_screen = 2 };
struct Event {
    Api api{};
    std::uint32_t hwnd{};
    std::array<std::int32_t,4> before{};
    std::array<std::int32_t,4> after{};
    std::int32_t result{};
    bool buffer_nonnull{};
    friend bool operator==(const Event&,const Event&)=default;
};
using Trace=std::vector<Event>;
inline Trace& mutable_trace(){static Trace events;return events;}
inline void reset(){mutable_trace().clear();}
inline const Trace& trace(){return mutable_trace();}
inline std::uint32_t narrow(HWND h){return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(h));}
inline BOOL WINAPI get_client_rect(HWND hwnd,LPRECT rect){
    const BOOL result=::GetClientRect(hwnd,rect);
    Event e{};e.api=Api::get_client_rect;e.hwnd=narrow(hwnd);e.result=result;e.buffer_nonnull=rect!=nullptr;
    if(rect)e.after={rect->left,rect->top,rect->right,rect->bottom};
    mutable_trace().push_back(e);return result;
}
inline BOOL WINAPI client_to_screen(HWND hwnd,LPPOINT point){
    Event e{};e.api=Api::client_to_screen;e.hwnd=narrow(hwnd);e.buffer_nonnull=point!=nullptr;
    if(point)e.before={point->x,point->y,0,0};
    const BOOL result=::ClientToScreen(hwnd,point);
    e.result=result;if(point)e.after={point->x,point->y,0,0};
    mutable_trace().push_back(e);return result;
}
inline bool valid_trace(const Trace& events){
    if(events.size()!=3)return false;
    const auto& g=events[0];const auto& a=events[1];const auto& b=events[2];
    return g.api==Api::get_client_rect&&g.result!=0&&g.buffer_nonnull&&
           a.api==Api::client_to_screen&&a.result!=0&&a.buffer_nonnull&&
           b.api==Api::client_to_screen&&b.result!=0&&b.buffer_nonnull&&
           g.hwnd!=0&&a.hwnd==g.hwnd&&b.hwnd==g.hwnd&&
           a.before[0]==g.after[0]&&a.before[1]==g.after[1]&&
           b.before[0]==g.after[2]&&b.before[1]==g.after[3];
}inline std::uint32_t get_client_rect_address(){return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&get_client_rect));}
inline std::uint32_t client_to_screen_address(){return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&client_to_screen));}
}

