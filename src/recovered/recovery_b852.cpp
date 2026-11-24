#include "recovery_b852.hpp"

#include "recovered/leaf_b15_a.hpp"
#include "recovered/leaf_b17_fields.hpp"
#include "recovered/leaf_b17_scalars.hpp"
#include "recovered/leaf_b21_a.hpp"
#include "recovered/leaf_containers.hpp"

#include <stdexcept>

namespace ra2::recovered::recovery_b852 {
namespace {
constexpr std::uint32_t traversal_limit = 64;

std::uint32_t first(Memory& m, std::uint32_t list_head) {
    leaf::Inputs i{};
    i.cx = list_head;
    return leaf::fun_004073a0(m, i);
}

void unlink(Memory& m, std::uint32_t node) {
    leaf::Inputs i{};
    i.cx = node;
    (void)leaf::fun_00407380(m, i);
}

void insert_after(Memory& m, std::uint32_t head, std::uint32_t node) {
    leaf::Inputs i{};
    i.cx = head;
    i.dx = node; // Preserve the original EDX value; 0x7460 derives node-8.
    (void)leaf::fun_00407460(m, i);
}

void clear_child_state(Memory& m, std::uint32_t child) {
    leaf::Inputs i{};
    i.cx = child;
    (void)leaf::fun_00408520(m, i);
}

void retained_noop(Memory& m, std::uint32_t node) {
    leaf::Inputs i{};
    i.cx = node + 0x1cu;
    (void)leaf::fun_00408450(m, i); // Verified body is a single RET.
}
}

std::uint32_t fun_00401b00(Memory& m, const Inputs& in,
                           ra2::platform::ordinary_heap::Heap& heap) {
    const std::uint32_t self = in.cx;
    const std::uint32_t outer_head = self + 0x0cu;
    std::uint32_t outer_count = 0;

    while (const std::uint32_t outer = first(m, outer_head)) {
        if (++outer_count > traversal_limit)
            throw std::domain_error("B852 outer list exceeds finite contract");

        // The original skips unlink only when the +4 link already equals the
        // node. This finite positive route requires the linked case.
        if (m.r32(outer + 4u) != outer) unlink(m, outer);

        const std::uint32_t child_head = outer + 0x24u;
        std::uint32_t child_count = 0;
        while (const std::uint32_t child = first(m, child_head)) {
            if (++child_count > traversal_limit)
                throw std::domain_error("B852 child list exceeds finite contract");
            unlink(m, child);
            clear_child_state(m, child);
            const std::uint32_t destination = m.r32(m.r32(outer + 0x3cu) + 4u);
            insert_after(m, destination, child);
        }

        retained_noop(m, outer);
        const std::uint32_t destination = m.r32(m.r32(outer + 0x3cu) + 8u);
        insert_after(m, destination, outer);
    }

    std::uint32_t result = 0;
    const std::uint32_t first_owned = m.r32(self + 4u);
    if (first_owned) result = heap.release(first_owned);
    const std::uint32_t second_owned = m.r32(self + 8u);
    if (second_owned) result = heap.release(second_owned);
    result = heap.release(self); // Original final HeapFree BOOL is full EAX.
    return result;
}
}
