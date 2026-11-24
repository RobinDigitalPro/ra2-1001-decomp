#pragma once
#include "recovered/leaf_memory.hpp"
#include <array>
#include <cstdint>

namespace ra2::recovered::indirect_b25 {
// `target` is the raw guest32 address read from the original indirect slot.
// Observer behavior is controlled and does not recover the target routine.
struct Operations {
    std::uint32_t (*invoke)(std::uint32_t target, std::uint32_t raw_ecx,
        std::uint32_t arg0, std::uint32_t arg1, void* context);
    void* context;
};
using Function = std::uint32_t (*)(leaf::Memory&, const leaf::Inputs&, const Operations&);
struct Entry { std::uint32_t rva, size, kind, vtable_offset; Function function; };
const std::array<Entry, 41>& entries();
std::uint32_t fun_004137b0(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0042b0f0(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0046cf00(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_004cddf0(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_004fa0f0(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_004fa4c0(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_004fa890(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0050a9e0(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0051d8a0(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_00568820(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0058bdf0(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_005c5f10(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_00604c30(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_00612ee0(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_00613220(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_00613520(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0064a4f0(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0064a8e0(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0064abf0(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0064f100(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0065a4f0(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0065f4a0(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0068dd10(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_006d4f00(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_006ed7e0(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_007192f0(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_004354b0(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_00453ae0(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_00453b20(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_004a4a20(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_004bf830(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_004cdb60(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_00508cb0(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_00632430(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0064f0e0(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0064f0f0(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_00652330(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_00652340(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0068dad0(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_00752010(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_00752020(leaf::Memory&, const leaf::Inputs&, const Operations&);
} // namespace ra2::recovered::indirect_b25
