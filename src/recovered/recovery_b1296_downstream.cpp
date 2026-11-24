#include "recovery_b1296_downstream.hpp"
#include "recovered/global_b58_c.hpp"
#include "recovered/leaf_memory.hpp"
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::b1296 {
namespace {
void need(bool okay,const char* message){if(!okay)throw std::domain_error(message);}
unsigned pack(int x,int y){return (unsigned(std::uint16_t(y))<<16u)|unsigned(std::uint16_t(x));}

// Original 0x165690 makes two reverse traversals of the same three-entry
// vector. The accepted 0x157450 model is called for each produced point.
// Its AL0 route excludes both the map-label store and missing 0x163130.
void traverse(Memory& m,unsigned self,unsigned data){
 auto copy=m;
 leaf::Memory heap_span(reinterpret_cast<std::uint8_t*>(std::uintptr_t(data)),data,48u);
 copy.add(heap_span);
 need(copy.r32(self+0xf0u)==7u&&copy.r32(self+0xfcu)==0u,
      "1296 actual bounded Map predicate fields");
 for(unsigned pass=0;pass<2u;++pass)
  for(unsigned j=3u;j-->0u;){
   b1279::Inputs q{};q.cx=self;q.arg[0]=data+4u*j;q.arg[1]=1u;
   const unsigned result=global_b26::fun_00557450(copy,q);
   need(result==0u,"1296 genuine 157450 first-threshold rejection");
  }
}
}

unsigned region_scan(Memory& m,const b1279::Inputs& i,Heap& h){
 const unsigned rect=i.arg[0];
 const auto x=leaf::s32(m.r32(rect));
 const auto y=leaf::s32(m.r32(rect+4u));
 const auto width=m.r32(rect+8u),height=m.r32(rect+12u);
 need((x==1&&y==0&&width==1u&&height==3u)||
      (x==0&&y==1&&width==3u&&height==1u),
      "1296 exact 1x3/3x1 produced rectangle");
 need(m.r32(0x81a958u)!=0u,"1296 genuine borrowed cell-pointer table");
 const auto data=h.allocate(40u); // 0x42D050 requests 10*4; CRT aligns IAT extent to 48.
 need(data!=0u,"1296 allocating vector insertion");
 unsigned n=0u;
 for(unsigned xx=0;xx<width;++xx)
  for(unsigned yy=0;yy<height;++yy)
   h.w32(data+4u*n++,pack(x+int(xx),y+int(yy)));
 need(n==3u,"1296 three genuine vector points within capacity ten");
 traverse(m,i.cx,data);
 const auto freed=h.release(data); // Owned local vector: 0x76D67B after 0x165690.
 need(freed==1u,"1296 genuine 48-byte aligned CRT vector owner free");
 return freed;
}
}
