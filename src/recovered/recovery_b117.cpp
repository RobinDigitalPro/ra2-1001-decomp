#include "recovery_b117.hpp"

#include <limits>
#include <stdexcept>

namespace ra2::recovered::recovery_b117 {
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

// RVA 0x35b110 / VA 0x75b110. ECX is the output char**; EDX points to a
// holder for the first string, and [ESP+4] points to a holder for the second.
// Use two 1017-character borrowed strings to force all three allocations onto
// the unchanged ordinary-heap route (1018, 2035, 2035 bytes).
std::uint32_t fun_0075b110(Memory& m, const Inputs& i, Heap& heap) {
    const auto output_slot=i.cx;
    const auto current_holder=i.dx;
    const auto candidate_holder=i.arg[0];
    require(output_slot && current_holder && candidate_holder,
            "0x35b110 requires output slot and two string holders");
    require(output_slot!=current_holder && output_slot!=candidate_holder &&
            current_holder!=candidate_holder,
            "0x35b110 fixture cells must be disjoint");
    const auto current=m.r32(current_holder);
    const auto candidate=m.r32(candidate_holder);
    require(current && candidate && current!=candidate,
            "0x35b110 requires distinct nonnull borrowed strings");
    bounded_byte_string_length(m,current,1017u);
    bounded_byte_string_length(m,candidate,1017u);

    constexpr std::uint32_t current_request=1018u;
    const auto current_copy=heap.allocate(current_request);
    if (!current_copy) throw std::domain_error("0x35b110 requires current-copy allocation");
    copy_byte_string(m,heap,current_copy,current,1017u);

    i.arg[0]=candidate; // original [ESP+0x18] afterfivepushes iscallerarg0
    constexpr std::uint32_t joined_request=2035u;
    const auto joined=heap.allocate(joined_request);
    if (!joined) throw std::domain_error("0x35b110 requires joined-string allocation");
    // Copy current including its NUL; the candidate copy starts at that NUL,
    // replacing it, and includes its own terminating NUL.
    copy_heap_byte_string(heap,joined,current_copy,1017u);
    copy_byte_string(m,heap,joined+1017u,candidate,1017u);
    (void)heap.release(current_copy);

    m.w32(output_slot,0u);
    const auto final=heap.allocate(joined_request);
    if (!final) throw std::domain_error("0x35b110 requires final-string allocation");
    m.w32(output_slot,final);
    copy_heap_byte_string(heap,final,joined,joined_request-1u);
    (void)heap.release(joined);
    return output_slot; // full EAX=output slot; RET 4
}

// RVA 0x35b810 / VA 0x75b810. ECX points to a receiver whose current UTF-16
// pointer is null. [ESP+4] is an output wchar_t** and [ESP+8] is a bounded
// 508-unit candidate. Original helpers 36ef45/36ef9f/36efc9 are represented
// by their exact finite string effects; heap allocations/frees use real Heap.
std::uint32_t fun_0075b810(Memory& m, const Inputs& i, Heap& heap) {
    const auto receiver=i.cx;
    const auto output_slot=i.arg[0];
    const auto candidate=i.arg[1];
    require(receiver && output_slot && candidate,
            "0x35b810 requires receiver, output slot, and candidate pointer");
    require(m.r32(receiver)==0,
            "0x35b810 finite case requires a null current receiver string");
    bounded_wide_string_length(m,candidate,508u);

    constexpr std::uint32_t units_with_nul=509u;
    constexpr std::uint32_t temporary_request=4u*units_with_nul; // 2036 > 1016
    constexpr std::uint32_t final_request=2u*units_with_nul;     // 1018 > 1016
    const auto temporary=heap.allocate(temporary_request);
    if (!temporary) throw std::domain_error("0x35b810 requires successful temporary allocation");

    // ESI has no prior copy when receiver[0]==0. Original writes one UTF-16
    // NUL, then helper 36ef9f appends source including its terminator.
    write_heap_word(heap,temporary,0u);
    const auto empty_length=bounded_heap_wide_length(heap,temporary,0u);
    require(empty_length==0u,"0x35b810 temporary did not start empty");
    for (std::uint32_t n=0; n<=508u; ++n)
        write_heap_word(heap,temporary+2u*n,m.r16(candidate+2u*n));

    m.w32(output_slot,0u); // original clears the output before final allocation
    const auto joined_length=bounded_heap_wide_length(heap,temporary,508u);
    const auto final=heap.allocate(2u*(joined_length+1u));
    if (!final) throw std::domain_error("0x35b810 requires successful final allocation");
    m.w32(output_slot,final); // original publishes before helper 36efc9 copies
    for (std::uint32_t n=0; n<=508u; ++n)
        write_heap_word(heap,final+2u*n,
                        heap.r8(temporary+2u*n)|(heap.r8(temporary+2u*n+1u)<<8));
    (void)heap.release(temporary); // actual BOOL ignored by original root
    return output_slot; // full EAX=output-slot address; RET 8
}

// RVA 0x35b8e0 / VA 0x75b8e0. This is the same null-current UTF-16 route as
// 0x35b810, except [ESP+8] is a pointer to the candidate pointer cell.
std::uint32_t fun_0075b8e0(Memory& m, const Inputs& i, Heap& heap) {
    const auto receiver=i.cx;
    const auto output_slot=i.arg[0];
    const auto candidate_holder=i.arg[1];
    require(receiver && output_slot && candidate_holder,
            "0x35b8e0 requires receiver, output slot, and candidate holder");
    require(receiver!=output_slot && receiver!=candidate_holder &&
            output_slot!=candidate_holder,
            "0x35b8e0 fixture cells must be disjoint");
    require(m.r32(receiver)==0,
            "0x35b8e0 finite case requires null current receiver string");
    const auto candidate=m.r32(candidate_holder);
    require(candidate!=0,
            "0x35b8e0 candidate must be nonnull to avoid default global literal");
    bounded_wide_string_length(m,candidate,508u);

    constexpr std::uint32_t units_with_nul=509u;
    constexpr std::uint32_t temporary_request=4u*units_with_nul;
    constexpr std::uint32_t final_request=2u*units_with_nul;
    const auto temporary=heap.allocate(temporary_request);
    if (!temporary) throw std::domain_error("0x35b8e0 requires temporary allocation");
    write_heap_word(heap,temporary,0u);
    for (std::uint32_t n=0; n<units_with_nul; ++n)
        write_heap_word(heap,temporary+2u*n,m.r16(candidate+2u*n));

    m.w32(output_slot,0u);
    const auto final=heap.allocate(final_request);
    if (!final) throw std::domain_error("0x35b8e0 requires final allocation");
    m.w32(output_slot,final);
    for (std::uint32_t n=0; n<units_with_nul; ++n)
        write_heap_word(heap,final+2u*n,
                        heap.r8(temporary+2u*n)|(heap.r8(temporary+2u*n+1u)<<8));
    (void)heap.release(temporary);
    return output_slot; // full EAX=output slot; RET 8
}

}
