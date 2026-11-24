#include "recovery_b1405.hpp"
#include "platform/ole_stream951.hpp"
namespace ra2::recovered::recovery_b1405 {
using U=std::uint32_t;namespace ole=ra2::platform::ole_stream951;
U configure_crt(Memory& m,const Inputs& i){
 // Actual unindexed773328: unsigned limit1016, cdecl RET0, no FP operations.
 const U value=i.arg[0];if(value>1016u)return 0u;m.w32(0x817554u,value);return 1u;
}
U fun_00706a20(Memory& m,const Inputs& i,Heap& heap){
 ole::need(i.cx==ole::Stream::current().address(),"B1405 genuine ECX IStream");
 ole::need(m.r32(0x817554u)==0&&m.r32(0xb10e14u)==0,"B1405 genuinely configured ordinary CRT, empty small registry");
 ole::need(m.r32(0xab81d8u)==0&&m.r32(0xab81ccu)==0&&m.r32(0xab81d0u)==0&&m.r8(0xab81d5u)==0,"B1405 original initialized empty object registry");
 ole::need(m.r32(0xab8220u)==0,"B1405 first bitmap restore, no displaced owner");
 m.w32(0xab81d8u,0);m.w8(0xab81d5u,0);m.w32(0xab81d0u,0);
 // Actual428AC0 is this call-free integer expression; no FP or receiver read.
 const U bytes=2u*(m.r32(0x81a914u)+4u)*m.r32(0x81a910u);
 ole::need(m.r32(0x81a910u)==4&&m.r32(0x81a914u)==4&&bytes==64,"B1405 exact four-by-four map bitmap");
 auto* stream=reinterpret_cast<IStream*>(std::uintptr_t(i.cx));U count=0xdeadbeefu;
 ole::need(stream->Read(&count,4,nullptr)==S_OK&&count==0,"B1405 actual zero object count Read");
 const U owner=heap.allocate(bytes);ole::need(owner!=0,"B1405 actual successful owned bitmap allocation");m.w32(0xab8220u,owner);
 ole::need(stream->Read(reinterpret_cast<void*>(std::uintptr_t(owner)),bytes,nullptr)==S_OK,"B1405 complete actual64-byte Read");
 // Final EAX comes from the locally Read count0, then MOV AL,1. RET0.
 return (count&0xffffff00u)|1u;
}
}
