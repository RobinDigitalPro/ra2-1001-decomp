#include "recovered/recovery_b1012.hpp"
#include "recovered/recovery_b1011.hpp"
#include "platform/ole_property1011.hpp"
#include "platform/ole_storage973.hpp"
#include "platform/observed_cp975.hpp"
#include <array>
namespace ra2::recovered::b1012 {
namespace p=ra2::platform::ole_property1011;namespace s=ra2::platform::ole_storage973;
namespace {
enum class Type{wide,integer,ticks,ansi};struct Row{unsigned id,offset;Type type;};
constexpr Row rows[]={{2,8,Type::wide},{3,0x108,Type::wide},{9,4,Type::integer},{0x10,0,Type::integer},{0xc,0x3d8,Type::ticks},{0xd,0x3e8,Type::ticks},{0xa,0x3e0,Type::ticks},{0x12,0x2d4,Type::ansi},{4,0x294,Type::ansi},{8,0x294,Type::ansi},{0x64,0x18c,Type::integer},{0x65,0x188,Type::integer},{0x66,0x3f0,Type::integer}};
std::wstring wide(Memory&m,unsigned a){std::wstring v;for(unsigned j=0;j<128u;++j){const auto c=m.r8(a+j*2u)|(m.r8(a+j*2u+1u)<<8u);if(!c)return v;v.push_back(wchar_t(c));}throw std::domain_error("1012 terminated UTF16 input");}
std::wstring converted(Memory&m,unsigned a){std::string v;for(unsigned j=0;j<128u;++j){const auto c=m.r8(a+j);if(!c){std::array<wchar_t,128>out{};const int count=ra2::platform::cp975::convert(CP_ACP,0,v.c_str(),-1,out.data(),128);p::need(count>0&&count<=128,"1012 positiveactualACPconversion");return std::wstring(out.data(),unsigned(count)-1u);}p::need(c<128u,"1012 boundedASCII input");v.push_back(char(c));}throw std::domain_error("1012 terminatedASCIIinput");}
void ansi_property(Memory&m,unsigned source,unsigned id,IPropertySetStorage*sets){const auto text=converted(m,source);IPropertyStorage*property=nullptr;p::need(sets->Open(p::fmtid,0x12u,&property)==S_OK&&property,"1012 actualexistingFMTID Open");PROPSPEC spec{};spec.ulKind=PRSPEC_PROPID;spec.propid=id;PROPVARIANT value{};value.vt=VT_LPWSTR;value.pwszVal=const_cast<wchar_t*>(text.c_str());const auto hr=property->WriteMultiple(1u,&spec,&value,2u);property->Release();p::need(hr==S_OK,"1012 realANSIproperty WriteMultiple");}
void stream(Memory&m,unsigned receiver,const Row&r,IStorage*storage){std::vector<unsigned char>bytes;if(r.type==Type::wide||r.type==Type::ansi){const auto text=r.type==Type::wide?wide(m,receiver+r.offset):converted(m,receiver+r.offset);for(auto c:text){bytes.push_back(static_cast<unsigned char>(c));bytes.push_back(static_cast<unsigned char>(unsigned(c)>>8u));}bytes.push_back(0u);bytes.push_back(0u);}else{const unsigned count=r.type==Type::integer?4u:8u;for(unsigned k=0;k<count;++k)bytes.push_back(static_cast<unsigned char>(m.r8(receiver+r.offset+k)));}IStream*target=nullptr;p::need(storage->CreateStream(s::item(r.id).name,0x12u,0u,0u,&target)==S_OK&&target,"1012 realabsentmetadata CreateStream");const auto hr=target->Write(bytes.data(),ULONG(bytes.size()),nullptr);p::need(hr==S_OK,"1012 actualwholemetadata Write");const auto committed=target->Commit(0u);target->Release();p::need(committed==S_OK,"1012 actualmetadata Commit");}
}
unsigned fun_006505c0(Memory&m,const Inputs&input){auto&i=const_cast<Inputs&>(input);auto&owner=p::Storage::current();const auto life=owner.lifetime();p::need(i.arg[0]==life.storage,"1012 actualsamecompoundIStorage identity");auto*storage=reinterpret_cast<IStorage*>(std::uintptr_t(i.arg[0]));IPropertySetStorage*sets=nullptr;i.arg[0]=0u;const auto hr=storage->QueryInterface(p::iid_sets,reinterpret_cast<void**>(&sets));p::need(hr==S_OK&&sets&&p::pointer(sets)==owner.address(),"1012 genuineQIsetsidentity");i.arg[0]=p::pointer(sets); // Original QI out-param aliases callerword0.
 for(const auto&r:rows){if(r.type==Type::ansi){ansi_property(m,i.cx+r.offset,r.id,sets);continue;}Inputs nested{};nested.cx=i.cx;nested.arg[0]=p::pointer(sets);nested.arg[1]=r.id;nested.arg[2]=r.type==Type::integer?m.r32(i.cx+r.offset):i.cx+r.offset;const unsigned status=r.type==Type::wide?ra2::recovered::b1011::fun_00651c80(m,nested):r.type==Type::integer?ra2::recovered::b1011::fun_00651e60(m,nested):ra2::recovered::b1011::fun_006521e0(m,nested);p::need(status==0u,"1012 positive typedproperty helper");}
 // Original success path always continues to all thirteen metadata streams.
 for(const auto&r:rows)stream(m,i.cx,r,storage);sets->Release();return 0u; //650B16 XOREAX after finalRelease.
}
}
