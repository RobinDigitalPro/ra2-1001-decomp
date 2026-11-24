#include "recovery_b1245.hpp"
#include "recovered/recovery_b838.hpp"
#include "recovered/name_hash.hpp"
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>
#include <stdexcept>
namespace ra2::recovered::b1245 {namespace {
void need(bool x){if(!x)throw std::domain_error("1245 bounded positive physical Battle INI");}
unsigned hash(const std::string&s){return ini_name_hash(reinterpret_cast<const std::uint8_t*>(s.data()),s.size(),nullptr);}
struct Section{unsigned address=0,name=0,table=0;std::string text;std::vector<unsigned>nodes;std::vector<std::string>keys;};
struct Parser{
 Heap&h;Observation&o;unsigned root,table=0;std::vector<Section>sections;
 unsigned alloc(unsigned n){++o.allocations;return h.allocate(n);}
 unsigned clone(const std::string&s){const auto p=alloc(unsigned(s.size()+1u));for(unsigned k=0;k<=s.size();++k)h.w8(p+k,k==s.size()?0u:static_cast<unsigned char>(s[k]));return p;}
 void list(unsigned self){h.w32(self,0x785af4u);h.w32(self+4u,0x785afcu);h.w32(self+8u,self+0x10u);h.w32(self+12u,0u);h.w32(self+0x10u,0x785afcu);h.w32(self+20u,0u);h.w32(self+24u,self+4u);}
 void index(unsigned p){h.w32(p,0u);h.w32(p+4u,0u);h.w32(p+8u,0u);h.w8(p+12u,0u);h.w32(p+16u,0u);}
 void insert(unsigned head,unsigned p){const auto next=h.r32(head+4u);h.w32(p+8u,head);h.w32(p+4u,next);if(next)h.w32(next+8u,p);h.w32(head+4u,p);}
 void unlink(unsigned p){const auto next=h.r32(p+4u),prev=h.r32(p+8u);need(next&&prev);h.w32(prev+4u,next);h.w32(next+8u,prev);h.w32(p+8u,0u);h.w32(p+4u,0u);}
 void begin(){list(root+4u);h.w32(root+4u,0x785aecu);index(root+0x20u);h.w32(root,0x785ae4u);h.w32(root+0x34u,0u);h.w8(root+0x38u,0u);}
 void section(const std::string&name){Section s;s.text=name;s.address=alloc(68u);s.name=clone(name);h.w32(s.address,0x78eba4u);h.w32(s.address+4u,0u);h.w32(s.address+8u,0u);h.w32(s.address+12u,s.name);list(s.address+0x10u);h.w32(s.address+0x10u,0x78ebacu);index(s.address+0x2cu);h.w32(s.address+0x40u,0u);sections.push_back(s);++o.sections;}
 void key(const std::string&key,const std::string&value){need(!sections.empty()&&!key.empty()&&!value.empty());auto&s=sections.back();need(s.nodes.size()<10u);const auto node=alloc(40u),v=clone(value),k=clone(key);for(unsigned off=0u;off<40u;off+=4u)h.w32(node+off,0u);h.w32(node,0x78eb9cu);h.w32(node+12u,k);h.w32(node+16u,v);if(!s.table){s.table=alloc(80u);h.w32(s.address+0x2cu,s.table);h.w32(s.address+0x34u,10u);}const auto n=unsigned(s.nodes.size());h.w32(s.table+8u*n,hash(key));h.w32(s.table+8u*n+4u,node);s.nodes.push_back(node);s.keys.push_back(key);h.w32(s.address+0x30u,n+1u);h.w8(s.address+0x38u,0u);insert(h.r32(s.address+0x28u),node);++o.keys;}
 void publish(){auto&s=sections.back();need(!s.nodes.empty());if(!table){table=alloc(80u);h.w32(root+0x20u,table);h.w32(root+0x28u,10u);}const auto n=unsigned(sections.size()-1u);h.w32(table+8u*n,hash(s.text));h.w32(table+8u*n+4u,s.address);h.w32(root+0x24u,n+1u);h.w8(root+0x2cu,0u);insert(h.r32(root+0x1cu),s.address);}
 void parse(const std::string&text){std::size_t pos=0;while(pos<text.size()){const auto end=text.find("\r\n",pos);need(end!=std::string::npos);const auto line=text.substr(pos,end-pos);pos=end+2u;if(line.size()>2u&&line.front()=='['&&line.back()==']'){if(!sections.empty())publish();section(line.substr(1u,line.size()-2u));}else{const auto eq=line.find('=');need(eq!=std::string::npos);key(line.substr(0u,eq),line.substr(eq+1u));}}publish();need(sections.size()==2u&&sections[0].text=="Battles"&&sections[1].text=="unit"&&sections[0].keys==std::vector<std::string>{"unit"}&&sections[1].nodes.size()==7u);}
 void sort(unsigned table,unsigned count){std::vector<std::pair<std::int32_t,unsigned>>v;for(unsigned k=0;k<count;++k)v.emplace_back(global_b26::s32(h.r32(table+8u*k)),h.r32(table+8u*k+4u));std::sort(v.begin(),v.end());for(unsigned k=0;k<count;++k){h.w32(table+8u*k,unsigned(v[k].first));h.w32(table+8u*k+4u,v[k].second);}}
 void consumer_sorted_views(){sort(table,2u);h.w8(root+0x2cu,1u);for(auto&s:sections){sort(s.table,unsigned(s.nodes.size()));h.w8(s.address+0x38u,1u);}}
 void destroy(){for(auto it=sections.begin();it!=sections.end();++it){auto&s=*it;h.release(s.name);h.w32(s.address+12u,0u);for(auto j=s.nodes.begin();j!=s.nodes.end();++j){const auto p=*j;h.release(h.r32(p+12u));h.w32(p+12u,0u);h.release(h.r32(p+16u));h.w32(p+16u,0u);unlink(p);h.w32(p,0x785afcu);h.release(p);}h.release(s.table);index(s.address+0x2cu);h.w32(s.address+0x40u,0u);h.w32(s.address+0x10u,0x785af4u);h.w32(s.address+0x14u,0x785afcu);h.w32(s.address+0x20u,0x785afcu);unlink(s.address);h.w32(s.address,0x785afcu);h.release(s.address);}h.release(table);index(root+0x20u);h.w32(root,0x78db34u);h.w32(root+4u,0x785af4u);h.w32(root+8u,0x785afcu);h.w32(root+0x14u,0x785afcu); // empty head.next=tail, tail.prev=head survive; opposite links are null
  h.release(root);}
};
}
unsigned run(unsigned r,Memory&m,const Inputs&,Heap&h,FileApi&api,FindApi&find,Observation&o){
 need(r==0x111c40u&&m.r32(0x838be0u)==0u&&m.r32(0xa588e0u)==0u&&m.r8(0xa9e184u)==0u&&m.r32(0x817554u)==0u&&m.r32(0xb10e14u)==0u&&m.r32(0xb10530u)==0u&&m.r32(0x81776cu)==1u);
 WIN32_FIND_DATAA data;HANDLE search=find.first("BATTLE*.INI",&data);need(search!=INVALID_HANDLE_VALUE&&(data.dwFileAttributes&0x116u)==0u);const std::string name=data.cAlternateFileName[0]?data.cAlternateFileName:data.cFileName;need(name=="BATTLE.INI");
 Parser p{h,o,0u};o.filename=p.clone(name);o.ini=p.alloc(80u);p.root=o.ini;p.begin();o.reader=h.allocate_reader();++o.allocations;
 const auto path=reinterpret_cast<const char*>(std::uintptr_t(o.filename));for(unsigned k=0;k<2u;++k){const HANDLE probe=api.create_file_a(path,GENERIC_READ,FILE_SHARE_READ,nullptr,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,nullptr);need(probe!=INVALID_HANDLE_VALUE&&api.close_handle(probe)!=FALSE);}const auto input=api.create_file_a(path,GENERIC_READ,3u,nullptr,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL|FILE_FLAG_SEQUENTIAL_SCAN,nullptr);need(input!=INVALID_HANDLE_VALUE);DWORD got=0u,eof=0u;need(api.read_file(input,reinterpret_cast<void*>(std::uintptr_t(o.reader)),4096u,&got,nullptr)!=FALSE&&got>0u&&got<512u);need(api.read_file(input,reinterpret_cast<void*>(std::uintptr_t(o.reader+got)),4096u-got,&eof,nullptr)!=FALSE&&eof==0u);need(api.read_file(input,reinterpret_cast<void*>(std::uintptr_t(o.reader)),4096u,&eof,nullptr)!=FALSE&&eof==0u);
 p.parse(std::string(reinterpret_cast<const char*>(std::uintptr_t(o.reader)),got));h.free_reader(o.reader);need(api.close_handle(input)!=FALSE);p.consumer_sorted_views();
 // Same original B838/B481 consumer contract, now backed by actual bytes read
 // and all genuine parser allocations. No preconstructed replacement INI.
 Memory local=m;std::vector<std::unique_ptr<leaf::Memory>>spans;auto add=[&](unsigned a,unsigned n){spans.emplace_back(new leaf::Memory(reinterpret_cast<unsigned char*>(std::uintptr_t(a)),a,n));local.add(*spans.back());};add(o.ini,80u);add(p.table,80u);for(const auto&s:p.sections){add(s.address,68u);add(s.name,unsigned(s.text.size()+1u));add(s.table,80u);for(auto node:s.nodes){add(node,40u);for(unsigned off:{12u,16u}){const auto a=h.r32(node+off);unsigned n=0u;while(h.r8(a+n))++n;add(a,n+1u);}}}
 floating_b61::Inputs call{};call.cx=o.ini;(void)recovery_b838::fun_00465320(local,call);++o.battle_callbacks;p.destroy();o.final_free_bool=h.release(o.filename);need(o.final_free_bool!=0u);need(find.next(search,&data)==FALSE);o.find_close_bool=unsigned(find.close(search));need(o.find_close_bool!=0u);return(o.find_close_bool&0xffffff00u)|1u;
}
}
