#pragma once
#define NOMINMAX
#include <windows.h>
#include <cstdint>
#include <string>
#include <vector>
#include <stdexcept>
#include <sstream>
#include <iomanip>
#include <cstring>
#include "recovered/global_b26_memory.hpp"

// B1006 test-only registry observer. All target create/set/close calls reach
// advapi32's real ANSI APIs. HKCR is redirected to an owned volatile HKCU
// subtree for this process, leaving the machine's game keys untouched.
namespace ra2::platform::registry1006 {
using U=std::uint32_t;
using Memory=ra2::recovered::global_b26::Memory;
inline void need(bool ok,const char* why){if(!ok)throw std::runtime_error(why);}
template<class T>T symbol(HMODULE module,const char* name){auto p=GetProcAddress(module,name);need(p!=nullptr,name);return reinterpret_cast<T>(p);}

class Observer {
 inline static Observer* active_{};
 HMODULE advapi_{}; HKEY sandbox_root_{},open_handle_{};
 bool redirected_{},began_{},finished_{},owns_private_tree_{}; Memory* memory_{};
 std::wstring private_path_; U root_rva_{},seed_{},calls_{};
 std::string expected_subkey_,expected_value_; std::vector<std::string> trace_;
 using CreateA=LSTATUS(WINAPI*)(HKEY,LPCSTR,DWORD,LPSTR,DWORD,REGSAM,const LPSECURITY_ATTRIBUTES,PHKEY,LPDWORD);
 CreateA create_a_{};
 using OpenA=LSTATUS(WINAPI*)(HKEY,LPCSTR,DWORD,REGSAM,PHKEY);
 using QueryA=LSTATUS(WINAPI*)(HKEY,LPCSTR,LPDWORD,LPDWORD,LPBYTE,LPDWORD);
 using Close=LSTATUS(WINAPI*)(HKEY);
 using CreateW=LSTATUS(WINAPI*)(HKEY,LPCWSTR,DWORD,LPWSTR,DWORD,REGSAM,const LPSECURITY_ATTRIBUTES,PHKEY,LPDWORD);
 using SetA=LSTATUS(WINAPI*)(HKEY,LPCSTR,DWORD,DWORD,const BYTE*,DWORD);
 using DeleteTreeW=LSTATUS(WINAPI*)(HKEY,LPCWSTR);
 using Override=LSTATUS(WINAPI*)(HKEY,HKEY);
 using OpenW=LSTATUS(WINAPI*)(HKEY,LPCWSTR,DWORD,REGSAM,PHKEY);
 OpenA open_a_{}; QueryA query_a_{}; Close close_{}; CreateW create_w_{};
 SetA set_a_{}; DeleteTreeW delete_tree_w_{}; Override override_{}; OpenW open_w_{};

 public:
 static std::string base_for(U n){return "Recovery"+std::to_string(n%31u);}
 static std::string suffix_for(U n){return "Value"+std::to_string(n%47u);}
 static std::string data_for(U n){return "RA2-value-"+std::to_string(n)+std::string(1u+n%37u,char('A'+n%26u));}
 private:
 static std::string bounded_ascii(LPCSTR address){need(address!=nullptr,"B1006 ANSI string pointer");std::string s;
  for(unsigned i=0;i<260;++i){const char c=address[i];if(!c)return s;s.push_back(c);}
  throw std::runtime_error("B1006 unterminated ANSI string");}
 static HKEY hklm(){return HKEY_CLASSES_ROOT;}
 void note(std::string s){trace_.push_back(std::move(s));}
 std::wstring unique_path()const{std::wostringstream s;s<<L"Software\\RA2RecoveryB1006_"<<GetCurrentProcessId()<<L"_"<<GetTickCount64();return s.str();}

