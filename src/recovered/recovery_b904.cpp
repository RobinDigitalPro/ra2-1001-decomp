#include "recovered/recovery_b904.hpp"

#include <stdexcept>
#include <string>

namespace ra2::recovered::recovery_b904 {
namespace {
using U = std::uint32_t;
constexpr U kRecordCount = 0x00b0fc00u;
constexpr U kRecords = 0x00b0fc08u;
constexpr U kHolder = 0x00b0e5f0u;
constexpr U kTargetCount = 0x00b0ee60u;
constexpr U kTargetCapacity = 0x00b0ee64u;
constexpr U kTargetArray = 0x00b0ee68u;

std::string read_text(const Memory& m, U address) {
    if (!address) throw std::domain_error("B904 null string is outside the fixture route");
    std::string result;
    for (U n = 0; n < 7u; ++n) {
        const U c = m.r8(address + n);
        if (!c) {
            if (result.empty()) throw std::domain_error("B904 empty text is outside the fixture route");
            return result;
        }
        result.push_back(static_cast<char>(c));
    }
    throw std::domain_error("B904 text exceeds six characters");
}

bool equal_ascii_folded(const std::string& a, const std::string& b) {
    if (a.size() != b.size()) return false;
    for (std::size_t n = 0; n < a.size(); ++n) {
        auto fold = [](unsigned char c) {
            return c >= 'A' && c <= 'Z' ? static_cast<unsigned char>(c + ('a' - 'A')) : c;
        };
        if (fold(static_cast<unsigned char>(a[n])) != fold(static_cast<unsigned char>(b[n])))
            return false;
    }
    return true;
}

void allocate_text(Heap& heap, U destination, const std::string& text) {
    for (U n = 0; n < text.size(); ++n)
        heap.w8(destination + n, static_cast<unsigned char>(text[n]));
    heap.w8(destination + static_cast<U>(text.size()), 0u);
}
}

U fun_007486b0(Memory& memory, const Inputs&, Heap& heap) {
    const U record_count = memory.r32(kRecordCount);
    const U records = memory.r32(kRecords);
    const U holder_pointer = memory.r32(kHolder);
    const U holder = holder_pointer ? holder_pointer : 0x008248a4u;
    const std::string holder_text = read_text(memory, holder);
    U count = memory.r32(kTargetCount);
    const U capacity = memory.r32(kTargetCapacity);
    const U array = memory.r32(kTargetArray);
    if (!records || !array || record_count < 1u || record_count > 3u ||
        count > 1u || capacity != 8u || count + record_count > capacity)
        throw std::domain_error("B904 state outside the non-resizing append route");

    for (U index = 0; index < record_count; ++index) {
        const U record = records + index * 0x6cu;
        if (memory.r8(record) & 1u)
            throw std::domain_error("B904 flagged-record logging route is outside the fixture");
        const std::string name = read_text(memory, record + 0x24u);
        if (equal_ascii_folded(holder_text, name))
            throw std::domain_error("B904 holder-equal skip route is outside the fixture");

        // Original 0x759260 makes the temporary copy. 0x7592C0 then makes
        // the independent string installed in the next pointer-array cell.
        const U temporary = heap.allocate(static_cast<U>(name.size() + 1u));
        if (!temporary) throw std::domain_error("B904 temporary allocation failed");
        allocate_text(heap, temporary, name);
        const U installed = heap.allocate(static_cast<U>(name.size() + 1u));
        if (!installed) throw std::domain_error("B904 installed-string allocation failed");
        allocate_text(heap, installed, name);
        memory.w32(array + count * 4u, installed);
        ++count;
        memory.w32(kTargetCount, count);

        // 0x759320 -> 0x76D67B -> 0x76DF28 returns the real HeapFree BOOL.
        if (!heap.release(temporary))
            throw std::domain_error("B904 original temporary-string release failed");
    }

    // The final loop tail reloads B0FC00 after the last destructor call.
    return memory.r32(kRecordCount);
}
}
