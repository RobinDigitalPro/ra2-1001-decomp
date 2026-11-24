#include "recovered/recovery_b1526.hpp"
#include "recovered/map_b106.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1526 {
namespace {
using U=std::uint32_t;
void demand(bool v){if(!v)throw std::runtime_error("B1526 outside frozen boundary/height domain");}
std::int32_t coord(Memory& m,U a){return std::int16_t(m.r16(a));}
U packed(int x,int y){return U(std::uint16_t(x))|(U(std::uint16_t(y))<<16);}
U query(Memory& m,int x,int y){demand(y*512+x<0);m.w32(0x00a57634u,packed(x,y));return 0x00a57610u;}
U height(Memory& m,const Inputs& i,U cell,int x,int y){
    demand(m.r8(cell+0x11cu)==0u && std::int8_t(m.r8(cell+0x11bu))>=-4 && std::int8_t(m.r8(cell+0x11bu))<=4);
    // The original caller produces every byte of this point before passing it.
    // Its logical address and the callee's private stack never escape the call.
    std::array<std::uint8_t,8> bytes{};leaf::Memory point(bytes.data(),0xf0000000u,8u);point.w32(0xf0000000u,U(x));point.w32(0xf0000004u,U(y));
    Memory nested_memory=m;nested_memory.add(point);Inputs nested=i;nested.cx=cell;nested.arg[0]=0xf0000000u;
    U result=map_b106::fun_004702c0(nested_memory,nested);i.fp.image=nested.fp.image;return result;
}
void common(Memory& m,const Inputs& i){
    demand(i.cx!=0x00a57610u && m.r32(0x00a576f4u)==0u && m.r32(0x00a576f8u)==0u);
    demand(m.r32(0x00838f80u)==60u && m.r8(0x00838f70u)==4u && m.r16(0x007c3a04u)==0x0e7fu);
    demand(i.fp.image.word(0)==0x037fu && i.fp.image.word(8)==0xffffu && i.fp.image.word(4)==0u);
    int x=coord(m,i.cx+0x24u),y=coord(m,i.cx+0x26u);demand(x>=-16 && x<=-10 && y>=-16 && y<=-10);
}
U neighbors(Memory& m,const Inputs& i){
    for(int dx=-2;dx<3;++dx)for(int dy=-2;dy<3;++dy){
        U cell=query(m,coord(m,i.cx+0x24u)+dx,coord(m,i.cx+0x26u)+dy);
        demand(cell!=i.cx && m.r32(cell+0xe4u)==0u && m.r32(cell+0xe8u)==0u);
    }
    return 3u;
}
}
std::uint32_t fun_0047c530(Memory& m,const Inputs& i){
    common(m,i);demand(m.r8(i.cx+0x128u)!=0u);
    const int rawx=coord(m,i.cx+0x24u)*256+128,rawy=coord(m,i.cx+0x26u)*256+128;
    const U cell=query(m,rawx/256,rawy/256);
    const U local_z=height(m,i,cell,rawx,rawy)+m.r32(0x00838f74u);(void)local_z;
    return neighbors(m,i);
}
std::uint32_t fun_0047c810(Memory& m,const Inputs& i){
    common(m,i);demand(m.r32(i.cx+0xe4u)==0u);
    // 41B630 produces (cellX*256+128,cellY*256+128,0); the
    // explicit writes at 47C8A0/A4 separately produce the height point.
    const std::array<U,3> triplet{U(coord(m,i.cx+0x24u)*256+128),U(coord(m,i.cx+0x26u)*256+128),0u};(void)triplet;
    const U local_height=height(m,i,i.cx,128,128);(void)local_height;
    return neighbors(m,i);
}
}
