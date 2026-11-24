#include "recovery_b1308.hpp"
#include <stdexcept>

namespace ra2::recovered::b1308 {
namespace { void need(bool v,const char* s){if(!v)throw std::domain_error(s);} }
U run(global_b26::Memory& m,const Inputs& i){
    // Finite original action-15 leaf route at VA 0x439670, RET 12.
    constexpr U house_vt=0x00787bbcu, target_vt=0x0078612cu;
    need(i.cx!=0u,"B1308 nonnull root receiver");
    const U target=i.arg[0];
    need(target!=0u&&i.arg[1]==15u&&i.arg[2]==0x00a28820u,"B1308 original root arguments 0/1/2");
    need(m.r32(i.cx)==house_vt,"B1308 root original vptr");
    need(m.r32(house_vt+0x17cu)==0x00439670u,"B1308 root +17c actual 0x439670 slot");
    need(m.r32(house_vt+0x16cu)==0x00591570u,"B1308 root +16c actual getter");
    need(m.r32(target)==target_vt,"B1308 target primary vptr");
    need(m.r32(target+0x04u)==0x00786110u,"B1308 original secondary vptr set at constructor VA 0x413dbe");
    need(m.r32(0x00786110u+0x0cu)==0x0040ffb0u,"B1308 secondary +0c callback target");
    need(m.r32(target_vt+0x2cu)==0x0041b580u&&m.r32(target_vt+0x3cu)==0x006bca10u,"B1308 authentic target primary getter slots");
    need(m.r32(target_vt+0x80u)==0x006b6910u&&m.r32(target_vt+0x84u)==0x0041b600u,"B1308 authentic target type getter chain");

    const U action=i.arg[1];
    need(action>=3u&&action-3u<=0x1cu,"B1308 original dispatcher selector bounds");
    // Original immutable selector/tables are pinned in the dependency evidence.
    // The 0x6b7f8f path calls 0x62dea0(this, arg2, action, target).
    // 0x62dea0 rotates receiver+bc/+c0/+c4 unless its current action equals 15;
    // preserve that exact state transition. Its action-15 tail calls 0x5cc340,
    // which returns zero without dereferencing the forwarded arg0 or target.
    const U priorAction=m.r32(i.cx+0xbcu);
    if(priorAction!=action){
        const U priorC0=m.r32(i.cx+0xc0u);
        m.w32(i.cx+0xc0u,priorAction);
        m.w32(i.cx+0xc4u,priorC0);
        m.w32(i.cx+0xbcu,action);
    }
    need(m.r32(0x00a283c4u)!=0u,"B1308 runtime global mode bypasses 0x62e470");

    const U rootMode=m.r32(i.cx+0x98u);
    const U rootCategory=rootMode==0xffffffffu?m.r32(i.cx+0xa0u):rootMode;
    need(rootCategory!=18u&&rootCategory!=19u,"B1308 root +16c return exclusions");
    need(m.r32(i.cx+0x42cu)!=0u,"B1308 required root +42c");
    const U rootOwner=m.r32(i.cx+0x1b4u),targetOwner=m.r32(target+0x1b4u);
    need(rootOwner!=0u&&targetOwner==rootOwner,"B1308 0x4e4c20 owner identity branch");

    const U targetType=m.r32(target+0x5acu);
    need(targetType!=0u&&m.r32(targetType+0x500u)==5u,"B1308 target type bypasses +ada comparisons");
    need(m.r8(targetType+0xb1au)==0u,"B1308 target type +b1a passes");
    need(m.r8(i.cx+0x530u)!=0u,"B1308 required root +530");
    const U rootType=m.r32(i.cx+0x418u);
    need(rootType!=0u,"B1308 root type descriptor");
    need(m.r8(rootType+0x1349u)==0u&&m.r8(rootType+0x135cu)==0u&&m.r8(rootType+0x135bu)==0u&&m.r8(rootType+0x1365u)!=0u,
         "B1308 root descriptor reaches +43989e callback");

    // 0x4398ae loads the secondary vptr at target+4 and calls its +0x0c slot.
    // 0x40ffb0 takes Q=&target[+4], recovers target=Q-4, and calls target.vptr+2c.
    // The original +2c target 0x41b580 returns EAX=2; root arithmetic then returns EAX=1.
    need(m.r32(m.r32(target+4u)+0x0cu)==0x0040ffb0u,"B1308 exact secondary dispatch");
    need(m.r32(target_vt+0x2cu)==0x0041b580u,"B1308 primary +2c returns 2");
    return 1u;
}
}

