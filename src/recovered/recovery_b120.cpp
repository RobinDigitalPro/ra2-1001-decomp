#include "recovery_b120.hpp"

#include <limits>
#include <stdexcept>

namespace ra2::recovered::recovery_b120 {
namespace {
void require(bool condition, const char* message) {
    if (!condition) throw std::domain_error(message);
}

std::uint32_t bounded_byte_string_length(Memory& m, std::uint32_t source,
                                         std::uint32_t expected_length) {
    require(source != 0, "bounded byte string must be nonnull");
    for (std::uint32_t n=0; n<=expected_length; ++n) {
        const auto b=m.r8(source+n);
        if (n==expected_length) {
            require(b==0, "byte string terminator is not at the contracted bound");
            return expected_length;
        }
        require(b!=0, "byte string has an early terminator");
    }
    throw std::domain_error("unreachable byte-string scan state");
}

std::uint32_t bounded_wide_string_length(Memory& m, std::uint32_t source,
                                         std::uint32_t expected_units) {
    require(source != 0 && (source&1u)==0, "bounded UTF-16 source must be nonnull and word-aligned");
    for (std::uint32_t n=0; n<=expected_units; ++n) {
        const auto ch=m.r16(source+2u*n);
        if (n==expected_units) {
            require(ch==0, "UTF-16 terminator is not at the contracted bound");
            return expected_units;
        }
        require(ch!=0, "UTF-16 source has an early terminator");
    }
    throw std::domain_error("unreachable UTF-16 scan state");
}

std::uint32_t bounded_heap_wide_length(Heap& h, std::uint32_t source,
                                       std::uint32_t expected_units) {
    require(source != 0 && (source&1u)==0, "heap UTF-16 source must be nonnull and word-aligned");
    for (std::uint32_t n=0; n<=expected_units; ++n) {
        const auto ch=h.r8(source+2u*n)|(h.r8(source+2u*n+1u)<<8);
        if (n==expected_units) {
            require(ch==0, "heap UTF-16 terminator is not at the contracted bound");
            return expected_units;
        }
        require(ch!=0, "heap UTF-16 source has an early terminator");
    }
    throw std::domain_error("unreachable heap UTF-16 scan state");
}

void write_heap_word(Heap& h, std::uint32_t address, std::uint32_t value) {
    h.w8(address, value&0xffu);
    h.w8(address+1u, (value>>8)&0xffu);
}

void copy_byte_string(Memory& m, Heap& h, std::uint32_t destination,
                      std::uint32_t source, std::uint32_t characters) {
    for (std::uint32_t n=0; n<=characters; ++n)
        h.w8(destination+n,m.r8(source+n));
}

void copy_heap_byte_string(Heap& h, std::uint32_t destination,
                           std::uint32_t source, std::uint32_t characters) {
    for (std::uint32_t n=0; n<=characters; ++n)
        h.w8(destination+n,h.r8(source+n));
}
} // namespace

// RVA 0x1f8100 / VA 0x5f8100. A one-source-node positive case with a null
// receiver list: [ESP+4] is source node {next,+4,+8=uint16_t*,+0xc}. The
// allocation is one 16-byte node header plus 501 inline UTF-16 units.
std::uint32_t fun_005f8100(Memory& m, const Inputs& i, Heap& heap) {
    const auto receiver=i.cx;
    const auto source=i.arg[0];
    require(receiver && source,"0x1f8100 requires receiver and one source node");
    require(m.r32(receiver+0x34u)==0,
            "0x1f8100 finite case requires receiver list initially empty");
    require(m.r32(source)==0,
            "0x1f8100 finite case requires exactly one source node");
    const auto source_text=m.r32(source+8u);
    bounded_wide_string_length(m,source_text,500u);

    constexpr std::uint32_t request=2u*501u+0x10u; // 1018 = header 16 + text incl NUL
    const auto node=heap.allocate(request);
    if (!node) throw std::domain_error("0x1f8100 requires successful node allocation");
    const auto inline_text=node+0x10u;
    heap.w32(node+8u,inline_text);
    heap.w32(node,m.r32(receiver+0x34u)); // old head (known null) as new next
    heap.w32(node+4u,0u);                 // original initial value, then source field
    m.w32(receiver+0x34u,node);
    heap.w32(node+0x0cu,m.r32(source+0x0cu));
    heap.w32(node+4u,m.r32(source+4u));
    for (std::uint32_t n=0; n<=500u; ++n)
        write_heap_word(heap,inline_text+2u*n,m.r16(source_text+2u*n));
    return inline_text; // helper 36efc9 leaves EAX=destination; RET 4
}

} // namespace ra2::recovered::recovery_b120
