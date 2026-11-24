#pragma once
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include "recovered/recovery_b427.hpp"
#include <windows.h>
#include <algorithm>
#include <cstring>
#include <stdexcept>
#include <vector>

namespace ra2::platform::locale427 {
namespace Model=ra2::recovered::recovery_b427;
using Memory=Model::Memory;
struct Ops {
    Memory* memory{};
    struct Event { std::uint32_t api{},count{},result{}; std::array<std::uint32_t,6> args{}; };
    std::vector<Event> events;
    static void record(void* x,std::uint32_t id,std::initializer_list<std::uint32_t> a,std::uint32_t r){auto& e=static_cast<Ops*>(x)->events.emplace_back();e.api=id;e.count=static_cast<std::uint32_t>(a.size());e.result=r;std::copy(a.begin(),a.end(),e.args.begin());}
    static std::vector<char> bytes(Memory& m,std::uint32_t p,std::uint32_t n){std::vector<char> v(n);for(std::uint32_t k=0;k<n;++k)v[k]=char(m.r8(p+k));return v;}
    static void store(Memory& m,std::uint32_t p,const char* b,std::uint32_t n){for(std::uint32_t k=0;k<n;++k)m.w8(p+k,static_cast<unsigned char>(b[k]));}
    static std::vector<wchar_t> words(Memory& m,std::uint32_t p,std::uint32_t n){std::vector<wchar_t> v(n);for(std::uint32_t k=0;k<n;++k)v[k]=wchar_t(m.r16(p+2*k));return v;}
    static void store_words(Memory& m,std::uint32_t p,const wchar_t* b,std::uint32_t n){for(std::uint32_t k=0;k<n;++k)m.w16(p+2*k,std::uint16_t(b[k]));}
    static std::uint32_t liw(void* x,std::uint32_t l,std::uint32_t t,std::uint32_t o,std::uint32_t n){auto& m=*static_cast<Ops*>(x)->memory;auto v=words(m,o,n);const auto r=::GetLocaleInfoW(l,t,v.data(),int(n));store_words(m,o,v.data(),n);record(x,0x785330u,{l,t,o,n},std::uint32_t(r));return std::uint32_t(r);}
    static std::uint32_t lia(void* x,std::uint32_t l,std::uint32_t t,std::uint32_t o,std::uint32_t n){auto& m=*static_cast<Ops*>(x)->memory;auto v=bytes(m,o,n);const auto r=::GetLocaleInfoA(l,t,v.data(),int(n));store(m,o,v.data(),n);record(x,0x785304u,{l,t,o,n},std::uint32_t(r));return std::uint32_t(r);}
    static std::uint32_t sta(void* x,std::uint32_t l,std::uint32_t t,std::uint32_t s,std::uint32_t n,std::uint32_t o){auto& m=*static_cast<Ops*>(x)->memory;if(!n||n>4096)throw std::domain_error("B427 finite GetStringTypeA count");auto in=bytes(m,s,n);std::vector<WORD> out(n);for(std::uint32_t k=0;k<n;++k)out[k]=WORD(m.r16(o+2*k));const auto r=::GetStringTypeA(l,t,in.data(),int(n),out.data());for(std::uint32_t k=0;k<n;++k)m.w16(o+2*k,out[k]);record(x,0x785314u,{l,t,s,n,o},std::uint32_t(r));return std::uint32_t(r);}
    static std::uint32_t stw(void* x,std::uint32_t t,std::uint32_t s,std::uint32_t n,std::uint32_t o){auto& m=*static_cast<Ops*>(x)->memory;if(!n||n>4096)throw std::domain_error("B427 finite GetStringTypeW count");auto in=words(m,s,n);std::vector<WORD> out(n);for(std::uint32_t k=0;k<n;++k)out[k]=WORD(m.r16(o+2*k));const auto r=::GetStringTypeW(t,in.data(),int(n),out.data());for(std::uint32_t k=0;k<n;++k)m.w16(o+2*k,out[k]);record(x,0x785318u,{t,s,n,o},std::uint32_t(r));return std::uint32_t(r);}
    static std::uint32_t map_a(void* x,std::uint32_t l,std::uint32_t f,std::uint32_t s,std::uint32_t n,std::uint32_t o,std::uint32_t c){auto& m=*static_cast<Ops*>(x)->memory;if(!n||n>4096||c>4096)throw std::domain_error("B427 finite LCMapStringA bounds");auto in=bytes(m,s,n);auto out=bytes(m,o,c);const auto r=::LCMapStringA(l,f,in.data(),int(n),out.data(),int(c));store(m,o,out.data(),c);record(x,0x7852a0u,{l,f,s,n,o,c},std::uint32_t(r));return std::uint32_t(r);}
    static std::uint32_t map_w(void* x,std::uint32_t l,std::uint32_t f,std::uint32_t s,std::uint32_t n,std::uint32_t o,std::uint32_t c){auto& m=*static_cast<Ops*>(x)->memory;if(!n||n>4096||c>4096)throw std::domain_error("B427 finite LCMapStringW bounds");auto in=words(m,s,n);auto out=words(m,o,c);const auto r=::LCMapStringW(l,f,in.data(),int(n),out.data(),int(c));store_words(m,o,out.data(),c);record(x,0x7852a4u,{l,f,s,n,o,c},std::uint32_t(r));return std::uint32_t(r);}
    static bool ver(void* x,Model::Ops::VersionA& out){OSVERSIONINFOA v{};v.dwOSVersionInfoSize=sizeof(v);const BOOL ok=::GetVersionExA(&v);if(!ok)return false;out.size=v.dwOSVersionInfoSize;out.major=v.dwMajorVersion;out.minor=v.dwMinorVersion;out.build=v.dwBuildNumber;out.platform=v.dwPlatformId;std::memcpy(out.csd.data(),v.szCSDVersion,out.csd.size());record(x,0x78517cu,{sizeof(v)},std::uint32_t(ok));return true;}
    Model::Ops bind(){return {this,liw,lia,sta,stw,map_a,map_w,ver};}
};
}
