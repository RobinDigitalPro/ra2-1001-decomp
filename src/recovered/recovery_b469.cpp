#include "recovered/recovery_b469.hpp"

#include <stdexcept>

namespace ra2::recovered::recovery_b469 {
namespace {
void require(bool ok, const char* message) {
    if (!ok) throw std::domain_error(message);
}

// The positive branch of original 0x58b3a0 reached by this constructor:
// count=20, prior count=0, prior pointer=null, and the owned-buffer flag is 0.
// The first-chunk allocator supplies one real 320-byte CRT allocation. As the
// original leaves newly allocated contents untouched, this model does too.
void initialize_vector_20(Memory& m, Inputs& call, Allocator& heap) {
    const auto object = call.cx;
    const auto count = call.arg[0];
    require(count == 20u && call.arg[1] == 0u,
            "B469 only models the original count-20/null-buffer vector route");
    require(m.r32(object + 4u) == 0u && m.r32(object + 8u) == 0u &&
            m.r8(object + 0x0du) == 0u,
            "B469 vector must begin empty and non-owned");
    m.w8(object + 0x0cu, 0u);
    const auto storage = heap.allocate(count * 16u);
    require(storage != 0u, "B469 excludes original allocation failure");
    m.w8(object + 0x0cu, 1u);
    m.w32(object + 4u, storage);
    m.w32(object + 8u, count);
    m.w8(object + 0x0du, 1u);
}

void clear_empty_vector(Memory& m, std::uint32_t object) {
    require(m.r32(object + 4u) == 0u,
            "B469 clear-helper nonnull-free path is excluded");
    m.w32(object + 0x10u, 0u);
    m.w8(object + 0x0du, 0u);
    m.w32(object + 8u, 0u);
}
}

std::uint32_t fun_005af7c0(Memory& m, Inputs& in, Allocator& heap) {
    const auto self = in.cx;
    require(self != 0u, "B469 requires a nonnull constructor receiver");
    const auto first = self + 8u;
    const auto second = self + 0x18u;
    const auto third = self + 0x30u;

    // Literal stores from 0x5af7d2..0x5af819, preserving untouched padding.
    m.w32(first + 4u, 0u); m.w32(first + 8u, 0u);
    m.w8(first + 0x0cu, 1u); m.w8(first + 0x0du, 0u);
    m.w32(first, 0x790e98u);
    m.w32(second + 4u, 0u); m.w32(second + 8u, 0u);
    m.w8(second + 0x0cu, 1u); m.w8(second + 0x0du, 0u);
    m.w32(second, 0x79202cu); m.w32(second + 0x14u, 10u);
    m.w32(second + 0x10u, 0u);
    m.w32(third + 4u, 0u); m.w32(third + 8u, 0u);
    m.w8(third + 0x0cu, 1u); m.w8(third + 0x0du, 0u);
    m.w32(third, 0x79200cu); m.w32(third + 0x14u, 10u);
    m.w32(third + 0x10u, 0u);
    m.w32(self, 0x791ffcu); m.w32(self + 4u, 0u);

    require(m.r32(0x790ea0u)==0x58b3a0u&&m.r32(0x792038u)==0x5b0440u&&m.r32(0x792018u)==0x5b04a0u,"B469 original vptr target identity");
    Inputs resize{}; resize.cx = first; resize.arg[0] = 20u; resize.arg[1] = 0u;
    initialize_vector_20(m, resize, heap);

    // These correspond to the constructor's real vtable calls to 0x5b0440
    // and 0x5b04a0. Their positive null-pointer path clears byte/count fields
    // and does not invoke the actual free target.
    clear_empty_vector(m, second);
    clear_empty_vector(m, third);
    return self;
}
} // namespace ra2::recovered::recovery_b469
