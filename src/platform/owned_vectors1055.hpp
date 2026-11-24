#pragma once
// Fixture and independent closed-state oracle; never invokes recovered code.
#include <algorithm>
#include <cstring>
#include <stdexcept>
namespace ra2::platform::owned_vectors1055{
namespace b=b1055_test;
inline void need(bool v,const char*s){if(!v)throw std::domain_error(s);}
constexpr unsigned fields[]{0x28d0u,0x28b8u,0x28a0u,0x27e0u,0x27c8u,0x27b0u,0x8a0u,0x640u};
constexpr unsigned initial_tags[]{0x7906f4u,0x78955cu,0x79440cu,0x791838u,0x791838u,0x791838u,0x79442cu,0x79444cu};
constexpr unsigned final_tags[]{0x790714u,0x78957cu,0x7944acu,0x791858u,0x791858u,0x791858u,0x79448cu,0x79446cu};
struct World{
 unsigned root,base;b::Case c;static constexpr unsigned arena_size=65536u;
 World(unsigned r,unsigned a,b::Case v):root(r),base(a),c(v){}
 unsigned receiver()const{return base+0x400u;}unsigned file()const{return receiver()+0x22fcu;}unsigned reset()const{return receiver()+0x9d8u;}
 unsigned entries()const{return c.count+c.second;}unsigned fixture_count()const{return entries()+9u;}
 unsigned array_id(unsigned j)const{return entries()+j+(j>=6u?1u:0u);}unsigned stream_id()const{return entries()+6u;}
 std::vector<unsigned>allocation_sizes()const{std::vector<unsigned>v(fixture_count(),32u);for(unsigned k=0;k<c.count;++k)v[k]=48u;return v;}
 std::vector<unsigned>free_order()const{std::vector<unsigned>v;for(unsigned k=0;k<fixture_count();++k)v.push_back(k);return v;}
 unsigned request(unsigned id)const{return id<c.count?41u:id<entries()?17u+(c.seed+id)%15u:32u;}
 std::vector<unsigned char>block(unsigned id,const b::HeapAdapter&h,bool final)const{
  auto v=b::fresh(id,allocation_sizes().at(id));
  if(id<entries()){const auto n=request(id);for(unsigned k=0;k<n-1u;++k)v[k]=static_cast<unsigned char>(65u+(c.seed+id+k)%26u);v[n-1u]=0u;return v;}
  if(id==stream_id())return v;
  for(unsigned k=0;k<8u;++k)b::word(v,4u*k,base+0x6000u+32u*(id*8u+k));
  if(id==entries()||id==entries()+1u){const bool second=id==entries();const auto n=second?c.second:c.count,start=second?c.count:0u;for(unsigned k=0;k<n;++k)b::word(v,4u*k,h.addresses[start+(final?n-1u:k)]);}
  return v;
 }
 void setup(b::Memory&m,unsigned char*arena,b::HeapAdapter&h)const{
  need(root==0x265630u&&m.r32(0x793c9cu)==0x630a70u,"1055 genuine originalRawFileIsOpen slot");for(unsigned k=0;k<arena_size;++k)arena[k]=static_cast<unsigned char>(b::mix(c.seed+131u*k));
  for(unsigned k=0;k<fixture_count();++k){const auto a=h.allocate(request(k));const auto id=h.identify(a,allocation_sizes()[k]);need(id.ordinal==k&&id.offset==0u,"1055 wholeliveinputallocation ordinal/zerooffset/roundedextent proof");}
  for(unsigned id=0;id<fixture_count();++id){const auto bytes=block(id,h,false);for(unsigned k=0;k<bytes.size();++k)h.w8(h.addresses[id]+k,bytes[k]);}
  for(unsigned j=0;j<8u;++j){const auto p=receiver()+fields[j];m.w32(p,initial_tags[j]);m.w32(p+4u,h.addresses[array_id(j)]);m.w32(p+8u,8u);m.w8(p+12u,1u);m.w8(p+13u,1u);m.w32(p+16u,j==0u?c.second:j==1u?c.count:0u);m.w32(p+20u,10u);}
  // Exact initialized unopened embedded468BF0/46F990/42F1F0 object fields.
  const auto f=file();m.w32(f,0x7856a0u);m.w32(f+4u,1u);for(unsigned off:{8u,0x14u,0x28u,0x2cu,0x30u,0x34u,0x38u,0x44u,0x48u,0x4cu,0x60u})m.w32(f+off,0u);for(unsigned off:{0xcu,0x10u,0x3cu,0x40u})m.w32(f+off,0xffffffffu);for(unsigned off:{0x18u,0x1au})m.w16(f+off,0u);for(unsigned off:{0x1cu,0x20u,0x21u,0x22u,0x23u,0x24u,0x25u,0x50u})m.w8(f+off,0u);m.w32(f+0x54u,h.addresses[stream_id()]);m.w32(f+0x58u,32u);m.w8(f+0x5cu,1u);
  m.w32(reset(),0u);m.w8(reset()+0x19u,0u);m.w32(reset()+0x24u,0u);
 }
 b::Inputs input()const{b::Inputs i{};i.ax=b::mix(c.seed+1u);i.cx=receiver();i.dx=b::mix(c.seed+2u);for(unsigned k=0;k<16u;++k)i.arg[k]=b::mix(c.seed+73u*k+17u);return i;}
 std::array<unsigned,16>caller()const{return input().arg;}ra2::platform::x87::Image expected_fp()const{return ra2::platform::x87::Image::empty(static_cast<std::uint16_t>(c.control));}
 void expected_memory(std::vector<unsigned char>&arena)const{const auto p=receiver();const auto w=[&](unsigned a,unsigned v){b::word(arena,a-base,v);};const auto byte=[&](unsigned a,unsigned v){arena.at(a-base)=static_cast<unsigned char>(v);};const auto zero16=[&](unsigned a){byte(a,0u);byte(a+1u,0u);};
  for(unsigned j=0;j<8u;++j){const auto q=p+fields[j];w(q,final_tags[j]);w(q+4u,0u);w(q+8u,0u);byte(q+13u,0u);if(j<2u)w(q+16u,0u);}
  const auto f=file();w(f,0x793c3cu);w(f+0x54u,0u);w(f+0x58u,0u);byte(f+0x5cu,0u);w(f+0x60u,0u);w(f+0x30u,0u);for(unsigned off:{0x21u,0x23u,0x24u,0x25u})byte(f+off,0u);
  const auto q=reset();for(unsigned off:{0u,4u,8u,12u,16u,0x1cu,0x20u,0x24u,0x2b0u,0x2b4u})w(q+off,0u);w(q+0x14u,0x13u);for(unsigned off:{0x18u,0x19u,0x1au})byte(q+off,0u);for(unsigned off:{0x28u,0x16cu,0x2b8u})zero16(q+off);w(q+0x2bcu,0xfffffffeu);w(q+0x2c0u,0xffffffffu);w(q+0x2c4u,0x278u);for(unsigned k=0;k<7u;++k)w(q+0x1480u+4u*k,0x00010001u);
 }
 void normalize_before(std::vector<unsigned char>&a,const b::HeapAdapter&h)const{const auto exact=[&](unsigned p,unsigned id){need(b::readword(a,p-base)==h.addresses[id],"1055 exactknowninputownedfield");b::word(a,p-base,0xd0550000u+id);};for(unsigned j=0;j<8u;++j)exact(receiver()+fields[j]+4u,array_id(j));exact(file()+0x54u,stream_id());}
};
struct Observation{std::vector<b::Event>events;std::vector<std::vector<unsigned char>>prefree;std::vector<unsigned char>image,arena;unsigned scalar{},heap_bytes{},prefree_bytes{},normalizations{};};
inline Observation verify(const World&w,b::HeapAdapter&h,unsigned eax,const ra2::platform::x87::Image&fp,const std::vector<unsigned char>&bi,const std::vector<unsigned char>&ba,const unsigned char*image,const unsigned char*arena){const auto sizes=w.allocation_sizes();need(h.addresses.size()==sizes.size()&&h.allocation_flags.size()==sizes.size()&&h.snapshots.size()==sizes.size()&&h.events().size()==4u*sizes.size()&&h.live().empty(),"1055 completeordinaryheap inventory/alltargetfreed");Observation o;o.events=h.events();unsigned e=0u;for(unsigned id=0;id<sizes.size();++id){const auto&v=o.events[e++];need(v.kind==b::Event::Kind::allocate&&v.ordinal==id&&v.size==sizes[id]&&v.address==h.addresses[id]&&v.result==v.address&&h.allocation_flags[id]==0u,"1055 exactgenuinefixtureallocation");o.heap_bytes+=sizes[id];}
 for(unsigned id=0;id<sizes.size();++id){const auto&a=o.events[e++],&z=o.events[e++],&v=o.events[e++];need(a.kind==b::Event::Kind::enter_lock&&z.kind==b::Event::Kind::leave_lock&&a.address==z.address&&a.address==b::readword(bi,0x41729cu)&&a.ordinal==0u&&z.ordinal==0u&&a.result==0u&&z.result==0u&&a.size==0u&&z.size==0u&&v.kind==b::Event::Kind::release&&v.ordinal==id&&v.address==h.addresses[id]&&v.size==sizes[id]&&v.result!=0u,"1055 actualCRT9events/order/fullHeapFreeBOOL");const auto&s=h.snapshots[id];need(s.ordinal==id&&s.bytes==w.block(id,h,true),"1055 immediateprefreeentireroundedpayload/capacity/staleshift oracle");auto bytes=s.bytes;if(id==w.entries()||id==w.entries()+1u){const bool second=id==w.entries();const auto n=second?w.c.second:w.c.count,ordinal=(second?w.c.count:0u)+n-1u;for(unsigned k=0;k<n;++k){need(b::readword(bytes,4u*k)==h.addresses[ordinal],"1055 exactrecordedliveinputordinal nowfreedstale pointervalue");b::word(bytes,4u*k,0xd0550000u+ordinal);++o.normalizations;}}o.prefree.push_back(std::move(bytes));o.prefree_bytes+=sizes[id];}
 auto expected=ba;w.expected_memory(expected);need(std::equal(bi.begin(),bi.end(),image)&&std::equal(expected.begin(),expected.end(),arena),"1055 independentwhole7503872image/64Karena oracle");o.image=bi;o.arena=expected;o.scalar=o.events.back().result;need(eax==o.scalar,"1055 rawfullEAX last640backingactualHeapFreeBOOL");need(ra2::platform::x87::same_numeric(fp,w.expected_fp()),"1055 independentfullnumericx87 unchanged");return o;}
inline void compare(const Observation&a,const Observation&d){need(a.scalar==d.scalar&&a.image==d.image&&a.arena==d.arena&&a.prefree==d.prefree&&a.events.size()==d.events.size(),"1055 pairedfullstate/rawBOOL/prefreecapacity");for(unsigned k=0;k<a.events.size();++k){const auto&x=a.events[k],&y=d.events[k];need(x.kind==y.kind&&x.ordinal==y.ordinal&&x.size==y.size,"1055 allheapeventpairs");if(x.kind==b::Event::Kind::release)need(x.result==y.result,"1055 actualfullHeapFreeBOOLpair");if(x.kind==b::Event::Kind::enter_lock||x.kind==b::Event::Kind::leave_lock)need(x.address==y.address&&x.result==y.result,"1055 samegenuineCRTlockpair");}}
inline void cleanup(b::HeapAdapter&h){need(h.live().empty(),"1055 nofixtureownershipsurvives target");}
}
