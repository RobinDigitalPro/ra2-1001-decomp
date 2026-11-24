#include "recovery_b920.hpp"
#include "recovered/allocation_wrappers.hpp"
#include "recovered/construct_b102.hpp"
#include "recovered/preallocated_b66.hpp"
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b920 {
namespace {
struct AllocationContext { ra2::platform::ordinary_heap::Heap* heap; };
std::uint32_t allocate(std::uint32_t size, std::uint32_t flag, void* raw) {
    auto& context = *static_cast<AllocationContext*>(raw);
    if (flag != 1u) throw std::domain_error("B920 wrapper flag outside observed contract");
    return context.heap->allocate(size);
}
}

std::uint32_t fun_006b42d0(Memory& memory, const Inputs& input,
                           ra2::platform::ordinary_heap::Heap& heap,
                           std::vector<std::unique_ptr<leaf::Memory>>& live_spans) {
    const std::uint32_t owner = input.cx;
    std::uint32_t selected = input.arg[0];
    if (selected == 0u) selected = memory.r32(owner + 0xc0u);

    // This candidate implements the observed positive allocation route only.
    // The other branch calls a separate unresolved limit/lookup path.
    if (memory.r32(0x00a283c4u) == 0u)
        throw std::domain_error("B920 limit-gate branch is outside this finite contract");

    AllocationContext context{&heap};
    const ra2::recovered::AllocationWrapperOperations operations{&allocate, nullptr, &context};
    const std::uint32_t object = ra2::recovered::fun_0076d957(0x9cu, operations);
    if (object == 0u) return 0u;

    // Model exactly the accepted structural 0x6aca80 finite branch. The
    // original constructor executes natively in the differential bridge.
    ra2::recovered::construct_b102::Inputs constructor{};
    constructor.cx = object;
    constructor.arg[0] = 0; // accepted constructor prefix; owner-positive extension below
    constructor.arg[1] = selected;
    constructor.arg[2] = 0u;
    live_spans.emplace_back(std::make_unique<leaf::Memory>(
        reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(object)), object, 0xa0u));
    memory.add(*live_spans.back());
    (void)ra2::recovered::construct_b102::fun_006aca80(memory, constructor);
    memory.w32(object+0x24,owner);
    if(memory.r8(owner+0xee)||memory.r32(owner+0xcc)!=0xffffffffu||memory.r32(0xaa7bd0)!=memory.r32(0xaa7b58)||memory.r32(owner+0xc8))throw std::domain_error("920 owner-positive finite route");
    memory.w32(owner+0xd4,memory.r32(owner+0xd4)+1);
    const auto child=heap.allocate(0x30);if(!child)throw std::domain_error("920 successful child allocation");
    live_spans.emplace_back(std::make_unique<leaf::Memory>(reinterpret_cast<std::uint8_t*>(std::uintptr_t(child)),child,0x30));memory.add(*live_spans.back());
    global_b26::Inputs child_in{};child_in.cx=child;child_in.arg[0]=memory.r32(owner+0xd8);(void)global_b26::fun_0065f6e0(memory,child_in);memory.w32(object+0x28,child);
    return object;
}
}
