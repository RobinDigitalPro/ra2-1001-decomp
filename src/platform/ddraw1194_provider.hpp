#pragma once
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include <vector>
#include <cstring>
#include <stdexcept>
#include "recovered/recovery_b1194.hpp"
#include "platform/x87_state.hpp"
namespace ra2::platform::ddraw1194{
using Caps=recovered::b1194::Caps;using Mode=recovered::b1194::Mode;
inline unsigned pointer(const void*p){static_assert(sizeof(void*)==4u);return unsigned(reinterpret_cast<std::uintptr_t>(p));}inline void need(bool x,const char*s){if(!x)throw std::runtime_error(s);}
struct Identity{unsigned object=0,vptr=0,addref=0,release=0,caps=0,mode=0;bool operator==(const Identity&x)const{return object==x.object&&vptr==x.vptr&&addref==x.addref&&release==x.release&&caps==x.caps&&mode==x.mode;}bool operator!=(const Identity&x)const{return!(*this==x);}};
inline Identity actual_identity(unsigned o){need(o!=0u,"1194 LIVE realfactory output");const auto*v=*reinterpret_cast<const unsigned*const*>(std::uintptr_t(o));return{o,pointer(v),v[1],v[2],v[11],v[12]};}
struct Call{unsigned kind=0,receiver=0,slot=0,arg0=0,arg1=0,arg2=0,result=0,output=0;Identity identity{};Caps caps_before{},caps_after{};Mode mode_before{},mode_after{};};
struct FactoryObservation{unsigned guid=0,output_parameter=0,output_before=0,outer=0,result=0,output=0;Identity identity{};};
// Observer storage is preallocated, POD-only, never reset while any API owner
// lives. It observes the original import boundary; COM vtables remain untouched.
inline std::array<FactoryObservation,512>original_creates{};inline unsigned original_create_count=0;
using Factory=HRESULT(WINAPI*)(GUID*,void**,void*);inline Factory original_factory=nullptr;
extern "C" inline HRESULT WINAPI observe_create1194(GUID*guid,void**out,void*outer){
 const unsigned before=out?pointer(*out):0u;
 const HRESULT result=original_factory(guid,out,outer);
 const auto returned_fp=x87::capture_host();
 // All fields are integer/POD stores. No allocation, API call, AddRef, Release,
 // alternate provider, or substitution is inserted into the original sequence.
 if(original_create_count<original_creates.size()){
  auto&r=original_creates[original_create_count++];r.guid=pointer(guid);r.output_parameter=pointer(out);r.output_before=before;r.outer=pointer(outer);r.result=unsigned(result);r.output=out?pointer(*out):0u;
  if(result==S_OK&&r.output){const auto*v=*reinterpret_cast<const unsigned*const*>(std::uintptr_t(r.output));r.identity={r.output,pointer(v),v[1],v[2],v[11],v[12]};}
 }
 x87::restore_host(returned_fp);return result;
}
class Provider:public recovered::b1194::Api{
 HMODULE module_=nullptr;Factory factory_=nullptr;unsigned owned_=0u;Identity id_{};std::vector<Call>calls_;
 using Ref=ULONG(WINAPI*)(void*);using GetCaps=HRESULT(WINAPI*)(void*,void*,void*);using GetMode=HRESULT(WINAPI*)(void*,void*);
 public:unsigned draw_releases=0,module_release_result=0;char module_path[MAX_PATH]{};
 Provider(){char name[MAX_PATH]{};const unsigned n=GetSystemDirectoryA(name,MAX_PATH);need(n&&n+11u<MAX_PATH,"1194 actualSystem32directory");std::strcat(name,"\\ddraw.dll");module_=LoadLibraryA(name);need(module_!=nullptr,"1194 realSystem32ddrawmodule");need(GetModuleFileNameA(module_,module_path,MAX_PATH)!=0u,"1194 actualmodulepath");factory_=reinterpret_cast<Factory>(GetProcAddress(module_,"DirectDrawCreate"));need(factory_!=nullptr,"1194 realfactoryexport");}
 ~Provider(){if(owned_)reinterpret_cast<Ref>(std::uintptr_t(id_.release))(reinterpret_cast<void*>(std::uintptr_t(owned_)));if(module_)FreeLibrary(module_);}
 Provider(const Provider&)=delete;Provider&operator=(const Provider&)=delete;
 unsigned module()const{return pointer(module_);}unsigned factory()const{return pointer(reinterpret_cast<void*>(factory_));}unsigned owned()const{return owned_;}const std::vector<Call>&calls()const{return calls_;}
 Identity identity()const{need(owned_&&actual_identity(owned_)==id_,"1194 unchanged realCOMidentity whileLIVE");return id_;}
 unsigned create(unsigned guid,unsigned out,unsigned outer)override{
  need(!owned_&&guid==0u&&out&&outer==0u&&*reinterpret_cast<unsigned*>(std::uintptr_t(out))==0u,"1194 exactCreate NULL/outputNULL/NULL");const unsigned hr=unsigned(factory_(reinterpret_cast<GUID*>(std::uintptr_t(guid)),reinterpret_cast<void**>(std::uintptr_t(out)),reinterpret_cast<void*>(std::uintptr_t(outer))));const auto returned=x87::capture_host();const unsigned o=*reinterpret_cast<unsigned*>(std::uintptr_t(out));Call c;c.kind=0u;c.slot=factory();c.arg0=guid;c.arg1=out;c.arg2=outer;c.result=hr;c.output=o;need(hr==unsigned(S_OK)&&o,"1194 positiveactualfactory");owned_=o;id_=actual_identity(o);c.identity=id_;calls_.push_back(c);x87::restore_host(returned);return hr;
 }
 unsigned caps(unsigned object,Caps&hardware,unsigned software)override{
  const auto id=identity();unsigned size=0;std::memcpy(&size,hardware.data(),4);need(object==id.object&&size==316u&&software==0u&&(pointer(hardware.data())&3u)==0u,"1194 fullGetCapsreceiver/316/NULLsoftware");Call c;c.kind=1u;c.receiver=object;c.slot=id.caps;c.arg0=pointer(hardware.data());c.arg1=software;c.identity=id;c.caps_before=hardware;const auto hr=unsigned(reinterpret_cast<GetCaps>(std::uintptr_t(id.caps))(reinterpret_cast<void*>(std::uintptr_t(object)),hardware.data(),nullptr));const auto returned=x87::capture_host();c.result=hr;c.caps_after=hardware;calls_.push_back(c);need(identity()==id,"1194 realGetCapsvtableunchanged");x87::restore_host(returned);return hr;
 }
 unsigned mode(unsigned object,Mode&display)override{
  const auto id=identity();Mode initial{};initial[0]=108u;need(object==id.object&&display==initial&&(pointer(display.data())&3u)==0u,"1194 completeGetDisplayModezero108+size");Call c;c.kind=2u;c.receiver=object;c.slot=id.mode;c.arg0=pointer(display.data());c.identity=id;c.mode_before=display;const auto hr=unsigned(reinterpret_cast<GetMode>(std::uintptr_t(id.mode))(reinterpret_cast<void*>(std::uintptr_t(object)),display.data()));const auto returned=x87::capture_host();c.result=hr;c.mode_after=display;calls_.push_back(c);need(identity()==id,"1194 realGetModevtableunchanged");x87::restore_host(returned);return hr;
 }
 unsigned release(unsigned object)override{const auto id=identity();need(object==id.object,"1194 rawreleaseownedidentity");const unsigned count=reinterpret_cast<Ref>(std::uintptr_t(id.release))(reinterpret_cast<void*>(std::uintptr_t(object)));const auto returned=x87::capture_host();owned_=0;Call c;c.kind=3u;c.receiver=object;c.slot=id.release;c.result=count;c.identity=id;calls_.push_back(c);++draw_releases;need(count==0u,"1194 actualfinalReleasezero");x87::restore_host(returned);return count;}
 void close(){need(!owned_,"1194 allAPIownersreleased");module_release_result=unsigned(FreeLibrary(module_));module_=nullptr;need(module_release_result==unsigned(TRUE),"1194 actualFreeLibraryBOOL1");}
};
}
