#include "recovered/recovery_b1115.hpp"
#include <string>
#include <stdexcept>
namespace ra2::recovered::b1115{
static void need(bool v){if(!v)throw std::domain_error("1115 genuine warm reset static literal StringClass vectors");}
static std::string literal(Memory&m,unsigned p){std::string s;for(unsigned n=0;n<32u;++n){const auto x=m.r8(p+n);if(!x)return s;s+=char(x);}throw std::domain_error("1115 fixed nonempty original literal");}
static std::string owned(Heap&h,unsigned p){need(p);std::string s;for(unsigned n=0;n<32u;++n){const auto x=h.r8(p+n);if(!x)return s;s+=char(x);}throw std::domain_error("1115 finite owned StringClass");}
static unsigned copy(Heap&h,const std::string&s){need(!s.empty());const auto p=h.allocate(unsigned(s.size())+1u);need(p);for(unsigned n=0;n<=s.size();++n)h.w8(p+n,n<s.size()?unsigned(static_cast<unsigned char>(s[n])):0u);return p;}
unsigned run(unsigned root,Memory&m,const Inputs&,Heap&h,State&){need(root==0x340940u&&m.r8(0xb100f0u)==0u&&m.r8(0xb0fcd4u)==1u&&m.r32(0x817554u)==0u&&m.r32(0xb10e14u)==0u);constexpr unsigned headers[]{0xb0e490u,0xb0dfe0u,0xb0ee90u,0xb0e870u,0xb0e3c0u,0xb0fba0u,0xb0dff0u,0xb0e720u};for(auto v:headers){need(m.r32(v)==0u&&m.r32(v+4u)==10u&&m.r32(v+8u));for(unsigned k=0;k<10u;++k)need(h.r32(m.r32(v+8u)+4u*k)==0u);}
 for(unsigned n=0;n<16u;++n){const auto field=0xb0ecb0u+4u*n;const auto s=literal(m,0x7e8138u-12u*n);need(s.size()==11u&&owned(h,m.r32(field))==s);need(h.release(m.r32(field))!=0u);m.w32(field,0u);m.w32(field,copy(h,s));}
 // Original first thirteen calls insert at zero. The final three inline
 // insertions have count zero after reset and select that same valid index.
 constexpr unsigned group[]{0u,0u,0u,2u,2u,2u,1u,1u,1u,3u,3u,3u,4u,6u,5u,7u};
 for(unsigned n=0;n<16u;++n){const auto v=headers[group[n]],count=m.r32(v),data=m.r32(v+8u);need(count<10u);for(unsigned j=count;j>0u;--j)h.w32(data+4u*j,h.r32(data+4u*(j-1u)));const auto p=copy(h,owned(h,m.r32(0xb0ecb0u+4u*n)));h.w32(data,p);m.w32(v,count+1u);}
 m.w8(0xb100f0u,1u);return m.r32(0xb0e720u); // Original MOV count, INC => full EAX1.
}
}
