#include "recovered/recovery_b868.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b868 {
namespace {using U=std::uint32_t;U list(platform::ordinary_heap::Heap&h,U count,U item){const U stride=item+8;const U p=h.allocate(count*stride+8);if(!p)throw std::domain_error("868 successful list allocation");h.w32(p,p+8);for(U k=0;k<count;++k)h.w32(p+8+k*stride,k+1<count?p+8+(k+1)*stride:0);return p;}}
std::uint32_t fun_004019e0(Memory&,const Inputs&i,platform::ordinary_heap::Heap&h){if(i.arg[1]>128)throw std::domain_error("868 secondargument bound");const auto item=i.arg[1]+28;const auto n=global_b26::s32(i.dx)/std::int32_t(item);if(n<1||n>8||i.arg[0]<1||i.arg[0]>8)throw std::domain_error("868 bounded positive factory");auto p=h.allocate(232);if(!p)throw std::domain_error("868 successful owner allocation");for(U k=0;k<232;k+=4)h.w32(p+k,0);h.w32(p,i.cx);h.w32(p+24,i.arg[1]);h.w32(p+4,list(h,U(n),item));h.w32(p+8,list(h,i.arg[0],100));for(U k:{12u,16u,20u})h.w32(p+k,p+12);return p;}
}
