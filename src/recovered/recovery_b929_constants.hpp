#pragma once
#include <array>
#include <cstdint>

namespace recovery_b929_cases {
inline constexpr std::uint32_t rva=0x295d30u,body_size=1074u,receiver_span=0x4f18u;
inline constexpr unsigned cases=512,assurance_cases=32,arena_size=0x100000u,receiver_offset=0x2000u;
inline constexpr std::uint32_t table_fallback=0x007e0084u,table_begin=0x007e0088u,table_end=0x007e00b4u,table_count=11u;
inline constexpr std::uint32_t clock_global=0x00a2896cu,published_child=0x00a5e1d8u;
inline constexpr std::array<std::uint32_t,11> lookup_literals{{
 0x007e00bcu,0x007e00b4u,0x007c60c4u,0x007c6104u,0x007b886cu,
 0x007c7c88u,0x007b8828u,0x007e00d8u,0x007e00d0u,0x007e00c8u,0x007c7d14u}};
inline constexpr std::array<std::uint32_t,11> output_globals{{
 0x00aa5f6cu,0x00aa5d9cu,0x00aa5418u,0x00aa5d80u,0x00aa5dc0u,
 0x00aa5e74u,0x00aa5dc4u,0x00aa5e78u,0x00aa5e80u,0x00aa5f70u,0x00aa5d98u}};
inline constexpr std::array<std::uint32_t,6> added_pages{{
 0x007b8000u,0x007c6000u,0x007c7000u,0x007e0000u,0x00a5e000u,
 0x00aa5000u}};
inline constexpr std::array<std::uint32_t,3> b319_runtime_pages{{0x00785000u,0x00817000u,0x00b10000u}};
// Four existing B319 writable input pages remain part of the composite input.
inline constexpr std::array<std::uint32_t,4> b319_pages{{0x0083a000u,0x00a28000u,0x00a9d000u,0x00aa1000u}};
inline constexpr std::array<std::uint32_t,4> readonly_literal_pages{{0x007b8000u,0x007c6000u,0x007c7000u,0x007e0000u}};
}
