#include "recovered/recovery_b1029.hpp"
#include "recovered/recovery_b1029_lookup.hpp"
#include "platform/dialog1029.hpp"
namespace ra2::recovered::b1029 {
namespace {
HWND hwnd(unsigned x){return reinterpret_cast<HWND>(std::uintptr_t(x));}
unsigned live_context(unsigned w){const unsigned p=unsigned(ui::user(hwnd(w),8));ui::need(p!=0u,"1029 actual live dialog context");return p;}
void command(const Inputs&i){ui::need(i.arg[1]==WM_COMMAND,"1029 exact original1F77C0 command-default dependency");}
unsigned preview(Memory&m,unsigned parent,unsigned ordinal,Heap&heap){
 ui::need(ordinal==3u||ordinal==5u||ordinal==6u||ordinal==7u,"1029 original mapped four preview ordinals");
 ui::need(m.r32(0x817554u)==0u&&m.r32(0xb10e14u)==0u,"1029 original ordinary malloc9/free route");
 const auto h=hwnd(parent);const auto p=combo_ui::get(h,int(0x6dau+ordinal));const unsigned id=combo_ui::combo_id(ordinal);
 const auto selected=combo_ui::send(h,id,CB_GETCURSEL,0,0);ui::need(selected>=0&&selected<4,"1029 actual positive selected item");
 Inputs q{};q.cx=unsigned(combo_ui::send(h,id,CB_GETITEMDATA,WPARAM(selected),0));const auto resource=lookup199::fun_004d0b50(m,q,heap);
 const unsigned key=combo_ui::pointer(p);ui::need(m.r32(0xa5b1b8u)==0x5d6fc0u&&m.r32(0xa5b1acu)==7u&&m.r32(0xa5b1a4u)>0u,"1029 actual original numeric HWND hash callback");
 unsigned node=m.r32(m.r32(0xa5b1a0u)+4u*(key&127u)),seen=0;while(node&&m.r32(node)!=key){ui::need(++seen<4u,"1029 bounded positive HWND chain");node=m.r32(node+0x204u);}ui::need(node,"1029 positive preview HWND record");
 m.w32(node+0x74u,2u);m.w32(node+0x18u,resource);return unsigned(combo_ui::invalidate(p,nullptr,TRUE));
}
}
unsigned fun_004cf7e0(Memory&m,const Inputs&i,Heap&){command(i);const unsigned p=live_context(i.arg[0]),id=i.arg[2]&65535u,notification=i.arg[2]>>16u;
 ui::need(id==0x686u||((id==0x52cu||id==0x52du)&&notification==0u&&m.r8(0xa285a8u)==1u),"1029 positive close/mode commands");
 if(id==0x52cu||id==0x52du)m.w32(0xa28988u,id==0x52cu?4u:6u);m.w32(p,1u);return 0u;}
unsigned fun_0073be50(Memory&m,const Inputs&i,Heap&){command(i);const unsigned p=live_context(i.arg[0]),id=i.arg[2]&65535u;const auto h=hwnd(i.arg[0]);
 if(id==0x629u){if(ui::send_dialog(h,0x629,BM_GETCHECK,0,0)==BST_CHECKED){ui::send_dialog(h,0x66c,BM_SETCHECK,BST_UNCHECKED,0);m.w8(p+0x11u,0u);m.w8(p+0x10u,1u);}else m.w8(p+0x10u,0u);}
 else if(id==0x66cu){if(ui::send_dialog(h,0x66c,BM_GETCHECK,0,0)==BST_CHECKED){ui::send_dialog(h,0x629,BM_SETCHECK,BST_UNCHECKED,0);m.w8(p+0x11u,1u);m.w8(p+0x10u,0u);}else m.w8(p+0x11u,0u);}
 else if(id==0x6dfu||id==0x6e0u){const unsigned other=id==0x6dfu?0x6e0u:0x6dfu;if(ui::checked(h,other))ui::check(h,other,BST_UNCHECKED);else ui::check(h,id,BST_CHECKED);}
 else{ui::need(id==0x71eu,"1029 supported actual check controls");m.w8(p+0x12u,ui::send(hwnd(i.arg[3]),BM_GETCHECK,0,0)==BST_CHECKED?1u:0u);}return 0u;}
unsigned fun_005749c0(Memory&m,const Inputs&i,Heap&){command(i);const unsigned p=live_context(i.arg[0]);i.arg[3]=p;ui::need((i.arg[2]&65535u)==0x5c0u,"1029 positive command5C0 context completion");m.w32(p,2u);return 1u;}
unsigned fun_00678120(Memory&m,const Inputs&i,Heap&h){live_context(i.cx);ui::need(i.dx>=0x51eu&&i.dx<=0x521u,"1029 exact original positive dispatch range");const unsigned ordinal=i.dx==0x51eu?3u:i.dx==0x51fu?5u:i.dx==0x520u?6u:7u;return preview(m,i.cx,ordinal,h);}
unsigned fun_00679440(Memory&m,const Inputs&i,Heap&h){command(i);Inputs child{};child.cx=i.arg[0];child.dx=i.arg[2]&65535u;child.arg[0]=i.arg[3];child.arg[1]=i.arg[2]>>16u;fun_00678120(m,child,h);return 1u;}
unsigned run(Memory&m,const Inputs&i,Heap&h,unsigned r){switch(r){case 0xcf7e0:return fun_004cf7e0(m,i,h);case 0x33be50:return fun_0073be50(m,i,h);case 0x1749c0:return fun_005749c0(m,i,h);case 0x278120:return fun_00678120(m,i,h);case 0x279440:return fun_00679440(m,i,h);default:throw std::domain_error("1029 selected root");}}
}
