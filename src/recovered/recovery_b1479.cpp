#include "recovered/recovery_b1479.hpp"
#include "recovered/recovery_b251.hpp"
#include <stdexcept>
namespace ra2::recovered::b1479 {namespace {
using U=std::uint32_t;void need(bool v,const char*s){if(!v)throw std::domain_error(s);}
// Real979 ownership adapter. The fixture declares committed actualheap spans
// before entry so all nested B251 Memory copies see the same realbytes.
struct IntroHeap final:recovery_b251::Heap{
 Memory&m;b1479::Heap&heap;IntroHeap(Memory&v,b1479::Heap&h):m(v),heap(h){}
 U allocate(U n)override{const U p=heap.allocate(n);need(p&&n,"1479 genuine positiveowner");const U raw=(n+15)&~15u;for(U k=0;k<raw;++k)need(m.r8(p+k)==heap.r8(p+k),"1479 owner outside predeclared genuineheap view");return p;}
 void release(U p)override{need(p&&heap.release(p)==1,"1479 actualHeapFreeBOOL1");}
 std::uint8_t r8(U p)const override{return std::uint8_t(heap.r8(p));}
 void w8(U p,std::uint8_t v)override{heap.w8(p,v);}void w32(U p,U v)override{heap.w32(p,v);}
};}
std::uint32_t configure_crt(Memory&m,const Inputs&i){need(i.arg[0]==0,"1479 actualsetter0");m.w32(0x817554,0);return 1;}
std::uint32_t fun_004dda10(Memory&m,const Inputs&i,Heap&h){
 const U p=i.cx;need(m.r32(0x817554)==0&&m.r32(p)==0x78db34,"1479 producedCRT and parsedmanager");
 need(m.r32(p+0x24)==1&&m.r32(p+0x28)==10&&m.r8(p+0x2c)==0&&m.r32(p+0x30)==0,"1479 authentic cold rootindex");
 recovery_b251::Document d{};d.manager=p;d.selector_z=m.r32(i.dx);d.section_table=m.r32(p+0x20);d.section=m.r32(d.section_table+4);d.section_name=m.r32(d.section+0xc);d.key_table=m.r32(d.section+0x2c);d.node=m.r32(d.key_table+4);d.key=m.r32(d.node+0xc);d.value=m.r32(d.node+0x10);
 need(m.r32(d.section+0x30)==1&&m.r32(d.section+0x34)==10&&m.r8(d.section+0x38)==0&&m.r32(d.section+0x3c)==0,"1479 authentic cold keyindex");
 IntroHeap actual(m,h);return recovery_b251::build_intro_object(m,actual,d);
}}
