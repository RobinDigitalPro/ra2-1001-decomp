#include "recovery_b1399.hpp"
#include "platform/ole_stream951.hpp"
#include <array>
namespace ra2::recovered::b1399 {
namespace {
using U=std::uint32_t;namespace ole=ra2::platform::ole_stream951;
// All nine original75B helpers are byte-identical. This bounded adapter keeps
// their actual4B count/element Write calls and final full count result.
U write_vector(Memory& m,IStream* p,U header,U* outer_count){
 const U count=m.r32(header+16u),data=m.r32(header+4u);
 ole::need(count>=1u&&count<=3u&&data!=0u,"B1399 nonempty bounded borrowed vector");
 U private_count=count;const U* published=&private_count;
 if(outer_count){*outer_count=count;published=outer_count;}
 ole::need(p->Write(published,4,nullptr)==S_OK,"B1399 actual count Write");
 for(U k=0;k<count;++k){const U word=m.r32(data+4u*k);ole::need(p->Write(&word,4,nullptr)==S_OK,"B1399 actual element Write");}
 return count;
}
}
std::uint32_t fun_00644f20(Memory& m,const Inputs& i){
 const U self=i.cx,stream=i.arg[0];ole::need(stream==ole::Stream::current().address(),"B1399 genuine IStream");
 auto* p=reinterpret_cast<IStream*>(std::uintptr_t(stream));
 std::array<std::uint8_t,0x14c0u> raw{};for(U k=0;k<raw.size();++k)raw[k]=std::uint8_t(m.r8(self+k));
 ole::need(p->Write(raw.data(),U(raw.size()),nullptr)==S_OK,"B1399 complete actual object Write");
 constexpr U inline_headers[]{0xe6cu,0xe88u,0xea4u,0xec0u,0xedcu,0xef8u,0xf14u,0xf30u,0xf4cu,0xf68u,0xf84u,0xfa0u,0x1058u,0xe30u,0xb90u,0xbacu,0xc04u,0xc20u,0xbc8u,0xff8u,0x1014u};
 for(U h:inline_headers)(void)write_vector(m,p,self+h,&i.arg[0]);
 // Original direct call sites and distinct targets remain in exact evidence.
 // Their produced private count slots do not alias root caller words.
 constexpr U helper_headers[]{0xfc0u,0xfdcu,0x1030u,0xe4cu,0x394u,0x3b0u,0x3ccu,0x60u,0x520u,0x2b8u,0x2d4u,0x2f0u,0x30cu,0x328u,0x344u,0x5ecu,0x654u,0x6ecu,0x708u,0x724u,0x740u,0x75cu,0x790u,0x7c8u,0x7e4u,0x800u,0x81cu,0x838u,0x854u,0x870u,0x88cu,0x8a8u,0x8c4u,0x8e0u,0x8fcu,0x918u,0x934u,0x950u,0x96cu,0x988u,0xa08u,0xa24u,0xa40u,0xa80u,0x9d0u,0xcb8u,0x9ecu,0x118u,0xfcu,0x134u,0x150u,0x568u,0x30u,0xac4u,0xae0u,0xafcu,0xb18u,0xb34u,0xb50u,0x234u,0x250u,0x26cu};
 U result=0;for(U h:helper_headers)result=write_vector(m,p,self+h,nullptr);
 return result; //649C20 reloads self27C count after its final actual Write.
}
}
