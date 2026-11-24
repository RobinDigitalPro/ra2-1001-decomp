#include "recovery_b1400.hpp"
#include "platform/ole_save1400.hpp"
#include <array>
namespace ra2::recovered::b1400 {
namespace {
using U=std::uint32_t;namespace ole=ra2::platform::ole_stream951;
void need(bool b,const char* s){ole::need(b,s);}
void word(IStream* stream,U value){need(stream->Write(&value,4,nullptr)==S_OK,"B1400 genuine successful Write4");}
void base_004100c0(Memory& m,U self,IStream* stream,U clear){
    need(m.r32(self)==0x78612cu,"B1400 concrete413A40 primary vptr");
    word(stream,self);
    // Original[78612C+30]=41B570 is the complete MOV EAX,5C0;RET getter.
    std::array<std::uint8_t,0x5c0> raw{};
    for(U k=0;k<raw.size();++k)raw[k]=m.r8(self+k);
    need(stream->Write(raw.data(),U(raw.size()),nullptr)==S_OK,"B1400 actual concrete raw-object Write5C0");
    if(clear)m.w8(self+0x20u,0u); // After rawimage Write, precisely41010E.
}
void base_0062e2c0(Memory& m,U self,IStream* stream,U clear){
    base_004100c0(m,self,stream,clear);
    const U count=m.r32(self+0xd0u),array=m.r32(self+0xccu);
    need(count==1u&&array!=0u,"B1400 genuine constructor-derived one-word base vector");
    word(stream,count);for(U k=0;k<count;++k)word(stream,m.r32(array+4u*k));
}
void outer_vector(Memory& m,const Inputs& i,U self,IStream* stream,U ptrOff,U countOff){
    i.arg[2]=m.r32(self+countOff);const U array=m.r32(self+ptrOff);
    need(i.arg[2]>=1u&&i.arg[2]<=3u&&array!=0u,"B1400 nonempty valid borrowed vector");
    word(stream,i.arg[2]);for(U k=0;k<i.arg[2];++k)word(stream,m.r32(array+4u*k));
}
}
std::uint32_t fun_004c9be0(Memory& m,const Inputs& i){
    const U self=i.arg[0],streamAddress=i.arg[1],clear=i.arg[2];
    need(streamAddress==ole::Stream::current().address()&&clear<=1u,"B1400 real COM stream and original clear flag");
    need(m.r32(self+0x564u)==0u&&m.r32(self+0x5acu)==0u,"B1400 real baseNULL component preserved by concreteNULLtype constructor arm");
    need(m.r32(0x7855e8u)==ra2::platform::ole_save1400::address(),"B1400 originalIAT bound directly to genuine OS export");
    auto* stream=reinterpret_cast<IStream*>(std::uintptr_t(streamAddress));
    // Actual6CBFF0 forwards the private three-word frame then returnszero.
    base_0062e2c0(m,self,stream,clear);
    outer_vector(m,i,self,stream,0x47cu,0x488u);
    outer_vector(m,i,self,stream,0x4a0u,0x4acu);
    i.arg[1]=0u; // 4C9CA7 overwrites entryESP+8, not an inventedprivateword.
    const U ignored=U(ra2::platform::ole_save1400::actual_export()(nullptr,stream));
    need(ignored==0x80070057u,"B1400 pinned realWindows NULLcomponent result");
    return 0u; // Original4C9D14 ignores that HRESULT then returnsEBX0/RET12.
}
}
