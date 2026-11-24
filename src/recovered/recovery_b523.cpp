#include "recovery_b523.hpp"
#include "recovered/allocation_wrappers.hpp"
#include <stdexcept>

namespace ra2::recovered::recovery_b523 {
namespace {
using namespace ra2::platform;
using x87::State;
unsigned allocate(std::uint32_t bytes, std::uint32_t flag, void* context) {
    if (flag != 1u) throw std::domain_error("523 allocation wrapper flag");
    return static_cast<Heap*>(context)->allocate(bytes);
}
std::uint32_t clamp_bucket(std::uint32_t ecx) {
    auto v = ra2::recovered::global_b26::sar(ecx << 6u, 8u);
    if (static_cast<std::int32_t>(v) >= 63) v = 63;
    if (static_cast<std::int32_t>(v) <= 21) v = 21;
    return v;
}
void initialize_xyz(Memory& m, Heap& heap, std::uint32_t self, std::uint32_t x,
                    std::uint32_t y, std::uint32_t z, std::uint32_t bucket,
                    std::uint32_t flags) {
    // Instruction-equivalent writes of the reached 0x5d5c10 body. Its native
    // original closure remains mapped and compared by the private bridge.
    heap.w32(self,x);heap.w32(self+4u,y);heap.w32(self+8u,z);
    heap.w32(self+0x0cu,0u);heap.w32(self+0x10u,bucket);heap.w32(self+0x14u,0u);
    const auto count=m.r32(0x00a5ad30u),capacity=m.r32(0x00a5ad28u);
    if (count>=capacity) throw std::domain_error("523 registry capacity route is excluded");
    const auto registry=m.r32(0x00a5ad24u);
    m.w32(registry+count*4u,self);m.w32(0x00a5ad30u,count+1u);
    heap.w32(self+0x14u,flags);
}
}

std::uint32_t fun_0047f220(Memory& m, const Inputs& i, Heap& heap) {
    if (m.r32(0x00a2876cu)!=0u) throw std::domain_error("523 fresh resource gate requires A2876C zero");
    const std::uint32_t flags=i.arg[4];
    if ((flags&0x0fu)==0u || i.arg[3]!=1u) throw std::domain_error("523 bounded flags/arg3 route required");
    if (!i.dx) throw std::domain_error("523 object pointer required");
    const auto object_weight=m.r32(i.dx+0x13cu);
    if (object_weight!=0u && object_weight!=0xbf800000u)
        throw std::domain_error("523 finite selector route supports only +0 or -1 weights");

    auto fp=i.fp;
    fp.load32(object_weight);
    fp.compare32(m.r32(0x00785738u));
    const auto status=fp.status();
    if ((status&0x4100u)==0u) throw std::domain_error("523 nonpositive x87 branch required");
    fp.pop_st0();
    i.fp=fp;

    const auto bucket=clamp_bucket(i.cx);
    const ra2::recovered::AllocationWrapperOperations operations{allocate,nullptr,&heap};
    const auto self=ra2::recovered::fun_0076d957(24u,operations);
    if (!self) throw std::domain_error("523 successful 24-byte allocation required");
    initialize_xyz(m,heap,self,i.arg[0],i.arg[1],i.arg[2],bucket,flags);
    return self;
}
}
