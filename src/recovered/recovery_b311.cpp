#include "recovery_b311.hpp"
#include "recovered/allocation_wrappers.hpp"
#include "recovered/leaf_b16_a.hpp"
#include "recovery_b311_composed.hpp"
#include "recovered/text_bytes.hpp"
#include <array>
#include <cstdint>
#include <stdexcept>
#include <vector>

namespace ra2::recovered::recovery_b311 {
namespace {
std::uint32_t allocate_cb(std::uint32_t bytes,std::uint32_t flag,void* context) {
    if(flag!=1u) throw std::domain_error("0x36d957 literal allocation flag changed");
    return static_cast<Heap*>(context)->allocate(bytes);
}
std::uint32_t release_cb(std::uint32_t pointer,void* context) {
    return static_cast<Heap*>(context)->release(pointer);
}
std::uint32_t allocate(std::uint32_t bytes,const ra2::recovered::AllocationWrapperOperations& ops) {
    return ra2::recovered::fun_0076d957(bytes,ops);
}
void release(std::uint32_t pointer,const ra2::recovered::AllocationWrapperOperations& ops) {
    (void)ra2::recovered::fun_0076d67b(pointer,ops);
}

// The accepted leaf converter uses one bounded span. Run it on an exact local
// image of its source and requested destination span, then copy that span
// back. Rounded bytes beyond the request remain the real allocator payload.
void convert_into_live_block(Memory& m,std::uint32_t source,std::uint32_t destination,
                             std::uint32_t units,std::uint32_t bytes,Heap& heap) {
    constexpr std::uint32_t base=0x10000000u,source_off=0x100u,dest_off=0x1000u;
    std::array<std::uint8_t,0x2000> scratch{};
    for(std::uint32_t n=0;n<1164u;++n)scratch[source_off+n]=static_cast<std::uint8_t>(m.r8(source+n));
    for(std::uint32_t n=0;n<bytes;++n)scratch[dest_off+n]=static_cast<std::uint8_t>(heap.r8(destination+n));
    ra2::recovered::leaf::Memory span(scratch.data(),base,static_cast<std::uint32_t>(scratch.size()));
    ra2::recovered::leaf::Inputs in{};in.cx=base+source_off;in.dx=base+dest_off;in.arg[0]=units;
    const auto converted=ra2::recovered::recovery_b311_helpers::fun_00430df0(span,in);
    if(converted!=units)throw std::domain_error("draft311 converter did not consume all 509 units");
    for(std::uint32_t n=0;n<bytes;++n)heap.w8(destination+n,scratch[dest_off+n]);
}

// Invoke the accepted NUL-terminated word copy on a local two-span image. The
// requested destination span is copied back; rounded bytes after the request
// and bytes after the NUL terminator retain their allocator-seeded values.
void copy_words_into_live_block(std::uint32_t destination,std::uint32_t source,
                                std::uint32_t bytes,Heap& heap) {
    constexpr std::uint32_t base=0x10000000u,source_off=0x100u,dest_off=0x1000u;
    std::array<std::uint8_t,0x2000> scratch{};
    for(std::uint32_t n=0;n<bytes;++n){
        scratch[source_off+n]=static_cast<std::uint8_t>(heap.r8(source+n));
        scratch[dest_off+n]=static_cast<std::uint8_t>(heap.r8(destination+n));
    }
    ra2::recovered::leaf::Memory span(scratch.data(),base,static_cast<std::uint32_t>(scratch.size()));
    ra2::recovered::leaf::Inputs in{};in.arg[0]=base+dest_off;in.arg[1]=base+source_off;
    (void)ra2::recovered::recovery_b311_helpers::fun_0076efc9(span,in);
    for(std::uint32_t n=0;n<bytes;++n)heap.w8(destination+n,scratch[dest_off+n]);
}
}

std::uint32_t rva_0035d010(Memory& m,const Inputs& in,Heap& heap) {
    const std::uint32_t receiver=in.cx,object=in.dx;
    const std::uint32_t source=m.r32(object);
    if(!source)throw std::domain_error("draft311 covers only nonnull 1163-byte source route");
    std::uint32_t length=0;
    while(m.r8(source+length)!=0u){
        if(length>=1163u)throw std::domain_error("draft311 source exceeds its exact positive route");
        ++length;
    }
    if(length!=1163u)throw std::domain_error("draft311 requires source length 1163");
    for(std::uint32_t n=0;n<length;++n)
        if((m.r8(source+n)&0x7fu)!=0x7fu)throw std::domain_error("draft311 source encoding leaves the accepted positive route");

    // Original 0x75d02c..0x75d03f count/size arithmetic for the finite input.
    const std::uint32_t scanned=length+1u;
    const std::uint32_t units=((((scanned*8u-scanned)>>3u)+1u)>>1u);
    if(units!=509u)throw std::domain_error("draft311 original unit bound mismatch");
    const std::uint32_t first_bytes=units*2u+2u;
    const ra2::recovered::AllocationWrapperOperations ops{allocate_cb,release_cb,&heap};

    const std::uint32_t first=allocate(first_bytes,ops);
    convert_into_live_block(m,source,first,units,first_bytes,heap);
    const auto first_length=ra2::recovered::recovery_b311_helpers::fun_0076ef45(
        reinterpret_cast<const std::uint16_t*>(std::uintptr_t(first)));
    if(first_length!=508u)throw std::domain_error("draft311 accepted converter output length mismatch");

    const std::uint32_t second_bytes=(first_length+1u)*2u;
    const std::uint32_t second=allocate(second_bytes,ops);
    heap.w8(second,0u);heap.w8(second+1u,0u);
    copy_words_into_live_block(second,first,second_bytes,heap);
    release(first,ops);
    m.w32(receiver,0u); // Original VA 0x75d0a4 clears the slot before sizing final output.

    const auto second_length=ra2::recovered::recovery_b311_helpers::fun_0076ef45(
        reinterpret_cast<const std::uint16_t*>(std::uintptr_t(second)));
    if(second_length!=508u)throw std::domain_error("draft311 intermediate output length mismatch");
    const std::uint32_t final_bytes=second_length*2u+2u;
    const std::uint32_t final=allocate(final_bytes,ops);
    m.w32(receiver,final);
    copy_words_into_live_block(final,second,final_bytes,heap);
    release(second,ops);
    return receiver;
}
}
