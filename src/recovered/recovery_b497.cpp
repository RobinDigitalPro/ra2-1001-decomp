// Reuse the already reviewed exact instruction translations as one private
// translation unit. Historical233 source and its accepted evidence stay intact.
#include "recovery_b233.cpp"
#include "recovery_b497.hpp"
namespace ra2::recovered::recovery_b233 {
static std::uint32_t invoke497(Memory&original,const Inputs&i,bool power){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{entry,entry,0x76543210u};m.w32(entry,f.outer_return);
 for(unsigned k=0;k<16;++k)m.w32(entry+4+4*k,i.arg[k]);
 if(power)f_001a6450(m,s,f,{});else f_001a5e10(m,s,f,{});
 i.fp=s.fp;for(unsigned k=0;k<16;++k)i.arg[k]=m.r32(entry+4+4*k);
 return s.ax;
}
}
namespace ra2::recovered::recovery_b497 {
std::uint32_t fun_005a5e10(Memory&m,const Inputs&i){return recovery_b233::invoke497(m,i,false);}
std::uint32_t fun_005a6450(Memory&m,const Inputs&i){return recovery_b233::invoke497(m,i,true);}
}
