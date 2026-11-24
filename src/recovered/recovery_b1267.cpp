#include "recovered/recovery_b1267.hpp"
#include <stdexcept>
namespace ra2::recovered::b1267{namespace{void need(bool b){if(!b)throw std::domain_error("1267 genuine populated supplied-buffer front insertion");}}
unsigned run(unsigned root,Memory&m,const Inputs&i){const auto v=i.cx+0x18u;need(root==0x1af9b0u&&m.r32(v)==0x79202cu&&m.r32(v+8u)==10u&&m.r32(v+16u)==1u&&m.r8(v+12u)==1u&&m.r8(v+13u)==0u&&i.arg[0]!=0u&&i.arg[1]==0u);const auto data=m.r32(v+4u);/* Actual5B0730 Find ofpublicarg1NULL visits the one nonnullentry, returnsFFFFFFFF. */const auto prior=m.r32(data);need(prior!=0u);/* Actual76EBD0 copies4B fromdata todata+4:adjacent,nonoverlapping. */m.w32(data+4u,prior);m.w32(data,i.arg[0]);m.w32(v+16u,2u);/* Original overwritespublicarg0 witharg1 before nullable deletion test. */i.arg[0]=i.arg[1];return i.arg[1];}
}
