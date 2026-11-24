#include "recovery_b908.hpp"
#include "recovered/ini_bulk.hpp"
#include "recovered/ini_text.hpp"
#include "recovered/name_hash.hpp"
#include "platform/current_crt_thread.hpp"
#include <array>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <vector>

// Private portable semantic draft. The native differential must execute the
// original root and every original helper; this file only supplies its model.
namespace b908_draft {
namespace {
using namespace ra2::recovered;
using Memory=global_b26::Memory;
using Inputs=global_b26::Inputs;
using Heap=ra2::platform::ordinary_heap::Heap;

void need(bool b,const char*why){if(!b)throw std::domain_error(why);}
std::int32_t s32(U x){return global_b26::s32(x);}
std::int32_t s16(U x){return static_cast<std::int16_t>(x);}
void hw16(Heap&h,U a,U x){h.w8(a,x);h.w8(a+1u,x>>8);}
std::uint32_t hash_bytes(const std::uint8_t*p,std::size_t n,void*){
  return ini_name_hash(p,n,nullptr);
}
std::int32_t ascii_lower(std::int32_t c,void*){
  return c>='A'&&c<='Z'?c+('a'-'A'):c;
}
void no_sort(IniIndexEntry*,std::int32_t,IniIndexKind,void*){
  throw std::domain_error("908 finite fixture requires already sorted indexes");
}
std::string guest_text(const Memory&m,U p,U limit){
  need(p!=0,"908 nonnull guest text");std::string s;
  for(U k=0;k<limit;++k){U c=m.r8(p+k);if(!c)return s;s.push_back(static_cast<char>(c));}
  throw std::domain_error("908 guest text bound");
}
struct IniView {
  Memory&m;U root_guest{},section_guest{},key_guest{},root_table{},key_table{};
  U root_cache_before{},key_cache_before{};
  std::array<std::uint8_t,64> key_text{};std::array<std::uint8_t,0x200> value_text{};
  IniValue value{};IniIndexEntry root_entry{},key_entry{};IniIndex root{};
  IniSection section{};IniKeyNode first{},sentinel{};IniOperations ops{};
  IniView(Memory&mem,U ini):m(mem),root_guest(ini+0x20u){
    root_table=m.r32(root_guest);
    need(root_table&&m.r32(root_guest+4u)==1u&&m.r8(root_guest+12u)==1u,
         "908 one initialized sorted Tubes section");
    root_cache_before=m.r32(root_guest+16u);
    need(!root_cache_before||root_cache_before==root_table,
         "908 root cache points to its only section row");
    root_entry.key=static_cast<std::int32_t>(m.r32(root_table));
    section_guest=m.r32(root_table+4u);key_guest=section_guest+0x2cu;
    key_table=m.r32(key_guest);
    need(key_table&&m.r32(key_guest+4u)==1u&&m.r32(key_guest+8u)>=1u&&
         m.r8(key_guest+12u)==1u,"908 one initialized sorted key");
    key_cache_before=m.r32(key_guest+16u);
    need(!key_cache_before||key_cache_before==key_table,
         "908 key cache points to its only row");
    key_entry.key=static_cast<std::int32_t>(m.r32(key_table));
    const U value_guest=m.r32(key_table+4u);
    value.text=key_text.data();key_entry.value=&value;root_entry.value=&section;
    root.entries=&root_entry;root.count=1;root.spare=1;root.sorted=1;
    root.cached=root_cache_before?&root_entry:nullptr;
    section.keys.entries=&key_entry;section.keys.count=1;section.keys.spare=1;
    section.keys.sorted=1;section.keys.cached=key_cache_before?&key_entry:nullptr;
    const U key_list=m.r32(section_guest+0x18u);
    const U name_guest=m.r32(key_list+0x0cu);
    bool key_end=false,value_end=false;
    for(U k=0;k<key_text.size();++k){key_text[k]=static_cast<std::uint8_t>(m.r8(name_guest+k));if(!key_text[k]){key_end=true;break;}}
    for(U k=0;k<value_text.size();++k){value_text[k]=static_cast<std::uint8_t>(m.r8(m.r32(value_guest+0x10u)+k));if(!value_text[k]){value_end=true;break;}}
    need(key_end&&value_end,"908 bounded NUL-terminated key/value strings");
    value.text=value_text.data();
    // Original 0x50c250 enumerates this initialized sentinel-terminated chain;
    // the key index is a separate sorted lookup structure.
    const U node=m.r32(section_guest+0x18u);
    need(node&&m.r32(node+4u)&&m.r32(node+8u),"908 initialized key-list node");
    const U listed_name=m.r32(node+0x0cu);
    need(listed_name==name_guest,"908 linked key name agrees with key row");
    sentinel.next=nullptr;sentinel.previous=&first;sentinel.name=nullptr;
    first.next=&sentinel;first.previous=&sentinel;first.name=key_text.data();section.first=&first;
    ops={hash_bytes,no_sort,ascii_lower,nullptr,nullptr,nullptr};
    need(root_entry.key==static_cast<std::int32_t>(ini_name_hash(
      reinterpret_cast<const std::uint8_t*>("Tubes"),5,nullptr)),"908 exact Tubes hash");
  }
  void flush(){
    m.w32(root_guest+16u,root_table);
    m.w32(key_guest+16u,key_table);
  }
};

std::vector<std::int32_t> comma_ints(const std::string&s){
  need(!s.empty(),"908 nonempty text");std::vector<std::int32_t>out;
  std::size_t p=0;
  while(p<s.size()){
    const std::size_t begin=p;if(s[p]=='-')++p;
    const std::size_t digits=p;std::int64_t value=0;
    while(p<s.size()&&s[p]>='0'&&s[p]<='9'){
      value=value*10+(s[p++]-'0');need(value<=2147483648ll,"908 bounded signed decimal");
    }
    need(p>digits,"908 integer has at least one digit");
    const bool neg=s[begin]=='-';need(value<=(neg?2147483648ll:2147483647ll),"908 signed dword range");
    out.push_back(static_cast<std::int32_t>(neg?-value:value));
    if(p==s.size())break;
    need(s[p++]==','&&p<s.size(),"908 comma-separated complete tokens");
  }
  return out;
}
void base_initialize(Heap&h,U o){
  h.w32(o+8,0x785e44);h.w32(o+0x0c,0x785e3c);h.w32(o+0x18,0);h.w32(o+0x1c,0);h.w8(o+0x20,0);
  const U flags=h.r8(o+0x14)&0xf8u;h.w32(o+0x10,0xffffffffu);h.w32(o,0x785dd8);h.w32(o+4,0x785dbc);
  h.w32(o+8,0x785db4);h.w32(o+0x0c,0x785dac);h.w8(o+0x14,flags);
}
void construct( Memory&m,Heap&h,U o,U registry_entry){
  // The root's constructor arguments address two explicit zero local words.
  base_initialize(h,o);const U first=0;
  h.w32(o+0x24,first);h.w32(o+0x28,first);h.w32(o+0x2c,0);h.w32(o+0x1c0,0);
  h.w32(o,0x7989e0);h.w32(o+4,0x7989c4);h.w32(o+8,0x7989bc);h.w32(o+0x0c,0x7989b4);
  need(m.r32(0x00a255c0u)==0,"908 only accepted 0x40ffd0 zero-global branch");
  h.w32(o+0x10,0); // actual 0x40ffd0 writes argument(receiver+4)+0x0c
  for(U k=0;k<100;++k)h.w32(o+0x30u+4u*k,0xffffffffu);
  const U old=m.r32(0x0084e508u),cap=m.r32(0x0084e500u),table=m.r32(0x0084e4fcu);
  need(s32(old)>=0&&s32(cap)>s32(old)&&table,"908 preallocated direct registry append");
  m.w32(0x0084e508u,old+1u);m.w32(table+4u*old,registry_entry);
}
}

U fun_006e4880(Memory&m,Inputs&i,Heap&heap,U entry_esp,U crt_thread){
  const U actual_thread=ra2::platform::current_crt_thread(m.r32(0x00817778u));
  need(actual_thread==crt_thread,"908 supplied thread matches the actual current CRT TLS slot");
  IniView graph(m,i.cx);static constexpr std::uint8_t section_name[]="Tubes";
  const auto count=fun_0050bf50(&graph.root,section_name,graph.ops);
  need(count==1,"908 exactly one actual Tubes row");
  const auto*key=fun_0050c250(&graph.root,section_name,0,graph.ops);
  need(key!=nullptr,"908 actual first indexed key enumerates");
  std::array<std::uint8_t,0x200>row{};static constexpr std::uint8_t fallback[]={0};
  const auto copied=fun_0050ddf0(&graph.root,section_name,key,fallback,row.data(),0x200,graph.ops);
  graph.flush();need(copied>0&&copied<0x200,"908 nonempty bounded original text route");
  const auto value=comma_ints(std::string(reinterpret_cast<const char*>(row.data())));
  need(value.size()>=7&&value.size()<=10,"908 five headers plus one-to-four directions and terminator");
  const auto dirs=static_cast<U>(value.size()-6u);need(dirs>=1&&dirs<=4&&value.back()==-1,"908 exact direction grammar");
  for(U k=0;k<5;++k)need(value[k]>=-32768&&value[k]<=32767,"908 signed WORD header range");
  for(U k=5;k<value.size();++k)need(value[k]==-1||(value[k]>=0&&value[k]<=7),"908 finite 0..7 direction code or -1 sentinel");
  const U x=static_cast<std::uint16_t>(value[0]),y=static_cast<std::uint16_t>(value[1]);
  need(value[0]>=1&&value[0]<=511&&value[1]>=1&&value[1]<=511,"908 positive map coordinates");
  const U request=0x1c4u;const U o=heap.allocate(request);need(o,"908 successful original CRT allocation");
  construct(m,heap,o,o);
  hw16(heap,o+0x24,static_cast<U>(value[0]));hw16(heap,o+0x26,static_cast<U>(value[1]));
  heap.w32(o+0x2c,static_cast<U>(value[2]));hw16(heap,o+0x28,static_cast<U>(value[3]));hw16(heap,o+0x2a,static_cast<U>(value[4]));
  heap.w32(o+0x1c0,0xffffffffu);
  for(U k=0;k<dirs+1u;++k){heap.w32(o+0x30u+4u*k,static_cast<U>(value[5u+k]));heap.w32(o+0x1c0,heap.r32(o+0x1c0)+1u);}
  const U index=y*512u+x,map_table=m.r32(0x0081a958u);
  need(map_table&&index<0x40000u,"908 authentic map table and bounded positive index");
  const U tile=m.r32(map_table+4u*index);need(tile!=0,"908 nonnull original map tile");
  m.w16(tile+0x116u,0); // original enumeration index is zero
  const U text_len=static_cast<U>(copied);
  m.w32(crt_thread+0x18u,entry_esp-0x200u+text_len);
  return count;
}
}
