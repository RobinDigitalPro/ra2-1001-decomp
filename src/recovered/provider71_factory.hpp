#pragma once
#include "recovered/global_b26_memory.hpp"

namespace ra2::recovered::provider71_factory {
using Memory=global_b26::Memory;
using Inputs=global_b26::Inputs;
struct Operations {
    void* context;
    unsigned (*allocate)(void*,Memory&,unsigned);
};
// Finite cold manager at A285C8, mode4, two successful 1x2 constructors.
unsigned fun_00523fb0(Memory&,const Inputs&,const Operations&);
}
