#pragma once
#define NOMINMAX
#include <windows.h>
#include <cstdint>
#include <stdexcept>
namespace ra2::platform::control635 {
class Control {
 using Create=HWND(WINAPI*)(DWORD,LPCSTR,LPCSTR,DWORD,int,int,int,int,HWND,HMENU,HINSTANCE,LPVOID);
 using Destroy=BOOL(WINAPI*)(HWND);using GetId=int(WINAPI*)(HWND);
 HMODULE module_{};HWND parent_{},child_{};Destroy destroy_{};GetId get_{};
 int id_;unsigned calls_=0;inline static Control* active_=nullptr;
 static void need(bool b,const char*s){if(!b)throw std::runtime_error(s);}
 template<class T>T proc(const char*s){auto p=reinterpret_cast<T>(GetProcAddress(module_,s));need(p!=nullptr,"635 real USER32 export");return p;}
public:
 explicit Control(int id):id_(id){static_assert(sizeof(void*)==4,"635 x86 original API");module_=LoadLibraryW(L"user32.dll");need(module_!=nullptr,"635 USER32 loaded");try{destroy_=proc<Destroy>("DestroyWindow");get_=proc<GetId>("GetDlgCtrlID");const auto create=proc<Create>("CreateWindowExA");
  parent_=create(0,"STATIC","RA2 recovery635",WS_OVERLAPPED,0,0,64,64,nullptr,nullptr,GetModuleHandleW(nullptr),nullptr);need(parent_!=nullptr,"635 owned hidden parent");
  child_=create(0,"STATIC","",WS_CHILD,0,0,8,8,parent_,reinterpret_cast<HMENU>(std::intptr_t(id)),GetModuleHandleW(nullptr),nullptr);need(child_!=nullptr,"635 owned hidden child");need(get_(child_)==id_,"635 actual control ID prestate");
 }catch(...){if(parent_)destroy_(parent_);FreeLibrary(module_);throw;}}
 ~Control(){if(active_==this)active_=nullptr;if(parent_)destroy_(parent_);if(module_)FreeLibrary(module_);}
 unsigned handle()const{return unsigned(reinterpret_cast<std::uintptr_t>(child_));}
 void begin(){need(!active_&&get_(child_)==id_,"635 real control unchanged before leg");calls_=0;active_=this;}
 void finish(){need(active_==this&&calls_==1&&get_(child_)==id_,"635 exactly one actual ID observation and preserved window");active_=nullptr;}
 static int WINAPI observe(HWND h){need(active_&&active_->calls_==0&&h==active_->child_,"635 exact owned HWND and event order");const int result=active_->get_(h);need(result==active_->id_,"635 actual USER32 result");++active_->calls_;return result;}
 static unsigned guest_call(unsigned h){return unsigned(observe(reinterpret_cast<HWND>(std::uintptr_t(h))));}
 static unsigned address(){return unsigned(reinterpret_cast<std::uintptr_t>(&observe));}
 template<class Memory,class Inputs>void bind(Memory&m,Inputs&i){m.w32(0x7853f4,address());i.dx=handle();}
};
}
