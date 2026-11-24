#include "recovery_b1330.hpp"
#include <stdexcept>

namespace ra2::recovered::b1330 {
namespace {
using U=std::uint32_t;
constexpr U kGrid=0x0081a958u;
constexpr U kDefaultScratch=0x00a56e5cu;
constexpr U kCellSentinel=0x38u;
void need(bool ok,const char*why){if(!ok)throw std::domain_error(why);}
}

U fun_00565cc0(Memory&m,const Inputs&i){
 // Finite route at 0x565cc9..0x565d32: the original A56E5C load is copied
 // only to a private local; it does not reach this route's declared output.
 const U default_scratch=m.r32(kDefaultScratch);
 (void)default_scratch;
 const U receiver=i.cx;need(receiver!=0u,"B1330 requires the mapped receiver input");
 const U packed_ptr=i.arg[1];need(packed_ptr!=0u,"B1330 coordinate pointer");
 const auto x=static_cast<std::int16_t>(m.r16(packed_ptr));
 const auto y=static_cast<std::int16_t>(m.r16(packed_ptr+2u));
 need(x>=1&&x<=31&&y>=1&&y<=31,"B1330 positive interior coordinate range");
 const U index=(static_cast<U>(y)<<9u)+static_cast<U>(x);
 need(index<0x40000u,"B1330 original grid index bound");
 const U grid=m.r32(kGrid);need(grid!=0u,"B1330 mapped original grid pointer");
 const U cell=m.r32(grid+index*4u);need(cell!=0u,"B1330 selected nonnull grid cell");
 const auto marker=floating_b61::s32(m.r32(cell+kCellSentinel));
 need(marker==-1,"B1330 selected signed -1 cell marker");
 const U output=i.arg[0];need(output!=0u,"B1330 output pointer");
 // Original branch 0x565d23 <0 enters 0x565d25 and copies the packed input.
 m.w32(output,m.r32(packed_ptr));
 return output;
}
}

