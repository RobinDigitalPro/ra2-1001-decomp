#include "recovered/recovery_b1167.hpp"
#include <stdexcept>
namespace ra2::recovered::b1167 {namespace {
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
void read(Memory&m,unsigned file,unsigned out,unsigned bytes,Observation&z){need(m.r32(file)==0x793bf4u&&m.r8(file+24u)==1u&&(m.r8(file+20u)&1u),"1167 genuine borrowed open MemFile");const unsigned pos=m.r32(file+16u),len=m.r32(file+12u),data=m.r32(file+4u);need(pos<=len&&bytes<=len-pos,"1167 complete positive read extent");for(unsigned j=0;j<bytes;++j)m.w8(out+j,m.r8(data+pos+j));m.w32(file+16u,pos+bytes);++z.file_reads;z.virtual_callbacks+=2u;}
unsigned word(Memory&m,unsigned a){return m.r8(a)|(m.r8(a+1u)<<8u);}
}
// RVA24110, finite original424070 post-open input domain. The borrowed file
// callbacks are translated from their pinned bodies; no original GAME call.
unsigned run(Memory&m,Inputs&i,Heap&h,unsigned root,unsigned base,Observation&z){
 const unsigned self=i.cx,file=m.r32(self+0x84u);need(root==0x24110u&&self>=base+0x1000u&&self<=base+0x4000u&&m.r32(self)==0x787294u&&m.r8(self+0x88u)==0u&&m.r8(self+0x89u)==1u,"1167 fresh ANIM constructor and actual borrowed-file wrapper");need(file==base+0x6000u&&m.r32(file+16u)==0u&&m.r32(file+12u)==2816u,"1167 exact whole generated LPF stream");
 m.w8(self+0x88u,1u);for(unsigned j=0;j<128u;++j)m.w8(self+0x8cu+j,0u);read(m,file,self+0x8cu,128u,z);for(unsigned j=0;j<128u;++j)m.w8(self+4u+j,0u);read(m,file,self+4u,128u,z);
 // Original relative Seek(0,1), current position256 stays within read length.
 need(m.r8(file+24u)==1u&&m.r32(file+16u)==256u,"1167 genuine relative seek state");++z.relative_seeks;z.virtual_callbacks+=2u;
 read(m,file,self+0x10cu,1024u,z);for(unsigned j=0;j<256u;++j){m.w8(self+0x50cu+3u*j,m.r8(self+0x10eu+4u*j));m.w8(self+0x50du+3u*j,m.r8(self+0x10du+4u*j));m.w8(self+0x50eu+3u*j,m.r8(self+0x10cu+4u*j));++z.palette_entries;}
 for(unsigned j=0;j<1536u;++j)m.w8(self+0x80cu+j,0u);read(m,file,self+0x80cu,1536u,z);
 need(m.r32(self+0x8cu)==0x2046504cu&&m.r32(self+0x9cu)==0x4d494e41u&&word(m,self+0x90u)==256u&&m.r32(self+0x94u)<=65535u&&word(m,self+0x98u)<=256u&&word(m,self+0x9au)==1280u&&word(m,self+0xa0u)==320u&&word(m,self+0xa2u)==200u&&m.r8(self+0xa9u)<=1u&&m.r8(self+0xabu)==1u&&m.r8(self+0xaau)==0u&&m.r8(self+0xa8u)==0u,"1167 actual242B0 LPF format checks");const unsigned n=word(m,self+0x92u);need(n>=1u&&n<=6u,"1167 positive LPF entry count");for(unsigned j=0;j<n;++j)need(word(m,self+0x80eu+6u*j)<=256u,"1167 actual242B0 entry constraints");
 const unsigned surf=h.allocate(32u);++z.allocations;need(surf!=0u,"1167 successful real surface allocation");h.w32(surf+4u,320u);h.w32(surf+8u,200u);h.w32(surf+12u,0u);h.w32(surf+16u,1u);h.w32(surf,0x785f8cu);h.w32(surf+20u,0u);h.w32(surf+24u,64000u);h.w8(surf+28u,0u);
 const unsigned pixels=h.allocate(64000u);++z.allocations;need(pixels!=0u,"1167 successful real pixel allocation");h.w32(surf+20u,pixels);h.w8(surf+28u,1u);h.w32(surf,0x785ef8u);
 const unsigned scratch=h.allocate(65536u);++z.allocations;need(scratch!=0u,"1167 successful real scratch allocation");m.w32(self+0xe0cu,surf);m.w32(self+0xe10u,scratch);for(unsigned j=0;j<65536u;++j)h.w8(scratch+j,0u);return 1u;
}}
