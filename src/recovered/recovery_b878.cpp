#include "recovered/recovery_b878.hpp"
#include "recovered/name_hash.hpp"
#include <string>
#include <array>
namespace ra2::recovered::recovery_b878 {namespace {using U=std::uint32_t;
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
std::string text(const Memory&m,U p){need(p,"878 nonnulltext");std::string s;for(U k=0;k<64;++k){U c=m.r8(p+k);if(!c)return s;s+=char(c);}throw std::domain_error("878 textbound");}
U hash(const std::string&s){return ini_name_hash(reinterpret_cast<const std::uint8_t*>(s.data()),s.size(),nullptr);}
U lookup(Memory&m,U ix,U query){U table=m.r32(ix),n=m.r32(ix+4),cached=m.r32(ix+16);need(table&&n>=1&&n<=38&&m.r32(ix+8)>=n&&m.r8(ix+12),"878 initializedsortedindex");for(U k=1;k<n;++k)need(global_b26::s32(m.r32(table+8*(k-1)))<global_b26::s32(m.r32(table+8*k)),"878 uniquekeys");if(cached&&m.r32(cached)==query)return m.r32(cached+4);U lo=0,hi=n;while(lo<hi){U mid=lo+(hi-lo)/2,key=m.r32(table+8*mid);if(key==query){m.w32(ix+16,table+8*mid);return m.r32(table+8*mid+4);}if(global_b26::s32(key)<global_b26::s32(query))lo=mid+1;else hi=mid;}throw std::domain_error("878 positivehit required");}
std::string ini(Memory&m,const std::string&section,const std::string&key){U s=lookup(m,0x821b50,hash(section)),v=lookup(m,s+0x2c,hash(key));auto result=text(m,m.r32(v+0x10));need(!result.empty()&&result.size()<32&&std::uint8_t(result.front())>32&&std::uint8_t(result.back())>32,"878 nonempty untrimmed32bufferinput");return result;}
std::array<U,3> integers(const std::string&s,std::string&direction){std::array<U,3>out{};std::size_t p=0;for(U k=0;k<3;++k){bool minus=s.at(p)=='-';if(minus)++p;std::uint64_t value=0;unsigned digits=0;while(p<s.size()&&s[p]>='0'&&s[p]<='9'){value=value*10+s[p++]-'0';need(++digits<=10&&value<=(minus?2147483648ull:2147483647ull),"878 int32boundeddecimal");}need(digits&&p<s.size()&&s[p++]==',',"878 completeintegercomma");out[k]=minus?U(0-U(value)):U(value);}direction=s.substr(p);need(direction.size()>=1&&direction.size()<=2,"878 shortdirection");return out;}
}
std::uint32_t fun_00509530(Memory&m,const Inputs&i){need(i.cx&&m.r32(i.cx+0xb98)&&m.r32(0x81776c)==1,"878 initializedowner andsinglebyteCctype");auto section=ini(m,text(m,i.cx+0x1c8),text(m,0x7c62bc));U records=m.r32(i.cx+0xb98),result=0;for(U k=0;k<38;++k){auto value=ini(m,section,text(m,m.r32(0x7c5fe8+4*k)));std::string dir;auto nums=integers(value,dir);for(U j=0;j<3;++j)m.w32(records+16*k+4*j,nums[j]);bool known=false;for(U d=0;d<8;++d)if(dir==text(m,0x7c62ac-4*d)){m.w32(records+16*k+12,d);known=true;break;}need(known||dir=="ZZ","878 explicit unknown direction");result=known?0:0xffffffffu;}return result;}
}
