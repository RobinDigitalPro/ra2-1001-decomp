#include "recovery_b778.hpp"
#include "recovered/name_hash.hpp"
#include "recovered/text_trim.hpp"
#include "platform/ini_guid778_api.hpp"
namespace ra2::recovered::recovery_b778 {
namespace {using U=std::uint32_t;std::string z(Memory&m,U a){std::string s;for(unsigned n=0;n<128;++n){auto c=m.r8(a+n);if(!c)return s;s+=char(c);}throw std::domain_error("778 bounded text missingNUL");}
U row(Memory&m,U index,const std::string&name){auto p=m.r32(index);auto h=ini_name_hash(reinterpret_cast<const std::uint8_t*>(name.data()),name.size(),nullptr);if(!p||m.r32(index+4)!=1||m.r8(index+12)!=1||m.r32(index+16)!=p||m.r32(p)!=h)throw std::domain_error("778 one warm existing INI row required");return m.r32(p+4);}}
std::uint32_t fun_0050ce50(Memory&m,const Inputs&i){auto section=row(m,i.cx+0x20,z(m,i.arg[1]));auto value=row(m,section+0x2c,z(m,i.arg[2]));auto raw=z(m,m.r32(value+0x10));std::array<std::uint8_t,128> local{};for(unsigned k=0;k<raw.size();++k)local[k]=static_cast<std::uint8_t>(raw[k]);local[127]=0;fun_006e41d0(local.data());std::array<wchar_t,128> wide{};GUID id{};
 // Original50CFDF/50CFF2 retain real Windows conversion boundaries.
 ra2::platform::ini_guid778::convert(0,1,reinterpret_cast<const char*>(local.data()),-1,wide.data(),128);ra2::platform::ini_guid778::parse(wide.data(),&id);
 const auto*b=reinterpret_cast<const unsigned char*>(&id);for(unsigned k=0;k<16;++k)m.w8(i.arg[0]+k,b[k]);return i.arg[0];}
}
