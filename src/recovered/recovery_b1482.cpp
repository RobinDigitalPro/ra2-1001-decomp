#include "recovered/recovery_b1482.hpp"
#include "recovered/ini_bulk.hpp"
#include "recovered/name_hash.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1482 {
namespace {
using U=std::uint32_t;
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
std::array<std::uint8_t,64> text(Memory&m,U p){
 std::array<std::uint8_t,64> out{};need(p!=0,"1482 readable nonnull string");
 for(U k=0;k<out.size();++k){out[k]=m.r8(p+k);if(!out[k])return out;}throw std::domain_error("1482 bounded string");
}
// Actual 76D686 count<2 guard; no comparator/provider is reached here.
void one_row_sort(IniIndexEntry*,std::int32_t count,IniIndexKind,void*){need(count==1,"1482 actual one-row qsort guard");}
// Actual 76E313 with original B10530=0, bounded ASCII input.
std::int32_t uppercase(std::int32_t c,void*){need(c>=0&&c<128,"1482 C-locale ASCII");return c>='a'&&c<='z'?c-32:c;}
struct Graph {
 Memory&m;U manager,section,node,root_table,key_table;
 std::array<std::uint8_t,64> value_text;
 IniValue value;IniSection view{};IniIndexEntry key_entry{},section_entry{};IniIndex roots{};IniOperations ops{};
 Graph(Memory&memory,U p):m(memory),manager(p),section(m.r32(m.r32(p+0x20u)+4u)),node(m.r32(m.r32(section+0x2cu)+4u)),root_table(m.r32(p+0x20u)),key_table(m.r32(section+0x2cu)),value_text(text(m,m.r32(node+0x10u))),value{value_text.data()}{
  need(m.r32(p)==0x78db34u&&m.r32(section)==0x78eba4u&&m.r32(node)==0x78eb9cu,"1482 actual parsed graph vptrs");
  need(m.r32(p+0x24u)==1u&&m.r32(p+0x28u)==10u&&m.r8(p+0x2cu)==0u&&m.r32(p+0x30u)==0u,"1482 cold one-section index");
  need(m.r32(section+0x30u)==1u&&m.r32(section+0x34u)==10u&&m.r8(section+0x38u)==0u&&m.r32(section+0x3cu)==0u,"1482 cold one-key index");
  key_entry={leaf::s32(m.r32(key_table)),&value};view.keys={&key_entry,1,0,nullptr,10};
  section_entry={leaf::s32(m.r32(root_table)),&view};roots={&section_entry,1,0,nullptr,10};
  ops={ini_name_hash,one_row_sort,uppercase,nullptr,nullptr,nullptr};
 }
 void flush(){
  need(!roots.cached||roots.cached==&section_entry,"1482 section cache correspondence");need(!view.keys.cached||view.keys.cached==&key_entry,"1482 key cache correspondence");
  m.w8(manager+0x2cu,roots.sorted);m.w32(manager+0x30u,roots.cached?root_table:0u);
  m.w8(section+0x38u,view.keys.sorted);m.w32(section+0x3cu,view.keys.cached?key_table:0u);
 }
 // 50D7F0 uses the same actual membership/index paths on this absent-key
 // domain. Its fallback double is produced by caller PUSHes, never dead stack.
 void fallback(const std::uint8_t* section_name,const std::uint8_t* key_name,std::uint64_t bits,platform::x87::State&fp){
  auto*s=fun_0050be00(&roots,section_name,ops);need(s==&view,"1482 present numeric section");
  need(fun_0050f620(&s->keys,key_name,ops)==nullptr,"1482 genuine absent numeric key");flush();fp.load64(bits);
 }
};
}
std::uint32_t fun_00649310(Memory&m,const Inputs&i){
 static constexpr U counts[]={0xa1e048,0xa27f98,0x84e520,0xa1e018,0xa255b8,0xa1e088,0xa27fb0,0x821ee0,0xa1e030,0x821e50,0xa27f80,0xa28818,0xa1e128,0xa1e140,0xa1e110,0xa28730};
 for(U p:counts)need(m.r32(p)==0u,"1482 actual empty pre-load type registries");need(m.r32(0xb10530u)==0u,"1482 original C-locale gate");
 Graph graph(m,i.arg[0]);static constexpr U keys[]={0x7cc848,0x7cc840,0x7cc834,0x7cc828,0x7cc81c,0x7cc814};
 for(U k=0;k<30u;++k){
  const U record=0xa28000u+32u*k;m.w32(record,k);const auto section_name=text(m,m.r32(0x7b8704u+4u*k));
  auto*section=fun_0050be00(&graph.roots,section_name.data(),graph.ops);graph.flush();if(!section)continue;
  need(k==0u&&section==&graph.view,"1482 only actual Sleep section present");
  for(U b=0;b<6u;++b){const auto key=text(m,keys[b]);m.w8(record+4u+b,fun_0050e860(&graph.roots,section_name.data(),key.data(),m.r8(record+4u+b),graph.ops));graph.flush();}
  const auto rate=text(m,0x7b9eecu),aa=text(m,0x7cc80cu);
  graph.fallback(section_name.data(),rate.data(),floating_b61::read64(m,record+0x10u),i.fp);
  floating_b61::write64(m,record+0x10u,i.fp.pop64());
  graph.fallback(section_name.data(),aa.data(),0u,i.fp);
  floating_b61::write64(m,record+0x18u,i.fp.store64());i.fp.compare_pop64(floating_b61::read64(m,0x786610u));
  if(i.fp.status()&0x4000u)floating_b61::write64(m,record+0x18u,floating_b61::read64(m,record+0x10u));
 }
 // Last actual missing section returns full EAX0; final MOV AL,1 yields 1.
 return 1u;
}
}
