#include "recovered/recovery_b1010.hpp"
#include "recovered/text_bytes.hpp"
#include <cstring>
namespace ra2::recovered::b1010 {
namespace ole=ra2::platform::ole_property1010;
namespace{
std::uint32_t read(Memory&m,Inputs&i,Observation&o,unsigned type){
 const auto destination=i.arg[2];if(type==VT_LPWSTR)m.w16(destination,0u);else{m.w32(destination,0u);if(type==VT_FILETIME)m.w32(destination+4u,0u);}i.arg[2]=0u;auto&owner=ole::Storage::current();ole::need(i.arg[0]==owner.address(),"1010 actual provider identity");IPropertyStorage*p=nullptr;o.open_result=owner.get()->Open(ole::fmtid,0x12u,&p);ole::need(o.open_result==S_OK&&p,"1010 positive genuine Open");o.open_pointer=ole::pointer(p);o.live_vtable=*reinterpret_cast<const std::uint32_t*>(p);i.arg[2]=o.open_pointer;PROPSPEC spec{};spec.ulKind=PRSPEC_PROPID;spec.propid=i.arg[1];o.spec_kind=spec.ulKind;o.spec_id=spec.propid;
 PROPVARIANT value;static_assert(sizeof(value)==16u,"1010 original x86 PROPVARIANT");const std::uint32_t seed[4]{i.ax,i.cx,i.dx,i.stack_minus8};std::memcpy(&value,seed,16u);o.read_result=p->ReadMultiple(1u,&spec,&value);ole::need(o.read_result==S_OK&&value.vt==type,"1010 positive typed ReadMultiple");std::memcpy(o.variant.data(),&value,16u);
 if(type==VT_LPWSTR){ole::need(value.pwszVal!=nullptr,"1010 live caller-owned ReadMultiple string");std::array<std::uint16_t,128>copy{};ra2::recovered::fun_0076ef62(copy.data(),reinterpret_cast<const std::uint16_t*>(value.pwszVal),128u);for(unsigned k=0;k<128u;++k)m.w16(destination+k*2u,copy[k]);}else if(type==VT_I4)m.w32(destination,std::uint32_t(value.lVal));else{m.w32(destination,value.filetime.dwLowDateTime);m.w32(destination+4u,value.filetime.dwHighDateTime);}p->Release();return std::uint32_t(o.read_result);
}
}
std::uint32_t fun_006516b0(Memory&m,Inputs&i,Observation&o){return read(m,i,o,VT_LPWSTR);}std::uint32_t fun_00651850(Memory&m,Inputs&i,Observation&o){return read(m,i,o,VT_I4);}std::uint32_t fun_00652010(Memory&m,Inputs&i,Observation&o){return read(m,i,o,VT_FILETIME);}
}
