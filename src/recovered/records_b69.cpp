#include "recovered/records_b69.hpp"

#include "recovered/global_b58_a.hpp"
#include "recovered/global_b60_a.hpp"
#include "recovered/hash_wrappers.hpp"
#include "recovered/name_hash.hpp"

#include <algorithm>
#include <array>
#include <cstdint>
#include <stdexcept>
#include <vector>

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

void load_hash_state(Memory& m, std::uint32_t p, NameHashState& s) {
    s.accumulator=m.r32(p); s.pending=m.r32(p+4u);
    for(unsigned k=0;k<4;++k) s.scratch[k]=static_cast<std::uint8_t>(m.r8(p+8u+k));
    s.completion_byte=static_cast<std::uint8_t>(m.r8(p+12u));
}
void store_hash_state(Memory& m, std::uint32_t p, const NameHashState& s) {
    m.w32(p,s.accumulator); m.w32(p+4u,s.pending);
    for(unsigned k=0;k<4;++k) m.w8(p+8u+k,s.scratch[k]);
    m.w8(p+12u,s.completion_byte);
}

std::uint32_t append_string(Memory& m, NameHashState& state, std::uint32_t p) {
    std::vector<std::uint8_t> bytes;
    bytes.reserve(64);
    for(unsigned n=0;n<256;++n) {
        const auto b=static_cast<std::uint8_t>(m.r8(p+n));
        if(!b) return fun_00493da0(state,bytes.data(),static_cast<std::int32_t>(bytes.size()));
        bytes.push_back(b);
    }
    // Unterminated strings beyond the fixture's documented bound are outside
    // this recovery contract.
    return fun_00493da0(state,bytes.data(),static_cast<std::int32_t>(bytes.size()));
}
void append_word(Memory& m, std::uint32_t state_addr, NameHashState& state, std::uint32_t v) {
    (void)ra2::recovered::fun_00493d10(state,v); store_hash_state(m,state_addr,state);
}
void append_qword(Memory& m, std::uint32_t state_addr, NameHashState& state,
                  std::uint32_t low, std::uint32_t high) {
    const auto v=std::uint64_t(low)|(std::uint64_t(high)<<32);
    (void)ra2::recovered::fun_00493d50(state,v); store_hash_state(m,state_addr,state);
}
void compress_local(std::array<std::uint8_t,64>& block, std::array<std::uint8_t,20>& state) {
    constexpr std::uint32_t block_base=0x1000u,state_base=0x2000u;
    ra2::recovered::leaf::Memory block_span(block.data(),block_base,64u);
    ra2::recovered::leaf::Memory state_span(state.data(),state_base,20u);
    global_b26::Memory local; local.add(block_span); local.add(state_span);
    Inputs call{}; call.arg[0]=block_base; call.arg[1]=state_base;
    (void)global_b26::fun_0066a7e0(local,call);
}
}

std::uint32_t fun_0047fff0(Memory& m,const Inputs& i) {
    return insert_record(m,i,32u,4u,0x24u,0x28u,0x0cu,0x2cu,0x30u,0x14u,0x18u,0x1cu);
}

