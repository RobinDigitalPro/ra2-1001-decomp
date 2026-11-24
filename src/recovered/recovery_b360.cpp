#include "recovery_b360.hpp"

#include <array>
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b360 {
namespace {
using U = std::uint32_t;
using I = std::int32_t;
constexpr U kInvalidSocket = 0xffffffffu;
struct Query { U socket{}; std::array<std::uint8_t,24> address{}; };

void require_ops(const Operations& ops) {
    if (!ops.socket || !ops.bind || !ops.getsockopt || !ops.close)
        throw std::invalid_argument("0x356250/0x3563c0 requires the typed platform operations");
}

Query read_address(Memory& m, const Inputs& in, const Operations& ops) {
    require_ops(ops);
    if (in.cx == 0u || in.arg[0] != 0u || m.r8(0x821f8cu) != 0u)
        throw std::domain_error("0x356250 outside the reviewed index-zero/global-gate route");

    const U socket = ops.socket(ops.context, 6, 2, 1000);
    if (socket == kInvalidSocket)
        throw std::domain_error("0x356250 socket-failure route is excluded");

    std::array<std::uint8_t, 14> local_address{};
    // The sequential stack trace resolves the MOV WORD [ESP+0x24],6 write to
    // byte offset zero of the 14-byte buffer at [ESP+0x18].
    local_address[0] = 6u;
    I bind_result = ops.bind(ops.context, socket, local_address.data(), 14);
    if (bind_result == -1)
        throw std::domain_error("0x356250 bind-failure route is excluded");

    U count = 1u;
    I count_length = 4;
    const I count_result = ops.getsockopt(ops.context, socket, 1000, 0x400d,
        reinterpret_cast<std::uint8_t*>(&count), &count_length);
    if (count_result == -1)
        throw std::domain_error("0x356250 count-query failure route is excluded");
    if (count_length != 4 || count == 0u || count > 0x7fffffffu)
        throw std::domain_error("0x356250 count query is empty or outside signed index range");

    if (in.arg[0] >= count)
        throw std::domain_error("0x356250 index is outside the returned address count");
    std::array<std::uint8_t, 24> address{};
    I address_length = 24;
    const I address_result = ops.getsockopt(ops.context, socket, 1000, 0x4007,
        address.data(), &address_length);
    if (address_result == -1)
        throw std::domain_error("0x356250 address-query failure route is excluded");
    if (address_length != 24 || address[0] != 0u || address[1] != 0u ||
        address[2] != 0u || address[3] != 0u)
        throw std::domain_error("0x356250 address result differs from the reviewed 24-byte record");

    return {socket, address};
}

U network_word(const std::array<std::uint8_t, 24>& address) {
    return U(address[4]) | (U(address[5]) << 8) | (U(address[6]) << 16) |
           (U(address[7]) << 24);
}

void render_address(const std::array<std::uint8_t, 24>& address,
                    std::array<std::uint8_t, 32>& out) {
    static constexpr char digits[] = "0123456789abcdef";
    std::array<std::uint8_t, 10> bytes{};
    for (unsigned k = 0; k < 4; ++k) bytes[k] = address[4u+k];
    for (unsigned k = 0; k < 6; ++k) bytes[4u+k] = address[8u+k];
    unsigned p = 0;
    for (unsigned k = 0; k < bytes.size(); ++k) {
        out[p++] = std::uint8_t(digits[bytes[k] >> 4]);
        out[p++] = std::uint8_t(digits[bytes[k] & 15u]);
        if (k == 3u) { out[p++] = ' '; out[p++] = ':'; out[p++] = ' '; }
        else if (k + 1u < bytes.size()) out[p++] = ' ';
    }
    out[p] = 0u;
}
}

U fun_00756250(Memory& m, const Inputs& in, const Operations& ops) {
    const auto query = read_address(m, in, ops);
    const U network = network_word(query.address);
    const U out = in.arg[1];
    m.w32(out + 2u, network);
    for (U k = 0; k < 4u; ++k) m.w8(out + 6u + k, query.address[8u+k]);
    m.w16(out + 10u, U(query.address[12]) | (U(query.address[13]) << 8));
    m.w32(in.cx + 0x43afcu, network);
    if (ops.close(ops.context, query.socket) != 0)
        throw std::domain_error("0x356250 close result is not the reviewed success value");
    return 1u;
}

U fun_007563c0(Memory& m, const Inputs& in, const Operations& ops) {
    require_ops(ops);
    if (m.r8(in.cx + 0x43868u) == 0u || in.arg[0] != 0u || in.arg[2] < 32u)
        throw std::domain_error("0x3563c0 outside enabled, index-zero, capacity-at-least-32 route");

    const auto query = read_address(m, in, ops);
    std::array<std::uint8_t, 14> private_storage{};
    const U network = network_word(query.address);
    for (U k=0;k<4u;++k) private_storage[2u+k]=query.address[4u+k];
    for (U k=0;k<6u;++k) private_storage[6u+k]=query.address[8u+k];
    m.w32(in.cx + 0x43afcu, network);
    if (ops.close(ops.context, query.socket) != 0)
        throw std::domain_error("0x3563c0 inner close result is not the reviewed success value");
    std::array<std::uint8_t, 24> address{};
    for (U k = 0; k < 4u; ++k) address[4u+k] = private_storage[2u+k];
    for (U k = 0; k < 6u; ++k) address[8u+k] = private_storage[6u+k];
    std::array<std::uint8_t, 32> rendered{};
    render_address(address, rendered);
    const U capacity = in.arg[2];
    constexpr U length_including_nul = 32u;
    if (capacity < length_including_nul)
        throw std::domain_error("0x3563c0 insufficient output capacity route is excluded");
    for (U k = 0; k < length_including_nul; ++k) m.w8(in.arg[1] + k, rendered[k]);
    return 1u;
}
}
