#pragma once

#include <cstdint>
#include <filesystem>
#include <istream>
#include <vector>

namespace ra2::mix {

struct Entry {
    std::uint32_t id;
    std::uint32_t offset;
    std::uint32_t size;
};

struct LegacyIndex {
    std::uint32_t body_size;
    std::uint64_t data_offset;
    std::vector<Entry> entries;
};

// Reads the unencrypted, pre-extension MIX index. Rejects unsupported formats.
LegacyIndex read_legacy_index(std::istream& stream, std::uint64_t file_size);
LegacyIndex read_legacy_index(const std::filesystem::path& path);

} // namespace ra2::mix
