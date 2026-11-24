#include "recovery_b337.hpp"
#include "platform/small_crt_heap_b337.hpp"
#include "recovered/name_hash.hpp"

#include <algorithm>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

namespace ra2::recovered::recovery_b337 {
namespace {
void need(bool ok,const char*why){if(!ok)throw std::domain_error(why);}
std::int32_t s32(std::uint32_t x){return (x&0x80000000u)?static_cast<std::int32_t>(std::int64_t(x)-0x100000000ll):static_cast<std::int32_t>(x);}
std::int16_t s16(std::uint16_t x){return (x&0x8000u)?static_cast<std::int16_t>(std::int32_t(x)-0x10000):static_cast<std::int16_t>(x);}
std::string read_z(const Memory&m,std::uint32_t p){
 need(p!=0,"337 non-null string precondition");std::string out;
 for(unsigned n=0;n<64;++n){const auto c=m.r8(p+n);if(!c)return out;out.push_back(static_cast<char>(c));}
 throw std::domain_error("337 bounded NUL-terminated string");
}
std::string signed_digit(std::int32_t x){
 need(x>=-9&&x<=9,"337 row integer stays one visible digit");
 if(x<0)return std::string("-")+char('0'-x);return std::string(1,char('0'+x));
}
std::uint32_t hash(const std::string&s){return ini_name_hash(reinterpret_cast<const std::uint8_t*>(s.data()),s.size(),nullptr);}
void write_z(Heap&h,std::uint32_t p,const std::string&s){for(unsigned n=0;n<s.size();++n)h.w8(p+n,static_cast<std::uint8_t>(s[n]));h.w8(p+static_cast<std::uint32_t>(s.size()),0);}
void sort_index(Memory&m,std::uint32_t index){
 const auto count=m.r32(index+4),table=m.r32(index);std::vector<std::pair<std::int32_t,std::uint32_t>> rows;rows.reserve(count);
 for(unsigned n=0;n<count;++n)rows.emplace_back(s32(m.r32(table+n*8)),m.r32(table+n*8+4));
 std::sort(rows.begin(),rows.end(),[](const auto&a,const auto&b){return a.first<b.first;});
 for(unsigned n=0;n<count;++n){m.w32(table+n*8,static_cast<std::uint32_t>(rows[n].first));m.w32(table+n*8+4,rows[n].second);}
 m.w32(index+16,0);m.w8(index+12,1);
}
void insert_absent(Memory&m,Heap&h,std::uint32_t section,const std::string&key,const std::string&value){
 need(!key.empty()&&!value.empty(),"337 keys and values are nonempty");
 const auto index=section+0x2cu;auto table=m.r32(index);auto count=m.r32(index+4);const auto cap=m.r32(index+8);
 need(table&&count<cap&&cap==32,"337 existing capacity-32 key index has spare cells");
 if(count&&m.r8(index+12)==0)sort_index(m,index);
 const auto keyhash=hash(key);
 for(unsigned n=0;n<count;++n)need(m.r32(table+n*8)!=keyhash,"337 selected keys are distinct and initially absent");
 const auto node=h.allocate(40);need(node,"337 real node allocation succeeds");
 const auto val=h.allocate(static_cast<unsigned>(value.size()+1));need(val,"337 real value clone allocation succeeds");write_z(h,val,value);
 const auto name=h.allocate(static_cast<unsigned>(key.size()+1));need(name,"337 real key clone allocation succeeds");write_z(h,name,key);
 h.w32(node,0x78eb9cu);h.w32(node+4,0);h.w32(node+8,0);h.w32(node+12,name);h.w32(node+16,val);
 for(unsigned off=20;off<=36;off+=4)h.w32(node+off,0);
 const auto head=m.r32(section+0x28);need(head,"337 initialized section list head");const auto next=m.r32(head+4);
 h.w32(node+8,head);h.w32(node+4,next);if(next)h.w32(next+8,node);m.w32(head+4,node);
 m.w32(table+count*8,keyhash);m.w32(table+count*8+4,node);m.w32(index+16,0);m.w8(index+12,0);m.w32(index+4,count+1);
}
std::uint32_t require_existing_section(const Memory&m,std::uint32_t manager,std::uint32_t section_name){
 const auto name=read_z(m,section_name);const auto index=manager+0x20;const auto table=m.r32(index);
 need(m.r32(index+4)==1&&m.r32(index+8)==1&&m.r8(index+12)==1&&table&&m.r32(index+16)==table,
      "337 exact one-section sorted cache-hit receiver shape");
 need(m.r32(table)==hash(name),"337 receiver section hash equals the argument section");
 const auto section=m.r32(table+4);need(section,"337 cached section object exists");
 const auto keys=section+0x2c;need(m.r32(keys)!=0&&m.r32(keys+4)==0&&m.r32(keys+8)==32&&m.r8(keys+12)==1&&m.r32(keys+16)==0,
      "337 exact empty sorted capacity-32 key index");
 const auto head=m.r32(section+0x28);need(head&&m.r32(head+4)==0&&m.r32(head+8)==0,"337 initialized empty list head");
 return section;
}
}

std::uint32_t fun_002c5d0(Memory&m,const Inputs&i,Heap&h){
 need(ra2::platform::small_crt_heap::b337::valid_recipe(ra2::platform::small_crt_heap::b337::requests()),
      "337 local exact nine-request recipe");
 const auto game=i.cx,manager=i.arg[0],section_name=i.arg[1];
 need(game&&manager&&section_name,"337 required root, section, and INI receiver addresses");
 const auto section_text=read_z(m,section_name);need(section_text=="Settings","337 selected literal section fixture");
 const auto section=require_existing_section(m,manager,section_name);
 need(m.r32(game+0x14)==1,"337 exactly one output row");
 const auto percent=m.r32(game+0x1c);need(percent==1,"337 PercentBuilt formatter input is 0..15");
 const auto rows=m.r32(game+8);need(rows,"337 one-row array address");
 const auto row_key=s32(m.r32(rows));need(row_key<0,"337 negative row selector takes literal %d,%d,%d branch");
 const auto a=s16(static_cast<std::uint16_t>(m.r16(rows+4))),b=s16(static_cast<std::uint16_t>(m.r16(rows+6)));
 need(row_key>=-9&&row_key<=-1&&a>=0&&a<=9&&b>=0&&b<=9,"337 bounded one-digit row fields");
 // Original selector-zero 0x50cb30 calls format through %d and forwards the
 // section, PE key, and formatted value to the real 0x10da40 path.
 insert_absent(m,h,section,"PercentBuilt",std::to_string(percent));
 insert_absent(m,h,section,"NodeCount",std::to_string(m.r32(game+0x14)));
 // Original %03d loop index is zero; the negative row word excludes map lookup.
 const auto value=signed_digit(row_key)+","+signed_digit(a)+","+signed_digit(b);
 insert_absent(m,h,section,"000",value);
 return m.r32(game+0x14);
}
}
