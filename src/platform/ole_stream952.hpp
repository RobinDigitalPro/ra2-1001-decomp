#pragma once
#include "platform/ole_stream951.hpp"
#include "recovered/global_b26_memory.hpp"
#include <vector>
#include <array>
namespace ra2::platform::ole_stream952 {
using ra2::recovered::global_b26::Memory;
inline HRESULT write_bytes(std::uint32_t stream_address,const std::uint8_t* bytes,std::uint32_t size){
 auto& provider=ra2::platform::ole_stream951::Stream::current();
 ra2::platform::ole_stream951::need(stream_address==provider.address(),"952 stable genuine stream identity");
 auto* stream=reinterpret_cast<IStream*>(std::uintptr_t(stream_address));
 const HRESULT result=stream->Write(bytes,ULONG(size),nullptr);
 ra2::platform::ole_stream951::need(result==S_OK,"952 successful write contract");return result;
}
inline HRESULT write_range(Memory&m,std::uint32_t stream_address,std::uint32_t source,std::uint32_t size){
 std::vector<std::uint8_t> local(size);for(std::uint32_t k=0;k<size;++k)local[k]=std::uint8_t(m.r8(source+k));
 return write_bytes(stream_address,local.data(),size);
}
inline HRESULT write_word(std::uint32_t stream_address,std::uint32_t value){
 const std::uint8_t local[4]={std::uint8_t(value),std::uint8_t(value>>8),std::uint8_t(value>>16),std::uint8_t(value>>24)};
 return write_bytes(stream_address,local,4);
}
}
