#include "recovered/recovery_b928.hpp"
#include <stdexcept>

namespace ra2::recovered::recovery_b928 {
std::uint32_t fun_00773039(Memory&, const Inputs& in) {
    // On this bounded route the first copied stack word is the saved x87 CW.
    const std::uint32_t saved_cw = in.arg[0] & 0xffffu;
    if(in.fp.image.word(0)!=0x027fu || (saved_cw&0x3fu)!=0x3fu)throw std::domain_error("928 masked control word domain");
    const std::uint64_t stored = in.fp.store64(); // original FST m64, non-popping
    const std::uint32_t high = static_cast<std::uint32_t>(stored >> 32);
    const std::uint32_t exponent = high & 0x7ff00000u;
    if (!exponent || exponent == 0x7ff00000u)
        throw std::domain_error("B928 excludes zero, subnormal, infinity and NaN routes");
    const std::uint16_t output_cw = saved_cw == 0x027fu
        ? in.fp.image.word(0)
        : static_cast<std::uint16_t>(saved_cw);
    if (saved_cw != 0x027fu) in.fp.load_control(output_cw);
    return exponent | (saved_cw == 0x027fu ? 0x027fu : (saved_cw & 0x20u));
}
}
