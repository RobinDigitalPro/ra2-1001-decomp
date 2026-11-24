#include "recovered/recovery_b1116.hpp"
#include <stdexcept>
namespace ra2::recovered::b1116{
unsigned run(Memory&m,const Inputs&i,Api&a){if(m.r32(i.cx)!=0u||i.arg[1]!=0u||i.arg[2]!=7u||i.arg[0]!=0x78ca70u)throw std::domain_error("1116 genuine coldoriginalBlowfishcontext7");const auto&iid=*reinterpret_cast<const GUID*>(0x7b95a0u);const auto&clsid=*reinterpret_cast<const GUID*>(std::uintptr_t(i.arg[0]));auto hr=a.create(clsid,nullptr,i.arg[2],iid,reinterpret_cast<void**>(&i.arg[1]));if(FAILED(hr))return unsigned(hr);auto*p=reinterpret_cast<IUnknown*>(std::uintptr_t(i.arg[1]));hr=a.run(p);if(SUCCEEDED(hr))hr=p->QueryInterface(iid,reinterpret_cast<void**>(std::uintptr_t(i.cx)));p->Release();return unsigned(hr);}
}
