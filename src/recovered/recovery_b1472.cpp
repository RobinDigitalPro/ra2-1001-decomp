#include "recovered/recovery_b1472.hpp"
namespace ra2::recovered::b1472 {
unsigned fun_0061eb70(Memory&m,const Inputs&i,Heap&heap){
 using U=std::uint32_t;auto*w=ui::active;ui::need(w&&w->has_dialog(),"1472 genuine dialog fixture active");
 ui::need(i.arg[0]==ui::ptr(w->parent())&&i.arg[1]==0x111u&&i.arg[2]==0x640u&&i.arg[3]==ui::ptr(w->command_button()),"1472 finite WndProc HWND/WM_COMMAND/LOWORD 0x640/BUTTON lParam input");
 ui::need(m.r32(0x78548c)==ui::addr(&ui::getwindow),"1472 exact GetWindowLongA import observer binding");
 // Original calls GetWindowLongA(parent,8); its return is unused in this
 // selected WM_COMMAND branch. The observer forwards actual result/LastError.
 (void)ui::getwindow(w->parent(),8);
 Inputs child=i;child.cx=i.arg[0];child.dx=0;const U result=ra2::recovered::b1469::fun_0061e840(m,child,heap);
 ui::need(result==0,"1472 accepted B1469 positive child result");i.fp.image=child.fp.image;
 // Original XOR EAX,EAX after the child and RET 16.
 return 0;
}
}
