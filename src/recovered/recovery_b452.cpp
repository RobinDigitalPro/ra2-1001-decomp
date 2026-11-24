#include "recovered/recovery_b452.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::recovery_b452 {
namespace {
using U=std::uint32_t;
U length(Memory&m,U p){if(!p)throw std::domain_error("B452 nonempty initialized locale strings");for(U n=0;n<128;++n)if(!m.r8(p+n))return n;throw std::domain_error("B452 finite locale span");}
U allocate(Heap&h,U bytes){if(bytes<=1016||bytes>4096)throw std::domain_error("B452 original ordinary-heap range");const auto p=h.allocate(bytes);if(!p)throw std::domain_error("B452 successful allocation route");return p;}
void copy(Memory&m,Heap&h,U dst,U src,U len){for(U k=0;k<=len;++k)h.w8(dst+k,m.r8(src+k));}
}
std::uint32_t fun_0077f757(Memory&m,const Inputs&,Heap&h){
 const auto table=m.r32(0x818690);std::array<U,24> strings{},sizes{};U total=25;
 for(U k=0;k<12;++k)for(U side=0;side<2;++side){const U n=2*k+side;strings[n]=m.r32(table+0x38+4*k+side*0x30);sizes[n]=length(m,strings[n]);total+=sizes[n];}
 const auto result=allocate(h,total);U cursor=result;
 for(U k=0;k<24;++k){h.w8(cursor++,':');copy(m,h,cursor,strings[k],sizes[k]);cursor+=sizes[k];}
 h.w8(cursor,0);return result;
}
std::uint32_t fun_0077f7ec(Memory&m,const Inputs&,Heap&h){
 const auto table=m.r32(0x818690);std::array<U,43> strings{},sizes{};U total=0xac+43;
 for(U k=0;k<43;++k){strings[k]=m.r32(table+4*k);sizes[k]=length(m,strings[k]);total+=sizes[k];}
 const auto result=allocate(h,total);for(U k=0;k<0xac;++k)h.w8(result+k,m.r8(table+k));U cursor=result+0xac;
 auto append=[&](U index){h.w32(result+4*index,cursor);copy(m,h,cursor,strings[index],sizes[index]);cursor+=sizes[index]+1;};
 for(U k=0;k<7;++k){append(k);append(k+7);}
 for(U k=0;k<12;++k){append(k+14);append(k+26);}
 for(U k=38;k<42;++k)append(k);
 // Original reserves length of field42 but only stores its destination pointer.
 h.w32(result+0xa8,cursor);return result;
}
}
