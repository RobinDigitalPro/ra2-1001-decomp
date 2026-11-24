#include "recovered/recovery_b1109.hpp"
#include <string>
#include <vector>
#include <stdexcept>
namespace ra2::recovered::b1109{
static void need(bool v){if(!v)throw std::domain_error("1109 populated fixed session/player serializer");}
static std::string z(Memory&m,unsigned p){std::string s;for(unsigned j=0;j<64u;++j){auto x=m.r8(p+j);if(!x)return s;s+=char(x);}throw std::domain_error("1109 finite ASCII input");}
static std::vector<unsigned char>wide(Memory&m,unsigned p){std::vector<unsigned char>v;for(unsigned j=0;j<=8u;++j){auto lo=m.r8(p+2u*j),hi=m.r8(p+2u*j+1u);need(hi==0u);v.push_back(static_cast<unsigned char>(lo));v.push_back(0u);if(!lo){need(j>0u);return v;}need(j<8u&&lo<128u);}throw std::domain_error("1109 bounded nonempty wideASCII");}
static std::string decimal(unsigned x){bool neg=(x&0x80000000u)!=0u;unsigned n=neg?0u-x:x;std::string out;do{out.insert(out.begin(),char('0'+n%10u));n/=10u;}while(n);if(neg)out.insert(out.begin(),'-');return out;}
struct Strings{Heap&h;unsigned copy(const std::vector<unsigned char>&s){auto p=h.allocate(unsigned(s.size()));need(p);for(unsigned j=0;j<s.size();++j)h.w8(p+j,s[j]);return p;}unsigned copy(const std::string&s){std::vector<unsigned char>v(s.begin(),s.end());v.push_back(0u);return copy(v);}void free(unsigned p){need(h.release(p)!=0u);}};
// Complete430C60 transformation: consume source bits LSB first and insert1
// before each source bit numbered7,14,... . Output byte is initialized0.
static std::vector<unsigned char>packed(const std::vector<unsigned char>&w){const auto bits=unsigned(w.size())*8u;std::vector<unsigned char>out((bits+6u)/7u,0u);unsigned destination=0u;for(unsigned k=0;k<bits;++k){if(k&&k%7u==0u){out[destination/8u]|=static_cast<unsigned char>(1u<<(destination%8u));++destination;}if((w[k/8u]>>(k%8u))&1u)out[destination/8u]|=static_cast<unsigned char>(1u<<(destination%8u));++destination;}need(out.back()==0u);return out;}
static void write(Memory&m,unsigned p,const std::string&s){for(unsigned j=0;j<s.size();++j)m.w8(p+j,static_cast<unsigned char>(s[j]));m.w8(p+unsigned(s.size()),0u);}
unsigned run(unsigned root,Memory&m,const Inputs&i,Heap&h,State&){need(root==0x1b7b10u||root==0x331d10u);need(m.r32(0xb10530u)==0u&&m.r32(0x817554u)==0u&&m.r32(0xb10e14u)==0u);Strings strings{h};const auto wide_input=wide(m,0xa25672u);const auto w=strings.copy(wide_input);const auto encoded=packed(wide_input);const auto temporary=strings.copy(encoded);const auto copy=strings.copy(encoded);strings.free(temporary);const auto narrow=strings.copy(encoded);strings.free(copy);const auto retained=strings.copy(encoded);strings.free(narrow);strings.free(w);
 std::string map(encoded.begin(),encoded.end()-1),out;auto add=[&](unsigned x){if(!out.empty())out+=',';out+=decimal(x);};
 for(unsigned a:{0xa2897cu,0xa28758u,0xa255f8u,0xa255ecu,0xa25600u})add(m.r32(a));for(unsigned a:{0xa255f2u,0xa255f3u,0xa255f4u,0xa25670u,0xa255f1u})add(m.r8(a));add(m.r32(0xa255e0u));out+=','+map;for(unsigned a:{0xa25e4cu,0xa25e48u,0xa25e44u})add(a==0xa25e48u?m.r8(a):m.r32(a));out+=','+z(m,0xa25c20u)+','+z(m,0xa25e22u)+':';write(m,i.cx,out);
 const unsigned scratch=root==0x1b7b10u?0xa59764u:0xb0efb4u,count=m.r32(0xa27db8u),players=m.r32(0xa27dacu);need(count>=1u&&count<=4u);for(unsigned j=0;j<512u;++j)m.w8(scratch+j,0u);std::string body;
 for(unsigned j=0;j<count;++j){const auto p=m.r32(players+4u*j);const auto name_wide=wide(m,p);std::string name;for(unsigned k=0;k+2u<name_wide.size();k+=2u)name+=char(name_wide[k]);const auto first=m.r32(p+0x4du)==0xfffffffeu?0xfffffffeu:m.r32(p+0x49u),second=m.r32(p+0x55u)==0xfffffffeu?0xfffffffeu:m.r32(p+0x51u);unsigned owned=0u;
  if(root==0x1b7b10u){auto cursor=m.r32(0xab7edcu);need(cursor<8u);const auto target=0xaa8decu+1024u*cursor;write(m,target,name);m.w8(target+1023u,0u);m.w32(0xab7edcu,(cursor+1u)&7u);}
  else{const auto player_w=strings.copy(name_wide),low=strings.copy(name),copied=strings.copy(name);strings.free(low);owned=strings.copy(name);strings.free(copied);strings.free(player_w);}
  body+=name+','+decimal(first)+','+decimal(second)+',';write(m,scratch,body);if(owned)strings.free(owned);
 }
 need(!body.empty()&&body.back()==',');body.back()=':';body+="@:";write(m,scratch,body);for(unsigned j=0;j<8u;++j){body+=decimal(m.r32(0xa2560cu+4u*j))+','+decimal(m.r32(0xa2562cu+4u*j))+','+decimal(m.r32(0xa2564cu+4u*j))+',';write(m,scratch,body);}need(body.size()<512u&&out.size()+body.size()<1024u);write(m,i.cx,out+body);return h.release(retained);
}
}
