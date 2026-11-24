#include "recovered/recovery_b385.hpp"
#include "recovered/ini_bulk.hpp"
#include "recovered/ini_integer.hpp"
#include "recovered/ini_lookup.hpp"
#include "recovered/name_hash.hpp"
#include "recovered/recovery_b381.hpp"
#include "recovered/decimal_text.hpp"
#include <algorithm>
#include <array>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

namespace ra2::recovered::recovery_b385 {
namespace {
using U=std::uint32_t;
using namespace floating_b61;
[[noreturn]] void reject(const char* why){throw std::domain_error(why);}
std::vector<std::uint8_t> ztext(const Memory&m,U p){
 if(!p)reject("B385 requires nonnull INI string");std::vector<std::uint8_t>s;
 for(unsigned n=0;n<64;++n){auto b=static_cast<std::uint8_t>(m.r8(p+n));s.push_back(b);if(!b)return s;}
 reject("B385 string exceeds bounded 64-byte span");
}
std::uint32_t hash_z(const std::vector<std::uint8_t>&s){unsigned n=0;while(n<s.size()&&s[n])++n;return ini_name_hash(s.data(),n,nullptr);}
std::int32_t signed_hash(U h){return global_b26::s32(h);}
void no_sort(IniIndexEntry*,std::int32_t,IniIndexKind,void*){reject("B385 requires positive signed-sorted indices");}
std::uint32_t hash_cb(const std::uint8_t*p,std::size_t n,void*){return ini_name_hash(p,n,nullptr);}
std::int32_t upper_cb(std::int32_t c,void*){return c>='a'&&c<='z'?c-('a'-'A'):c;}
struct SectionView;
struct KeyView {IniValue value{}; std::vector<std::uint8_t> text;};
struct SectionView {IniSection value{};std::vector<IniIndexEntry> nodes;std::vector<std::unique_ptr<KeyView>> keys;U guest=0;};
class Projection {
 Memory&m_; U receiver_; IniIndex root_{}; std::vector<IniIndexEntry> root_nodes_;
 std::vector<std::unique_ptr<SectionView>> sections_; IniOperations ops_{};
 U read_cache(U index,const std::vector<IniIndexEntry>&nodes,const std::vector<U>&guest_nodes,IniIndexEntry*cached){
  if(!cached)return 0;for(std::size_t n=0;n<nodes.size();++n)if(&nodes[n]==cached)return guest_nodes[n];
  reject("B385 logical cache is outside its projected index");
 }
 SectionView* section(U guest){for(auto&v:sections_)if(v->guest==guest)return v.get();return nullptr;}
 void make_section(U guest){
  if(section(guest))return;
  auto s=std::make_unique<SectionView>();s->guest=guest;const U index=guest+0x2cu;
  const U count=m_.r32(index+4),table=m_.r32(index);if(count>16||!count||!table||!m_.r8(index+12))reject("B385 key index outside finite sorted subset");
  s->nodes.resize(count);s->keys.reserve(count);std::vector<U>guest_nodes(count);
  for(U k=0;k<count;++k){const U row=table+8*k;guest_nodes[k]=row;s->nodes[k].key=global_b26::s32(m_.r32(row));
   const U vp=m_.r32(row+4),tp=m_.r32(vp+0x10);auto kv=std::make_unique<KeyView>();kv->text=ztext(m_,tp);kv->value.text=kv->text.data();
   s->nodes[k].value=&kv->value;s->keys.push_back(std::move(kv));
   if(k&&s->nodes[k-1].key>=s->nodes[k].key)reject("B385 key rows must be unique signed-sorted hits");
  }
  s->value.keys={s->nodes.empty()?nullptr:s->nodes.data(),static_cast<std::int32_t>(count),1,nullptr,count};
  const U cached=m_.r32(index+16);if(cached){for(U k=0;k<count;++k)if(guest_nodes[k]==cached)s->value.keys.cached=&s->nodes[k];if(!s->value.keys.cached)reject("B385 key cache must point into its table");}
  sections_.push_back(std::move(s));
 }
public:
 Projection(Memory&m,U receiver):m_(m),receiver_(receiver){
  if(!receiver_)reject("B385 null INI receiver");const U index=receiver+0x20u,count=m.r32(index+4),table=m.r32(index);
  if(count>16||!count||!table||!m.r8(index+12))reject("B385 requires nonempty initialized section index");
  root_nodes_.resize(count);sections_.reserve(count);std::vector<U>guest_nodes(count);
  for(U k=0;k<count;++k){const U row=table+8*k,sp=m.r32(row+4);guest_nodes[k]=row;root_nodes_[k].key=global_b26::s32(m.r32(row));make_section(sp);root_nodes_[k].value=&section(sp)->value;
   if(k&&root_nodes_[k-1].key>=root_nodes_[k].key)reject("B385 section rows must be unique signed-sorted hits");}
  root_={root_nodes_.data(),static_cast<std::int32_t>(count),1,nullptr,count};const U cached=m.r32(index+16);
  if(cached){for(U k=0;k<count;++k)if(guest_nodes[k]==cached)root_.cached=&root_nodes_[k];if(!root_.cached)reject("B385 section cache must point into its table");}
  ops_={hash_cb,no_sort,upper_cb,nullptr,nullptr,nullptr};
 }
 IniIndex& root(){return root_;} const IniOperations& ops()const{return ops_;}
 void refresh(){
  const U idx=receiver_+0x20u,table=m_.r32(idx),raw_cache=m_.r32(idx+16);root_.cached=nullptr;
  if(raw_cache){for(std::size_t n=0;n<root_nodes_.size();++n)if(table+8u*n==raw_cache)root_.cached=&root_nodes_[n];if(!root_.cached)reject("B385 raw section cache escaped its table");}
  for(auto&s:sections_){const U ki=s->guest+0x2c,kt=m_.r32(ki),cache=m_.r32(ki+16);s->value.keys.cached=nullptr;
   if(cache){for(std::size_t n=0;n<s->nodes.size();++n)if(kt+8u*n==cache)s->value.keys.cached=&s->nodes[n];if(!s->value.keys.cached)reject("B385 raw key cache escaped its table");}}
 }
 void flush(){
  const U idx=receiver_+0x20u,table=m_.r32(idx);U root_cache=0;
  if(root_.cached)root_cache=table+8u*static_cast<U>(root_.cached-root_nodes_.data());m_.w32(idx+16,root_cache);
  for(auto&s:sections_){const U ki=s->guest+0x2c,kt=m_.r32(ki);U cache=0;
   if(s->value.keys.cached)cache=kt+8u*static_cast<U>(s->value.keys.cached-s->nodes.data());m_.w32(ki+16,cache);}
 }
};
struct Ctx{std::array<std::uint16_t,257> flags{};CrtClassification ctype{};GetterHexContext hex{};};
std::int32_t classify(std::uint8_t b,U mask,void*p){auto&c=*static_cast<Ctx*>(p);return static_cast<std::int32_t>(c.ctype.flags_from_minus_one[b+1]&mask);}
std::int32_t decimal_classify(std::uint8_t b,U mask,void*p){return classify(b,mask,p);}
std::int32_t lowercase(std::int32_t c,void*){return c>='A'&&c<='Z'?c+('a'-'A'):c;}
void init_context(Memory&m,Ctx&c){const U table=m.r32(0x817560u)-2u;for(unsigned n=0;n<257;++n)c.flags[n]=static_cast<std::uint16_t>(m.r16(table+2*n));c.ctype={1,c.flags.data(),nullptr,nullptr};c.hex={&c.ctype};}
IntegerReadOperations int_ops(const IniOperations&lookup,Ctx&c){return {lookup,{decimal_classify,&c},lowercase,scan_getter_hex32_callback,&c.hex};}
std::vector<std::uint8_t> host_text(const Memory&m,U p){return ztext(m,p);}
std::uint32_t read_integer(Memory&m,Projection&g,Ctx&ctx,U section,U key,U fallback){auto s=host_text(m,section),k=host_text(m,key);const U out=fun_0050cc40(&g.root(),s.data(),k.data(),fallback,int_ops(g.ops(),ctx));g.flush();return out;}
std::uint8_t read_bool(Memory&m,Projection&g,U section,U key,std::uint8_t fallback){auto s=host_text(m,section),k=host_text(m,key);auto out=fun_0050e860(&g.root(),s.data(),k.data(),fallback,g.ops());g.flush();return out;}
U read_float(Memory&m,Projection&graph,const Inputs&outer,U ini,U section,U key,U dst,U fallback_lo,U fallback_hi){
 Inputs nested=outer;nested.cx=ini;nested.arg[0]=section;nested.arg[1]=key;nested.arg[2]=fallback_lo;nested.arg[3]=fallback_hi;
 const U eax=recovery_b381::fun_0050d7f0(m,nested);outer.fp=nested.fp;graph.refresh();
 const auto wide=outer.fp.pop64();floating_b61::write64(m,dst,wide);return eax;
}
std::uint32_t al(std::uint32_t eax,U byte){return floating_b61::with_al(eax,byte);}
bool section_present(Memory&m,Projection&g,U section){auto s=host_text(m,section);auto*p=fun_0050be00(&g.root(),s.data(),g.ops());g.flush();return p!=nullptr;}
U float_field(Memory&m,Projection&g,const Inputs&i,U ini,U sec,U key,U dst){return read_float(m,g,i,ini,sec,key,dst,m.r32(dst),m.r32(dst+4));}
}

// ABI observations: 0x23edf0/0x244a90 take output record in ECX and INI in
// entry stack word 0. 0x244c10 takes INI in ECX, output in EDX, section in
// entry stack word 0. All three original roots use RET 4; native harness must
// independently verify this cleanup. Inputs.arg[] are caller words and are
// never reused as B381's private nested frame.
std::uint32_t fun_0063edf0(Memory&m,const Inputs&i){
 const U out=i.cx,ini=i.arg[0],sec=m.r32(0x793ef4u);
 Projection graph(m,ini);if(!section_present(m,graph,sec))return 0;
 Ctx ctx{};init_context(m,ctx);const U integer=read_integer(m,graph,ctx,sec,0x7d9b68u,m.r32(out+0x1480u));m.w32(out+0x1480u,integer);
 U eax=float_field(m,graph,i,ini,sec,0x7d9b50u,out+0x1488u);
 eax=float_field(m,graph,i,ini,sec,0x7d9b3cu,out+0x1490u);
 return al(eax,1);
}
std::uint32_t fun_00644a90(Memory&m,const Inputs&i){
 const U out=i.cx,ini=i.arg[0],sec=m.r32(0x793f44u);Projection graph(m,ini);
 if(!section_present(m,graph,sec))return 0;Ctx ctx{};init_context(m,ctx);
 const U turn=read_integer(m,graph,ctx,sec,0x7db6d4u,m.r32(out+0x368u));m.w32(out+0x368u,turn);
 const U speed=read_integer(m,graph,ctx,sec,0x7be950u,m.r32(out+0x36cu));m.w32(out+0x36cu,speed);
 U eax=float_field(m,graph,i,ini,sec,0x7db6ccu,out+0x370u);
 const U cruise=read_integer(m,graph,ctx,sec,0x7db6bcu,m.r32(out+0x378u));m.w32(out+0x378u,cruise);
 eax=float_field(m,graph,i,ini,sec,0x7bc378u,out+0x380u);
 eax=float_field(m,graph,i,ini,sec,0x7db6a8u,out+0x388u);
 const U wobble=read_integer(m,graph,ctx,sec,0x7db698u,m.r32(out+0x390u));m.w32(out+0x390u,wobble);
 return al(wobble,1);
}
std::uint32_t fun_00644c10(Memory&m,const Inputs&i){
 const U ini=i.cx,out=i.dx,sec=i.arg[0];Projection graph(m,ini);if(!section_present(m,graph,sec))return 0;
 struct F{U key,off,lo,hi;};static constexpr F first8[]={
  {0x7db724,0x00,0,0x3ff00000},{0x7c5ec8,0x08,0,0x3ff00000},{0x7c5ebc,0x10,0,0x3ff00000},
  {0x7be958,0x18,0,0x3ff00000},{0x7c5eb8,0x20,0,0x3ff00000},{0x7c5eb0,0x28,0,0x3ff00000},
  {0x7db718,0x38,0x47ae147b,0x3f947ae1},{0x7db70c,0x40,0xeb851eb8,0x3f9eb851}};
 for(auto x:first8)(void)read_float(m,graph,i,ini,sec,x.key,out+x.off,x.lo,x.hi);
 const auto build_slowdown=read_bool(m,graph,sec,0x7db6fcu,0);m.w8(out+0x48,build_slowdown);
 (void)read_float(m,graph,i,ini,sec,0x7c5ea4u,out+0x30u,0,0x3ff00000u);
 const auto destroy_walls=read_bool(m,graph,sec,0x7db6ecu,1);m.w8(out+0x49,destroy_walls);
 const auto content_scan=read_bool(m,graph,sec,0x7db64cu,0);m.w8(out+0x4a,content_scan);
 // With fixture literals '0'/'1', original 0x76e313 returns 0x30/0x31;
 // 0x50e860 subtracts '0' then writes AL=0/1, so full EAX is exactly 0/1.
 return content_scan;
}
}




