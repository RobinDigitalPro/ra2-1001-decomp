#pragma once
#define NOMINMAX
#include <windows.h>
#include <cstdint>
#include <string>
#include <vector>
namespace ra2::platform::cp975 {
struct Event{UINT cp;DWORD flags;int length,capacity,result;std::string input;std::wstring output;bool operator==(const Event&o)const{return cp==o.cp&&flags==o.flags&&length==o.length&&capacity==o.capacity&&result==o.result&&input==o.input&&output==o.output;}bool operator!=(const Event&o)const{return !(*this==o);}};
inline std::vector<Event>&trace(){static std::vector<Event>v;return v;}
inline void reset(){trace().clear();}
inline int WINAPI convert(UINT cp,DWORD flags,LPCCH input,int length,LPWSTR out,int cap){const int result=::MultiByteToWideChar(cp,flags,input,length,out,cap);trace().push_back({cp,flags,length,cap,result,std::string(input),result>0?std::wstring(out,std::size_t(result)):std::wstring()});return result;}
inline bool valid(){if(trace().size()!=1u)return false;const auto&e=trace()[0];return e.cp==CP_ACP&&e.flags==0u&&e.length==-1&&e.capacity==128&&e.result>=1&&e.result<=128;}
inline std::uint32_t address(){static_assert(sizeof(void*)==4);return std::uint32_t(reinterpret_cast<std::uintptr_t>(&convert));}
}
