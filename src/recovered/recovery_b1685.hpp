#pragma once
#include "recovered/global_b26_memory.hpp"
namespace ra2::recovered::b1685 {
using Memory=global_b26::Memory;
using Inputs=global_b26::Inputs;
// Adapter supplies actual SDK calls on its genuinely owned hidden HWND. This
// interface does not synthesize an API result or control foreign windows.
class Api {
public:
    virtual ~Api()=default;
    virtual unsigned destroy_window(unsigned hwnd)=0;
    virtual unsigned set_focus(unsigned hwnd)=0;
};
struct Observation {
    unsigned stage{},hwnd{},destroy_result{},focus_result{};
};
// Finite positive path only: one entry, input CX=entry HWND or0 (last),
// getter byte A27F64=1, normal empty registry, and B0DE50=NULL.
unsigned run(Memory&,const Inputs&,Api&,Observation&);
unsigned run(Memory&,const Inputs&,Api&);
}
