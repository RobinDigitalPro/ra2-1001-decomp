#include "recovered/recovery_b1610.hpp"
#include <stdexcept>
namespace ra2::recovered::b1610 {
U run(U root,Memory&m,const Inputs&i,Heap&heap,FileOps&files){const auto need=[](bool b){if(!b)throw std::domain_error("B1610 owned context/buffer/file close");};need(root==0x3677b0);const U self=i.cx,p=heap.r32(self+0x6f4),size=heap.r32(self+0x6f8),fd=heap.r32(self+0xb8);need(p&&(size==8||size==20)&&fd>=3&&fd<64&&m.r32(0xb10e00)==64);
 for(U off=0;off<0x7dc;++off){U v=0;for(U field:{0x30u,0x40u,0x44u,0x50u,0x78u,0xb8u,0x6f4u,0x6f8u})if(off>=field&&off<field+4){const U x=field==0x30?0x7dc:field==0x40?0x763d90:field==0x44?0x763120:field==0x50?i.dx:field==0x78?i.ax:field==0xb8?fd:field==0x6f4?p:size;v=(x>>(8*(off-field)))&255;break;}need(heap.r8(self+off)==v);}
 const U d=m.r32(0xb10d00+4*(fd>>5))+36*(fd&31);need(m.r8(d+4)==1&&m.r32(d+8)==1);
 namespace fp=ra2::platform::x87;need(i.fp.image.word(8)==0xffff);const auto host=fp::capture_host();fp::restore_host(i.fp.image);
 try{
  // Whole762AD0 selectedone6F4 route: actual763120op5 no-write,
  // op3 calls76DF28. Rawpointer remains in context until its ownfree.
  need(heap.release(p)==1);
  // Actual763D90selector4 calls776634: initializeddescriptor lock,
  // acceptedB431actualCloseHandle/row invalidation, thenunlock.
  recovery_b431::Inputs q{};q.arg[0]=fd;files.enter(d+12);need(recovery_b431::fun_00776691(m,q,files)==0);files.leave(d+12);
  // Actual763120op5(context,7DC) is no-write, op3 closescontextlifetime.
  need(heap.release(self)==1);i.fp.image=fp::capture_host();fp::restore_host(host);
 }catch(...){fp::restore_host(host);throw;}return 0;
}
}
