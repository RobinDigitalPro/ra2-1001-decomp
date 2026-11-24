#include "recovery_b1403.hpp"
#include "recovered/rng_b77.hpp"
#include "platform/ole_stream951.hpp"
#include "platform/observed_ticks1403.hpp"
#include <array>
namespace ra2::recovered::b1403 {
namespace {
using U=std::uint32_t;namespace ole=ra2::platform::ole_stream951;
// Exact actual65A490/46CDF0 with count0,pointer0: no allocator is reached.
void empty_vector(Memory& m,U p,U initial,U intermediate,U final){
 m.w32(p+4u,0);m.w32(p+8u,0);m.w8(p+12u,1);m.w8(p+13u,0);
 m.w32(p,initial);m.w32(p,intermediate);m.w32(p+20u,10);m.w32(p+16u,0);m.w32(p,final);
}
void wrappers(Memory& m,U self){
 empty_vector(m,self+0x2254u,0x788a14u,0x78bb9cu,0x788a34u);
 empty_vector(m,self+0x2270u,0x7889d4u,0x788a94u,0x7889f4u);
 empty_vector(m,self+0x228cu,0x7889d4u,0x788a94u,0x7889f4u);
}
// Exact finite252810 composition; canonical B77 supplies the actual RNG body.
void restore_members(Memory& m,U self){
 global_b26::Inputs rng{};rng.cx=self+0x218u;rng.arg[0]=0;
 (void)global_b26::fun_0062fd30(m,rng);
 const U raw=ra2::platform::ticks1403::Tick::get();
 m.w32(self+0x620u,raw>>4u);m.w32(self+0x628u,0);
 wrappers(m,self);
 ole::need(m.r8(self+0x7d8u)==0,"B1403 empty localized-name member");
 m.w32(self+0x7d4u,0x82208cu);
}
}
std::uint32_t fun_00658070(Memory& m,const Inputs& i){
 const U self=i.cx,stream=i.arg[0];
 ole::need(self!=0&&m.r32(self+0x614u)==0xffffffffu,"B1403 paused destination before load");
 ole::need(stream==ole::Stream::current().address(),"B1403 genuine live IStream");
 auto* p=reinterpret_cast<IStream*>(std::uintptr_t(stream));
 std::array<std::uint8_t,0x2460u> object{};
 ole::need(p->Read(object.data(),U(object.size()),nullptr)==S_OK,"B1403 complete actual raw Read");
 for(U k=0;k<object.size();++k)m.w8(self+k,object[k]);
 ole::need(m.r32(self+0x614u)==0xffffffffu,"B1403 actual writer serialized paused state");
 restore_members(m,self);
 constexpr U at[]{0x2254u,0x2270u,0x228cu};
 for(U j=0;j<3u;++j){
  empty_vector(m,self+at[j],j==0u?0x788a14u:0x7889d4u,j==0u?0x78bb9cu:0x788a94u,j==0u?0x788a34u:0x7889f4u);
  // Fourregistersaves+SUB8 giveT=S-24. LEA afterPUSH0 givesT+28=S+4.
  // Each real count Read overwrites outerarg0. ESI retains the genuine stream.
  ole::need(p->Read(&i.arg[0],4,nullptr)==S_OK&&i.arg[0]==0,"B1403 actual three empty vector counts");
 }
 ole::need(m.r32(self+0x2264u)==0&&m.r8(self+0x7d8u)==0,"B1403 no remap or localization branch");
 m.w32(self+0x7d4u,0x82208cu);
 ole::need(m.r32(self+0x614u)==0xffffffffu,"B1403 final timer resume required");
 m.w32(self+0x614u,ra2::platform::ticks1403::Tick::get()>>4u);
 // Actual4068F0 is C3. It preserves EAX loaded from serialized opaque member618.
 return m.r32(self+0x618u);
}
}
