#include "indirect_b25.hpp"
#include <stdexcept>

namespace ra2::recovered::indirect_b25 {
namespace {
std::uint32_t grow_append_body(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    const std::uint32_t limit_word = memory.r32(receiver + 0x8u); // observed field at +8
    std::uint32_t current_index = memory.r32(receiver + 0x10u); // observed field at +10
    if (leaf::s32(current_index) < leaf::s32(limit_word)) {
        const std::uint32_t storage = memory.r32(receiver + 0x4u);
        const std::uint32_t index = current_index;
        memory.w32(receiver + 0x10u, current_index + 1u);
        // Original reads the argument pointer after storing the incremented word.
        const std::uint32_t source = inputs.arg[0];
        const std::uint32_t item = memory.r32(source);
        memory.w32(storage + index * 4u, item);
        return (current_index & 0xffffff00u) | 1u;
    }

    std::uint32_t eax = (current_index & 0xffffff00u) | memory.r8(receiver + 0xdu);
    const bool guard_set = (eax & 0xffu) != 0u;
    if (!guard_set && limit_word != 0u) {
        eax &= 0xffffff00u; // XOR AL,AL; preserve original upper 24 EAX bits.
        return eax;
    }

    eax = memory.r32(receiver + 0x14u);
    if (leaf::s32(eax) <= 0) {
        eax &= 0xffffff00u;
        return eax;
    }
    const std::uint32_t dispatch_base = memory.r32(receiver);
    eax += limit_word; // Original 32-bit ADD wraps modulo 2^32.
    const std::uint32_t target = memory.r32(dispatch_base + 0x8u);
    if (!operations.invoke) throw std::invalid_argument("Block25 grow path requires a controlled observer");
    // PUSH 0; PUSH EAX means arg0=EAX and arg1=0 at callee entry.
    eax = operations.invoke(target, receiver, eax, 0u, operations.context);
    if ((eax & 0xffu) == 0u) {
        eax &= 0xffffff00u; // XOR AL,AL after callback; upper bits come from callback EAX.
        return eax;
    }

    // This success path reloads both fields after callback-visible memory mutation.
    const std::uint32_t current_index_after_callback = memory.r32(receiver + 0x10u);
    const std::uint32_t storage = memory.r32(receiver + 0x4u);
    memory.w32(receiver + 0x10u, current_index_after_callback + 1u);
    const std::uint32_t source = inputs.arg[0];
    const std::uint32_t item = memory.r32(source);
    memory.w32(storage + current_index_after_callback * 4u, item);
    return (current_index_after_callback & 0xffffff00u) | 1u;
}

std::uint32_t null_dispatch_body(leaf::Memory& memory, const leaf::Inputs& inputs,
    const Operations& operations, std::uint32_t slot_offset) {
    const std::uint32_t object = memory.r32(inputs.cx);
    if (object == 0u) return 0u;
    const std::uint32_t dispatch_base = memory.r32(object);
    const std::uint32_t target = memory.r32(dispatch_base + slot_offset);
    if (!operations.invoke) throw std::invalid_argument("Block25 dispatch requires a controlled observer");
    return operations.invoke(target, dispatch_base, object, 0u, operations.context);
}
} // namespace

const std::array<Entry, 41>& entries() {
    static const std::array<Entry, 41> value{{
    Entry{0x137b0u, 80u, 1u, 8u, &fun_004137b0},
    Entry{0x2b0f0u, 80u, 1u, 8u, &fun_0042b0f0},
    Entry{0x354b0u, 13u, 2u, 8u, &fun_004354b0},
    Entry{0x53ae0u, 13u, 2u, 8u, &fun_00453ae0},
    Entry{0x53b20u, 13u, 2u, 4u, &fun_00453b20},
    Entry{0x6cf00u, 80u, 1u, 8u, &fun_0046cf00},
    Entry{0xa4a20u, 13u, 2u, 8u, &fun_004a4a20},
    Entry{0xbf830u, 13u, 2u, 8u, &fun_004bf830},
    Entry{0xcdb60u, 13u, 2u, 8u, &fun_004cdb60},
    Entry{0xcddf0u, 80u, 1u, 8u, &fun_004cddf0},
    Entry{0xfa0f0u, 80u, 1u, 8u, &fun_004fa0f0},
    Entry{0xfa4c0u, 80u, 1u, 8u, &fun_004fa4c0},
    Entry{0xfa890u, 80u, 1u, 8u, &fun_004fa890},
    Entry{0x108cb0u, 13u, 2u, 8u, &fun_00508cb0},
    Entry{0x10a9e0u, 80u, 1u, 8u, &fun_0050a9e0},
    Entry{0x11d8a0u, 80u, 1u, 8u, &fun_0051d8a0},
    Entry{0x168820u, 80u, 1u, 8u, &fun_00568820},
    Entry{0x18bdf0u, 80u, 1u, 8u, &fun_0058bdf0},
    Entry{0x1c5f10u, 80u, 1u, 8u, &fun_005c5f10},
    Entry{0x204c30u, 80u, 1u, 8u, &fun_00604c30},
    Entry{0x212ee0u, 80u, 1u, 8u, &fun_00612ee0},
    Entry{0x213220u, 80u, 1u, 8u, &fun_00613220},
    Entry{0x213520u, 80u, 1u, 8u, &fun_00613520},
    Entry{0x232430u, 13u, 2u, 4u, &fun_00632430},
    Entry{0x24a4f0u, 80u, 1u, 8u, &fun_0064a4f0},
    Entry{0x24a8e0u, 80u, 1u, 8u, &fun_0064a8e0},
    Entry{0x24abf0u, 80u, 1u, 8u, &fun_0064abf0},
    Entry{0x24f0e0u, 13u, 2u, 8u, &fun_0064f0e0},
    Entry{0x24f0f0u, 13u, 2u, 8u, &fun_0064f0f0},
    Entry{0x24f100u, 80u, 1u, 8u, &fun_0064f100},
    Entry{0x252330u, 13u, 2u, 8u, &fun_00652330},
    Entry{0x252340u, 13u, 2u, 8u, &fun_00652340},
    Entry{0x25a4f0u, 80u, 1u, 8u, &fun_0065a4f0},
    Entry{0x25f4a0u, 80u, 1u, 8u, &fun_0065f4a0},
    Entry{0x28dad0u, 13u, 2u, 8u, &fun_0068dad0},
    Entry{0x28dd10u, 80u, 1u, 8u, &fun_0068dd10},
    Entry{0x2d4f00u, 80u, 1u, 8u, &fun_006d4f00},
    Entry{0x2ed7e0u, 80u, 1u, 8u, &fun_006ed7e0},
    Entry{0x3192f0u, 80u, 1u, 8u, &fun_007192f0},
    Entry{0x352010u, 13u, 2u, 8u, &fun_00752010},
    Entry{0x352020u, 13u, 2u, 8u, &fun_00752020}
    }};
    return value;
}

std::uint32_t fun_004137b0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    return grow_append_body(memory, inputs, operations);
}

