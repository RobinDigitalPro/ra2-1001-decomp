#include "recovered/recovery_b436.hpp"

#include "recovered/allocation_families.hpp"

#include <array>
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::ini436 {
namespace {
using global_b26::Inputs;
using global_b26::Memory;

std::uint32_t no_alloc(std::uint32_t, std::uint32_t, void*) {
    throw std::domain_error("0x573e00 zero-count path unexpectedly allocated");
}
std::uint32_t no_free(std::uint32_t, void*) {
    throw std::domain_error("0x573e00 zero-count path unexpectedly freed");
}
const AllocationWrapperOperations no_allocation{no_alloc, no_free, nullptr};

void initialize_base_zero_selector(Memory& memory, std::uint32_t receiver) {
    // Bounded composition of the already accepted 0x173d40 branch reached
    // here: zero selector skips dictionary lookup and UTF-16 text copy.
    if (memory.r32(0x00ab7eccu) != 0u)
        throw std::domain_error("0x573e00 draft covers only 0x173d40 zero-selector branch");
    if (memory.r32(0x00790830u) != 0x0053ac50u)
        throw std::domain_error("0x573e00 pinned 0x173d40 vtable slot differs");
    const auto w32=[&](std::uint32_t off,std::uint32_t value){memory.w32(receiver+off,value);};
    w32(0x20u,0x00790824u);w32(0x24u,0);w32(0x28u,0);memory.w8(receiver+0x2cu,1);memory.w8(receiver+0x2du,0);
    w32(0x30u,0);w32(0x34u,10);
    w32(4u,0);w32(0xcu,receiver+0x78u);w32(0x14u,0);
    w32(0,0x007907fcu);w32(8u,0x007ca620u);w32(0x10u,0x800u);
    w32(0x38u,0);w32(0x3cu,1);w32(0x40u,1);w32(0x44u,0);w32(0x48u,1);w32(0x4cu,0);w32(0x50u,2);
    for(std::uint32_t off=0x54u;off<=0x70u;off+=4u)w32(off,0);
    w32(0x74u,0xffffffffu);w32(0,0x00790e04u);w32(8u,0x007cbfe4u);
    memory.w16(receiver+0x78u,0);
}

template <class Call>
void run_array_ctor(Memory& memory, std::uint32_t address, Call call,
                    std::uint32_t initial_tag) {
    std::array<std::uint8_t, 0x18> bytes{};
    for (std::uint32_t n = 0; n < bytes.size(); ++n)
        bytes[n] = static_cast<std::uint8_t>(memory.r8(address + n));
    leaf::Memory local(bytes.data(), address, static_cast<std::uint32_t>(bytes.size()));
    leaf::Inputs in{};
    in.cx = address;
    in.arg[0] = 0; // EBX is zero at every call in the 0x573e00 body.
    in.arg[1] = 0;
    (void)call(local, in, no_allocation);
    for (std::uint32_t n = 0; n < bytes.size(); ++n)
        memory.w8(address + n, local.r8(address + n));
    memory.w32(address, initial_tag); // The original caller writes the final tag.
}
}

std::uint32_t fun_00573e00(Memory& memory, const Inputs& inputs) {
    const auto receiver = inputs.cx;
    if (receiver == 0) throw std::domain_error("0x573e00 requires a writable receiver");

    // The accepted 0x573d40 zero-selector route is inlined so this scoped
    // translation does not pull unrelated branches into its link closure.
    initialize_base_zero_selector(memory, receiver);

    memory.w32(receiver + 0x178u, 0);
    memory.w32(receiver + 0x17cu, 0);
    memory.w32(receiver + 0x180u, 0);
    memory.w32(receiver + 0x184u, 0);

    const auto array18 = [&](std::uint32_t off) {
        run_array_ctor(memory, receiver + off, fun_0046cdf0, 0x007889f4u);
    };
    const auto array49 = [&](std::uint32_t off, std::uint32_t tag) {
        run_array_ctor(memory, receiver + off, fun_0046cc20, tag);
    };
    const auto array49_f7ea0 = [&](std::uint32_t off, std::uint32_t tag) {
        run_array_ctor(memory, receiver + off, fun_004f7ea0, tag);
    };
    array18(0x188u);
    array18(0x1a4u);
    array18(0x1c0u);
    array18(0x1dcu);
    array49(0x1f8u, 0x007889f4u);
    memory.w32(receiver + 0x1f8u + 0x14u, 10u);
    memory.w32(receiver + 0x1f8u + 0x10u, 0u);
    array18(0x214u);
    array18(0x230u);
    array18(0x24cu);
    array49(0x268u, 0x007889f4u);
    memory.w32(receiver + 0x268u + 0x14u, 10u);
    memory.w32(receiver + 0x268u + 0x10u, 0u);
    array18(0x284u);
    array18(0x2a0u);
    memory.w32(receiver + 0x2bcu, 0x9c4u);
    memory.w32(receiver + 0x2c0u, 0x157cu);
    run_array_ctor(memory, receiver + 0x2c4u, fun_0058af70, 0x00790e2cu);
    array49_f7ea0(0x2e0u, 0x00790e2cu);
    memory.w32(receiver + 0x2e0u + 0x14u, 10u);
    memory.w32(receiver + 0x2e0u + 0x10u, 0u);
    memory.w32(receiver + 0x2fcu, 0x1f4u);
    memory.w8(receiver + 0x300u, 1u);
    memory.w32(receiver + 0x304u, 0u);
    memory.w32(receiver + 0x30cu, 4u);
    memory.w8(receiver + 0x310u, 0u);
    return receiver;
}
}
