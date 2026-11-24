#include "recovered/recovery_b952.hpp"
#include "platform/ole_stream952.hpp"
namespace ra2::recovered::recovery_b952 {
using ra2::platform::ole_stream952::write_range;
using ra2::platform::ole_stream952::write_word;
static std::uint32_t root2c_result(HRESULT hr){return std::int32_t(hr)<0?0u:std::uint32_t(hr);}
static std::uint32_t preserve_hr(HRESULT hr){return std::uint32_t(hr);}
static std::uint32_t counted_words(Memory&m,std::uint32_t stream,std::uint32_t count_address,std::uint32_t pointer_address){
 const auto count=m.r32(count_address);auto hr=write_word(stream,count);if(std::int32_t(hr)<0)return preserve_hr(hr);
 const auto base=m.r32(pointer_address);for(std::uint32_t k=0;k<count;++k){hr=write_range(m,stream,base+4*k,4);if(std::int32_t(hr)<0)return preserve_hr(hr);}return root2c_result(hr);
}
std::uint32_t fun_0042c8e0(Memory&m,const Inputs&i){
 const auto receiver=i.arg[0];const auto stream=i.arg[1];HRESULT hr=write_range(m,stream,receiver,0x78);if(std::int32_t(hr)<0)return preserve_hr(hr);
 auto count=m.r32(receiver+0x14);i.arg[1]=count;hr=write_word(stream,count);if(std::int32_t(hr)<0)return preserve_hr(hr);
 auto records=m.r32(receiver+0x08);for(std::uint32_t k=0;k<count;++k){hr=write_range(m,stream,records+16*k,16);if(std::int32_t(hr)<0)return preserve_hr(hr);}
 count=m.r32(receiver+0x30);i.arg[1]=count;hr=write_word(stream,count);if(std::int32_t(hr)<0)return preserve_hr(hr);
 auto values=m.r32(receiver+0x24);for(std::uint32_t k=0;k<count;++k){hr=write_range(m,stream,values+4*k,4);if(std::int32_t(hr)<0)return preserve_hr(hr);}
 count=m.r32(receiver+0x48);i.arg[1]=count;hr=write_word(stream,count);if(std::int32_t(hr)<0)return preserve_hr(hr);
 values=m.r32(receiver+0x3c);for(std::uint32_t k=0;k<count;++k){hr=write_range(m,stream,values+4*k,4);if(std::int32_t(hr)<0)return preserve_hr(hr);}return root2c_result(hr);
}
std::uint32_t fun_0051e930(Memory&m,const Inputs&i){const auto stream=i.cx;HRESULT hr;
 for(const auto& q:{std::pair<std::uint32_t,std::uint32_t>{0x00a39574,1},{0x007c8bd0,4},{0x007c8bd4,4},{0x00a39578,4},{0x00a39584,1},{0x007c8bd8,4},{0x007c8bdc,4},{0x00a3957c,4},{0x00a394b8,4},{0x00a39580,4}}){hr=write_range(m,stream,q.first,q.second);if(std::int32_t(hr)<0)return preserve_hr(hr);}
 for(const auto& q:{std::pair<std::uint32_t,std::uint32_t>{0x00a39558,0x00a3954c},{0x00a394d0,0x00a394c4},{0x00a39518,0x00a3950c}}){hr=std::int32_t(counted_words(m,stream,q.first,q.second));if(std::int32_t(hr)<0)return preserve_hr(hr);}return preserve_hr(hr);
}
std::uint32_t fun_0064eaf0(Memory&m,const Inputs&i){const auto stream=i.cx;HRESULT hr;
 for(const auto&q:{std::pair<std::uint32_t,std::uint32_t>{0x00a28960,4},{0x00a1e0e4,4},{0x00a2896c,4}}){hr=write_range(m,stream,q.first,q.second);if(std::int32_t(hr)<0)return preserve_hr(hr);}
 hr=std::int32_t(counted_words(m,stream,0x00a288b0,0x00a288a4));if(std::int32_t(hr)<0)return preserve_hr(hr);
 hr=write_range(m,stream,0x008391d0,0x1b0);if(std::int32_t(hr)<0)return preserve_hr(hr);
 Inputs child{};child.cx=stream;const auto child_result=fun_0051e930(m,child);hr=HRESULT(child_result);if(std::int32_t(hr)<0)return preserve_hr(hr);
 for(const auto&q:{std::pair<std::uint32_t,std::uint32_t>{0x0084e4a0,0x0084e494},{0x0084e578,0x0084e56c}}){hr=std::int32_t(counted_words(m,stream,q.first,q.second));if(std::int32_t(hr)<0)return preserve_hr(hr);}
 for(const auto&q:{std::pair<std::uint32_t,std::uint32_t>{0x007bea10,0x4c},{0x007bea5c,0x4c},{0x008393b0,0x98},{0x00839448,0x13},{0x00a28000,0x3c0},{0x00aa0c7c,4}}){hr=write_range(m,stream,q.first,q.second);if(std::int32_t(hr)<0)return preserve_hr(hr);}return std::int32_t(hr)<0?preserve_hr(hr):0u;
}
}
