#include "recovered/recovery_b1492.hpp"
#include "platform/custom_edit1490.hpp"
#include <array>
namespace ra2::recovered::b1492 {
namespace ui=b1490::ui;namespace fp=ra2::platform::x87;using U=unsigned;
unsigned fun_005ea1e0(Memory&m,const Inputs&i,Heap&heap){
 auto&c=ui::context();ui::need(&m==&c.memory()&&&heap==&c.heap()&&i.cx==ui::ptr(c.edit())&&i.arg[0]==2048&&i.arg[1]==0,"1492 genuine direct getter contract");
 ui::stack_span(i.dx,4096);ui::need(m.r32(0xa5b1ec)==2&&m.r32(0xa5b1f0)==128&&m.r32(0xa5b1f4)==7&&m.r32(0xa5b200)==0x5d6fc0,"1492 genuine oldproc scalar registry");
 U node=m.r32(m.r32(0xa5b1e8)+(i.cx&127)*4),steps=0;while(node&&m.r32(node)!=i.cx){ui::need(++steps<2,"1492 bounded registry chain");node=m.r32(node+8);}ui::need(node&&m.r32(node+4)==ui::addr(c.os(c.edit())),"1492 actual captured oldEdit procedure");
 const auto host=fp::capture_host();fp::restore_host(i.fp.image);
 try{
  std::array<char,1024>ansi;ansi[0]=0;
  (void)ui::call(c.os(c.edit()),c.edit(),WM_GETTEXT,1024,reinterpret_cast<LPARAM>(ansi.data()));
  auto*out=reinterpret_cast<WCHAR*>(std::uintptr_t(i.dx));out[0]=0;
  (void)ui::convert(0,0,ansi.data(),-1,out,2048);out[2047]=0;
  U length=0;while(length<2048&&out[length])++length;ui::need(length>=1&&length<=2,"1492 actual positive short text");for(U k=0;k<length;++k)ui::need(out[k]<128&&out[k]!=13&&out[k]!=10,"1492 finite noCRLF ASCII");
  const U request=2*length+6,owner=heap.allocate(request);ui::need(owner,"1492 genuine temporary owner");for(U k=0;k<request;++k)heap.w8(owner+k,0);
  U copied=0;for(U k=0;k<length;++k){U ch=out[k];if(ch!=13&&ch!=10){heap.w8(owner+2*copied,ch);heap.w8(owner+2*copied+1,ch>>8);++copied;}}
  ui::need(copied==length,"1492 original append branch excluded by actual text");
  for(U k=0;;++k){U ch=heap.r8(owner+2*k)|(heap.r8(owner+2*k+1)<<8);out[k]=WCHAR(ch);if(!ch)break;}
  ui::need(heap.release(owner)==1,"1492 genuine scratch HeapFree BOOL");U result=0;while(out[result])++result;
  i.fp.image=fp::capture_host();fp::restore_host(host);return result;
 }catch(...){fp::restore_host(host);throw;}
}
}
