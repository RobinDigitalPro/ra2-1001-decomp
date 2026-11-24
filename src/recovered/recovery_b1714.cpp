#include "recovered/recovery_b1714.hpp"
#include "platform/current_crt_thread.hpp"
#include <stdexcept>
namespace ra2::recovered::b1714 {
namespace {using U=std::uint32_t;void need(bool v){if(!v)throw std::runtime_error("B1714 outside realTLS/action5 produced-clone domain");}}
void initialize_state(Memory&m,U state){m.w32(state+0x50u,0x817b48u);m.w32(state+0x14u,1u);}
U register_action5(Memory&m,Heap& h,U slot){
 U state=ra2::platform::current_crt_thread(slot),table=m.r32(state+0x50u);need(m.r32(0x817bccu)==10u&&m.r32(0x817bc8u)==120u);
 if(table==0x817b48u){table=h.allocate(120u);for(U k=0;k<120u;++k)h.w8(table+k,m.r8(0x817b48u+k));m.w32(state+0x50u,table);}
 need(h.r32(table)==0xc0000005u&&h.r32(table+4u)==11u&&h.r32(table+16u)==4u);U old=h.r32(table+8u);need(old==0u);h.w32(table+8u,5u);return old;
}
U fun_0077992e(Memory&m,const Inputs&i){
 need(m.r32(0x817bccu)==10u&&i.arg[0]==0xc0000005u);
 const auto host=ra2::platform::x87::capture_host();ra2::platform::x87::restore_host(i.fp.image);
 const U state=ra2::platform::current_crt_thread(m.r32(0x817778u));
 i.fp.image=ra2::platform::x87::capture_host();ra2::platform::x87::restore_host(host);
 const U table=m.r32(state+0x50u);need(table!=0x817b48u&&m.r32(table)==0xc0000005u&&m.r32(table+4u)==11u&&m.r32(table+8u)==5u);
 i.arg[0]=5u;m.w32(table+8u,0u);return 1u;
}
}
