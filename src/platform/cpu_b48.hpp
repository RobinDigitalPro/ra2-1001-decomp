#pragma once
#include <cstdint>
#include <stdexcept>
namespace ra2::platform::cpu_b48 {
struct Registers {std::uint32_t ax,bx,cx,dx;};
// The deterministic recovered caller receives this platform boundary explicitly.
// Native and injected observations are distinct test domains.
struct Operations {
    Registers(*cpuid)(std::uint32_t leaf,std::uint32_t subleaf,void* context){};
    std::uint64_t(*rdtsc)(void* context){};
    void* context{};
};
#if defined(__i386__) || defined(__x86_64__)
inline Registers native_cpuid(std::uint32_t leaf,std::uint32_t subleaf,void*){
    Registers out{};
    __asm__ volatile("cpuid":"=a"(out.ax),"=b"(out.bx),"=c"(out.cx),"=d"(out.dx):"0"(leaf),"2"(subleaf):"memory");
    return out;
}
inline std::uint64_t native_rdtsc(void*){
    std::uint32_t low,high;
    // Preserve the original unsynchronised instruction; no LFENCE/RDTSCP is inserted.
    __asm__ volatile("rdtsc":"=a"(low),"=d"(high)::"memory");
    return std::uint64_t(low)|(std::uint64_t(high)<<32);
}
#endif
}
