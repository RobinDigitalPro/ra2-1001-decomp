#include "recovered/recovery_b956.hpp"
#include "platform/ole_stream956.hpp"
namespace ra2::recovered::recovery_b956 {
using ra2::platform::ole_stream956::write_range;using ra2::platform::ole_stream956::write_word;
std::uint32_t fun_00428ac0(Memory&m,const Inputs&){return ((m.r32(0x0081a914u)+4u)*m.r32(0x0081a910u))<<1;}
std::uint32_t fun_00706d10(Memory&m,const Inputs&i){const auto stream=i.cx;write_word(m,stream,m.r32(0x00ab81d8u));const auto payload=fun_00428ac0(m,i);write_range(m,stream,m.r32(0x00ab8220u),payload);const auto count=m.r32(0x00ab81d8u);const auto range=(m.r32(m.r32(0x00821b88u)+0xd4u))<<3;for(std::uint32_t n=0;n<count;++n){const auto record=m.r32(m.r32(0x00ab81ccu)+n*4);write_word(m,stream,record);write_range(m,stream,record,0xf0);write_range(m,stream,m.r32(record+0xb0),payload);write_range(m,stream,m.r32(record+0xa0),range);const auto queue=m.r32(record+0x9c),base=m.r32(record+0xa0);write_word(m,stream,m.r32(queue));write_word(m,stream,m.r32(queue+4));for(std::uint32_t j=0;j<m.r32(queue+4);++j)write_word(m,stream,(m.r32(m.r32(queue+8)+j*4)-base)>>3);}return 1;}
}

