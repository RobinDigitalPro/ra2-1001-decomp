#include "recovery_b362.hpp"
#include "recovery_b359.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::recovery_b362 {
std::uint32_t fun_00497e30(Memory&m,const Inputs&i) {
    if(i.arg[6]!=0xffffffffu)throw std::domain_error("97e30 direct branch requires arg6 sentinel");
    // Original local result occupies eight private stack bytes. The child
    // receives copied argument words: its metric writes stay in that frame.
    std::array<std::uint8_t,8> bytes{};
    constexpr std::uint32_t result=0x7d000000u;
    leaf::Memory local(bytes.data(),result,8u);
    Memory child_memory=m;child_memory.add(local);
    Inputs child=i;child.cx=result;child.arg[6]=i.arg[7];
    const auto p=recovery_b359::fun_00497610(child_memory,child);
    if(p!=result)throw std::runtime_error("97e30 child output pointer differs");
    m.w32(i.cx,local.r32(result));m.w32(i.cx+4u,local.r32(result+4u));
    return i.cx;
}
}
