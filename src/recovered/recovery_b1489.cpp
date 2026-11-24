#include "recovered/recovery_b1489.hpp"
#include "platform/observed_registry1489.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1489 {
unsigned fun_00736830(Memory&m,const Inputs&){
 if(m.r32(0xa5a874)||m.r32(0xa5a878)||m.r32(0xb10104))throw std::domain_error("1489 exact cold PE used-field scope");
 std::array<char,256> path{};unsigned k=0;do{if(k==path.size())throw std::domain_error("1489 bounded original path");path[k]=char(m.r8(0x7d0ed4+k));}while(path[k++]);
 std::array<char,4> key{};for(k=0;k<key.size();++k)key[k]=char(m.r8(0x7e7130+k));if(key[3])throw std::domain_error("1489 actual SKU terminator");
 using O=ra2::platform::registry1489::Observer;DWORD value=0,type=0,size=4;HKEY handle{};
 const auto status=O::open(HKEY_LOCAL_MACHINE,path.data(),0,0x20019,&handle);
 if(status==ERROR_SUCCESS){O::query(handle,key.data(),nullptr,&type,reinterpret_cast<BYTE*>(&value),&size);O::close(handle);}
 m.w32(0xb10104,value&255u);
 // Both independently null-checked original optional interfaces retain PE NULL.
 // Final EAX was loaded from the second NULL pointer before XOR AL,AL.
 return 0;
}
}
