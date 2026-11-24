#pragma once
#define NOMINMAX
#include <windows.h>
#include <cstdint>
#include <stdexcept>
#include <vector>
namespace ra2::platform::thread966 {
inline void need(bool b,const char*s){if(!b)throw std::runtime_error(s);}
inline std::uint32_t ptr(const void*p){static_assert(sizeof(void*)==4);return std::uint32_t(reinterpret_cast<std::uintptr_t>(p));}
struct Event{DWORD count;std::uint32_t handle;BOOL wait_all;DWORD timeout,result;std::uint32_t raw_pointer;};
inline std::vector<Event>&events(){static std::vector<Event>v;return v;}
using Wait=DWORD(WINAPI*)(DWORD,const HANDLE*,BOOL,DWORD);
inline Wait real_wait(){static Wait f=[](){auto p=GetProcAddress(GetModuleHandleW(L"kernel32.dll"),"WaitForMultipleObjects");need(p!=nullptr,"B966 genuine wait API absent");return reinterpret_cast<Wait>(p);}();return f;}
inline DWORD WINAPI observed_wait(DWORD count,const HANDLE*handles,BOOL all,DWORD timeout){
 need(count==1u&&handles&&handles[0]&&all==FALSE&&timeout<=3u,"B966 bounded wait arguments");
 const auto handle=ptr(handles[0]),address=ptr(handles);const auto result=real_wait()(count,handles,all,timeout);
 events().push_back({count,handle,all,timeout,result,address});return result;
}
inline std::uint32_t address(){return std::uint32_t(reinterpret_cast<std::uintptr_t>(&observed_wait));}
inline DWORD wait_one(std::uint32_t handle,DWORD timeout){const HANDLE h=reinterpret_cast<HANDLE>(std::uintptr_t(handle));return observed_wait(1u,&h,FALSE,timeout);}
inline void reset(){events().clear();}
inline bool same_semantics(const Event&a,const Event&b){return a.count==b.count&&a.handle==b.handle&&a.wait_all==b.wait_all&&a.timeout==b.timeout&&a.result==b.result;}
}
