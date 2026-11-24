#include "recovered/global_b62_b.hpp"
#include <array>
namespace ra2::recovered::global_b26 {
namespace {
// Exact closed helper at RVA145500, with the coordinate supplied by value
// instead of the original caller's local stack address.
std::uint32_t cell(Memory&m,std::uint32_t xy){
    const auto index=(sx16(xy>>16)<<9)+sx16(xy);
    if(s32(index)>=0&&s32(index)<0x40000){
        const auto p=m.r32(m.r32(0x81a958)+index*4u);if(p)return p;
    }
    m.w32(0xa57634,xy);return 0xa57610;
}
// RVA80530: eligibility test and twenty-byte record address.
std::uint32_t record(Memory&m,std::uint32_t object,std::uint32_t index){
    const auto slots=m.r32(object+0x40),base=m.r32(object+0x34);
    const auto p=base+m.r32(slots+index*4u)*20u;
    return m.r8(p)&1u?p:0u;
}
void forward_copy(Memory&m,std::uint32_t dst,std::uint32_t src,std::uint32_t n){
    for(auto k=n>>2;k;--k){const auto v=m.r32(src);m.w32(dst,v);src+=4;dst+=4;}
    for(auto k=n&3u;k;--k)m.w8(dst++,m.r8(src++));
}
}
std::uint32_t fun_00427060(Memory&m,const Inputs&i){
    auto xy=m.r32(i.dx),count=i.arg[0],commands=i.arg[1];
    while(s32(count)>0){
        const auto direction=m.r32(commands);
        if(direction==8){
            const auto selected=sx16(m.r16(cell(m,xy)+0x116));
            xy=selected==0xffffffffu?0u:m.r32(m.r32(m.r32(0x84e4fc)+selected*4u)+0x28);
        }else{
            const auto x=(m.r16(0x839da0+direction*4u)+(xy&65535u))&65535u;
            const auto y=(m.r16(0x839da2+direction*4u)+(xy>>16))&65535u;
            xy=x|(y<<16);
        }
        commands+=4;--count;
    }
    m.w32(i.cx,xy);return i.cx;
}
std::uint32_t fun_00481530(Memory&m,const Inputs&i){
    const auto object=i.cx;auto collection=m.r32(object+4u);
    if(s32(m.r32(collection+0x38))<=0)return 0;
    std::uint32_t index=0;
    do{
        const auto p=record(m,collection,index);
        if(p&&!(m.r8(p)&2u)){
            const auto payload=m.r32(p+8u),kind=m.r8(payload+2u);
            bool accept=kind==1u;
            if(kind==0u&&m.r32(payload+4u)==m.r32(object+0x48u)+1u){m.w32(object+0x48u,m.r32(payload+4u));accept=true;}
            if(accept){
                const auto length=m.r32(p+4u)-8u;
                m.w32(p,m.r32(p)|2u);
                if(s32(length)>0)forward_copy(m,i.arg[0],m.r32(p+8u)+8u,length);
                m.w32(i.arg[1],length);return 1;
            }
        }
        collection=m.r32(object+4u);++index;
    }while(s32(index)<s32(m.r32(collection+0x38u)));
    return 0;
}
std::uint32_t fun_005a4200(Memory&m,const Inputs&i){
    const auto src=i.cx,dst=i.dx,len=i.arg[0];
    // RVA1a43e0's original sign read uses len*4 while its byte cursor uses len.
    const bool negative=s32(m.r32(src+len*4u-4u))<0;
    const auto sign=negative?255u:0u;auto at=src+len-1u;
    while(at>src&&m.r8(at)==sign)--at;
    std::array<std::uint8_t,260> scratch{};std::uint32_t size=0;
    if(bool(m.r8(at)&0x80u)!=negative)scratch[size++]=std::uint8_t(sign);
    scratch[size++]=std::uint8_t(m.r8(at));
    while(at!=src)scratch[size++]=std::uint8_t(m.r8(--at));
    m.w8(dst,2);std::uint32_t header=1;
    if(size<=127)m.w8(dst+1,size);
    else{
        unsigned bytes=4;while(bytes&&((size>>((bytes-1u)*8u))==0u))--bytes;
        m.w8(dst+1,0x80u|bytes);
        for(unsigned k=bytes;k;--k)m.w8(dst+(++header),size>>((k-1u)*8u));
    }
    for(unsigned k=0;k<size;++k)m.w8(dst+header+1u+k,scratch[k]);
    return size+header+1u;
}
}
