#include "recovered/recovery_b156.hpp"
#include "recovered/name_hash.hpp"

#include <stdexcept>
#include <string>

namespace ra2::recovered::recovery_b156 {
namespace {
void require(bool ok, const char* why) {
    if (!ok) throw std::domain_error(why);
}
std::string read_z(Memory& m, std::uint32_t p) {
    require(p != 0, "non-null bounded string required");
    std::string out;
    for (unsigned n=0; n<128; ++n) {
        const auto c=static_cast<unsigned char>(m.r8(p+n));
        if (!c) return out;
        out.push_back(static_cast<char>(c));
    }
    throw std::domain_error("bounded string has no NUL within 128 bytes");
}
std::string read_z(Heap& h, std::uint32_t p) {
    require(p != 0, "non-null heap text required");
    std::string out;
    for (unsigned n=0; n<128; ++n) {
        const auto c=static_cast<unsigned char>(h.r8(p+n));
        if (!c) return out;
        out.push_back(static_cast<char>(c));
    }
    throw std::domain_error("heap text has no NUL within 128 bytes");
}
std::uint32_t hash_name(const std::string& s) {
    return ini_name_hash(reinterpret_cast<const std::uint8_t*>(s.data()),s.size(),nullptr);
}
void write_z(Heap& h,std::uint32_t p,const std::string& s) {
    for (unsigned n=0;n<s.size();++n) h.w8(p+n,static_cast<std::uint8_t>(s[n]));
    h.w8(p+static_cast<unsigned>(s.size()),0);
}
std::uint32_t insert_new_value(Memory& m,Heap& h,std::uint32_t receiver,
        std::uint32_t section_name,std::uint32_t key_name,std::uint32_t value_pointer) {
    const auto section_text=read_z(m,section_name), key_text=read_z(m,key_name),value=read_z(h,value_pointer);
    require(!section_text.empty()&&!key_text.empty()&&!value.empty(),"nonempty INI text required");
    const auto section_root=receiver+0x20u, section_table=m.r32(section_root);
    require(m.r32(section_root+4u)==1u&&m.r8(section_root+12u)==1u,
            "one-row sorted section hit required");
    require(m.r32(section_table)==hash_name(section_text),"sole section row hash mismatch");
    const auto section=m.r32(section_table+4u);
    require(section&&m.r32(section_root+16u)==section_table,"valid sole section cache required");
    const auto key_root=section+0x2cu,key_table=m.r32(key_root);
    require(m.r32(key_root+4u)==1u&&m.r32(key_root+8u)>=2u&&m.r8(key_root+12u)==1u&&
            m.r32(key_root+16u)==0u,"one sorted key, spare capacity, null key cache required");
    const auto key_hash=hash_name(key_text);
    require(m.r32(key_table)!=key_hash,"sole prior key must be a sorted miss");

    const auto node=h.allocate(40u);
    require(node!=0,"real 40-byte node allocation required");
    const auto value_copy=h.allocate(static_cast<unsigned>(value.size()+1u));
    require(value_copy!=0,"real value-clone allocation required");
    write_z(h,value_copy,value);
    const auto key_copy=h.allocate(static_cast<unsigned>(key_text.size()+1u));
    require(key_copy!=0,"real key-clone allocation required");
    write_z(h,key_copy,key_text);
    h.w32(node,0x0078eb9cu);h.w32(node+4u,0u);h.w32(node+8u,0u);
    h.w32(node+0x0cu,key_copy);h.w32(node+0x10u,value_copy);h.w32(node+0x14u,0u);
    for(unsigned off=0x18;off<=0x24;off+=4)h.w32(node+off,0u);

    const auto position=m.r32(section+0x28u);
    require(position&&h.r32(position+4u)==0u,"empty readable list insertion position required");
    h.w32(node+4u,0u);h.w32(node+8u,position);h.w32(position+4u,node);
    m.w32(key_table+8u,key_hash);m.w32(key_table+12u,node);
    m.w8(key_root+12u,0u);m.w32(key_root+4u,2u);
    return 1u;
}
}

std::uint32_t fun_0050e140(Memory& m,const Inputs& i,Heap& h) {
    const auto wide=i.arg[2];
    require(wide!=0,"non-null UTF-16 pointer required");
    const auto unit=m.r16(wide);
    require(unit>=1u&&unit<=15u&&m.r16(wide+2u)==0u,
            "finite route requires exactly one UTF-16 code unit U+0001..U+000F");
    // The original advances its caller-owned UTF-16 cursor once per converted
    // unit.  On this one-unit route arg2 is left pointing at the terminator.
    i.arg[2]=wide+2u;

    // The original asks for 8*n+1 bytes (n=1), converts radix 16 to lowercase,
    // and appends the pinned comma literal. This route therefore always asks
    // for 9 bytes and produces one hex digit, comma, NUL.
    const auto temporary=h.allocate(9u);
    require(temporary!=0,"real request-9 small allocation required");
    const char digit=static_cast<char>(unit<10u?'0'+unit:'a'+(unit-10u));
    h.w8(temporary,static_cast<std::uint8_t>(digit));
    h.w8(temporary+1u,',');h.w8(temporary+2u,0u);

    const auto setter_al=insert_new_value(m,h,i.cx,i.arg[0],i.arg[1],temporary);
    // Original VA 0x76d67b frees the temporary buffer after saving setter AL
    // in BL. Heap::release is the proposed bounded real class-1 no-neighbor
    // extension; its observed raw EAX=0x12 is deliberately not returned here.
    h.release(temporary);
    return setter_al&0xffu; // Entry contract compares AL only; upper EAX is residue.
}
}
