#include "recovered/recovery_b1478.hpp"

#include "platform/ole_stream951.hpp"

#include <array>
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::b1478 {
namespace {
using U = std::uint32_t;

constexpr U kPairData = 0x00aa7a60u;
constexpr U kPairCount = 0x00aa7a64u;
constexpr U kPairCapacity = 0x00aa7a68u;
constexpr U kPairSorted = 0x00aa7a6cu;
constexpr U kPairHint = 0x00aa7a70u;

constexpr U kIdVectorData = 0x00aa5390u;
constexpr U kIdVectorCapacity = 0x00aa5394u;
constexpr U kIdVectorCount = 0x00aa539cu;

void need(bool condition, const char* message) {
    if (!condition) throw std::domain_error(message);
}

U original_serialized_size(Memory& memory, U self) {
    // Original primary slot 0x30 is 0x006D9DB0, which returns 0xC8.
    const U primary = memory.r32(self);
    need(primary == 0x798274u, "1478 selected primary vptr");
    need(memory.r32(primary + 0x30u) == 0x006d9db0u,
         "1478 original primary +0x30 size getter");
    return 0xc8u;
}

U original_serialized_id(Memory& memory, U self) {
    // Original secondary slot 0x10 is 0x0040FFC0; it reads [self+0x10].
    const U secondary = memory.r32(self + 4u);
    need(secondary == 0x798248u, "1478 selected secondary vptr");
    need(memory.r32(secondary + 0x10u) == 0x0040ffc0u,
         "1478 original secondary +0x10 ID getter");
    return memory.r32(self + 0x10u);
}

void append_serialized_id(Memory& memory, U serialized_id, U self) {
    const U count = memory.r32(kIdVectorCount);
    const U capacity = memory.r32(kIdVectorCapacity);
    const U data = memory.r32(kIdVectorData);
    need(count <= 3u && capacity == 64u && count < capacity && data != 0u,
         "1478 bounded preallocated ID registry");

    const U row = data + count * 8u;
    memory.w32(kIdVectorCount, count + 1u);
    memory.w32(row, serialized_id);
    memory.w32(row + 4u, self);
}

void initialize_embedded_vector(Memory& memory, U address) {
    // Exact stores from the reached 0x00405BF0 initializer.
    memory.w32(address + 12u, 0x008192ecu);
    memory.w32(address, 0u);
    memory.w32(address + 4u, 0u);
    memory.w32(address + 8u, 0u);
}

void remove_single_pair(Memory& memory, U old_id, U self) {
    const U data = memory.r32(kPairData);
    const U count = memory.r32(kPairCount);
    const U capacity = memory.r32(kPairCapacity);
    const U sorted = memory.r8(kPairSorted);
    need(data != 0u && count == 1u && capacity == 10u && sorted == 0u,
         "1478 one-row unsorted pair registry");
    need(memory.r32(data) == old_id && memory.r32(data + 4u) == self,
         "1478 exact old pair row");

    // 0x006D9830's qsort count-one path performs no comparator calls.
    memory.w32(kPairHint, 0u);
    memory.w8(kPairSorted, 1u);

    // The following bsearch finds row zero; count-one removal does no memmove.
    memory.w32(kPairCount, 0u);
    memory.w32(data, 0u);
    memory.w32(data + 4u, 0u);
    memory.w32(kPairHint, 0u);
}

void append_single_pair(Memory& memory, U new_id, U self) {
    const U data = memory.r32(kPairData);
    const U count = memory.r32(kPairCount);
    const U capacity = memory.r32(kPairCapacity);
    need(data != 0u && count == 0u && capacity == 10u,
         "1478 pair registry has one spare slot after removal");

    memory.w32(data, new_id);
    memory.w32(data + 4u, self);
    memory.w8(kPairSorted, 0u);
    memory.w32(kPairCount, 1u);
}

void install_base_and_derived_vptrs(Memory& memory, U self) {
    // 0x005CAB90 / 0x0040FF60 base no-init sequence, followed by the
    // four derived overrides in 0x006D9830. These are the route's exact final
    // object words; no base constructor or object factory is claimed.
    memory.w32(self + 8u, 0x785e44u);
    memory.w32(self + 12u, 0x785e3cu);
    memory.w32(self, 0x785dd8u);
    memory.w32(self + 4u, 0x785dbcu);
    memory.w32(self + 8u, 0x785db4u);
    memory.w32(self + 12u, 0x785dacu);

    memory.w32(self, 0x792458u);
    memory.w32(self + 4u, 0x79243cu);
    memory.w32(self + 8u, 0x792434u);
    memory.w32(self + 12u, 0x79242cu);

    memory.w32(self, 0x798274u);
    memory.w32(self + 4u, 0x798248u);
    memory.w32(self + 8u, 0x79826cu);
    memory.w32(self + 12u, 0x798264u);
}

} // namespace

U fun_006d9830(Memory& memory, const Inputs& inputs) {
    const U self = inputs.arg[0];
    const U stream_address = inputs.arg[1];
    auto& stream_fixture = ra2::platform::ole_stream951::Stream::current();
    need(self != 0u && stream_address == stream_fixture.address(),
         "1478 actual current IStream and receiver");

    const U old_id = original_serialized_id(memory, self);
    need(old_id == 0xffffffffu, "1478 selected old object ID");
    remove_single_pair(memory, old_id, self);

    auto* stream = reinterpret_cast<IStream*>(static_cast<std::uintptr_t>(stream_address));
    U source_address = 0u;
    need(stream->Read(&source_address, 4u, nullptr) == S_OK,
         "1478 actual IStream Read of serialized source address");
    need(source_address != 0u && source_address != 0xffffffffu && source_address != self,
         "1478 source address distinct from payload object ID");
    append_serialized_id(memory, source_address, self);

    const U old_1c = memory.r32(self + 0x1cu);
    const U bytes_to_read = original_serialized_size(memory, self);
    need(bytes_to_read == 0xc8u, "1478 exact positive 200-byte stream image");

    std::array<std::uint8_t, 0xc8> image{};
    need(stream->Read(image.data(), static_cast<ULONG>(image.size()), nullptr) == S_OK,
         "1478 actual IStream Read of 200-byte object image");
    for (U offset = 0; offset < image.size(); ++offset)
        memory.w8(self + offset, image[offset]);
    memory.w32(self + 0x1cu, old_1c);

    // The four base fixups occur in this exact order; +B0 is later.
    for (U offset : {0x30u, 0x34u, 0x38u, 0x18u})
        need(memory.r32(self + offset) == 0u,
             "1478 selected null pointer-fixup slot");

    initialize_embedded_vector(memory, self + 0x3cu);
    initialize_embedded_vector(memory, self + 0x50u);
    memory.w32(self + 0x94u, 0u);

    install_base_and_derived_vptrs(memory, self);

    const U new_id = original_serialized_id(memory, self);
    need(new_id == 0xffffffffu, "1478 selected loaded object ID");
    append_single_pair(memory, new_id, self);

    // 0x006D9830 calls 0x00695170 for self+0xB0. Its actual zero-pointer
    // branch is a no-op; nonzero object registration is outside this domain.
    need(memory.r32(self + 0xb0u) == 0u,
         "1478 selected null +0xB0 registration slot");

    return 0u;
}

} // namespace ra2::recovered::b1478
