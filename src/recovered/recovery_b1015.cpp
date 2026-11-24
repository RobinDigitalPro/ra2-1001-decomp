#include "recovered/recovery_b1015.hpp"
#include "platform/registry_child1015.hpp"
#include <array>
namespace ra2::recovered::b1015 {
namespace reg=ra2::platform::registry_child1015;
namespace {unsigned fold(unsigned c){return c>=65u&&c<=90u?c+32u:c;}bool equal(Memory&m,unsigned query,Heap&h,unsigned name){for(unsigned j=0;j<256u;++j){const auto a=m.r8(query+j),b=h.r8(name+j);if(fold(a)!=fold(b))return false;if(!a)return true;}throw std::domain_error("1015 bounded ASCII key names");}}
std::uint32_t fun_00728d80(Memory&m,const Inputs&i,Heap&h){
 reg::need(m.r32(0xb10530u)==0u&&m.r32(0x817554u)==0u&&m.r32(0xb10e14u)==0u,"1015 actual C-locale/ordinary heap preconditions");auto parent=reinterpret_cast<HKEY>(std::uintptr_t(i.cx));std::array<char,1024>cls{};DWORD class_size=1024u,count=0u,maxname=0u,maxclass=0u,values=0u,maxvalue=0u,maxdata=0u,security=0u;FILETIME time{};
 reg::need(reg::Provider::info(parent,cls.data(),&class_size,nullptr,&count,&maxname,&maxclass,&values,&maxvalue,&maxdata,&security,&time)==ERROR_SUCCESS,"1015 positive actual QueryInfo");const auto capacity=maxname+16u;const auto name=h.allocate(capacity),class_buffer=h.allocate(maxclass+1u);reg::need(count>=3u&&count<=7u,"1015 several genuine siblingkeys");HKEY result=nullptr;for(DWORD index=0u;index<count;++index){DWORD length=capacity;h.w8(name,0u);reg::Provider::enumerate(parent,index,reinterpret_cast<char*>(std::uintptr_t(name)),&length,nullptr,reinterpret_cast<char*>(std::uintptr_t(class_buffer)),&maxclass,&time);if(equal(m,i.dx,h,name)){reg::need(reg::Provider::open(parent,reinterpret_cast<const char*>(std::uintptr_t(name)),0u,0x20019u,&result)==ERROR_SUCCESS&&result,"1015 positive actual matched Open");break;}}
 reg::need(result!=nullptr,"1015 positive selected child exists");if(i.arg[0]&255u)reg::need(reg::Provider::close(parent)==ERROR_SUCCESS,"1015 requested actual parent close");h.release(name);h.release(class_buffer);return std::uint32_t(reinterpret_cast<std::uintptr_t>(result));
}
}
