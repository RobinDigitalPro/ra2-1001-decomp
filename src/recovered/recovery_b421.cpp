#include "recovery_b421.hpp"
#include "recovered/allocation_wrappers.hpp"
#include "recovered/release_families.hpp"
#include <algorithm>
#include <array>
#include <cstdint>
#include <stdexcept>

namespace ra2::recovery_b421 {
namespace {
std::int32_t s32(std::uint32_t x) { return ra2::recovered::leaf::s32(x); }
std::uint32_t release_null(std::uint32_t p,void*) { if(p)throw std::domain_error("B421 constructor excludes nonnull CRT release");return 0u; }
}

// The original constructor's virtual helper sees a freshly initialized empty
// vector: ptr=0 and owned=0. Its accepted 0x2e11d0 contract clears extra,
// ownership and size; the following root call frees null through 0x36d67b.
std::uint32_t fun_006e05a0(Memory& m,const Inputs& in) {
    const auto self=in.cx, vector=self+0x234u;
    if(m.r32(0x798804)!=0x6e11d0)throw std::domain_error("421 original constructor dispatch");
    m.w32(self+4u,0u); m.w32(self+8u,in.arg[0]); m.w8(self+0xcu,0u);
    m.w32(self+0x228u,1000u); m.w32(self+0x230u,10000u);
    m.w32(vector+4u,0u); m.w32(vector+8u,0u); m.w8(vector+0xcu,1u); m.w8(vector+0xdu,0u);
    m.w32(vector,0x7987f8u); m.w32(vector+0x10u,0u); m.w32(vector+0x14u,10u);
    m.w32(self,0x7987dcu);
    m.w32(self+0x24cu,0u); m.w32(self+0x250u,0u); m.w32(self+0x254u,0u);
    m.w8(self+0x258u,0u); m.w32(self+0x25cu,0u);
    // Compose accepted 0x2e11d0 over a checked 24-byte guest view of its
    // embedded vector. This fixture's initialized ptr/owned fields are zero.
    std::array<std::uint8_t,24> vector_bytes{};
    for(unsigned k=0;k<vector_bytes.size();++k)vector_bytes[k]=static_cast<std::uint8_t>(m.r8(vector+k));
    ra2::recovered::leaf::Memory vector_memory(vector_bytes.data(),vector,static_cast<std::uint32_t>(vector_bytes.size()));
    ra2::recovered::leaf::Inputs vector_inputs;vector_inputs.cx=vector;
    const ra2::recovered::AllocationWrapperOperations no_release{nullptr,nullptr,nullptr};
    (void)ra2::recovered::fun_006e11d0(vector_memory,vector_inputs,no_release);
    for(unsigned k=0;k<vector_bytes.size();++k)m.w8(vector+k,vector_bytes[k]);
    // Compose accepted 0x36d67b on the root's null pointer. The adapter
    // rejects every pointer except the one this route proves.
    if (m.r32(self+0x24cu)!=0u) throw std::domain_error("B421 constructor null-release precondition");
    const ra2::recovered::AllocationWrapperOperations null_release{nullptr,release_null,nullptr};
    (void)ra2::recovered::fun_0076d67b(0u,null_release);
    return self;
}

// Exact positive-sized rectangle intersection against the bounds returned by
// accepted 0x11290 through the surface vtable. Outputs occupy receiver+0x10.
std::uint32_t fun_00430180(Memory& m,const Inputs& in) {
    const auto self=in.cx;
    const auto dims=m.r32(self+4u),surface=m.r32(self+0xcu);
    const std::int32_t width=s32(m.r32(dims)),height=s32(m.r32(dims+4u));
    const std::int32_t boundw=s32(m.r32(surface+4u)),boundh=s32(m.r32(surface+8u));
    if(m.r32(surface)!=0x785ef8||m.r32(0x785f70)!=0x411290||width<=0||height<=0||boundw<=0||boundh<=0)throw std::domain_error("421 authentic positive surface route");
    std::int32_t x=s32(in.arg[0]),y=s32(in.arg[1]);
    std::int32_t outx=0,outy=0,outw=0,outh=0;
    if (boundw>0 && boundh>0 && width>0 && height>0) {
        in.arg[1]=static_cast<std::uint32_t>(boundh); // original MOV [ESP+3c],EDX
        if(std::int64_t(width)+std::min<std::int32_t>(x,0)>=1)
            in.arg[0]=0u; // original MOV [ESP+38],EDI after the left-bound adjustment
        std::int64_t x0=x,y0=y,x1=x0+width,y1=y0+height;
        if(x0<0)x0=0;if(y0<0)y0=0;
        if(x1>boundw)x1=boundw;if(y1>boundh)y1=boundh;
        if(x1-x0>=1 && y1-y0>=1) {
            outx=static_cast<std::int32_t>(x0); outy=static_cast<std::int32_t>(y0);
            outw=static_cast<std::int32_t>(x1-x0); outh=static_cast<std::int32_t>(y1-y0);
        }
    }
    m.w32(self+0x10u,static_cast<std::uint32_t>(outx));
    m.w32(self+0x14u,static_cast<std::uint32_t>(outy));
    m.w32(self+0x18u,static_cast<std::uint32_t>(outw));
    m.w32(self+0x1cu,static_cast<std::uint32_t>(outh));
    return static_cast<std::uint32_t>(outx);
}
}
