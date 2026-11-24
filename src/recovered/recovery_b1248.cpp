#include "recovery_b1248.hpp"
#include "static_tables1248.hpp"
#include <stdexcept>
namespace ra2::recovered::b1248 {
unsigned run(Memory&m,const Inputs&,Heap&heap,Observation&o,unsigned root){
 if(root!=0x188220u)throw std::domain_error("1248 exact constant initializer root");
 for(const auto&h:constants::headers){
  // Meaningful original cold inputs are null; empty unused third words are
  // deliberately unread and preserved. No whole startup/lifecycle claim.
  if(m.r32(h.address)||m.r32(h.address+4u))throw std::domain_error("1248 cold count/pointer headers");
  m.w32(h.address,h.count);++o.headers;
  if(!h.count){m.w32(h.address+4u,0u);continue;}
  m.w32(h.address+8u,0u);const unsigned p=heap.allocate(8u*h.count);++o.allocations;
  if(!p)throw std::runtime_error("1248 successful actual allocation domain");
  m.w32(h.address+4u,p);
  // Actual587F20/40AED0 and588000/588050 default record construction is
  // completely overwritten by the constant coordinate/index copies.
  for(unsigned j=0;j<h.count;++j){heap.w32(p+8u*j,0u);heap.w32(p+8u*j+4u,0xffffffffu);}
  for(unsigned j=0;j<h.count;++j){const auto&r=constants::records[h.first+j];heap.w32(p+8u*j,r.coordinate);heap.w32(p+8u*j+4u,r.index);++o.records;}
 }
 return 0xa581c8u;
}
}
