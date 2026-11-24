#pragma once
#include "recovered/global_b26_memory.hpp"

namespace ra2::recovered::construct_b102 {
using global_b26::Inputs;
using global_b26::Memory;

#define RA2_B102_DECL(rva) std::uint32_t fun_##rva(Memory&, const Inputs&)
RA2_B102_DECL(00402190); RA2_B102_DECL(0041ed70); RA2_B102_DECL(0042bf70);
RA2_B102_DECL(00465080); RA2_B102_DECL(004b4910); RA2_B102_DECL(004b8d10);
RA2_B102_DECL(0052d3c0); RA2_B102_DECL(0065f9d0); RA2_B102_DECL(0066a9e0);
RA2_B102_DECL(0067ee10); RA2_B102_DECL(0067f010); RA2_B102_DECL(006a9bc0);
RA2_B102_DECL(006abea0); RA2_B102_DECL(006aca80); RA2_B102_DECL(006db0a0);
RA2_B102_DECL(006ddc60);
#undef RA2_B102_DECL
}
