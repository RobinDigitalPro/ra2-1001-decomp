#include "recovery_b197.hpp"
#include "recovery_b190.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::recovery_b197 {
namespace {
std::uint32_t scaled(std::uint32_t raw) {
    // Original three LEAs, SHL3, signed magic divide by100.
    const auto times1000=raw*1000u;
    const auto high=global_b26::imul_high(0x51eb851fu,times1000);
    const auto quotient=global_b26::sar(high,5);
    return quotient+(quotient>>31);
}
void update_cell(Memory&m,std::uint32_t cell){
    const auto config=m.r32(0xa255c0);
    auto low=(scaled(m.r32(config+0x22ac))+m.r16(cell+0x108))&0xffffu;
    m.w16(cell+0x10a,low);m.w16(cell+0x10e,low);
    const auto first=m.r8(0xa39574)!=0;
    const auto second=m.r32(0xa3957c)==1;
    const auto offset=first?0x22d8u:(second?0x22f0u:0x22c0u);
    const auto height=global_b26::s32(global_b26::sx8(m.r8(cell+0x11b)));
    const auto step=m.r16(config+offset+4),bias=m.r16(config+offset);
    const auto ordinary=(low+std::uint32_t(height)*step-bias)&0xffffu;
    const auto raised=(low+std::uint32_t(height+4)*step-bias)&0xffffu;
    m.w16(cell+0x10a,ordinary);m.w16(cell+0x10e,raised);
    const auto scale=m.r32(cell+0x104);
    const auto scaled_ordinary=global_b26::sar(global_b26::sx16(ordinary)*scale,16)&0xffffu;
    const auto scaled_raised=global_b26::sar(global_b26::sx16(raised)*scale,16)&0xffffu;
    m.w16(cell+0x10c,scaled_ordinary);m.w16(cell+0x10e,scaled_raised);
    const auto clamp=[](std::uint32_t x){const auto s=global_b26::s32(global_b26::sx16(x));return std::uint32_t(s<0?0:(s>2000?2000:s));};
    m.w16(cell+0x10a,clamp(ordinary));m.w16(cell+0x10c,clamp(scaled_ordinary));m.w16(cell+0x10e,clamp(scaled_raised));
}
std::uint32_t next_cell(Memory&m){
    constexpr unsigned p=0x81a820;
    const auto count=m.r32(p+0x110),old=m.r32(p+0x114);
    if(count){m.w32(p+0x108,m.r32(p+0x108)+1);m.w32(p+0x10c,m.r32(p+0x10c)-1);m.w32(p+0x110,count-1);m.w32(p+0x114,old-0x7fc);}
    else{
        auto end=m.r32(p+0x10c),begin=m.r32(p+0x108),row=m.r32(p+0xf0);
        m.w32(p+0x108,end);m.w32(p+0x10c,begin);
        if((end-row+begin-1)&1){++begin;--row;m.w32(p+0x10c,begin);}
        else{++end;row-=2;m.w32(p+0x108,end);}
        m.w32(p+0x110,row);m.w32(p+0x114,m.r32(p+0x138)+4*((m.r32(p+0x10c)<<9)+m.r32(p+0x108)));
    }
    return m.r32(old);
}
void apply_config(Memory&m,std::uint32_t red,std::uint32_t green,std::uint32_t blue){
    (void)red;(void)green;(void)blue; // No active object slots in this finite route.
    if(m.r32(0x81a6e8)||m.r32(0xa9ea10))throw std::domain_error("197 active object callbacks excluded");
    std::array<std::uint8_t,12> bytes{};leaf::Memory cursor(bytes.data(),0xf0001000,12);Memory local=m;local.add(cursor);
    Inputs in{};in.cx=0xf0001000;
    if(recovery_b190::fun_005fb220(local,in))throw std::domain_error("197 requires iterator exhaustion");
    constexpr unsigned p=0x81a820;const auto dimension=m.r32(p+0xf0);
    if(dimension!=2)throw std::domain_error("197 finite two-row cursor");
    m.w32(p+0x108,1);m.w32(p+0x10c,dimension);m.w32(p+0x110,dimension-1);m.w32(p+0x114,(dimension<<11)+m.r32(p+0x138)+4);
    unsigned seen=0;
    for(auto cell=next_cell(m);cell;cell=next_cell(m)){
        if(++seen>2)throw std::domain_error("197 at most two cells");
        update_cell(m,cell);
    }
}
}
std::uint32_t fun_0051fcb0(Memory&m,const Inputs&){
    const auto config=m.r32(0xa255c0);
    unsigned offset;
    if(m.r32(0xa3957c)==1){offset=0x22e0;}
    else{
        if(!m.r8(0xa39574))throw std::domain_error("197 requires a positive mode");
        m.w8(m.r32(0xa1e0e4)+0x5669,1);offset=0x22c8;
    }
    m.w32(config+0x22b0,m.r32(config+offset));
    apply_config(m,scaled(m.r32(config+offset+4)),scaled(m.r32(config+offset+8)),scaled(m.r32(config+offset+12)));
    return 0;
}
}
