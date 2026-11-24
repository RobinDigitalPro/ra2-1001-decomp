#pragma once
#include "recovered/recovery_b1211.hpp"
#include "platform/x87_state.hpp"

namespace ra2::recovered::recovery_b1692 {
using U=std::uint32_t;
using Memory=b1211::Memory;
using Inputs=b1211::Inputs;
using Heap=b1211::Heap;
// A checked supplied pre-existing state, not an executed placement producer.
struct Projection {
 U receiver{},type{},blob{},cell{},table{},types{},cache4{},cache10{},rules{};
};
// Read-only setup validation, outside the observed guest boundary. The supplied
// image is inspected as bytes; this function neither captures nor restores FP.
Projection preflight(U root,Memory&,const Inputs&,Heap&,
                     const ra2::platform::x87::Image& entry);
// Only RVA125CE0 / operation0 / the checked one-cell positive removal route.
// Call preflight before entering the guest boundary; do not mutate its graph.
U run(U root,Memory&,const Inputs&,Heap&,const Projection&);
}
