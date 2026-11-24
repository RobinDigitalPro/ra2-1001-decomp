#include "recovered/recovery_b1469.hpp"
#include "recovered/text_b104.hpp"
#include "platform/listbox_reconnect1469.hpp"
namespace ra2::recovered::b1469 {
unsigned fun_0061e840(Memory&m,const Inputs&i,Heap&heap){
 namespace fp=ra2::platform::x87;using U=std::uint32_t;auto&c=b1462::ui::context();
 ui::need(&c.memory()==&m&&&c.heap()==&heap&&i.cx==ui::ptr(c.parent())&&i.dx==0,"1469 genuine parent and self-target route");
 const U table=m.r32(0xa27dac),first=m.r32(table),index=m.r32(first+0x5d),selected=m.r32(table+4*i.dx);
 ui::need(first&&selected==first&&index==0&&m.r32(0xa27db8)==1,"1469 genuine first peer/house-index projection");
 // Actual4068F0 is C3. Its four explicitly pushed arguments have no effects.
 const auto host=fp::capture_host();fp::restore_host(i.fp.image);try{
  const auto child=ui::getitem(c.parent(),0x651);global_b26::Inputs lookup{};lookup.cx=0x7d68b4;lookup.dx=0;lookup.arg[0]=0x7d6574;lookup.arg[1]=0xcc9;
  const U text=text_b104::fun_006eeb60(m,lookup);for(U k=0;k<6;++k)ui::need(m.r16(text+2*k)==U(k==5?0:(k%2?'Y':'X')),"1469 exact produced fixture localization");
  Inputs call=i;call.cx=0xffffffff;call.dx=text;call.arg[0]=ui::ptr(child);call.fp.image=fp::capture_host();ui::need(b1462::fun_005bd930(m,call,heap)==1,"1469 genuine font append ReleaseDC1");
  fp::restore_host(call.fp.image);const U count=U(ui::send(child,0x18b,0,0));ui::need(count==1,"1469 real positive row count; no eviction");const U result=U(ui::send(child,0x197,count-1,0));ui::need(result==0,"1469 actual equal-top fullEAX0");i.fp.image=fp::capture_host();fp::restore_host(host);return result;
 }catch(...){fp::restore_host(host);throw;}
}
}
