#include "recovered/recovery_b1586.hpp"
#include <stdexcept>
namespace ra2::recovered::b1586 {namespace {
void need(bool v){if(!v)throw std::domain_error("B1586 finite standalone one-source append");}
void caller_byte(Caller&c,unsigned byte,unsigned value){const unsigned shift=(byte%4u)*8u;c[byte/4u]=(c[byte/4u]&~(255u<<shift))|((value&255u)<<shift);}
unsigned caller_byte(const Caller&c,unsigned byte){return (c[byte/4u]>>((byte%4u)*8u))&255u;}
}
unsigned run(Memory&m,const Inputs&i,Caller&caller,Heap&heap,Observation&o){const unsigned owner=i.cx,p=i.dx;need(owner!=0&&p!=0&&owner!=p&&m.r32(p)==0x79327cu);const unsigned count=m.r32(p+0x10);need(count==1);const unsigned source_array=m.r32(p+4);need(source_array!=0);const unsigned relation=m.r32(source_array);need(relation!=0);const unsigned self=heap.r32(relation);need(self!=0&&m.r32(self)==0x78612cu&&m.r32(self+4)==0x786110u&&m.r32(0x786158u)==0x41b580u&&m.r32(0x786120u)==0x40ffc0u);const unsigned h=m.r32(self+0x408);need(h!=0&&m.r32(h+4)==0x7931dcu&&m.r32(h+0x14)==1&&m.r32(m.r32(h+8))==p);const unsigned id=m.r32(self+0x10);for(unsigned k=0;k<4;++k)caller_byte(caller,7+k,id>>(8*k));caller_byte(caller,0xb,0x34); // Actual produced ID/type overwrite within the caller's 112-byte by-value area.
std::array<unsigned char,111>bytes{};for(unsigned k=0;k<111;++k)bytes[k]=static_cast<unsigned char>(caller_byte(static_cast<const Caller&>(caller),k));Memory copy=m;leaf::Memory local(bytes.data(),0x7c227000u,111u);copy.add(local);unsigned completed=0;do{Inputs child=i;child.cx=owner;child.arg[0]=self;child.arg[1]=0x7c227000u;const unsigned index=b1043::run(copy,child,heap,0x208940u,o);need(index<256u);i.fp=child.fp;++completed;}while(completed<count);return completed;}
}
