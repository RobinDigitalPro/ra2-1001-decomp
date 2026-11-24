#include "recovered/recovery_b1634.hpp"
#include "platform/x87_state.hpp"
#include <stdexcept>
namespace ra2::recovered::b1634 {
namespace{void need(bool b,const char*s){if(!b)throw std::domain_error(s);}U ptr(HWND h){return U(reinterpret_cast<std::uintptr_t>(h));}}
U fun_0072bfc0(Memory&m,const Inputs&i,Api&a){
 namespace fp=ra2::platform::x87;const auto host=fp::capture_host();
 try{
  need(a.main_window&&a.invalidate&&m.r32(0xb0de50)==ptr(a.main_window),"1634 actual owned main HWND binding");
  need(m.r32(0x819780)==0&&m.r32(0xae0a68)==0&&m.r32(0x821fa8)==0&&m.r32(0x821cac)==0&&m.r32(0xb0d84c)==0,"1634 authentic inactive provider/counter/dialog finite scope");
  need(m.r8(0x839fe0)==1&&m.r8(0xb0de60)<=1&&m.r32(0x81a82c)<=2,"1634 explicit runtime flag and finite Map mode");
  fp::restore_host(i.fp.image);
  // 4068F0 is literal RET. 406F70 cold counter0 returns without A870.
  // 821FA8 NULL and explicit839FE0=1 exclude every surface dispatch.
  // Real E0030(Map,2): equality skips ONLY the mode store (4E004C->0051).
  if(m.r32(0x81a82c)!=2)m.w32(0x81a82c,2);
  // 4E0056 calls actual call-free157AB0 for arg2 nonzero, even oldmode2.
  m.w8(0x81b974,m.r8(0x81b974)+1u);
  (void)a.invalidate(a.main_window,nullptr,FALSE);
  // 19D880 count0 returns; final72A6D0 reloads genuineB0D84C=0.
  const U eax=m.r32(0xb0d84c);i.fp.image=fp::capture_host();fp::restore_host(host);return eax;
 }catch(...){fp::restore_host(host);throw;}
}
}
