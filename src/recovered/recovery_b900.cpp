#include "recovered/global_b26_memory.hpp"
#include "recovered/name_hash.hpp"
#include "recovered/recovery_b900.hpp"
#include <cstdint>
#include <stdexcept>
#include <string>

// Bounded raw-index model for the native page fixture. The original code
// exercises 0x50cc40; this model uses the same sorted one-section/one-key
// memory graph and parses the sole positive decimal value directly.
namespace ra2::recovered::recovery_b900 {
using U = std::uint32_t;
using namespace global_b26;
namespace {
std::string bounded_text(const Memory& m, U p, U limit) {
    if (!p) throw std::domain_error("25a230 null text outside bounded fixture");
    std::string out;
    for (U k=0; k<limit; ++k) { const U c=m.r8(p+k); if (!c) return out; out.push_back(char(c)); }
    throw std::domain_error("25a230 unterminated bounded fixture text");
}
U hash_text(const std::string& s) {
    return ini_name_hash(reinterpret_cast<const std::uint8_t*>(s.data()),s.size(),nullptr);
}
U decimal_value(const Memory& m, U value_node) {
    const auto s=bounded_text(m,m.r32(value_node+0x10u),16);
    if (s.empty()) return 0;
    U value=0;
    for (const unsigned char c:s) {
        if (c<'0'||c>'9') throw std::domain_error("25a230 fixture requires positive decimal INI text");
        const U digit=U(c-'0');
        if (value>(0xffffffffu-digit)/10u) throw std::domain_error("25a230 fixture decimal overflow");
        value=value*10u+digit;
    }
    return value;
}
U query_fixture(const Memory& m, U ini_receiver, const std::string& key, U& section_row, U& key_row) {
    const U root_index=ini_receiver+0x20u;
    const U root_table=m.r32(root_index), root_count=m.r32(root_index+4u);
    if (!root_table||root_count!=1||!m.r8(root_index+12u)) throw std::domain_error("25a230 one sorted Waypoints section precondition");
    const U section_hash=hash_text("Waypoints");
    if (m.r32(root_table)!=section_hash) throw std::domain_error("25a230 authentic section hash mismatch");
    section_row=root_table;
    const U section=m.r32(root_table+4u), key_index=section+0x2cu;
    const U key_table=m.r32(key_index), key_count=m.r32(key_index+4u);
    if (!key_table||key_count>1||!m.r8(key_index+12u)) throw std::domain_error("25a230 zero-or-one sorted key precondition");
    if (key_count==0||m.r32(key_table)!=hash_text(key)) { key_row=0; return 0; }
    key_row=key_table;
    return decimal_value(m,m.r32(key_table+4u));
}
}
U fun_0065a230(Memory& m, const Inputs& in) {
    const U receiver=in.cx, ini_receiver=in.arg[0];
    if (!receiver||!ini_receiver) throw std::domain_error("25a230 bounded receiver/INI argument");
    U eax=0;
    for (U slot=0;slot<101;++slot) {
        const std::string key=std::to_string(slot);
        U section_row=0,key_row=0;
        const U value=query_fixture(m,ini_receiver,key,section_row,key_row);
        const U root_index=ini_receiver+0x20u;
        const U section=m.r32(section_row+4u),key_index=section+0x2cu;
        m.w32(root_index+0x10u,section_row); // original positive section-query cache
        if (key_row) m.w32(key_index+0x10u,key_row); // miss preserves prior key cache
        eax=value;
        const U dst=receiver+0x632u+slot*4u;
        if (!value) { m.w32(dst,m.r32(0x00a9e990u)); eax=0x7fffu; }
        else {
            const U rem=value%1000u, quotient=value/1000u;
            m.w16(dst,rem); m.w16(dst+2u,quotient);
            in.arg[0]=(rem&0xffffu)|((quotient&0xffffu)<<16);
        }
        const U x=m.r16(dst),y=m.r16(dst+2u);
        if (x!=m.r16(0x00a9e990u)||y!=m.r16(0x00a9e992u)) {
            const auto sx=static_cast<std::int16_t>(x),sy=static_cast<std::int16_t>(y);
            const std::int64_t map_index=std::int64_t(sy)*512+sx;
            if (map_index<0||map_index>=0x40000) throw std::domain_error("25a230 accepted 0x545500 positive map bound");
            const U map_table=m.r32(0x0081a958u),cell=m.r32(map_table+U(map_index)*4u);
            if (!map_table||!cell) throw std::domain_error("25a230 requires authentic nonnull map cell");
            m.w32(cell+0x140u,m.r32(cell+0x140u)|4u);
            eax=cell+0x140u;
        }
    }
    return eax;
}
}

