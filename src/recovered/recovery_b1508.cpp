#include "recovered/recovery_b1508.hpp"
#include "recovered/ini_text.hpp"
#include "recovered/name_hash.hpp"
#include "recovered/text_bytes.hpp"
#include "recovered/text_trim.hpp"
#include <cstring>
#include <stdexcept>
namespace ra2::recovered::b1508 {
namespace {
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
using Text=std::array<std::uint8_t,64>;
Text read_text(const Memory&m,U p){need(p!=0,"1508 nonnull readable text");Text out{};for(U k=0;k<out.size();++k){out[k]=std::uint8_t(m.r8(p+k));if(!out[k])return out;}throw std::domain_error("1508 bounded63byte text");}
Text heap_text(const Heap&h,U p){need(p!=0,"1508 actualnonnull heaptext");Text out{};for(U k=0;k<out.size();++k){out[k]=std::uint8_t(h.r8(p+k));if(!out[k])return out;}throw std::domain_error("1508 bounded63byte heaptext");}
U hash(const Text&t){return ini_name_hash(t.data(),fun_00775160(t.data()),nullptr);}
bool equal(const Text&t,const char*s){return std::strcmp(reinterpret_cast<const char*>(t.data()),s)==0;}
bool decimal_token(const std::uint8_t*&p){if(*p=='-')++p;U digits=0;while(*p>='0'&&*p<='9'){++p;++digits;if(digits>9)return false;}return digits!=0;}
void plain_id(const Text&t){const auto*p=t.data();need(decimal_token(p)&&*p==0,"1508 exact nonempty boundeddecimal ID");}
void complete_rectangle(const Text&t){auto*p=t.data();for(U k=0;k<4;++k){need(decimal_token(p),"1508 full4CSV allfields produced");need(*p==(k==3?0:','),"1508 exact4CSV format");if(k!=3)++p;}}
class Ledger {
 Heap&h;Observation&o;
 public:Ledger(Heap&heap,Observation&out):h(heap),o(out){need(o.owners.empty()&&o.free_order.empty(),"1508 freshobservation");o.owners.reserve(11);o.free_order.reserve(10);}
 U allocate(U requested){const U p=h.allocate(requested);need(p!=0,"1508 positive actualallocator");const U rounded=(requested+15u)&~15u;for(const auto&v:o.owners)need(v.released||v.address!=p,"1508 unique liveallocation");for(U k=0;k<rounded;++k)(void)h.r8(p+k);o.owners.push_back({p,requested,rounded,false,0,{}});return p;}
 void snapshot(U index){auto&v=o.owners.at(index);need(!v.released,"1508 snapshotliveowner");v.raw.resize(v.rounded);for(U k=0;k<v.rounded;++k)v.raw[k]=std::uint8_t(h.r8(v.address+k));}
 void release(U p){for(U k=0;k<o.owners.size();++k){auto&v=o.owners[k];if(v.address==p&&!v.released){snapshot(k);v.actual_free_result=h.release(p);need(v.actual_free_result!=0,"1508 actualfullHeapFreeBOOL");v.released=true;o.free_order.push_back(k);return;}}throw std::domain_error("1508 unknown/double free");}
};
void caller_word1(Memory&m,const Inputs&i,const Runtime&r,U value){need(r.actual_entry_s!=0&&std::uint64_t(r.actual_entry_s)+68<=0x100000000ull,"1508 genuinecaller64span");m.w32(r.actual_entry_s+8,value);i.arg[1]=value;}
U clone(Memory&m,const Inputs&i,Heap&h,Ledger&l,const Runtime&r,const Text&t,bool caller_slot){if(caller_slot)caller_word1(m,i,r,0);const U n=fun_00775160(t.data())+1;need(n<=16,"1508 exactshortstring domain");const U p=l.allocate(n);if(caller_slot)caller_word1(m,i,r,p);h.w8(p,0);for(U k=0;k<n;++k)h.w8(p+k,t[k]);return p;}
U literal(Memory&m,const Inputs&i,Heap&h,Ledger&l,const Runtime&r,U address,const char*expected,bool caller_slot){const auto t=read_text(m,address);need(equal(t,expected),"1508 independentoriginal literal bytes");return clone(m,i,h,l,r,t,caller_slot);}
void destroy_string(Memory&m,const Inputs&i,Ledger&l,const Runtime&r,U p,bool caller_slot){l.release(p);if(caller_slot)caller_word1(m,i,r,0);}
struct IniView {
 Memory&m;U receiver{},section_table{},section_object{},key_table{};Text section_name{};
 std::array<IniIndexEntry,1>sections{};std::array<IniIndexEntry,4>keys{};std::array<IniValue,4>values{};std::array<Text,4>value_text{};IniSection section{};IniIndex root{};
 static U name_hash(const std::uint8_t*p,std::size_t n,void*){return ini_name_hash(p,n,nullptr);}
 static void no_sort(IniIndexEntry*,std::int32_t,IniIndexKind,void*){throw std::domain_error("1508 genuinealready-sorted input excludes sort");}
 static std::int32_t no_upper(std::int32_t,void*){throw std::domain_error("1508 no boolean/uppercase getter reached");}
 IniOperations operations(){return {&name_hash,&no_sort,&no_upper,this,nullptr,nullptr};}
 IniView(Memory&memory,U ini,U holder):m(memory),receiver(ini){
  section_name=read_text(m,m.r32(holder));section_table=m.r32(ini+0x20);need(m.r32(ini)==0x78db34&&m.r32(ini+0x24)==1&&m.r32(ini+0x28)==10&&m.r8(ini+0x2c)==1&&section_table,"1508 coherentborrowed one-section index");
  need(m.r32(section_table)==hash(section_name),"1508 actualsection hash");section_object=m.r32(section_table+4);need(section_object&&m.r32(section_object)==0x78eba4,"1508 actualsection object");need(equal(read_text(m,m.r32(section_object+0xc)),reinterpret_cast<const char*>(section_name.data())),"1508 sectionname producer");
  key_table=m.r32(section_object+0x2c);need(key_table&&m.r32(section_object+0x30)==4&&m.r32(section_object+0x34)==10&&m.r8(section_object+0x38)==1,"1508 exactlyfour sortedborrowed keyrows");
  bool id=false,rect=false,image=false,palette=false;for(U k=0;k<4;++k){const U key=m.r32(key_table+k*8),node=m.r32(key_table+k*8+4);need(node&&m.r32(node)==0x78eb9c,"1508 originalvalue-node tag");const auto name=read_text(m,m.r32(node+0xc));need(key==hash(name),"1508 actualkeyhash/name");value_text[k]=read_text(m,m.r32(node+0x10));values[k].text=value_text[k].data();keys[k]={global_b26::s32(key),&values[k]};if(equal(name,"ID")){plain_id(value_text[k]);id=true;}else if(equal(name,"ActiveRect")){complete_rectangle(value_text[k]);rect=true;}else if(equal(name,"Image")){need(std::strlen(reinterpret_cast<const char*>(value_text[k].data()))==12,"1508 exact12byteSHP");const auto*t=value_text[k].data();need(t[0]=='I'&&t[1]=='M'&&t[2]=='G'&&t[8]=='.'&&t[9]=='S'&&t[10]=='H'&&t[11]=='P',"1508 generateduppercaseSHP");for(U j=3;j<8;++j)need(t[j]>='0'&&t[j]<='9',"1508 fiveSHPdigits");image=true;}else if(equal(name,"Palette")){need(equal(value_text[k],"WHOLE.PAL"),"1508 exactphysicalPALdomain");palette=true;}else need(false,"1508 exactlyID/Image/Palette/ActiveRect; Origin/Loop/Rateabsent");}
  need(id&&rect&&image&&palette,"1508 allfourdistinctkeys");for(U k=1;k<4;++k)need(keys[k-1].key<keys[k].key,"1508 exactsignedkeyordering");section.keys={keys.data(),4,1,nullptr,10};sections[0]={global_b26::s32(m.r32(section_table)),&section};root={sections.data(),1,1,nullptr,10};
  const U rc=m.r32(receiver+0x30),kc=m.r32(section_object+0x3c);need(rc==0||rc==section_table,"1508 actualsection cache");if(rc)root.cached=sections.data();need(kc==0||(kc>=key_table&&kc<key_table+32&&((kc-key_table)%8)==0),"1508 actualkey cache");if(kc)section.keys.cached=keys.data()+(kc-key_table)/8;
 }
 void sync(){m.w8(receiver+0x2c,root.sorted);m.w32(receiver+0x30,root.cached?section_table:0);m.w8(section_object+0x38,section.keys.sorted);m.w32(section_object+0x3c,section.keys.cached?key_table+U(section.keys.cached-keys.data())*8:0);}
};
struct ClassificationContext {const CrtClassification&ctype;};
std::int32_t classify_digit(std::uint8_t b,U mask,void*ctx){auto&c=*static_cast<ClassificationContext*>(ctx);need(mask==4||mask==8,"1508 exactdecimalclassification masks");return std::int32_t(mask==4?fun_0076e4cc(b,c.ctype):fun_0076e521(b,c.ctype));}
std::int32_t lower_decimal(std::int32_t ch,void*){need(ch>='0'&&ch<='9',"1508 digitfinalbyte cold76FB34 path");return ch;}
std::int32_t no_hex(ScannerBuffer&,const std::uint8_t*,void*,void*){throw std::domain_error("1508 decimalID excludeshexscanner");}

// Exact positive50DF90 variant; old B773/B1502 guards remain unchanged.
U existing_name_string(IniView&view,Heap&h,Ledger&ledger,U key,U default_text,const char*expected,U length){
 const auto k=heap_text(h,key),fallback=heap_text(h,default_text);need(fallback[0]==0,"1508 actualempty supplieddefault");auto ops=view.operations();auto*sec=fun_0050be00(&view.root,view.section_name.data(),ops);need(sec,"1508 actualexistingsection");auto*value=fun_0050f620(&sec->keys,k.data(),ops);need(value&&value->text,"1508 actualpresentImage/Palette");view.sync();std::array<std::uint8_t,1023>scratch;fun_0076dd10(scratch.data(),value->text,1023);scratch.back()=0;fun_006e41d0(scratch.data());need(fun_00775160(scratch.data())==length&&(!expected||std::strcmp(reinterpret_cast<const char*>(scratch.data()),expected)==0),"1508 exact12/9byte trimmedname");const U p=ledger.allocate(length+1);h.w8(p,0);for(U k2=0;k2<=length;++k2)h.w8(p+k2,scratch[k2]);return p;
}
U address(const void*p){const auto n=reinterpret_cast<std::uintptr_t>(p);need(n&&n<=0xffffffffu,"1508 actualx86 localspan");return U(n);}
}
U fun_004de9e0(Memory&m,const Inputs&i,Heap&h,Api&api,Clock clock,const Runtime&r,Observation&o){
 need(r.classification&&r.classification->max_character_width==1&&r.classification->flags_from_minus_one&&r.locale_initial_flag==0,"1508 pinnedinitialsinglebyteCRT");need(!(i.arithmetic_flags&0x400)&&clock,"1508 positiveDFclear/realclockprovider");need(r.actual_entry_s&&m.r32(r.actual_entry_s+8)==i.arg[1],"1508 actualcallerword1");
 const U original_xy=i.arg[1];IniView view(m,i.dx,i.cx);Ledger ledger(h,o);auto lookup=view.operations();ClassificationContext classification{*r.classification};IntegerReadOperations integer{lookup,{&classify_digit,&classification},&lower_decimal,&no_hex,&classification};
 U key=literal(m,i,h,ledger,r,0x7c03d8,"ID",false);auto kt=heap_text(h,key);o.id=fun_0050ce20(&view.root,{view.section_name.data()},{kt.data()},0xffffffffu,integer);view.sync();destroy_string(m,i,ledger,r,key,false);need(o.id!=0xffffffffu,"1508 genuinepositiveID");
 // Image output holder starts null759250; then default,key,actualoutput.
 U def=literal(m,i,h,ledger,r,0x8248a4,"",false);key=literal(m,i,h,ledger,r,0x7bad74,"Image",false);const U shp=existing_name_string(view,h,ledger,key,def,nullptr,12);destroy_string(m,i,ledger,r,key,false);destroy_string(m,i,ledger,r,def,false);need(h.r8(shp)!=0,"1508 genuineImage lengthpositive");
 def=literal(m,i,h,ledger,r,0x8248a4,"",false);key=literal(m,i,h,ledger,r,0x7c4ecc,"Palette",false);const U pal=existing_name_string(view,h,ledger,key,def,"WHOLE.PAL",9);destroy_string(m,i,ledger,r,key,false);destroy_string(m,i,ledger,r,def,false);need(h.r8(pal)!=0,"1508 genuinePalette lengthpositive");
 key=literal(m,i,h,ledger,r,0x7c4ec4,"Origin",false);kt=heap_text(h,key);std::array<U,2>zero{0,0},point{};GetterDecimalContext dc{r.classification};MultiIntegerReadOperations multi{lookup,&scan_getter_decimal_callback,&dc};fun_0050ec50(&view.root,point.data(),{view.section_name.data()},{kt.data()},ComponentFallback{zero.data(),0},multi);view.sync();destroy_string(m,i,ledger,r,key,false);const std::array<U,2>base{m.r32(original_xy),m.r32(original_xy+4)};point[0]+=base[0];point[1]+=base[1];o.point=point;
 key=literal(m,i,h,ledger,r,0x7c4eb8,"ActiveRect",true);kt=heap_text(h,key);std::array<U,4>fallback{},rect{};fun_0050d3c0(&view.root,rect.data(),{view.section_name.data()},{kt.data()},fallback.data(),multi);view.sync();destroy_string(m,i,ledger,r,key,true);need(global_b26::s32(rect[2])>0&&global_b26::s32(rect[3])>0,"1508 nondegenerateActiveRect");rect[0]+=base[0];rect[1]+=base[1];o.rectangle=rect;
 const auto loop_literal=read_text(m,0x7c4eb0);need(equal(loop_literal,"Loop"),"1508 actualLoopliteral");o.loop=fun_0050e860(&view.root,view.section_name.data(),loop_literal.data(),1,lookup);view.sync();need(o.loop==1,"1508 genuineabsentLoop default1");
 key=literal(m,i,h,ledger,r,0x7b9eec,"Rate",true);kt=heap_text(h,key);o.rate=fun_0050ce20(&view.root,{view.section_name.data()},{kt.data()},5,integer);view.sync();destroy_string(m,i,ledger,r,key,true);need(o.rate==5,"1508 genuineabsentRate default5");
 const U self=ledger.allocate(40);std::array<U,2>holders{shp,pal};leaf::Memory shp_span(reinterpret_cast<std::uint8_t*>(std::uintptr_t(shp)),shp,16),pal_span(reinterpret_cast<std::uint8_t*>(std::uintptr_t(pal)),pal,16),self_span(reinterpret_cast<std::uint8_t*>(std::uintptr_t(self)),self,48),point_span(reinterpret_cast<std::uint8_t*>(point.data()),address(point.data()),8),rect_span(reinterpret_cast<std::uint8_t*>(rect.data()),address(rect.data()),16),holder_span(reinterpret_cast<std::uint8_t*>(holders.data()),address(holders.data()),8);auto v=m;v.add(shp_span);v.add(pal_span);v.add(self_span);v.add(point_span);v.add(rect_span);v.add(holder_span);
 b1100::Inputs q{};q.ax=self;q.cx=self;q.dx=i.arg[0];q.arg[0]=o.id;q.arg[1]=i.arg[0];q.arg[2]=point_span.base();q.arg[3]=rect_span.base();q.arg[4]=holder_span.base();q.arg[5]=holder_span.base()+4;q.arg[6]=o.rate;q.arg[7]=o.loop;
 const U result=b1100::run(v,q,h,api,clock,i.fp,o.constructor);need(result==self,"1508 actualconstructorselfEAX");destroy_string(m,i,ledger,r,pal,false);destroy_string(m,i,ledger,r,shp,false);ledger.snapshot(10);o.final_owner=result;o.final_section_cache=m.r32(i.dx+0x30);o.final_key_cache=m.r32(view.section_object+0x3c);need(o.owners.size()==11&&o.free_order==std::vector<U>{0,2,1,5,4,7,8,9,6,3},"1508 exactwrapper11alloc10free");need(i.arg[1]==0&&m.r32(r.actual_entry_s+8)==0,"1508 allproducedcallerword1zero");return result;
}
}
