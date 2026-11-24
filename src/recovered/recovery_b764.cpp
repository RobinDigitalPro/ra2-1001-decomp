#include "recovery_b764.hpp"
#include "platform/observed_ticks152.hpp"
#include <stdexcept>

namespace ra2::recovered::recovery_b764 {
namespace {
void require(bool ok, const char* message) {
    if (!ok) throw std::domain_error(message);
}
void put_stack32(Inputs& in, unsigned offset, std::uint32_t value) {
    for (unsigned k = 0; k < 4; ++k)
        in.raw_stack[offset + k] = static_cast<std::uint8_t>(value >> (8u * k));
}
void format_selector19(Memory& memory, Inputs& in, std::uint32_t object) {
    const auto value = memory.r32(object + 0x30u);
    require(value <= 0x7fffffffu, "outside nonnegative 21b240 formatter route");
    // Exact reached b5ce0 effects for selector 19; 68f0 is the evidenced RET.
    (void)memory.r32(0x7c16fcu + 4u * 19u);
    (void)0x7c19c0u; // pushed by the helper, not dereferenced by reached closure
    in.raw_stack[2] = static_cast<std::uint8_t>(value);
    in.raw_stack[0] = 19u;
    put_stack32(in, 3u, memory.r32(0xa2896cu));
}
void copy_record(Memory& memory, const Inputs& in, std::uint32_t destination) {
    for (unsigned k = 0; k < 111; ++k)
        memory.w8(destination + k, in.raw_stack[k]);
}
}

std::uint32_t fun_0061b240(Memory& memory, Inputs& in) {
    const auto object = memory.r32(0xa1e0e4u);
    require(object != 0, "missing 21b240 object");
    require(memory.r32(0xa255c8u)<4u,"outside normal-mode selector19 route");
    const auto count = memory.r32(0xa1a668u);
    require(count < 0x80u, "outside unsaturated 21b240 ring");
    const auto cursor = memory.r32(0xa1a670u);
    require(cursor < 0x80u, "outside bounded 21b240 ring cursor");

    format_selector19(memory, in, object);
    copy_record(memory, in, 0xa1a674u + 111u * cursor);
    memory.w32(0xa1ddf4u + 4u * cursor,
               ra2::platform::ticks152::Tick::get());
    memory.w32(0xa1a668u, count + 1u);
    memory.w32(0xa1a670u, (cursor + 1u) & 0x7fu);
    // The bounded old count makes INC EAX yield 1..128; MOV AL,1 then gives 1.
    return 1u;
}
}
