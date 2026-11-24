#include "recovery_b1397.hpp"
#include "platform/ole_stream951.hpp"
#include "platform/observed_ticks1378.hpp"
#include <array>
namespace ra2::recovered::b1397 {
std::uint32_t fun_00657f30(Memory& m,const Inputs& i){
    using U=std::uint32_t;namespace ole=ra2::platform::ole_stream951;
    const U self=i.cx,stream=i.arg[0];
    ole::need(stream==ole::Stream::current().address(),"B1397 genuine live IStream");
    auto* p=reinterpret_cast<IStream*>(std::uintptr_t(stream));
    // All12 original logger arguments are produced from the three timer words.
    // Actual4068F0 is literalRET and preserves state; it formats/reads nothing.
    const std::array<U,3> timer{m.r32(self+0x614u),m.r32(self+0x618u),m.r32(self+0x61cu)};
    ole::need(timer[0]==0xffffffffu,"B1397 genuine stopped-timer entry");
    std::array<std::uint8_t,0x2460u> object{};
    for(U k=0;k<object.size();++k)object[k]=std::uint8_t(m.r8(self+k));
    ole::need(p->Write(object.data(),U(object.size()),nullptr)==S_OK,"B1397 complete actual object Write");
    constexpr U pointers[]{0x2258u,0x2274u,0x2290u},counts[]{0x2264u,0x2280u,0x229cu};
    for(U vector=0;vector<3u;++vector){
        const U count=m.r32(self+counts[vector]),table=m.r32(self+pointers[vector]);
        ole::need(count>=1u&&count<=3u&&table!=0u,"B1397 positive bounded borrowed vector");
        // Original[ESP+24] after four argument pushes aliases outerarg0.
        i.arg[0]=count;
        ole::need(p->Write(&i.arg[0],4,nullptr)==S_OK,"B1397 genuine vector count Write");
        for(U k=0;k<count;++k){const U value=m.r32(table+4u*k);ole::need(p->Write(&value,4,nullptr)==S_OK,"B1397 genuine nonempty vector entry Write");}
    }
    ole::need(m.r32(self+0x614u)==0xffffffffu,"B1397 serialized stopped state unchanged until final clock");
    // Exact68FAD0: one real timeGetTime call through unchanged strict observer,
    // followed by logical SHR4. Its ECX carrier=self618 is not dereferenced.
    const U result=ra2::platform::ticks1378::Tick::get()>>4u;
    m.w32(self+0x614u,result);return result;
}
}
