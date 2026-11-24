#pragma once
#define NOMINMAX
#include <windows.h>
#include "recovered/global_b26_memory.hpp"
#include <array>
#include <cstring>
#include <stdexcept>
#include <string>
#include <vector>
namespace ra2::platform::file483 {
using U=std::uint32_t;using Memory=recovered::global_b26::Memory;
struct Snapshot {std::vector<unsigned char>bytes;std::vector<std::array<U,5>>events;bool live;
 bool operator==(const Snapshot&o)const{return bytes==o.bytes&&events==o.events&&live==o.live;}};
class File {
 using Create=HANDLE(WINAPI*)(LPCSTR,DWORD,DWORD,LPSECURITY_ATTRIBUTES,DWORD,DWORD,HANDLE);
 using Close=BOOL(WINAPI*)(HANDLE);
 Create create_{};Close close_{};std::string path_;HANDLE live_=INVALID_HANDLE_VALUE;
 BY_HANDLE_FILE_INFORMATION identity_{};bool native_=false,bad_=false,owned_=false;U path_pointer_=0;
 std::vector<std::array<U,5>>events_;inline static File*active_=nullptr;
 static void need(bool b,const char*m){if(!b)throw std::runtime_error(m);}
 template<class T>T proc(const char*n){const auto p=GetProcAddress(GetModuleHandleW(L"kernel32.dll"),n);need(p!=nullptr,"483 kernel32 export");return reinterpret_cast<T>(p);}
 static HANDLE WINAPI observe_create(LPCSTR p,DWORD access,DWORD share,LPSECURITY_ATTRIBUTES sa,DWORD disposition,DWORD flags,HANDLE templ){
  auto&a=*active_;need(p&&a.path_==p&&(!a.native_||U(reinterpret_cast<std::uintptr_t>(p))==a.path_pointer_),"483 exact owned path");
  need(access==GENERIC_READ&&(share==1||share==3)&&!sa&&disposition==OPEN_EXISTING&&(flags==0x80||flags==0x8000080)&&!templ&&a.live_==INVALID_HANDLE_VALUE,"483 exact CreateFile arguments");
  const auto h=a.create_(p,access,share,sa,disposition,flags,templ);need(h!=INVALID_HANDLE_VALUE,"483 real open success");a.live_=h;
  BY_HANDLE_FILE_INFORMATION info{};need(GetFileInformationByHandle(h,&info)&&info.dwVolumeSerialNumber==a.identity_.dwVolumeSerialNumber&&info.nFileIndexHigh==a.identity_.nFileIndexHigh&&info.nFileIndexLow==a.identity_.nFileIndexLow,"483 real file identity");
  a.events_.push_back({1,access,share,disposition,flags});return h;
 }
 static BOOL WINAPI observe_close(HANDLE h){auto&a=*active_;need(h==a.live_&&h!=INVALID_HANDLE_VALUE,"483 close owned handle");const auto ok=a.close_(h);need(ok!=0,"483 actual close success");a.live_=INVALID_HANDLE_VALUE;a.events_.push_back({2,U(ok),0,0,0});return ok;}
public:
 File(){
  need(!active_,"483 nested observer");create_=proc<Create>("CreateFileA");close_=proc<Close>("CloseHandle");
  std::array<char,32768>p{};const auto relative=std::string("build\\block483\\provider_")+std::to_string(GetCurrentProcessId())+".bin";
  const auto n=GetFullPathNameA(relative.c_str(),DWORD(p.size()),p.data(),nullptr);need(n>0&&n<p.size(),"483 generated absolute path");path_=p.data();
  const auto h=create_(path_.c_str(),GENERIC_READ|GENERIC_WRITE,7,nullptr,CREATE_NEW,FILE_ATTRIBUTE_TEMPORARY,nullptr);need(h!=INVALID_HANDLE_VALUE,"483 exclusive owned fixture creation");owned_=true;
  need(GetFileInformationByHandle(h,&identity_)!=0,"483 fixture identity");need(close_(h)!=0,"483 fixture close");active_=this;
 }
 ~File(){if(live_!=INVALID_HANDLE_VALUE)close_(live_);if(owned_)DeleteFileA(path_.c_str());active_=nullptr;}
 static const std::string&path(){need(active_,"483 missing observer");return active_->path_;}
 static unsigned char seed(U n,U k){return static_cast<unsigned char>(n*31+k*7+0x51);}
 void bind(Memory&m){m.w32(0x7851b0,U(reinterpret_cast<std::uintptr_t>(&observe_create)));m.w32(0x7851d4,U(reinterpret_cast<std::uintptr_t>(&observe_close)));}
 void begin(bool native,U n,U pointer){
  need(live_==INVALID_HANDLE_VALUE,"483 previous fixture handle still open");
  const auto h=create_(path_.c_str(),GENERIC_READ|GENERIC_WRITE,7,nullptr,OPEN_EXISTING,0,nullptr);need(h!=INVALID_HANDLE_VALUE,"483 reset owned fixture");
  std::array<unsigned char,4096>image{};for(U k=0;k<image.size();++k)image[k]=seed(n,k);DWORD wrote=0;
  need(WriteFile(h,image.data(),DWORD(image.size()),&wrote,nullptr)&&wrote==image.size()&&SetEndOfFile(h),"483 fixture image");need(close_(h)!=0,"483 reset close");
  native_=native;path_pointer_=pointer;events_.clear();SetLastError(0);
 }
 Snapshot finish(Memory&m,U self){
  need(GetLastError()==0,"483 preserved successful last error");
  const bool alive=live_!=INVALID_HANDLE_VALUE;
  if(alive){need(m.r32(self+0x10)==U(reinterpret_cast<std::uintptr_t>(live_)),"483 published actual handle");m.w32(self+0x10,0xd4830001u);}
  else need(m.r32(self+0x10)==0xffffffffu,"483 closed receiver handle");
  // This handle is observation-only and never passed to the recovered root.
  const auto h=create_(path_.c_str(),GENERIC_READ,7,nullptr,OPEN_EXISTING,0,nullptr);need(h!=INVALID_HANDLE_VALUE&&GetFileSize(h,nullptr)==4096,"483 exact file size");
  std::vector<unsigned char>image(4096);DWORD got=0;need(ReadFile(h,image.data(),4096,&got,nullptr)&&got==4096,"483 entire real file readback");need(close_(h)!=0,"483 readback close");
  const auto recorded=events_;if(alive){need(close_(live_)!=0,"483 teardown root-owned handle");live_=INVALID_HANDLE_VALUE;}return {std::move(image),recorded,alive};
 }
 static U open(bool normal){auto&a=*active_;return U(reinterpret_cast<std::uintptr_t>(observe_create(a.path_.c_str(),GENERIC_READ,normal?3:1,nullptr,OPEN_EXISTING,normal?0x8000080:0x80,nullptr)));}
 static U close(U h){return U(observe_close(reinterpret_cast<HANDLE>(std::uintptr_t(h))));}
};
}
