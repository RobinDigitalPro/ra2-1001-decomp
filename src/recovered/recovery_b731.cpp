#include "recovered/recovery_b731.hpp"
#include <array>
#include <stdexcept>

namespace ra2::recovered::rendering_b731 {
namespace {
using U = std::uint32_t;
void need(bool ok, const char* what) { if (!ok) throw std::domain_error(what); }
}

U fun_004309b0(Memory& m, const Inputs& i) {
  const U owner = i.cx;
  const U descriptor = m.r32(owner + 0x20u);
  const U target_surface = i.arg[0];
  need(descriptor != 0 && m.r32(descriptor) != 0 && target_surface != 0,
       "B731 populated owner descriptor and target surface route");
  const U bounds_surface = m.r32(descriptor + 0x10u);
  need(bounds_surface != 0 && m.r32(bounds_surface) == 0x785ef8u &&
       m.r32(target_surface) == 0x785ef8u,
       "B731 constructor-proven BSurface callback receivers");
  const U width = m.r32(bounds_surface + 4u);
  const U height = m.r32(bounds_surface + 8u);
  need(width == 32u && height == 24u &&
       m.r32(bounds_surface + 0x10u) == m.r32(target_surface + 0x10u),
       "B731 bounded equal 32x24 software surfaces");

  const U left = m.r32(descriptor + 0x24u);
  const U top = m.r32(descriptor + 0x28u);
  const U rect_width = m.r32(descriptor + 0x2cu);
  const U rect_height = m.r32(descriptor + 0x30u);
  const U delta_x = m.r32(owner + 0x18u) - width;
  const U sign_x = (static_cast<std::int32_t>(delta_x) < 0) ? 0xffffffffu : 0u;
  const auto centered_x = static_cast<std::int32_t>(delta_x - sign_x) >> 1;
  const U x = left + static_cast<U>(centered_x) + m.r32(owner + 0x10u);
  const U y = top + m.r32(owner + 0x1cu) - height + m.r32(owner + 0x14u);
  need(left == 0 && top == 0 && rect_width == width && rect_height == height &&
       x == 0 && y == 0,
       "B731 finite full-surface geometry produced by original centering arithmetic");

  // The authentic +0x14 BSurface method receives stack-local rectangles. Use
  // private scratch bytes in the portable arena, then restore them exactly so
  // they do not become observable guest-memory effects.
  const U scratch = owner + 0x6f000u;
  std::array<std::uint8_t, 32> saved{};
  for (U k = 0; k < saved.size(); ++k) saved[k] = m.r8(scratch + k);
  m.w32(scratch + 0u, x); m.w32(scratch + 4u, y);
  m.w32(scratch + 8u, rect_width); m.w32(scratch + 12u, rect_height);
  m.w32(scratch + 16u, 0u); m.w32(scratch + 20u, 0u);
  m.w32(scratch + 24u, width); m.w32(scratch + 28u, height);
  Inputs nested = i;
  nested.cx = target_surface;
  nested.arg[0] = scratch;
  nested.arg[1] = scratch + 16u;
  nested.arg[2] = 0u;
  const U result = ra2::recovered::surface_b453::fun_0075fd00(m, nested);
  for (U k = 0; k < saved.size(); ++k) m.w8(scratch + k, saved[k]);
  return result;
}
}
