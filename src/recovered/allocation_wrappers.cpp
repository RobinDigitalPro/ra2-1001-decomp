#include "allocation_wrappers.hpp"

#include <stdexcept>

namespace ra2::recovered {

std::uint32_t fun_0076d957(std::uint32_t size, const AllocationWrapperOperations& operations) {
    if (!operations.allocate) {
        throw std::invalid_argument("allocation wrapper requires an allocation callback");
    }
    return operations.allocate(size, 1u, operations.context);
}

std::uint32_t fun_0076d67b(std::uint32_t pointer, const AllocationWrapperOperations& operations) {
    if (!operations.release) {
        throw std::invalid_argument("release wrapper requires a release callback");
    }
    return operations.release(pointer, operations.context);
}

} // namespace ra2::recovered
