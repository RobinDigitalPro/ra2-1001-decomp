#define NOMINMAX
#include <windows.h>

#include "recovered/recovery_b149.hpp"
#include "platform/observed_mutex149.hpp"

#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b149 {
using namespace global_b26;

namespace {
std::int32_t signed_word(Memory& memory, std::uint32_t address) {
    return static_cast<std::int16_t>(memory.r16(address));
}

void read_rectangle(Memory& memory, std::uint32_t object,
                    std::uint32_t& x, std::uint32_t& y,
                    std::uint32_t& width, std::uint32_t& height) {
    const auto table = memory.r32(object + 4u);
    const auto index = memory.r32(object + 8u);
    const auto count = signed_word(memory, table + 6u);
    if (count > 0 && index < static_cast<std::uint32_t>(count)) {
        const auto item = table + 8u + index * 24u;
        x = static_cast<std::uint32_t>(signed_word(memory, item));
        y = static_cast<std::uint32_t>(signed_word(memory, item + 2u));
        width = static_cast<std::uint32_t>(signed_word(memory, item + 4u));
        height = static_cast<std::uint32_t>(signed_word(memory, item + 6u));
        return;
    }
    x = memory.r32(0x00b103b8u);
    y = memory.r32(0x00b103bcu);
    width = memory.r32(0x00b103c0u);
    height = memory.r32(0x00b103c4u);
}
}

std::uint32_t fun_0075dab0(Memory& memory, const Inputs& input) {
    static_assert(sizeof(void*) == 4, "RVA 0x35dab0 requires the original x86 process ABI");
    const auto object = input.cx;
    if (memory.r32(object + 4u) == 0u)
        throw std::domain_error("0x35dab0 bounded route requires its non-null sync gate");

    // Both calls reach the exact imported Kernel32 APIs at original IAT VAs
    // 0x7851d0 and 0x785190. The supplied handle is a real per-fixture mutex.
    const auto raw_handle = memory.r32(0x00b103f8u);
    const auto mutex = reinterpret_cast<HANDLE>(static_cast<std::uintptr_t>(raw_handle));
    if (ra2::platform::mutex149::Mutex::wait(mutex, 0x2710u) != WAIT_OBJECT_0)
        throw std::domain_error("0x35dab0 route requires a real immediately available mutex");

    std::uint32_t x = 0, y = 0, width = 0, height = 0;
    read_rectangle(memory, object, x, y, width, height);

    // Preserve original 32-bit wraparound arithmetic for the translated origin.
    const auto left = memory.r32(object + 0x14u) - memory.r32(object + 0x3cu) + x;
    const auto top = memory.r32(object + 0x18u) - memory.r32(object + 0x40u) + y;
    const auto result_width = width;
    const auto result_height = height;
    const auto output = input.arg[0];
    (void)ra2::platform::mutex149::Mutex::release(mutex); // Original ignores this BOOL result.
    memory.w32(output, left);
    memory.w32(output + 4u, top);
    memory.w32(output + 8u, result_width);
    memory.w32(output + 12u, result_height);
    return output;
}
}
