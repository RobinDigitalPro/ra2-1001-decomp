#include "recovered/recovery_b1437.hpp"
#include "platform/custom_combo1437.hpp"
#include "platform/x87_state.hpp"
#include "platform/x87_b61.hpp"
#include <array>
namespace ra2::recovered::b1437 {
namespace {using U=std::uint32_t;namespace fp=ra2::platform::x87;
void need(bool v,const char*s){ui::need(v,s);}
U lookup(Memory&m,U owner,U hwnd,U next){
 need(m.r32(owner+4)==3&&m.r32(owner+8)==128&&m.r32(owner+12)==7&&m.r32(owner+24)==0x5d6fc0,"1437 genuine three-HWND scalar hash layout");
 U node=m.r32(m.r32(owner)+(hwnd&127u)*4u);for(U k=0;k<3&&node;++k){if(m.r32(node)==hwnd)return node;node=m.r32(node+next);}throw std::domain_error("1437 actual scalar hash key absent");
}
void rect_relative(HWND window,RECT&out){
 need(ui::rect(window,&out)!=0,"1437 actual72A250 GetWindowRect success");auto&c=ui::context();RECT client{};need(ui::client(c.parent(),&client)!=0,"1437 actual parent client rect");POINT origin{client.left,client.top};need(ui::screen(c.parent(),&origin)!=0,"1437 actual ClientToScreen");out.left-=origin.x;out.right-=origin.x;out.top-=origin.y;out.bottom-=origin.y;
}
void load_unsigned(fp::State&f,U x){const std::uint64_t n=x;fp::Image host;asm volatile("fnsave %[h]\n\tfrstor %[g]\n\tfildq %[n]\n\tfnsave %[g]\n\tfrstor %[h]":[h]"=m"(host.bytes),[g]"+m"(f.image.bytes):[n]"m"(n):"memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");}
void insert_ratio(){fp::State f;f.image=fp::capture_host();load_unsigned(f,1u);f.divide_integer32(128u);f.compare_pop64(0x3fe999999999999aull);need((f.status()&0x100u)!=0u,"1437 exact1/128 below upperloadfactor");fp::restore_host(f.image);}
U removal_ratio(){fp::State f;f.image=fp::capture_host();load_unsigned(f,0u);f.divide_integer32(128u);const U ratio=f.pop32();fp::restore_host(f.image);return ratio;}
void remove_compare(U ratio){fp::State f;f.image=fp::capture_host();f.load32(ratio);f.compare_pop64(0x3fc999999999999aull);need((f.status()&0x100u)!=0u,"1437 exactzero below lowerloadfactor");fp::restore_host(f.image);}
}
unsigned configure_crt(Memory&m,const Inputs&i){if(i.arg[0]>1016u)return 0u;m.w32(0x817554u,i.arg[0]);return 1u;}
LRESULT CALLBACK common_window_proc(HWND h,UINT message,WPARAM w,LPARAM l){
 auto&c=ui::context();Memory&m=c.memory();Heap&heap=c.heap();const U hwnd=ui::ptr(h),owner=0xa5aef8u;
 need(c.child_index(h)<3&&c.valid_message(h,message,w,l),"1437 typed original common scope");
 // Actual72CB80 non-IME branches return0/RET8 on these4B3/147/150 paths.
 const U handler=lookup(m,0xa5af60u,hwnd,8u);need(m.r32(handler+4u)==(h==c.edit()?0x5e99d0u:0x5ecc60u),"1437 authentic selected Edit/Combo handler");
 (void)lookup(m,0xa5b1e8u,hwnd,8u);
 need((m.r8(0xa5dc94u)&3u)==3u&&m.r32(0xa5dc70u)==0u&&m.r32(0xa5dc74u)==0u&&m.r32(0xa5dc78u)==0u,"1437 actual warm lazy registries and empty modal vector");
 need(m.r32(owner+4u)==0u&&m.r32(owner+8u)==128u&&m.r32(owner+12u)==7u&&m.r32(owner+24u)==0x5d6fd0u&&m.r32(owner+48u)==128u,"1437 actual temporary pair-key map prestate");
 need(m.r32(owner+32u)==0x9999999au&&m.r32(owner+36u)==0x3fc99999u&&m.r32(owner+40u)==0x9999999au&&m.r32(owner+44u)==0x3fe99999u,"1437 original .2/.8 load factors");
 need(m.r8(0xa28968u)==0u,"1437 ordinary nonpaint global mode");
 RECT relative{},screen{};rect_relative(h,relative);need(ui::rect(h,&screen)!=0,"1437 common raw window rect");
 // First lookup/removal sees a genuine empty message map, then original
 // 5E6937 allocates a fresh16B node and publishes exact pair(msg,HWND).
 const U table=m.r32(owner),bucket=(message*hwnd)&127u;need(m.r32(table+4u*bucket)==0u,"1437 no preexisting same-message recursion guard");
 const U node=heap.allocate(16u);need(node!=0u,"1437 actual owned transient message node");
 heap.w32(node,message);heap.w32(node+4u,hwnd);heap.w8(node+8u,1u);heap.w32(node+12u,0u);
 m.w32(table+4u*bucket,node);m.w32(owner+4u,1u);insert_ratio();
 RECT client{},again{};need(ui::client(h,&client)!=0,"1437 common client rect");rect_relative(h,again);
 m.w8(0x7d2ea8u,m.r8(0xa28968u));
 const U control=lookup(m,0xa5b1a0u,hwnd,0x204u)+4u;
 need(m.r32(control+0x24u)==0u&&m.r32(0xa5b46cu)!=hwnd,"1437 coherent ordinary nonpaint route");
 // Original callback address remains in memory. Portable execution composes
 // its typed equivalent, while the original-side IAT sees literal5E99D0 or5ECC60.
 const LRESULT result=ui::call(h==c.edit()?&edit_window_proc:&combo_window_proc,h,message,w,l);
 // Actual5F9CF0 count1 head-removal: preserve producer padding9..B, free
 // the genuine owner, clear exact bucket/count, compare exactfloat0 to.2.
 const U ratio=removal_ratio();need(heap.r32(node)==message&&heap.r32(node+4u)==hwnd&&heap.r8(node+8u)==1u&&heap.r32(node+12u)==0u,"1437 genuine head identity before free");
 need(heap.release(node)==1u,"1437 actual HeapFree BOOL1");m.w32(table+4u*bucket,0u);m.w32(owner+4u,0u);remove_compare(ratio);
 return result;
}
LRESULT CALLBACK combo_window_proc(HWND h,UINT msg,WPARAM w,LPARAM l){
 auto&c=ui::context();Memory&m=c.memory();const U hwnd=ui::ptr(h);need(h!=c.edit()&&c.valid_message(h,msg,w,l),"1437 actual read-only Combo getter route");
 const U oldnode=lookup(m,0xa5b1e8,hwnd,8);need(m.r32(oldnode+4)==ui::addr(c.os(h)),"1437 genuine oldCombo procedure");
 RECT relative{},client{},screen{};rect_relative(h,relative);need(ui::client(h,&client)&&ui::rect(h,&screen),"1437 selected Combo geometry");const U p=lookup(m,0xa5b1a0,hwnd,0x204)+4;need(m.r32(p+0x68)==3,"1437 actual Combo type3");
 if(msg==0x147)return LRESULT(m.r32(p+0xf8));
 const U node=U(ui::call(c.os(h),h,0x150,w,0));need(node==c.item(1)&&m.r32(node+12)==1,"1437 real OS returned borrowed original UTF16 node");return LRESULT(m.r32(node+4));
}
LRESULT CALLBACK edit_window_proc(HWND h,UINT msg,WPARAM w,LPARAM l){
 auto&c=ui::context();Memory&m=c.memory();Heap&heap=c.heap();need(h==c.edit()&&msg==0x4b3&&w==20,"1437 finite genuine Edit4B3 route");const U hwnd=ui::ptr(h),oldnode=lookup(m,0xa5b1e8,hwnd,8),p=lookup(m,0xa5b1a0,hwnd,0x204)+4;
 need(m.r32(oldnode+4)==ui::addr(c.os(h))&&m.r32(p+0x68)==1,"1437 actual installed Edit handler and oldproc");
 need(ui::focus()!=h,"1437 actual unfocused branch avoidsSetFocus");(void)ui::window_long(h,GWL_STYLE);
 // Original5EA1E0 count800/optional0. Only produced bytes of the private
 // buffers are observed; no arbitrary caller/dead-stack data is supplied.
 std::array<char,1024> narrow;narrow[0]=0;
 std::array<WCHAR,2048> wide;wide[0]=0;
 (void)ui::call(c.os(h),h,WM_GETTEXT,1024,reinterpret_cast<LPARAM>(narrow.data()));
 (void)ui::convert(0,0,narrow.data(),-1,wide.data(),2048);wide[2047]=0;
 U length=0;while(length<2048&&wide[length])++length;need(length==5,"1437 original fiveASCII finite line");
 const U bytes=2*length+6,node=heap.allocate(bytes);need(node,"1437 actual temporary text allocation");for(U k=0;k<bytes;++k)heap.w8(node+k,0);
 U copied=0;for(U k=0;k<length;++k){const U ch=wide[k];if(ch!=13&&ch!=10){heap.w8(node+2*copied,ch);heap.w8(node+2*copied+1,ch>>8);++copied;}}
 need(copied==length,"1437 noCRLF excludes original append helper");
 for(U k=0;;++k){const U ch=heap.r8(node+2*k)|(heap.r8(node+2*k+1)<<8);wide[k]=WCHAR(ch);if(!ch)break;}
 need(heap.release(node)==1,"1437 genuine text owner freed before return");
 // Original76EF62 count20 zero-pads the complete root40-byte output.
 auto*out=reinterpret_cast<WCHAR*>(l);bool ended=false;for(U k=0;k<20;++k){const WCHAR ch=ended?0:wide[k];out[k]=ch;if(ch==0)ended=true;}out[19]=0;
 U result=0;while(out[result])++result;return LRESULT(result);
}
unsigned fun_00593b50(Memory&m,const Inputs&i,Heap&heap){
 auto&c=ui::context();need(&c.memory()==&m&&&c.heap()==&heap&&m.r32(i.cx)==ui::ptr(c.dialog()),"1437 genuine receiver HWND");const auto host=fp::capture_host();fp::restore_host(i.fp.image);
 try{
  std::array<WCHAR,20> output;c.root_buffer(ui::ptr(output.data()));
  const HWND edit=ui::get(c.dialog(),0x5c1);need(edit==c.edit(),"1437 actual Edit child");(void)ui::send(edit,0x4b3,20,reinterpret_cast<LPARAM>(output.data()));
  // Exact6EED90 argument-1 route: lowBYTE copy, thenNUL. The preceding
  // actual OS ACP conversion is a separate operation in the Edit provider.
  U k=0;for(;output[k];++k)m.w8(0xa256d0+k,U(output[k])&255);m.w8(0xa256d0+k,0);
  const HWND palette=ui::get(c.dialog(),0x405);m.w32(0xa256e4,U(ui::send(palette,0x147,0,0)));
  const HWND registry=ui::get(c.dialog(),0x667);const U selected=U(ui::send(registry,0x147,0,0));const U result=U(ui::send(registry,0x150,selected,0));m.w32(0xa256ec,result);
  // The final4068F0 is exactlyRET, so fullEAX survives unchanged.
  i.fp.image=fp::capture_host();fp::restore_host(host);return result;
 }catch(...){fp::restore_host(host);throw;}
}
}
