#define NOMINMAX
#include "recovered/recovery_b499.hpp"
#include "platform/observed_find499.hpp"
#include <windows.h>
#include <array>
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b499 {
namespace {
constexpr std::uint32_t active_handle=0x007bd76cu;
constexpr std::uint32_t max_pattern=260u;
constexpr std::uint32_t max_filename=260u;
}
std::uint32_t fun_0046feb0(Memory& m,const Inputs& i) {
    const std::uint32_t guest=i.cx;
    if(!guest) throw std::runtime_error("B499 null receiver is outside the bounded positive route");
    const std::uint32_t old=m.r32(active_handle);
    if(old!=0xffffffffu) {
        ra2::platform::find499::Observer::close(reinterpret_cast<HANDLE>(std::uintptr_t(old)));
        m.w32(active_handle,0xffffffffu);
    }
    std::array<char,max_pattern> query{};
    std::uint32_t n=0;
    for(;n<max_pattern;++n) {
        query[n]=static_cast<char>(m.r8(guest+n));
        if(!query[n]) break;
    }
    if(n==max_pattern) throw std::runtime_error("B499 bounded query lacks NUL");
    WIN32_FIND_DATAA data{};
    const HANDLE h=ra2::platform::find499::Observer::first(query.data(),&data);
    if(h==INVALID_HANDLE_VALUE) throw std::runtime_error("B499 positive contract requires a successful file search");
    if((data.dwFileAttributes&0x116u)!=0) {
        throw std::runtime_error("B499 bounded route requires attributes passing the original 0x116 test");
    }
    std::uint32_t k=0;
    for(;k<max_filename;++k) {
        m.w8(guest+k,static_cast<unsigned char>(data.cFileName[k]));
        if(!data.cFileName[k]) break;
    }
    if(k==max_filename) {
        ra2::platform::find499::Observer::close(h);
        throw std::runtime_error("B499 Win32 filename is not NUL terminated");
    }
    m.w32(active_handle,std::uint32_t(reinterpret_cast<std::uintptr_t>(h)));
    const std::uint32_t output_length=k+1u; // The original MOV EAX,ECX then MOV AL,1.
    return (output_length&0xffffff00u)|1u;
}
}
