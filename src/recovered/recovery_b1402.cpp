#include "recovery_b1402.hpp"
#include "recovered/recovery_b1365.hpp"
#include <stdexcept>
namespace ra2::recovered::b1402 {
namespace {void need(bool valid,const char* reason){if(!valid)throw std::domain_error(reason);}}
std::uint32_t fun_00692730(Memory& m,const Inputs& i){
    using U=std::uint32_t;
    U descriptor=m.r32(i.cx+0x24u);
    need(m.r8(descriptor+0xddu)==0u,"B1402 configured non-charge-drain route");
    const U timer=m.r32(i.cx+0x2cu);
    need(timer==0xffffffffu,"B1402 borrowed stopped timer");
    need(m.r8(descriptor+0xe1u)==1u&&m.r32(descriptor+0xb4u)==0u,"B1402 original PostClick=1, Type=MultiMissile configuration");
    need((i.arg[0]&255u)==0u,"B1402 no optional child UI action");
    // T=S-0x20 after the 0x10 local bytes and four saved registers. The actual pushes exchange the
    // two outer arguments for child692EF0; no other child argument is read.
    Inputs child{};child.cx=i.cx;child.ax=descriptor;child.dx=i.arg[1];
    child.arg[0]=i.arg[1];child.arg[1]=i.arg[0];child.fp=i.fp;
    b1365::fun_00692ef0(m,child);i.fp=child.fp;
    // Root reload at6928B6 deliberately discards the child's pointer-valued EAX.
    descriptor=m.r32(i.cx+0x24u);
    need(m.r8(descriptor+0xe1u)==1u&&m.r8(i.cx+0x56u)==0u,"B1402 unchanged ready-state path after genuine child work");
    need(m.r8(descriptor+0xe9u)==0u&&m.r8(descriptor+0xe0u)==0u,"B1402 no manual-control or pre-click timer path");
    // E1!=0 at69297F selects the common epilogue. XOR AL,AL preserves high24.
    return descriptor&0xffffff00u;
}
}
