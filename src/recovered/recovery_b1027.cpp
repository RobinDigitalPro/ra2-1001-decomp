#include "recovered/recovery_b1027.hpp"
#include "platform/control_class1027.hpp"
namespace ra2::recovered::b1027 {
namespace {
unsigned profile(Memory&m,unsigned hwnd){
 ui::need(m.r32(0xa5b1b8u)==0x5d6fc0u&&m.r32(0xa5b1acu)==7u&&m.r32(0xa5b1a8u)==128u&&m.r32(0xa5b1a4u)>=1u&&m.r32(0xa5b1a4u)<=4u,"1027 original identity callback/valid128-bucket prepared hash");
 // Original5D6FC0 returns the DWORD key passed by address; SHL1,CL/DEC
 // creates127 for the scoped genuine table shift7. No callback replacement.
 unsigned p=m.r32(m.r32(0xa5b1a0u)+(hwnd&127u)*4u);
 for(unsigned n=0;n<4u&&p;++n){if(m.r32(p)==hwnd)return m.r32(p+0x70u);p=m.r32(p+0x204u);}
 throw std::domain_error("1027 positive existing numeric HWND record required");
}
struct Query{unsigned profile,id;};
Query query(Memory&m,const Inputs&i){const unsigned p=profile(m,i.cx),id=unsigned(ui::control_id(reinterpret_cast<HWND>(std::uintptr_t(i.dx))));ui::need((p==0x94u&&id==0x694u)||(p==0xbcu&&id==0x6ecu)||(p==0x103u&&id==0x6f4u)||(p==0xbc7u&&id==0x411u)||(p==0x108u&&id==0x6d2u)||(p==0xbc6u&&id==0x419u),"1027 bounded six useful positive profile/control pairs");return {p,id};}
}
std::uint32_t fun_005d7600(Memory&m,const Inputs&i){const auto q=query(m,i);if(q.profile==0x103u)return 15u;if(q.profile==0xbc7u||q.profile==0xbc6u)return 60u;return 30u;}
std::uint32_t fun_005d7f20(Memory&m,const Inputs&i){const auto q=query(m,i);return q.profile==0x103u?3u:1u;}
std::uint32_t fun_005d8640(Memory&m,const Inputs&i){const auto q=query(m,i);if(q.profile==0x103u)return 16u;if(q.profile==0xbc7u||q.profile==0x108u)return 32u;if(q.profile==0xbc6u)return 64u;return 8u;}
std::uint32_t fun_005d8d80(Memory&m,const Inputs&i){const auto q=query(m,i);return(q.id&0xffffff00u)|1u;}
std::uint32_t run(Memory&m,const Inputs&i,unsigned r){switch(r){case 0x1d7600:return fun_005d7600(m,i);case 0x1d7f20:return fun_005d7f20(m,i);case 0x1d8640:return fun_005d8640(m,i);case 0x1d8d80:return fun_005d8d80(m,i);default:throw std::domain_error("1027 selected root");}}
}
