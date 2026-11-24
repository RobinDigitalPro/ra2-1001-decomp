#include "recovered/recovery_b858.hpp"
#include "recovered/text_bytes.hpp"
#include <stdexcept>
#include <array>
namespace ra2::recovered::recovery_b858 {
std::uint32_t fun_0070a290(Memory&m,const Inputs&){using U=std::uint32_t;U s=m.r32(0xab83dc);if(!s||!m.r32(s+0x14))throw std::domain_error("858 existinginitializedstream");m.w32(0xab82f8,0);m.w32(0xab8348,0);for(U h:{0xab8360,0xab836c,0xab8378,0xab8384,0xab8310,0xab82e8})for(U k=0;k<3;++k)m.w32(h+4*k,h);m.w32(0xab83c8,0);m.w32(0xab83cc,1);
 std::array<std::uint8_t,80>d{},text{};for(U k=0;k<80;++k)text[k]=m.r8(0x7e34a4+k);ra2::recovered::fun_0076dd10(d.data(),text.data(),80);for(U k=0;k<80;++k)m.w8(s+0xa4+k,d[k]);m.w8(s+0xf3,0);U backend=m.r32(s+0x14);m.w32(backend+0x94,m.r32(0x819790));m.w32(backend+0x9c,m.r32(0x8197a0));return 1;}
}
