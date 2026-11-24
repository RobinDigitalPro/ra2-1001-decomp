#include "recovery_b1391.hpp"
#include "recovered/recovery_b1360.hpp"
#include "platform/ole_stream951.hpp"
namespace ra2::recovered::b1391 {
std::uint32_t fun_006dd600(Memory& m,const Inputs& i){
 using U=std::uint32_t;namespace ole=ra2::platform::ole_stream951;
 const U stream=i.arg[0];ole::need(stream==ole::Stream::current().address(),"B1391 genuine owned COM stream");
 auto* p=reinterpret_cast<IStream*>(std::uintptr_t(stream));
 U first=0,second=0;
 const U hr1=U(p->Read(&first,4,nullptr));ole::need(hr1==0u&&first==0xffffffffu,"B1391 exact first successful sentinel read");
 i.arg[0]=first; //6DD60B actual destination is outerarg0, not private storage.
 const U hr2=U(p->Read(&second,4,nullptr));ole::need(hr2==0u&&second==0xffffffffu,"B1391 exact second successful sentinel read");
 ole::need(m.r8(0xa28791u)==1u,"B1391 restore enabled");
 Inputs child=i;child.cx=0xa1e0a8u;child.arg[0]=first;
 (void)b1360::fun_006dd170(m,child);i.fp=child.fp;
 ole::need(m.r8(0xa28858u)==1u&&m.r32(0x819778u)!=0u&&m.r8(0xa2894cu)==0u,"B1391 real406F30 enabled restore arm");
 m.w32(0xa1e0b0u,second);
 return hr2; //EDI preserves complete second HRESULT through helper calls.
}
}
