#include "recovery_b1404.hpp"
#include "platform/observed_qpc1404.hpp"
#include "recovered/special_b63.hpp"
#include <stdexcept>
namespace ra2::recovered::b1404 {
namespace {
using U=std::uint32_t;using Q=std::uint64_t;using Clock=ra2::platform::qpc1404::Clock;
void need(bool valid,const char* reason){if(!valid)throw std::domain_error(reason);}
Q divide(Memory& m,Q numerator,Q denominator){
    need((numerator>>63u)==0u&&denominator!=0u&&(denominator>>63u)==0u,"B1404 genuine positive signed64 operands");
    special_b63::Inputs call{};call.arg[0]=U(numerator);call.arg[1]=U(numerator>>32u);call.arg[2]=U(denominator);call.arg[3]=U(denominator>>32u);
    return special_b63::fun_0076de10(m,call); //Same Memory type, exact accepted signed64 result.
}
U empty_queue(Memory& m,U head){
    const U node=m.r32(head);need(node==head&&m.r32(head+4u)==head&&m.r32(node+8u)==head,"B1404 original4071F0 empty sentinel");
    return node==m.r32(node+8u)?0u:node; //Actual4072F0.
}
}
std::uint64_t initialize_clock(Memory& m){
    need(m.r32(0x7851ccu)==Clock::frequency_address(),"B1404 genuine QPF import observer binding");
    LARGE_INTEGER frequency{};need(Clock::frequency(&frequency)!=0&&frequency.QuadPart>=1000,"B1404 real successful QPF initialization");
    const Q divisor=divide(m,Q(frequency.QuadPart),1000u);
    floating_b61::write64(m,0x819878u,divisor);m.w32(0x819898u,0x4092e0u);return divisor;
}
std::uint64_t current_time(Memory& m){
    need(m.r32(0x819898u)==0x4092e0u,"B1404 original4092D0 authentic QPC provider");
    need(m.r32(0x7851c8u)==Clock::counter_address(),"B1404 genuine QPC import observer binding");
    LARGE_INTEGER counter{};need(Clock::counter(&counter)!=0&&counter.QuadPart>0,"B1404 real successful QPC result");
    return divide(m,Q(counter.QuadPart),floating_b61::read64(m,0x819878u));
}
std::uint32_t fun_0070a760(Memory& m,const Inputs&){
    need(m.r8(0xa2894cu)==0u&&m.r32(0x819778u)!=0u,"B1404 normal enabled borrowed subsystem");
    const U wrapper=m.r32(0xab83dcu);need(wrapper!=0u&&(m.r32(wrapper+12u)&1u)==0u,"B1404 real nonplaying wrapper flag");
    //Actual408060 returns both words; root ADD/ADC constructs the64-bit deadline.
    const Q timestamp=floating_b61::read64(m,wrapper+0x20u),offset=floating_b61::read64(m,0xab83e0u);
    need(offset==500u&&timestamp<=0xffffffffffffffffull-offset,"B1404 actual producer500ms offset, no deadline overflow");
    const Q deadline=timestamp+offset,now=current_time(m);
    need(now>deadline,"B1404 actual unsigned root comparison strictly past deadline");
    need(m.r32(0xab8348u)==0u,"B1404 no competing request");
    const U record=m.r32(0xab83d4u);need(record!=0u&&m.r32(record+0x48u)==0u,"B1404 current request completion");
    m.w32(record+0x48u,2u);m.w32(0xab83d4u,0u);
    U eax=empty_queue(m,0xab82e8u);need(eax==0u,"B1404 first queue empty");
    eax=empty_queue(m,0xab8310u);need(eax==0u,"B1404 second queue empty");
    need(m.r32(0xab83c8u)==0u,"B1404 no standalone owned request");
    for(U head=0xab8384u;;head-=12u){eax=empty_queue(m,head);need(eax==0u,"B1404 priority sentinel empty");if(head==0xab8360u)break;}
    return eax; //Final4072F0 full0 reaches70A895 epilogue/RET0.
}
}
