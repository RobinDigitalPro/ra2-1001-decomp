#include "recovery_b1221.hpp"
#include "platform/x87_state.hpp"
#include <stdexcept>
namespace ra2::recovered::b1221{
namespace fp=ra2::platform::x87;
static void need(bool x){if(!x)throw std::domain_error("1221 genuine scale1 Tactical footprint lists");}
static unsigned scaled(Memory&m,int dimension){
 fp::State f;f.image=fp::capture_host();const unsigned minimum=dimension==1?1u:2u;
 if(dimension==1)f.load32(m.r32(0x81bca4u));else{f.load_integer32(unsigned(dimension));f.multiply32(m.r32(0x81bca4u));}
 f.add64(0x3fe0000000000000ull);f.load64(minimum==1u?0x3ff0000000000000ull:0x4000000000000000ull);f.compare_pop_st1();
 if((f.status()&0x4100u)==0u){f.pop_st0();f.load64(minimum==1u?0x3ff0000000000000ull:0x4000000000000000ull);}
 // Real76AA50 keeps the fixed0E7F control word after FISTPq.
 f.load_control(static_cast<unsigned short>(m.r32(0x7c3a04u)));const auto out=f.pop_integer64();fp::restore_host(f.image);need(out>=1u&&out<=6u);return unsigned(out);
}
static void grow(Memory&m,Heap&h,unsigned v,unsigned capacity){
 need(m.r32(v)==0x791f7cu&&m.r8(v+0xcu)==1u&&m.r32(v+0x14u)==10u);const unsigned old=m.r32(v+4u),oldcap=m.r32(v+8u);m.w8(v+0xcu,0u);const unsigned p=h.allocate(8u*capacity);need(p!=0u);m.w8(v+0xcu,1u);
 if(old){const unsigned n=capacity<oldcap?capacity:oldcap;for(unsigned j=0;j<n;++j){h.w32(p+8u*j,h.r32(old+8u*j));h.w32(p+8u*j+4u,h.r32(old+8u*j+4u));}need(m.r8(v+0xdu)==1u);h.release(old);m.w32(v+4u,0u);}
 m.w32(v+4u,p);m.w32(v+8u,capacity);m.w8(v+0xdu,1u);if(capacity<m.r32(v+0x10u))m.w32(v+0x10u,capacity);
}
unsigned run(unsigned r,Memory&m,const Inputs&i,Heap&h){need(r==0x229d80u&&i.cx==0x81a820u&&m.r32(i.cx+0x1484u)==0x3f800000u);unsigned result=0u;
 for(unsigned shape=0;shape<22u;++shape){const unsigned v=i.cx+0x1274u+24u*shape;need(m.r32(v)==0x791f7cu&&m.r32(0x791f84u)==0x5ae6e0u&&m.r32(0x791f88u)==0x5ae2c0u);m.w32(v+0x10u,0u);const unsigned old=m.r32(v+4u);if(old){need(m.r8(v+0xdu)==1u);h.release(old);m.w32(v+4u,0u);}m.w8(v+0xdu,0u);m.w32(v+8u,0u);
  const int width=int(scaled(m,int(m.r32(0x7bac08u+4u*shape)))),height=int(scaled(m,int(m.r32(0x7bac60u+4u*shape))));
  for(int row=0;row<width+height-1;++row){int lo=row<height?-row:row-2*height+2;const int hi=row<width?row:2*width-row-2;
   for(int column=lo;column<=hi;++column){const unsigned used=m.r32(v+0x10u),capacity=m.r32(v+8u);if(used>=capacity){need((m.r8(v+0xdu)!=0u||capacity==0u)&&m.r32(v+0x14u)>0u);grow(m,h,v,capacity+m.r32(v+0x14u));}result=m.r32(v+0x10u);m.w32(v+0x10u,result+1u);const unsigned p=m.r32(v+4u);h.w32(p+8u*result,unsigned(column));h.w32(p+8u*result+4u,unsigned(row));}
  }
 }
 need(result==4u);return result;
}
}
