#include "recovered/recovery_b474.hpp"
#include "recovered/ini_bulk.hpp"
#include "recovered/ini_integer.hpp"
#include "recovered/ini_text.hpp"
#include "recovered/ini_lookup.hpp"
#include "recovered/name_hash.hpp"
#include "recovered/text_bytes.hpp"
#include "recovered/crt_classify.hpp"
#include "recovered/decimal_text.hpp"
#include "recovered/recovery_b109.hpp"
#include "recovered/leaf_memory.hpp"
#include "platform/current_crt_thread.hpp"
#include <algorithm>
#include <array>
#include <memory>
#include <cstdio>
#include <stdexcept>
#include <string>
#include <vector>

namespace ra2::recovered::recovery_b474 {
namespace {
using U=std::uint32_t;
using namespace ra2::recovered;
[[noreturn]] void reject(const char*why){throw std::domain_error(why);}
void need(bool ok,const char*why){if(!ok)reject(why);}
std::vector<std::uint8_t> ztext(const Memory&m,U p,U limit=128u){
 if(!p)reject("B474 requires nonnull bounded text");std::vector<std::uint8_t>v;
 for(U n=0;n<limit;++n){const auto c=static_cast<std::uint8_t>(m.r8(p+n));v.push_back(c);if(!c)return v;}
 reject("B474 text exceeds finite bound");
}
std::uint32_t hash_cb(const std::uint8_t*p,std::size_t n,void*){return ini_name_hash(p,n,nullptr);}
std::int32_t upper_cb(std::int32_t c,void*){return c>='a'&&c<='z'?c-('a'-'A'):c;}
void no_sort(IniIndexEntry*,std::int32_t,IniIndexKind,void*){reject("B474 requires sorted original INI indices");}
struct KV{IniValue value{};std::vector<std::uint8_t>text;};
struct Sec{U guest{};IniSection value{};std::vector<IniIndexEntry>nodes;std::vector<std::unique_ptr<KV>>keys;};
class Projection{
 Memory&m_;U guest_{};IniIndex root_{};std::vector<IniIndexEntry>sections_;std::vector<std::unique_ptr<Sec>>local_;IniOperations ops_{};
 Sec*find(U p){for(auto&s:local_)if(s->guest==p)return s.get();return nullptr;}
 void load(U p){if(find(p))return;auto s=std::make_unique<Sec>();s->guest=p;const U idx=p+0x2c,count=m_.r32(idx+4),rows=m_.r32(idx);
  need(count>0&&count<=32&&rows&&m_.r8(idx+12)!=0&&m_.r32(idx+8)>=count,"B474 requires initialized sorted key graph");
  s->nodes.resize(count);s->keys.reserve(count);
  for(U k=0;k<count;++k){const U row=rows+8*k,vp=m_.r32(row+4),tp=m_.r32(vp+0x10);auto x=std::make_unique<KV>();x->text=ztext(m_,tp);x->value.text=x->text.data();s->nodes[k]={global_b26::s32(m_.r32(row)),&x->value};if(k)need(s->nodes[k-1].key<s->nodes[k].key,"B474 keys must be unique signed-sorted hashes");s->keys.push_back(std::move(x));}
  s->value.keys={s->nodes.data(),static_cast<std::int32_t>(count),1,nullptr,count};const U cache=m_.r32(idx+16);if(cache){need(cache>=rows&&(cache-rows)%8==0&&(cache-rows)/8<count,"B474 key cache outside raw table");s->value.keys.cached=&s->nodes[(cache-rows)/8];}local_.push_back(std::move(s));
 }
public:
 Projection(Memory&m,U ini):m_(m),guest_(ini){need(ini,"B474 requires INI object");const U idx=ini+0x20,count=m.r32(idx+4),rows=m.r32(idx);need(count==1&&rows&&m.r8(idx+12)!=0&&m.r32(idx+8)>=count,"B474 supports the one-section indexed root");sections_.resize(count);local_.reserve(count);for(U k=0;k<count;++k){const U row=rows+8*k,p=m.r32(row+4);load(p);sections_[k]={global_b26::s32(m.r32(row)),&find(p)->value};if(k)need(sections_[k-1].key<sections_[k].key,"B474 section hashes must be sorted");}root_={sections_.data(),static_cast<std::int32_t>(count),1,nullptr,count};const U cache=m.r32(idx+16);if(cache){need(cache==rows,"B474 section cache outside its one-row index");root_.cached=&sections_[0];}ops_={hash_cb,no_sort,upper_cb,nullptr,nullptr,nullptr};}
 IniIndex&root(){return root_;}const IniOperations&ops()const{return ops_;}
 void flush(){const U idx=guest_+0x20,rows=m_.r32(idx);m_.w32(idx+16,root_.cached?rows:0);for(auto&s:local_){const U ki=s->guest+0x2c,kr=m_.r32(ki);U cache=0;if(s->value.keys.cached){const auto n=static_cast<U>(s->value.keys.cached-s->nodes.data());need(n<s->nodes.size(),"B474 projected key cache escaped graph");cache=kr+8*n;}m_.w32(ki+16,cache);}}
};
struct Ctx{std::array<std::uint16_t,257>flags{};CrtClassification ctype{};};
std::int32_t classify(std::uint8_t b,U mask,void*p){auto&c=*static_cast<Ctx*>(p);if(mask==8u)return static_cast<std::int32_t>(fun_0076e521(b,c.ctype));if(mask==4u)return static_cast<std::int32_t>(fun_0076e4cc(b,c.ctype));reject("B474 parser requested an unsupported CRT classification mask");}
void init_context(Memory&m,Ctx&c){need(m.r32(0x81776c)==1&&m.r32(0x817560)==0x81756a,"B474 requires warmed single-byte CRT classification");const U table=m.r32(0x817560)-2;for(U n=0;n<257;++n)c.flags[n]=static_cast<std::uint16_t>(m.r16(table+2*n));c.ctype={1,c.flags.data(),nullptr,nullptr};}
IntegerReadOperations int_ops(const IniOperations&o,Ctx&c){return {o,{classify,&c},[](std::int32_t x,void*){return x>='A'&&x<='Z'?x+('a'-'A'):x;},nullptr,nullptr};}
U read_int(Memory&m,Projection&g,Ctx&c,U sec,U key,U fallback){auto s=ztext(m,sec),k=ztext(m,key);const U x=fun_0050cc40(&g.root(),s.data(),k.data(),fallback,int_ops(g.ops(),c));g.flush();return x;}
U read_bool(Memory&m,Projection&g,U sec,U key,U fallback){auto s=ztext(m,sec),k=ztext(m,key);const U x=fun_0050e860(&g.root(),s.data(),k.data(),static_cast<std::uint8_t>(fallback),g.ops());g.flush();return x;}
std::uint32_t next_token(Memory&m,U input,U delimiters){std::array<std::uint8_t,32>bits{};for(U k=0;k<256;++k){const U c=m.r8(delimiters+k);if(!c)break;bits[c>>3]|=static_cast<std::uint8_t>(1u<<(c&7));if(k==255)reject("B474 tokenizer delimiter list exceeds bound");}const U state=platform::current_crt_thread(m.r32(0x817778));U p=input?input:m.r32(state+0x18);if(!p)reject("B474 positive tokenizer requires initialized TLS continuation");for(U k=0;k<512;++k){const U c=m.r8(p);if(!c||!(bits[c>>3]&(1u<<(c&7))))break;++p;}const U start=p;for(U k=0;k<512;++k){const U c=m.r8(p);if(!c)break;if(bits[c>>3]&(1u<<(c&7))){m.w8(p,0);++p;break;}++p;}m.w32(state+0x18,p);return start!=p?start:0u;}
std::int32_t number(Memory&m,U p,Ctx&c){std::vector<std::uint8_t>v=ztext(m,p,512);return static_cast<std::int32_t>(fun_0076e73d(v.data(),{classify,&c}));}
std::string slot_key(U n){char b[16]{};const int count=std::snprintf(b,sizeof b,"Slot%02u",n);need(count==6,"B474 Slot key format contract");return std::string(b,6);}
std::array<U,3> read_slot(Memory&m,Projection&g,Ctx&c,U sec,U key,U fallback,U helper_entry_esp,std::uint8_t*buffer){auto s=ztext(m,sec),k=ztext(m,key),fb=ztext(m,fallback);const U guest=helper_entry_esp-0x200u;const U count=static_cast<U>(fun_0050ddf0(&g.root(),s.data(),k.data(),fb.data(),buffer,512,g.ops()));g.flush();need(count>0&&count<512,"B474 Slot requires present bounded triplet");const U a=next_token(m,guest,0x7b9950u),b=next_token(m,0,0x7b9950u),d=next_token(m,0,0x7b9950u);need(a&&b&&d,"B474 Slot requires three nonempty tokens");return {static_cast<U>(number(m,a,c)),static_cast<U>(number(m,b,c)),static_cast<U>(number(m,d,c))};}
}
std::uint32_t fun_00665ce0(Memory&m,Inputs&i,std::uint32_t virtual_entry_esp){
 std::array<std::uint8_t,0x400> caller_stack{};const U stack_base=virtual_entry_esp-0x300u;leaf::Memory stack_span(caller_stack.data(),stack_base,static_cast<U>(caller_stack.size()));Memory local=m;local.add(stack_span);
 const U receiver=i.cx,ini=i.arg[0],section=i.arg[1],defaults=local.r32(0x821b88);
 need(virtual_entry_esp>=0x23cu,"B474 root stack base underflow");
 Inputs crt=i;const U state=recovery_b109::fun_005b39d0(local,crt);const U first_default=local.r32(state+0x28);need(defaults,"B474 defaults object missing");
 Projection graph(local,ini);Ctx ctx{};init_context(local,ctx);
 const std::array<U,5> ikeys{0x7dcfc4u,0x7dcfb8u,0x7d2b28u,0x7c593cu,0x7db210u};
 const std::array<U,5> ioffs{0,4,8,12,16};const std::array<U,5> idefaults{first_default,0u,local.r32(defaults+0x1108u),local.r32(defaults+0x10ecu),local.r32(defaults+0x10fcu)};
 for(U k=0;k<5;++k)local.w32(receiver+ioffs[k],read_int(local,graph,ctx,section,ikeys[k],idefaults[k]));
 const std::array<U,5>bkeys{0x7db150u,0x7db13cu,0x7db12cu,0x7dcfacu,0x7dcf9cu};const std::array<U,5>boffs{0x14u,0x15u,0x16u,0x17u,0x18u};const std::array<U,5>bdefaults{local.r8(defaults+0x111eu),local.r8(defaults+0x1121u),local.r8(defaults+0x1122u),local.r8(defaults+0x1120u),local.r8(defaults+0x1119u)};
 for(U k=0;k<5;++k)local.w8(receiver+boffs[k],static_cast<std::uint8_t>(read_bool(local,graph,section,bkeys[k],bdefaults[k])));
 const U key_guest=virtual_entry_esp-0x10u,helper_entry=virtual_entry_esp-0x3cu,buffer_guest=helper_entry-0x200u;auto*buffer=caller_stack.data()+(buffer_guest-stack_base);
 i.arg[1]=i.arg[3];
 for(U n=1;n<=7;++n){const auto key=slot_key(n);for(U j=0;j<=key.size();++j)local.w8(key_guest+j,j<key.size()?static_cast<std::uint8_t>(key[j]):0);const auto xyz=read_slot(local,graph,ctx,section,key_guest,0x8248a4u,helper_entry,buffer);i.arg[0]=xyz[1];i.arg[1]=xyz[0];const U row_offset=n*12u;local.w32(receiver+0x1cu+row_offset,xyz[0]);local.w32(receiver+0x20u+row_offset,xyz[1]);local.w32(receiver+0x24u+row_offset,xyz[2]);}
 return 30u;
}
}
