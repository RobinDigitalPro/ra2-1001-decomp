#include "recovered/recovery_b1630.hpp"
#include "platform/observed_inactive1629.hpp"
#include <stdexcept>
namespace ra2::recovered::b1630 {
namespace {
void need(bool v){if(!v)throw std::domain_error("1630 finite nonempty first-slot flag update domain");}
U lower(U c){return c>='A'&&c<='Z'?c+32u:c;}
void domain(Memory&m,const Inputs&i){need(i.cx!=0u&&i.dx==1u&&m.r32(0xa27db8u)==1u);const U list=m.r32(0xa27dacu),record=m.r32(list),query=i.cx;const U addresses[]{list,record,query},sizes[]{4u,0x69u,8u};for(U k=0;k<3u;++k){const auto lo=std::uint64_t(addresses[k]),end=lo+sizes[k];need(lo>=0x10000000u&&end<=0x70000000u);(void)m.r8(addresses[k]);(void)m.r8(U(end-1u));for(U j=0;j<k;++j)need(end<=addresses[j]||std::uint64_t(addresses[j])+sizes[j]<=lo);}constexpr char name[]="PlayerA";for(U k=0;k<8u;++k)need(m.r8(query+k)==U(name[k])&&m.r16(record+2u*k)==U(name[k]));need(m.r32(record+0x65u)==0u&&m.r16(0xa2793eu)==0u&&m.r32(0xab7edcu)==0u&&m.r32(0xab7ee0u)==0u&&m.r32(0xb10530u)==0u&&m.r32(0xb0d84cu)==0u&&m.r32(0xb0d850u)==0u&&m.r32(0xb0d858u)==0u);}
U widen(Memory&m,U src){if(!src)return 0u;const U out=0xaace7cu+(m.r32(0xab7ee0u)<<11u);U dst=out,left=0x400u;while(m.r8(src)&&left){m.w16(dst,m.r8(src));dst+=2u;++src;--left;}m.w16(dst,0u);m.w16(out+0x7feu,0u);m.w32(0xab7ee0u,(m.r32(0xab7ee0u)+1u)&7u);return out;}
U wide_compare(Memory&m,U a,U b){for(;;a+=2u,b+=2u){const U x=m.r16(a),y=m.r16(b);if(x!=y)return x<y?0xffffffffu:1u;if(!y)return 0u;}}
U narrow(Memory&m,U src){if(!src)return 0u;const U out=0xaa8decu+(m.r32(0xab7edcu)<<10u);U dst=out,left=0x400u;while(m.r16(src)&&left){m.w8(dst,m.r8(src));++dst;src+=2u;--left;}m.w8(dst,0u);m.w8(out+0x3ffu,0u);m.w32(0xab7edcu,(m.r32(0xab7edcu)+1u)&7u);return out;}
U compare(Memory&m,U a,U b){need(m.r32(0xb10530u)==0u);for(;;){const U x=m.r8(a++),y=m.r8(b++);if(x==y){if(!x)return 0u;continue;}const U lx=lower(x),ly=lower(y);if(lx!=ly)return lx<ly?0xffffffffu:1u;if(!lx)return 0u;}}
U inactive_child(Memory&m){U dialog=m.r32(0xb0d84cu);const U kind=m.r32(0xb0d850u);need(kind!=0xbcu&&kind!=0xbdu);need(m.r32(0xb0d858u)==0u); // Actual72A570 count0 returns0; class/ancestor provider not reached.
dialog=m.r32(0xb0d84cu);const HWND out=ra2::platform::inactive1629::Trace::get(reinterpret_cast<HWND>(std::uintptr_t(dialog)),0x53e);if(!dialog)return U(reinterpret_cast<std::uintptr_t>(out));need(false);return 0u;}
}
U fun_005b7d80(Memory&m,const Inputs&i){domain(m,i);const U name=i.cx;U flag=i.dx; // NonNULLquery excludes optional72A500/5C5930 control initializer.
const U wide=widen(m,name);if(wide_compare(m,wide,0xa2793eu)==0u)flag=1u;U index=0u;const U count=m.r32(0xa27db8u);for(;index<count;++index){const U record=m.r32(m.r32(0xa27dacu)+index*4u);const U converted=narrow(m,record);if(compare(m,converted,name)==0u)break;}if(index<count&&index!=0xffffffffu){const U record=m.r32(m.r32(0xa27dacu)+index*4u);m.w32(record+0x65u,flag);}
// ActualRoot restoresits3savednonvolatiles andTAILJMPs child. Returntheactual
// full GetDlgItem HWND bits; no parentconstantEAX reload as in B1629.
return inactive_child(m);
}
}
