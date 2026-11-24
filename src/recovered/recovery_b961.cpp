#define NOMINMAX
#include <windows.h>
#include <objidl.h>
#include <cstdint>
#include <stdexcept>
#include "recovered/recovery_b961.hpp"
#include "platform/ole_stream951.hpp"
namespace ra2::recovered::recovery_b961 {
namespace {
void need(bool ok,const char* message){if(!ok)throw std::runtime_error(message);}
void read_exact(IStream* s,void* out,ULONG n){HRESULT hr=s->Read(out,n,nullptr);need(hr==S_OK,"B961 positive genuine IStream::Read");}
}
std::uint32_t fun_00491bf0(Memory& m,const Inputs& i,Heap& h){
 const std::uint32_t receiver=i.cx;
 const std::uint32_t stream_address=i.arg[0]; // preserve real IStream* before count overwrites caller arg0
 need(receiver&&stream_address==ra2::platform::ole_stream951::Stream::current().address(),"B961 valid receiver and genuine stream required");
 m.w32(receiver,0x007895acu);m.w32(receiver+4u,0u);m.w32(receiver+8u,0u);m.w8(receiver+0x0cu,1u);m.w8(receiver+0x0du,0u);
 auto* stream=reinterpret_cast<IStream*>(std::uintptr_t(stream_address));
 read_exact(stream,const_cast<std::uint32_t*>(&i.arg[0]),4u); // original destination is entry stack arg0
 const std::uint32_t count=i.arg[0];
 if(count<1u||count>8u)throw std::domain_error("B961 finite count contract 1..8");
 // Positive 0x6CCB0 route: null destination allocates count*4 bytes via
 // the proven ordinary-heap chain, then publishes data/count/ownership fields.
 m.w8(receiver+0x0cu,0u);
 const std::uint32_t data=h.allocate(count*4u);
 if(!data)throw std::runtime_error("B961 positive heap allocation failed");
 m.w8(receiver+0x0cu,1u);m.w32(receiver+4u,data);m.w32(receiver+8u,count);m.w8(receiver+0x0du,1u);
 for(std::uint32_t j=0;j<count;++j){std::uint32_t value=0;read_exact(stream,&value,4u);h.w32(data+j*4u,value);}
 return 0u;
}
}
