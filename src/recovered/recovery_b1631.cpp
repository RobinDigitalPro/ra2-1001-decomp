
// Canonical merge: unchanged finite -2 helper, followed by fullRoot.
#include "recovered/recovery_b1631.hpp"
#include "platform/custom_combo1430.hpp"
#include "platform/x87_state.hpp"
namespace ra2::recovered::b1631 {
namespace ui = ra2::recovered::b1430::ui;
namespace fp = ra2::platform::x87;
using U = std::uint32_t;

unsigned fun_004d1bb0_minus2(Memory& m, const Inputs& i, Heap& heap) {
    auto& c = ui::context();
    ui::need(&c.memory() == &m && &c.heap() == &heap &&
             i.cx == ui::ptr(c.parent()) && i.dx == 0x6a2 &&
             i.arg[0] == 0xfffffffeu,
             "1631 exact D1BB0 owner-0 minus-two request");

    const auto host = fp::capture_host();
    fp::restore_host(i.fp.image);
    try {
        const HWND child = ui::get(c.parent(), int(i.dx));
        const U hidden = U(ui::show(child, 0)) == 0;
        ui::need(hidden, "1631 actual declared hidden entry");

        // Match B1417's existing owner-0 clear exactly. This is a real
        // assignment slot update before querying/selecting the authentic row.
        bool cleared = false;
        for (U color = 0; color < 8; ++color) {
            if (m.r32(0x84e410 + 12 * color) == 0) {
                m.w32(0x84e410 + 12 * color, 0xffffffffu);
                cleared = true;
                break;
            }
        }
        ui::need(cleared, "1631 original owner-0 assignment slot exists");

        const U count = U(ui::send_dialog(c.parent(), int(i.dx), 0x146, 0, 0));
        ui::need(count == 9, "1631 genuine nine-row owner-0 palette");
        bool found = false;
        for (U row = 0; row < count; ++row) {
            const U value = U(ui::send_dialog(c.parent(), int(i.dx), 0x150, row, 0));
            if (value != i.arg[0]) continue;
            (void)ui::send_dialog(c.parent(), int(i.dx), 0x14e, row, 0);
            // The authentic -2 item-data is a selection sentinel. D1BB0's
            // taken equality branch skips the indexed assignment at 4D1CDD..5D.
            found = true;
            break;
        }
        ui::need(found, "1631 authentic Random row carries item-data -2");

        i.fp.image = fp::capture_host();
        fp::restore_host(host);
        U result = 0;
        for (U role = 0; role < 8; ++role) {
            Inputs child_input = i;
            child_input.dx = ui::ids[role];
            result = b1430::fun_004d18c0(m, child_input, heap);
            i.fp.image = child_input.fp.image;
        }
        return result;
    } catch (...) {
        fp::restore_host(host);
        throw;
    }
}
}


