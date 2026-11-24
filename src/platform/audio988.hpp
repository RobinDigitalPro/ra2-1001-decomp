#pragma once
#include <array>
#include <cstdint>
namespace ra2::platform::audio988 {
using Format=std::array<std::uint8_t,18>;
struct Boundary{virtual ~Boundary()=default;virtual std::uint32_t stop(std::uint32_t)=0;virtual std::uint32_t set_format(std::uint32_t,const Format&)=0;virtual std::uint32_t play(std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t)=0;};
}
