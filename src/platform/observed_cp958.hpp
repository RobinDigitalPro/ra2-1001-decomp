#pragma once
#define NOMINMAX
#include <windows.h>
#include <cstdint>
#include <string>
#include <vector>
namespace ra2::platform::cp958 {
struct Event{UINT cp;DWORD flags;int length,capacity,result;bool null_default,null_used;std::wstring wide;std::string output;bool operator==(const Event&)const=default;};
inline std::vector<Event>&trace(){static std::vector<Event>v;return v;}
inline void reset(){trace().clear();}
inline int WINAPI convert(UINT cp,DWORD flags,LPCWCH wide,int length,LPSTR out,int cap,LPCCH def,LPBOOL used){int result=::WideCharToMultiByte(cp,flags,wide,length,out,cap,def,used);trace().push_back({cp,flags,length,cap,result,def==nullptr,used==nullptr,std::wstring(wide),result>0?std::string(out,std::size_t(result)):std::string()});return result;}
inline bool valid(){if(trace().size()!=1)return false;auto&e=trace()[0];return e.cp==CP_ACP&&e.flags==0&&e.length==-1&&e.capacity==127&&e.result>0&&e.result<=127&&e.null_default&&e.null_used;}
inline std::uint32_t address(){return std::uint32_t(reinterpret_cast<std::uintptr_t>(&convert));}
}
