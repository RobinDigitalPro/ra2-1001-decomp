#include "recovery_b291.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b291 {
namespace {
void need(bool ok,const char* why){if(!ok)throw std::domain_error(why);}
constexpr std::uint32_t empty_wide=0x008248a4u;
}
std::uint32_t fun_00522f30(Memory& m,Inputs& i,Heap& heap){
 const auto self=i.cx;
 const auto a1=i.arg[0],a2=i.arg[1],a3=i.arg[2],a4=i.arg[3];
 const auto a5=i.arg[4],a6=i.arg[5],a7=i.arg[6],a8=i.arg[7];
 need(self,"receiver must be mapped/non-null");
 need(a1==1u&&a2==1u&&a3==0u&&a5==0u&&a8==0u,"exact positive 291 constructor counts and null optional inputs required");
 need(a7==empty_wide&&m.r16(a7)==0u,"selected empty UTF-16 source required");

 // 0x522f30..0x522f62: 0x810c0 keeps the first request8 at receiver+0x20,
 // allocates the 88-byte helper object, then initializes and clears its state.
 const auto unused=heap.allocate(a3+8u);need(unused,"first real 8-byte allocation required");
 const auto object=heap.allocate(0x58u);need(object,"real 88-byte helper object required");
 m.w32(self,0x00788dccu);m.w32(self+0x1cu,a3+8u);m.w32(self+0x20u,unused);
 m.w16(self+0x24u,std::uint16_t(a4));m.w32(self+0x28u,2u);m.w32(self+0x2cu,0xffffffffu);m.w32(self+0x30u,60u);
 // 0x7fce0 parameter fields and its four unconditional array allocations.
 const auto rows32=heap.allocate(a1*32u);
 const auto rows20=heap.allocate(a2*20u);
 const auto ptrsA1=heap.allocate(a1*4u);
 const auto ptrsA2=heap.allocate(a2*4u);
 heap.w32(object,0x00788db4u);heap.w32(object+4u,a1);heap.w32(object+8u,a2);
 heap.w32(object+0x0cu,a3+8u);heap.w32(object+0x10u,a8);
 heap.w32(object+0x24u,rows32);heap.w32(object+0x34u,rows20);
 heap.w32(object+0x30u,ptrsA1);heap.w32(object+0x40u,ptrsA2);
 // A1=1 loop allocates one payload and stores it at row32+0x14; A8=0
 // suppresses only the optional second request and writes row32+0x1c=0.
 const auto rowA1=heap.allocate(a3+8u);heap.w32(rows32+0x14u,rowA1);heap.w32(rows32+0x1cu,0u);
 // A2=1 loop has its own unconditional payload allocation at row20+8.
 const auto rowA2=heap.allocate(a3+8u);heap.w32(rows20+8u,rowA2);heap.w32(rows20+0x10u,0u);
 // Pinned 0x7fea0 destructor: clear object state and array flags/owned links,
 // preserving the two row payload pointers and the four array-base pointers.
 heap.w32(object+0x2cu,0u);heap.w32(object+0x3cu,0u);
 heap.w32(object+0x14u,0u);heap.w32(object+0x18u,0u);heap.w32(object+0x1cu,0u);
 heap.w32(object+0x20u,0u);heap.w32(object+0x28u,0u);heap.w32(object+0x38u,0u);
 heap.w32(object+0x44u,0u);heap.w32(object+0x48u,0u);heap.w32(object+0x4cu,0u);heap.w32(object+0x54u,0u);
 heap.w32(rows32,heap.r32(rows32)&~7u);heap.w32(rows32+4u,0u);heap.w32(rows32+8u,0u);
 heap.w32(rows32+0x0cu,0u);heap.w32(rows32+0x10u,0u);heap.w32(rows32+0x18u,0u);heap.w32(ptrsA1,0u);
 heap.w32(rows20,heap.r32(rows20)&~7u);heap.w32(rows20+4u,0u);heap.w32(rows20+0x0cu,0u);
 heap.w32(ptrsA2,0u);

 // Root 0x522f67..0x522f85. Its [ESP+0x24] load is original A5; selected
 // A5=0 takes the null branch, so the 0x122950 FF fill remains unchanged.
 m.w32(self,0x0078f644u);
 for(unsigned k=0;k<10u;++k)m.w8(self+0x4cu+k,0xffu);
 if(a5){for(unsigned k=0;k<10u;++k)m.w8(self+0x4cu+k,std::uint8_t(m.r8(a5+k)));}
 m.w32(self+0x60u,a6);
 // Accepted 0x36efc9 loops over UTF-16 and copies the terminator.
 for(std::uint32_t k=0;;k+=2u){const auto ch=m.r16(a7+k);m.w16(self+0x64u+k,ch);if(ch==0)break;need(k<0x100u,"bounded selected wide string");}
 // Exact122a60 writes firstDWORD to arg0=rootcallerA8; nextDWORD+WORD
 // to arg1=rootlocalS-8. Only callerA8 changes. Selected tenbytes are allFF.
 std::uint32_t copied=0;for(unsigned k=0;k<4;++k)copied|=std::uint32_t(m.r8(self+0x4cu+k))<<(8u*k);
 const auto copied16=std::uint16_t(m.r8(self+0x50u)|(std::uint16_t(m.r8(self+0x51u))<<8u));
 i.arg[7]=copied; // First4 bytes go to callerA8; next6 bytes go only to root local.
 m.w32(self+0x56u,copied);m.w16(self+0x5au,copied16);m.w32(self+0x5cu,0u);
 m.w32(self+4u,object);
 return self;
}
}
