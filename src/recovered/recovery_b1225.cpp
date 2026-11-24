#include "recovered/recovery_b1225.hpp"
#include "recovered/name_hash.hpp"
#include <string>
#include <vector>
#include <utility>
#include <stdexcept>
#include <cstdint>
namespace ra2::recovered::b1225{namespace{
void need(bool b){if(!b)throw std::domain_error("1225 bounded genuine derived INI contract");}
struct Raw{Heap&h;std::string text(unsigned p){std::string s;for(unsigned j=0;j<128;++j){auto x=h.r8(p+j);if(!x)return s;s+=char(x);}throw std::domain_error("1225 finite original owned text");}};
// Arena pointers are handled separately from actual owned parser allocations.
struct Queries{Memory&m;Heap&h;unsigned self,ini;Raw raw;Queries(Memory&a,Heap&b,unsigned s,unsigned i):m(a),h(b),self(s),ini(i),raw{b}{}
 unsigned hash(const std::string&s){return ini_name_hash(reinterpret_cast<const unsigned char*>(s.data()),s.size(),nullptr);}
 unsigned section(unsigned i,const std::string&s){need(m.r32(i)==0x78db34u&&m.r32(i+36u)==1u&&m.r8(i+44u));auto t=m.r32(i+32u);need(h.r32(t)==hash(s));m.w32(i+48u,t);return h.r32(t+4u);}
 unsigned value(unsigned i,const std::string&s,const std::string&k){const auto sec=section(i,s),t=h.r32(sec+44u),n=h.r32(sec+48u),q=hash(k);need(h.r8(sec+56u)&&n>0u&&n<=20u);unsigned first=0u,count=n;while(count){unsigned half=count/2u,j=first+half;auto v=h.r32(t+8u*j);if(std::int32_t(q)<std::int32_t(v))count=half;else if(q==v){h.w32(sec+60u,t+8u*j);return h.r32(t+8u*j+4u);}else{first=j+1;count-=half+1;}}return 0u;}
 std::string read(unsigned i,const std::string&s,const std::string&k,const std::string&fallback){auto v=value(i,s,k);return v?raw.text(h.r32(v+16u)):fallback;}
 std::string own(unsigned p,unsigned cap=128u){std::string s;for(unsigned j=0;j<cap;++j){unsigned x=m.r8(p+j);if(!x)return s;s+=char(x);}throw std::domain_error("1225 bounded arena string");}
 std::string key(unsigned p){return own(p);}
 void copy(unsigned p,unsigned n,const std::string&s){need(s.size()<n);for(unsigned j=0;j<n;++j)m.w8(p+j,j<s.size()?static_cast<unsigned char>(s[j]):0u);}
 std::string get(unsigned k,const std::string&d=""){return read(ini,own(self+36u),key(k),d);}
 unsigned integer(unsigned k,unsigned fallback){auto s=get(k);if(s.empty())return fallback;unsigned v=0;for(auto x:s){need(x>='0'&&x<='9');v=v*10u+unsigned(x-'0');}need(v<100000u);return v;}
 unsigned boolean(unsigned k,unsigned fallback){auto s=get(k);if(s.empty())return fallback;char c=s[0];if(c>='a'&&c<='z')c-=32;need(c=='0'||c=='1'||c=='Y'||c=='N'||c=='T'||c=='F');return c=='1'||c=='Y'||c=='T';}
 unsigned artbool(unsigned k,unsigned fallback){auto s=read(0x821b30u,own(self+0x1c8u),key(k),"");if(s.empty())return fallback;need(s=="1"||s=="0");return s=="1";}
 void color(unsigned off,unsigned k,bool art=false){const unsigned recv=art?0x821b30u:ini;const auto sect=own(self+(art?0x1c8u:36u));std::string def=std::to_string(m.r8(self+off))+","+std::to_string(m.r8(self+off+1))+","+std::to_string(m.r8(self+off+2));auto s=read(recv,sect,key(k),def);unsigned pos=0;for(unsigned j=0;j<3;++j){unsigned v=0,n=0;while(pos<s.size()&&s[pos]>='0'&&s[pos]<='9'){v=v*10+unsigned(s[pos++]-'0');++n;}need(n&&v<256);m.w8(self+off+j,v);if(j<2){need(pos<s.size()&&s[pos]==',');++pos;}}need(pos==s.size());}
 void ib(unsigned o,unsigned k){m.w32(self+o,integer(k,m.r32(self+o)));}void bb(unsigned o,unsigned k){m.w8(self+o,boolean(k,m.r8(self+o)));}
 void absent(unsigned k){need(get(k).empty());}
 std::uint64_t u64(unsigned p){return std::uint64_t(m.r32(p))|(std::uint64_t(m.r32(p+4))<<32);}
 void write64(unsigned p,std::uint64_t v){m.w32(p,unsigned(v));m.w32(p+4,unsigned(v>>32));}
 void real(unsigned off,unsigned k,State&s,bool f32=false){absent(k);if(f32){s.load32(m.r32(self+off));auto d=s.pop64();s.load64(d);m.w32(self+off,s.pop32());}else{s.load64(u64(self+off));write64(self+off,s.pop64());}}
 void base(){const auto sec=own(self+36u);copy(self+100u,49u,read(ini,sec,"Name",own(self+100u,49u)));copy(self+61u,32u,read(ini,sec,"UIName",own(self+61u,32u)));const auto label=m.r32(0xab7ec0u);need(m.r32(0xab7eb8u)==1u&&own(label,32u)==own(self+61u,32u)&&m.r32(label+32u)==1u&&m.r32(label+36u)==0u);m.w32(self+96u,m.r32(m.r32(0xab7ec4u)));
  copy(self+0x1c8u,25u,get(0x7bad74u,own(self+0x1c8u,25u)));copy(self+0x1e3u,25u,get(0x7d2390u,own(self+0x1e3u,25u)));absent(0x7d2384u);absent(0x7d2374u);
  for(auto x:std::vector<std::pair<unsigned,unsigned>>{{0x1fd,0x7d2368},{0x1fe,0x7d235c},{0x1b8,0x7d2350},{0x1e1,0x7d233c},{0x1ff,0x7d232c},{0x200,0x7d2320},{0x201,0x7d2314}})bb(x.first,x.second);
  // Original46A4D0: absent Armor preserves the genuine constructor index0.
  need(get(0x7be958u).empty());ib(0xa0u,0x7d2308u);for(auto x:std::vector<std::pair<unsigned,unsigned>>{{0x203,0x7d2300},{0x202,0x7d22f0},{0x208,0x7d22dc}})bb(x.first,x.second);color(0x98,0x7d22d0);bb(0x209,0x7d22bc);
  m.w8(self+0x20a,artbool(0x7d22ac,m.r8(self+0x20a)));color(0x20b,0x7d229c,true);need(read(0x821b30u,own(self+0x1c8u),key(0x7d2284u),"").empty());for(auto x:std::vector<std::pair<unsigned,unsigned>>{{0x1fc,0x7b9f94},{0x207,0x7b9f88},{0x206,0x7d227c}})m.w8(self+x.first,artbool(x.second,m.r8(self+x.first)));need(m.r8(self+0x206)==1u&&m.r8(self+0x1e3)==0u);
 }
 unsigned registry(unsigned array,unsigned count,const std::string&s){need(m.r32(count)==2u);const auto a=m.r32(array);for(unsigned j=0;j<2;++j){auto p=m.r32(a+4*j);if(own(p+36u)==s)return j;}throw std::domain_error("1225 actual type registry hit");}
};}
unsigned run(unsigned root,Memory&m,const Inputs&i,Heap&h,State&s){need(root==0x2183c0u||root==0x303030u);Queries q(m,h,i.cx,i.arg[0]);const auto self=i.cx;q.base();if(root==0x2183c0u){m.w32(self+0x264,q.registry(0xa1e134u,0xa1e140u,q.get(0x7d61b0u)));q.bb(0x268,0x7b9e00);q.ib(0x26c,0x7d61a4);q.ib(0x274,0x7d6198);q.ib(0x278,0x7d618c);q.real(0x270,0x7d6180,s,true);q.real(0x27c,0x7d6174,s,true);q.real(0x280,0x7d615c,s,true);q.ib(0x288,0x7d6150);const auto behavior=q.get(0x7d6144);unsigned which=0xffffffffu;for(unsigned j=0;j<5;++j)if(q.own(m.r32(0x7d5fe4u+4*j))==behavior)which=j;need(which<5);m.w32(self+0x284,which);q.absent(0x7d6134);for(auto x:std::vector<std::pair<unsigned,unsigned>>{{0x298,0x7d6120},{0x2a0,0x7d610c},{0x2a8,0x7d60fc},{0x2b0,0x7d60dc},{0x2b8,0x7d60bc},{0x2c0,0x7d609c}})q.real(x.first,x.second,s);q.bb(0x2db,0x7d6094);q.color(0x2d8,0x7d6088);q.ib(0x2d0,0x7d6074);q.ib(0x2d4,0x7d6068);q.bb(0x2dc,0x7d6058);q.real(0x2c8,0x7d6040,s);return 1u;}
 q.bb(0x264,0x7b9f58);q.bb(0x265,0x7b9f4c);q.bb(0x2d0,0x7b9e60);q.bb(0x2a0,0x7b9de8);q.real(0x270,0x7b9e1c,s);for(unsigned k:{0x7e2d3cu,0x7e2d28u}){q.absent(k);s.load64(0xbff0000000000000ull);s.compare32(0u);s.multiply64(q.u64(0x799570u));q.write64(self+(k==0x7e2d3cu?0x278u:0x280u),s.pop64());}q.ib(0x26c,0x7e2d1c);q.real(0x288,0x7b9e08,s);q.real(0x290,0x7e2d14,s);q.real(0x298,0x7b9e10,s);q.absent(0x7b9e00);q.ib(0x2a8,0x7b9df4);need(q.boolean(0x7e2d04,0)==1u&&q.boolean(0x7e2cf4,0)==0u&&q.boolean(0x7e2ce4,0)==0u);q.ib(0x268,0x7e2cd8);for(unsigned k:{0x7b9d50u,0x7b9d3cu,0x7b9d30u,0x7b9d24u,0x7b9d18u})q.absent(k);q.ib(0x2c0,0x7b9ee4);q.ib(0x2c4,0x7b9cf4);q.absent(0x7b9cec);q.absent(0x7e2cc8);m.w8(self+0x266,1u);const auto source=q.registry(0xa27fa4u,0xa27fb0u,q.get(0x7e2cbcu));const auto p=m.r32(m.r32(0xa27fa4u)+4*source);m.w32(self+0xb0,m.r32(p+0xb0));m.w32(self+0xb4,m.r32(p+0xb4));return(p&0xffffff00u)|1u;}
}
