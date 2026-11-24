#include "leaf_b21_a.hpp"

#include <cstdint>

namespace ra2::recovered::leaf {

std::uint32_t fun_004071f0(Memory& m,const Inputs& i) {
    m.w32(i.cx,i.cx); m.w32(i.cx+4,i.cx); m.w32(i.cx+8,i.cx); return 0;
}

std::uint32_t fun_00407210(Memory& m,const Inputs& i) {
    const auto node=i.dx, key=m.r32(i.dx+8u);
    auto head=m.r32(i.cx);
    std::uint32_t eax=0;
    if(!head || head==m.r32(head+8)) {
        auto next=m.r32(i.cx+4);
        m.w32(node,i.cx); m.w32(node+4,next); m.w32(i.cx+4,node);
        auto link=m.r32(node+4); m.w32(link,node); return eax;
    }
    for(;;) {
        const auto next=m.r32(head+8);
        if(head==next)break;
        if(s32(key)>s32(next)) { ++eax; head=m.r32(head); continue; }
        auto prior=m.r32(head+4); m.w32(node,head); m.w32(node+4,prior);
        m.w32(head+4,node); auto link=m.r32(node+4); m.w32(link,node); return eax;
    }
    {
        auto prior=m.r32(i.cx+4); m.w32(node,i.cx); m.w32(node+4,prior);
        m.w32(i.cx+4,node); auto link=m.r32(node+4); m.w32(link,node); return eax;
    }
}

std::uint32_t fun_00407460(Memory& m,const Inputs& i) {
    const auto p=i.dx-8u; const auto v=m.r32(i.cx); m.w32(p,v); m.w32(i.cx,p); return p;
}
std::uint32_t fun_00407f90(Memory& m,const Inputs& i) { return m.r32(i.cx+0xcu)&1u; }
std::uint32_t fun_00408c60(Memory& m,const Inputs& i) { return m.r32(i.cx+0x4c)-m.r32(i.cx+0x50); }
std::uint32_t fun_00409240(Memory& m,const Inputs& i) { return m.r32(i.cx+0x34)-m.r32(i.cx+0x38); }

std::uint32_t fun_00408d90(Memory& m,const Inputs& i) {
    auto c=m.r32(i.cx+0x1c)-1u; m.w32(i.cx+0x1c,c);
    if(static_cast<std::int32_t>(c)<0) m.w32(i.cx+0x1c,0);
    const auto p=m.r32(i.cx); auto n=m.r32(p+0x98)-1u;
    m.w32(p+0x98,n); if(static_cast<std::int32_t>(n)<0) m.w32(p+0x98,0);
    return p;
}

std::uint32_t fun_0042e8f0(Memory& m,const Inputs& i) {
    auto count=m.r32(i.cx+0x60); if(!count) return 0;
    const auto wanted=i.arg[0];
    for(std::uint32_t row=0;row<8;++row) {
        const auto base=i.cx+row*12u;
        for(std::uint32_t col=0;col<3;++col) {
            const auto obj=m.r32(base+col*4u);
            if(obj && (m.r8(obj+0xc)&2u) && (wanted==0xffffffffu || wanted==m.r32(obj+0x110))) return obj;
        }
    }
    return 0;
}

std::uint32_t fun_0042f1f0(Memory& m,const Inputs& i) {
    const auto p=i.cx;
    m.w32(p+4,1);m.w32(p+8,0);m.w32(p+0xc,0xffffffffu);m.w32(p+0x10,0xffffffffu);
    m.w32(p+0x14,0);m.w16(p+0x18,0);m.w16(p+0x1a,0);
    for(auto o:{0x1cu,0x20u,0x21u,0x22u,0x23u,0x24u,0x25u})m.w8(p+o,0);
    for(auto o:{0x28u,0x2cu,0x30u,0x34u,0x38u})m.w32(p+o,0);
    m.w32(p+0x3c,0xffffffffu);m.w32(p+0x40,0xffffffffu);
    m.w32(p+0x44,0);m.w32(p+0x48,0);m.w32(p+0x4c,0);
    m.w32(p,0x78773c); return p;
}

std::uint32_t fun_00431d40(Memory& m,const Inputs& i) {
    const auto p=m.r32(i.cx+4); if(!p)return 0;
    const auto ix=i.arg[0]&0xffffu; const auto value=m.r16(m.r32(p+0x18)+ix*2u);
    if(!value)return 0; return m.r32(p+0x14)*(value-1u)+m.r32(p+0x1c);
}

std::uint32_t fun_0044d010(Memory& m,const Inputs& i) {
    m.w8(i.cx+0x530,0); std::uint32_t off=0,eax=0;
    for(std::uint32_t slot=0;off<0x4c8;off+=0x44,slot++) {
        eax=m.r32(i.cx+0x418);
        const auto flags=m.r8(eax+off+0xd14); if(!flags)continue;
        eax=m.r32(i.cx+0x454+slot*4u); if(!eax)continue;
        const auto v=m.r32(eax+0x98);m.w8(eax+0x102,1);m.w8(eax+0x103,0);m.w32(eax+0x104,v);m.w8(eax+0x101,1);
    }
    return eax;
}

static std::uint32_t remove_word(Memory& m,const Inputs& i,std::uint32_t width,bool wide) {
    auto index=i.arg[0]; auto count=m.r32(i.cx+0x10);
    if(static_cast<std::int32_t>(index)>=static_cast<std::int32_t>(count))return 0;
    --count; m.w32(i.cx+0x10,count);
    if(static_cast<std::int32_t>(index)>=static_cast<std::int32_t>(count))return 1;
    auto arr=m.r32(i.cx+4); auto src=arr+(index+1u)*width; auto dst=arr+index*width;
    do { auto lo=m.r32(src); m.w32(dst,lo); if(wide){auto hi=m.r32(src+4);m.w32(dst+4,hi);} src+=width;dst+=width; }
    while(static_cast<std::int32_t>(++index)<static_cast<std::int32_t>(count));
    return 1;
}
static std::uint32_t remove_dword(Memory& m,const Inputs& i) {
    auto eax=i.arg[0]; auto edx=m.r32(i.cx+0x10);
    if(s32(eax)>=s32(edx)) return eax&0xffffff00u;
    --edx; m.w32(i.cx+0x10,edx);
    if(s32(eax)>=s32(edx)) return (eax&0xffffff00u)|1u;
    do {
        const auto array=m.r32(i.cx+4);
        ++eax;
        const auto next=m.r32(array+eax*4u);
        m.w32(array+eax*4u-4u,next);
        edx=m.r32(i.cx+0x10);
    } while(s32(eax)<s32(edx));
    return (eax&0xffffff00u)|1u;
}
std::uint32_t fun_004547e0(Memory&m,const Inputs&i){return remove_dword(m,i);}
std::uint32_t fun_00567e60(Memory&m,const Inputs&i){return remove_word(m,i,8,true);}
std::uint32_t fun_0058bdb0(Memory&m,const Inputs&i){return remove_dword(m,i);}
std::uint32_t fun_005bd500(Memory&m,const Inputs&i){return remove_dword(m,i);}
std::uint32_t fun_00612f30(Memory&m,const Inputs&i){return remove_dword(m,i);}
std::uint32_t fun_00613910(Memory&m,const Inputs&i){return remove_dword(m,i);}
std::uint32_t fun_006139a0(Memory&m,const Inputs&i){return remove_dword(m,i);}
std::uint32_t fun_006139e0(Memory&m,const Inputs&i){return remove_dword(m,i);}
std::uint32_t fun_00626090(Memory&m,const Inputs&i){return remove_dword(m,i);}
std::uint32_t fun_00633e40(Memory&m,const Inputs&i){return remove_dword(m,i);}
std::uint32_t fun_006943e0(Memory&m,const Inputs&i){return remove_dword(m,i);}
std::uint32_t fun_006d4fe0(Memory&m,const Inputs&i){return remove_dword(m,i);}
std::uint32_t fun_007076a0(Memory&m,const Inputs&i){return remove_dword(m,i);}
std::uint32_t fun_006e0ad0(Memory&m,const Inputs&i){const auto v=m.r32(i.cx+0x228);m.w32(i.cx+0x22c,v);return v;}
std::uint32_t fun_006e0ae0(Memory&m,const Inputs&i){const auto v=m.r32(i.cx+0x22c);m.w32(i.cx+0x228,v);return v;}

std::uint32_t fun_0047bf60(Memory&m,const Inputs&i){auto x=i.arg[0];m.w16(i.cx+0x7c+x*2u,m.r16(i.cx+0x7c+x*2u)+1u);return x;}
std::uint32_t fun_0047bf70(Memory&m,const Inputs&i){auto x=i.arg[0];m.w16(i.cx+0x7c+x*2u,m.r16(i.cx+0x7c+x*2u)-1u);return x;}
std::uint32_t fun_0047bf80(Memory&m,const Inputs&i){auto x=i.arg[0];m.w16(i.cx+0xac+x*2u,m.r16(i.cx+0xac+x*2u)+1u);return x;}
std::uint32_t fun_0047bf90(Memory&m,const Inputs&i){auto x=i.arg[0];m.w16(i.cx+0xac+x*2u,m.r16(i.cx+0xac+x*2u)-1u);return x;}

std::uint32_t fun_0047ff80(Memory&m,const Inputs&i){
    const auto count=m.r32(i.cx+4);m.w32(i.cx+0x28,0);if(static_cast<std::int32_t>(count)<=0)return count;
    auto off=0u,idx=0u;const auto output=m.r32(i.cx+0x30);
    while(idx<count){auto p=m.r32(i.cx+0x24)+off;m.w32(p,m.r32(p)&~1u);p=m.r32(i.cx+0x24)+off;m.w32(p,m.r32(p)&~2u);p=m.r32(i.cx+0x24)+off;off+=0x20u;m.w32(p,m.r32(p)&~4u);++idx;
        const auto base=m.r32(i.cx+0x24)+off-0x20u;for(auto delta:{4u,8u,12u,16u,24u})m.w32(base+delta,0);m.w32(output+idx*4u-4u,0);}
    return off;
}

std::uint32_t fun_00485fa0(Memory&m,const Inputs&i){
    const auto table=m.r32(i.cx+4); auto dst=i.arg[0]-2u,src=i.arg[1]; auto count=i.arg[2];std::uint32_t eax=0;
    while(count){--count;dst+=2;eax=m.r8(src++);if(eax)m.w16(dst,m.r16(table+eax*2u));}
    return eax;
}

std::uint32_t fun_00490c60(Memory&m,const Inputs&i){
    const auto p=i.cx, first=p+4u, second=p+0x10u;
    m.w32(first+4,0);m.w32(first+8,0);m.w32(first,0x785afc);
    m.w32(second+4,0);m.w32(second+8,0);m.w32(second,0x785afc);m.w32(p,0x785af4);
    auto a=m.r32(second+4);if(a){auto b=m.r32(second+8);if(b){m.w32(b+4,a);a=m.r32(second+4);b=m.r32(second+8);m.w32(a+8,b);m.w32(second+8,0);m.w32(second+4,0);}}
    auto tail=m.r32(first+4);m.w32(second+8,first);m.w32(second+4,tail);tail=m.r32(first+4);if(tail)m.w32(tail+8,second);m.w32(first+4,second);return p;
}
std::uint32_t fun_00490dd0(Memory&m,const Inputs&i){fun_00490c60(m,i);m.w32(i.cx,0x785aec);return i.cx;}

std::uint32_t fun_004cebc0(Memory&m,const Inputs&i){
    const auto p=i.cx; m.w32(p+0x10,i.arg[1]);m.w32(p+0xc,i.arg[0]);m.w32(p+0x18,i.arg[3]);m.w32(p+0x14,i.arg[2]);
    m.w32(p+4,0);m.w32(p+8,0);m.w8(p+0x1c,0);m.w8(p+0x1e,0);m.w8(p+0x1d,static_cast<std::uint8_t>(i.arg[5]));m.w32(p+0x20,i.arg[4]);m.w32(p,0x78c82c);
    if(static_cast<std::uint8_t>(i.arg[5]))m.w32(p+0x20,i.arg[4]|5u);return p;
}

std::uint32_t fun_004d0d70(Memory&,const Inputs&i){
    switch(i.cx){case 0:return 0x6a1;case 1:return 0x510;case 2:return 0x513;case 3:return 0x51e;case 4:return 0x514;case 5:return 0x51f;case 6:return 0x520;default:return i.cx==7?0x521u:0xffffffffu;}
}
std::uint32_t fun_004d1590(Memory&,const Inputs&i){
    if(i.cx==0x6a2)return 0;if(i.cx>=0x522&&i.cx<=0x527)return i.cx-0x522u+1u;
    return i.cx==0x528?7u:0xffffffffu;
}

std::uint32_t fun_0052d0a0(Memory&m,const Inputs&i){
    const auto bit=i.dx;auto ecx=bit&0x80000007u;if(static_cast<std::int32_t>(ecx)<0)ecx=(ecx-1u)|0xfffffff8u,ecx+=1u;
    auto mask=std::uint8_t(1u<<(ecx&31u));auto rem=static_cast<std::uint32_t>(static_cast<std::int32_t>(bit)>>31)&7u;
    auto addr=i.cx+sar(bit+rem,3);auto v=m.r8(addr);if(i.arg[0])v|=mask;else v&=~mask;m.w8(addr,v);return addr;
}

std::uint32_t fun_00557ab0(Memory&m,const Inputs&i){m.w8(i.cx+0x1154,m.r8(i.cx+0x1154)+1u);return 0;}
std::uint32_t fun_00567e60(Memory&,const Inputs&); // declaration already defined above

std::uint32_t fun_00591b20(Memory&m,const Inputs&i){
    auto a=m.r32(i.cx+0x98), b=i.arg[0];if(a==0x1c&&b==5)return a;if(a==0x13)return a;
    const auto prior=m.r32(i.cx+0xa0);if(prior!=0xffffffffu){m.w32(i.cx+0x98,b);m.w32(i.cx+0x9c,prior);m.w8(i.cx+0xa4,0);return a;}
    m.w32(i.cx+0x9c,a);m.w32(i.cx+0x98,b);m.w8(i.cx+0xa4,0);return a;
}

std::uint32_t fun_0059b750(Memory&,const Inputs&i){auto x=static_cast<std::uint8_t>(i.arg[0]);switch(x){case 0xa:return 0x20;case 0xb3:return 0x7c;case 0xc4:return 0x2d;case 0xcd:return 0x3d;case 0xb4:case 0xda:case 0xc2:case 0xbf:case 0xc6:case 0xc3:case 0xd1:case 0xc5:case 0xd8:case 0xb5:case 0xc0:case 0xc1:case 0xd9:case 0xd5:return 0x2b;default:return x;}}
std::uint32_t fun_005b2170(Memory&m,const Inputs&i){return i.cx+m.r32(i.cx+0x2b4)*2u+0x28u;}

std::uint32_t fun_005c3120(Memory&,const Inputs&i){if(i.cx>=0x411&&i.cx<=0x417)return i.cx-0x411u;return i.cx==0x418?7u:0xffffffffu;}
std::uint32_t fun_0060d5c0(Memory&,const Inputs&i){const auto a=static_cast<std::uint8_t>(i.arg[1]);if(i.cx==1)return a==0xb?1u:0u;if(i.cx!=0xb)return 0;return (a==0xb||a==0)?1u:0u;}

std::uint32_t fun_006343a0(Memory&m,const Inputs&i){
    const auto a=i.cx,b=i.arg[0];const auto dx0=m.r8(a),sx0=m.r8(b);auto d0=dx0>sx0?dx0-sx0:sx0-dx0;
    const auto d1=m.r8(a+1),s1=m.r8(b+1);auto d1v=d1>s1?d1-s1:s1-d1;
    const auto d2=m.r8(a+2),s2=m.r8(b+2);auto d2v=d2>s2?d2-s2:s2-d2;
    return d2v*3u+d0*2u+d1v*4u;
}
std::uint32_t fun_0065a3b0(Memory&m,const Inputs&i){const auto ix=i.arg[0],v=i.arg[1];m.w32(i.cx+ix*4u+0x632u,v);return v;}
std::uint32_t fun_0065f8b0(Memory&m,const Inputs&i){m.w32(i.cx+0x2c,0xffffffffu);return 1;}

std::uint32_t fun_00668b40(Memory&m,const Inputs&i){
    const auto wanted=i.arg[0];if(wanted==0xfffffffeu)return 0;
    auto count=m.r32(i.cx+0x27f0);auto arr=m.r32(i.cx+0x27e4);
    for(std::uint32_t n=0;n<count;++n){auto p=m.r32(arr+n*4u);auto x=(m.r32(p+0x55)==0xfffffffeu&&m.r32(p+0x51)==0xffffffffu)?0xfffffffeu:m.r32(p+0x51);if(x==wanted)return 1;}
    for(std::uint32_t n=0;n<8;++n)if(m.r32(i.cx+0x84+n*4u)==wanted)return 1;return 0;
}

std::uint32_t fun_00676e90(Memory&m,const Inputs&i){return static_cast<std::int32_t>(m.r32(i.cx+0x50))>0?1u:0u;}

std::uint32_t fun_0071af60(Memory&m,const Inputs&i){return m.r32(i.cx+0x34+i.arg[0]*4u);}

std::uint32_t fun_00725450(Memory&m,const Inputs&i){
    auto p=m.r32(i.cx+0xc);if(!p)return 0;auto data=m.r32(i.cx+0x10);if(!data)return 0;
    const auto off=i.arg[0],limit=m.r32(p+0x20);if(off>=limit)return 0;const auto c=m.r8(data+off);if(c==0)return 1;if(c==1)return 2;if(c==2)return 3;return 0;
}
std::uint32_t fun_0075a0e0(Memory&m,const Inputs&i){auto p=m.r32(i.cx);if(!p)return 0;std::uint32_t n=0;while(m.r8(p+n))++n;return n;}
std::uint32_t fun_00765030(Memory&m,const Inputs&i){
    if(!i.dx)return 1;auto count=static_cast<std::int16_t>(m.r16(i.cx+0x714));if(count<=0)return 0;
    const auto flag=m.r8(i.cx+0x716);if(!(flag&3u))return 0;auto p=m.r32(i.cx+0x71c);
    for(std::int32_t n=0;n<count;++n){if(m.r16(p)==static_cast<std::uint16_t>(i.dx))return 1;p+=4;}return 0;
}
std::uint32_t fun_007684a0(Memory&m,const Inputs&i){m.w32(i.cx+0x148,m.r32(i.cx+0x148)+i.dx);return 0;}

std::uint32_t fun_007712d1(Memory&m,const Inputs&i){auto a=i.arg[0],b=i.arg[1],n=i.arg[2];if(!n)return 0;--n;while(n){auto x=m.r16(a);if(!x||x!=m.r16(b))break;a+=2;b+=2;--n;}return m.r16(a)-m.r16(b);}
std::uint32_t fun_00772644(Memory&m,const Inputs&i){auto p=i.arg[0];m.w32(p,m.r32(p)+4u);auto q=m.r32(p);return m.r32(q-4u);}
std::uint32_t fun_00774fb8(Memory&m,const Inputs&i){auto p=i.arg[0];m.w32(p+0x50,0x817b48);m.w32(p+0x14,1);return p;}

std::uint32_t fun_00778e5d(Memory&,const Inputs&i){
    const auto low=i.arg[0], high=i.arg[1];if(high==0x7ff00000u&&low==0)return 1;if(high==0xfff00000u&&low==0)return 2;
    const auto high_word=high>>16;if((high_word&0x7ff8u)==0x7ff8u)return 3;if(high_word==0x7ff0u&&(high&0x7ffffu)==0&&low!=0)return 4;return 0;
}

std::uint32_t fun_0077b5b7(Memory&m,const Inputs&i){auto p=i.arg[0];std::uint32_t eax=0;for(;;){auto c=m.r8(p++);if(!c)return eax;std::int32_t v=static_cast<std::int8_t>(c);if(c>='a'&&c<='f')v=static_cast<std::int8_t>(c+0xd9u);else if(c>='A'&&c<='F')v=static_cast<std::int8_t>(c+0xf9u);eax=(eax<<4)+static_cast<std::uint32_t>(v-48);}}

std::uint32_t fun_0077ff22(Memory&m,const Inputs&i){
    auto remp=i.arg[2];if(!m.r32(remp))return 0;auto dstp=i.arg[1];auto src=i.arg[0];
    while(m.r32(remp)){auto c=m.r8(src);if(!c)break;auto dst=m.r32(dstp);m.w8(dst,c);m.w32(dstp,m.r32(dstp)+1u);++src;m.w32(remp,m.r32(remp)-1u);}
    return 0;
}

std::uint32_t fun_0078048d(Memory&m,const Inputs&i){auto p=i.arg[0];auto a=m.r32(p),b=m.r32(p+4),c=m.r32(p+8);const auto na=a*2u,nb=b*2u,nc=(c*2u)|(b>>31);m.w32(p,na);m.w32(p+4,nb|(a>>31));m.w32(p+8,nc);return p;}
std::uint32_t fun_007827fb(Memory&m,const Inputs&i){auto p=i.arg[0];m.w32(p,m.r32(p)+4u);auto q=m.r32(p);return m.r32(q-4u);}

} // namespace ra2::recovered::leaf
