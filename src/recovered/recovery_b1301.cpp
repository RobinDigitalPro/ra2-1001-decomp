#include "recovery_b1301.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b1301 {
namespace {void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
unsigned coordinate(Memory&m,unsigned object){need(m.r32(object)==0x78612cu&&m.r32(0x786174u)==0x5cd4d0u,"1301 original coordinate getter");
 const int x=std::int32_t(m.r32(object+0x88u))/256,y=std::int32_t(m.r32(object+0x8cu))/256;(void)m.r32(object+0x90u);
 need(x>=1&&x<=8&&y>=256&&y<=263,"1301 finite positive coordinate range");return unsigned(x)|(unsigned(y)<<16u);
}
unsigned valid(Memory&m,unsigned object){const auto p=coordinate(m,object),x=p&65535u,y=p>>16u;const auto cell=m.r32(m.r32(0x81a958u)+4u*(x+512u*y));need(cell&&m.r32(cell+0xecu)==5u,"1301 actual already-valid map cell");return p;}
}
std::uint32_t fun_004cb4f0(Memory&m,const Inputs&i){const auto p=valid(m,i.cx);m.w32(i.arg[0],p);return i.arg[0];}
std::uint32_t fun_004cb430(Memory&m,const Inputs&i){need(m.r32(i.cx+0x494u)==0u,"1301 original enabled route");const auto p=valid(m,i.cx);i.arg[0]=p;i.arg[1]=p;
 need(m.r32(0x84e230u)!=p,"1301 valid coordinate differs from original sentinel");const auto again=coordinate(m,i.cx);need(p==again,"1301 actual current-coordinate match");return ((again>>16u)&0xffffff00u)|1u;
}
}
