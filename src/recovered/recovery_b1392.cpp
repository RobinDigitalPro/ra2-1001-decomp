#include "recovery_b1392.hpp"
#include "platform/ole_stream951.hpp"
namespace ra2::recovered::b1392 {
namespace {
using U=std::uint32_t;
void need(bool ok,const char* message){ra2::platform::ole_stream951::need(ok,message);}
U inhibited_00407e60(Memory& m,U wrapper){
    const U inhibited=m.r32(wrapper+0x88u);
    need(inhibited>=1u&&inhibited<=7u,"B1392 actual positive inhibit count");
    return inhibited; //407E6B directly reachesPOP ESI/RET, no backend/API call.
}
U empty_004072f0(Memory& m,U head){
    const U node=m.r32(head);
    need(node==head&&m.r32(node+4u)==head&&m.r32(node+8u)==head,"B1392 real initialized empty sentinel");
    return node==m.r32(node+8u)?0u:node;
}
U empty_0070a370(Memory& m){
    need(m.r32(0xab83ccu)==1u&&m.r32(0xab83c8u)==0u,"B1392 initialized queue subsystem without standalone node");
    U eax=empty_004072f0(m,0xab8310u);
    need(eax==0u,"B1392 first initialized empty queue");
    eax=empty_004072f0(m,0xab82e8u);
    need(eax==0u,"B1392 second initialized empty queue");
    for(U head=0xab8360u;head<0xab8390u;head+=12u){
        eax=empty_004072f0(m,head);
        need(eax==0u,"B1392 priority queues initialized empty");
    }
    return eax;
}
}
std::uint32_t fun_0070b390(Memory& m,const Inputs& i){
    namespace ole=ra2::platform::ole_stream951;
    const U stream=i.cx;
    need(stream==ole::Stream::current().address(),"B1392 genuine live COM IStream");
    const U record=m.r32(0xab83d4u),wrapper=m.r32(0xab83dcu);
    need(record!=0u&&m.r32(record+0x48u)==0u,"B1392 actual current request record");
    need(wrapper!=0u&&m.r32(wrapper+0x14u)!=0u,"B1392 borrowed live wrapper and backend");
    m.w32(record+0x48u,2u);m.w32(0xab83d4u,0u);
    (void)inhibited_00407e60(m,wrapper);
    (void)empty_0070a370(m);
    auto* p=reinterpret_cast<IStream*>(std::uintptr_t(stream));
    U word=0;
    const U first=U(p->Read(&word,4,nullptr));
    need(first==0u&&word==0x566f7853u,"B1392 exact genuine successful header Read");
    const U second=U(p->Read(&word,4,nullptr));
    need(second==0u&&word==0x566f7845u,"B1392 exact genuine successful end Read");
    return second; //Normal70B470 epilogue, fullS_OK; both buffers areprivate.
}
}
