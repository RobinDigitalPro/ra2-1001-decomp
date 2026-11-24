#include "recovered/recovery_b1480.hpp"
#include "platform/custom_button1480.hpp"
#include "platform/x87_state.hpp"
#include "platform/x87_b61.hpp"
#include <array>
namespace ra2::recovered::b1480 {
namespace {using U=std::uint32_t;namespace fp=ra2::platform::x87;
void need(bool v,const char*s){ui::need(v,s);}
U lookup(Memory&m,U owner,U hwnd,U next){
 need(m.r32(owner+4u)==4u&&m.r32(owner+8u)==128u&&m.r32(owner+12u)==7u&&m.r32(owner+24u)==0x5d6fc0u,"1480 actual four HWND scalar hash");
 U node=m.r32(m.r32(owner)+(hwnd&127u)*4u),steps=0;while(node&&m.r32(node)!=hwnd){need(++steps<4,"1480 bounded genuine collision chain");node=m.r32(node+next);}need(node!=0,"1480 genuine matching HWND record");return node;
}
void rect_relative(HWND window,RECT&out){
 need(ui::rect(window,&out)!=0,"1480 actual72A250 GetWindowRect success");auto&c=ui::context();RECT client{};need(ui::client(c.parent(),&client)!=0,"1480 actual parent client rect");POINT origin{client.left,client.top};need(ui::screen(c.parent(),&origin)!=0,"1480 actual ClientToScreen");out.left-=origin.x;out.right-=origin.x;out.top-=origin.y;out.bottom-=origin.y;
}
void load_unsigned(fp::State&f,U x){const std::uint64_t n=x;fp::Image host;asm volatile("fnsave %[h]\n\tfrstor %[g]\n\tfildq %[n]\n\tfnsave %[g]\n\tfrstor %[h]":[h]"=m"(host.bytes),[g]"+m"(f.image.bytes):[n]"m"(n):"memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");}
void insert_ratio(){fp::State f;f.image=fp::capture_host();load_unsigned(f,1u);f.divide_integer32(128u);f.compare_pop64(0x3fe999999999999aull);need((f.status()&0x100u)!=0u,"1480 exact1/128 below upperloadfactor");fp::restore_host(f.image);}
U removal_ratio(){fp::State f;f.image=fp::capture_host();load_unsigned(f,0u);f.divide_integer32(128u);const U ratio=f.pop32();fp::restore_host(f.image);return ratio;}
void remove_compare(U ratio){fp::State f;f.image=fp::capture_host();f.load32(ratio);f.compare_pop64(0x3fc999999999999aull);need((f.status()&0x100u)!=0u,"1480 exactzero below lowerloadfactor");fp::restore_host(f.image);}
}
unsigned configure_crt(Memory&m,const Inputs&i){if(i.arg[0]>1016u)return 0u;m.w32(0x817554u,i.arg[0]);return 1u;}
LRESULT CALLBACK button_window_proc(HWND h,UINT message,WPARAM w,LPARAM l){
 auto&c=ui::context();Memory&m=c.memory();need(c.index(h)<4&&(message==0xf0u||message==0xf1u)&&l==0,"1480 actual Button F0/F1 scope");
 const U record=lookup(m,0xa5b1a0u,ui::ptr(h),0x204u)+4u;need(m.r32(record+0x68u)==0,"1480 original Button type0");
 if(message==0xf0u){need(w==0,"1480 actual query wParam0");return LRESULT(m.r32(record+0xe8u));}
 need(w<=1,"1480 original produced boolean setter");m.w32(record+0xe8u,U(w));(void)ui::invalidate(h,nullptr,FALSE);return 0;
}
LRESULT CALLBACK common_window_proc(HWND h,UINT message,WPARAM w,LPARAM l){
 auto&c=ui::context();Memory&m=c.memory();Heap&heap=c.heap();const U hwnd=ui::ptr(h),owner=0xa5aef8u;
 need(c.index(h)<4&&(message==0xf0u||message==0xf1u)&&l==0&&(message==0xf0u?w==0:w<=1),"1480 typed original common scope");
 // Actual72CB80 non-IME branches return0/RET8 for147 and498.
 const U handler=lookup(m,0xa5af60u,hwnd,8u);need(m.r32(handler+4u)==0x5ebdb0u,"1480 authentic game Button handler");
 (void)lookup(m,0xa5b1e8u,hwnd,8u);
 need((m.r8(0xa5dc94u)&3u)==3u&&m.r32(0xa5dc70u)==0u&&m.r32(0xa5dc74u)==0u&&m.r32(0xa5dc78u)==0u,"1480 actual warm lazy registries and empty modal vector");
 need(m.r32(owner+4u)==0u&&m.r32(owner+8u)==128u&&m.r32(owner+12u)==7u&&m.r32(owner+24u)==0x5d6fd0u&&m.r32(owner+48u)==128u,"1480 actual temporary pair-key map prestate");
 need(m.r32(owner+32u)==0x9999999au&&m.r32(owner+36u)==0x3fc99999u&&m.r32(owner+40u)==0x9999999au&&m.r32(owner+44u)==0x3fe99999u,"1480 original .2/.8 load factors");
 need(m.r8(0xa28968u)==0u,"1480 ordinary nonpaint global mode");
 RECT relative{},screen{};rect_relative(h,relative);need(ui::rect(h,&screen)!=0,"1480 common raw window rect");
 // First lookup/removal sees a genuine empty message map, then original
 // 5E6937 allocates a fresh16B node and publishes exact pair(msg,HWND).
 const U table=m.r32(owner),bucket=(message*hwnd)&127u;need(m.r32(table+4u*bucket)==0u,"1480 no preexisting same-message recursion guard");
 const U node=heap.allocate(16u);need(node!=0u,"1480 actual owned transient message node");
 heap.w32(node,message);heap.w32(node+4u,hwnd);heap.w8(node+8u,1u);heap.w32(node+12u,0u);
 m.w32(table+4u*bucket,node);m.w32(owner+4u,1u);insert_ratio();
 RECT client{},again{};need(ui::client(h,&client)!=0,"1480 common client rect");rect_relative(h,again);
 m.w8(0x7d2ea8u,m.r8(0xa28968u));
 const U control=lookup(m,0xa5b1a0u,hwnd,0x204u)+4u;
 need(m.r32(control+0x24u)==0u&&m.r32(0xa5b46cu)!=hwnd,"1480 coherent ordinary nonpaint route");
 // Original callback address remains in memory. Portable execution composes
 // its typed equivalent, while the original-side IAT sees literal5EBDB0.
 const LRESULT result=ui::call(&button_window_proc,h,message,w,l);
 // Actual5F9CF0 count1 head-removal: preserve producer padding9..B, free
 // the genuine owner, clear exact bucket/count, compare exactfloat0 to.2.
 const U ratio=removal_ratio();need(heap.r32(node)==message&&heap.r32(node+4u)==hwnd&&heap.r8(node+8u)==1u&&heap.r32(node+12u)==0u,"1480 genuine head identity before free");
 need(heap.release(node)==1u,"1480 actual HeapFree BOOL1");m.w32(table+4u*bucket,0u);m.w32(owner+4u,0u);remove_compare(ratio);
 return result;
}
unsigned fun_005baae0(Memory&m,const Inputs&i,Heap&h){
 auto&c=ui::context();need(&c.memory()==&m&&&c.heap()==&h&&i.arg[0]==ui::ptr(c.parent()),"1480 real parent caller");
 need(m.r8(0xa59a18u)==0&&i.arg[1]==0x111u,"1480 genuine enabled WM_COMMAND");const U id=i.arg[2]&0xffffu;const U slot=c.index_id(id);need(slot<4,"1480 selected useful checkbox ID");
 const U address=ui::Windows::globals[slot];const auto host=fp::capture_host();fp::restore_host(i.fp.image);
 try{m.w8(address,0);const U result=U(ui::send(c.parent(),int(id),0xf0u,0,0));if(result==1)m.w8(address,1);i.fp.image=fp::capture_host();fp::restore_host(host);return 0;}catch(...){fp::restore_host(host);throw;}
}
}
