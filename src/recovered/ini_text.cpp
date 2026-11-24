#include "recovered/ini_text.hpp"
#include "recovered/ini_bulk.hpp"
#include "recovered/text_bytes.hpp"
#include "recovered/text_trim.hpp"
namespace ra2::recovered {
std::int32_t fun_0050ddf0(IniIndex* index, const std::uint8_t* section,
    const std::uint8_t* key, const std::uint8_t* fallback,
    std::uint8_t* output, std::int32_t count, const IniOperations& ops) {
    if (!output || count < 2 || !section || !key) return 0;
    const auto* source = fallback;
    auto* found_section = fun_0050be00(index, section, ops);
    if (found_section) {
        auto* value = fun_0050f620(&found_section->keys, key, ops);
        if (value && value->text) source = value->text;
    }
    if (!source) { output[0] = 0; return 0; }
    fun_0076dd10(output, source, static_cast<std::uint32_t>(count));
    output[count - 1] = 0;
    fun_006e41d0(output);
    return static_cast<std::int32_t>(fun_00775160(output));
}
}
