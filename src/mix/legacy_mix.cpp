#include "mix/legacy_mix.hpp"

#include <array>
#include <fstream>
#include <stdexcept>

namespace ra2::mix {
namespace {

std::uint16_t u16(const unsigned char* data) {
    return static_cast<std::uint16_t>(data[0]) |
           (static_cast<std::uint16_t>(data[1]) << 8);
}

std::uint32_t u32(const unsigned char* data) {
    return static_cast<std::uint32_t>(data[0]) |
           (static_cast<std::uint32_t>(data[1]) << 8) |
           (static_cast<std::uint32_t>(data[2]) << 16) |
           (static_cast<std::uint32_t>(data[3]) << 24);
}

void read_exact(std::istream& stream, unsigned char* data, std::size_t size) {
    if (!stream.read(reinterpret_cast<char*>(data), static_cast<std::streamsize>(size))) {
        throw std::runtime_error("truncated MIX index");
    }
}

} // namespace

LegacyIndex read_legacy_index(std::istream& stream, std::uint64_t file_size) {
    std::array<unsigned char, 6> header{};
    if (file_size < header.size()) {
        throw std::runtime_error("MIX header is too short");
    }
    read_exact(stream, header.data(), header.size());

    const auto count = u16(header.data());
    if (count == 0) {
        throw std::runtime_error("extended MIX index requires separate parser");
    }
    const auto body_size = u32(header.data() + 2);
    const std::uint64_t data_offset = header.size() + std::uint64_t{count} * 12;
    if (data_offset > file_size || body_size > file_size - data_offset) {
        throw std::runtime_error("MIX index or body exceeds file size");
    }

    LegacyIndex result{body_size, data_offset, {}};
    result.entries.reserve(count);
    for (std::uint32_t i = 0; i < count; ++i) {
        std::array<unsigned char, 12> raw{};
        read_exact(stream, raw.data(), raw.size());
        Entry entry{u32(raw.data()), u32(raw.data() + 4), u32(raw.data() + 8)};
        if (entry.offset > body_size || entry.size > body_size - entry.offset) {
            throw std::runtime_error("MIX entry exceeds archive body");
        }
        result.entries.push_back(entry);
    }
    return result;
}

LegacyIndex read_legacy_index(const std::filesystem::path& path) {
    std::ifstream file(path, std::ios::binary | std::ios::ate);
    if (!file) {
        throw std::runtime_error("cannot open MIX archive");
    }
    const auto end = file.tellg();
    if (end < 0) {
        throw std::runtime_error("cannot determine MIX archive size");
    }
    file.seekg(0);
    return read_legacy_index(file, static_cast<std::uint64_t>(end));
}

} // namespace ra2::mix
