#include "recovered/recovery_b857.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::recovery_b857 {
namespace accepted_queue {using namespace global_b26;
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

std::uint32_t fun_0047fff0(Memory& m,const Inputs& i) {
    return insert_record(m,i,32u,4u,0x24u,0x28u,0x0cu,0x2cu,0x30u,0x14u,0x18u,0x1cu);
}

std::uint32_t fun_004811a0(Memory& m,const Inputs& i) {
    const auto obj=i.cx, out=m.r32(i.cx+0x20u);
    const auto flag=i.arg[2];
    m.w16(out,m.r16(obj+0x24u));
    if(flag) {
        m.w8(out+2u,0u); m.w32(out+4u,m.r32(obj+0x40u));
    } else {
        m.w8(out+2u,1u); m.w32(out+4u,m.r32(obj+0x3cu));
    }
    if(m.r32(0x00a255c8u)==4u && m.r8(0x00a27ed4u)!=0u)
        m.w8(out+3u,i.arg[3]&0xffu);

    const auto wanted=i.arg[1];
    const auto count=m.r32(obj+0x1cu);
    if(s32(count)<s32(wanted)) return 0u;

    copy_forward(m,out+8u,i.arg[0],wanted);
    Inputs child{};
    child.cx=m.r32(obj+4u); child.arg[0]=out; child.arg[1]=wanted+8u;
    child.arg[2]=0u; child.arg[3]=0u;
    if(fun_0047fff0(m,child)==0u) return 0u;
    if(flag) {m.w32(obj+0x40u,m.r32(obj+0x40u)+1u);}
    else {m.w32(obj+0x3cu,m.r32(obj+0x3cu)+1u);}
    return 1u;
}

}
std::uint32_t fun_00595130(Memory&m,const Inputs&i){
 using U=std::uint32_t;constexpr U p=0xf2400000u;
 std::array<std::uint8_t,250> packet{};leaf::Memory local(packet.data(),p,250);Memory work=m;work.add(local);
 work.w32(p,0x65);work.w32(p+0x86,m.r32(i.cx+0x50));work.w32(p+0xd4,m.r32(i.cx+0x54));work.w32(p+0xd0,m.r32(i.cx+0x58));work.w32(p+0xd8,m.r32(0x7c39a0));
 work.w32(p+0x1e,0x20000);work.w32(p+0x22,0x20000);work.w8(p+0x18,m.r8(0xa27e64));
 U len=0;while(len<20&&m.r8(0xa256d0+len))++len;if(len==20)throw std::domain_error("857 bounded message name");
 for(U k=0;k<=len;++k)work.w8(p+4+k,m.r8(0xa256d0+k));
 work.w32(p+0x19,m.r32(0xa256ec));work.w8(p+0x1d,m.r8(0xa256e4));
 if(!m.r32(0xa286a4))throw std::domain_error("857 active sender");
 Inputs call{};call.cx=m.r32(0xa286a0);if(m.r32(call.cx)!=0x792388)throw std::domain_error("857 original interface");
 call.arg[0]=p;call.arg[1]=250;call.arg[2]=1;call.arg[3]=0;
 U result=accepted_queue::fun_004811a0(work,call);if(!result)m.w32(0xa286d0,m.r32(0xa286d0)+1);return result;
}
}
