#include "recovered/recovery_b1133.hpp"
#include <algorithm>
#include <stdexcept>
namespace ra2::recovered::b1133 {
static void need(bool x){if(!x)throw std::domain_error("1133 original map7x11/playable2,2,3,3 positive graph");}
static std::uint64_t read64(Memory&m,unsigned a){return m.r32(a)|(std::uint64_t(m.r32(a+4u))<<32u);}
static unsigned draw(Memory&m){constexpr unsigned r=0xa581d8u;need(m.r8(r)==0u);const auto i=m.r32(r+4u),j=m.r32(r+8u);need(i<250u&&j<250u);const auto v=m.r32(r+12u+4u*i)^m.r32(r+12u+4u*j);m.w32(r+12u+4u*i,v);m.w32(r+4u,i==249u?0u:i+1u);m.w32(r+8u,j==249u?0u:j+1u);return v;}
static void unsigned_load(State&f,unsigned x){const std::uint64_t v=x;ra2::platform::x87::Image host;asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\tfildq %[v]\n\tfnsave %[guest]\n\tfrstor %[host]":[host]"=m"(host.bytes),[guest]"+m"(f.image.bytes):[v]"m"(v):"memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");}
struct Map {
 Memory&m;unsigned table,aux;
 unsigned cell(unsigned p)const{return m.r32(table+4u*((p&65535u)+512u*(p>>16u)));}
 unsigned slot(unsigned p)const{return aux+80u*((p&65535u)+19u*(p>>16u));}
 void begin(){m.w32(0x81a928u,1u);m.w32(0x81a92cu,7u);m.w32(0x81a930u,6u);m.w32(0x81a934u,table+4u*(1u+512u*7u));}
 unsigned next(){auto x=m.r32(0x81a928u),y=m.r32(0x81a92cu),left=m.r32(0x81a930u),p=m.r32(0x81a934u);const auto value=m.r32(p);if(left){++x;--y;--left;p-=2044u;}else{std::swap(x,y);unsigned width=7u;if((x-width+y-1u)&1u){++y;--width;}else{++x;width-=2u;}left=width;p=table+4u*(x+512u*y);}m.w32(0x81a928u,x);m.w32(0x81a92cu,y);m.w32(0x81a930u,left);m.w32(0x81a934u,p);return value;}
 unsigned adjacent(unsigned p,unsigned d)const{const auto delta=m.r32(0x839da0u+4u*d);return unsigned(std::uint16_t(std::uint16_t(p)+std::uint16_t(delta)))|(unsigned(std::uint16_t(std::uint16_t(p>>16u)+std::uint16_t(delta>>16u)))<<16u);}
};

unsigned run(unsigned root,Memory&m,const Inputs&i,Heap&heap,State&f){
 need(root==0x179d20u&&f.image.word(0)==0xe7fu&&f.image.word(4)==0u&&f.image.word(8)==0xffffu);
 need(m.r32(0x817554u)==0u&&m.r32(0xb10e14u)==0u&&m.r32(0xa3a898u)==256u&&m.r32(0xa3a1c8u)==320u);
 (void)i;Map map{m,m.r32(0x81a958u),m.r32(0xa5863cu)};
 unsigned data=0u,count=0u,capacity=0u;
 const auto append=[&](unsigned p){if(count>=capacity){need(capacity==0u&&data==0u);data=heap.allocate(40000u);need(data!=0u);capacity=10000u;}heap.w32(data+4u*count++,p);};
 const auto adjacent_free=[&](unsigned p){const auto type=m.r32(p+0x38u);return type==0xffffu||type==0u;};
 map.begin();unsigned scanned=0u;for(auto p=map.next();p;p=map.next()){
  need(++scanned<=143u);const auto type=m.r32(p+0x38u),start=m.r32(0xa3a1c8u);
  if(type!=m.r32(0xa3a898u)&&(type<start||type>=start+16u))continue;
  for(unsigned d=0;d<8u;d+=2u){const auto q=map.adjacent(m.r32(p+0x24u),d),target=map.cell(q);need(target!=0u);if(adjacent_free(target))append(target);}
 }
 need(scanned==143u&&count==3u&&capacity==10000u);
 unsigned iterations=std::min(count/3u,1000u);need(iterations==1u);
 do{
  f.load_integer32(count);const auto extent=f.pop64();unsigned chosen;
  do{unsigned_load(f,draw(m));f.multiply64(extent);f.multiply64(read64(m,0x790db0u));chosen=unsigned(f.pop_integer64());}while(chosen>count-1u);
  const auto target=heap.r32(data+4u*chosen);--count;for(unsigned k=chosen;k<count;++k)heap.w32(data+4u*k,heap.r32(data+4u*(k+1u)));
  m.w32(target+0x38u,m.r32(0xa3a898u));
  for(unsigned d=0;d<8u;d+=2u){const auto q=map.adjacent(m.r32(target+0x24u),d),p=map.cell(q);need(p!=0u);if(adjacent_free(p))append(p);}
 }while(--iterations);
 need(count==2u);return heap.release(data);
}
}
