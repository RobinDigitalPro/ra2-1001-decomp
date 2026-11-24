#include "recovered/recovery_b1503.hpp"
#include "recovered/leaf_state.hpp"
#include "platform/observed_ticks1378.hpp"
#include <stdexcept>
namespace ra2::recovered::b1503 {
namespace {
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
U cursor_hit(Memory&m){
 const U self=0x81a820;
 need(m.r32(self)==0x785954&&m.r32(0x7859a0)==0x59c040,"1503 actual Map vptr/slot4C");
 need(m.r32(self+0x4f34)==0&&m.r32(self+0x4f30)==0&&m.r8(self+0x4f2c)==0,"1503 actual requested/current cursor0 alt0");
 need(m.r32(0x7cd5dc)==1&&m.r8(0xa58bbd)==1&&m.r32(0xa58b7c)!=0,"1503 borrowed loaded warm MOUSE.SHP cache identity");
 // Caller supplies a borrowed cache identity with opaque mapped backing.
 // No SHPheader/loader/full-cache reconstruction or actualassetpointer claim.
 // 59C040 EAX=index0, XOR AL,AL => fullEAX0, RET8. No refresh/privateword.
 return 0;
}
void gain_default(Memory&m){
 const U c=m.r32(0x8197a8);need(c==0x819418&&m.r32(0x7dba04)==0x4000,"1503 original published default gain4000");
 need(m.r32(c)==3&&m.r32(c+4)==0x40000000&&m.r32(c+8)==0x40000000,"1503 constructor/default gain retained");
 // Checked byte adapter to the existing contiguous leaf Memory contract.
 // No accepted implementation is copied or widened; all12 bytes roundtrip.
 std::uint8_t bytes[12];for(U k=0;k<12;++k)bytes[k]=std::uint8_t(m.r8(c+k));
 leaf::Memory view(bytes,c,12);leaf::Inputs in{};in.cx=c;in.dx=m.r32(0x7dba04);
 (void)leaf::fun_00407080(view,in);for(U k=0;k<12;++k)m.w8(c+k,bytes[k]);
}
U maintenance(Memory&m){
 need(m.r32(0xab83e8)==0&&m.r32(0xab83dc)==0&&m.r32(0xab8348)==0,"1503 initialized noaudio null wrappers/count");
 const U first=m.r32(0xab8250);need(first==0xab8250&&m.r32(first+8)==0xab8250,"1503 genuine initialized empty playback ring");
 // 4072F0 compares head with head+8, returns0; 7090B0 exits withoutcallbacks.
 const U enabled=m.r32(0x8192f8);need(enabled==1&&m.r32(0x8191e0)==0x8191e0,"1503 enabled original empty active ring");
 need(m.r32(0x819778)==0,"1503 genuine noaudio null backend");
 // 405020 leaves fullEAX=enabled; 406E70 nullbackend tail does not rewriteEAX.
 return enabled;
}
}
U fun_006531c0(Memory&m,const Inputs&){
 (void)cursor_hit(m);const U self=m.r32(0xa255c0);
 need(m.r32(self+0x614)==0xffffffff,"1503 stopped timer restart selected");
 need(m.r32(0x785524)==platform::ticks1378::Tick::address(),"1503 genuine observed WinMM IAT");
 need(m.r32(0x821cf0)==0&&m.r32(0xae0a68)==0,"1503 independent optional widget null/initialized overlay count0");
 // Actual68FAD0 ignoresECX and returns actual timeGetTime>>4. Its caller
 // publishes614.618/61C remain exact. Logger4068F0 is literalRET; the fully
 // produced three-word private timercopy has no public effects.
 m.w32(self+0x614,platform::ticks1378::Tick::get()>>4);
 gain_default(m);m.w32(0x7dba04,0x4000);
 // 59D880 signedzero count exits before virtualdispatch. Tail406E70 below.
 return maintenance(m);
}
}
