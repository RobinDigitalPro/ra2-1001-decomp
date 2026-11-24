#pragma once
#define NOMINMAX
#include <windows.h>
#include <array>
#include <cstdint>
#include <string>
#include <stdexcept>
namespace ra2::platform::classes752 {
// All calls reach User32. Classes belong to this test process and have no windows.
class Classes {
 using U=std::uint32_t;inline static Classes*active_{};
 HINSTANCE instance_=GetModuleHandleA(nullptr);std::array<std::string,2>names_;
 std::array<U,2>results_{};unsigned calls_{};
 static void need(bool b,const char*s){if(!b)throw std::runtime_error(s);}
 static U pointer(const void*p){return U(reinterpret_cast<std::uintptr_t>(p));}
 template<class M>static std::string string(M&m,U a){std::string s;for(unsigned k=0;k<128;++k){char c=char(m.r8(a+k));if(!c)return s;s+=c;}throw std::runtime_error("752 unterminated class name");}
 void verify(unsigned k){WNDCLASSA c{};need(GetClassInfoA(instance_,MAKEINTATOM(results_[k]&65535u),&c)!=0,"752 actual registered atom");need(c.style==(k?0x83u:3u)&&pointer(reinterpret_cast<void*>(c.lpfnWndProc))==(k?0x5e2fe0u:0x5e3000u)&&c.cbClsExtra==0&&c.cbWndExtra==0&&c.hInstance==instance_&&!c.hIcon&&!c.hCursor&&!c.hbrBackground,"752 queried attributes");need(pointer(c.lpszClassName)==(results_[k]&65535u)||(pointer(c.lpszClassName)>65535u&&names_[k]==c.lpszClassName),"752 queried class identity");WNDCLASSA named{};need(GetClassInfoA(instance_,names_[k].c_str(),&named)&&named.lpfnWndProc==c.lpfnWndProc&&named.style==c.style&&named.hInstance==c.hInstance,"752 queried by original name");need(k?c.lpszMenuName==nullptr:(c.lpszMenuName&&names_[0]==c.lpszMenuName),"752 queried menu identity");}
public:
 template<class M>explicit Classes(M&m):names_{string(m,0x7d4dcc),string(m,0x7d2f50)}{need(instance_&&!names_[0].empty()&&!names_[1].empty()&&names_[0]!=names_[1],"752 class setup");}
 ~Classes(){if(active_==this)active_=nullptr;for(unsigned k=0;k<2;++k)if(results_[k])UnregisterClassA(names_[k].c_str(),instance_);}
 template<class M,class I>void bind(M&m,I&){m.w32(0xb0dbf8,pointer(instance_));m.w32(0x7854cc,pointer(reinterpret_cast<void*>(&register_class)));}
 void begin(){need(!active_,"752 observer active");for(unsigned k=0;k<2;++k){WNDCLASSA c{};need(!GetClassInfoA(instance_,names_[k].c_str(),&c),"752 initially unregistered");}results_={};calls_=0;active_=this;}
 U finish(){need(active_==this&&calls_==2,"752 exactly two genuine registrations");for(unsigned k=0;k<2;++k)verify(k);U result=results_[1];active_=nullptr;for(unsigned k=0;k<2;++k){need(UnregisterClassA(names_[k].c_str(),instance_)!=0,"752 unregister own class");results_[k]=0;WNDCLASSA c{};need(!GetClassInfoA(instance_,names_[k].c_str(),&c),"752 registration removed");}return result;}
 static U WINAPI register_class(const WNDCLASSA*c){need(active_&&active_->calls_<2&&c,"752 active call");auto&a=*active_;unsigned k=a.calls_++;need(c->style==(k?0x83u:3u)&&pointer(reinterpret_cast<void*>(c->lpfnWndProc))==(k?0x5e2fe0u:0x5e3000u)&&c->cbClsExtra==0&&c->cbWndExtra==0&&c->hInstance==a.instance_&&!c->hIcon&&!c->hCursor&&!c->hbrBackground,"752 literal input attributes");need(c->lpszClassName&&a.names_[k]==c->lpszClassName,"752 literal class name");need(k?c->lpszMenuName==nullptr:(c->lpszMenuName&&a.names_[0]==c->lpszMenuName),"752 literal menu");
  // Capture full original x86 EAX rather than narrowing User32's ATOM to 16 bits.
  using Raw=U(WINAPI*)(const WNDCLASSA*);static Raw call=reinterpret_cast<Raw>(GetProcAddress(GetModuleHandleA("user32.dll"),"RegisterClassA"));need(call,"752 real User32 entry");U v=call(c);need((v&65535u)!=0,"752 positive registration");a.results_[k]=v;a.verify(k);return v;
 }
};
}
