#include "recovered/recovery_b1468.hpp"
#include "recovered/recovery_b1467.hpp"
#include "recovered/recovery_b1404.hpp"
#include "recovered/recovery_b1367.hpp"
#include <stdexcept>
namespace ra2::recovered::b1468 {
namespace {
using U=std::uint32_t;using Q=std::uint64_t;
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
U sound_tick(Memory&m){
 // Complete selected708EF0 path: actual4072F0 on the4071F0-produced head.
 const U head=0xab8250u,node=m.r32(head);
 need(node==head&&m.r32(head+4u)==head&&m.r32(node+8u)==head,"1468 authentic empty sound list");
 return 0u;
}
U cursor_tick(Memory&m){
 // Actual25-byte75D100. No current cursor object; no75ED40 or OS API call.
 const U result=m.r32(0xb103fcu);
 need(result==0u&&m.r32(0xb103f4u)==0u,"1468 actual no-current-cursor state");
 return result;
}
}
U fun_00406ea0(Memory&m,const Inputs&i){
 need(m.r32(0x8197acu)==0u&&m.r32(0x819778u)!=0u,"1468 enabled nonreentrant coordinator");
 m.w32(0x8197acu,1u);
 const Q now=b1404::current_time(m);
 const Q before=floating_b61::read64(m,0x8197b0u);
 // Original SUB/SBB uses an unsigned64 difference. This declared positive
 // elapsed domain excludes wraparound; the true QPC observation proves it.
 need(now>=before&&now-before>33u,"1468 actual positive elapsed scheduler interval");
 (void)b1467::fun_004041b0(m,i);
 (void)sound_tick(m);
 (void)b1404::fun_0070a760(m,i);
 Inputs queued=i;queued.cx=0xa1e0a8u;
 (void)b1367::fun_006dcf90(m,queued);
 const U eax=cursor_tick(m);
 floating_b61::write64(m,0x8197b0u,now);
 m.w32(0x8197acu,0u);
 return eax;
}
}
