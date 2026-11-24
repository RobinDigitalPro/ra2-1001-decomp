#include "recovered/recovery_b1048.hpp"
#include <stdexcept>
namespace ra2::recovered::b1048 {
static void require(bool c){if(!c)throw std::domain_error("B1048 outside reviewed positive contract");}
std::uint32_t fun_0052f900(Memory&m,const Inputs&i,Heap&h){
 const auto entity=i.arg[0],target=i.arg[1],r=i.cx;require(m.r8(m.r32(entity+0x5acu)+0xb18u)!=0u&&target!=0u);
 const auto p=h.allocate(8u);require(p!=0u);h.w32(p,entity);
 // Genuine +48 getter copies XYZ; signed division truncates toward zero.
 require(m.r32(target)==0x78612cu);const auto x=std::uint32_t(global_b26::s32(m.r32(target+0x88u))/256),y=std::uint32_t(global_b26::s32(m.r32(target+0x8cu))/256);
 const auto packed=(x&65535u)|(y<<16u);i.arg[0]=i.arg[1]=packed;
 require(x<512u&&y<512u);const auto cell=m.r32(m.r32(0x81a958u)+4u*(y*512u+x));require(cell!=0u);h.w32(p+4u,cell);
 m.w8(entity+0x5b2u,1u);m.w32(entity+0x254u,1u);const auto count=m.r32(r+0x1cu);require(count<m.r32(r+0x14u));m.w32(r+0x1cu,count+1u);m.w32(m.r32(r+0x10u)+4u*count,p);return count;
}
std::uint32_t fun_0052fae0(Memory&m,const Inputs&i,Heap&h){
 const auto r=i.cx,n=m.r32(r+0x1cu),array=m.r32(r+0x10u);require(n>0u);for(unsigned index=n;index--!=0u;){const auto p=m.r32(array+4u*index);if(h.r32(p)==i.arg[0]){h.release(p);m.w32(r+0x1cu,n-1u);for(unsigned k=index+1u;k<n;++k)m.w32(array+4u*(k-1u),m.r32(array+4u*k));return n-1u;}require(h.r32(p+4u)!=i.arg[0]);}throw std::domain_error("B1048 first-component positive match required");
}
std::uint32_t fun_0067f180(Memory&m,const Inputs&i,Heap&h){
 const auto r=i.cx,v=r+0x38u;require(m.r8(0xa285a8u)==0u&&m.r32(v)==0x7967d4u);
 constexpr unsigned d[]{0x796770u,0x796754u,0x79674cu,0x796744u};for(unsigned k=0;k<4u;++k)m.w32(r+4u*k,d[k]);
 const auto count=m.r32(v+16u),old=m.r32(v+4u),cap=m.r32(v+8u);require(count>0u&&cap>=count&&m.r8(v+13u)==1u);
 for(unsigned k=count;k--!=0u;){const auto p=h.r32(old+4u*k);if(p)h.release(p);}
 m.w32(v+16u,0u);h.release(old);m.w32(v+4u,0u);m.w8(v+13u,0u);m.w32(v+8u,0u);
 // Original virtual Clear then SetCapacity(oldcap,0) really allocates again.
 m.w8(v+12u,0u);const auto fresh=h.allocate(4u*cap);m.w8(v+12u,1u);require(fresh!=0u);m.w32(v+4u,fresh);m.w32(v+8u,cap);m.w8(v+13u,1u);
 const auto data=m.r32(0xaa4b34u),n=m.r32(0xaa4b40u);unsigned index=n;for(unsigned k=0;k<n;++k)if(m.r32(data+4u*k)==r){index=k;break;}require(index<n);m.w32(0xaa4b40u,n-1u);for(unsigned k=index+1u;k<n;++k)m.w32(data+4u*(k-1u),m.r32(data+4u*k));
 m.w32(v,0x7967f4u);const auto eax=h.release(fresh);m.w32(v+4u,0u);m.w8(v+13u,0u);m.w32(v+8u,0u);constexpr unsigned base[]{0x785dd8u,0x785dbcu,0x785db4u,0x785dacu};for(unsigned k=0;k<4u;++k)m.w32(r+4u*k,base[k]);return eax;
}
std::uint32_t fun_006b72a0(Memory&m,const Inputs&i,State&fp){
 const auto r=i.cx,type=m.r32(r+0x5acu),house=m.r32(r+0x1b4u);require(m.r32(r)==0x78612cu&&type!=0u&&house!=0u);m.w8(r+0x372u,house==m.r32(0xa1e0e4u)?1u:0u);
 require(m.r32(type+0x540u)==0u&&m.r32(type+0xb08u)==0u&&m.r32(type+0x74cu)==0u&&m.r8(type+0xaf7u)==0u&&m.r32(r+0x118u)==0u&&m.r32(r+0x11cu)==0u);
 // Actual GetWeapon is invoked three times, each through original +39C.
 const auto two=std::uint64_t(m.r32(0x7856f8u))|(std::uint64_t(m.r32(0x7856fcu))<<32u);for(unsigned k=0;k<3u;++k){fp.load64(0ull);fp.compare_pop64(two);}
 for(unsigned k=0;k<4u;++k){m.w32(r+0x330u+4u*k,m.r32(type+0xab0u+4u*k));m.w32(r+0x350u+4u*k,m.r32(type+0xac4u+4u*k));}m.w32(r+0x3ecu,1u);m.w32(r+0x3f0u,0u);return type+0xac4u;
}
std::uint32_t run(Memory&m,const Inputs&i,Heap&h,State&f,unsigned r){switch(r){case 0x12f900u:return fun_0052f900(m,i,h);case 0x12fae0u:return fun_0052fae0(m,i,h);case 0x27f180u:return fun_0067f180(m,i,h);case 0x2b72a0u:return fun_006b72a0(m,i,f);default:throw std::domain_error("B1048 root");}}
}
