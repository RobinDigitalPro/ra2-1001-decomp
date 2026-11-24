#include "recovery_b324.hpp"

#include "recovered/scanner_input.hpp"
#include "recovered/name_hash.hpp"

#include <array>
#include <cstring>
#include <stdexcept>
#include <string>

namespace ra2::recovered::recovery_b324 {
namespace {
void need(bool ok, const char* message) {
    if (!ok) throw std::domain_error(message);
}

std::array<std::uint8_t, 16> decimal_triplet(const std::array<std::uint8_t, 3>& value) {
    std::array<std::uint8_t, 16> text{};
    std::size_t at = 0;
    for (unsigned field = 0; field != 3; ++field) {
        const auto number = static_cast<unsigned>(value[field]);
        if (field) text[at++] = ',';
        if (number >= 100) text[at++] = static_cast<std::uint8_t>('0' + number / 100);
        if (number >= 10) text[at++] = static_cast<std::uint8_t>('0' + (number / 10) % 10);
        text[at++] = static_cast<std::uint8_t>('0' + number % 10);
    }
    text[at] = 0;
    return text;
}
std::array<std::uint8_t, 128> copy_guest_text(const Memory& memory, std::uint32_t address) {
    std::array<std::uint8_t, 128> out{};
    need(address != 0, "B324 guest text pointer is null");
    for (std::uint32_t n = 0; n != out.size(); ++n) {
        out[n] = static_cast<std::uint8_t>(memory.r8(address + n));
        if (!out[n]) return out;
    }
    throw std::domain_error("B324 guest name exceeds the bounded fixture name size");
}
std::int32_t signed_hash(std::uint32_t hash) {
    return hash <= 0x7fffffffu ? static_cast<std::int32_t>(hash)
        : -1 - static_cast<std::int32_t>(0xffffffffu - hash);
}
void require_positive_triplet(const std::uint8_t* text) {
    for (unsigned field = 0; field != 3; ++field) {
        need(text[0] >= '0' && text[0] <= '9',
             "B324 selected positive text must begin each field with an ASCII digit");
        unsigned value = 0;
        unsigned digits = 0;
        while (text[0] >= '0' && text[0] <= '9') {
            value = value * 10u + static_cast<unsigned>(text[0] - '0');
            ++digits;
            need(digits <= 3u && value <= 255u,
                 "B324 selected positive decimal fields must be in the byte range");
            ++text;
        }
        need(digits != 0, "B324 selected positive text requires three nonempty fields");
        if (field != 2) {
            need(text[0] == ',', "B324 selected positive fields require literal commas");
            ++text;
        }
    }
    need(text[0] == 0, "B324 selected positive text must end after exactly three fields");
}
}

void IndexProjection::flush(Memory& memory) const {
    need(guest_index && guest_nodes && logical && entries && logical->entries == entries &&
         logical->count == static_cast<std::int32_t>(count) && logical->sorted == 1,
         "B324 requires a fixed, sorted raw INI index projection");
    std::uint32_t cache = 0;
    if (logical->cached) {
        bool found = false;
        for (std::uint32_t n = 0; n != count; ++n) {
            if (logical->cached == entries + n) {
                cache = guest_nodes + 8u * n;
                found = true;
                break;
            }
        }
        need(found, "B324 cache node escaped its raw sorted index");
    }
    memory.w32(guest_index + 16u, cache);
}

std::uint32_t rva_00069c30(Memory& memory, const Inputs& input, IniIndex& ini_graph,
    const IndexProjection& section_index, const IndexProjection& key_index,
    const IniOperations& ini_ops, const CrtClassification& classification) {
    constexpr std::uint32_t format_va = 0x007ba2f0u;
    constexpr std::uint8_t scan_format[] = "%d,%d,%d";
    const auto receiver = input.cx;
    const auto output = input.arg[0];
    const auto section = input.arg[1];
    const auto key = input.arg[2];
    const auto source = input.arg[3];
    need(receiver && output && section && key && source,
         "B324 requires the four observed nonnull stack arguments");
    need(section_index.guest_index == receiver + 0x20u &&
         section_index.logical == &ini_graph && section_index.count == 1 &&
         key_index.count == 1 && key_index.logical,
         "B324 requires one sorted section and its one-key sorted index");
    const auto section_text = copy_guest_text(memory, section);
    const auto key_text = copy_guest_text(memory, key);
    need(std::strcmp(reinterpret_cast<const char*>(key_text.data()), "RadialColor") == 0,
         "B324 finite fixture uses the pinned caller key RadialColor");
    need(memory.r8(format_va) == '%' && memory.r8(format_va + 1u) == 'd' &&
         memory.r8(format_va + 2u) == ',' && memory.r8(format_va + 3u) == '%' &&
         memory.r8(format_va + 4u) == 'd' && memory.r8(format_va + 5u) == ',' &&
         memory.r8(format_va + 6u) == '%' && memory.r8(format_va + 7u) == 'd' &&
         memory.r8(format_va + 8u) == 0,
         "B324 requires the original three-decimal-field format literal");

    const std::array<std::uint8_t, 3> original{
        static_cast<std::uint8_t>(memory.r8(source)),
        static_cast<std::uint8_t>(memory.r8(source + 1u)),
        static_cast<std::uint8_t>(memory.r8(source + 2u))};
    const auto fallback = decimal_triplet(original);
    std::array<std::uint8_t, 64> selected{};
    const auto found_length = fun_0050ddf0(&ini_graph,
        section_text.data(), key_text.data(), fallback.data(), selected.data(),
        static_cast<std::int32_t>(selected.size()), ini_ops);
    section_index.flush(memory);
    key_index.flush(memory);

    std::array<std::uint8_t, 3> result = original;
    if (found_length != 0) {
        require_positive_triplet(selected.data());
        std::uint32_t fields[3]{};
        DecimalFieldOutputs outputs{{&fields[0], &fields[1], &fields[2], nullptr}};
        GetterDecimalContext decimal{&classification};
        const auto assigned = fun_0076f070(selected.data(), scan_format, &outputs,
            scan_getter_decimal_callback, &decimal);
        need(assigned == 3, "B324 selected positive fixture must assign all three decimal fields");
        for (unsigned n = 0; n != 3; ++n) {
            need(fields[n] <= 255u,
                 "B324 finite selected values are limited to byte-valued decimal fields");
            result[n] = static_cast<std::uint8_t>(fields[n]);
        }
    }
    for (unsigned n = 0; n != 3; ++n) memory.w8(output + n, result[n]);
    return output;
}

std::uint32_t fun_00469c30(Memory& memory, const Inputs& input,
    const IniOperations& ini_ops) {
    constexpr std::uint32_t max_text = 64u;
    constexpr std::uint32_t crt_width_va = 0x0081776cu;
    constexpr std::uint32_t crt_table_pointer_va = 0x00817560u;
    const auto receiver = input.cx;
    const auto section_arg = input.arg[1];
    const auto key_arg = input.arg[2];
    need(receiver && section_arg && key_arg,
         "B324 raw adapter requires the observed receiver, section, and key arguments");
    need(ini_ops.hash_name != nullptr && ini_ops.sort_nodes != nullptr,
         "B324 raw adapter requires accepted INI hash and sorted-index operations");

    const auto root_index = receiver + 0x20u;
    const auto root_nodes = memory.r32(root_index);
    const auto root_count = memory.r32(root_index + 4u);
    need(root_nodes && root_count == 1u && memory.r8(root_index + 12u) == 1u,
         "B324 raw route requires exactly one already-sorted section node");
    need(memory.r32(root_index + 8u) >= root_count,
         "B324 raw section index capacity must cover its one node");
    need(memory.r32(root_index + 16u) == 0,
         "B324 raw route requires a null initial section cache");
    const auto section_object = memory.r32(root_nodes + 4u);
    need(section_object != 0, "B324 raw section node requires a section object");

    const auto raw_key_index = section_object + 0x2cu;
    const auto key_nodes = memory.r32(raw_key_index);
    const auto key_count = memory.r32(raw_key_index + 4u);
    need(key_nodes && key_count == 1u && memory.r8(raw_key_index + 12u) == 1u,
         "B324 raw route requires exactly one already-sorted key node");
    need(memory.r32(raw_key_index + 8u) >= key_count,
         "B324 raw key index capacity must cover its one node");
    need(memory.r32(raw_key_index + 16u) == 0,
         "B324 raw route requires a null initial key cache");
    const auto raw_value = memory.r32(key_nodes + 4u);
    need(raw_value != 0, "B324 raw key node requires a value object");
    const auto raw_text = memory.r32(raw_value + 0x10u);
    need(raw_text != 0, "B324 raw INI value requires nonnull text");

    const auto section_text = copy_guest_text(memory, section_arg);
    const auto key_text = copy_guest_text(memory, key_arg);
    const auto section_length = std::char_traits<char>::length(
        reinterpret_cast<const char*>(section_text.data()));
    const auto key_length = std::char_traits<char>::length(
        reinterpret_cast<const char*>(key_text.data()));
    const auto section_hash = signed_hash(ini_ops.hash_name(
        section_text.data(), section_length, ini_ops.context));
    const auto key_hash = signed_hash(ini_ops.hash_name(
        key_text.data(), key_length, ini_ops.context));
    need(static_cast<std::int32_t>(memory.r32(root_nodes)) == section_hash,
         "B324 raw section node hash must match the actual section argument");
    need(static_cast<std::int32_t>(memory.r32(key_nodes)) == key_hash,
         "B324 raw key node hash must match the actual key argument");

    IniValue value{};
    std::array<std::uint8_t, max_text> value_text{};
    std::uint32_t text_length = 0;
    for (; text_length != max_text; ++text_length) {
        value_text[text_length] = static_cast<std::uint8_t>(memory.r8(raw_text + text_length));
        if (value_text[text_length] == 0) break;
    }
    need(text_length != max_text,
         "B324 positive INI value must fit the observed 64-byte local buffer");
    value.text = value_text.data();
    IniIndexEntry key_node{key_hash, &value};
    IniSection section{};
    section.keys = {&key_node, 1, 1, nullptr, 1};
    IniIndexEntry section_node{section_hash, &section};
    IniIndex graph{&section_node, 1, 1, nullptr, 1};
    const IndexProjection root_projection{root_index, root_nodes, &graph, &section_node, 1};
    const IndexProjection key_projection{raw_key_index, key_nodes, &section.keys, &key_node, 1};

    need(memory.r32(crt_width_va) == 1u,
         "B324 selected native scanner route requires initialized single-byte CRT classification");
    const auto crt_table = memory.r32(crt_table_pointer_va);
    need(crt_table >= 2u, "B324 initialized CRT table pointer must include its EOF entry");
    std::array<std::uint16_t, 257> crt_flags{};
    for (std::int32_t input_byte = -1; input_byte <= 255; ++input_byte) {
        const auto address = static_cast<std::uint32_t>(
            static_cast<std::int64_t>(crt_table) + std::int64_t(input_byte) * 2);
        crt_flags[static_cast<std::size_t>(input_byte + 1)] =
            static_cast<std::uint16_t>(memory.r8(address));
    }
    const CrtClassification classification{1, crt_flags.data(), nullptr, nullptr};
    return rva_00069c30(memory, input, graph, root_projection, key_projection,
                        ini_ops, classification);
}
}
