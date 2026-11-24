#include "recovered/objects_b99.hpp"

#include "recovered/crt_b83.hpp"
#include "recovered/global_b58_a.hpp"
#include "recovered/name_hash.hpp"
#include "recovered/text_bytes.hpp"
#include "recovered/text_trim.hpp"
#include "recovered/ini_lookup.hpp"
#include "recovered/ini_text.hpp"

#include <array>
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::objects_b99 {
namespace {
using global_b26::s32;
constexpr std::uint32_t ini_table=0x00a9ea04u;
constexpr std::uint32_t ini_count=0x00a9ea10u;
constexpr std::uint32_t crt_mode=0x00b10530u;
constexpr std::uint32_t empty_section_list=0x00b10aacu;

std::uint32_t ini_hash_callback(const std::uint8_t* text,std::size_t n,void*) {
    NameHashState state{};
    return fun_00493da0(state,text,n);
}

std::uint32_t bounded_length(Memory& m,std::uint32_t p,std::uint32_t limit) {
    for(std::uint32_t n=0;n<limit;++n) if(m.r8(p+n)==0) return n;
    throw std::domain_error("Block99 INI string is not terminated within its contract span");
}

void hash_section(Memory& m,std::uint32_t section) {
    // Four bytes make the fresh-state original 0x93da0 route one complete
    // group, allowing an exact check against the mapped original CRC table.
    std::array<std::uint8_t,4> bytes{};
    const auto length=bounded_length(m,section,5u);
    if(length!=4u) throw std::domain_error("Block99 INI section must be exactly four ASCII bytes on the mapped-hash route");
    for(std::uint32_t n=0;n<length;++n) bytes[n]=static_cast<std::uint8_t>(m.r8(section+n));
    NameHashState accepted_state{};
    const auto accepted_hash=fun_00493da0(accepted_state,bytes.data(),4);

    std::array<std::uint8_t,4096> crc_page{};
    std::array<std::uint8_t,16> local_state{};
    constexpr std::uint32_t state_base=0x35000000u;
    leaf::Memory crc(crc_page.data(),0x007c0000u,static_cast<std::uint32_t>(crc_page.size()));
    leaf::Memory state_bytes(local_state.data(),state_base,static_cast<std::uint32_t>(local_state.size()));
    global_b26::Memory local;local.add(crc);local.add(state_bytes);
    for(std::uint32_t n=0;n<1024u;++n) crc.w8(0x007c0634u+n,m.r8(0x007c0634u+n));
    for(const auto byte:bytes) {
        global_b26::Inputs in{};in.cx=state_base;in.arg[0]=byte;
        (void)global_b26::fun_00493bd0(local,in);
    }
    if(local.r32(state_base)!=accepted_hash || local.r32(state_base+4u)!=0u)
        throw std::domain_error("Block99 mapped CRC helper disagrees with accepted section hash");
}

std::uint32_t compare_with_local_text(Memory& source,std::uint32_t candidate,
                                      const std::array<std::uint8_t,32>& output) {
    std::array<std::uint8_t,4096> mode_page{};
    std::array<std::uint8_t,32> strings{};
    constexpr std::uint32_t text_base=0x31000000u;
    leaf::Memory page(mode_page.data(),0x00b10000u,static_cast<std::uint32_t>(mode_page.size()));
    leaf::Memory text(strings.data(),text_base,static_cast<std::uint32_t>(strings.size()));
    global_b26::Memory local;
    local.add(page);local.add(text);local.w32(crt_mode,0);
    for(std::uint32_t n=0;n<8u;++n) {
        local.w8(text_base+n,source.r8(candidate+n));
        local.w8(text_base+16u+n,output[n]);
    }
    Inputs in{};in.arg[0]=text_base;in.arg[1]=text_base+16u;
    return crt_b83::fun_0076d860(local,in);
}
}

std::uint32_t fun_00469b70(Memory& m,const Inputs& i) {
    const auto receiver=i.cx,section=i.arg[0],key=i.arg[1],selector=i.arg[2];
    if(!receiver || !section || !key) throw std::domain_error("Block99 INI route requires mapped receiver, section and key");
    if(m.r32(crt_mode)!=0u) throw std::domain_error("Block99 INI route requires mode-zero ASCII comparison");
    if(m.r32(receiver+0x24u)!=0u || m.r32(empty_section_list)!=0u)
        throw std::domain_error("Block99 INI route requires the empty section-index fallback arm");
    const auto count=m.r32(ini_count),table=m.r32(ini_table);
    if(s32(count)<=0 || count>8u || selector>=count || !table)
        throw std::domain_error("Block99 INI selector/count outside the bounded table contract");
    const auto section_length=bounded_length(m,section,32u);
    const auto key_length=bounded_length(m,key,32u);
    if(section_length==0u || key_length==0u) throw std::domain_error("Block99 INI names must be nonempty");
    hash_section(m,section);

    // With [receiver+0x24]==0, accepted 0x10ddf0 takes its empty-list arm
    // through [0xb10aac]==0 and copies the selector record's fallback name.
    const auto selected=m.r32(table+selector*4u);
    if(!selected) throw std::domain_error("Block99 INI selector has no fallback record");
    const auto fallback=m.r32(selected+0x304u);
    const auto fallback_length=bounded_length(m,fallback,32u);
    if(fallback_length>31u) throw std::domain_error("Block99 fallback exceeds its 32-byte output count");
    std::array<std::uint8_t,32> output{},section_bytes{},key_bytes{},fallback_bytes{};
    for(std::uint32_t n=0;n<section_length;++n)section_bytes[n]=static_cast<std::uint8_t>(m.r8(section+n));
    for(std::uint32_t n=0;n<key_length;++n)key_bytes[n]=static_cast<std::uint8_t>(m.r8(key+n));
    for(std::uint32_t n=0;n<fallback_length;++n)fallback_bytes[n]=static_cast<std::uint8_t>(m.r8(fallback+n));
    IniIndex empty_index{};IniOperations operations{};operations.hash_name=ini_hash_callback;
    const auto output_length=fun_0050ddf0(&empty_index,section_bytes.data(),key_bytes.data(),fallback_bytes.data(),output.data(),32,operations);
    if(output_length<0 || output_length>31)throw std::domain_error("Block99 accepted INI helper returned an invalid bounded length");

    for(std::uint32_t n=0;n<count;++n) {
        const auto record=m.r32(table+n*4u);
        if(!record) throw std::domain_error("Block99 INI table contains a null record in the bounded scan");
        if(compare_with_local_text(m,m.r32(record+0x304u),output)==0 && m.r32(record+0x310u)!=1u)
            return n;
    }
    return selector;
}
} // namespace ra2::recovered::objects_b99
