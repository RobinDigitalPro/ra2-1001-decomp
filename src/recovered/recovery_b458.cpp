#include "recovered/recovery_b458.hpp"
#include "recovered/ini_bulk.hpp"
#include "recovered/ini_integer.hpp"
#include "recovered/ini_text.hpp"
#include "recovered/ini_multi.hpp"
#include "recovered/name_hash.hpp"
#include "recovered/lookup_b100.hpp"
#include "recovered/recovery_b381.hpp"
#include "recovered/crt_classify.hpp"
#include "recovered/decimal_text.hpp"
#include "recovered/scanner_input.hpp"
#include "recovered/text_scan.hpp"
#include "recovered/leaf_memory.hpp"
#include <array>
#include <memory>
#include <stdexcept>
#include <vector>

namespace ra2::recovered::recovery_b458 {
namespace {
using U=std::uint32_t;
using namespace ra2::recovered;
void need(bool ok,const char*why){if(!ok)throw std::domain_error(why);}
std::vector<std::uint8_t> text(const Memory&m,U p){
 need(p!=0,"B458 requires nonnull bounded text");std::vector<std::uint8_t>v;
 for(unsigned n=0;n<128;++n){auto c=static_cast<std::uint8_t>(m.r8(p+n));v.push_back(c);if(!c)return v;}
 throw std::domain_error("B458 text exceeds 128-byte route bound");
}
std::int32_t no_upper(std::int32_t c,void*){return c>='a'&&c<='z'?c-('a'-'A'):c;}
void no_sort(IniIndexEntry*,std::int32_t,IniIndexKind,void*){throw std::domain_error("B458 requires pre-sorted original INI indices");}
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
  need(count>0&&count<=32&&rows&&m_.r8(idx+12u)!=0&&m_.r32(idx+8u)>=count,"B458 finite positive key index required");
  s->nodes.resize(count);s->keys.reserve(count);
  for(U k=0;k<count;++k){const U row=rows+8u*k;const U vp=m_.r32(row+4u),tp=m_.r32(vp+0x10u);auto key=std::make_unique<Key>();
   key->bytes=text(m_,tp);key->value.text=key->bytes.data();s->nodes[k]={global_b26::s32(m_.r32(row)),&key->value};
   if(k)need(s->nodes[k-1].key<s->nodes[k].key,"B458 key rows must be unique signed-sorted hits");s->keys.push_back(std::move(key));}
  s->value.keys={s->nodes.data(),static_cast<std::int32_t>(count),1,nullptr,count};
  const U cached=m_.r32(idx+16u);if(cached){need(cached>=rows&&(cached-rows)%8u==0&&(cached-rows)/8u<count,"B458 key cache must name a raw node");s->value.keys.cached=&s->nodes[(cached-rows)/8u];}
  local_sections_.push_back(std::move(s));
 }
public:
 Projection(Memory&m,U ini):m_(m),guest_(ini){
  need(ini!=0,"B458 nonnull INI receiver required");const U idx=ini+0x20u,count=m.r32(idx+4u),rows=m.r32(idx);
  need(count>0&&count<=8&&rows&&m.r8(idx+12u)!=0&&m.r32(idx+8u)>=count,"B458 finite positive section index required");
  sections_.resize(count);local_sections_.reserve(count);
  for(U k=0;k<count;++k){const U row=rows+8u*k,p=m.r32(row+4u);load_section(p);sections_[k]={global_b26::s32(m.r32(row)),&find(p)->value};
   if(k)need(sections_[k-1].key<sections_[k].key,"B458 section rows must be unique signed-sorted hits");}
  root_={sections_.data(),static_cast<std::int32_t>(count),1,nullptr,count};
  const U cached=m.r32(idx+16u);if(cached){need(cached>=rows&&(cached-rows)%8u==0&&(cached-rows)/8u<count,"B458 section cache must name a raw node");root_.cached=&sections_[(cached-rows)/8u];}
  ops_={hash_cb,no_sort,no_upper,nullptr,nullptr,nullptr};
 }
 IniIndex&root(){return root_;}const IniOperations&ops()const{return ops_;}
 void refresh(){
  const U idx=guest_+0x20u,rows=m_.r32(idx),cached=m_.r32(idx+16u);root_.cached=nullptr;
  if(cached){need(cached>=rows&&(cached-rows)%8u==0&&(cached-rows)/8u<sections_.size(),"B458 raw section cache escaped index");root_.cached=&sections_[(cached-rows)/8u];}
  for(auto&s:local_sections_){const U ki=s->guest+0x2cu,kr=m_.r32(ki),kc=m_.r32(ki+16u);s->value.keys.cached=nullptr;
   if(kc){need(kc>=kr&&(kc-kr)%8u==0&&(kc-kr)/8u<s->nodes.size(),"B458 raw key cache escaped index");s->value.keys.cached=&s->nodes[(kc-kr)/8u];}}
 }
 void flush(){
  const U ri=guest_+0x20u,rr=m_.r32(ri);m_.w32(ri+16u,root_.cached?rr+8u*static_cast<U>(root_.cached-sections_.data()):0u);
  for(auto&s:local_sections_){const U ki=s->guest+0x2cu,kr=m_.r32(ki);m_.w32(ki+16u,s->value.keys.cached?kr+8u*static_cast<U>(s->value.keys.cached-s->nodes.data()):0u);}
 }
};
U read_int(Memory&m,Projection&g,Context&c,U section,U key,U fallback){auto s=text(m,section),k=text(m,key);const U v=fun_0050cc40(&g.root(),s.data(),k.data(),fallback,int_ops(g.ops(),c));g.flush();return v;}
U read_double(Memory&m,Projection&g,const Inputs&outer,U ini,U section,U key,U dst){
 Inputs nested=outer;nested.cx=ini;nested.arg[0]=section;nested.arg[1]=key;nested.arg[2]=m.r32(dst);nested.arg[3]=m.r32(dst+4u);
 (void)recovery_b381::fun_0050d7f0(m,nested);outer.fp=nested.fp;g.refresh();
 const auto bits=outer.fp.pop64();floating_b61::write64(m,dst,bits);return 0;
}
bool present(Memory&m,Projection&g,U section){auto s=text(m,section);const auto found=fun_0050be00(&g.root(),s.data(),g.ops());g.flush();return found!=nullptr;}
void parse_color(Memory&m,Projection&g,Context&ctx,U section,U key,U fallback,U scanout){
 // This caller's pinned key is "RadColor". B324's separately accepted finite
 // fixture pins "RadialColor", so compose its reached getter/scanner primitives
 // directly rather than asserting the different helper key contract.
 auto section_text=text(m,section),key_text=text(m,key),fallback_text=text(m,fallback);
 std::array<std::uint8_t,64> selected{};
 const U count=static_cast<U>(fun_0050ddf0(&g.root(),section_text.data(),key_text.data(),fallback_text.data(),selected.data(),static_cast<std::int32_t>(selected.size()),g.ops()));g.flush();
 need(count!=0,"B458 positive RadColor requires present nonempty text");
 DecimalFieldOutputs fields{};std::array<U,3> values{};
 fields.fields[0]=&values[0];fields.fields[1]=&values[1];fields.fields[2]=&values[2];
 GetterDecimalContext decimal{&ctx.ctype};
 static constexpr std::uint8_t format[]="%d,%d,%d";
 need(m.r8(0x7ba2f0u)=='%'&&m.r8(0x7ba2f1u)=='d'&&m.r8(0x7ba2f8u)==0,"B458 original RadColor scan format");
 const U assigned=static_cast<U>(fun_0076f070(selected.data(),format,&fields,
     scan_getter_decimal_callback,&decimal));
 need(assigned==3,"B458 RadColor bounded decimal triplet must assign three fields");
 for(unsigned n=0;n<3;++n){need(values[n]<=255u,"B458 RadColor byte field range");m.w8(scanout+n,static_cast<std::uint8_t>(values[n]));}
}
}

