#include "recovery_b1653.hpp"
#include <stdexcept>
namespace ra2::recovered::b1653 {
namespace {
void need(bool condition,const char*message){if(!condition)throw std::domain_error(message);}
U child(Api&api,U dialog,int identifier,fp::State&state){
 const U control=api.get_dialog_item(dialog,identifier,state);
 need(control!=0,"B1653 authentic resource245 required control absent");
 return control;
}
}
U fun_0053f9a0(Memory&m,const Inputs&i,Api&api){
 const U dialog=i.cx;
 need(api.owned_dialog(dialog),"B1653 genuinely owned resource245 dialog required");
 // 53F9B2 GetDlgItem(52B);53F9C8 SendMessage(TBM_GETPOS,0,0).
 const U detail_control=child(api,dialog,0x52b,i.fp);
 const U detail_position=api.send(detail_control,0x400,0,0,i.fp);
 need(detail_position<=1,"B1653 visual-detail trackbar domain0..1");
 const U mapped_detail=detail_position!=0?2u:0u; // NEG/SBB/AND2.
 // The changed-detail49E2A0 branch is outside this finite domain. Matching
 // public state executes the original equality exit without any global store.
 need(m.r32(0xa2876c)==mapped_detail,"B1653 unchanged detail excludes49E2A0");

 // 53F9F0/53FA00: difficulty0..2 is stored as its full actual DWORD.
 const U difficulty_control=child(api,dialog,0x50f,i.fp);
 const U difficulty=api.send(difficulty_control,0x400,0,0,i.fp);
 need(difficulty<=2,"B1653 difficulty trackbar domain0..2");
 m.w32(0xa2875c,difficulty);

 // 53FA0D/53FA1D;SETZCL and actual7B6CCF30 helper effect.
 const U target_control=child(api,dialog,0x601,i.fp);
 const U target_check=api.send(target_control,0xf0,0,0,i.fp);
 need(target_check<=1,"B1653 target-lines checkbox domain0..1");
 const U target_lines=target_check==1?1u:0u;
 m.w8(0xa28772,target_lines);
 // 6CCF30 880DA0097E00 MOV [7E09A0],CL;6CCF36 C3 RET.
 m.w8(0x7e09a0,target_lines);

 // 53FA36/53FA46: hidden-objects checkbox.
 const U hidden_control=child(api,dialog,0x604,i.fp);
 const U hidden_check=api.send(hidden_control,0xf0,0,0,i.fp);
 need(hidden_check<=1,"B1653 hidden-objects checkbox domain0..1");
 m.w8(0xa28773,hidden_check==1?1u:0u);

 // 53FA59/53FA69: tooltips checkbox, before scroll-rate query.
 const U tooltip_control=child(api,dialog,0x602,i.fp);
 const U tooltip_check=api.send(tooltip_control,0xf0,0,0,i.fp);
 need(tooltip_check<=1,"B1653 tooltips checkbox domain0..1");
 m.w8(0xa28774,tooltip_check==1?1u:0u);

 // 53FA7D/53FA8D: scroll-rate0..6 -> exact full DWORD6-position.
 const U scroll_control=child(api,dialog,0x52a,i.fp);
 const U scroll_position=api.send(scroll_control,0x400,0,0,i.fp);
 need(scroll_position<=6,"B1653 scroll trackbar domain0..6");
 m.w32(0xa28764,6u-scroll_position);

 // These three lookups are all reached in the original. Resource245 truly
 // has no audio controls; nonnull results select unsupported audio/FP paths.
 const U absent_music=api.get_dialog_item(dialog,0x52f,i.fp);
 need(absent_music==0,"B1653 resource245 excludes music control");
 const U absent_effects=api.get_dialog_item(dialog,0x532,i.fp);
 need(absent_effects==0,"B1653 resource245 excludes sound control");
 const U absent_voice=api.get_dialog_item(dialog,0x536,i.fp);
 need(absent_voice==0,"B1653 resource245 excludes voice control");
 return absent_voice; // Last actual full EAX; no boolean/pointer normalization.
}
}
