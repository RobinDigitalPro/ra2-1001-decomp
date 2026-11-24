#include "recovered/recovery_b983.hpp"
#include "recovered/name_hash.hpp"
#include "platform/current_crt_thread.hpp"
#include <stdexcept>
#include <string>
namespace ra2::recovered::recovery_b983 {
namespace {
using U=std::uint32_t;void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
std::string text(const Memory&m,U p,U limit=512u){need(p!=0,"983 nonnull text");std::string s;for(U k=0;k<limit;++k){const auto c=m.r8(p+k);if(!c)return s;s.push_back(char(c));}throw std::domain_error("983 bounded text");}
U hash(const std::string&s){return ini_name_hash(reinterpret_cast<const std::uint8_t*>(s.data()),s.size(),nullptr);}
U cached(const Memory&m,U index,const std::string&query){const auto row=m.r32(index+16u);need(m.r32(index+4u)==1u&&m.r32(index+8u)>=1u&&m.r8(index+12u)&&row&&m.r32(row)==hash(query),"983 warm positive original INI cache");return m.r32(row+4u);}
bool equal(const std::string&a,const std::string&b){if(a.size()!=b.size())return false;for(U j=0;j<a.size();++j){const auto lower=[](char c){return c>='A'&&c<='Z'?char(c+32):c;};if(lower(a[j])!=lower(b[j]))return false;}return true;}
U decimal(const std::string&s){U at=0,value=0;bool negative=false;if(s[at]=='-'||s[at]=='+'){negative=s[at]=='-';++at;}need(at<s.size(),"983 decimal digits");for(;at<s.size();++at){need(s[at]>='0'&&s[at]<='9',"983 finite decimal token");value=10u*value+U(s[at]-'0');need(value<=999u,"983 small decimal value");}return negative?0u-value:value;}
}
U run(Memory&m,Inputs&i,Heap&h,U root,U entry,TokenObservation&o){
 need(root==0x6adb0u||root==0x6b530u,"983 selected root");const bool names=root==0x6b530u;
 // ECX is the actual INI receiver. The hidden/result address is caller word0;
 // words1/2 are section/key. Words3..8 carry the finite empty default vector.
 need(i.arg[4]==0u&&i.arg[5]==0u&&(i.arg[6]&0xffffu)==1u&&i.arg[7]==0u,"983 genuine empty nonowning fallback");
 const auto section=cached(m,i.cx+0x20u,text(m,i.arg[1]));const auto value=cached(m,section+0x2cu,text(m,i.arg[2]));const auto source=text(m,m.r32(value+0x10u));
 need(!source.empty()&&source.size()<512u&&source.front()>32&&source.back()>32,"983 no-op trim positive source");need(m.r32(0xb10530u)==0u&&m.r32(0x81776cu)==1u,"983 ASCII C locale");
 o={};o.entry_esp=entry;o.buffer=entry-0x200u;for(U k=0;k<source.size();++k)o.bytes[k]=std::uint8_t(source[k]);
 std::vector<U>items;U pos=0,temporary=0;
 while(pos<source.size()){
  const auto thread=platform::current_crt_thread(m.r32(0x817778u));const U begin=pos;while(pos<source.size()&&source[pos]!=',')++pos;need(pos>begin&&pos-begin<=7u,"983 finite nonempty ASCII token");const auto token=source.substr(begin,pos-begin);
  o.token_offsets.push_back(begin);if(pos<source.size())o.bytes[pos++]=0u;o.cursor=o.buffer+pos;m.w32(thread+0x18u,o.cursor);
  U item=0;if(names){const auto count=m.r32(0xa28708u),table=m.r32(0xa286fcu);need(count>=1u&&count<=16u,"983 existing name table");bool found=false;for(U j=0;j<count;++j){const auto object=m.r32(table+4u*j);if(equal(token,text(m,object+0x24u,8u))){item=object;found=true;break;}}need(found,"983 known name hit");}else item=decimal(token);
  if(!temporary){temporary=h.allocate(40u);need(temporary,"983 temporary allocation");}h.w32(temporary+4u*U(items.size()),item);items.push_back(item);need(items.size()<=3u,"983 one to three items");
 }
 const auto thread=platform::current_crt_thread(m.r32(0x817778u));o.cursor=o.buffer+U(source.size());m.w32(thread+0x18u,o.cursor);
 const U output=i.arg[0],base_vptr=names?0x788a14u:0x7889d4u,derived_vptr=base_vptr+0x20u;
 m.w32(output,base_vptr);m.w32(output+4u,0u);m.w32(output+8u,0u);m.w8(output+12u,1u);m.w8(output+13u,0u);
 const auto allocation=h.allocate(40u);need(allocation,"983 output allocation");for(U j=0;j<10u;++j)h.w32(allocation+4u*j,h.r32(temporary+4u*j));
 m.w32(output+4u,allocation);m.w32(output+8u,10u);m.w8(output+13u,1u);m.w32(output+16u,U(items.size()));m.w32(output+20u,10u);m.w32(output,derived_vptr);
 need(h.release(temporary)!=0u,"983 temporary real free");i.arg[3]=base_vptr;return output;
}
U fun_0046adb0(Memory&m,Inputs&i,Heap&h,U entry,TokenObservation&o){return run(m,i,h,0x6adb0u,entry,o);}
U fun_0046b530(Memory&m,Inputs&i,Heap&h,U entry,TokenObservation&o){return run(m,i,h,0x6b530u,entry,o);}
}
