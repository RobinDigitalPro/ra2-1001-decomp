#pragma once
#include "recovered/global_b26_memory.hpp"
namespace ra2::recovered::b1687 {
using Memory=global_b26::Memory;
using Inputs=global_b26::Inputs;
// Real SDK/CRT services only. The adapter forwards to Enter/LeaveCriticalSection,
// 76F385 fopen and 76DFFC fread on genuinely produced FILE32/owned disk handles.
// It must not call original 1221F0/8F50/90E0/9020 or fabricate library results.
// All Memory views of existing owner/node/backing/public pages are installed
// before run; these methods require no guest-time Memory::add/bookkeeping.
class Services {
public:
    virtual ~Services()=default;
    virtual void enter(unsigned critical_section)=0;
    virtual void leave(unsigned critical_section)=0;
    virtual unsigned open(unsigned filename,unsigned mode)=0;
    virtual unsigned read(unsigned destination,unsigned size,unsigned count,unsigned file)=0;
};
struct Observation {
    unsigned stage{},opens{},reads{},cursor_passes{},commits{};
    unsigned owner{},node{},destination{},file{},requested{},transferred{};
    unsigned local_count{},transfer_return{};
};
// Finite positive normal singleton: actual 8710/8A60 tail2800/8990/8B50
// producers, both records selected, selector0 receiver, genuine own rb file
// exactly10240 bytes. Owner/node/backing are distinct actual live allocations.
// Only Root1221F0 is proposed for credit; helpers are locally translated, not
// additional recoveries. Caller16 remains unchanged. RET0/full EAX0 or1.
unsigned run(Memory&,const Inputs&,Services&,Observation&);
unsigned run(Memory&,const Inputs&,Services&);
}
