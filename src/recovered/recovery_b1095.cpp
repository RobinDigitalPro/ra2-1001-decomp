#include "recovered/recovery_b1095.hpp"
#include <string>
#include <stdexcept>
namespace ra2::recovered::b1095 {
static void need(bool x){if(!x)throw std::domain_error("1095 bounded positive warmcache");}
static std::string name(Memory&m,unsigned p){need(p!=0u);std::string s;for(unsigned k=0;k<256u;++k){auto c=m.r8(p+k);if(c==0u)return s;need(c<128u);s+=char(c);}throw std::domain_error("1095 unterminated");}
unsigned run(Memory&m,const Inputs&i,State&,unsigned root){
 if(root==0x31f0d0u){const auto count=m.r32(i.cx+0xccu),data=m.r32(i.cx+0xc0u);need(count>=3u&&count<=7u);const auto query=name(m,m.r32(i.arg[0]));need(!query.empty());for(unsigned j=0;j<count;++j){const auto r=m.r32(data+4u*j);if(name(m,m.r32(r))==query){const auto p=m.r32(r+4u);need(p!=0u);return p;}}throw std::domain_error("1095 coldpath excluded");}
 need(root==0x1faf60u&&m.r32(0xb10530u)==0u);const auto manager=m.r32(0xa5df68u);need(manager!=0u);const auto map=m.r32(manager+12u);need(m.r32(map+4u)==0x5fb1f0u&&m.r32(map+8u)==31u&&m.r32(map+12u)==10u);auto query=name(m,i.cx);need(!query.empty());unsigned hash=0u;for(auto&c:query){if(c>='a'&&c<='z')c=char(c-32);hash=(26u*hash+unsigned(c))%31u;}const auto bucket=m.r32(map)+24u*hash;const auto count=m.r32(bucket+16u),data=m.r32(bucket+4u);need(count>=3u&&count<=7u);for(unsigned j=count;j>0u;--j){const auto rec=data+260u*(j-1u);if(name(m,rec)==query){const auto associated=m.r32(rec+256u),result=m.r32(associated+256u);need(result!=0u);return result;}}throw std::domain_error("1095 coldpath excluded");
}
}
