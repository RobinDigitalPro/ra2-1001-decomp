#include "recovered/recovery_b161.hpp"
#include <array>
#include <cstdint>
#include <stdexcept>
#include <vector>
namespace ra2::recovered::recovery_b161 {
std::uint32_t fun_0054f040(Memory&m,const Inputs&i){
 const auto coord=i.arg[0],direction=i.arg[1]&7u;
 const auto dx=std::uint16_t(m.r16(0x00839da0u+direction*4u)+m.r16(coord));
 const auto dy=std::uint16_t(m.r16(0x00839da2u+direction*4u)+m.r16(coord+2u));
 const auto packed=std::uint32_t(dx)|(std::uint32_t(dy)<<16);i.arg[1]=packed;
 const auto index=std::int32_t(static_cast<std::int16_t>(dy))*512+static_cast<std::int16_t>(dx);
 if(index<0||index>=0x40000)throw std::domain_error("161 in-bounds map-cell route required");
 const auto table=m.r32(0x0081a958u),tile=m.r32(table+std::uint32_t(index)*4u);
 if(!tile)throw std::domain_error("161 populated map-table entry required");
 if(m.r8(tile+0x140u)&0x80u){const auto k=m.r8(tile+0x11eu);if(k>=9u&&k<=12u)m.w8(tile+0x11eu,14u);else if(k==13u)m.w8(tile+0x11eu,15u);}
 const auto result=m.r32(tile+0x38u)-m.r32(0x00a547a0u)+1u;
 if(result==m.r32(0x00a55c48u)||result==m.r32(0x00a3afc8u)||result==m.r32(0x00a3aab0u)||result==m.r32(0x00a3aab0u)+2u)
  throw std::domain_error("161 fixture must avoid transition helper branches");
 return result;
}
}
