#include "recovered/recovery_b916.hpp"
#include "recovered/ini_integer.hpp"
#include "recovered/ini_lookup.hpp"
#include "recovered/ini_text.hpp"
#include "recovered/text_b104.hpp"
#include "recovered/name_hash.hpp"
#include "recovered/global_b26_memory.hpp"
#include <algorithm>
#include <array>
#include <memory>
#include <charconv>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <vector>

namespace ra2::recovered::recovery_b916 {
namespace {
using U=std::uint32_t;
using namespace global_b26;
[[noreturn]] void reject(const char* why){throw std::domain_error(why);}
std::vector<std::uint8_t> ztext(const Memory&m,U p,U limit=96){
 if(!p)reject("B916 null string");std::vector<std::uint8_t> out;
 for(U n=0;n<limit;++n){auto b=static_cast<std::uint8_t>(m.r8(p+n));out.push_back(b);if(!b)return out;}
 reject("B916 bounded string exceeded");
}
std::int32_t shash(U h){return global_b26::s32(h);}
std::uint32_t hash_cb(const std::uint8_t*p,std::size_t n,void*){return ini_name_hash(p,n,nullptr);}
void no_sort(IniIndexEntry*,std::int32_t,IniIndexKind,void*){reject("B916 initialized signed-sorted indexes only");}
std::int32_t upper(std::int32_t c,void*){return c>='a'&&c<='z'?c-('a'-'A'):c;}
std::int32_t lower(std::int32_t c,void*){return c>='A'&&c<='Z'?c+('a'-'A'):c;}
struct IniGraph{
 Memory&m;U receiver;U section_guest=0;IniIndex root{};IniIndexEntry root_row[1]{};IniSection section{};
 std::vector<IniIndexEntry> rows;std::vector<std::unique_ptr<IniValue>> values;std::vector<std::vector<std::uint8_t>> strings;IniOperations ops{};
 IniGraph(Memory&mem,U recv,U section_name,U expected):m(mem),receiver(recv){
  const U index=receiver+0x20u,table=m.r32(index),count=m.r32(index+4u);
  if(!receiver||count!=1||!table||!m.r8(index+12u)||!m.r32(table+4u))reject("B916 requires one initialized sorted section");
  section_guest=m.r32(table+4u);const auto section_bytes=ztext(m,section_name);const U rh=m.r32(table),qh=ini_name_hash(section_bytes.data(),section_bytes.size()-1u,nullptr);
  if(rh!=qh)reject("B916 section hash does not match original section string");
  root_row[0]={shash(rh),&section};root={root_row,1,1,nullptr,1};
  const U ki=section_guest+0x2cu,kt=m.r32(ki),kc=m.r32(ki+4u);
  if(kc!=expected||!kt||!m.r8(ki+12u)||m.r32(ki+8u)<kc)reject("B916 requires complete initialized key table");
  rows.resize(kc);values.reserve(kc);strings.reserve(kc);
  for(U n=0;n<kc;++n){const U row=kt+8u*n,v=m.r32(row+4u),tp=m.r32(v+0x10u);strings.push_back(ztext(m,tp));auto value=std::make_unique<IniValue>();value->text=strings.back().data();rows[n]={shash(m.r32(row)),value.get()};values.push_back(std::move(value));if(n&&rows[n-1].key>=rows[n].key)reject("B916 key hashes must be unique signed-sorted");}
  section.keys={rows.data(),static_cast<std::int32_t>(kc),1,nullptr,kc};ops={hash_cb,no_sort,upper,nullptr,nullptr,nullptr};
  refresh();
 }
 void refresh_one(U index,IniIndex&idx,IniIndexEntry*data,U n){idx.cached=nullptr;const U raw=m.r32(index+16u),tab=m.r32(index);if(!raw)return;if(raw<tab||((raw-tab)&7u)||(raw-tab)/8u>=n)reject("B916 cache outside key table");idx.cached=data+(raw-tab)/8u;}
 void refresh(){refresh_one(receiver+0x20u,root,root_row,1);refresh_one(section_guest+0x2cu,section.keys,rows.data(),static_cast<U>(rows.size()));}
 void flush_one(U index,const IniIndex&idx,const IniIndexEntry*data,U n){U raw=0;if(idx.cached){if(idx.cached<data||idx.cached>=data+n)reject("B916 logical cache escaped table");raw=m.r32(index)+8u*static_cast<U>(idx.cached-data);}m.w32(index+16u,raw);}
 void flush(){flush_one(receiver+0x20u,root,root_row,1);flush_one(section_guest+0x2cu,section.keys,rows.data(),static_cast<U>(rows.size()));}
};
std::vector<std::uint8_t> read_text(Memory&m,U recv,U section,U key,U fallback,U cap,U key_count){
 IniGraph g(m,recv,section,key_count);auto s=ztext(m,section),k=ztext(m,key),d=ztext(m,fallback);std::vector<std::uint8_t> out(cap,0);
 const auto len=fun_0050ddf0(&g.root,s.data(),k.data(),d.data(),out.data(),static_cast<std::int32_t>(cap),g.ops);g.flush();
 if(len<0||static_cast<U>(len)>=cap)reject("B916 requires bounded successful string read");out.resize(static_cast<U>(len)+1u);return out;
}
std::uint8_t read_bool(Memory&m,U recv,U section,U key,std::uint8_t fallback,U count){IniGraph g(m,recv,section,count);auto s=ztext(m,section),k=ztext(m,key);const auto v=fun_0050e860(&g.root,s.data(),k.data(),fallback,g.ops);g.flush();return v;}
struct HexCtx{CrtClassification ctype;};
std::int32_t scan_cb(ScannerBuffer&s,const std::uint8_t*f,void*out,void*ctx){return scan_getter_hex32_callback(s,f,out,&static_cast<HexCtx*>(ctx)->ctype);}
std::int32_t classify(std::uint8_t b,std::uint32_t mask,void*ctx){auto&c=*static_cast<HexCtx*>(ctx);return c.ctype.flags_from_minus_one[b+1u]&mask;}
std::uint32_t read_hex(Memory&m,U recv,U section,U key,U fallback,U count){
 IniGraph g(m,recv,section,count);auto s=ztext(m,section),k=ztext(m,key);std::array<std::uint16_t,257> table{};const U ctype=m.r32(0x817560u)-2u;for(U n=0;n<257;++n)table[n]=static_cast<std::uint16_t>(m.r16(ctype+2u*n));HexCtx ctx{{1,table.data(),nullptr,nullptr}};GetterHexContext hctx{&ctx.ctype};
 IntegerReadOperations ops{g.ops,{classify,&ctx},lower,scan_cb,&hctx};const auto v=fun_0050cc40(&g.root,s.data(),k.data(),fallback,ops);g.flush();return v;
}
bool ieq(const std::vector<std::uint8_t>&a,const std::vector<std::uint8_t>&b){if(a.size()!=b.size())return false;for(U n=0;n<a.size();++n){auto x=a[n],y=b[n];if(x>='A'&&x<='Z')x=static_cast<std::uint8_t>(x+32);if(y>='A'&&y<='Z')y=static_cast<std::uint8_t>(y+32);if(x!=y)return false;}return true;}
void name_gate(Memory&m,const Inputs&i,U self,U owner_ini,U owner_count){
 const U alias=owner_ini+0x10000u,rt=alias+0x100u,section=alias+0x200u,kt=alias+0x300u,values=alias+0x380u;
 const U original_section=m.r32(m.r32(owner_ini+0x20u)+4u),original_kt=m.r32(original_section+0x2cu),original_count=m.r32(original_section+0x30u);
 std::array<U,2> value_ptr{};const U name_hash=ini_name_hash(reinterpret_cast<const std::uint8_t*>("Name"),4,nullptr),ui_hash=ini_name_hash(reinterpret_cast<const std::uint8_t*>("UIName"),6,nullptr);for(U n=0;n<original_count;++n){const U row=original_kt+8u*n,h=static_cast<U>(m.r32(row)),val=m.r32(row+4u);if(h==name_hash)value_ptr[0]=val;if(h==ui_hash)value_ptr[1]=val;}
 if(!value_ptr[0]||!value_ptr[1]||owner_count<2)reject("B916 Name/UIName real entries required for original text gate");
 std::vector<std::uint8_t> saved_alias(0x1000u);for(U n=0;n<saved_alias.size();++n)saved_alias[n]=static_cast<std::uint8_t>(m.r8(alias+n));
 const auto section_name=ztext(m,self+0x24u);const U section_hash=ini_name_hash(section_name.data(),section_name.size()-1u,nullptr);m.w32(alias+0x20u,rt);m.w32(alias+0x24u,1);m.w32(alias+0x28u,1);m.w8(alias+0x2cu,1);m.w32(alias+0x30u,0);
 m.w32(rt,section_hash);m.w32(rt+4u,section);m.w32(section+0x2cu,kt);m.w32(section+0x30u,2);m.w32(section+0x34u,2);m.w8(section+0x38u,1);m.w32(section+0x3cu,0);
 struct Row{U h;U val;};std::array<Row,2> rows{{{ini_name_hash(reinterpret_cast<const std::uint8_t*>("Name"),4,nullptr),value_ptr[0]},{ini_name_hash(reinterpret_cast<const std::uint8_t*>("UIName"),6,nullptr),value_ptr[1]}}};std::sort(rows.begin(),rows.end(),[](const Row&a,const Row&b){return global_b26::s32(a.h)<global_b26::s32(b.h);});for(U n=0;n<2;++n){m.w32(kt+8u*n,rows[n].h);m.w32(kt+8u*n+4u,rows[n].val);}
 Inputs nested=i;nested.cx=self;nested.arg[0]=alias;try{(void)text_b104::fun_004107e0(m,nested);}catch(const std::exception&e){for(U n=0;n<saved_alias.size();++n)m.w8(alias+n,saved_alias[n]);throw std::domain_error(std::string("B916 text gate: ")+e.what());}
 // The original routine leaves its last sorted-key cache at UIName. Project
 // that exact cache result back onto the actual 20-key INI graph.
 m.w32(owner_ini+0x20u+16u,m.r32(owner_ini+0x20u));for(U n=0;n<original_count;++n)if(m.r32(original_kt+8u*n)==ui_hash)m.w32(original_section+0x3cu,original_kt+8u*n);for(U n=0;n<saved_alias.size();++n)m.w8(alias+n,saved_alias[n]);
}
std::uint32_t resolve_string(Memory&m,const std::vector<std::uint8_t>&s){const U count=m.r32(0xab82a8u),rows=m.r32(0xab829cu);if(!count||count>32u||!rows)reject("B916 bounded initialized lookup table required");for(U n=0;n<count;++n){const U node=m.r32(rows+4u*n);if(!node)reject("B916 table node required");if(m.r32(node)!=0)reject("B916 excludes table callback target 0x405150");auto lit=ztext(m,0x7e33a4u);if(ieq(s,lit))return n;}return 0xffffffffu;}
std::uint32_t enum_index(Memory&m,const std::vector<std::uint8_t>&s){for(U n=0;n<11;++n){const U ptr=m.r32(0x788e28u+4u*n);if(ieq(s,ztext(m,ptr)))return n;}return 0;}
std::array<std::uint8_t,3> color_read(Memory&m,U recv,U section,U key,U input,U count){
 const auto fallback=std::array<std::uint8_t,3>{static_cast<std::uint8_t>(m.r8(input)),static_cast<std::uint8_t>(m.r8(input+1u)),static_cast<std::uint8_t>(m.r8(input+2u))};
 IniGraph g(m,recv,section,count);auto s=ztext(m,section),k=ztext(m,key);std::array<std::uint8_t,96> def{};auto fmt=std::to_string(fallback[0])+","+std::to_string(fallback[1])+","+std::to_string(fallback[2]);std::copy(fmt.begin(),fmt.end(),def.begin());std::array<std::uint8_t,96> out{};
 const auto len=fun_0050ddf0(&g.root,s.data(),k.data(),def.data(),out.data(),static_cast<std::int32_t>(out.size()),g.ops);g.flush();if(len<=0||static_cast<U>(len)>=out.size())reject("B916 valid color tuple required");
 std::array<std::uint8_t,3> parsed{};const char*begin=reinterpret_cast<const char*>(out.data());const char*end=begin+len;for(U n=0;n<3;++n){unsigned v=0;auto r=std::from_chars(begin,end,v);if(r.ec!=std::errc{}||v>255u)reject("B916 color components must be complete 0..255 decimal");parsed[n]=static_cast<std::uint8_t>(v);begin=r.ptr;if(n<2){if(begin==end||*begin!=',')reject("B916 comma color tuple required");++begin;}}if(begin!=end)reject("B916 excludes color trailing bytes");return parsed;
}
}
U fun_005cfea0(Memory&m,const Inputs&i){
 const char* stage="entry";try{
 const U self=i.cx,owner_ini=i.arg[0],owner_section=self+0x24u,art_section=self+0x1c8u,art_ini=0x821b30u;
 if(!self||!owner_ini||!m.r8(owner_section)||!m.r8(art_section))reject("B916 positive nonempty owner/art sections required");
 stage="name gate";name_gate(m,i,self,owner_ini,20u);
 constexpr U owner_n=20,art_n=6;
 // Original string reads execute in order and preserve both index caches.
 stage="Image query";auto image=read_text(m,owner_ini,owner_section,0x7bad74u,self+0x1c8u,25,owner_n);
 if(image.size()>25u)reject("B916 Image must fit original 25-byte destination span");for(U n=0;n<25;++n)m.w8(self+0x1c8u+n,n<image.size()?image[n]:0);
 stage="AlphaImage query";auto alpha=read_text(m,owner_ini,owner_section,0x7d2390u,self+0x1e3u,25,owner_n);
 if(alpha.size()>25u)reject("B916 AlphaImage must fit original 25-byte destination span");for(U n=0;n<25;++n)m.w8(self+0x1e3u+n,n<alpha.size()?alpha[n]:0);
 stage="CrushSound query";auto crush=read_text(m,owner_ini,owner_section,0x7d2384u,0x8248a4u,128,owner_n);
 stage="AmbientSound query";auto ambient=read_text(m,owner_ini,owner_section,0x7d2374u,0x8248a4u,128,owner_n);
 stage="sound lookup";const U crush_index=resolve_string(m,crush),ambient_index=resolve_string(m,ambient);if(crush_index!=0xffffffffu)m.w32(self+0x1c0u,crush_index);if(ambient_index!=0xffffffffu)m.w32(self+0x1c4u,ambient_index);
 stage="owner flags";const auto setb=[&](U off,U key,std::uint8_t fallback){m.w8(self+off,read_bool(m,owner_ini,owner_section,key,fallback,owner_n));};
 setb(0x1fdu,0x7d2368u,static_cast<std::uint8_t>(m.r8(self+0x1fdu)));
 setb(0x1feu,0x7d235cu,static_cast<std::uint8_t>(m.r8(self+0x1feu)));
 setb(0x1b8u,0x7d2350u,static_cast<std::uint8_t>(m.r8(self+0x1b8u)));
 setb(0x1e1u,0x7d233cu,static_cast<std::uint8_t>(m.r8(self+0x1e1u)));
 setb(0x1ffu,0x7d232cu,static_cast<std::uint8_t>(m.r8(self+0x1ffu)));
 setb(0x200u,0x7d2320u,static_cast<std::uint8_t>(m.r8(self+0x200u)));
 setb(0x201u,0x7d2314u,static_cast<std::uint8_t>(m.r8(self+0x201u)));
 stage="Armor query";const U armor_default=m.r32(0x788e28u+4u*m.r32(self+0x9cu));
 if(m.r32(self+0x9cu)>10u)reject("B916 Armor default index outside original enum table");
 m.w32(self+0x9cu,enum_index(m,read_text(m,owner_ini,owner_section,0x7be958u,armor_default,128,owner_n)));
 stage="Strength query";m.w32(self+0xa0u,read_hex(m,owner_ini,owner_section,0x7d2308u,m.r32(self+0xa0u),owner_n));
 setb(0x203u,0x7d2300u,static_cast<std::uint8_t>(m.r8(self+0x203u)));
 setb(0x202u,0x7d22f0u,static_cast<std::uint8_t>(m.r8(self+0x202u)));
 setb(0x208u,0x7d22dcu,static_cast<std::uint8_t>(m.r8(self+0x208u)));
 stage="RadialColor query";auto radial=color_read(m,owner_ini,owner_section,0x7d22d0u,self+0x98u,owner_n);for(U n=0;n<3;++n)m.w8(self+0x98u+n,radial[n]);
 setb(0x209u,0x7d22bcu,static_cast<std::uint8_t>(m.r8(self+0x209u)));
 m.w8(self+0x20au,read_bool(m,art_ini,art_section,0x7d22acu,static_cast<std::uint8_t>(m.r8(self+0x20au)),art_n));
 
 stage="LineTrailColor query";auto trail=color_read(m,art_ini,art_section,0x7d229cu,self+0x20bu,art_n);for(U n=0;n<3;++n)m.w8(self+0x20bu+n,trail[n]);
 stage="LineTrailColorDecrement query";m.w32(self+0x210u,read_hex(m,art_ini,art_section,0x7d2284u,m.r32(self+0x210u),art_n));
stage="Theater query";m.w8(self+0x1fcu,read_bool(m,art_ini,art_section,0x7b9f94u,static_cast<std::uint8_t>(m.r8(self+0x1fcu)),art_n));
 stage="NewTheater query";m.w8(self+0x207u,read_bool(m,art_ini,art_section,0x7b9f88u,static_cast<std::uint8_t>(m.r8(self+0x207u)),art_n));
 stage="Voxel query";m.w8(self+0x206u,read_bool(m,art_ini,art_section,0x7d227cu,static_cast<std::uint8_t>(m.r8(self+0x206u)),art_n));
 if(!m.r8(self+0x206u))reject("B916 bounded route requires parsed +0x206 true to skip nested child root");
 const auto basename=ztext(m,self+0x1e3u,32);if(basename.size()<2||basename.size()>25)reject("B916 nonempty bounded .SHP name required");
 std::string path;for(U n=0;n+1<basename.size();++n){auto c=static_cast<char>(basename[n]);if(c>='a'&&c<='z')c=static_cast<char>(c-('a'-'A'));path.push_back(c);}path += ".SHP";
 if(path!="PBEACON.SHP")reject("B916 bounded authenticated B187 cache key is PBEACON.SHP");
 // B907's authenticated positive 0x5928a0 cache model is reproduced by reading
 // the same original manager and signed-sorted 12-byte row graph.
 stage="cache lookup";const U manager=m.r32(0xa588e0u),count=m.r32(manager+0x14u),table=m.r32(manager+0x20u);if(!manager||!m.r32(manager+4u)||!m.r32(manager+8u)||count!=1||!table||m.r8(0xb10530u)!=0)reject("B916 requires B907 one-row C-mode cache fixture");
 const U backing=m.r32(manager+0x24u),offset=m.r32(table+4u),resource=backing+offset;if(!backing||m.r32(table)!=0xa281add0u)reject("B916 requires original PBEACON.SHP cache hash");
 m.w32(self+0xacu,resource);
 return (resource&0xffffff00u)|1u;
 }catch(const std::exception&e){throw std::domain_error(std::string("B916 ")+stage+": "+e.what());}
}
}

