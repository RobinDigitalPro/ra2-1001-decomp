#include "recovery_b1344.hpp"
#include "platform/x87_state.hpp"
#include <stdexcept>
namespace ra2::recovered::b1344 {
namespace {
using U=std::uint32_t;
using X87=ra2::platform::x87::State;
constexpr U kCounter=0x308u,kPhase=0x3cu,kDensity=0x4cu;
constexpr U kWidth=0x180u,kHeight=0x184u,kPlaced=0x304u;
constexpr U kControlGlobal=0x007c3a04u;
constexpr U kFactor008=0x00790f20u,kOffset100=0x007867f0u;
void need(bool ok,const char* text){if(!ok)throw std::domain_error(text);}
void fimul_i32(X87& fp,U operand){
    fp.require_masked();ra2::platform::x87::Image host;
    asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\tfimull %[operand]\n\tfnsave %[guest]\n\tfrstor %[host]"
        : [host]"=m"(host.bytes),[guest]"+m"(fp.image.bytes)
        : [operand]"m"(operand)
        : "memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");
}
U call_76aa50_numeric_prefix(Memory& m,X87& fp){
    // The selected accepted 0x76AA50 body compares FNSTCW against 0x7C3A04,
    // loads that word only when different, then executes FISTP qword.
    const U target=m.r16(kControlGlobal);
    if(fp.control()!=target)fp.load_control_masked(static_cast<std::uint16_t>(target));
    return static_cast<U>(fp.pop_integer64());
}
U child_17af00_finite(Memory& m,U self,X87& fp){
    const U height=m.r32(self+kHeight);
    const U width=m.r32(self+kWidth);
    const U density=m.r32(self+kDensity);
    fp.load_integer32(height);             // FILD dword [self+184]
    fimul_i32(fp,width);                    // FIMUL dword [self+180]
    fimul_i32(fp,density);                  // FIMUL dword [self+4C], captured by original local stack
    fp.multiply64(ra2::recovered::floating_b61::read64(m,kFactor008));
    fp.add64(ra2::recovered::floating_b61::read64(m,kOffset100));
    const U converted=call_76aa50_numeric_prefix(m,fp);
    const U remaining=converted-m.r32(self+kPlaced);
    need(ra2::recovered::global_b26::s32(remaining)<=75,
         "B1344 selected 17AF00 path must remain below the original minimum threshold");
    // Original 17AF00 reaches 57BA0C, XOR AL,AL, RET 4. Here remaining is
    // 1..70, so clearing AL also clears the full 32-bit EAX value to zero.
    return remaining&0xffffff00u;
}
}
U fun_0057ab60(Memory& m,const Inputs& i){
    const U self=i.cx;
    need(self!=0u,"B1344 finite route requires a mapped object");
    need(m.r32(self+kPhase)==1u,
         "B1344 phase 1 skips the optional original state-3/state-4 family");
    need(m.r32(self+kDensity)==1u&&m.r32(self+kWidth)==5u&&m.r32(self+kHeight)==5u,
         "B1344 finite route uses actual positive density and 5x5 dimensions");
    const U placed=m.r32(self+kPlaced);
    need(placed>=30u&&placed<=99u,
         "B1344 finite route requires existing placed count 30..99");
    need(m.r16(kControlGlobal)==0x0e7fu,
         "B1344 finite route pins the actual global 0x76AA50 control word to 0x0E7F");
    m.w32(self+kCounter,m.r32(self+kCounter)+1u);
    // Original root makes all ten real child attempts. Their early threshold
    // exit prevents allocation, zone creation and map publication.
    for(U attempt=0;attempt<10u;++attempt){
        const U child_eax=child_17af00_finite(m,self,i.fp);
        if(child_eax&0xffu)return child_eax;
    }
    return 0u;
}
}