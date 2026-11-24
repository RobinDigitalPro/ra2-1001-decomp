#include "recovery_b752.hpp"
#include "platform/observed_classes752.hpp"
namespace ra2::recovered::recovery_b752 {
unsigned fun_005e2f10(Memory&m,const Inputs&){
 if(m.r32(0xa5df44)==1)return 1;m.w32(0xa5df44,1);
 auto name=[&](unsigned a){std::string s;for(unsigned k=0;k<128;++k){char c=char(m.r8(a+k));if(!c)return s;s+=c;}throw std::domain_error("752 unterminated class name");};
 std::array<std::string,2>names{name(0x7d4dcc),name(0x7d2f50)};unsigned result=0;
 for(unsigned k=0;k<2;++k){WNDCLASSA c{};c.style=k?0x83:3;c.lpfnWndProc=reinterpret_cast<WNDPROC>(std::uintptr_t(k?0x5e2fe0:0x5e3000));c.hInstance=reinterpret_cast<HINSTANCE>(std::uintptr_t(m.r32(0xb0dbf8)));c.lpszClassName=names[k].c_str();c.lpszMenuName=k?nullptr:names[0].c_str();result=ra2::platform::classes752::Classes::register_class(&c);}return result;
}}
