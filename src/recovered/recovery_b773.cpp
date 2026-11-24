#include "recovered/recovery_b773.hpp"

#include "recovered/name_hash.hpp"
#include "recovered/text_bytes.hpp"
#include "recovered/text_trim.hpp"

#include <stdexcept>
#include <vector>

namespace ra2::heap773_draft {
namespace {
using U = std::uint32_t;
using namespace ra2::recovered;

[[noreturn]] void reject(const char* why) { throw std::domain_error(why); }
void need(bool ok, const char* why) { if (!ok) reject(why); }

std::vector<std::uint8_t> guest_z(const Memory& m, U p, U limit = 0x400u) {
    need(p != 0, "B773 positive path requires nonnull string pointers");
    std::vector<std::uint8_t> bytes;
    bytes.reserve(32);
    for (U n = 0; n < limit; ++n) {
        const auto ch = static_cast<std::uint8_t>(m.r8(p + n));
        bytes.push_back(ch);
        if (!ch) return bytes;
    }
    reject("B773 input text exceeded its bounded NUL search");
}

U hash_name(const std::vector<std::uint8_t>& z) {
    need(!z.empty() && z.back() == 0, "B773 name is not NUL terminated");
    return ini_name_hash(z.data(), z.size() - 1u, nullptr);
}
} // namespace

U fun_0050df90(Memory& memory, Inputs& input, Heap& heap) {
    const U receiver = input.cx;
    const U section_holder = input.arg[0];
    const U key_holder = input.arg[1];
    const U third_holder = input.arg[2];
    const U destination = input.arg[3];
    need(receiver && section_holder && key_holder && third_holder && destination,
         "B773 positive route needs all four nonnull root inputs");
    need(memory.r32(destination) == 0,
         "B773 finite route requires the initialized empty destination object");

    const U section_name_ptr = memory.r32(section_holder);
    const U key_name_ptr = memory.r32(key_holder);
    const U third_name_ptr = memory.r32(third_holder);
    need(section_name_ptr && key_name_ptr && third_name_ptr,
         "B773 75a070 holders return three nonnull contained string pointers");
    const auto section_name = guest_z(memory, section_name_ptr, 64u);
    const auto key_name = guest_z(memory, key_name_ptr, 64u);
    // The third 75a070 result is tested for null, but its pointed-to string is
    // not dereferenced on this positive route.
    const U section_hash = hash_name(section_name);
    const U key_hash = hash_name(key_name);

    const U section_index_address = receiver + 0x20u;
    const U section_rows = memory.r32(section_index_address);
    const U section_count = memory.r32(section_index_address + 4u);
    const U section_cache = memory.r32(section_index_address + 0x10u);
    need(section_count == 1u && section_rows != 0 && memory.r8(section_index_address + 0xcu) == 1u &&
         section_cache == section_rows,
         "B773 bounded projection requires a populated one-row warm section index");
    need(memory.r32(section_rows) == section_hash,
         "B773 section hash does not match the initialized row");
    const U section_object = memory.r32(section_rows + 4u);
    need(section_object != 0, "B773 section row has no real section object");

    const U key_index_address = section_object + 0x2cu;
    const U key_rows = memory.r32(key_index_address);
    const U key_count = memory.r32(key_index_address + 4u);
    const U key_cache = memory.r32(key_index_address + 0x10u);
    need(key_count == 1u && key_rows != 0 && memory.r8(key_index_address + 0xcu) == 1u &&
         key_cache == key_rows,
         "B773 bounded projection requires a populated one-row warm key index");
    need(memory.r32(key_rows) == key_hash,
         "B773 key hash does not match the initialized cached row");
    const U value_object = memory.r32(key_rows + 4u);
    need(value_object != 0u, "B773 key row does not reference a real value object");

    auto source = guest_z(memory, memory.r32(value_object + 0x10u), 0x4000u);
    std::array<std::uint8_t, 0x3ff> local_text{};
    fun_0076dd10(local_text.data(), source.data(), 0x3ffu);
    local_text[0x3feu] = 0u; // Root's explicit terminator after the bounded copy.
    local_text[0x3fe]=0; // Original forced terminator50E102.
    fun_006e41d0(local_text.data());
    U length = 0u;
    while (local_text[length] != 0u) ++length;
    need(length == 10u, "B773 fixture is bounded to ten-byte trimmed output");

    // RVA 0x359500: with a null destination pointer, skip 0x36d67b, scan the
    // ten trimmed bytes plus NUL, call 0x36d957 with request 11, publish the
    // pointer, NUL-initialize the destination, then copy all 11 bytes.
    memory.w32(destination, 0u);
    const U allocation = heap.allocate(length + 1u);
    need(allocation != 0u, "B773 requires a successful request-11 allocation");
    memory.w32(destination, allocation);
    heap.w8(allocation, 0u);
    for (U n = 0; n <= length; ++n)
        heap.w8(allocation + n, n == length ? 0u : local_text[n]);
    input.ax = length; // 0x50e131 restores EBX (the trimmed length) into EAX.
    const U output = memory.r32(destination);
    need(output != 0u, "B773 assignment did not publish an allocated string");
    for (U n = 0; n < length; ++n)
        need(heap.r8(output + n) == local_text[n], "B773 assignment bytes differ from trimmed text");
    need(heap.r8(output + length) == 0u, "B773 assignment omitted the trailing NUL");
    return length;
}

} // namespace ra2::heap773_draft
