#include "recovery_b1378.hpp"
#include "platform/observed_ticks1378.hpp"
#include <stdexcept>
namespace ra2::recovered::b1378 {
namespace {
using U=std::uint32_t;
void need(bool b,const char* message){if(!b)throw std::domain_error(message);}
U original_68fad0(Memory& m){
 need(m.r32(0x785524u)==platform::ticks1378::Tick::address(),"B1378 genuine observed WinMM binding");
 // Original ten-byte helper never consumes ECX=self+14 and never writes there.
 return platform::ticks1378::Tick::get()>>4u;
}
U original_759420_null(Memory& m,U string_owner){
 const U pointer=m.r32(string_owner);need(pointer==0u,"B1378 valid default stringowner, actualnull comparison route");
 // EAX=0 and supplied second pointer=0: XOR AL,AL leaves fullEAX0; RET4.
 return pointer&0xffffff00u;
}
void base(Memory& m,U self){
 m.w32(self+4u,0u);m.w32(self+8u,0u);m.w8(self+0xcu,0u);
 m.w32(self+0x10u,original_68fad0(m));m.w32(self+0x18u,0u);
}
U empty_surface(Memory& m,const Inputs& i,U flag){
 const U self=i.cx;base(m,self);m.w32(self,0x791d10u);
 m.w32(self+0x1cu,m.r32(0x821c98u));m.w32(self+0x20u,i.arg[1]);m.w32(self+0x24u,0u);
 m.w8(self+0x28u,std::uint8_t(flag));m.w8(self+0x29u,0u);
 for(U k=0;k<4u;++k)m.w32(self+0x2cu+4u*k,0u);
 m.w32(self,0x791e54u);m.w8(self+0xcu,1u);
 need(original_759420_null(m,i.arg[0])==0u,"B1378 no-resource constructor route");return self;
}
}
U fun_005ac1d0(Memory& m,const Inputs& i){return empty_surface(m,i,i.arg[2]);}
U fun_005ac370(Memory& m,const Inputs& i){
 // The arg2 pointpointer is used only in the excluded resource-loaded branch.
 return empty_surface(m,i,i.arg[3]);
}
U fun_005aa970(Memory& m,const Inputs& i){
 const U self=i.cx;base(m,self);m.w8(self+0x2cu,std::uint8_t(i.arg[3]));
 m.w32(self+0x1cu,0u);m.w32(self+0x20u,i.arg[1]);m.w32(self+0x24u,i.arg[2]);
 m.w32(self+0x28u,0u);m.w8(self+0x2du,0u);m.w32(self,0x791dd8u);
 need(original_759420_null(m,i.arg[0])==0u,"B1378 selected null-string route precedes all originalFP/resource arms");return self;
}
}
