#pragma once
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include "platform/x87_state.hpp"
#include <cstdint>
#include <cstring>
#include <stdexcept>
namespace ra2::platform::disk1408 {
using U=std::uint32_t;using Q=std::uint64_t;
struct Event {U module{},resolved{},dispatch{},api_return{},available_pointer{},total_pointer{},free_pointer{},api_fp_checks{};Q available{},total{},free{};};
class Disk {
    using Module=HMODULE(WINAPI*)(LPCSTR);using Lookup=FARPROC(WINAPI*)(HMODULE,LPCSTR);
    using Query=BOOL(WINAPI*)(LPCSTR,PULARGE_INTEGER,PULARGE_INTEGER,PULARGE_INTEGER);
    inline static Disk* active_{};unsigned phase_{};Event event_{};
    Module module_api_{};Lookup lookup_api_{};Query query_api_{};HMODULE genuine_module_{};
    static void need(bool b,const char* s){if(!b)throw std::runtime_error(s);}
    static U address(const void* p){return U(reinterpret_cast<std::uintptr_t>(p));}
    static Disk& current(unsigned phase){need(active_&&active_->phase_==phase,"1408 missing/duplicate/out-of-order API observation");return *active_;}
    void fp(const x87::Image& before){need(x87::same_numeric(before,x87::capture_host()),"1408 real API changed numericFP");++event_.api_fp_checks;}
public:
    Disk(){
        static_assert(sizeof(void*)==4,"1408 actual x86 observer");
        genuine_module_=GetModuleHandleA("KERNEL32.DLL");need(genuine_module_!=nullptr,"1408 genuine kernel32 module");
        module_api_=reinterpret_cast<Module>(GetProcAddress(genuine_module_,"GetModuleHandleA"));
        lookup_api_=reinterpret_cast<Lookup>(GetProcAddress(genuine_module_,"GetProcAddress"));
        query_api_=reinterpret_cast<Query>(GetProcAddress(genuine_module_,"GetDiskFreeSpaceExA"));
        need(module_api_&&lookup_api_&&query_api_,"1408 genuine exports must resolve");
    }
    ~Disk(){if(active_==this)active_=nullptr;}
    Disk(const Disk&)=delete;Disk& operator=(const Disk&)=delete;
    void begin(){need(!active_,"1408 observer already active");event_={};phase_=0;active_=this;}
    Event finish(){need(active_==this&&phase_==3&&event_.api_fp_checks==3,"1408 exactly three actual API calls required");active_=nullptr;phase_=4;return event_;}
    static HMODULE WINAPI module(LPCSTR name){
        auto& s=current(0);need(name&&std::strcmp(name,"KERNEL32.DLL")==0,"1408 original module name");
        const auto before=x87::capture_host();const auto result=s.module_api_(name);s.fp(before);
        need(result==s.genuine_module_&&result,"1408 actual module result");s.event_.module=address(result);s.phase_=1;return result;
    }
    static FARPROC WINAPI lookup(HMODULE module,LPCSTR name){
        auto& s=current(1);need(module==s.genuine_module_&&name&&std::strcmp(name,"GetDiskFreeSpaceExA")==0,"1408 original lookup arguments");
        const auto before=x87::capture_host();const auto result=s.lookup_api_(module,name);s.fp(before);
        need(result&&result==reinterpret_cast<FARPROC>(s.query_api_),"1408 actual resolved export identity");
        s.event_.resolved=address(reinterpret_cast<void*>(result));s.event_.dispatch=address(reinterpret_cast<void*>(&query));s.phase_=2;
        // Explicit observation binding: only the dispatch pointer changes. The
        // genuine result is retained above, and query forwards it unchanged.
        return reinterpret_cast<FARPROC>(&query);
    }
    static BOOL WINAPI query(LPCSTR path,PULARGE_INTEGER available,PULARGE_INTEGER total,PULARGE_INTEGER free){
        auto& s=current(2);need(!path&&available&&total&&free,"1408 original NULL path and output buffers");
        const U a=address(available),t=address(total),f=address(free);
        need(a<=0xffffffe7u&&f==a+8u&&t==a+16u,"1408 exact private output buffer order");
        need(s.event_.resolved==address(reinterpret_cast<void*>(s.query_api_)),"1408 observed genuine target");
        const auto before=x87::capture_host();const BOOL result=s.query_api_(path,available,total,free);s.fp(before);
        s.event_.api_return=U(result);s.event_.available=available->QuadPart;s.event_.total=total->QuadPart;s.event_.free=free->QuadPart;
        s.event_.available_pointer=a;s.event_.total_pointer=t;s.event_.free_pointer=f;s.phase_=3;
        need((U(result)&255u)!=0u,"1408 actual disk query must take original AL-success branch");
        need(s.event_.available>=(Q(1)<<32)&&s.event_.available<(Q(1)<<53),"1408 actual available bytes outside reviewed positive domain");
        return result;
    }
    template<class Memory>static void bind(Memory& m){m.w32(0x785230u,address(reinterpret_cast<void*>(&module)));m.w32(0x785240u,address(reinterpret_cast<void*>(&lookup)));}
    static bool same_observation(const Event& a,const Event& b){return a.module==b.module&&a.resolved==b.resolved&&a.dispatch==b.dispatch&&a.api_return==b.api_return&&a.available==b.available&&a.total==b.total&&a.free==b.free;}
};
}
