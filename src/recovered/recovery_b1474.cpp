#include "recovered/recovery_b1474.hpp"
#include "recovered/recovery_b107.hpp"
#include <stdexcept>
namespace ra2::recovered::global_b26 {std::uint32_t fun_0072a500(Memory&,const Inputs&);}
namespace ra2::recovered::b1474 {
namespace {using U=std::uint32_t;namespace fp=ra2::platform::x87;void need(bool x,const char*s){if(!x)throw std::domain_error(s);}}
std::uint32_t configure_crt(Memory&m,const Inputs&i){if(i.arg[0]>1016u)return 0u;m.w32(0x817554u,i.arg[0]);return 1u;}
std::uint32_t fun_005beaf0(Memory&m,const Inputs&i,Heap&heap){
 need(m.r32(0x817554u)==0u&&m.r32(0xb10e14u)==0u,"1474 produced ordinary CRT configuration");
 need(m.r8(i.cx)=='K'&&m.r8(i.cx+1u)=='1'&&m.r8(i.cx+2u)==0u&&i.dx!=0u,"1474 actual finite nonempty K1 command");
 need(m.r32(0xa27db8u)==1u&&m.r32(0xb10530u)==0u,"1474 one genuine peer/mode0");
 const auto host=fp::capture_host();fp::restore_host(i.fp.image);
 try {
  //779146: strlen2, malloc3, shared779010/779081 strcpy including NUL.
  const U owner=heap.allocate(3u);need(owner!=0u,"1474 actual successful command owner");
  for(U k=0;k<3u;++k)heap.w8(owner+k,m.r8(i.cx+k));
  Inputs query{};query.cx=0xc2u;const U hwnd=global_b26::fun_0072a500(m,query);need(hwnd!=0u,"1474 real existing C2 registry route");
  need(heap.r8(owner+1u)=='1',"1474 original command selector");
  Inputs child{};child.cx=i.dx;child.dx=1u;
  (void)recovery_b107::fun_005bea40(m,child);
  const U freed=heap.release(owner);need(freed!=0u,"1474 genuine command HeapFree success");
  i.fp.image=fp::capture_host();fp::restore_host(host);return freed&0xffffff00u;
 }catch(...){fp::restore_host(host);throw;}
}
}
