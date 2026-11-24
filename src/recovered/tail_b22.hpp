#pragma once
#include <array>
#include <cstddef>
#include <cstdint>

namespace ra2::recovered::tail_b22 {
// Raw guest x86-32 state at a wrapper boundary. Field order is stable for the
// native bridge; no source ABI or class identity is implied.
struct Cpu32 {
    std::uint32_t eax, ecx, edx, ebx, esp, ebp, esi, edi, eflags, next_eip;
};
class Memory {
public:
    virtual ~Memory() = default;
    virtual std::uint8_t read8(std::uint32_t address) const = 0;
    virtual std::uint32_t read32(std::uint32_t address) const = 0;
    virtual void write8(std::uint32_t address, std::uint32_t value) = 0;
    virtual void write32(std::uint32_t address, std::uint32_t value) = 0;
};
using Function = void (*)(Memory&, Cpu32&);
struct Entry { std::uint32_t rva, size; Function function; };

void fun_004026a0(Memory&, Cpu32&);
void fun_004026b0(Memory&, Cpu32&);
void fun_00403810(Memory&, Cpu32&);
void fun_00406fa0(Memory&, Cpu32&);
void fun_00407fe0(Memory&, Cpu32&);
void fun_00408400(Memory&, Cpu32&);
void fun_00408440(Memory&, Cpu32&);
void fun_0046e0c0(Memory&, Cpu32&);
void fun_00479e20(Memory&, Cpu32&);
void fun_00481170(Memory&, Cpu32&);
void fun_004c8890(Memory&, Cpu32&);
void fun_004c8970(Memory&, Cpu32&);
void fun_004cca70(Memory&, Cpu32&);
void fun_004ced20(Memory&, Cpu32&);
void fun_004ced30(Memory&, Cpu32&);
void fun_0051a280(Memory&, Cpu32&);
void fun_00539370(Memory&, Cpu32&);
void fun_005393c0(Memory&, Cpu32&);
void fun_0059a2e0(Memory&, Cpu32&);
void fun_005ae2a0(Memory&, Cpu32&);
void fun_005b3530(Memory&, Cpu32&);
void fun_005b63e0(Memory&, Cpu32&);
void fun_005b6fa0(Memory&, Cpu32&);
void fun_0060ba20(Memory&, Cpu32&);
void fun_00614130(Memory&, Cpu32&);
void fun_006497b0(Memory&, Cpu32&);
void fun_006497c0(Memory&, Cpu32&);
void fun_00696170(Memory&, Cpu32&);
void fun_006a93e0(Memory&, Cpu32&);
void fun_006a93f0(Memory&, Cpu32&);
void fun_006a9400(Memory&, Cpu32&);
void fun_006c69e0(Memory&, Cpu32&);
void fun_006e0420(Memory&, Cpu32&);
void fun_006e0430(Memory&, Cpu32&);
void fun_006e2e20(Memory&, Cpu32&);
void fun_0071c840(Memory&, Cpu32&);
void fun_0071c850(Memory&, Cpu32&);
void fun_0071c860(Memory&, Cpu32&);
void fun_0071d230(Memory&, Cpu32&);
void fun_00724ed0(Memory&, Cpu32&);
void fun_00727600(Memory&, Cpu32&);
void fun_00730ba0(Memory&, Cpu32&);
void fun_007359a0(Memory&, Cpu32&);
void fun_0076d4a6(Memory&, Cpu32&);
void fun_0076d4ac(Memory&, Cpu32&);
void fun_0076d4b2(Memory&, Cpu32&);
void fun_0076d4b8(Memory&, Cpu32&);
void fun_0076d4be(Memory&, Cpu32&);
void fun_0076d4c4(Memory&, Cpu32&);
void fun_0076d4ca(Memory&, Cpu32&);
void fun_0076d4d0(Memory&, Cpu32&);
void fun_0076d4d6(Memory&, Cpu32&);
void fun_0076d4dc(Memory&, Cpu32&);
void fun_0076d4e2(Memory&, Cpu32&);
void fun_0076d4e8(Memory&, Cpu32&);
void fun_0076d4ee(Memory&, Cpu32&);
void fun_0076d4f4(Memory&, Cpu32&);
void fun_0076d4fa(Memory&, Cpu32&);
void fun_0076d500(Memory&, Cpu32&);
void fun_0076d506(Memory&, Cpu32&);
void fun_0076d50c(Memory&, Cpu32&);
void fun_0076d512(Memory&, Cpu32&);
void fun_0076d518(Memory&, Cpu32&);
void fun_0076d51e(Memory&, Cpu32&);
void fun_0076d524(Memory&, Cpu32&);
void fun_0076d52a(Memory&, Cpu32&);
void fun_0076d530(Memory&, Cpu32&);
void fun_0076d560(Memory&, Cpu32&);
void fun_0076d566(Memory&, Cpu32&);
void fun_0076d572(Memory&, Cpu32&);
void fun_0076f4ef(Memory&, Cpu32&);
void fun_0076f540(Memory&, Cpu32&);
void fun_0076f76f(Memory&, Cpu32&);
void fun_00772ef0(Memory&, Cpu32&);
void fun_00779010(Memory&, Cpu32&);
void fun_007795f7(Memory&, Cpu32&);
void fun_007819ca(Memory&, Cpu32&);

const std::array<Entry, 77>& entries();
}
