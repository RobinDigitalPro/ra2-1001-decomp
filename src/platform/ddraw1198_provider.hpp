#pragma once
#include "platform/ddraw1193_provider.hpp"
#include "platform/x87_state.hpp"
#include "recovered/recovery_b1198.hpp"
namespace ra2::platform::ddraw1198{
using Desc=recovered::b1198::Descriptor;
using Base=ddraw1193::Provider;inline unsigned pointer(const void*p){return ddraw1193::pointer(p);}inline void need(bool x,const char*s){ddraw1193::need(x,s);}
struct Identity{unsigned object=0,vptr=0,addref=0,release=0,getdesc=0,lost=0,lock=0,unlock=0;bool operator==(const Identity&x)const{return object==x.object&&vptr==x.vptr&&addref==x.addref&&release==x.release&&getdesc==x.getdesc&&lost==x.lost&&lock==x.lock&&unlock==x.unlock;}bool operator!=(const Identity&x)const{return!(*this==x);}};
struct Call{unsigned kind=0,receiver=0,slot=0,rect=0,descriptor=0,flags=0,event=0,pixels=0,result=0;Identity identity{};Desc before{},after{};};
class Provider:public Base,public recovered::b1198::Api{
 std::vector<Call>operations_;
 using Lost=HRESULT(WINAPI*)(void*);using Lock=HRESULT(WINAPI*)(void*,RECT*,void*,DWORD,HANDLE);using Unlock=HRESULT(WINAPI*)(void*,void*);
 public:const std::vector<Call>&operations()const{return operations_;}
 Identity lock_identity()const{const auto actual=surface_identity();const auto*v=*reinterpret_cast<const unsigned*const*>(std::uintptr_t(actual.object));need(actual.vptr==pointer(v),"1198 actualunchangedbaseprovider surface identity");return{actual.object,pointer(v),v[1],v[2],v[22],v[24],v[25],v[32]};}
 unsigned is_lost(unsigned surface)override{const auto id=lock_identity();need(surface==id.object,"1198 actualIsLostreceiver");Call c;c.kind=0;c.receiver=surface;c.slot=id.lost;c.identity=id;const unsigned result=unsigned(reinterpret_cast<Lost>(std::uintptr_t(id.lost))(reinterpret_cast<void*>(std::uintptr_t(surface))));const auto returned=x87::capture_host();c.result=result;operations_.push_back(c);need(lock_identity()==id,"1198 actualIsLostnoCOMvptrmutation");x87::restore_host(returned);return result;}
 unsigned lock(unsigned surface,Desc&descriptor)override{const auto id=lock_identity();Desc initial{};initial[0]=108u;need(surface==id.object&&descriptor==initial&&(pointer(descriptor.data())&3u)==0u,"1198 exactLockrealreceiver NULLrect zero108+size flags1 NULLHANDLE");Call c;c.kind=1u;c.receiver=surface;c.slot=id.lock;c.descriptor=pointer(descriptor.data());c.flags=1u;c.identity=id;c.before=descriptor;const unsigned result=unsigned(reinterpret_cast<Lock>(std::uintptr_t(id.lock))(reinterpret_cast<void*>(std::uintptr_t(surface)),nullptr,descriptor.data(),1u,nullptr));const auto returned=x87::capture_host();c.result=result;c.after=descriptor;operations_.push_back(c);need(lock_identity()==id,"1198 realLocknoCOMvptrmutation");x87::restore_host(returned);return result;}
 unsigned unlock(unsigned surface,unsigned pixels)override{const auto id=lock_identity();need(surface==id.object&&pixels>=0x10000u,"1198 exactUnlockrealreceiver andrawpriorLockpointer");Call c;c.kind=2u;c.receiver=surface;c.slot=id.unlock;c.pixels=pixels;c.identity=id;const unsigned result=unsigned(reinterpret_cast<Unlock>(std::uintptr_t(id.unlock))(reinterpret_cast<void*>(std::uintptr_t(surface)),reinterpret_cast<void*>(std::uintptr_t(pixels))));const auto returned=x87::capture_host();c.result=result;operations_.push_back(c);need(lock_identity()==id,"1198 actualUnlocknoCOMvptrmutation");x87::restore_host(returned);return result;}
};
}
