#include "recovered/recovery_b169.hpp"

#include <array>
#include <stdexcept>
#include <string>

namespace ra2::recovered::recovery_b169 {
namespace {

[[noreturn]] void unsupported(const char* text) {
    throw std::domain_error(text);
}
void require(bool condition, const char* text) {
    if (!condition) unsupported(text);
}

std::string read_guest_c_string(const Memory& m, std::uint32_t p) {
    require(p != 0, "326a20 requires a non-null original prefix literal");
    std::string result;
    for (std::uint32_t n = 0; n != 64; ++n) {
        const auto ch = static_cast<char>(m.r8(p + n));
        if (ch == '\0') return result;
        result.push_back(ch);
    }
    unsupported("326a20 prefix did not terminate in the bounded readonly span");
}

std::uint32_t allocate_text(Heap& heap, const std::string& text) {
    const auto p = heap.allocate(static_cast<std::uint32_t>(text.size() + 1));
    require(p != 0, "the positive route requires successful real CRT allocation");
    return p;
}
void copy_text(Heap& heap, std::uint32_t dst, const std::string& text) {
    for (std::size_t i = 0; i < text.size(); ++i)
        heap.w8(dst + static_cast<std::uint32_t>(i),
                static_cast<std::uint8_t>(text[i]));
    heap.w8(dst + static_cast<std::uint32_t>(text.size()), 0);
}
std::string read_heap_text(const Heap& heap, std::uint32_t p) {
    std::string result;
    for (std::uint32_t n = 0; n != 64; ++n) {
        const auto ch = static_cast<char>(heap.r8(p + n));
        if (ch == '\0') return result;
        result.push_back(ch);
    }
    unsupported("326a20 temporary text exceeded the exact finite route bound");
}

} // namespace

std::uint32_t fun_00726a20(Memory& m, const Inputs& i, Heap& heap) {
    const auto mode = i.cx;          // 0x726a2a: EDI=entry ECX
    const auto record = i.dx;        // 0x726a2c: ESI=entry EDX
    const auto output_cell = i.arg[0]; // [entry ESP+4], RET 4
    require(record != 0 && output_cell != 0,
            "326a20 bounded route needs a valid record and output cell");

    // 0x726a30 calls 0x759f70 on the output pointer slot. This finite route
    // proves the slot is null, so its authentic clear/free helper has no
    // allocation effect and writes the same zero back.
    require(m.r32(output_cell) == 0,
            "326a20 route excludes the initial-output free branch");
    m.w32(output_cell, 0);

    // 0x726a35..0x726a5e: the one-item count bypasses 0x62fe40 entirely.
    // The array slot is consumed as the integer formatting value by 0x75af50;
    // it is not dereferenced as a C string in this branch.
    const auto count = m.r32(record + 0x10u);
    require(count == 1u, "326a20 finite route requires the count-one branch");
    const auto array = m.r32(record + 4u);
    require(array != 0, "326a20 count-one record needs its element array");
    const auto value = m.r32(array);
    require(value <= 9u,
            "326a20 finite formatter route limits the selected value to 0..9");

    // 0x726a64 supplies width 2 and 0x35af50 returns the terminated `%02d`
    // text. For the explicitly bounded 0..9 input the original helper writes
    // exactly two payload bytes and one NUL, requesting three bytes.
    const std::string digits{static_cast<char>('0' + value / 10u),
                             static_cast<char>('0' + value % 10u)};
    const auto f = allocate_text(heap, digits); // F, request 3
    heap.w8(f,0);
    copy_text(heap, f, digits);

    // 0x726a61/66 chooses an original ten-byte literal prefix. 0x35aff0
    // first clones it (A), clones it again (B), concatenates digits into B
    // (C), releases B, clones C (D), then releases C and A. The explicit
    // staging preserves the original six-request / five-release schedule and
    // publishes all bytes into actual CRT allocations.
    const auto prefix_va = mode == 3u ? 0x007e5f8cu : 0x007e5f80u;
    const auto prefix = read_guest_c_string(m, prefix_va);
    require(prefix.size() == 10u,
            "326a20 selected prefix must be the pinned ten-byte literal");

    const auto a = allocate_text(heap, prefix); // A, request 11
    heap.w8(a,0);
    copy_text(heap, a, prefix);
    const auto b = allocate_text(heap, prefix); // B, request 11
    copy_text(heap, b, prefix);

    const auto concat = prefix + read_heap_text(heap, f);
    const auto c = allocate_text(heap, concat); // C, request 13
    copy_text(heap,c,prefix);
    copy_text(heap,c+unsigned(prefix.size()),read_heap_text(heap,f));
    heap.release(b);

    const auto c_text = read_heap_text(heap, c);
    // Mode3 places this temporary slot at root entry ESP+4 (caller arg0).
    // The saved output_cell above remains the original output pointer.
    if(mode==3u)i.arg[0]=0;
    const auto d = allocate_text(heap, c_text); // D reuses B, request 13
    if(mode==3u)i.arg[0]=d;
    copy_text(heap, d, c_text);
    heap.release(c);
    heap.release(a);

    // 0x759570 sees the caller output slot still null, allocates E by copying
    // D, and publishes that pointer in the caller's cell.
    const auto d_text = read_heap_text(heap, d);
    const auto e = allocate_text(heap, d_text); // E reuses A, request 13
    m.w32(output_cell,e);
    heap.w8(e,0);
    copy_text(heap,e,d_text);

    // 0x726a8f/98 destroy the local D and F pointer slots. The last free's
    // imported void-API residue is not a specified C++ value; root
    // 0x726a9d guarantees only AL=1, so the recovery exposes that byte.
    heap.release(d);
    if(mode==3u)i.arg[0]=0; // original temporary destructor clears caller slot
    heap.release(f);
    return 1u & 0xffu;
}

} // namespace ra2::recovered::recovery_b169
