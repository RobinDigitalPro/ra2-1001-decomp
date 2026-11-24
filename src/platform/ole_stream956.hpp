#pragma once
#include "platform/ole_stream951.hpp"
#include "recovered/global_b26_memory.hpp"
#include <vector>
namespace ra2::platform::ole_stream956 {
inline void write_range(ra2::recovered::global_b26::Memory&m,std::uint32_t stream,std::uint32_t source,std::uint32_t size){auto&s=ra2::platform::ole_stream951::Stream::current();ra2::platform::ole_stream951::need(stream==s.address(),"956 expected genuine IStream");std::vector<std::uint8_t>b(size);for(std::uint32_t k=0;k<size;++k)b[k]=std::uint8_t(m.r8(source+k));if(size){ULONG written=0;auto*p=reinterpret_cast<IStream*>(static_cast<std::uintptr_t>(stream));ra2::platform::ole_stream951::need(p->Write(b.data(),size,&written)==S_OK&&written==size,"956 genuine Write failed");}}
inline void write_word(ra2::recovered::global_b26::Memory&m,std::uint32_t stream,std::uint32_t value){std::uint8_t b[4]{std::uint8_t(value),std::uint8_t(value>>8),std::uint8_t(value>>16),std::uint8_t(value>>24)};auto&s=ra2::platform::ole_stream951::Stream::current();ra2::platform::ole_stream951::need(stream==s.address(),"956 expected genuine IStream");ULONG written=0;auto*p=reinterpret_cast<IStream*>(static_cast<std::uintptr_t>(stream));ra2::platform::ole_stream951::need(p->Write(b,4,&written)==S_OK&&written==4,"956 genuine word Write failed");}
}
