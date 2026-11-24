#pragma once
#include <algorithm>
#include <string>
#include <vector>
#include <stdexcept>
namespace ra2::platform::warm_palette1095 {
namespace b=b1095_test;
inline void need(bool x,const char*s){if(!x)throw std::domain_error(s);}
// Independent polynomial hash: reverse weighted sum, rather than model recurrence.
inline unsigned polynomial(const std::string&s){unsigned v=0u,p=1u;for(auto j=s.rbegin();j!=s.rend();++j){v=(v+unsigned(*j)*p)%31u;p=p*26u%31u;}return v;}
struct World{
 unsigned root,base; b::Case c;std::string key,query;unsigned bucket=0u,winner=0u;std::vector<std::string> names;
 World(unsigned r,unsigned a,b::Case v):root(r),base(a),c(v){
  key="CACHE_"+std::to_string(c.seed%997u)+"_X";query=key;
  if(root==0x31f0d0u){if(c.seed&1u){key[0]='c';query=key;}winner=c.hit;names.resize(c.count);for(unsigned j=0;j<c.count;++j)names[j]=key+"_"+std::to_string(j);names[winner]=key;if(c.duplicate)names[winner+1u]=key;else if(winner>0u){names[0]=key;names[0][0]=key[0]=='C'?'c':'C';}}
  else{bucket=polynomial(key);for(unsigned j=0;j<query.size();++j)if((c.seed+j)&1u)if(query[j]>='A'&&query[j]<='Z')query[j]=char(query[j]+32);winner=c.duplicate?c.count-2u:c.hit;names.resize(c.count);unsigned k=0u;for(unsigned j=0;j<c.count;++j){std::string s;do{s="OTHER_"+std::to_string(k++);}while(polynomial(s)!=bucket||s==key);names[j]=s;}names[winner]=key;if(c.duplicate)names[winner-1u]=key;}
 }
 unsigned returned(unsigned j)const{return base+(root==0x31f0d0u?0x20000u+0x400u*j:0xb000u+32u*j);}
 b::Inputs input()const{b::Inputs i{};i.ax=0xa1250000u^c.seed;i.dx=0x19b753d0u+c.seed;for(unsigned j=0;j<16u;++j)i.arg[j]=0xf00d0000u^(c.seed*131u+j*0x10203u);i.cx=base+(root==0x31f0d0u?0x400u:0x300u);if(root==0x31f0d0u)i.arg[0]=base+0x200u;return i;}
 void setup(b::Memory&m,unsigned char*arena)const{
  for(unsigned j=0;j<0x100000u;++j)arena[j]=static_cast<unsigned char>(c.seed*17u+j*131u+(j>>4u));
  auto str=[&](unsigned p,const std::string&s){for(unsigned j=0;j<s.size();++j)m.w8(p+j,unsigned(s[j]));m.w8(p+unsigned(s.size()),0u);};str(base+0x300u,query);m.w32(0xb10530u,0u);
  if(root==0x31f0d0u){m.w32(base+0x200u,base+0x300u);m.w32(base+0x400u,0x79a07cu);m.w32(base+0x4bcu,0x79a08cu);m.w32(base+0x4c0u,base+0x1000u);m.w32(base+0x4c4u,10u);m.w8(base+0x4c8u,1u);m.w8(base+0x4c9u,0u);m.w32(base+0x4ccu,c.count);m.w32(base+0x4d0u,10u);for(unsigned j=0;j<c.count;++j){const auto rec=base+0x2000u+8u*j;str(base+0x3000u+64u*j,names[j]);m.w32(base+0x1000u+4u*j,rec);m.w32(rec,base+0x3000u+64u*j);m.w32(rec+4u,returned(j));}}
  else{m.w32(0xa5df68u,base+0x400u);m.w32(base+0x40cu,base+0x500u);m.w32(base+0x500u,base+0x1000u);m.w32(base+0x504u,0x5fb1f0u);m.w32(base+0x508u,31u);m.w32(base+0x50cu,10u);m.w32(base+0xffcu,31u);for(unsigned j=0;j<31u;++j){const auto p=base+0x1000u+24u*j;m.w32(p,0x792b38u);m.w32(p+4u,0u);m.w32(p+8u,0u);m.w8(p+12u,1u);m.w8(p+13u,0u);m.w32(p+16u,0u);m.w32(p+20u,10u);}const auto b=base+0x1000u+24u*bucket;m.w32(b+4u,base+0x3000u);m.w32(b+8u,10u);m.w32(b+16u,c.count);for(unsigned j=0;j<c.count;++j){str(base+0x3000u+260u*j,names[j]);m.w32(base+0x3000u+260u*j+256u,base+0x8000u+260u*j);str(base+0x8000u+260u*j,"Original_"+names[j]);m.w32(base+0x8000u+260u*j+256u,returned(j));}}
 }
 void verify(unsigned eax,const ra2::platform::x87::Image&beforefp,const ra2::platform::x87::Image&afterfp,const std::vector<unsigned char>&beforeimage,const std::vector<unsigned char>&beforearena,const unsigned char*image,const unsigned char*arena)const{
  // Winner is a construction label, independent of a second search implementation.
  need(eax==returned(winner),"1095 full raw borrowed return identity");need(eax>=base&&eax+(root==0x31f0d0u?0x400u:24u)<=base+0x100000u,"1095 complete borrowed extent");need(std::equal(beforeimage.begin(),beforeimage.end(),image),"1095 entire original image immutable");need(std::equal(beforearena.begin(),beforearena.end(),arena),"1095 entire arena including opaque payloads immutable");need(ra2::platform::x87::same_numeric(beforefp,afterfp),"1095 independent full numeric FP unchanged");
 }
};
}
