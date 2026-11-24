#include "small_heap_b336_adapter.hpp"
#include "platform/small_crt_heap_empty173.hpp"

#include <stdexcept>

namespace ra2::platform::small_crt_heap::b336 {
namespace {
void need(bool ok,const char* why) {
    if (!ok) throw std::domain_error(why);
}
std::uint32_t class_for_span(std::uint32_t span) {
    need(span >= 0x10u && (span & 0x0fu) == 0u,"invalid CRT span");
    const auto cls=(span>>4u)-1u;
    return cls>63u?63u:cls;
}
}

std::uint32_t allocate_eight_from_tracked_empty_chunk(
    X86Memory& m,std::uint32_t request,std::uint32_t entry_esp) {
    constexpr std::uint32_t tracker_record=0x00b10e10u;
    constexpr std::uint32_t tracker_chunk=0x00b10e08u;
    constexpr std::uint32_t region_table=0x00b10e18u;
    constexpr std::uint32_t region_count=0x00b10e14u;
    constexpr std::uint32_t cursor=0x00b10e0cu;
    constexpr std::uint32_t expected_span=0x10u;
    need(request==8u && ((request+0x17u)&0xfffffff0u)==expected_span,
         "B336 second temporary must be request 8 / span 0x10");
    const auto record=m.r32(region_table);
    need(record!=0 && m.r32(region_count)==1u && m.r32(cursor)==record,
         "B336 requires its sole current first region");
    const auto arena=m.r32(record+0x0cu),metadata=m.r32(record+0x10u);
    need(arena!=0 && metadata!=0 && m.r32(record)==0u &&
         m.r32(record+4u)==1u && m.r32(record+8u)==0x7fffffffu,
         "B336 region must retain the initial chunk-zero availability");
    need(m.r32(metadata)==0u && m.r32(metadata+0x44u)==0u &&
         m.r32(metadata+0xc4u)==1u && m.r32(metadata+0x144u)==0u,
         "B336 first temporary must have left chunk zero empty");
    need(m.r32(tracker_record)==record && m.r32(tracker_chunk)==0u,
         "B336 request 8 must consume the recorded empty chunk");
    const auto node=arena+0x0cu,head=metadata+0x33cu;
    need(m.r32(node)==0xff0u && m.r32(node+0xfecu)==0xff0u &&
         m.r32(head+4u)==node && m.r32(head+8u)==arena+0x700cu &&
         m.r32(node+4u)==arena+0x100cu && m.r32(node+8u)==head,
         "B336 empty-chunk class-63 extent/ring differs");
    for(std::uint32_t page=1;page<8;++page) {
        const auto base=arena+page*0x1000u,p=base+0x0cu;
        need(m.r32(base+8u)==0xffffffffu && m.r32(base+0xffcu)==0xffffffffu &&
             m.r32(p)==0xff0u && m.r32(p+0xfecu)==0xff0u &&
             m.r32(p+4u)==(page==7u?head:p+0x1000u) &&
             m.r32(p+8u)==p-0x1000u,
             "B336 unallocated page extent was modified");
    }

    // 0x77372c/0x7737c8 select the extant region. The class-63 same-class
    // split leaves a 0xfe0 residual, allocates at the high edge, increments
    // the chunk live count, and clears only the matching empty-record slot.
    m.w32(entry_esp+4u,record);
    m.w32(cursor,record);
    const auto residual=0xff0u-expected_span;
    const auto allocated=node+residual;
    m.w32(node,residual);
    m.w32(node+residual-4u,residual);
    m.w32(allocated,expected_span+1u);
    m.w32(allocated+expected_span-4u,expected_span+1u);
    m.w32(metadata+0x144u,1u);
    m.w32(metadata,0u);
    m.w32(tracker_record,0u);
    need(class_for_span(residual)==63u && allocated+4u==arena+0xff0u,
         "B336 split must remain on class-63 branch");
    return allocated+4u;
}

void release_first_class1_temporary(X86Memory& m,std::uint32_t user,
                                    std::uint32_t request) {
    need((request==14u || request==15u) &&
         ((request+0x17u)&0xfffffff0u)==0x20u,
         "B336 first temporary must be request 14/15 in class 1");
    // The release helper consumes only the exact span/tags/list state; the
    // original 0x3733a8 body does not inspect the user's compressed bytes.
    empty173::release_last_class1(m,user);
}

void release_second_class0_temporary(X86Memory& m,std::uint32_t user) {
    constexpr std::uint32_t region_table=0x00b10e18u;
    constexpr std::uint32_t region_count=0x00b10e14u;
    constexpr std::uint32_t tracker_record=0x00b10e10u;
    constexpr std::uint32_t tracker_chunk=0x00b10e08u;
    const auto record=m.r32(region_table);
    need(record!=0 && m.r32(region_count)==1u &&
         m.r32(0x00b10e0cu)==record,
         "B336 class-0 free requires the sole current region");
    const auto arena=m.r32(record+0x0cu),metadata=m.r32(record+0x10u);
    const auto header=user-4u,left=header-0xfe0u;
    const auto head63=metadata+0x33cu,head0=metadata+0x144u;
    need(user==arena+0xff0u && m.r32(header)==0x11u &&
         m.r32(header+0x0cu)==0x11u &&
         m.r32(header+0x10u)==0xffffffffu,
         "B336 request-8 allocation/sentinel tags differ");
    need(m.r32(header-4u)==0xfe0u && m.r32(left)==0xfe0u &&
         class_for_span(0xfe0u)==63u && m.r32(head63+4u)==left &&
         m.r32(head63+8u)==arena+0x700cu,
         "B336 left class-63 residual does not match the split");
    need(m.r32(metadata+0x144u)==1u && m.r8(metadata+4u)==0u &&
         m.r32(head0+4u)==head0 && m.r32(head0+8u)==head0 &&
         (m.r32(record)&0x80000000u)==0u &&
         (m.r32(metadata+0x44u)&0x80000000u)==0u,
         "B336 class-0 list/count/maps must be empty before free");
    need(m.r32(tracker_record)==0u && m.r32(tracker_chunk)==0u,
         "B336 request-8 allocation must have consumed the empty marker");

    // The predecessor and merged spans both map to class 63. 0x7734b9
    // therefore retains the existing free-list node; no class-list or map
    // writes occur. 0x7735c3..0x7736c8 writes merged tags, drops live count,
    // and restores the empty-chunk tracker for chunk zero.
    m.w32(left,0xff0u);
    m.w32(left+0xff0u-4u,0xff0u);
    m.w32(metadata+0x144u,0u);
    m.w32(tracker_record,record);
    m.w32(tracker_chunk,0u);
}
} // namespace ra2::platform::small_crt_heap::b336
