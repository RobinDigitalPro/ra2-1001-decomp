#include "recovered/recovery_b1011.hpp"
#include "platform/ole_property1011.hpp"
#include "platform/ole_storage973.hpp"
#include <array>
#include <cstddef>
namespace ra2::recovered::b1011 {
namespace p=ra2::platform::ole_property1011;
namespace s=ra2::platform::ole_storage973;
static_assert(sizeof(PROPVARIANT)==16&&offsetof(PROPVARIANT,filetime)==8&&sizeof(PROPSPEC)==8,"Original x86 property ABI");
namespace {
std::wstring wide(Memory&m,unsigned address){std::wstring out;for(unsigned k=0;k<128u;++k){unsigned c=m.r8(address+2*k)|(m.r8(address+2*k+1)<<8);if(!c)return out;out.push_back(wchar_t(c));}throw std::domain_error("1011 bounded terminated UTF16 input");}
unsigned stream_write(Memory&m,const Inputs&i,unsigned type){
 auto&owner=s::Storage::current();s::need(i.arg[0]==owner.address(),"1011 actual IStorage identity");
 std::vector<std::uint8_t> bytes;
 if(type==0u){const auto text=wide(m,i.arg[2]);for(auto c:text){bytes.push_back(std::uint8_t(c));bytes.push_back(std::uint8_t(unsigned(c)>>8));}bytes.push_back(0);bytes.push_back(0);}
 else if(type==1u){for(unsigned k=0;k<4;++k)bytes.push_back(std::uint8_t(i.arg[2]>>(8*k)));}
 else {for(unsigned k=0;k<8;++k)bytes.push_back(std::uint8_t(m.r8(i.arg[2]+k)));}
 IStream*stream=nullptr;const auto opened=owner.get()->CreateStream(s::item(i.arg[1]).name,0x12u,0u,0u,&stream);s::need(opened==S_OK&&stream,"1011 create absent genuine metadata stream");
 const auto written=stream->Write(bytes.data(),ULONG(bytes.size()),nullptr);s::need(written==S_OK,"1011 positive whole stream write");
 const auto committed=stream->Commit(0);stream->Release();s::need(committed==S_OK,"1011 positive stream commit");return unsigned(committed);
}
unsigned property_write(Memory&m,const Inputs&i,unsigned type){
 auto&owner=p::Storage::current();p::need(i.arg[0]==owner.address(),"1011 actual IPropertySetStorage identity");
 IPropertyStorage*property=nullptr;const auto opened=owner.get()->Open(p::fmtid,0x12u,&property);p::need(opened==S_OK&&property,"1011 existing original FMTID route");
 PROPSPEC spec{};spec.ulKind=PRSPEC_PROPID;spec.propid=i.arg[1];PROPVARIANT value{};std::wstring text;
 if(type==0u){text=wide(m,i.arg[2]);value.vt=VT_LPWSTR;value.pwszVal=text.data();}
 else if(type==1u){value.vt=VT_I4;std::memcpy(&value.lVal,&i.arg[2],4);}
 else{value.vt=VT_FILETIME;value.filetime.dwLowDateTime=m.r32(i.arg[2]);value.filetime.dwHighDateTime=m.r32(i.arg[2]+4);}
 const auto written=property->WriteMultiple(1,&spec,&value,2u);property->Release();p::need(written==S_OK,"1011 positive typed WriteMultiple");return unsigned(written);
}
}
std::uint32_t fun_00651a60(Memory&m,const Inputs&i){return stream_write(m,i,0);}
std::uint32_t fun_00651d70(Memory&m,const Inputs&i){return stream_write(m,i,1);}
std::uint32_t fun_006520f0(Memory&m,const Inputs&i){return stream_write(m,i,2);}
std::uint32_t fun_00651c80(Memory&m,const Inputs&i){return property_write(m,i,0);}
std::uint32_t fun_00651e60(Memory&m,const Inputs&i){return property_write(m,i,1);}
std::uint32_t fun_006521e0(Memory&m,const Inputs&i){return property_write(m,i,2);}
}
