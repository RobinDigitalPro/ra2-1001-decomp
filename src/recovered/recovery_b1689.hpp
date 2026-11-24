#pragma once
#include "recovered/recovery_b1279.hpp"

namespace ra2::recovered::b1689 {
using Memory = b1279::Memory;
using Inputs = b1279::Inputs;
using Heap = b1279::Heap;
struct Span { unsigned base, bytes; };
// Borrowed public allocations. The harness proves genuine ownership and
// installs the same spans in Memory/the production MixedHeap1279 adapter.
struct Bounds {
    Span cache;   // 361 four-byte cache records
    Span header;  // actual 16-byte cache header
    Span vectors; // cookie DWORD + 256 genuine 24-byte empty headers
    Span grid;    // 361 records of 0x50 bytes
    Span table;   // public Map+138 pointer table
};
void preflight(Memory&, Heap&, const Bounds&);
// The current physical x87 image is the entry image. The real arithmetic
// leaves its resulting physical image active through the production heap
// composition and at return. The outer harness restores its host state.
unsigned run(unsigned root, Memory&, const Inputs&, Heap&, const Bounds&);
}

