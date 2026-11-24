#include "recovered/recovery_b1641.hpp"
#include "platform/x87_state.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1641 {
namespace {
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
U ptr(HWND h){return U(reinterpret_cast<std::uintptr_t>(h));}
// Same call-free clamp recipe as leaf_b56_b.cpp, on the caller's existing
// aggregate numeric address space. No old leaf contract or source is changed.
U clamp(Memory&m,U c){
 constexpr std::array<U,15>off{0x40,0x3c,0x48,0x44,0x4c,0x50,0x54,0x58,0x5c,0x60,0x64,0x68,0x6c,0x70,0x74};
 constexpr std::array<U,15>lo{0,0,0,0,0,2,1,0,0,0,0,0,0,0,0};
 constexpr std::array<U,15>hi{3,4,3,100,100,8,100,100,100,100,3,3,100,100,0xffff};
 U eax=0;for(U k=0;k<off.size();++k){const U a=c+off[k],v=m.r32(a);eax=v;if(leaf::s32(v)<leaf::s32(lo[k]))m.w32(a,lo[k]);else if(leaf::s32(v)>leaf::s32(hi[k]))m.w32(a,hi[k]);}return eax;
}
}
U fun_00575210(Memory&m,const Inputs&i,Api&a){
 namespace fp=ra2::platform::x87;const auto host=fp::capture_host();
 try{
  need(a.parent&&a.get_dlg_item&&a.send_message_a&&i.cx&&i.arg[0]==ptr(a.parent),"1641 borrowed numeric record and actual parent caller word");
  need(m.r8(0xa57c80)==0,"1641 initial unchanged-selection flag zero");
  const U c=i.cx;constexpr std::array<U,5>ids{0x405,0x407,0x408,0x3ea,0x406},offs{0x3c,0x38,0x40,0x48,0x64};
  fp::restore_host(i.fp.image);
  for(U k=0;k<5;++k){
   const U old=m.r32(c+offs[k]);HWND h=a.get_dlg_item(a.parent,int(ids[k]));need(h,"1641 genuine owned ComboBox");
   // PUSH argument preparation writes [preCALLRoot S], the root's arg0.
   i.arg[0]=ptr(h);
   const auto selection=a.send_message_a(h,0x147,0,0);need(selection>=0&&selection<=1,"1641 actual finite ComboBox selection");
   const U value=U(a.send_message_a(h,0x150,WPARAM(selection),0));m.w32(c+offs[k],value);
   if(k==4)m.w32(c+0x68,value);
   need(value==old&&value<=(k==0?4u:3u),"1641 real item data matches unchanged field; RNG branch excluded");
  }
  const U old_position=m.r32(c+0x50);
  // 575373 MOV [ESP+20],ECX overwrites caller arg0 before GetDlgItem.
  i.arg[0]=old_position;
  HWND h=a.get_dlg_item(a.parent,0x3eb);need(h,"1641 genuine owned trackbar");
  const U position=U(a.send_message_a(h,0x400,0,0));m.w32(c+0x50,position);
  need(position>=2&&position<=8&&position==old_position&&m.r8(0xa57c80)==0,"1641 unchanged actual slider and inactive reinitialization flag");
  const U eax=clamp(m,c);i.fp.image=fp::capture_host();fp::restore_host(host);return eax;
 }catch(...){fp::restore_host(host);throw;}
}
}
