#include "recovered/recovery_b1533.hpp"
#include "platform/observed_queue1533.hpp"
namespace ra2::recovered::b1533 {
std::uint32_t fun_005b29f0(Memory& m,const Inputs&i){
 using namespace platform::queue1533;
 need(m.r32(0xb0de50)!=0&&m.r32(0xa39eec)==0&&!m.r32(0x821cf0)&&!m.r32(0xa59528)&&!m.r32(0xa59550)&&!m.r32(0xa595bc),"1533 selected cold enabled singleWM_CHAR domain");
 need(m.r32(0x785464)==ptr(reinterpret_cast<void*>(&peek))&&m.r32(0x7854b0)==ptr(reinterpret_cast<void*>(&translate))&&m.r32(0x7854b4)==ptr(reinterpret_cast<void*>(&dispatch)),"1533 authenticated forwarders");
 m.w32(0xa39ed8,m.r32(0xa39ed8)+1u);MSG msg{};
 // Caller-local specialization of actual522410 cold mode0 and mode1.
 auto poll=[&](U flags){return guest(i.fp.image,[&]{return peek(&msg,nullptr,0,0,flags);});};
 need(poll(0)!=FALSE,"1533 actual firstpoll positive");
 need(poll(1)!=FALSE&&msg.message==WM_CHAR,"1533 5223D0 mode1 success/nonQUIT");
 // Actual491790 branches directly to RET for WM_CHAR != BEEF.
 guest(i.fp.image,[&]{return translate(&msg);});guest(i.fp.image,[&]{return dispatch(&msg);});
 need(poll(0)==FALSE,"1533 singlemessage finalpoll empty");return 0u;
}
}
