#include "recovered/recovery_b1619.hpp"
#include <algorithm>
#include <array>
#include <vector>
#include <stdexcept>
#include <cstdlib>
namespace ra2::recovered::recovery_b220 {std::uint32_t fun_00474d00(global_b26::Memory&,const floating_b61::Inputs&);}
namespace ra2::recovered::recovery_b612 {std::uint32_t fun_00474ab0(global_b26::Memory&,const floating_b61::Inputs&);}
namespace ra2::recovered::b1619 {namespace {
void need(bool v){if(!v)throw std::domain_error("1619 finite runtime-vector Wall cache/list domain");}
using Rect=std::array<int,4>;using Point=std::array<int,2>;
constexpr Point vectors[]{{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1}};
constexpr U indices[]{0,2,4,6,0xffffffffu};
int sx16(U v){return std::int16_t(v);}int sx8(U v){return std::int8_t(v);}U packed(Point p){return U(std::uint16_t(p[0]))|(U(std::uint16_t(p[1]))<<16);}
Point coordinate(Memory&m,U c){return {sx16(m.r16(c+0x24)),sx16(m.r16(c+0x26))};}
Point add_direction(Memory&m,Point p,U d){need(d<8);return {std::int16_t(p[0]+sx16(m.r16(0x839da0+4*d))),std::int16_t(p[1]+sx16(m.r16(0x839da2+4*d)))};}
U lookup(Memory&m,Point p){const int index=p[0]+512*p[1];need(index>=0&&U(index)<m.r32(0x81a95c));const U c=m.r32(m.r32(0x81a958)+4*U(index));need(c);return c;}
Rect read_rect(Memory&m,U p){return {int(m.r32(p)),int(m.r32(p+4)),int(m.r32(p+8)),int(m.r32(p+12))};}
Rect combine(Rect a,Rect b){if(a[2]<=0||a[3]<=0)return b;if(b[2]<=0||b[3]<=0)return a;int x=a[0],y=a[1],w=a[2],h=a[3];if(x>b[0]){w+=x-b[0];x=b[0];}if(y>b[1]){h+=y-b[1];y=b[1];}if(x+w<b[0]+b[2])w=b[0]-x+b[2]+1;if(y+h<b[1]+b[3])h=b[1]+b[3]-y+1;return{x,y,w,h};}
Rect intersection(Rect a,Rect b){const int x=std::max(a[0],b[0]),y=std::max(a[1],b[1]);return{x,y,std::max(0,std::min(a[0]+a[2],b[0]+b[2])-x),std::max(0,std::min(a[1]+a[3],b[1]+b[3])-y)};}
void fiadd(ra2::platform::x87::State&s,std::int32_t value){ra2::platform::x87::Image host;asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\tfiaddl %[value]\n\tfnsave %[guest]\n\tfrstor %[host]" :[host]"=m"(host.bytes),[guest]"+m"(s.image.bytes):[value]"m"(value):"memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");}
Rect tile_rect(Memory&m,const Inputs&i,U cell){need(m.r32(cell+0x38)==0xffff);auto p=coordinate(m,cell);const auto round=[](int v){return ((v*256+128)/256);};const int x=round(p[0]),y=round(p[1]);const U scene=m.r32(0x821cac);auto&s=i.fp;const std::int32_t z=0;s.load_integer32(U(z));s.multiply64(floating_b61::read64(m,0xaa5f90));fiadd(s,z);s.add64(floating_b61::read64(m,0x785728));if(s.image.word(0)!=m.r32(0x7c3a04))s.load_control(std::uint16_t(m.r32(0x7c3a04)));const int altitude=int(s.pop_integer64());return {30*(x-y)-int(m.r32(scene+0xb0))-30,15*(x+y)-int(m.r32(scene+0xb4))-altitude+int(m.r32(0x821974))-15*sx8(m.r8(cell+0x11b)),60,30};}
void append(Memory&m,U point){const U map=0x81a820,data=m.r32(map+0x1224);const int count=int(m.r32(map+0x1230));need(count>=0&&count<10);for(int n=count-1;n>=0;--n)if(m.r16(data+4*U(n))==std::uint16_t(point)&&m.r16(data+4*U(n)+2)==(point>>16))return;need(U(count)<m.r32(map+0x1228));m.w32(map+0x1230,U(count+1));m.w32(data+4*U(count),point);m.w8(map+0x14d5,1);}
U classify(Memory&m,U cell){Point p=coordinate(m,cell);int index=p[0]+int(m.r32(0x81a910)+m.r32(0x81a914)+1)*p[1];index=std::max(0,std::min(index,int(m.r32(0x81a888))-1));U a=m.r32(0x81a884)+4*U(index),b=m.r32(0x81a88c)+10*U(index);const U t=m.r32(m.r32(0xa1e11c)+4*m.r32(cell+0x44));m.w32(cell+0xec,m.r32(t+0x268));need(m.r32(t+0x268)==0&&m.r8(t+0x27c)==0);if(std::int32_t(m.r32(cell+0x38))>=std::int32_t(m.r32(0xa28920)))m.w32(cell+0x38,0xffff);need(m.r32(cell+0x38)==0xffff);m.w32(cell+0xec,m.r32(t+0x268));m.w8(cell+0x11c,0);need(m.r8(m.r32(0x821b88)+0x584)==0);const int w=int(m.r32(0x81a910)),bx=int(m.r32(0x81a918)),by=int(m.r32(0x81a91c)),bw=int(m.r32(0x81a920)),bh=int(m.r32(0x81a924));need(p[0]+p[1]>w+2*by&&p[0]+p[1]<=w+2*(by+bh)+2&&p[0]-p[1]<2*(bx+bw)-w&&p[1]-p[0]<w-2*bx);need(!m.r8(t+0x1fd)&&m.r8(t+0x278));m.w32(cell+0x4c,2);m.w8(a+1,m.r8(cell+0x11b));m.w8(a,m.r8(cell+0x4c));m.w8(b+8,m.r8(cell+0x11b));return b;}
}
U run(U root,Memory&m,const Inputs&i,Heap&heap){(void)heap;need(root==0x75560&&i.arg[0]==0);const U center=i.cx;need(coordinate(m,center)==Point{7,7});
 const U table=m.r32(0x81a958),registry=m.r32(0xa1e11c),type=m.r32(registry+20),shp=m.r32(type+0xa4),scene=m.r32(0x821cac),rules=m.r32(0x821b88),cache4=m.r32(0x81a884),cache10=m.r32(0x81a88c),list=m.r32(0x81a820+0x1224),dirty=m.r32(0xaa60bc);
 need(m.r32(0x81a95c)==8192&&m.r32(type)==0x7929c8&&m.r32(0x792a64)==0x5d57d0&&m.r32(type+0x264)==5&&m.r32(type+0x268)==0&&m.r32(type+0x270)==3&&m.r32(type+0x274)==100&&m.r8(type+0xa8)==1&&m.r8(type+0x278)==1);for(U k:{0x279u,0x27au,0x27cu,0x27fu,0x284u,0x1fdu})need(m.r8(type+k)==0);
 need(m.r16(shp+2)==16&&m.r16(shp+4)==14&&m.r16(shp+6)==48);for(U f=0;f<48;++f)if(f<16||(f>=24&&f<40)){U p=shp+8+24*f;need(m.r16(p)==U(f<16)&&m.r16(p+2)==U(f<16)&&m.r16(p+4)==12&&m.r16(p+6)==10);}
 need(m.r32(0x81a910)==7&&m.r32(0x81a914)==11&&m.r32(0x81a888)==361&&m.r32(0x81a918)==0&&m.r32(0x81a91c)==0&&m.r32(0x81a920)==7&&m.r32(0x81a924)==11&&m.r32(scene+0xb0)==0&&m.r32(scene+0xb4)==0&&m.r8(rules+0x584)==0);need(m.r32(0x821970)==0&&m.r32(0x821974)==0&&m.r32(0xaa6070)==640&&m.r32(0xaa6074)==480&&m.r32(0xaa5f90)==0&&m.r32(0xaa5f94)==0&&m.r32(0x785728)==0&&m.r32(0x78572c)==0x3fe00000&&m.r32(0x7c3a04)==0xe7f);
 for(U k=0;k<8;++k)need(sx16(m.r16(0x839da0+4*k))==vectors[k][0]&&sx16(m.r16(0x839da2+4*k))==vectors[k][1]);for(U k=0;k<5;++k)need(m.r32(0x7bdaf0+4*k)==indices[k]);need(m.r32(0x81a820+0x1228)==10&&m.r32(0x81a820+0x1230)==0&&m.r8(0x81a820+0x14d5)==0&&m.r32(0xaa60c8)==1&&m.r32(0xaa60c0)==1&&m.r8(dirty+16)==0);need(read_rect(m,dirty)==Rect{-128,128,256,256});
 std::vector<std::array<U,2>> spans{{type,0x288},{shp,1160},{scene,0xb8},{rules,0x585},{registry,24},{table,32768},{cache4,1444},{cache10,3610},{list,40},{dirty,20}};
 for(int x=5;x<=9;++x)for(int y=5;y<=9;++y)if(std::abs(x-7)+std::abs(y-7)<=2){U c=lookup(m,{x,y});need(coordinate(m,c)==Point{x,y}&&m.r32(c)==0x788b04&&m.r32(c+0x44)==5&&m.r32(c+0x38)==0xffff&&m.r32(c+0x4c)==2&&m.r32(c+0xec)==0&&m.r32(c+0xe4)==0&&m.r8(c+0x11b)==0&&m.r8(c+0x11c)==0&&m.r8(c+0x11e)==0&&(m.r8(c+0x140)&0x80)==0);spans.push_back({c,0x144});}need(lookup(m,{7,7})==center);
 constexpr U globals[]{0x785000,0x792000,0x7bd000,0x7c3000,0x804000,0x81a000,0x81b000,0x821000,0x839000,0xa1e000,0xa28000,0xaa5000,0xaa6000};for(U a=0;a<spans.size();++a){const auto p=spans[a][0];const std::uint64_t end=std::uint64_t(p)+spans[a][1];need(p&&end<=0x100000000ull);need(end<=0x7d000000ull||p>=0x7d008000);need(end<=0x7d020000ull||p>=0x7d021000);for(U g:globals)need(end<=g||p>=g+4096);for(U b=a+1;b<spans.size();++b)need(end<=spans[b][0]||std::uint64_t(spans[b][0])+spans[b][1]<=p);}
 need(i.fp.image.word(8)==0xffff&&(i.fp.image.word(4)&~0x3800)==0);constexpr std::uint16_t cw[]{0x37f,0x77f,0xb7f,0xf7f,0x27f,0x67f,0xa7f,0xe7f,0x7f,0x47f,0x87f,0xc7f};bool valid=false;for(auto c:cw)valid|=i.fp.image.word(0)==c;need(valid);
 std::array<std::uint8_t,4096> local{};leaf::Memory scratch(local.data(),0x7d020000,4096);Memory work=m;work.add(scratch);U eax=0;
 auto rectangle=[&](U cell,U out,bool bounding){Inputs child=i;child.cx=cell;child.arg[0]=out;const U result=bounding?recovery_b220::fun_00474d00(work,child):recovery_b612::fun_00474ab0(work,child);need(result==out);i.fp=child.fp;return read_rect(work,out);};
 for(U n=0;n<5;++n){U d=m.r32(0x7bdaf0+4*n);U cell=d<8?lookup(m,add_direction(m,coordinate(m,center),d)):center;Rect first=rectangle(cell,0x7d020000,false),bound=rectangle(cell,0x7d020020,true);need(first[2]>0&&first[3]>0&&bound[2]>0&&bound[3]>0&&first[0]>bound[0]&&first[1]>bound[1]);const Point produced_private{bound[0],bound[1]};(void)produced_private;
  bound=rectangle(cell,0x7d020040,true);first=rectangle(cell,0x7d020060,false);Rect incoming=combine(combine(tile_rect(m,i,cell),first),bound);incoming[0]-=int(m.r32(0x821970));incoming[1]-=int(m.r32(0x821974));need(intersection(read_rect(m,dirty),incoming)==incoming);const U flag=0;need(!flag);append(m,m.r32(cell+0x24));
  U mask=0;for(U bit=0;bit<4;++bit){const U neighbor=lookup(m,add_direction(m,coordinate(m,cell),m.r32(0x7bdaf0+4*bit)));const U actual_type=m.r32(neighbor+0x44),expected_type=m.r32(cell+0x44);need(actual_type==expected_type&&actual_type!=0xffffffff);const U full_match=(actual_type&0xffffff00u)|1u;if(full_match&255)mask|=1u<<bit;}
  const U old_class=m.r32(cell+0x4c);m.w8(cell+0x11e,(m.r8(cell+0x11e)&0xf0)|mask);need(m.r32(cell+0x44)==5);(void)classify(m,cell);eax=m.r32(cell+0x4c);need(eax==old_class); // Actual4758A7 excludes all late map work.
 }
 return eax;
}}
