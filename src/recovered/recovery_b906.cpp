#include "recovered/recovery_b906.hpp"
#include "recovered/name_hash.hpp"
#include "platform/current_crt_thread.hpp"
#include <cstdint>
#include <stdexcept>
#include <string>
namespace ra2::recovered::recovery_b906 {
namespace {
using U=std::uint32_t;
struct IndexView {U address;};
void need(bool v,const char* why){if(!v)throw std::domain_error(why);}
std::string text(const Memory&m,U p,U limit=128){need(p,"906 null text");std::string s;for(U k=0;k<limit;++k){U c=m.r8(p+k);if(!c)return s;s.push_back(char(c));}throw std::domain_error("906 bounded text");}
U hash(const std::string&s){return ini_name_hash(reinterpret_cast<const std::uint8_t*>(s.data()),s.size(),nullptr);}
U lookup(Memory&m,IndexView index,U query){
 const U ix=index.address,table=m.r32(ix),count=m.r32(ix+4),capacity=m.r32(ix+8),sorted=m.r8(ix+12),cached=m.r32(ix+16);
 need(table&&count&&count<=19&&capacity>=count&&sorted,"906 initialized sorted raw index");
 if(cached&&m.r32(cached)==query)return m.r32(cached+4);
 U lo=0,hi=count;
 while(lo<hi){const U mid=lo+(hi-lo)/2,row=table+mid*8,key=m.r32(row);if(key==query){m.w32(ix+16,row);return m.r32(row+4);}if(global_b26::s32(key)<global_b26::s32(query))lo=mid+1;else hi=mid;}
 throw std::domain_error("906 bounded route requires every Powerups row");
}
std::uint32_t signed_decimal(const std::string&s){
 need(!s.empty()&&s.size()<=4,"906 one signed decimal token length");
 U pos=0;bool negative=false;if(s[pos]=='-'){negative=true;++pos;}need(pos<s.size(),"906 sign without digits");
 U magnitude=0;for(;pos<s.size();++pos){const U c=std::uint8_t(s[pos]);need(c>='0'&&c<='9',"906 no whitespace or additional token");magnitude=magnitude*10+(c-'0');need(magnitude<=999,"906 decimal range -999..999");}
 return negative?0u-magnitude:magnitude;
}
}
std::uint32_t fun_00644540(Memory&m,const Inputs&i,U entry_esp){
 // The sole stack argument is an initialized raw sorted-index receiver. The
 // ABI slot is not asserted to be a named proprietary class.
 const U receiver=i.arg[0];need(receiver,"906 nonnull INI receiver argument");
 const std::string section_name=text(m,m.r32(0x793f3cu));need(section_name=="Powerups","906 original Powerups section name");
 const U section=lookup(m,{receiver+0x20u},hash(section_name));need(section,"906 Powerups section hit");
 U last_length=0;
 for(U k=0;k<19;++k){
  const U key_va=m.r32(0x788e54u+4u*k);const std::string key=text(m,key_va);
  const U value=lookup(m,{section+0x2cu},hash(key));
  const U string_pointer=m.r32(value+0x10);const std::string value_text=text(m,string_pointer);
  // Original 0x6e41d0 trim is a no-op on this digit-only token. Its first
  // strtok token is the full signed decimal; three later strtok(NULL, ",")
  // calls return null, so optional integer/bool/float outputs are untouched.
  const U parsed=signed_decimal(value_text);
  m.w32(0x7bea10u+4u*k,parsed);
  last_length=U(value_text.size());
 }
 const U thread=platform::current_crt_thread(m.r32(0x817778u));
 // Root buffer is entry ESP-0x80; the terminal strtok cursor is its NUL byte.
 m.w32(thread+0x18u,entry_esp-0x80u+last_length);
 // Final strtok(NULL, ",") returns null, leaving EAX=0; MOV AL,1 yields 1.
 return 1u;
}
}
