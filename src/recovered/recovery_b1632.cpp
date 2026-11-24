#include "recovered/recovery_b1632.hpp"
#include "recovered/leaf_b21_a.hpp"
#include "recovered/leaf_b21_b.hpp"
#include "recovered/leaf_b21_c.hpp"
#include "platform/observed_controls1632.hpp"
namespace ra2::recovered::b1632 {
namespace observation=ra2::platform::controls1632;namespace fp=ra2::platform::x87;using U=std::uint32_t;
unsigned fun_00679050(Memory&m,const Inputs&i){
 auto&c=observation::Trace::context();if(i.dx!=7u||i.cx!=observation::ptr(c.parent()))throw std::domain_error("1632 exact owned HWND/EDX7 finite domain");(void)m;
 const auto host=fp::capture_host();fp::restore_host(i.fp.image);
 try{
  const HWND parent=c.parent();U index=i.dx-1u;const U selector=index==6u?0x51du:0xffffffffu;if(selector!=0x51du)throw std::domain_error("1632 actual selector mapping");
  const U count=U(observation::Trace::send_dialog(parent,int(selector),CB_GETCOUNT,0,0));if(count<1u||count>4u)throw std::domain_error("1632 actual nonempty selector range");
  for(U row=0;row<count;++row){const U data=U(observation::Trace::send_dialog(parent,int(selector),CB_GETITEMDATA,row,0));if(data>2u)throw std::domain_error("1632 every actual selector itemdata0/1/2");}
  // Accepted pure getters access no Memory; one-byte local adapter only
  // supplies their existing C++ signature, not an Original object/provider.
  std::uint8_t unused=0;leaf::Memory ignored(&unused,0,1);leaf::Inputs getter{};getter.cx=index+1u;const U palette=leaf::fun_004d1530(ignored,getter),country=leaf::fun_004d0d70(ignored,getter);if(country!=0x521u||palette!=0x528u)throw std::domain_error("1632 authentic role7 country/palette IDs");
  const U selected=U(observation::Trace::send_dialog(parent,int(selector),CB_GETCURSEL,0,0));if(selected>=count)throw std::domain_error("1632 actual valid selected row");const U chosen=U(observation::Trace::send_dialog(parent,int(selector),CB_GETITEMDATA,selected,0));if(chosen>2u)throw std::domain_error("1632 actual selected value skips both rebuild helpers");
  const HWND palette_h=observation::Trace::get(parent,int(palette));const HWND country_h=observation::Trace::get(parent,int(country));(void)observation::Trace::enable(palette_h,TRUE);(void)observation::Trace::enable(country_h,TRUE);
  ++index; // 679206..210 produces next index7 and comparison value8.
  if(index+1u!=8u)throw std::domain_error("1632 exactly one first iteration");
  U second=i.dx-1u;++second;getter.cx=second;const U auxiliary=leaf::fun_004d0a80(ignored,getter);const U country2=leaf::fun_004d0d70(ignored,getter);const U palette2=leaf::fun_004d1530(ignored,getter);if(auxiliary!=0x6e1u||country2!=country||palette2!=palette)throw std::domain_error("1632 actual final hide IDs");
  const HWND selector_h=observation::Trace::get(parent,int(selector));const HWND auxiliary_h=observation::Trace::get(parent,int(auxiliary));const HWND country_h2=observation::Trace::get(parent,int(country2));const HWND palette_h2=observation::Trace::get(parent,int(palette2));(void)observation::Trace::show(selector_h,SW_HIDE);(void)observation::Trace::show(auxiliary_h,SW_HIDE);(void)observation::Trace::show(country_h2,SW_HIDE);(void)observation::Trace::show(palette_h2,SW_HIDE);
  const U eax=second+1u; // Authentic 679304 LEA EAX,[ESI+1], full8.
  i.fp.image=fp::capture_host();fp::restore_host(host);return eax;
 }catch(...){fp::restore_host(host);throw;}
}
}
