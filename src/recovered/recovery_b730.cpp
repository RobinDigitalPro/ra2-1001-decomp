#include "recovered/recovery_b730.hpp"
#include <stdexcept>

namespace ra2::recovered::recovery_b730 {
std::uint32_t fun_006bfb00(Memory& m, const Inputs& i) {
  const std::uint32_t receiver = i.cx;
  const std::uint32_t vptr = m.r32(receiver);
  // The bounded contract uses the actual original Building callback chain:
  // slot +0x80 is 0x6b6910, whose tail jump through slot +0x84 is 0x4538b0.
  if (m.r32(vptr + 0x80u) != 0x006b6910u ||
      m.r32(vptr + 0x84u) != 0x004538b0u || i.arg[1] != 0u)
    throw std::out_of_range("B730 bounded null-secondary-argument route only");
  const std::uint32_t type = m.r32(receiver + 0x418u);
  const std::uint32_t type_vptr = m.r32(type);
  if (type_vptr != 0x007881f8u)
    throw std::out_of_range("B730 bounded constructor-proven BuildingType state only");
  const std::uint32_t descriptor_byte = m.r8(type + 0x3a0u);
  const std::uint32_t local_word = (i.stack_minus8 & 0xffff0000u) | (descriptor_byte << 8u);
  m.w32(i.arg[0], local_word);
  return i.arg[0];
}
}
