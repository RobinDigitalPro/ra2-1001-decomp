#include "recovered/recovery_b1223.hpp"
#include <windows.h>
#include <stdexcept>
namespace ra2::recovered::b1223{namespace{void need(bool x,const char*s){if(!x)throw std::domain_error(s);}}
unsigned run(unsigned r,Memory&m,const Inputs&i,State&){need(r==0x16f0u,"1223 exact selector");const auto owner=i.cx,index=i.dx,count=m.r32(owner+4u),array=m.r32(owner);need(count>=1u&&count<=4u&&index<count&&array&&m.r32(owner+0x110u)==0u&&m.r32(owner+0x114u)==0u,"1223 actual populated index/default noexternalstate");const auto record=array+36u*index,file=m.r32(owner+0x10cu);need(file&&m.r32(file)==0x7856a0u&&m.r32(file+0x54u)==0u&&m.r8(file+0x25u)==0u&&m.r8(file+0x21u)==0u&&m.r32(file+0xcu)==0xffffffffu&&m.r32(file+0x10u)!=0xffffffffu,"1223 authentic uncached unbuffered open CCFile readset");m.w32(owner+0x118u,0u);m.w32(owner+0x118u,file);const auto length=m.r32(record+0x14u),offset=m.r32(record+0x10u);need(length>0u&&offset>0u&&offset+length<=512u,"1223 positive real member extent");m.w32(owner+0x11cu,length);
 // 468D10→42FB90→630550 uncached C=-1,+18→468E00→42F600 open true.
 // No filename, size cache, error callback or ownership field is consulted.
 using Seek=DWORD(WINAPI*)(HANDLE,LONG,PLONG,DWORD);const auto api=reinterpret_cast<Seek>(std::uintptr_t(m.r32(0x7851b4u)));need(api!=nullptr,"1223 actual bound SetFilePointer import");const auto result=api(reinterpret_cast<HANDLE>(std::uintptr_t(m.r32(file+0x10u))),LONG(offset),nullptr,FILE_BEGIN);need(result==offset,"1223 positive actual physical seek result");return 1u;}
}
