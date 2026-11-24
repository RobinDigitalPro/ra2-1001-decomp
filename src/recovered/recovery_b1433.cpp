#include "recovered/recovery_b1433.hpp"
#include "platform/custom_listbox1433.hpp"
#include "platform/x87_state.hpp"
namespace ra2::recovered::global_b26 {std::uint32_t fun_006eedc0(Memory&,const Inputs&);}
namespace ra2::recovered::b1433 {
namespace {using U=std::uint32_t;namespace fp=ra2::platform::x87;
void need(bool b,const char*s){ui::need(b,s);}
U lookup(Memory&m,U owner,U hwnd,U next){need(m.r32(owner+4)==1&&m.r32(owner+8)==128&&m.r32(owner+12)==7&&m.r32(owner+24)==0x5d6fc0,"1433 true scalar HWND registry");const U node=m.r32(m.r32(owner)+(hwnd&127)*4);need(node&&m.r32(node)==hwnd&&m.r32(node+next)==0,"1433 exact one real HWND record");return node;}
U control(Memory&m,HWND h){return lookup(m,0xa5b1a0,ui::ptr(h),0x204)+4;}
WNDPROC oldproc(Memory&m,HWND h){const U p=m.r32(lookup(m,0xa5b1e8,ui::ptr(h),8)+4);need(p==ui::addr(ui::context().os()),"1433 authentic captured oldOS procedure");return reinterpret_cast<WNDPROC>(std::uintptr_t(p));}
void relative(HWND h,RECT&r){need(ui::rect(h,&r)!=0,"1433 actual72A250 screen success");RECT client{};POINT p{};auto parent=ui::context().parent();need(ui::client(parent,&client)!=0,"1433 parentclient");p.x=client.left;p.y=client.top;need(ui::screen(parent,&p)!=0,"1433 real screen conversion");r.left-=p.x;r.right-=p.x;r.top-=p.y;r.bottom-=p.y;}
void load_unsigned(fp::State&f,U x){const std::uint64_t v=x;fp::Image host;asm volatile("fnsave %[h]\n\tfrstor %[g]\n\tfildq %[n]\n\tfnsave %[g]\n\tfrstor %[h]":[h]"=m"(host.bytes),[g]"+m"(f.image.bytes):[n]"m"(v):"memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");}
U ratio(U count){fp::State f;f.image=fp::capture_host();load_unsigned(f,count);f.divide_integer32(128);const U v=f.pop32();fp::restore_host(f.image);return v;}
void lower(U value){fp::State f;f.image=fp::capture_host();f.load32(value);f.compare_pop64(0x3fc999999999999aull);need(f.status()&0x100,"1433 exact ratio below .2");fp::restore_host(f.image);}
void insert_fp(U count){fp::State f;f.image=fp::capture_host();load_unsigned(f,count);f.divide_integer32(128);f.compare_pop64(0x3fe999999999999aull);need(f.status()&0x100,"1433 exact ratio below .8");fp::restore_host(f.image);}
U readword(Heap&h,U p){return h.r8(p)|(h.r8(p+1)<<8);}
U length_memory(Memory&m,U p){U n=0;while(m.r16(p+2*n)){need(n<6,"1433 exact bounded UTF16 source");++n;}return n;}
U length_heap(Heap&h,U p){U n=0;while(readword(h,p+2*n)){need(n<6,"1433 exact owned UTF16 source");++n;}return n;}
void copy_memory(Memory&m,Heap&h,U out,U in,U n){for(U k=0;k<=n;++k){const U w=m.r16(in+2*k);h.w8(out+2*k,w);h.w8(out+2*k+1,w>>8);}}
void copy_heap(Heap&h,U out,U in,U n){for(U k=0;k<=n;++k){const U w=readword(h,in+2*k);h.w8(out+2*k,w);h.w8(out+2*k+1,w>>8);}}
// Exact5F9CF0 on the warm min-capacity message map. Unlike acceptedB1199,
// this fixture has a borrowed table and needs count0/1 and a missing key.
bool remove_message(Memory&m,Heap&h,U message,U hwnd){constexpr U owner=0xa5aef8;const U count=m.r32(owner+4);if(!count)return false;need(count<=2,"1433 finite nested message count");const U q=ratio(count-1),at=m.r32(owner)+4*((message*hwnd)&127);U previous=0,node=m.r32(at);if(!node)return false;
 while(node&&(h.r32(node)!=message||h.r32(node+4)!=hwnd)){previous=node;node=h.r32(node+12);}if(!node){lower(q);return false;}need(h.r8(node+8)==1,"1433 original published node byte");const U next=h.r32(node+12);if(previous){h.w32(previous+12,next);m.w32(owner+4,count-1);need(h.release(node)==1,"1433 real nonhead free");}else{need(h.release(node)==1,"1433 real head free");m.w32(at,next);m.w32(owner+4,count-1);}lower(q);return true;}
}
unsigned configure_crt(Memory&m,const Inputs&i){if(i.arg[0]>1016)return 0;m.w32(0x817554,i.arg[0]);return 1;}
LRESULT CALLBACK listbox_window_proc(HWND h,UINT msg,WPARAM w,LPARAM l){auto&c=ui::context();Memory&m=c.memory();Heap&heap=c.heap();need(h==c.listbox()&&ui::candidate_message(msg),"1433 finite ListBox handler");const auto old=oldproc(m,h);need(ui::parent(h)==c.parent(),"1433 real GetParent");const U p=control(m,h);RECT client_rect{},relative_rect{};need(ui::client(h,&client_rect),"1433 actual client bounds");relative(h,relative_rect);need(m.r32(p+0x68)==4&&m.r32(p+0xc)==0&&m.r32(p+0xe8)==0&&m.r32(p+0xec)==0&&m.r32(p+0xf8)==0,"1433 constructor-compatible ordinary ListBox state");
 if(msg!=0x18b&&msg!=0x1a1){const U count=U(ui::send(h,0x18b,0,0));const U observed=U(ui::send(h,0x1a1,0,0)),height=observed>1?observed:1;const int available=client_rect.bottom-client_rect.top-2*int(m.r32(0xa5dc80));need(count<=1&&available>0&&std::uint64_t(count)*height<=U(available),"1433 actual rows fit without scrollbar");}
 if(msg==0x4cd){need(w==0,"1433 append actual localized text");global_b26::Inputs cv{};cv.cx=U(l);const U narrow=global_b26::fun_006eedc0(m,cv);const U index=U(ui::call(old,h,0x180,0,LPARAM(narrow)));need(index==0,"1433 genuine successful ListBox add");const U n=length_memory(m,U(l));need(n==5,"1433 bounded short text");const U node=heap.allocate(2*n+18);need(node,"1433 real UTF16 owner");heap.w32(node+8,node+16);heap.w32(node,m.r32(p+0x34));m.w32(p+0x34,node);heap.w32(node+4,0);heap.w32(node+12,1);copy_memory(m,heap,node+16,U(l),n);const U result=U(ui::call(old,h,0x19a,index,LPARAM(node)));need(result!=0xffffffffu&&result!=0xfffffffeu,"1433 actual owner publication");
  // Actual75B2F0 initializes two local null string owners;75B390 checks each
  // null pointer and returns without a call/free. Both locals are produced.
  const U local_a=0,local_b=0;need(local_a==0&&local_b==0,"1433 produced null local lifetimes");return LRESULT(index);}
 if(msg==0x197){const int count=int(ui::send(h,0x18b,0,0)),height=int(ui::send(h,0x1a1,0,0));need(count==1&&height>0,"1433 actual extra topindex queries");const int available=client_rect.bottom-client_rect.top-2*int(m.r32(0xa5dc80));const int limit=count-available/height;int top=int(U(w));if(top<0)top=0;if(limit>0){if(top>limit)top=limit;}else top=0;need(top==int(m.r32(p+0xf0)),"1433 actual equal-top noinvalidate branch");return 0;}
 if(msg==0x49d){need(w==0&&(U(l)==0||U(l)==1),"1433 real49D observed bounds");return ui::call(old,h,msg,w,l);}

 need(msg==0x18b||msg==0x1a1,"1433 literal forwarding cases");return ui::call(old,h,msg,w,l);
}

LRESULT CALLBACK common_window_proc(HWND h,UINT msg,WPARAM w,LPARAM l){auto&c=ui::context();Memory&m=c.memory();Heap&heap=c.heap();const U hwnd=ui::ptr(h),owner=0xa5aef8;need(h==c.listbox()&&ui::candidate_message(msg),"1433 reviewed common message");need(m.r32(lookup(m,0xa5af60,hwnd,8)+4)==0x5ee640,"1433 actual selected procedure");(void)oldproc(m,h);need(m.r8(0xa5dc94)==3&&m.r32(0xa5dc70)==0&&m.r32(0xa5dc74)==0&&m.r32(0xa5dc78)==0&&m.r8(0xa28968)==0,"1433 original warm nonmodal/nonpaint state");need(m.r32(owner+4)<=1&&m.r32(owner+8)==128&&m.r32(owner+12)==7&&m.r32(owner+24)==0x5d6fd0&&m.r32(owner+48)==128,"1433 actual bounded pairhash");need(m.r32(owner+32)==0x9999999a&&m.r32(owner+36)==0x3fc99999&&m.r32(owner+40)==0x9999999a&&m.r32(owner+44)==0x3fe99999,"1433 original .2/.8 factors");RECT a{},r{};relative(h,a);need(ui::rect(h,&r),"1433 actual common rectangle");
 const U at=m.r32(owner)+4*((msg*hwnd)&127);for(U q=m.r32(at);q;q=heap.r32(q+12))need(heap.r32(q)!=msg||heap.r32(q+4)!=hwnd,"1433 no same-message recursion shortcut");need(!remove_message(m,heap,msg,hwnd),"1433 original initial lookup is missing key");const U node=heap.allocate(16);need(node,"1433 real temporary message owner");heap.w32(node,msg);heap.w32(node+4,hwnd);heap.w8(node+8,1);heap.w32(node+12,m.r32(at));m.w32(at,node);m.w32(owner+4,m.r32(owner+4)+1);insert_fp(m.r32(owner+4));RECT b{},r2{};need(ui::client(h,&b),"1433 real common client");relative(h,r2);m.w8(0x7d2ea8,m.r8(0xa28968));const U p=control(m,h);need(m.r32(p+0x24)==0&&m.r32(0xa5b46c)!=hwnd,"1433 ordinary nonpaint route");
 if(msg==0x49d){const U previous=m.r32(p+0x20);(void)previous;m.w32(p+0x20,U(l));need(m.r32(p+0xc)==0,"1433 actual49D no scrollbar child; selected forwarding still mandatory");}
 const LRESULT result=ui::call(&listbox_window_proc,h,msg,w,l);need(remove_message(m,heap,msg,hwnd),"1433 genuine current-message unlink");return result;
}
// Actual1BDAB0 finite caller-produced default-color route. Copy/search helpers
// retain original counted-copy and CR-before-LF behavior; no formatter.
unsigned fun_005bdab0(Memory&m,const Inputs&i,Heap&heap){auto&c=ui::context();need(&c.memory()==&m&&&c.heap()==&heap&&i.cx==ui::ptr(c.listbox())&&i.arg[0]>=5&&i.arg[0]<=7&&i.arg[1]==0xffffffffu,"1433 genuine caller HWND/text/count/defaultcolor");const auto host=fp::capture_host();fp::restore_host(i.fp.image);try{
 constexpr U out=0xa59a28;for(U k=0;k<256;++k)m.w32(out+4*k,0);
 // Original76EF62: copy exactly count WORDs, zero-padding if source terminates.
 bool ended=false;for(U k=0;k<i.arg[0];++k){const U v=ended?0:m.r16(i.dx+2*k);m.w16(out+2*k,v);if(!v)ended=true;}
 auto find=[&](U ch){for(U at=out;;at+=2){const U v=m.r16(at);if(v==ch)return at;if(!v)return U(0);}};
 U cut=find(13);if(!cut)cut=find(10);if(cut)m.w16(cut,0);
 const HWND h=c.listbox();const U previous=U(ui::send(h,0x49d,0,1));const U count=U(ui::send(h,0x18b,0,0));need(count==0,"1433 actual empty collection excludes eviction");(void)ui::send(h,0x4cd,0,out);(void)ui::send(h,0x197,count,0);const U result=U(ui::send(h,0x49d,0,previous));i.fp.image=fp::capture_host();fp::restore_host(host);return result;
 }catch(...){fp::restore_host(host);throw;}}
}
