#pragma once
#define NOMINMAX
#include <windows.h>
#include "platform/x87_state.hpp"
#include <vector>
#include <stdexcept>
namespace ra2::platform::timer1528 {
constexpr UINT_PTR timer_id=0x54544950u;
struct Event{std::uint32_t hwnd{},id{};BOOL result{};DWORD thread{};bool operator==(const Event& x)const{return hwnd==x.hwnd&&id==x.id&&result==x.result&&thread==x.thread;}};
inline std::vector<Event>& events(){static std::vector<Event> v;return v;}
inline void reset(){events().clear();events().reserve(1);}
inline BOOL WINAPI kill_timer(HWND hwnd,UINT_PTR id){const BOOL result=::KillTimer(hwnd,id);const auto post_api=ra2::platform::x87::capture_host();events().push_back({std::uint32_t(reinterpret_cast<std::uintptr_t>(hwnd)),std::uint32_t(id),result,::GetCurrentThreadId()});ra2::platform::x87::restore_host(post_api);return result;}
inline std::uint32_t address(){return std::uint32_t(reinterpret_cast<std::uintptr_t>(&kill_timer));}
inline void verify_real_import(){auto module=::GetModuleHandleA("USER32.dll");if(!module||::GetProcAddress(module,"KillTimer")!=reinterpret_cast<FARPROC>(&::KillTimer))throw std::runtime_error("B1528 actual USER32 KillTimer import identity");}
inline BOOL guest_kill(std::uint32_t hwnd,ra2::platform::x87::Image& guest){
    auto host=ra2::platform::x87::capture_host();ra2::platform::x87::restore_host(guest);
    BOOL result=kill_timer(reinterpret_cast<HWND>(std::uintptr_t(hwnd)),timer_id);
    guest=ra2::platform::x87::capture_host();ra2::platform::x87::restore_host(host);return result;
}
struct Fs{std::uint32_t head{};std::uint16_t selector{};bool operator==(const Fs& x)const{return head==x.head&&selector==x.selector;}};
inline Fs fs(){Fs v;asm volatile("movl %%fs:0,%0;movw %%fs,%1":"=r"(v.head),"=r"(v.selector));return v;}
}
