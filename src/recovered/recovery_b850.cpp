#include "recovered/recovery_b850.hpp"
#include "recovered/ini_writer850.hpp"
#include "recovered/global_b26_memory.hpp"
#include "recovered/name_hash.hpp"
#include <cstdint>
#include <stdexcept>
#include <string>

namespace ra2::recovered::recovery_b850 {
namespace {
using Memory=ra2::recovered::global_b26::Memory;
using Heap=ra2::platform::ordinary_heap::Heap;
void need(bool v,const char*why){if(!v)throw std::domain_error(why);}
std::string read_z(const Memory&m,std::uint32_t p,unsigned bound=128){need(p,"850 serializer string pointer");std::string s;for(unsigned k=0;k<bound;++k){auto c=static_cast<unsigned char>(m.r8(p+k));if(!c)return s;s.push_back(static_cast<char>(c));}throw std::domain_error("850 bounded string input");}
void write_z(Memory&m,std::uint32_t p,const std::string&s){for(unsigned k=0;k<s.size();++k)m.w8(p+k,static_cast<unsigned char>(s[k]));m.w8(p+static_cast<std::uint32_t>(s.size()),0);}
std::int32_t s32(std::uint32_t v){return ra2::recovered::global_b26::s32(v);}
std::uint32_t hash(const std::string&s){return ra2::recovered::ini_name_hash(reinterpret_cast<const std::uint8_t*>(s.data()),s.size(),nullptr);}
std::string literal(Memory&m,std::uint32_t p,const char*expected){auto s=read_z(m,p,64);need(s==expected,"850 original literal address contains the checked text");return s;}
std::uint32_t write(Memory&m,Heap&h,std::uint32_t root,std::uint32_t section,
                    const std::string&key,const std::string&value,
                    std::uint32_t key_scratch,std::uint32_t value_scratch){
 need(!key.empty()&&!value.empty(),"850 writer values must be nonempty");write_z(m,key_scratch,key);write_z(m,value_scratch,value);
 return write_absent(m,h,root,section,key_scratch,value_scratch);
}
std::string decimal(std::int32_t n){return std::to_string(n);}
std::int32_t credits_scaled_100(std::int32_t value){
 // Matches the original signed 0x51eb851f multiply, SAR 5 and sign-correction
 // sequence for the selected finite values (the effect is truncating /100).
 return value/100;
}
std::string allies_value(const Memory&m,std::uint32_t object){
 constexpr std::uint32_t count_addr=0x00a1a5d8u,array_ptr_addr=0x00a1a5ccu;
 const auto count=m.r32(count_addr),array=m.r32(array_ptr_addr),mask=m.r32(object+0x120);
 need(count==1&&array,"850 Allies route is bounded to one global house-table entry");
 const auto member=m.r32(array);need(member&&m.r32(member+0x30)==0,"850 one-member Allies bit index is zero");
 need((mask&1u)!=0,"850 selected object mask includes the one Allies member");
 return read_z(m,member+0x15ee0,64);
}
}

std::uint32_t serialize_eb750(Memory&m,const Eb750Case&c,Heap&h){
 need(c.object&&c.ini_root&&c.country_text&&c.color_table&&c.color_object&&c.color_text,"850 fixture anchors are nonnull");
 need(c.section_scratch&&c.key_scratch&&c.value_scratch,"850 model-only scratch addresses are explicit");
 const auto obj=c.object,root=c.ini_root;
 need(m.r32(obj+0x34)+0x24u==c.country_text,"850 Country value is the original object field +0x34 then +0x24");
 const auto section=read_z(m,obj+0x15ee0,20);need(!section.empty(),"850 fresh section name is nonempty");
 write_z(m,c.section_scratch,section); // Original entry copies this name to its stack local.
 // In 0xeb750 the target is cleared via 0x10adf0 before any writer call. The
 // finite root fixture holds one unrelated Settings section; byte review of
 // 0x50adf0/0x510440 supports true on this absent section without mutation.
 need(m.r32(root+0x24)==1&&m.r32(root+0x28)==10&&m.r8(root+0x2c)==1,
      "850 clear route begins with one sorted Settings section and spare index capacity");
 const auto rtable=m.r32(root+0x20);need(rtable&&m.r32(rtable+4)!=0&&m.r32(root+0x30)==rtable,"850 initialized root index and cached Settings row");
 need(hash(section)!=hash("Settings"),"850 section hash must miss the sole Settings row in the actual 0x10adf0 search");
 for(unsigned k=0;k<m.r32(root+0x24);++k)
  need(read_z(m,m.r32(m.r32(rtable+8*k+4)+0x0c))!=section,"850 section clear/search proves target absent");

 const auto country=read_z(m,c.country_text,64);need(!country.empty(),"850 Country text is nonempty");
 // 0x4eb7a5: first writer, which creates the target section.
 write(m,h,root,c.section_scratch,"Country",country,c.key_scratch,c.value_scratch);

 // Original 0x10cb30 selector=0 path formats these numeric fields with the
 // verified literal `%d`; selected fixture values keep conversion in the
 // ordinary signed-decimal route.
 const auto tech=s32(m.r32(obj+0x11c));
 write(m,h,root,c.section_scratch,literal(m,0x007c5944u,"TechLevel"),decimal(tech),c.key_scratch,c.value_scratch);
 const auto credits=credits_scaled_100(s32(m.r32(obj+0x124)));
 write(m,h,root,c.section_scratch,literal(m,0x007c593cu,"Credits"),decimal(credits),c.key_scratch,c.value_scratch);
 const auto iq=s32(m.r32(obj+0x118));
 write(m,h,root,c.section_scratch,literal(m,0x007c58dcu,"IQ"),decimal(iq),c.key_scratch,c.value_scratch);

 // Original 0x6aa10 maps the selected small index through its constant table.
 const auto edge_index=m.r32(obj+0x128);need(edge_index==0,"850 Edge fixture selects the proven table row zero");
 const auto edge_ptr=m.r32(0x00785b50u+4*edge_index);const auto edge=read_z(m,edge_ptr,32);
 need(edge=="North","850 Edge literal table row zero is North");
 write(m,h,root,c.section_scratch,literal(m,0x007c58d4u,"Edge"),edge,c.key_scratch,c.value_scratch);

 // Original 0x10e7d0 selects exact `yes`/`no` literals. Choose yes in the
 // fixture; both branches can be covered by changing only this byte.
 const bool player_control=m.r8(obj+0x135)!=0;
 write(m,h,root,c.section_scratch,literal(m,0x007c592cu,"PlayerControl"),player_control?"yes":"no",c.key_scratch,c.value_scratch);

 // 0x469c00 indexes the real game color pointer array, then reads +0x304.
 const auto color_index=m.r32(obj+0x15f40);need(color_index==0,"850 Color fixture uses index zero");
 need(m.r32(0x00a9ea04u)==c.color_table&&m.r32(c.color_table+4*color_index)==c.color_object,
      "850 color global table contains the fixture color object at index zero");
 need(m.r32(c.color_object+0x304)==c.color_text,"850 color object's string field is the fixture text");
 const auto color=read_z(m,c.color_text,64);need(!color.empty(),"850 color string is nonempty");
 write(m,h,root,c.section_scratch,literal(m,0x007bc370u,"Color"),color,c.key_scratch,c.value_scratch);

 // The accepted 0x6a3c0 path receives object+0x120 as bit mask. Constrain its
 // global house array to one matching member so comma-join behavior is exact.
 const auto allies=allies_value(m,obj);
 write(m,h,root,c.section_scratch,literal(m,0x007c58ccu,"Allies"),allies,c.key_scratch,c.value_scratch);

 // The original emits UIName only when its first byte is nonzero. This case
 // exercises that positive branch; the independent cases include both modes.
 if(m.r8(obj+0x15ef5)!=0){
  const auto ui=read_z(m,obj+0x15ef5,64);need(!ui.empty(),"850 optional UIName is nonempty");
  write(m,h,root,c.section_scratch,literal(m,0x007b922cu,"UIName"),ui,c.key_scratch,c.value_scratch);
 }

 // The final original 0x2c5d0 call receives the same stack-local house section
 // name and contributes three more distinct rows to that fresh section.
 const auto game=obj+0x55f0;
 need(m.r32(game+0x14)==1&&m.r32(game+0x1c)==1,"850 final Settings route has one node and percent one");
 const auto rows=m.r32(game+8);need(rows&&s32(m.r32(rows))==-1&&m.r16(rows+4)==0&&m.r16(rows+6)==0,
      "850 final Settings row selects bounded negative literal formatting");
 write(m,h,root,c.section_scratch,"PercentBuilt","1",c.key_scratch,c.value_scratch);
 write(m,h,root,c.section_scratch,"NodeCount","1",c.key_scratch,c.value_scratch);
 write(m,h,root,c.section_scratch,"000","-1,0,0",c.key_scratch,c.value_scratch);
 return 1;
}
}

namespace ra2::recovered::recovery_b850 {std::uint32_t fun_004eb750(global_b26::Memory&m,const global_b26::Inputs&i,const Eb750Case&c,platform::ordinary_heap::Heap&h){if(i.cx!=c.object||i.arg[0]!=c.ini_root)throw std::domain_error("850 original entry arguments");auto result=serialize_eb750(m,c,h);i.arg[0]=0;return result;}}
