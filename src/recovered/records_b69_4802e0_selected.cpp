#include "recovered/records_b69.hpp"
namespace ra2::recovered::records_b69 {
namespace {
using namespace global_b26;
void copy_forward(Memory& m, std::uint32_t dst, std::uint32_t src, std::uint32_t n) {
    // These routines use forward MOVSD/MOVSB. The supported fixtures keep the
    // ranges disjoint, so byte stores preserve the same resulting bytes.
    for (std::uint32_t k=0; k<n; ++k) m.w8(dst+k,m.r8(src+k));
}

// The list insertion code calls the original RET-only reporting leaf. Its
// architectural effect is no register or memory change; intentionally inline
// that effect rather than substituting the leaf's undefined EAX residue.
std::uint32_t insert_record(Memory& m, const Inputs& i, unsigned stride,
                            std::uint32_t count_off, std::uint32_t list_off,
                            std::uint32_t cursor_off, std::uint32_t limit_off,
                            std::uint32_t serial_off, std::uint32_t table_off, std::uint32_t payload_off,
                            std::uint32_t optional_len_off, std::uint32_t optional_data_off) {
    const auto obj=i.cx;
    const auto count=m.r32(obj+count_off);
    const auto cursor=m.r32(obj+cursor_off);
    const auto payload_len=i.arg[1];
    if(cursor==count || s32(payload_len)>s32(m.r32(obj+limit_off))) return 0;
    if(s32(count)<=0) return 0;

    const auto list=m.r32(obj+list_off);
    std::uint32_t slot=0;
    while(slot<count && (m.r8(list+slot*stride)&1u)!=0u) ++slot;
    if(slot==count) return 0;

    auto record=list+slot*stride;
    m.w32(record,m.r32(record)|1u);
    m.w32(record,m.r32(record)&~2u);
    m.w32(record,m.r32(record)&~4u);
    if(stride==32u) {
        m.w32(record+4u,0u); m.w32(record+8u,0u); m.w32(record+12u,0u);
        m.w32(record+16u,payload_len);
        copy_forward(m,m.r32(record+payload_off),i.arg[0],payload_len);
        const auto opt_src=i.arg[2], opt_len=i.arg[3];
        if(opt_src && s32(opt_len)>0 && s32(opt_len)<=s32(m.r32(obj+0x10u))) {
            copy_forward(m,m.r32(record+optional_data_off),opt_src,opt_len);
            m.w32(record+optional_len_off,opt_len);
        } else m.w32(record+optional_len_off,0u);
    } else {
        m.w32(record+4u,payload_len);
        copy_forward(m,m.r32(record+payload_off),i.arg[0],payload_len);
        const auto opt_src=i.arg[2], opt_len=i.arg[3];
        if(opt_src && s32(opt_len)>0 && s32(opt_len)<=s32(m.r32(obj+0x10u))) {
            copy_forward(m,m.r32(record+optional_data_off),opt_src,opt_len);
            m.w32(record+optional_len_off,opt_len);
        } else m.w32(record+optional_len_off,0u);
    }

    const auto old_cursor=m.r32(obj+cursor_off);
    const auto table=m.r32(obj+table_off);
    m.w32(table+old_cursor*4u,slot);
    const auto next_cursor=m.r32(obj+cursor_off)+1u;
    const auto next_serial=m.r32(obj+serial_off)+1u;
    m.w32(obj+serial_off,next_serial);
    m.w32(obj+cursor_off,next_cursor);
    return 1u;
}

}
std::uint32_t fun_004802e0(Memory& m,const Inputs& i) {
    return insert_record(m,i,20u,8u,0x34u,0x38u,0x0cu,0x3cu,0x40u,8u,0x0cu,0x10u);
}

}
