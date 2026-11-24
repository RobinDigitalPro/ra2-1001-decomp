#include "recovery_b1260.hpp"
#include <stdexcept>
namespace ra2::recovered::b1260 {namespace {
void need(bool v){if(!v)throw std::domain_error("1260 successful cold console-page domain");}
unsigned reset(Heap&h,unsigned p,Observation&o){
 unsigned eax=0;for(unsigned row=0;row<25u;++row){unsigned character=p+row;eax=p+2000u+4u*row;for(unsigned col=0;col<80u;++col){h.w8(character,32u);h.w32(eax,0u);character+=25u;eax+=100u;++o.characters;++o.attributes;}}
 h.w8(p+0x2734u,1u);++o.resets;++o.guard_calls;
 // Actual59B880 cold B22 guard writes AL0, with no API/callback reached.
 return eax&0xffffff00u;
}
}
unsigned run(Memory&m,Inputs&i,Heap&heap,Observation&o,unsigned root){
 need(root==0x19a570u&&m.r8(0xa58b21u)==0u&&m.r8(0xa58b22u)==0u&&m.r32(0xa58b28u)==0u&&(i.arg[0]&255u)<=1u);
 for(unsigned j=0;j<8u;++j)need(m.r32(0xa58a58u+4u*j)==0u);
 m.w32(0xa58b18u,i.cx);m.w32(0xa58b1cu,i.dx);m.w8(0xa58b20u,i.arg[0]&255u);
 i.arg[0]=0u;for(unsigned j=0;j<8u;++j){const unsigned p=heap.allocate(10040u);need(p!=0u);++o.allocations;heap.w32(p+0x2718u,j);for(unsigned off=0x271cu;off<=0x2728u;off+=4u)heap.w32(p+off,0u);heap.w32(p+0x272cu,80u);heap.w32(p+0x2730u,25u);reset(heap,p,o);m.w32(0xa58a58u+4u*j,p);i.arg[0]=j+1u;}
 m.w32(0xa58b24u,m.r32(0xa58a58u));unsigned eax=0u;for(unsigned j=0;j<8u;++j)eax=reset(heap,m.r32(0xa58a58u+4u*j),o);
 return eax; // Actual final MOV AL,coldB21=0 preserves these upper24 bits.
}
unsigned cleanup(Memory&m,Heap&heap){
 need(m.r32(0xa58b28u)==0u);for(unsigned j=0;j<8u;++j){const unsigned a=0xa58a58u+4u*j,p=m.r32(a);need(p!=0u&&heap.release(p)!=0u);m.w32(a,0u);}return 0u;
}
}
