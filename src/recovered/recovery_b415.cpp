#include "recovery_b415.hpp"
#include <cstdint>
#include <stdexcept>
namespace ra2::recovered::strings415 {
namespace {
std::uint32_t length(Heap& h,std::uint32_t p){std::uint32_t n=0;while(h.r8(p+n)!=0u)++n;return n;}
std::uint32_t allocate(Heap& h,std::uint32_t n){const auto p=h.allocate(n);if(!p)throw std::runtime_error("B415 HeapAlloc failed on success-only route");return p;}
}
std::uint32_t fun_00759d20(Memory& m,const Inputs& i,Heap& h){
    const auto slot=i.cx,old=m.r32(slot);
    if(!old)throw std::domain_error("B415 requires a nonnull owned input string");
    const auto needle=i.arg[0]&0xffu;
    bool changed=false;
    for(;;){
        const auto n=length(h,old);std::uint32_t at=0;
        while(at<n&&h.r8(old+at)!=needle)++at;
        if(at==n)break;
        changed=true;
        // Original memmove copies only the suffix characters; the root writes
        // the new terminator separately, leaving bytes beyond it untouched.
        for(std::uint32_t k=at;k+1u<n;++k)h.w8(old+k,h.r8(old+k+1u));
        h.w8(old+n-1u,0u);
    }
    if(!changed)throw std::domain_error("B415 only the positive deletion route is accepted");
    const auto n=length(h,old),fresh=allocate(h,n+1u);
    for(std::uint32_t k=0;k<=n;++k)h.w8(fresh+k,h.r8(old+k));
    const auto freed=h.release(old);
    if(freed!=1u)throw std::runtime_error("B415 HeapFree failed on success-only route");
    m.w32(slot,fresh);
    if(changed)i.arg[0]=(i.arg[0]&0xffffff00u)|1u; // original writes byte [ESP+0x14] and reloads it for MOV AL,BL.
    // MOV AL,BL after the original HeapFree call preserves upper EAX bits.
    return (freed&0xffffff00u)|(changed?1u:0u);
}
}
