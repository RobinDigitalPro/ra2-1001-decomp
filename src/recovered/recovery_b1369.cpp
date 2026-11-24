#include "recovery_b1369.hpp"
#include "platform/map_adjust1044_fp.hpp"
#include <stdexcept>
namespace ra2::recovered::b1369 {
namespace {
using U=std::uint32_t;
void need(bool value,const char* message){if(!value)throw std::domain_error(message);}
void original_404120_detached(Memory& m,U receiver){
    // Actual40412E branches directly to4041A8 when the related object is null.
    need(m.r32(receiver+0xb0u)==0u,"B1369 coherent detached related-object branch");
}
U original_401f90(Memory& m,U child){
    const U result=m.r32(child+0xcu)-1u;
    m.w32(child+0xcu,floating_b61::s32(result)<0?0u:result);return result;
}
void original_42cc10_borrowed(Memory& m,U vector){
    const U storage=m.r32(vector+4u);
    m.w32(vector+0x10u,0u);
    need(storage!=0u&&m.r8(vector+0xdu)==0u,"B1369 genuine nonowning embedded vector");
    // Actual pointer is retained:76D67B is not called when owner byte is zero.
    m.w8(vector+0xdu,0u);m.w32(vector+8u,0u);
}
U original_76aa50(Memory& m,const Inputs& i){
    const U incoming=i.fp.control(),cached=m.r32(0x7c3a04u);
    need(cached==0x0e7fu,"B1369 original cached conversion control");
    // FNSTCW's unproduced upper local WORD is masked away before use.
    if(incoming!=cached)i.fp.load_control(std::uint16_t(cached));
    return U(i.fp.pop_integer64());
}
}
U fun_004055d0(Memory& m,const Inputs& i){
    const U receiver=i.cx;
    need(m.r32(0x7b7b68u)==1u&&m.r32(receiver+0x1cu)==4u&&(m.r8(receiver+0x18u)&1u)==0u,"B1369 actual state4 selector and pending completion");
    original_404120_detached(m,receiver);
    U count=m.r32(receiver+0xa8u);need(count>=1u&&count<=3u,"B1369 nonempty bounded child array");
    for(U k=0;k<count;++k){
        const U slot=receiver+0x28u+4u*k,child=m.r32(slot);
        need(child!=0u&&m.r32(child+0xcu)>0u&&m.r32(child+0xcu)<0x80000000u,"B1369 real positive child count");
        (void)original_401f90(m,child);m.w32(slot,0u);
        count=m.r32(receiver+0xa8u); // actual final EAX is this reloaded count
    }
    m.w32(receiver+0xa8u,0u);m.w32(receiver+0x1cu,4u);
    m.w32(receiver+0x138u,0u);m.w32(receiver+0x278u,0u);
    m.w32(receiver+0x18u,m.r32(receiver+0x18u)|1u);return count;
}
U fun_0056d2b0(Memory& m,const Inputs& i){
    U count=m.r32(0xa57950u);need(count>=1u&&count<=3u,"B1369 populated region registry");
    need(i.fp.image.word(0)==0x037fu&&i.fp.image.word(8)==0xffffu&&(i.fp.image.word(4)&~0x3800u)==0u,"B1369 finite exact numeric domain");
    for(U k=0;k<count;++k){
        U region=m.r32(m.r32(0xa57944u)+4u*k);
        // Constructor56A660 establishes7875A0; exact original slot+C=42CC10.
        need(m.r32(region+0x28u)==0x7875a0u,"B1369 authentic live embedded provider");
        original_42cc10_borrowed(m,region+0x28u);
        region=m.r32(m.r32(0xa57944u)+4u*k);m.w32(region+0xcu,0u);
        region=m.r32(m.r32(0xa57944u)+4u*k);
        m.w32(region+0x40u,0x270fu);m.w32(region+0x44u,0x270fu);
        m.w32(region+0x48u,0u);m.w32(region+0x4cu,0u);count=m.r32(0xa57950u);
    }
    const U dimension=m.r32(0x836b4cu);need(dimension==2u,"B1369 actual four-record matrix");
    const auto boundary=floating_b61::s32(m.r32(0xa58634u));
    for(U remaining=dimension*dimension;remaining!=0u;--remaining){
        const U record=m.r32(0xa5863cu)+80u*(remaining-1u);
        // Actual DWORD coordinate load then signed WORD extraction; all4 visited.
        const U packed=m.r32(record);
        const auto x=floating_b61::s32(floating_b61::sx16(packed));
        const auto y=floating_b61::s32(floating_b61::sx16(packed>>16u));
        need(x+y<=boundary,"B1369 genuine unassigned matrix early branch");
    }
    need(m.r32(0xa579f0u)==0u&&m.r32(0xa57b04u)==2u&&m.r32(0xa57b00u)==2u,"B1369 positive dimension exact finite threshold route");
    // Literal operands are exact original binary64 constants, also mapped unchanged
    // in native readonly_data. These are real ordered x87 operations, not a result seam.
    i.fp.load_integer32(m.r32(0xa579f0u));
    i.fp.multiply64(0x3f747ae147ae147bull);
    i.fp.add64(0x3fa999999999999aull);
    ra2::platform::map_adjust1044_fp::multiply_integer32(i.fp,m.r32(0xa57b04u));
    ra2::platform::map_adjust1044_fp::multiply_integer32(i.fp,m.r32(0xa57b00u));
    floating_b61::fp_extra::reg<0xdcc0>(i.fp);
    const U threshold=original_76aa50(m,i);
    count=m.r32(0xa57950u);
    for(U k=0;k<count;++k){
        const U region=m.r32(m.r32(0xa57944u)+4u*k);
        if(m.r8(region+0x1au)==0u&&m.r8(region+0x14u)==0u){
            need(floating_b61::s32(m.r32(region+0xcu))<=floating_b61::s32(threshold),"B1369 no merge/delete branch");
            m.w8(region+0x1au,1u);
        }
        count=m.r32(0xa57950u); // Actual56D4E1 final full EAX.
    }
    return count;
}
}
