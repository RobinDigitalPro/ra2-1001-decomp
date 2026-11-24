#include "recovery_b321.hpp"

#include "recovered/crt_b83.hpp"
#include "recovered/name_hash.hpp"

#include <algorithm>
#include <array>
#include <cstring>
#include <stdexcept>

namespace ra2::recovered::recovery_b321 {
namespace {
constexpr std::uint32_t sound_offset = 0x100;
constexpr std::uint32_t number_offset = 0x280;
constexpr std::uint32_t normal_offset = 0x288;
constexpr std::uint32_t repeat_offset = 0x289;
constexpr std::uint32_t side_offset = 0x28c;
constexpr std::uint32_t side_key_va = 0x007b8d1c;
constexpr std::uint8_t section_name[] = {'M','a','p',0};
constexpr std::uint8_t sound_key[] = "Sound";
constexpr std::uint8_t number_key[] = "Scenario";
constexpr std::uint8_t normal_key[] = "Normal";
constexpr std::uint8_t repeat_key[] = "Repeat";
constexpr std::uint8_t side_key[] = "Side";
constexpr std::uint8_t empty[] = {0};

void require(bool ok, const char* message) {
    if (!ok) throw std::domain_error(message);
}
void flush_both(Memory& m, const IndexProjection& root, const IndexProjection& keys) {
    root.flush_cache(m);
    keys.flush_cache(m);
}
}

void IndexProjection::flush_cache(Memory& m) const {
    require(logical != nullptr && guest_index != 0 && guest_table != 0,
            "B321 raw-index projection is incomplete");
    require(logical->entries == entries && logical->count == static_cast<std::int32_t>(count),
            "B321 finite projection requires its original fixed sorted node array");
    require(logical->sorted == 1, "B321 finite route requires already-sorted index");
    std::uint32_t raw_cache = 0;
    if (logical->cached) {
        bool matched = false;
        for (std::uint32_t n = 0; n < count; ++n) {
            if (logical->cached == entries + n) {
                raw_cache = guest_table + 8u * n;
                matched = true;
                break;
            }
        }
        require(matched, "B321 lookup cache escaped the finite raw node table");
    }
    m.w32(guest_index + 16u, raw_cache);
}

std::uint32_t rva_002dca40(Memory& m, const Inputs& i, IniIndex& section_graph,
    const IndexProjection& root_index, const IndexProjection& key_index,
    const IniOperations& ops, const IntegerReadOperations& integer_ops) {
    const auto receiver = i.cx;
    const auto ini_receiver = i.arg[0];
    require(receiver != 0 && ini_receiver != 0, "B321 finite route requires both receivers");
    require(m.r8(receiver) == 'M' && m.r8(receiver + 1u) == 'a' &&
            m.r8(receiver + 2u) == 'p' && m.r8(receiver + 3u) == 0,
            "B321 raw receiver base must contain the section name Map");
    require(root_index.logical == &section_graph && root_index.guest_index == ini_receiver + 0x20u,
            "B321 section index must be the original INI receiver+0x20");
    require(section_graph.count == 1 && section_graph.sorted == 1 && section_graph.entries,
            "B321 route is exactly one sorted Map section");
    auto* map_section = static_cast<IniSection*>(section_graph.entries[0].value);
    require(map_section && key_index.logical == &map_section->keys,
            "B321 key projection must refer to the Map section key index");
    require(key_index.count == 5 && key_index.logical->sorted == 1,
            "B321 route requires five sorted Map keys");

    auto* found = fun_0050be00(&section_graph, section_name, ops);
    flush_both(m, root_index, key_index);
    if (!found) return 0;

    std::array<std::uint8_t, 0x100> text{};
    (void)fun_0050ddf0(&section_graph, section_name, sound_key, empty,
                       text.data(), static_cast<std::int32_t>(text.size()), ops);
    flush_both(m, root_index, key_index);
    const auto original_end = std::find(text.begin(), text.end(), std::uint8_t{0});
    require(original_end != text.end(), "B321 original Sound value exceeds its 256-byte buffer");
    const auto original_bytes = static_cast<std::size_t>(original_end - text.begin()) + 1u;
    for (std::size_t n = 0; n < text.size(); ++n)
        m.w8(receiver + sound_offset + static_cast<std::uint32_t>(n), text[n]);
    auto first = text.begin();
    while (first != text.end() && (*first == '$' || *first == '#')) ++first;
    require(first != text.end(), "B321 selected Sound value must contain a terminator");
    const auto terminator = std::find(first, text.end(), std::uint8_t{0});
    require(terminator != text.end(), "B321 Sound value exceeds its 256-byte buffer");
    const auto bytes = static_cast<std::size_t>(terminator - first) + 1u;
    std::memmove(text.data(), &*first, bytes);
    for (std::size_t n = 0; n < bytes; ++n)
        m.w8(receiver + sound_offset + static_cast<std::uint32_t>(n), text[n]);

    const auto scenario = fun_0050cc40(&section_graph, section_name, number_key,
        m.r32(receiver + number_offset), integer_ops);
    flush_both(m, root_index, key_index);
    m.w32(receiver + number_offset, scenario);
    const auto normal = fun_0050e860(&section_graph, section_name, normal_key,
        static_cast<std::uint8_t>(m.r8(receiver + normal_offset)), ops);
    flush_both(m, root_index, key_index);
    m.w8(receiver + normal_offset, normal);
    const auto repeat = fun_0050e860(&section_graph, section_name, repeat_key,
        static_cast<std::uint8_t>(m.r8(receiver + repeat_offset)), ops);
    flush_both(m, root_index, key_index);
    m.w8(receiver + repeat_offset, repeat);

    std::array<std::uint8_t,128> query{};
    const auto query_length=fun_0050ddf0(&section_graph,section_name,side_key,empty,query.data(),128,ops);
    flush_both(m,root_index,key_index);
    require(query_length==1&&query[0]=='t'&&m.r32(0x84e4f0)==1,"321 one positive existing side row");
    const auto row=m.r32(m.r32(0x84e4e4));
    const auto local_address=std::uint32_t(std::uintptr_t(query.data()));
    leaf::Memory local(query.data(),local_address,128);Memory with_query=m;with_query.add(local);
    Inputs compare{};compare.arg[0]=row+0x24;compare.arg[1]=local_address;
    require(crt_b83::fun_0076d860(with_query,compare)==0,"321 supplied live side row must match");
    m.w32(receiver+side_offset,0);
    if (normal != 0) throw std::domain_error("B321 selected route requires Normal=0 to skip Name");
    return 1;
}

std::uint32_t fun_006dca40(Memory& m, const Inputs& input, const IniOperations& ops,
    const IntegerReadOperations& integer_ops) {
    constexpr std::uint32_t max_text = 256;
    const auto receiver = input.cx;
    const auto ini_receiver = input.arg[0];
    require(receiver && ini_receiver, "B321 raw adapter requires receiver and INI receiver");
    const auto raw_root_index = ini_receiver + 0x20u;
    const auto raw_root_table = m.r32(raw_root_index);
    const auto root_count = m.r32(raw_root_index + 4u);
    require(raw_root_table && root_count == 1 && m.r8(raw_root_index + 12u) == 1,
            "B321 raw adapter is limited to one sorted section node");
    require(m.r32(raw_root_index + 16u) == 0,
            "B321 raw adapter requires an initially null section cache");
    const auto section_node = raw_root_table;
    const auto section_object = m.r32(section_node + 4u);
    require(section_object != 0, "B321 raw section node requires a Map section object");
    const auto raw_key_index = section_object + 0x2cu;
    const auto raw_key_table = m.r32(raw_key_index);
    const auto key_count = m.r32(raw_key_index + 4u);
    require(raw_key_table && key_count == 5 && m.r8(raw_key_index + 12u) == 1,
            "B321 raw adapter is limited to five already-sorted Map keys");
    require(m.r32(raw_key_index + 16u) == 0,
            "B321 raw adapter requires an initially null key cache");

    std::array<std::array<std::uint8_t, max_text>, 5> text_storage{};
    std::array<IniValue, 5> values{};
    std::array<IniIndexEntry, 5> keys{};
    for (std::uint32_t n = 0; n != 5; ++n) {
        const auto raw_node = raw_key_table + 8u * n;
        const auto hash = static_cast<std::int32_t>(m.r32(raw_node));
        const auto raw_value = m.r32(raw_node + 4u);
        require(raw_value != 0, "B321 raw key node requires a value object");
        const auto raw_text = m.r32(raw_value + 0x10u);
        require(raw_text != 0, "B321 raw INI value requires nonnull text");
        std::uint32_t length = 0;
        for (; length != max_text; ++length) {
            text_storage[n][length] = static_cast<std::uint8_t>(m.r8(raw_text + length));
            if (text_storage[n][length] == 0) break;
        }
        require(length != max_text, "B321 raw INI value exceeds its 256-byte fixture limit");
        values[n].text = text_storage[n].data();
        keys[n] = {hash, &values[n]};
        if (n) require(keys[n - 1].key <= keys[n].key,
                       "B321 raw key nodes must be signed-hash sorted");
    }

    IniSection map_section{};
    map_section.keys = {keys.data(), 5, 1, nullptr, 5};
    IniIndexEntry root_node{static_cast<std::int32_t>(ini_name_hash(
        reinterpret_cast<const std::uint8_t*>("Map"), 3, nullptr)), &map_section};
    require(static_cast<std::uint32_t>(root_node.key) == m.r32(section_node),
            "B321 raw section node must hash to the exact Map query");
    IniIndex section_graph{&root_node, 1, 1, nullptr, 1};
    const IndexProjection root_projection{raw_root_index, raw_root_table, &section_graph,
        &root_node, 1};
    const IndexProjection key_projection{raw_key_index, raw_key_table, &map_section.keys,
        keys.data(), 5};
    return rva_002dca40(m, input, section_graph, root_projection, key_projection,
                        ops, integer_ops);
}
std::uint32_t fun_006dca40(Memory& m,const Inputs& i){
    require(m.r32(0xb10530)==0&&m.r32(0x81776c)<=1,"321 initial C locale route");
    const auto upper=[](std::int32_t c,void*)->std::int32_t{return c>='a'&&c<='z'?c-32:c;};
    const auto lower=[](std::int32_t c,void*)->std::int32_t{return c>='A'&&c<='Z'?c+32:c;};
    const auto classify=[](std::uint8_t c,std::uint32_t mask,void*context)->std::int32_t{
        const auto& raw=*static_cast<Memory*>(context);return raw.r16(raw.r32(0x817560)+2u*c)&mask;
    };
    const IniOperations ops{ini_name_hash,nullptr,upper,nullptr,nullptr,nullptr};
    const IntegerReadOperations integer_ops{ops,{classify,&m},lower,nullptr,nullptr};
    return fun_006dca40(m,i,ops,integer_ops);
}

}
