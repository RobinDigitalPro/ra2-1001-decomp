#pragma once
// Final-member and rational-table reference oracle, independent of the
// recovered construction order and original signed-magic arithmetic.
#include <algorithm>
#include <cstdint>
#include <stdexcept>
namespace ra2::platform::conversion1063{
namespace b=b1063_test;namespace ref=b1063_oracle;
inline void need(bool v,const char*s){if(!v)throw std::domain_error(s);}
struct World{
 unsigned root,base;b::Case c;static constexpr unsigned arena_size=65536u;
 World(unsigned r,unsigned a,b::Case v):root(r),base(a),c(v){}
 bool one()const{return c.second==1u;}unsigned receiver()const{return base+0x400u;}
 unsigned fixture_count()const{return one()?2u:1u;}unsigned output_count()const{return one()?25u:91u;}
 unsigned source_size()const{return c.count*(one()?256u:512u);}unsigned middle()const{return((c.count-1u)/2u)*(one()?256u:512u);}
 unsigned return_ordinal()const{return fixture_count()+(one()?24u:25u);}
 std::vector<unsigned>allocation_sizes()const{std::vector<unsigned>v{source_size()};if(one())v.push_back(256u);if(one())for(const auto&d:ref::one_byte_blocks)v.push_back((d.requested+15u)&~15u);else for(const auto&d:ref::two_byte_blocks)v.push_back((d.requested+15u)&~15u);return v;}
 std::vector<unsigned>free_order()const{return{};}
 unsigned member_value(unsigned off,const b::HeapAdapter&h)const{switch(off){case 0x16cu:return c.count;case 0x170u:return h.addresses.at(0u);case 0x174u:return h.addresses.at(0u)+middle();case 0x178u:return one()?h.addresses.at(1u):0u;case 0x180u:return c.point?0x3defu:0x7befu;case 0x184u:return c.point?0x1ce7u:0x39e7u;default:throw std::domain_error("1063 reference unexpected member");}}
 std::vector<unsigned char>input_block(unsigned id)const{const auto sizes=allocation_sizes();auto bytes=b::fresh(id,sizes.at(id));for(unsigned k=0;k<bytes.size();++k)bytes[k]^=static_cast<unsigned char>(b::mix(c.seed+71u*id+k));return bytes;}
 void setup(b::Memory&m,unsigned char*arena,b::HeapAdapter&h)const{need(root==0x838e0u&&h.addresses.empty(),"1063 empty fixture heap");for(unsigned k=0;k<arena_size;++k)arena[k]=static_cast<unsigned char>(b::mix(c.seed+131u*k));
  // Same original83430-produced owner header and backing extent,188 bytes
  // proved at4A6B67. Target is initialization after those field producers.
  for(unsigned id=0;id<fixture_count();++id){const auto p=h.allocate(allocation_sizes()[id]);need(p!=0u,"1063 genuine fixture-owned source allocation");auto bytes=input_block(id);for(unsigned k=0;k<bytes.size();++k)h.w8(p+k,bytes[k]);}
  m.w32(receiver(),0x788f70u);m.w32(receiver()+4u,c.second);for(unsigned off=8u;off<=0x168u;off+=4u)m.w32(receiver()+off,0u);m.w32(receiver()+0x17cu,0u);
  for(unsigned off:{0x16cu,0x170u,0x174u,0x178u,0x180u,0x184u})m.w32(receiver()+off,member_value(off,h));
  // Exact original41E320 empty cache. The original's unmodified786800+8
  // virtual41E7F0 allocates its first owned10-cell backing during the target.
  m.w32(0x824920u,0x786800u);m.w32(0x824924u,0u);m.w32(0x824928u,0u);m.w8(0x82492cu,1u);m.w8(0x82492du,0u);m.w32(0x824930u,0u);m.w32(0x824934u,10u);
 }
 b::Inputs input()const{b::Inputs i{};i.ax=b::mix(c.seed+1u);i.cx=receiver();i.dx=b::mix(c.seed+2u);for(unsigned k=0;k<16u;++k)i.arg[k]=b::mix(c.seed+73u*k+17u);return i;}
 std::array<unsigned,16>caller()const{return input().arg;}ra2::platform::x87::Image expected_fp()const{return ra2::platform::x87::Image::empty(static_cast<std::uint16_t>(c.control));}
 unsigned field_value(const ref::Field&v,const b::HeapAdapter&h)const{switch(v.kind){case 0u:return v.value;case 1u:return member_value(v.value,h);case 2u:return receiver()+v.value;case 3u:return h.addresses.at(fixture_count()+v.value);default:throw std::domain_error("1063 reference field kind");}}
 const ref::Field*fields(unsigned id,unsigned&n)const{return one()?ref::one_byte_fields(id,n):ref::two_byte_fields(id,n);}
 template<class F>void members(F f)const{if(one()){for(const auto&v:ref::one_byte_members)f(v);}else{for(const auto&v:ref::two_byte_members)f(v);}}
 std::vector<unsigned char>block(unsigned id,const b::HeapAdapter&h)const{if(id<fixture_count())return input_block(id);const auto local=id-fixture_count();auto bytes=b::fresh(id,allocation_sizes().at(id));if(!one()&&local==25u){
   // 0x82061029 is ceil(2^46/32258). For0<=numerator<=65025*52,
   // its approximation error is less than1/32258, hence exact positive floor.
   for(unsigned y=0;y<256u;++y)for(unsigned x=0;x<256u;++x){const auto q=std::min(c.count-1u,(x*y*(c.count-1u))/32258u),off=2u*(256u*y+x);bytes[off]=0u;bytes[off+1u]=static_cast<unsigned char>(q);}
   b::word(bytes,0x20000u,c.count);b::word(bytes,0x20004u,39u);return bytes;
  }if(!one()&&local==26u){b::word(bytes,0u,h.addresses.at(fixture_count()+25u));return bytes;}unsigned n=0u;const auto*items=fields(local,n);for(unsigned j=0;j<n;++j){const auto&v=items[j];const auto value=field_value(v,h);for(unsigned k=0;k<v.width;++k)bytes.at(v.offset+k)=static_cast<unsigned char>(value>>(8u*k));}return bytes;
 }
 void expected_memory(std::vector<unsigned char>&arena,const b::HeapAdapter&h)const{members([&](const auto&v){b::word(arena,receiver()+v.offset-base,h.addresses.at(fixture_count()+v.ordinal));});}
 unsigned token(const b::HeapAdapter&h,unsigned value,unsigned id,unsigned off=0u)const{const auto size=allocation_sizes().at(id);need(value==h.addresses.at(id)+off&&off<size,"1063 exact raw pointer to known ordinal+offset");const auto whole=h.identify(h.addresses.at(id),size),point=h.identify(value,1u);need(whole.ordinal==id&&whole.offset==0u&&point.ordinal==id&&point.offset==off,"1063 whole LIVE allocation extent and precise pointer offset");return 0xd0630000u+id*0x10000u+off;}
 unsigned normalize_inputs(std::vector<unsigned char>&arena,const b::HeapAdapter&h)const{unsigned n=0u;for(unsigned off:{0x170u,0x174u}){const auto p=receiver()+off-base;b::word(arena,p,token(h,b::readword(arena,p),0u,off==0x174u?middle():0u));++n;}if(one()){const auto p=receiver()+0x178u-base;b::word(arena,p,token(h,b::readword(arena,p),1u));++n;}return n;}
 void normalize_before(std::vector<unsigned char>&arena,const b::HeapAdapter&h)const{normalize_inputs(arena,h);}
 unsigned normalize_arena(std::vector<unsigned char>&arena,const b::HeapAdapter&h)const{auto n=normalize_inputs(arena,h);members([&](const auto&v){const auto p=receiver()+v.offset-base;b::word(arena,p,token(h,b::readword(arena,p),fixture_count()+v.ordinal));++n;});return n;}
 unsigned normalize_block(std::vector<unsigned char>&bytes,unsigned id,const b::HeapAdapter&h)const{if(id<fixture_count())return 0u;if(!one()&&id==fixture_count()+26u){b::word(bytes,0u,token(h,b::readword(bytes,0u),fixture_count()+25u));return 1u;}unsigned n=0u,count=0u;const auto*items=fields(id-fixture_count(),count);for(unsigned j=0;j<count;++j){const auto&v=items[j];if(v.width!=4u)continue;unsigned ordinal=0u,off=0u;bool pointer=false;if(v.kind==3u){ordinal=fixture_count()+v.value;pointer=true;}else if(v.kind==1u){if(v.value==0x170u){ordinal=0u;pointer=true;}if(v.value==0x174u){ordinal=0u;off=middle();pointer=true;}if(v.value==0x178u&&one()){ordinal=1u;pointer=true;}}if(pointer){b::word(bytes,v.offset,token(h,b::readword(bytes,v.offset),ordinal,off));++n;}}return n;}
};
struct Observation{std::vector<b::Event>events;std::vector<std::vector<unsigned char>>live,prefree;std::vector<unsigned char>image,arena;unsigned scalar{},heap_bytes{},prefree_bytes{},normalizations{};};
inline Observation verify(const World&w,b::HeapAdapter&h,unsigned eax,const ra2::platform::x87::Image&fp,const std::vector<unsigned char>&bi,const std::vector<unsigned char>&ba,const unsigned char*image,const unsigned char*arena){const auto sizes=w.allocation_sizes();need(h.addresses.size()==sizes.size()&&h.allocation_flags.size()==sizes.size()&&h.snapshots.empty()&&h.events().size()==sizes.size()&&h.live().size()==sizes.size(),"1063 all fixture+target allocation events/no frees/no hidden allocations");Observation o;o.events=h.events();for(unsigned id=0;id<sizes.size();++id){const auto&e=o.events[id];need(e.kind==b::Event::Kind::allocate&&e.ordinal==id&&e.address==h.addresses[id]&&e.result==e.address&&e.size==sizes[id]&&h.allocation_flags[id]==0u,"1063 genuine allocation identity/fullresult/roundedsize/flags");o.heap_bytes+=sizes[id];}
 auto ei=bi,ea=ba;if(!w.one()){b::word(ei,0x824924u-0x400000u,h.addresses.at(w.fixture_count()+26u));b::word(ei,0x824928u-0x400000u,10u);ei.at(0x82492du-0x400000u)=1u;b::word(ei,0x824930u-0x400000u,1u);}w.expected_memory(ea,h);need(std::equal(ei.begin(),ei.end(),image)&&std::equal(ea.begin(),ea.end(),arena),"1063 independent entireimage/arena including all receiver slots/cache growth/input buffers");o.image=std::move(ei);o.arena=std::move(ea);o.normalizations=w.normalize_arena(o.arena,h);if(!w.one()){const auto p=0x824924u-0x400000u;b::word(o.image,p,w.token(h,b::readword(o.image,p),w.fixture_count()+26u));++o.normalizations;}
 auto live=h.live();std::sort(live.begin(),live.end(),[](const auto&a,const auto&d){return a.ordinal<d.ordinal;});for(unsigned id=0;id<sizes.size();++id){const auto&l=live[id];need(l.ordinal==id&&l.address==h.addresses[id]&&l.bytes==sizes[id],"1063 exact whole live block identity");auto bytes=std::vector<unsigned char>(reinterpret_cast<const unsigned char*>(std::uintptr_t(l.address)),reinterpret_cast<const unsigned char*>(std::uintptr_t(l.address))+l.bytes);need(bytes==w.block(id,h),"1063 independent every descriptor field/whole input/65536 lookup words/refs/roundedpadding");o.normalizations+=w.normalize_block(bytes,id,h);o.live.push_back(std::move(bytes));}
 o.scalar=w.token(h,eax,w.return_ordinal());need(ra2::platform::x87::same_numeric(fp,w.expected_fp()),"1063 full unchanged numeric FP oracle");return o;
}
inline void compare(const Observation&a,const Observation&d){need(a.scalar==d.scalar&&a.image==d.image&&a.arena==d.arena&&a.live==d.live&&a.events.size()==d.events.size(),"1063 complete paired state after exact LIVE ordinal pointer proofs");for(unsigned id=0;id<a.events.size();++id){const auto&x=a.events[id],&y=d.events[id];need(x.kind==y.kind&&x.ordinal==y.ordinal&&x.size==y.size,"1063 exact paired heap allocation event sequence");}}
inline void cleanup(b::HeapAdapter&h){auto live=h.live();std::sort(live.begin(),live.end(),[](const auto&a,const auto&d){return a.ordinal>d.ordinal;});for(const auto&v:live)need(h.release(v.address)!=0u,"1063 fixture cleanup all observed owned allocations after comparison");need(h.live().empty(),"1063 no fixture leaks");}
}
