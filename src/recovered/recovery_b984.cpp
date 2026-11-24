#include "recovered/recovery_b984.hpp"
#include "recovered/name_hash.hpp"
#include "platform/current_crt_thread.hpp"
#include <stdexcept>
#include <string>
namespace ra2::recovered::recovery_b984 {
namespace {
using U=std::uint32_t;void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
std::string text(const Memory&m,U p,U limit=512u){need(p!=0,"984 nonnull text");std::string s;for(U k=0;k<limit;++k){const auto c=m.r8(p+k);if(!c)return s;s.push_back(char(c));}throw std::domain_error("984 bounded text");}
U hash(const std::string&s){return ini_name_hash(reinterpret_cast<const std::uint8_t*>(s.data()),s.size(),nullptr);}
U cached(const Memory&m,U index,const std::string&query){const auto row=m.r32(index+16u);need(m.r32(index+4u)==1u&&m.r32(index+8u)>=1u&&m.r8(index+12u)&&row&&m.r32(row)==hash(query),"984 warm positive original INI cache");return m.r32(row+4u);}
U decimal(const std::string&s){need(!s.empty()&&s.size()<=3u,"984 bounded unsigned decimal");U value=0;for(char c:s){need(c>='0'&&c<='9',"984 decimal digits");value=10u*value+U(c-'0');}need(value<=255u,"984 byte component");return value;}
}
U run(Memory&m,Inputs&i,Heap&h,U root,U entry,TokenObservation&o){
 need(root==0x6bb60u,"984 selected root");need(i.arg[4]==0u&&i.arg[5]==0u&&(i.arg[6]&0xffffu)==1u&&i.arg[7]==0u,"984 genuine empty nonowning fallback");
 const auto section=cached(m,i.cx+0x20u,text(m,i.arg[1]));const auto value=cached(m,section+0x2cu,text(m,i.arg[2]));const auto source=text(m,m.r32(value+0x10u));
 need(!source.empty()&&source.size()<512u&&source.front()>32&&source.back()>32,"984 no-op trim positive source");need(m.r32(0xb10530u)==0u&&m.r32(0x81776cu)==1u,"984 ASCII C locale");
 o={};o.entry_esp=entry;o.buffer=entry-0x200u;for(U k=0;k<source.size();++k)o.bytes[k]=std::uint8_t(source[k]);U pos=0,temporary=0,count=0;
 const auto next=[&](){need(pos<source.size(),"984 three required components");const auto thread=platform::current_crt_thread(m.r32(0x817778u));const U begin=pos;while(pos<source.size()&&source[pos]!=',')++pos;need(pos>begin,"984 nonempty token");const auto token=source.substr(begin,pos-begin);o.token_offsets.push_back(begin);if(pos<source.size())o.bytes[pos++]=0u;o.cursor=o.buffer+pos;m.w32(thread+0x18u,o.cursor);return token;};
 while(pos<source.size()){
  const auto first=next();need(first.front()=='('&&first.size()>=2u,"984 opening parenthesis");const auto red=decimal(first.substr(1u));const auto green=decimal(next());const auto third=next();need(third.back()==')'&&third.size()>=2u,"984 closing parenthesis");const auto blue=decimal(third.substr(0u,third.size()-1u));
  // Original root removes the last character of token3 after strtok has
  // already stored its continuation address. The cursor retains source-end
  // provenance even though the closing parenthesis becomes an earlier NUL.
  o.bytes[o.token_offsets.back()+third.size()-1u]=0u;
  if(!temporary){temporary=h.allocate(30u);need(temporary,"984 temporary allocation");for(U j=0;j<30u;++j)h.w8(temporary+j,0u);}need(count<3u,"984 one to three complete tuples");h.w8(temporary+3u*count,red);h.w8(temporary+3u*count+1u,green);h.w8(temporary+3u*count+2u,blue);++count;
 }
 const auto thread=platform::current_crt_thread(m.r32(0x817778u));o.cursor=o.buffer+U(source.size());m.w32(thread+0x18u,o.cursor);
 const U output=i.arg[0];m.w32(output,0x788a54u);m.w32(output+4u,0u);m.w32(output+8u,0u);m.w8(output+12u,1u);m.w8(output+13u,0u);
 const auto allocation=h.allocate(30u);need(allocation,"984 output allocation");for(U j=0;j<30u;++j)h.w8(allocation+j,0u);for(U j=0;j<30u;++j)h.w8(allocation+j,h.r8(temporary+j));
 m.w32(output+4u,allocation);m.w32(output+8u,10u);m.w8(output+13u,1u);m.w32(output+16u,count);m.w32(output+20u,10u);m.w32(output,0x788a74u);need(h.release(temporary)!=0u,"984 temporary real free");i.arg[3]=0x788a54u;return output;
}
U fun_0046bb60(Memory&m,Inputs&i,Heap&h,U entry,TokenObservation&o){return run(m,i,h,0x6bb60u,entry,o);}
}
