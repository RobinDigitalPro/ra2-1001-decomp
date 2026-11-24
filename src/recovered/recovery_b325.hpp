#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/small_crt_heap_win32.hpp"
#include "platform/observed_locale325.hpp"
namespace ra2::recovered::recovery_b325 {
using Memory=global_b26::Memory;using Inputs=global_b26::Inputs;
using Heap=ra2::platform::small_crt_heap::Heap;using Counter=ra2::platform::locale325::Counter;
unsigned fun_0075ca70(Memory&,const Inputs&,Heap&,Counter&);
}
