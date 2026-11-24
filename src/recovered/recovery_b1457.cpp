#include "recovered/recovery_b1457.hpp"
#include "recovered/direct_b33_memory.hpp"
#include <stdexcept>
#include <vector>
namespace ra2::recovered::b1457 {
namespace {
constexpr std::uint32_t kReturn=0x13579bdfu;
constexpr std::uint32_t kStackBase=0x7d000000u;
constexpr std::uint32_t kRootSp=kStackBase+0x8000u;
constexpr std::uint32_t kChildSp=kStackBase+0x7000u;
}
std::uint32_t fun_00428cf0(Memory& m,const Inputs& i) {
    std::vector<std::uint8_t> stack(0x10000u);
    ra2::recovered::leaf::Memory stack_span(stack.data(),kStackBase,std::uint32_t(stack.size()));
    Memory mem=m;mem.add(stack_span);
    const auto directions=i.arg[1];
    const auto count=i.arg[3];
    const auto second_count=i.arg[4];
    const auto output=i.arg[5];
    if(!directions||!output||count<1u||count>32u||second_count!=0u)
        throw std::domain_error("B1457 finite ordinary-prefix domain");
    const auto dir_end=std::uint64_t(directions)+4u*(std::uint64_t(count)+1u);
    const auto out_end=std::uint64_t(output)+4u;
    if(dir_end>0x100000000ull||out_end>0x100000000ull||
       (std::uint64_t(output)<dir_end&&std::uint64_t(directions)<out_end)||
       (std::uint64_t(output)<std::uint64_t(kRootSp)+68u&&std::uint64_t(kRootSp)<out_end)||
       (std::uint64_t(directions)<std::uint64_t(kRootSp)+68u&&std::uint64_t(kRootSp)<dir_end))
        throw std::domain_error("B1457 finite disjoint storage domain");
    static constexpr std::uint32_t table_words[8]={0xffff0000u,0xffff0001u,0x00000001u,0x00010001u,0x00010000u,0x0001ffffu,0x0000ffffu,0xffffffffu};
    for(std::uint32_t k=0;k<8u;++k)if(mem.r32(0x839da0u+4u*k)!=table_words[k])
        throw std::domain_error("B1457 requires the genuine initializer-produced direction table");
    if(mem.r32(directions+4u*count)!=8u)
        throw std::domain_error("B1457 requires the root's first 8 marker at array[count]");
    for(std::uint32_t n=0;n<count;++n)
        if(mem.r32(directions+4u*n)>7u)
            throw std::domain_error("B1457 ordinary direction outside 0..7");
    // Root 0x429074 seeds its working coordinate and jumps over 0x428D3C..0x429071.
    // At 0x429090 it calls only the unchanged accepted 0x42AD50 leaf.
    // Its ECX/EDX pointers address the root's real caller words arg[1] and arg[5].
    mem.w32(kRootSp,kReturn);
    for(std::uint32_t n=0;n<16u;++n)mem.w32(kRootSp+4u+4u*n,i.arg[n]);
    auto coordinate=mem.r32(output);
    mem.w32(kRootSp+4u+4u*5u,coordinate);
    const auto& table=ra2::recovered::direct_b33::entries_a();
    ra2::recovered::direct_b33::Function leaf=nullptr;
    for(const auto& e:table)if(e.rva==0x2ad50u){leaf=e.function;break;}
    if(!leaf)throw std::logic_error("accepted 0x2AD50 entry missing");
    for(std::uint32_t n=0;n<count;++n){
        const auto direction=mem.r32(directions+4u*n);
        const auto child_direction=direction;
        mem.w32(kChildSp,kReturn);mem.w32(kChildSp+4u,child_direction);
        for(std::uint32_t k=1u;k<16u;++k)mem.w32(kChildSp+4u+4u*k,0u);
        ra2::recovered::direct_b33::State state{};
        state.cx=kRootSp+4u+4u*1u; // After PUSH: ECX=(T-4)+50=T+4C, caller arg[1] slot
        state.dx=kRootSp+4u+4u*5u; // original EDX=T+5C: caller arg[5] slot
        ra2::recovered::direct_b33::Frame frame{kChildSp,kChildSp,kReturn,kReturn,4u,16u,0u};
        leaf(mem,state,frame,ra2::recovered::direct_b33::Operations{});
        if(frame.sp!=kChildSp+8u)
            throw std::runtime_error("B1457 0x2AD50 RET4 child frame mismatch");
        coordinate=mem.r32(kRootSp+4u+4u*1u);
        mem.w32(kRootSp+4u+4u*5u,coordinate);
    }
    mem.w32(output,coordinate);
    for(std::uint32_t n=0;n<16u;++n)i.arg[n]=mem.r32(kRootSp+4u+4u*n);
    return count;
}
}





