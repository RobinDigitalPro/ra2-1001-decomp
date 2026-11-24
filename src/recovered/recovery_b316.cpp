#include "recovery_b316.hpp"

#include <stdexcept>

namespace ra2::recovered::recovery_b316 {
namespace {
void need(bool ok,const char* why) { if(!ok) throw std::domain_error(why); }
}

std::uint32_t fun_0046af70(Memory& memory,Inputs& in,GuestHeap& heap,
                           std::uint32_t frame_base) {
    constexpr std::uint32_t prefix_flag_va=0x008248a4u;
    need(in.cx&&in.arg[0]&&in.arg[1]&&in.arg[2],
         "0x6af70 route requires root, section, key and collection pointers");
    need(frame_base&&std::uint64_t(frame_base)+0x210u<=0x100000000ull,
         "0x6af70 local frame must be mapped and nonwrapping");
    need(memory.r8(prefix_flag_va)==0,
         "0x6af70 route requires the original zero-filled optional-prefix byte");
    const auto collection=in.arg[2];
    need(memory.r32(collection+0x10u)==1,
         "0x6af70 finite route covers exactly one integer row");
    const auto values=memory.r32(collection+4u);
    need(values!=0,"0x6af70 one-row collection requires its integer array");
    const auto value=memory.r32(values);
    need(value>=10u&&value<=99u,
         "0x6af70 finite formatter route requires a two-digit positive value");

    // At entry S0, the original SUB ESP,0x210 makes frame_base=S0-0x210.
    // The root saves ECX at +0, the %d temporary begins at +4, the local
    // accumulator prefix byte is +0x10, and its copied value begins there.
    memory.w32(frame_base,in.cx);
    memory.w8(frame_base+0x10u,0);
    for(std::uint32_t i=0x11u;i!=0x210u;++i) memory.w8(frame_base+i,0);
    const std::uint8_t digits[3]={
        static_cast<std::uint8_t>('0'+value/10u),
        static_cast<std::uint8_t>('0'+value%10u),0};
    for(unsigned i=0;i<3;++i) memory.w8(frame_base+4u+i,digits[i]);
    for(unsigned i=0;i<3;++i) memory.w8(frame_base+0x10u+i,digits[i]);

    // Original 0x46b04c calls 0x10da40 with outer section/key and the local
    // accumulator. Keep helper argument writes in its own temporary Inputs.
    Inputs child{};
    child.ax=in.ax; child.cx=in.cx; child.dx=in.dx;
    child.arg[0]=in.arg[0]; child.arg[1]=in.arg[1]; child.arg[2]=frame_base+0x10u;
    child.stack_minus8=in.stack_minus8; child.arithmetic_flags=in.arithmetic_flags;
    const auto eax=ra2::recovered::recovery_b305::fun_0010da40(memory,child,heap);
    in.ax=eax;
    return eax;
}
}
