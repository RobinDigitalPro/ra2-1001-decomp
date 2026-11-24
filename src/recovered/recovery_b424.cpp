#include "recovery_b424.hpp"
#include <stdexcept>

namespace ra2::recovery_b424 {
namespace {
void need(bool ok, const char* why) {
    if (!ok) throw std::domain_error(why);
}
}

std::uint32_t fun_007252c0(Memory& m, const Inputs& i, Heap& h) {
    const std::uint32_t receiver = i.cx;
    const std::uint32_t source_wrapper = i.dx;
    const std::uint32_t index = i.arg[0];
    need(receiver && source_wrapper, "B424 requires receiver and source wrapper");
    need(receiver != source_wrapper, "B424 excludes the uncharacterized alias case");

    // 0x7252c7..0x7252ce: real helper request 0x14, successful selected route.
    const std::uint32_t node = h.allocate(20u);
    need(node != 0, "B424 excludes original operator-new failure");

    // 0x7252dd..0x7252ea: initialize node+4 and the embedded reference at +8.
    need(h.r32(node + 4u) == 0u && h.r32(node + 8u) == 0u &&
         h.r32(node + 12u) == 0u,
         "B424 new request-20 payload is expected zero-filled");
    h.w32(node + 4u, 0u);                         // original MOV [ESI+4],0
    h.w32(node, 0x00793cd4u);                     // original MOV [ESI],793cd4
    h.w32(node + 8u, 0x00793cccu);               // 0x630a80 embedded init vptr
    h.w32(node + 12u, 0u);                        // 0x630a80 embedded refcount

    // 0x7252ef..0x7252fb: install the embedded descriptor and copy the
    // source child reference through 0x630ad0. The selected route has a
    // nonnull source child and zero old destination ref, so the original
    // reached path increments child+4 and stores child at node+0xc.
    const std::uint32_t child = m.r32(source_wrapper + 4u);
    need(child != 0u, "B424 requires a nonnull source child reference");
    need(h.r32(node + 12u) == 0u, "B424 embedded destination ref starts null");
    h.w32(node + 8u, 0x0079a034u);               // original MOV [EDI],79a034
    m.w32(child + 4u, m.r32(child + 4u) + 1u);  // exact 0x230ad0 INC source+4
    h.w32(node + 12u, child);                    // exact 0x230ad0 assignment

    // 0x725300..0x725329: initialize the selected-element field, install the
    // primary vptr, then copy source child[index] only when index<count.
    h.w32(node + 16u, 0u);
    h.w32(node, 0x0079a25cu);
    const std::uint32_t child_count = m.r32(child + 0x24u);
    need(index < child_count,
         "B424 positive route requires a valid nonzero child-array index");
    const std::uint32_t refs = m.r32(child + 0x44u);
    need(refs != 0u, "B424 requires a nonnull source reference array");
    const std::uint32_t selected = m.r32(refs + index * 4u);
    need(selected != 0u, "B424 requires a nonnull selected reference");
    h.w32(node + 16u, selected);                  // original [ESI+10]=array[index]

    // 0x72532d..0x725343: initialize the receiver's reference pair, install
    // the literal output vptr, then retain the newly allocated node through
    // 0x230ad0. Its exact reached branch increments node+4 from 0 to 1.
    m.w32(receiver + 4u, 0u);                    // 0x630a80 [receiver+4]=0
    m.w32(receiver, 0x00793cccu);                // 0x630a80 [receiver]=793ccc
    m.w32(receiver, 0x00799e74u);                // original MOV [EBP],799e74
    need(h.r32(node + 4u) == 0u, "B424 newly allocated node ref starts zero");
    h.w32(node + 4u, 1u);                        // exact 0x230ad0 INC node+4
    m.w32(receiver + 4u, node);                  // exact 0x230ad0 assignment
    return receiver;                             // original EAX=EBP, RET 4
}
}
