#include "recovered/recovery_b1456.hpp"
#include "platform/rows1456_provider.hpp"
#include "platform/x87_state.hpp"
#include "recovered/text_b104.hpp"
#include "recovered/leaf_b21_a.hpp"
#include "recovered/leaf_b21_b.hpp"
#include "recovered/leaf_b21_c.hpp"
namespace ra2::recovered::global_b26 {std::uint32_t fun_006eedc0(Memory&,const Inputs&);}
namespace ra2::recovered::b1456 {
namespace {using U=std::uint32_t;namespace fp=ra2::platform::x87;
void need(bool b,const char*s){ui::need(b,s);}
U lookup(Memory&m,U owner,U hwnd,U next){need(m.r32(owner+4)==5&&m.r32(owner+8)==128&&m.r32(owner+12)==7&&m.r32(owner+24)==0x5d6fc0,"1456 true five-HWND registry");U node=m.r32(m.r32(owner)+(hwnd&127)*4),steps=0;while(node&&m.r32(node)!=hwnd){need(++steps<5,"1456 bounded original collision chain");node=m.r32(node+next);}need(node&&m.r32(node)==hwnd,"1456 actual HWND registry match");return node;}
U control(Memory&m,HWND h){return lookup(m,0xa5b1a0,ui::ptr(h),0x204)+4;}
WNDPROC oldproc(Memory&m,HWND h){const U p=m.r32(lookup(m,0xa5b1e8,ui::ptr(h),8)+4);need(p==ui::addr(ui::context().os(h)),"1456 authentic per-HWND captured oldOS procedure");return reinterpret_cast<WNDPROC>(std::uintptr_t(p));}
void relative(HWND h,RECT&r){need(ui::rect(h,&r)!=0,"1456 actual72A250 screen success");RECT client{};POINT p{};auto parent=ui::context().outer();need(ui::client(parent,&client)!=0,"1456 parentclient");p.x=client.left;p.y=client.top;need(ui::screen(parent,&p)!=0,"1456 real screen conversion");r.left-=p.x;r.right-=p.x;r.top-=p.y;r.bottom-=p.y;}
void load_unsigned(fp::State&f,U x){const std::uint64_t v=x;fp::Image host;asm volatile("fnsave %[h]\n\tfrstor %[g]\n\tfildq %[n]\n\tfnsave %[g]\n\tfrstor %[h]":[h]"=m"(host.bytes),[g]"+m"(f.image.bytes):[n]"m"(v):"memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");}
U ratio(U count){fp::State f;f.image=fp::capture_host();load_unsigned(f,count);f.divide_integer32(128);const U v=f.pop32();fp::restore_host(f.image);return v;}
void lower(U value){fp::State f;f.image=fp::capture_host();f.load32(value);f.compare_pop64(0x3fc999999999999aull);need(f.status()&0x100,"1456 exact ratio below .2");fp::restore_host(f.image);}
void insert_fp(U count){fp::State f;f.image=fp::capture_host();load_unsigned(f,count);f.divide_integer32(128);f.compare_pop64(0x3fe999999999999aull);need(f.status()&0x100,"1456 exact ratio below .8");fp::restore_host(f.image);}
U readword(Heap&h,U p){return h.r8(p)|(h.r8(p+1)<<8);}
U length_memory(Memory&m,U p){U n=0;while(m.r16(p+2*n)){need(n<6,"1456 exact bounded UTF16 source");++n;}return n;}
U length_heap(Heap&h,U p){U n=0;while(readword(h,p+2*n)){need(n<6,"1456 exact owned UTF16 source");++n;}return n;}
void copy_memory(Memory&m,Heap&h,U out,U in,U n){for(U k=0;k<=n;++k){const U w=m.r16(in+2*k);h.w8(out+2*k,w);h.w8(out+2*k+1,w>>8);}}
void copy_heap(Heap&h,U out,U in,U n){for(U k=0;k<=n;++k){const U w=readword(h,in+2*k);h.w8(out+2*k,w);h.w8(out+2*k+1,w>>8);}}
// Exact5F9CF0 on the warm min-capacity message map. Unlike acceptedB1199,
// this fixture has a borrowed table and needs count0/1 and a missing key.
bool remove_message(Memory&m,Heap&h,U message,U hwnd){constexpr U owner=0xa5aef8;const U count=m.r32(owner+4);if(!count)return false;need(count<=3,"1456 finite nested message count");const U q=ratio(count-1),at=m.r32(owner)+4*((message*hwnd)&127);U previous=0,node=m.r32(at);if(!node)return false;
 while(node&&(h.r32(node)!=message||h.r32(node+4)!=hwnd)){previous=node;node=h.r32(node+12);}if(!node){lower(q);return false;}need(h.r8(node+8)==1,"1456 original published node byte");const U next=h.r32(node+12);if(previous){h.w32(previous+12,next);m.w32(owner+4,count-1);need(h.release(node)==1,"1456 real nonhead free");}else{need(h.release(node)==1,"1456 real head free");m.w32(at,next);m.w32(owner+4,count-1);}lower(q);return true;}
}
unsigned configure_crt(Memory&m,const Inputs&i){if(i.arg[0]>1016)return 0;m.w32(0x817554,i.arg[0]);return 1;}
LRESULT CALLBACK combo_window_proc(HWND h,UINT msg,WPARAM w,LPARAM l){auto&c=ui::context();Memory&m=c.memory();Heap&heap=c.heap();need(c.is_combo(h)&&ui::candidate_message(msg),"1456 bounded original selected handler");const auto old=oldproc(m,h);RECT a{},b{},r{};relative(h,a);need(ui::client(h,&b)&&ui::rect(h,&r),"1456 actual handler geometry");const U p=control(m,h);need(m.r32(p+0x68)==3,"1456 actual ComboBox type3");
 if(msg==0x4c2){need(w==0,"1456 append palette text");global_b26::Inputs convert{};convert.cx=U(l);const U narrow=global_b26::fun_006eedc0(m,convert);const U index=U(ui::call(old,h,0x143,0,LPARAM(narrow)));need(index<9,"1456 real successful OS addstring");const U n=length_memory(m,U(l)),node=heap.allocate(2*n+18);need(node,"1456 real original item allocation");heap.w32(node+8,node+16);heap.w32(node,m.r32(p+0x34));heap.w32(node+4,0);m.w32(p+0x34,node);heap.w32(node+12,1);copy_memory(m,heap,node+16,U(l),n);const U result=U(ui::call(old,h,0x151,index,LPARAM(node)));need(result!=0xffffffffu&&result!=0xfffffffeu,"1456 actual OS itemdata publication");return LRESULT(index);}
 if(msg==0x150||msg==0x151){const U node=U(ui::call(old,h,0x150,w,0));if(node==0xffffffffu||node==0)return LRESULT(0xffffffffu);need(w<9,"1456 real valid owned row");if(msg==0x150)return LRESULT(heap.r32(node+4));heap.w32(node+4,U(l));return LRESULT(node);}
 if(msg==0x4dd){need(w==0&&l==1,"1456 original palette-enable byte");m.w8(p+0xcc,U(l));return ui::call(oldproc(m,h),h,msg,w,l);}
 if(msg==0x498){need(w<9,"1456 original bounded per-item color");m.w32(p+0x110+4*U(w),U(l));return ui::call(oldproc(m,h),h,msg,w,l);}
 if(msg==0x4de){need(w==0&&l==9,"1456 actual format field");m.w32(p+0xd0,U(l));return ui::call(oldproc(m,h),h,msg,w,l);}
 if(msg==0x14e){need(w<9&&l==0,"1456 actual finite selection");m.w32(p+0xf8,U(w));const U node=U(ui::call(old,h,0x150,w,0));need(node&&node!=0xffffffffu&&heap.r32(node+12)==1,"1456 selected genuine UTF16 item");(void)ui::send(h,0x4b2,0,LPARAM(heap.r32(node+8)));const U style=U(ui::window_long(h,GWL_STYLE));need((style&3)==3,"1456 actual dropdownlist style");(void)ui::invalidate(h,nullptr,FALSE);return ui::call(oldproc(m,h),h,msg,w,l);}
 if(msg==0x147)return LRESULT(m.r32(p+0xf8));

 if(msg==0x4b2){const U style=U(ui::window_long(h,GWL_STYLE));need((style&3)==3,"1456 actual4B2 dropdownlist style path5EE19C");}
 need(msg==0x14b||msg==0x146||msg==0x4b2||ui::lifecycle_message(msg),"1456 reviewed default message");return ui::call(oldproc(m,h),h,msg,w,l);
}
LRESULT CALLBACK static_window_proc(HWND h,UINT msg,WPARAM w,LPARAM l){auto&c=ui::context();auto&m=c.memory();need(h==c.static_control()&&ui::lifecycle_message(msg),"1456 exact reached Static lifecycle");const U p=control(m,h);need(m.r32(p+0x68)==2&&m.r32(p+0x10)==0,"1456 original constructor no cached surface");if(msg==WM_SIZE||msg==WM_WINDOWPOSCHANGED){m.w32(p+0x10,0);(void)ui::invalidate(h,nullptr,FALSE);return 0;}return ui::call(oldproc(m,h),h,msg,w,l);}
LRESULT CALLBACK generic_window_proc(HWND h,UINT msg,WPARAM w,LPARAM l){auto&c=ui::context();need(h==c.parent()&&ui::lifecycle_message(msg),"1456 exact generic dialog lifecycle");auto&m=c.memory();RECT a{},b{};relative(h,a);need(ui::client(h,&b),"1456 real generic client");(void)control(m,h);return ui::call(oldproc(m,h),h,msg,w,l);}
INT_PTR CALLBACK dialog_proc(HWND h,UINT msg,WPARAM,LPARAM){need(h==ui::context().parent()&&ui::lifecycle_message(msg),"1456 actual679440 and5F77C0 exact default message");return 0;}

LRESULT CALLBACK common_window_proc(HWND h,UINT msg,WPARAM w,LPARAM l){auto&c=ui::context();Memory&m=c.memory();Heap&heap=c.heap();const U hwnd=ui::ptr(h),owner=0xa5aef8;need((c.is_combo(h)&&ui::candidate_message(msg))||((h==c.static_control()||h==c.parent())&&ui::lifecycle_message(msg)),"1456 reviewed common message");need(m.r32(lookup(m,0xa5af60,hwnd,8)+4)==(h==c.parent()?0x5e8310u:h==c.static_control()?0x5eac10u:0x5ecc60u),"1456 actual selected procedure");(void)oldproc(m,h);need(m.r8(0xa5dc94)==3&&m.r32(0xa5dc70)==0&&m.r32(0xa5dc74)==0&&m.r32(0xa5dc78)==0&&m.r8(0xa28968)==0,"1456 original warm nonmodal/nonpaint state");need(m.r32(owner+4)<=2&&m.r32(owner+8)==128&&m.r32(owner+12)==7&&m.r32(owner+24)==0x5d6fd0&&m.r32(owner+48)==128,"1456 actual bounded pairhash");need(m.r32(owner+32)==0x9999999a&&m.r32(owner+36)==0x3fc99999&&m.r32(owner+40)==0x9999999a&&m.r32(owner+44)==0x3fe99999,"1456 original .2/.8 factors");RECT a{},r{};relative(h,a);need(ui::rect(h,&r),"1456 actual common rectangle");
 const U at=m.r32(owner)+4*((msg*hwnd)&127);for(U q=m.r32(at);q;q=heap.r32(q+12))need(heap.r32(q)!=msg||heap.r32(q+4)!=hwnd,"1456 no same-message recursion shortcut");need(!remove_message(m,heap,msg,hwnd),"1456 original initial lookup is missing key");const U node=heap.allocate(16);need(node,"1456 real temporary message owner");heap.w32(node,msg);heap.w32(node+4,hwnd);heap.w8(node+8,1);heap.w32(node+12,m.r32(at));m.w32(at,node);m.w32(owner+4,m.r32(owner+4)+1);insert_fp(m.r32(owner+4));RECT b{},r2{};need(ui::client(h,&b),"1456 real common client");relative(h,r2);m.w8(0x7d2ea8,m.r8(0xa28968));const U p=control(m,h);need(m.r32(p+0x24)==0&&m.r32(0xa5b46c)!=hwnd,"1456 ordinary nonpaint route");
 if(msg==0x4b2){need(w==0&&m.r32(p+0x70)==0,"1456 actual selectedlabel state");const U old=m.r32(p+0x28);if(old){U k=0;while(readword(heap,old+2*k)==readword(heap,U(l)+2*k)&&readword(heap,old+2*k)){need(++k<7,"1456 exact76F113 bounded compare");}need(heap.release(old)==1,"1456 actual old label free even when equal");}m.w32(p+0x28,0);const U n=length_heap(heap,U(l));need(n>0,"1456 positive UTF16 selected label");const U text=heap.allocate(2*n+2);need(text,"1456 genuine selectedlabel owner");m.w32(p+0x28,text);copy_heap(heap,text,U(l),n);m.w32(p+0x2c,0);}

 const LRESULT result=ui::call(h==c.parent()?&generic_window_proc:h==c.static_control()?&static_window_proc:&combo_window_proc,h,msg,w,l);need(remove_message(m,heap,msg,hwnd),"1456 genuine current-message unlink");return result;
}
template<class F>U with_fp(const Inputs&i,F operation){const auto host=fp::capture_host();fp::restore_host(i.fp.image);try{const U result=operation();i.fp.image=fp::capture_host();fp::restore_host(host);return result;}catch(...){fp::restore_host(host);throw;}}
// Exact used-field producer6797BC..679874: four real cache lookups and
// owned Combo rows. Selection1..3 is the subsequent proven AI restoration.
unsigned populate(Memory&m,const Inputs&i,Heap&heap,unsigned selected){auto&c=ui::context();need(&m==&c.memory()&&&heap==&c.heap()&&selected>=1&&selected<=3,"1456 actual type row producer domain");return with_fp(i,[&]{constexpr U keys[]{0x7dd8a0,0x7d152c,0x7d151c,0x7d1510};for(U k=0;k<4;++k){global_b26::Inputs lookup{};lookup.cx=keys[k];lookup.dx=0;lookup.arg[0]=0x7dd86c;lookup.arg[1]=0x9c+3*k;const U text=text_b104::fun_006eeb60(m,lookup);need(text,"1456 genuine B104 positive cache hit");const U row=U(ui::send(c.combo(0),0x4c2,0,LPARAM(text)));need(row==k,"1456 actual four row insertion");(void)ui::send(c.combo(0),0x151,row,LPARAM(k?3-k:0xffffffffu));}return U(ui::send(c.combo(0),0x14e,selected,0));});}
unsigned fun_00678e20(Memory&m,const Inputs&i,Heap&heap){auto&c=ui::context();need(&m==&c.memory()&&&heap==&c.heap()&&i.cx==ui::ptr(c.parent())&&i.dx==1&&i.arg[0]==1,"1456 actual one positive row");return with_fp(i,[&]{
 const U index=i.dx,limit=index+i.arg[0],type_id=0x50b;leaf::Inputs id{};id.cx=index;
 i.arg[0]=leaf::fun_004d0a80(c.leaf_span(),id);const U palette_id=leaf::fun_004d1530(c.leaf_span(),id),country_id=leaf::fun_004d0d70(c.leaf_span(),id);
 const HWND type=ui::get(c.parent(),type_id);const HWND preview=ui::get(c.parent(),i.arg[0]);i.arg[0]=ui::ptr(preview);const HWND palette=ui::get(c.parent(),palette_id),country=ui::get(c.parent(),country_id);
 (void)ui::show(type,5);(void)ui::show(preview,5);(void)ui::show(palette,5);(void)ui::show(country,5);
 id.cx=1;i.arg[0]=leaf::fun_004d1530(c.leaf_span(),id);const U last_country_id=leaf::fun_004d0d70(c.leaf_span(),id);
 const U row=U(ui::send_dialog(c.parent(),type_id,0x147,0,0));const U data=U(ui::send_dialog(c.parent(),type_id,0x150,row,0));need(data<=2,"1456 actual positive AI selection");
 const HWND lastpalette=ui::get(c.parent(),i.arg[0]);i.arg[0]=ui::ptr(lastpalette);const HWND lastcountry=ui::get(c.parent(),last_country_id);(void)ui::enable(lastpalette,TRUE);(void)ui::enable(lastcountry,TRUE);const U result=index+1;need(result==limit,"1456 exact single useful loop iteration");return result;});}
}
