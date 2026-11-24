#include "recovered/leaf_math.hpp"

namespace ra2::recovered::leaf {
namespace {
std::uint32_t pair16_add(std::uint32_t a,std::uint32_t b) {
    const auto lo=(a&0xffffu)+(b&0xffffu);
    const auto hi=((a>>16)&0xffffu)+((b>>16)&0xffffu);
    return (lo&0xffffu)|((hi&0xffffu)<<16);
}
std::uint32_t pair16_sub(std::uint32_t a,std::uint32_t b) {
    return ((a-b)&0xffffu)|(((((a>>16)&0xffffu)-((b>>16)&0xffffu))&0xffffu)<<16);
}
}

std::uint32_t fun_0042add0(Memory& m,const Inputs& in) {
    const auto x=m.r32(in.cx), y=m.r32(in.arg[1]);
    m.w32(in.arg[0],pair16_add(x,y)); return in.arg[0];
}
std::uint32_t fun_00567810(Memory& m,const Inputs& in) {
    m.w16(in.cx,m.r16(in.cx)+m.r16(in.arg[0]));
    m.w16(in.cx+2,m.r16(in.cx+2)+m.r16(in.arg[0]+2)); return in.cx;
}
std::uint32_t fun_00567830(Memory& m,const Inputs& in) {
    const auto x=m.r32(in.cx), y=m.r32(in.arg[1]);
    m.w32(in.arg[0],pair16_sub(x,y)); return in.arg[0];
}
std::uint32_t fun_0047cc40(Memory& m,const Inputs& in) {
    const auto a0=m.r32(in.cx),a1=m.r32(in.cx+4),b0=m.r32(in.arg[1]),b1=m.r32(in.arg[1]+4);
    m.w32(in.arg[0],a0-b0);m.w32(in.arg[0]+4,a1-b1);return in.arg[0];
}
std::uint32_t fun_004347b0(Memory& m,const Inputs& in) {
    const auto a0=m.r32(in.cx),a1=m.r32(in.cx+4),a2=m.r32(in.cx+8);
    const auto b0=m.r32(in.arg[1]),b1=m.r32(in.arg[1]+4),b2=m.r32(in.arg[1]+8);
    m.w32(in.arg[0],a0-b0);m.w32(in.arg[0]+4,a1-b1);m.w32(in.arg[0]+8,a2-b2);return in.arg[0];
}
std::uint32_t fun_0047cc00(Memory& m,const Inputs& in) {
    const auto a0=m.r32(in.cx),a1=m.r32(in.cx+4),a2=m.r32(in.cx+8),a3=m.r32(in.cx+12);
    const auto b0=m.r32(in.arg[1]),b1=m.r32(in.arg[1]+4);
    m.w32(in.arg[0],a0-b0);m.w32(in.arg[0]+4,a1-b1);
    m.w32(in.arg[0]+8,a2);m.w32(in.arg[0]+12,a3);return in.arg[0];
}
std::uint32_t fun_00435400(Memory& m,const Inputs& in) {
    const auto a0=m.r32(in.cx),a1=m.r32(in.cx+4),b0=m.r32(in.arg[1]),b1=m.r32(in.arg[1]+4);
    m.w32(in.arg[0],a0+b0);m.w32(in.arg[0]+4,a1+b1);return in.arg[0];
}
std::uint32_t fun_00694350(Memory& m,const Inputs& in) {
    const auto a0=m.r32(in.cx),a1=m.r32(in.cx+4),a2=m.r32(in.cx+8);
    const auto b0=m.r32(in.arg[1]),b1=m.r32(in.arg[1]+4),b2=m.r32(in.arg[1]+8);
    m.w32(in.arg[0],a0+b0);m.w32(in.arg[0]+4,a1+b1);m.w32(in.arg[0]+8,a2+b2);return in.arg[0];
}
std::uint32_t fun_006a1ea0(Memory& m,const Inputs& in) {
    const auto first=m.r32(in.cx)-m.r32(in.arg[0]);
    const auto second_left=m.r32(in.cx+4);
    m.w32(in.cx,first);
    const auto second=second_left-m.r32(in.arg[0]+4);
    m.w32(in.cx+4,second);return in.cx;
}
std::uint32_t fun_00612490(Memory& m,const Inputs& in) {
    for(std::uint32_t o=0;o<12;o+=4)if(m.r32(in.cx+o)!=m.r32(in.arg[0]+o))return 0;
    return 1;
}
std::uint32_t fun_004bf7d0(Memory& m,const Inputs& in) {
    return m.r32(in.cx)==m.r32(in.arg[0])&&m.r32(in.cx+4)==m.r32(in.arg[0]+4)?1u:0u;
}
std::uint32_t fun_004fe420(Memory& m,const Inputs& in) {
    return m.r32(in.cx)==m.r32(in.arg[0])?1u:0u;
}
std::uint32_t fun_0058a950(Memory& m,const Inputs& in) {
    return m.r32(in.cx)!=m.r32(in.arg[0])?1u:0u;
}
std::uint32_t fun_006124c0(Memory& m,const Inputs& in) {
    const auto x=s32(m.r32(in.arg[0])),y=s32(m.r32(in.arg[0]+4));
    const auto left=s32(m.r32(in.cx)),top=s32(m.r32(in.cx+4));
    const auto right=s32(m.r32(in.cx+8)+m.r32(in.cx));
    const auto bottom=s32(m.r32(in.cx+12)+m.r32(in.cx+4));
    return x>=left&&x<right&&y>=top&&y<bottom?1u:0u;
}
std::uint32_t fun_0060a150(Memory& m,const Inputs& in) {
    const auto twice=in.dx+in.dx;
    const auto twice_s=s32(twice);
    if(twice_s<0&&(twice_s>=s32(m.r32(in.cx+8))||twice_s>=s32(m.r32(in.cx+12)))) {
        m.w32(in.cx,0);m.w32(in.cx+4,0);m.w32(in.cx+8,0);m.w32(in.cx+12,0);return twice;
    }
    m.w32(in.cx,m.r32(in.cx)-in.dx);m.w32(in.cx+4,m.r32(in.cx+4)-in.dx);
    m.w32(in.cx+8,m.r32(in.cx+8)+twice);m.w32(in.cx+12,m.r32(in.cx+12)+twice);return twice;
}
std::uint32_t fun_006e6be0(Memory& m,const Inputs& in) {
    const auto twice=in.dx+in.dx;
    m.w32(in.cx,m.r32(in.cx)+in.dx);m.w32(in.cx+4,m.r32(in.cx+4)+in.dx);
    m.w32(in.cx+8,m.r32(in.cx+8)-twice);m.w32(in.cx+12,m.r32(in.cx+12)-twice);return twice;
}
std::uint32_t fun_006e6c10(Memory& m,const Inputs& in) {
    const auto twice_x=in.dx+in.dx, twice_y=in.arg[0]+in.arg[0];
    m.w32(in.cx,m.r32(in.cx)+in.dx);m.w32(in.cx+4,m.r32(in.cx+4)+in.arg[0]);
    m.w32(in.cx+8,m.r32(in.cx+8)-twice_x);m.w32(in.cx+12,m.r32(in.cx+12)-twice_y);return 0u-twice_y;
}
std::uint32_t fun_0054cf80(Memory& m,const Inputs& in) {
    const auto stride=m.r32(in.cx+0xf4)+m.r32(in.cx+0xf0)+1u;
    const auto row=sx16(m.r16(in.arg[0]+2)),col=sx16(m.r16(in.arg[0]));
    return stride*row+col;
}
std::uint32_t fun_0054cf40(Memory& m,const Inputs& in) {
    const auto stride=m.r32(in.cx+0xf4)+m.r32(in.cx+0xf0)+1u;
    const auto row=sx16(m.r16(in.arg[0]+2)),col=sx16(m.r16(in.arg[0]));
    const auto index=stride*row+col;
    if(s32(index)<0)return 0;
    const auto limit=m.r32(in.cx+0x68);
    if(s32(index)<s32(limit))return index;
    return limit-1u;
}
std::uint32_t fun_00547f40(Memory& m,const Inputs& in) {
    const auto x=sx16(m.r16(in.arg[0])),y=sx16(m.r16(in.arg[0]+2));
    const auto d=m.r32(in.cx+0xf0), twice_height=m.r32(in.cx+0xf4)*2u;
    const auto sum=x+y,xy=x-y,yx=y-x;
    return s32(sum)>s32(d)&&s32(xy)<s32(d)&&s32(yx)<s32(d)&&
           s32(sum)<=s32(d+twice_height)?1u:0u;
}
std::uint32_t fun_00545200(Memory& m,const Inputs& in) {
    const auto x=m.r32(in.arg[1])+m.r32(in.cx+0xf8);
    const auto y=m.r32(in.arg[1]+4)+m.r32(in.cx+0xfc);
    const auto out0=x+sar(y+1u,1),out1=m.r32(in.cx+0xf0)+sar(y,1)-x;
    m.w32(in.arg[0],out0);m.w32(in.arg[0]+4,out1);return in.arg[0];
}
std::uint32_t fun_00616660(Memory& m,const Inputs& in) {
    const auto y=sx16(m.r16(in.arg[0]+2)),x=sx16(m.r16(in.arg[0]));
    m.w32(in.cx+4,y*0x100u+0x80u);m.w32(in.cx+8,in.arg[1]);
    m.w32(in.cx,x*0x100u+0x80u);return in.cx;
}
std::uint32_t fun_0054b800(Memory& m,const Inputs& in) {
    const auto y0=sx16(m.r16(in.arg[0]+2)),x0=sx16(m.r16(in.arg[0]));
    const auto y=sar(y0+(s32(y0)<0?3u:0u),2);
    const auto x=sar(x0+(s32(x0)<0?3u:0u),2);
    return x+y*130u+131u;
}
std::uint32_t fun_004bf7a0(Memory& m,const Inputs& in) {
    const auto a=s32(sx16(m.r16(in.arg[0]))),b=s32(sx16(m.r16(in.cx)));
    const auto abs_a=a<0?0u-static_cast<std::uint32_t>(a):static_cast<std::uint32_t>(a);
    const auto abs_b=b<0?0u-static_cast<std::uint32_t>(b):static_cast<std::uint32_t>(b);
    return abs_b>=abs_a?1u:0u;
}
std::uint32_t fun_00590f10(Memory& m,const Inputs& in) {
    const auto diff=sx16((m.r16(in.cx)-m.r16(in.arg[0]))&0xffffu);
    const auto a=s32(diff),b=s32(sx16(m.r16(in.arg[1])));
    const auto abs_a=a<0?0u-static_cast<std::uint32_t>(a):static_cast<std::uint32_t>(a);
    const auto abs_b=b<0?0u-static_cast<std::uint32_t>(b):static_cast<std::uint32_t>(b);
    return abs_b>=abs_a?1u:0u;
}
std::uint32_t fun_0069be10(Memory& m,const Inputs& in) {
    const auto a=m.r32(in.cx+0xd64)-m.r32(in.cx+0xb0);
    const auto b=m.r32(in.cx+0xd68)-m.r32(in.cx+0xb4);
    m.w32(in.arg[0],a);m.w32(in.arg[0]+4,b);return in.arg[0];
}
std::uint32_t fun_00557840(Memory& m,const Inputs& in) {
    const auto a=m.r32(in.cx+0xfc),b=m.r32(in.cx+0xf8);
    m.w32(in.cx+0x118,b+a+1u);
    m.w32(in.cx+0x11c,m.r32(in.cx+0xf0)-b+a);return a;
}
std::uint32_t fun_0062eb30(Memory& m,const Inputs& in) {
    const auto scaled=(in.arg[0]<<8)+0x80u;
    m.w32(in.cx+0x44,in.arg[0]);m.w32(in.cx+0x48,scaled);return scaled;
}
std::uint32_t fun_0047cb10(Memory& m,const Inputs& in) {
    const auto v=sx8(m.r8(in.cx+0x11b));
    const auto bit=(m.r32(in.cx+0x140)>>7)&1u;
    return v+bit*4u;
}
std::uint32_t fun_0078040e(Memory& m,const Inputs& in) {
    const auto base=in.arg[0],length=in.arg[1],sum=base+length;
    const bool carry=sum<base;
    const bool less_than_length=sum<length;
    m.w32(in.arg[2],sum);
    return carry||less_than_length?1u:0u;
}
}
