#pragma once
#include "platform/small_crt_heap_algorithm.hpp"
#include <cstdint>

namespace ra2::platform::small_crt_heap1279 {
using X86Memory = ra2::platform::small_crt_heap::X86Memory;
using RealWin32Api = ra2::platform::small_crt_heap::RealWin32Api;
std::uint32_t create_region(X86Memory&, RealWin32Api&);
std::uint32_t commit_first_chunk(X86Memory&, RealWin32Api&, std::uint32_t record);
std::uint32_t allocate_first_zero(X86Memory&, RealWin32Api&, std::uint32_t request, std::uint32_t entry_esp);
std::uint32_t allocate_second_zero(X86Memory&, std::uint32_t request, std::uint32_t entry_esp);
void release_first_zero(X86Memory&, std::uint32_t user);
void release_second_zero(X86Memory&, std::uint32_t user);
}
