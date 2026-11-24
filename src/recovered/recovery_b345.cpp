#include "recovery_b345.hpp"

#include "recovered/recovery_b323.hpp"
#include "recovered/floating_b61_memory.hpp"

#include <stdexcept>

namespace ra2::recovery_b345_20e950 {
namespace {
constexpr std::uint32_t kUiGlobal=0x00821b88u;
constexpr std::uint32_t kUiControlOffset=0x620u;
constexpr std::uint32_t kFloatOne=0x3f800000u;
}

std::uint32_t fun_0060e950(recovered::global_b26::Memory& m,EntryState& state,
                           platform::x87::State& fp) {
    // The selected original route reads the byte at entry ECX, falls through
    // all three special-key comparisons, and reaches the default 0x708970 call.
    const auto key=m.r8(state.ecx);
    if(key==0x09u||key==0x06u||key==0x07u)
        throw std::invalid_argument("B345/20e950 finite route excludes three localized special keys");

    // Root pushes arg1=0 then arg0=1.0f and sets EDX=0x2000. The called root
    // accepts ECX as a numeric type-registry index. Index 0 is a proven finite
    // B323 contract; no vtable or synthetic callback is used.
    const auto control=m.r32(kUiGlobal);
    if(control==0)throw std::invalid_argument("B345/20e950 requires mapped UI-control global");
    const auto index=m.r32(control+kUiControlOffset);
    recovered::global_b26::Inputs child_input{};
    child_input.cx=index;child_input.dx=0x2000u;
    child_input.arg[0]=kFloatOne;child_input.arg[1]=0;

    recovery_b323::EntryState child{};
    child.input=child_input;
    child.eax=(state.eax&0xffffff00u)|key;
    child.ecx=index;child.edx=0x2000u;
    child.ebx=state.ebx;child.ebp=state.ebp;child.esi=state.esi;child.edi=state.edi;
    child.caller_words[0]=kFloatOne;child.caller_words[1]=0;
    const auto eax=recovery_b323::fun_00708970(m,child,fp);
    state.eax=eax;state.ecx=child.ecx;state.edx=child.edx;
    state.ebx=child.ebx;state.ebp=child.ebp;state.esi=child.esi;state.edi=child.edi;
    return eax;
}
}
