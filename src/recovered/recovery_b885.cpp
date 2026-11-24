#include "recovered/recovery_b885.hpp"
namespace ra2::recovered::recovery_b885 {using U=std::uint32_t;
U fun_005698e0(Memory&m,const Inputs&i,ra2::platform::ordinary_heap::Heap&h){const U d=i.cx,s=i.arg[0],n=m.r32(s+8),p=m.r32(s+4);if(!d||!s||d==s||n<1||n>8||!p||m.r32(d)!=0x790ab8||m.r32(0x790ac4)!=0x567860||m.r32(d+4)||m.r8(d+13))throw std::domain_error("885 finite authentic emptyvector contract");m.w32(d+16,0);m.w32(d+8,0);m.w8(d+13,0);m.w32(d+8,n);U a=h.allocate(n*8);if(!a)throw std::domain_error("885 allocation success");m.w32(d+4,a);m.w8(d+13,1);for(U k=0;k<n*8;k+=4)h.w32(a+k,m.r32(p+k));return d;}
}
