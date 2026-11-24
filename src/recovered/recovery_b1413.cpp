#include "recovered/recovery_b1413.hpp"
#include "platform/custom_combo1413.hpp"
#include "platform/x87_state.hpp"
#include "platform/x87_b61.hpp"
#include <array>
namespace ra2::recovered::b1413 {
namespace {using U=std::uint32_t;namespace fp=ra2::platform::x87;
void need(bool v,const char*s){ui::need(v,s);}
U lookup(Memory&m,U owner,U hwnd,U next){
 need(m.r32(owner+4u)==1u&&m.r32(owner+8u)==128u&&m.r32(owner+12u)==7u&&m.r32(owner+24u)==0x5d6fc0u,"1413 real scalar-key hash layout");
 // Genuine5D6FC0 returns *key, then5F98E0 masks by(1<<bits)-1.
 const U node=m.r32(m.r32(owner)+(hwnd&127u)*4u);
 need(node&&m.r32(node)==hwnd&&m.r32(node+next)==0u,"1413 one genuine HWND keyed record");return node;
}
void rect_relative(HWND window,RECT&out){
 need(ui::rect(window,&out)!=0,"1413 actual72A250 GetWindowRect success");auto&c=ui::context();RECT client{};need(ui::client(c.parent(),&client)!=0,"1413 actual parent client rect");POINT origin{client.left,client.top};need(ui::screen(c.parent(),&origin)!=0,"1413 actual ClientToScreen");out.left-=origin.x;out.right-=origin.x;out.top-=origin.y;out.bottom-=origin.y;
}
void load_unsigned(fp::State&f,U x){const std::uint64_t n=x;fp::Image host;asm volatile("fnsave %[h]\n\tfrstor %[g]\n\tfildq %[n]\n\tfnsave %[g]\n\tfrstor %[h]":[h]"=m"(host.bytes),[g]"+m"(f.image.bytes):[n]"m"(n):"memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");}
void insert_ratio(){fp::State f;f.image=fp::capture_host();load_unsigned(f,1u);f.divide_integer32(128u);f.compare_pop64(0x3fe999999999999aull);need((f.status()&0x100u)!=0u,"1413 exact1/128 below upperloadfactor");fp::restore_host(f.image);}
U removal_ratio(){fp::State f;f.image=fp::capture_host();load_unsigned(f,0u);f.divide_integer32(128u);const U ratio=f.pop32();fp::restore_host(f.image);return ratio;}
void remove_compare(U ratio){fp::State f;f.image=fp::capture_host();f.load32(ratio);f.compare_pop64(0x3fc999999999999aull);need((f.status()&0x100u)!=0u,"1413 exactzero below lowerloadfactor");fp::restore_host(f.image);}
}
unsigned configure_crt(Memory&m,const Inputs&i){if(i.arg[0]>1016u)return 0u;m.w32(0x817554u,i.arg[0]);return 1u;}
LRESULT CALLBACK combo_window_proc(HWND h,UINT message,WPARAM w,LPARAM l){
 auto&c=ui::context();Memory&m=c.memory();const U hwnd=ui::ptr(h);need(h==c.combo()&&(message==0x147u||message==0x498u)&&w==0,"1413 typed original combo scope");
 const U oldnode=lookup(m,0xa5b1e8u,hwnd,8u);need(m.r32(oldnode+4u)==ui::addr(c.os()),"1413 genuine captured old OS procedure");
 RECT relative{},client{},screen{};rect_relative(h,relative);need(ui::client(h,&client)!=0&&ui::rect(h,&screen)!=0,"1413 actual handler rectangles");
 const U record=lookup(m,0xa5b1a0u,hwnd,0x204u)+4u;
 need(m.r32(record+0x68u)==3u,"1413 actual ComboBox type producer");
 // Actual147 byte-table selector0 targets5ED6D7: cachedindex, not OSfallback.
 if(message==0x147u)return LRESULT(m.r32(record+0xf8u));
 // Actual498 selector targets5EE327. wParam0 chooses color element0.
 m.w32(record+0x110u,U(l));const U again=lookup(m,0xa5b1e8u,hwnd,8u);
 return ui::call(reinterpret_cast<WNDPROC>(std::uintptr_t(m.r32(again+4u))),h,message,w,l);
}
LRESULT CALLBACK common_window_proc(HWND h,UINT message,WPARAM w,LPARAM l){
 auto&c=ui::context();Memory&m=c.memory();Heap&heap=c.heap();const U hwnd=ui::ptr(h),owner=0xa5aef8u;
 need(h==c.combo()&&(message==0x147u||message==0x498u)&&w==0,"1413 typed original common scope");
 // Actual72CB80 non-IME branches return0/RET8 for147 and498.
 const U handler=lookup(m,0xa5af60u,hwnd,8u);need(m.r32(handler+4u)==0x5ecc60u,"1413 authentic game ComboBox handler");
 (void)lookup(m,0xa5b1e8u,hwnd,8u);
 need((m.r8(0xa5dc94u)&3u)==3u&&m.r32(0xa5dc70u)==0u&&m.r32(0xa5dc74u)==0u&&m.r32(0xa5dc78u)==0u,"1413 actual warm lazy registries and empty modal vector");
 need(m.r32(owner+4u)==0u&&m.r32(owner+8u)==128u&&m.r32(owner+12u)==7u&&m.r32(owner+24u)==0x5d6fd0u&&m.r32(owner+48u)==128u,"1413 actual temporary pair-key map prestate");
 need(m.r32(owner+32u)==0x9999999au&&m.r32(owner+36u)==0x3fc99999u&&m.r32(owner+40u)==0x9999999au&&m.r32(owner+44u)==0x3fe99999u,"1413 original .2/.8 load factors");
 need(m.r8(0xa28968u)==0u,"1413 ordinary nonpaint global mode");
 RECT relative{},screen{};rect_relative(h,relative);need(ui::rect(h,&screen)!=0,"1413 common raw window rect");
 // First lookup/removal sees a genuine empty message map, then original
 // 5E6937 allocates a fresh16B node and publishes exact pair(msg,HWND).
 const U table=m.r32(owner),bucket=(message*hwnd)&127u;need(m.r32(table+4u*bucket)==0u,"1413 no preexisting same-message recursion guard");
 const U node=heap.allocate(16u);need(node!=0u,"1413 actual owned transient message node");
 heap.w32(node,message);heap.w32(node+4u,hwnd);heap.w8(node+8u,1u);heap.w32(node+12u,0u);
 m.w32(table+4u*bucket,node);m.w32(owner+4u,1u);insert_ratio();
 RECT client{},again{};need(ui::client(h,&client)!=0,"1413 common client rect");rect_relative(h,again);
 m.w8(0x7d2ea8u,m.r8(0xa28968u));
 const U control=lookup(m,0xa5b1a0u,hwnd,0x204u)+4u;
 need(m.r32(control+0x24u)==0u&&m.r32(0xa5b46cu)!=hwnd,"1413 coherent ordinary nonpaint route");
 // Original callback address remains in memory. Portable execution composes
 // its typed equivalent, while the original-side IAT sees literal5ECC60.
 const LRESULT result=ui::call(&combo_window_proc,h,message,w,l);
 // Actual5F9CF0 count1 head-removal: preserve producer padding9..B, free
 // the genuine owner, clear exact bucket/count, compare exactfloat0 to.2.
 const U ratio=removal_ratio();need(heap.r32(node)==message&&heap.r32(node+4u)==hwnd&&heap.r8(node+8u)==1u&&heap.r32(node+12u)==0u,"1413 genuine head identity before free");
 need(heap.release(node)==1u,"1413 actual HeapFree BOOL1");m.w32(table+4u*bucket,0u);m.w32(owner+4u,0u);remove_compare(ratio);
 return result;
}
unsigned fun_00593e10(Memory&m,const Inputs&i,Heap&h){
 auto&c=ui::context();need(&c.memory()==&m&&&c.heap()==&h&&m.r32(i.cx)==ui::ptr(c.parent()),"1413 concrete real window owner");
 const auto host=fp::capture_host();fp::restore_host(i.fp.image);
 try{
  const HWND child=ui::get(c.parent(),0x405);need(child==c.combo(),"1413 genuine405 child");
  const U selected=U(ui::send(child,0x147u,0,0));need(selected<8u&&selected!=m.r32(i.cx+0x48u),"1413 existing valid differentselection");
  m.w32(0xa256e4u,selected);m.w8(i.cx+9u,1u);m.w8(i.cx+8u,1u);
  const U color=m.r32(0x7d1178u+4u*selected);const U result=U(ui::send(child,0x498u,0,LPARAM(color)));
  i.fp.image=fp::capture_host();fp::restore_host(host);return result;
 }catch(...){fp::restore_host(host);throw;}
}
}
