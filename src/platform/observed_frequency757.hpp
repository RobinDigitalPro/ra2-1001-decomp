#pragma once
#define NOMINMAX
#include <windows.h>
#include <cstdint>
#include <stdexcept>
#include <vector>
namespace ra2::platform::frequency757 {
inline std::vector<std::uint64_t> observations;
inline BOOL WINAPI query(LARGE_INTEGER* output){
    if(!output)throw std::runtime_error("757 missing frequency destination");
    const BOOL result=QueryPerformanceFrequency(output);
    if(!result||output->QuadPart<=0)throw std::runtime_error("757 requires successful positive host frequency");
    observations.push_back(std::uint64_t(output->QuadPart));
    return result;
}
inline std::uint32_t address(){return std::uint32_t(reinterpret_cast<std::uintptr_t>(&query));}
}