std::uint32_t fun_0042b0f0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    return grow_append_body(memory, inputs, operations);
}

std::uint32_t fun_0046cf00(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    return grow_append_body(memory, inputs, operations);
}

std::uint32_t fun_004cddf0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    return grow_append_body(memory, inputs, operations);
}

std::uint32_t fun_004fa0f0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    return grow_append_body(memory, inputs, operations);
}

std::uint32_t fun_004fa4c0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    return grow_append_body(memory, inputs, operations);
}

std::uint32_t fun_004fa890(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    return grow_append_body(memory, inputs, operations);
}

std::uint32_t fun_0050a9e0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    return grow_append_body(memory, inputs, operations);
}

std::uint32_t fun_0051d8a0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    return grow_append_body(memory, inputs, operations);
}

std::uint32_t fun_00568820(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    return grow_append_body(memory, inputs, operations);
}

std::uint32_t fun_0058bdf0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    return grow_append_body(memory, inputs, operations);
}

std::uint32_t fun_005c5f10(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    return grow_append_body(memory, inputs, operations);
}

std::uint32_t fun_00604c30(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    return grow_append_body(memory, inputs, operations);
}

std::uint32_t fun_00612ee0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    return grow_append_body(memory, inputs, operations);
}

std::uint32_t fun_00613220(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    return grow_append_body(memory, inputs, operations);
}

std::uint32_t fun_00613520(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    return grow_append_body(memory, inputs, operations);
}

std::uint32_t fun_0064a4f0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    return grow_append_body(memory, inputs, operations);
}

std::uint32_t fun_0064a8e0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    return grow_append_body(memory, inputs, operations);
}

std::uint32_t fun_0064abf0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    return grow_append_body(memory, inputs, operations);
}

std::uint32_t fun_0064f100(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    return grow_append_body(memory, inputs, operations);
}

std::uint32_t fun_0065a4f0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    return grow_append_body(memory, inputs, operations);
}

std::uint32_t fun_0065f4a0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    return grow_append_body(memory, inputs, operations);
}

std::uint32_t fun_0068dd10(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    return grow_append_body(memory, inputs, operations);
}

std::uint32_t fun_006d4f00(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    return grow_append_body(memory, inputs, operations);
}

std::uint32_t fun_006ed7e0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    return grow_append_body(memory, inputs, operations);
}

std::uint32_t fun_007192f0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    return grow_append_body(memory, inputs, operations);
}

std::uint32_t fun_004354b0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    return null_dispatch_body(memory, inputs, operations, 8u);
}

std::uint32_t fun_00453ae0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    return null_dispatch_body(memory, inputs, operations, 8u);
}

std::uint32_t fun_00453b20(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    return null_dispatch_body(memory, inputs, operations, 4u);
}

std::uint32_t fun_004a4a20(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    return null_dispatch_body(memory, inputs, operations, 8u);
}

std::uint32_t fun_004bf830(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    return null_dispatch_body(memory, inputs, operations, 8u);
}

std::uint32_t fun_004cdb60(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    return null_dispatch_body(memory, inputs, operations, 8u);
}

std::uint32_t fun_00508cb0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    return null_dispatch_body(memory, inputs, operations, 8u);
}

std::uint32_t fun_00632430(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    return null_dispatch_body(memory, inputs, operations, 4u);
}

std::uint32_t fun_0064f0e0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    return null_dispatch_body(memory, inputs, operations, 8u);
}

std::uint32_t fun_0064f0f0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    return null_dispatch_body(memory, inputs, operations, 8u);
}

std::uint32_t fun_00652330(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    return null_dispatch_body(memory, inputs, operations, 8u);
}

std::uint32_t fun_00652340(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    return null_dispatch_body(memory, inputs, operations, 8u);
}

std::uint32_t fun_0068dad0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    return null_dispatch_body(memory, inputs, operations, 8u);
}

std::uint32_t fun_00752010(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    return null_dispatch_body(memory, inputs, operations, 8u);
}

std::uint32_t fun_00752020(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    return null_dispatch_body(memory, inputs, operations, 8u);
}

} // namespace ra2::recovered::indirect_b25
