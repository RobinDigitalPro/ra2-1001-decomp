#include "recovered/recovery_b1124.hpp"
#include <stdexcept>
namespace ra2::recovered::b1124 {
static void need(bool v){if(!v)throw std::domain_error("1124 bounded original two-cell region graph");}
static std::uint64_t read64(Memory&m,unsigned a){return std::uint64_t(m.r32(a))|(std::uint64_t(m.r32(a+4u))<<32u);}
static unsigned draw(Memory&m){constexpr unsigned r=0xa581d8u;need(m.r8(r)==0u);const auto i=m.r32(r+4u),j=m.r32(r+8u);need(i<250u&&j<250u);const auto v=m.r32(r+12u+4u*i)^m.r32(r+12u+4u*j);m.w32(r+12u+4u*i,v);m.w32(r+4u,i==249u?0u:i+1u);m.w32(r+8u,j==249u?0u:j+1u);return v;}
static void unsigned_load(State&f,unsigned x){const std::uint64_t v=x;ra2::platform::x87::Image host;asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\tfildq %[v]\n\tfnsave %[guest]\n\tfrstor %[host]":[host]"=m"(host.bytes),[guest]"+m"(f.image.bytes):[v]"m"(v):"memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");}
// Positive exponent0/index0 branch of original4BA080. The full table is
// pinned separately. Preserve each load/compare/store and physical x87 slot.
static void distance_one(Memory&m,State&f,unsigned squared){need(squared==1u&&m.r32(0x80013cu)==0u&&m.r32(0x785738u)==0u);f.load_integer32(squared);const auto argument=f.pop64();f.load64(argument);f.compare32(0u);f.compare32(0u);need(f.pop32()==0x3f800000u);f.load32(0x3f800000u+m.r32(0x80013cu));}
struct Map {
 Memory&m;unsigned table,aux;
 unsigned cell(unsigned p)const{return m.r32(table+4u*((p&65535u)+512u*(p>>16u)));}
 unsigned slot(unsigned p)const{return aux+80u*((p&65535u)+7u*(p>>16u));}
 bool inside(unsigned p)const{const int x=std::int16_t(p),y=std::int16_t(p>>16u),lo=int(m.r32(0xa58634u));return x+y>lo&&x-y<lo&&y-x<lo&&x+y<=int(m.r32(0xa58638u));}
 unsigned next(unsigned p,unsigned d)const{const auto o=m.r32(0x839da0u+4u*(d&7u));return unsigned(std::uint16_t(p)+std::uint16_t(o))%65536u|(unsigned(std::uint16_t(p>>16u)+std::uint16_t(o>>16u))%65536u<<16u);}
 // Original557340/557280 iterator numeric fields and terminal NULL lookup.
 void clear(){unsigned x=1u,y=m.r32(0x81a910u),remaining=y-1u,p=table+4u*(1u+512u*y);m.w32(0x81a928u,x);m.w32(0x81a92cu,y);m.w32(0x81a930u,remaining);m.w32(0x81a934u,p);for(unsigned limit=0;limit<16u;++limit){const auto old=p;const auto value=m.r32(old);if(remaining){++x;--y;--remaining;p-=2044u;}else{const auto priorx=x;x=y;y=priorx;int n=int(m.r32(0x81a910u));if(((x-unsigned(n)+y-1u)&1u)!=0u){++y;--n;}else{++x;n-=2;}remaining=unsigned(n);p=table+4u*(x+512u*y);}m.w32(0x81a928u,x);m.w32(0x81a92cu,y);m.w32(0x81a930u,remaining);m.w32(0x81a934u,p);if(!value){need(limit==15u);return;}m.w32(slot(m.r32(value+0x24u))+0x3cu,0u);}need(false);}
};
struct Queue {
 Heap&h;unsigned p,array;
 void push(unsigned node){const auto count=h.r32(p),index=count+1u;need(count==0u&&index<h.r32(p+4u));h.w32(array+4u*index,node);h.w32(p,index);if(node>h.r32(p+12u))h.w32(p+12u,node);if(node<h.r32(p+16u))h.w32(p+16u,node);}
 unsigned pop(){const auto count=h.r32(p);if(!count)return 0u;need(count==1u);const auto node=h.r32(array+4u),last=h.r32(array+4u*count);h.w32(array+4u,last);h.w32(array+4u*count,0u);h.w32(p,count-1u);return node;}
};
unsigned run(unsigned root,Memory&m,const Inputs&i,Heap&h,State&f){need(root==0x180590u||root==0x183140u);need(f.image.word(0)==0xe7fu&&f.image.word(4)==0u&&f.image.word(8)==0xffffu&&m.r32(0x817554u)==0u&&m.r32(0xb10e14u)==0u);Map map{m,m.r32(0x81a958u),m.r32(0xa5863cu)};need(m.r32(0x81a910u)==3u&&m.r32(0x81a914u)==3u&&m.r32(0x836b4cu)==7u&&m.r32(0xa58634u)==3u&&m.r32(0xa58638u)==9u);
 constexpr unsigned coordinates[]{0x30001u,0x20002u,0x10003u,0x30002u,0x20003u,0x40002u,0x30003u,0x20004u,0x40003u,0x30004u,0x50003u,0x40004u,0x30005u,0x50004u,0x40005u};constexpr unsigned directions[]{0xffff0000u,0xffff0001u,1u,0x10001u,0x10000u,0x1ffffu,0xffffu,0xffffffffu};for(unsigned j=0;j<8u;++j)need(m.r32(0x839da0u+4u*j)==directions[j]);for(unsigned j=0;j<15u;++j){const auto p=map.cell(coordinates[j]);need(p&&m.r32(p+0x24u)==coordinates[j]&&m.r32(p)==0x788b04u&&m.r32(p+0x38u)==(j==4u||j==6u?0xffffu:256u)&&m.r32(p+0x44u)==0xffffffffu&&m.r32(p+0xe4u)==0u&&m.r8(p+0x11cu)==0u&&m.r32(map.slot(coordinates[j])+0x3cu)==0u&&m.r8(map.slot(coordinates[j])+0x45u)==0u);}
 const unsigned regions=root==0x180590u?m.r32(i.cx+0x50u):1u;need(regions==(root==0x180590u?2u:1u));unsigned released=0u;
 for(unsigned region=0u;region<regions;++region){const unsigned seed=root==0x180590u?m.r32(m.r32(0xa255c0u)+0x632u+4u*region):m.r32(i.arg[0]+0x24u),count=root==0x180590u?400u:i.arg[2],marker=root==0x180590u?region+1u:i.arg[3],capacity=root==0x180590u?800u:i.arg[2]*10u;need(seed==(region==0u?0x30003u:0x20003u));if(root==0x183140u)need(i.arg[0]==map.cell(seed)&&i.arg[1]==m.r32(0xa55d20u)&&i.arg[1]==256u&&count==4u&&marker==1539u&&(i.arg[4]&255u)==0u);
 const auto nodes=h.allocate(8u*capacity),header=h.allocate(20u);need(nodes&&header);h.w32(header,0u);h.w32(header+4u,capacity);h.w32(header+12u,0u);h.w32(header+16u,0xffffffffu);const auto array=h.allocate(4u*(capacity+1u));need(array);h.w32(header+8u,array);for(unsigned j=0;j<=capacity;++j)h.w32(array+4u*j,0u);Queue q{h,header,array};if(root==0x180590u)map.clear();h.w32(nodes,seed);h.w32(nodes+4u,0u);m.w32(map.slot(seed)+0x3cu,marker);q.push(nodes);unsigned used=1u,done=0u;
 for(auto current=q.pop();current&&done<count;current=q.pop()){const auto coordinate=h.r32(current),cell=map.cell(coordinate);if(root==0x180590u)m.w8(map.slot(coordinate)+0x45u,1u);else m.w32(cell+0x38u,i.arg[1]);for(unsigned direction=0;direction<8u;++direction){const auto neighbor=map.next(coordinate,direction);if(!map.inside(neighbor))continue;const auto target=map.cell(neighbor);need(target);if(m.r32(map.slot(neighbor)+0x3cu)==marker)continue;const auto type=m.r32(target+0x38u);if(type!=0xffffu&&type!=0u)continue;if(root==0x183140u&&(m.r8(target+0x11cu)||m.r32(target+0x44u)!=0xffffffffu||m.r32(target+0xe4u)))continue;need(used==1u&&neighbor==(seed==0x30003u?0x20003u:0x30003u));const auto node=nodes+8u*used;h.w32(node,neighbor);const int dx=std::int16_t(seed)-std::int16_t(neighbor),dy=std::int16_t(seed>>16u)-std::int16_t(neighbor>>16u);distance_one(m,f,unsigned(dx*dx+dy*dy));unsigned score;if(root==0x180590u)score=f.pop32();else{const auto distance=f.pop64();unsigned_load(f,draw(m));f.multiply64(read64(m,0x790d20u));f.multiply64(read64(m,0x790db0u));f.add64(distance);score=f.pop32();}h.w32(node+4u,score);m.w32(map.slot(neighbor)+0x3cu,marker);++used;q.push(node);}++done;}
 need(done==2u&&used==2u&&h.r32(header)==0u);h.release(nodes);h.release(array);released=h.release(header);}
 return root==0x180590u?(i.cx&0xffffff00u)|1u:released;
}
}
