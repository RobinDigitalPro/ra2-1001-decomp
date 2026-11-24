#include "recovered/leaf_b16_a.hpp"

namespace ra2::recovered::leaf {

std::uint32_t fun_00486c70(Memory& m,const Inputs& i) {
    const auto count=s32(i.arg[2]);
    if(count<=0)return 0; // EAX is not defined on this excluded input path.
    auto src=i.arg[1], dst=i.arg[0];
    for(std::int32_t n=0;n<count;++n) {
        const auto ch=m.r8(src);
        const auto table=m.r32(i.cx+4);
        m.w16(dst,m.r16(table+ch*2u));
        src+=1;dst+=2;
    }
    return src;
}

std::uint32_t fun_005fabb0(Memory& m,const Inputs& i) {
    const auto dst=i.cx,src=i.arg[0];
    for(std::uint32_t n=0;n<0x100;++n){m.w8(dst+n*3,0);m.w8(dst+n*3+1,0);m.w8(dst+n*3+2,0);}
    for(std::uint32_t n=0;n<0x100;++n){
        const auto word=m.r16(src);m.w16(dst+n*3,word);
        const auto tail=m.r8(src+2);m.w8(dst+n*3+2,tail);
    }
    return dst;
}

std::uint32_t fun_0052d130(Memory& m,const Inputs& i) {
    auto p=i.cx;std::uint32_t groups=0;
    while(m.r8(p)==0){++p;++groups;}
    const auto byte=m.r8(p);
    std::uint32_t bit=0;while(bit<8&&((byte&(1u<<bit))==0))++bit;
    return groups*8u+bit;
}

std::uint32_t fun_00407200(Memory& m,const Inputs& i) {
    m.w32(i.cx,i.cx);m.w32(i.cx+4,i.cx);m.w32(i.cx+8,0);return 0;
}

std::uint32_t fun_00707d20(Memory& m,const Inputs& i) {
    m.w32(i.cx+0x3c,0x20000);m.w32(i.cx+0x40,0x20000);return 0x20000;
}

std::uint32_t fun_0075bd30(Memory& m,const Inputs& i) {
    const auto v=m.r32(i.cx);return v?v:0x0082208cu;
}

std::uint32_t fun_006ed710(Memory& m,const Inputs& i) {
    return i.cx?m.r8(i.cx+0x14)&1u:0u;
}

std::uint32_t fun_00776555(Memory& m,const Inputs& i) {
    const auto cursor=i.arg[0];const auto next=m.r32(cursor)+4u;m.w32(cursor,next);return m.r32(next-4u);
}

std::uint32_t fun_00687350(Memory& m,const Inputs& i) {m.w32(i.cx+4,0);m.w32(i.cx,0x00796900);return i.cx;}

std::uint32_t fun_0071c870(Memory& m,const Inputs& i) {
    const auto object=i.cx;const auto p=m.r32(object+4);const auto n=m.r32(object+8);return n<m.r32(p+0x10)?1u:0u;
}

std::uint32_t fun_00724f60(Memory& m,const Inputs& i) {
    const auto object=i.cx;const auto p=m.r32(object+4);const auto n=m.r32(object+8);return n<m.r32(p+0x10)?1u:0u;
}

std::uint32_t fun_00782818(Memory& m,const Inputs& i) {
    const auto cursor=i.arg[0];const auto next=m.r32(cursor)+4u;m.w32(cursor,next);return (next&0xffff0000u)|m.r16(next-4u);
}

std::uint32_t fun_0069ffb0(Memory& m,const Inputs& i) {
    const auto dst=i.arg[0],src=i.arg[1];const auto v=m.r32(src);m.w32(dst,v);return dst;
}

std::uint32_t fun_00687650(Memory& m,const Inputs& i) {m.w32(i.cx+4,0);m.w32(i.cx,0x00796930);return i.cx;}

std::uint32_t fun_0062e3b0(Memory& m,const Inputs& i) {
    const auto table=m.r32(i.cx+0xcc);return m.r32(table+i.arg[0]*4u);
}

std::uint32_t fun_0072e590(Memory& m,const Inputs& i) {
    if(m.r32(i.cx+0x20)!=i.arg[0]){m.w32(i.cx+0x20,i.arg[0]);m.w8(i.cx+8,1);}
    return i.arg[0];
}

std::uint32_t fun_006a7980(Memory& m,const Inputs& i) {
    auto eax=i.arg[0];if(eax){const auto v=m.r32(i.cx+0x74);m.w32(eax+0x5554,v);}return (eax&0xffffff00u)|1u;
}

std::uint32_t fun_00724f30(Memory& m,const Inputs& i) {
    m.w32(i.cx+4,i.arg[0]);m.w32(i.cx+8,i.arg[1]);m.w32(i.cx,0x0079a220);return i.cx;
}

std::uint32_t fun_0053f5e0(Memory& m,const Inputs& i) {
    auto eax=m.r32(i.cx+0x10);if(eax){eax=m.r32(eax);if(eax==m.r32(i.arg[0]))return (eax&0xffffff00u)|1u;return eax&0xffffff00u;}return 0;
}

std::uint32_t fun_006fefb0(Memory& m,const Inputs& i) {
    auto eax=m.r32(i.cx+0x10);if(eax){eax=m.r32(eax);if(eax==m.r32(i.arg[0]))return (eax&0xffffff00u)|1u;return eax&0xffffff00u;}return 0;
}

std::uint32_t fun_0077ba47(Memory& m,const Inputs& i) {
    const auto p=i.arg[0];for(unsigned n=0;n<3;++n)if(m.r32(p+n*4)!=0)return 0;return 1;
}

std::uint32_t fun_00590eb0(Memory& m,const Inputs& i) {
    const auto source=i.arg[1],dst=i.arg[0];const auto low=(m.r16(source)+m.r16(i.cx))&0xffffu;
    const auto value=(i.arg[1]&0xffff0000u)|low;m.w32(dst,value);return dst;
}

std::uint32_t fun_00568250(Memory& m,const Inputs& i) {
    for(unsigned off=0;off<8;off+=2)m.w16(i.cx+off,0);m.w8(i.cx+8,0);m.w32(i.cx+0xc,0xffffffffu);return i.cx;
}

std::uint32_t fun_0058cbe0(Memory& m,const Inputs& i) {
    for(unsigned off=0;off<48;off+=4){const auto v=m.r32(i.arg[0]+off);m.w32(i.cx+off,v);}return i.cx;
}

std::uint32_t fun_0076ef9f(Memory& m,const Inputs& i) {
    auto dst=i.arg[0],src=i.arg[1];auto pos=dst;
    if(m.r16(pos)!=0){do{pos+=2;}while(m.r16(pos)!=0);}
    for(;;){const auto v=m.r16(src);m.w16(pos,v);pos+=2;src+=2;if(v==0)break;}
    return dst;
}

std::uint32_t fun_0076efc9(Memory& m,const Inputs& i) {
    auto dst=i.arg[0],src=i.arg[1];for(;;){const auto v=m.r16(src);m.w16(dst,v);dst+=2;src+=2;if(v==0)break;}return i.arg[0];
}

std::uint32_t fun_007681e0(Memory& m,const Inputs& i) {
    const auto n=s32(i.dx);if(n<=0)return 0xffffffffu;
    const auto limit=m.r16(i.cx+0xec);if(s32(limit)<n)return 0xffffffffu;
    const auto old=m.r32(i.cx+0x11c);m.w32(i.cx+0x11c,i.dx&0xffffu);return old;
}

std::uint32_t fun_0042e7e0(Memory& m,const Inputs& i) {
    auto eax=m.r32(i.cx+0x60);if(eax==0)return eax;
    auto slot=i.cx;
    for(unsigned outer=0;outer<8;++outer)for(unsigned inner=0;inner<3;++inner){
        eax=m.r32(slot);if(eax)m.w8(eax+0xc,m.r8(eax+0xc)&0xfdu);slot+=4;
    }
    return eax;
}

std::uint32_t fun_0077f035(Memory& m,const Inputs& i) {
    const auto p=i.arg[0],n=i.arg[1];for(std::uint32_t k=0;k<n;++k)if(m.r8(p+k)==0)return k;return n;
}

std::uint32_t fun_00768260(Memory& m,const Inputs& i) {
    auto v=m.r8(i.cx+0xf2);m.w32(i.dx,v);
    v=m.r8(i.cx+0xf3);m.w32(i.arg[0],v);
    v=m.r8(i.cx+0x108);m.w32(i.arg[1],v);
    return 0xffffffffu;
}

std::uint32_t fun_007612c0(Memory& m,const Inputs& i) {
    auto dst=i.arg[0],src=i.arg[1],count=i.arg[2];
    for(std::uint32_t n=0;n<count;++n){const auto c=m.r8(src++);if(c!=0)m.w8(dst,c);++dst;}
    return 0;
}

std::uint32_t fun_00630a80(Memory& m,const Inputs& i) {m.w32(i.cx+4,0);m.w32(i.cx,0x00793ccc);return i.cx;}
std::uint32_t fun_00686d50(Memory& m,const Inputs& i) {m.w32(i.cx+4,0);m.w32(i.cx,0x007968a0);return i.cx;}
std::uint32_t fun_00687050(Memory& m,const Inputs& i) {m.w32(i.cx+4,0);m.w32(i.cx,0x007968d0);return i.cx;}

std::uint32_t fun_004038c0(Memory& m,const Inputs& i) {m.w32(i.cx+0x20,i.arg[0]);m.w32(i.cx+0x24,i.arg[1]);return i.arg[0];}
std::uint32_t fun_004cf260(Memory& m,const Inputs& i) {m.w32(i.cx+0x14,i.arg[0]);m.w32(i.cx+0x18,i.arg[1]);return i.arg[0];}
std::uint32_t fun_0062cd30(Memory& m,const Inputs& i) {m.w32(i.cx+0x38,i.arg[0]);m.w32(i.cx+0x3c,i.arg[1]);return i.arg[0];}

std::uint32_t fun_0065f8f0(Memory& m,const Inputs& i) {
    const auto p=m.r32(i.cx+0x24),n=m.r32(i.cx+0x2c);return n<m.r32(p+0xa0)?1u:0u;
}

std::uint32_t fun_0051a770(Memory& m,const Inputs& i) {m.w32(i.cx+4,i.arg[0]);m.w32(i.cx,0x0078f414);return i.cx;}
std::uint32_t fun_0051a950(Memory& m,const Inputs& i) {m.w32(i.cx+4,i.arg[0]);m.w32(i.cx,0x0078f464);return i.cx;}

std::uint32_t fun_00608460(Memory& m,const Inputs& i) {m.w8(i.cx,0);m.w32(i.cx+0x70,0);m.w32(i.cx+0x74,0xffffffffu);return i.cx;}
std::uint32_t fun_0059b030(Memory& m,const Inputs& i) {m.w32(i.cx+0x271c,i.arg[0]);m.w32(i.cx+0x2720,i.arg[1]);return i.arg[0];}

std::uint32_t fun_00650520(Memory& m,const Inputs& i) {
    const auto src=i.arg[0];auto first=m.r32(src);m.w32(i.cx+0x3e0,first);auto second=m.r32(src+4);m.w32(i.cx+0x3e4,second);return second;
}

std::uint32_t fun_0069bdf0(Memory& m,const Inputs& i) {
    m.w32(i.arg[0],m.r32(i.cx+0xd64));const auto second=m.r32(i.cx+0xd68);m.w32(i.arg[0]+4,second);return i.arg[0];
}

std::uint32_t fun_00522950(Memory& m,const Inputs& i) {for(unsigned k=0;k<10;++k)m.w8(i.cx+k,0xff);return i.cx;}

std::uint32_t fun_00649b10(Memory& m,const Inputs& i) {
    m.w32(i.cx+4,0);m.w32(i.cx+8,0);m.w8(i.cx+0xc,1);m.w8(i.cx+0xd,0);m.w32(i.cx+0x14,0xa);m.w32(i.cx+0x10,0);m.w32(i.cx,0x00793fa0);return i.cx;
}
std::uint32_t fun_00649c70(Memory& m,const Inputs& i) {
    m.w32(i.cx+4,0);m.w32(i.cx+8,0);m.w8(i.cx+0xc,1);m.w8(i.cx+0xd,0);m.w32(i.cx+0x14,0xa);m.w32(i.cx+0x10,0);m.w32(i.cx,0x007889f4);return i.cx;
}
std::uint32_t fun_00649e60(Memory& m,const Inputs& i) {
    m.w32(i.cx+4,0);m.w32(i.cx+8,0);m.w8(i.cx+0xc,1);m.w8(i.cx+0xd,0);m.w32(i.cx+0x14,0xa);m.w32(i.cx+0x10,0);m.w32(i.cx,0x0078e0d8);return i.cx;
}
std::uint32_t fun_00649fb0(Memory& m,const Inputs& i) {
    m.w32(i.cx+4,0);m.w32(i.cx+8,0);m.w8(i.cx+0xc,1);m.w8(i.cx+0xd,0);m.w32(i.cx+0x14,0xa);m.w32(i.cx+0x10,0);m.w32(i.cx,0x00793f60);return i.cx;
}

std::uint32_t fun_005677e0(Memory& m,const Inputs& i) {
    const auto src=i.arg[0];auto v=m.r32(src+0x10);m.w32(i.cx+0x10,v);
    v=m.r8(src+0x14);m.w8(i.cx+0x14,v);
    v=m.r32(src+0x18);m.w32(i.cx+0x18,v);
    v=m.r32(src+0x1c);m.w32(i.cx+0x1c,v);
    v=m.r8(src+0x20);m.w8(i.cx+0x20,v);
    return i.cx;
}

} // namespace ra2::recovered::leaf
