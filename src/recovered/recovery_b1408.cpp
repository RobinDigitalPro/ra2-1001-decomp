#include "recovered/recovery_b1408.hpp"
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include <stdexcept>
namespace ra2::recovered::b1408 {
namespace {
namespace x87=ra2::platform::x87;
struct GuestCall {
    x87::State& state;x87::Image host;
    explicit GuestCall(x87::State& s):state(s),host(x87::capture_host()){x87::restore_host(state.image);}
    ~GuestCall(){state.image=x87::capture_host();x87::restore_host(host);}
};
template<unsigned N>void text(Memory& m,std::uint32_t a,char(&out)[N]){for(unsigned k=0;k<N;++k)out[k]=char(m.r8(a+k));if(out[N-1]!=0)throw std::runtime_error("1408 original name is not terminated");}
}
std::uint32_t fun_00482a20(Memory& m,const Inputs& i){
    using Module=HMODULE(WINAPI*)(LPCSTR);using Lookup=FARPROC(WINAPI*)(HMODULE,LPCSTR);
    using Query=BOOL(WINAPI*)(LPCSTR,PULARGE_INTEGER,PULARGE_INTEGER,PULARGE_INTEGER);
    char module_name[13],export_name[20];text(m,0x7be79cu,module_name);text(m,0x7be788u,export_name);
    HMODULE module{};{GuestCall g(i.fp);module=reinterpret_cast<Module>(std::uintptr_t(m.r32(0x785230u)))(module_name);}
    if(!module)throw std::runtime_error("1408 module failure outside positive contract");
    FARPROC target{};{GuestCall g(i.fp);target=reinterpret_cast<Lookup>(std::uintptr_t(m.r32(0x785240u)))(module,export_name);}
    if(!target)throw std::runtime_error("1408 lookup failure outside positive contract");
    // Root T=S-2C: available T+14, free T+1C, total T+24. All are
    // produced by the actual API; no private or outer word is an input.
    ULARGE_INTEGER output[3];BOOL status{};
    {GuestCall g(i.fp);status=reinterpret_cast<Query>(target)(nullptr,&output[0],&output[2],&output[1]);}
    if((std::uint32_t(status)&255u)==0u)throw std::runtime_error("1408 failed API outside positive contract");
    return convert_available(m,i,output[0].QuadPart);
}
std::uint32_t convert_available(Memory& m,const Inputs& i,std::uint64_t available){
    i.fp.load_integer32(std::uint32_t(available>>32));
    i.fp.multiply64(floating_b61::read64(m,0x788e10u));
    ra2::platform::x87_extended::add_integer32(i.fp,std::uint32_t(available));
    i.fp.multiply64(floating_b61::read64(m,0x788e08u));
    // Literal76AA50 semantics. Its FNSTCW upper scratch bits are masked
    // before comparison; FISTP fully produces the private64-bit result.
    const auto control=m.r32(0x7c3a04u);
    if(i.fp.control()!=control)i.fp.load_control(std::uint16_t(control));
    const auto value=i.fp.pop_integer64();
    // All4068F0 bodies are literal RET. The diagnostic SHR is discarded by
    // MOV EAX,ESI, so return the complete original low32; RET0/all16 unchanged.
    return std::uint32_t(value);
}
}
