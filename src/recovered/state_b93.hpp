#pragma once
#include "global_b26_memory.hpp"

namespace ra2::recovered::state_b93 {
using global_b26::Inputs;
using global_b26::Memory;

#define RA2_B93_DECL(rva) std::uint32_t fun_##rva(Memory&, const Inputs&)
RA2_B93_DECL(004070f0); RA2_B93_DECL(0044b470); RA2_B93_DECL(004688d0);
RA2_B93_DECL(00475440); RA2_B93_DECL(00569a30); RA2_B93_DECL(005c28e0);
RA2_B93_DECL(0062a680); RA2_B93_DECL(00653260);
RA2_B93_DECL(00674090); RA2_B93_DECL(00674d10); RA2_B93_DECL(00674ec0); RA2_B93_DECL(006ae600);
RA2_B93_DECL(006cd1f0); RA2_B93_DECL(006cd5f0); RA2_B93_DECL(006d78d0);
RA2_B93_DECL(006dd460); RA2_B93_DECL(00756ea0); RA2_B93_DECL(00771aee);
#undef RA2_B93_DECL
}
