#include "recovered/crt_classify.hpp"

namespace ra2::recovered {
namespace {

std::uint32_t classify(std::int32_t input,
                       std::uint32_t mask,
                       const CrtClassification& ops) {
    if (ops.max_character_width > 1) {
        return ops.multibyte(input, mask, ops.context);
    }

    // The bounded single-byte view accepts EOF (-1) and every byte value.
    // The caller provides a pointer to the table's EOF entry, so input + 1
    // selects the corresponding word without changing the original signed
    // input passed to a multibyte helper.
    return static_cast<std::uint32_t>(ops.flags_from_minus_one[input + 1]) & mask;
}

} // namespace

std::uint32_t fun_0076e44e(std::int32_t input, const CrtClassification& ops) {
    return classify(input, 0x103u, ops);
}

std::uint32_t fun_0076e4cc(std::int32_t input, const CrtClassification& ops) {
    return classify(input, 0x4u, ops);
}

std::uint32_t fun_0076e4f4(std::int32_t input, const CrtClassification& ops) {
    return classify(input, 0x80u, ops);
}

std::uint32_t fun_0076e521(std::int32_t input, const CrtClassification& ops) {
    return classify(input, 0x8u, ops);
}

std::uint32_t fun_0076e571(std::int32_t input, const CrtClassification& ops) {
    return classify(input, 0x107u, ops);
}

std::uint32_t fun_0076e5cd(std::int32_t input, const CrtClassification& ops) {
    return classify(input, 0x117u, ops);
}

std::uint32_t fun_00775cf2(std::int32_t input, const CrtClassification& ops) {
    if (fun_0076e4cc(input, ops) != 0) {
        return static_cast<std::uint32_t>(input);
    }
    return (static_cast<std::uint32_t>(input) & 0xffffffdfu) - 7u;
}

} // namespace ra2::recovered
