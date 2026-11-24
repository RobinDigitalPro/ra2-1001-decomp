#include "recovery_b1318.hpp"
#include "recovered/global_b26_memory.hpp"
#include <array>
#include <cstdint>
#include <stdexcept>
namespace ra2::recovered::global_b26 { std::uint32_t fun_00545500(Memory&,const Inputs&); }
namespace ra2::recovered::b1318 {
namespace {
void need(bool ok,const char* why){if(!ok)throw std::domain_error(why);}
constexpr unsigned pack(unsigned x,unsigned y){return ((y&0xffffu)<<16u)|(x&0xffffu);}
constexpr unsigned grid_global=0x0081a958u,global_map=0x0081a820u,fallback_cell=0x00a57610u;
unsigned lookup(Memory& source,unsigned x,unsigned y){
 const int sx=static_cast<std::int16_t>(x),sy=static_cast<std::int16_t>(y); const int index=sy*512+sx;
 if(index<0||index>=0x40000){source.w32(0x00a57634u,pack(x,y));return fallback_cell;}
 std::array<std::uint8_t,8> bytes{}; constexpr unsigned stack=0x7c010000u;
 Memory local=source; ra2::recovered::leaf::Memory span(bytes.data(),stack,unsigned(bytes.size())); local.add(span);
 local.w32(stack,pack(x,y)); Inputs q{};q.cx=global_map;q.arg[0]=stack;
 return ra2::recovered::global_b26::fun_00545500(local,q);
}
void negative_probe(Memory&m,unsigned x,unsigned y,unsigned expected){
 need(lookup(m,x,y)==fallback_cell,"B1318 authentic negative 0x545500 fallback pointer");
 need(m.r32(0x00a57634u)==expected,"B1318 fallback coordinate producer");
 need(m.r32(fallback_cell+0x44u)==0u,"B1318 original fallback category zero");
}
}
unsigned run(unsigned root,Memory&m,const Inputs&i,Heap&heap){
 need(root==0x001539b0u||root==0x00154520u,"B1318 exact two-root pair");
 const auto coord=i.arg[0];need(coord!=0u,"B1318 outer coordinate pointer");
 need(m.r32(coord)==pack(22u,0u),"B1318 arena input remains packed(22,0)");
 const auto grid=m.r32(grid_global);need(grid!=0u&&m.r32(global_map+0x138u)==grid,"B1318 authentic global lookup table");
 const auto receiver=i.cx;need(receiver!=global_map&&m.r32(receiver)==0x0079091cu,"B1318 borrowed zone receiver distinct from global Map");
 // Literal 5x5 root scan: x=20 at center-column, y runs -2,-1,0.
 // Preserve full signed coordinates and publish the exact two fallback writes.
 negative_probe(m,20u,0xfffeu,pack(20u,0xfffeu));
 negative_probe(m,20u,0xffffu,pack(20u,0xffffu));
 need(m.r32(coord)==pack(22u,0u),"B1318 scan scratch does not change original arena coordinate");
 const auto cell=lookup(m,20u,0u);need(cell!=fallback_cell,"B1318 third probe selects populated center through accepted 0x545500");
 const auto category=m.r32(cell+0x44u);
 const auto expected=root==0x001539b0u?0xcdu:0x4au;
 need(category==expected,"B1318 selected center category arm");
 // Root's matched coordinate aliases caller arg0 and is packed(20,0).
 i.arg[0]=pack(20u,0u);
 // The selected accepted B1299 child takes a pointer to a separate local
 // word; its own caller-arg overwrite must not leak into B1318's outer arg.
 std::array<std::uint8_t,8> bytes{};constexpr unsigned nested_stack=0x7c020000u;
 Memory nested_memory=m;ra2::recovered::leaf::Memory span(bytes.data(),nested_stack,unsigned(bytes.size()));nested_memory.add(span);
 nested_memory.w32(nested_stack,pack(20u,0u));
 Inputs nested=i;nested.arg[0]=nested_stack;
 const unsigned child=root==0x001539b0u?0x001542c0u:0x00154080u;
 const auto result=ra2::recovered::b1299::run(child,nested_memory,nested,heap);
 need(i.arg[0]==pack(20u,0u),"B1318 outer arg0 remains packed(20,0) after nested overwrite");
 need(m.r32(coord)==pack(22u,0u),"B1318 original caller coordinate remains packed(22,0)");
 need(m.r32(0x00a57634u)==pack(21u,1u),"B1318 selected child final fallback coordinate");
 return result; // full EAX is the actual viewport pointer; wrapper RET 4.
}
}

