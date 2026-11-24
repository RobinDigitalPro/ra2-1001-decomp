#include "leaf_containers.hpp"

namespace ra2::recovered::leaf {
std::uint32_t fun_0060b830(Memory& m,const Inputs& i) {
    const auto count=m.r32(i.cx+0x14u);
    const auto index=count-1u;
    if(s32(index)<0) return 0;
    return m.r32(m.r32(i.cx+8u)+index*4u);
}
std::uint32_t fun_00407370(Memory& m,const Inputs& i) {
    const auto head=i.cx,node=i.dx;
    m.w32(node+4u,head);const auto first=m.r32(head);m.w32(node,first);m.w32(head,node);
    const auto successor=m.r32(node);m.w32(successor+4u,node);return first;
}
std::uint32_t fun_00407380(Memory& m,const Inputs& i) {
    const auto node=i.cx,next=m.r32(node),prev=m.r32(node+4u);
    m.w32(prev,next);const auto next_again=m.r32(node);const auto prev_again=m.r32(node+4u);
    m.w32(next_again+4u,prev_again);m.w32(node,node);m.w32(node+4u,node);return next_again;
}
std::uint32_t fun_004073b0(Memory& m,const Inputs& i) {
    const auto node=m.r32(i.cx+4u);return node!=m.r32(node+8u)?node:0;
}
std::uint32_t fun_0041b630(Memory& m,const Inputs& i) {
    m.w32(i.cx,i.arg[0]);m.w32(i.cx+4u,i.arg[1]);m.w32(i.cx+8u,i.arg[2]);return i.cx;
}
std::uint32_t fun_00430320(Memory& m,const Inputs& i) {
    const auto p=m.r32(i.cx+4u);return m.r32(p+8u)<=m.r32(p+0xcu)?1u:0u;
}
std::uint32_t fun_004547a0(Memory& m,const Inputs& i) {
    auto index=i.arg[0];auto count=m.r32(i.cx+0x10u);
    if(s32(index)>=s32(count)) return 0;
    --count;m.w32(i.cx+0x10u,count);
    if(s32(index)<s32(count)) {
        do {const auto array=m.r32(i.cx+4u);++index;const auto v=m.r32(array+index*4u);m.w32(array+(index-1u)*4u,v);count=m.r32(i.cx+0x10u);} while(s32(index)<s32(count));
    }
    return 1;
}
std::uint32_t fun_0047a050(Memory& m,const Inputs& i) {m.w32(i.cx+0x24u,m.r32(i.arg[0]));return i.arg[0];}
std::uint32_t fun_00490a30(Memory& m,const Inputs& i) {
    const auto index=i.arg[0],out=i.arg[1];const auto count=m.r32(i.cx+0x54u);
    if(s32(index)<0||s32(index)>=s32(count)){m.w32(out,0);return 0;}
    const auto base=m.r32(i.cx+0x50u);m.w32(out,base+index*0x44u);return 1;
}
std::uint32_t fun_00490a70(Memory& m,const Inputs& i) {
    const auto out=i.arg[0],count=m.r32(i.cx+0x54u);
    m.w32(out,count);
    const auto flag=m.r8(i.cx+0x58u);
    return (count&0xffffff00u)|flag;
}
std::uint32_t fun_004de620(Memory& m,const Inputs& i) {
    const auto container=m.r32(i.cx+4u),index=m.r32(i.cx+8u);return index<m.r32(container+0x10u)?1u:0u;
}
std::uint32_t fun_004f60e0(Memory& m,const Inputs& i) {
    m.w32(i.cx,i.arg[0]);m.w32(i.cx+4u,m.r32(i.arg[1]));m.w8(i.cx+8u,0);m.w32(i.cx+0xcu,0);return i.cx;
}
std::uint32_t fun_00522980(Memory& m,const Inputs& i) {
    const auto dst=i.cx,src1=i.arg[0],src2=i.arg[1];m.w32(dst,m.r32(src1));m.w32(dst+4u,m.r32(src2));m.w16(dst+8u,m.r16(src2+4u));return dst;
}
std::uint32_t fun_00522a60(Memory& m,const Inputs& i) {
    const auto src=i.cx,dst1=i.arg[0],dst2=i.arg[1];m.w32(dst1,m.r32(src));m.w32(dst2,m.r32(src+4u));m.w16(dst2+4u,m.r16(src+8u));return dst2;
}
std::uint32_t fun_00538680(Memory& m,const Inputs& i) {
    const auto index=m.r32(i.cx+0x16cu),count=m.r32(i.cx+0x44u);
    if(s32(index)>=s32(count))return 0;
    return m.r32(m.r32(i.cx+0x38u)+index*4u);
}
std::uint32_t fun_0053b1f0(Memory& m,const Inputs& i) {m.w32(i.arg[0]+8u,i.arg[1]);m.w32(i.arg[0]+4u,i.arg[1]);return 0;}
std::uint32_t fun_005a93f0(Memory& m,const Inputs& i) {
    const auto value=i.arg[0],limit_ptr=m.r32(i.cx+0x1cu);
    m.w32(i.cx+0x2cu,value);
    const auto limit=sx16(m.r16(limit_ptr+6u));
    if(value<limit)return limit;
    const auto clamped=limit-1u;m.w32(i.cx+0x2cu,clamped);return clamped;
}
std::uint32_t fun_005ad530(Memory& m,const Inputs& i) {
    const auto index=i.arg[0]&0xffffu,count=m.r32(i.cx+0x10u);
    if(s32(count)<=static_cast<std::int32_t>(index))return 0;
    return m.r32(m.r32(i.cx+4u)+index*4u);
}
std::uint32_t fun_005cd4d0(Memory& m,const Inputs& i) {
    const auto src=i.cx+0x88u,dst=i.arg[0];m.w32(dst,m.r32(src));m.w32(dst+4u,m.r32(src+4u));m.w32(dst+8u,m.r32(src+8u));return dst;
}
std::uint32_t fun_0062ccb0(Memory& m,const Inputs& i) {
    const auto dst=i.cx+0x18u,src=i.arg[0];m.w16(dst,m.r16(src));const auto last=m.r8(src+2u);m.w8(dst+2u,last);return (src&0xffffff00u)|last;
}
std::uint32_t fun_0062cce0(Memory& m,const Inputs& i) {
    const auto dst=i.cx+0x1cu,src=i.arg[0];m.w32(dst,m.r32(src));m.w32(dst+4u,m.r32(src+4u));const auto last=m.r32(src+8u);m.w32(dst+8u,last);return last;
}
std::uint32_t fun_0065f820(Memory& m,const Inputs& i) {
    const auto index=m.r32(i.cx+0x2cu),out=i.arg[0];
    if(index==0xffffffffu){m.w32(out,0xffffffffu);m.w32(out+4u,0);return out;}
    const auto p=m.r32(i.cx+0x24u);m.w32(out,m.r32(p+0xa4u+index*8u));m.w32(out+4u,m.r32(p+0xa8u+index*8u));return out;
}
std::uint32_t fun_0065f860(Memory& m,const Inputs& i) {
    const auto p=m.r32(i.cx+0x24u),index=m.r32(i.cx+0x2cu),count=m.r32(p+0xa0u),out=i.arg[0];
    if(s32(index+1u)>=s32(count)){m.w32(out,0xffffffffu);m.w32(out+4u,0);return out;}
    m.w32(out,m.r32(p+0xacu+index*8u));m.w32(out+4u,m.r32(p+0xb0u+index*8u));return out;
}
std::uint32_t fun_0065f8d0(Memory& m,const Inputs& i) {
    const auto index=m.r32(i.cx+0x2cu)+1u;m.w32(i.cx+0x2cu,index);
    return index<m.r32(m.r32(i.cx+0x24u)+0xa0u)?1u:0u;
}
std::uint32_t fun_006e6bc0(Memory& m,const Inputs& i) {
    const auto dst=i.cx,src=i.dx,first=m.r32(src),second=m.r32(src+4u);m.w32(dst,first);m.w32(dst+4u,second);return dst;
}
std::uint32_t fun_00701000(Memory& m,const Inputs& i) {
    const auto p=i.cx;m.w32(p+0x800u,0x200u);
    for(std::uint32_t n=0;n<0x200u;++n)m.w32(p+n*4u,0);
    m.w32(p+0x804u,0);return p;
}
std::uint32_t fun_00701050(Memory& m,const Inputs& i) {
    const auto index=i.arg[0],limit=m.r32(i.cx+0x800u);
    if(s32(index)<s32(limit))m.w32(i.cx+index*4u,m.r32(i.cx+index*4u)+1u);return index;
}
std::uint32_t fun_00719920(Memory& m,const Inputs& i) {
    const auto index=i.arg[0],count=m.r32(i.cx+0x38u);if(s32(index)<0||s32(index)>=s32(count))return 0;
    return m.r32(i.cx+0x2cu)+index*0xcu;
}
std::uint32_t fun_00752310(Memory& m,const Inputs& i) {
    const auto out=i.arg[0],index=i.arg[1],count=m.r32(i.cx);
    if(s32(index)<0||s32(index)>=s32(count))return 0;
    m.w32(out,m.r32(i.cx+8u)+index*0xf8u);return 1;
}
std::uint32_t fun_00754400(Memory& m,const Inputs& i) {
    const auto out=i.arg[0],index=i.arg[1],count=m.r32(i.cx);
    if(s32(index)<0||s32(index)>=s32(count))return 0;
    m.w32(out,m.r32(m.r32(i.cx+8u)+index*4u));return 1;
}
}
