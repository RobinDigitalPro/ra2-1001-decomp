#pragma once
#include <array>
#include <cstdint>
namespace ra2::platform::locale991 {
using Buffer=std::array<std::uint8_t,120>;
struct Boundary{virtual ~Boundary()=default;virtual int get(std::uint32_t,std::uint32_t,char*,int)=0;};
}
