#include "special_b63.hpp"
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::special_b63 {
namespace {

std::uint8_t sat_delta(Memory& m, std::uint32_t table, unsigned index,
                       std::uint8_t predictor) {
    const auto address=table+std::uint32_t(index);
    const auto addend=m.r8(address);
    const unsigned sum=unsigned(predictor)+addend;
    const bool carry=sum>0xffu;
    const auto result=std::uint8_t(sum);
    const auto sign_probe=m.r8(address); // original CMP reloads the table byte after PUSHFD
    const bool negative=sign_probe>=0x80u;
    if(negative&&!carry)return 0;
    if(!negative&&carry)return 0xffu;
    return result;
}

std::uint64_t quotient64(const Inputs& i) {
    std::uint64_t dividend = (std::uint64_t(i.arg[1]) << 32) | i.arg[0];
    std::uint64_t divisor = (std::uint64_t(i.arg[3]) << 32) | i.arg[2];
    if (divisor == 0) throw std::domain_error("Block63 signed 64-bit divide by zero");
    const bool dividend_negative = (dividend >> 63) != 0;
    const bool divisor_negative = (divisor >> 63) != 0;
    const std::uint64_t dividend_magnitude = dividend_negative ? (~dividend + 1u) : dividend;
    const std::uint64_t divisor_magnitude = divisor_negative ? (~divisor + 1u) : divisor;
    if (dividend_negative) {
        i.arg[1]=std::uint32_t(dividend_magnitude>>32); // original stores high word before low
        i.arg[0]=std::uint32_t(dividend_magnitude);
    }
    if (divisor_negative) {
        i.arg[3]=std::uint32_t(divisor_magnitude>>32);
        i.arg[2]=std::uint32_t(divisor_magnitude);
    }
    const auto magnitude = dividend_magnitude / divisor_magnitude;
    return dividend_negative != divisor_negative ? (~magnitude + 1u) : magnitude;
}

} // namespace

// RVA 0x8f510. The stack adapter exposes all 58 dwords consumed by RET 0xe8.
std::uint64_t fun_0048f510(Memory& m, const Inputs& i) {
    const auto index = i.arg[0];
    auto eax = index;
    if (s32(index) < 0)
        return std::uint32_t(eax & 0xffffff00u);
    const auto limit = m.r32(i.cx + 0x40u);
    if (s32(index) >= s32(limit))
        return std::uint32_t(eax & 0xffffff00u);

    m.w32(i.cx + 0x38u, index);
    m.w32(i.cx + 0x48u, m.r32(i.cx + 0x48u) + i.arg[18]);
    m.w32(i.cx + 0x4cu, m.r32(i.cx + 0x4cu) + i.arg[46]);
    m.w32(i.cx + 0x50u, m.r32(i.cx + 0x50u) + i.arg[22]);
    m.w32(i.cx + 0x54u, m.r32(i.cx + 0x54u) + i.arg[50]);
    m.w32(i.cx + 0x58u, m.r32(i.cx + 0x58u) + i.arg[14]);
    m.w32(i.cx + 0x5cu, m.r32(i.cx + 0x5cu) + i.arg[42]);
    m.w32(i.cx + 0x60u, m.r32(i.cx + 0x60u) + i.arg[26]);
    m.w32(i.cx + 0x64u, m.r32(i.cx + 0x64u) + i.arg[54]);
    m.w32(i.cx + 0x68u, i.arg[1]);
    eax = (eax & 0xffffff00u) | 1u;
    return eax;
}

// RVA 0x36de10. The original returns the quotient in EDX:EAX and consumes 16 bytes.
std::uint64_t fun_0076de10(Memory&, const Inputs& i) {
    return quotient64(i);
}

// RVA 0x384e0b. Preserve the byte-level average, signed-byte squared distance,
// later-candidate tie selection and first exact-match early exit.
std::uint64_t fun_00784e0b(Memory& m, const Inputs& i) {
    constexpr std::uint32_t pointer_global = 0x00a29420u;
    constexpr std::uint32_t output = 0x00a29424u;
    auto source_row = m.r32(pointer_global);
    auto pixel_source = m.r32(pointer_global);
    std::uint32_t output_index = 0;
    for (unsigned row = 0; row < 256; ++row) {
        pixel_source = m.r32(pointer_global); // Original outer back edge reloads EDI.
        for (unsigned column = 0; column < 256; ++column) {
            std::uint8_t target[3];
            for (unsigned ch = 0; ch < 3; ++ch) {
                const auto a = m.r8(source_row + ch);
                const auto b = m.r8(pixel_source + ch);
                target[ch] = std::uint8_t(std::uint8_t(a + b) >> 1);
            }

            const std::uint32_t palette = m.r32(pointer_global);
            std::uint32_t best_index = 0;
            std::uint32_t best_distance = 0xffffffffu;
            for (unsigned candidate = 0; candidate < 256; ++candidate) {
                std::uint32_t distance = 0;
                for (unsigned ch = 0; ch < 3; ++ch) {
                    const auto c = m.r8(palette + candidate * 3u + ch);
                    const auto d = std::uint8_t(c - target[ch]);
                    const int signed_d = d < 0x80u ? int(d) : int(d) - 0x100;
                    distance += std::uint32_t(signed_d * signed_d);
                }
                if (distance <= best_distance) {
                    best_distance = distance;
                    best_index = candidate;
                    if (distance == 0) break;
                }
            }
            m.w8(output + output_index, best_index);
            ++output_index;
            pixel_source += 3u;
        }
        source_row += 3u;
    }
    return i.ax; // PUSHAD/POPAD restores the incoming EAX.
}

// RVA 0x36a710. The four control classes and their original REP/copy boundaries
// are transcribed independently; fixtures keep every stream within its output span.
std::uint64_t fun_0076a710(Memory& m, const Inputs& i) {
    constexpr std::uint32_t four_step_table = 0x0076a8e2u;
    constexpr std::uint32_t sixteen_step_table = 0x0076a8e6u;
    auto esi = i.arg[0];
    auto edi = i.arg[1];
    auto ecx = i.arg[2];
    std::uint32_t consumed = 0;
    if (esi == 0 || edi == 0 || ecx == 0) return 0;
    std::uint32_t edx = (i.dx & 0xffffff00u) | 0x80u;

    while (s32(ecx) > 0) {
        const auto control = m.r8(esi++);
        ++consumed;
        const auto mode = (control >> 6) & 3u;
        const auto value = control & 0x3fu;
        auto dl = std::uint8_t(edx);

        if (mode == 2u) {
            if (value & 0x20u) {
                const int delta = (value & 0x10u) ? int(value & 0x1fu) - 32 : int(value & 0x1fu);
                dl = std::uint8_t(unsigned(dl) + unsigned(delta));
                edx = (edx & 0xffffff00u) | dl;
                m.w8(edi++, dl);
                --ecx;
            } else {
                const auto run = value + 1u;
                for (unsigned k = 0; k < run; ++k) {
                    const auto byte = m.r8(esi++);
                    m.w8(edi++, byte);
                }
                consumed += run;
                ecx -= run;
                --edi;
                dl = std::uint8_t(m.r8(edi));
                ++edi;
                edx = (edx & 0xffffff00u) | dl;
            }
            continue;
        }

        if (mode == 1u) {
            const auto pairs = value + 1u;
            for (unsigned k = 0; k < pairs; ++k) {
                const auto packed = m.r8(esi++);
                ++consumed;
                dl = sat_delta(m, sixteen_step_table, packed & 0x0fu, dl);
                edx = (edx & 0xffffff00u) | dl;
                const auto dh = dl;
                dl = sat_delta(m, sixteen_step_table, packed >> 4, dl);
                edx = (edx & 0xffff00ffu) | (std::uint32_t(dl) << 8);
                m.w16(edi, std::uint32_t(dh) | (std::uint32_t(dl) << 8));
                edx = (edx & 0xffffff00u) | dl; // MOV DL,DH carries the new predictor forward
                edi += 2u;
                ecx -= 2u;
            }
            continue;
        }

        if (mode == 0u) {
          for (unsigned unit = 0; unit < value + 1u; ++unit) {
            const auto packed = m.r8(esi++);
            ++consumed;
            for (unsigned k = 0; k < 4; ++k) {
                const auto code = (packed >> (k * 2u)) & 3u;
                dl = sat_delta(m, four_step_table, code, dl);
                edx = (edx & 0xffffff00u) | dl;
                if (k != 3) edx = (edx & 0xffff00ffu) | (std::uint32_t(dl) << 8);
                edx = (edx >> 8) | (edx << 24);
            }
            m.w32(edi, edx);
            ecx -= 4u;
            edi += 4u;
            edx = (edx << 8) | (edx >> 24);
          }
            continue;
        }

        // Mode 3 is the original STOSB repeat: length is low six bits plus one.
        const auto run = value + 1u;
        const auto fill = std::uint8_t(edx);
        ecx -= run;
        for (unsigned k = 0; k < run; ++k) m.w8(edi++, fill);
    }
    return consumed;
}

} // namespace ra2::recovered::special_b63
