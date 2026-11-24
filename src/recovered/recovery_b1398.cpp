#include "recovery_b1398.hpp"
#include "platform/ole_stream951.hpp"
namespace ra2::recovered::b1398 {
namespace {
using U=std::uint32_t;
void need(bool ok,const char* message){ra2::platform::ole_stream951::need(ok,message);}
//4072F0 and407310 have the same exact pointer/sentinel expression.
U first_or_next(Memory& m,U p){
    if(p==0u)return 0u;
    const U next=m.r32(p);
    return next!=0u&&next==m.r32(next+8u)?0u:next;
}
void empty_handle_00405d50(Memory& m,U view){
    need(m.r32(0x8192f8u)==0u,"B1398 actual disabled resource manager");
    m.w32(view+8u,0u); //405E81; no owned resource/provider/free arm.
}
void unlink_00407380(Memory& m,U node){
    const U prev=m.r32(node+4u),next=m.r32(node);
    m.w32(prev,next);m.w32(next+4u,prev);
    m.w32(node,node);m.w32(node+4u,node);
}
void push_00407460(Memory& m,U pool,U node){
    const U block=node-8u,old_head=m.r32(pool);
    m.w32(block,old_head);m.w32(pool,block);
}
void reset_00406dc0_00404e50(Memory& m){
    need(m.r32(0x819778u)==0u&&m.r32(0x8192f8u)==0u,"B1398 exact genuine disabled-provider tail");
    //406DC0 skips403730; actual404E50 seeszero8192F8 and returns.
}
}
std::uint32_t fun_00709740(Memory& m,const Inputs& i){
    namespace ole=ra2::platform::ole_stream951;
    need(i.cx==ole::Stream::current().address(),"B1398 genuine COM IStream");
    const U head=0xab8250u,pool=m.r32(0xab82c4u),node=first_or_next(m,head);
    need(pool!=0u&&node==pool+0x10u&&m.r32(pool)==pool+0x4cu,"B1398 actual100-slot pool after first successful pop");
    need(m.r32(head+4u)==node&&m.r32(head+8u)==head&&m.r32(node)==head&&m.r32(node+4u)==head&&m.r32(node+8u)==0u,"B1398 real single pending queue node");
    need(m.r32(0xab82c8u)==1u&&m.r32(0xab82ccu)>=1u,"B1398 genuine positive pending count");
    need(m.r32(node+0xcu)==0u&&m.r32(node+0x10u)==0u&&m.r32(node+0x14u)==0u&&m.r32(node+0x18u)==0x8192ecu,"B1398 actual initialized unresolved request handle");
    for(U k=0;k<100u;++k){
        const U block=pool+8u+0x44u*k;
        need(m.r32(block)==(k==99u?0u:block+0x44u),"B1398 full borrowed original pool chain");
    }
    const U next=first_or_next(m,node);need(next==0u,"B1398 original next sentinel terminator");
    empty_handle_00405d50(m,node+0xcu);
    unlink_00407380(m,node);
    push_00407460(m,pool,node);
    m.w32(0xab82c8u,m.r32(0xab82c8u)-1u);
    reset_00406dc0_00404e50(m);
    U incoming_count=0u;
    const U hr=U(reinterpret_cast<IStream*>(std::uintptr_t(i.cx))->Read(&incoming_count,4,nullptr));
    need(hr==0u&&incoming_count==0u,"B1398 successful zero-repopulation count read after real queue clear");
    return hr; //7097BF JLE normal epilogue, fullS_OK,RET0.
}
}
