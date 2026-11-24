#pragma once
#define NOMINMAX
#include <windows.h>
#include <objbase.h>
#include <array>
#include <string>
#include <cstring>
#include <stdexcept>
namespace ra2::platform::ini_guid778 {
using U=std::uint32_t;using Convert=int(WINAPI*)(UINT,DWORD,LPCCH,int,LPWSTR,int);using Parse=HRESULT(WINAPI*)(LPCOLESTR,LPCLSID);
inline Convert actual_convert=nullptr;inline Parse actual_parse=nullptr;inline unsigned phase=0;inline std::string expected_text;
inline void need(bool v,const char*m){if(!v)throw std::runtime_error(m);}
inline std::array<unsigned char,16> expected_bytes(U n){std::array<unsigned char,16>b{};U a=0xa1b20000u+n*0x1021u;unsigned d=0xc300u+(n&255),e=0xd400u+((n>>1)&255);for(U k=0;k<4;++k)b[k]=a>>(8*k);b[4]=d;b[5]=d>>8;b[6]=e;b[7]=e>>8;for(U k=8;k<16;++k)b[k]=n*7+k*19;return b;}
inline std::string text(U n){auto b=expected_bytes(n);constexpr unsigned order[]{3,2,1,0,5,4,7,6,8,9,10,11,12,13,14,15};constexpr char h[]="0123456789ABCDEF";std::string s="{";for(unsigned k=0;k<16;++k){if(k==4||k==6||k==8||k==10)s+='-';s+=h[b[order[k]]>>4];s+=h[b[order[k]]&15];}return s+'}';}
inline void resolve(){if(actual_convert)return;auto kernel=GetModuleHandleW(L"kernel32.dll");auto ole=LoadLibraryW(L"ole32.dll");need(kernel&&ole,"778 system DLL resolution");actual_convert=reinterpret_cast<Convert>(GetProcAddress(kernel,"MultiByteToWideChar"));actual_parse=reinterpret_cast<Parse>(GetProcAddress(ole,"CLSIDFromString"));need(actual_convert&&actual_parse,"778 actual import resolution");}
inline void begin(U n){resolve();phase=0;expected_text=text(n);}
inline int WINAPI convert(UINT cp,DWORD flags,LPCCH src,int count,LPWSTR dst,int cap){need(phase==0&&cp==0&&flags==1&&count==-1&&cap==128&&src&&dst,"778 first API exact parameters/order");need(expected_text==src,"778 first API actual trimmed source");const int r=actual_convert(cp,flags,src,count,dst,cap);need(r==39,"778 actual conversion returns39 includingNUL");for(unsigned k=0;k<39;++k)need(dst[k]==(k==38?0:static_cast<unsigned char>(expected_text[k])),"778 actual converted units");++phase;return r;}
inline HRESULT WINAPI parse(LPCOLESTR src,LPCLSID out){need(phase==1&&src&&out,"778 second API exact order/nonnull");for(unsigned k=0;k<39;++k)need(src[k]==(k==38?0:static_cast<unsigned char>(expected_text[k])),"778 second API actual input");auto r=actual_parse(src,out);need(r==S_OK,"778 actual CLSID parse success");++phase;return r;}
inline void audit(){need(phase==2,"778 exactly two actual API calls");}
}
