#include "recovered/recovery_b1026.hpp"
#include <stdexcept>
namespace ra2::recovered::b1026 {
unsigned fun_00779f6f(Memory&m,Inputs&i,Api&a){
 if(m.r32(0xb104c0u)!=1u)throw std::domain_error("1026 selected actual STDERR route");
 unsigned message=0u;
 for(unsigned k=0;k<18u;++k)if(m.r32(0x817bd0u+8u*k)==i.arg[0]){message=m.r32(0x817bd4u+8u*k);break;}
 if(!message)throw std::domain_error("1026 known original diagnostic code");
 unsigned length=0;while(length<512u&&m.r8(message+length))++length;
 if(!length||length>=512u)throw std::domain_error("1026 bounded nonempty original diagnostic");
 const auto handle=a.standard(STD_ERROR_HANDLE);
 DWORD written=0;const auto result=a.write(handle,reinterpret_cast<LPCVOID>(std::uintptr_t(message)),length,&written,nullptr);
 i.arg[0]=written;
 return unsigned(result);
}
}
