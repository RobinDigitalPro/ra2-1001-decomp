#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/x87_state.hpp"
#include <array>

namespace ra2::recovered::b1690 {
using Memory=global_b26::Memory;
using Inputs=global_b26::Inputs;
// Actual historical wide CRT library service, not an Original game callback.
// Arguments x/y carry the exact signed32 vararg bit patterns.
struct WideStdio {
    virtual ~WideStdio()=default;
    virtual unsigned format(unsigned destination,unsigned format,
                            unsigned x_bits,unsigned y_bits)=0;
};
struct Observation {
    unsigned stage=0,predicate_calls=0,getter_calls=0,child_calls=0,formats=0;
    unsigned root_receiver=0,root_vptr=0,predicate_target=0,predicate_al=0;
    unsigned mouse_receiver=0,mouse_vptr=0,getter_target=0,getter_output=0;
    std::array<unsigned,2> getter_values{},screen{};
    std::array<unsigned,6> child_arguments{};
    // Source-owned six-argument adapter bookkeeping, never a private Original
    // frame capture. In particular word9 is not an Original input requirement.
    std::array<unsigned,16> child_words_after{};
    unsigned child_result=0,packed_cell=0,object=0,flag_a=0,flag_b=0;
    std::array<unsigned,3> world{};
    unsigned action_before=0,action_after=0,format_x_bits=0,format_y_bits=0;
    unsigned format_result=0;
    platform::x87::Image entry_fp{},child_fp{};
};
// Mandatory finite-domain/declared-span check, invoked outside the observed
// Root boundary. Ownership and authentic code/data receipts belong to harness.
void preflight(Memory&,const Inputs&);
// Selected positive coordinate-format route only. Requires preflight and
// physical entry CW037F/empty tags, SW containing only TOP; all80 bytes arbitrary.
// Mutable input.arg[0] models the actual child output byte alias. Native bridge
// handles RET4. No constructor history or other Root branches are claimed.
unsigned run(Memory&,const Inputs&,WideStdio&,Observation&);
}
