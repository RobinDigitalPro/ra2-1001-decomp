#include "recovered/global_b60_c.hpp"
#include <array>

namespace ra2::recovered::global_b26 {
namespace {
std::uint32_t sar32(std::uint32_t v,unsigned n) { return sar(v,n); }
void copy_rep_forward(Memory& m,std::uint32_t dst,std::uint32_t src,std::uint32_t n) {
    auto words=n>>2;
    while(words--){const auto v=m.r32(src);m.w32(dst,v);src+=4u;dst+=4u;}
    for(auto tail=n&3u;tail;--tail){const auto v=m.r8(src);m.w8(dst,v);++src;++dst;}
}

std::uint32_t remove_entry(Memory& m,const Inputs& i,bool wide) {
    const auto obj=i.cx;
    const auto count_off=wide?0x28u:0x38u;
    const auto table_off=wide?0x30u:0x40u;
    const auto records_off=wide?0x24u:0x34u;
    const auto stride=wide?32u:20u;
    const auto idx=i.arg[2];
    if(m.r32(obj+count_off)==0)return 0;
    const auto initial_table=m.r32(obj+table_off);
    const auto initial_records=m.r32(obj+records_off);
    const auto entry_index=m.r32(initial_table+idx*4u);
    const auto record=initial_records+entry_index*stride;
    if((m.r8(record)&1u)==0)return 0;

    if(i.arg[0]!=0){
        const auto rec=m.r32(obj+table_off),base=m.r32(obj+records_off);
        const auto selected=m.r32(rec+idx*4u),copy_record=base+selected*stride;
        const auto length=m.r32(copy_record+(wide?0x10u:4u));
        const auto source=m.r32(copy_record+(wide?0x14u:8u));
        copy_rep_forward(m,i.arg[0],source,length);
        const auto out_table=m.r32(obj+table_off),out_records=m.r32(obj+records_off);
        const auto out_selected=m.r32(out_table+idx*4u),out_record=out_records+out_selected*stride;
        m.w32(i.arg[1],m.r32(out_record+(wide?0x10u:4u)));
    }
    if(i.arg[3]!=0 && i.arg[4]!=0){
        const auto rec=m.r32(obj+table_off),base=m.r32(obj+records_off);
        const auto selected=m.r32(rec+idx*4u),copy_record=base+selected*stride;
        const auto length=m.r32(copy_record+(wide?0x18u:0xcu));
        const auto source=m.r32(copy_record+(wide?0x1cu:0x10u));
        copy_rep_forward(m,i.arg[3],source,length);
        const auto out_table=m.r32(obj+table_off),out_records=m.r32(obj+records_off);
        const auto out_selected=m.r32(out_table+idx*4u),out_record=out_records+out_selected*stride;
        m.w32(i.arg[4],m.r32(out_record+(wide?0x18u:0xcu)));
    }

    auto resolve=[&](){const auto table=m.r32(obj+table_off),base=m.r32(obj+records_off);return base+m.r32(table+idx*4u)*stride;};
    auto rec=resolve();auto flags=m.r32(rec);m.w32(rec,flags&~1u);
    rec=resolve();flags=m.r32(rec);m.w32(rec,flags&~2u);
    rec=resolve();flags=m.r32(rec);m.w32(rec,flags&~4u);
    if(wide){
        rec=resolve();m.w32(rec+4u,0);rec=resolve();m.w32(rec+8u,0);rec=resolve();m.w32(rec+0xcu,0);
        rec=resolve();m.w32(rec+0x10u,0);rec=resolve();m.w32(rec+0x18u,0);
    }else{
        rec=resolve();m.w32(rec+4u,0);rec=resolve();m.w32(rec+0xcu,0);
    }

    const auto count=m.r32(obj+count_off);
    auto j=idx;
    if(s32(j)<s32(count-1u)){
        while(true){
            const auto table=m.r32(obj+table_off);
            const auto next=m.r32(table+(j+1u)*4u);
            m.w32(table+j*4u,next);
            ++j;
            const auto current_count=m.r32(obj+count_off)-1u;
            if(s32(j)>=s32(current_count))break;
        }
    }
    const auto final_count=m.r32(obj+count_off),final_table=m.r32(obj+table_off);
    m.w32(final_table+(final_count-1u)*4u,0);
    m.w32(obj+count_off,m.r32(obj+count_off)-1u);
    return 1;
}
}

std::uint32_t fun_004ab710(Memory& m,const Inputs& i) {
    auto esi=i.dx,ebx=i.cx;
    if(s32(esi)<1)return i.ax;
    auto eax=esi-1u;
    if(s32(eax)<0)return eax;
    ++eax;
    const auto rows=eax;
    auto row_y=0u;
    const auto src=i.arg[0];
    for(auto row=0u;row<rows;++row){
        if(s32(rows)<=1)eax=0x10000u;
        else eax=std::uint32_t(s32(row_y)/s32(rows-1u));
        std::uint32_t ebp=0;
        while(s32(ebp)<256){
            auto ecx=ebp&0x800000ffu;
            if(s32(ecx)<0)ecx=std::uint32_t(s32(ecx)|0xffffff00);
            const auto index=s32(ecx);
            const auto p=src+std::uint32_t(index*2+index);
            auto red=m.r8(p),green=m.r8(p+1u),blue=m.r8(p+2u);
            auto r=std::uint32_t(s32((red*eax))>>16);
            auto g=std::uint32_t(s32(green*eax)>>16);
            auto b=std::uint32_t(s32(blue*eax)>>16);
            if(s32(r)>=255)r=255;if(s32(g)>=255)g=255;if(s32(b)>=255)b=255;
            const auto sb=sar32(b,m.r32(0x83b2f4));
            const auto db=sb<<(m.r32(0x83b2f0)&31u);
            const auto sg=sar32(g,m.r32(0x83b2fc));
            const auto dg=sg<<(m.r32(0x83b2f8)&31u);
            const auto sr=sar32(r,m.r32(0x83b2ec));
            const auto dr=sr<<(m.r32(0x83b2e8)&31u);
            ebx+=2u;
            const auto packed=db|dg|dr;
            m.w16(ebx-2u,packed);
            ++ebp;
        }
        row_y+=0x20000u;
        eax=rows-row-1u;
    }
    return eax;
}

std::uint32_t fun_0067c500(Memory& m,const Inputs& i) {
    const auto object=i.cx;
    const auto packed=m.r32(object+0x24u);
    const auto x=sx16(packed),y=sx16(packed>>16);
    const auto stride=m.r32(0x810a24u);
    const auto xoff=x-m.r32(0x810a28u);
    const auto yoff=y-m.r32(0x810a2cu);
    const auto first_index=stride*yoff+xoff;
    const auto second_index=stride*(yoff+1u)+xoff;
    const auto table=m.r32(0xaa49b4u);
    const auto first=table+first_index*8u,second=table+second_index*8u;
    std::uint32_t flags[4]{};
    std::uint32_t values[4]{};
    flags[0]=m.r8(first+4u);values[0]=m.r32(first);(void)m.r8(first+5u);
    values[1]=m.r32(first+8u);flags[1]=m.r8(first+12u);(void)m.r8(first+13u);
    flags[2]=m.r8(second+12u);values[2]=m.r32(second+8u);values[3]=m.r32(second);
    (void)m.r8(second+13u);flags[3]=m.r8(second+4u);(void)m.r8(second+5u);
    auto minimum=1000u,maximum=0xffffffffu;
    for(auto v:values){if(s32(v)<s32(minimum))minimum=v;if(s32(v)>s32(maximum))maximum=v;}
    std::uint32_t eax=0;
    if(maximum==minimum){
        for(unsigned k=0;k<4;++k)if(flags[k]==0)eax+=1u<<k;
    }else if(s32(i.dx)>0){
        for(unsigned k=0;k<4;++k)if(s32(values[k])<s32(maximum)&&flags[k]==0)eax+=1u<<k;
    }else{
        for(unsigned k=0;k<4;++k)if(s32(values[k])>s32(minimum)&&flags[k]==0)eax+=1u<<k;
    }
    return eax;
}

std::uint32_t fun_00427e90(Memory& m,const Inputs& i) {
    const auto obj=i.cx;
    m.w32(m.r32(obj+0xcu)+0x180000u,0);
    m.w32(m.r32(obj+0x10u)+0x100000u,0);
    const auto clear_header=[&](std::uint32_t h){
        auto n=m.r32(h);
        if(s32(n)>=0){
            std::uint32_t edx=0;
            do{const auto p=m.r32(h+8u);++edx;m.w32(p+(edx-1u)*4u,0);n=m.r32(h);}while(s32(edx)<=s32(n));
        }
        m.w32(h,0);
    };
    clear_header(m.r32(obj+0x14u));
    clear_header(m.r32(obj+0x68u));
    auto eax=m.r32(obj+0x28u)+1u;
    m.w32(obj+0x28u,eax);
    if(eax!=0)return eax;

    auto dimension=m.r32(0x836b4cu);
    auto cells=dimension*dimension;
    auto index=cells-1u;
    if(s32(index)>=0){
        do{const auto p1=m.r32(obj+0x18u);--index;m.w32(p1+index*4u+4u,0);const auto p2=m.r32(obj+0x1cu);m.w32(p2+index*4u+4u,0);}while(s32(index)>=0);
    }
    for(unsigned group=0;group<3;++group){
        const auto field=obj+0x4cu+4u*group;
        const auto n=m.r32(0x81a890u+4u*group);
        if(s32(n)>=0){
            const auto current=m.r32(field),before=m.r32(field-0xcu),after=m.r32(field+0xcu);
            for(std::uint32_t k=n;k>0;--k){const auto off=(k-1u)*4u;m.w32(before+off,0);m.w32(current+off,0);m.w32(after+off,0);}
        }
    }
    eax=m.r32(obj+0x28u)+1u;
    m.w32(obj+0x28u,eax);
    return eax;
}

std::uint32_t fun_005a45b0(Memory& m,const Inputs& i) {
    const auto base=i.cx;
    auto count=s32(i.dx);
    if(count==0)return i.ax;
    const auto len=i.arg[0];
    if(count==32){
        auto eax=base+len*4u;auto remaining=len;std::uint32_t ecx=0;
        if(remaining==0)return eax;
        while(remaining!=0){const auto edx=m.r32(eax-4u);eax-=4u;--remaining;m.w32(eax,ecx);ecx=edx;}
        return eax;
    }
    if(count<32){
        auto ebx=1u<<(std::uint32_t(count)&31u);auto mask=ebx-1u;
        const auto complement=32u-std::uint32_t(count);
        auto remaining=len;
        i.arg[0]=0;
        auto eax=len-1u;
        if(len==0)return eax;
        auto esi=base+len*4u;
        while(remaining!=0){
            auto value=m.r32(esi-4u);esi-=4u;
            const auto dropped=value&mask;
            value>>=(std::uint32_t(count)&31u);
            value|=i.arg[0]<<(complement&31u);
            i.arg[0]=dropped;
            m.w32(esi,value);
            --remaining;eax=remaining;
        }
        return eax;
    }
    const auto signed_count=std::uint32_t(count);
    const auto quotient=sar32(signed_count+((signed_count>>31)&31u),5);
    auto remainder=signed_count&0x8000001fu;
    if(s32(remainder)<0)remainder=std::uint32_t((remainder-1u)|0xffffffe0u)+1u;
    const auto len_minus_one=len-1u;
    auto esi=base;
    if(s32(quotient)<s32(len_minus_one)){
        const auto shifts=32u-remainder;
        auto iterations=len_minus_one-quotient;
        while(iterations!=0){
            const auto high=m.r32(esi+quotient*4u+4u);
            const auto low=m.r32(esi+quotient*4u);
            const auto shifted=(high<<(shifts&31u))|(low>>(remainder&31u));
            esi+=4u;m.w32(esi-4u,shifted);--iterations;
        }
    }
    if(s32(quotient)<s32(len)){
        const auto v=m.r32(esi+quotient*4u);
        m.w32(esi,v>>(remainder&31u));esi+=4u;
    }
    auto clear_count=s32(quotient)<s32(len)?quotient:len;
    while(clear_count!=0){m.w32(esi,0);esi+=4u;--clear_count;}
    return quotient;
}

std::uint32_t fun_004803e0(Memory& m,const Inputs& i){return remove_entry(m,i,false);}
std::uint32_t fun_00480140(Memory& m,const Inputs& i){return remove_entry(m,i,true);}

std::uint32_t fun_004f5040(Memory& m,const Inputs& i) {
    auto count=m.r32(0xa1a5d8u);
    if(s32(count)<=0)return 0xffffffffu;
    const auto array=m.r32(0xa1a5ccu);
    const auto needle=i.cx;
    for(std::uint32_t index=0;index<count;++index){
        const auto entry=m.r32(array+index*4u);
        auto p=entry+0x15ee0u;
        std::uint32_t n=0;
        while(m.r8(p+n)!=0)++n;
        ++n;
        std::array<std::uint8_t,20> scratch{};
        std::uint32_t copied=0;
        while(copied+4u<=n){const auto v=m.r32(p+copied);for(unsigned b=0;b<4;++b)scratch[copied+b]=std::uint8_t(v>>(b*8u));copied+=4u;}
        while(copied<n){scratch[copied]=std::uint8_t(m.r8(p+copied));++copied;}
        bool match=false;
        for(std::uint32_t k=0;k<n;++k){const auto left=scratch[k];const auto right=m.r8(needle+k);if(left!=right)break;if(left==0){match=true;break;}}
        if(match)return index;
    }
    return 0xffffffffu;
}
}
