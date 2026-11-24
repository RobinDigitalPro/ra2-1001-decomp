#pragma once
#define NOMINMAX
#include <windows.h>
#include "recovered/recovery_b874.hpp"
#include <vector>
namespace ra2::platform::locale874 {
using U=std::uint32_t;
struct Event {U wide,lc,type,capacity,result;std::vector<std::uint8_t>bytes;bool operator==(const Event&o)const{return wide==o.wide&&lc==o.lc&&type==o.type&&capacity==o.capacity&&result==o.result&&bytes==o.bytes;}};
struct Trace {std::vector<Event>events;bool original=false;void record(bool wide,U lc,U type,void*buffer,int cap,int result){if(cap!=(wide?4:128)||result<=0||result>(wide?4:16))throw std::runtime_error("874 API capacity/result bounds");if(original&&wide&&std::uintptr_t(buffer)!=0xb10818)throw std::runtime_error("874 original Wide destination");if(original&&!wide){NT_TIB*tib;__asm__("movl %%fs:0x18,%0":"=r"(tib));auto p=std::uintptr_t(buffer);if(p<std::uintptr_t(tib->StackLimit)||p+128>std::uintptr_t(tib->StackBase))throw std::runtime_error("874 original ANSI stack buffer");}auto*p=static_cast<std::uint8_t*>(buffer);events.push_back({U(wide),lc,type,U(cap),U(result),{p,p+result*(wide?2:1)}});}};
inline Trace*active=nullptr;
inline int ansi(void*c,U lc,U type,char*p,int cap){int r=GetLocaleInfoA(lc,type,p,cap);DWORD e=GetLastError();static_cast<Trace*>(c)->record(false,lc,type,p,cap,r);SetLastError(e);return r;}
inline int wide(void*c,U lc,U type,std::uint16_t*p,int cap){static_assert(sizeof(wchar_t)==2);int r=GetLocaleInfoW(lc,type,reinterpret_cast<wchar_t*>(p),cap);DWORD e=GetLastError();static_cast<Trace*>(c)->record(true,lc,type,p,cap,r);SetLastError(e);return r;}
inline int WINAPI iat_a(LCID lc,LCTYPE type,LPSTR p,int n){return ansi(active,lc,type,p,n);}
inline int WINAPI iat_w(LCID lc,LCTYPE type,LPWSTR p,int n){return wide(active,lc,type,reinterpret_cast<std::uint16_t*>(p),n);}
inline recovered::recovery_b874::LocaleOps ops(Trace&t){return {&t,ansi,wide};}
inline void install(Trace&t){if(*reinterpret_cast<void**>(0x785304)!=reinterpret_cast<void*>(&GetLocaleInfoA)||*reinterpret_cast<void**>(0x785330)!=reinterpret_cast<void*>(&GetLocaleInfoW))throw std::runtime_error("874 original imports must be real");active=&t;*reinterpret_cast<void**>(0x785304)=reinterpret_cast<void*>(&iat_a);*reinterpret_cast<void**>(0x785330)=reinterpret_cast<void*>(&iat_w);}
}
