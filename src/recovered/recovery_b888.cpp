#include "recovered/recovery_b888.hpp"

#include <stdexcept>

namespace ra2::recovered::recovery_b888 {
using U = std::uint32_t;

// B885's accepted route normally keeps its descriptor in global_b26::Memory.
// Here that descriptor lives inside the newly allocated Heap buffer, so this
// small adaptor applies the same accepted instruction effects across the two
// address spaces: source reads use Memory; destination/vector bytes use Heap.
static void copy_nested_vector(Memory& m, U dst, U src,
                               ra2::platform::ordinary_heap::Heap& heap) {
    const U count = m.r32(src + 8);
    const U source_data = m.r32(src + 4);
    if (!count || count > 4 || !source_data || heap.r32(dst) != 0x790ab8u ||
        m.r32(0x790ac4u) != 0x567860u || heap.r32(dst + 4) != 0 ||
        heap.r8(dst + 0x0d) != 0)
        throw std::domain_error("B888 accepted-vector-copy preconditions");

    // Original vslot target 0x167860 on the empty destination, followed by
    // the accepted B885 0x1698E0 allocation/copy effects.
    heap.w32(dst + 0x10, 0);
    heap.w32(dst + 8, 0);
    heap.w8(dst + 0x0d, 0);
    heap.w32(dst + 8, count);
    const U fresh = heap.allocate(count * 8u);
    if (!fresh) throw std::domain_error("B888 nested allocation-success route");
    heap.w32(dst + 4, fresh);
    heap.w8(dst + 0x0d, 1);
    for (U n = 0; n != count * 2u; ++n)
        heap.w32(fresh + n * 4u, m.r32(source_data + n * 4u));
}

U fun_00568310(Memory& m, const Inputs& i,
               ra2::platform::ordinary_heap::Heap& heap) {
    const U owner = i.cx;
    const U requested = i.arg[0];
    const U external_raw = i.arg[1];

    // The draft covers successful, internally allocated growth only. In
    // particular the old table is borrowed, so the original free path is
    // unreachable and the old array remains byte-for-byte intact.
    if (!owner || requested < 2 || requested > 4 || external_raw != 0 ||
        m.r32(owner + 4) == 0 || m.r32(owner + 8) != 1 ||
        m.r8(owner + 0x0d) != 0)
        throw std::domain_error("B888 finite borrowed-old-array growth contract");

    const U old_records = m.r32(owner + 4);
    const U old_count = m.r32(owner + 8);

    // Original 0x568310 first clears owner+0x0c, then requests 4+36*n
    // bytes. The allocator adapter supplies the original HeapAlloc rounding
    // and payload pattern; the model writes only bytes written by the root.
    m.w8(owner + 0x0c, 0);
    const U raw = heap.allocate(requested * 0x24u + 4u);
    if (!raw) throw std::domain_error("B888 allocation-success route");
    heap.w32(raw, requested);
    const U fresh_records = raw + 4u;

    // 0x568365..0x568388: call accepted 0x169840 with (0,0), rebind the
    // authentic 0x790AB8 table vptr, initialize the observed fields, and
    // dispatch the accepted +0x0c clear target through B885's exact effect.
    for (U n = 0; n != requested; ++n) {
        const U dst = fresh_records + n * 0x24u;
        heap.w32(dst + 4, 0);
        heap.w32(dst + 8, 0);
        heap.w8(dst + 0x0c, 1);
        heap.w8(dst + 0x0d, 0);
        heap.w32(dst, 0x78576cu);       // 0x169840 constructor vptr
        heap.w32(dst, 0x790ab8u);       // authentic caller rebind at 0x56836E
        heap.w32(dst + 0x14, 10);
        heap.w32(dst + 0x10, 0);
        heap.w32(dst + 0x10, 0);        // 0x167860 clear's +0x10 store
        heap.w32(dst + 8, 0);           // 0x167860 clear's +8 store
        heap.w8(dst + 0x0d, 0);         // 0x167860 clear's ownership store
        heap.w8(dst + 0x18, 0);
        heap.w8(dst + 0x19, 0);
        heap.w32(dst + 0x1c, 0);
        heap.w32(dst + 0x20, 0);
    }
    m.w8(owner + 0x0c, 1);

    // The original copies min(requested, old capacity); this draft fixes the
    // old capacity to one, so exactly the first 0x24-byte record is copied.
    const U copied = requested < old_count ? requested : old_count;
    for (U n = 0; n != copied; ++n) {
        const U src = old_records + n * 0x24u;
        const U dst = fresh_records + n * 0x24u;

        copy_nested_vector(m, dst, src, heap);

        // 0x568451..0x56846E copy exact tail widths. The +0x10 DWORD
        // deliberately overwrites the clear's zero with the old value.
        heap.w32(dst + 0x10, m.r32(src + 0x10));
        heap.w32(dst + 0x14, m.r32(src + 0x14));
        const U tail_word = m.r16(src + 0x18);
        heap.w8(dst + 0x18, tail_word);
        heap.w8(dst + 0x19, tail_word >> 8);
        heap.w32(dst + 0x1c, m.r32(src + 0x1c));
        heap.w32(dst + 0x20, m.r32(src + 0x20));
    }

    // Borrowed old table: no old-record destructor, nested release, or outer
    // release executes. The root installs fresh data/count and marks it owned
    // because its optional external-table argument was null.
    m.w32(owner + 4, fresh_records);
    m.w32(owner + 8, requested);
    m.w8(owner + 0x0d, 1);
    return 1; // Original full EAX is 1 on this successful null-arg route.
}
}
