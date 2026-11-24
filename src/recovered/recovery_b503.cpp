#include "recovery_b503.hpp"
#include <stdexcept>

namespace ra2::recovered::surface_b503 {
namespace {
using U = std::uint32_t;
constexpr U kSurfaceVptr = 0x00785ef8u;
void need(bool value, const char* why) {
    if (!value) throw std::domain_error(why);
}

U rect_x(Memory& m, U p) { return m.r32(p); }
U rect_y(Memory& m, U p) { return m.r32(p + 4u); }
U rect_w(Memory& m, U p) { return m.r32(p + 8u); }
U rect_h(Memory& m, U p) { return m.r32(p + 12u); }

// Original slot +0x5c target 0x11370. Its reached calls use authentic
// BSurface slots +0x70/+0x74/+0x7c. Those methods return format, width*format,
// and width respectively; the target increments +0x0c and computes
// pixels+x*format+y*(width*format).
U lock_pixel_11370(Memory& m, U surface, U x, U y) {
    need(m.r32(surface) == kSurfaceVptr, "B503 authentic receiver vptr");
    need(m.r32(kSurfaceVptr + 0x5cu) == 0x00411370u &&
         m.r32(kSurfaceVptr + 0x60u) == 0x004112f0u &&
         m.r32(kSurfaceVptr + 0x70u) == 0x004113b0u &&
         m.r32(kSurfaceVptr + 0x74u) == 0x004113c0u &&
         m.r32(kSurfaceVptr + 0x7cu) == 0x004112c0u,
         "B503 exact reached BSurface getter slots");
    const U width = m.r32(surface + 4u);
    const U height = m.r32(surface + 8u);
    const U format = m.r32(surface + 0x10u);
    const U pixels = m.r32(surface + 0x14u);
    need(width > 0 && height > 0 && format == 2u && pixels != 0 &&
         x < width && y < height, "B503 positive owned two-byte surface point");
    const U old_lock = m.r32(surface + 0x0cu);
    need(old_lock != 0xffffffffu, "B503 bounded nonwrapping lock increment");
    m.w32(surface + 0x0cu, old_lock + 1u);
    const U stride = width * format;
    return pixels + y * stride + x * format;
}

void require_full_rect(Memory& m, U p, U width, U height) {
    need(rect_x(m, p) == 0 && rect_y(m, p) == 0 &&
         rect_w(m, p) == width && rect_h(m, p) == height,
         "B503 equal positive full-rectangle route");
}
}

U fun_00760cf0(Memory& m, const Inputs& in) {
    // Entry ECX is the first surface; EDX is the third rectangle. The seven
    // stack words map to rect0, surface1, rect2, rect3, byte result, pointer A,
    // pointer B. This route restricts every rectangle to the same full bounds.
    const U surface_a = in.cx;
    const U rect_edx = in.dx;
    const U rect0 = in.arg[0];
    const U surface_b = in.arg[1];
    const U rect2 = in.arg[2];
    const U rect3 = in.arg[3];
    const U overlap_byte = in.arg[4];
    const U out_a = in.arg[5];
    const U out_b = in.arg[6];

    need(surface_a != surface_b && surface_a != 0 && surface_b != 0,
         "B503 two distinct authentic BSurface receivers");
    need(overlap_byte != 0 && out_a != 0 && out_b != 0 &&
         overlap_byte != out_a && overlap_byte != out_b && out_a != out_b,
         "B503 distinct valid output cells");
    const U width = m.r32(surface_a + 4u);
    const U height = m.r32(surface_a + 8u);
    need(width >= 2 && width <= 32 && height >= 2 && height <= 24,
         "B503 finite positive dimensions");
    for (U surface : {surface_a, surface_b}) {
        need(m.r32(surface) == kSurfaceVptr && m.r32(surface + 4u) == width &&
             m.r32(surface + 8u) == height && m.r32(surface + 0x10u) == 2u &&
             m.r32(surface + 0x14u) != 0,
             "B503 constructor-proven matching BSurface layout");
    }
    require_full_rect(m, rect0, width, height);
    require_full_rect(m, rect_edx, width, height);
    require_full_rect(m, rect2, width, height);
    require_full_rect(m, rect3, width, height);

    // The exact 0x360ad0 clipping helper leaves equal {0,0,W,H} records
    // unchanged and reports positive extents. Distinct surface receivers take
    // the original JNZ path around the same-surface overlap marker write.
    m.w8(overlap_byte, 0);
    m.w32(out_a, 0);
    m.w32(out_b, 0);
    const U pixel_a = lock_pixel_11370(m, surface_a, 0, 0);
    m.w32(out_a, pixel_a);
    const U pixel_b = lock_pixel_11370(m, surface_b, 0, 0);
    m.w32(out_b, pixel_b);

    // Original final MOV AL,1 preserves the high 24 bits returned by the
    // second 0x11370 virtual call.
    return (pixel_b & 0xffffff00u) | 1u;
}
}
