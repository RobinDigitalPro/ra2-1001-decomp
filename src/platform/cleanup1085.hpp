#pragma once
// Independent literal payload, complete state and ownership oracle.
#include <algorithm>
#include <cstring>
#include <stdexcept>
namespace ra2::platform::cleanup1085 {
namespace b=b1085_test;
inline void need(bool v,const char*s){if(!v)throw std::domain_error(s);}
struct Proof{std::array<unsigned,6>address{};unsigned token(unsigned raw,unsigned ordinal)const{need(ordinal<6u&&raw==address[ordinal],"1085 exact priorLIVE allocationbase relation");return 0xd0850000u+ordinal*0x100u;}};
struct World{
 unsigned base;b::Case c;World(unsigned a,b::Case v):base(a),c(v){}
 static constexpr unsigned arena_size=65536u;
 unsigned source(unsigned n)const{return base+0x100u+0x80u*n;}
 unsigned length(unsigned n)const{return 1u+b::mix(c.seed+17u*n)%17u;}
 unsigned unit(unsigned n,unsigned k)const{return 0x20u+b::mix(c.seed+31u*n+73u*k)%0x7dfu;}
 void setup(b::Memory&m,unsigned char*a)const{
  for(unsigned k=0;k<arena_size;++k)a[k]=static_cast<unsigned char>(b::mix(c.seed+131u*k));
  for(unsigned n=0;n<6u;++n){m.w32(0xa5a884u+4u*n,source(n));m.w32(0xa5a89cu+4u*n,0u);for(unsigned k=0;k<=length(n);++k){const unsigned v=k<length(n)?unit(n,k):0u;m.w8(source(n)+2u*k,v);m.w8(source(n)+2u*k+1u,v>>8u);}}
  // Exact BSS-backed constructor projection, no wholeowner execution claim.
  for(unsigned k=0;k<24u;++k)m.w8(0xa27da8u+k,0u);m.w32(0xa27da8u,0x791838u);m.w8(0xa27db4u,1u);m.w32(0xa27dbcu,10u);
 }
 b::Inputs input()const{b::Inputs i{};i.ax=b::mix(c.seed+1u);i.cx=b::mix(c.seed+2u);i.dx=b::mix(c.seed+3u);for(unsigned k=0;k<16u;++k)i.arg[k]=b::mix(c.seed+73u*k+17u);return i;}
 std::vector<unsigned char>payload(unsigned n)const{auto v=b::fresh(n,128u);std::fill(v.begin()+0x28u,v.begin()+0x32u,0xffu);for(unsigned k=0;k<=length(n);++k){const unsigned u=k<length(n)?unit(n,k):0u;v[2u*k]=static_cast<unsigned char>(u);v[2u*k+1u]=static_cast<unsigned char>(u>>8u);}return v;}
 Proof prove(const b::Memory&m,const b::HeapAdapter&h)const{
  // PREPASS complete real LIVE allocation graph before ANY normalization.
  need(h.live().size()==6u&&h.addresses.size()==6u&&h.allocation_flags==std::vector<unsigned>(6u,0u)&&h.events().size()==6u&&h.snapshots.empty(),"1085 exact sixLIVE fixturebuffers");Proof p;std::array<bool,6>seen{};
  for(const auto&v:h.live()){need(v.ordinal<6u&&!seen[v.ordinal]&&v.bytes==128u&&v.address==h.addresses[v.ordinal],"1085 fullLIVE inventory/roundedsize/ordinal");seen[v.ordinal]=true;const auto id=h.identify(v.address,v.bytes);need(id.ordinal==v.ordinal&&id.offset==0u,"1085 genuineLIVE fullrange identity");p.address[v.ordinal]=v.address;}
  for(unsigned n=0;n<6u;++n){need(seen[n]&&m.r32(0xa5a89cu+4u*n)==p.address[n],"1085 each publishedglobal exactLIVEbase");const auto&e=h.events()[n];need(e.kind==b::Event::Kind::allocate&&e.ordinal==n&&e.address==p.address[n]&&e.result==p.address[n]&&e.size==128u,"1085 actualfixtureallocateevent");std::vector<unsigned char>bytes(reinterpret_cast<const unsigned char*>(std::uintptr_t(p.address[n])),reinterpret_cast<const unsigned char*>(std::uintptr_t(p.address[n]))+128u);need(bytes==payload(n),"1085 fullindependentproducerbytes/sentinel/padding");}
  return p;
 }
 void normalize_input(std::vector<unsigned char>&image,const Proof&p)const{for(unsigned n=0;n<6u;++n)b::word(image,0x65a89cu+4u*n,p.token(b::readword(image,0x65a89cu+4u*n),n));}
};
struct Observation{std::vector<unsigned char>image,arena;std::vector<std::vector<unsigned char>>prefree;std::vector<unsigned>release_results;};
inline Observation verify(const World&w,const Proof&p,b::HeapAdapter&h,unsigned eax,const ra2::platform::x87::Image&numeric,const std::vector<unsigned char>&bi,const std::vector<unsigned char>&ba,const unsigned char*image,const unsigned char*arena){
 need(eax==0u&&h.live().empty()&&h.events().size()==24u&&h.snapshots.size()==6u,"1085 fullEAXzero/all6free/no retainedblocks");
 Observation o;o.image=bi;o.arena=ba;for(unsigned n=0;n<6u;++n)b::word(o.image,0x65a89cu+4u*n,0u);need(std::equal(o.image.begin(),o.image.end(),image)&&std::equal(ba.begin(),ba.end(),arena),"1085 independent completeimage/arena exactlysixclears");
 for(unsigned n=0;n<6u;++n){const auto&alloc=h.events()[n];need(alloc.kind==b::Event::Kind::allocate&&alloc.ordinal==n&&alloc.address==p.address[n]&&alloc.result==p.address[n]&&alloc.size==128u,"1085 preserved genuinefixtureevent");const auto&e=h.events()[6u+3u*n],&leave=h.events()[7u+3u*n],&release=h.events()[8u+3u*n];need(e.kind==b::Event::Kind::enter_lock&&leave.kind==b::Event::Kind::leave_lock&&e.address==leave.address&&e.address==b::readword(bi,0x41729cu)&&e.size==0u&&leave.size==0u&&e.ordinal==0u&&leave.ordinal==0u&&e.result==0u&&leave.result==0u,"1085 exactlockpair");need(release.kind==b::Event::Kind::release&&release.ordinal==n&&release.size==128u&&release.address==p.address[n]&&release.result!=0u,"1085 exactsuccessreleaseorder/rawpointer");const auto&s=h.snapshots[n];need(s.ordinal==n&&s.bytes==w.payload(n),"1085 fullroundedprefreebytes allsixproducerbuffers");o.prefree.push_back(s.bytes);o.release_results.push_back(release.result);}
 need(ra2::platform::x87::same_numeric(numeric,ra2::platform::x87::Image::empty(static_cast<std::uint16_t>(w.c.control))),"1085 fullnumericx87unchanged");return o;
}
inline void compare(const Observation&a,const Observation&d){need(a.image==d.image&&a.arena==d.arena&&a.prefree==d.prefree&&a.release_results==d.release_results,"1085 pairedfullimage/arena/prefreepayload/actualfreeBOOL");}
}
