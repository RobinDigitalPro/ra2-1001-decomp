#include "recovered/recovery_b1703.hpp"
#include "platform/ordinary_heap_win32.hpp"

#include <algorithm>
#include <stdexcept>

namespace ra2::recovered::recovery_b1703::helpers {
namespace {
constexpr U kHouseTable = 0x00a1a5ccu;
constexpr U kManager = 0x00a285c8u;
constexpr U kDebug = 0x00a2895cu;
constexpr U kFrame = 0x00a2896cu;
constexpr U kSession = 0x00a255c8u;
constexpr U kEventCount = 0x00a27db8u;
constexpr U kActiveCounter = 0x00a2588cu;
constexpr U kEntryVptr = 0x0078f644u;
constexpr U kEntryCount = 3u;
constexpr U kEntryBytes = 1024u;

void require(bool condition, const char* message) {
    if (!condition) throw std::domain_error(message);
}


} // namespace

void require_selected_basis(const Memory& memory, const State& state,
                            const Frame& frame, Heap& heap) {
    try {
        // This helper is a read-only preflight for the selected Root entry state.
        // It does not construct or normalize any private/global object.
        require(state.cx == 1u && state.dx == 2u,
                "1B6760 basis requires House index 1 and mode 2");
        require(frame.sp == frame.entry_sp,
                "1B6760 basis requires the untouched entry stack pointer");

        const U house_table = memory.r32(kHouseTable);
        require(house_table != 0u, "1B6760 basis requires a nonnull House pointer table");
        const U house = memory.r32(house_table + state.cx * 4u);
        require(house != 0u, "1B6760 basis requires a nonnull selected House");
        require(memory.r8(house + 0x134u) == 1u &&
                memory.r8(house + 0x13eu) == 0u &&
                memory.r8(house + 0x13fu) == 0u &&
                memory.r8(house + 0x140u) == 0u,
                "1B6760 basis House public flags outside finite domain");

        require(memory.r8(kDebug) == 0u && memory.r32(kFrame) == 0u &&
                memory.r32(kSession) != 4u && memory.r32(kEventCount) == 0u &&
                memory.r32(kActiveCounter) == 3u,
                "1B6760 basis public globals outside finite mode2/frame0 route");

        require(memory.r8(kManager + 4u) == 1u &&
                memory.r32(kManager + 0x44u) == kEntryCount &&
                memory.r32(kManager + 0x54u) == 2u,
                "1B6760 basis manager is not enabled count3 current2");

        auto* concrete = dynamic_cast<const ra2::platform::ordinary_heap::HeapAdapter*>(&heap);
        require(concrete != nullptr,
                "1B6760 basis requires the supported ordinary HeapAdapter provider");
        const auto blocks = concrete->live();
        for (U index = 0; index < kEntryCount; ++index) {
            const U slot = kManager + 0x28u + index * 4u;
            const U entry = memory.r32(slot);
            require(entry != 0u, "1B6760 basis excludes null manager entries");
            for (U previous = 0; previous < index; ++previous)
                require(entry != memory.r32(kManager + 0x28u + previous * 4u),
                        "1B6760 basis requires distinct manager entries");

            const auto identity = concrete->identify(entry, kEntryBytes);
            require(identity.offset == 0u,
                    "1B6760 basis requires manager entries at owned allocation bases");
            const auto owner = std::find_if(blocks.begin(), blocks.end(), [&](const auto& block) {
                return block.address == entry && block.bytes == kEntryBytes &&
                       block.ordinal == identity.ordinal;
            });
            require(owner != blocks.end(),
                    "1B6760 basis requires three live owned 1024-byte manager entries");
            require(concrete->r32(entry) == kEntryVptr &&
                    concrete->r32(entry + 4u) == 0u &&
                    concrete->r32(entry + 0x20u) == 0u &&
                    concrete->r32(entry + 0x60u) == index,
                    "1B6760 basis entry vptr/nested fields/index ID outside finite B843 domain");
        }
    } catch (const std::domain_error&) {
        throw;
    } catch (const std::exception&) {
        throw std::domain_error("1B6760 selected basis is unsupported or not fully mapped/owned");
    }
}
} // namespace ra2::recovered::recovery_b1703::helpers



