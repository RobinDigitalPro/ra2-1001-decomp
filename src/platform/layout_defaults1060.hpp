#pragma once
// Independent final-layout and complete heap ownership oracle. Included only
// after the fixture cases and the separate reference byte inventory.
#include <algorithm>
#include <stdexcept>
namespace ra2::platform::layout_defaults1060{
namespace b=b1060_test;namespace ref=b1060_oracle;
inline void need(bool v,const char*s){if(!v)throw std::domain_error(s);}
struct World{
 unsigned root,base;b::Case c;static constexpr unsigned arena_size=65536u;
 World(unsigned r,unsigned a,b::Case v):root(r),base(a),c(v){}
 bool cleanup_root()const{return root==0x239a90u;}unsigned receiver()const{return base+0x400u;}
 unsigned fixture_count()const{return cleanup_root()?83u:0u;}std::vector<unsigned>allocation_sizes()const{return std::vector<unsigned>(fixture_count(),32u);}std::vector<unsigned>free_order()const{std::vector<unsigned>v;for(unsigned j=0;j<fixture_count();++j)v.push_back(j);return v;}
 unsigned count(unsigned j)const{return 1u+(c.count+j)%4u;}
 std::vector<unsigned char>block(unsigned id)const{auto bytes=b::fresh(id,32u);for(unsigned k=0;k<32u;++k)bytes[k]^=static_cast<unsigned char>(b::mix(c.seed+71u*id+k));return bytes;}
 void setup(b::Memory&m,unsigned char*arena,b::HeapAdapter&h)const{need(h.addresses.empty(),"1060 emptyfixtureheapbefore setup");for(unsigned k=0;k<arena_size;++k)arena[k]=static_cast<unsigned char>(b::mix(c.seed+131u*k));
  // Defaults receives a genuine empty constructed object, including the one
  // header1058 which its own body intentionally leaves unchanged.
  if(root!=0x237510u)for(const auto&v:ref::constructed)m.w8(receiver()+v.offset,v.value);
  if(cleanup_root()){
   for(const auto&v:ref::defaults)m.w8(receiver()+v.offset,v.value);
   for(unsigned id=0;id<83u;++id){const auto a=h.allocate(32u),q=receiver()+ref::release_order[id].offset;const auto proof=h.identify(a,32u);need(proof.ordinal==id&&proof.offset==0u,"1060 everywholeLIVEowned32bytebacking ordinalzerooffset");const auto bytes=block(id);for(unsigned k=0;k<32u;++k)h.w8(a+k,bytes[k]);need(m.r32(q)==ref::release_order[id].initial_tag,"1060 genuine originalconstructor-produced header tag");m.w32(q+4u,a);m.w32(q+8u,8u);m.w8(q+12u,1u);m.w8(q+13u,1u);m.w32(q+16u,count(id));m.w32(q+20u,10u);}
  }
 }
 b::Inputs input()const{b::Inputs i{};i.ax=b::mix(c.seed+1u);i.cx=receiver();i.dx=b::mix(c.seed+2u);for(unsigned k=0;k<16u;++k)i.arg[k]=b::mix(c.seed+73u*k+17u);return i;}
 std::array<unsigned,16>caller()const{return input().arg;}ra2::platform::x87::Image expected_fp()const{return ra2::platform::x87::Image::empty(static_cast<std::uint16_t>(c.control));}
 void expected_memory(std::vector<unsigned char>&arena)const{const auto p=receiver()-base;if(root==0x237510u){for(const auto&v:ref::constructed)arena.at(p+v.offset)=v.value;return;}if(root==0x237c30u){for(const auto&v:ref::defaults)arena.at(p+v.offset)=v.value;return;}
  for(const auto&v:ref::release_order){b::word(arena,p+v.offset,v.final_tag);b::word(arena,p+v.offset+4u,0u);b::word(arena,p+v.offset+8u,0u);arena.at(p+v.offset+13u)=0u;}
 }
 void normalize_before(std::vector<unsigned char>&arena,const b::HeapAdapter&h)const{if(!cleanup_root())return;for(unsigned id=0;id<83u;++id){const auto off=receiver()-base+ref::release_order[id].offset+4u;need(b::readword(arena,off)==h.addresses[id],"1060 exactknownLIVEinputbacking field");b::word(arena,off,0xd0600000u+id);}}
};
struct Observation{std::vector<b::Event>events;std::vector<std::vector<unsigned char>>prefree;std::vector<unsigned char>image,arena;unsigned scalar{},heap_bytes{},prefree_bytes{},normalizations{};};
inline Observation verify(const World&w,b::HeapAdapter&h,unsigned eax,const ra2::platform::x87::Image&fp,const std::vector<unsigned char>&bi,const std::vector<unsigned char>&ba,const unsigned char*image,const unsigned char*arena){const auto n=w.fixture_count();need(h.addresses.size()==n&&h.allocation_flags.size()==n&&h.events().size()==4u*n&&h.snapshots.size()==n&&h.live().empty(),"1060 completeordinaryheapinventory all83targetfreed orconstructorzeroevents");Observation o;o.events=h.events();unsigned at=0u;for(unsigned id=0;id<n;++id){const auto&e=o.events[at++];need(e.kind==b::Event::Kind::allocate&&e.ordinal==id&&e.address==h.addresses[id]&&e.result==e.address&&e.size==32u&&h.allocation_flags[id]==0u,"1060 exactreal fixtureallocation");o.heap_bytes+=32u;}
 for(unsigned id=0;id<n;++id){const auto&a=o.events[at++],&z=o.events[at++],&f=o.events[at++];need(a.kind==b::Event::Kind::enter_lock&&z.kind==b::Event::Kind::leave_lock&&a.address==z.address&&a.address==b::readword(bi,0x41729cu)&&a.ordinal==0u&&z.ordinal==0u&&a.size==0u&&z.size==0u&&a.result==0u&&z.result==0u&&f.kind==b::Event::Kind::release&&f.ordinal==id&&f.address==h.addresses[id]&&f.size==32u&&f.result!=0u,"1060 exact83actualCRTlock9/freeorder/fullBOOL");need(h.snapshots[id].ordinal==id&&h.snapshots[id].bytes==w.block(id),"1060 everyoriginalimmediateprefreebyte/fullcapacity/padding independentoracle");o.prefree.push_back(h.snapshots[id].bytes);o.prefree_bytes+=32u;}
 auto expected=ba;w.expected_memory(expected);need(std::equal(bi.begin(),bi.end(),image)&&std::equal(expected.begin(),expected.end(),arena),"1060 independentwhole7503872image/64Karena defaults/vptr/ownership/count/growth/untouchedpadding oracle");o.image=bi;o.arena=expected;o.scalar=w.cleanup_root()?o.events.back().result:w.receiver();need(eax==o.scalar,"1060 fullEAX exactconstructedreceiver orfinalactualHeapFreeBOOL");need(ra2::platform::x87::same_numeric(fp,w.expected_fp()),"1060 independentcompleteunchangednumericx87");return o;}
inline void compare(const Observation&a,const Observation&d){need(a.scalar==d.scalar&&a.image==d.image&&a.arena==d.arena&&a.prefree==d.prefree&&a.events.size()==d.events.size(),"1060 pairedcompletepostconditions/prefreecapacity/rawfullEAX");for(unsigned j=0;j<a.events.size();++j){const auto&x=a.events[j],&y=d.events[j];need(x.kind==y.kind&&x.ordinal==y.ordinal&&x.size==y.size,"1060 allheapeventpairs");if(x.kind==b::Event::Kind::release)need(x.result==y.result,"1060 actualfullHeapFreeBOOLpair");if(x.kind==b::Event::Kind::enter_lock||x.kind==b::Event::Kind::leave_lock)need(x.address==y.address&&x.result==y.result,"1060 sameactualCRTcriticalsectionpair");}}
inline void cleanup(b::HeapAdapter&h){need(h.live().empty(),"1060 noownedfixtureblocksremain");}
}
