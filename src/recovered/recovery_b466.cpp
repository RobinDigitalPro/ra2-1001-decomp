#include "recovered/recovery_b466.hpp"
#include "recovered/ini_bulk.hpp"
#include "recovered/ini_integer.hpp"
#include "recovered/ini_text.hpp"
#include "recovered/ini_multi.hpp"
#include "recovered/name_hash.hpp"
#include "recovered/lookup_b100.hpp"
#include "recovered/lookup_b92.hpp"
#include "recovered/recovery_b381.hpp"
#include "recovered/crt_classify.hpp"
#include "recovered/decimal_text.hpp"
#include "recovered/scanner_input.hpp"
#include "recovered/text_scan.hpp"
#include "recovered/crt_b83.hpp"
#include "recovered/leaf_memory.hpp"
#include "platform/x87_extended_b40.hpp"
#include <array>
#include <memory>
#include <stdexcept>
#include <vector>

namespace ra2::recovered::recovery_b466 {
namespace {
using U=std::uint32_t;
using namespace ra2::recovered;
void need(bool ok,const char*why){if(!ok)throw std::domain_error(why);}
std::vector<std::uint8_t> text(const Memory&m,U p){
 need(p!=0,"B466 requires nonnull bounded text");std::vector<std::uint8_t>v;
 for(unsigned n=0;n<128;++n){auto c=static_cast<std::uint8_t>(m.r8(p+n));v.push_back(c);if(!c)return v;}
 throw std::domain_error("B466 text exceeds 128-byte route bound");
}
std::int32_t no_upper(std::int32_t c,void*){return c>='a'&&c<='z'?c-('a'-'A'):c;}
void no_sort(IniIndexEntry*,std::int32_t,IniIndexKind,void*){throw std::domain_error("B466 requires pre-sorted original INI indices");}
std::uint32_t hash_cb(const std::uint8_t*p,std::size_t n,void*){return ini_name_hash(p,n,nullptr);}
std::uint32_t hash_text(const std::vector<std::uint8_t>&v){std::size_t n=0;while(n<v.size()&&v[n])++n;return ini_name_hash(v.data(),n,nullptr);}
std::int32_t classify(std::uint8_t b,U mask,void*p){
 const auto& c=*static_cast<CrtClassification*>(p);
 return static_cast<std::int32_t>(c.flags_from_minus_one[b+1]&mask);
}
std::int32_t lower(std::int32_t c,void*){return c>='A'&&c<='Z'?c+('a'-'A'):c;}
struct Context{std::array<std::uint16_t,257> flags{};CrtClassification ctype{};GetterHexContext hex{};};
void init_context(Memory&m,Context&c){
 const U table=m.r32(0x817560u)-2u;
 for(unsigned n=0;n<257;++n)c.flags[n]=static_cast<std::uint16_t>(m.r16(table+2u*n));
 c.ctype={1,c.flags.data(),nullptr,nullptr};c.hex={&c.ctype};
}
IntegerReadOperations int_ops(const IniOperations&lookup,Context&c){
 return {lookup,{classify,&c.ctype},lower,scan_getter_hex32_callback,&c.hex};
}
struct Key {IniValue value{};std::vector<std::uint8_t> bytes;};
struct Section {U guest{};IniSection value{};std::vector<IniIndexEntry> nodes;std::vector<std::unique_ptr<Key>> keys;};
class Projection{
 Memory&m_;U guest_{};IniIndex root_{};std::vector<IniIndexEntry> sections_;std::vector<std::unique_ptr<Section>> local_sections_;IniOperations ops_{};
 Section* find(U p){for(auto&s:local_sections_)if(s->guest==p)return s.get();return nullptr;}
 void load_section(U p){
  if(find(p))return;
  auto s=std::make_unique<Section>();s->guest=p;const U idx=p+0x2cu,count=m_.r32(idx+4u),rows=m_.r32(idx);
  need(count>0&&count<=32&&rows&&m_.r8(idx+12u)!=0&&m_.r32(idx+8u)>=count,"B466 finite positive key index required");
  s->nodes.resize(count);s->keys.reserve(count);
  for(U k=0;k<count;++k){const U row=rows+8u*k;const U vp=m_.r32(row+4u),tp=m_.r32(vp+0x10u);auto key=std::make_unique<Key>();
   key->bytes=text(m_,tp);key->value.text=key->bytes.data();s->nodes[k]={global_b26::s32(m_.r32(row)),&key->value};
   if(k)need(s->nodes[k-1].key<s->nodes[k].key,"B466 key rows must be unique signed-sorted hits");s->keys.push_back(std::move(key));}
  s->value.keys={s->nodes.data(),static_cast<std::int32_t>(count),1,nullptr,count};
  const U cached=m_.r32(idx+16u);if(cached){need(cached>=rows&&(cached-rows)%8u==0&&(cached-rows)/8u<count,"B466 key cache must name a raw node");s->value.keys.cached=&s->nodes[(cached-rows)/8u];}
  local_sections_.push_back(std::move(s));
 }
public:
 Projection(Memory&m,U ini):m_(m),guest_(ini){
  need(ini!=0,"B466 nonnull INI receiver required");const U idx=ini+0x20u,count=m.r32(idx+4u),rows=m.r32(idx);
  need(count>0&&count<=8&&rows&&m.r8(idx+12u)!=0&&m.r32(idx+8u)>=count,"B466 finite positive section index required");
  sections_.resize(count);local_sections_.reserve(count);
  for(U k=0;k<count;++k){const U row=rows+8u*k,p=m.r32(row+4u);load_section(p);sections_[k]={global_b26::s32(m.r32(row)),&find(p)->value};
   if(k)need(sections_[k-1].key<sections_[k].key,"B466 section rows must be unique signed-sorted hits");}
  root_={sections_.data(),static_cast<std::int32_t>(count),1,nullptr,count};
  const U cached=m.r32(idx+16u);if(cached){need(cached>=rows&&(cached-rows)%8u==0&&(cached-rows)/8u<count,"B466 section cache must name a raw node");root_.cached=&sections_[(cached-rows)/8u];}
  ops_={hash_cb,no_sort,no_upper,nullptr,nullptr,nullptr};
 }
 IniIndex&root(){return root_;}const IniOperations&ops()const{return ops_;}
 void refresh(){
  const U idx=guest_+0x20u,rows=m_.r32(idx),cached=m_.r32(idx+16u);root_.cached=nullptr;
  if(cached){need(cached>=rows&&(cached-rows)%8u==0&&(cached-rows)/8u<sections_.size(),"B466 raw section cache escaped index");root_.cached=&sections_[(cached-rows)/8u];}
  for(auto&s:local_sections_){const U ki=s->guest+0x2cu,kr=m_.r32(ki),kc=m_.r32(ki+16u);s->value.keys.cached=nullptr;
   if(kc){need(kc>=kr&&(kc-kr)%8u==0&&(kc-kr)/8u<s->nodes.size(),"B466 raw key cache escaped index");s->value.keys.cached=&s->nodes[(kc-kr)/8u];}}
 }
 void flush(){
  const U ri=guest_+0x20u,rr=m_.r32(ri);m_.w32(ri+16u,root_.cached?rr+8u*static_cast<U>(root_.cached-sections_.data()):0u);
  for(auto&s:local_sections_){const U ki=s->guest+0x2cu,kr=m_.r32(ki);m_.w32(ki+16u,s->value.keys.cached?kr+8u*static_cast<U>(s->value.keys.cached-s->nodes.data()):0u);}
 }
};
U read_int(Memory&m,Projection&g,Context&c,U section,U key,U fallback){auto s=text(m,section),k=text(m,key);const U v=fun_0050cc40(&g.root(),s.data(),k.data(),fallback,int_ops(g.ops(),c));g.flush();return v;}
U read_bool(Memory&m,Projection&g,U section,U key,U fallback){auto s=text(m,section),k=text(m,key);const U v=fun_0050e860(&g.root(),s.data(),k.data(),static_cast<std::uint8_t>(fallback),g.ops());g.flush();return v;}
U read_double(Memory&m,Projection&g,const Inputs&outer,U ini,U section,U key,U dst){
 Inputs nested=outer;nested.cx=ini;nested.arg[0]=section;nested.arg[1]=key;nested.arg[2]=m.r32(dst);nested.arg[3]=m.r32(dst+4u);
 (void)recovery_b381::fun_0050d7f0(m,nested);outer.fp=nested.fp;g.refresh();
 const auto bits=outer.fp.pop64();floating_b61::write64(m,dst,bits);return 0;
}
bool present(Memory&m,Projection&g,U section){auto s=text(m,section);const auto found=fun_0050be00(&g.root(),s.data(),g.ops());g.flush();return found!=nullptr;}
U enum_value(Memory&m,U p){
 const U first=0x00788e54u,last=0x00788ea0u;
 for(U k=0;k<(last-first)/4u;++k){Inputs q{};q.arg[0]=p;q.arg[1]=m.r32(first+4u*k);if(crt_b83::fun_0076d860(m,q)==0)return k;}
 return 0;
}

}

namespace {
U read_enum_field(Memory&m,Projection&g,U section,U key,U fallback){
 auto s=text(m,section),k=text(m,key),fb=text(m,0x8248a4u);std::array<std::uint8_t,128> out{};
 const U length=static_cast<U>(fun_0050ddf0(&g.root(),s.data(),k.data(),fb.data(),out.data(),static_cast<std::int32_t>(out.size()),g.ops()));g.flush();
 if(!length)return fallback;
 constexpr U out_base=0x7f100000u;leaf::Memory span(out.data(),out_base,static_cast<std::uint32_t>(out.size()));Memory extended=m;extended.add(span);
 return enum_value(extended,out_base);
}
U read_list(Memory&m,Projection&g,U section,U key){
 auto s=text(m,section),k=text(m,key),fb=text(m,0x8248a4u);std::array<std::uint8_t,128> out{};
 const U length=static_cast<U>(fun_0050ddf0(&g.root(),s.data(),k.data(),fb.data(),out.data(),static_cast<std::int32_t>(out.size()),g.ops()));g.flush();
 need(length!=0,"B466 requires present list name");
 constexpr U out_base=0x7f100100u;leaf::Memory span(out.data(),out_base,static_cast<std::uint32_t>(out.size()));Memory extended=m;extended.add(span);
 const U count=m.r32(0xab82a8u),table=m.r32(0xab829cu);
 for(U n=0;n<count;++n){const U record=m.r32(table+4u*n);const U candidate=record?(m.r32(record)==0?0x7e33a4u:(m.r32(0x8192f8u)==0?0x7b7c64u:m.r32(record)+0x6cu)):0u;Inputs q{};q.arg[0]=candidate;q.arg[1]=out_base;if(candidate&&crt_b83::fun_0076d860(extended,q)==0)return n;}
 throw std::domain_error("B466 requires matching list name");
}
U read_scaled(Memory&m,Projection&g,const Inputs&i,U ini,U section,U key,U fallback){
 Inputs nested=i;nested.cx=ini;nested.arg[0]=section;nested.arg[1]=key;nested.arg[2]=0u;nested.arg[3]=0xbff00000u;
 (void)recovery_b381::fun_0050d7f0(m,nested);
 auto& fp=i.fp;fp=nested.fp;
 const std::uint64_t threshold=std::uint64_t(m.r32(0x788578u+4u))<<32|m.r32(0x788578u);
 const std::uint64_t scale=std::uint64_t(m.r32(0x785700u+4u))<<32|m.r32(0x785700u);
 ra2::platform::x87_extended::compare64(fp,threshold);
 if(fp.status()&0x4000u){(void)fp.pop64();return fallback;}
 fp.multiply64(scale);
 const auto control=static_cast<std::uint16_t>(m.r16(0x7c3a04u));
 if(fp.control()!=control)fp.load_control_masked(control);
 return static_cast<U>(fp.pop_integer64());
}
U read_resource(Memory&m,Projection&g,U section,U key){
 auto s=text(m,section),k=text(m,key),fb=text(m,0x8248a4u);std::array<std::uint8_t,128> out{};
 const U length=static_cast<U>(fun_0050ddf0(&g.root(),s.data(),k.data(),fb.data(),out.data(),static_cast<std::int32_t>(out.size()),g.ops()));g.flush();
 need(length!=0,"B466 requires present resource name");
 constexpr U out_base=0x7f100200u;leaf::Memory span(out.data(),out_base,static_cast<std::uint32_t>(out.size()));Memory extended=m;extended.add(span);Inputs q{};q.cx=out_base;return lookup_b92::fun_00700100(extended,q);
}
U read_name_resource(Memory&m,Projection&g,U section,U key){
 auto s=text(m,section),k=text(m,key),fb=text(m,0x8248a4u);std::array<std::uint8_t,128> out{};
 const U length=static_cast<U>(fun_0050ddf0(&g.root(),s.data(),k.data(),fb.data(),out.data(),static_cast<std::int32_t>(out.size()),g.ops()));g.flush();
 need(length!=0,"B466 requires present name-resource name");
 constexpr U out_base=0x7f100300u;leaf::Memory span(out.data(),out_base,static_cast<std::uint32_t>(out.size()));Memory extended=m;extended.add(span);Inputs q{};q.cx=out_base;return lookup_b100::fun_005d55f0(extended,q);
}
}

std::uint32_t fun_0063da60(Memory&m,const Inputs&i){
 const U receiver=i.cx,ini=i.arg[0],section=m.r32(0x793ee8u);Projection graph(m,ini);
 need(present(m,graph,section),"B466 requires present section");
 Context ctx{};init_context(m,ctx);
 auto get32=[&](U off){return m.r32(receiver+off);};
 m.w8(receiver+0x4cu,static_cast<std::uint8_t>(read_bool(m,graph,section,0x7d9694u,m.r8(receiver+0x4cu))));
 for(const auto [key,off]:std::array<std::pair<U,U>,3>{{{0x7d9684u,0xf0u},{0x7d9678u,0xf4u},{0x7d9668u,0xf8u}}})m.w32(receiver+off,read_name_resource(m,graph,section,key));
 m.w32(receiver+0x638u,read_list(m,graph,section,0x7d9658u));
 m.w32(receiver+0x10d8u,read_int(m,graph,ctx,section,0x7d9648u,get32(0x10d8u)));
 m.w32(receiver+0x10dcu,read_int(m,graph,ctx,section,0x7d9638u,get32(0x10dcu)));
 m.w32(receiver+0x1394u,read_scaled(m,graph,i,ini,section,0x7d962cu,get32(0x1394u)));
 (void)read_double(m,graph,i,ini,section,0x7d9620u,receiver+0x12d8u);
 m.w32(receiver+0xe20u,read_resource(m,graph,section,0x7d9610u));
 m.w32(receiver+0xe18u,read_int(m,graph,ctx,section,0x7d9600u,get32(0xe18u)));
 m.w32(receiver+0x10ccu,read_enum_field(m,graph,section,0x7d95f4u,get32(0x10ccu)));
 m.w32(receiver+0x10d0u,read_enum_field(m,graph,section,0x7d95e8u,get32(0x10d0u)));
 const U last=read_enum_field(m,graph,section,0x7d95dcu,get32(0x10d4u));m.w32(receiver+0x10d4u,last);
 return floating_b61::with_al(last,1u);
}
}
