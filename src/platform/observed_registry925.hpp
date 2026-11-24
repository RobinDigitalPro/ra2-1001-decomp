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

// B925 test-only registry observer. All target open/query/close calls reach
// advapi32's real ANSI APIs. HKLM is redirected to an owned volatile HKCU
// subtree for this process, leaving the machine's game keys untouched.
namespace ra2::platform::registry925 {
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

 static U value_for(U n){static constexpr U edges[]={0u,1u,2u,0x7fffffffu,0x80000000u,0xfffffffeu,0xffffffffu,0x55555555u,0xaaaaaaaau};
  return n<sizeof(edges)/sizeof(edges[0])?edges[n]:(0x9e3779b9u*(n+1u))^(n<<13)^0xa9255a3cu;}
 static std::string subkey(U root){if(root==0x000fe700u)return "SOFTWARE\\Westwood\\WOLAPI\\";
  if(root==0x00280a20u)return "SOFTWARE\\Westwood\\Red Alert 2\\";
  throw std::invalid_argument("B925 root must be 0xFE700 or 0x280A20");}
 static std::string value_name(U root){if(root==0x000fe700u)return "Options";
  if(root==0x00280a20u)return "EscapeMovies";
  throw std::invalid_argument("B925 root must be 0xFE700 or 0x280A20");}
 static std::string bounded_ascii(LPCSTR address){need(address!=nullptr,"B925 ANSI string pointer");std::string s;
  for(unsigned i=0;i<260;++i){const char c=address[i];if(!c)return s;s.push_back(c);}
  throw std::runtime_error("B925 unterminated ANSI string");}
 static HKEY hklm(){return HKEY_LOCAL_MACHINE;}
 void note(std::string s){trace_.push_back(std::move(s));}
 std::wstring unique_path()const{std::wostringstream s;s<<L"Software\\RA2RecoveryB925_"<<GetCurrentProcessId()<<L"_"<<GetTickCount64();return s.str();}

