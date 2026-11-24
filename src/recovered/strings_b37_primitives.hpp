#pragma once
#include "recovered/direct_b33_integer.hpp"
#include "recovered/strings_b37_memory.hpp"
#include <cstdint>
#include <stdexcept>

// Exact string instruction primitives. They do not establish an original
// class, ABI or helper implementation; per-caller native proof remains required.
namespace ra2::recovered::strings_b37::string_detail {
namespace integer=ra2::recovered::direct_b33::integer;
enum class Kind {move,store,compare,scan};
enum class Repeat {single,count,equal,not_equal};
inline constexpr std::uint32_t DF=0x400;

template<class Memory,class State>
void string_instruction(Memory& memory,State& s,std::uint32_t& flags,
                        Kind kind,unsigned width,Repeat repeat) {
    if(width!=8&&width!=16&&width!=32)throw std::invalid_argument("string width");
    const bool comparing=kind==Kind::compare||kind==Kind::scan;
    if((comparing&&repeat==Repeat::count)||(!comparing&&(repeat==Repeat::equal||repeat==Repeat::not_equal)))
        throw std::invalid_argument("string repeat form");
    const auto bytes=width/8;
    const std::uint32_t step=(flags&DF)?0u-bytes:bytes;
    // A single instruction ignores CX; a zero repeated count touches nothing.
    if(repeat!=Repeat::single&&!s.cx)return;
    for(;;) {
        if(kind==Kind::move) {
            const auto value=memory.read(s.si,width);
            memory.write(s.di,value,width);s.si+=step;s.di+=step;
        } else if(kind==Kind::store) {
            memory.write(s.di,s.ax,width);s.di+=step;
        } else if(kind==Kind::compare) {
            const auto source=memory.read(s.si,width),destination=memory.read(s.di,width);
            (void)integer::sub(source,destination,width,flags);s.si+=step;s.di+=step;
        } else {
            const auto destination=memory.read(s.di,width);
            (void)integer::sub(s.ax,destination,width,flags);s.di+=step;
        }
        if(repeat==Repeat::single)return;
        --s.cx;
        if(!s.cx||(repeat==Repeat::equal&&!(flags&integer::ZF))||
                  (repeat==Repeat::not_equal&&(flags&integer::ZF)))return;
    }
}
} // namespace ra2::recovered::strings_b37::string_detail

namespace ra2::recovered::strings_b37 {
using string_detail::Kind;using string_detail::Repeat;
struct StringMemoryView {
    Memory& memory;
    std::uint32_t read(std::uint32_t address,unsigned width) {
        return width==8?memory.r8(address):width==16?memory.r16(address):memory.r32(address);
    }
    void write(std::uint32_t address,std::uint32_t value,unsigned width) {
        if(width==8)memory.w8(address,std::uint8_t(value));
        else if(width==16)memory.w16(address,std::uint16_t(value));
        else memory.w32(address,value);
    }
};
inline void string_instruction(Memory& memory,State& state,std::uint32_t& flags,
                               Kind kind,unsigned width,Repeat repeat) {
    StringMemoryView view{memory};
    string_detail::string_instruction(view,state,flags,kind,width,repeat);
}
} // namespace ra2::recovered::strings_b37
