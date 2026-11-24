#include "recovered/recovery_b973.hpp"
#include "platform/observed_cp973.hpp"
#include "platform/ole_storage973.hpp"
#include <array>
#include <string>
namespace ra2::recovered::recovery_b973{
std::uint32_t fun_00651920(Memory&m,const Inputs&i){namespace ole=ra2::platform::ole_storage973;auto&owner=ole::Storage::current();ole::need(i.arg[0]==owner.address(),"973 genuine storage identity");std::string source;for(unsigned k=0;k<128u;++k){const auto c=m.r8(i.arg[2]+k);if(!c)break;ole::need(c<128u&&k<127u,"973 bounded ASCII source");source.push_back(char(c));}
 std::array<wchar_t,128>wide{};const int converted=ra2::platform::cp973::convert(CP_ACP,0,source.c_str(),-1,wide.data(),128);ole::need(converted>=1&&converted<=128,"973 actual positive conversion");IStream*s=nullptr;HRESULT hr=owner.get()->CreateStream(ole::item(i.arg[1]).name,0x12u,0,0,&s);ole::need(hr==S_OK&&s,"973 genuine target CreateStream");unsigned length=0;while(length<128u&&wide[length])++length;ole::need(length<128u,"973 terminated wide output");hr=s->Write(wide.data(),2u*(length+1u),nullptr);if(hr==S_OK)hr=s->Commit(STGC_DEFAULT);s->Release();ole::need(hr==S_OK,"973 positive genuine Write/Commit");return std::uint32_t(hr);
}
}
