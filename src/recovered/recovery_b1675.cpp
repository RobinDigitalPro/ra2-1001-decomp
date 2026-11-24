#include "recovery_b1675.hpp"
#include "recovered/recovery_b1627.hpp"

#include <array>
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::b1675 {
namespace {
using U = std::uint32_t;
using Byte = std::uint8_t;
using Packet = std::array<Byte, 455>;

constexpr std::array<U, 8> kStringGlobals{
    0x00a27dc4u, 0x00a27dc8u, 0x00a27dccu, 0x00a27dd0u,
    0x00a27dd4u, 0x00a27dd8u, 0x00a27ddcu, 0x00a27de0u};
constexpr std::array<U, 6> kSentinelGlobals{
    0x00a5a89cu, 0x00a5a8a0u, 0x00a5a8a4u,
    0x00a5a8a8u, 0x00a5a8acu, 0x00a5a8b0u};

void need(bool condition, const char* message) {
    if (!condition) throw std::domain_error(message);
}

void put32(Packet& packet, U offset, U value) {
    for (U k = 0; k < 4u; ++k)
        packet.at(offset + k) = static_cast<Byte>(value >> (8u * k));
}

U ascii_with_nul(Memory& memory, U source, Packet& packet, U offset,
                 U min_length, U max_length) {
    U length = 0;
    for (; length <= max_length; ++length) {
        const U value = memory.r8(source + length);
        packet.at(offset + length) = static_cast<Byte>(value);
        if (value == 0u) break;
    }
    need(length >= min_length && length <= max_length,
         "B1675 finite ASCII source length");
    return length;
}

// Reuses only the Source-qualified 1BE7A0/5235C0/47FFF0 one-peer effects.
// The B1674 helper is private and also runs 821e0, so this stays local and
// does not add any provider, callback, heap, or alternate queue implementation.
void enqueue_one(Memory& memory, const Packet& packet, U peer) {
    constexpr U manager = 0x00a285c8u;
    need(memory.r8(manager + 4u) != 0u && memory.r8(manager + 5u) != 0u,
         "B1675 selected manager enabled");
    bool descriptor_is_all_ff = true;
    for (U k = 0; k < 10u; ++k)
        if (memory.r8(peer + 0x28u + k) != 0xffu) descriptor_is_all_ff = false;
    need(!descriptor_is_all_ff, "B1675 non-FF peer descriptor10");

    const U provider = memory.r32(manager + 0x48u);
    need(provider != 0u, "B1675 selected provider");
    const U queue = memory.r32(provider + 4u);
    const U buffer = memory.r32(provider + 0x20u);
    need(queue != 0u && buffer != 0u, "B1675 actual queue and buffer pointers");
    need(memory.r32(provider) == 0x78f684u &&
         memory.r32(queue) == 0x788db4u &&
         memory.r32(queue + 4u) == 1u &&
         memory.r32(queue + 0x28u) == 0u &&
         memory.r32(queue + 0x2cu) == 0u &&
         memory.r32(queue + 0x0cu) == 465u &&
         memory.r32(queue + 0x10u) == 10u,
         "B1675 finite first outgoing queue state");

    memory.w16(buffer, memory.r16(provider + 0x24u));
    memory.w8(buffer + 2u, 0u);
    memory.w8(buffer + 3u, 0u);
    memory.w32(buffer + 4u, memory.r32(queue + 0x2cu));
    memory.w16(buffer + 8u, memory.r16(provider + 0xb4u));
    for (U k = 0; k < packet.size(); ++k)
        memory.w8(buffer + 10u + k, packet[k]);

    const U row = memory.r32(queue + 0x24u);
    const U slots = memory.r32(queue + 0x30u);
    need(row != 0u && slots != 0u, "B1675 constructor-produced row and slot array");
    const U payload = memory.r32(row + 0x14u);
    const U auxiliary = memory.r32(row + 0x1cu);
    need(payload != 0u && auxiliary != 0u && memory.r32(row) == 0u,
         "B1675 first row and constructor-produced buffers");

    memory.w32(row, memory.r32(row) | 1u);
    memory.w32(row, memory.r32(row) & ~2u);
    memory.w32(row, memory.r32(row) & ~4u);
    memory.w32(row + 4u, 0u);
    memory.w32(row + 8u, 0u);
    memory.w32(row + 12u, 0u);
    memory.w32(row + 16u, 465u);
    for (U k = 0; k < 465u; ++k)
        memory.w8(payload + k, memory.r8(buffer + k));
    for (U k = 0; k < 10u; ++k)
        memory.w8(auxiliary + k, memory.r8(peer + 0x28u + k));
    memory.w32(row + 0x18u, 10u);
    memory.w32(slots, 0u);
    memory.w32(queue + 0x28u, 1u);
    memory.w32(queue + 0x2cu, memory.r32(queue + 0x2cu) + 1u);
}

void append_utf16_strings(Memory& memory, Heap& heap, Packet& packet,
                          U& cursor) {
    for (const U global : kStringGlobals) {
        const U source = memory.r32(global);
        need(source != 0u, "B1675 nonnull UTF16 string pointer");
        for (const U sentinel_global : kSentinelGlobals)
            need(source != memory.r32(sentinel_global),
                 "B1675 ordinary B899 non-sentinel pointer");

        std::array<std::uint16_t, 6> code_units{};
        U length = 0;
        bool terminated = false;
        for (U n = 0; n <= 6u; ++n) {
            const auto value = static_cast<std::uint16_t>(memory.r16(source + 2u * n));
            if (value == 0u) {
                length = n;
                terminated = true;
                break;
            }
            need(n < code_units.size(), "B1675 UTF16 terminator within six units");
            code_units[n] = value;
        }
        need(terminated && length >= 4u && length <= 6u,
             "B1675 finite UTF16 length4to6");

        const U request = 2u * (length + 1u);
        const U temporary = heap.allocate(request);
        need(temporary != 0u && (request == 10u || request == 12u || request == 14u),
             "B1675 actual owned CRT temporary allocation");
        for (U n = 0; n < length; ++n) {
            heap.w8(temporary + 2u * n, code_units[n]);
            heap.w8(temporary + 2u * n + 1u, code_units[n] >> 8u);
        }
        heap.w8(temporary + 2u * length, 0u);
        heap.w8(temporary + 2u * length + 1u, 0u);

        // Read the actual allocated bytes through Heap; preserve the original
        // helper's cursor-at-NUL behavior without fabricating a guest stack VA.
        U offset = 0;
        for (;;) {
            const U low = heap.r8(temporary + offset);
            const U high = heap.r8(temporary + offset + 1u);
            need(cursor + 2u <= packet.size(), "B1675 packet capacity");
            packet[cursor++] = static_cast<Byte>(low);
            packet[cursor++] = static_cast<Byte>(high);
            offset += 2u;
            if (low == 0u && high == 0u) {
                cursor -= 2u; // next append replaces this WCHAR NUL
                break;
            }
        }
        need(cursor + 4u <= packet.size(), "B1675 comma/NUL packet capacity");
        packet[cursor++] = 0x2cu;
        packet[cursor++] = 0u;
        packet[cursor] = 0u;
        packet[cursor + 1u] = 0u; // cursor remains at the terminator

        // The original helper does not inspect HeapFree's EAX. Subsequent
        // operations kill it, and the final observable EAX comes from 821e0.
        (void)heap.release(temporary);
    }
}
}

std::uint32_t fun_005b6f00(Memory& memory, const Inputs& inputs, Heap& heap) {
    need(memory.r32(0x00a255c8u) == 1u &&
         (memory.r8(0x00a27decu) & 1u) == 0u &&
         memory.r32(0x00a27db8u) == 2u,
         "B1675 finite mode1/flag-clear/two-peer domain");

    Packet packet{};
    put32(packet, 0u, 22u);
    ascii_with_nul(memory, 0x00a256d0u, packet, 4u, 1u, 12u);
    U cursor = 47u;
    append_utf16_strings(memory, heap, packet, cursor);
    need(cursor + 2u <= packet.size(), "B1675 final packet terminator");

    const U peer_array = memory.r32(0x00a27dacu);
    need(peer_array != 0u, "B1675 peer array");
    const U peer = memory.r32(peer_array + 4u); // selected peer entry1
    need(peer != 0u, "B1675 selected peer1");
    enqueue_one(memory, packet, peer);

    // Retain the unchanged B1627 positive coordinator result as full EAX.
    const U result = b1627::fun_004821e0(memory, inputs);
    return result;
}
}
