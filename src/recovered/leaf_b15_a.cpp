#include "recovered/leaf_b15_a.hpp"

namespace ra2::recovered::leaf {
namespace b15_a_detail {
std::uint32_t qdiv(std::uint32_t high,unsigned shift) {
    const auto shifted=sar(high,shift);
    return shifted+(high>>31);
}
std::uint32_t rounded_24_8(std::uint32_t v) {
    const auto bias=(v>>31)?0xffu:0u;
    return sar(v+bias,8)&0xffffu;
}
}

std::uint32_t fun_00401190(Memory& m,const Inputs& in) {
    const auto cell=m.r32(in.cx+0x2c)>>16;
    const auto low=cell*in.dx;
    const auto product=static_cast<std::int64_t>(s32(low))*static_cast<std::int64_t>(0x51eb851fu);
    return b15_a_detail::qdiv(static_cast<std::uint32_t>(static_cast<std::uint64_t>(product)>>32),5);
}
std::uint32_t fun_004038a0(Memory& m,const Inputs& in) {
    const auto a=in.arg[0];m.w32(in.cx+8,a);
    const auto b=in.arg[1];m.w32(in.cx+12,b);return a;
}
std::uint32_t fun_00405bf0(Memory& m,const Inputs& in) {
    m.w32(in.cx+12,0x008192ecu);m.w32(in.cx,0);m.w32(in.cx+4,0);m.w32(in.cx+8,0);return 0;
}
std::uint32_t fun_00406610(Memory& m,const Inputs& in) {
    const auto a=in.arg[0];m.w32(in.cx+0x58,in.dx);m.w32(in.cx+0x5c,a);return a;
}
std::uint32_t fun_004072e0(Memory& m,const Inputs& in) {
    auto node=m.r32(in.cx);std::uint32_t count=0;
    while(node!=in.cx){node=m.r32(node);++count;}
    return count;
}
std::uint32_t fun_004072f0(Memory& m,const Inputs& in) {
    if(!in.cx)return 0;
    const auto head=m.r32(in.cx);
    if(!head)return 0;
    return head==m.r32(head+8)?0u:head;
}
std::uint32_t fun_00407310(Memory& m,const Inputs& in) {
    if(!in.cx)return 0;
    const auto head=m.r32(in.cx);
    if(!head)return 0;
    return head==m.r32(head+8)?0u:head;
}
std::uint32_t fun_00407350(Memory& m,const Inputs& in) {
    const auto old=m.r32(in.cx+4);
    m.w32(in.dx,in.cx);m.w32(in.dx+4,old);m.w32(in.cx+4,in.dx);
    const auto next=m.r32(in.dx+4);m.w32(next,in.dx);return old;
}
std::uint32_t fun_004073a0(Memory& m,const Inputs& in) {
    const auto p=m.r32(in.cx);
    if(!p||p==m.r32(p+8))return 0;
    return p;
}
std::uint32_t fun_00407450(Memory& m,const Inputs& in) {
    const auto node=m.r32(in.cx);
    if(!node)return 0;
    const auto next=m.r32(node);m.w32(in.cx,next);return node+8;
}
std::uint32_t fun_00407ff0(Memory& m,const Inputs& in) {
    if((m.r8(in.cx+12)&1u)==0)return 0;
    const auto object=m.r32(in.cx+20);
    return m.r32(object+20)!=m.r32(object+24)?1u:0u;
}
std::uint32_t fun_00408460(Memory& m,const Inputs& in) {
    const auto field=m.r32(in.cx+0x14),low=field*in.arg[0];
    const auto product=static_cast<std::int64_t>(s32(low))*static_cast<std::int64_t>(0x10624dd3u);
    return b15_a_detail::qdiv(static_cast<std::uint32_t>(static_cast<std::uint64_t>(product)>>32),6);
}
std::uint32_t fun_00408c50(Memory& m,const Inputs& in) {
    return m.r32(in.cx+0x8c)-m.r32(in.cx+0x90);
}
std::uint32_t fun_00411290(Memory& m,const Inputs& in) {
    const auto out=in.arg[0],a=m.r32(in.cx+4),b=m.r32(in.cx+8);
    m.w32(out,0);m.w32(out+4,0);m.w32(out+8,a);m.w32(out+12,b);return out;
}
std::uint32_t fun_00413770(Memory& m,const Inputs& in) {
    const auto x=b15_a_detail::rounded_24_8(m.r32(in.cx));
    const auto y=b15_a_detail::rounded_24_8(m.r32(in.cx+4));
    const auto out=in.arg[0];m.w32(out,x|(y<<16));return out;
}
std::uint32_t fun_0041b320(Memory& m,const Inputs& in) {
    const auto x=b15_a_detail::rounded_24_8(m.r32(in.cx+0x88));
    const auto y=b15_a_detail::rounded_24_8(m.r32(in.cx+0x8c));
    const auto out=in.arg[0];m.w32(out,x|(y<<16));return out;
}
std::uint32_t fun_004246f0(Memory& m,const Inputs& in) {
    const auto i=in.arg[0];
    const auto a=m.r16(in.cx+i*6u+0x80eu);
    const auto j=i*3u+0x408u;
    const auto b=m.r16(in.cx+j*2u);
    return b+a*2u+8u;
}
std::uint32_t fun_0042ad30(Memory& m,const Inputs& in) {
    const auto a=in.arg[0]&0xffffu,b=in.arg[1]&0xffffu;
    m.w16(in.cx,a);m.w16(in.cx+2,b);return in.cx;
}
std::uint32_t fun_0042cb70(Memory& m,const Inputs& in) {
    if(!in.arg[0])return 0;
    const auto count=m.r32(in.arg[0]+12)+1u;m.w32(in.arg[0]+12,count);return count;
}
std::uint32_t fun_0042e6b0(Memory& m,const Inputs& in) {
    auto p=in.cx+in.arg[0]*12u;
    for(unsigned n=0;n<3;++n,p+=4)if(m.r32(p)==0)return 1;
    return 0;
}
std::uint32_t fun_00431320(Memory& m,const Inputs& in) {
    const auto src=in.arg[0];
    if(!src){m.w32(in.cx+0x3c,0);m.w32(in.cx+0x38,0);m.w32(in.cx+0x34,0);m.w32(in.cx+0x30,0);return 0;}
    auto v=m.r32(src);m.w32(in.cx+0x30,v);
    v=m.r32(src+4);m.w32(in.cx+0x34,v);
    v=m.r32(src+8);m.w32(in.cx+0x38,v);
    v=m.r32(src+12);m.w32(in.cx+0x3c,v);return v;
}
std::uint32_t fun_00432c30(Memory& m,const Inputs& in) {
    const auto a=in.arg[0]&0xffu,b=in.arg[1]&0xffu,c=in.arg[2]&0xffu;
    m.w8(in.cx,a);m.w8(in.cx+1,b);m.w8(in.cx+2,c);return in.cx;
}
std::uint32_t fun_004346e0(Memory& m,const Inputs& in) {
    const auto a=in.arg[0];m.w32(in.cx,a);m.w32(in.cx+4,in.arg[1]);m.w32(in.cx+8,in.arg[2]);return in.cx;
}
std::uint32_t fun_00435420(Memory& m,const Inputs& in) {
    const auto out=in.arg[0],a=m.r32(in.cx),b=m.r32(in.cx+4);
    m.w32(out,a);m.w32(out+4,b);return out;
}
std::uint32_t fun_00437510(Memory& m,const Inputs& in) {
    const auto a=in.arg[0];m.w32(in.cx,a);m.w32(in.cx+4,in.arg[1]);m.w32(in.cx+8,in.arg[2]);return in.cx;
}
std::uint32_t fun_00453ab0(Memory& m,const Inputs& in) {
    const auto src=in.arg[0];auto v=m.r32(src);m.w32(in.cx,v);
    v=m.r32(src+4);m.w32(in.cx+4,v);
    const auto a=in.arg[1];m.w32(in.cx+8,a);m.w32(in.cx+12,in.arg[2]);return in.cx;
}
std::uint32_t fun_0045e8c0(Memory& m,const Inputs& in) {
    return (m.r8(in.cx+0x1362)||m.r8(in.cx+0x135e)||m.r8(in.cx+0x1363)||m.r8(in.cx+0x1364))?1u:0u;
}
std::uint32_t fun_00467d40(Memory& m,const Inputs& in) {
    const auto old=m.r32(in.cx+0x24);
    if(old==in.arg[0]){m.w32(in.cx+0x24,0);m.w32(in.cx+0x28,0);return 1;}
    return (old&0xffffff00u)|1u;
}
std::uint32_t fun_00468610(Memory& m,const Inputs& in) {
    const auto node=m.r32(in.cx+4);
    if(!node)return 0;
    const auto next=m.r32(node+0x30);m.w32(in.cx+4,next);m.w32(node+0x30,0);
    m.w32(in.cx,m.r32(in.cx)-1u);return node;
}
std::uint32_t fun_00478320(Memory& m,const Inputs& in) {
    auto flags=m.r32(in.cx+0x140);
    if((flags&0x10u)==0)return flags&0xffffff00u;
    flags=(flags&0xffffff00u)|((flags&0xffu)&0xefu);
    m.w32(in.cx+0x50,0xffffffffu);m.w32(in.cx+0x140,flags);
    return (flags&0xffffff00u)|1u;
}
std::uint32_t fun_0047bee0(Memory& m,const Inputs& in) {
    return s32(sx16(m.r16(in.cx+0x7c+in.arg[0]*2u)))>0?1u:0u;
}
std::uint32_t fun_0047bf00(Memory& m,const Inputs& in) {
    return s32(sx16(m.r16(in.cx+0xac+in.arg[0]*2u)))>0?1u:0u;
}
std::uint32_t fun_0047cb30(Memory& m,const Inputs& in) {
    const auto value=in.arg[0];
    if(!value){m.w32(in.cx+0xe0,0);return 1;}
    const auto old=m.r32(in.cx+0xe0);
    if(!old||old==value){m.w32(in.cx+0xe0,value);return 1;}
    return 0;
}
std::uint32_t fun_004802c0(Memory& m,const Inputs& in) {
    const auto arr=m.r32(in.cx+0x30),base=m.r32(in.cx+0x24);
    const auto entry=m.r32(arr+in.arg[0]*4u);
    const auto p=base+entry*32u;
    return (m.r32(p)&1u)?p:0u;
}
std::uint32_t fun_00480530(Memory& m,const Inputs& in) {
    const auto arr=m.r32(in.cx+0x40),base=m.r32(in.cx+0x34);
    const auto entry=m.r32(arr+in.arg[0]*4u);
    const auto scaled=entry*5u,p=base+scaled*4u;
    return (m.r32(p)&1u)?p:0u;
}
std::uint32_t fun_004805f0(Memory& m,const Inputs& in) {
    if(in.arg[0]&0xffu){m.w32(in.cx+0x14,0);m.w32(in.cx+0x18,0);m.w32(in.cx+0x1c,0);m.w32(in.cx+0x20,0);return 0;}
    const auto value=m.r32(in.cx+0x1c);
    m.w32(in.cx+0x18,1);m.w32(in.cx+0x14,value);m.w32(in.cx+0x20,value);return value;
}
std::uint32_t fun_0048dc40(Memory&,const Inputs& in) {
    const auto v=s32(in.cx);
    if(v<0||v>15)return 0;
    return static_cast<std::uint32_t>(v<10?v+0x30:v+0x37);
}
namespace {
std::uint32_t copy_active_field(Memory& m,const Inputs& in,std::uint32_t offset) {
    if(!m.r8(in.cx+0x6c))return 0;
    const auto value=m.r32(in.cx+offset);m.w32(in.arg[0],value);return 1;
}
}
std::uint32_t fun_0048e490(Memory& m,const Inputs& in) {return copy_active_field(m,in,0x44);}
std::uint32_t fun_0048e4b0(Memory& m,const Inputs& in) {return copy_active_field(m,in,0x40);}
std::uint32_t fun_0048e4d0(Memory& m,const Inputs& in) {return copy_active_field(m,in,0x38);}
std::uint32_t fun_00490ea0(Memory& m,const Inputs& in) {
    m.w32(in.cx,0);m.w32(in.cx+4,0);m.w32(in.cx+8,0);m.w8(in.cx+12,0);m.w32(in.cx+16,0);return in.cx;
}
std::uint32_t fun_004919e0(Memory& m,const Inputs& in) {
    m.w32(in.cx+4,0);m.w32(in.cx+8,0);m.w8(in.cx+12,1);m.w8(in.cx+13,0);m.w32(in.cx,0x007895acu);return in.cx;
}
std::uint32_t fun_00491b70(Memory& m,const Inputs& in) {
    auto remaining=m.r32(in.cx+8);std::uint32_t sum=0;
    if(s32(remaining)<=0)return sum;
    auto p=m.r32(in.cx+4);
    while(remaining--){sum+=m.r32(p);p+=4;}
    return sum;
}
std::uint32_t fun_004942f0(Memory& m,const Inputs& in) {
    m.w32(in.cx,0);m.w32(in.cx+4,0);m.w8(in.cx+8,0);m.w8(in.cx+9,0);m.w8(in.cx+10,0);m.w32(in.cx+12,0);return in.cx;
}
std::uint32_t fun_00496870(Memory& m,const Inputs& in) {return m.r8(in.cx+0x18)!=0&&m.r8(in.cx+0x19)!=0?1u:0u;}
std::uint32_t fun_00496890(Memory& m,const Inputs& in) {return m.r8(in.cx+0x18)!=0&&m.r8(in.cx+0x19)==0?1u:0u;}
std::uint32_t fun_00496910(Memory& m,const Inputs& in) {return m.r8(in.cx+0x18)==0&&m.r8(in.cx+0x19)==1?1u:0u;}
std::uint32_t fun_00496930(Memory& m,const Inputs& in) {return m.r8(in.cx+0x18)==0&&m.r8(in.cx+0x19)==0?1u:0u;}
std::uint32_t fun_00496ac0(Memory& m,const Inputs& in) {
    if(m.r8(in.cx+0x18)==0)return 0;
    const auto second=m.r8(in.cx+0x19);
    m.w8(in.cx+0x18,0);m.w8(in.cx+0x19,second==0?0u:1u);return 0;
}
std::uint32_t fun_0049e970(Memory& m,const Inputs& in) {
    if((m.r8(in.cx+0x1198)&0xffu)==0)return 0;
    const auto value=m.r32(in.cx+0x119c);return value;
}
}
