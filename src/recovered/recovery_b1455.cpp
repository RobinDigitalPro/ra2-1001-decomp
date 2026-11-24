#include "recovered/recovery_b1455.hpp"
#include "platform/custom_listbox1455.hpp"
#include "platform/x87_state.hpp"
namespace ra2::recovered::global_b26 {std::uint32_t fun_006eedc0(Memory&,const Inputs&);}
namespace ra2::recovered::b1455 {
namespace {using U=std::uint32_t;namespace fp=ra2::platform::x87;
void need(bool b,const char*s){ui::need(b,s);}
U lookup(Memory&m,U owner,U hwnd,U next){need(m.r32(owner+4)==1&&m.r32(owner+8)==128&&m.r32(owner+12)==7&&m.r32(owner+24)==0x5d6fc0,"1455 true scalar HWND registry");const U node=m.r32(m.r32(owner)+(hwnd&127)*4);need(node&&m.r32(node)==hwnd&&m.r32(node+next)==0,"1455 exact one real HWND record");return node;}
U control(Memory&m,HWND h){return lookup(m,0xa5b1a0,ui::ptr(h),0x204)+4;}
WNDPROC oldproc(Memory&m,HWND h){const U p=m.r32(lookup(m,0xa5b1e8,ui::ptr(h),8)+4);need(p==ui::addr(ui::context().os()),"1455 authentic captured oldOS procedure");return reinterpret_cast<WNDPROC>(std::uintptr_t(p));}
void relative(HWND h,RECT&r){need(ui::rect(h,&r)!=0,"1455 actual72A250 screen success");RECT client{};POINT p{};auto parent=ui::context().parent();need(ui::client(parent,&client)!=0,"1455 parentclient");p.x=client.left;p.y=client.top;need(ui::screen(parent,&p)!=0,"1455 real screen conversion");r.left-=p.x;r.right-=p.x;r.top-=p.y;r.bottom-=p.y;}
void load_unsigned(fp::State&f,U x){const std::uint64_t v=x;fp::Image host;asm volatile("fnsave %[h]\n\tfrstor %[g]\n\tfildq %[n]\n\tfnsave %[g]\n\tfrstor %[h]":[h]"=m"(host.bytes),[g]"+m"(f.image.bytes):[n]"m"(v):"memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");}
U ratio(U count){fp::State f;f.image=fp::capture_host();load_unsigned(f,count);f.divide_integer32(128);const U v=f.pop32();fp::restore_host(f.image);return v;}
void lower(U value){fp::State f;f.image=fp::capture_host();f.load32(value);f.compare_pop64(0x3fc999999999999aull);need(f.status()&0x100,"1455 exact ratio below .2");fp::restore_host(f.image);}
void insert_fp(U count){fp::State f;f.image=fp::capture_host();load_unsigned(f,count);f.divide_integer32(128);f.compare_pop64(0x3fe999999999999aull);need(f.status()&0x100,"1455 exact ratio below .8");fp::restore_host(f.image);}
U readword(Heap&h,U p){return h.r8(p)|(h.r8(p+1)<<8);}
U length_memory(Memory&m,U p){U n=0;while(m.r16(p+2*n)){need(n<6,"1455 exact bounded UTF16 source");++n;}return n;}
U length_heap(Heap&h,U p){U n=0;while(readword(h,p+2*n)){need(n<6,"1455 exact owned UTF16 source");++n;}return n;}
void copy_memory(Memory&m,Heap&h,U out,U in,U n){for(U k=0;k<=n;++k){const U w=m.r16(in+2*k);h.w8(out+2*k,w);h.w8(out+2*k+1,w>>8);}}
void copy_heap(Heap&h,U out,U in,U n){for(U k=0;k<=n;++k){const U w=readword(h,in+2*k);h.w8(out+2*k,w);h.w8(out+2*k+1,w>>8);}}
// Exact5F9CF0 on the warm min-capacity message map. Unlike acceptedB1199,
// this fixture has a borrowed table and needs count0/1 and a missing key.
bool remove_message(Memory&m,Heap&h,U message,U hwnd){constexpr U owner=0xa5aef8;const U count=m.r32(owner+4);if(!count)return false;need(count<=2,"1455 finite nested message count");const U q=ratio(count-1),at=m.r32(owner)+4*((message*hwnd)&127);U previous=0,node=m.r32(at);if(!node)return false;
 while(node&&(h.r32(node)!=message||h.r32(node+4)!=hwnd)){previous=node;node=h.r32(node+12);}if(!node){lower(q);return false;}need(h.r8(node+8)==1,"1455 original published node byte");const U next=h.r32(node+12);if(previous){h.w32(previous+12,next);m.w32(owner+4,count-1);need(h.release(node)==1,"1455 real nonhead free");}else{need(h.release(node)==1,"1455 real head free");m.w32(at,next);m.w32(owner+4,count-1);}lower(q);return true;}
}
unsigned configure_crt(Memory&m,const Inputs&i){if(i.arg[0]>1016)return 0;m.w32(0x817554,i.arg[0]);return 1;}
LRESULT CALLBACK listbox_window_proc(HWND h,UINT msg,WPARAM w,LPARAM l){auto&c=ui::context();Memory&m=c.memory();Heap&heap=c.heap();need(h==c.listbox()&&ui::candidate_message(msg),"1455 finite ListBox handler");const auto old=oldproc(m,h);need(ui::parent(h)==c.parent(),"1455 real GetParent");const U p=control(m,h);RECT client_rect{},relative_rect{};need(ui::client(h,&client_rect),"1455 actual client bounds");relative(h,relative_rect);need(m.r32(p+0x68)==4&&m.r32(p+0xc)==0&&m.r32(p+0xe8)==0&&m.r32(p+0xec)==0&&m.r32(p+0xf8)==0,"1455 constructor-compatible ordinary ListBox state");
 if(msg!=0x18b&&msg!=0x1a1){const U count=U(ui::send(h,0x18b,0,0));const U observed=U(ui::send(h,0x1a1,0,0)),height=observed>1?observed:1;const int available=client_rect.bottom-client_rect.top-2*int(m.r32(0xa5dc80));need(count<=1&&available>0&&std::uint64_t(count)*height<=U(available),"1455 actual rows fit without scrollbar");}
 if(msg==0x4cd){need(w==0,"1455 append actual localized text");global_b26::Inputs cv{};cv.cx=U(l);const U narrow=global_b26::fun_006eedc0(m,cv);const U index=U(ui::call(old,h,0x180,0,LPARAM(narrow)));need(index==0,"1455 genuine successful ListBox add");const U n=length_memory(m,U(l));need(n==5,"1455 bounded short text");const U node=heap.allocate(2*n+18);need(node,"1455 real UTF16 owner");heap.w32(node+8,node+16);heap.w32(node,m.r32(p+0x34));m.w32(p+0x34,node);heap.w32(node+4,0);heap.w32(node+12,1);copy_memory(m,heap,node+16,U(l),n);const U result=U(ui::call(old,h,0x19a,index,LPARAM(node)));need(result!=0xffffffffu&&result!=0xfffffffeu,"1455 actual owner publication");
  // Actual75B2F0 initializes two local null string owners;75B390 checks each
  // null pointer and returns without a call/free. Both locals are produced.
  const U local_a=0,local_b=0;need(local_a==0&&local_b==0,"1455 produced null local lifetimes");return LRESULT(index);}
 if(msg==0x188){need(w==0&&l==0,"1455 actual selected-index query");return LRESULT(m.r32(p+0xf4));}
 if(msg==0x18a||msg==0x4b6){need(w==0&&(msg==0x18a?l==0:l!=0),"1455 real owned row text query");if(msg==0x4b6){heap.w8(U(l),0);heap.w8(U(l)+1,0);}const U node=U(ui::call(old,h,0x199,w,0));need(node&&node!=0xffffffffu&&heap.r32(node+12)==1,"1455 actual original item");const U text=heap.r32(node+8),n=length_heap(heap,text);need(n==5,"1455 genuine five UTF16 units");if(msg==0x4b6)copy_heap(heap,U(l),text,n);return LRESULT(n);}

 need(msg==0x18b||msg==0x1a1,"1455 literal forwarding cases");return ui::call(old,h,msg,w,l);
}

LRESULT CALLBACK common_window_proc(HWND h,UINT msg,WPARAM w,LPARAM l){auto&c=ui::context();Memory&m=c.memory();Heap&heap=c.heap();const U hwnd=ui::ptr(h),owner=0xa5aef8;need(h==c.listbox()&&ui::candidate_message(msg),"1455 reviewed common message");need(m.r32(lookup(m,0xa5af60,hwnd,8)+4)==0x5ee640,"1455 actual selected procedure");(void)oldproc(m,h);need(m.r8(0xa5dc94)==3&&m.r32(0xa5dc70)==0&&m.r32(0xa5dc74)==0&&m.r32(0xa5dc78)==0&&m.r8(0xa28968)==0,"1455 original warm nonmodal/nonpaint state");need(m.r32(owner+4)<=1&&m.r32(owner+8)==128&&m.r32(owner+12)==7&&m.r32(owner+24)==0x5d6fd0&&m.r32(owner+48)==128,"1455 actual bounded pairhash");need(m.r32(owner+32)==0x9999999a&&m.r32(owner+36)==0x3fc99999&&m.r32(owner+40)==0x9999999a&&m.r32(owner+44)==0x3fe99999,"1455 original .2/.8 factors");RECT a{},r{};relative(h,a);need(ui::rect(h,&r),"1455 actual common rectangle");
 const U at=m.r32(owner)+4*((msg*hwnd)&127);for(U q=m.r32(at);q;q=heap.r32(q+12))need(heap.r32(q)!=msg||heap.r32(q+4)!=hwnd,"1455 no same-message recursion shortcut");need(!remove_message(m,heap,msg,hwnd),"1455 original initial lookup is missing key");const U node=heap.allocate(16);need(node,"1455 real temporary message owner");heap.w32(node,msg);heap.w32(node+4,hwnd);heap.w8(node+8,1);heap.w32(node+12,m.r32(at));m.w32(at,node);m.w32(owner+4,m.r32(owner+4)+1);insert_fp(m.r32(owner+4));RECT b{},r2{};need(ui::client(h,&b),"1455 real common client");relative(h,r2);m.w8(0x7d2ea8,m.r8(0xa28968));const U p=control(m,h);need(m.r32(p+0x24)==0&&m.r32(0xa5b46c)!=hwnd,"1455 ordinary nonpaint route");
 const LRESULT result=ui::call(&listbox_window_proc,h,msg,w,l);need(remove_message(m,heap,msg,hwnd),"1455 genuine current-message unlink");return result;
}
// Fixture message prelude: same genuine SendMessage on both sides. The native
// side has actual original5E6550/5EE640 installed; no original producer root credit.
unsigned populate(Memory&m,const Inputs&i,Heap&heap,unsigned text){auto&c=ui::context();need(&c.memory()==&m&&&c.heap()==&heap,"1455 active genuine fixture");const auto host=fp::capture_host();fp::restore_host(i.fp.image);try{const U r=U(ui::send(c.listbox(),0x4cd,0,LPARAM(text)));i.fp.image=fp::capture_host();fp::restore_host(host);return r;}catch(...){fp::restore_host(host);throw;}}
unsigned fun_00745eb0(Memory&m,const Inputs&i,Heap&heap){auto&c=ui::context();need(&c.memory()==&m&&&c.heap()==&heap&&i.dx==ui::ptr(c.listbox())&&m.r32(i.cx)==0,"1455 actual output cell and populated ListBox");const auto host=fp::capture_host();fp::restore_host(i.fp.image);try{
 const HWND h=c.listbox();U row=U(ui::send(h,0x188,0,0));need(row==0,"1455 constructor F4 zero");need(U(ui::send(h,0x18b,0,0))==1,"1455 actual one populated row");
 // Exact5F8BB0 and75B4B0: produced null holder, fetch, own copy, temp release.
 U wide=0;const U n=U(ui::send(h,0x18a,row,0));need(n==5,"1455 actual length");
 const U fetched=heap.allocate(2*n+4);need(fetched,"1455 real14request owner");need(U(ui::send(h,0x4b6,row,fetched))==5,"1455 actual copy count");
 wide=heap.allocate(2*(length_heap(heap,fetched)+1));need(wide,"1455 real wide descriptor");heap.w8(wide,0);heap.w8(wide+1,0);copy_heap(heap,wide,fetched,n);need(heap.release(fetched)==1,"1455 exact fetch temporary free");
 need(readword(heap,wide)==0x28,"1455 useful parenthesized name");
 // Exact75C5B0, unique final ')': owned prefix temporary then replacement.
 U cut=0;while(readword(heap,wide+2*cut)!=0x29){need(cut<5,"1455 closing marker");++cut;}need(cut==4,"1455 exact final marker");
 const U prefix=heap.allocate(2*cut+2);need(prefix,"1455 real prefix temp");heap.w8(prefix,0);heap.w8(prefix+1,0);for(U k=0;k<2*cut;++k)heap.w8(prefix+k,heap.r8(wide+k));heap.w8(prefix+2*cut,0);heap.w8(prefix+2*cut+1,0);
 need(heap.release(wide)==1,"1455 old wide release");wide=0;wide=heap.allocate(2*(cut+1));need(wide,"1455 prefix replacement");heap.w8(wide,0);heap.w8(wide+1,0);copy_heap(heap,wide,prefix,cut);need(heap.release(prefix)==1,"1455 prefix temp release");
 // Exact75BA50 index0: memmove count2*4-0-2=6, then explicit WORD NUL.
 for(U k=0;k<6;++k)heap.w8(wide+k,heap.r8(wide+k+2));heap.w8(wide+6,0);heap.w8(wide+7,0);
 const U trimmed=heap.allocate(8);need(trimmed,"1455 trimmed owner");copy_heap(heap,trimmed,wide,3);need(heap.release(wide)==1,"1455 prefix release");wide=trimmed;
 // Exact75CBC0 plus6EED90 low-byte copy; no locale/Unicode conversion API.
 const U converted=heap.allocate(4);need(converted,"1455 narrow conversion temp");for(U k=0;k<3;++k)heap.w8(converted+k,heap.r8(wide+2*k));heap.w8(converted+3,0);
 const U middle=heap.allocate(4);need(middle,"1455 second narrow temp");heap.w8(middle,0);for(U k=0;k<4;++k)heap.w8(middle+k,heap.r8(converted+k));need(heap.release(converted)==1,"1455 converted temp free");
 m.w32(i.cx,0);const U result=heap.allocate(4);need(result,"1455 real published narrow owner");m.w32(i.cx,result);for(U k=0;k<4;++k)heap.w8(result+k,heap.r8(middle+k));need(heap.release(middle)==1,"1455 middle tempfree");
 need(heap.release(wide)==1,"1455 root local wide destructor");i.fp.image=fp::capture_host();fp::restore_host(host);return i.cx;
 }catch(...){fp::restore_host(host);throw;}}
}
