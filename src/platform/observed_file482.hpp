#pragma once
#define NOMINMAX
#include <windows.h>
#include "recovered/global_b26_memory.hpp"
#include <array>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <vector>
namespace ra2::platform::file482 {
using U=std::uint32_t;using Memory=ra2::recovered::global_b26::Memory;
struct Snapshot{
 std::vector<unsigned char> bytes;U position;std::vector<std::array<U,4>> events;
 bool operator==(const Snapshot&b)const{return bytes==b.bytes&&position==b.position&&events==b.events;}
};
class File {
 using Read=BOOL(WINAPI*)(HANDLE,LPVOID,DWORD,LPDWORD,LPOVERLAPPED);
 using Write=BOOL(WINAPI*)(HANDLE,LPCVOID,DWORD,LPDWORD,LPOVERLAPPED);
 using Seek=DWORD(WINAPI*)(HANDLE,LONG,PLONG,DWORD);
 HANDLE file_=INVALID_HANDLE_VALUE;Read read_{};Write write_{};Seek seek_{};
 bool native_=false,bad_=false;U data_pointer_=0;std::vector<std::array<U,4>> events_;
 inline static File* active_=nullptr;
 static void need(bool b,const char*s){if(!b)throw std::runtime_error(s);}
 template<class T>T proc(const char*n){auto p=GetProcAddress(GetModuleHandleW(L"kernel32.dll"),n);need(p!=nullptr,"482 original kernel32 export");return reinterpret_cast<T>(p);}
 static BOOL WINAPI observe_read(HANDLE h,LPVOID p,DWORD n,LPDWORD got,LPOVERLAPPED ov){
  auto&a=*active_;if(h!=a.file_||!p||!got||ov||n==0||n>256||(a.native_&&reinterpret_cast<std::uintptr_t>(p)!=a.data_pointer_))a.bad_=true;
  const BOOL ok=a.read_(h,p,n,got,ov);a.events_.push_back({1,n,U(ok),got?U(*got):0});return ok;
 }
 static BOOL WINAPI observe_write(HANDLE h,LPCVOID p,DWORD n,LPDWORD got,LPOVERLAPPED ov){
  auto&a=*active_;if(h!=a.file_||!p||!got||ov||n==0||n>256||(a.native_&&reinterpret_cast<std::uintptr_t>(p)!=a.data_pointer_))a.bad_=true;
  const BOOL ok=a.write_(h,p,n,got,ov);a.events_.push_back({2,n,U(ok),got?U(*got):0});return ok;
 }
 static DWORD WINAPI observe_seek(HANDLE h,LONG offset,PLONG high,DWORD method){
  auto&a=*active_;if(h!=a.file_||high||method>2)a.bad_=true;
  const auto pos=a.seek_(h,offset,high,method);a.events_.push_back({3,U(offset),method,pos});return pos;
 }
public:
 File(){
  need(!active_,"482 nested file observer");read_=proc<Read>("ReadFile");write_=proc<Write>("WriteFile");seek_=proc<Seek>("SetFilePointer");
  // CREATE_NEW cannot overwrite an existing file; DELETE_ON_CLOSE removes
  // only this owned generated fixture. The game installations are untouched.
  const auto relative=std::wstring(L"build\\block482\\provider_")+std::to_wstring(GetCurrentProcessId())+L".bin";
  std::array<wchar_t,32768> path{};const auto count=GetFullPathNameW(relative.c_str(),DWORD(path.size()),path.data(),nullptr);
  need(count>0&&count<path.size(),"482 workspace fixture path");
  file_=CreateFileW(path.data(),GENERIC_READ|GENERIC_WRITE,FILE_SHARE_READ|FILE_SHARE_WRITE|FILE_SHARE_DELETE,nullptr,CREATE_NEW,FILE_ATTRIBUTE_TEMPORARY|FILE_FLAG_DELETE_ON_CLOSE,nullptr);
  need(file_!=INVALID_HANDLE_VALUE,"482 own temporary file creation");active_=this;
 }
 ~File(){if(file_!=INVALID_HANDLE_VALUE)CloseHandle(file_);active_=nullptr;}
 static U handle(){need(active_!=nullptr,"482 missing file observer");return U(reinterpret_cast<std::uintptr_t>(active_->file_));}
 void bind(Memory&m){
  m.w32(0x785110,U(reinterpret_cast<std::uintptr_t>(&observe_read)));m.w32(0x78512c,U(reinterpret_cast<std::uintptr_t>(&observe_write)));
  m.w32(0x7851b4,U(reinterpret_cast<std::uintptr_t>(&observe_seek)));m.w32(0x7851f4,U(reinterpret_cast<std::uintptr_t>(proc<DWORD(WINAPI*)()>("GetLastError"))));
 }
 static unsigned char seed(U n,U k){return static_cast<unsigned char>(n*17+k*13+0x43);}
 static U initial_position(U n){return 17+n%61;}
 void begin(bool native,U n,U data){
  std::vector<unsigned char>b(4096);for(U k=0;k<b.size();++k)b[k]=seed(n,k);
  need(seek_(file_,0,nullptr,FILE_BEGIN)==0,"482 fixture seek0");DWORD got=0;
  need(write_(file_,b.data(),DWORD(b.size()),&got,nullptr)&&got==b.size()&&SetEndOfFile(file_),"482 fixture image");
  need(seek_(file_,LONG(initial_position(n)),nullptr,FILE_BEGIN)==initial_position(n),"482 fixture initial position");
  native_=native;data_pointer_=data;bad_=false;events_.clear();SetLastError(0);
 }
 Snapshot finish(){
  need(!bad_,"482 actual API identity/pointer/arguments");
  for(const auto&e:events_)if(e[0]!=3)need(e[2]!=0&&e[3]==e[1],"482 full successful transfer");else need(e[3]!=INVALID_SET_FILE_POINTER,"482 successful seek");
  need(GetLastError()==0,"482 successful calls preserve zero LastError");
  const auto pos=seek_(file_,0,nullptr,FILE_CURRENT);need(pos!=INVALID_SET_FILE_POINTER&&GetFileSize(file_,nullptr)==4096,"482 exact file size/position");
  need(seek_(file_,0,nullptr,FILE_BEGIN)==0,"482 snapshot seek");std::vector<unsigned char> data(4096);DWORD got=0;
  need(read_(file_,data.data(),4096,&got,nullptr)&&got==4096,"482 complete file readback");
  need(seek_(file_,LONG(pos),nullptr,FILE_BEGIN)==pos,"482 restore observed position");return {std::move(data),pos,events_};
 }
 static U read(Memory&m,U p,U n){std::array<unsigned char,256>b{};need(n>0&&n<=b.size(),"482 read bound");DWORD got=0;need(observe_read(active_->file_,b.data(),n,&got,nullptr)!=0,"482 model real ReadFile");for(U k=0;k<got;++k)m.w8(p+k,b[k]);return got;}
 static U write(Memory&m,U p,U n){std::array<unsigned char,256>b{};need(n>0&&n<=b.size(),"482 write bound");for(U k=0;k<n;++k)b[k]=static_cast<unsigned char>(m.r8(p+k));DWORD got=0;need(observe_write(active_->file_,b.data(),n,&got,nullptr)!=0,"482 model real WriteFile");return got;}
 static U seek(U offset,U method){return observe_seek(active_->file_,LONG(offset),nullptr,method);}
};
}
