#include "objects_b99.hpp"
#include "rng_b70.hpp"
#include "leaf_b15_a.hpp"
#include "leaf_b15_d.hpp"
#include "leaf_b17_fields.hpp"
#include "ini_text.hpp"
#include "name_hash.hpp"
#include <array>
#include <cstddef>
#include <cstdint>
#include <stdexcept>
namespace ra2::recovered::global_b26 {std::uint32_t fun_006dd700(Memory&,const Inputs&);}
namespace ra2::recovered::objects_b99 {
using U=std::uint32_t;using global_b26::s32;using global_b26::sar;using global_b26::imul_high;
namespace {
U remap_linked_nodes(Memory&m,U head,leaf::Memory& scratch,U base){
 std::array<U,4> original{};U p=head;std::size_t count=0;
 while(p){if(count==original.size())throw std::domain_error("Block99 list exceeds four-node bound");
  for(std::size_t j=0;j<count;++j)if(original[j]==p)throw std::domain_error("Block99 list is cyclic");
  original[count++]=p;p=m.r32(p);}
 scratch.w32(base+0x20u,count?base+0x100u:0u);
 for(std::size_t j=0;j<count;++j){const U q=base+0x100u+U(j)*0x100u;const U next=j+1<count?q+0x100u:0u;
  scratch.w32(q,next);const U sentinel=m.r32(original[j]+8u);U mapped=0;
  for(std::size_t k=0;k<count;++k)if(original[k]==sentinel)mapped=base+0x100u+U(k)*0x100u;
  scratch.w32(q+8u,mapped);}
 return U(count);
}
U list_call(Memory&m,U header,U node,bool first){
 constexpr U base=0x35000000u;std::array<std::uint8_t,0x600> bytes{};leaf::Memory scratch(bytes.data(),base,bytes.size());
 const U count=remap_linked_nodes(m,m.r32(header),scratch,base);leaf::Inputs q{};q.cx=first?base+0x20u:0u;
U index=0;if(!first){U original=m.r32(header);for(;index<count&&original!=node;++index)original=m.r32(original);if(index==count)return 0;q.cx=base+0x100u+index*0x100u;}
 const U result=first?leaf::fun_004072f0(scratch,q):leaf::fun_00407310(scratch,q);
 if(!result)return 0;for(U k=0;k<count;++k)if(result==base+0x100u+k*0x100u){U p=m.r32(header);while(k--)p=m.r32(p);return p;}return 0;
}
U mark_child(Memory&m,U r){U child=m.r32(r),flags=m.r32(child+0x18)|0x60;m.w32(child+0x18,flags);m.w32(r,0);m.w32(r+8,0);return flags;}
U ini_hash_callback(const std::uint8_t* text,std::size_t n,void*){NameHashState state{};return fun_00493da0(state,text,n);}
}
std::uint32_t fun_004035f0(Memory&m,const Inputs&i){
 const U key=i.dx==0xffffffff?1:i.dx;U primary=0,secondary=0,priority=127,other_priority=127,age=0xffffffff;
 for(U p=list_call(m,i.cx+0xf8u,0,true);p;p=list_call(m,i.cx+0xf8u,p,false)){
  if(m.r32(p+0xc)!=key)continue;const U flags=m.r8(p+0xa4),v=m.r32(p+0xa0);if(!(flags&0x15))return p;
  if(flags&1){const U candidate_age=m.r32(p+0xdc);if(s32(v)<s32(priority)||(v==priority&&candidate_age<age&&age-candidate_age>=0x666)){primary=p;priority=v;age=candidate_age;}}
  else if(s32(v)<s32(other_priority)){secondary=p;other_priority=v;}
 }
 return secondary&&s32(other_priority)<=s32(priority)?secondary:primary;
}
std::uint32_t fun_00405fe0(Memory&m,const Inputs&i){return mark_child(m,i.cx);}
std::uint32_t fun_00406070(Memory&m,const Inputs&i){return mark_child(m,i.cx);}
std::uint32_t fun_0042e940(Memory&m,const Inputs&i){
 for(U k=0;k<24;++k){const U p=m.r32(i.cx+4*k);if(p&&(m.r8(p+0xc)&2)){const U owner=m.r32(p+0x110);if(owner==m.r32(m.r32(0xa1e0e4)+0x30))throw std::domain_error("42e940 deletion route excluded");m.w8(p+0xc,m.r8(p+0xc)&0xfc);return owner;}}
 throw std::domain_error("42e940 requires a selected entry");
}
std::uint32_t fun_0044c550(Memory&m,const Inputs&i){
 const U r=i.cx,index=m.r8(r+0x5c6);if(m.r32(r+0x478))throw std::domain_error("44ccc0 callback excluded");
 m.w32(r+0x4bc+4*index,0);m.w8(r+0x5c6,0);m.w32(r+0x4d0,0xffffffff);return 1;
}
std::uint32_t fun_00524f30(Memory&m,const Inputs&i){
 const U r=i.cx,count=m.r32(r+0x44);for(U k=0;k<count;++k){const U p=m.r32(r+0x28+4*k),obj=m.r32(m.r32(0xa1a5cc)+4*m.r32(p+0x60));if(!obj||obj==m.r32(0xa1e0e4))continue;
  const U out=0xa258f4+0x68*k,fields=m.r32(p+4);if(!m.r8(out-0x40))throw std::domain_error("524f30 random route excluded");
  std::array<std::uint8_t,0x40> bytes{};constexpr U base=0x35000000u;leaf::Memory scratch(bytes.data(),base,bytes.size());
  scratch.w32(base+0x20u,m.r32(fields+0x20u));scratch.w32(base+0x1cu,m.r32(fields+0x1cu));leaf::Inputs scalar{};scalar.cx=base;
  U x=leaf::fun_004805e0(scratch,scalar)*1000u;U h=sar(imul_high(0x88888889u,x)+x,5);h+=h>>31;U old=m.r32(out);m.w32(out,s32(old)>s32(h)?old:h);
  U y=leaf::fun_004805d0(scratch,scalar)*1000u;U scaled=U((std::uint64_t(0x88888889u)*y)>>32)>>5;old=m.r32(out+0x10);m.w32(out+0x10,s32(scaled)>s32(old)?scaled:old);
  m.w32(out+4,m.r32(p+8));m.w32(out+8,m.r32(p+0xc));m.w32(out+0xc,m.r32(p+0x10));
 }return count;
}
std::uint32_t fun_00609a00(Memory&m,const Inputs&i){
 const U r=i.cx,d=i.arg[0];if(m.r8(d+0xc)){m.w8(d+0xc,0);U c=m.r32(r+0xa8)-1;m.w32(r+0xa8,c);if(!c)m.w32(r+0xb0,0xffffffff);}
 U result=m.r32(d+8);if(result!=0xffffffff){result=m.r32(m.r32(r+0x24)+4*result);m.w32(result+0x74,0xffffffff);m.w32(r+0xb4,0xffffffff);U count=m.r32(result+0x70)-1;m.w32(result+0x70,count);
  if(!count){result=(result&0xffffff00u)|m.r8(r+0x1c);if(!(result&255)){m.w8(r+0x1c,1);const U n=m.r32(0xa5e2c0);if(s32(n)>=s32(m.r32(0xa5e2b8)))throw std::domain_error("609a00 growth excluded");result=n;m.w32(0xa5e2c0,n+1);m.w32(m.r32(0xa5e2b4)+4*n,r);}}
 }m.w32(d+8,0xffffffff);return result;
}
std::uint32_t fun_00694210(Memory&m,const Inputs&i){
 const U r=i.cx,nested=m.r32(r+0x24);m.w8(r+0x57,0);m.w32(r+0x5c,0xffffffff);m.w32(r+0x2c,m.r32(0xa2896c));m.w32(r+0x30,i.stack_minus8);m.w32(r+0x34,m.r32(nested+0xb0));return r+0x2c;
}
std::uint32_t fun_006ae200(Memory&m,const Inputs&i){
 const U r=i.cx,parent=m.r32(r+0x24),data=m.r32(parent+0xdc),old=m.r8(r+0x7a),actual=m.r32(r+0x48);
 const U count=m.r32(data+0x9c);if(count>32u)throw std::domain_error("Block99 inventory count exceeds bounded helper span");
 std::array<std::uint8_t,0x200> bytes{};constexpr U base=0x35000000u;leaf::Memory scratch(bytes.data(),base,bytes.size());
 scratch.w32(base+0x9cu,count);for(U k=0;k<count;++k)scratch.w32(base+0xa4u+8u*k,m.r32(data+0xa4u+8u*k));leaf::Inputs accepted{};accepted.cx=base;
 const U sum=leaf::fun_006ac180(scratch,accepted);
 const bool equal=actual==sum;m.w8(r+0x79,equal);if(equal)m.w8(r+0x78,1);
 U status;if(m.r8(parent+0xab))status=s32(sum)>2?s32(actual)<=s32(global_b26::idiv_quotient(sum,3)):s32(actual)<s32(sum);else status=!m.r8(r+0x78);
 m.w8(r+0x7a,status);if(m.r8(parent+0xa7))m.w8(r+0x76,!status);m.w8(r+0x7e,0);m.w8(r+0x7d,0);if(old!=status)m.w8(r+0x7b,1);return 1;
}
std::uint32_t fun_006dd040(Memory&m,const Inputs&i){
 const U r=i.cx;for(U attempt=1;attempt<=1000;++attempt){floating_b61::Inputs rng{};rng.cx=0x821558;rng.arg[0]=0;rng.arg[1]=m.r32(r+0x24)-1;U index=rng_b70::fun_0062fe40(m,rng);if(attempt==1000)return 0;Inputs check{};check.cx=r;check.arg[0]=index;if(global_b26::fun_006dd700(m,check)&255)return index;}return 0;
}
}
