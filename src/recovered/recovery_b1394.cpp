#include "recovery_b1394.hpp"
#include "platform/ole_stream951.hpp"
namespace ra2::recovered::b1394 {
using U=std::uint32_t;namespace ole=ra2::platform::ole_stream951;
void zero_record(Memory&m,U p){for(U o:{0u,4u,8u,16u})m.w32(p+o,0);m.w8(p+12u,0);}
std::uint32_t fun_005d02c0(Memory&m,const Inputs&i){
 const U self=i.arg[0],stream=i.arg[1];ole::need(m.r32(self)==0x7881f8u&&m.r32(0x788228u)==0x45e980u,"B1394 genuine concrete size provider");
 ole::need(stream==ole::Stream::current().address(),"B1394 genuine IStream");
 for(U o:{0x214u,0x228u,0x23cu,0x250u}){ole::need(m.r32(self+o)==0u,"B1394 genuine null-buffer cleanup");zero_record(m,self+o);}
 for(U o=0xb0u;o<=0xc4u;o+=4u)ole::need(m.r32(self+o)==0u,"B1394 empty single art owners");
 for(U k=0;k<15u;++k)for(U o:{0xc8u,0xccu,0x140u,0x144u})ole::need(m.r32(self+o+8u*k)==0u,"B1394 genuine empty indexed art owners");
 auto* p=reinterpret_cast<IStream*>(std::uintptr_t(stream));U id=0;
 ole::need(p->Read(&id,4,nullptr)==S_OK&&id!=0u,"B1394 successful ID Read");
 const U count=m.r32(0xaa539cu),capacity=m.r32(0xaa5394u),slots=m.r32(0xaa5390u);
 ole::need(count<capacity&&capacity==8u,"B1394 actual6951F0 room-capacity registration");
 m.w32(slots+8u*count,id);m.w32(slots+8u*count+4u,self);m.w32(0xaa539cu,count+1u);
 const U old=m.r32(self+0x1cu);std::vector<std::uint8_t> blob(0x1418);
 ole::need(p->Read(blob.data(),ULONG(blob.size()),nullptr)==S_OK,"B1394 complete actual object Read");
 for(U k=0;k<blob.size();++k)m.w8(self+k,blob[k]);m.w32(self+0x1cu,old);
 m.w32(self+0xa4u,0u);m.w8(self+0xa8u,0u);m.w32(self+0xacu,0u);
 for(U o:{0x214u,0x228u,0x23cu,0x250u})zero_record(m,self+o);
 for(U o=0xb0u;o<=0xc4u;o+=4u)m.w32(self+o,0u);
 for(U k=0;k<15u;++k)for(U o:{0xc8u,0xccu,0x140u,0x144u})m.w32(self+o+8u*k,0u);
 ole::need(m.r8(self+0x1e3u)==0u,"B1394 empty optional image filename from actual stream");
 return 0u;
}
}
