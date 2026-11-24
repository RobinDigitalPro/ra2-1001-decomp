#include "recovered/recovery_b1018.hpp"
#include "platform/std_handles1018.hpp"
namespace ra2::recovered::b1018 {
namespace os=ra2::platform::std_handles1018;
std::uint32_t fun_00776d24(Memory&m,const Inputs&,Heap&h){os::need(m.r32(0x817554u)==0u&&m.r32(0xb10e14u)==0u,"1018 ordinary threshold0/empty small registry");const auto table=h.allocate(0x480u);m.w32(0xb10d00u,table);m.w32(0xb10e00u,32u);for(unsigned j=0;j<32u;++j){const auto p=table+j*36u;h.w8(p+4u,0u);h.w32(p,0xffffffffu);h.w32(p+8u,0u);h.w8(p+5u,10u);}STARTUPINFOA info{};os::Provider::startup(&info);os::need(info.cbReserved2==0u,"1018 actual bounded startup no inherited CRT blob");const DWORD ids[3]{STD_INPUT_HANDLE,STD_OUTPUT_HANDLE,STD_ERROR_HANDLE};for(unsigned j=0;j<3u;++j){const auto p=table+j*36u;h.w8(p+4u,0x81u);const auto handle=os::Provider::standard(ids[j]);const auto type=os::Provider::type(handle);os::need(handle!=INVALID_HANDLE_VALUE&&handle!=nullptr&&type==FILE_TYPE_DISK,"1018 genuine owned disk standard handle");h.w32(p,os::pointer(handle));}return os::Provider::count(32u);}
}
