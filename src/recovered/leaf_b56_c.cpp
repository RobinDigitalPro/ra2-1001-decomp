#include "leaf_b56_c.hpp"

namespace ra2::recovered::leaf {
namespace {
inline bool slt(std::uint32_t a,std::uint32_t b){return s32(a)<s32(b);}
inline std::uint32_t sxbyte(std::uint32_t a){return sx8(a);}
inline void copy4(Memory& m,std::uint32_t dst,std::uint32_t src){
    for(unsigned n=0;n<4;++n){const auto v=m.r32(src+4*n);m.w32(dst+4*n,v);}
}
}

// 0x1fdf0: clip the second origin/extent record against the first, in the
// original order. Intermediate signed checks matter when endpoint sums wrap.
std::uint32_t fun_0041fdf0(Memory& m,const Inputs& in){
    const std::uint32_t out=in.cx,r1=in.dx,r2=in.arg[0];
    std::uint32_t left=m.r32(r2),top=m.r32(r2+4),w=m.r32(r2+8),h=m.r32(r2+12);
    const std::uint32_t x1=m.r32(r1),y1=m.r32(r1+4),w1=m.r32(r1+8),h1=m.r32(r1+12);
    if(!slt(0,w1)||!slt(0,h1)||!slt(0,w)||!slt(0,h))goto fail;
    if(slt(left,x1)){w+=left-x1;left=x1;}
    if(slt(w,1))goto fail;
    if(slt(top,y1)){h+=top-y1;top=y1;}
    if(slt(h,1))goto fail;
    if(slt(x1+w1,left+w))w=x1-left+w1;
    if(slt(w,1))goto fail;
    if(slt(y1+h1,top+h))h=y1-top+h1;
    if(slt(h,1))goto fail;
    // The second origin is reloaded here; accumulator aliases can change it.
    if(in.arg[1])m.w32(in.arg[1],m.r32(in.arg[1])+m.r32(r2)-left);
    if(in.arg[2])m.w32(in.arg[2],m.r32(in.arg[2])+m.r32(r2+4)-top);
    m.w32(out,left);m.w32(out+4,top);m.w32(out+8,w);m.w32(out+12,h);return out;
fail:
    m.w32(out,0);m.w32(out+4,0);m.w32(out+8,0);m.w32(out+12,0);return out;
}

// 0x242b0: byte-exact header predicates plus a bounded uint16 record count.
std::uint32_t fun_004242b0(Memory& m,const Inputs& in){
    const auto p=in.cx;
    const std::uint32_t magic=m.r32(p+0x8c);
    bool ok=magic==0x2046504cu;
    ok=ok&&(m.r32(p+0x9c)==0x4d494e41u);
    ok=ok&&(m.r16(p+0x90)==0x100u);
    ok=ok&&(m.r32(p+0x94)<=0xffffu);
    ok=ok&&(m.r16(p+0x98)<=0x100u);
    ok=ok&&(m.r16(p+0x9a)==0x500u);
    ok=ok&&(m.r16(p+0xa0)==0x140u);
    ok=ok&&(m.r16(p+0xa2)==0xc8u);
    ok=ok&&(m.r8(p+0xa9)<=1u);
    ok=ok&&(m.r8(p+0xab)==1u);
    ok=ok&&(m.r8(p+0xaa)==0u);
    ok=ok&&(m.r8(p+0xa8)==0u);
    if(ok){
        const std::uint32_t count=m.r16(p+0x92);
        std::uint32_t cursor=p+0x80e;
        for(std::uint32_t i=0;i<count;++i,cursor+=6){if(m.r16(cursor)>0x100u){ok=false;break;}}
    }
    return (magic&0xffffff00u)|(ok?1u:0u); // only AL is defined for valid-memory outcomes
}

// 0x31ec0: edge-ordered overlap validation, sequential copy/clamp stores.
std::uint32_t fun_00431ec0(Memory& m,const Inputs& in){
    const std::uint32_t out=in.arg[0],r1=in.arg[1],r2=in.arg[2];
    if(slt(m.r32(r2+12),m.r32(r1+4))||slt(m.r32(r1+12),m.r32(r2+4))||
       slt(m.r32(r2+8),m.r32(r1))||slt(m.r32(r1+8),m.r32(r2))){
        m.w32(out,0);m.w32(out+4,0);m.w32(out+8,0xffffffffu);m.w32(out+12,0xffffffffu);
        return 0;
    }
    copy4(m,out,r1);
    auto v=m.r32(r2+4);if(slt(m.r32(out+4),v))m.w32(out+4,v);
    v=m.r32(r2);if(slt(m.r32(out),v))m.w32(out,v);
    v=m.r32(r2+12);if(slt(v,m.r32(out+12)))m.w32(out+12,v);
    v=m.r32(r2+8);if(slt(v,m.r32(out+8)))m.w32(out+8,v);
    return 1;
}

// 0x5ec50: combine origin/extent records; retain instruction-order edge
// expansion and the conditional +1 adjustment rather than imposing a named
// rectangle convention.
std::uint32_t fun_0045ec50(Memory& m,const Inputs& in){
    const std::uint32_t out=in.cx,r1=in.dx,r2=in.arg[0];
    const std::uint32_t x1=m.r32(r1),y1=m.r32(r1+4),w1=m.r32(r1+8),h1=m.r32(r1+12);
    const std::uint32_t x2=m.r32(r2),y2=m.r32(r2+4),w2=m.r32(r2+8),h2=m.r32(r2+12);
    if(!slt(0,w1)||!slt(0,h1)){copy4(m,out,r2);return out;}
    if(!slt(0,w2)||!slt(0,h2)){copy4(m,out,r1);return out;}
    std::uint32_t x=x1,w=w1,y=y1,h=h1;
    if(slt(x1,x2)){x=x1;}else{w=w1+(x1-x2);x=x2;}
    const std::uint32_t r2right=x2+w2, r1right=x+w;
    if(slt(r1right,r2right))w=r2right-x+1u;
    if(slt(y1,y2)){y=y1;}else{h=h1+(y1-y2);y=y2;}
    const std::uint32_t r2bottom=y2+h2, r1bottom=y+h;
    if(slt(r1bottom,r2bottom))h=r2bottom-y+1u;
    m.w32(out,x);m.w32(out+4,y);m.w32(out+8,w);m.w32(out+12,h);
    return out;
}

// 0x995f0: scan signed 16-bit pairs through the exact sentinel, pack width
// (low word) and height (high word) into one output dword.
std::uint32_t fun_004995f0(Memory& m,const Inputs& in){
    const std::uint32_t p=in.arg[1],out=in.arg[0];
    std::int32_t maxx=-512,minx=512,maxy=-512,miny=512;
    std::uint32_t width=0,height=0;
    if(p){
        std::uint32_t q=p;
        for(;;q+=4){
            const auto ux=m.r16(q),uy=m.r16(q+2);
            if(ux==0x7fffu&&uy==0x7fffu)break;
            const auto x=s32(sx16(ux)),y=s32(sx16(uy));
            if(maxx<x)maxx=x;if(minx>x)minx=x;
            if(maxy<y)maxy=y;if(miny>y)miny=y;
        }
        const std::int32_t dx=maxx-minx+1,dy=maxy-miny+1;
        width=static_cast<std::uint32_t>(dx<1?1:dx)&0xffffu;
        height=static_cast<std::uint32_t>(dy<1?1:dy)&0xffffu;
    }
    m.w32(out,width|(height<<16));return out;
}

// 0x157530: point-in-transformed-bounds predicates, preserving signed byte
// offsets and every strict/inclusive branch from the original sequence.
std::uint32_t fun_00557530(Memory& m,const Inputs& in){
    const auto obj=in.cx,rec=in.arg[0];
    const std::uint32_t x=sx16(m.r16(rec+0x24)),y=sx16(m.r16(rec+0x26));
    std::uint32_t off=0;
    if((in.arg[1]&0xffu)!=0){
        off=sxbyte(m.r8(rec+0x11b));
        if(m.r8(rec+0x11c)!=0){
            const std::uint32_t lim=m.r32(obj+0xf0)+m.r32(obj+0xfc)*2u+4u+off;
            if(slt(x+y,lim))off+=1u;
        }
    }
    const std::uint32_t f0=m.r32(obj+0xf0),fc=m.r32(obj+0xfc),sum=x+y;
    std::uint32_t lim=f0+fc*2u+off;
    if(!slt(lim,sum))return 0;
    const std::uint32_t f104=m.r32(obj+0x104);
    lim=f0+(f104+fc)*2u+2u+off;
    if(slt(lim,sum))return 0;
    const std::uint32_t f8=m.r32(obj+0xf8),f100=m.r32(obj+0x100);
    lim=(f100+f8)*2u-f0;
    if(!slt(x-y,lim))return 0;
    lim=f0-f8*2u;
    if(!slt(y-x,lim))return 0;
    return 1;
}

// 0x1657c0: signed 16-bit coordinate transform. The original uses SAR for
// negative halves, low-word stack packing, and a final dword store.
std::uint32_t fun_005657c0(Memory& m,const Inputs& in){
    const std::uint32_t obj=in.cx,out=in.arg[0],pair=in.arg[1],mode=in.arg[2]&0xffu;
    const std::uint32_t x=sx16(m.r16(pair)),y=sx16(m.r16(pair+2));
    const auto half_signed=[](std::uint32_t v){const auto sign=(v&0x80000000u)?0xffffffffu:0u;return sar(v-sign,1);};
    const std::uint32_t f0=m.r32(obj+0xf0),f8=m.r32(obj+0xf8),fc=m.r32(obj+0xfc);
    const std::uint32_t dx=sar(x-y+((f0&1u)?1u:0u),1)+half_signed(f0)-f8;
    const std::uint32_t dy=y-f0+x-fc;
    const std::uint32_t half104=half_signed(m.r32(obj+0x104)),half100=half_signed(m.r32(obj+0x100));
    const auto abs32=[](std::uint32_t v){return (v&0x80000000u)?0u-v:v;};
    const std::uint32_t absx=abs32(dx-half100),absy=abs32(dy-half104);
    std::uint32_t primary,secondary;
    if(s32(absx)>=s32(absy)){
        primary=slt(dy,half104)?(mode?1u:0u):m.r32(obj+0x104)-(mode?1u:0u);
        secondary=dx;
    }else{
        primary=dy;
        secondary=slt(dx,half100)?(mode?1u:0u):m.r32(obj+0x100)-(mode?1u:0u);
    }
    const std::uint32_t a=primary+fc,b=f8+secondary;
    const std::uint32_t lo=sar(a+1u,1)+b,hi=sar(a,1)-b+m.r32(obj+0xf0);
    m.w32(out,(hi&0xffffu)<<16|(lo&0xffffu));return out;
}

// 0x185c20: reverse scan of packed coordinate words. SI is loaded from the
// high word of the saved current dword at the common comparison point on both
// branches; it is not conditional on the low-coordinate update.
std::uint32_t fun_00585c20(Memory& m,const Inputs& in){
    const std::uint32_t out=in.cx,obj=in.dx;
    std::uint32_t count=m.r32(obj+0x10);
    std::int32_t minx=999,maxx=0,miny=999,maxy=0;
    if((count-1u)<0x80000000u){
        const std::uint32_t array=m.r32(obj+4);
        for(std::uint32_t n=count;n>0;--n){
            const std::uint32_t packed=m.r32(array+4u*(n-1u));
            const auto x=s32(sx16(packed)),y=s32(sx16(packed>>16));
            if(x<minx)minx=x;if(y<miny)miny=y;
            if(x>maxx)maxx=x;if(y>maxy)maxy=y;
        }
    }
    m.w32(out,static_cast<std::uint32_t>(minx));
    m.w32(out+4,static_cast<std::uint32_t>(miny));
    m.w32(out+8,static_cast<std::uint32_t>(maxx-minx+1));
    m.w32(out+12,static_cast<std::uint32_t>(maxy-miny+1));
    return out;
}
}
