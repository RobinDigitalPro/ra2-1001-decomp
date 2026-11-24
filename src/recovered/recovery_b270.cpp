#include "recovered/recovery_b270.hpp"
#include "recovered/recovery_b153.hpp"

namespace ra2::recovered::recovery_b270 {
// Original RVA 0x66ec0, 152 indexed bytes. The arithmetic, key and formatter
// arguments match 0x65850. At 0x466f35 the debug line is 0x2b0 instead of 0x64.
// The actual 0x2eeb60 hit path returns at 0x6eebbf without reading that slot;
// its miss/error paths do use it and are explicitly outside this contract.
// Reuse is restricted to Block153's supplied sorted two-row table, original
// UTF-16 "%d", nonnegative input, mode-zero locale and nonnull destination.
// No claim is made about real gameplay localization-table initialization.
std::uint32_t fun_00466ec0(Memory& memory, const Inputs& inputs) {
    return recovery_b153::fun_00465850(memory, inputs);
}
}
