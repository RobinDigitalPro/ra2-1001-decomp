#include "recovery_b118.hpp"

#include <stdexcept>

namespace ra2::recovered::recovery_b118 {
namespace {
void require(bool condition, const char* message) {
    if (!condition) throw std::domain_error(message);
}

std::uint32_t bounded_memory_wide_length(Memory& m, std::uint32_t source,
                                        std::uint32_t expected) {
    require(source != 0 && (source&1u)==0, "UTF-16 source must be aligned");
    for (std::uint32_t n=0; n<=expected; ++n) {
        const auto ch=m.r16(source+2u*n);
        if (n==expected) {
            require(ch==0, "UTF-16 terminator outside contracted bound");
            return expected;
        }
        require(ch!=0, "UTF-16 source has an early terminator");
    }
    throw std::domain_error("unreachable UTF-16 scan state");
}

std::uint32_t bounded_memory_byte_length(Memory& m, std::uint32_t source,
                                         std::uint32_t expected) {
    require(source != 0, "borrowed byte string must be nonnull");
    for (std::uint32_t n=0; n<=expected; ++n) {
        const auto ch=m.r8(source+n);
        if (n==expected) {
            require(ch==0, "borrowed byte terminator outside contracted bound");
            return expected;
        }
        require(ch!=0, "borrowed byte string has an early terminator");
    }
    throw std::domain_error("unreachable borrowed byte-string scan state");
}

void write_heap_word(Heap& h, std::uint32_t at, std::uint32_t value) {
    h.w8(at,value&0xffu);
    h.w8(at+1u,(value>>8)&0xffu);
}

} // namespace

// RVA 0x35a7b0 / VA 0x75a7b0. Receiver[0] points to a borrowed guest byte
// string with 1017 uppercase ASCII bytes plus NUL. arg0 points at output
// char**. The original initial-state locale pointer at [0xb10530] is zero,
// selecting the helper's in-body ASCII fast path, so 'A' becomes 'a'.
std::uint32_t fun_0075a7b0(Memory& m, const Inputs& i, Heap& heap) {
    const auto receiver=i.cx;
    const auto output_slot=i.arg[0];
    require(receiver && output_slot && receiver!=output_slot,
            "0x35a7b0 requires disjoint receiver and output cell");
    const auto old=m.r32(receiver);
    require(old!=0,"0x35a7b0 finite route requires a borrowed old string");
    bounded_memory_byte_length(m,old,1017u);
    require(m.r32(0x00b10530u)==0,
            "0x35a7b0 case route requires initial locale pointer [0xb10530]=0");
    for (std::uint32_t n=0; n<1017u; ++n)
        require(m.r8(old+n)>='A'&&m.r8(old+n)<='Z',"0x35a7b0 finite conversion case requires ASCII A..Z");

    constexpr std::uint32_t request=1018u;
    const auto temporary=heap.allocate(request);
    if (!temporary) throw std::domain_error("0x35a7b0 requires a successful copy allocation");
    for (std::uint32_t n=0; n<request; ++n)
        heap.w8(temporary+n,m.r8(old+n));
    for (std::uint32_t n=0; n<1017u; ++n)
        heap.w8(temporary+n,heap.r8(temporary+n)+0x20u);

    m.w32(output_slot,0u);
    const auto result=heap.allocate(request);
    if (!result) throw std::domain_error("0x35a7b0 requires a successful result allocation");
    m.w32(output_slot,result);
    for (std::uint32_t n=0; n<request; ++n)
        heap.w8(result+n,heap.r8(temporary+n));
    (void)heap.release(temporary);
    return output_slot; // EAX=arg0 pointee address; RET 4
}

// RVA 0x35c460 / VA 0x75c460. Receiver[0] points to a borrowed guest UTF-16
// string with 508 lowercase ASCII units plus NUL. arg0 is output wchar_t**.
// Initial-state [0xb10530]==0 selects the helper's ASCII fast path ('a'->'A').
std::uint32_t fun_0075c460(Memory& m, const Inputs& i, Heap& heap) {
    const auto receiver=i.cx;
    const auto output_slot=i.arg[0];
    require(receiver && output_slot && receiver!=output_slot,
            "0x35c460 requires disjoint receiver and output cell");
    const auto old=m.r32(receiver);
    require(old!=0,"0x35c460 finite route requires a borrowed old string");
    bounded_memory_wide_length(m,old,508u);
    require(m.r32(0x00b10530u)==0,
            "0x35c460 case route requires initial locale pointer [0xb10530]=0");
    for (std::uint32_t n=0; n<508u; ++n)
        require(m.r16(old+2u*n)>='a'&&m.r16(old+2u*n)<='z',"0x35c460 finite conversion case requires UTF-16 a..z");

    constexpr std::uint32_t request=2u*(508u+1u); // 1018 > 1016
    const auto temporary=heap.allocate(request);
    if (!temporary) throw std::domain_error("0x35c460 requires a successful temporary allocation");
    for (std::uint32_t n=0; n<509u; ++n)
        write_heap_word(heap,temporary+2u*n,
                        m.r16(old+2u*n));
    for (std::uint32_t n=0; n<508u; ++n)
        write_heap_word(heap,temporary+2u*n,(heap.r8(temporary+2u*n)|(heap.r8(temporary+2u*n+1u)<<8))-0x20u);

    m.w32(output_slot,0u);
    const auto result=heap.allocate(request);
    if (!result) throw std::domain_error("0x35c460 requires a successful output allocation");
    m.w32(output_slot,result);
    for (std::uint32_t n=0; n<509u; ++n)
        write_heap_word(heap,result+2u*n,
                        heap.r8(temporary+2u*n)|(heap.r8(temporary+2u*n+1u)<<8));
    (void)heap.release(temporary);
    return output_slot; // EAX=arg0 pointee address; RET 4
}

// RVA 0x35cda0 / VA 0x75cda0. EDX points to receiver[0], ECX is output
// wchar_t**; arg0 points to a holder containing a separate 508-unit candidate.
// Both input strings are borrowed from guest memory. Joined temp request is
// intentionally larger than the written joined extent; its untouched tail
// retains the actual Heap adapter's fresh-byte seed.
std::uint32_t fun_0075cda0(Memory& m, const Inputs& i, Heap& heap) {
    const auto receiver=i.dx;
    const auto output_slot=i.cx;
    const auto candidate_holder=i.arg[0];
    require(receiver && output_slot && candidate_holder &&
            receiver!=output_slot && receiver!=candidate_holder &&
            output_slot!=candidate_holder,
            "0x35cda0 requires disjoint receiver, output cell and candidate holder");
    const auto old=m.r32(receiver);
    const auto candidate=m.r32(candidate_holder);
    require(old && candidate,"0x35cda0 requires nonnull old and candidate strings");
    require(old!=candidate,"0x35cda0 old and candidate strings must be distinct");
    bounded_memory_wide_length(m,old,508u);
    bounded_memory_wide_length(m,candidate,508u);

    constexpr std::uint32_t old_request=2u*(508u+1u); // helper-copy temp: 1018
    const auto current_copy=heap.allocate(old_request);
    if (!current_copy) throw std::domain_error("0x35cda0 requires current-copy allocation");
    for (std::uint32_t n=0; n<509u; ++n)
        write_heap_word(heap,current_copy+2u*n,
                        m.r16(old+2u*n));

    constexpr std::uint32_t combined_characters=508u+508u;
    constexpr std::uint32_t joined_request=4u*(508u+1u+508u); // 4068
    const auto joined=heap.allocate(joined_request);
    if (!joined) throw std::domain_error("0x35cda0 requires joined allocation");
    // Current occupies 509 units; append starts on its NUL and replaces it.
    for (std::uint32_t n=0; n<509u; ++n)
        write_heap_word(heap,joined+2u*n,
                        heap.r8(current_copy+2u*n)|(heap.r8(current_copy+2u*n+1u)<<8));
    for (std::uint32_t n=0; n<509u; ++n)
        write_heap_word(heap,joined+2u*(508u+n),m.r16(candidate+2u*n));
    (void)heap.release(current_copy);

    m.w32(output_slot,0u);
    constexpr std::uint32_t final_request=2u*(combined_characters+1u); // 2034
    const auto result=heap.allocate(final_request);
    if (!result) throw std::domain_error("0x35cda0 requires final allocation");
    m.w32(output_slot,result);
    for (std::uint32_t n=0; n<=combined_characters; ++n)
        write_heap_word(heap,result+2u*n,
                        heap.r8(joined+2u*n)|(heap.r8(joined+2u*n+1u)<<8));
    (void)heap.release(joined);
    return output_slot; // EAX=ECX/output-cell address; RET 4
}
} // namespace ra2::recovered::recovery_b118
