#pragma once
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include <cstdint>
#include <array>
#include <stdexcept>
namespace ra2::platform::qpc1404 {
using U=std::uint32_t;using Q=std::uint64_t;
struct Event {U api_return{};Q raw{};};
// Same real-export witness boundary as ticks1378, adapted for two LARGE_INTEGER APIs.
// Neither callback supplies a result: both forward the actual OS call unchanged.
class Clock {
    inline static Clock* active_{};
    enum class Phase {idle,frequency,counter,pair1468};Phase phase_{Phase::idle};unsigned calls_{};Event event_{};std::array<Event,2> pair_{};
    using Api=BOOL(WINAPI*)(LARGE_INTEGER*);
    static void need(bool b,const char* message){if(!b)throw std::runtime_error(message);}
    static Api api(const char* name){
        const auto module=GetModuleHandleW(L"kernel32.dll");need(module!=nullptr,"1404 actual kernel32 module");
        const auto p=reinterpret_cast<Api>(GetProcAddress(module,name));need(p!=nullptr,"1404 actual QPC/QPF export");return p;
    }
    static Api frequency_api(){static const auto p=api("QueryPerformanceFrequency");return p;}
    static Api counter_api(){static const auto p=api("QueryPerformanceCounter");return p;}
    void begin(Phase phase){need(active_==nullptr,"1404 observer already active");phase_=phase;calls_=0;event_={};pair_={};active_=this;}
    Event finish(Phase phase){need(active_==this&&phase_==phase&&calls_==1u,"1404 exactly one actual API call required");active_=nullptr;phase_=Phase::idle;return event_;}
    static BOOL observe(Phase phase,LARGE_INTEGER* output,Api target){
        need(active_&&output,"1404 missing actual API observation");
        const bool pair=active_->phase_==Phase::pair1468&&phase==Phase::counter;
        need(pair?active_->calls_<2u:(active_->phase_==phase&&active_->calls_==0u),"1404 missing/duplicate/wrong-phase actual API call");
        const BOOL result=target(output);const Event e{U(result),Q(output->QuadPart)};
        if(pair)active_->pair_[active_->calls_]=e;else active_->event_=e;
        ++active_->calls_;return result;
    }
public:
    Clock(){static_assert(sizeof(void*)==4,"1404 original x86 IAT width");(void)frequency_api();(void)counter_api();}
    ~Clock(){if(active_==this)active_=nullptr;}
    Clock(const Clock&)=delete;Clock& operator=(const Clock&)=delete;
    static BOOL WINAPI frequency(LARGE_INTEGER* output){return observe(Phase::frequency,output,frequency_api());}
    static BOOL WINAPI counter(LARGE_INTEGER* output){return observe(Phase::counter,output,counter_api());}
    static U frequency_address(){return U(reinterpret_cast<std::uintptr_t>(&frequency));}
    static U counter_address(){return U(reinterpret_cast<std::uintptr_t>(&counter));}
    template<class Memory>void bind(Memory& m){m.w32(0x7851ccu,frequency_address());m.w32(0x7851c8u,counter_address());}
    void begin_pair1468(){begin(Phase::pair1468);}
    std::array<Event,2> finish_pair1468(){
        need(active_==this&&phase_==Phase::pair1468&&calls_==2u,"1468 exactly two actual counter calls");
        active_=nullptr;phase_=Phase::idle;return pair_;
    }
    void begin_frequency(){begin(Phase::frequency);}
    void begin_counter(){begin(Phase::counter);}
    static Q frequency_divisor(const Event& e){need(e.api_return!=0u&&e.raw>=1000u&&(e.raw>>63u)==0u,"1404 real positive QPF and nonzero divisor");return e.raw/1000u;}
    static Q quotient(const Event& e,Q divisor){need(e.api_return!=0u&&e.raw>0u&&(e.raw>>63u)==0u&&divisor>0u&&(divisor>>63u)==0u,"1404 real positive QPC and divisor");return e.raw/divisor;}
    template<class Memory>Event finish_frequency(Memory& m,Q result){
        const Event e=finish(Phase::frequency);const Q d=frequency_divisor(e);
        const Q stored=Q(m.r32(0x819878u))|(Q(m.r32(0x81987cu))<<32u);
        need(stored==d&&result==d&&m.r32(0x819898u)==0x4092e0u,"1404 actual409280 frequency/divisor/provider publication");return e;
    }
    Event finish_baseline(Q divisor,Q result){const Event e=finish(Phase::counter);need(quotient(e,divisor)==result,"1404 complete EDX:EAX baseline matches real QPC");return e;}
    template<class Memory>Event finish_root(Memory& m,Q divisor,Q deadline,U record,U eax){
        const Event e=finish(Phase::counter);need(quotient(e,divisor)>deadline,"1404 actual elapsed time must exceed original deadline");
        need(eax==0u&&m.r32(record+0x48u)==2u&&m.r32(0xab83d4u)==0u,"1404 full root return and positive completion fields");
        const Q stored=Q(m.r32(0x819878u))|(Q(m.r32(0x81987cu))<<32u);
        need(stored==divisor&&m.r32(0x819898u)==0x4092e0u,"1404 genuine provider state unchanged");return e;
    }
};
}
