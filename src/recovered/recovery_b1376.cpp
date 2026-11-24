#include "recovery_b1376.hpp"
#include <stdexcept>
namespace ra2::recovered::b1376 {using U=std::uint32_t;
namespace {void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
U notify_72ccc0(U eax){return eax;} // PinnedC3, no inventedcallback.
}
U fun_005b2280(Memory&m,const Inputs&i){
 const U s=i.cx,n=m.r32(s+0x2b0u),start=m.r32(s+0x2b4u),capacity=m.r32(s+0x10u);
 need((i.arg[1]&0xffffu)==13&&i.arg[0]!=0&&m.r8(s+0x19u)==1,"1376 activeEnterevent");
 need(start==0&&n>=1&&n<=32&&capacity>=n+2&&capacity<=n+5,"1376 nonemptyboundedtextroom");
 need(m.r32(s+0x24u)==0&&m.r8(s+0x1au)==0&&m.r16(s+0x28u+2*n)==0,"1376 existingtextwithoutownedwidget");
 m.w16(s+0x28u+2*n,0x20);m.w32(s+0x2b0u,n+1);m.w16(s+0x28u+2*(n+1),0);
 m.w8(s+0x19u,0);(void)notify_72ccc0(n+1);m.w32(i.arg[0],0);return 3;
}
}
