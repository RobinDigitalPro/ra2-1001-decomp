#include "recovered/recovery_b387.hpp"
#include "recovered/leaf_b57_c.hpp"
#include <cstdint>
#include <stdexcept>
#include <vector>

namespace ra2::recovered::recovery_b387 {
namespace {
std::uint32_t h16(Heap& h,std::uint32_t p){return h.r8(p)|(h.r8(p+1u)<<8);}
void hw16(Heap& h,std::uint32_t p,std::uint32_t v){h.w8(p,v);h.w8(p+1u,v>>8);}
std::uint32_t wide_length(Heap& h,std::uint32_t p){std::uint32_t n=0;while(h16(h,p+n*2u))++n;return n;}
std::uint32_t wide_length(Memory& m,std::uint32_t p){std::uint32_t n=0;while(m.r16(p+n*2u))++n;return n;}
std::uint32_t wide_find(Heap& h,std::uint32_t p,std::uint16_t ch){for(;;p+=2u){const auto v=h16(h,p);if(!v)return 0;if(v==ch)return p;}}
bool wide_contains(Memory& m,std::uint32_t p,std::uint16_t ch){for(;;p+=2u){const auto v=m.r16(p);if(!v)return false;if(v==ch)return true;}}
void heap_copy(Heap& h,std::uint32_t dst,std::uint32_t src,std::uint32_t bytes){for(std::uint32_t n=0;n<bytes;++n)h.w8(dst+n,h.r8(src+n));}
void heap_move(Heap& h,std::uint32_t dst,std::uint32_t src,std::uint32_t bytes){
    std::vector<std::uint8_t> temp(bytes);for(std::uint32_t n=0;n<bytes;++n)temp[n]=static_cast<std::uint8_t>(h.r8(src+n));
    for(std::uint32_t n=0;n<bytes;++n)h.w8(dst+n,temp[n]);
}
std::uint32_t allocate(Heap& h,std::uint32_t bytes){const auto p=h.allocate(bytes);if(!p)throw std::runtime_error("B387 ordinary HeapAlloc failed; success-only route");return p;}
void release(Heap& h,std::uint32_t p){if(h.release(p)!=1u)throw std::runtime_error("B387 actual HeapFree failed");}
}

std::uint32_t fun_0075ba50(Memory& m,const Inputs& i,Heap& h){
    const auto receiver=i.cx,old=m.r32(receiver);if(!old)return 0;
    const auto needle=static_cast<std::uint16_t>(i.arg[0]);std::uint32_t changed=0;
    for(;;){
        const auto p=wide_find(h,old,needle);if(!p)break;changed=1;
        const auto length=wide_length(h,old),index=(p-old)/2u;
        // Exact 0x75ba89..0x75baa5 count: EDI=2*length, ECX=(p-old)>>1,
        // then count=EDI-ECX-2; the original writes the final word NUL itself.
        const auto bytes=length*2u-index-2u;heap_move(h,p,p+2u,bytes);
        hw16(h,old+length*2u-2u,0);
    }
    const auto length=wide_length(h,old),request=(length+1u)*2u;
    const auto fresh=allocate(h,request);hw16(h,fresh,0);
    for(std::uint32_t n=0;n<=length;++n)hw16(h,fresh+n*2u,h16(h,old+n*2u));
    release(h,old);m.w32(receiver,fresh);
    return changed;
}

std::uint32_t fun_0075bb70(Memory& m,const Inputs& i,Heap& h){
    const auto receiver=i.cx,old=m.r32(receiver),set_slot=i.arg[0];
    const auto set=m.r32(set_slot);
    if(!old||!set_slot||!set)throw std::domain_error("B387 35bb70 covers nonnull owned string and nonnull pointer-to-pointer trim set only");
    const auto length=wide_length(h,old);if(!length)throw std::domain_error("B387 35bb70 requires nonempty input string");
    std::uint32_t index=length-1u;
    // Original walks backward while each old suffix word occurs anywhere in set.
    for(;;){
        const auto ch=static_cast<std::uint16_t>(h16(h,old+index*2u));
        if(!wide_contains(m,set,ch))break;
        if(index==0u)break;
        --index;
    }
    const auto keep=index+1u,bytes=(keep+1u)*2u;
    const auto temp=allocate(h,bytes);hw16(h,temp,0);
    for(std::uint32_t n=0;n<keep;++n)hw16(h,temp+n*2u,h16(h,old+n*2u));
    hw16(h,temp+keep*2u,0);
    release(h,old);
    const auto out=allocate(h,bytes);hw16(h,out,0);
    for(std::uint32_t n=0;n<=keep;++n)hw16(h,out+n*2u,h16(h,temp+n*2u));
    release(h,temp);m.w32(receiver,out);
    return 1u;
}

std::uint32_t fun_0075cf10(Memory& m,const Inputs& i,Heap& h){
    const auto out_slot=i.cx,source_slot=i.dx;
    auto source=m.r32(source_slot);const auto input_length=source?wide_length(m,source):0u;
    const auto bit_count=(input_length+1u)*16u; // original passes this exact bit count to 0x30c60.
    const auto output_bytes=1u+(bit_count-1u)/7u; // 8003 for 3500 units plus NUL.
    const auto converted=allocate(h,output_bytes);
    if(source){
        constexpr std::uint32_t base=0x10000000u,src_off=0x100u,dst_off=0x10000u;
        // 30c60 reads ceil(bit_count/8) source bytes and writes exactly
        // ceil(bit_count/7) output bytes. The final byte is part of the
        // written extent and contains the encoded source NUL bits.
        const auto source_bytes=(bit_count+7u)/8u;
        const auto need=dst_off+output_bytes;
        std::vector<std::uint8_t> scratch(need);
        for(std::uint32_t n=0;n<source_bytes;++n)scratch[src_off+n]=static_cast<std::uint8_t>(m.r8(source+n));
        ra2::recovered::leaf::Memory span(scratch.data(),base,static_cast<std::uint32_t>(scratch.size()));
        ra2::recovered::leaf::Inputs pack{};pack.cx=base+src_off;pack.dx=base+dst_off;pack.arg[0]=bit_count;
        const auto written=ra2::recovered::leaf::fun_00430c60(span,pack);
        if(written!=output_bytes)throw std::logic_error("30c60 output extent disagreement");
        for(std::uint32_t n=0;n<output_bytes;++n)h.w8(converted+n,scratch[dst_off+n]);
    }
    std::uint32_t length=0;while(length<output_bytes&&h.r8(converted+length)!=0u)++length;
    if(length==output_bytes)throw std::domain_error("B387 35cf10 requires a NUL within 30c60's written output extent");
    const auto bytes=length+1u;
    auto middle=allocate(h,bytes);h.w8(middle,0);
    heap_copy(h,middle,converted,bytes);release(h,converted);
    m.w32(out_slot,0u);
    const auto result=allocate(h,bytes);m.w32(out_slot,result);
    heap_copy(h,result,middle,bytes);release(h,middle);
    return out_slot;
}
}
