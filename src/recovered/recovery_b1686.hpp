#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"
namespace ra2::recovered::b1686 {
using Memory=global_b26::Memory;
using Inputs=global_b26::Inputs;
using Heap=platform::ordinary_heap::Heap;
// A real library service, not a replacement Root/callee oracle. The adapter
// calls the already qualified original CRT fgets on its genuinely produced
// FILE32; writes must be visible through the same Memory spans passed to run.
class Stdio {
public:
    virtual ~Stdio()=default;
    virtual unsigned read_line(unsigned buffer,unsigned limit,unsigned file)=0;
};
struct Observation {
    unsigned stage{},reads{},key_length{},value_length{},allocation{},requested{};
};
// Exactly one key (1..31 ASCII letters), one quoted value (1..31 ASCII
// letters), END line and actual EOF. LF lines; no spaces/escapes/annotation.
// Public record/pointer tables are genuinely caller-owned; no factory claim.
unsigned run(Memory&,const Inputs&,Heap&,Stdio&,Observation&);
unsigned run(Memory&,const Inputs&,Heap&,Stdio&);
}
