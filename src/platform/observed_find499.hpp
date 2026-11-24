#pragma once
#define NOMINMAX
#include <windows.h>
#include <winnt.h>
#include <array>
#include <cstdint>
#include <cstddef>
#include <cstring>
#include <stdexcept>
#include <string>
#include <vector>

namespace ra2::platform::find499 {
using U=std::uint32_t;
struct Event { U api=0,result=0,argument0=0,argument1=0,attributes=0; std::string pattern,name; std::array<std::uint8_t,sizeof(WIN32_FIND_DATAA)> data{}; };
class Observer {
 using First=HANDLE(WINAPI*)(LPCSTR,LPWIN32_FIND_DATAA);
 using Close=BOOL(WINAPI*)(HANDLE);
 First first_{}; Close close_{}; bool bad_=false; U expected_pattern_=0,expected_data_=0; std::vector<Event> events_;
 inline static Observer* active_=nullptr;
 static void need(bool b,const char*s){if(!b)throw std::runtime_error(s);}
 template<class T>static T proc(const char*n){auto p=GetProcAddress(GetModuleHandleW(L"kernel32.dll"),n);need(p!=nullptr,"B499 kernel32 export");return reinterpret_cast<T>(p);}
 static bool stack_span(const void*p,std::size_t n){auto*tib=reinterpret_cast<NT_TIB*>(NtCurrentTeb());auto a=std::uintptr_t(p);return a>=std::uintptr_t(tib->StackLimit)&&a<=std::uintptr_t(tib->StackBase)&&n<=std::uintptr_t(tib->StackBase)-a;}
 static HANDLE WINAPI wrap_first(LPCSTR pattern,LPWIN32_FIND_DATAA data){
  auto&o=*active_;if(!pattern||!data||!stack_span(pattern,1)||!stack_span(data,sizeof(*data))||
      (o.expected_pattern_&&U(reinterpret_cast<std::uintptr_t>(pattern))!=o.expected_pattern_)||
      (o.expected_data_&&U(reinterpret_cast<std::uintptr_t>(data))!=o.expected_data_))o.bad_=true;
  Event e{};if(pattern){for(std::size_t k=0;k<64;++k){if(!stack_span(pattern,k+1)){o.bad_=true;break;}const char c=pattern[k];if(!c)break;e.pattern.push_back(c);}}
  e.argument0=U(reinterpret_cast<std::uintptr_t>(pattern));e.argument1=U(reinterpret_cast<std::uintptr_t>(data));
  const HANDLE h=o.first_(pattern,data);const DWORD last=GetLastError();e.result=U(reinterpret_cast<std::uintptr_t>(h));
  if(h!=INVALID_HANDLE_VALUE&&data){e.attributes=data->dwFileAttributes;for(std::size_t k=0;k<MAX_PATH;++k){const char c=data->cFileName[k];if(!c)break;e.name.push_back(c);if(k+1==MAX_PATH)o.bad_=true;}std::memcpy(e.data.data(),data,36);std::memcpy(e.data.data()+offsetof(WIN32_FIND_DATAA,cFileName),data->cFileName,e.name.size()+1);for(unsigned k=0;k<14;++k){e.data[offsetof(WIN32_FIND_DATAA,cAlternateFileName)+k]=data->cAlternateFileName[k];if(!data->cAlternateFileName[k])break;}}
  e.api=0x7851fcu;o.events_.push_back(std::move(e));SetLastError(last);return h;
 }
 static BOOL WINAPI wrap_close(HANDLE h){auto&o=*active_;Event e{};e.api=0x7852f8u;e.argument0=U(reinterpret_cast<std::uintptr_t>(h));const BOOL r=o.close_(h);const DWORD last=GetLastError();e.result=U(r);o.events_.push_back(std::move(e));SetLastError(last);return r;}
 static void patch(U at,const void*p){*reinterpret_cast<volatile U*>(std::uintptr_t(at))=U(reinterpret_cast<std::uintptr_t>(p));}
public:
 Observer(){need(!active_,"B499 nested observer");first_=proc<First>("FindFirstFileA");close_=proc<Close>("FindClose");active_=this;}
 ~Observer(){active_=nullptr;}
 Observer(const Observer&)=delete;Observer&operator=(const Observer&)=delete;
 void bind(){patch(0x7851fcu,reinterpret_cast<const void*>(&wrap_first));patch(0x7852f8u,reinterpret_cast<const void*>(&wrap_close));}
 void bind(ra2::recovered::global_b26::Memory&m){m.w32(0x7851fcu,U(reinterpret_cast<std::uintptr_t>(&wrap_first)));m.w32(0x7852f8u,U(reinterpret_cast<std::uintptr_t>(&wrap_close)));}
 static HANDLE first(LPCSTR p,LPWIN32_FIND_DATAA d){need(active_!=nullptr,"B499 missing active observer");return wrap_first(p,d);}
 static BOOL close(HANDLE h){need(active_!=nullptr,"B499 missing active observer");return wrap_close(h);}
 void begin(){events_.clear();bad_=false;expected_pattern_=expected_data_=0;SetLastError(0);}
 void validate_native(U entry_esp){validate_positive("*.NET");const auto&e=events_[0];need(e.argument0==entry_esp-0x244u&&e.argument1==entry_esp-0x140u,"B499 exact original stack API arguments");}
 void validate_positive(const char*expected){need(!bad_,"B499 Win32 API pointer is outside current thread stack");need(events_.size()==1,"B499 expected exactly one FindFirstFileA");const auto&e=events_[0];need(e.api==0x7851fcu&&e.pattern==expected&&e.result!=U(INVALID_HANDLE_VALUE),"B499 FindFirstFileA identity/pattern/result");need(e.name=="SAVEGAME.NET"&&(e.attributes&FILE_ATTRIBUTE_ARCHIVE)!=0,"B499 real fixture file result");need((e.attributes&0x116u)==0,"B499 original positive attribute predicate");}
 const std::vector<Event>&events()const{return events_;}
 static void create_fixture(std::wstring&dir){
  std::array<wchar_t,32768>cwd{};DWORD n=GetCurrentDirectoryW(DWORD(cwd.size()),cwd.data());need(n&&n<cwd.size(),"B499 fixture workspace path");
  dir=std::wstring(cwd.data())+L"\\build\\private499\\fixture_"+std::to_wstring(GetCurrentProcessId());
  if(!CreateDirectoryW((std::wstring(cwd.data())+L"\\build\\private499").c_str(),nullptr)&&GetLastError()!=ERROR_ALREADY_EXISTS)throw std::runtime_error("B499 private fixture parent");
  if(!CreateDirectoryW(dir.c_str(),nullptr))throw std::runtime_error("B499 unique fixture directory");
  const auto file=dir+L"\\SAVEGAME.NET";HANDLE h=CreateFileW(file.c_str(),GENERIC_WRITE,0,nullptr,CREATE_NEW,FILE_ATTRIBUTE_ARCHIVE,nullptr);need(h!=INVALID_HANDLE_VALUE,"B499 unique fixture file");CloseHandle(h);
 }
 static void remove_fixture(const std::wstring&dir){DeleteFileW((dir+L"\\SAVEGAME.NET").c_str());RemoveDirectoryW(dir.c_str());}
};
}
