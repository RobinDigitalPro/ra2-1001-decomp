#include "leaf_b57_c.hpp"

namespace ra2::recovered::leaf {
namespace {
inline bool signed_lt(std::uint32_t a,std::uint32_t b){return s32(a)<s32(b);}
}

// 0x8990: visit a sentinel-linked list, copy each node's same two fields to
// both destination pairs, assign its ordinal, then seed the two context rows.
std::uint32_t fun_00408990(Memory& m,const Inputs& in){
    const std::uint32_t ctx=in.cx,sentinel=ctx+4;
    const std::uint32_t first=m.r32(sentinel);
    const std::uint32_t list_head=first==sentinel?0u:first;
    std::uint32_t node=first,index=0;
    if(node!=sentinel){
        while(node!=0 && node!=sentinel){
            const auto a=m.r32(node+0x18),b=m.r32(node+0x1c);
            m.w32(node+0x20,a);m.w32(node+0x24,b);
            m.w32(node+0x28,a);m.w32(node+0x2c,b);
            m.w32(node+0x34,index++);
            node=m.r32(node);
        }
    }
    const std::uint32_t row=ctx+0x4c;
    for(unsigned n=0;n<2;++n){
        const auto p=row+0x40u*n;
        m.w32(p-0x0c,list_head);m.w32(p,0xfffffc17u);m.w32(p+4,0xfffffc17u);
        m.w32(p-4,0);m.w32(p-8,0);m.w32(p-0x28,list_head);
        const auto selector=m.r32(p-0x20);
        m.w32(p-0x30,list_head?m.r32(list_head+selector*8u+0x20u):0u);
        m.w32(p-0x2c,0);m.w32(p-0x24,m.r32(p-0x24)&0xfffffffeu);
    }
    m.w32(row,m.r32(row)+m.r32(ctx+0x14));
    return m.r32(row);
}

// 0x20b660: clear a selected table entry and then a signed index suffix.
std::uint32_t fun_0060b660(Memory& m,const Inputs& in){
    const auto ctx=in.cx;constexpr std::uint32_t minus_one=0xffffffffu;
    auto reset=[&](std::uint32_t rec){
        if(!rec)return;
        m.w32(rec+0xb4,minus_one);
        const auto count=m.r32(rec+0x30);
        if(s32(count)>0){for(std::uint32_t i=0;i<count;++i){const auto table=m.r32(rec+0x24);const auto child=m.r32(table+4u*i);m.w32(child+0x74,minus_one);}}
        m.w32(rec+0xac,minus_one);
    };
    if(m.r8(ctx+0x98)){
        const auto selected=m.r32(ctx+0x94);
        if(selected!=minus_one){const auto table=m.r32(ctx+8);reset(m.r32(table+selected*4u));}
        m.w8(ctx+0x98,0);
    }
    const auto count=m.r32(ctx+0x14),stored=m.r32(ctx+0x8c);
    const auto begin=stored==minus_one?0u:stored;
    std::uint32_t eax=begin;
    if(signed_lt(begin,count)){
        for(std::uint32_t i=begin;signed_lt(i,count);++i){
            const auto table=m.r32(ctx+8);const auto rec=m.r32(table+i*4u);
            eax=table;
            if(rec){m.w32(rec+0xb4,minus_one);eax=0;const auto child_count=m.r32(rec+0x30);if(s32(child_count)>0){for(std::uint32_t j=0;j<child_count;++j){const auto child_table=m.r32(rec+0x24);const auto child=m.r32(child_table+4u*j);m.w32(child+0x74,minus_one);eax=j+1;}}m.w32(rec+0xac,minus_one);}
        }
    }
    m.w32(ctx+0x8c,minus_one);
    return eax;
}

// 0x30c60: pack source bits and inject a one after each group of seven bits.
// The initial low source bit seeds the first output byte, as in the entry body.
std::uint32_t fun_00430c60(Memory& m,const Inputs& in){
    std::uint32_t src=in.cx,dst=in.dx;
    const std::uint32_t count=in.arg[0];
    m.w8(dst,m.r8(src)&1u);
    if(count==0)throw std::invalid_argument("zero bit count wraps in original; outside contract");
    std::uint32_t output_units=1, out_bit=0, input_bit=0;
    for(std::uint32_t n=1;n<count;++n){
        ++input_bit;
        if(input_bit%7u==0){
            ++out_bit;
            if(out_bit==8){out_bit=0;++dst;++output_units;m.w8(dst,0);}
            m.w8(dst,m.r8(dst)|(1u<<out_bit));
        }
        const std::uint32_t bit=(m.r8(src+(input_bit/8u))&(1u<<(input_bit%8u)))?1u:0u;
        ++out_bit;
        if(out_bit==8){out_bit=0;++dst;++output_units;m.w8(dst,0);}
        if(bit)m.w8(dst,m.r8(dst)|(1u<<out_bit));
    }
    return 1u+(count-1u)/7u;
}

// 0x30df0: expand packed source bits into output bytes and 16-bit units.
// A zero output unit terminates early; count is a unit bound, not an inverse
// count for 0x30c60. Caller supplies a writable prefix at output-2.
std::uint32_t fun_00430df0(Memory& m,const Inputs& in){
    const auto src=in.cx;std::uint32_t out=in.dx;const auto units=in.arg[0];
    m.w8(out,m.r8(src)&1u);
    if(units==0){m.w16(out-2,0);return 0;}
    std::uint32_t src_bit=0,out_bits=0,units_done=0,input_units=0;bool zero_word=false;
    while(units_done<units){
        ++input_units;
        ++src_bit;
        if(input_units%7u==0)++src_bit;
        const auto bit=(m.r8(src+src_bit/8u)&(1u<<(src_bit%8u)))?1u:0u;
        const auto dst_byte=input_units/8u;
        const auto dst_bit=input_units%8u;
        if(dst_bit==0)m.w8(out+dst_byte,0);
        if(bit)m.w8(out+dst_byte,m.r8(out+dst_byte)|(1u<<dst_bit));
        ++out_bits;
        if(out_bits%16u==0){
            ++units_done;
            if(m.r16(out+out_bits/8u-2u)==0){zero_word=true;break;}
        }
    }
    if(!zero_word)m.w16(out+units*2u-2u,0);
    return units_done;
}

// 0x213c80: instruction-shaped signed raster branches. Each emitted record
// stores the current ECX value at the selected dword; EAX remains the branch's
// final error accumulator (or early sign result), not the output cursor.
std::uint32_t fun_00613c80(Memory& m,const Inputs& in){
    std::uint32_t ecx=in.cx,edx=in.dx;const std::uint32_t arg0=in.arg[0];std::uint32_t edi=arg0,esi=in.arg[1];
    const auto selector=in.arg[2],skip=in.arg[3],cursor_ptr=in.arg[4];
    std::uint32_t ebx=m.r32(cursor_ptr),eax;
    edi-=ecx;esi-=edx;
    eax=s32(edi)<=0?0u:0xffffffffu;
    eax&=2u;eax-=1u;const auto xstep=eax; // SETLE/DEC/AND/DEC produces the original x-step on early return.
    if(s32(esi)<=0)return eax;
    std::uint32_t sign= (edi&0x80000000u)?0xffffffffu:0u;
    std::uint32_t ebp=(edi^sign)-sign;
    if(ebp==0){
        esi-=skip;const auto n=esi;esi-=1u;
        if(s32(n)<=0){m.w32(cursor_ptr,ebx);return 0;}
        eax=esi+1u;
        while(eax){m.w32(ebx+(selector==1?0u:4u),ecx);ebx+=8u;--eax;}
        m.w32(cursor_ptr,ebx);return 0;
    }
    if(esi==ebp){
        eax=skip;
        if(skip)ecx+=xstep;
        esi-=skip;eax=esi;esi-=1u;
        if(s32(eax)<=0){m.w32(cursor_ptr,ebx);return eax;}
        while(eax){m.w32(ebx+(selector==1?0u:4u),ecx);ecx+=xstep;ebx+=8u;--eax;}
        m.w32(cursor_ptr,ebx);return 0;
    }
    if(s32(esi)>s32(ebp)){
        eax=s32(edi)<0?1u-esi:0u;
        if(skip){eax+=ebp;if(s32(eax)>0){ecx+=xstep;eax-=esi;}}
        std::uint32_t rows=esi-skip;
        if(s32(rows)<=0){m.w32(cursor_ptr,ebx);return eax;}
        std::uint32_t left=rows;
        while(left--){m.w32(ebx+(selector==1?0u:4u),ecx);ebx+=8u;eax+=ebp;if(s32(eax)>0){ecx+=xstep;eax-=esi;}}
        m.w32(cursor_ptr,ebx);return eax;
    }
    // Shallow branch: the original uses signed IDIV twice and carries the
    // quotient/remainder pair through the same per-row stores.
    const auto den=s32(esi),wide=s32(ebp);
    const std::uint32_t quotient=static_cast<std::uint32_t>(wide/den);
    std::uint32_t step=quotient*xstep;
    std::uint32_t rem=static_cast<std::uint32_t>(wide%den);
    eax=s32(edi)<0?1u-esi:0u;
    if(skip){eax+=rem;ecx+=step;if(s32(eax)>0){ecx+=xstep;eax-=esi;}}
    std::uint32_t rows=esi-skip;
    if(s32(rows)<=0){m.w32(cursor_ptr,ebx);return eax;}
    std::uint32_t left=rows;
    while(left--){m.w32(ebx+(selector==1?0u:4u),ecx);eax+=rem;ecx+=step;if(s32(eax)>0){ecx+=xstep;eax-=esi;}ebx+=8u;}
    m.w32(cursor_ptr,ebx);return eax;
}

// 0x367dc0: normalize the requested rectangle, preserve signed/unsigned
// truncation points, reject out-of-bounds results, then set the success bit.
std::uint32_t fun_00767dc0(Memory& m,const Inputs& in){
    const auto p=in.cx,flags=m.r32(p+0x80);const auto mode=flags&0x30u;
    std::uint32_t width=in.arg[0]?in.arg[0]:m.r16(p+0xee);
    std::uint32_t height=in.arg[1]?in.arg[1]:m.r16(p+0xf0);
    const auto saved=in.dx;std::uint32_t xoff=in.arg[2],yoff=in.arg[3];
    std::uint32_t x=0,y=0;
    if(s32(xoff)<0&&s32(yoff)<0){
        if(flags&8u){
            if(flags&0x40u){x=m.r16(p+0xfa)/2u;y=m.r16(p+0xfc)/2u;}
            else{x=m.r16(p+0xfa);y=m.r16(p+0xfc);}
            m.w32(p+0x1b4,x);m.w32(p+0x1b8,y);
        }else if(flags&0x40u){
            x=(width-(m.r16(p+0xee)/2u))>>1;y=(height-(m.r16(p+0xf0)/2u))>>1;
            m.w32(p+0x1b4,x);m.w32(p+0x1b8,y);goto bounds;
        }else{x=(width-m.r16(p+0xee))>>1;y=(height-m.r16(p+0xf0))>>1;m.w32(p+0x1b4,x);m.w32(p+0x1b8,y);goto bounds;}
    }else{
        if(flags&0x40u){x=sar(xoff-(xoff&0x80000000u?0xffffffffu:0u),1);y=sar(yoff-(yoff&0x80000000u?0xffffffffu:0u),1);}
        else{x=xoff;y=yoff;}
        if(mode==0x20u){x=width-x;y=height-y;m.w32(p+0x1b4,x);m.w32(p+0x1b8,y);}
        else if(mode==0x30u){m.w32(p+0x1b4,x);m.w32(p+0x1b8,height-y);}
        else{m.w32(p+0x1b4,x);m.w32(p+0x1b8,y);}
    }
bounds:
    x=m.r32(p+0x1b4);y=m.r32(p+0x1b8);
    if(s32(x)<0||s32(y)<0||x>=width||y>=height)return 0xffffffe8u;
    const auto bpp=m.r8(p+0x108);
    if(bpp==1u||bpp==4u){x*=2u;y*=2u;}
    auto linear=y*width+x;
    m.w32(p+0x1ac,width);m.w32(p+0x1bc,linear);m.w32(p+0x1b0,height);
    if(saved){m.w32(p+0x1a8,saved);m.w32(p+8,saved);}
    m.w32(p+0x150,m.r32(p+0x150)|0x10u);return 0xffffffffu;
}
}
