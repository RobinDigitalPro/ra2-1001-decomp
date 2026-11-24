#pragma once
#define NOMINMAX
#include <windows.h>
#include "recovered/recovery_b433.hpp"
#include <array>
#include <algorithm>
#include <cstdint>
#include <initializer_list>
#include <vector>
namespace keyboard433_test {
struct Event{std::uint32_t api{},count{},result{};std::array<std::uint32_t,5>args{};};
struct Ops {
 ra2::recovered::keyboard433::Memory* memory{};std::vector<Event>events;
 static void add(void*x,std::uint32_t api,std::initializer_list<std::uint32_t>a,std::uint32_t r){auto&e=static_cast<Ops*>(x)->events.emplace_back();e.api=api;e.count=std::uint32_t(a.size());std::copy(a.begin(),a.end(),e.args.begin());e.result=r;}
 static std::uint32_t map(void*x,std::uint32_t vk,std::uint32_t type){const auto r=::MapVirtualKeyA(vk,type);add(x,0x7853d8u,{vk,type},r);return r;}
 static std::int32_t ascii(void*x,std::uint32_t vk,std::uint32_t scan,std::uint32_t kp,std::uint32_t out,std::uint32_t flags){auto&m=*static_cast<Ops*>(x)->memory;std::array<BYTE,256>key{};for(unsigned i=0;i<key.size();++i)key[i]=BYTE(m.r8(kp+i));WORD result=WORD(m.r16(out));const auto r=::ToAscii(vk,scan,key.data(),&result,flags);m.w16(out,result);add(x,0x7853a0u,{vk,scan,kp,0xf0000000u,flags},std::uint32_t(r));return r;}
 ra2::recovered::keyboard433::Ops bind(){return {this,map,ascii};}
};
}