 static LSTATUS WINAPI on_open(HKEY root,LPCSTR path,DWORD options,REGSAM access,PHKEY result){
  auto*self=active_;need(self&&self->began_&&!self->finished_&&self->calls_==0,"B925 open order");
  need(root==hklm()&&options==0&&access==0x000f003fu&&result,"B925 open root/options/access/result");
  const auto text=bounded_ascii(path);
  need(text==self->expected_subkey_,"B925 authentic target subkey text");
  const auto status=self->open_a_(root,path,options,access,result);++self->calls_;
  need(status==ERROR_SUCCESS&&*result&&self->open_handle_==nullptr,"B925 real open success/owned handle");
  self->open_handle_=*result;
  std::ostringstream e;e<<"open|"<<text<<"|options="<<options<<"|access=0x"<<std::hex<<access<<"|result="<<std::dec<<status;self->note(e.str());return status;
 }
 static LSTATUS WINAPI on_query(HKEY key,LPCSTR name,LPDWORD reserved,LPDWORD type,LPBYTE data,LPDWORD size){
  auto*self=active_;need(self&&self->began_&&!self->finished_&&self->calls_==1,"B925 query order");
  need(key&&key==self->open_handle_&&!reserved&&type&&data&&size,"B925 query handle/reserved/buffers");
  const auto text=bounded_ascii(name);
  need(text==self->expected_value_,"B925 authentic target value name");
  need(*size==4,"B925 original DWORD query input size");
  const auto status=self->query_a_(key,name,reserved,type,data,size);++self->calls_;
  need(status==ERROR_SUCCESS,"B925 real registry query success");
  if(status==ERROR_SUCCESS)need(*type==REG_DWORD&&*size==4,"B925 real DWORD result type/size");
  U value=0;std::memcpy(&value,data,sizeof(value));need(value==self->seed_,"B925 real query returned the seeded DWORD");
  std::ostringstream e;e<<"query|"<<text<<"|input_size=4|type="<<*type<<"|size="<<*size<<"|value=0x"<<std::hex<<value<<"|result="<<std::dec<<status;self->note(e.str());return status;
 }
 static LSTATUS WINAPI on_close(HKEY key){
  auto*self=active_;need(self&&self->began_&&!self->finished_&&self->calls_==2,"B925 close order");
  need(key&&key==self->open_handle_,"B925 close exact owned opened key");
  const auto status=self->close_(key);++self->calls_;need(status==ERROR_SUCCESS,"B925 real registry close success");self->open_handle_=nullptr;
  self->note("close|result="+std::to_string(status));return status;
 }
 void load_api(){advapi_=LoadLibraryW(L"advapi32.dll");need(advapi_,"B925 load advapi32");
  open_a_=symbol<OpenA>(advapi_,"RegOpenKeyExA");query_a_=symbol<QueryA>(advapi_,"RegQueryValueExA");close_=symbol<Close>(advapi_,"RegCloseKey");
  create_w_=symbol<CreateW>(advapi_,"RegCreateKeyExW");set_a_=symbol<SetA>(advapi_,"RegSetValueExA");
  delete_tree_w_=symbol<DeleteTreeW>(advapi_,"RegDeleteTreeW");override_=symbol<Override>(advapi_,"RegOverridePredefKey");open_w_=symbol<OpenW>(advapi_,"RegOpenKeyExW");}
 void cleanup_noexcept()noexcept{if(open_handle_&&close_){close_(open_handle_);open_handle_=nullptr;}
  if(redirected_&&override_){override_(HKEY_LOCAL_MACHINE,nullptr);redirected_=false;}
  if(sandbox_root_&&close_){close_(sandbox_root_);sandbox_root_=nullptr;}
  if(owns_private_tree_&&!private_path_.empty()&&delete_tree_w_){delete_tree_w_(HKEY_CURRENT_USER,private_path_.c_str());owns_private_tree_=false;}
  if(advapi_){FreeLibrary(advapi_);advapi_=nullptr;}if(active_==this)active_=nullptr;}
public:
 Observer(){try{load_api();private_path_=unique_path();DWORD disp=0;
  const auto cr=create_w_(HKEY_CURRENT_USER,private_path_.c_str(),0,nullptr,REG_OPTION_VOLATILE,KEY_ALL_ACCESS,nullptr,&sandbox_root_,&disp);
  owns_private_tree_=cr==ERROR_SUCCESS&&disp==REG_CREATED_NEW_KEY&&sandbox_root_!=nullptr;
  if(!owns_private_tree_)throw std::runtime_error("B925 create owned volatile HKCU root status="+std::to_string(cr)+" disposition="+std::to_string(disp));
  need(override_(HKEY_LOCAL_MACHINE,sandbox_root_)==ERROR_SUCCESS,"B925 process-local HKLM override");redirected_=true;
 }catch(...){cleanup_noexcept();throw;}}
 Observer(const Observer&)=delete;Observer&operator=(const Observer&)=delete;~Observer(){cleanup_noexcept();}
 // Public model wrappers use the same checked callbacks as the original IAT.
 static LSTATUS WINAPI open(HKEY root,LPCSTR path,DWORD options,REGSAM access,PHKEY result){return on_open(root,path,options,access,result);}
 static LSTATUS WINAPI query(HKEY key,LPCSTR name,LPDWORD reserved,LPDWORD type,LPBYTE data,LPDWORD size){return on_query(key,name,reserved,type,data,size);}
 static LSTATUS WINAPI close(HKEY key){return on_close(key);}
 void bind(Memory&m){need(!began_,"B925 bind before active call");memory_=&m;
  m.w32(0x78500c,U(reinterpret_cast<std::uintptr_t>(&on_open)));
  m.w32(0x785008,U(reinterpret_cast<std::uintptr_t>(&on_query)));
  m.w32(0x785004,U(reinterpret_cast<std::uintptr_t>(&on_close)));}
 void begin(U root,U n){need(memory_&&!began_&&!open_handle_&&active_==nullptr,"B925 begin lifecycle");
  root_rva_=root;seed_=value_for(n);calls_=0;trace_.clear();expected_subkey_=subkey(root);expected_value_=value_name(root);
  DWORD disp=0;HKEY child{};auto create_path=expected_subkey_;if(!create_path.empty()&&create_path.back()=='\\')create_path.pop_back();
  const std::wstring path(create_path.begin(),create_path.end());
  const auto cr=create_w_(sandbox_root_,path.c_str(),0,nullptr,REG_OPTION_VOLATILE,KEY_ALL_ACCESS,nullptr,&child,&disp);
  need(cr==ERROR_SUCCESS&&child,"B925 create/open scoped target key under private root");
  const auto set=set_a_(child,expected_value_.c_str(),0,REG_DWORD,reinterpret_cast<const BYTE*>(&seed_),sizeof(seed_));
  need(set==ERROR_SUCCESS,"B925 seed only private REG_DWORD value");need(close_(child)==ERROR_SUCCESS,"B925 close setup key");
  active_=this;began_=true;finished_=false;}
 void finish(){need(active_==this&&began_&&!finished_&&calls_==3&&!open_handle_,"B925 exact open/query/close with closed handle");
  began_=false;finished_=true;active_=nullptr;}
 U seed()const{return seed_;}const std::vector<std::string>&trace()const{return trace_;}
 void shutdown(){need(!began_&&!open_handle_,"B925 shutdown during target call");
  if(redirected_){need(override_(HKEY_LOCAL_MACHINE,nullptr)==ERROR_SUCCESS,"B925 restore real HKLM mapping");redirected_=false;}
  if(sandbox_root_){need(close_(sandbox_root_)==ERROR_SUCCESS,"B925 close private HKCU root");sandbox_root_=nullptr;}
  if(!private_path_.empty()){need(owns_private_tree_,"B925 refuse deleting an unowned registry tree");
   need(delete_tree_w_(HKEY_CURRENT_USER,private_path_.c_str())==ERROR_SUCCESS,"B925 delete owned volatile HKCU tree");owns_private_tree_=false;
   HKEY check{};const auto status=open_w_(HKEY_CURRENT_USER,private_path_.c_str(),0,KEY_READ,&check);if(check)close_(check);
   need(status==ERROR_FILE_NOT_FOUND,"B925 private registry tree not removed");private_path_.clear();}
  if(advapi_){FreeLibrary(advapi_);advapi_=nullptr;}}
};
} // namespace ra2::platform::registry925
