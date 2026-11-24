#include "recovered/recovery_b1609.hpp"
#include <stdexcept>
namespace ra2::recovered::b1609 {
U run(U root,Memory&m,const Inputs&i,Heap&heap){
 const auto need=[](bool b){if(!b)throw std::domain_error("B1609 positive five-allocation header projection");};need(root==0x3621e0);const U self=i.cx;constexpr unsigned char header[]{0,0,0,0,1,0,1,0,1,0,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
 for(U off=0;off<0x7dc;++off){U v=off>=0xe8&&off<0x112?header[off-0xe8]:0;for(U field:{0x30u,0x40u,0x44u,0x50u,0x78u,0x88u,0x8cu})if(off>=field&&off<field+4){const U x=field==0x30?0x7dc:field==0x40?0x763d90:field==0x44?0x763120:field==0x50?self+0x1000:field==0x78?self+0x1100:1;v=(x>>(8*(off-field)))&255;break;}need(m.r8(self+off)==v);}
 namespace fp=ra2::platform::x87;need(i.fp.image.word(8)==0xffff);const auto host=fp::capture_host();fp::restore_host(i.fp.image);
 try{
  // HeaderF8/F2/F3=1,108=0; selected existingpositive8C bypasses
  // optional grouping. Actual default763120 op4 leaves payload unchanged.
  m.w32(self+0x774,4);m.w32(self+0x10a,4);
  const U a=heap.allocate(4);need(a);m.w32(self+0x6f0,a);m.w32(self+0x154,1);m.w32(self+0x768,20);m.w32(self+0x30,0x7e0);
  const U b=heap.allocate(44);need(b);m.w32(self+0x6ec,b);for(U k=0;k<24;++k)heap.w8(b+k,0);heap.w32(b,b+24);heap.w32(b+4,b);heap.w32(b+8,b);m.w32(self+0x164,b);m.w32(self+0x168,b);m.w32(self+0x768,16);m.w32(self+0x30,0x80c);
  m.w32(self+0x770,0x3fc);m.w32(self+0x778,4);m.w32(self+0x76c,12);m.w32(self+0x154,3);
  const U c=heap.allocate(4);need(c);m.w32(self+0x6e8,c);m.w32(self+0x30,0x810);
  const U d=heap.allocate(1076);need(d);m.w32(self+0x6e4,d);for(U k=0;k<44;++k)heap.w8(d+k,0);heap.w32(d,d+44);heap.w32(d+8,d+56);heap.w32(d+12,d);heap.w32(d+16,d);m.w32(self+0x170,d);m.w32(self+0x1a0,d);m.w32(self+0x6dc,d);m.w32(self+0x770,0x3f8);m.w32(self+0x76c,8);m.w32(self+0x30,0xc44);
  const U e=heap.allocate(4);need(e);m.w32(self+0x764,e);m.w32(self+0x30,0xc48);i.fp.image=fp::capture_host();fp::restore_host(host);
 }catch(...){fp::restore_host(host);throw;}
 return 0xffffffffu;
}
}
