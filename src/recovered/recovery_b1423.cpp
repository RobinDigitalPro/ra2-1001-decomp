#include "recovered/recovery_b1423.hpp"
#include "platform/custom_combo1423.hpp"
#include "platform/x87_state.hpp"
namespace ra2::recovered::global_b26 {std::uint32_t fun_006eedc0(Memory&,const Inputs&);}
namespace ra2::recovered::b1423 {
namespace {using U=std::uint32_t;namespace fp=ra2::platform::x87;
void need(bool b,const char*s){ui::need(b,s);}
U lookup(Memory&m,U owner,U hwnd,U next){need(m.r32(owner+4)==1&&m.r32(owner+8)==128&&m.r32(owner+12)==7&&m.r32(owner+24)==0x5d6fc0,"1423 true scalar HWND registry");const U node=m.r32(m.r32(owner)+(hwnd&127)*4);need(node&&m.r32(node)==hwnd&&m.r32(node+next)==0,"1423 exact one real HWND record");return node;}
U control(Memory&m,HWND h){return lookup(m,0xa5b1a0,ui::ptr(h),0x204)+4;}
WNDPROC oldproc(Memory&m,HWND h){const U p=m.r32(lookup(m,0xa5b1e8,ui::ptr(h),8)+4);need(p==ui::addr(ui::context().os()),"1423 authentic captured oldOS procedure");return reinterpret_cast<WNDPROC>(std::uintptr_t(p));}
void relative(HWND h,RECT&r){need(ui::rect(h,&r)!=0,"1423 actual72A250 screen success");RECT client{};POINT p{};auto parent=ui::context().parent();need(ui::client(parent,&client)!=0,"1423 parentclient");p.x=client.left;p.y=client.top;need(ui::screen(parent,&p)!=0,"1423 real screen conversion");r.left-=p.x;r.right-=p.x;r.top-=p.y;r.bottom-=p.y;}
void load_unsigned(fp::State&f,U x){const std::uint64_t v=x;fp::Image host;asm volatile("fnsave %[h]\n\tfrstor %[g]\n\tfildq %[n]\n\tfnsave %[g]\n\tfrstor %[h]":[h]"=m"(host.bytes),[g]"+m"(f.image.bytes):[n]"m"(v):"memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");}
U ratio(U count){fp::State f;f.image=fp::capture_host();load_unsigned(f,count);f.divide_integer32(128);const U v=f.pop32();fp::restore_host(f.image);return v;}
void lower(U value){fp::State f;f.image=fp::capture_host();f.load32(value);f.compare_pop64(0x3fc999999999999aull);need(f.status()&0x100,"1423 exact ratio below .2");fp::restore_host(f.image);}
void insert_fp(U count){fp::State f;f.image=fp::capture_host();load_unsigned(f,count);f.divide_integer32(128);f.compare_pop64(0x3fe999999999999aull);need(f.status()&0x100,"1423 exact ratio below .8");fp::restore_host(f.image);}
U readword(Heap&h,U p){return h.r8(p)|(h.r8(p+1)<<8);}
U length_memory(Memory&m,U p){U n=0;while(m.r16(p+2*n)){need(n<6,"1423 exact bounded UTF16 source");++n;}return n;}
U length_heap(Heap&h,U p){U n=0;while(readword(h,p+2*n)){need(n<6,"1423 exact owned UTF16 source");++n;}return n;}
void copy_memory(Memory&m,Heap&h,U out,U in,U n){for(U k=0;k<=n;++k){const U w=m.r16(in+2*k);h.w8(out+2*k,w);h.w8(out+2*k+1,w>>8);}}
void copy_heap(Heap&h,U out,U in,U n){for(U k=0;k<=n;++k){const U w=readword(h,in+2*k);h.w8(out+2*k,w);h.w8(out+2*k+1,w>>8);}}
// Exact5F9CF0 on the warm min-capacity message map. Unlike acceptedB1199,
// this fixture has a borrowed table and needs count0/1 and a missing key.
bool remove_message(Memory&m,Heap&h,U message,U hwnd){constexpr U owner=0xa5aef8;const U count=m.r32(owner+4);if(!count)return false;need(count<=2,"1423 finite nested message count");const U q=ratio(count-1),at=m.r32(owner)+4*((message*hwnd)&127);U previous=0,node=m.r32(at);if(!node)return false;
 while(node&&(h.r32(node)!=message||h.r32(node+4)!=hwnd)){previous=node;node=h.r32(node+12);}if(!node){lower(q);return false;}need(h.r8(node+8)==1,"1423 original published node byte");const U next=h.r32(node+12);if(previous){h.w32(previous+12,next);m.w32(owner+4,count-1);need(h.release(node)==1,"1423 real nonhead free");}else{need(h.release(node)==1,"1423 real head free");m.w32(at,next);m.w32(owner+4,count-1);}lower(q);return true;}
}
unsigned configure_crt(Memory&m,const Inputs&i){if(i.arg[0]>1016)return 0;m.w32(0x817554,i.arg[0]);return 1;}
LRESULT CALLBACK combo_window_proc(HWND h,UINT msg,WPARAM w,LPARAM l){auto&c=ui::context();Memory&m=c.memory();Heap&heap=c.heap();need(h==c.combo()&&ui::candidate_message(msg),"1423 bounded original selected handler");const auto old=oldproc(m,h);RECT a{},b{},r{};relative(h,a);need(ui::client(h,&b)&&ui::rect(h,&r),"1423 actual handler geometry");const U p=control(m,h);need(m.r32(p+0x68)==3,"1423 actual ComboBox type3");
 if(msg==0x4c2){need(w==0,"1423 append House5");global_b26::Inputs convert{};convert.cx=U(l);const U narrow=global_b26::fun_006eedc0(m,convert);const U index=U(ui::call(old,h,0x143,0,LPARAM(narrow)));need(index==0,"1423 real successful OS addstring");const U n=length_memory(m,U(l)),node=heap.allocate(2*n+18);need(node,"1423 real original item allocation");heap.w32(node+8,node+16);heap.w32(node,m.r32(p+0x34));heap.w32(node+4,0);m.w32(p+0x34,node);heap.w32(node+12,1);copy_memory(m,heap,node+16,U(l),n);const U result=U(ui::call(old,h,0x151,index,LPARAM(node)));need(result!=0xffffffffu&&result!=0xfffffffeu,"1423 actual OS itemdata publication");return LRESULT(index);}
 if(msg==0x150||msg==0x151){const U node=U(ui::call(old,h,0x150,w,0));if(node==0xffffffffu||node==0)return LRESULT(0xffffffffu);need(w==0,"1423 real valid owned row");if(msg==0x150)return LRESULT(heap.r32(node+4));heap.w32(node+4,U(l));return LRESULT(node);}
 if(msg==0x14e){need(w==0&&l==0,"1423 actual finite selection");m.w32(p+0xf8,U(w));const U node=U(ui::call(old,h,0x150,w,0));need(node&&node!=0xffffffffu&&heap.r32(node+12)==1,"1423 selected genuine UTF16 item");(void)ui::send(h,0x4b2,0,LPARAM(heap.r32(node+8)));const U style=U(ui::window_long(h,GWL_STYLE));need((style&3)==3,"1423 actual dropdownlist style");(void)ui::invalidate(h,nullptr,FALSE);return ui::call(oldproc(m,h),h,msg,w,l);}
 //14B starts with a genuinely empty owned list;146 and4B2 take original
 //default dispatch to the genuine captured OS procedure.
 if(msg==0x14b)need(m.r32(p+0x34)==0&&m.r32(p+0x28)==0,"1423 original empty reset ownership");if(msg==0x4b2){const U style=U(ui::window_long(h,GWL_STYLE));need((style&3)==3,"1423 actual5EE19C label style query");}
 need(msg==0x14b||msg==0x4b2||msg==0x18,"1423 reviewed default message");return ui::call(oldproc(m,h),h,msg,w,l);
}
LRESULT CALLBACK common_window_proc(HWND h,UINT msg,WPARAM w,LPARAM l){auto&c=ui::context();Memory&m=c.memory();Heap&heap=c.heap();const U hwnd=ui::ptr(h),owner=0xa5aef8;need(h==c.combo()&&ui::candidate_message(msg),"1423 reviewed common message");need(m.r32(lookup(m,0xa5af60,hwnd,8)+4)==0x5ecc60,"1423 actual selected procedure");(void)oldproc(m,h);need(m.r8(0xa5dc94)==3&&m.r32(0xa5dc70)==0&&m.r32(0xa5dc74)==0&&m.r32(0xa5dc78)==0&&m.r8(0xa28968)==0,"1423 original warm nonmodal/nonpaint state");need(m.r32(owner+4)<=1&&m.r32(owner+8)==128&&m.r32(owner+12)==7&&m.r32(owner+24)==0x5d6fd0&&m.r32(owner+48)==128,"1423 actual bounded pairhash");need(m.r32(owner+32)==0x9999999a&&m.r32(owner+36)==0x3fc99999&&m.r32(owner+40)==0x9999999a&&m.r32(owner+44)==0x3fe99999,"1423 original .2/.8 factors");RECT a{},r{};relative(h,a);need(ui::rect(h,&r),"1423 actual common rectangle");
 const U at=m.r32(owner)+4*((msg*hwnd)&127);for(U q=m.r32(at);q;q=heap.r32(q+12))need(heap.r32(q)!=msg||heap.r32(q+4)!=hwnd,"1423 no same-message recursion shortcut");need(!remove_message(m,heap,msg,hwnd),"1423 original initial lookup is missing key");const U node=heap.allocate(16);need(node,"1423 real temporary message owner");heap.w32(node,msg);heap.w32(node+4,hwnd);heap.w8(node+8,1);heap.w32(node+12,m.r32(at));m.w32(at,node);m.w32(owner+4,m.r32(owner+4)+1);insert_fp(m.r32(owner+4));RECT b{},r2{};need(ui::client(h,&b),"1423 real common client");relative(h,r2);m.w8(0x7d2ea8,m.r8(0xa28968));const U p=control(m,h);need(m.r32(p+0x24)==0&&m.r32(0xa5b46c)!=hwnd,"1423 ordinary nonpaint route");
 if(msg==0x18){need(w==1&&l==0,"1423 actual positive WM_SHOWWINDOW");}
 if(msg==0x4b2){need(w==0&&m.r32(p+0x28)==0&&m.r32(p+0x70)==0,"1423 actual initial selectedlabel state");const U n=length_heap(heap,U(l));need(n>0,"1423 positive UTF16 selected label");const U text=heap.allocate(2*n+2);need(text,"1423 genuine selectedlabel owner");m.w32(p+0x28,text);copy_heap(heap,text,U(l),n);m.w32(p+0x2c,0);}
 const LRESULT result=ui::call(&combo_window_proc,h,msg,w,l);need(remove_message(m,heap,msg,hwnd),"1423 genuine current-message unlink");return result;
}
// Exact ASCII fast route of76D860: B10530=0, actual special sentinel
// first, then first nonempty registry record's +64 (case-insensitive match).
namespace {
U compare_ascii(Memory&m,U a,U b){need(m.r32(0xb10530)==0,"1423 actual CRT ASCII fast domain");for(U k=0;k<64;++k){U x=m.r8(a+k),y=m.r8(b+k);if(x!=y){if(x-65<26)x+=32;if(y-65<26)y+=32;if(x!=y)return x<y?0xffffffffu:1u;}if(!x)return 0;}throw std::domain_error("1423 unterminated ASCII input");}
U registry_index(Memory&m,U token){need(token,"1423 nonempty real token");if(compare_ascii(m,token,0x7bceb0)==0)return 0xfffffffeu;const U count=m.r32(0xa1e048);need(count==1,"1423 one populated registry");const U table=m.r32(0xa1e03c);for(U k=0;k<count;++k){const U record=m.r32(table+k*4);if(compare_ascii(m,record+0x64,token)==0||compare_ascii(m,record+0x24,token)==0)return k;}return 0xffffffffu;}
U row_lookup(Memory&m,U owner,U index,U&out){if(std::int32_t(index)<0||std::int32_t(index)>=std::int32_t(m.r32(owner+0x54))){out=0;throw std::domain_error("1423 positive row lookup required");}const U base=m.r32(owner+0x50);out=base+index*0x44;return (base&0xffffff00u)|1;}
}
unsigned fun_005a03a0(Memory&m,const Inputs&i,Heap&heap){auto&c=ui::context();need(&c.memory()==&m&&&c.heap()==&heap&&i.arg[0]==ui::ptr(c.parent())&&i.arg[1]==0x6a1,"1423 genuine parent/id entry");const auto host=fp::capture_host();fp::restore_host(i.fp.image);try{
 const HWND h=ui::get(c.parent(),int(i.arg[1]));need(h==c.combo(),"1423 real6A1 child");(void)ui::show(h,0);(void)ui::send(h,0x14b,0,0);
 // T=S-10:490A30 output T18 aliases outerarg1; root T14 aliases arg0.
 (void)row_lookup(m,m.r32(i.cx+0x40),m.r32(i.cx+0x260),i.arg[1]);const U row=i.arg[1];need(row&&m.r32(row+0x20)==1,"1423 one genuine positive row");i.arg[0]=m.r32(row+0x20);
 for(U k=0;k<i.arg[0];++k){const U token=m.r32(m.r32(i.arg[1]+0x14)+k*4);const U index=registry_index(m,token);need(index==0,"1423 actual positive registry match");const U object=m.r32(m.r32(0xa1e03c)+index*4);const U osindex=U(ui::send(h,0x4c2,0,LPARAM(m.r32(object+0x60))));(void)ui::send(h,0x151,osindex,index);}
 (void)ui::send(h,0x14e,0,0);const U result=U(ui::show(h,5));i.fp.image=fp::capture_host();fp::restore_host(host);return result;
 }catch(...){fp::restore_host(host);throw;}}
}
