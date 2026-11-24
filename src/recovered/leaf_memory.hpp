#pragma once
#include <array>
#include <cstddef>
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::leaf {
// Explicit original-32 address space, independent of host pointer width. The
// functions expose observed entry inputs, not inferred original class/ABI names.
struct Inputs {
    std::uint32_t cx=0,dx=0;
    std::array<std::uint32_t,8> arg{}; // Original stack words after return address.
};
class Memory {
    std::uint8_t* bytes_;
    std::uint32_t base_,size_;
    std::uint32_t offset(std::uint32_t address,std::uint32_t width) const {
        if(address<base_ || width>size_ || address-base_>size_-width)
            throw std::out_of_range("leaf original32 address outside valid memory contract");
        return address-base_;
    }
public:
    Memory(std::uint8_t* bytes,std::uint32_t base,std::uint32_t size):bytes_(bytes),base_(base),size_(size) {}
    std::uint32_t base() const {return base_;}
    std::uint32_t size() const {return size_;}
    // Translate a checked guest span for an existing pointer-based recovery.
    // Native comparison uses the arena's real 32-bit address as its guest base.
    const void* host_view(std::uint32_t address,std::uint32_t width) const {
        return bytes_+offset(address,width);
    }
    std::uint32_t r8(std::uint32_t a) const {return bytes_[offset(a,1)];}
    std::uint32_t r16(std::uint32_t a) const {
        const auto o=offset(a,2);return std::uint32_t(bytes_[o])|(std::uint32_t(bytes_[o+1])<<8);
    }
    std::uint32_t r32(std::uint32_t a) const {
        const auto o=offset(a,4);return std::uint32_t(bytes_[o])|(std::uint32_t(bytes_[o+1])<<8)|
            (std::uint32_t(bytes_[o+2])<<16)|(std::uint32_t(bytes_[o+3])<<24);
    }
    void w8(std::uint32_t a,std::uint32_t v) {bytes_[offset(a,1)]=static_cast<std::uint8_t>(v);}
    void w16(std::uint32_t a,std::uint32_t v) {
        const auto o=offset(a,2);bytes_[o]=static_cast<std::uint8_t>(v);bytes_[o+1]=static_cast<std::uint8_t>(v>>8);
    }
    void w32(std::uint32_t a,std::uint32_t v) {
        const auto o=offset(a,4);for(unsigned n=0;n<4;++n)bytes_[o+n]=static_cast<std::uint8_t>(v>>(n*8));
    }
};
inline std::int32_t s32(std::uint32_t v) {
    return v<=0x7fffffffu?static_cast<std::int32_t>(v):-1-static_cast<std::int32_t>(0xffffffffu-v);
}
inline std::uint32_t sx16(std::uint32_t v) {v&=0xffffu;return (v&0x8000u)?v|0xffff0000u:v;}
inline std::uint32_t sx8(std::uint32_t v) {v&=0xffu;return (v&0x80u)?v|0xffffff00u:v;}
inline std::uint32_t sar(std::uint32_t v,unsigned n) {
    n&=31;if(!n)return v;return (v>>n)|((v&0x80000000u)?(~std::uint32_t{0}<<(32-n)):0);
}
using Function=std::uint32_t(*)(Memory&,const Inputs&);
}
