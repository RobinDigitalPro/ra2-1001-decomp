#pragma once
// Fixture-only provider; included after tests/recovery_b1031_cases.hpp by the
// native/assurance translation unit. The recovered model never includes it.
#include <algorithm>
#include <cstring>
#include <set>
#include <stdexcept>
namespace ra2::platform::map_vector1031 {
namespace b=b1031_test;
inline void need(bool ok,const char*s){if(!ok)throw std::domain_error(s);}
struct World {
 unsigned root,base; b::Case c;unsigned own_index,point,eligible;std::array<unsigned,15>owners{};std::vector<unsigned>out,neighbor_ids;
 static constexpr unsigned arena_size=1048576u,receiver_offset=0x400u,table_offset=0x10000u,metadata_offset=0x20000u,objects_offset=0x30000u;
 World(unsigned r,unsigned a,b::Case v):root(r),base(a),c(v){c.types=3u+c.seed%3u;c.owned=1u+(c.seed>>3u)%(c.types-1u);own_index=root==0x16d0a0u?6u:b::chosen[c.point_index];point=b::coordinates[own_index];eligible=b::coordinates[b::adjacent[1][c.direction]];for(unsigned k=0;k<15u;++k)owners[k]=(c.owned+1u+k%(c.types-1u))%c.types;owners[own_index]=c.owned;if(root==0x16d0a0u)owners[unsigned(b::adjacent[1][c.direction])]=0xffffffffu;
  if(root==0x16ccc0u){for(unsigned k=c.input_count;k>0u;--k)out.push_back(b::coordinates[b::source_indices[k-1u]]);for(unsigned k=0;k<c.input_count;++k)need(owners[b::source_witness[k]]!=c.owned,"1031 explicit independent positive reverse-input boundary witness");}
  else if(root==0x16d7b0u){std::set<unsigned>s;for(int k:b::adjacent[c.point_index])if(k>=0&&owners[unsigned(k)]!=c.owned)s.insert(owners[unsigned(k)]);out.assign(s.begin(),s.end());need(!out.empty()&&out.size()<10u,"1031 nonempty sorted distinct neighbor-owner oracle");}
  else out.push_back(point);
  const unsigned row=root==0x16d0a0u?1u:c.point_index;for(int k:b::adjacent[row])if(k>=0&&owners[unsigned(k)]<c.types)neighbor_ids.push_back(owners[unsigned(k)]);
 }
 unsigned receiver()const{return base+receiver_offset;}unsigned table()const{return base+table_offset;}unsigned grid()const{return base+metadata_offset;}
 unsigned slot(unsigned packed)const{return grid()+80u*((packed>>16u)*7u+(packed&65535u));}
 void setup(b::Memory&m,unsigned char*arena)const{
  for(unsigned k=0;k<arena_size;++k)arena[k]=static_cast<unsigned char>(b::mix(c.seed+k*131u));
  // Complete physical rows needed by genuine512-stride MapClass lookup and the
  // one-past-logical iterator probe. Every unoccupied pointer is genuinely NULL.
  std::memset(arena+table_offset,0u,7u*512u*4u);
  for(unsigned y=0;y<7u;++y)for(unsigned x=0;x<7u;++x){const auto p=grid()+80u*(y*7u+x);m.w32(p,0u);m.w32(p+0x38u,0xffffffffu);m.w8(p+0x4bu,0u);}
  for(unsigned k=0;k<15u;++k){const auto p=b::coordinates[k],object=base+objects_offset+0x40u*k;m.w32(object+0x24u,p);m.w32(table()+4u*((p>>16u)*512u+(p&65535u)),object);m.w32(slot(p),p);m.w32(slot(p)+0x38u,owners[k]);}
  if(root==0x16d0a0u)m.w8(slot(eligible)+0x4bu,1u);
  m.w32(receiver()+4u,0u);m.w32(receiver()+8u,c.owned);m.w32(receiver()+0xcu,root==0x16d7b0u?2u+c.seed%49u:1u);m.w32(receiver()+0x2cu,base+0x800u);m.w32(receiver()+0x38u,c.input_count);m.w32(receiver()+0x180u,1u);m.w32(receiver()+0x184u,c.growth);
  for(unsigned k=0;k<4u;++k)m.w32(base+0x800u+4u*k,b::coordinates[b::source_indices[k]]);
  m.w32(0x81a910u,3u);m.w32(0x81a914u,3u);m.w32(0x81a958u,table());m.w32(0x836b4cu,7u);m.w32(0xa58634u,3u);m.w32(0xa58638u,9u);m.w32(0xa5863cu,grid());m.w32(0xa58640u,c.types);
  // Nondefault iterator preimage proves exact genuine reset/advance effects.
  m.w32(0x81a928u,b::mix(c.seed+1u));m.w32(0x81a92cu,b::mix(c.seed+2u));m.w32(0x81a930u,b::mix(c.seed+3u));m.w32(0x81a934u,base+0x980u);m.w32(0xa57634u,b::mix(c.seed+4u));
  for(unsigned k=0;k<8u;++k)need(m.r32(0x839da0u+4u*k)==b::deltas[k],"1031 genuine172-byte static neighbor initializer output");
  need(m.r32(0x7875a0u)==0x42d3e0u&&m.r32(0x7875a8u)==0x42d050u&&m.r32(0x788a94u)==0x46cb50u&&m.r32(0x788a9cu)==0x46ce50u,"1031 authentic original literal vector methods");
 }
 bool walks_map()const{return root==0x16bb00u||root==0x16d7b0u||root==0x16d0a0u;}
 void expected_memory(std::vector<unsigned char>&image,std::vector<unsigned char>&arena,unsigned result_header)const{
  auto iw=[&](unsigned va,unsigned x){b::word(image,va-0x400000u,x);};
  if(walks_map()){iw(0x81a928u,5u);iw(0x81a92cu,5u);iw(0x81a930u,1u);iw(0x81a934u,table()+10260u);if(own_index==1u)iw(0xa57634u,0x00010001u);else if(own_index==11u)iw(0xa57634u,0x00050005u);}
  if(root==0x16d7b0u){b::word(arena,receiver_offset+4u,result_header);b::word(arena,receiver_offset+0xcu,1u);}
  if(root==0x16d0a0u)b::word(arena,slot(eligible)-base+0x38u,c.owned);
 }
 std::vector<unsigned> allocation_sizes()const{if(root==0x16d7b0u)return{32u,16u,32u,48u,48u};if(root==0x16d0a0u)return{32u,48u,200000u};return{32u,root==0x17ece0u?16u:48u};}
 std::vector<unsigned> free_order()const{if(root==0x16d7b0u)return{3u,2u,1u};if(root==0x16d0a0u)return{1u,0u,2u};return{};}
 std::vector<unsigned char> block_expected(unsigned ordinal,const b::HeapAdapter&h)const{
  auto v=b::fresh(ordinal,allocation_sizes().at(ordinal));auto header=[&](unsigned tag,unsigned array,unsigned cap,unsigned count,unsigned growth,bool dead){b::word(v,0u,tag);b::word(v,4u,dead?0u:array);b::word(v,8u,dead?0u:cap);v[12]=1u;v[13]=dead?0u:1u;b::word(v,16u,count);b::word(v,20u,growth);};
  if(root==0x16d7b0u){if(ordinal==0u)header(0x788a94u,h.addresses.at(4u),10u,unsigned(out.size()),10u,false);else if(ordinal==1u){std::fill(v.begin(),v.begin()+c.types,0u);for(unsigned id:neighbor_ids)v.at(id)=1u;}else if(ordinal==2u)header(0x7875e0u,0u,10u,1u,10u,true);else if(ordinal==3u)b::word(v,0u,point);else for(unsigned k=0;k<out.size();++k)b::word(v,4u*k,out[k]);}
  else if(root==0x16d0a0u){if(ordinal==0u)header(0x7875e0u,0u,10u,1u,10u,true);else b::word(v,0u,ordinal==1u?point:eligible);}
  else if(ordinal==0u)header(0x7875a0u,h.addresses.at(1u),root==0x17ece0u?c.growth:10u,unsigned(out.size()),root==0x17ece0u?c.growth:10u,false);else for(unsigned k=0;k<out.size();++k)b::word(v,k*4u,out[k]);
  return v;
 }
};
struct Observation{std::vector<b::Event>events;std::vector<std::vector<unsigned char>>prefree,live;unsigned scalar{},heap_bytes{};};
inline Observation verify(const World&w,b::HeapAdapter&h,unsigned eax,const std::vector<unsigned char>&before_image,const std::vector<unsigned char>&before_arena,const unsigned char*image,const unsigned char*arena){
 const auto sizes=w.allocation_sizes(),freed=w.free_order();need(h.addresses.size()==sizes.size()&&h.allocation_flags.size()==sizes.size()&&h.snapshots.size()==freed.size()&&h.events().size()==sizes.size()+3u*freed.size(),"1031 exact all target allocations/freeevents and snapshots");Observation out;out.events=h.events();unsigned cursor=0u;for(unsigned k=0;k<sizes.size();++k){const auto&e=out.events[cursor++];need(e.kind==b::Event::Kind::allocate&&e.ordinal==k&&e.size==sizes[k]&&e.address==h.addresses[k]&&e.result==h.addresses[k]&&h.allocation_flags[k]==0u,"1031 genuine ordinary allocation exactordinal/roundedsize/flags/fullpointer");out.heap_bytes+=sizes[k];}
 for(unsigned k=0;k<freed.size();++k){const unsigned id=freed[k];const auto&a=out.events[cursor++],&z=out.events[cursor++],&f=out.events[cursor++];need(a.kind==b::Event::Kind::enter_lock&&z.kind==b::Event::Kind::leave_lock&&a.address==z.address&&a.address==b::readword(before_image,0x41729cu)&&a.ordinal==0u&&z.ordinal==0u&&a.size==0u&&z.size==0u&&a.result==0u&&z.result==0u&&f.kind==b::Event::Kind::release&&f.ordinal==id&&f.address==h.addresses[id]&&f.size==sizes[id]&&f.result!=0u,"1031 exact original enter/leave/free order and actual fullBOOL");need(h.snapshots[k].ordinal==id&&h.snapshots[k].bytes==w.block_expected(id,h),"1031 complete rounded original prefreepayload independent oracle including unusedcapacity andpadding");out.prefree.push_back(h.snapshots[k].bytes);}
 auto expected_image=before_image,expected_arena=before_arena;w.expected_memory(expected_image,expected_arena,w.root==0x16d7b0u?h.addresses[0]:0u);need(std::equal(expected_image.begin(),expected_image.end(),image)&&std::equal(expected_arena.begin(),expected_arena.end(),arena),"1031 exact wholeoriginalimage and guarded1MiBarena independent oracle");
 auto blocks=h.live();std::sort(blocks.begin(),blocks.end(),[](const auto&a,const auto&d){return a.ordinal<d.ordinal;});need(blocks.size()==sizes.size()-freed.size(),"1031 complete liveheap inventory");for(const auto&l:blocks){need(l.bytes==sizes[l.ordinal]&&l.address==h.addresses[l.ordinal],"1031 live allocation identity");auto bytes=std::vector<unsigned char>(reinterpret_cast<const unsigned char*>(std::uintptr_t(l.address)),reinterpret_cast<const unsigned char*>(std::uintptr_t(l.address))+l.bytes);need(bytes==w.block_expected(l.ordinal,h),"1031 every raw livepayload byte independent oracle");if(l.ordinal==0u){const unsigned target=w.root==0x16d7b0u?4u:1u;const auto id=h.identify(b::readword(bytes,4u),sizes[target]);need(id.ordinal==target&&id.offset==0u&&b::readword(bytes,4u)==h.addresses[target],"1031 exact newlyowned array pointer ordinal+zerooffset and wholeallocation proof before normalization");b::word(bytes,4u,0xd0310000u+target);}out.live.push_back(std::move(bytes));}
 if(w.root==0x16d7b0u){const auto id=h.identify(b::readword(expected_arena,World::receiver_offset+4u),32u);need(id.ordinal==0u&&id.offset==0u,"1031 receiverownedheader exactwholepointer relation");out.scalar=out.events.back().result;need(eax==out.scalar,"1031 fullEAX exactlastactualflagsHeapFreeBOOL");}else if(w.root==0x16d0a0u){out.scalar=(out.events.back().result&0xffffff00u)|1u;need(eax==out.scalar,"1031 fullEAX actualfinalHeapFreeBOOL upper24 plusMOVAL1");}else{const auto id=h.identify(eax,32u);need(id.ordinal==0u&&id.offset==0u&&eax==h.addresses[0],"1031 fullEAX exactgenuine newheader pointer before identity normalization");out.scalar=0xd0310000u;}
 return out;
}
inline void compare(const Observation&a,const Observation&d){need(a.scalar==d.scalar&&a.prefree==d.prefree&&a.live==d.live&&a.events.size()==d.events.size(),"1031 paired fullEAX/allroundedheapbytes including prefrees/live");for(unsigned k=0;k<a.events.size();++k){const auto&x=a.events[k],&y=d.events[k];need(x.kind==y.kind&&x.ordinal==y.ordinal&&x.size==y.size,"1031 all allocation/CS/free events pair");if(x.kind==b::Event::Kind::release)need(x.result==y.result,"1031 paired actualfullHeapFreeBOOL");if(x.kind==b::Event::Kind::enter_lock||x.kind==b::Event::Kind::leave_lock)need(x.address==y.address&&x.result==y.result,"1031 shared real initialized CRTcriticalsection");}}
inline void cleanup(b::HeapAdapter&h){auto blocks=h.live();for(const auto&l:blocks)if(l.ordinal!=0u)h.release(l.address);for(const auto&l:blocks)if(l.ordinal==0u)h.release(l.address);need(h.live().empty(),"1031 fixture cleans surviving genuinelyowned output only after all observations");}
}
