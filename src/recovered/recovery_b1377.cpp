#include "recovered/recovery_b1377.hpp"
#include <stdexcept>
namespace ra2::recovered::b1377 {
// RVA119C00. Explicit optional-selector branch: no coordinate or distance
// query, but a genuine nonempty registry and full selected-object output.
std::uint32_t fun_00519c00(Memory& m,const Inputs& i){
    using U=std::uint32_t;
    const U count=m.r32(0xa288b0),table=m.r32(0xa288a4);
    if(i.cx!=0||i.dx!=0||count<1||count>16||table==0)
        throw std::domain_error("B1377 bounded nonempty optional no-distance query");
    std::int32_t best_priority=-1;
    U best_distance=0x7fffffff,selected=0;
    for(U index=0;index<count;++index){
        const U object=m.r32(table+4*index);
        if(object==0||(m.r8(object+0x14)&1)!=0)
            throw std::domain_error("B1377 requires nonnull borrowed priority-zero records");
        // Original519C4C initializes priority0. The clear flag branches before
        // every virtual call.519CDF..519CF2 skips distance with both selectors0.
        const std::int32_t priority=0;
        const U distance=0x7fffffff;
        if(priority<best_priority)continue;
        if(priority>best_priority){best_priority=priority;}
        else if(distance>=best_distance)continue;
        selected=object;best_distance=distance;
    }
    // Original519DC9 loads the whole pointer; no partial-EAX masking.
    return selected;
}
}
