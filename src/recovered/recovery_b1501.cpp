#include "recovered/recovery_b1501.hpp"
#include <stdexcept>
namespace ra2::recovered::b1501 {
namespace {
void need(bool x,const char*s){if(!x)throw std::domain_error(s);}
void fp_domain(const platform::x87::Image&i){
 constexpr unsigned short cw[]{0x037f,0x077f,0x0b7f,0x0f7f,0x027f,0x067f,0x0a7f,0x0e7f,0x007f,0x047f,0x087f,0x0c7f};bool ok=false;for(auto x:cw)ok|=x==i.word(0);need(ok,"1501 twelve declared masked CW");
 const U sw=i.word(4),top=(sw>>11)&7,tag=i.word(8);need((sw&~0x3800u)==0,"1501 no arbitrary condition/exception bits");bool empty=false;
 for(U k=0;k<8;++k){U t=(tag>>(2*((top+k)&7)))&3;need(t==0||t==3,"1501 normal valid values or empty slots only");if(t==3)empty=true;else{need(!empty,"1501 contiguous declared live stack");const U exponent=(i.bytes[36+10*k]|(U(i.bytes[37+10*k])<<8))&0x7fff;need((i.bytes[35+10*k]&0x80)&&exponent>0&&exponent<0x7fff,"1501 finite normal live register payload");}if(k==7)need(t==3,"1501 full depth8 excluded before operation");}
}
}
U fun_0060c390(Memory&m,const Inputs&i){
 fp_domain(i.fp.image);const U pool=m.r32(0x819300),a=pool-0x10000,type=a+0x2000,first=pool+16,second=pool+8+648+8,head=0x8191e0,rules=a+0x4000,house=a+0x30000;
 need(m.r8(0xa5e2fc)==1&&m.r32(0xa5e1d8)==0,"1501 genuine enabled planning and optional null handler");
 need(m.r32(0xa5e2e4)==0&&m.r32(0xa5e250)==0&&m.r32(0xa5e208)==0,"1501 constructor-zero reset DWORDs");
 need(m.r32(0xa1a668)==128&&m.r32(0xa1a670)==0,"1501 reachable full128 queue, no successful enqueue claim");
 need(m.r32(0xa1e0e4)==house&&m.r32(house+0x30)==0&&m.r32(0x821b88)==rules&&m.r32(rules+0x1cc)==0&&m.r32(rules+0x1d8)==0,"1501 genuine configured currentHouse/Start/End index0");
 need(m.r32(0x7c17a8)==0x7c17d4&&m.r32(0x79276c)==0x46800000&&m.r32(0x7c3a04)==0xe7f,"1501 pinned event-name/scalar/CW constants");
 need(m.r32(0xab82a8)==1&&m.r32(0xab829c)==a+0x3100&&m.r32(a+0x3100)==a+0x3110&&m.r32(a+0x3110)==type&&m.r32(type+0xc)==1&&m.r32(type+0x1c)==(327u<<16),"1501 original named type/Volume2 gain327");
 need(m.r32(0x819898)==0&&m.r32(0x7b7b68)==1&&m.r32(0x8192f8)==1&&m.r32(0x8192fc)==1,"1501 actual ready manager gates/null clock callback");
 need(m.r32(0x8192e4)==1&&m.r32(0x8192e8)==2&&m.r32(head)==first&&m.r32(head+4)==first&&m.r32(first)==head&&m.r32(first+4)==head&&m.r32(first+0x24)==type&&m.r32(first+0x138)+1==m.r32(0x7b7b6c),"1501 coherent post-enabler one-active manager list");
 need(m.r32(pool)==pool+8+648,"1501 oneactive99free actual B869pool");for(U k=0;k<100;++k)need(m.r32(pool+8+k*648)==(k==99?0:pool+8+(k+1)*648),"1501 actual100header freechain backing");
 // 60C3A1..60C3B0 produces only event type/owner/epoch. 4B5CE0's
 // 4068F0 callee is an actual RET, and the43entry tableword is pinned.
 const U owner=m.r32(m.r32(0xa1e0e4)+0x30),event_type=0x2b,event_owner=owner&255,event_epoch=m.r32(0xa2896c);(void)event_type;(void)event_owner;(void)event_epoch;
 // 60C3B5..60C3C7 copies111 private bytes,105 not produced. The full
 // 625EA0 branch writes only its own outgoing arg epoch, then rejects before
 // reading or publishing any byte or calling timeGetTime. The copy is dead:
 // no private padding is materialized, zero-filled, seeded or exposed here.
 m.w32(0xa5e2e4,0);m.w32(0xa5e250,0);m.w32(0xa5e208,0);m.w8(0xa5e2fc,0);
 ra2::recovery_b323::EntryState child{};child.input.cx=m.r32(rules+0x1d8);child.input.dx=0x2000;child.input.arg[0]=0x3f800000;child.input.arg[1]=0;child.ecx=child.input.cx;child.edx=child.input.dx;child.caller_words=child.input.arg;
 const U out=ra2::recovery_b323::fun_00708970(m,child,i.fp);need(out==second,"1501 exact second actual payload rawEAX");
 // 60C400 genuine optional-null branch leaves EAX intact; RET0/all16 outer
 // words. B323's saved-ECX overwrite is private to its own child frame.
 return out;
}
}
