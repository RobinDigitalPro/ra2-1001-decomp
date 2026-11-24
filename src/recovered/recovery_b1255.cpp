#include "recovered/recovery_b1255.hpp"
#include <stdexcept>
namespace ra2::recovered::b1255{namespace{void need(bool b){if(!b)throw std::domain_error("1255 positive genuine loaded pre-render timeline");}}
unsigned run(unsigned root,Memory&m,const Inputs&i){need(root==0x290ac0u);const auto self=i.cx,group=m.r32(self),time=i.arg[0];need(group&&m.r32(group)==0x79703cu&&m.r32(group+16u)==2u&&m.r32(self+12u)==0u&&m.r32(self+16u)==0u&&time<120u);auto index=m.r32(self+4u);need(index<=1u);const auto data=m.r32(group+4u);unsigned changed=0u;while(index<2u){const auto record=m.r32(data+4u*index);if(m.r32(record)>time)break;++index;m.w32(self+8u,record);m.w32(self+4u,index);/* Actual690BA0 trueNULLsurface guard returns without font/API/rectangle effects. */changed=1u;}unsigned eax=m.r32(self+8u);if(eax&&time>=m.r32(eax)+m.r32(eax+4u)){m.w32(self+8u,0u);/* Originalreloads actualcallbackC0 then findsactualsurface10NULL. */eax=0u;}return(eax&0xffffff00u)|changed;}
}
