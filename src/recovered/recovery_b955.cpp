#include "recovery_b955.hpp"
#include "platform/ole_stream951.hpp"
#include <algorithm>
#include <array>
#include <cstdint>
#include <objidl.h>
namespace ra2::recovered::b955 {
std::uint32_t fun_00494de0(Memory&m,const Inputs&i){
 const std::uint32_t self=i.cx,input=i.arg[0],input_len=i.arg[1];
 if(input_len>13)throw std::domain_error("955 shortinput contract");
 const std::uint32_t output=m.r32(self+0x1cu);
 const std::uint32_t output_len=input_len==0?3u:input_len+4u;
 std::array<std::uint8_t,17> frame{};
 if(input_len==0){frame[0]=17;}
 else {frame[0]=std::uint8_t(input_len+17u);for(std::uint32_t n=0;n<input_len;++n)frame[n+1]=m.r8(input+n);frame[input_len+1]=17;}
 m.w32(self+0x24u,output_len);m.w32(self+0x28u,0x10000u);
 for(std::uint32_t n=0;n<output_len;++n)m.w8(output+n,frame[n]);
 const auto stream_ptr=m.r32(self+8u);auto*stream=reinterpret_cast<IStream*>(std::uintptr_t(stream_ptr));
 ra2::platform::ole_stream951::need(stream_ptr==ra2::platform::ole_stream951::Stream::current().address(),"955 genuine provider identity");
 std::array<std::uint32_t,2> header{{m.r32(self+0x24u),m.r32(self+0x28u)}};
 ULONG written=0;HRESULT hr=stream->Write(header.data(),8,&written);i.arg[1]=written;
 if(FAILED(hr))return std::uint32_t(hr);if(written!=8)return 0x80004005u;
 std::array<std::uint8_t,17> payload{};for(std::uint32_t n=0;n<output_len;++n)payload[n]=std::uint8_t(m.r8(output+n));
 written=0;hr=stream->Write(payload.data(),output_len,&written);i.arg[1]=written;
 if(FAILED(hr))return std::uint32_t(hr);return written==output_len?0u:0x80004005u;
}
}