std::uint32_t fun_0063ec10(Memory&m,const Inputs&i){
 const U receiver=i.cx,ini=i.arg[0],section=m.r32(0x793ef0u);Projection graph(m,ini);
 need(present(m,graph,section),"B458 requires present Radiation section");
 Context ctx{};init_context(m,ctx);
 struct I{U key,offset;};static constexpr I ints[]={{0x7d9b28,0x1448},{0x7d9b14,0x144c},{0x7d9b08,0x1450},{0x7d9af8,0x1454},{0x7d9ae8,0x1458}};
 for(auto f:ints)m.w32(receiver+f.offset,read_int(m,graph,ctx,section,f.key,m.r32(receiver+f.offset)));
 static constexpr U floats[]={0x7d9ad8,0x7d9ac8,0x7d9ab8};
 for(unsigned n=0;n<3;++n)(void)read_double(m,graph,i,ini,section,floats[n],receiver+0x1460u+8u*n);
 // Keep local scanner outputs outside the actual guest arena.
 std::array<std::uint8_t,64> scratch{};constexpr U scratch_base=0x7f000000u;leaf::Memory scratch_span(scratch.data(),scratch_base,scratch.size());
 Memory extended=m;extended.add(scratch_span);
 std::array<std::uint8_t,32> fallback{};constexpr U fallback_base=0x7f000100u;leaf::Memory fallback_span(fallback.data(),fallback_base,fallback.size());extended.add(fallback_span);
 const U initial[3]={m.r8(receiver+0x1478u),m.r8(receiver+0x1479u),m.r8(receiver+0x147au)};
 unsigned at=0;for(unsigned field=0;field<3;++field){if(field)fallback[at++]=',';const U v=initial[field];if(v>=100)fallback[at++]=static_cast<std::uint8_t>('0'+v/100);if(v>=10)fallback[at++]=static_cast<std::uint8_t>('0'+(v/10)%10);fallback[at++]=static_cast<std::uint8_t>('0'+v%10);}fallback[at]=0;
 parse_color(extended,graph,ctx,section,0x7d9aacu,fallback_base,receiver+0x1478u);
 std::array<std::uint8_t,128> name{};constexpr U name_base=0x7f001000u;leaf::Memory name_span(name.data(),name_base,name.size());extended.add(name_span);
 auto section_text=text(extended,section),name_key=text(extended,0x7d9a9cu),fallback_text=text(extended,0x8248a4u);
 (void)fun_0050ddf0(&graph.root(),section_text.data(),name_key.data(),fallback_text.data(),name.data(),static_cast<std::int32_t>(name.size()),graph.ops());graph.flush();
 for(unsigned n=0;n<name.size();++n)extended.w8(name_base+n,name[n]);
 need(m.r32(0x821e50u)==1u,"B458 one populated resource table record");
 const U record=m.r32(m.r32(0x821e44u));
 need(record!=0&&name[0]!=0,"B458 positive resource name and record");
 for(unsigned k=0;k<name.size();++k){need(m.r8(record+0x24u+k)==name[k],"B458 matching inline resource name");if(!name[k])break;}
 Inputs lookup{};lookup.cx=name_base;const U previous=lookup_b100::fun_00715af0(extended,lookup);
 m.w32(receiver+0x147cu,previous);return floating_b61::with_al(previous,1u);
}
}
