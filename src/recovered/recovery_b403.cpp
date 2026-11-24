#include "recovery_b403.hpp"
#include "recovered/decimal_text.hpp"
#include "recovered/global_b26_memory.hpp"
#include "recovered/ini_bulk.hpp"
#include "recovered/ini_integer.hpp"
#include "recovered/ini_lookup.hpp"
#include "recovered/ini_text.hpp"
#include "recovered/name_hash.hpp"
#include "recovered/recovery_b253.hpp"
#include "recovered/text_bytes.hpp"
#include "platform/x87_state.hpp"
#include "platform/current_crt_thread.hpp"
#include "recovered/text_bytes.hpp"
#include <algorithm>
#include <array>
#include <cstring>
#include <memory>
#include <stdexcept>
#include <vector>

namespace ra2::recovered::recovery_b403 {
namespace {
using U = std::uint32_t;
using namespace floating_b61;
[[noreturn]] void reject(const char* why) { throw std::domain_error(why); }
std::vector<std::uint8_t> text(const Memory& m, U p) {
    if (!p) reject("INI403 requires a nonnull string");
    std::vector<std::uint8_t> out;
    for (unsigned n = 0; n != 64; ++n) {
        const auto b = static_cast<std::uint8_t>(m.r8(p + n)); out.push_back(b);
        if (!b) return out;
    }
    reject("INI403 strings are bounded to 64 readable bytes");
}
std::uint32_t hash_z(const std::vector<std::uint8_t>& s) {
    unsigned n = 0; while (n < s.size() && s[n]) ++n;
    return ini_name_hash(s.data(), n, nullptr);
}
std::int32_t signed_hash(U h) { return global_b26::s32(h); }
void no_sort(IniIndexEntry*, std::int32_t, IniIndexKind, void*) {
    reject("INI403 uses initialized signed-sorted indexes only");
}
std::uint32_t hash_cb(const std::uint8_t* p, std::size_t n, void*) { return ini_name_hash(p, n, nullptr); }
std::int32_t upper_cb(std::int32_t c, void*) { return c >= 'a' && c <= 'z' ? c - ('a' - 'A') : c; }

struct Section { IniSection view{}; std::vector<IniIndexEntry> rows; std::vector<std::unique_ptr<IniValue>> values; std::vector<std::vector<std::uint8_t>> strings; };
class Projection {
    Memory& m_; U receiver_, section_guest_; IniIndex root_{}; std::array<IniIndexEntry, 1> root_row_{}; Section section_{};
    IniOperations ops_{};
    void refresh_index(U index, IniIndex& logical, IniIndexEntry* rows, unsigned count) {
        logical.cached = nullptr; const U raw = m_.r32(index + 16), table = m_.r32(index);
        if (!raw) return;
        if (raw < table || ((raw - table) & 7u) || (raw - table) / 8u >= count)
            reject("INI403 cache escaped its bounded table");
        logical.cached = rows + (raw - table) / 8u;
    }
    void flush_index(U index, const IniIndex& logical, const IniIndexEntry* rows, unsigned count) {
        U raw = 0;
        if (logical.cached) {
            if (logical.cached < rows || logical.cached >= rows + count) reject("INI403 logical cache escaped table");
            raw = m_.r32(index) + 8u * static_cast<U>(logical.cached - rows);
        }
        m_.w32(index + 16, raw);
    }
public:
    Projection(Memory& m, U receiver, U section_name, unsigned key_count) : m_(m), receiver_(receiver), section_guest_(0) {
        if (!receiver_) reject("INI403 null INI receiver");
        const U index = receiver_ + 0x20u, table = m_.r32(index), count = m_.r32(index + 4);
        if (count != 1 || !table || !m_.r8(index + 12) || !m_.r32(table + 4))
            reject("INI403 requires the exact one-section positive fixture graph");
        section_guest_ = m_.r32(table + 4);
        const U root_hash = m_.r32(table), query_hash = hash_z(text(m, section_name));
        if (root_hash != query_hash) reject("INI403 section index does not match original section string");
        root_row_[0] = {signed_hash(root_hash), &section_.view};
        root_ = {root_row_.data(), 1, 1, nullptr, 1};
        refresh_index(index, root_, root_row_.data(), 1);
        const U ki = section_guest_ + 0x2c, kt = m_.r32(ki), kc = m_.r32(ki + 4);
        if (kc != key_count || !kt || !m_.r8(ki + 12) || m_.r32(ki + 8) < kc)
            reject("INI403 requires the complete initialized key table");
        section_.rows.resize(kc); section_.values.reserve(kc); section_.strings.reserve(kc);
        for (U k = 0; k != kc; ++k) {
            const U row = kt + 8u * k, value = m_.r32(row + 4), value_text = m_.r32(value + 0x10);
            section_.strings.push_back(text(m_, value_text));
            auto v = std::make_unique<IniValue>(); v->text = section_.strings.back().data();
            section_.rows[k] = {signed_hash(m_.r32(row)), v.get()}; section_.values.push_back(std::move(v));
            if (k && section_.rows[k - 1].key >= section_.rows[k].key) reject("INI403 keys are unique signed-sorted hashes");
        }
        section_.view.keys = {section_.rows.data(), static_cast<std::int32_t>(kc), 1, nullptr, kc};
        refresh_index(ki, section_.view.keys, section_.rows.data(), kc);
        ops_ = {hash_cb, no_sort, upper_cb, nullptr, nullptr, nullptr};
    }
    IniIndex& root() { return root_; }
    IniOperations ops() const { return ops_; }
    void refresh() {
        refresh_index(receiver_ + 0x20u, root_, root_row_.data(), 1);
        refresh_index(section_guest_ + 0x2cu, section_.view.keys, section_.rows.data(), static_cast<unsigned>(section_.rows.size()));
    }
    void flush() {
        flush_index(receiver_ + 0x20u, root_, root_row_.data(), 1);
        flush_index(section_guest_ + 0x2cu, section_.view.keys, section_.rows.data(), static_cast<unsigned>(section_.rows.size()));
    }
};

std::vector<std::uint8_t> read_text(Memory& m, Projection& graph, U section, U key,
                                    std::uint32_t capacity) {
    auto s=text(m,section), k=text(m,key);
    std::vector<std::uint8_t> out(capacity,0);
    const auto length=ra2::recovered::fun_0050ddf0(&graph.root(),s.data(),k.data(),nullptr,
                                                   out.data(),capacity,graph.ops());
    graph.flush();
    if(length<=0 || static_cast<std::uint32_t>(length)>=capacity)
        reject("B403 requires present nonempty bounded INI text");
    out.resize(static_cast<std::size_t>(length)+1u);
    return out;
}
bool equal_ascii(const std::vector<std::uint8_t>& a,const std::vector<std::uint8_t>& b) {
    if(a.size()!=b.size()) return false;
    for(std::size_t n=0;n<a.size();++n) {
        auto x=a[n],y=b[n];
        if(x>='A'&&x<='Z')x=static_cast<std::uint8_t>(x+('a'-'A'));
        if(y>='A'&&y<='Z')y=static_cast<std::uint8_t>(y+('a'-'A'));
        if(x!=y)return false;
    }
    return true;
}
}



std::uint32_t fun_0046c5d0(Memory& m,const Inputs& i,std::uint32_t entry_esp) {
    Projection graph(m,i.cx,i.arg[0],1);
    auto value=read_text(m,graph,i.arg[0],i.arg[1],128u);
    const U stack_base=entry_esp-0x80u;
    for(U n=0;n<0x80u;++n)m.w8(stack_base+n,0);
    for(std::size_t n=0;n<value.size();++n)m.w8(stack_base+static_cast<U>(n),value[n]);
    Inputs nested=i;nested.arg[0]=stack_base;nested.arg[1]=0x7b9950u;
    const U token=ra2::recovered::recovery_b253::fun_0076e802(m,nested);
    if(!token)reject("B403 enum route requires a nonempty first token");
    const auto normal=text(m,0x7bcac8u),strong=text(m,0x7bca3cu),fallback_none=text(m,0x7b9944u);
    const auto token_text=text(m,token);
    if(equal_ascii(token_text,fallback_none))return 0u;
    if(equal_ascii(token_text,normal))return 1u;
    if(equal_ascii(token_text,strong))return 2u;
    return i.arg[2];
}
} // namespace ra2::recovered::recovery_b403
