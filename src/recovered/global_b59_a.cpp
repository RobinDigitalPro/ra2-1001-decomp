#include "global_b59_a.hpp"

namespace ra2::recovered::global_b26 {
namespace {
struct ImageArgs {
    std::uint32_t table, source, destination, width, height, pitch;
};

ImageArgs image_args(const Inputs& i) {
    return {i.arg[0], i.arg[1], i.arg[2], i.arg[3], i.arg[4], i.arg[5]};
}

std::uint32_t pixel_byte(Memory& m, const ImageArgs& a, std::uint32_t position) {
    return m.r8(a.source + position);
}

std::uint32_t format_byte(Memory& m, const ImageArgs& a, std::uint32_t total,
                          std::uint32_t position) {
    return m.r8(a.source + total + position);
}

std::uint32_t duplicate_byte(std::uint32_t value) {
    value &= 0xffu;
    return value | (value << 8) | (value << 16) | (value << 24);
}

std::uint32_t duplicate_word(std::uint32_t value) {
    value &= 0xffffu;
    return value | (value << 16);
}

std::uint32_t format_index(std::uint32_t format, std::uint32_t pixel) {
    return ((format & 0xffu) << 8) | (pixel & 0xffu);
}
}

// RVA 0x36b890: two dword destinations. 0xff in the format plane selects
// the repeated source-byte form; all other formats select an eight-byte table row.
std::uint32_t fun_0076b890(Memory& m, const Inputs& i) {
    const auto a = image_args(i);
    const std::uint32_t total = a.width * a.height;
    std::uint32_t eax = total;
    std::uint32_t position = 0;
    std::uint32_t destination = a.destination;
    for (std::uint32_t row = 0; row < a.height; ++row) {
        for (std::uint32_t x = 0; x < a.width; ++x, ++position) {
            const std::uint32_t format = format_byte(m, a, total, position);
            const std::uint32_t pixel = pixel_byte(m, a, position);
            if (format == 0xffu) {
                const std::uint32_t value = duplicate_byte(pixel);
                eax = value;
                m.w32(destination, value);
                m.w32(a.pitch + destination, value);
            } else {
                const std::uint32_t record = a.table + format_index(format, pixel) * 8u;
                eax = m.r32(record);
                const std::uint32_t second = m.r32(record + 4u);
                m.w32(destination, eax);
                m.w32(a.pitch + destination, second);
            }
            destination += 4u;
        }
        destination = a.destination + (row + 1u) * (a.pitch * 2u);
    }
    return eax;
}

// RVA 0x36b9e4: two 16-bit color planes extracted from table offsets 0/2
// and 8/10. The MOV AL/AH sequence retains the high half of EAX's pixel-count value.
std::uint32_t fun_0076b9e4(Memory& m, const Inputs& i) {
    const auto a = image_args(i);
    const std::uint32_t total = a.width * a.height;
    std::uint32_t eax = total;
    std::uint32_t position = 0;
    std::uint32_t destination = a.destination;
    const std::uint32_t plane = a.pitch;
    for (std::uint32_t row = 0; row < a.height; ++row) {
        for (std::uint32_t x = 0; x < a.width; ++x, ++position) {
            const std::uint32_t format = format_byte(m, a, total, position);
            const std::uint32_t pixel = pixel_byte(m, a, position);
            std::uint32_t color;
            if (format == 0xffu) {
                color = (pixel & 0xffu) * 0x0101u;
            } else {
                const std::uint32_t record = a.table + format_index(format, pixel) * 16u;
                color = m.r8(record) | (m.r8(record + 2u) << 8);
            }
            eax = (total & 0xffff0000u) | color;
            m.w16(destination, color);
            if (format != 0xffu) {
                const std::uint32_t record = a.table + format_index(format, pixel) * 16u;
                color = m.r8(record + 8u) | (m.r8(record + 10u) << 8);
                eax = (total & 0xffff0000u) | color;
            }
            m.w16(plane + destination, color);
            destination += 2u;
        }
        destination = a.destination + (row + 1u) * (plane * 2u);
    }
    return eax;
}

// RVA 0x36b7c9: four dword chunks across two separated planes. Its sixth
// stack word is doubled in place before either destination stride is derived.
std::uint32_t fun_0076b7c9(Memory& m, const Inputs& i) {
    i.arg[5] *= 2u;
    const auto a = image_args(i);
    const std::uint32_t total = a.width * a.height;
    const std::uint32_t plane = a.pitch * 2u;
    std::uint32_t eax = total;
    std::uint32_t position = 0;
    std::uint32_t destination = a.destination;
    for (std::uint32_t row = 0; row < a.height; ++row) {
        for (std::uint32_t x = 0; x < a.width; ++x, ++position) {
            const std::uint32_t format = format_byte(m, a, total, position);
            const std::uint32_t pixel = pixel_byte(m, a, position);
            if (format & 0x80u) {
                const std::uint32_t index = format_index(format & 0x7fu, pixel);
                const std::uint32_t lookup = m.r32(0x00ab8094u);
                const std::uint32_t color = m.r16(lookup + index * 2u);
                eax = duplicate_word(color);
                m.w32(destination, eax);
                m.w32(destination + 4u, eax);
                m.w32(plane + destination, eax);
                m.w32(plane + destination + 4u, eax);
            } else {
                const std::uint32_t record = a.table + format_index(format, pixel) * 32u;
                eax = m.r32(record);
                const std::uint32_t first_high = m.r32(record + 4u);
                m.w32(destination, eax);
                m.w32(destination + 4u, first_high);
                eax = m.r32(record + 0x10u);
                const std::uint32_t second_high = m.r32(record + 0x14u);
                m.w32(plane + destination, eax);
                m.w32(plane + destination + 4u, second_high);
            }
            destination += 8u;
        }
        destination = a.destination + (row + 1u) * (a.pitch * 4u);
    }
    return eax;
}

// RVA 0x36b926: four independently selected dword planes. Reads remain
// interleaved with writes as in the original, so legitimate storage aliases keep order.
std::uint32_t fun_0076b926(Memory& m, const Inputs& i) {
    const auto a = image_args(i);
    const std::uint32_t total = a.width * a.height;
    std::uint32_t eax = total;
    std::uint32_t position = 0;
    std::uint32_t destination = a.destination;
    for (std::uint32_t row = 0; row < a.height; ++row) {
        for (std::uint32_t x = 0; x < a.width; ++x, ++position) {
            const std::uint32_t format = format_byte(m, a, total, position);
            const std::uint32_t pixel = pixel_byte(m, a, position);
            if (format == 0xffu) {
                const std::uint32_t value = duplicate_byte(pixel);
                eax = value;
                m.w32(destination, value);
                m.w32(a.pitch + destination, value);
                m.w32(a.pitch * 2u + destination, value);
                m.w32(a.pitch * 3u + destination, value);
            } else {
                const std::uint32_t record = a.table + format_index(format, pixel) * 16u;
                eax = m.r32(record);
                const std::uint32_t second = m.r32(record + 4u);
                m.w32(destination, eax);
                eax = a.table + format_index(format, pixel) * 16u;
                m.w32(a.pitch + destination, second);
                eax = m.r32(eax + 8u);
                const std::uint32_t fourth = m.r32(a.table + format_index(format, pixel) * 16u + 12u);
                m.w32(a.pitch * 2u + destination, eax);
                m.w32(a.pitch * 3u + destination, fourth);
            }
            destination += 4u;
        }
        destination = a.destination + (row + 1u) * (a.pitch * 4u);
    }
    return eax;
}

// RVA 0x36bb18: four two-dword planes with signed-format marker expansion.
// The original doubles the sixth stack word and exposes that stack write.
std::uint32_t fun_0076bb18(Memory& m, const Inputs& i) {
    i.arg[5] *= 2u;
    const auto a = image_args(i);
    const std::uint32_t total = a.width * a.height;
    const std::uint32_t plane = a.pitch;
    std::uint32_t eax = total;
    std::uint32_t position = 0;
    std::uint32_t destination = a.destination;
    for (std::uint32_t row = 0; row < a.height; ++row) {
        for (std::uint32_t x = 0; x < a.width; ++x, ++position) {
            const std::uint32_t format = format_byte(m, a, total, position);
            const std::uint32_t pixel = pixel_byte(m, a, position);
            if (format & 0x80u) {
                const std::uint32_t color = format_index(format & 0x7fu, pixel);
                eax = duplicate_word(color);
                m.w32(destination, eax);
                m.w32(destination + 4u, eax);
                m.w32(plane + destination, eax);
                m.w32(plane + destination + 4u, eax);
                m.w32(plane * 2u + destination, eax);
                m.w32(plane * 2u + destination + 4u, eax);
                m.w32(plane * 3u + destination, eax);
                m.w32(plane * 3u + destination + 4u, eax);
            } else {
                const std::uint32_t record = a.table + format_index(format, pixel) * 32u;
                eax = m.r32(record);
                const std::uint32_t first_high = m.r32(record + 4u);
                m.w32(destination, eax);
                m.w32(destination + 4u, first_high);
                eax = m.r32(record + 8u);
                const std::uint32_t second_high = m.r32(record + 12u);
                m.w32(plane + destination, eax);
                m.w32(plane + destination + 4u, second_high);
                eax = m.r32(record + 0x10u);
                const std::uint32_t third_high = m.r32(record + 0x14u);
                m.w32(plane * 2u + destination, eax);
                m.w32(plane * 2u + destination + 4u, third_high);
                eax = m.r32(record + 0x18u);
                const std::uint32_t fourth_high = m.r32(record + 0x1cu);
                m.w32(plane * 3u + destination, eax);
                m.w32(plane * 3u + destination + 4u, fourth_high);
            }
            destination += 8u;
        }
        destination = a.destination + (row + 1u) * (a.pitch * 4u);
    }
    return eax;
}

// RVA 0x36ba7e: 16-bit sibling of 0x36b9e4, independently retained because
// its original entry and instruction evidence are separate.
std::uint32_t fun_0076ba7e(Memory& m, const Inputs& i) {
    const auto a = image_args(i);
    const std::uint32_t total = a.width * a.height;
    std::uint32_t eax = total;
    std::uint32_t position = 0;
    std::uint32_t destination = a.destination;
    const std::uint32_t plane = a.pitch;
    for (std::uint32_t row = 0; row < a.height; ++row) {
        for (std::uint32_t x = 0; x < a.width; ++x, ++position) {
            const std::uint32_t format = format_byte(m, a, total, position);
            const std::uint32_t pixel = pixel_byte(m, a, position);
            std::uint32_t color;
            if (format == 0xffu) {
                color = (pixel & 0xffu) * 0x0101u;
            } else {
                const std::uint32_t record = a.table + format_index(format, pixel) * 8u;
                color = m.r8(record) | (m.r8(record + 2u) << 8);
            }
            eax = (total & 0xffff0000u) | color;
            m.w16(destination, color);
            if (format != 0xffu) {
                const std::uint32_t record = a.table + format_index(format, pixel) * 8u;
                color = m.r8(record + 8u) | (m.r8(record + 10u) << 8);
                eax = (total & 0xffff0000u) | color;
            }
            m.w16(plane + destination, color);
            destination += 2u;
        }
        destination = a.destination + (row + 1u) * (plane * 2u);
    }
    return eax;
}

}
