#include "recovered/recovery_b975.hpp"
#include "platform/observed_cp975.hpp"
#include "platform/ole_property975.hpp"
#include <array>
#include <cstddef>
#include <string>
namespace ra2::recovered::recovery_b975{
static_assert(sizeof(PROPVARIANT)==16u&&offsetof(PROPVARIANT,pwszVal)==8u&&sizeof(PROPSPEC)==8u,"975 exact x86 COM property ABI");
std::uint32_t fun_00651b60(Memory&m,const Inputs&i){namespace ole=ra2::platform::ole_property975;auto&owner=ole::Storage::current();ole::need(i.arg[0]==owner.address(),"975 genuine IPropertySetStorage identity");std::string source;for(unsigned k=0;k<128u;++k){const auto c=m.r8(i.arg[2]+k);if(!c)break;ole::need(c<128u&&k<127u,"975 bounded ASCII input");source.push_back(char(c));}std::array<wchar_t,128>wide{};const auto converted=ra2::platform::cp975::convert(CP_ACP,0,source.c_str(),-1,wide.data(),128);ole::need(converted>=1&&converted<=128,"975 actual complete conversion");IPropertyStorage*p=nullptr;const auto opened=owner.get()->Open(ole::fmtid,0x12u,&p);ole::need(opened==S_OK&&p,"975 existing-FMTID positive Open route");PROPSPEC spec{};spec.ulKind=PRSPEC_PROPID;spec.propid=i.arg[1];PROPVARIANT v{};v.vt=VT_LPWSTR;v.pwszVal=wide.data();const auto written=p->WriteMultiple(1u,&spec,&v,2u);p->Release();ole::need(written==S_OK,"975 actual positive WriteMultiple");return std::uint32_t(written);}
}
