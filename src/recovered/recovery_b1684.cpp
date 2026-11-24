#include "recovery_b1684.hpp"
#include <stdexcept>
namespace ra2::recovered::b1684 {
namespace {
void require(bool p){if(!p)throw std::invalid_argument("DDF10 excluded finite component contract");}
void empty_vector(Memory&m,unsigned a,unsigned table){
    require(m.r32(a)==table&&m.r32(a+4u)==0u&&m.r32(a+8u)==0u);
    require(m.r8(a+12u)==1u&&m.r8(a+13u)==0u);
    require(m.r32(a+16u)==0u&&m.r32(a+20u)==10u);
}
unsigned surface(Memory&m,unsigned slot,bool clear){
    const unsigned a=m.r32(slot);require(a!=0u&&m.r32(a)==0x785ef8u);
    require(m.r32(a+4u)==1u&&m.r32(a+8u)==1u&&m.r32(a+12u)==0u&&m.r32(a+16u)==2u);
    require(m.r32(a+20u)!=0u&&m.r32(a+24u)==2u);
    require(m.r32(0x785ef8u+(clear?0x18u:4u))==(clear?0x760760u:0x7607a0u));
    if(clear)require(m.r32(0x785ef8u+0x10u)==0x75fd00u);
    require(m.r32(0x785ef8u+0x78u)==0x411290u);
    return a;
}
void clear_empty(Memory&m,unsigned a){
    // Exact selected null-backed +C helper path: valid/count/growth/padding
    // remain unchanged; only owner and capacity are written.
    m.w8(a+13u,0u);m.w32(a+8u,0u);
}
}
unsigned run(Memory&m,const Inputs&in,Heap&heap,Observation&out){
    out={};const unsigned self=in.cx;
    require(self!=0u&&m.r32(self)==0x78db3cu&&m.r32(self+4u)==0x791ffcu&&m.r32(self+8u)==0u);
    require(m.r32(self+12u)==0x790e98u&&m.r32(self+16u)!=0u&&m.r32(self+20u)==20u);
    require(m.r8(self+24u)==1u&&m.r8(self+25u)==1u);
    empty_vector(m,self+0x1cu,0x79202cu);empty_vector(m,self+0x34u,0x79200cu);
    empty_vector(m,self+0x58u,0x78db44u);
    require(m.r32(0x78db88u)==0x4de620u);
    require(m.r32(0x792018u)==0x5b04a0u&&m.r32(0x792038u)==0x5b0440u&&m.r32(0x790ea4u)==0x58b490u);
    require(m.r32(self+0x4cu)!=0u&&m.r32(self+0x50u)!=0u&&m.r32(self+0x54u)==0u);
    m.w32(self,0x78db3cu);out.stage=1u;
    // Derived count0 makes genuine iterator DE620 return full0; no elements.
    const unsigned first=surface(m,0x821c98u,true);
    m.w16(m.r32(first+20u),0u);out.stage=2u;
    const unsigned second=surface(m,0x821c94u,true);
    require(first!=second);m.w16(m.r32(second+20u),0u);out.stage=3u;
    const unsigned third=surface(m,0x821c90u,false);
    require(third!=first&&third!=second);
    // Actual virtual7607A0 arguments(src=second,0,1), finite 1x1 format2.
    m.w16(m.r32(third+20u),m.r16(m.r32(second+20u)));out.stage=4u;
    m.w32(self+0x58u,0x78db64u);
    // Null derived backing skips conditional pointer clear/free.
    m.w8(self+0x65u,0u);m.w32(self+0x60u,0u);out.stage=5u;
    // String759320 releases while each owning field still contains pointer.
    (void)heap.release(m.r32(self+0x50u));++out.releases;
    m.w32(self+0x50u,0u);out.stage=6u;
    (void)heap.release(m.r32(self+0x4cu));++out.releases;
    m.w32(self+0x4cu,0u);out.stage=7u;
    // Base5AF850: empty object-vector loops; normal +C methods zero count
    // before pointer/owner/cap processing and run BEFORE their
    // later final table writes. Numeric +C58B490 releases its real80 bytes.
    m.w32(self+4u,0x791ffcu);
    m.w32(self+0x44u,0u);clear_empty(m,self+0x34u);
    m.w32(self+0x2cu,0u);clear_empty(m,self+0x1cu);
    const unsigned numeric=m.r32(self+0x10u);
    (void)heap.release(numeric);++out.releases;
    m.w32(self+0x10u,0u);m.w8(self+0x19u,0u);m.w32(self+0x14u,0u);out.stage=8u;
    m.w32(self+0x34u,0x79206cu);clear_empty(m,self+0x34u);
    m.w32(self+0x1cu,0x79204cu);clear_empty(m,self+0x1cu);
    // 5AF914 reloads already-cleared numeric backing, so final full EAX=0
    // independently of every actual HeapFree return value.
    const unsigned result=m.r32(self+0x10u);
    m.w32(self+0x0cu,0x790e98u);clear_empty(m,self+0x0cu);
    out.stage=9u;return result;
}
unsigned run(Memory&m,const Inputs&in,Heap&heap){Observation out;return run(m,in,heap,out);}
}

