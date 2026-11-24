#pragma once
// Fixture-only provider, included after recovery_b1040_cases.hpp.
#include "platform/map_vector1036.hpp"
namespace ra2::platform::heightfield1040 {
namespace b=b1040_test;namespace prior=ra2::platform::map_vector1036;
using prior::need;
struct World {
 unsigned root,base;b::Case c;prior::World map;
 static constexpr unsigned arena_size=1048576u,queue_offset=0x70000u;
 World(unsigned r,unsigned a,b::Case v):root(r),base(a),c(v),map(r,a,b1036_test::Case{v.seed,0u,1u,1u,v.land,v.land+1u,v.flag,v.height,1u}){}
 unsigned center_height()const{return(root==0x27bd40u?(c.mode?90u:60u)+15u*((c.seed>>20u)%3u):c.height);}
 unsigned background()const{return root==0x27bd40u?(c.mode?center_height()-30u:center_height()+30u):center_height();}
 unsigned edited_x()const{return c.x+((c.corner==1u||c.corner==2u)?1u:0u);}unsigned edited_y()const{return c.y+(c.corner>=2u?1u:0u);}
 void setup(b::Memory&m,unsigned char*arena,b::HeapAdapter&h)const{
  map.setup(m,arena,h);for(unsigned k=0;k<15u;++k){m.w8(map.object(k)+0x11bu,c.land);m.w8(map.object(k)+0x11cu,0u);m.w8(map.slot(b1031_test::coordinates[k])+0x45u,0u);}
  m.w32(0x81a940u,0u);m.w32(0x81a944u,0u);m.w32(0x81a948u,7u);m.w32(0x81a94cu,7u);
  need(m.r32(0x7963b4u)==0x67cab0u&&m.r32(0x7963bcu)==0x67c910u,"1040 authentic originaltriplet methods");
  // Byte-proven actual initializer67A670 supplies this genuine vptr and
  // constructed numeric fields. Its atexit registration is not executed.
  m.w32(0xaa4920u,0x7963b4u);m.w32(0xaa4924u,root==0x27bd40u?base+queue_offset:0u);m.w32(0xaa4928u,root==0x27bd40u?16u:0u);m.w8(0xaa492cu,1u);m.w8(0xaa492du,0u);m.w32(0xaa4930u,root==0x27bd40u?c.prefix:0u);m.w32(0xaa4934u,10u);
  if(root==0x27ad30u){m.w32(0xaa49b4u,0u);m.w32(0x810a20u,b::mix(c.seed+1u));m.w32(0x810a24u,b::mix(c.seed+2u));m.w32(0x810a28u,b::mix(c.seed+3u));m.w32(0x810a2cu,b::mix(c.seed+4u));}
  else{m.w32(0x810a20u,8u);m.w32(0x810a24u,8u);m.w32(0x810a28u,0u);m.w32(0x810a2cu,0u);const auto p=h.allocate(512u);for(unsigned k=0;k<64u;++k){h.w32(p+8u*k,background());h.w8(p+8u*k+4u,0u);h.w8(p+8u*k+5u,0u);}if(root==0x27bd40u)h.w32(p+8u*(c.y*8u+c.x),center_height());const auto id=h.identify(p,512u);need(id.ordinal==0u&&id.offset==0u,"1040 genuine fixtureheightfield whole512ownership");m.w32(0xaa49b4u,p);}
  need(m.r32(0x7dda0cu)==0xaa49a4u,"1040 genuine originalflatshape pointer");for(unsigned k=0;k<4u;++k)need(m.r32(0xaa49a4u+4u*k)==0u,"1040 original sixteenflatBSSbytes percase");
 }
 b::Inputs input()const{b::Inputs i{};i.ax=b::mix(c.seed+1u);i.cx=b::mix(c.seed+2u);i.dx=(b::mix(c.seed+3u)&0xffffff00u)|c.flag;for(unsigned k=0;k<16u;++k)i.arg[k]=b::mix(c.seed+73u*k+17u);if(root==0x27bd40u){i.cx=c.mode;i.arg[0]=c.x;i.arg[1]=c.y;}if(root==0x27c120u){i.cx=c.mode?1u:0xffffffffu;i.arg[0]=c.x|(c.y<<16u);i.arg[1]=1u<<c.corner;}return i;}
 std::array<unsigned,16> caller()const{auto out=input().arg;if(root==0x27c120u){out[0]=c.x+2u;out[1]=c.y+2u;}return out;}
 unsigned expected_eax()const{return root==0x27ad30u?8u:1u;}
 bool covered(unsigned x,unsigned y)const{for(unsigned p:b1031_test::coordinates){const unsigned px=p&65535u,py=p>>16u;if((x==px||x==px+1u)&&(y==py||y==py+1u))return true;}return false;}
 std::vector<unsigned> allocation_sizes()const{return root==0x27c120u?std::vector<unsigned>{512u,128u}:std::vector<unsigned>{512u};}
 void expected_memory(std::vector<unsigned char>&image,std::vector<unsigned char>&arena,const b::HeapAdapter&h)const{
  const auto iw=[&](unsigned p,unsigned value){b::word(image,p-0x400000u,value);};
  if(root==0x27ad30u){iw(0xaa49b4u,h.addresses.at(0u));iw(0x810a20u,8u);iw(0x810a24u,8u);iw(0x810a28u,0u);iw(0x810a2cu,0u);}
  if(root==0x27bd40u){iw(0xaa4930u,c.prefix+8u);unsigned n=c.prefix;for(int dy=-1;dy<2;++dy)for(int dx=-1;dx<2;++dx){if(!dx&&!dy)continue;const auto at=queue_offset+12u*n++;b::word(arena,at,unsigned(int(c.x)+dx));b::word(arena,at+4u,unsigned(int(c.y)+dy));b::word(arena,at+8u,background());}}
  if(root==0x27c120u){iw(0xaa4924u,h.addresses.at(1u));iw(0xaa4928u,10u);image.at(0x6a492cu)=1u;image.at(0x6a492du)=1u;iw(0xaa4930u,1u);}
 }
 std::vector<unsigned char> block_expected(unsigned id)const{
  auto v=b::fresh(id,allocation_sizes().at(id));
  if(id==0u){for(unsigned y=0;y<8u;++y)for(unsigned x=0;x<8u;++x){const unsigned p=8u*(y*8u+x);unsigned height=background(),fixed=0u,changed=0u;if(root==0x27ad30u){height=covered(x,y)?15u*c.land:0u;fixed=covered(x,y)?0u:1u;}else if(root==0x27bd40u){if(x==c.x&&y==c.y)height=center_height();else if(x+1u>=c.x&&x<=c.x+1u&&y+1u>=c.y&&y<=c.y+1u){height=c.mode?center_height()-15u:center_height()+15u;changed=1u;}}else if(x==edited_x()&&y==edited_y()){height=c.mode?center_height()+15u:center_height()-15u;changed=1u;}b::word(v,p,height);v[p+4u]=static_cast<unsigned char>(fixed);v[p+5u]=static_cast<unsigned char>(changed);}}
  else{std::fill(v.begin(),v.begin()+120u,0u);b::word(v,0u,edited_x());b::word(v,4u,edited_y());b::word(v,8u,center_height());}
  return v;
 }
};
struct Observation{std::vector<b::Event>events;std::vector<std::vector<unsigned char>>live;unsigned heap_bytes{},scalar{};};
inline Observation verify(const World&w,b::HeapAdapter&h,unsigned eax,const std::vector<unsigned char>&before_image,const std::vector<unsigned char>&before_arena,const unsigned char*image,const unsigned char*arena){
 const auto sizes=w.allocation_sizes();need(h.addresses.size()==sizes.size()&&h.allocation_flags.size()==sizes.size()&&h.events().size()==sizes.size()&&h.snapshots.empty(),"1040 exactfixture/targetallocs;zero targetfree/CS/prefreeevents");Observation out;out.events=h.events();for(unsigned k=0;k<sizes.size();++k){const auto&e=out.events[k];need(e.kind==b::Event::Kind::allocate&&e.ordinal==k&&e.size==sizes[k]&&e.address==h.addresses[k]&&e.result==h.addresses[k]&&h.allocation_flags[k]==0u,"1040 exactgenuineallocation identity/flags/roundedsize");out.heap_bytes+=sizes[k];}
 auto expected_image=before_image,expected_arena=before_arena;w.expected_memory(expected_image,expected_arena,h);need(std::equal(expected_image.begin(),expected_image.end(),image)&&std::equal(expected_arena.begin(),expected_arena.end(),arena),"1040 full7503872image and1MiBarena independentoracle includingjournalcapacity/prefix");auto live=h.live();std::sort(live.begin(),live.end(),[](const auto&a,const auto&d){return a.ordinal<d.ordinal;});need(live.size()==sizes.size(),"1040 completeowned liveheapinventory");for(const auto&l:live){need(l.ordinal<live.size()&&l.address==h.addresses[l.ordinal]&&l.bytes==sizes[l.ordinal],"1040 exactall-liveheapordinal");auto bytes=std::vector<unsigned char>(reinterpret_cast<const unsigned char*>(std::uintptr_t(l.address)),reinterpret_cast<const unsigned char*>(std::uintptr_t(l.address))+l.bytes);need(bytes==w.block_expected(l.ordinal),"1040 full512heightfield/full128journal incl30zeroDWORDs/8roundedtail bytes independentoracle");out.live.push_back(std::move(bytes));}
 const auto height=h.identify(b::readword(expected_image,0x6a49b4u),512u);need(height.ordinal==0u&&height.offset==0u&&b::readword(expected_image,0x6a49b4u)==h.addresses[0u],"1040 exactwhole512genuine ownedheightfield pointer relation");if(w.root==0x27c120u){const auto id=h.identify(b::readword(expected_image,0x6a4924u),128u);need(id.ordinal==1u&&id.offset==0u&&b::readword(expected_image,0x6a4924u)==h.addresses[1u],"1040 exactwhole128newjournalallocation pointer relation");}need(eax==w.expected_eax(),"1040 independent fullEAX producerwidth8 /positiveheightedit1");out.scalar=eax;return out;
}
inline void compare(const Observation&a,const Observation&d){need(a.scalar==d.scalar&&a.live==d.live&&a.events.size()==d.events.size(),"1040 pairedfullEAX/allroundedheapbytes");for(unsigned k=0;k<a.events.size();++k){const auto&x=a.events[k],&y=d.events[k];need(x.kind==y.kind&&x.ordinal==y.ordinal&&x.size==y.size,"1040 completefixture/targetallocation event pair");}}
inline void cleanup(b::HeapAdapter&h){for(const auto&l:h.live())need(h.release(l.address)!=0u,"1040 genuine ownedheight/journal cleanup onlyafterallobservations");need(h.live().empty(),"1040 allownedoutputs finallyfreed");}
inline void normalize_final(std::vector<unsigned char>&image,unsigned root){b::word(image,0x6a49b4u,0xd0400000u);if(root==0x27c120u)b::word(image,0x6a4924u,0xd0400001u);}
}
