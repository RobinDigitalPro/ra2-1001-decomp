#include "recovered/numeric_b71_matrix.hpp"

#include "recovered/floating_composed_b43_memory.hpp"
#include "recovered/leaf_memory.hpp"
#include "recovered/numeric_b71.hpp"

#include <array>
#include <cstdint>

namespace ra2::recovered::global_b26 {
std::uint32_t fun_00545490(Memory&, const Inputs&);
}

namespace ra2::recovered::numeric_b71 {
namespace {
namespace b39 = ra2::recovered::floating_b39;
namespace b43 = ra2::recovered::floating_composed_b43;

constexpr std::uint32_t synthetic_local_base = 0x30000000u;
constexpr std::uint32_t synthetic_stack_base = 0x31000000u;
constexpr std::uint32_t synthetic_stack_pointer = synthetic_stack_base + 0x3ff0u;
constexpr std::uint32_t synthetic_return = 0xfeedb71au;

struct LocalMemory {
    std::array<std::uint8_t, 0x5000> bytes{};
    ra2::recovered::leaf::Memory span{bytes.data(), synthetic_local_base,
                                      static_cast<std::uint32_t>(bytes.size())};
    Memory view;
    explicit LocalMemory(Memory& original) : view(original) { view.add(span); }
};

std::uint64_t read64(Memory& m, std::uint32_t p) {
    return std::uint64_t(m.r32(p)) | (std::uint64_t(m.r32(p + 4u)) << 32u);
}

std::uint32_t angle_index(std::uint32_t interpolated) {
    // Exact unsigned shifts from the callers; the later SUB 8 is deliberately
    // represented as wrapping x86 arithmetic before FILD interprets it signed.
    return (((interpolated >> 10u) + 1u) >> 1u) & 0x1fu;
}

std::uint32_t interpolate(Memory& m, const Inputs& i, std::uint32_t descriptor,
                          std::uint32_t output) {
    Inputs call = i;
    call.cx = descriptor;
    call.arg[0] = output;
    return fun_004b8850(m, call);
}

std::uint32_t rounded_angle(Memory& m, const Inputs& i, std::uint32_t quantized) {
    const auto signed_angle = quantized - 8u;
    i.fp.load_integer32(signed_angle);
    i.fp.multiply64(read64(m, 0x00788090u));
    return i.fp.pop32(); // Original FSTP float scratch rounds here.
}

void rotate_with_accepted_body(Memory& m, const Inputs& i, std::uint32_t matrix,
                              std::uint32_t angle_bits) {
    // 0x58d7a0 is composed by executing its accepted instruction body, with
    // its accepted 0x4ba140/0x4ba0f0 callees. The synthetic stack is disjoint
    // from the observed arena and exists only for this nested RET 4 frame.
    std::array<std::uint8_t, 0x5000> bytes{};
    ra2::recovered::leaf::Memory scratch_page(bytes.data(), synthetic_stack_base,
                                               static_cast<std::uint32_t>(bytes.size()));
    Memory scratch = m;
    scratch.add(scratch_page);
    scratch.w32(synthetic_stack_pointer, synthetic_return);
    scratch.w32(synthetic_stack_pointer + 4u, angle_bits);

    b39::State state{};
    state.ax = i.ax;
    state.cx = matrix;
    state.dx = i.dx;
    state.arg = i.arg;
    state.arithmetic_flags = i.arithmetic_flags;
    state.fp = i.fp;

    b39::Frame frame;
    frame.entry_sp = synthetic_stack_pointer;
    frame.return_sp = synthetic_stack_pointer;
    frame.sp = synthetic_stack_pointer;
    frame.outer_return = synthetic_return;
    frame.call_return = synthetic_return;
    b43::resolve(0x0018d7a0u)(scratch, state, frame, b39::Operations{});
    i.fp = state.fp;
}

void initialize_identity(Memory& m, std::uint32_t matrix) {
    // Exact twelve dword writes of accepted 0x58ce60.
    for (unsigned k = 0; k != 12; ++k)
        m.w32(matrix + 4u * k,
              (k == 0u || k == 5u || k == 10u) ? 0x3f800000u : 0u);
}

void transform(Memory& m, const Inputs& i, std::uint32_t matrix,
               std::uint32_t quantized) {
    const auto angle = rounded_angle(m, i, quantized);
    rotate_with_accepted_body(m, i, matrix, angle);
}

void copy_matrix_forward(Memory& m, std::uint32_t dst, std::uint32_t src) {
    // The original is REP MOVSD with DF assumed clear. Keep the forward
    // read-then-write order; the prepared contract uses disjoint spans.
    for (unsigned k = 0; k != 12; ++k) m.w32(dst + 4u * k, m.r32(src + 4u * k));
}
}

std::uint32_t fun_0053b210(Memory& m, const Inputs& i) {
    const auto object = i.arg[0];
    const auto output = i.arg[1];
    const auto key = i.arg[2];
    LocalMemory local(m);
    auto& work = local.view;
    const auto matrix = synthetic_local_base + 0x100u;
    const auto angle_out = synthetic_local_base + 0x200u;
    const auto second_out = synthetic_local_base + 0x204u;

    initialize_identity(work, matrix);

    // Reload object+8 for each interpolation, as the original does. The
    // optional packed-key update occurs between these calls and may alias the
    // descriptor under the unrestricted ABI; prepared cases keep them apart.
    auto descriptor = m.r32(object + 8u) + 0x2e0u;
    (void)interpolate(work, i, descriptor, angle_out);
    const auto first = work.r32(angle_out);
    transform(work, i, matrix, angle_index(first));
    i.arg[0] = angle_index(first) - 8u;

    if (key != 0u && m.r32(key) != 0xffffffffu) {
        m.w32(key, m.r32(key) << 5u);
        descriptor = m.r32(object + 8u) + 0x2e0u;
        // The caller's first stack word is the output destination. Model that
        // private stack slot locally, then expose its final dword via Inputs.
        (void)interpolate(work, i, descriptor, second_out);
        const auto second = work.r32(second_out);
        m.w32(key, m.r32(key) | angle_index(second));
        i.arg[0] = second;
    }

    copy_matrix_forward(work, output, matrix);
    return output;
}

std::uint32_t fun_0053b2b0(Memory& m, const Inputs& i) {
    const auto outer = i.arg[0];
    const auto output = i.arg[1];
    const auto key = i.arg[2];
    const auto input_record = m.r32(outer + 8u);
    const auto vector = input_record + 0x88u;
    LocalMemory local(m);
    auto& work = local.view;
    const auto matrix = synthetic_local_base + 0x300u;
    const auto angle_out = synthetic_local_base + 0x400u;

    // Compose the accepted map lookup with its real original-memory fallback
    // behavior. The target record's byte selector is read only after lookup.
    Inputs map_call = i;
    map_call.cx = 0x0081a820u;
    map_call.arg[0] = vector;
    const auto selected_record = ra2::recovered::global_b26::fun_00545490(m, map_call);
    const auto selector = m.r8(selected_record + 0x11cu);

    // Original 0x70d920 performs exactly twelve forward dword copies from the
    // immutable selected row at 0xae0088 + selector*0x30.
    const auto table_row = 0x00ae0088u + std::uint32_t(selector) * 0x30u;
    copy_matrix_forward(work, matrix, table_row);

    auto descriptor = m.r32(outer + 8u) + 0x2e0u;
    (void)interpolate(work, i, descriptor, angle_out);
    const auto first = work.r32(angle_out);
    transform(work, i, matrix, angle_index(first));

    if (key != 0u && m.r32(key) != 0xffffffffu) {
        m.w32(key, ((m.r32(key) << 6u) + selector) << 5u);
        descriptor = m.r32(outer + 8u) + 0x2e0u;
        (void)interpolate(work, i, descriptor, angle_out);
        const auto second = work.r32(angle_out);
        m.w32(key, m.r32(key) | angle_index(second));
    }

    copy_matrix_forward(work, output, matrix);
    return output;
}
}
