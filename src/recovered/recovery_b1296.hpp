#pragma once
#include "recovered/recovery_b1279.hpp"
#include "platform/x87_state.hpp"

namespace ra2::recovered::b1296 {
using Memory=b1279::Memory;
using Heap=b1279::Heap;
struct Inputs : b1279::Inputs {
    mutable ra2::platform::x87::State fp;
};
// Four map-cell category switch wrappers. The pointer argument addresses a
// borrowed packed coordinate; the Map receiver is a real B1279 zone cache.
unsigned run(unsigned root, Memory&, const Inputs&, Heap&);
}
