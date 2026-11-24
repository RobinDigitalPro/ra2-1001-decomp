#include "recovered/ini_components.hpp"
#include "recovered/text_bytes.hpp"
#include "recovered/text_trim.hpp"

namespace ra2::recovered {
NameHashState* fun_0050ff70(NameHashState& state, std::uint32_t seed) {
    state.accumulator=seed; state.pending=0; state.scratch.fill(0);
    return &state;
}
namespace {
std::int32_t signed_hash(std::uint32_t bits) {
    return bits <= 0x7fffffffu ? static_cast<std::int32_t>(bits)
        : -1-static_cast<std::int32_t>(0xffffffffu-bits);
}
bool component_text(IniIndex* index, const std::uint8_t* section, const std::uint8_t* key,
    std::uint8_t (&text)[64], std::uint32_t& section_hash, std::uint32_t& key_hash,
    const MultiIntegerReadOperations& ops) {
    if (!section || !key) return false;
    section_hash=ops.lookup.hash_name(section,fun_00775160(section),ops.lookup.context);
    auto sh=signed_hash(section_hash);
    if (!fun_00510440(*index,&sh,ops.lookup)) return false;
    void* missing_section=ops.lookup.missing_section;
    auto* found=static_cast<IniSection*>(*fun_005104e0(*index,&sh,missing_section,ops.lookup));
    if (!found) return false;
    key_hash=ops.lookup.hash_name(key,fun_00775160(key),ops.lookup.context);
    auto kh=signed_hash(key_hash);
    if (!fun_00510220(found->keys,&kh,ops.lookup)) return false;
    void* missing_value=ops.lookup.missing_value;
    auto* value=static_cast<IniValue*>(*fun_005102c0(found->keys,&kh,missing_value,ops.lookup));
    if (!value || !value->text) return false;
    fun_0076dd10(text,value->text,64); text[63]=0;
    fun_006e41d0(text);
    return fun_00775160(text)!=0;
}
void scan_components(std::uint8_t* text, std::uint32_t* words, unsigned count,
                     const MultiIntegerReadOperations& ops) {
    DecimalFieldOutputs fields{{words,words+1,count==3?words+2:nullptr,nullptr}};
    static constexpr std::uint8_t two[]="%d,%d",three[]="%d,%d,%d";
    (void)fun_0076f070(text,count==2?two:three,&fields,ops.scan,ops.context);
}
}
std::uint32_t* fun_0050eac0(IniIndex* index,std::uint32_t* output,
    const std::uint8_t* section,const std::uint8_t* key,const std::uint32_t* fallback,
    const MultiIntegerReadOperations& ops) {
    std::uint8_t text[64]; std::uint32_t sh=0,kh=0;
    if (component_text(index,section,key,text,sh,kh,ops)) {
        std::uint32_t words[]{kh,sh}; scan_components(text,words,2,ops);
        output[0]=words[0]; output[1]=words[1];
    } else { output[0]=fallback[0]; output[1]=fallback[1]; }
    return output;
}
std::uint32_t* fun_0050ec50(IniIndex* index,std::uint32_t* output,
    const IniByteString& section,const IniByteString& key,ComponentFallback fallback,
    const MultiIntegerReadOperations& ops) {
    const auto* k=fun_0075a070(key); const auto* s=fun_0075a070(section);
    std::uint8_t text[64]; std::uint32_t sh=0,kh=0;
    if (component_text(index,s,k,text,sh,kh,ops)) {
        std::uint32_t words[]{fallback.address,0x008248a4u}; scan_components(text,words,2,ops);
        output[0]=words[0]; output[1]=words[1];
    } else {
        const auto a=fallback.values[0],b=fallback.values[1]; output[0]=a; output[1]=b;
    }
    return output;
}
std::uint32_t* fun_0050ee90(IniIndex* index,std::uint32_t* output,
    const std::uint8_t* section,const std::uint8_t* key,ComponentFallback fallback,
    const MultiIntegerReadOperations& ops) {
    std::uint8_t text[64]; std::uint32_t sh=0,kh=0;
    if (component_text(index,section,key,text,sh,kh,ops)) {
        std::uint32_t words[]{kh,sh,fallback.address}; scan_components(text,words,3,ops);
        for(unsigned i=0;i<3;++i)output[i]=words[i];
    } else { for(unsigned i=0;i<3;++i)output[i]=fallback.values[i]; }
    return output;
}
}
