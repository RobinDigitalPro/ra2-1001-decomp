#include "recovered/recovery_b1089.hpp"
#include "recovered/name_hash.hpp"
#include <stdexcept>
#include <vector>
namespace ra2::recovered::b1089 {
namespace {
void need(bool v){if(!v)throw std::domain_error("1089 positive loaded cache and authentic unopened local file");}
unsigned cached(Memory&m,unsigned name){
 need(m.r32(0xb10530u)==0u);std::vector<unsigned char>s;
 for(unsigned k=0;k<32u;++k){const auto c=m.r8(name+k);if(!c)break;need(c>=0x20u&&c<=0x7eu&&!(c>='a'&&c<='z'));s.push_back(static_cast<unsigned char>(c));}
 need(!s.empty()&&s.size()<32u);NameHashState state{};const auto key=fun_00493da0(state,s.data(),static_cast<int>(s.size()));auto owner=m.r32(0xa588e0u);
 for(unsigned chain=0;owner&&chain<2u;++chain){const auto next=m.r32(owner+4u);need(next&&m.r32(owner+8u));auto count=m.r32(owner+0x14u),table=m.r32(owner+0x20u);need(count==0u||count==4u);
  while(count){const auto middle=count/2u,entry=table+middle*12u,hash=m.r32(entry);if(global_b26::s32(hash)>global_b26::s32(key))count=middle;else if(hash==key){const auto backing=m.r32(owner+0x24u);need(backing);return backing+m.r32(entry+4u);}else{table=entry+12u;count-=middle+1u;}}owner=next;
 }throw std::domain_error("1089 genuine loaded positive fixed-name cache hit required");
}
unsigned initialize(Memory&m){
 need(m.r32(0x819778u)!=0u); // Original406F30 observes only this pointer predicate.
 constexpr unsigned names[]{0x7dc6c8u,0x7dc69cu,0x7dc670u};constexpr unsigned outputs[]{0xa9eab0u,0xa9eab8u,0xa9eac0u};
 for(unsigned n=0;n<3u;++n)m.w32(outputs[n],cached(m,names[n]));
 // Real468BF0/46F990/42F1F0/438140 give a local file with handle-1,
 // null owned buffers and zero ownership flags.438290/42F250/630060
 // call actual793C9C->630A70, whose full EAX is0. No API/free executes.
 need(m.r32(0x793c9cu)==0x630a70u);return 0u;
}
}
unsigned run(Memory&m,const Inputs&i,State&,unsigned root){
 need(root==0x25e8b0u||root==0x25ed70u);
 if(root==0x25e8b0u)return initialize(m);
 const auto self=i.cx;m.w32(self+4u,0u);m.w32(self+8u,0u);m.w32(self+12u,0u);m.w32(self+20u,0u);m.w32(self,0x794148u);
 initialize(m);m.w32(0xa9eaa8u,m.r32(0xa9eaa8u)+1u);m.w32(self,0x794160u);m.w8(self+16u,0u);m.w32(self+12u,cached(m,0x7d0844u));m.w32(self+4u,11u);m.w32(self+20u,i.arg[0]);m.w32(self+8u,21u);return self;
}
}
