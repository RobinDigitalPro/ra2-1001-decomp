#include "recovered/recovery_b842.hpp"
#include "recovered/name_hash.hpp"

#include <algorithm>
#include <array>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

namespace ra2::recovered::recovery_b842 {
namespace {
void need(bool ok,const char*why){if(!ok)throw std::domain_error(why);}
std::int32_t s32(std::uint32_t x){return (x&0x80000000u)?static_cast<std::int32_t>(std::int64_t(x)-0x100000000ll):static_cast<std::int32_t>(x);}
std::string read_z(const Memory&m,std::uint32_t p){
 need(p!=0,"842 non-null static string");std::string out;
 for(unsigned n=0;n<64;++n){const auto c=m.r8(p+n);if(!c)return out;out.push_back(static_cast<char>(c));}
 throw std::domain_error("842 bounded NUL-terminated string");
}
std::uint32_t hash(const std::string&s){return ini_name_hash(reinterpret_cast<const std::uint8_t*>(s.data()),s.size(),nullptr);}
void write_z(Heap&h,std::uint32_t p,const std::string&s){
 for(unsigned n=0;n<s.size();++n)h.w8(p+n,static_cast<std::uint8_t>(s[n]));
 h.w8(p+static_cast<std::uint32_t>(s.size()),0);
}
void sort_index(Memory&m,std::uint32_t index){
 const auto count=m.r32(index+4),table=m.r32(index);std::vector<std::pair<std::int32_t,std::uint32_t>> rows;rows.reserve(count);
 for(unsigned n=0;n<count;++n)rows.emplace_back(s32(m.r32(table+n*8)),m.r32(table+n*8+4));
 std::sort(rows.begin(),rows.end(),[](const auto&a,const auto&b){return a.first<b.first;});
 for(unsigned n=0;n<count;++n){m.w32(table+n*8,static_cast<std::uint32_t>(rows[n].first));m.w32(table+n*8+4,rows[n].second);}
 m.w32(index+16,0);m.w8(index+12,1);
}
std::uint32_t insert_absent(Memory&m,Heap&h,std::uint32_t section,const std::string&key,const std::string&value){
 need(!key.empty()&&!value.empty(),"842 INI key/value are nonempty");
 const auto index=section+0x2cu;const auto table=m.r32(index),count=m.r32(index+4),cap=m.r32(index+8);
 need(table&&count<cap&&cap==32,"842 existing capacity-32 index has one spare row per call");
 if(count&&m.r8(index+12)==0)sort_index(m,index);
 const auto keyhash=hash(key);
 for(unsigned n=0;n<count;++n)need(m.r32(table+n*8)!=keyhash,"842 selected distinct key is absent");
 // B337-derived structured absent-key route. Under the explicit threshold-zero
 // precondition, each exact request is a real ordinary-heap allocation.
 const auto node=h.allocate(40);need(node,"842 real node allocation succeeds");
 const auto val=h.allocate(static_cast<unsigned>(value.size()+1));need(val,"842 real value clone allocation succeeds");write_z(h,val,value);
 const auto name=h.allocate(static_cast<unsigned>(key.size()+1));need(name,"842 real key clone allocation succeeds");write_z(h,name,key);
 h.w32(node,0x78eb9cu);h.w32(node+4,0);h.w32(node+8,0);h.w32(node+12,name);h.w32(node+16,val);
 for(unsigned off=20;off<=36;off+=4)h.w32(node+off,0);
 const auto head=m.r32(section+0x28);need(head,"842 initialized SpecialFlags list head");const auto next=m.r32(head+4);
 h.w32(node+8,head);h.w32(node+4,next);if(next)h.w32(next+8,node);m.w32(head+4,node);
 m.w32(table+count*8,keyhash);m.w32(table+count*8+4,node);m.w32(index+16,0);m.w8(index+12,0);m.w32(index+4,count+1);
 // Original 0x10da40 successful insertion epilogue writes AL=1 at VA 0x50dda5.
 return 1;
}
std::uint32_t require_section(const Memory&m,std::uint32_t receiver,std::uint32_t section_name){
 need(read_z(m,section_name)=="SpecialFlags","842 actual global section-name argument is SpecialFlags");
 const auto index=receiver+0x20,table=m.r32(index);
 need(m.r32(index+4)==1&&m.r32(index+8)==1&&m.r8(index+12)==1&&table&&m.r32(index+16)==table,
      "842 matching one-section sorted receiver/cache shape");
 need(m.r32(table)==hash("SpecialFlags"),"842 receiver section hash matches literal section");
 const auto section=m.r32(table+4);need(section,"842 existing cached section pointer");
 const auto keys=section+0x2c;need(m.r32(keys)&&m.r32(keys+4)<32&&m.r32(keys+8)==32&&m.r32(keys+16)==0,
      "842 capacity-32 existing-key index with room for thirteen entries");
 need(m.r32(section+0x28),"842 initialized section list head");return section;
}
constexpr std::array<std::uint32_t,13> key_va{
 0x7db1a4u,0x7ddd4cu,0x7d96fcu,0x7ddd38u,0x7ddd2cu,0x7ddd1cu,0x7ddd0cu,
 0x7ddcfcu,0x7db120u,0x7ddcf4u,0x7ddce8u,0x7ddcdcu,0x7ddcd0u};
constexpr std::array<unsigned,13> bit{6,7,14,15,8,9,10,11,12,5,17,16,18};
constexpr std::array<std::uint32_t,13> expected_hash{
 0xbbfdc45au,0x95f2d8e6u,0x0a7117b8u,0x88387572u,0x7d2174d4u,
 0x9450795eu,0x048dbdaau,0x1061d75au,0x8d2f0269u,0xaaf6487au,
 0x5638b326u,0x19f8e6e7u,0xeffca434u};
}

std::uint32_t fun_00680b30(Memory&m,const Inputs&i,Heap&h){
 const auto flags=i.cx,receiver=i.arg[0],section_name=m.r32(0x7ddc88u);
 need(flags&&receiver&&section_name==0x7ddc90u,"842 root flags, receiver, and actual SpecialFlags global pointer");
 need(m.r32(0x817554u)==0&&m.r32(0xb10e14u)==0,"842 explicit ordinary-heap threshold-zero initial state");
 const auto word=m.r32(flags),section=require_section(m,receiver,section_name);
 std::uint32_t last_writer_result=0;
 for(unsigned n=0;n<key_va.size();++n){
  const auto key=read_z(m,key_va[n]);need(hash(key)==expected_hash[n],"842 cached key literal/hash identity");
  const auto value=((word>>bit[n])&1u)?std::string("yes"):std::string("no");
  last_writer_result=insert_absent(m,h,section,key,value);
 }
 // Original root returns the EAX left by its thirteenth boolean/writer call.
 return last_writer_result;
}
} // namespace ra2::recovered::recovery_b842
