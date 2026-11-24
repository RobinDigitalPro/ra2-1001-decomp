#include "recovery_b1200.hpp"
#include <stdexcept>
namespace ra2::recovered::b1200{
static void need(bool x){if(!x)throw std::domain_error("1200 positive genuine flat Cell E4 Infantry insertion");}
unsigned run(unsigned root,Memory&m,const Inputs&i,State&s){
 need(root==0x73730u&&i.arg[0]!=0u&&(i.arg[1]&255u)==0u);
 const unsigned actor=i.arg[0],cell=i.cx;need(m.r32(cell)==0x788b04u&&m.r32(actor)==0x78e540u&&m.r8(actor+0x79u)==0u&&m.r32(actor+0x30u)==0u&&m.r32(0x78e56cu)==0x508c50u);
 const auto head=m.r32(cell+0xe4u);need(head&&m.r32(head+0x30u)!=actor);m.w32(actor+0x30u,head);m.w32(cell+0xe4u,actor);
 const auto packed=m.r32(cell+0x24u);i.arg[1]=packed;
 need(packed==0x00140014u&&m.r8(cell+0x11bu)==0u&&m.r8(cell+0x11cu)==0u&&m.r8(0x838f70u)==7u&&m.r32(0x838f80u)==104u);
 // Original4702C0 flat/shape0 and76AA50: scratch push, +.5, truncCW, pop.
 s.load_integer32(0u);s.add64(0x3fe0000000000000ull);s.load_control(static_cast<unsigned short>(m.r32(0x7c3a04u)));need(s.pop_integer64()==0u);
 need(m.r32(0xa57848u)==104u);const auto table=m.r32(0x81a958u),found=m.r32(table+4u*(20u+512u*20u));need(found==cell&&(m.r8(found+0x12cu)&8u)==0u&&m.r32(0xa255c8u)==0u);
 // True564F30 positive even-Z lookup skips5651B0; A255C8 zero skips+180.
 // Final actual78E540+2C getter again returns full15 before placement arms.
 return 15u;
}
}
