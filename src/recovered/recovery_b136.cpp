#include "recovered/recovery_b136.hpp"

#include <stdexcept>

namespace ra2::recovered::recovery_b136 {
namespace {
void require(bool condition, const char* message) {
    if (!condition) throw std::domain_error(message);
}

void initialize_node_links(ra2::platform::small_crt_heap::Heap& heap,
                           std::uint32_t node) {
    // Exact accepted 0x407200 body: self-link +0/+4, clear +8, RET.
    heap.w32(node, node);
    heap.w32(node + 4u, node);
    heap.w32(node + 8u, 0);
}

void insert_after_empty_head(ra2::platform::small_crt_heap::Heap& heap,
                             std::uint32_t head,
                             std::uint32_t node) {
    // Exact accepted 0x407370 instructions, preserving access/store order.
    heap.w32(node + 4u, head);                 // 0x407370
    const auto successor = heap.r32(head);     // 0x407373
    heap.w32(node, successor);                 // 0x407375
    heap.w32(head, node);                      // 0x407377
    const auto new_successor = heap.r32(node); // 0x407379
    heap.w32(new_successor + 4u, node);         // 0x40737b
}
}

std::uint32_t fun_00008a60_one_node(
    ra2::platform::small_crt_heap::Heap& heap,
    ra2::recovered::global_b26::Memory& memory,
    const ra2::recovered::global_b26::Inputs& inputs) {
    constexpr std::uint32_t kTail = 0x2800u;
    constexpr std::uint32_t kShift = 0u;
    const auto root = inputs.cx;
    const auto count = inputs.dx;
    // Heap routes both its owned CRT allocations and unowned game addresses
    // to the same global_b26 Memory supplied at construction.
    (void)memory;
    require(root != 0 && count == 1u,
            "only the caller-proven one-node route is in this draft");
    require(inputs.arg[0] == kTail && inputs.arg[1] == kShift,
            "stack args do not match the natural 0x121aa0 callsite route");

    // Locals at original entryESP-0xc/-8/-4 are internal stack-frame state;
    // represent them as C++ locals. The callee-visible arg[1] mutation below
    // is kept in Inputs.arg[1], matching the native bridge's mutable stack.
    std::uint32_t completed = 0;
    std::uint32_t remaining = count - 1u;
    const std::uint32_t quantum = 1u << kShift;
    const auto request = quantum + kTail;
    inputs.arg[1] = request;                    // 0x408a95 before first alloc

    auto node = heap.allocate(0x3cu);            // 0x408a99: real small alloc
    require(node != 0, "successful 60-byte small allocation is required");
    for (std::uint32_t offset = 0; offset < 0x3cu; offset += 4u)
        heap.w32(node + offset, 0);              // 0x408aab: REP STOSD 15 dwords
    initialize_node_links(heap, node);

    const auto backing = heap.allocate(request); // 0x408abc: real ordinary alloc
    heap.w32(node + 0x10u, backing);             // 0x408ac4 before TEST EAX,EAX
    require(backing != 0, "successful 0x2801-byte backing allocation is required");

    const auto interior = (backing + quantum - 1u) & ~(quantum - 1u);
    heap.w32(node + 0x14u, kShift);              // 0x408acf
    heap.w32(node + 0x1cu, kTail);               // 0x408ae1
    heap.w32(node + 0x18u, interior);            // 0x408ae8

    // Constructor 0x8710/0x71f0 supplies this empty circular-list receiver.
    // Use the actual accepted helper; it observes and mutates both root and
    // node memory through Heap's unified guest-memory routing.
    insert_after_empty_head(heap, root + 4u, node);

    const auto root_count = heap.r32(root);       // 0x408af7
    const auto root_total = heap.r32(root + 0x14u); // 0x408af9
    heap.w32(root, root_count + 1u);              // 0x408afd
    const auto actual_tail = heap.r32(node + 0x1cu); // 0x408aff
    heap.w32(root + 0x14u, root_total + actual_tail); // 0x408b04

    const auto node_count_remaining = remaining;  // 0x408b07
    heap.w32(node + 0x30u, root);                // 0x408b0b
    const auto root_flags = heap.r32(root + 0x10u); // 0x408b0e
    const auto completed_before = completed;      // 0x408b11
    const auto continue_loop = node_count_remaining;
    const auto remaining_after = node_count_remaining - 1u; // 0x408b1b
    heap.w32(root + 0x10u, root_flags & 0xfffffffdu); // 0x408b1c
    completed = completed_before + 1u;            // 0x408b18/21

    require(continue_loop == 0 && remaining_after == 0xffffffffu,
            "loop continuation requires another node and is outside this draft");
    return completed;                             // 0x408b3d: full EAX=1, RET 8
}

} // namespace ra2::recovered::recovery_b136

namespace ra2::recovered::recovery_b136 { std::uint32_t fun_00408a60(Memory&m,const Inputs&i,Heap&h){return fun_00008a60_one_node(h,m,i);} }
