#include "recovered/recovery_b957.hpp"
#include "platform/ole_stream952.hpp"
namespace ra2::recovered::recovery_b957 {
using ra2::platform::ole_stream952::write_range;
using ra2::platform::ole_stream952::write_word;
static std::uint32_t write_counted(Memory& m, std::uint32_t stream, std::uint32_t count_address, std::uint32_t data_address, std::uint32_t stride) {
    const auto n=m.r32(count_address);
    auto hr=write_word(stream,n);
    if(std::int32_t(hr)<0) return std::uint32_t(hr);
    const auto data=m.r32(data_address);
    for(std::uint32_t k=0;k<n;++k) {
        hr=write_range(m,stream,data+k*stride,stride);
        if(std::int32_t(hr)<0) return std::uint32_t(hr);
    }
    return std::uint32_t(hr);
}
std::uint32_t fun_0062a490(Memory& m,const Inputs& i) {
    const auto receiver=i.cx;
    const auto stream=i.arg[0];
    for(std::uint32_t d=0;d<5;++d) {
        const auto descriptor=0x83a8a8u+d*0x18u;
        const auto hr=write_counted(m,stream,descriptor+0x10,descriptor+4,4);
        if(std::int32_t(hr)<0) return hr;
    }
    auto count=m.r32(receiver+0x1268);
    i.arg[0]=count;
    auto hr=write_word(stream,count);
    if(std::int32_t(hr)<0) return std::uint32_t(hr);
    auto records=m.r32(receiver+0x125c);
    for(std::uint32_t k=0;k<count;++k) {
        hr=write_range(m,stream,records+k*8,8);
        if(std::int32_t(hr)<0) return std::uint32_t(hr);
    }
    count=m.r32(receiver+0x1230);
    i.arg[0]=count;
    hr=write_word(stream,count);
    if(std::int32_t(hr)<0) return std::uint32_t(hr);
    const auto values=m.r32(receiver+0x1224);
    for(std::uint32_t k=0;k<count;++k) {
        hr=write_range(m,stream,values+k*4,4);
        if(std::int32_t(hr)<0) return std::uint32_t(hr);
    }
    for(const auto offset:{0x14acu,0x14a8u,0x14b0u,0x14b4u}) {
        hr=write_range(m,stream,receiver+offset,4);
        if(std::int32_t(hr)<0) return std::uint32_t(hr);
    }
    return 0;
}
}
