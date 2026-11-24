#pragma once
// Independent fixture and state oracle, excluded from recovered production code.
#include "platform/entity_vectors1048.hpp"
namespace ra2::platform::entity_membership1053 {
namespace b=b1053_test;namespace old=ra2::platform::entity_vectors1048;
using old::need;using Observation=old::Observation;using old::compare;using old::cleanup;
struct World {
 unsigned root,base;b::Case c;old::World prior;
 World(unsigned r,unsigned a,b::Case v):root(r),base(a),c(v),prior(0x2b72a0u,a,v){}
 unsigned type()const{return prior.type();}unsigned receiver()const{return prior.receiver();}unsigned house()const{return base+0x52000u;}unsigned record()const{return base+0x54000u;}unsigned list()const{return base+0x55000u;}
 std::vector<unsigned>allocation_sizes()const{return{};}unsigned fixture_count()const{return 0u;}std::vector<unsigned>free_order()const{return{};}
 void setup(b::Memory&m,unsigned char*arena,b::HeapAdapter&heap)const{prior.setup(m,arena,heap);m.w32(house()+0x34u,record());m.w8(house()+0x207u,0u);m.w8(type()+0x701u,0u);const unsigned vec=record()+0x168u;m.w32(vec,0x78e0d8u);m.w32(vec+4u,list());m.w32(vec+8u,8u);m.w8(vec+0xcu,1u);m.w8(vec+0xdu,0u);m.w32(vec+0x10u,c.count);m.w32(vec+0x14u,10u);m.w32(vec+0x18u,0u);for(unsigned k=0;k<8u;++k)m.w32(list()+4u*k,k==c.index?type():base+0x56000u+0x100u*k);}
 b::Inputs input()const{return prior.input();}std::array<unsigned,16>caller()const{return input().arg;}auto expected_fp()const{return prior.expected_fp();}
 void normalize_before(std::vector<unsigned char>&,const b::HeapAdapter&)const{}
};
inline Observation verify(const World&w,b::HeapAdapter&h,unsigned eax,const ra2::platform::x87::Image&fp,const std::vector<unsigned char>&bi,const std::vector<unsigned char>&ba,const unsigned char*image,const unsigned char*arena){
 need(h.addresses.empty()&&h.events().empty()&&h.snapshots.empty()&&h.live().empty(),"1053 no hidden allocation/free/provider activity");auto ei=bi,ea=ba;w.prior.expected_memory(ei,ea,h);b1048_test::word(ea,w.receiver()+0x118u-w.base,0u);b1048_test::word(ea,w.receiver()+0x11cu-w.base,0x3ff00000u);need(std::equal(ei.begin(),ei.end(),image)&&std::equal(ea.begin(),ea.end(),arena),"1053 independent entire original image and guarded1MiB arena including membership list, house/type, base stats and exact binary64 one");need(eax==w.type(),"1053 full EAX actual type pointer, not typeAC4 or masked byte");need(ra2::platform::x87::same_numeric(fp,w.expected_fp()),"1053 independent CW/status0100/empty tags/all80 x87 bytes");Observation o;o.scalar=eax;o.image=std::move(ei);o.arena=std::move(ea);return o;
}
}
