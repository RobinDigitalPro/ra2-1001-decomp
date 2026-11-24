#include "recovered/recovery_b1134.hpp"
#include <stdexcept>
namespace ra2::recovered::b1134 {
unsigned run(Memory&m,Inputs&i,Heap&,unsigned root,unsigned base,Observation&z){
 if(root==0x216b40u){if(i.cx!=0xa5e540u||m.r32(i.cx)!=0x7933fcu||i.arg[0]==0xffffffffu||i.arg[2]!=base+0x6000u||i.arg[3]!=i.arg[4]||(i.arg[3]&255u)>1u)throw std::domain_error("1134 original static7933FC explicit coordinate/borrowedtext/boolean producer route");m.w32(i.cx+0x68u,i.arg[0]);m.w32(i.cx+0x6cu,i.arg[1]);m.w32(i.cx+0x50u,i.arg[2]);m.w8(i.cx+0x70u,i.arg[3]);m.w8(i.cx+0x71u,i.arg[4]);z.field_writes=5u;return(i.arg[0]&0xffffff00u)|(i.arg[3]&255u);}
 if(root==0x5df00u){if(i.cx!=base+0x1000u||i.arg[0]!=base+0x5000u||m.r32(i.cx+0x11ecu)==m.r32(0x8370c8u))throw std::domain_error("1134 useful positive cached rectangle differs original zero sentinel/disjoint caller output");for(unsigned k=0;k<4u;++k)m.w32(i.arg[0]+k*4u,m.r32(i.cx+0x11ecu+k*4u));z.copy_dwords=4u;return i.arg[0];}
 if(root==0x21ea50u){const unsigned bucket=i.dx,n=bucket<8u?m.r32(0xa25e80u+bucket*4u):0u;if(bucket>=8u||n<2u||n>6u||i.cx!=7u||m.r32(0xa255c8u)!=0u)throw std::domain_error("1134 populated unique positive bounded8slot bucket/mode0 original caller");for(unsigned j=0;j<n;++j)if(m.r32(0xa25ea0u+bucket*32u+j*4u)==i.cx)throw std::domain_error("1134 uniqueappend must not take duplicate/nochange return");m.w32(0xa25ea0u+bucket*32u+n*4u,i.cx);m.w32(0xa25e80u+bucket*4u,n+1u);z.appends=1u;return 0u;}
 throw std::domain_error("1134 exactly three useful closed roots");
}
}
