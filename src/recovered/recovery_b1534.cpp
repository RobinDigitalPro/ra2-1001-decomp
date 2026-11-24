#include "recovered/recovery_b1534.hpp"
#include <stdexcept>
namespace ra2::recovered::b1534 {
std::uint32_t fun_00656fd0(Memory&m,const Inputs&i,Heap&h){
 const auto scenario=m.r32(0xa255c0u),coordinate=m.r32(scenario+0x632u);
 if((i.dx&255u)!=1u||!coordinate||m.r32(scenario+0x636u)||m.r32(0xa9e990u)||m.r32(0xa25604u)||m.r32(0xa27db8u)||m.r32(0x7875a8u)!=0x42d050u||m.r32(0x7875ecu)!=0x42cfb0u)throw std::domain_error("1534 requires frozen onecoordinate authenticvector domain");
 // Actual42D4A0(0,0) constructs private empty vector; root sets derived
 // vptr/count0/growth10. Actual42D050(10,0) allocates fullcapacity40.
 const auto temporary=h.allocate(40u);h.w32(temporary,coordinate);
 // Root constructs borrowedreceiver's baseheader, preserving E/F padding.
 const auto receiver=i.cx;m.w32(receiver+4,0);m.w32(receiver+8,0);m.w8(receiver+0xc,1);m.w8(receiver+0xd,0);m.w32(receiver,0x7875e0u);
 // Actual65A540: empty42CFB0 reset, capacity10, full40-byte copy.
 m.w8(receiver+0xd,0);m.w32(receiver+8,0);m.w32(receiver+8,10);
 const auto final=h.allocate(40u);m.w32(receiver+4,final);m.w8(receiver+0xd,1);
 for(std::uint32_t k=0;k<10;++k)h.w32(final+4*k,h.r32(temporary+4*k));
 m.w32(receiver,0x7875a0u);m.w32(receiver+0x10,1);m.w32(receiver+0x14,10);
 // Genuine privatevector teardown frees only temporaryallocation0.
 h.release(temporary);return receiver;
}
}
