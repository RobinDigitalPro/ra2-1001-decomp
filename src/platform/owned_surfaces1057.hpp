#pragma once
// Independent finite surface graph/bytes oracle; no recovered helper calls.
#include <algorithm>
#include <cstring>
#include <stdexcept>
namespace ra2::platform::owned_surfaces1057{
namespace b=b1057_test;
inline void need(bool v,const char*s){if(!v)throw std::domain_error(s);}
struct World{
 unsigned root,base;b::Case c;static constexpr unsigned arena_size=65536u;
 World(unsigned r,unsigned a,b::Case v):root(r),base(a),c(v){}
 unsigned receiver()const{return base+0x400u;}unsigned shape()const{return base+0x2000u;}unsigned source()const{return base+0x3000u;}unsigned pixels()const{return base+0x8000u;}
 unsigned requested()const{return c.count*c.capacity*c.second;}unsigned rounded()const{return(requested()+15u)&~15u;}
 std::vector<unsigned>allocation_sizes()const{return{32u,rounded(),32u,rounded(),32u,rounded()};}unsigned fixture_count()const{return 0u;}std::vector<unsigned>free_order()const{return{};}
 void setup(b::Memory&m,unsigned char*arena,b::HeapAdapter&h)const{need(root==0x35d890u&&h.addresses.empty()&&m.r32(0x785f68u)==0x4113b0u,"1057 originalunmodifiedgenuinebytesperpixelmethod/noinputheap");for(unsigned k=0;k<arena_size;++k)arena[k]=static_cast<unsigned char>(b::mix(c.seed+131u*k));
  m.w32(receiver()+4u,shape());m.w32(receiver()+0x24u,source());for(unsigned off:{0x44u,0x58u,0x6cu})m.w32(receiver()+off,0u);m.w16(shape()+2u,c.count);m.w16(shape()+4u,c.capacity);
  // Same original785EF8 surface layout;438140(nonnull,bytes) produces a
  // genuinely borrowed prepared pixel span, no allocator/device/render stub.
  m.w32(source(),0x785ef8u);m.w32(source()+4u,32u);m.w32(source()+8u,32u);m.w32(source()+12u,0u);m.w32(source()+0x10u,c.second);m.w32(source()+0x14u,pixels());m.w32(source()+0x18u,32u*32u*c.second);m.w8(source()+0x1cu,0u);
 }
 b::Inputs input()const{b::Inputs i{};i.ax=b::mix(c.seed+1u);i.cx=receiver();i.dx=b::mix(c.seed+2u);for(unsigned k=0;k<16u;++k)i.arg[k]=b::mix(c.seed+73u*k+17u);return i;}
 std::array<unsigned,16>caller()const{return input().arg;}ra2::platform::x87::Image expected_fp()const{return ra2::platform::x87::Image::empty(static_cast<std::uint16_t>(c.control));}
 std::vector<unsigned char>block(unsigned id,const b::HeapAdapter&h)const{auto bytes=b::fresh(id,allocation_sizes().at(id));if(!(id&1u)){b::word(bytes,0u,0x785ef8u);b::word(bytes,4u,c.count);b::word(bytes,8u,c.capacity);b::word(bytes,12u,0u);b::word(bytes,16u,c.second);b::word(bytes,20u,h.addresses.at(id+1u));b::word(bytes,24u,requested());bytes[28u]=1u;}return bytes;}
 void expected_memory(std::vector<unsigned char>&arena,const b::HeapAdapter&h)const{constexpr unsigned off[]{0x44u,0x58u,0x6cu};for(unsigned j=0;j<3u;++j)b::word(arena,receiver()+off[j]-base,h.addresses.at(2u*j));}
 void normalize_before(std::vector<unsigned char>&,const b::HeapAdapter&)const{}
 unsigned normalize_arena(std::vector<unsigned char>&a,const b::HeapAdapter&h)const{constexpr unsigned off[]{0x44u,0x58u,0x6cu};for(unsigned j=0;j<3u;++j){const auto p=receiver()+off[j]-base,id=2u*j;need(b::readword(a,p)==h.addresses.at(id),"1057 exactnewreceiver-ownedheader rawpointer");const auto relation=h.identify(h.addresses.at(id),32u);need(relation.ordinal==id&&relation.offset==0u,"1057 wholeLIVE32byteheader ordinalzerooffset");b::word(a,p,0xd0570000u+id);}return 3u;}
};
struct Observation{std::vector<b::Event>events;std::vector<std::vector<unsigned char>>live,prefree;std::vector<unsigned char>image,arena;unsigned scalar{},heap_bytes{},prefree_bytes{},normalizations{};};
inline Observation verify(const World&w,b::HeapAdapter&h,unsigned eax,const ra2::platform::x87::Image&fp,const std::vector<unsigned char>&bi,const std::vector<unsigned char>&ba,const unsigned char*image,const unsigned char*arena){need(h.addresses.size()==6u&&h.allocation_flags.size()==6u&&h.snapshots.empty()&&h.events().size()==6u&&h.live().size()==6u,"1057 completeexact6targetallocations/nofree/fixturealloc");Observation o;o.events=h.events();const auto sizes=w.allocation_sizes();for(unsigned id=0;id<6u;++id){const auto&e=o.events[id];need(e.kind==b::Event::Kind::allocate&&e.ordinal==id&&e.address==h.addresses[id]&&e.result==e.address&&e.size==sizes[id]&&h.allocation_flags[id]==0u,"1057 genuineallocation exactordinal/fullpointer/roundedsize/flags");o.heap_bytes+=sizes[id];}
 auto expected=ba;w.expected_memory(expected,h);need(std::equal(bi.begin(),bi.end(),image)&&std::equal(expected.begin(),expected.end(),arena),"1057 independentwhole7503872image/64Karena immutableborrowedsource/shapeandnew3ownedfields");o.image=bi;o.arena=expected;o.normalizations=w.normalize_arena(o.arena,h);
 auto live=h.live();std::sort(live.begin(),live.end(),[](const auto&a,const auto&d){return a.ordinal<d.ordinal;});for(unsigned id=0;id<6u;++id){const auto&l=live[id];need(l.ordinal==id&&l.address==h.addresses[id]&&l.bytes==sizes[id],"1057 exactwholeliveblockidentity");auto bytes=std::vector<unsigned char>(reinterpret_cast<const unsigned char*>(std::uintptr_t(l.address)),reinterpret_cast<const unsigned char*>(std::uintptr_t(l.address))+l.bytes);need(bytes==w.block(id,h),"1057 everyliveheaderfield/paddingandallpixelcapacitybytes independentoracle");if(!(id&1u)){const auto pointer=b::readword(bytes,20u);need(pointer==h.addresses[id+1u],"1057 exactownedpixelpointer fromknownnewheader");const auto relation=h.identify(pointer,sizes[id+1u]);need(relation.ordinal==id+1u&&relation.offset==0u,"1057 wholeLIVEroundedpixel extent/ordinalzerooffset");b::word(bytes,20u,0xd0570000u+id+1u);++o.normalizations;}o.live.push_back(std::move(bytes));}
 need(eax==1u,"1057 originalfullEAX1 positiveallthreecreated");o.scalar=eax;need(ra2::platform::x87::same_numeric(fp,w.expected_fp()),"1057 completeunchanged numericx87 oracle");return o;}
inline void compare(const Observation&a,const Observation&d){need(a.scalar==d.scalar&&a.image==d.image&&a.arena==d.arena&&a.live==d.live&&a.events.size()==d.events.size(),"1057 pairedeveryheader/pixel/capacity/image/arena/fullEAX");for(unsigned id=0;id<6u;++id){const auto&x=a.events[id],&y=d.events[id];need(x.kind==y.kind&&x.ordinal==y.ordinal&&x.size==y.size,"1057 exactpairedallocationeventsafterprecisepointerproof");}}
inline void cleanup(b::HeapAdapter&h){if(h.live().empty())return;need(h.live().size()==6u,"1057 knowncompleteownership beforefixturecleanupoutsideobservation");for(unsigned id:{1u,0u,3u,2u,5u,4u})need(h.release(h.addresses[id])!=0u,"1057 outsideobservation actualownedpixels-beforeheader cleanup");need(h.live().empty(),"1057 allreturnedownershipcleaned");}
}
