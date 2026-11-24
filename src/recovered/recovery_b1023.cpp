#include "recovered/recovery_b1023.hpp"
#include "platform/dialog1023.hpp"
namespace ra2::recovered::b1023 {
namespace {
HWND hwnd(unsigned n){return reinterpret_cast<HWND>(std::uintptr_t(n));}
void command_base(Memory&m,const Inputs&i){Inputs helper{};helper.cx=i.arg[0];helper.dx=i.arg[1];helper.arg[0]=i.arg[2];helper.arg[1]=i.arg[3];ui::need(helper.dx==0x111u&&fun_005f77c0(m,helper)==0u,"1023 proven original command default dependency");}
unsigned context(unsigned w){const auto p=unsigned(ui::user(hwnd(w),8));ui::need(p!=0u,"1023 live actual dialog context");return p;}
}
std::uint32_t fun_005f77c0(Memory&,const Inputs&i){if(i.dx==0x111u)return 0u;ui::need(i.dx>=0x132u&&i.dx<=0x138u,"1023 bounded original color messages");return ui::address(ui::stock(4));}
std::uint32_t fun_00539460(Memory&m,const Inputs&i){const unsigned p=context(i.cx);ui::need(i.arg[1]==0u&&(i.dx==0x686u||i.dx==0x6c7u),"1023 bounded positive command helper");m.w32(p+0x18u,i.dx==0x686u?2u:1u);return p;}
std::uint32_t fun_005395b0(Memory&m,const Inputs&i){command_base(m,i);const unsigned p=context(i.arg[0]);ui::need((i.arg[2]&0xffffu)==0x686u,"1023 bounded686 callback accepting any notification highword");m.w32(p+0x18u,2u);return 0u;}
std::uint32_t fun_00539710(Memory&m,const Inputs&i){command_base(m,i);Inputs child{};child.cx=i.arg[0];child.dx=i.arg[2]&0xffffu;child.arg[0]=i.arg[3];child.arg[1]=i.arg[2]>>16u;fun_00539460(m,child);return 0u;}
std::uint32_t fun_00539830(Memory&m,const Inputs&i){command_base(m,i);const unsigned p=context(i.arg[0]),id=i.arg[2]&0xffffu;ui::need((i.arg[2]>>16u)==0u&&(id==0x686u||id==0x6c8u),"1023 bounded686/6c8 zero-notify callback");m.w32(p+0x18u,id==0x686u?2u:1u);return 0u;}
std::uint32_t fun_005b14a0(Memory&m,const Inputs&i){command_base(m,i);const unsigned p=context(i.arg[0]),id=i.arg[2]&0xffffu;ui::need((i.arg[2]>>16u)==0u&&(id==1u||id==2u||id==0x5aeu||id==0x5afu),"1023 bounded four numeric commands");m.w32(p,id==0x5aeu?0u:id==0x5afu?2u:1u);return 0u;}
std::uint32_t fun_00632810(Memory&m,const Inputs&i){command_base(m,i);const unsigned id=unsigned(ui::control(hwnd(i.arg[3])));ui::need(id==0x423u&&(i.arg[2]>>16u)==0u,"1023 actual controlID423 and zero notification");const unsigned p=context(i.arg[0]);m.w32(p,id);return 0u;}
unsigned run(Memory&m,const Inputs&i,unsigned r){switch(r){case 0x1f77c0:return fun_005f77c0(m,i);case 0x139460:return fun_00539460(m,i);case 0x1395b0:return fun_005395b0(m,i);case 0x139710:return fun_00539710(m,i);case 0x139830:return fun_00539830(m,i);case 0x1b14a0:return fun_005b14a0(m,i);case 0x232810:return fun_00632810(m,i);default:throw std::domain_error("1023 selected root");}}
}
