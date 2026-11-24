#include "recovered/recovery_b986.hpp"
#include "recovered/name_hash.hpp"
#include "platform/current_crt_thread.hpp"
#include <stdexcept>
#include <string>
namespace ra2::recovered::recovery_b986 {
namespace {
using U=std::uint32_t;void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
std::string text(const Memory&m,U p,U limit=128u){need(p!=0,"986 nonnull text");std::string s;for(U k=0;k<limit;++k){const auto c=m.r8(p+k);if(!c)return s;s.push_back(char(c));}throw std::domain_error("986 bounded text");}
U hash(const std::string&s){return ini_name_hash(reinterpret_cast<const std::uint8_t*>(s.data()),s.size(),nullptr);}
U cached(const Memory&m,U index,const std::string&query){const auto row=m.r32(index+16u);need(m.r32(index+4u)==1u&&m.r32(index+8u)>=1u&&m.r8(index+12u)&&row&&m.r32(row)==hash(query),"986 warm positive original INI cache");return m.r32(row+4u);}
bool equal(const std::string&a,const std::string&b){if(a.size()!=b.size())return false;for(U j=0;j<a.size();++j){const auto lower=[](char c){return c>='A'&&c<='Z'?char(c+32):c;};if(lower(a[j])!=lower(b[j]))return false;}return true;}
U lookup(const Memory&m,U root,const std::string&name){
 U table=0,count=0;if(root==0x6b800u){need(!equal(name,text(m,0x7bceb0u)),"986 not random sentinel");table=m.r32(0xa1e03cu);count=m.r32(0xa1e048u);}else if(root==0x10aa60u){need(!equal(name,text(m,0x7b8e5cu)),"986 not none sentinel");need(m.r32(0x8192f8u)==1u,"986 original403EB0 initialized getter state");table=m.r32(0xab829cu);count=m.r32(0xab82a8u);}else{for(U p:{0x7bced8u,0x7bced0u,0x7bcec4u,0x7bcebcu,0x7bd070u,0x7bd068u})need(!equal(name,text(m,p)),"986 known names, not special category keywords");table=m.r32(0xa1e00cu);count=m.r32(0xa1e018u);}
 need(count>=1u&&count<=16u&&table,"986 finite existing table");U found=0,ordinal=0;for(U j=0;j<count;++j){const auto object=m.r32(table+4u*j);bool hit=false;if(root==0x10aa60u){const auto text_object=m.r32(object);need(text_object!=0,"986 existing name object");hit=equal(name,text(m,text_object+0x6cu,8u));}else if(root==0x6b800u)hit=equal(name,text(m,object+0x64u,8u))||equal(name,text(m,object+0x24u,8u));else hit=equal(name,text(m,object+0x24u,8u));if(hit){found=object;ordinal=j;break;}}
 need(found!=0,"986 known positive name hit");if(root==0x6b800u){const auto result=m.r32(found+0xb8u);need(result!=0xffffffffu,"986 no group fallback");return result;}if(root==0x10aa60u){for(U j=0;j<count;++j)if(m.r32(table+4u*j)==found)return j;throw std::domain_error("986 selected object retained in table");}return ordinal;
}
}
U run(Memory&m,Inputs&i,Heap&h,U root,U entry,TokenObservation&o){
 need(root==0x6b800u||root==0x10aa60u||root==0x6c120u,"986 selected root");const bool indirect_output=root==0x6b800u;const U fallback=indirect_output?3u:2u,ini=indirect_output?i.cx:i.dx,output=indirect_output?i.arg[0]:i.cx,section_arg=indirect_output?1u:0u;
 need(i.arg[fallback+1u]==0u&&i.arg[fallback+2u]==0u&&(i.arg[fallback+3u]&0xffffu)==1u&&i.arg[fallback+4u]==0u,"986 genuine empty nonowning fallback");
 const auto section=cached(m,ini+0x20u,text(m,i.arg[section_arg]));const auto value=cached(m,section+0x2cu,text(m,i.arg[section_arg+1u]));const auto source=text(m,m.r32(value+0x10u));need(!source.empty()&&source.size()<128u&&source.front()>32&&source.back()>32,"986 no-op trim positive source");need(m.r32(0xb10530u)==0u,"986 ASCII comparator mode");
 o={};o.entry_esp=entry;o.buffer=entry-0x80u;for(U k=0;k<source.size();++k)o.bytes[k]=std::uint8_t(source[k]);U pos=0,temporary=0,count=0;
 while(pos<source.size()){
  const auto thread=platform::current_crt_thread(m.r32(0x817778u));const U begin=pos;while(pos<source.size()&&source[pos]!=',')++pos;need(pos>begin&&pos-begin<=7u,"986 finite nonempty token");const auto token=source.substr(begin,pos-begin);o.token_offsets.push_back(begin);if(pos<source.size())o.bytes[pos++]=0u;o.cursor=o.buffer+pos;m.w32(thread+0x18u,o.cursor);
  const auto item=lookup(m,root,token);if(!temporary){temporary=h.allocate(40u);need(temporary,"986 temporary allocation");}need(count<3u,"986 one to three known tokens");h.w32(temporary+4u*count,item);++count;
 }
 const auto thread=platform::current_crt_thread(m.r32(0x817778u));o.cursor=o.buffer+U(source.size());m.w32(thread+0x18u,o.cursor);
 m.w32(output,0x7889d4u);m.w32(output+4u,0u);m.w32(output+8u,0u);m.w8(output+12u,1u);m.w8(output+13u,0u);const auto allocation=h.allocate(40u);need(allocation,"986 output allocation");for(U j=0;j<10u;++j)h.w32(allocation+4u*j,h.r32(temporary+4u*j));m.w32(output+4u,allocation);m.w32(output+8u,10u);m.w8(output+13u,1u);m.w32(output+16u,count);m.w32(output+20u,10u);m.w32(output,0x7889f4u);need(h.release(temporary)!=0u,"986 temporary real free");i.arg[fallback]=0x7889d4u;return output;
}
U fun_0046b800(Memory&m,Inputs&i,Heap&h,U entry,TokenObservation&o){return run(m,i,h,0x6b800u,entry,o);}
U fun_0050aa60(Memory&m,Inputs&i,Heap&h,U entry,TokenObservation&o){return run(m,i,h,0x10aa60u,entry,o);}
U fun_0046c120(Memory&m,Inputs&i,Heap&h,U entry,TokenObservation&o){return run(m,i,h,0x6c120u,entry,o);}
}
