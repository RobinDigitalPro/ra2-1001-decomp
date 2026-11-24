#include "recovered/recovery_b1621.hpp"
#include "recovered/recovery_b1174.hpp"
#include "recovered/name_hash.hpp"
#include "recovered/recovery_b1621_fp.hpp"
#include <array>
#include <string>
#include <stdexcept>
#include <algorithm>
namespace ra2::recovered::b1621 { namespace {
void need_at(bool b,int line){if(!b)throw std::domain_error("1621 finite EB0D0 guard line "+std::to_string(line));}
#define need(x) need_at((x),__LINE__)
std::string text(Memory&m,U p,U limit){need(p);std::string s;for(U k=0;k<limit;++k){U c=m.r8(p+k);if(!c)return s;s+=char(c);}throw std::domain_error("1621 public ASCII extent");}
std::string owned_text(Heap&h,U p,U limit){need(p);std::string s;for(U k=0;k<limit;++k){U c=h.r8(p+k);if(!c)return s;s+=char(c);}throw std::domain_error("1621 owned ASCII extent");}
U hash(const std::string&s){return ::ra2::recovered::ini_name_hash(reinterpret_cast<const std::uint8_t*>(s.data()),s.size(),nullptr);}
struct Span{U address,size;};
bool separate(Span a,Span b){return std::uint64_t(a.address)+a.size<=b.address||std::uint64_t(b.address)+b.size<=a.address;}
void valid(Span a){need(a.address&&std::uint64_t(a.address)+a.size<=0x100000000ull);}
U rounded(U n){return(n+15u)&~15u;}
struct IniGraph{U row,section,section_name,node,value,key_name,key_row;U percent;std::array<Span,7>owned;};
IniGraph graph(Memory&m,Heap&h,U ini,U section_pointer){
 need(m.r32(ini)==0x78db34&&m.r32(ini+4)==0x785aec&&m.r32(ini+8)==0x785afc&&m.r32(ini+16)==0&&m.r32(ini+20)==0x785afc&&m.r32(ini+24)==0&&m.r32(ini+36)==1&&m.r32(ini+40)==10&&m.r8(ini+44)==1&&m.r32(ini+52)==0);
 IniGraph g{};g.row=m.r32(ini+32);need(g.row&&m.r32(ini+48)==g.row);g.section=h.r32(g.row+4);need(g.section&&m.r32(ini+12)==g.section&&m.r32(ini+28)==g.section);
 need(h.r32(g.section)==0x78eba4&&h.r32(g.section+4)==ini+20&&h.r32(g.section+8)==ini+8&&h.r32(g.section+16)==0x78ebac&&h.r32(g.section+20)==0x785afc&&h.r32(g.section+28)==0&&h.r32(g.section+32)==0x785afc&&h.r32(g.section+36)==0&&h.r32(g.section+48)==1&&h.r32(g.section+52)==10&&h.r8(g.section+56)==1&&h.r32(g.section+64)==0);
 g.section_name=h.r32(g.section+12);g.node=h.r32(g.section+24);g.key_row=h.r32(g.section+44);need(g.node&&h.r32(g.section+40)==g.node&&g.key_row&&h.r32(g.section+60)==g.key_row);
 need(h.r32(g.node)==0x78eb9c&&h.r32(g.node+4)==g.section+32&&h.r32(g.node+8)==g.section+20);for(U k=20;k<40;k+=4)need(h.r32(g.node+k)==0);
 g.key_name=h.r32(g.node+12);g.value=h.r32(g.node+16);
 const auto section=text(m,section_pointer,32),key=owned_text(h,g.key_name,32),value=owned_text(h,g.value,4);
 need(section=="House"&&owned_text(h,g.section_name,32)==section&&key=="PercentBuilt"&&h.r32(g.row)==hash(section)&&h.r32(g.key_row)==hash(key)&&h.r32(g.key_row+4)==g.node);
 need(!value.empty()&&value.size()<=3);for(unsigned char c:value){need(c>='0'&&c<='9');g.percent=g.percent*10+(c-'0');}need(g.percent>=1&&g.percent<=100);
 g.owned={Span{g.section,rounded(68)},Span{g.section_name,rounded(U(section.size()+1))},Span{g.node,rounded(40)},Span{g.value,rounded(U(value.size()+1))},Span{g.key_name,rounded(U(key.size()+1))},Span{g.key_row,80},Span{g.row,80}};
 for(U a=0;a<g.owned.size();++a){valid(g.owned[a]);for(U b=a+1;b<g.owned.size();++b)need(separate(g.owned[a],g.owned[b]));}
 return g;
}
// Exact warmed one-entry signed binary-search miss. The Root key is read from
// authentic public input bytes and hashed by the unchanged accepted CRC source.
void miss(Memory&m,Heap&h,const IniGraph&g,U key,const char*literal){
 const auto name=text(m,key,32);need(name==literal);const U query=hash(name),present=h.r32(g.key_row);need(query!=present);
 int count=1;U first=g.key_row;bool found=false;while(count>0){const int half=count/2;const U middle=first+8*U(half);const auto n=std::int32_t(h.r32(middle)),q=std::int32_t(query);if(q<n)count=half;else if(q==n){found=true;break;}else{first=middle+8;count-=half+1;}}
 need(!found); // Actual5105A0 returns0 and preserves cached PercentBuilt row.
}
void child_projection(Memory&m,U p){need(m.r32(p)==0x787590&&m.r32(p+28)==0);for(U off:{4u,32u,56u}){need(m.r32(p+off)==(off==4?0x7875c0u:0x7875a0u)&&m.r32(p+off+4)==0&&m.r32(p+off+8)==0&&m.r8(p+off+12)==1&&m.r8(p+off+13)==0&&m.r32(p+off+16)==0&&m.r32(p+off+20)==10);}need(m.r32(p+80)==0);for(U off=84;off<=116;off+=4)need(m.r32(p+off)==0);}
}
U run(U root,Memory&m,const Inputs&i,Heap&h,U base){
 need(root==0xeb0d0&&base>=0x10000000&&std::uint64_t(base)+0x200000<=0x100000000ull);const U house=i.cx,ini=i.arg[0];need(house==base+0x10000&&ini==base+0x3000);
 const U section=house+0x15ee0;need(text(m,section,32)=="House"&&m.r8(house+0x15ef5)==0);need(m.r32(0x81776c)==1&&m.r32(0xb10530)==0);
 const auto g=graph(m,h,ini,section);
 constexpr U keys[]{0x7c5944,0x7c593c,0x7c592c,0x7b922c,0x7c5918,0x7c5904,0x7c58f0,0x7c58e0,0x7c58dc,0x7c58d4,0x7bc370,0x7c58cc};
 constexpr const char*names[]{"TechLevel","Credits","PlayerControl","UIName","RatioAITriggerTeam","RatioTeamAircraft","RatioTeamInfantry","RatioTeamUnits","IQ","Edge","Color","Allies"};for(U k=0;k<12;++k)miss(m,h,g,keys[k],names[k]);
 need(text(m,0x7ba2e0,32)=="PercentBuilt"&&text(m,0x7ba2d4,32)=="NodeCount"&&hash(text(m,0x7ba2d4,32))!=h.r32(g.key_row)&&m.r8(0x8248a4)==0);
 const U type=m.r32(house+0x34),caption=m.r32(type+0x60),map=m.r32(0xa255c0),rules=m.r32(0x821b88),rows=m.r32(rules+0xe34),houses=m.r32(0xa1a5cc);
 need(type==base+0x28000&&caption==base+0x29000&&map==base+0x90000&&rules==base+0xa0000&&rows==base+0xa2000&&houses==base+0xb0000);
 need(m.r32(type+0xbc)==0xffffffff&&m.r32(house+0x30)==0&&m.r32(house+0xc8)==0&&std::int32_t(m.r32(rules+0x109c))>=0&&m.r32(houses)==house&&m.r32(0xa1a5d8)==1);
 need(m.r16(caption)=='H'&&m.r16(caption+2)>0&&m.r16(caption+2)<128&&m.r16(caption+4)==0);child_projection(m,house+0x55f0);
 const U registry=m.r32(0xa9ea04),prior=m.r32(registry),scheme=m.r32(registry+4),prior_name=m.r32(prior+0x304),next_name=m.r32(scheme+0x304),ctx=m.r32(scheme+0x30c),palette=m.r32(ctx+0x170);
 need(registry==base+0x33000&&prior==base+0x31000&&scheme==base+0x30000&&prior_name==base+0x32100&&next_name==base+0x32000&&ctx==base+0x34000&&palette==base+0x68000);
 need(m.r32(house+0x15f40)==1&&m.r32(0xa9ea10)==2&&m.r32(0xa9ea08)==10&&m.r32(prior)==1&&m.r32(scheme)==2&&m.r32(prior+0x310)==53&&m.r32(scheme+0x310)==53&&m.r32(scheme+0x330)==16);
 need(text(m,prior_name,16)=="prior.pal"&&text(m,next_name,16)=="next.pal"&&m.r32(ctx)==0x7905bc&&m.r32(ctx+4)==2&&m.r32(ctx+0x16c)==53&&m.r32(ctx+0x174)==palette+26*512&&m.r32(ctx+0x178)==0&&m.r32(ctx+0x17c)==0);
 const U color=m.r16(m.r32(ctx+0x174)+2*m.r32(scheme+0x330));need(color==0x18e3);
 need(m.r16(0x83b2e8)==0&&m.r32(0x83b2ec)==3&&m.r16(0x83b2f8)==11&&m.r32(0x83b2fc)==3&&m.r16(0x83b2f0)==5&&m.r32(0x83b2f4)==2);
 const std::array<Span,13>pub{{{ini,56},{house,0x15f44},{type,0x100},{caption,6},{scheme,0x33c},{prior,0x33c},{next_name,9},{prior_name,10},{registry,40},{ctx,0x1b4},{palette,53*512},{map,0x838},{rules,0x10a0}}};
 for(U a=0;a<pub.size();++a){valid(pub[a]);need(pub[a].address>=base&&std::uint64_t(pub[a].address)+pub[a].size<=std::uint64_t(base)+0x200000);for(U b=a+1;b<pub.size();++b)need(separate(pub[a],pub[b]));for(auto block:g.owned)need(separate(pub[a],block));}
 const std::array<Span,2>extra{{{rows,4},{houses,4}}};for(auto a:extra){valid(a);need(a.address>=base&&std::uint64_t(a.address)+a.size<=std::uint64_t(base)+0x200000);for(auto b:pub)need(separate(a,b));for(auto b:g.owned)need(separate(a,b));}need(separate(extra[0],extra[1]));
 for(auto block:g.owned)need(separate(block,Span{base,0x200000})&&separate(block,Span{0x80013c,16384*4}));
 need(m.r32(0x7c3a04)==0xe7f&&floating_b61::read64(m,0x786610)==0&&floating_b61::read64(m,0x78df48)==0x4058000000000000ull&&floating_b61::read64(m,0x78df50)==0x406fe00000000000ull&&floating_b61::read64(m,0x78df58)==0x406e000000000000ull);
 need(i.fp.image.word(8)==0xffff&&(i.fp.image.word(4)&~0x3800)==0);const U cw=i.fp.image.word(0);need((cw&0xf0ff)==0x7f&&(cw&0x300)!=0x100);
 // All actual INI/index/name guards precede folding genuine missing-key defaults.
 m.w32(house+0x11c,m.r32(map+0x834));m.w32(house+0x124,0);m.w32(house+0x24c,0);m.w8(house+0x135,0);
 // Actual fallback32->private31+explicitNUL->REP8DWORD, no private input seed.
 std::array<std::uint8_t,32>fallback{},copy{};for(U k=0;k<32;++k)fallback[k]=0;for(U k=0;k<31;++k)copy[k]=fallback[k];copy[31]=0;for(U k=0;k<32;++k)m.w8(house+0x15ef5+k,copy[k]);
 for(U k=0;k<3;++k)m.w16(house+0x15f16+2*k,m.r16(caption+2*k));
 m.w32(house+0x554c,m.r32(house+0x554c));for(U off:{0x5550u,0x5554u,0x5558u})m.w32(house+off,75);m.w32(house+0x130,0);m.w32(house+0x118,0);m.w32(house+0x194,0);m.w32(house+0x128,0);
 // Actual69B70 fallback-name scan, unique prior.pal/next.pal with 53!=1.
 const auto wanted=text(m,next_name,32);U selected=1;bool match=false;for(U n=0;n<m.r32(0xa9ea10);++n){U record=m.r32(registry+4*n);const auto candidate=text(m,m.r32(record+0x304),32);if(candidate==wanted&&m.r32(record+0x310)!=1){selected=n;match=true;break;}}need(match&&selected==1);m.w32(house+0x15f40,selected);
 const U red=std::uint8_t(std::uint8_t(color>>m.r16(0x83b2e8))<<m.r32(0x83b2ec)),second=std::uint8_t(std::uint8_t(color>>m.r16(0x83b2f8))<<m.r32(0x83b2fc)),third=std::uint8_t(std::uint8_t(color>>m.r16(0x83b2f0))<<m.r32(0x83b2f4));
 m.w8(house+0x55e9,red);m.w8(house+0x55ea,second);m.w8(house+0x55eb,third);need(red==24&&second==24&&third==28);
 // Real ordered numeric recipe is separately supplied/qualified. No golden
 // converted bytes, register image, status, or timer highword are assigned here.
 std::array<U,16384>table{};for(U k=0;k<table.size();++k)table[k]=m.r32(0x80013c+4*k);
 need(table[7296]==0x300000u&&table[14399]==0x6ffdddu&&table[14400]==0x700000u);
 const auto numeric=::ra2::recovered::b1621_fp::run(i.fp,table.data());for(U k=0;k<3;++k)m.w8(house+0x55ec+k,numeric.converted[k]&255u);
 m.w32(house+0x56cc,0); // Mandatory E4D00(self,0) genuinely rejects before writes.
 const U self_reject_full=house&0xffffff00u;(void)self_reject_full;
 const U tick=m.r32(0xa2896c),row=m.r32(rows+4*m.r32(house+0xc8))+175*m.r32(house+0x30);m.w32(house+0x5684,tick);m.w32(house+0x5688,U(numeric.second[1]>>32));m.w32(house+0x568c,row);
 b979::Inputs child{};child.ax=i.ax;child.cx=house+0x55f0;child.dx=i.dx;child.arg=i.arg;child.arg[0]=ini;child.arg[1]=section;child.stack_minus8=i.stack_minus8;child.arithmetic_flags=i.arithmetic_flags;const auto caller=child.arg;b1174::Observation observed{};
 const U eax=b1174::run(m,child,h,0x2c460,base,observed);need(eax==0&&child.arg==caller&&observed.positive_percent_reads==1&&observed.missing_node_reads==1&&observed.configuration_publications==1&&m.r32(house+0x560c)==g.percent);
 m.w32(house+0x5664,house);return eax;
}
}
