#include "recovery_b1359.hpp"
#include "recovered/crt_b83.hpp"
#include "recovered/leaf_containers.hpp"
#include "recovered/global_b58_c.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1359 {
namespace {
using U=std::uint32_t;
void need(bool valid,const char* reason) { if(!valid) throw std::domain_error(reason); }
void ascii_name(Memory& m,U address) {
    for(U k=0;k<=12;++k) {
        const U word=m.r16(address+2*k);
        if(word==0) { need(k!=0,"B1359 nonempty UTF16 name"); return; }
        need(word>=0x21 && word<=0x7e,"B1359 bounded ASCII-range UTF16");
    }
    throw std::domain_error("B1359 UTF16 name longer than12 units");
}
U compare_names(Memory& m,U a,U b,U eax) {
    // Original781C48 mutates its two by-value argument slots. These Inputs
    // represent nested private pushes, never the outer root caller words.
    ascii_name(m,a); ascii_name(m,b);
    global_b26::Inputs inner{};inner.ax=eax;inner.arg[0]=a;inner.arg[1]=b;
    return crt_b83::fun_00781c48(m,inner);
}
// Exact original4068F0 is C3: all data/GPR/numeric FP state is preserved.
U ret_004068f0(U eax) noexcept { return eax; }
U unpack_address(Memory& m,U source) {
    // Root stable T=S-28: 522A60 writes4 bytes atT+14 and6 atT+20.
    // Its leaf Memory API uses one contiguous span. The disjoint input copy
    // at+40 is adapter storage, not original stack input; only produced bytes
    // at+20..23 are consumed. The helper's private return pointer is discarded.
    constexpr U b=0x7d600000;
    std::array<std::uint8_t,0x4a> bytes{};
    leaf::Memory local(bytes.data(),b,static_cast<U>(bytes.size()));
    for(U k=0;k<10;++k) local.w8(b+0x40+k,m.r8(source+k));
    leaf::Inputs inner{};inner.cx=b+0x40;inner.arg[0]=b+0x14;inner.arg[1]=b+0x20;
    (void)leaf::fun_00522a60(local,inner);
    U result=0;
    for(U k=0;k<4;++k) result=(result<<8)|local.r8(b+0x20+k);
    return result;
}
U actual_005575e0(Memory& m,U point,U packed) {
    // Exact signed toward-zero world/256 conversion. Original writes the
    // packed coordinate into its own caller slot, inside the root frame.
    auto component=[](U v) { return global_b26::sar(v+((v&0x80000000u)?255u:0u),8)&0xffffu; };
    m.w16(packed,component(m.r32(point)));
    m.w16(packed+2,component(m.r32(point+4)));
    const U pair=m.r32(packed);m.w32(packed,pair); // 557612/557617 produced spill
    global_b26::Inputs inner{};inner.ax=pair;inner.cx=0x81a820;inner.dx=packed;
    inner.arg[0]=packed;inner.arg[1]=1;
    // This is the actual compatible B58 body, not the old B33 callback seam.
    return global_b26::fun_00557450(m,inner);
}
}
U fun_00597980(Memory& m,const Inputs& i) {
    need(m.r32(0xb10530)==0 && m.r8(i.cx+9)==0,"B1359 default-locale unmarked receiver");
    const U equal=compare_names(m,i.cx+0x22,i.arg[0],i.ax);
    need(equal==0 && m.r32(i.cx+0x4c)==i.arg[1] && m.r32(i.cx+0x50)==i.arg[2],
         "B1359 matching nonempty name and two scalar values");
    const U eax=i.arg[2]; // Original5979B0 loads full outerarg2 before the match.
    m.w8(i.cx+9,1);
    return eax;
}
U fun_00665960(Memory& m,const Inputs& i) {
    need(m.r32(0xa255c8)==3 && m.r32(0x821f90)==0 && m.r32(i.cx)==3 &&
         m.r32(i.cx+0x27f0)==1 && m.r32(0xb10530)==0 && m.r8(0xa27ed4)==1,
         "B1359 one-peer publication without optional provider/reconfiguration");
    (void)ret_004068f0(i.ax); // 66596E
    const U list=m.r32(i.cx+0x27e4);
    for(U index=0;index<m.r32(i.cx+0x27f0);++index) {
        const U record=m.r32(list+4*index), owner_index=m.r32(record+0x5d);
        need(owner_index<4,"B1359 bounded owner-pointer array index");
        (void)ret_004068f0(record); // 6659CF
        const U owner=m.r32(m.r32(0xa1a5cc)+4*owner_index);
        need(compare_names(m,record,owner+0x15f16,record)==0,"B1359 peer and owner names match");
        need(compare_names(m,record,i.cx+0x2922,list)!=0,"B1359 distinct local manager name");
        need(m.r8(owner+0x150)==1,"B1359 pending owner flag");
        m.w32(owner+0x14c,m.r32(record+0x69));
        // A27DAC is a separate source-record pointer array. No record alias is assumed.
        const U source=m.r32(m.r32(0xa27dac)+4*index)+0x28;
        const U address=unpack_address(m,source);
        (void)ret_004068f0(record); // 665AD0
        m.w32(owner+0x148,address);
        m.w8(owner+0x150,0);
        // Count1 means actual index0<=EBX0: no524280 remote registration.
    }
    m.w8(0xa27ed4,0);
    U eax=ret_004068f0(0x7bd468); // 665C1F
    eax=ret_004068f0(eax);       // 665C29; genuine tail RET, no dereferenced text
    (void)eax;
    return 1;
}
U fun_004bc8d0(Memory& m,const Inputs& i) {
    const U actor=m.r32(i.cx+0xc), x=m.r32(actor+0x88), y=m.r32(actor+0x8c);
    need(x>=3*256 && x<5*256 && y>=3*256 && y<5*256 && m.r8(actor+0x32d)==0,
         "B1359 unmarked actor with selected positive cell coordinates");
    const U origin=m.r32(0x81a820+0xf8);
    const U neg=0u-origin;
    need(neg>=1 && neg<=385 && (neg-1)%128==0 && m.r32(0x81a820+0xf0)==0 &&
         m.r32(0x81a820+0xfc)==0 && m.r32(0x81a820+0x100)==4+2*(neg-1) &&
         m.r32(0x81a820+0x104)==4,"B1359 finite real map bounds");
    const U cell=m.r32(m.r32(0x81a958)+4*((y/256)*512+x/256));
    need(cell!=0 && m.r8(cell+0x11b)==0 && m.r8(cell+0x11c)==0,"B1359 genuine populated flat cell");
    // Private b=T-4; root XYZ is T+4/T+8/T+C, all explicitly produced.
    // Packed coordinate atT-4 is written by5575E0 before557450 reads it.
    constexpr U b=0x7d610000;
    std::array<std::uint8_t,0x14> bytes{};
    leaf::Memory private_span(bytes.data(),b,static_cast<U>(bytes.size()));
    Memory nested=m;nested.add(private_span);
    nested.w32(b+8,x);nested.w32(b+0xc,y);nested.w32(b+0x10,m.r32(actor+0x90));
    const U eax=actual_005575e0(nested,b+8,b);
    need((eax&255u)==1,"B1359 actual map geometry must accept the point");
    m.w8(actor+0x32d,1);
    return eax&0xffffff00u;
}
}
