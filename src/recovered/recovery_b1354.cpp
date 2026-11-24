#include "recovery_b1354.hpp"
#include <stdexcept>
namespace ra2::recovered::b1354 {
namespace {using U=std::uint32_t;void need(bool b,const char*s){if(!b)throw std::domain_error(s);}}
U fun_004cad10(Memory&m,const Inputs&i){
 need(m.r8(i.cx+0x37f)==0&&i.arg[0]==0,"B1354 exact null-target reset route");
 // 4CB28B..4CB2A3 fully produce two zero packed words in outerarg0.
 m.w32(i.cx+0x418,0xffffffff);i.arg[0]=0;
 m.w8(i.cx+0x576,0);m.w32(i.cx+0x41c,0);m.w32(i.cx+0x420,0);m.w8(i.cx+0x388,0);
 return i.ax&0xffffff00u;
}
U fun_004e7b80(Memory&m,const Inputs&i){
 need(m.r32(i.cx+0x230)==0,"B1354 base-record initialization without child traversal");
 m.w32(i.cx+0x53bc,m.r32(0xa28b90));m.w32(i.cx+0x53c0,m.r32(0xa28b94));m.w32(i.cx+0x53c4,m.r32(0xa28b98));m.w32(i.cx+0x53c8,0);
 U cursor=i.cx+0x53d0;
 for(unsigned k=0;k<5;++k){m.w32(cursor-4,0);m.w32(cursor,0);m.w32(cursor+4,0);cursor+=12;}
 return cursor;
}
U fun_00520880(Memory&m,const Inputs&i){
 const U previous=m.r32(i.cx+0xc);need(previous<79&&m.r32(i.cx+0x10)==1,"B1354 bounded mode1 counter progression");
 m.w32(i.cx+0xc,previous+1);return previous;
}
}
