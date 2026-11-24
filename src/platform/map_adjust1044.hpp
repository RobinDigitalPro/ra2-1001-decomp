#pragma once
// Fixture-only provider, included after recovery_b1044_cases.hpp.
#include "platform/map_vector1036.hpp"
namespace ra2::platform::map_adjust1044 {
namespace b=b1044_test;namespace old=ra2::platform::map_vector1036;using old::need;
struct World{
 unsigned root,base;b::Case c;old::World map;
 static constexpr unsigned arena_size=1048576u,center=0x00030003u,source_offset=0x800u,array_offset=0x900u;
 World(unsigned r,unsigned a,b::Case v):root(r),base(a),c(v),map(r,a,b1036_test::Case{v.seed,0u,1u,1u,v.land,v.land+1u,v.flag,60u,1u}){}
 unsigned slot(unsigned p)const{return map.slot(p);}unsigned cell(unsigned k)const{return map.object(k);}unsigned owner()const{return c.flag?0xffffffffu:map.own();}unsigned mask()const{return c.orientation?0x22u:0x88u;}
 void setup(b::Memory&m,unsigned char*arena,b::HeapAdapter&h)const{
  map.setup(m,arena,h);need(h.addresses.empty(),"1044 nofixtureheapallocations");need(m.r32(0x7856f8u)==0u&&m.r32(0x7856fcu)==0x40000000u,"1044 exactoriginal double2 literal on mutableIATpage preserved");
  for(unsigned k=0;k<15u;++k){m.w32(cell(k)+0x38u,0xffffu);m.w8(cell(k)+0x11au,0x40u+(c.seed+k)%128u);m.w8(cell(k)+0x11bu,c.land+(root==0x158000u&&k!=6u?4u:0u));m.w8(slot(b1031_test::coordinates[k])+0x4au,k==6u?1u:0u);m.w32(slot(b1031_test::coordinates[k])+0x40u,0xffffffffu);}
  m.w32(slot(center)+0x38u,0u);
  for(unsigned a:{0xa3aaa8u,0xa3a1bcu,0xa54b90u,0xa3aad8u,0xa3ab28u,0xa55938u,0xa547a8u,0xa3a8b0u,0xa547a0u,0xa55d30u,0xa3aaa4u,0xa3a1b8u})need(m.r32(a)==0u,"1044 actual initial terraincategory bases unchangedzero");
  if(root==0x159420u){m.w32(cell(c.orientation?3u:4u)+0x38u,0u);m.w32(cell(c.orientation?9u:8u)+0x38u,0u);}
  if(root==0x173600u){
   // Actual749EC9 config producer writes4; A579D8 remains original zero.
   // Actual16A660 context constructor writes DWORD+20hex zero.
   m.w32(0xa579d0u,4u);need(m.r32(0xa579d8u)==0u&&m.r32(0x7c3a04u)==0xe7fu,"1044 originalzero selectorcounter andtruncation controlword");m.w32(map.receiver()+0x20u,0u);
   const auto p=base+source_offset;m.w32(p,0x7875a0u);m.w32(p+4u,base+array_offset);m.w32(p+8u,c.capacity);m.w8(p+12u,1u);m.w8(p+13u,0u);m.w32(p+16u,1u);m.w32(p+20u,10u);m.w32(base+array_offset,b1031_test::coordinates[c.point]);
  }
 }
 b::Inputs input()const{b::Inputs i{};i.ax=b::mix(c.seed+1u);i.cx=root==0x173600u?map.receiver():0x81a820u;i.dx=b::mix(c.seed+2u);for(unsigned k=0;k<16u;++k)i.arg[k]=b::mix(c.seed+73u*k+17u);i.arg[0]=root==0x173600u?base+source_offset:cell(6u);if(root!=0x173600u)i.arg[1]=owner();if(root==0x159420u)i.arg[2]=(i.arg[2]&0xffffff00u)|c.flag;return i;}
 std::array<unsigned,16>caller()const{auto a=input().arg;if(root==0x158000u)a[0]=center;else if(root==0x159420u)a[0]=8u;return a;}
 std::vector<unsigned>allocation_sizes()const{return root==0x173600u?std::vector<unsigned>{32u,48u}:std::vector<unsigned>{};}
 void expected_memory(std::vector<unsigned char>&image,std::vector<unsigned char>&arena)const{
  (void)image;const auto aw=[&](unsigned p,unsigned value){b::word(arena,p-base,value);};
  if(root==0x158000u){arena.at(cell(6u)-base+0x11bu)=static_cast<unsigned char>(c.land+4u);aw(slot(center)+0x38u,owner());}
  if(root==0x159420u){aw(cell(6u)+0x38u,0u);arena.at(cell(6u)-base+0x11au)=0u;aw(slot(center)+0x38u,c.flag?0u:owner());aw(slot(center)+0x40u,mask());constexpr unsigned neighbors[]{4u,7u,9u,11u,8u,5u,3u,1u};for(unsigned k:neighbors)aw(slot(b1031_test::coordinates[k])+0x40u,0u);}
 }
 std::vector<unsigned char>block_expected(unsigned id,const b::HeapAdapter&h)const{auto v=b::fresh(id,allocation_sizes().at(id));if(id==0u){b::word(v,0u,0x7875a0u);b::word(v,4u,h.addresses.at(1u));b::word(v,8u,10u);v[12]=1u;v[13]=1u;b::word(v,16u,1u);b::word(v,20u,10u);}else b::word(v,0u,b1031_test::coordinates[c.point]);return v;}
 ra2::platform::x87::Image expected_fp()const{return ra2::platform::x87::Image::empty(static_cast<std::uint16_t>(root==0x173600u?0xe7fu:c.control));}
};
struct Observation{std::vector<b::Event>events;std::vector<std::vector<unsigned char>>live;unsigned scalar{},heap_bytes{};};
inline Observation verify(const World&w,b::HeapAdapter&h,unsigned eax,const ra2::platform::x87::Image&fp,const std::vector<unsigned char>&before_image,const std::vector<unsigned char>&before_arena,const unsigned char*image,const unsigned char*arena){
 const auto sizes=w.allocation_sizes();need(h.addresses.size()==sizes.size()&&h.allocation_flags.size()==sizes.size()&&h.events().size()==sizes.size()&&h.snapshots.empty(),"1044 completeactualallocinventory/nofreeevents");Observation out;out.events=h.events();for(unsigned k=0;k<sizes.size();++k){const auto&e=out.events[k];need(e.kind==b::Event::Kind::allocate&&e.ordinal==k&&e.size==sizes[k]&&e.address==h.addresses[k]&&e.result==h.addresses[k]&&h.allocation_flags[k]==0u,"1044 exactgenuineallocation ordinal/flags/pointer/roundedsize");out.heap_bytes+=sizes[k];}
 auto ei=before_image,ea=before_arena;w.expected_memory(ei,ea);need(std::equal(ei.begin(),ei.end(),image)&&std::equal(ea.begin(),ea.end(),arena),"1044 whole7503872image/1MiBarena independentclosedcentre/cache oracle");auto live=h.live();std::sort(live.begin(),live.end(),[](const auto&a,const auto&b){return a.ordinal<b.ordinal;});need(live.size()==sizes.size(),"1044 exactall-liveownedoutputs");for(const auto&l:live){need(l.ordinal<live.size()&&l.address==h.addresses[l.ordinal]&&l.bytes==sizes[l.ordinal],"1044 wholeliveallocation identity");auto bytes=std::vector<unsigned char>(reinterpret_cast<const unsigned char*>(std::uintptr_t(l.address)),reinterpret_cast<const unsigned char*>(std::uintptr_t(l.address))+l.bytes);need(bytes==w.block_expected(l.ordinal,h),"1044 completeownedvector32/48 includingcapacity/padding");if(l.ordinal==0u){const auto id=h.identify(b::readword(bytes,4u),48u);need(id.ordinal==1u&&id.offset==0u&&b::readword(bytes,4u)==h.addresses[1u],"1044 whole48newarray pointer ordinal1zerooffset");b::word(bytes,4u,0xd0440001u);}out.live.push_back(std::move(bytes));}
 if(w.root==0x173600u){const auto id=h.identify(eax,32u);need(id.ordinal==0u&&id.offset==0u&&eax==h.addresses[0u],"1044 fullEAXexactwhole32ownedheader ordinal0zerooffset");out.scalar=0xd0440000u;}else{need(eax==1u,"1044 actualrecursivepositive fullEAX1");out.scalar=eax;}
 need(ra2::platform::x87::same_numeric(fp,w.expected_fp()),"1044 independentnumericx87 oracle:emptytags/TOP0/status0/all80zero;selectorfinalCW0E7F");return out;
}
inline void compare(const Observation&a,const Observation&b){need(a.scalar==b.scalar&&a.live==b.live&&a.events.size()==b.events.size(),"1044 pairedfullEAXexactidentity/allheapbytes");for(unsigned k=0;k<a.events.size();++k)need(a.events[k].kind==b.events[k].kind&&a.events[k].ordinal==b.events[k].ordinal&&a.events[k].size==b.events[k].size,"1044 completeactualallocationeventpairs");}
inline void cleanup(b::HeapAdapter&h){for(const auto&l:h.live())need(h.release(l.address)!=0u,"1044 cleanupownedoutputsafterallobservations");need(h.live().empty(),"1044 finalownershipempty");}
}
