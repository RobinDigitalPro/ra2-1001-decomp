// Keep the previously accepted caller and its translations unchanged.
#include "recovery_b212.cpp"
#include "recovery_b502.hpp"
namespace ra2::recovered::recovery_b212 {
static std::uint32_t invoke502(Memory&original,const Inputs&i,bool rectangle){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{entry,entry,0x76543210u};m.w32(entry,f.outer_return);
 for(unsigned k=0;k<16;++k)m.w32(entry+4+4*k,i.arg[k]);
 if(rectangle)f_0002de20(m,s,f,{});else f_00229ca0(m,s,f,{});
 i.fp=s.fp;for(unsigned k=0;k<16;++k)i.arg[k]=m.r32(entry+4+4*k);
 return s.ax;
}
}
namespace ra2::recovered::recovery_b502 {
std::uint32_t fun_0042de20(Memory&m,const Inputs&i){return recovery_b212::invoke502(m,i,true);}
std::uint32_t fun_00629ca0(Memory&m,const Inputs&i){return recovery_b212::invoke502(m,i,false);}
}
