#include "recovery_b1365.hpp"
#include <stdexcept>
namespace ra2::recovered::b1365 {
namespace {
using U=std::uint32_t;
void need(bool valid,const char* reason){if(!valid)throw std::domain_error(reason);}
U al(U eax,U byte){return (eax&0xffffff00u)|(byte&255u);}
// Original4068F0 consists of C3. The older masked-return leaf is not a
// full-carrier adapter. This exact local adapter preserves the incoming EAX.
U original_ret_4068f0(U eax){return eax;}
}
U fun_004b62d0(Memory& m,const Inputs& i){
    const U owners=m.r32(0xa1a5cc),index=m.r8(i.cx+2);
    need(index<4 && m.r8(i.cx)==12,"B1365 legal byte selector12 and bounded signed owner index");
    // The original performs this read even though this case never dereferences
    // the selected owner. Keep its borrowed array dependency explicit.
    const U owner=m.r32(owners+4*index);(void)owner;
    const U eax=U(m.r8(i.cx))-1;
    need((m.r8(0xa27928)&2)==0 && m.r32(0xa28988)==0,"B1365 pending global publication");
    m.w32(0xa28988,1); // Actual table slot11 ->4B6E67, store4B6E77.
    return eax;       // No Boolean substitution: full EAX is the ordinal11.
}
U fun_00416670(Memory& m,const Inputs& i){
    U eax=m.r32(i.cx+0xa8);
    need(eax==3 && m.r32(i.cx+0xfc)!=0 && m.r32(i.cx+0x3f8)!=0 && m.r8(i.cx+0x5bc)==0,
         "B1365 legal mode3 with existing nonzero state fields");
    eax=original_ret_4068f0(eax); // Actual pushed7B96A4 is not read by C3.
    eax=m.r32(i.cx+0xfc);(void)eax;
    m.w8(i.cx+0x5bc,1);
    return 1; // 416AA6 overwrites all32bits before balanced RET0.
}
U fun_006a3130(Memory& m,const Inputs& i){
    const U eax=al(i.ax,1),selector=m.r32(i.cx+0x2c);
    // This is the second outer word: its read precedes the fourth save.
    need(i.arg[1]==0 && (selector==71 || selector==72),"B1365 legal widening selectors and null arg1");
    const U value=m.r32(i.cx+0x74),exponent=(value>>23)&255;
    need(exponent!=0 && exponent!=255,"B1365 finite normal binary32 input");
    need(i.fp.image.word(8)==0xffff && (i.fp.image.word(4)&0x3800)==0,"B1365 empty incoming x87 TOP0");
    i.fp.require_masked();
    i.fp.load32(value); // Original FLD m32. Preserve physical stale output.
    const U rules=m.r32(0x821b88);
    const auto output=i.fp.pop64(); // Original FSTP m64, no arithmetic shortcut.
    floating_b61::write64(m,rules+(selector==71?0x12d0:0x12c8),output);
    return eax;
}
U fun_00692ef0(Memory& m,const Inputs& i){
    const U descriptor=m.r32(i.cx+0x24);
    U eax=m.r32(descriptor+0xb4);
    need(eax==0 && m.r8(i.cx+0x57)==1 && m.r8(i.cx+0x56)==0 && (i.arg[1]&255)==0,
         "B1365 legal case0, enabled record, no optional UI action");
    eax=al(eax,m.r8(i.cx+0x57));
    eax=al(eax,m.r8(i.cx+0x56));
    const U count=m.r32(0xa1e018),records=m.r32(0xa1e00c);
    need(count>=1 && count<=4,"B1365 genuine nonempty bounded registry");
    for(U k=0;k<count;++k){
        eax=m.r32(records+4*k); // Full pointer survives in EAX after last iteration.
        need(m.r8(eax+0x1354)==0,"B1365 actual ineligible-record loop branch");
    }
    eax=al(eax,i.arg[1]);
    const U linked=m.r32(i.cx+0x28);
    need(m.r8(linked+0x144)==0,"B1365 positive linked-object flag transition");
    m.w8(linked+0x144,1);
    return eax;
}
}
