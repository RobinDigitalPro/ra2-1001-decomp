#pragma once

#include <cstdint>

namespace ra2::recovered {

// Original GAME.EXE RVA 0x10a0. The object must expose bytes through offset 0x50.
std::uint32_t fun_004010a0(const void* object) noexcept;

} // namespace ra2::recovered
