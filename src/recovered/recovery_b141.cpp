#include "recovered/recovery_b141.hpp"
#include <stdexcept>

namespace ra2::recovered::recovery_b141 {
namespace {
constexpr std::uint32_t kSelector1=0x00a5a89cu;
constexpr std::uint32_t kSelector2=0x00a5a8a0u;
constexpr std::uint32_t kSelector3=0x00a5a8b0u;
constexpr std::uint32_t kSelector4=0x00a5a8a4u;
constexpr std::uint32_t kSelector5=0x00a5a8a8u;
constexpr std::uint32_t kSelector6=0x00a5a8acu;
constexpr std::uint32_t kString1=0x007d11c8u;
constexpr std::uint32_t kString2=0x007d11ccu;
constexpr std::uint32_t kString3=0x007d11d0u;
constexpr std::uint32_t kString4=0x007d11d4u;
constexpr std::uint32_t kString5=0x007d11d8u;
constexpr std::uint32_t kString6=0x007d11dcu;
void require(bool condition,const char* message){if(!condition)throw std::domain_error(message);}
std::uint32_t original_string_assignment(Memory&m,std::uint32_t receiver,
                                        std::uint32_t source,Heap&heap){
    require(receiver!=0,"bounded assignment needs receiver");
    require(source!=0,"selected original static string pointer must be nonnull");
    // 0x359260 first clears [receiver], then counts/copies the NUL too.
    m.w32(receiver,0); // original clears the receiver before strlen
    std::uint32_t count=0;
    for(;count<11u;++count)if(m.r8(source+count)==0)break;
    require(count<11u,"source exceeds the exact selected static-string bounds");
    ++count;
    const auto allocation=heap.allocate(count);          // 0x759286 -> 0x36d957
    require(allocation!=0,"successful genuine small-CRT allocation required");
    m.w32(receiver,allocation);                          // 0x75928e
    heap.w8(allocation,0);                               // 0x759292
    for(std::uint32_t k=0;k<count;++k)                   // 0x759297..0x7592ba
        heap.w8(allocation+k,static_cast<std::uint8_t>(m.r8(source+k)));
    return receiver;                                     // 0x7592bd; RET 4
}
}

std::uint32_t fun_005c59d0(Memory&m,const Inputs&i,Heap&heap){
    const auto receiver=i.cx;
    const auto selector=i.dx;
    std::uint32_t source_pointer_cell=kString3;           // final default @Waiting@
    if(selector==m.r32(kSelector1)) source_pointer_cell=kString1;
    else if(selector==m.r32(kSelector2)) source_pointer_cell=kString2;
    else if(selector==m.r32(kSelector3)) source_pointer_cell=kString3;
    else if(selector==m.r32(kSelector4)) source_pointer_cell=kString4;
    else if(selector==m.r32(kSelector5)) source_pointer_cell=kString5;
    else if(selector==m.r32(kSelector6)) source_pointer_cell=kString6;
    const auto source=m.r32(source_pointer_cell);
    return original_string_assignment(m,receiver,source,heap); // 0x5c59e2..0x5c5a74
}
}
