#include "recovered/recovery_b1250.hpp"
#include <stdexcept>
namespace ra2::recovered::b1250{namespace{void need(bool b){if(!b)throw std::domain_error("1250 finite genuine linkedInfantry coordinate query");}
unsigned cell(Memory&m,unsigned actor){const auto x=m.r32(actor+0x88u),y=m.r32(actor+0x8cu);need(x>=5120u&&x<5376u&&y>=5120u&&y<5376u);const auto index=((y>>8u)<<9u)+(x>>8u),cap=m.r32(0x81a95cu),table=m.r32(0x81a958u);need(index==10260u&&cap==0x40000u);const auto p=m.r32(table+4u*index);need(p&&m.r32(p)==0x788b04u);return p;}
}
unsigned run(unsigned root,Memory&m,const Inputs&i){need(root==0x1ff810u);const auto self=i.cx,target=m.r32(self+0x28u),owner=m.r32(self+0x24u);need(m.r32(self)==0x792c58u&&target&&owner&&m.r32(target)==0x78e540u&&m.r32(owner)==0x78e540u);/* True54=4CCA70 tail5CDAA0:74clear returnsAL0 withoutheightcallback. */need(m.r8(target+0x74u)==0u);/* True80=6B6910 tail84=505DA0 -> actualType5A8. */const auto type=m.r32(owner+0x5a8u);need(m.r32(type)==0x78ea78u&&m.r8(type+0xadau)==0u);/* True2C=508C50 returns15, so kind1 path is not reached. */const auto a=cell(m,target),z=cell(m,target);need(a==z&&m.r32(z+0xecu)==0u);const auto out=i.arg[0];m.w32(out,m.r32(target+0x88u));m.w32(out+4u,m.r32(target+0x8cu));m.w32(out+8u,m.r32(target+0x90u));return out;}
}
