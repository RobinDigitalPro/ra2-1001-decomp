#include "recovered/ini_bulk.hpp"

namespace ra2::recovered {
namespace {
std::int32_t name_key(const std::uint8_t* name, const IniOperations& ops) {
    const auto* end = name;
    while (*end) ++end;
    const auto bits = ops.hash_name(name, static_cast<std::size_t>(end-name), ops.context);
    return bits <= 0x7fffffffu ? static_cast<std::int32_t>(bits)
        : -1-static_cast<std::int32_t>(0xffffffffu-bits);
}
std::uint8_t member(IniIndex& index, const std::int32_t* query,
                    IniIndexKind kind, const IniOperations& ops) {
    if (!index.count) return 0;
    if (index.cached && index.cached->key == *query) return 1;
    auto* found = kind == IniIndexKind::sections
        ? fun_005106d0(index, query, ops) : fun_005105a0(index, query, ops);
    if (!found) return 0;
    index.cached = found;
    return 1;
}
void** slot(IniIndex& index, const std::int32_t* query, void*& fallback,
            IniIndexKind kind, const IniOperations& ops) {
    return member(index, query, kind, ops) ? &index.cached->value : &fallback;
}
void* named(IniIndex* index, const std::uint8_t* name, void* fallback,
            IniIndexKind kind, const IniOperations& ops) {
    if (!name) return nullptr; // Original returns before dereferencing receiver.
    const auto key = name_key(name, ops);
    if (!member(*index, &key, kind, ops)) return nullptr;
    return *slot(*index, &key, fallback, kind, ops); // Preserve second lookup.
}
IniIndexEntry* raw_search(IniIndexEntry* first, std::int32_t count, const std::int32_t* query) {
    if (count <= 0) return nullptr;
    const auto key = *query;
    do {
        const auto half = count/2;
        auto* middle = first+half;
        if (middle->key > key) count=half;
        else if (middle->key == key) return middle;
        else { first=middle+1; count-=half+1; }
    } while (count > 0);
    return nullptr;
}
}
IniIndex* fun_00510130(IniIndex& index) {
    index.entries=nullptr; index.count=0; index.spare=0;
    index.sorted=0; index.cached=nullptr;
    return &index; // MOV EAX,ECX survives RET; no allocation/free occurs.
}
std::uint8_t fun_00510580(const IniIndex& index, const std::int32_t* query) {
    return index.cached && index.cached->key == *query ? 1 : 0;
}
std::uint8_t fun_005106b0(const IniIndex& index, const std::int32_t* query) {
    return index.cached && index.cached->key == *query ? 1 : 0;
}
std::uint8_t fun_00510440(IniIndex& index, const std::int32_t* query, const IniOperations& ops) {
    return member(index, query, IniIndexKind::sections, ops);
}
void** fun_005102c0(IniIndex& index, const std::int32_t* query, void*& fallback, const IniOperations& ops) {
    return slot(index,query,fallback,IniIndexKind::entries,ops);
}
void** fun_005104e0(IniIndex& index, const std::int32_t* query, void*& fallback, const IniOperations& ops) {
    return slot(index,query,fallback,IniIndexKind::sections,ops);
}
IniIndexEntry* fun_00510780(IniIndexEntry* first, std::int32_t count, const std::int32_t* query) {
    return raw_search(first,count,query);
}
IniIndexEntry* fun_00510800(IniIndexEntry* first, std::int32_t count, const std::int32_t* query) {
    return raw_search(first,count,query);
}
const std::uint8_t* fun_0075a070(const IniByteString& string) {
    static const std::uint8_t empty[] = {0};
    return string.bytes ? string.bytes : empty;
}
IniSection* fun_0050be00(IniIndex* index, const std::uint8_t* name, const IniOperations& ops) {
    return static_cast<IniSection*>(named(index,name,ops.missing_section,IniIndexKind::sections,ops));
}
IniValue* fun_0050f620(IniIndex* index, const std::uint8_t* name, const IniOperations& ops) {
    return static_cast<IniValue*>(named(index,name,ops.missing_value,IniIndexKind::entries,ops));
}
std::int32_t fun_0050bf50(IniIndex* index, const std::uint8_t* name, const IniOperations& ops) {
    auto* section = fun_0050be00(index,name,ops);
    return section ? section->keys.count : 0;
}
std::int32_t fun_0050c020(IniIndex* index, const IniByteString& name, const IniOperations& ops) {
    return fun_0050bf50(index,fun_0075a070(name),ops);
}
const std::uint8_t* fun_0050c250(IniIndex* index, const std::uint8_t* name,
                               std::int32_t position, const IniOperations& ops) {
    auto* section = fun_0050be00(index,name,ops);
    if (!section || position >= section->keys.count) return nullptr;
    auto remaining = static_cast<std::uint32_t>(position);
    for (auto* node=section->first; node && node->next && node->previous; node=node->next) {
        if (remaining == 0) return node->name;
        --remaining;
    }
    return nullptr;
}
} // namespace ra2::recovered
