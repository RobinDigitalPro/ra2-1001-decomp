#pragma once
#include "leaf_memory.hpp"
#include <array>
#include <cstdint>
#include <vector>
#include <stdexcept>

namespace ra2::recovered::global_b26 {
// Numeric original-address spans. Pointer graphs may cross declared spans;
// no original class or contiguous global-object layout is implied.
class Memory {
    std::vector<leaf::Memory*> spans_;
    void (*observer_)(std::uint32_t, bool, void*) = nullptr;
    void* observer_context_ = nullptr;
    leaf::Memory& span(std::uint32_t a) const {
        for (auto* p:spans_) if(a>=p->base() && a-p->base()<p->size()) return *p;
        throw std::out_of_range("Block26 address outside declared spans");
    }
public:
    // Optional portable fixture instrumentation. Native execution uses declared
    // spans and independent page guards; observations do not prove x86 coverage.
    void observe(void (*callback)(std::uint32_t, bool, void*), void* context) {
        observer_ = callback; observer_context_ = context;
    }
    void add(leaf::Memory& p) {
        const auto end=std::uint64_t(p.base())+p.size();
        if(!p.size() || end>0x100000000ull) throw std::invalid_argument("invalid Block26 span");
        for(auto* q:spans_)
            if(std::uint64_t(p.base())<std::uint64_t(q->base())+q->size() && std::uint64_t(q->base())<end)
                throw std::invalid_argument("overlapping Block26 spans");
        spans_.push_back(&p);
    }
    std::uint32_t r8(std::uint32_t a) const {auto& p=span(a);if(observer_)observer_(a,false,observer_context_);return p.r8(a);}
    std::uint32_t r16(std::uint32_t a) const {return r8(a)|(r8(a+1u)<<8);}
    std::uint32_t r32(std::uint32_t a) const {return r16(a)|(r16(a+2u)<<16);}
    void w8(std::uint32_t a,std::uint32_t v) {auto& p=span(a);if(observer_)observer_(a,true,observer_context_);p.w8(a,v);}
    void w16(std::uint32_t a,std::uint32_t v) {w8(a,v);w8(a+1u,v>>8);}
    void w32(std::uint32_t a,std::uint32_t v) {w16(a,v);w16(a+2u,v>>16);}
};
struct Inputs {
    std::uint32_t ax=0,cx=0,dx=0;
    // The raw caller argument area is observable writable memory in a few
    // original bodies. Native validation compares all sixteen words afterward.
    mutable std::array<std::uint32_t,16> arg{};
    // Explicit raw entry state for bodies that observe prior stack contents.
    std::uint32_t stack_minus8=0;
    std::uint32_t arithmetic_flags=0;
};
using Function=std::uint32_t(*)(Memory&,const Inputs&);
struct Entry {std::uint32_t rva;Function function;};
inline std::int32_t s32(std::uint32_t v) {return leaf::s32(v);}
inline std::uint32_t sx8(std::uint32_t v) {return leaf::sx8(v);}
inline std::uint32_t sx16(std::uint32_t v) {return leaf::sx16(v);}
inline std::uint32_t sar(std::uint32_t v,unsigned n) {return leaf::sar(v,n);}
// Signed double-width arithmetic is evaluated in int64_t, avoiding signed
// 32-bit overflow in the portable reconstruction.
inline std::uint32_t imul_high(std::uint32_t a,std::uint32_t b) {
    return std::uint32_t(std::uint64_t(std::int64_t(s32(a))*std::int64_t(s32(b)))>>32);
}
inline std::uint32_t idiv_quotient(std::uint32_t a,std::uint32_t b) {
    if(!b || (a==0x80000000u && b==0xffffffffu)) throw std::domain_error("excluded Block26 IDIV fault");
    return std::uint32_t(std::int64_t(s32(a))/std::int64_t(s32(b)));
}
inline std::uint32_t idiv_remainder(std::uint32_t a,std::uint32_t b) {
    if(!b || (a==0x80000000u && b==0xffffffffu)) throw std::domain_error("excluded Block26 IDIV fault");
    return std::uint32_t(std::int64_t(s32(a))%std::int64_t(s32(b)));
}
const std::array<Entry,55>& entries_a();
const std::array<Entry,55>& entries_b();
const std::array<Entry,52>& entries_c();
} // namespace ra2::recovered::global_b26
