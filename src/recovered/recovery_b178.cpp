#include "recovery_b178.hpp"

#include "recovered/allocation_families.hpp"
#include "recovered/leaf_b15_a.hpp"
#include "recovered/leaf_b17_init.hpp"
#include "recovered/leaf_b17_scalars.hpp"

#include <array>
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b178 {
namespace {
using global_b26::Inputs;
using global_b26::Memory;

template <std::size_t N, class F>
void through_leaf(Memory& m, std::uint32_t address, F&& function) {
    std::array<std::uint8_t, N> bytes{};
    for (std::uint32_t n=0;n<N;++n) bytes[n]=static_cast<std::uint8_t>(m.r8(address+n));
    leaf::Memory local(bytes.data(),address,static_cast<std::uint32_t>(N));
    function(local);
    for (std::uint32_t n=0;n<N;++n) m.w8(address+n,bytes[n]);
}

// Compose the accepted 0x1cab90 -> 0xff60 sequence and the exact
// 0x22de60 post-call stores. No callback or guessed return is used.
void constructor_22de60(Memory& m,std::uint32_t receiver,std::uint32_t argument) {
    through_leaf<0x10>(m,receiver,[&](leaf::Memory& local) {
        leaf::Inputs in{}; in.cx=receiver; in.arg[0]=argument;
        (void)leaf::fun_0040ff60(local,in);
    });
    // Tail of original 0x1cab90 after its actual 0xff60 call.
    m.w32(receiver,0x00792458);m.w32(receiver+4,0x0079243c);
    m.w32(receiver+8,0x00792434);m.w32(receiver+0xc,0x0079242c);
    // 0x22de60 then stores +0xc8 and replaces all four vptr words.
    m.w32(receiver+0xc8,0x007857fc);
    m.w32(receiver,0x007938a8);m.w32(receiver+4,0x0079388c);
    m.w32(receiver+8,0x00793884);m.w32(receiver+0xc,0x0079387c);
}

void initialize_zero_count_array(Memory& m,std::uint32_t address,bool family66) {
    constexpr std::uint32_t bytes=0x18;
    through_leaf<bytes>(m,address,[&](leaf::Memory& local) {
        leaf::Inputs in{};in.cx=address;in.arg[0]=0;in.arg[1]=0;
        const AllocationWrapperOperations no_allocation{nullptr,nullptr,nullptr};
        if(family66) (void)fun_0046cc20(local,in,no_allocation);
        else (void)fun_004ce770(local,in,no_allocation);
    });
}

void helper_2b7580(Memory& m,std::uint32_t receiver,std::uint32_t argument) {
    constructor_22de60(m,receiver,argument);
    m.w32(receiver+0x1bc,0);
    m.w32(receiver+0x1c0,m.r32(0x00a2896c));
    m.w32(receiver+0x1c8,0);
    m.w32(receiver+0x1cc,0);
    m.w32(receiver+0x1d0,1);

    // Original 0x23f60 is called with ECX=receiver+0x2b0 and the forwarded
    // argument; its accepted body is MOV EAX,ECX / RET 4 and writes no memory.
    std::array<std::uint8_t,4> identity_bytes{};
    leaf::Memory identity_memory(identity_bytes.data(),receiver+0x2b0,4);
    leaf::Inputs identity{};identity.cx=receiver+0x2b0;identity.arg[0]=argument;
    (void)leaf::fun_00423f60(identity_memory,identity);

    m.w32(receiver+0x334,1);m.w32(receiver+0x330,2);
    m.w32(receiver+0x350,2);m.w32(receiver+0x364,0);m.w32(receiver+0x368,0);
    m.w32(receiver+0x338,1);m.w32(receiver+0x33c,1);
    m.w32(receiver+0x344,0);m.w32(receiver+0x348,0);
    m.w32(receiver+0x354,1);m.w32(receiver+0x358,1);m.w32(receiver+0x35c,1);

    m.w32(receiver+0x350,2);m.w32(receiver+0x364,0);m.w32(receiver+0x368,0);
    initialize_zero_count_array(m,receiver+0x390,true);
    m.w32(receiver+0x390,0x00788a94);m.w32(receiver+0x3a4,10);m.w32(receiver+0x3a0,0);
    initialize_zero_count_array(m,receiver+0x3a8,false);
    m.w32(receiver+0x3a8,0x0078c77c);m.w32(receiver+0x3bc,10);m.w32(receiver+0x3b8,0);
    initialize_zero_count_array(m,receiver+0x3c0,false);
    m.w32(receiver+0x3c0,0x0078c77c);m.w32(receiver+0x3d4,10);m.w32(receiver+0x3d0,0);

    m.w32(receiver,0x00797a28);m.w32(receiver+4,0x00797a0c);
    m.w32(receiver+8,0x00797a04);m.w32(receiver+0xc,0x007979fc);

    const auto count=m.r32(0x00a28870);
    // With count zero the original duplicate scan is skipped. Its local byte
    // remains zero, so no grow callback is reached after the embedded reset.
    if(count!=0 || m.r32(0x00a28868)!=1u || !m.r32(0x00a28864))
        throw std::domain_error("Block178 requires count-zero one-slot collection state");
    through_leaf<0x10>(m,receiver+0x3d8,[&](leaf::Memory& local) {
        leaf::Inputs in{};in.cx=receiver+0x3d8;
        (void)leaf::fun_00405bf0(local,in);
    });
    m.w32(0x00a28870,1);
    m.w32(m.r32(0x00a28864),receiver);
}
}

std::uint32_t fun_00438aa0(Memory& m,const Inputs& i) {
    const auto receiver=i.cx;
    if(m.r32(0x00a28870)!=0 || m.r32(0x00a28868)!=1u || !m.r32(0x00a28864))
        throw std::domain_error("Block178 collection must start empty with one spare slot");
    helper_2b7580(m,receiver,i.arg[0]);

    // Direct root stores, retained in their original ordering and widths.
    const auto zero=std::uint32_t{0},one=std::uint32_t{1};
    m.w32(receiver+0x4f4,zero);
    const auto frame=m.r32(0x00a2896c);m.w32(receiver+0x4f8,frame);
    m.w32(receiver+0x500,zero);m.w32(receiver+0x504,zero);m.w32(receiver+0x508,one);
    m.w32(receiver+0x540,zero);m.w32(receiver+0x544,zero);
    m.w8(receiver+0x548,1);m.w8(receiver+0x549,0);
    m.w32(receiver+0x53c,0x00788054);
    m.w32(receiver+0x550,10);m.w32(receiver+0x54c,zero);
    m.w32(receiver+0x558,zero);m.w32(receiver+0x55c,zero);
    m.w8(receiver+0x560,1);m.w8(receiver+0x561,0);
    m.w32(receiver+0x554,0x00788054);
    m.w32(receiver+0x568,10);m.w32(receiver+0x564,zero);
    m.w32(receiver,0x00787bbc);m.w32(receiver+4,0x00787ba0);
    m.w32(receiver+8,0x00787b98);m.w32(receiver+0xc,0x00787b90);
    return receiver;
}
}