std::uint32_t fun_004802e0(Memory& m,const Inputs& i) {
    return insert_record(m,i,20u,8u,0x34u,0x38u,0x0cu,0x3cu,0x40u,8u,0x0cu,0x10u);
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

std::uint32_t fun_0066a570(Memory& m,const Inputs& i) {
    const auto obj=i.cx;
    auto remaining=m.r32(i.arg[1]);
    auto eax=i.arg[1];
    if(!remaining) return eax;
    const auto cursor=m.r32(i.arg[0]);
    if(!cursor) return eax;
    auto pending=m.r32(obj+0x30u);
    if(pending>64u) throw std::domain_error("Block69 pending count outside 64-byte block");
    if(!pending && s32(remaining)>=64) return eax;
    const auto room=64u-pending;
    const auto amount=std::min(remaining,room);
    copy_forward(m,obj+0x34u+pending,cursor,amount);
    m.w32(i.arg[0],cursor+amount);
    m.w32(obj+0x30u,pending+amount);
    m.w32(i.arg[1],remaining-amount);
    pending+=amount;
    if(pending!=64u) return pending;

    Inputs block{}; block.arg[0]=obj+0x34u; block.arg[1]=obj+0x18u;
    (void)global_b26::fun_0066a7e0(m,block);
    m.w32(obj+0x30u,0u);
    m.w32(obj+0x2cu,m.r32(obj+0x2cu)+64u);
    return m.r32(obj+0x2cu);
}

std::uint32_t fun_0066a690(Memory& m,const Inputs& i) {
    const auto obj=i.cx, output=i.arg[0];
    if(m.r8(obj)!=0u)
        for(unsigned k=0;k<5;++k) m.w32(output+k*4u,m.r32(obj+4u+k*4u));

    auto pending=m.r32(obj+0x30u);
    const auto total=m.r32(obj+0x2cu)+pending;
    std::array<std::uint8_t,64> block{};
    std::array<std::uint8_t,20> state{};
    for(unsigned k=0;k<state.size();++k)state[k]=static_cast<std::uint8_t>(m.r8(obj+0x18u+k));
    for(unsigned k=0;k<64;++k) block[k]=static_cast<std::uint8_t>(m.r8(obj+0x34u+k));
    block[pending]=0x80;
    if(64u-pending<9u) {
        for(unsigned k=pending+1u;k<64u;++k) block[k]=0;
        compress_local(block,state);
        block.fill(0);
    } else {
        for(unsigned k=pending+1u;k<64u;++k) block[k]=0;
    }
    // The original writes only the low 32-bit product at +60..+63; the
    // preceding four length bytes are explicitly zeroed.
    const std::uint32_t bitlen=total*8u;
    for(unsigned k=0;k<4;++k) block[56u+k]=0;
    for(unsigned k=0;k<4;++k) block[60u+k]=static_cast<std::uint8_t>(bitlen>>(24u-8u*k));
    compress_local(block,state);
    for(unsigned k=0;k<5;++k) {
        const auto word=std::uint32_t(state[k*4u])|(std::uint32_t(state[k*4u+1u])<<8)|
                        (std::uint32_t(state[k*4u+2u])<<16)|(std::uint32_t(state[k*4u+3u])<<24);
        const auto swapped=((word&0x000000ffu)<<24)|((word&0x0000ff00u)<<8)|
                           ((word&0x00ff0000u)>>8)|((word&0xff000000u)>>24);
        m.w32(obj+4u+k*4u,swapped);
    }
    m.w8(obj,1u);
    for(unsigned k=0;k<5;++k)m.w32(output+k*4u,m.r32(obj+4u+k*4u));
    return 20u;
}

std::uint32_t fun_004f9340(Memory& m,const Inputs& i) {
    const auto receiver=i.cx, state_addr=i.arg[0];
    NameHashState state{}; load_hash_state(m,state_addr,state);

    append_word(m,state_addr,state,m.r32(receiver+0x10u));
    const auto bool_byte=m.r8(receiver+0x20u)&0xffu;
    // 0x4101b0's second field is byte-normalized by 0x93c60.
    Inputs boolean{}; boolean.cx=state_addr; boolean.arg[0]=bool_byte;
    const auto ret_bool=global_b26::fun_00493c60(m,boolean);
    load_hash_state(m,state_addr,state);

    for(const auto off:{0x24u,0x64u,0x3du}) {
        (void)append_string(m,state,receiver+off); store_hash_state(m,state_addr,state);
    }
    for(const auto off:{0xb8u,0xbcu,0xc0u}) append_word(m,state_addr,state,m.r32(receiver+off));
    for(std::uint32_t off=0xc8u;off<=0xf8u;off+=8u) {
        const auto hi=m.r32(receiver+off+4u),lo=m.r32(receiver+off);
        append_qword(m,state_addr,state,lo,hi);
    }
    (void)append_string(m,state,receiver+0x1a0u); store_hash_state(m,state_addr,state);
    Inputs raw{};raw.cx=state_addr;raw.arg[0]=m.r8(receiver+0x1a4u);
    auto result=global_b26::fun_00493bd0(m,raw);
    Inputs normalized{};normalized.cx=state_addr;normalized.arg[0]=m.r8(receiver+0x1a5u);
    result=global_b26::fun_00493c60(m,normalized);
    (void)ret_bool;
    return result;
}
}

