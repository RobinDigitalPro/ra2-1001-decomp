#include "recovery_b1362.hpp"
#include <stdexcept>
namespace ra2::recovered::b1362 {
namespace {
using U=std::uint32_t;
void need(bool valid,const char* reason){if(!valid)throw std::domain_error(reason);}
U al(U eax,U value){return (eax&0xffffff00u)|(value&255u);}
}
U fun_0065e5d0(Memory& m,const Inputs& i){
    need(m.r8(0x83a70c)==0 && m.r8(0xa9eaa0)==1 && m.r32(i.cx+0x2c)==0,
         "B1362 pending progress byte and empty ordinary list");
    m.w8(0xa9eaa0,0); // Original65E5DB occurs before the count check.
    return m.r32(i.cx+0x2c); // Full EAX count0; no callback or list element read.
}
U fun_00672be0(Memory& m,const Inputs& i){
    need(m.r8(i.cx+0x4ee1)==0 && m.r8(0xaa488c)==1,"B1362 inactive receiver consumes pending shared flag");
    m.w8(0xaa488c,0); // EBX0 and unconditional672F8A epilogue store.
    return i.ax;     // This original path never assigns any part of EAX.
}
U fun_00421710(Memory& m,const Inputs& i){
    const U descriptor=m.r32(i.cx+0xb0),rules=m.r32(0x821b88);
    need(m.r8(i.cx+0x178)==1 && m.r8(descriptor+0x310)==0 && m.r8(descriptor+0x32e)==0 &&
         m.r32(rules+0xb4)!=descriptor && m.r8(descriptor+0x315)==0 && m.r8(i.cx+0x103)==0 &&
         m.r8(i.cx+0x174)==0 && m.r8(i.cx+0x7d)==0 && m.r32(rules+0x10e4)!=descriptor &&
         m.r8(i.cx+0x17b)==0 && m.r8(i.cx+0x17c)==1,"B1362 explicit one-shot status consumption route");
    U eax=m.r32(i.cx+0xb0); // 421F25 fully reloads the descriptor pointer.
    eax=al(eax,m.r8(i.cx+0x17b));
    eax=al(eax,m.r8(i.cx+0x17c));
    m.w8(i.cx+0x17c,0);    // 421F74 retains the loaded AL1 through RET.
    return eax;
}
U fun_00712de0(Memory& m,const Inputs& i){
    for(U k=0;k<3;++k){
        const U sentinel=m.r32(0xae0ae0+4*k);
        need(m.r32(i.cx+0x28+4*k)==sentinel && m.r32(i.cx+0x1c+4*k)==sentinel,
             "B1362 both coordinate triples match the original global sentinel");
    }
    const U actor=m.r32(i.cx+0xc);
    const auto value=floating_b61::read64(m,actor+0x468);
    need(m.r8(actor+0x57a)==1 && (value==0 || value==0xbff0000000000000ull || value==0xc000000000000000ull) &&
         floating_b61::read64(m,0x786610)==0,"B1362 actual nonpositive0/-1/-2 comparison");
    need(i.fp.image.word(8)==0xffff && (i.fp.image.word(4)&0x3800)==0,"B1362 empty incoming x87 TOP0");
    i.fp.require_masked();
    // These are the actual original FLD/FCOMP/FNSTSW operations. In particular,
    // the popped physical payload remains visible; no arithmetic shortcut is used.
    i.fp.load64(value);
    i.fp.compare_pop64(floating_b61::read64(m,0x786610));
    const U status=i.fp.status();
    need((status&0x4100)!=0,"B1362 equal-or-negative original branch");
    const U eax=m.r32(i.cx+0xc); //7140F2 overwrites all FNSTSW-derived EAX bits.
    m.w8(eax+0x57a,0);
    return eax;
}
}
