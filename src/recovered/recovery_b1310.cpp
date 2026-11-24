#include "recovery_b1310.hpp"
#include "recovery_b1308.hpp"
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::b1310 {
namespace { void need(bool v,const char*s){if(!v)throw std::domain_error(s);} }
U run(global_b26::Memory& m,const Inputs& i){
    // Bounded positive 0x4cd520 route: one borrowed query and one House-list element.
    constexpr U self_vt=0x0078612cu, candidate_vt=0x00787bbcu;
    need(i.cx!=0u&&m.r32(i.cx)==self_vt,"B1310 original receiver vptr 0x78612c");
    need(m.r32(self_vt+0x4b0u)==0x004cd360u,"B1310 original +4b0 helper route");
    need(m.r32(self_vt+0x2cu)==0x0041b580u,"B1310 kind-2 getter selects distance bypass");
    const U query_list=i.arg[0];
    need(query_list!=0u&&m.r32(query_list+0x10u)==1u,"B1310 one-element caller query list");
    const U query_items=m.r32(query_list+4u),query=m.r32(query_items);
    need(query_items!=0u&&query!=0u&&m.r32(i.cx+0x1b4u)!=0u,"B1310 valid query element and House owner");
    need(i.arg[2]==1u,"B1310 arg2=1 bypasses original 0x62e470 predicate");

    const U owner=m.r32(i.cx+0x1b4u),type_index=m.r32(query+0xb90u);
    const U counts=owner+0x5420u,count=m.r32(counts+8u),counter_data=m.r32(counts+4u);
    need(type_index==0u&&count>type_index&&counter_data!=0u&&m.r32(counter_data+type_index*4u)!=0u,
         "B1310 0x491af0 original count/index-positive vector slot");
    const U house_count=m.r32(owner+0x78u),house_items=m.r32(owner+0x6cu);
    need(house_count==1u&&house_items!=0u,"B1310 borrowed populated House +6c/+78 building list");
    const U candidate=m.r32(house_items);
    need(candidate!=0u&&m.r32(candidate)==candidate_vt,"B1310 authentic kind-6 candidate vptr");
    need(m.r8(candidate+0x76u)==0u&&m.r32(candidate+0x418u)==query,
         "B1310 original 4cd360 candidate clear/type-identity filters");

    // 4cd360 sees the receiver kind getter return 2 and skips its 54cc50 geometry filter.
    // It then invokes receiver+258 -> 62e120 -> 62dff0 -> candidate+17c (439670).
    need(m.r32(self_vt+0x258u)==0x0062e120u&&m.r32(self_vt+0x25cu)==0x0062dff0u,
         "B1310 original action-15 wrapper slots");
    need(m.r32(candidate_vt+0x17cu)==0x00439670u,"B1310 candidate action-15 target 439670");
    b1308::Inputs leaf{};leaf.cx=candidate;leaf.arg[0]=i.cx;leaf.arg[1]=15u;leaf.arg[2]=0x00a28820u;
    const U nested=b1308::run(m,leaf);
    need(nested==1u,"B1310 nested original action-15 callback succeeds");

    // Original 5cd430 score: self+48 copies self+88 xyz; candidate+48 computes
    // candidate+88 xyz plus (type-table-cell*128-128) in X/Y. Index zero uses
    // the canonical table values 1/1, hence zero translation; fixture points match.
    need(m.r32(self_vt+0x48u)==0x005cd4d0u&&m.r32(candidate_vt+0x48u)==0x00443e10u,
         "B1310 exact 5cd430 coordinate getter targets");
    const U point_index=m.r32(query+0xc78u);
    need(point_index==0u&&m.r32(0x007bac60u+point_index*4u)==1u&&m.r32(0x007bac08u+point_index*4u)==1u,
         "B1310 canonical 4585c0/4585b0 coordinate table entries");
    const U sx=m.r32(i.cx+0x88u),sy=m.r32(i.cx+0x8cu),sz=m.r32(i.cx+0x90u);
    const U bx=m.r32(candidate+0x88u),by=m.r32(candidate+0x8cu),bz=m.r32(candidate+0x90u);
    const U dx=sx-bx,dy=sy-by;
    const U score=dx*dx+dy*dy; // Original 5CD430 ignores Z.
    (void)sz;(void)bz;

    // 4cd520 captures the input list pointer in EBX, then aliases the caller's
    // arg0 stack word as the child score output. It writes -1 before the helper,
    // and the successful score 0 remains visible to the caller on RET 12.
    i.arg[0]=score;
    return candidate;
}
}

namespace ra2::recovered::b1310 {
U command(Memory&m,const Inputs&i){
 const U self=i.cx;need(self!=0u,"1310 commandnonnullreceiver");
 if(i.arg[1]==15u){const U old=m.r32(self+0xbcu);need(old!=15u,"1310 positivehistoryrotation");m.w32(self+0xc4u,m.r32(self+0xc0u));m.w32(self+0xc0u,old);m.w32(self+0xbcu,15u);return 0u;}
 need(i.arg[1]==31u&&m.r32(self)==0x78612cu,"1310 originalcommand31 receiver");need(m.r32(0x7861acu)==0x6b6910u&&m.r32(0x7861b0u)==0x41b600u,"1310 actualtypegetterchain");
 const U type=m.r32(self+0x5acu),old=m.r32(self+0x254u);need(type!=0u&&old!=m.r32(type+0x5acu),"1310 positiveincrementbranch");m.w32(self+0x254u,old+1u);return 1u;
}}
