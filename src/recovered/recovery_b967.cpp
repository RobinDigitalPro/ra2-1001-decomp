#include "recovered/recovery_b967.hpp"
#include "recovered/name_hash.hpp"
#include "platform/current_crt_thread.hpp"
#include <stdexcept>
#include <string>
#include <vector>
namespace ra2::recovered::recovery_b967 {
namespace {
using U=std::uint32_t;void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
std::string text(const Memory&m,U p,U limit=128){need(p!=0,"967 nonnull text");std::string s;for(U k=0;k<limit;++k){const auto c=m.r8(p+k);if(!c)return s;s.push_back(char(c));}throw std::domain_error("967 bounded text");}
U hash(const std::string&s){return ini_name_hash(reinterpret_cast<const std::uint8_t*>(s.data()),s.size(),nullptr);}
U cached(const Memory&m,U index,const std::string&query){const auto row=m.r32(index+16u);need(m.r32(index+4u)==1u&&m.r32(index+8u)>=1u&&m.r8(index+12u)&&row&&m.r32(row)==hash(query),"967 warm positive original INI cache");return m.r32(row+4u);}
char lower(char c){return c>='A'&&c<='Z'?char(c+32):c;}
bool equal(std::string a,std::string b){if(a.size()!=b.size())return false;for(U k=0;k<a.size();++k)if(lower(a[k])!=lower(b[k]))return false;return true;}
}
U run(Memory&m,const Inputs&i,Heap&h,U root,U entry,TokenObservation&o){
 U table_at=0,count_at=0,vptr=0;
 if(root==0x24ac70u){table_at=0xa1e00cu;count_at=0xa1e018u;vptr=0x790e2cu;}else if(root==0x24af30u){table_at=0xa27fa4u;count_at=0xa27fb0u;vptr=0x78e0f8u;}else if(root==0x24b1f0u){table_at=0xa27f74u;count_at=0xa27f80u;vptr=0x793f60u;}else throw std::domain_error("967 selected root");
 // EDX is the INI receiver; ECX is the result receiver. All three stack
 // arguments remain unchanged. Positive cached INI10DDF0 returns this value.
 const auto section=cached(m,i.dx+0x20u,text(m,i.arg[0]));const auto value=cached(m,section+0x2cu,text(m,i.arg[1]));const auto source=text(m,m.r32(value+0x10u));
 need(!source.empty()&&source.size()<128u&&source.front()>32&&source.back()>32,"967 no-op trim positive source");need(m.r32(0xb10530u)==0u,"967 ASCII mode");
 o={};o.entry_esp=entry;o.buffer=entry-0x80u;for(U k=0;k<source.size();++k)o.bytes[k]=std::uint8_t(source[k]); // strncpy128 zero-pads every remaining byte
 std::vector<U>objects;U pos=0,temporary=0;
 while(pos<source.size()){
  const auto thread=platform::current_crt_thread(m.r32(0x817778u));const U begin=pos;while(pos<source.size()&&source[pos]!=',')++pos;need(pos>begin&&pos-begin<=7u,"967 finite nonempty ASCII token");
  const auto token=source.substr(begin,pos-begin);for(char c:token)need((c>='A'&&c<='Z')||(c>='a'&&c<='z')||(c>='0'&&c<='9'),"967 alphanumeric token");
  o.token_offsets.push_back(begin);if(pos<source.size())o.bytes[pos++]=0u;o.cursor=o.buffer+pos;m.w32(thread+0x18u,o.cursor);
  const auto count=m.r32(count_at),table=m.r32(table_at);need(count>=1u&&count<=16u,"967 existing named-object table");U object=0;for(U j=0;j<count;++j){const auto rec=m.r32(table+4u*j);if(equal(token,text(m,rec+0x24u,8u))){object=rec;break;}}need(object!=0u,"967 known name hit, no constructor");
  if(!temporary){temporary=h.allocate(40u);need(temporary,"967 temporary allocation");}h.w32(temporary+4u*U(objects.size()),object);objects.push_back(object);
 }
 need(objects.size()>=1u&&objects.size()<=3u,"967 one to three tokens");
 // Final strtok(NULL,",") revisits the terminating NUL and stores the same
 // exact buffer-end pointer in the genuine current-thread PTD.
 const auto thread=platform::current_crt_thread(m.r32(0x817778u));o.cursor=o.buffer+U(source.size());m.w32(thread+0x18u,o.cursor);
 // The first reserve requests 10 DWORD cells. Its unused cells retain actual
 // allocation bytes and the assignment helper copies all10 cells, not count.
 m.w32(i.cx+4u,0u);m.w32(i.cx+8u,0u);m.w8(i.cx+0xcu,1u);m.w8(i.cx+0xdu,0u);
 const auto output=h.allocate(40u);need(output,"967 owned output allocation");for(U j=0;j<10u;++j)h.w32(output+4u*j,h.r32(temporary+4u*j));
 m.w32(i.cx,vptr);m.w32(i.cx+4u,output);m.w32(i.cx+8u,10u);m.w8(i.cx+0xdu,1u);m.w32(i.cx+0x10u,U(objects.size()));m.w32(i.cx+0x14u,10u);
 need(h.release(temporary)!=0u,"967 successful temporary free");return i.cx;
}
U fun_0064ac70(Memory&m,const Inputs&i,Heap&h,U entry,TokenObservation&o){return run(m,i,h,0x24ac70u,entry,o);}
U fun_0064af30(Memory&m,const Inputs&i,Heap&h,U entry,TokenObservation&o){return run(m,i,h,0x24af30u,entry,o);}
U fun_0064b1f0(Memory&m,const Inputs&i,Heap&h,U entry,TokenObservation&o){return run(m,i,h,0x24b1f0u,entry,o);}
}
