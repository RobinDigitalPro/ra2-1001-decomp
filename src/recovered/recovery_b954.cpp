#define NOMINMAX
#include <windows.h>
#include <objidl.h>
#include <cstdint>
#include <stdexcept>
#include "recovered/recovery_b954.hpp"
#include "platform/ole_stream951.hpp"
namespace ra2::recovered::recovery_b954 {
namespace {
inline constexpr std::uint32_t kRegistry=0x00aa5370u;
std::uint32_t read_dword(std::uint32_t stream_address) {
    ra2::platform::ole_stream951::need(stream_address==ra2::platform::ole_stream951::Stream::current().address(),"954 actual stream identity");
    auto* stream=reinterpret_cast<IStream*>(std::uintptr_t(stream_address));
    std::uint32_t value=0;
    const HRESULT hr=stream->Read(&value,4,nullptr);
    if(hr!=S_OK) throw std::runtime_error("B954 fixture requires S_OK genuine IStream::Read");
    return value;
}
void register_fixup(Memory& m,std::uint32_t slot) {
    const std::uint32_t value=m.r32(slot);
    // 0x295170: null slot returns immediately. Non-null slots append to the
    // preallocated (value,slot address) registry and are then zeroed.
    if(value) {
        const auto capacity=m.r32(kRegistry+0x0cu);
        const auto count=m.r32(kRegistry+0x14u);
        if(count>=capacity) throw std::domain_error("B954 no-growth helper bound violated");
        const auto entries=m.r32(kRegistry+0x08u);
        m.w32(kRegistry+0x14u,count+1u);
        m.w32(entries+count*8u,value);
        m.w32(entries+count*8u+4u,slot);
    }
    m.w32(slot,0u);
}
}
std::uint32_t fun_00532ce0(Memory& m,const Inputs& i) {
    const auto receiver=i.cx;
    const auto stream=i.arg[0]; // EDI preserves it while caller arg0 is reused as Read output.
    const auto n=read_dword(stream);
    i.arg[0]=n;
    if(static_cast<std::int32_t>(n)>0) {
        const auto values=m.r32(receiver+4u),capacity=m.r32(receiver+8u);
        auto count=m.r32(receiver+0x10u);
        for(std::uint32_t j=0;j<n;++j) {
            const auto value=read_dword(stream);
            if(count>=capacity) throw std::domain_error("B954 receiver growth vcall excluded");
            m.w32(receiver+0x10u,++count);
            m.w32(values+(count-1u)*4u,value);
        }
        for(std::uint32_t j=0;j<n;++j) register_fixup(m,values+j*4u);
    }
    return 0u;
}
std::uint32_t fun_00413400(Memory& m,const Inputs& i) {
    const auto receiver=i.cx;
    const auto stream=i.arg[0]; // EBX preserves stream pointer across 400 descriptors.
    for(std::uint32_t descriptor=0;descriptor<400u;++descriptor) {
        const auto d=receiver+8u+descriptor*0x18u;
        const auto n=read_dword(stream);
        i.arg[0]=n; // Original's [entry ESP+4] caller-word output slot.
        if(static_cast<std::int32_t>(n)<=0) continue;
        const auto capacity=m.r32(d),values=m.r32(d-4u);
        auto count=m.r32(d+8u);
        for(std::uint32_t j=0;j<n;++j) {
            const auto value=read_dword(stream);
            if(count>=capacity) throw std::domain_error("B954 13400 growth vcall excluded");
            m.w32(d+8u,++count);
            m.w32(values+(count-1u)*4u,value);
        }
        for(std::uint32_t j=0;j<n;++j) register_fixup(m,values+j*4u);
    }
    return 0u;
}
}