#include "recovered/recovery_b1631.hpp"
#include "recovered/recovery_b1016_lookup.hpp"
#include "recovered/leaf_b21_a.hpp"
#include "recovered/leaf_b21_c.hpp"
#include "platform/custom_combo1430.hpp"
#include "platform/x87_state.hpp"
namespace ra2::recovered::b1631 {
namespace ui=b1430::ui;namespace fp=ra2::platform::x87;using U=std::uint32_t;
unsigned fun_004d1310_minus2(Memory&m,const Inputs&i,RootHeap&heap){
 auto&c=ui::context();ui::need(&c.memory()==&m&&&c.heap()==&heap&&i.cx==ui::ptr(c.parent())&&i.dx==0x6a1u&&i.arg[0]==0xfffffffeu&&c.expected_control_registry_count(0xa5b1a0u)==10u,"1631 exact country minus2 finite input");
 const auto host=fp::capture_host();fp::restore_host(i.fp.image);
 try{
  const HWND parent=c.parent();const HWND country=ui::get(parent,int(i.dx));ui::need(country==c.extra_combo(8),"1631 actual owned country");const U was_visible=U(ui::show(country,SW_HIDE));ui::need(was_visible==0u,"1631 declared hidden country");
  const U count=U(ui::send_dialog(parent,int(i.dx),CB_GETCOUNT,0,0));ui::need(count==4u,"1631 real country four rows");bool found=false;
  for(U row=0;row<count;++row){const U value=U(ui::send_dialog(parent,int(i.dx),CB_GETITEMDATA,row,0));if(value!=i.arg[0])continue;ui::need(row==0u,"1631 genuine Random sentinel first row");const U result=U(ui::send_dialog(parent,int(i.dx),CB_SETCURSEL,row,0));ui::need(result==row,"1631 actual selection return");found=true;break;}
  ui::need(found,"1631 real minus2 match");const HWND preview=ui::get(parent,0x6da);ui::need(preview==c.preview(),"1631 genuine preview HWND");const U selected=U(ui::send_dialog(parent,int(i.dx),CB_GETCURSEL,0,0));ui::need(selected==0u,"1631 actual selected row0");b979::Inputs lookup{};lookup.cx=U(ui::send_dialog(parent,int(i.dx),CB_GETITEMDATA,selected,0));ui::need(lookup.cx==0xfffffffeu,"1631 actual selected itemdata");
  const U resource=b1016::lookup199::fun_004d0b50(m,lookup,heap);const U key=ui::ptr(preview);ui::need(m.r32(0xa5b1a4u)==10u&&m.r32(0xa5b1a8u)==128u&&m.r32(0xa5b1acu)==7u&&m.r32(0xa5b1b8u)==0x5d6fc0u,"1631 authentic ten-node preview hash");U node=m.r32(m.r32(0xa5b1a0u)+4u*(key&127u)),steps=0;
  while(node&&m.r32(node)!=key){ui::need(++steps<10u,"1631 bounded preview chain");node=m.r32(node+0x204u);}ui::need(node&&m.r32(node)==key,"1631 existing preview record");m.w32(node+0x74u,2u);m.w32(node+0x18u,resource);
  const U result=U(ui::invalidate(preview,nullptr,TRUE));ui::need(result!=0u,"1631 actual preview invalidation");i.fp.image=fp::capture_host();fp::restore_host(host);return result;
 }catch(...){fp::restore_host(host);throw;}
}
unsigned fun_005c41a0(Memory&m,const Inputs&i,RootHeap&heap){
 auto&c=ui::context();ui::need(&c.memory()==&m&&&c.heap()==&heap&&i.cx==ui::ptr(c.parent())&&m.r32(0xa255c8u)!=4u&&c.disable_message(c.combo(0),0x1fu,0,0),"1631 owner0 preview fullRoot finite mode");
 const U tokens[]{m.r32(0xa5a8a4u),m.r32(0xa5a8a8u),m.r32(0xa5a8acu)};for(U t:tokens)ui::need(t!=0u,"1631 public nonzero role tokens");
 const auto host=fp::capture_host();fp::restore_host(i.fp.image);
 try{
  U last=0;bool changed=false;
  for(U role=0;role<8u;++role){const U id=0x411u+role;const U row=U(ui::send_dialog(c.parent(),int(id),CB_GETCURSEL,0,0));ui::need(row==0u,"1631 actual finite role selection0");last=U(ui::send_dialog(c.parent(),int(id),CB_GETITEMDATA,row,0));
   if(role!=0u){ui::need(last==0u,"1631 other seven roles genuinely nonmatching");continue;}
   ui::need(last!=0u&&(last==tokens[0]||last==tokens[1]||last==tokens[2]),"1631 actual owner0 token hit");m.w32(0xa27dc4u,m.r32(0xa5a89cu));
   // Both authentic accepted getters ignore Memory. This one-byte Source-only
   // adapter supplies their required C++ reference, not an Original object.
   std::uint8_t unused=0;leaf::Memory getter_memory(&unused,0u,1u);leaf::Inputs getter{};getter.cx=role;const U country_id=leaf::fun_004d0d70(getter_memory,getter);const U palette_id=leaf::fun_004d1530(getter_memory,getter);ui::need(country_id==0x6a1u&&palette_id==0x6a2u,"1631 actual accepted owner0 ID mapping");
   Inputs child=i;child.cx=ui::ptr(c.parent());child.dx=country_id;child.arg[0]=0xfffffffeu;child.fp.image=fp::capture_host();(void)fun_004d1310_minus2(m,child,heap);fp::restore_host(child.fp.image);
   child=i;child.cx=ui::ptr(c.parent());child.dx=palette_id;child.arg[0]=0xfffffffeu;child.fp.image=fp::capture_host();(void)fun_004d1bb0_minus2(m,child,heap);fp::restore_host(child.fp.image);
   const HWND country=ui::get(c.parent(),int(country_id));ui::need(country==c.extra_combo(8),"1631 actual country disable target");(void)ui::enable(country,FALSE);
   const HWND palette=ui::get(c.parent(),int(palette_id));ui::need(palette==c.combo(0),"1631 actual palette disable target");(void)ui::enable(palette,FALSE);
   m.w32(0xa2560cu,0xffffffffu);m.w32(0xa2562cu,0xffffffffu);m.w32(0xa2564cu,0xffffffffu);changed=true;
  }
  i.fp.image=fp::capture_host();fp::restore_host(host);return(last&0xffffff00u)|(changed?1u:0u);
 }catch(...){fp::restore_host(host);throw;}
}
}
