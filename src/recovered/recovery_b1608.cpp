#include "recovered/recovery_b1608.hpp"
#include <stdexcept>
namespace ra2::recovered::b1608 {
U run(U root,Memory&m,const Inputs&i,Heap&heap){
 const auto need=[](bool b){if(!b)throw std::domain_error("B1608 normal-prefix one-owned-buffer cleanup");};
 need(root==0x362ad0);const U self=i.cx,p=m.r32(self+0x6f4),size=m.r32(self+0x6f8);need(p&&(size==8||size==20));
 // Original767191 zero-initializes7DCbytes, copiesparams and installs actual
 // default callbacks;767679/67F allocates and publishes6F4 atsize6F8.
 for(U off=0;off<0x7dc;++off){U v=0;for(U field:{0x30u,0x40u,0x44u,0x50u,0x78u,0x6f4u,0x6f8u})if(off>=field&&off<field+4){U x=field==0x30?0x7dc:field==0x40?0x763d90:field==0x44?0x763120:field==0x50?self+0x1000:field==0x78?self+0x1100:field==0x6f4?p:size;v=(x>>(8*(off-field)))&255;break;}need(m.r8(self+off)==v);}
 namespace fp=ra2::platform::x87;need(i.fp.image.word(8)==0xffff);const auto host=fp::capture_host();fp::restore_host(i.fp.image);
 try{
  // Actual763120 op5 returns the supplied pointer without writes; op3
  // calls the same76DF28 ordinary free observed through76D67B inB1607.
  need(heap.release(p)==1);i.fp.image=fp::capture_host();fp::restore_host(host);
 }catch(...){fp::restore_host(host);throw;}
 // Original retains the raw6F4 pointer after its lifetime; selected final
 // MOV EAX,[self+71C] reads0. Other conditional resources arezero.
 return 0;
}
}
