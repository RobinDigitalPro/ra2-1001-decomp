#pragma once
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include <array>
#include <cstdint>
#include <cstring>

namespace ra2::platform::locale206 {
// Observe and forward genuine Windows calls. No fixture supplies API results.
struct Trace { unsigned calls=0;bool valid=true;std::array<int,4> results{}; };
inline Trace trace{};
inline void reset(){trace=Trace{};}
inline int WINAPI locale_info(LCID id,LCTYPE type,LPWSTR out,int count){
 const unsigned index=trace.calls++;
 const bool args=index==0?(id==0&&type==LOCALE_ILANGUAGE&&!out&&count==0):
  index==1?(id==0x409&&type==LOCALE_ILANGUAGE&&!out&&count==0):
  index==2?(id==0x409&&type==LOCALE_ILANGUAGE&&out&&count==5):false;
 const int value=::GetLocaleInfoW(id,type,out,count);const DWORD error=::GetLastError();
 trace.valid=trace.valid&&args&&value==5;
 if(index<4)trace.results[index]=value;
 if(index==2&&out&&value==5)trace.valid=trace.valid&&out[0]=='0'&&out[1]=='4'&&out[2]=='0'&&out[3]=='9'&&out[4]==0;
 ::SetLastError(error);return value;
}
inline int WINAPI to_bytes(UINT cp,DWORD flags,LPCWCH input,int size,LPSTR output,int capacity,LPCCH fallback,LPBOOL used){
 const unsigned index=trace.calls++;
 const bool args=index==3&&cp==CP_ACP&&flags==0x220&&input&&size==-1&&output&&capacity==128&&!fallback&&!used;
 const int value=::WideCharToMultiByte(cp,flags,input,size,output,capacity,fallback,used);const DWORD error=::GetLastError();
 trace.valid=trace.valid&&args&&value==5;
 if(index<4)trace.results[index]=value;
 if(value==5&&output)trace.valid=trace.valid&&std::memcmp(output,"0409",5)==0;
 ::SetLastError(error);return value;
}
inline bool complete(){return trace.valid&&trace.calls==4&&trace.results==std::array<int,4>{5,5,5,5};}
}
