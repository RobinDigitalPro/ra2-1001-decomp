#pragma once

#include <cstdint>

namespace ra2::recovered {

// Explicit guest-32 dependency seam for the wrapper bodies at RVAs 0x36d957
// and 0x36d67b. These callback types describe this portable boundary only;
// they do not assert an original CRT prototype or host calling convention.
struct AllocationWrapperOperations {
    std::uint32_t (*allocate)(std::uint32_t size, std::uint32_t flag, void* context);
    std::uint32_t (*release)(std::uint32_t pointer, void* context);
    void* context;
};

// Return the callback's full guest EAX value. The allocation wrapper passes
// the observed literal flag 1; the release wrapper forwards its pointer.
std::uint32_t fun_0076d957(std::uint32_t size, const AllocationWrapperOperations& operations);
std::uint32_t fun_0076d67b(std::uint32_t pointer, const AllocationWrapperOperations& operations);

} // namespace ra2::recovered
