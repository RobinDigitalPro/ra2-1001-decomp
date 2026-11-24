#pragma once
#define NOMINMAX
#include <windows.h>
#include <cstdint>
#include <string>
#include <vector>
namespace ra2::platform::cp990 {
struct Event {
    UINT code_page; DWORD flags; int wide_length, byte_capacity, result;
    std::wstring input; std::string output; bool null_default_char, null_used_default;
    std::uintptr_t wide_address, output_address, property_address, property_vtable;
    bool operator==(const Event& other) const {
        return code_page==other.code_page && flags==other.flags && wide_length==other.wide_length &&
            byte_capacity==other.byte_capacity && result==other.result && input==other.input &&
            output==other.output && null_default_char==other.null_default_char &&
            null_used_default==other.null_used_default && wide_address==other.wide_address &&
            output_address==other.output_address && property_address==other.property_address && property_vtable==other.property_vtable;
    }
    bool operator!=(const Event& other) const { return !(*this==other); }
};
inline std::vector<Event>& trace() { static std::vector<Event> events; return events; }
inline std::vector<std::uintptr_t>& model_read_pointers() { static std::vector<std::uintptr_t> values; return values; }
inline void record_model_read_pointer(const void* p) { model_read_pointers().push_back(reinterpret_cast<std::uintptr_t>(p)); }
inline std::uintptr_t& model_property(){static std::uintptr_t p=0;return p;}
inline std::uint32_t*& original_slot_address_storage(){static std::uint32_t* p=nullptr;return p;}
inline void reset() { trace().clear(); model_read_pointers().clear(); model_property()=0; original_slot_address_storage()=nullptr; }
inline int WINAPI convert(UINT cp, DWORD flags, LPCWCH wide, int wide_length, LPSTR output,
                          int capacity, LPCCH default_char, LPBOOL used_default) {
    const auto slot_storage=original_slot_address_storage();
    const std::uintptr_t property=slot_storage ? *reinterpret_cast<const std::uint32_t*>(std::uintptr_t(*slot_storage)) : model_property();
    const std::uintptr_t vtable=property ? *reinterpret_cast<const std::uint32_t*>(property) : 0u;
    const int result = ::WideCharToMultiByte(cp, flags, wide, wide_length, output, capacity,
                                              default_char, used_default);
    const std::wstring input = wide ? std::wstring(wide) : std::wstring();
    const std::string bytes = output && result > 0 ? std::string(output, std::size_t(result)) : std::string();
    trace().push_back({cp, flags, wide_length, capacity, result, input, bytes,
                       default_char == nullptr, used_default == nullptr,
                       reinterpret_cast<std::uintptr_t>(wide), reinterpret_cast<std::uintptr_t>(output), property, vtable});
    return result;
}
inline bool valid() {
    if (trace().size() != 1u) return false;
    const auto& e = trace()[0];
    return e.code_page == CP_ACP && e.flags == 0u && e.wide_length == -1 &&
           e.byte_capacity == 128 && e.result >= 1 && e.result <= 128 && e.null_default_char && e.null_used_default &&
           e.output.size() == std::size_t(e.result) && e.output.back() == '\0' &&
           e.wide_address != 0 && e.output_address != 0 && e.property_address != 0 && e.property_vtable != 0;
}
inline bool same_semantics(const std::vector<Event>& a,const std::vector<Event>& b) {
    if(a.size()!=b.size()) return false;
    for(std::size_t i=0;i<a.size();++i) {
        const auto& x=a[i]; const auto& y=b[i];
        if(x.code_page!=y.code_page||x.flags!=y.flags||x.wide_length!=y.wide_length||
           x.byte_capacity!=y.byte_capacity||x.result!=y.result||x.input!=y.input||
           x.output!=y.output||x.null_default_char!=y.null_default_char||
           x.null_used_default!=y.null_used_default) return false;
    }
    return true;
}
inline std::uint32_t address() {
    static_assert(sizeof(void*) == 4);
    return std::uint32_t(reinterpret_cast<std::uintptr_t>(&convert));
}
}