 static LSTATUS WINAPI on_create(HKEY root,LPCSTR path,DWORD reserved,LPSTR cls,DWORD options,REGSAM access,const LPSECURITY_ATTRIBUTES security,PHKEY result,LPDWORD disposition){
  auto*s=active_;need(s&&s->began_&&!s->finished_&&s->calls_==0,"1006 create/open order");
  need(root==HKEY_CLASSES_ROOT&&reserved==0u&&!cls&&options==0u&&access==0xf003fu&&!security&&result&&!disposition,"1006 exact original CreateKey args");
  const auto text=bounded_ascii(path);need(text==s->expected_subkey_,"1006 bounded actual path");
  const auto status=s->create_a_(root,path,reserved,cls,options,access,security,result,disposition);++s->calls_;need(status==0&&*result&&!s->open_handle_,"1006 actual existing key opened");s->open_handle_=*result;s->note("create|"+text+"|options=0|access=983103|status=0");return status;
 }
 static LSTATUS WINAPI on_set(HKEY key,LPCSTR name,DWORD reserved,DWORD type,const BYTE*data,DWORD size){
  auto*s=active_;need(s&&s->began_&&!s->finished_&&s->calls_==1,"1006 set order");need(key&&key==s->open_handle_&&!name&&reserved==0&&type==REG_SZ&&data&&size==s->expected_value_.size()+1u,"1006 exact actual handle/default string args");need(std::memcmp(data,s->expected_value_.c_str(),size)==0,"1006 all real REG_SZ input bytes includingNUL");
  const auto status=s->set_a_(key,name,reserved,type,data,size);++s->calls_;need(status==0,"1006 actual changed value written");s->note("set|"+s->expected_value_+"|type=1|size="+std::to_string(size)+"|status=0");return status;
 }
 static LSTATUS WINAPI on_close(HKEY key){
  auto*self=active_;need(self&&self->began_&&!self->finished_&&self->calls_==2,"B1006 close order");
  need(key&&key==self->open_handle_,"B1006 close exact owned opened key");
  const auto status=self->close_(key);++self->calls_;need(status==ERROR_SUCCESS,"B1006 real registry close success");self->open_handle_=nullptr;
  self->note("close|result="+std::to_string(status));return status;
 }
 void load_api(){advapi_=LoadLibraryW(L"advapi32.dll");need(advapi_,"B1006 load advapi32");
  create_a_=symbol<CreateA>(advapi_,"RegCreateKeyExA");open_a_=symbol<OpenA>(advapi_,"RegOpenKeyExA");query_a_=symbol<QueryA>(advapi_,"RegQueryValueExA");close_=symbol<Close>(advapi_,"RegCloseKey");
  create_w_=symbol<CreateW>(advapi_,"RegCreateKeyExW");set_a_=symbol<SetA>(advapi_,"RegSetValueExA");
  delete_tree_w_=symbol<DeleteTreeW>(advapi_,"RegDeleteTreeW");override_=symbol<Override>(advapi_,"RegOverridePredefKey");open_w_=symbol<OpenW>(advapi_,"RegOpenKeyExW");}
 void cleanup_noexcept()noexcept{if(open_handle_&&close_){close_(open_handle_);open_handle_=nullptr;}
  if(redirected_&&override_){override_(HKEY_CLASSES_ROOT,nullptr);redirected_=false;}
  if(sandbox_root_&&close_){close_(sandbox_root_);sandbox_root_=nullptr;}
  if(owns_private_tree_&&!private_path_.empty()&&delete_tree_w_){delete_tree_w_(HKEY_CURRENT_USER,private_path_.c_str());owns_private_tree_=false;}
  if(advapi_){FreeLibrary(advapi_);advapi_=nullptr;}if(active_==this)active_=nullptr;}
public:
 Observer(){try{load_api();private_path_=unique_path();DWORD disp=0;
  const auto cr=create_w_(HKEY_CURRENT_USER,private_path_.c_str(),0,nullptr,REG_OPTION_VOLATILE,KEY_ALL_ACCESS,nullptr,&sandbox_root_,&disp);
  owns_private_tree_=cr==ERROR_SUCCESS&&disp==REG_CREATED_NEW_KEY&&sandbox_root_!=nullptr;
  if(!owns_private_tree_)throw std::runtime_error("B1006 create owned volatile HKCU root status="+std::to_string(cr)+" disposition="+std::to_string(disp));
  need(override_(HKEY_CLASSES_ROOT,sandbox_root_)==ERROR_SUCCESS,"B1006 process-local HKCR override");redirected_=true;
 }catch(...){cleanup_noexcept();throw;}}
 Observer(const Observer&)=delete;Observer&operator=(const Observer&)=delete;~Observer(){cleanup_noexcept();}
 // Public model wrappers use the same checked callbacks as the original IAT.
 static LSTATUS WINAPI create(HKEY root,LPCSTR path,DWORD reserved,LPSTR cls,DWORD options,REGSAM access,const LPSECURITY_ATTRIBUTES security,PHKEY result,LPDWORD disposition){return on_create(root,path,reserved,cls,options,access,security,result,disposition);}
 static LSTATUS WINAPI set(HKEY key,LPCSTR name,DWORD reserved,DWORD type,const BYTE*data,DWORD size){return on_set(key,name,reserved,type,data,size);}
 static LSTATUS WINAPI close(HKEY key){return on_close(key);}
 void bind(Memory&m){need(!began_,"1006 bind before active call");memory_=&m;m.w32(0x785018,U(reinterpret_cast<std::uintptr_t>(&on_create)));m.w32(0x785014,U(reinterpret_cast<std::uintptr_t>(&on_set)));m.w32(0x785004,U(reinterpret_cast<std::uintptr_t>(&on_close)));m.w32(0x785138,U(reinterpret_cast<std::uintptr_t>(&::lstrcpyA)));m.w32(0x785130,U(reinterpret_cast<std::uintptr_t>(&::lstrcatA)));m.w32(0x78519c,U(reinterpret_cast<std::uintptr_t>(&::lstrlenA)));}
 void begin(U root,U n){need(root==0x2832b0u&&memory_&&!began_&&!open_handle_&&!active_,"1006 begin lifecycle");root_rva_=root;seed_=n;calls_=0;trace_.clear();expected_subkey_=base_for(n)+"\\"+suffix_for(n);expected_value_=data_for(n);
  DWORD disp=0;HKEY child{};const std::wstring path(expected_subkey_.begin(),expected_subkey_.end());const auto cr=create_w_(sandbox_root_,path.c_str(),0,nullptr,REG_OPTION_VOLATILE,KEY_ALL_ACCESS,nullptr,&child,&disp);need(cr==0&&child,"1006 fixture prepares onlyownedvolatile child");
  const std::string old="OLD-"+std::to_string(n);need(old!=expected_value_,"1006 value must change");need(set_a_(child,nullptr,0,REG_SZ,reinterpret_cast<const BYTE*>(old.c_str()),DWORD(old.size()+1u))==0,"1006 fixture priorvalue");need(close_(child)==0,"1006 fixture close seed handle");active_=this;began_=true;finished_=false;}
 void finish(){need(active_==this&&began_&&!finished_&&calls_==3&&!open_handle_,"B1006 exact open/query/close with closed handle");
  began_=false;finished_=true;active_=nullptr;
  HKEY check{};need(open_a_(sandbox_root_,expected_subkey_.c_str(),0,KEY_READ,&check)==0&&check,"1006 independent fresh readback handle");DWORD type=0,size=256;BYTE bytes[256]{};need(query_a_(check,nullptr,nullptr,&type,bytes,&size)==0&&type==REG_SZ&&size==expected_value_.size()+1u&&std::memcmp(bytes,expected_value_.c_str(),size)==0,"1006 independent complete changed registry value");need(close_(check)==0,"1006 readback handleclosed");}
 U seed()const{return seed_;}const std::vector<std::string>&trace()const{return trace_;}
 void shutdown(){need(!began_&&!open_handle_,"B1006 shutdown during target call");
  if(redirected_){need(override_(HKEY_CLASSES_ROOT,nullptr)==ERROR_SUCCESS,"B1006 restore real HKCR mapping");redirected_=false;}
  if(sandbox_root_){need(close_(sandbox_root_)==ERROR_SUCCESS,"B1006 close private HKCU root");sandbox_root_=nullptr;}
  if(!private_path_.empty()){need(owns_private_tree_,"B1006 refuse deleting an unowned registry tree");
   need(delete_tree_w_(HKEY_CURRENT_USER,private_path_.c_str())==ERROR_SUCCESS,"B1006 delete owned volatile HKCU tree");owns_private_tree_=false;
   HKEY check{};const auto status=open_w_(HKEY_CURRENT_USER,private_path_.c_str(),0,KEY_READ,&check);if(check)close_(check);
   need(status==ERROR_FILE_NOT_FOUND,"B1006 private registry tree not removed");private_path_.clear();}
  if(advapi_){FreeLibrary(advapi_);advapi_=nullptr;}}
};
} // namespace ra2::platform::registry1006
