#include "recovered/ini_lookup.hpp"

namespace ra2::recovered {
namespace {

IniIndexEntry* search(IniIndex& index, const std::int32_t* key,
                      IniIndexKind kind, const IniOperations& ops) {
    if (index.count == 0) return nullptr;          // 0x5106d0 / 0x5105a0
    if (index.sorted == 0) {
        ops.sort_nodes(index.entries, index.count, kind, ops.context);
        index.cached = nullptr;                  // 0x5106f8 / 0x5105c8
        index.sorted = 1;
    }
    auto* first = index.entries;
    auto count = index.count;
    while (count > 0) {                           // 0x51070c / 0x5105dc
        const auto half = count / 2;
        auto* middle = first + half;
        if (*key < middle->key) {
            count = half;
        } else if (*key == middle->key) {
            return middle;
        } else {
            first = middle + 1;
            count -= half + 1;
        }
    }
    return nullptr;
}

std::size_t byte_length(const std::uint8_t* text) {
    const auto* end = text;
    while (*end != 0) ++end;
    return static_cast<std::size_t>(end - text);
}

std::int32_t signed_key(std::uint32_t value) {
    if (value <= 0x7fffffffu) return static_cast<std::int32_t>(value);
    return -1 - static_cast<std::int32_t>(0xffffffffu - value);
}

} // namespace

IniIndexEntry* fun_005106d0(IniIndex& index, const std::int32_t* query,
                           const IniOperations& ops) {
    return search(index, query, IniIndexKind::sections, ops);
}

IniIndexEntry* fun_005105a0(IniIndex& index, const std::int32_t* query,
                           const IniOperations& ops) {
    return search(index, query, IniIndexKind::entries, ops);
}

std::uint8_t fun_00510220(IniIndex& index, const std::int32_t* query,
                         const IniOperations& ops) {
    if (index.count == 0) return 0;                // 0x510220
    if (index.cached != nullptr && index.cached->key == *query) return 1;
    auto* found = search(index, query, IniIndexKind::entries, ops);
    if (found == nullptr) return 0;                // Preserve old cache on sorted miss.
    index.cached = found;                         // 0x5102a6
    return 1;
}

std::uint8_t fun_0050e860(IniIndex* sections,
                        const std::uint8_t* section_name, const std::uint8_t* key_name,
                        std::uint8_t default_value, const IniOperations& ops) {
    if (section_name == nullptr || key_name == nullptr) return default_value;
    const auto section_key = signed_key(ops.hash_name(section_name, byte_length(section_name), ops.context));
    if (sections->count == 0) return default_value; // 0x50e8af
    if (sections->cached == nullptr || sections->cached->key != section_key) {
        auto* found = fun_005106d0(*sections, &section_key, ops);
        if (found == nullptr) return default_value;
        sections->cached = found;                 // 0x50e8d7
    }
    IniSection* section = ops.missing_section;
    if (sections->count != 0) {                    // 0x50e8da: retain the second lookup.
        if (sections->cached == nullptr || sections->cached->key != section_key) {
            auto* found = fun_005106d0(*sections, &section_key, ops);
            if (found != nullptr) {
                sections->cached = found;
                section = static_cast<IniSection*>(found->value);
            }
        } else {
            section = static_cast<IniSection*>(sections->cached->value);
        }
    }
    if (section == nullptr) return default_value;
    const auto key = signed_key(ops.hash_name(key_name, byte_length(key_name), ops.context));
    auto& keys = section->keys;
    if (keys.count == 0) return default_value;      // 0x50e93d..0x50e949
    if (keys.cached == nullptr || keys.cached->key != key) {
        auto* found = fun_005105a0(keys, &key, ops);
        if (found == nullptr) return default_value;
        keys.cached = found;
    }
    auto* value = fun_00510220(keys, &key, ops) != 0
        ? static_cast<IniValue*>(keys.cached->value) : ops.missing_value;
    if (value == nullptr || value->text == nullptr) return default_value;
    const auto byte = *value->text;
    const auto character = byte < 0x80u ? static_cast<std::int32_t>(byte)
                                       : static_cast<std::int32_t>(byte) - 0x100;
    switch (ops.uppercase(character, ops.context)) { // 0x50e997..0x50e9b3 + dispatch data.
    case '0': case 'F': case 'N': return 0;
    case '1': case 'T': case 'Y': return 1;
    default: return default_value;
    }
}

} // namespace ra2::recovered
