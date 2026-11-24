#include "recovered/recovery_b1417.hpp"
#include "platform/custom_combo1430.hpp"
#include "platform/x87_state.hpp"
namespace ra2::recovered::b1417 {
using U=std::uint32_t;namespace ui=b1430::ui;namespace fp=ra2::platform::x87;
unsigned fun_004d1bb0(Memory&m,const Inputs&i,Heap&heap){
 auto&c=ui::context();ui::need(&c.memory()==&m&&&c.heap()==&heap&&i.cx==ui::ptr(c.parent())&&i.dx==0x6a2&&i.arg[0]<8,"1417 positive owner0 finite request");
 const auto host=fp::capture_host();fp::restore_host(i.fp.image);
 try{
  const HWND child=ui::get(c.parent(),int(i.dx));const U hidden=U(ui::show(child,0))==0;
  ui::need(hidden,"1417 actual declared hidden entry");
  for(U color=0;color<8;++color)if(m.r32(0x84e410+12*color)==0){m.w32(0x84e410+12*color,0xffffffffu);break;}
  const U count=U(ui::send_dialog(c.parent(),int(i.dx),0x146,0,0));ui::need(count==9,"1417 genuine producer nine owned rows");
  bool found=false;
  for(U row=0;row<count;++row){const U value=U(ui::send_dialog(c.parent(),int(i.dx),0x150,row,0));if(value!=i.arg[0])continue;
   (void)ui::send_dialog(c.parent(),int(i.dx),0x14e,row,0);m.w32(0x84e410+12*value,0);found=true;break;
  }
  ui::need(found,"1417 real nonnegative requested itemdata match");
  i.fp.image=fp::capture_host();fp::restore_host(host);
  U result=0;for(U role=0;role<8;++role){Inputs child_input=i;child_input.dx=ui::ids[role];result=b1430::fun_004d18c0(m,child_input,heap);i.fp.image=child_input.fp.image;}
  return result;
 }catch(...){fp::restore_host(host);throw;}
}
}
