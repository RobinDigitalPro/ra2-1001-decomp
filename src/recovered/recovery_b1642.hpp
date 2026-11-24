#pragma once
#include "recovered/recovery_b936.hpp"
#include "recovered/recovery_b1109.hpp"

namespace ra2::recovered::b1642 {
// Private fixed-recipe proposal. This is not an accepted recovered entry.
std::uint32_t run(global_b26::Memory&, const floating_b61::Inputs&,
                  b979::Heap&, const recovery_b936::Ops&);
}
