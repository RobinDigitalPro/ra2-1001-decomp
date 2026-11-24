#include "recovery_b487.hpp"
#include <algorithm>
#include <stdexcept>
namespace ra2::recovered::recovery_b487 {
using U=std::uint32_t;using S=std::int32_t;
static void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
static U blit(Memory&m,const Inputs&i,bool blend){
 need(m.r8(blend?0x838f86:0x838f85)!=0,"487 warm resource cache");
 U blob=blend?m.r32(0x838f30):m.r32((m.r32(m.r32(0xa255c0))&0x1000)?0x838f58:0x838f5c);
 U index=i.arg[2];need(index<m.r16(blob+6),"487 existing bounded frame");
 U frame=blob+8+24*index;
 S ox=static_cast<std::int16_t>(m.r16(frame)),oy=static_cast<std::int16_t>(m.r16(frame+2));
 S fw=static_cast<std::int16_t>(m.r16(frame+4)),fh=static_cast<std::int16_t>(m.r16(frame+6));
 S px=static_cast<S>(m.r32(i.arg[0])),py=static_cast<S>(m.r32(i.arg[0]+4));
 U clip=i.arg[1];S cx=static_cast<S>(m.r32(clip)),cy=static_cast<S>(m.r32(clip+4));
 S left=std::max(px+ox,cx),top=std::max(py+oy,cy);
 S right=std::min(px+ox+fw,cx+static_cast<S>(m.r32(clip+8)));
 S bottom=std::min(py+oy+fh,cy+static_cast<S>(m.r32(clip+12)));
 need(fw>0&&fw<=16&&fh>0&&fh<=12&&left>=0&&(left%2)==0&&right>left&&bottom>top,"487 positive even-left clipped rectangle");
 U image=m.r32(0x8198f4),surface=m.r32(image+0x14),stride=m.r32(image+0x28),pixels=m.r32(surface+20);
 need(m.r32(surface)==0x785ef8&&m.r32(0x785f54)==0x411370&&m.r32(0x785f58)==0x4112f0&&
 m.r32(0x785f68)==0x4113b0&&m.r32(0x785f6c)==0x4113c0&&m.r32(0x785f74)==0x4112c0,"487 authentic BSurface virtual closure");
 S y=top-static_cast<S>(m.r32(0x821974));
 need(stride==32&&m.r32(surface+4)==32&&m.r32(surface+8)==24&&m.r32(surface+16)==2&&y>=0&&y+bottom-top<24&&right<=32&&m.r32(image+0x10)==0,"487 nonwrapping word surface");
 U lock=m.r32(surface+12);m.w32(surface+12,lock+1);
 U cursor=pixels+2*(U(y)*stride+U(left));m.w32(surface+12,lock);
 need(cursor+2*(stride*U(bottom-top)+U(right-left))+4<m.r32(image+0x1c),"487 original contiguous-loop branch");
 U data=m.r32(frame+0x14);need(data!=0,"487 existing frame pixels");
 U source=blob+data+U(top-py-oy)*U(fw)+U(left-px-ox),start=source,last=0;
 for(S row=0;row<bottom-top;++row){
  for(S x=0;x<right-left;++x){
   last=m.r8(source++);
   if(blend){if(last<=127){U old=m.r16(cursor);S value=old==127?S(last):std::max(0,S(old+last)-127);m.w16(cursor,U(value));}}
   else if(last!=m.r32(0x788ad0))m.w16(cursor,last);
   cursor+=2;
  }
  source+=U(fw-(right-left));cursor+=2*(stride-U(right-left));
 }
 if(blend){i.arg[0]=source;i.arg[1]=U(left);i.arg[2]=(i.arg[2]&0xffffff00u)|last;return cursor;}
 i.arg[0]=U(right-left);i.arg[1]=U(right);i.arg[2]=start;return last;
}
U fun_00473e60(Memory&m,const Inputs&i){return blit(m,i,false);}
U fun_00474110(Memory&m,const Inputs&i){return blit(m,i,true);}
}
