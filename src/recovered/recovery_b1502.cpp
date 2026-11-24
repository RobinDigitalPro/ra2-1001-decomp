#include "recovered/recovery_b1502.hpp"
#include "recovered/ini_text.hpp"
#include "recovered/name_hash.hpp"
#include "recovered/text_bytes.hpp"
#include "recovered/text_trim.hpp"
#include <cstring>
#include <stdexcept>
namespace ra2::recovered::b1502 {
namespace {
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
using Text=std::array<std::uint8_t,64>;
Text read_text(const Memory&m,U p){need(p!=0,"1502 nonnull readable text");Text out{};for(U k=0;k<out.size();++k){out[k]=std::uint8_t(m.r8(p+k));if(!out[k])return out;}throw std::domain_error("1502 bounded63byte text");}
Text heap_text(const Heap&h,U p){need(p!=0,"1502 actualnonnull heaptext");Text out{};for(U k=0;k<out.size();++k){out[k]=std::uint8_t(h.r8(p+k));if(!out[k])return out;}throw std::domain_error("1502 bounded63byte heaptext");}
U hash(const Text&t){return ini_name_hash(t.data(),fun_00775160(t.data()),nullptr);}
bool equal(const Text&t,const char*s){return std::strcmp(reinterpret_cast<const char*>(t.data()),s)==0;}
bool decimal_token(const std::uint8_t*&p){if(*p=='-')++p;U digits=0;while(*p>='0'&&*p<='9'){++p;++digits;if(digits>9)return false;}return digits!=0;}
void plain_id(const Text&t){const auto*p=t.data();need(decimal_token(p)&&*p==0,"1502 exact nonempty boundeddecimal ID");}
void complete_rectangle(const Text&t){auto*p=t.data();for(U k=0;k<4;++k){need(decimal_token(p),"1502 full4CSV allfields produced");need(*p==(k==3?0:','),"1502 exact4CSV format");if(k!=3)++p;}}
class Ledger {
 Heap&h;Observation&o;
 public:Ledger(Heap&heap,Observation&out):h(heap),o(out){need(o.owners.empty()&&o.free_order.empty(),"1502 freshobservation");o.owners.reserve(20);o.free_order.reserve(18);}
 U allocate(U requested){const U p=h.allocate(requested);need(p!=0,"1502 positive actualallocator");const U rounded=(requested+15u)&~15u;for(const auto&v:o.owners)need(v.released||v.address!=p,"1502 unique liveallocation");for(U k=0;k<rounded;++k)(void)h.r8(p+k);o.owners.push_back({p,requested,rounded,false,0,{}});return p;}
 void snapshot(U index){auto&v=o.owners.at(index);need(!v.released,"1502 snapshotliveowner");v.raw.resize(v.rounded);for(U k=0;k<v.rounded;++k)v.raw[k]=std::uint8_t(h.r8(v.address+k));}
 void release(U p){for(U k=0;k<o.owners.size();++k){auto&v=o.owners[k];if(v.address==p&&!v.released){snapshot(k);v.actual_free_result=h.release(p);need(v.actual_free_result!=0,"1502 actualfullHeapFreeBOOL");v.released=true;o.free_order.push_back(k);return;}}throw std::domain_error("1502 unknown/double free");}
};
void caller_word1(Memory&m,const Inputs&i,const Runtime&r,U value){need(r.actual_entry_s!=0&&std::uint64_t(r.actual_entry_s)+68<=0x100000000ull,"1502 genuinecaller64span");m.w32(r.actual_entry_s+8,value);i.arg[1]=value;}
U clone(Memory&m,const Inputs&i,Heap&h,Ledger&l,const Runtime&r,const Text&t,bool caller_slot){if(caller_slot)caller_word1(m,i,r,0);const U n=fun_00775160(t.data())+1;need(n<=16,"1502 exactshortstring domain");const U p=l.allocate(n);if(caller_slot)caller_word1(m,i,r,p);h.w8(p,0);for(U k=0;k<n;++k)h.w8(p+k,t[k]);return p;}
U literal(Memory&m,const Inputs&i,Heap&h,Ledger&l,const Runtime&r,U address,const char*expected,bool caller_slot){const auto t=read_text(m,address);need(equal(t,expected),"1502 independentoriginal literal bytes");return clone(m,i,h,l,r,t,caller_slot);}
void destroy_string(Memory&m,const Inputs&i,Ledger&l,const Runtime&r,U p,bool caller_slot){l.release(p);if(caller_slot)caller_word1(m,i,r,0);}
struct IniView {
 Memory&m;U receiver{},section_table{},section_object{},key_table{};Text section_name{};
 std::array<IniIndexEntry,1>sections{};std::array<IniIndexEntry,2>keys{};std::array<IniValue,2>values{};std::array<Text,2>value_text{};IniSection section{};IniIndex root{};
 static U name_hash(const std::uint8_t*p,std::size_t n,void*){return ini_name_hash(p,n,nullptr);}
 static void no_sort(IniIndexEntry*,std::int32_t,IniIndexKind,void*){throw std::domain_error("1502 genuinealready-sorted input excludes sort");}
 static std::int32_t no_upper(std::int32_t,void*){throw std::domain_error("1502 no boolean/uppercase getter reached");}
 IniOperations operations(){return {&name_hash,&no_sort,&no_upper,this,nullptr,nullptr};}
 IniView(Memory&memory,U ini,U holder):m(memory),receiver(ini){
  section_name=read_text(m,m.r32(holder));section_table=m.r32(ini+0x20);need(m.r32(ini)==0x78db34&&m.r32(ini+0x24)==1&&m.r32(ini+0x28)==10&&m.r8(ini+0x2c)==1&&section_table,"1502 coherentborrowed one-section index");
  need(m.r32(section_table)==hash(section_name),"1502 actualsection hash");section_object=m.r32(section_table+4);need(section_object&&m.r32(section_object)==0x78eba4,"1502 actualsection object");need(equal(read_text(m,m.r32(section_object+0xc)),reinterpret_cast<const char*>(section_name.data())),"1502 sectionname producer");
  key_table=m.r32(section_object+0x2c);need(key_table&&m.r32(section_object+0x30)==2&&m.r32(section_object+0x34)==10&&m.r8(section_object+0x38)==1,"1502 exactlytwo sortedborrowed keyrows");
  bool id=false,rect=false;for(U k=0;k<2;++k){const U key=m.r32(key_table+k*8),node=m.r32(key_table+k*8+4);need(node&&m.r32(node)==0x78eb9c,"1502 originalvalue-node tag");const auto name=read_text(m,m.r32(node+0xc));need(key==hash(name),"1502 actualkeyhash/name");value_text[k]=read_text(m,m.r32(node+0x10));values[k].text=value_text[k].data();keys[k]={global_b26::s32(key),&values[k]};if(equal(name,"ID")){plain_id(value_text[k]);id=true;}else if(equal(name,"ActiveRect")){complete_rectangle(value_text[k]);rect=true;}else need(false,"1502 onlyID/ActiveRect; actualoptionalkeysabsent");}
  need(id&&rect&&keys[0].key<keys[1].key,"1502 exactsignedkeyordering");section.keys={keys.data(),2,1,nullptr,10};sections[0]={global_b26::s32(m.r32(section_table)),&section};root={sections.data(),1,1,nullptr,10};
  const U rc=m.r32(receiver+0x30),kc=m.r32(section_object+0x3c);need(rc==0||rc==section_table,"1502 actualsection cache");if(rc)root.cached=sections.data();need(kc==0||kc==key_table||kc==key_table+8,"1502 actualkey cache");if(kc)section.keys.cached=keys.data()+(kc-key_table)/8;
 }
 void sync(){m.w8(receiver+0x2c,root.sorted);m.w32(receiver+0x30,root.cached?section_table:0);m.w8(section_object+0x38,section.keys.sorted);m.w32(section_object+0x3c,section.keys.cached?key_table+U(section.keys.cached-keys.data())*8:0);}
};
struct ClassificationContext {const CrtClassification&ctype;};
std::int32_t classify_digit(std::uint8_t b,U mask,void*ctx){auto&c=*static_cast<ClassificationContext*>(ctx);need(mask==4||mask==8,"1502 exactdecimalclassification masks");return std::int32_t(mask==4?fun_0076e4cc(b,c.ctype):fun_0076e521(b,c.ctype));}
std::int32_t lower_decimal(std::int32_t ch,void*){need(ch>='0'&&ch<='9',"1502 digitfinalbyte cold76FB34 path");return ch;}
std::int32_t no_hex(ScannerBuffer&,const std::uint8_t*,void*,void*){throw std::domain_error("1502 decimalID excludeshexscanner");}
U missing_empty_string(IniView&view,Heap&h,Ledger&ledger,U key,U default_text){const auto k=heap_text(h,key),fallback=heap_text(h,default_text);need(fallback[0]==0,"1502 genuineemptydefault");auto ops=view.operations();auto*section=fun_0050be00(&view.root,view.section_name.data(),ops);need(section&&fun_0050f620(&section->keys,k.data(),ops)==nullptr,"1502 actualmissingoptionalvalue");view.sync();std::array<std::uint8_t,1023>scratch;fun_0076dd10(scratch.data(),fallback.data(),1023);scratch.back()=0;fun_006e41d0(scratch.data());need(scratch[0]==0,"1502 originalemptycopy/trim");const U p=ledger.allocate(1);h.w8(p,0);return p;}
U construct_empty_children(Heap&h,Ledger&ledger,U self,U id,U owner,const std::array<U,4>&rect,const std::array<U,5>&strings){for(U p:strings)need(p&&h.r8(p)==0,"1502 genuine nonnull-empty optionalStringClasses");h.w32(self+4,id);h.w8(self+8,0);h.w8(self+9,1);h.w32(self+0xc,0);h.w32(self,0x78dbd0);h.w32(self+0x10,owner);for(U k=0;k<4;++k)h.w32(self+0x14+k*4,rect[k]);for(U off:{0x24u,0x28u,0x2cu,0x30u,0x34u})h.w32(self+off,0);h.w32(self,0x78dbb4);const U select=ledger.allocate(1);h.w32(self+0x34,select);h.w8(select,0);return self;}
}
U fun_004deea0(Memory&m,const Inputs&i,Heap&h,const Runtime&r,Observation&o){
 need(r.classification&&r.classification->max_character_width==1&&r.classification->flags_from_minus_one&&r.locale_initial_flag==0,"1502 pinnedinitialsinglebyteCRT/locale");need(!(i.arithmetic_flags&0x400),"1502 DFclear");const U original_word1=i.arg[1];need(m.r32(r.actual_entry_s+8)==original_word1,"1502 actualinitialcallerword1");const std::array<U,2>base{m.r32(original_word1),m.r32(original_word1+4)};IniView view(m,i.dx,i.cx);Ledger ledger(h,o);auto lookup=view.operations();ClassificationContext classification{*r.classification};IntegerReadOperations integer{lookup,{&classify_digit,&classification},&lower_decimal,&no_hex,&classification};
 U key=literal(m,i,h,ledger,r,0x7c03d8,"ID",false);const auto id_key=heap_text(h,key);const U id=fun_0050ce20(&view.root,{view.section_name.data()},{id_key.data()},0xffffffffu,integer);view.sync();destroy_string(m,i,ledger,r,key,false);need(id!=0xffffffffu,"1502 actualpositiveID");o.id=id;
 key=literal(m,i,h,ledger,r,0x7c4ec4,"Origin",false);const auto origin_key=heap_text(h,key);std::array<U,2>zero{0,0},origin{};GetterDecimalContext decimal_context{r.classification};MultiIntegerReadOperations multi{lookup,&scan_getter_decimal_callback,&decimal_context};fun_0050ec50(&view.root,origin.data(),{view.section_name.data()},{origin_key.data()},ComponentFallback{zero.data(),0},multi);view.sync();destroy_string(m,i,ledger,r,key,false);origin[0]+=base[0];origin[1]+=base[1];
 key=literal(m,i,h,ledger,r,0x7c4eb8,"ActiveRect",true);const auto rect_key=heap_text(h,key);std::array<U,4>fallback{},rect{};fun_0050d3c0(&view.root,rect.data(),{view.section_name.data()},{rect_key.data()},fallback.data(),multi);view.sync();destroy_string(m,i,ledger,r,key,true);need(global_b26::s32(rect[2])>0&&global_b26::s32(rect[3])>0,"1502 genuine nondegenerate rectangle");rect[0]+=base[0];rect[1]+=base[1];o.rectangle=rect;
 constexpr std::array<U,5>addresses{0x7bad74,0x7c4f44,0x7c4f38,0x7c4f28,0x7c4f1c};constexpr std::array<const char*,5>names{"Image","Highlighted","Disabled","HighlightSound","SelectVQ"};std::array<U,5>empty{};
 for(U k=0;k<5;++k){const U def=literal(m,i,h,ledger,r,0x8248a4,"",false);key=literal(m,i,h,ledger,r,addresses[k],names[k],true);empty[k]=missing_empty_string(view,h,ledger,key,def);destroy_string(m,i,ledger,r,key,true);destroy_string(m,i,ledger,r,def,false);}
 const U result=ledger.allocate(56);construct_empty_children(h,ledger,result,id,i.arg[0],rect,empty);for(U k=5;k>0;--k)destroy_string(m,i,ledger,r,empty[k-1],false);
 need(o.owners.size()==20&&o.free_order==std::vector<U>{0,1,2,4,3,7,6,10,9,13,12,16,15,17,14,11,8,5},"1502 exact20allocation/18freeorder");ledger.snapshot(18);ledger.snapshot(19);o.final_owner=result;o.empty_select_vq=o.owners[19].address;o.final_section_cache=m.r32(i.dx+0x30);o.final_key_cache=m.r32(view.section_object+0x3c);need(i.arg[1]==0&&m.r32(r.actual_entry_s+8)==0,"1502 exactproducedcallerword1zero");return result;
}
}
