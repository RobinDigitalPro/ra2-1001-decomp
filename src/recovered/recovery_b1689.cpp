#include "recovery_b1689.hpp"
#include "platform/x87_state.hpp"
#include <array>
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::b1689 {
namespace {
namespace fp = ra2::platform::x87;
constexpr unsigned self = 0x81a820u;
void need(bool value) {
    if (!value) throw std::domain_error("173210 positive fixed-Map reset contract");
}
std::uint64_t end(Span s) { return std::uint64_t(s.base) + s.bytes; }
void valid(Span s) { need(s.base != 0u && s.bytes != 0u && end(s) <= 0x100000000ull); }
bool separate(Span a, Span b) { return end(a) <= b.base || end(b) <= a.base; }
void readable(Memory& m, Span s) {
    for (unsigned j = 0; j < s.bytes; ++j) (void)m.r8(s.base + j);
}
void readable(Heap& h, Span s) {
    for (unsigned j = 0; j < s.bytes; ++j) (void)h.r8(s.base + j);
}
std::uint64_t r64(Memory& m, unsigned p) {
    return m.r32(p) | (std::uint64_t(m.r32(p + 4u)) << 32u);
}
// Same host/explicit-image discipline as x87_state.hpp. That interface has
// no FIMUL32 member; this local operation executes the actual instruction.
void multiply_integer32(fp::State& s, std::uint32_t operand) {
    s.require_masked();
    fp::Image host;
    asm volatile(
        "fnsave %[host]\n\tfrstor %[guest]\n\tfimull %[operand]\n\t"
        "fnsave %[guest]\n\tfrstor %[host]"
        : [host] "=m" (host.bytes), [guest] "+m" (s.image.bytes)
        : [operand] "m" (operand)
        : "memory", "st", "st(1)", "st(2)", "st(3)",
          "st(4)", "st(5)", "st(6)", "st(7)");
}
void numeric_preflight(const fp::Image& image) {
    constexpr std::array<unsigned, 12> controls{
        0x037fu,0x077fu,0x0b7fu,0x0f7fu,
        0x027fu,0x067fu,0x0a7fu,0x0e7fu,
        0x007fu,0x047fu,0x087fu,0x0c7fu};
    bool found = false;
    for (unsigned cw : controls) found = found || image.word(0) == cw;
    need(found && image.word(8) == 0xffffu);
    need((image.word(4) & ~0x3800u) == 0u);
}
void prefix(Memory& m, fp::State& s) {
    // 573213..57325B: perform all arithmetic before the MAX400 branch.
    s.load_integer32(m.r32(0xa57b04u));
    multiply_integer32(s, m.r32(0xa57b00u));
    s.multiply64(r64(m, 0x790df0u));
    s.load64(r64(m, 0x790de8u));
    s.compare_pop_st1();
    const unsigned status = s.status();
    if ((status & 0x4100u) == 0u) {
        s.pop_st0();
        s.load64(r64(m, 0x790de8u));
    }
    // Actual 76AA50 cached-DWORD comparison and FISTP, without restoring CW.
    const unsigned cache = m.r32(0x7c3a04u);
    if (unsigned(s.control()) != cache)
        s.load_control(static_cast<std::uint16_t>(cache));
    const std::uint64_t threshold = s.pop_integer64();
    need(threshold == 400u); // internal result assertion, never an input seed
}
struct LocalVector {
    unsigned addresspoint = 0, pointer = 0, capacity = 0;
    unsigned status = 0, owner = 0, count = 0, growth = 0;
};
LocalVector construct_zero_vector() {
    // Reached 58BD60(0,0), root's derived header writes, then 58AE00.
    LocalVector v;
    v.addresspoint = 0x790d90u;
    v.pointer = 0u; v.capacity = 0u; v.status = 1u; v.owner = 0u;
    v.addresspoint = 0x790d70u; v.count = 0u; v.growth = 10u;
    // 58AE00 sees the genuinely null freshly constructed pointer.
    v.owner = 0u; v.capacity = 0u;
    return v;
}
void release_null() {
    // Actual 76D67B -> 76DF28 null branch: no heap/SDK/FP/FS/LastError effect.
    // Production MixedHeap1279::release deliberately rejects null; this
    // reached game branch performs no heap call rather than inventing one.
}
}

void preflight(Memory& m, Heap& h, const Bounds& b) {
    const std::array<Span, 5> owned{b.cache,b.header,b.vectors,b.grid,b.table};
    const Span image{0x400000u,0x730000u};
    for (unsigned j = 0; j < owned.size(); ++j) {
        valid(owned[j]); need(separate(owned[j], image));
        for (unsigned k = 0; k < j; ++k) need(separate(owned[j], owned[k]));
    }
    need(b.cache.bytes == 1444u && b.header.bytes == 16u &&
         b.vectors.bytes == 6148u && b.grid.bytes == 361u * 0x50u);
    need(b.table.bytes >= 0x3808u && b.table.bytes <= 0x10000u);
    readable(h,b.cache); readable(h,b.header); readable(h,b.vectors);
    readable(m,b.grid); readable(m,b.table);
    need(m.r32(self) == 0x79091cu && m.r32(self+0x14u) == b.header.base);
    need(m.r32(self+0x64u) == b.cache.base && m.r32(self+0x68u) == 361u);
    need(m.r32(self+0xf0u) == 7u && m.r32(self+0xf4u) == 11u);
    need(m.r32(self+0x138u) == b.table.base);
    need(m.r32(self+0x48u) == 0u && m.r32(self+0x4cu) == 0x7909d8u);
    need(m.r32(self+0x50u) == 0u && m.r32(self+0x54u) == 0u);
    need(m.r8(self+0x58u) == 1u && m.r8(self+0x59u) == 0u);
    need(m.r32(self+0x5cu) == 0u && m.r32(self+0x60u) == 10u);
    need(m.r32(0xa5784cu) == 0u && m.r32(0xa579bcu) == 0u &&
         m.r32(0xa57950u) == 0u);
    need(m.r32(0x836b4cu) == 19u && m.r32(0xa5863cu) == b.grid.base);
    need(m.r32(0xa57b00u) == 7u && m.r32(0xa57b04u) == 11u);
    need(r64(m,0x790df0u) == 0x3f9eb851eb851eb8ull &&
         r64(m,0x790de8u) == 0x4079000000000000ull);
    need(m.r32(0x7c3a04u) == 0x00000e7fu);
    need(m.r32(0x790a64u) == 0x567b30u &&
         m.r32(0x790aa0u) == 0x568c00u);
    need(h.r32(b.header.base) == b.vectors.base+4u &&
         h.r32(b.header.base+4u) == 0x54c6d0u &&
         h.r32(b.header.base+8u) == 256u &&
         h.r32(b.header.base+12u) == 20u &&
         h.r32(b.vectors.base) == 256u);
    for (unsigned j = 0; j < 256u; ++j) {
        const unsigned v = b.vectors.base+4u+24u*j;
        need(h.r32(v) == 0x790a58u && h.r32(v+4u) == 0u &&
             h.r32(v+8u) == 0u && h.r8(v+12u) == 1u &&
             h.r8(v+13u) == 0u && h.r32(v+16u) == 0u &&
             h.r32(v+20u) == 20u);
    }
    for (unsigned j = 0; j < 12u; ++j) {
        need(m.r32(self+0x18u+4u*j) == 0u);
        (void)m.r32(0x7cab9cu+32u*j);
        (void)m.r32(0x7cab9cu+32u*j+28u);
    }
    for (unsigned j = 0; j < 361u; ++j) {
        const int x = int(j%19u), y = int(j/19u);
        const bool clear = x+y>11 && x+y<=19 && x-y<3 && y-x<3;
        need(h.r8(b.cache.base+4u*j) == (clear?0u:7u));
        need(h.r8(b.cache.base+4u*j+1u) == 0u);
    }
    // This is an actual public pointer-table input, not an iterator result.
    need(m.r32(b.table.base+0x3804u) == 0u);
    (void)m.r32(b.table.base+0x3008u);
    (void)m.r32(0xa58640u);
    (void)m.r32(0xa579d0u);
}

unsigned run(unsigned root, Memory& m, const Inputs& input, Heap& h,
             const Bounds& b) {
    need(root == 0x173210u);
    fp::State numeric;
    numeric.image = fp::capture_host();
    numeric_preflight(numeric.image);
    preflight(m,h,b); // all input-domain rejection precedes guest side effects
    need(fp::same_numeric(numeric.image,fp::capture_host()));
    prefix(m,numeric);
    fp::restore_host(numeric.image);
    Inputs child = input;
    child.cx = self;
    const unsigned index = b1279::run(0x14c060u,m,child,h);
    // 57326E..573281: actual produced table pointer and actual returned index.
    const unsigned selectors[5]{5u,5u,5u,0u,0u};
    const unsigned selector = selectors[m.r32(0xa579bcu)];
    const unsigned table = m.r32(self+0x18u+4u*selector);
    const unsigned selected_word = h.r8(table+2u*index) |
                                  (h.r8(table+2u*index+1u)<<8u);
    (void)selected_word; // used only by the excluded candidate-creation loop
    // 56B580: nonempty 19*19 record reset, extending old n<=4 coverage.
    for (unsigned j=0; j<19u*19u; ++j) {
        const unsigned record = b.grid.base+0x50u*j;
        m.w32(record+0x38u,0xffffffffu);
        m.w32(record+0x3cu,0xffffffffu);
    }
    m.w32(0xa58640u,0u);
    // 557340 and first557280: execute the real reached stores/read.
    const unsigned width = m.r32(self+0xf0u);
    m.w32(self+0x108u,1u);
    m.w32(self+0x10cu,width);
    m.w32(self+0x110u,width-1u);
    const unsigned first = m.r32(self+0x138u)+(width<<11u)+4u;
    m.w32(self+0x114u,first);
    const unsigned remaining = m.r32(self+0x110u);
    const unsigned old_pointer = m.r32(self+0x114u);
    m.w32(self+0x108u,m.r32(self+0x108u)+1u);
    m.w32(self+0x110u,remaining-1u);
    m.w32(self+0x10cu,m.r32(self+0x10cu)-1u);
    m.w32(self+0x114u,old_pointer-0x7fcu);
    const unsigned cell = m.r32(old_pointer);
    need(cell == 0u); // implied by preflight and disjoint production writes
    LocalVector vector = construct_zero_vector();
    // Actual item count remains0: no sort/growth/distribution/sampler/RNG.
    release_null();
    vector.addresspoint = 0x790d90u;
    // All local storage is fully produced; no guest private bytes are seeded.
    return (vector.pointer & 0xffffff00u) | 1u;
}
}


