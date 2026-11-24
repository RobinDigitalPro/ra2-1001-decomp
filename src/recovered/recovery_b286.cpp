#include "recovery_b286.hpp"
namespace ra2::recovered::recovery_b286 {
std::uint32_t fun_004637f0(Memory&m,const Inputs&i){
 const auto count=m.r32(0x838650),capacity=m.r32(0x838648),array=m.r32(0x838644);
 if(count>=64||capacity!=64||!array||!i.cx)throw std::domain_error("286 finite preallocated insertion domain");
 m.w32(0x838650,count+1);m.w32(array+4*count,i.cx);
 const auto excess=count+1>5?count+1-5:0;
 const auto high=global_b26::imul_high(0x55555556,excess);
 const auto third=high+(high>>31);
 const auto descriptor=m.r32(i.cx+0x98);
 const auto value=m.r32(descriptor+0x2b4)+third;
 // Actual leaf64d80 receives this value as arg0, stores +2b8, returns it RET4.
 m.w32(descriptor+0x2b8,value);return value;
}}
