#pragma once
#include "recovered/global_b26_memory.hpp"
namespace ra2::recovered::recovery_b349 {
using Memory=global_b26::Memory;using Inputs=global_b26::Inputs;
// stack_minus8 additionally supplies the pre-entry word at entryESP-4 in this
// exact bridge. Its high three bytes become externally observable padding.
unsigned fun_00698660(Memory&,const Inputs&);
}
