#pragma once
#include "platform/x87_state.hpp"
namespace ra2::platform::x87_b61 {
// Elementary register operations absent from the older adapter. Numeric guest
// state stays explicit; these are not calls into original game code.
template<unsigned Opcode> inline void reg(x87::State& state) {
    static_assert(Opcode==0xddd8||Opcode==0xd8f1||Opcode==0xdec9||Opcode==0xdec1||
        Opcode==0xded9||Opcode==0xd9c0||Opcode==0xd8c1||Opcode==0xd8cc||
        Opcode==0xd9c2||Opcode==0xd8ce||Opcode==0xd9c3||Opcode==0xd8cf||
        Opcode==0xd9c9||Opcode==0xd8c9||Opcode==0xd8cb||Opcode==0xd9e0||
        Opcode==0xdee9||Opcode==0xd8d9||Opcode==0xdcc0||Opcode==0xd9c1||
        Opcode==0xd8e1||Opcode==0xdddb,"unreviewed x87 elementary operation");
    state.require_masked();x87::Image host;
    asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\t.byte %c[first],%c[second]\n\tfnsave %[guest]\n\tfrstor %[host]"
        : [host]"=m"(host.bytes),[guest]"+m"(state.image.bytes)
        : [first]"i"(Opcode>>8),[second]"i"(Opcode&255)
        : "memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");
}
inline void reverse_subtract32(x87::State& state,std::uint32_t operand) {
    state.require_masked();x87::Image host;
    asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\tfsubrs %[operand]\n\tfnsave %[guest]\n\tfrstor %[host]"
        : [host]"=m"(host.bytes),[guest]"+m"(state.image.bytes) : [operand]"m"(operand)
        : "memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");
}
}
