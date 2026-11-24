#include "recovery_b1499.hpp"
#include <cstring>
#include <stdexcept>
namespace ra2::recovered::b1499 {
U fun_0078131b(Memory&m,const Inputs&i,DispatchAPI&os){
 // Exact successful one-I4 argument / BOOL result specialization. All private
 // input VARIANT and EXCEPINFO bytes have original explicit zero producers.
 if(!i.arg[0]||i.arg[2]!=2||i.arg[3]!=11||m.r16(i.arg[5])!=3||m.r16(i.arg[5]+2)!=0)throw std::invalid_argument("1499 finite nonempty dispatch contract");
 m.w32(i.arg[7],0);
 if(os.length(reinterpret_cast<const std::uint16_t*>(std::uintptr_t(i.arg[5])))!=1)throw std::runtime_error("1499 actual one argument");
 Variant argument{};argument.bytes[0]=3;const U value=m.r32(i.arg[6]);std::memcpy(argument.bytes.data()+8,&value,4);
 Params params{&argument,nullptr,1,0};
 Variant result; // No seed: actual VariantInit is the result-buffer producer.
 os.initialize(result);
 Exception exception{};U bad_argument=0xffffffffu;
 for(U k=0;k<4;++k)if(m.r32(0xb10830+4*k))throw std::invalid_argument("1499 original IID_NULL projection");
 const U hr=os.invoke(i.arg[0],i.arg[1],i.arg[2],params,result,exception,bad_argument);
 std::uint16_t vt,out;std::memcpy(&vt,result.bytes.data(),2);std::memcpy(&out,result.bytes.data()+8,2);
 if(std::int32_t(hr)<0||vt!=11)throw std::runtime_error("1499 excludes failed/converting Invoke");
 m.w16(i.arg[4],out);
 i.fp.image=platform::x87::capture_host();return hr;
}
}
