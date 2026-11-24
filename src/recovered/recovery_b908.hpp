#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"

namespace b908_draft {
using U=std::uint32_t;
U fun_006e4880(ra2::recovered::global_b26::Memory&,
               ra2::recovered::global_b26::Inputs&,
               ra2::platform::ordinary_heap::Heap&,
               U entry_esp,U crt_thread);
}
