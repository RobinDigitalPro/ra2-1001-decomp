#include "recovered/recovery_b965.hpp"
#include "recovered/recovery_b946.hpp"
#include "platform/observed_mutex149.hpp"
#include "platform/observed_cursor965.hpp"
namespace ra2::recovered::recovery_b965 {
std::uint32_t fun_0075d360(Memory&m,const Inputs&i){auto r=i.cx;m.w32(r,0x79aa50);for(unsigned o:{4u,8u,0x14u,0x18u,0x1cu,0x20u,0x3cu,0x40u,0x44u,0x58u,0x6cu,0x94u})m.w32(r+o,0);m.w32(r+0xc,0xffffffff);m.w8(r+0x10,0);m.w32(r+0x24,i.arg[0]);m.w32(r+0x28,i.arg[1]);for(unsigned o:{0x2cu,0x48u,0x5cu,0x70u,0x80u})for(unsigned k=0;k<16;k+=4)m.w32(r+o+k,m.r32(0xb103b8+k));m.w32(r+0x90,0xffffffff);m.w32(r,0x79aa04);
auto h=reinterpret_cast<HANDLE>(std::uintptr_t(m.r32(0xb103f8)));if(ra2::platform::mutex149::Mutex::wait(h,10000)!=WAIT_OBJECT_0)throw std::domain_error("965 freshmutex");ra2::recovered::b946::fun_0075d590(m,i);m.w32(r+0x3c,m.r32(r+0x2c)+std::uint32_t(global_b26::s32(m.r32(r+0x34))/2));m.w32(r+0x40,m.r32(r+0x30)+std::uint32_t(global_b26::s32(m.r32(r+0x38))/2));m.w32(0xb103f4,r);ra2::platform::mutex149::Mutex::release(h);ra2::platform::cursor965::show(FALSE);return r;}
}
