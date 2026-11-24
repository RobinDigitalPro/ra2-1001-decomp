#include "recovery_b1372.hpp"
#include "recovered/map_b106.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1372 {
namespace {
using U=std::uint32_t;
void need(bool ok,const char* message){if(!ok)throw std::domain_error(message);}
void original_498cf0_null(Memory& m){
    need(m.r32(0x81b998u)==0u,"B1372 null old shape and suppliednull argument");
    m.w32(0x81b994u,m.r32(0x83a940u));m.w32(0x81b998u,0u);
}
U original_56a9b0(Memory& m,U index){return m.r32(0xa5863cu)+80u*index;}
U original_557280_nonzero(Memory& m){
    const U pointer=m.r32(0x81a934u),result=m.r32(pointer);
    need(m.r32(0x81a930u)!=0u,"B1372 actual nonzero iterator remaining branch");
    m.w32(0x81a928u,m.r32(0x81a928u)+1u);m.w32(0x81a930u,m.r32(0x81a930u)-1u);
    m.w32(0x81a92cu,m.r32(0x81a92cu)-1u);m.w32(0x81a934u,pointer-2044u);return result;
}
U populated_lookup(Memory& m,U point){
    const auto x=floating_b61::s32(m.r32(point))/256,y=floating_b61::s32(m.r32(point+4u))/256;
    const auto index=std::int64_t(y)*512+x;
    need(x==3&&y==2&&index>=0&&index<floating_b61::s32(m.r32(0x81a95cu)),"B1372 actual occupied coordinate lookup");
    const U cell=m.r32(m.r32(0x81a958u)+4u*U(index));need(cell!=0u,"B1372 real populated cell");return cell;
}
U original_557070_flat(Memory& memory,U point,const Inputs& i){
    const U cell=populated_lookup(memory,point);
    need(memory.r8(cell+0x11bu)==0u&&memory.r8(cell+0x11cu)==0u&&(memory.r8(0x838f70u)&7u)==7u,"B1372 actual warm flat-height branch");
    // Exact original557070 scratch is8-byteXY. No unproduced third coordinate.
    std::array<std::uint8_t,8> bytes{};constexpr U scratch=0x7a400000u;
    leaf::Memory local(bytes.data(),scratch,8u);Memory m=memory;m.add(local);
    local.w32(scratch,m.r32(point));local.w32(scratch+4u,m.r32(point+4u));
    Inputs height{};height.cx=cell;height.arg[0]=scratch;height.fp=i.fp;
    const U result=map_b106::fun_004702c0(m,height);i.fp=height.fp;return result;
}
U original_5ccea0(Memory& m,U self,const Inputs& i){
    // Actual constructor45F020 live788374 slot1B0 points to this79-byte body.
    const U height=original_557070_flat(m,self+0x88u,i);
    U result=m.r32(self+0x90u)-height;
    need(m.r8(self+0x79u)==0u,"B1372 actual provider without additionalheight offset");return result;
}
}
U fun_005590b0(Memory& m,const Inputs& i){
    (void)i;original_498cf0_null(m);
    need(m.r32(0xa5863cu)!=0u&&m.r32(0x836b4cu)==2u,"B1372 preallocated four-record matrix");
    const U n=m.r32(0x836b4cu);
    for(U index=0;index<n*n;++index)m.w32(original_56a9b0(m,index)+0x40u,0xffffffffu);
    U last=0u;
    for(U pass=0;pass<4u;++pass){
        const U width=m.r32(0x81a910u);need(width==4u,"B1372 bounded actual Map width");
        m.w32(0x81a92cu,width);m.w32(0x81a928u,1u);m.w32(0x81a930u,width-1u);
        m.w32(0x81a934u,m.r32(0x81a958u)+(width<<11u)+4u);
        last=original_557280_nonzero(m);need(last==0u,"B1372 genuine first-slot null ends eachpass");
    }
    need(m.r32(0x81b9c0u)==0u,"B1372 no owning auxiliary provider");m.w32(0x81b9c4u,0u);
    // The explicitly produced allocationflag is0; no free. MOVAL,BL withBL1.
    return (last&0xffffff00u)|1u;
}
U fun_00461840(Memory& m,const Inputs& i){
    const U self=i.cx,output=i.arg[0];
    m.w32(output,m.r32(self+0x88u));m.w32(output+4u,m.r32(self+0x8cu));m.w32(output+8u,m.r32(self+0x90u));
    const U cell=populated_lookup(m,output);i.arg[0]=cell; // physical OUTERarg0 at461878
    const U type=m.r32(self+0x98u);
    need(type!=0u&&m.r8(type+0x266u)==0u&&m.r8(type+0x268u)==0u,"B1372 actual direct threshold branch");
    need(m.r32(self)==0x788374u,"B1372 constructor-proven live receiver provider");
    const U clearance=original_5ccea0(m,self,i),threshold=(0u-m.r32(0x838690u))*4u;
    need(m.r32(0x838690u)==0u&&floating_b61::s32(clearance)<=floating_b61::s32(threshold),"B1372 originalzero threshold and actual nonpositiveclearance");
    return (clearance&0xffffff00u)|1u;
}
}
