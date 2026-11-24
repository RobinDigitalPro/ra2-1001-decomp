#include "recovery_b1331.hpp"
#include <stdexcept>
namespace ra2::recovered::b1331 {
namespace {void need(bool b,const char*s){if(!b)throw std::domain_error(s);}}
std::uint32_t fun_0049dd30(Memory&m,const Inputs&i){
 (void)i;
 need(m.r32(0xa28870u)==1u,"1331 one real registry entry");
 const auto actor=m.r32(m.r32(0xa28864u));
 need(actor&&m.r8(actor+0x76u)==0u,"1331 active actor");
 const auto v=m.r32(actor);
 need(v==0x78612cu&&m.r32(v+0x2cu)==0x41b580u,"1331 actual kind2 getter");
 const auto owner=m.r32(actor+0x1b4u);
 need(m.r32(0xa255c8u)==0u&&m.r8(owner+0x134u)!=0u,"1331 actual4F47B0 owner result1");
 need(m.r8(actor+0x373u)!=0u,"1331 positive callback dispatch");
 need(m.r32(v+0x41cu)==0x6cb400u,"1331 authentic clear callback");
 // Actual6CB400 four-zero-argument leg: no surface update or heap call.
 need(m.r8(actor+0x32du)!=0u&&m.r8(m.r32(owner+0x34u)+0x1a6u)==0u,"1331 reached owner/type gate");
 need(m.r8(actor+0x1e4u)!=0u&&m.r32(actor+0x1f4u)==0u,"1331 positive finite clear");
 m.w8(actor+0x1e4u,0u);
 need(m.r32(v+0x80u)==0x6b6910u&&m.r32(v+0x84u)==0x41b600u,"1331 actual chained type getter");
 const auto type=m.r32(actor+0x5acu);
 need(type&&m.r8(type+0xaddu)==0u,"1331 no additional type callback");
 return type;
}
}
