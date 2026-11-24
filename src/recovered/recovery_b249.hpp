#pragma once

#include "recovered/global_b26_memory.hpp"
#include "platform/file_heap_adapter249.hpp"

#include <cstdint>

namespace ra2::recovered::recovery_b249 {
using GuestMemory = ra2::recovered::global_b26::Memory;
using Inputs = ra2::recovered::global_b26::Inputs;
using FileHeap = ra2::platform::file_heap249::FileHeap;
using FileApi = ra2::platform::file_heap249::FileApi;

// One bounded successful current-directory wolinfo.ini route. Requires the
// original mapped PE/data pages, the exact nine-allocation CRT recipe, a fresh
// initialized CRT heap, and a real file containing
// "[Ask]\\r\\nAddMatchBuddies=yes\\r\\n". Full EAX, caller words, API events, x87 preservation and the stated heap/image bytes passed 512 unmasked original/C++ comparisons for the six recorded spellings.
std::uint32_t fun_0072da70(GuestMemory&, const Inputs&, FileHeap&, FileApi&);
}
