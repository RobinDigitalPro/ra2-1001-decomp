#include "recovered/recovery_b951.hpp"
#include "platform/ole_stream951.hpp"
namespace ra2::recovered::recovery_b951 {
std::uint32_t fun_00436640(Memory&m,const Inputs&i){auto&s=ra2::platform::ole_stream951::Stream::current();std::uint32_t result=0;for(auto off:{0u,0x18u}){auto count=m.r32(i.cx+0x10+off);if(count>8)throw std::domain_error("951 finite array count");result=s.write_word(i.arg[0],count);if(std::int32_t(result)<0)return result;for(std::uint32_t j=0;j<count;++j){result=s.write_word(i.arg[0],m.r32(m.r32(i.cx+4+off)+j*4));if(std::int32_t(result)<0)return result;}}return result;}
}
