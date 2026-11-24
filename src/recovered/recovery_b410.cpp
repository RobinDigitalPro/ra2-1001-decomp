#include "recovered/recovery_b410.hpp"
#include "recovered/leaf_b21_c.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::recovery_b410 {
namespace {
void need(bool b){if(!b)throw std::domain_error("B410 initialized software surface graph and bounded consumer");}
unsigned stride(Memory&m){auto p=m.r32(0x821c9c);need(m.r32(p)==0x785ef8&&m.r32(0x785ef8+0x74)==0x4113c0&&m.r32(0x785ef8+0x7c)==0x4112c0);auto w=m.r32(p+4),bytes=m.r32(p+16);need(w>0&&w<1024&&(bytes==1||bytes==2));return w*bytes;}
}
unsigned fun_00716880(Memory&m,const Inputs&i){const auto p=i.cx,h=stride(m)/2;const std::array<unsigned,8>offsets{0-h,1-h,1,h+1,h,h-1,0xffffffffu,0-h-1};for(unsigned k=0;k<8;++k)m.w32(p+0x174+4*k,offsets[k]);m.w32(p+0x1d0,0);m.w32(p+0x1d4,0);auto index=m.r32(p+0x194);need(index<8);auto d=m.r32(p+0x174+index*4);for(unsigned k=0;k<5;++k)m.w32(p+0x1d8+4*k,d);for(unsigned k=0;k<3;++k)m.w32(p+0x1ec+4*k,2*d);for(unsigned k=0;k<3;++k)m.w32(p+0x1f8+4*k,3*d);return 3*d;}
unsigned fun_005214f0(Memory&m,const Inputs&){const auto pitch=stride(m);need(pitch!=m.r32(0xa39bf8)&&m.r32(0xa39bd8)==0);m.w32(0xa39598,0);m.w32(0xa39bf8,stride(m));std::array<unsigned char,8> bytes{};leaf::Memory temp(bytes.data(),0x1000,8);leaf::Inputs nested{};nested.cx=0x1000;for(unsigned k=1;k<=288;++k){nested.dx=k;leaf::fun_00521580(temp,nested);m.w32(0xa39598+4*k,temp.r32(0x1000)+pitch*temp.r32(0x1004));}return m.r32(0xa39bd8);}
}
