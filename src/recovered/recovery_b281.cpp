#include "recovery_b281.hpp"

#include <cstdint>
#include <limits>
#include <stdexcept>

namespace ra2::recovered::recovery_b281 {
namespace {
void require(bool ok, const char* why) {
    if (!ok) throw std::domain_error(why);
}
std::uint32_t checked_add(std::uint32_t a, std::uint32_t b) {
    require(a <= std::numeric_limits<std::uint32_t>::max() - b,
            "B281 finite route excludes address wrap");
    return a + b;
}
std::uint32_t wide_at(Heap& h, std::uint32_t p) {
    const auto a=h.r8(p), b=h.r8(checked_add(p,1u));
    return a | (b << 8);
}
void write_wide(Heap& h, std::uint32_t p, std::uint32_t value) {
    h.w8(p,value); h.w8(checked_add(p,1u),value>>8);
}
std::uint32_t wide_length(Heap& h, std::uint32_t p, std::uint32_t limit) {
    require(p != 0, "B281 requires a nonnull owned UTF-16 string");
    for (std::uint32_t n=0;n<limit;++n)
        if (wide_at(h,checked_add(p,n*2u))==0) return n;
    throw std::domain_error("B281 UTF-16 string must terminate within the bounded unit span");
}
void copy_counted_wide(Heap& h, std::uint32_t dst, std::uint32_t src,
                       std::uint32_t count) {
    // Exact accepted 0x76ef62 strncpy effect: copy at most count UTF-16 units,
    // then zero-pad the remainder if a source terminator is copied.
    for (std::uint32_t n=0;n<count;++n) {
        const auto value=wide_at(h,checked_add(src,n*2u));
        write_wide(h,checked_add(dst,n*2u),value);
        if(value==0) {
            for(++n;n<count;++n) write_wide(h,checked_add(dst,n*2u),0);
            return;
        }
    }
}
void copy_wide_string(Heap& h, std::uint32_t dst, std::uint32_t src,
                      std::uint32_t units_including_nul) {
    for(std::uint32_t n=0;n<units_including_nul;++n)
        write_wide(h,checked_add(dst,n*2u),wide_at(h,checked_add(src,n*2u)));
}
}

std::uint32_t rva_0035c500(Memory& m, const Inputs& i, Heap& h) {
    const auto object=i.cx;
    const auto count=i.arg[0]; // entry [ESP+4]; original RET 4
    require(object!=0 && (i.arithmetic_flags&0x400u)==0,
            "B281 route requires object cell and clear direction flag");
    require(count>=1017u && count<=1032u,
            "B281 finite route requires a long 1017..1032-unit current string");
    const auto old=m.r32(object);
    require(old!=0, "B281 finite route excludes the original null/fallback branch");
    const auto old_length=wide_length(h,old,1033u);
    require(old_length==count,
            "B281 fixture requires current UTF-16 length exactly equal to count");

    const auto temp_bytes=checked_add(count*2u,2u);
    require(temp_bytes>1016u, "B281 temporary must use ordinary large-heap route");
    auto temp=h.allocate(temp_bytes);
    require(temp!=0 && temp!=old,
            "B281 success-only route requires a distinct temporary while old buffer is live");
    write_wide(h,temp,0);
    copy_counted_wide(h,temp,old,count); // original executes actual 0x76ef62
    write_wide(h,checked_add(temp,count*2u),0);

    // Original releases the old pointer before clearing the object cell.
    require(h.release(old)!=0, "B281 old owned UTF-16 buffer free must succeed");
    m.w32(object,0);

    const auto length=wide_length(h,temp,count+1u); // original executes 0x76ef45
    const auto result_bytes=(length+1u)*2u;
    require(result_bytes>1016u,
            "B281 final payload must remain above the small-block boundary");
    auto result=h.allocate(result_bytes);
    require(result!=0 && result!=temp,
            "B281 success-only route requires distinct live result and temporary buffers");
    m.w32(object,result); // original publishes result before copying
    write_wide(h,result,0);
    copy_wide_string(h,result,temp,length+1u); // original executes actual 0x76efc9
    const auto free_result=h.release(temp);
    require(free_result!=0,
            "B281 finite route requires successful HeapFree before final MOV AL,1");
    return (free_result&0xffffff00u)|1u;
}
}
