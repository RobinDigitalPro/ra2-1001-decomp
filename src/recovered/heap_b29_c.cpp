#include "recovered/heap_b29_memory.hpp"

namespace ra2::recovered::heap_b29 {
namespace {
void set_zero_if_needed(Memory& m, State& s, const Operations& ops,
                        std::uint32_t size, std::uint32_t object,
                        std::uint32_t initial_vtable, std::uint32_t final_vtable,
                        bool counted_tail) {
    std::uint32_t count = s.arg[0];
    m.w32(object + 4u, 0u);
    m.w32(object + 8u, count);
    m.w8(object + 0x0cu, 1u);
    m.w8(object + 0x0du, 0u);
    m.w32(object, initial_vtable);
    if (count != 0u) {
        const std::uint32_t supplied = s.arg[1];
        if (supplied != 0u) {
            count -= 1u;
            m.w32(object + 4u, supplied);
            s.arg[0] = count;
        } else {
            allocate(m, s, ops, size);
            const std::uint32_t pointer = s.ax;
            if (pointer != 0u)
                s.arg[0] = count - 1u;
            m.w32(object + 4u, pointer);
            m.w8(object + 0x0du, 1u);
        }
    }
    m.w32(object, final_vtable);
    if (counted_tail) {
        m.w32(object + 0x14u, 10u);
        m.w32(object + 0x10u, 0u);
    }
    s.ax = object;
}

std::uint32_t rounded_128(std::uint32_t value) {
    const std::uint32_t sign_adjust = s32(value) < 0 ? 0x7fu : 0u;
    std::uint32_t result = static_cast<std::uint32_t>(sar(value + sign_adjust, 7u)) + 1u;
    if (s32(result) < 128) result = 128u;
    return result;
}
} // namespace

void fun_00407400(Memory& m, State& s, const Operations& ops) {
    const std::uint32_t length = s.dx + 8u;
    const std::uint32_t object = s.cx;
    const std::uint32_t bytes = length * object + 8u;
    allocate(m, s, ops, bytes);
    std::uint32_t block = s.ax;
    if (block != 0u) {
        std::uint32_t remaining = object - 1u;
        std::uint32_t cursor = block + 8u;
        m.w32(block, cursor);
        if (remaining != 0u) {
            do {
                const std::uint32_t next = cursor + length;
                remaining -= 1u;
                m.w32(cursor, next);
                cursor = next;
            } while (remaining != 0u);
            s.dx = cursor;
        } else {
            s.dx = object - 1u;
        }
        m.w32(cursor, 0u);
        s.cx = cursor;
    }
}

void fun_0042b620(Memory& m, State& s, const Operations& ops) {
    const std::uint32_t object = s.cx;
    const std::uint32_t count = s.arg[0];
    s.dx = 0u;
    m.w32(object + 4u, 0u); m.w32(object + 8u, count);
    m.w8(object + 0x0cu, 1u); m.w8(object + 0x0du, 0u);
    m.w32(object, 0x00787534u);
    if (count != 0u) {
        const std::uint32_t supplied = s.arg[1];
        if (supplied != 0u) { m.w32(object + 4u, supplied); s.cx = supplied; }
        else {
            allocate(m, s, ops, count * 2u);
            m.w32(object + 4u, s.ax); m.w8(object + 0x0du, 1u);
        }
    }
    s.ax = object;
}

void fun_0042ce60(Memory& m, State& s, const Operations& ops) {
    set_zero_if_needed(m, s, ops, s.arg[0] * 4u, s.cx, 0x007875e0u, 0x007875a0u, true);
}

void fun_0042d430(Memory& m, State& s, const Operations& ops) {
    set_zero_if_needed(m, s, ops, s.arg[0] << 4u, s.cx, 0x00787600u, 0x00787600u, false);
}

void fun_0042d4a0(Memory& m, State& s, const Operations& ops) {
    set_zero_if_needed(m, s, ops, s.arg[0] * 4u, s.cx, 0x007875e0u, 0x007875e0u, false);
}

void fun_00438140(Memory& m, State& s, const Operations& ops) {
    const std::uint32_t object = s.cx, pointer = s.arg[0], count = s.arg[1];
    s.cx = count;
    m.w32(object, pointer); m.w32(object + 4u, count); m.w8(object + 8u, 0u);
    if (pointer == 0u && s32(count) > 0) {
        allocate(m, s, ops, count);
        m.w32(object, s.ax); m.w8(object + 8u, 1u);
    }
    s.ax = object;
}

void fun_00438200(Memory& m, State& s, const Operations& ops) {
    const std::uint32_t object = s.cx, count = s.arg[0];
    m.w32(object, 0u); m.w32(object + 4u, count); m.w8(object + 8u, 0u);
    if (s32(count) > 0) {
        allocate(m, s, ops, count);
        m.w32(object, s.ax); m.w8(object + 8u, 1u);
    }
    s.ax = object;
}

void fun_004945e0(Memory& m, State& s, const Operations& ops) {
    const std::uint32_t object = s.cx;
    s.ax = 0u;
    m.w32(object + 8u, 0u); m.w32(object + 0x0cu, 0u);
    m.w8(object + 0x10u, 0u); m.w8(object + 0x11u, 0u);
    m.w32(object + 0x14u, 0u);
    allocate(m, s, ops, 0x10000u); m.w32(object + 0x18u, s.ax);
    allocate(m, s, ops, 0x10000u); m.w32(object + 0x1cu, s.ax);
    allocate(m, s, ops, 0x10000u); m.w32(object + 0x20u, s.ax);
    m.w32(object, 0x00789704u); m.w32(object + 4u, 0x007896ecu);
    m.w32(object + 0x24u, 0xffffu);
    s.ax = object;
}

void fun_004f8220(Memory& m, State& s, const Operations& ops) {
    const std::uint32_t object = s.cx, count = s.arg[0];
    s.dx = 0u;
    m.w32(object + 4u, 0u); m.w32(object + 8u, count);
    m.w8(object + 0x0cu, 1u); m.w8(object + 0x0du, 0u);
    m.w32(object, 0x0078df64u);
    if (count != 0u) {
        const std::uint32_t supplied = s.arg[1];
        if (supplied != 0u) { m.w32(object + 4u, supplied); s.cx = supplied; }
        else {
            allocate(m, s, ops, count);
            m.w32(object + 4u, s.ax); m.w8(object + 0x0du, 1u);
        }
    }
    s.ax = object;
}

void fun_00533140(Memory& m, State& s, const Operations& ops) {
    const std::uint32_t object = s.cx;
    const std::uint32_t first = s.arg[0], count = s.arg[1];
    const std::uint32_t capacity = rounded_128(count);
    m.w32(object + 0x0cu, first); m.w32(object + 4u, 0u); m.w32(object + 8u, 0u);
    m.w32(object + 0x10u, 0u); m.w32(object + 0x14u, 0u); m.w32(object + 0x18u, 0u);
    m.w32(object + 0x1cu, count); m.w32(object, 0x00790444u); m.w32(object + 0x20u, capacity);
    allocate(m, s, ops, capacity + count);
    m.w32(object + 0x14u, s.ax);
    const std::uint32_t second_size = m.r32(object + 0x20u) + m.r32(object + 0x1cu);
    allocate(m, s, ops, second_size);
    m.w32(object + 0x18u, s.ax);
    m.w16(object + 0x24u, 0xffffu);
    s.ax = object;
}

void fun_00533530(Memory& m, State& s, const Operations& ops) {
    const std::uint32_t object = s.cx, first = s.arg[0], count = s.arg[1];
    const std::uint32_t capacity = static_cast<std::uint32_t>(sar(count + (s32(count) < 0 ? 0x7fu : 0u), 7u)) + 1u;
    m.w32(object + 4u, 0u); m.w32(object + 8u, 0u);
    m.w32(object + 0x0cu, first); m.w32(object + 0x10u, 0u); m.w32(object + 0x14u, 0u);
    m.w32(object + 0x18u, 0u); m.w32(object + 0x1cu, count); m.w32(object + 0x20u, capacity);
    m.w32(object, 0x0079045cu);
    allocate(m, s, ops, capacity + count); m.w32(object + 0x14u, s.ax);
    if (first == 0u) {
        const std::uint32_t second_size = m.r32(object + 0x20u) + m.r32(object + 0x1cu);
        allocate(m, s, ops, second_size); m.w32(object + 0x18u, s.ax);
    }
    s.ax = object;
}

void fun_00533b70(Memory& m, State& s, const Operations& ops) {
    std::uint32_t object = m.r32(0x00a563f4u);
    if (object == 0u) {
        allocate(m, s, ops, 0x60u);
        object = s.ax;
        if (object == 0u) {
            m.w32(0x00a563f4u, 0u);
            s.ax = 0u;
            return;
        }
        m.w32(object, 0x0079047cu); m.w32(object + 4u, 0u);
        m.w32(object + 0x38u, 0u); m.w32(object + 0x3cu, 0u);
        m.w32(object + 0x40u, 0u); m.w32(object + 0x44u, 0u);
        m.w32(object + 0x48u, 0u); m.w8(object + 0x4cu, 0u);
        m.w8(object + 0x4du, 0u); m.w8(object + 0x4eu, 0u);
        m.w32(object + 0x50u, 0u); m.w32(object + 0x54u, 0u);
        m.w32(object + 0x58u, 0u); m.w32(object + 0x5cu, 0u);
        m.w32(0x00a563f4u, object);
    }
    s.ax = object;
}

void fun_0053cd20(Memory& m, State& s, const Operations& ops) {
    const std::uint32_t object = s.cx, first = s.arg[0], count = s.arg[1];
    m.w32(object + 4u, 0u); m.w32(object + 8u, 0u); m.w32(object + 0x10u, 0u);
    m.w32(object + 0x14u, 0u); m.w32(object + 0x18u, 0u);
    m.w32(object + 0x0cu, first); m.w32(object + 0x1cu, count);
    m.w32(object + 0x20u, count); m.w32(object, 0x00790894u);
    allocate(m, s, ops, count * 2u); m.w32(object + 0x14u, s.ax);
    const std::uint32_t second_size = m.r32(object + 0x20u) + m.r32(object + 0x1cu);
    allocate(m, s, ops, second_size); m.w32(object + 0x18u, s.ax);
    m.w16(object + 0x24u, 0xffffu); s.ax = object;
}

void fun_0053d190(Memory& m, State& s, const Operations& ops) {
    const std::uint32_t object = s.cx, first = s.arg[0], count = s.arg[1];
    m.w32(object + 0x1cu, count); m.w32(object + 0x20u, count);
    m.w32(object + 4u, 0u); m.w32(object + 8u, 0u); m.w32(object + 0x0cu, first);
    m.w32(object + 0x10u, 0u); m.w32(object + 0x14u, 0u); m.w32(object + 0x18u, 0u);
    m.w32(object, 0x007908acu);
    allocate(m, s, ops, count * 2u); m.w32(object + 0x14u, s.ax);
    if (first == 0u) {
        const std::uint32_t second_size = m.r32(object + 0x20u) + m.r32(object + 0x1cu);
        allocate(m, s, ops, second_size); m.w32(object + 0x18u, s.ax);
    }
    s.ax = object;
}

void fun_00569bc0(Memory& m, State& s, const Operations& ops) {
    set_zero_if_needed(m, s, ops, s.arg[0] * 8u, s.cx, 0x00790ad8u, 0x00790ad8u, false);
}

void fun_00588000(Memory& m, State& s, const Operations& ops) {
    const auto object=s.cx;
    m.w32(object+8u,0u);m.w32(object,1u);
    allocate(m,s,ops,8u);const auto block=s.ax;
    if(block) {m.w16(block,0u);m.w16(block+2u,0u);m.w32(block+4u,0xffffffffu);}
    const auto input=s.arg[0];m.w32(object+4u,block);
    s.dx=m.r32(input);m.w32(block,s.dx);
    s.cx=m.r32(input+4u);m.w32(block+4u,s.cx);s.ax=object;
}

void fun_00588050(Memory& m, State& s, const Operations& ops) {
    const auto object=s.cx;
    m.w32(object+8u,0u);m.w32(object,2u);
    allocate(m,s,ops,0x10u);const auto block=s.ax;
    if(block)for(std::uint32_t i=0;i<2u;++i) {
        m.w16(block+i*8u,0u);m.w16(block+i*8u+2u,0u);m.w32(block+i*8u+4u,0xffffffffu);
    }
    const auto input0=s.arg[0];m.w32(object+4u,block);
    s.dx=m.r32(input0);m.w32(block,s.dx);
    s.cx=m.r32(input0+4u);m.w32(block+4u,s.cx);
    const auto input1=s.arg[1];s.dx=m.r32(object+4u);
    s.cx=m.r32(input1);m.w32(s.dx+8u,s.cx);
    s.ax=m.r32(input1+4u);m.w32(s.dx+0xcu,s.ax);s.ax=object;
}

void fun_005880c0(Memory& m, State& s, const Operations& ops) {
    const auto object=s.cx;
    m.w32(object+8u,0u);m.w32(object,3u);
    allocate(m,s,ops,0x18u);const auto block=s.ax;
    if(block)for(std::uint32_t i=0;i<3u;++i) {
        m.w16(block+i*8u,0u);m.w16(block+i*8u+2u,0u);m.w32(block+i*8u+4u,0xffffffffu);
    }
    const auto input0=s.arg[0];m.w32(object+4u,block);
    s.dx=m.r32(input0);m.w32(block,s.dx);
    s.cx=m.r32(input0+4u);m.w32(block+4u,s.cx);
    const auto input1=s.arg[1];s.dx=m.r32(object+4u);
    s.cx=m.r32(input1);m.w32(s.dx+8u,s.cx);
    s.ax=m.r32(input1+4u);m.w32(s.dx+0xcu,s.ax);
    const auto input2=s.arg[2];s.cx=m.r32(object+4u);
    s.dx=m.r32(input2);m.w32(s.cx+0x10u,s.dx);
    s.ax=m.r32(input2+4u);m.w32(s.cx+0x14u,s.ax);s.ax=object;
}

void fun_0058c060(Memory& m, State& s, const Operations& ops) {
    set_zero_if_needed(m, s, ops, s.arg[0] << 4u, s.cx, 0x00790e98u, 0x00790e98u, false);
}

void fun_0059cdd0(Memory& m, State& s, const Operations& ops) {
    set_zero_if_needed(m, s, ops, s.arg[0] * 8u, s.cx, 0x00790ad8u, 0x00790a58u, true);
}

void fun_0062c630(Memory& m, State& s, const Operations& ops) {
    set_zero_if_needed(m, s, ops, s.arg[0] * 8u, s.cx, 0x00791f9cu, 0x00791f9cu, false);
}

void fun_0062f8b0(Memory& m, State& s, const Operations& ops) {
    const std::uint32_t object = s.cx, first = s.arg[0], second = s.arg[1];
    s.dx = 0u;
    m.w32(object + 4u, first); m.w32(object + 8u, second); m.w32(object + 0x0cu, second);
    m.w32(object + 0x10u, 0u); m.w32(object + 0x14u, 1u);
    m.w8(object + 0x18u, 0u); m.w8(object + 0x19u, 0u); m.w32(object, 0x00793bf4u);
    s.cx = first;
    if (first == 0u && s32(second) > 0) {
        allocate(m, s, ops, second);
        m.w32(object + 4u, s.ax); m.w8(object + 0x19u, 1u);
    }
    s.ax = object;
}

void fun_00677cb0(Memory& m, State& s, const Operations& ops) {
    set_zero_if_needed(m, s, ops, s.arg[0] * 8u, s.cx, 0x00791f9cu, 0x00791f7cu, true);
}

void fun_0068f840(Memory& m, State& s, const Operations& ops) {
    const std::uint32_t object = s.cx, size = s.arg[0];
    m.w32(object, size);
    allocate(m, s, ops, size);
    const std::uint32_t pointer = s.ax;
    m.w32(object + 4u, pointer); m.w32(object + 8u, pointer);
    s.ax = object;
}

void fun_007108c0(Memory& m, State& s, const Operations& ops) {
    const std::uint32_t object = s.cx, first = s.arg[0], second = s.arg[1];
    if (first == 0u) {
        allocate(m, s, ops, 0x300u);
        m.w32(object + 0x10u, s.ax); m.w32(object + 0x18u, 1u);
    } else {
        m.w32(object + 0x10u, first); m.w32(object + 0x18u, 0u);
    }
    if (second == 0u) {
        allocate(m, s, ops, 0x8000u);
        m.w32(object + 0x14u, s.ax); m.w32(object + 0x1cu, 1u);
    } else {
        m.w32(object + 0x14u, second); m.w32(object + 0x1cu, 0u);
    }
    s.ax = object;
}

void fun_00728ce0(Memory& m, State& s, const Operations& ops) {
    const std::uint32_t object = s.cx;
    m.w32(object, 0x0079a370u);
    allocate(m, s, ops, 0x2000u); m.w32(object + 0x24u, s.ax);
    m.w32(object + 0x54u, 0u); m.w32(object + 0x58u, 0u);
    m.w8(object + 0x50u, 0u); m.w8(object + 0x51u, 0u);
    m.w32(object + 0x68u, 0u); m.w32(object + 0x64u, 0u);
    m.w32(object + 4u, 0u); m.w32(object + 8u, 0u); m.w32(object + 0x0cu, 0u);
    m.w32(object + 0x10u, 0u); m.w32(object + 0x14u, 0u); m.w32(object + 0x18u, 0u);
    m.w32(object + 0x5cu, 0xffffffffu);
    s.ax = object;
}

const std::array<Entry, 26>& entries_c() {
    static const std::array<Entry, 26> entries{{
        {0x7400u, fun_00407400}, {0x2b620u, fun_0042b620}, {0x2ce60u, fun_0042ce60},
        {0x2d430u, fun_0042d430}, {0x2d4a0u, fun_0042d4a0}, {0x38140u, fun_00438140},
        {0x38200u, fun_00438200}, {0x945e0u, fun_004945e0}, {0xf8220u, fun_004f8220},
        {0x133140u, fun_00533140}, {0x133530u, fun_00533530}, {0x133b70u, fun_00533b70},
        {0x13cd20u, fun_0053cd20}, {0x13d190u, fun_0053d190}, {0x169bc0u, fun_00569bc0},
        {0x188000u, fun_00588000}, {0x188050u, fun_00588050}, {0x1880c0u, fun_005880c0},
        {0x18c060u, fun_0058c060}, {0x19cdd0u, fun_0059cdd0}, {0x22c630u, fun_0062c630},
        {0x22f8b0u, fun_0062f8b0}, {0x277cb0u, fun_00677cb0}, {0x28f840u, fun_0068f840},
        {0x3108c0u, fun_007108c0}, {0x328ce0u, fun_00728ce0}
    }};
    return entries;
}
} // namespace ra2::recovered::heap_b29
