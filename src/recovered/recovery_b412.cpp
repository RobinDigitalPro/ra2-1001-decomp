#include "recovery_b412.hpp"
#include <algorithm>
#include <array>
#include <stdexcept>
namespace ra2::recovered::recovery_b412 {
namespace {using U=std::uint32_t;void need(bool b,const char*s){if(!b)throw std::domain_error(s);}}
U fun_005f5e90(Memory&m,const Inputs&i){
 need(m.r8(0xa28968)!=0,"412 rendering enabled");
 if(!i.arg[5])i.arg[5]=m.r32(0x821c98);
 const U font=i.dx?i.dx:m.r32(0x836d30),surface=i.arg[5],r=i.arg[0],text=i.arg[1];
 need(i.arg[2]==1&&i.arg[3]==0&&i.arg[4]==0&&i.arg[6]==0,"412 one glyph, leading alignment, flags0");
 need(m.r16(text)=='A'&&m.r16(text+2)==0,"412 exactly one terminated A");
 need(m.r32(surface)==0x785ef8&&m.r32(surface+4)==8&&m.r32(surface+8)==8&&m.r32(surface+16)==2,"412 original 8x8 16bit software surface");
 const U desc=m.r32(font+4),glyph=m.r32(desc+28);
 need(m.r16(m.r32(desc+24)+130)==1&&m.r8(glyph)==2&&m.r8(glyph+1)==0xc0&&m.r8(glyph+2)==0x80,"412 parsed A record");
 need(m.r32(font+28)==2&&m.r32(font+44)==0&&m.r32(font+24)==1,"412 fixed font metrics");
 const U x=m.r32(r),y=m.r32(r+4),width=m.r32(r+8),height=m.r32(r+12);
 need(x>=1&&x<=4&&y>=1&&y<=4&&width>=2&&width<=520&&height==2,"412 visible glyph rectangle");
 const U red=i.cx&255,green=(i.cx>>8)&255,blue=(i.cx>>16)&255;
 need(m.r32(0x83b2e8)==11&&m.r32(0x83b2ec)==3&&m.r32(0x83b2f0)==0&&m.r32(0x83b2f4)==3&&m.r32(0x83b2f8)==5&&m.r32(0x83b2fc)==2,"412 RGB565 fields");
 const U color=((red>>3)<<11)|((green>>2)<<5)|(blue>>3);
 // Root overwrites its first caller word with the vertical drawing position.
 i.arg[0]=y;m.w8(font+65,1);m.w32(font+48,x);m.w32(font+52,y);
 m.w32(font+56,x+width);m.w32(font+60,y+height);m.w16(font+36,color);
 // 31f70 locks and intersects the font clip with inclusive surface bounds.
 m.w32(surface+12,m.r32(surface+12)+1);m.w32(font+12,m.r32(surface+20));m.w32(font+16,8);
 m.w32(font+56,std::min(x+width,7u));m.w32(font+60,std::min(y+height,7u));m.w32(font+32,x);
 const U pixels=m.r32(surface+20);
 for(U row=0;row<2;++row)for(U col=0;col<2;++col)if((m.r8(glyph+1+row)>>(7-col))&1)m.w16(pixels+2*((y+row)*8+x+col),color);
 m.w32(font+12,0);m.w32(font+16,0);m.w32(surface+12,m.r32(surface+12)-1);
 return 2;
}
U fun_004b33a0(Memory&m,const Inputs&i){
 const U s=m.r32(0x821c9c),y=m.r32(i.cx+8),flags=m.r32(i.cx+12);
 need(m.r32(s+8)==8&&y>=1&&y<=4&&(flags&0x300)==0,"412 positive notification leading route");
 need(m.r8(0xa28968)!=0&&m.r16(m.r32(i.cx))=='A'&&m.r16(m.r32(i.cx)+2)==0,"412 visible notification A");
 std::array<unsigned char,16> bytes{};constexpr U p=0xf4100000;leaf::Memory span(bytes.data(),p,bytes.size());Memory work=m;work.add(span);
 const U screenwidth=m.r32(0x83a710);need(screenwidth>=522&&screenwidth<=528,"412 supplied screen width");
 work.w32(p,(screenwidth-520)/2);work.w32(p+4,y);work.w32(p+8,520);work.w32(p+12,m.r32(0x83a714));
 Inputs c{};c.cx=0x80ffff;c.arg[0]=p;c.arg[1]=m.r32(i.cx);c.arg[2]=1;c.arg[5]=m.r32(0x83b448);
 return fun_005f5e90(work,c);
}
}
