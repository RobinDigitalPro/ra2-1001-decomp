#include "recovered/recovery_b1428.hpp"
#include "platform/custom_combo1428.hpp"
#include "platform/x87_state.hpp"
#include "platform/x87_b61.hpp"
#include <array>
#include "recovered/recovery_b882.hpp"
namespace ra2::recovered::b1428 {
namespace {using U=std::uint32_t;namespace fp=ra2::platform::x87;
void need(bool v,const char*s){ui::need(v,s);}
U lookup(Memory&m,U owner,U hwnd,U next){
 need(m.r32(owner+4)==2&&m.r32(owner+8)==128&&m.r32(owner+12)==7&&m.r32(owner+24)==0x5d6fc0,"1428 genuine three-HWND scalar hash layout");
 U node=m.r32(m.r32(owner)+(hwnd&127u)*4u);for(U k=0;k<2&&node;++k){if(m.r32(node)==hwnd)return node;node=m.r32(node+next);}throw std::domain_error("1428 actual scalar hash key absent");
}
void rect_relative(HWND window,RECT&out){
 need(ui::rect(window,&out)!=0,"1428 actual72A250 GetWindowRect success");auto&c=ui::context();RECT client{};need(ui::client(c.parent(),&client)!=0,"1428 actual parent client rect");POINT origin{client.left,client.top};need(ui::screen(c.parent(),&origin)!=0,"1428 actual ClientToScreen");out.left-=origin.x;out.right-=origin.x;out.top-=origin.y;out.bottom-=origin.y;
}
void load_unsigned(fp::State&f,U x){const std::uint64_t n=x;fp::Image host;asm volatile("fnsave %[h]\n\tfrstor %[g]\n\tfildq %[n]\n\tfnsave %[g]\n\tfrstor %[h]":[h]"=m"(host.bytes),[g]"+m"(f.image.bytes):[n]"m"(n):"memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");}
void insert_ratio(){fp::State f;f.image=fp::capture_host();load_unsigned(f,1u);f.divide_integer32(128u);f.compare_pop64(0x3fe999999999999aull);need((f.status()&0x100u)!=0u,"1428 exact1/128 below upperloadfactor");fp::restore_host(f.image);}
U removal_ratio(){fp::State f;f.image=fp::capture_host();load_unsigned(f,0u);f.divide_integer32(128u);const U ratio=f.pop32();fp::restore_host(f.image);return ratio;}
void remove_compare(U ratio){fp::State f;f.image=fp::capture_host();f.load32(ratio);f.compare_pop64(0x3fc999999999999aull);need((f.status()&0x100u)!=0u,"1428 exactzero below lowerloadfactor");fp::restore_host(f.image);}
}
unsigned configure_crt(Memory&m,const Inputs&i){if(i.arg[0]>1016u)return 0u;m.w32(0x817554u,i.arg[0]);return 1u;}
LRESULT CALLBACK common_window_proc(HWND h,UINT message,WPARAM w,LPARAM l){
 auto&c=ui::context();Memory&m=c.memory();Heap&heap=c.heap();const U hwnd=ui::ptr(h),owner=0xa5aef8u;
 need(c.child_index(h)<2&&c.valid_message(h,message,w,l),"1428 typed original common scope");
 // Actual72CB80 non-IME branches return0/RET8 on these147/4B2/498 paths.
 const U handler=lookup(m,0xa5af60u,hwnd,8u);need(m.r32(handler+4u)==(h==c.static_control()?0x5eac10u:0x5ecc60u),"1428 authentic selected Edit/Combo handler");
 (void)lookup(m,0xa5b1e8u,hwnd,8u);
 need((m.r8(0xa5dc94u)&3u)==3u&&m.r32(0xa5dc70u)==0u&&m.r32(0xa5dc74u)==0u&&m.r32(0xa5dc78u)==0u,"1428 actual warm lazy registries and empty modal vector");
 need(m.r32(owner+4u)==0u&&m.r32(owner+8u)==128u&&m.r32(owner+12u)==7u&&m.r32(owner+24u)==0x5d6fd0u&&m.r32(owner+48u)==128u,"1428 actual temporary pair-key map prestate");
 need(m.r32(owner+32u)==0x9999999au&&m.r32(owner+36u)==0x3fc99999u&&m.r32(owner+40u)==0x9999999au&&m.r32(owner+44u)==0x3fe99999u,"1428 original .2/.8 load factors");
 need(m.r8(0xa28968u)==0u,"1428 ordinary nonpaint global mode");
 RECT relative{},screen{};rect_relative(h,relative);need(ui::rect(h,&screen)!=0,"1428 common raw window rect");
 // First lookup/removal sees a genuine empty message map, then original
 // 5E6937 allocates a fresh16B node and publishes exact pair(msg,HWND).
 const U table=m.r32(owner),bucket=(message*hwnd)&127u;need(m.r32(table+4u*bucket)==0u,"1428 no preexisting same-message recursion guard");
 const U node=heap.allocate(16u);need(node!=0u,"1428 actual owned transient message node");
 heap.w32(node,message);heap.w32(node+4u,hwnd);heap.w8(node+8u,1u);heap.w32(node+12u,0u);
 m.w32(table+4u*bucket,node);m.w32(owner+4u,1u);insert_ratio();
 RECT client{},again{};need(ui::client(h,&client)!=0,"1428 common client rect");rect_relative(h,again);
 m.w8(0x7d2ea8u,m.r8(0xa28968u));
 const U control=lookup(m,0xa5b1a0u,hwnd,0x204u)+4u;
 need(m.r32(control+0x24u)==0u&&m.r32(0xa5b46cu)!=hwnd,"1428 coherent ordinary nonpaint route");
 // Original callback address remains in memory. Portable execution composes
 // its typed equivalent, while the original-side IAT sees literal5EAC10 or5ECC60.
 if(message==0x4b2){const U old=m.r32(control+0x28),input=U(l);U length=0;while(c.input_unit(input,length)){need(++length<80,"1428 bounded produced text");}need(length==4||length==13,"1428 prior or formatted text");if(old){U k=0;while((heap.r8(old+2*k)|(heap.r8(old+2*k+1)<<8))==c.input_unit(input,k)&&c.input_unit(input,k))++k;need(c.input_unit(input,k)!=(heap.r8(old+2*k)|(heap.r8(old+2*k+1)<<8)),"1428 actual unequal old/new text");need(heap.release(old)==1,"1428 genuine oldtext free");m.w32(control+0x28,0);}const U ownertext=heap.allocate(2*length+2);need(ownertext,"1428 actual text owner");for(U k=0;k<=length;++k){const U ch=c.input_unit(input,k);heap.w8(ownertext+2*k,ch);heap.w8(ownertext+2*k+1,ch>>8);}m.w32(control+0x28,ownertext);m.w32(control+0x2c,0);need(m.r32(control+0x70)==0,"1428 real Static noIME/timer route");}
 const LRESULT result=ui::call(h==c.static_control()?&static_window_proc:&combo_window_proc,h,message,w,l);
 // Actual5F9CF0 count1 head-removal: preserve producer padding9..B, free
 // the genuine owner, clear exact bucket/count, compare exactfloat0 to.2.
 const U ratio=removal_ratio();need(heap.r32(node)==message&&heap.r32(node+4u)==hwnd&&heap.r8(node+8u)==1u&&heap.r32(node+12u)==0u,"1428 genuine head identity before free");
 need(heap.release(node)==1u,"1428 actual HeapFree BOOL1");m.w32(table+4u*bucket,0u);m.w32(owner+4u,0u);remove_compare(ratio);
 return result;
}
LRESULT CALLBACK combo_window_proc(HWND h,UINT msg,WPARAM w,LPARAM l){auto&c=ui::context();Memory&m=c.memory();need(h==c.child(0)&&msg==0x147&&w==0&&l==0,"1428 actual selected Combo getter");const U old=lookup(m,0xa5b1e8,ui::ptr(h),8);need(m.r32(old+4)==ui::addr(c.os(h)),"1428 captured genuine Combo procedure");RECT relative{},client{},screen{};rect_relative(h,relative);need(ui::client(h,&client)&&ui::rect(h,&screen),"1428 selected Combo geometry");const U p=lookup(m,0xa5b1a0,ui::ptr(h),0x204)+4;need(m.r32(p+0x68)==3,"1428 original Combo type3");return LRESULT(m.r32(p+0xf8));}
LRESULT CALLBACK static_window_proc(HWND h,UINT msg,WPARAM w,LPARAM l){auto&c=ui::context();Memory&m=c.memory();need(h==c.static_control()&&w==0,"1428 actual Static handler");const U p=lookup(m,0xa5b1a0,ui::ptr(h),0x204)+4;need(m.r32(p+0x68)==2,"1428 original Static kind2");if(msg==0x4b2){need(m.r32(p+0x10)==0,"1428 constructor no-render-surface state");return 1;}need(msg==0x498&&U(l)!=0xffffffff,"1428 valid palette color");if(m.r32(p+0xec)!=U(l))(void)ui::invalidate(h,nullptr,FALSE);m.w32(p+0xec,U(l));return 0;}
unsigned publish_prior(Memory&,const Inputs&i,Heap&){auto&c=ui::context();const auto host=fp::capture_host();fp::restore_host(i.fp.image);try{const U result=U(ui::send(c.static_control(),0x4b2,0,c.prior()));i.fp.image=fp::capture_host();fp::restore_host(host);return result;}catch(...){fp::restore_host(host);throw;}}
unsigned fun_00593f30(Memory&m,const Inputs&i,Heap&heap){auto&c=ui::context();need(&c.memory()==&m&&&c.heap()==&heap&&m.r32(i.cx)==ui::ptr(c.dialog())&&i.arg[1]<8&&i.arg[2]==0,"1428 finite receiver/valid palette/registry entry");const auto host=fp::capture_host();fp::restore_host(i.fp.image);try{
 U k=0;for(;;++k){need(k<20,"1428 original inline20UTF16 bound");const U ch=m.r16(i.arg[0]+2*k);m.w16(i.cx+0x20+2*k,ch);if(!ch)break;}need(k==5,"1428 positive five-unit input");m.w32(i.cx+0x48,i.arg[1]);
 const HWND combo=ui::get(c.dialog(),0x405);need(U(ui::send(combo,0x147,0,0))!=i.arg[1],"1428 valid selection mismatch skips optional193E10");m.w32(i.cx+0x4c,i.arg[2]);const HWND target=ui::get(c.dialog(),0x668);
 const U item=m.r32(m.r32(0xa1e03c)+4*i.arg[2]),house=m.r32(item+0x60);need(house&&m.r16(house)=='H',"1428 genuine borrowed postINI UIName");
 // Actual76F0A4 local stream/varargs derive solely from the root's pushes.
 // These host spans have lexical lifetime; they are not GAME heap owners.
 std::array<std::uint8_t,160>out;std::array<std::uint8_t,32>stream;std::array<std::uint8_t,8>ap;
 const U output=ui::ptr(out.data()),s=ui::ptr(stream.data()),a=ui::ptr(ap.data());c.root_buffer(output);
 leaf::Memory outspan(out.data(),output,160),sspan(stream.data(),s,32),aspan(ap.data(),a,8);Memory local=m;local.add(outspan);local.add(sspan);local.add(aspan);
 local.w32(s,output);local.w32(s+4,0x7fffffff);local.w32(s+8,output);local.w32(s+12,0x42);local.w32(a,i.arg[0]);local.w32(a+4,house);
 Inputs worker=i;worker.arg[0]=s;worker.arg[1]=0x7ccb78;worker.arg[2]=a;const U result=recovery_b882::fun_00775d7e(local,worker);need(result==13&&worker.arg[1]==0x7ccb88&&worker.arg[2]==a+8,"1428 actual882 finite formatter result/cursors");
 local.w32(s+4,local.r32(s+4)-1);local.w8(local.r32(s),0);local.w32(s,local.r32(s)+1);local.w32(s+4,local.r32(s+4)-1);local.w8(local.r32(s),0);need(local.r32(s)==output+27&&local.r32(s+4)==0x7fffffe3,"1428 authentic wrapper two-byte terminator");
 (void)ui::send(target,0x4b2,0,LPARAM(output));const U value=U(ui::send(target,0x498,0,m.r32(0x7d1178+4*i.arg[1])));i.fp.image=fp::capture_host();fp::restore_host(host);return value;
 }catch(...){fp::restore_host(host);throw;}}
}
