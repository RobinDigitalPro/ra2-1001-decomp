#include "recovered/recovery_b1629.hpp"
#include "platform/observed_inactive1629.hpp"
#include <stdexcept>
namespace ra2::recovered::b1629 {
namespace {
void need(bool v){if(!v)throw std::domain_error("1629 first-slot PlayerA finite numeric record/input domain");}
U lower(U c){return c>='A'&&c<='Z'?c+32u:c;}
void domain(Memory&m,const Inputs&i){const U record=m.r32(0xa27dc4u),query=i.cx;need(i.dx==1u&&i.arg[0]==3u&&record>=0x10000000u&&std::uint64_t(record)+0x59u<=0x70000000u&&query>=0x10000000u&&std::uint64_t(query)+8u<=0x70000000u);need(std::uint64_t(record)+0x59u<=query||std::uint64_t(query)+8u<=record);constexpr char name[]="PlayerA";for(U k=0;k<8u;++k)need(m.r8(query+k)==U(name[k])&&m.r16(record+2u*k)==U(name[k]));need(m.r32(record+0x49u)==0u&&m.r32(record+0x4du)==0xffffffffu&&m.r32(record+0x51u)==3u&&m.r32(record+0x55u)==0xffffffffu);need(m.r32(0xab7edcu)==0u&&m.r32(0xb10530u)==0u&&m.r32(0xb0d84cu)==0u&&m.r32(0xb0d850u)==0u&&m.r32(0xb0d858u)==0u);}
// Full accepted6EEDC0 conversion semantics on the new finite domain.
U convert(Memory&m,U src){if(!src)return 0;const U slot=m.r32(0xab7edcu),out=0xaa8decu+(slot<<10u);U dst=out,left=0x400u;while(m.r16(src)&&left){m.w8(dst,m.r8(src));++dst;src+=2u;--left;}m.w8(dst,0);m.w8(out+0x3ffu,0);m.w32(0xab7edcu,(m.r32(0xab7edcu)+1u)&7u);return out;}
// Actual local no-collation76D860 byte compare, not a pointer equality shortcut.
U compare(Memory&m,U a,U b){need(m.r32(0xb10530u)==0u);for(;;){const U x=m.r8(a++),y=m.r8(b++);if(x==y){if(!x)return 0u;continue;}const U lx=lower(x),ly=lower(y);if(lx!=ly)return lx<ly?0xffffffffu:1u;if(!lx)return 0u;}}
U dialog_lookup(Memory&m,U id){const U count=m.r32(0xb0d858u);U index=count-1u;if(global_b26::s32(index)<0)return 0u;do{if(m.r32(0xb0d634u+index*8u)==id)return m.r32(0xb0d630u+index*8u);--index;}while(global_b26::s32(index)>=0);return 0u;}
U first(Memory&m,U record){return m.r32(record+0x4du)==0xfffffffeu?0xfffffffeu:m.r32(record+0x49u);}
void set_first(Memory&m,U record,U value){if(value==0xfffffffeu){m.w32(record+0x49u,0u);m.w32(record+0x4du,value);}else{m.w32(record+0x49u,value);m.w32(record+0x4du,0xffffffffu);}}
U second(Memory&m,U record){return m.r32(record+0x55u)==0xfffffffeu?0xfffffffeu:m.r32(record+0x51u);}
U inactive_child(Memory&m){U dialog=m.r32(0xb0d84cu);const U kind=m.r32(0xb0d850u);need(kind!=0xbcu&&kind!=0xbdu); // Actual root prefix next walks zero-count ancestor table.
need(m.r32(0xb0d858u)==0u); //72A570 fullcount0 return0; no dereference/provider.
dialog=m.r32(0xb0d84cu);const HWND out=ra2::platform::inactive1629::Trace::get(reinterpret_cast<HWND>(std::uintptr_t(dialog)),0x53e);if(!dialog)return U(reinterpret_cast<std::uintptr_t>(out));need(false);return 0u;}
}
U fun_005b7eb0(Memory&m,const Inputs&i){domain(m,i);const U wanted=i.dx;U selected=0xffffffffu;for(U index=0;index<8u;++index){const U name=convert(m,m.r32(0xa27dc4u+index*4u));if(compare(m,name,i.cx)==0u){selected=index;break;}}U changed=0u;if(selected==0xffffffffu)return 0u;U dialog=dialog_lookup(m,0xbcu);if(!dialog)dialog=dialog_lookup(m,0xbdu);(void)dialog;const U record=m.r32(0xa27dc4u+selected*4u);if(first(m,record)!=wanted){changed=1u;set_first(m,record,wanted);}need(second(m,record)==i.arg[0]); // Actual5B7F48JE skipssecondsetter in this fixed domain.
(void)inactive_child(m);return changed; // Actual parent MOVEAX,EDI; RET4/all16 unchanged. VolatileECX=desired at nativePOP is not entryECX.
}
}
