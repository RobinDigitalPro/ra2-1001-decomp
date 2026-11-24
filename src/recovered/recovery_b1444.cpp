#include "recovered/recovery_b1444.hpp"
#include "platform/custom_combo1444.hpp"
#include "platform/x87_state.hpp"
#include "platform/x87_b61.hpp"
#include <array>
namespace ra2::recovered::b1444 {
namespace {using U=std::uint32_t;namespace fp=ra2::platform::x87;
void need(bool v,const char*s){ui::need(v,s);}
U lookup(Memory&m,U owner,U hwnd,U next){
 need(m.r32(owner+4)==1&&m.r32(owner+8)==128&&m.r32(owner+12)==7&&m.r32(owner+24)==0x5d6fc0,"1444 genuine one-HWND scalar hash layout");
 U node=m.r32(m.r32(owner)+(hwnd&127u)*4u);for(U k=0;k<1&&node;++k){if(m.r32(node)==hwnd)return node;node=m.r32(node+next);}throw std::domain_error("1444 actual scalar hash key absent");
}
void rect_relative(HWND window,RECT&out){
 need(ui::rect(window,&out)!=0,"1444 actual72A250 GetWindowRect success");auto&c=ui::context();RECT client{};need(ui::client(c.parent(),&client)!=0,"1444 actual parent client rect");POINT origin{client.left,client.top};need(ui::screen(c.parent(),&origin)!=0,"1444 actual ClientToScreen");out.left-=origin.x;out.right-=origin.x;out.top-=origin.y;out.bottom-=origin.y;
}
void load_unsigned(fp::State&f,U x){const std::uint64_t n=x;fp::Image host;asm volatile("fnsave %[h]\n\tfrstor %[g]\n\tfildq %[n]\n\tfnsave %[g]\n\tfrstor %[h]":[h]"=m"(host.bytes),[g]"+m"(f.image.bytes):[n]"m"(n):"memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");}
void insert_ratio(){fp::State f;f.image=fp::capture_host();load_unsigned(f,1u);f.divide_integer32(128u);f.compare_pop64(0x3fe999999999999aull);need((f.status()&0x100u)!=0u,"1444 exact1/128 below upperloadfactor");fp::restore_host(f.image);}
U removal_ratio(){fp::State f;f.image=fp::capture_host();load_unsigned(f,0u);f.divide_integer32(128u);const U ratio=f.pop32();fp::restore_host(f.image);return ratio;}
void remove_compare(U ratio){fp::State f;f.image=fp::capture_host();f.load32(ratio);f.compare_pop64(0x3fc999999999999aull);need((f.status()&0x100u)!=0u,"1444 exactzero below lowerloadfactor");fp::restore_host(f.image);}
}
unsigned configure_crt(Memory&m,const Inputs&i){if(i.arg[0]>1016u)return 0u;m.w32(0x817554u,i.arg[0]);return 1u;}
LRESULT CALLBACK common_window_proc(HWND h,UINT message,WPARAM w,LPARAM l){
 auto&c=ui::context();Memory&m=c.memory();Heap&heap=c.heap();const U hwnd=ui::ptr(h),owner=0xa5aef8u;
 need(c.child_index(h)<1&&c.valid_message(h,message,w,l),"1444 typed original common scope");
 // Actual72CB80 non-IME branches return0/RET8 on these4B2 paths.
 const U handler=lookup(m,0xa5af60u,hwnd,8u);need(m.r32(handler+4u)==0x5eac10u,"1444 authentic selected Static handler");
 (void)lookup(m,0xa5b1e8u,hwnd,8u);
 need((m.r8(0xa5dc94u)&3u)==3u&&m.r32(0xa5dc70u)==0u&&m.r32(0xa5dc74u)==0u&&m.r32(0xa5dc78u)==0u,"1444 actual warm lazy registries and empty modal vector");
 need(m.r32(owner+4u)==0u&&m.r32(owner+8u)==128u&&m.r32(owner+12u)==7u&&m.r32(owner+24u)==0x5d6fd0u&&m.r32(owner+48u)==128u,"1444 actual temporary pair-key map prestate");
 need(m.r32(owner+32u)==0x9999999au&&m.r32(owner+36u)==0x3fc99999u&&m.r32(owner+40u)==0x9999999au&&m.r32(owner+44u)==0x3fe99999u,"1444 original .2/.8 load factors");
 need(m.r8(0xa28968u)==0u,"1444 ordinary nonpaint global mode");
 RECT relative{},screen{};rect_relative(h,relative);need(ui::rect(h,&screen)!=0,"1444 common raw window rect");
 // First lookup/removal sees a genuine empty message map, then original
 // 5E6937 allocates a fresh16B node and publishes exact pair(msg,HWND).
 const U table=m.r32(owner),bucket=(message*hwnd)&127u;need(m.r32(table+4u*bucket)==0u,"1444 no preexisting same-message recursion guard");
 const U node=heap.allocate(16u);need(node!=0u,"1444 actual owned transient message node");
 heap.w32(node,message);heap.w32(node+4u,hwnd);heap.w8(node+8u,1u);heap.w32(node+12u,0u);
 m.w32(table+4u*bucket,node);m.w32(owner+4u,1u);insert_ratio();
 RECT client{},again{};need(ui::client(h,&client)!=0,"1444 common client rect");rect_relative(h,again);
 m.w8(0x7d2ea8u,m.r8(0xa28968u));
 const U control=lookup(m,0xa5b1a0u,hwnd,0x204u)+4u;
 need(m.r32(control+0x24u)==0u&&m.r32(0xa5b46cu)!=hwnd,"1444 coherent ordinary nonpaint route");
 // Original callback address remains in memory. Portable execution composes
 // its typed equivalent, while the original-side IAT sees literal5EAC10.
 if(message==0x4b2){const U old=m.r32(control+0x28),input=U(l);U length=0;while(c.input_unit(input,length)){need(++length<80,"1444 bounded produced text");}need(length==15||length==5,"1444 prior or formatted text");if(old){U k=0;while((heap.r8(old+2*k)|(heap.r8(old+2*k+1)<<8))==c.input_unit(input,k)&&c.input_unit(input,k))++k;need(c.input_unit(input,k)!=(heap.r8(old+2*k)|(heap.r8(old+2*k+1)<<8)),"1444 actual unequal old/new text");need(heap.release(old)==1,"1444 genuine oldtext free");m.w32(control+0x28,0);}const U ownertext=heap.allocate(2*length+2);need(ownertext,"1444 actual text owner");for(U k=0;k<=length;++k){const U ch=c.input_unit(input,k);heap.w8(ownertext+2*k,ch);heap.w8(ownertext+2*k+1,ch>>8);}m.w32(control+0x28,ownertext);m.w32(control+0x2c,0);need(m.r32(control+0x70)==0,"1444 real Static noIME/timer route");}
 const LRESULT result=ui::call(&static_window_proc,h,message,w,l);
 // Actual5F9CF0 count1 head-removal: preserve producer padding9..B, free
 // the genuine owner, clear exact bucket/count, compare exactfloat0 to.2.
 const U ratio=removal_ratio();need(heap.r32(node)==message&&heap.r32(node+4u)==hwnd&&heap.r8(node+8u)==1u&&heap.r32(node+12u)==0u,"1444 genuine head identity before free");
 need(heap.release(node)==1u,"1444 actual HeapFree BOOL1");m.w32(table+4u*bucket,0u);m.w32(owner+4u,0u);remove_compare(ratio);
 return result;
}
LRESULT CALLBACK static_window_proc(HWND h,UINT msg,WPARAM w,LPARAM l){auto&c=ui::context();Memory&m=c.memory();need(h==c.static_control()&&msg==0x4b2&&w==0&&c.valid_message(h,msg,w,l),"1444 actual Static4B2");const U p=lookup(m,0xa5b1a0,ui::ptr(h),0x204)+4;need(m.r32(p+0x68)==2&&m.r32(p+0x10)==0,"1444 original kind2/surfaceNULL finite route");return 1;}
unsigned construct_input(Memory&m,const Inputs&i,Heap&heap){const auto host=fp::capture_host();fp::restore_host(i.fp.image);try{const U source=i.arg[0];need(i.cx==ui::context().descriptor()&&source==ui::context().source(),"1444 genuine75B300 explicit ctor args");m.w32(i.cx,0);U length=0;while(m.r16(source+2*length)){need(++length<=5,"1444 bounded fiveUTF16 constructor input");}need(length==5,"1444 positive input");const U owner=heap.allocate(2*(length+1));need(owner,"1444 genuine constructor owner");m.w32(i.cx,owner);heap.w8(owner,0);heap.w8(owner+1,0);for(U k=0;k<=length;++k){const U ch=m.r16(source+2*k);heap.w8(owner+2*k,ch);heap.w8(owner+2*k+1,ch>>8);}i.fp.image=fp::capture_host();fp::restore_host(host);return i.cx;}catch(...){fp::restore_host(host);throw;}}
unsigned publish_prior(Memory&,const Inputs&i,Heap&){auto&c=ui::context();const auto host=fp::capture_host();fp::restore_host(i.fp.image);try{const U result=U(ui::send(c.static_control(),0x4b2,0,c.prior()));i.fp.image=fp::capture_host();fp::restore_host(host);return result;}catch(...){fp::restore_host(host);throw;}}
unsigned fun_0073ebf0(Memory&m,const Inputs&i,Heap&heap){auto&c=ui::context();need(&m==&c.memory()&&&heap==&c.heap()&&i.dx==c.descriptor()&&(i.cx==0x10||i.cx==0x20)&&(i.arg[0]&255)==0,"1444 exact truecaller finite request");const auto host=fp::capture_host();fp::restore_host(i.fp.image);try{
 const U count=m.r32(0xb0d858);need(count==1,"1444 coherent one-record existing dialog registry");U index=count-1,hwnd=0;do{if(m.r32(0xb0d634+8*index)==0xc4){hwnd=m.r32(0xb0d630+8*index);break;}--index;}while(std::int32_t(index)>=0);need(hwnd==ui::ptr(c.dialog()),"1444 actual72A500 positive realHWND result");m.w32(0xb100a8,m.r32(0xb100a8)|i.cx);
 const U input=m.r32(i.dx);need(input,"1444 actual75BDE0/75BD70 nonnull constructor owner");U length=0;while(heap.r8(input+2*length)|(heap.r8(input+2*length+1)<<8)){need(++length<=5,"1444 exact boundedUTF16strlen");}need(length==5,"1444 genuine nonempty descriptor");const HWND target=ui::get(c.dialog(),0x5b2);const U provider=U(ui::send(target,0x4b2,0,input));need(provider==1,"1444 original Static no-surface fullEAX1");const U result=(provider&0xffffff00u)|(i.arg[0]&255u);i.fp.image=fp::capture_host();fp::restore_host(host);return result;
 }catch(...){fp::restore_host(host);throw;}}
}
