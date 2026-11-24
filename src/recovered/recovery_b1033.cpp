#include "recovered/recovery_b1033.hpp"
#include "platform/control_geometry1033.hpp"
namespace ra2::recovered::b1033 {
namespace {
HWND hwnd(unsigned n){return reinterpret_cast<HWND>(std::uintptr_t(n));}
unsigned profile(Memory&m,unsigned key){ui::need(m.r32(0xa5b1b8u)==0x5d6fc0u&&m.r32(0xa5b1acu)==7u&&m.r32(0xa5b1a8u)==128u&&m.r32(0xa5b1a4u)>0u,"1033 original prepared HWND hash/callback");unsigned node=m.r32(m.r32(0xa5b1a0u)+4u*(key&127u)),seen=0;while(node&&m.r32(node)!=key){ui::need(++seen<4u,"1033 positive bounded HWND chain");node=m.r32(node+0x204u);}ui::need(node,"1033 existing parent HWND record");return m.r32(node+0x70u);}
}
unsigned fun_005da760(Memory&m,const Inputs&i){const unsigned kind=profile(m,i.cx),id=unsigned(ui::control(hwnd(i.dx)));ui::need(kind==0x94u,"1033 positive original campaign tooltip profile");switch(id){case 0x6ea:return 0x7d4cb0u;case 0x6eb:return 0x7d4c94u;case 0x6ec:return 0x7d4c7cu;case 0x50f:return 0x7d4c5cu;case 0x40e:return 0x7d4c44u;case 0x455:return 0x7d4c30u;default:throw std::domain_error("1033 supported useful tooltip controls");}}
unsigned fun_005e1760(Memory&m,const Inputs&i){const auto child=hwnd(i.cx),parent=ui::parent(child);RECT p{},c{};ui::need(ui::rectangle(parent,&p)!=FALSE&&ui::rectangle(child,&c)!=FALSE,"1033 successful actual parent/child rectangles");const unsigned kind=profile(m,ui::address(parent)),id=unsigned(ui::control(child));int x=c.left-p.left,y=c.top-p.top,w=c.right-c.left,h=c.bottom-c.top;
 if(kind==0x94u&&id==0x694u){ui::need(m.r8(0xa27f64u)==0u,"1033 original269140 AL getter positive adjustment flag0");y+=7;++h;}
 else if(kind==0xbcu&&id==0x53fu)++w;
 else if((kind==0xbcu&&id==0x54fu)||(kind==0x102u&&id==0x50cu))--y;
 else{ui::need((kind==0xbcu||kind==0x102u)&&id==0x54eu,"1033 supported useful geometry branches");--x;}
 return unsigned(ui::move(child,x,y,w,h,FALSE));}
unsigned run(Memory&m,const Inputs&i,unsigned r){if(r==0x1da760u)return fun_005da760(m,i);ui::need(r==0x1e1760u,"1033 selected root");return fun_005e1760(m,i);}
}
