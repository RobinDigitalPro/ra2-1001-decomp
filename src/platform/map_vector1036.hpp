#pragma once
// Included after the fixture cases, never by recovered reconstruction code.
#include "platform/map_vector1031.hpp"
namespace ra2::platform::map_vector1036 {
namespace b=b1036_test;namespace old=ra2::platform::map_vector1031;
using old::need;
struct World {
 unsigned root,base;b::Case c;old::World initial;
 static constexpr unsigned arena_size=1048576u,receiver_offset=0x400u,registry_offset=0x70000u;
 static constexpr unsigned center=0x00030003u;
 static constexpr unsigned last_missing[]{0x00010002u,0x00020005u,0x00020005u,0x00050005u,0x00050002u,0x00040001u,0x00020001u,0x00010001u};
 World(unsigned r,unsigned a,b::Case v):root(r),base(a),c(v),initial(r==0x16ce30u?0x16bb00u:0x17ece0u,a,b1031_test::Case{v.seed,0u,0u,1u,v.growth,v.direction,1u}){}
 unsigned receiver()const{return base+receiver_offset;}unsigned object(unsigned k)const{return base+0x30000u+0x200u*k;}unsigned point()const{return center;}unsigned eligible_index()const{return unsigned(b1031_test::adjacent[1][c.direction]);}unsigned eligible()const{return b1031_test::coordinates[eligible_index()];}
 unsigned slot(unsigned p)const{return initial.slot(p);}unsigned own()const{return initial.c.owned;}unsigned types()const{return initial.c.types;}
 bool walks()const{return root==0x16ce30u||root==0x27bb10u||(root==0x17e9f0u&&c.iterations==2u);}
 void setup(b::Memory&m,unsigned char*arena,b::HeapAdapter&h)const{
  initial.setup(m,arena);
  for(unsigned k=0;k<15u;++k){const auto p=b1031_test::coordinates[k],o=object(k);m.w32(initial.table()+4u*((p>>16u)*512u+(p&65535u)),o);m.w32(o+0x24u,p);m.w32(o+0x38u,root==0x172b10u&&k==6u?0u:0xffffu);m.w32(o+0x44u,0xffffffffu);m.w32(o+0x4cu,0u);m.w32(o+0xe4u,0u);m.w8(o+0x11au,0x80u+(c.seed+k)%64u);m.w8(o+0x11bu,c.land+1u);m.w8(o+0x11cu,0x70u+(c.seed+k)%64u);m.w32(slot(p)+0x3cu,root==0x172b10u?0xffffffffu:b::mix(c.seed+19u+k));if(root==0x27bb10u)m.w8(slot(p)+0x45u,0u);}
  m.w32(receiver()+16u,c.land);m.w8(receiver()+0x30cu,c.new_land);
  if(root==0x16ce30u){m.w32(slot(eligible())+0x38u,0xffffffffu);m.w8(object(eligible_index())+0x11bu,c.land);m.w32(object(eligible_index())+0x38u,0u);}
  if(root==0x17e740u){m.w32(slot(eligible())+0x38u,0u);m.w32(object(eligible_index())+0x38u,0u);}
  if(root==0x172b10u){
   m.w8(object(6u)+0x11bu,c.land);need(m.r32(0xa547acu)==0u,"1036 authentic initial classification-base0 actualfirst-range constructorbranch");
   const unsigned categories=base+0x40000u,values=base+0x41000u;m.w32(0x81a884u,categories);m.w32(0x81a888u,49u);m.w32(0x81a838u,values);
   for(unsigned k=0;k<49u;++k)m.w16(categories+4u*k+2u,3u);m.w16(categories+4u*((eligible()>>16u)*7u+(eligible()&65535u))+2u,2u);m.w16(values+4u,c.kind);m.w16(values+6u,c.kind+1u);
   // A preallocated current registry, consistent IDs0..types-1. Its original
   // vptr is retained; capacity8 makes the ctor's virtual growth unreachable.
   m.w32(0xa57944u,base+registry_offset);m.w32(0xa57948u,8u);m.w8(0xa5794cu,1u);m.w8(0xa5794du,0u);m.w32(0xa57950u,types());m.w32(0xa57954u,10u);
   for(unsigned k=0;k<types();++k){const auto p=base+0x80000u+0x80u*k;m.w32(base+registry_offset+4u*k,p);m.w32(p,0u);m.w32(p+4u,0u);m.w32(p+8u,k);m.w32(p+12u,0u);m.w32(p+0x2cu,0u);m.w32(p+0x30u,0u);m.w8(p+0x34u,1u);m.w8(p+0x35u,0u);m.w32(p+0x38u,0u);m.w32(p+0x3cu,100000u);}
  }
  if(root==0x27bb10u){
   // Actual producer67AD4F..67AE05 allocates8*(width+1)*(height+1)
   // from Map+128/+12C and records originMap+120/+124. Prepared7x7
   // physical extent therefore supplies a genuine8x8 corner field.
   m.w32(0x81a940u,0u);m.w32(0x81a944u,0u);m.w32(0x81a948u,7u);m.w32(0x81a94cu,7u);m.w32(0x810a20u,8u);m.w32(0x810a24u,8u);m.w32(0x810a28u,0u);m.w32(0x810a2cu,0u);
   const auto p=h.allocate(512u);for(unsigned k=0;k<64u;++k){h.w32(p+8u*k,c.height);h.w8(p+8u*k+4u,0u);h.w8(p+8u*k+5u,1u);}const auto id=h.identify(p,512u);need(id.ordinal==0u&&id.offset==0u,"1036 exact genuine owned heightfield allocation beforetarget");m.w32(0xaa49b4u,p);
   need(m.r32(0x7dda0cu)==0xaa49a4u&&m.r32(0xa3ab38u)==0u,"1036 original immutable flat-pattern pointer and initialtile0");for(unsigned k=0;k<4u;++k)need(m.r32(0xaa49a4u+4u*k)==0u,"1036 actual BSSflatshape fourzeroheights preserved");
  }
 }
 b::Inputs input()const{b::Inputs i{};i.ax=b::mix(c.seed+1u);i.cx=receiver();i.dx=b::mix(c.seed+2u);for(unsigned k=0;k<16u;++k)i.arg[k]=b::mix(c.seed+73u*k+17u);if(root==0x16ce30u)i.arg[0]=1u;else if(root==0x17e740u){i.arg[0]=own();i.arg[1]=1u;i.arg[2]=eligible()&65535u;i.arg[3]=eligible()>>16u;i.arg[4]=1u;i.arg[5]=1u;i.arg[6]=(i.arg[6]&0xffffff00u)|c.flag;i.arg[7]=(i.arg[7]&0xffffff00u)|c.new_land;}else if(root==0x17e9f0u){i.arg[0]=own();i.arg[1]=c.iterations;i.arg[2]=(own()+1u)%types();}else if(root==0x172b10u){i.cx=object(6u);i.dx=0u;i.arg[0]=c.kind;}return i;}
 std::array<unsigned,16> caller()const{auto words=input().arg;if(root==0x17e9f0u&&c.iterations==2u)words[1]=0x00040005u;return words;}
 std::vector<unsigned> allocation_sizes()const{if(root==0x16ce30u)return{32u,48u,32u,16u};if(root==0x17e740u)return{32u,16u,32u,16u};if(root==0x17e9f0u)return c.iterations==1u?std::vector<unsigned>{32u,16u}:std::vector<unsigned>{32u,16u,32u};if(root==0x172b10u)return{80u,80000u,400000u};return{512u};}
 std::vector<unsigned> free_order()const{if(root==0x16ce30u||root==0x17e740u)return{1u,0u,3u,2u};if(root==0x17e9f0u)return c.iterations==1u?std::vector<unsigned>{1u,0u}:std::vector<unsigned>{1u,0u,2u};if(root==0x172b10u)return{1u};return{0u};}
 void expected_memory(std::vector<unsigned char>&image,std::vector<unsigned char>&arena,const b::HeapAdapter&h)const{
  const auto iw=[&](unsigned p,unsigned x){b::word(image,p-0x400000u,x);};const auto aw=[&](unsigned p,unsigned x){b::word(arena,p-base,x);};
  if(walks()){iw(0x81a928u,5u);iw(0x81a92cu,5u);iw(0x81a930u,1u);iw(0x81a934u,initial.table()+10260u);}
  if(root==0x16ce30u)aw(slot(eligible())+0x38u,own());
  if(root==0x17e740u){aw(slot(eligible())+0x38u,own());if(c.flag)arena.at(object(eligible_index())-base+0x11bu)=static_cast<unsigned char>(c.new_land);}
  if(root==0x17e9f0u){aw(slot(center)+0x38u,(own()+1u)%types());aw(object(6u)+0x38u,0u);arena.at(object(6u)-base+0x11au)=0u;arena.at(object(6u)-base+0x11bu)=static_cast<unsigned char>(c.new_land);if(c.iterations==2u)for(unsigned p:b1031_test::coordinates)aw(slot(p)+0x3cu,0u);}
  if(root==0x172b10u){iw(0xa58640u,types()+1u);iw(0xa57950u,types()+1u);iw(0xa57634u,last_missing[c.direction]);aw(base+registry_offset+4u*types(),h.addresses.at(0u));aw(slot(center)+0x38u,types());aw(slot(center)+0x3cu,types());aw(slot(eligible())+0x38u,types());aw(slot(eligible())+0x3cu,types());}
  if(root==0x27bb10u){iw(0xaa49b4u,0u);for(unsigned k=0;k<15u;++k){aw(object(k)+0x38u,0u);arena.at(object(k)-base+0x11bu)=static_cast<unsigned char>(c.height/15u);arena.at(object(k)-base+0x11cu)=0u;}}
 }
 std::vector<unsigned char> block_expected(unsigned id,const b::HeapAdapter&h)const{
  auto v=b::fresh(id,allocation_sizes().at(id));const auto dead=[&](unsigned count,unsigned growth){b::word(v,0u,0x7875e0u);b::word(v,4u,0u);b::word(v,8u,0u);v[12]=1u;v[13]=0u;b::word(v,16u,count);b::word(v,20u,growth);};
  if(root==0x16ce30u||root==0x17e740u){if(id==0u)dead(1u,root==0x16ce30u?10u:c.growth);else if(id==1u)b::word(v,0u,center);else if(id==2u)dead(1u,3u);else b::word(v,0u,eligible());}
  else if(root==0x17e9f0u){if(id==0u)dead(1u,c.growth);else if(id==1u)b::word(v,0u,center);else dead(0u,1u);}
  else if(root==0x172b10u){if(id==0u){for(unsigned p:{0u,4u,28u,32u,64u,68u,72u,76u})b::word(v,p,0u);b::word(v,8u,types());b::word(v,12u,2u);b::word(v,16u,c.land);v[20]=1u;b::word(v,22u,center);v[26]=0u;v[27]=1u;v[36]=0u;b::word(v,40u,0x7875a0u);b::word(v,44u,h.addresses.at(2u));b::word(v,48u,100000u);v[52]=1u;v[53]=1u;b::word(v,56u,2u);b::word(v,60u,100000u);}else{b::word(v,0u,id==1u?eligible():center);if(id==2u)b::word(v,4u,eligible());}}
  else for(unsigned k=0;k<64u;++k){b::word(v,8u*k,c.height);v[8u*k+4u]=0u;v[8u*k+5u]=1u;}
  return v;
 }
};
struct Observation{std::vector<b::Event>events;std::vector<std::vector<unsigned char>>prefree,live;unsigned scalar{},heap_bytes{},prefree_bytes{};};
inline Observation verify(const World&w,b::HeapAdapter&h,unsigned eax,const std::vector<unsigned char>&before_image,const std::vector<unsigned char>&before_arena,const unsigned char*image,const unsigned char*arena){
 const auto sizes=w.allocation_sizes(),freed=w.free_order();need(h.addresses.size()==sizes.size()&&h.allocation_flags.size()==sizes.size()&&h.snapshots.size()==freed.size()&&h.events().size()==sizes.size()+3u*freed.size(),"1036 all fixture/targetallocations/freeevents/snapshots exactinventory");Observation out;out.events=h.events();unsigned cursor=0u;for(unsigned k=0;k<sizes.size();++k){const auto&e=out.events[cursor++];need(e.kind==b::Event::Kind::allocate&&e.ordinal==k&&e.size==sizes[k]&&e.address==h.addresses[k]&&e.result==h.addresses[k]&&h.allocation_flags[k]==0u,"1036 genuine exactordinal/roundedsize/flags/fullallocationpointer");out.heap_bytes+=sizes[k];}
 for(unsigned k=0;k<freed.size();++k){const auto id=freed[k];const auto&e=out.events[cursor++],&l=out.events[cursor++],&f=out.events[cursor++];need(e.kind==b::Event::Kind::enter_lock&&l.kind==b::Event::Kind::leave_lock&&e.address==l.address&&e.address==b::readword(before_image,0x41729cu)&&e.ordinal==0u&&l.ordinal==0u&&e.size==0u&&l.size==0u&&e.result==0u&&l.result==0u&&f.kind==b::Event::Kind::release&&f.ordinal==id&&f.address==h.addresses[id]&&f.size==sizes[id]&&f.result!=0u,"1036 exact realCRTlock and fullBOOLreleaseorder");need(h.snapshots[k].ordinal==id&&h.snapshots[k].bytes==w.block_expected(id,h),"1036 every originalprefreebyte including80000work/roundedpadding/capacity exactindependent oracle");out.prefree.push_back(h.snapshots[k].bytes);out.prefree_bytes+=sizes[id];}
 auto expected_image=before_image,expected_arena=before_arena;w.expected_memory(expected_image,expected_arena,h);need(std::equal(expected_image.begin(),expected_image.end(),image)&&std::equal(expected_arena.begin(),expected_arena.end(),arena),"1036 completeoriginalimage and1MiBarena independentoracle");auto live=h.live();std::sort(live.begin(),live.end(),[](const auto&a,const auto&d){return a.ordinal<d.ordinal;});need(live.size()==sizes.size()-freed.size(),"1036 completeall-liveallocation inventory");for(const auto&l:live){need(l.bytes==sizes[l.ordinal]&&l.address==h.addresses[l.ordinal],"1036 liveallocation exactidentity");auto bytes=std::vector<unsigned char>(reinterpret_cast<const unsigned char*>(std::uintptr_t(l.address)),reinterpret_cast<const unsigned char*>(std::uintptr_t(l.address))+l.bytes);need(bytes==w.block_expected(l.ordinal,h),"1036 full400000regionarray/capacityandcontextpadding rawindependentoracle");if(l.ordinal==0u){need(w.root==0x172b10u,"1036 only regionretains output");const auto id=h.identify(b::readword(bytes,44u),400000u);need(id.ordinal==2u&&id.offset==0u&&b::readword(bytes,44u)==h.addresses[2u],"1036 embeddedvectorpointer exact400000byte ordinal2zerooffset before normalization");b::word(bytes,44u,0xd0360002u);}out.live.push_back(std::move(bytes));}
 if(w.root==0x172b10u){const auto id=h.identify(b::readword(expected_arena,World::registry_offset+4u*w.types()),80u);need(id.ordinal==0u&&id.offset==0u,"1036 actualregistered completecontext pointer ordinal0 provenance");out.scalar=out.events.back().result;need(eax==out.scalar,"1036 fullEAX realworkarray HeapFreeBOOL");}
 else if(w.root==0x27bb10u){out.scalar=(out.events.back().result&0xffffff00u)|1u;need(eax==out.scalar,"1036 fullEAX realheightfield HeapFreeBOOLhigh24 plusAL1");}
 else if(w.root==0x17e9f0u&&w.c.iterations==2u){need(eax==1u,"1036 finalgenuine iteratorNULL establishesfullEAX1 afterMOVAL1");out.scalar=1u;}
 else{const unsigned id=w.root==0x17e9f0u?0u:2u;need(out.events.back().kind==b::Event::Kind::release&&out.events.back().ordinal==id&&out.events.back().address==h.addresses[id],"1036 actuallastdeletingwrapper freedits exactknownnewheader");need(eax==((h.addresses[id]&0xffffff00u)|1u),"1036 fullEAX byteproven wrapperMOV EAX,ESI selfreturn plusrootMOVAL1; no post-release dereference");out.scalar=0xd0360000u+id;}
 return out;
}
inline void compare(const Observation&a,const Observation&d){need(a.scalar==d.scalar&&a.prefree==d.prefree&&a.live==d.live&&a.events.size()==d.events.size(),"1036 fullEAX exactprovedreturnrelation/allheapbytes paired");for(unsigned k=0;k<a.events.size();++k){const auto&x=a.events[k],&y=d.events[k];need(x.kind==y.kind&&x.ordinal==y.ordinal&&x.size==y.size,"1036 everyallocation/lock/freeevent pair");if(x.kind==b::Event::Kind::release)need(x.result==y.result,"1036 actualfullHeapFreeBOOLpair");if(x.kind==b::Event::Kind::enter_lock||x.kind==b::Event::Kind::leave_lock)need(x.address==y.address&&x.result==y.result,"1036 samegenuineCRTcriticalsectionpair");}}
inline void cleanup(b::HeapAdapter&h){old::cleanup(h);}
}
