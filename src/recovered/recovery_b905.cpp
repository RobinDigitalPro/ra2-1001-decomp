#include "recovered/recovery_b905.hpp"
#include "recovered/name_hash.hpp"
#include "platform/current_crt_thread.hpp"
#include <string>
#include <vector>
#include <algorithm>
namespace ra2::recovered::recovery_b905{namespace{using U=std::uint32_t;
std::string text(Memory&m,U p){std::string s;for(U k=0;k<64;++k){U c=m.r8(p+k);if(!c)return s;s+=char(c);}throw std::domain_error("905 boundedtext");}
U hash(const std::string&s){return ini_name_hash(reinterpret_cast<const std::uint8_t*>(s.data()),s.size(),nullptr);}
U one(Memory&m,U ix,const std::string&key){U row=m.r32(ix);if(m.r32(ix+4)!=1||m.r32(ix+8)<1||!m.r8(ix+12)||m.r32(row)!=hash(key))throw std::domain_error("905 onesortedpositivekey");m.w32(ix+16,row);return m.r32(row+4);}
}
U fun_0050e240(Memory&m,Inputs&i,U entry){U sec=one(m,i.cx+0x20,text(m,i.arg[0])),node=one(m,sec+0x2c,text(m,i.arg[1]));auto s=text(m,m.r32(node+0x10));std::vector<U>values;U pos=0;while(pos<s.size()){U value=0;for(U k=0;k<4;++k){if(pos>=s.size())throw std::domain_error("905 fourdigits");U c=std::uint8_t(s[pos++]),d=c<='9'&&c>='0'?c-'0':c>='A'&&c<='F'?c-'A'+10:c>='a'&&c<='f'?c-'a'+10:16;if(d>15)throw std::domain_error("905 hex");value=value*16+d;}if(!value)throw std::domain_error("905 nonzerocodeunit");values.push_back(value);if(pos<s.size()&&s[pos++]!=',')throw std::domain_error("905 commas");}if(values.empty()||values.size()>6||i.arg[4]<1||i.arg[4]>values.size()+1)throw std::domain_error("905 finitegrammar");U count=std::min(U(values.size()),i.arg[4]);for(U k=0;k<count;++k)m.w16(i.arg[3]+k*2,values[k]);m.w16(i.arg[3]+count*2,0);U consumed=std::min(U(s.size()),5*(count+1));U thread=platform::current_crt_thread(m.r32(0x817778));m.w32(thread+24,entry-0x5000+consumed);return count;}
}
