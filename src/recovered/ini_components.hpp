#pragma once
#include "recovered/ini_multi.hpp"
#include "recovered/name_hash.hpp"

namespace ra2::recovered {
// Explicit original-address view: values is host-readable storage; address is
// its encoded 32-bit address in the original execution being represented. Never
// derive this word by truncating a host pointer. No original class/ABI claim.
struct ComponentFallback { const std::uint32_t* values; std::uint32_t address; };
// Seed constructor at RVA 0x10ff70. Leaves completion_byte untouched.
NameHashState* fun_0050ff70(NameHashState&, std::uint32_t seed);
// All return output. Names/text follow IniOperations contracts. Output/fallback
// must provide 2 or 3 words and may overlap in one valid allocation; neither may
// overlap text or lookup state. Text is copied to 64 bytes, terminated and trimmed.
// Missing/empty text copies fallback. Present nonempty text ignores scan count:
// raw2 retains [key hash, section hash]; adapted2 retains [fallback.address,
// 0x008248a4]; raw3 retains [key hash, section hash, fallback.address] in fields
// the scan did not assign. Raw fallbacks copy sequentially, adapted snapshots.
std::uint32_t* fun_0050eac0(IniIndex*, std::uint32_t* output,
    const std::uint8_t* section, const std::uint8_t* key, const std::uint32_t* fallback,
    const MultiIntegerReadOperations&);
std::uint32_t* fun_0050ec50(IniIndex*, std::uint32_t* output,
    const IniByteString& section, const IniByteString& key, ComponentFallback fallback,
    const MultiIntegerReadOperations&);
std::uint32_t* fun_0050ee90(IniIndex*, std::uint32_t* output,
    const std::uint8_t* section, const std::uint8_t* key, ComponentFallback fallback,
    const MultiIntegerReadOperations&);
}
