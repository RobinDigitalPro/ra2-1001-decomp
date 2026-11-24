#include "recovered/recovery_b894.hpp"
#include "recovered/name_hash.hpp"
#include <algorithm>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

namespace ra2::recovered::recovery_b894 {
namespace {
using Memory=ra2::recovered::global_b26::Memory;
using Heap=ra2::platform::ordinary_heap::Heap;
void need(bool v,const char* why){if(!v)throw std::domain_error(why);}
std::uint32_t r8(const Memory&m,const Heap&h,std::uint32_t a){(void)m;return h.r8(a);}
std::uint32_t r32(const Memory&m,const Heap&h,std::uint32_t a){(void)m;return h.r32(a);}
void w8(Memory&m,Heap&h,std::uint32_t a,std::uint32_t v){(void)m;h.w8(a,v);}
void w32(Memory&m,Heap&h,std::uint32_t a,std::uint32_t v){(void)m;h.w32(a,v);}
std::string z(const Memory&m,std::uint32_t p,std::uint32_t cap=256){
 need(p,"894 writer string pointer is nonnull");std::string s;
 for(std::uint32_t n=0;n<cap;++n){auto c=static_cast<unsigned char>(m.r8(p+n));if(!c)return s;s.push_back(static_cast<char>(c));}
 throw std::domain_error("894 bounded NUL string");
}
std::uint32_t hash(const std::string&s){
 return ra2::recovered::ini_name_hash(reinterpret_cast<const std::uint8_t*>(s.data()),s.size(),nullptr);
}
void put(Heap&h,std::uint32_t p,const std::string&s){for(std::uint32_t n=0;n<s.size();++n)h.w8(p+n,static_cast<unsigned char>(s[n]));h.w8(p+static_cast<std::uint32_t>(s.size()),0);}
std::uint32_t dup(Heap&h,const std::string&s){auto p=h.allocate(static_cast<std::uint32_t>(s.size()+1));need(p,"894 selected ordinary heap allocation succeeds");put(h,p,s);return p;}
void link_init(Heap&h,std::uint32_t p){h.w32(p,0x785afcu);h.w32(p+4,0);h.w32(p+8,0);}
std::uint32_t find_section(Memory&m,Heap&h,std::uint32_t root,const std::string&name){
 const auto ix=root+0x20,n=m.r32(ix+4),cap=m.r32(ix+8),table=m.r32(ix);
 need(n<=cap&&((n==0&&table==0)||(n>0&&table!=0)),"894 root index count/table shape");
 const auto needle_hash=ra2::recovered::global_b26::s32(hash(name));
 // This mirrors the inline sorted-index path inside 0x510440. The first fresh
 // section append clears the root sorted byte. The next write sorts those
 // two signed-hash rows in place, clears the cached-row pointer, then binary
 // searches. The selected names have distinct hashes, so duplicate ordering
 // in the original qsort comparator is not exercised.
 if(n&&m.r8(ix+12)==0){
  std::vector<std::pair<std::int32_t,std::uint32_t>> rows;rows.reserve(n);
  for(std::uint32_t k=0;k<n;++k)rows.emplace_back(ra2::recovered::global_b26::s32(m.r32(table+8*k)),m.r32(table+8*k+4));
  std::sort(rows.begin(),rows.end(),[](const auto&a,const auto&b){return a.first<b.first;});
  for(std::uint32_t k=0;k<n;++k){m.w32(table+8*k,static_cast<std::uint32_t>(rows[k].first));m.w32(table+8*k+4,rows[k].second);}
  m.w32(ix+16,0);m.w8(ix+12,1);
 }
 const auto cached=m.r32(ix+16);
 if(cached&&m.r32(cached)==static_cast<std::uint32_t>(needle_hash)){
  const auto s=m.r32(cached+4),np=r32(m,h,s+0x0c);std::string actual;
  for(unsigned j=0;j<256;++j){auto c=static_cast<unsigned char>(r8(m,h,np+j));if(!c)break;actual.push_back(static_cast<char>(c));}
  need(actual==name,"894 cached section hash resolves to the exact selected name");return s;
 }
 std::uint32_t low=0,high=n;
 while(low<high){const auto middle=low+(high-low)/2;const auto key=ra2::recovered::global_b26::s32(m.r32(table+8*middle));
  if(needle_hash<key)high=middle;else if(needle_hash==key){const auto row=table+8*middle,s=m.r32(row+4),np=r32(m,h,s+0x0c);std::string actual;for(unsigned j=0;j<256;++j){auto c=static_cast<unsigned char>(r8(m,h,np+j));if(!c)break;actual.push_back(static_cast<char>(c));}need(actual==name,"894 section hash collision is outside this selected finite route");m.w32(ix+16,row);return s;}else low=middle+1;
 }
 return 0;
}
void insert_key(Memory&m,Heap&h,std::uint32_t section,const std::string&key,const std::string&value){
 need(!key.empty()&&!value.empty(),"894 positive writer subset requires nonempty key/value");
 const auto ix=section+0x2cu;auto table=r32(m,h,ix),count=r32(m,h,ix+4),cap=r32(m,h,ix+8);
 if(count&&r8(m,h,ix+12)==0){
  const auto n=count;std::vector<std::pair<std::int32_t,std::uint32_t>> rows;rows.reserve(n);
  for(std::uint32_t i=0;i<n;++i)rows.emplace_back(ra2::recovered::global_b26::s32(r32(m,h,table+8*i)),r32(m,h,table+8*i+4));
  std::sort(rows.begin(),rows.end(),[](const auto&a,const auto&b){return a.first<b.first;});
  for(std::uint32_t i=0;i<n;++i){w32(m,h,table+8*i,static_cast<std::uint32_t>(rows[i].first));w32(m,h,table+8*i+4,rows[i].second);}
  w32(m,h,ix+16,0);w8(m,h,ix+12,1);
 }
 if(!table)need(count==0&&cap==0,"894 key-index creation requires exact empty index");
 else need(count<=cap&&(cap==10||cap==20||cap==32),"894 key index capacity is on the bounded 10/20/32 route");
 const auto kh=hash(key);for(std::uint32_t i=0;i<count;++i)need(r32(m,h,table+8*i)!=kh,"894 selected key is distinct and absent");
 const auto node=h.allocate(40);need(node,"894 node allocation succeeds");
 const auto value_copy=dup(h,value);const auto key_copy=dup(h,key);
 link_init(h,node);h.w32(node,0x78eb9cu);h.w32(node+12,key_copy);h.w32(node+16,value_copy);
 for(unsigned off=20;off<=36;off+=4)h.w32(node+off,0);
 const auto head=r32(m,h,section+0x28);need(head,"894 initialized section list head");
 const auto next=r32(m,h,head+4);w32(m,h,node+8,head);w32(m,h,node+4,next);if(next)w32(m,h,next+8,node);w32(m,h,head+4,node);
 // The original absent-section route constructs the node and clones both
 // strings before either initial key-index allocation or capacity growth.
 if(!table){table=h.allocate(80);need(table,"894 key table allocation succeeds");w32(m,h,ix,table);w32(m,h,ix+8,10);w32(m,h,ix+16,0);w8(m,h,ix+12,0);cap=10;}
 else if(count==cap){
  need(cap==10,"894 single observed growth is limited to the original 10-to-20 row transition");
  const auto grown=h.allocate(160);need(grown,"894 20-row key table allocation succeeds");
  for(std::uint32_t i=0;i<count;++i){h.w32(grown+8*i,r32(m,h,table+8*i));h.w32(grown+8*i+4,r32(m,h,table+8*i+4));}
  need(h.release(table)!=0,"894 original 0x110150 HeapFree succeeds for the old 80-byte table");
  table=grown;cap=20;w32(m,h,ix,table);w32(m,h,ix+8,cap);w32(m,h,ix+16,0);
 }
 need(count<cap,"894 key index has known spare capacity after optional creation");
 w32(m,h,table+8*count,kh);w32(m,h,table+8*count+4,node);w32(m,h,ix+16,0);w8(m,h,ix+12,0);w32(m,h,ix+4,count+1);
}
std::uint32_t make_section(Memory&m,Heap&h,std::uint32_t root,const std::string&name){
 const auto ix=root+0x20;auto table=m.r32(ix);const auto count=m.r32(ix+4),cap=m.r32(ix+8);
 need(table&&count>=1&&count<=2&&cap==10,"894 fresh-section append is bounded to existing Settings plus at most two absent names in spare ten-row root index");
 const auto s=h.allocate(0x44);need(s,"894 section object allocation succeeds");link_init(h,s);const auto nameptr=dup(h,name);
 h.w32(s,0x78eba4u);h.w32(s+0x0c,nameptr);
 h.w32(s+0x10,0x78ebacu);link_init(h,s+0x14);link_init(h,s+0x20);h.w32(s+0x18,s+0x20);h.w32(s+0x28,s+0x14);
 h.w32(s+0x2c,0);h.w32(s+0x30,0);h.w32(s+0x34,0);h.w8(s+0x38,0);h.w32(s+0x3c,0);h.w32(s+0x40,0);
 const auto head=m.r32(root+0x1c),next=count==1?m.r32(head+4):h.r32(head+4);h.w32(s+8,head);h.w32(s+4,next);if(next)m.w32(next+8,s);if(count==1)m.w32(head+4,s);else h.w32(head+4,s);
 need(count<cap,"894 existing root index has spare capacity for the target section");
 m.w32(table+8*count,hash(name));m.w32(table+8*count+4,s);
 // 0x110150's in-capacity append clears sorted and increments count; it
 // leaves the old cache pointer untouched until 0x510440 sorts next lookup.
 m.w8(ix+12,0);m.w32(ix+4,count+1);
 return s;
}
}

std::uint32_t probe_section(Memory&m,Heap&h,std::uint32_t root,std::uint32_t section_text){
 const auto name=z(m,section_text);need(!name.empty(),"894 nonnull named section lookup");return find_section(m,h,root,name);
}
std::uint32_t write_absent(Memory&m,Heap&h,std::uint32_t root,std::uint32_t section_text,
                           std::uint32_t key_text,std::uint32_t value_text){
 need(root&&section_text&&key_text&&value_text,"894 writer nonnull inputs");
 const auto section_name=z(m,section_text),key=z(m,key_text),value=z(m,value_text);
 need(!section_name.empty()&&!key.empty()&&!value.empty(),"894 writer strings are nonempty");
 auto section=find_section(m,h,root,section_name);
 if(!section)section=make_section(m,h,root,section_name);
 insert_key(m,h,section,key,value);
 return 1;
}
}
