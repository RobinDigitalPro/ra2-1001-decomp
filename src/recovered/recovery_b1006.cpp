#include "recovery_b1006.hpp"
#include "platform/observed_registry1006.hpp"
namespace ra2::recovered::recovery_b1006 {using platform::registry1006::Observer;
static std::string text(Memory&m,unsigned p){if(!p)throw std::domain_error("1006 nonnullstrings");std::string s;for(unsigned j=0;j<120u;++j){const auto c=m.r8(p+j);if(!c)return s;s+=char(c);}throw std::domain_error("1006 boundedtext");}
unsigned fun_006832b0(Memory&m,const Inputs&i){const auto path=text(m,i.cx)+"\\"+text(m,i.dx),value=text(m,i.arg[0]);if(path.size()>=260u||value.empty())throw std::domain_error("1006 boundedpositivewrite");HKEY key{};if(Observer::create(HKEY_CLASSES_ROOT,path.c_str(),0,nullptr,0,0xf003f,nullptr,&key,nullptr)!=0)throw std::domain_error("1006 actualpositivecreate");if(Observer::set(key,nullptr,0,REG_SZ,reinterpret_cast<const BYTE*>(value.c_str()),DWORD(value.size()+1u))!=0)throw std::domain_error("1006 actualpositiveset");const auto status=Observer::close(key);if(status!=0)throw std::domain_error("1006 actualpositiveclose");return (unsigned(status)&0xffffff00u)|1u;}
}
