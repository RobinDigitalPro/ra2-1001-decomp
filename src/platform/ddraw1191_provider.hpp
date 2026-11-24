#pragma once
#define NOMINMAX
#include <windows.h>
#include <array>
#include <vector>
#include <cstring>
#include <stdexcept>
#include "recovered/recovery_b1191.hpp"
namespace ra2::platform::ddraw1191{
using Descriptor=recovered::b1191::Descriptor;
inline void need(bool x,const char*s){if(!x)throw std::runtime_error(s);}inline unsigned pointer(const void*p){static_assert(sizeof(void*)==4u);return unsigned(reinterpret_cast<std::uintptr_t>(p));}
struct Identity{unsigned module,create,receiver,vptr,addref,release,getcaps;bool operator==(const Identity&x)const{return module==x.module&&create==x.create&&receiver==x.receiver&&vptr==x.vptr&&addref==x.addref&&release==x.release&&getcaps==x.getcaps;}bool operator!=(const Identity&x)const{return!(*this==x);}};
struct Call{unsigned receiver,slot,hardware,software,result;Descriptor before,after;};
class Provider:public recovered::b1191::Api{
 HMODULE module_=nullptr;void*object_=nullptr;Identity id_{};std::vector<Call>calls_;
 using Caps=HRESULT(WINAPI*)(void*,void*,void*);using Ref=ULONG(WINAPI*)(void*);
 public:
 unsigned create_result=0,create_output_parameter=0,final_release=~0u,unload_result=0;unsigned balanced_pairs=0;
 Provider(){char name[MAX_PATH]{};const unsigned n=GetSystemDirectoryA(name,MAX_PATH);need(n&&n+11u<MAX_PATH,"1191 actualSystem32 directory");std::strcat(name,"\\ddraw.dll");module_=LoadLibraryA(name);need(module_!=nullptr,"1191 actualSystem32 ddraw module");using Create=HRESULT(WINAPI*)(GUID*,void**,void*);const auto create=reinterpret_cast<Create>(GetProcAddress(module_,"DirectDrawCreate"));need(create!=nullptr,"1191 actualDirectDrawCreate export");create_output_parameter=pointer(&object_);create_result=unsigned(create(nullptr,&object_,nullptr));need(create_result==unsigned(S_OK)&&object_!=nullptr,"1191 genuineDirectDrawCreate NULL/output/NULL S_OK");const auto*vt=*reinterpret_cast<const unsigned*const*>(object_);id_={pointer(module_),unsigned(reinterpret_cast<std::uintptr_t>(create)),pointer(object_),pointer(vt),vt[1],vt[2],vt[11]};need(id_.vptr&&id_.addref&&id_.release&&id_.getcaps,"1191 fullrealIUnknown/GetCaps slots");balanced();}
 ~Provider(){if(object_)reinterpret_cast<Ref>(std::uintptr_t(id_.release))(object_);if(module_)FreeLibrary(module_);}
 Provider(const Provider&)=delete;Provider&operator=(const Provider&)=delete;
 Identity identity()const{need(object_!=nullptr,"1191 LIVE realDirectDraw");const auto*vt=*reinterpret_cast<const unsigned*const*>(object_);const Identity now{pointer(module_),id_.create,pointer(object_),pointer(vt),vt[1],vt[2],vt[11]};need(now==id_,"1191 complete rawprovider/method/module identity");return now;}
 const std::vector<Call>&calls()const{return calls_;}
 void balanced(){const auto id=identity();const unsigned raised=reinterpret_cast<Ref>(std::uintptr_t(id.addref))(object_),restored=reinterpret_cast<Ref>(std::uintptr_t(id.release))(object_);need(raised==2u&&restored==1u,"1191 complete actualAddRef2/Release1 lifetime");++balanced_pairs;}
 unsigned get_caps(unsigned receiver,Descriptor&hardware,unsigned software)override{const auto id=identity();Descriptor initial{};initial[0]=0x3cu;initial[1]=1u;need(receiver==id.receiver&&software==0u&&(pointer(hardware.data())&3u)==0u&&hardware==initial,"1191 completeGetCaps actualreceiver/zero316+size/hardware/NULLsoftware");Call c{receiver,id.getcaps,pointer(hardware.data()),software,0u,hardware,{}};c.result=unsigned(reinterpret_cast<Caps>(std::uintptr_t(id.getcaps))(object_,hardware.data(),nullptr));c.after=hardware;calls_.push_back(c);need(identity()==id,"1191 realCOMvtable remainsunchanged");return c.result;}
 void close(){balanced();identity();final_release=reinterpret_cast<Ref>(std::uintptr_t(id_.release))(object_);object_=nullptr;need(final_release==0u,"1191 actualfixturefinalRelease0");unload_result=unsigned(FreeLibrary(module_));module_=nullptr;need(unload_result==unsigned(TRUE),"1191 fullactualFreeLibraryBOOL");}
};
}
